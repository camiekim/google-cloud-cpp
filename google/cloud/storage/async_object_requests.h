// Copyright 2023 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_STORAGE_ASYNC_OBJECT_REQUESTS_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_STORAGE_ASYNC_OBJECT_REQUESTS_H

#include "google/cloud/storage/internal/async/write_payload_fwd.h"
#include "google/cloud/storage/internal/object_requests.h"
#include "google/cloud/storage/version.h"
#include "absl/strings/cord.h"
#include <cstdint>
#include <string>
#include <vector>

namespace google {
namespace cloud {
namespace storage_experimental {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

/**
 * An opaque representation of the data for an object payload.
 *
 * While applications do not need to create instances of this class, they may
 * need to use it in their mocks, to validate the contents of their requests.
 */
class WritePayload {
 public:
  /// Creates an empty payload.
  WritePayload() = default;

  /// Returns true if the payload has no data.
  bool empty() const { return impl_.empty(); }

  /// Returns the total size of the data.
  std::size_t size() const { return impl_.size(); }

  /**
   * Returns views into the data.
   *
   * Note that changing `*this` in any way (assignment, destruction, etc.)
   * invalidates all the returned buffers.
   */
  std::vector<absl::string_view> payload() const {
    return {impl_.chunk_begin(), impl_.chunk_end()};
  }

 private:
  friend struct storage_internal::WritePayloadImpl;
  explicit WritePayload(absl::Cord impl) : impl_(std::move(impl)) {}

  absl::Cord impl_;
};

/**
 * A request to insert object sans the data payload.
 *
 * This class can hold all the mandatory and optional parameters to insert an
 * object **except** for the data payload. The ideal representation for the data
 * payload depends on the type of request. For asynchronous requests the data
 * must be in an owning type, such as `WritePayload`. For blocking request, a
 * non-owning type (such as `absl::string_view`) can reduce data copying.
 *
 * This class is the public API for the library because it is required for
 * mocking.
 */
class InsertObjectRequest {
 public:
  InsertObjectRequest() = default;
  InsertObjectRequest(std::string bucket_name, std::string object_name)
      : impl_(std::move(bucket_name), std::move(object_name)) {}

  std::string const& bucket_name() const { return impl_.bucket_name(); }
  std::string const& object_name() const { return impl_.object_name(); }

  template <typename... O>
  InsertObjectRequest& set_multiple_options(O&&... o) & {
    impl_.set_multiple_options(std::forward<O>(o)...);
    return *this;
  }
  template <typename... O>
  InsertObjectRequest&& set_multiple_options(O&&... o) && {
    return std::move(set_multiple_options(std::forward<O>(o)...));
  }

  template <typename O>
  bool HasOption() const {
    return impl_.HasOption<O>();
  }
  template <typename O>
  O GetOption() const {
    return impl_.GetOption<O>();
  }

 protected:
  struct Impl : public storage::internal::InsertObjectRequestImpl<Impl> {
    using storage::internal::InsertObjectRequestImpl<
        Impl>::InsertObjectRequestImpl;
  };
  Impl impl_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace storage_experimental
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_STORAGE_ASYNC_OBJECT_REQUESTS_H
