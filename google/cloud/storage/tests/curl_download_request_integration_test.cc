// Copyright 2018 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "google/cloud/storage/internal/curl_request_builder.h"
#include "google/cloud/internal/absl_str_join_quiet.h"
#include "google/cloud/internal/getenv.h"
#include "google/cloud/log.h"
#include "google/cloud/testing_util/status_matchers.h"
#include <gmock/gmock.h>
#include <chrono>
#include <cstdlib>
#include <thread>
#include <vector>

namespace google {
namespace cloud {
namespace storage {
inline namespace STORAGE_CLIENT_NS {
namespace internal {
namespace {

using ::google::cloud::testing_util::IsOk;
using ::testing::Contains;
using ::testing::Pair;
using ::testing::StartsWith;

std::string HttpBinEndpoint() {
  return google::cloud::internal::GetEnv("HTTPBIN_ENDPOINT")
      .value_or("https://nghttp2.org/httpbin");
}

TEST(CurlDownloadRequestTest, SimpleStream) {
  // httpbin can generate up to 100 lines, do not try to download more than
  // that.
  constexpr int kDownloadedLines = 100;

  std::size_t count = 0;
  auto download = [&] {
    count = 0;
    CurlRequestBuilder request(
        HttpBinEndpoint() + "/stream/" + std::to_string(kDownloadedLines),
        storage::internal::GetDefaultCurlHandleFactory());
    auto download = request.BuildDownloadRequest(std::string{});
    char buffer[128 * 1024];
    do {
      auto n = sizeof(buffer);
      auto result = download.Read(buffer, n);
      if (!result) return std::move(result).status();
      if (result->bytes_received > sizeof(buffer)) {
        return Status{StatusCode::kUnknown, "invalid byte count"};
      }
      count += static_cast<std::size_t>(
          std::count(buffer, buffer + result->bytes_received, '\n'));
      if (result->response.status_code != 100) break;
    } while (true);
    return Status{};
  };

  auto delay = std::chrono::seconds(1);
  for (int i = 0; i != 3; ++i) {
    auto result = download();
    if (result.ok()) break;
    std::this_thread::sleep_for(delay);
    delay *= 2;
  }
  EXPECT_EQ(kDownloadedLines, count);
}

// Run one attempt of the Regression7051 test. This is wrapped in a retry loop,
// as integration tests flake due to unrelated (and unavoidable) problems, e.g.,
// trying to setup connections.
Status AttemptRegression7051() {
  // Download the maximum number of lines supported by httpbin.org
  auto constexpr kDownloadedLines = 100;
  auto constexpr kTestPoolSize = 32;
  auto factory =
      std::make_shared<PooledCurlHandleFactory>(kTestPoolSize, Options{});

  auto make_download = [&] {
    CurlRequestBuilder builder(
        HttpBinEndpoint() + "/stream/" + std::to_string(kDownloadedLines),
        factory);
    return builder.BuildDownloadRequest(std::string{});
  };

  auto error = [](std::string msg) {
    return Status(StatusCode::kUnknown, std::move(msg));
  };

  auto constexpr kBufferSize = kDownloadedLines;
  char buffer[kBufferSize];

  void* id;
  {
    auto r_no_close = make_download();
    id = r_no_close.id();
    if (id == nullptr) return error("r_no_close.id()==nulltptr");
    auto read = r_no_close.Read(buffer, kBufferSize);
    if (!read) return std::move(read).status();
  }

  {
    auto r_partial_close = make_download();
    if (r_partial_close.id() != id) return error("r_partial_close.id() != id");
    auto read = r_partial_close.Read(buffer, kBufferSize);
    if (!read) return std::move(read).status();
    auto close = r_partial_close.Close();
    if (!close) return std::move(close).status();
  }

  auto r_full = make_download();
  if (r_full.id() != id) return error("r_full.id() != id");
  do {
    auto read = r_full.Read(buffer, kBufferSize);
    if (!read) return std::move(read).status();
    if (read->response.status_code != 100) break;
  } while (true);
  auto close = r_full.Close();
  if (!close) return std::move(close).status();

  return Status{};
}

/// @test Prevent regressions of #7051: re-using a stream after a partial read.
TEST(CurlDownloadRequestTest, Regression7051) {
  auto delay = std::chrono::seconds(1);
  auto status = Status{};
  for (int i = 0; i != 3; ++i) {
    status = AttemptRegression7051();
    if (status.ok()) break;
    std::this_thread::sleep_for(delay);
    delay *= 2;
  }
  EXPECT_THAT(status, IsOk());
}

TEST(CurlDownloadRequestTest, HttpVersion) {
  using Headers = std::multimap<std::string, std::string>;
  // Run one attempt and return the headers, if any.
  auto attempt = [] {
    Headers headers;
    CurlRequestBuilder builder(HttpBinEndpoint() + "/get",
                               GetDefaultCurlHandleFactory());
    auto download = builder.BuildDownloadRequest(std::string{});

    auto constexpr kBufferSize = 4096;
    char buffer[kBufferSize];
    do {
      auto read = download.Read(buffer, kBufferSize);
      if (!read) return Headers{};
      headers.insert(read->response.headers.begin(),
                     read->response.headers.end());
      if (read->response.status_code != 100) break;
    } while (true);
    auto close = download.Close();
    if (!close) return Headers{};
    return headers;
  };

  struct Test {
    std::string version;
    std::string prefix;
  } cases[] = {
      // The HTTP version setting is a request, libcurl may choose a slightly
      // different version (e.g. 1.1 when 1.0 is requested).
      {"1.0", "http/1"},
      {"1.1", "http/1"},
      {"2", "http/"},  // HTTP/2 may not be compiled in
      {"", "http/"},
  };

  for (auto const& test : cases) {
    SCOPED_TRACE("Testing with version=<" + test.version + ">");
    auto delay = std::chrono::seconds(1);
    Headers headers;
    for (int i = 0; i != 3; ++i) {
      headers = attempt();
      if (!headers.empty()) break;
    }
    std::this_thread::sleep_for(delay);
    delay *= 2;
    EXPECT_THAT(headers, Contains(Pair(StartsWith(test.prefix), "")));
  }
}

}  // namespace
}  // namespace internal
}  // namespace STORAGE_CLIENT_NS
}  // namespace storage
}  // namespace cloud
}  // namespace google
