// Copyright 2022 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// Generated by the Codegen C++ plugin.
// If you make any local changes, they will be lost.
// source: google/cloud/webrisk/v1/webrisk.proto

#include "google/cloud/webrisk/web_risk_connection.h"
#include "google/cloud/webrisk/internal/web_risk_option_defaults.h"
#include "google/cloud/webrisk/internal/web_risk_stub_factory.h"
#include "google/cloud/webrisk/web_risk_options.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/common_options.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/retry_loop.h"
#include <memory>

namespace google {
namespace cloud {
namespace webrisk {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

WebRiskServiceConnection::~WebRiskServiceConnection() = default;

StatusOr<google::cloud::webrisk::v1::ComputeThreatListDiffResponse>
WebRiskServiceConnection::ComputeThreatListDiff(
    google::cloud::webrisk::v1::ComputeThreatListDiffRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StatusOr<google::cloud::webrisk::v1::SearchUrisResponse>
WebRiskServiceConnection::SearchUris(
    google::cloud::webrisk::v1::SearchUrisRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StatusOr<google::cloud::webrisk::v1::SearchHashesResponse>
WebRiskServiceConnection::SearchHashes(
    google::cloud::webrisk::v1::SearchHashesRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StatusOr<google::cloud::webrisk::v1::Submission>
WebRiskServiceConnection::CreateSubmission(
    google::cloud::webrisk::v1::CreateSubmissionRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

namespace {
class WebRiskServiceConnectionImpl : public WebRiskServiceConnection {
 public:
  WebRiskServiceConnectionImpl(
      std::unique_ptr<google::cloud::BackgroundThreads> background,
      std::shared_ptr<webrisk_internal::WebRiskServiceStub> stub,
      Options const& options)
      : background_(std::move(background)),
        stub_(std::move(stub)),
        retry_policy_prototype_(
            options.get<WebRiskServiceRetryPolicyOption>()->clone()),
        backoff_policy_prototype_(
            options.get<WebRiskServiceBackoffPolicyOption>()->clone()),
        idempotency_policy_(
            options.get<WebRiskServiceConnectionIdempotencyPolicyOption>()
                ->clone()) {}

  ~WebRiskServiceConnectionImpl() override = default;

  StatusOr<google::cloud::webrisk::v1::ComputeThreatListDiffResponse>
  ComputeThreatListDiff(
      google::cloud::webrisk::v1::ComputeThreatListDiffRequest const& request)
      override {
    return google::cloud::internal::RetryLoop(
        retry_policy_prototype_->clone(), backoff_policy_prototype_->clone(),
        idempotency_policy_->ComputeThreatListDiff(request),
        [this](grpc::ClientContext& context,
               google::cloud::webrisk::v1::ComputeThreatListDiffRequest const&
                   request) {
          return stub_->ComputeThreatListDiff(context, request);
        },
        request, __func__);
  }

  StatusOr<google::cloud::webrisk::v1::SearchUrisResponse> SearchUris(
      google::cloud::webrisk::v1::SearchUrisRequest const& request) override {
    return google::cloud::internal::RetryLoop(
        retry_policy_prototype_->clone(), backoff_policy_prototype_->clone(),
        idempotency_policy_->SearchUris(request),
        [this](grpc::ClientContext& context,
               google::cloud::webrisk::v1::SearchUrisRequest const& request) {
          return stub_->SearchUris(context, request);
        },
        request, __func__);
  }

  StatusOr<google::cloud::webrisk::v1::SearchHashesResponse> SearchHashes(
      google::cloud::webrisk::v1::SearchHashesRequest const& request) override {
    return google::cloud::internal::RetryLoop(
        retry_policy_prototype_->clone(), backoff_policy_prototype_->clone(),
        idempotency_policy_->SearchHashes(request),
        [this](grpc::ClientContext& context,
               google::cloud::webrisk::v1::SearchHashesRequest const& request) {
          return stub_->SearchHashes(context, request);
        },
        request, __func__);
  }

  StatusOr<google::cloud::webrisk::v1::Submission> CreateSubmission(
      google::cloud::webrisk::v1::CreateSubmissionRequest const& request)
      override {
    return google::cloud::internal::RetryLoop(
        retry_policy_prototype_->clone(), backoff_policy_prototype_->clone(),
        idempotency_policy_->CreateSubmission(request),
        [this](grpc::ClientContext& context,
               google::cloud::webrisk::v1::CreateSubmissionRequest const&
                   request) {
          return stub_->CreateSubmission(context, request);
        },
        request, __func__);
  }

 private:
  std::unique_ptr<google::cloud::BackgroundThreads> background_;
  std::shared_ptr<webrisk_internal::WebRiskServiceStub> stub_;
  std::unique_ptr<WebRiskServiceRetryPolicy const> retry_policy_prototype_;
  std::unique_ptr<BackoffPolicy const> backoff_policy_prototype_;
  std::unique_ptr<WebRiskServiceConnectionIdempotencyPolicy>
      idempotency_policy_;
};
}  // namespace

std::shared_ptr<WebRiskServiceConnection> MakeWebRiskServiceConnection(
    Options options) {
  internal::CheckExpectedOptions<CommonOptionList, GrpcOptionList,
                                 WebRiskServicePolicyOptionList>(options,
                                                                 __func__);
  options = webrisk_internal::WebRiskServiceDefaultOptions(std::move(options));
  auto background = internal::MakeBackgroundThreadsFactory(options)();
  auto stub = webrisk_internal::CreateDefaultWebRiskServiceStub(
      background->cq(), options);
  return std::make_shared<WebRiskServiceConnectionImpl>(
      std::move(background), std::move(stub), options);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace webrisk
}  // namespace cloud
}  // namespace google

namespace google {
namespace cloud {
namespace webrisk_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

std::shared_ptr<webrisk::WebRiskServiceConnection> MakeWebRiskServiceConnection(
    std::shared_ptr<WebRiskServiceStub> stub, Options options) {
  options = WebRiskServiceDefaultOptions(std::move(options));
  return std::make_shared<webrisk::WebRiskServiceConnectionImpl>(
      internal::MakeBackgroundThreadsFactory(options)(), std::move(stub),
      std::move(options));
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace webrisk_internal
}  // namespace cloud
}  // namespace google
