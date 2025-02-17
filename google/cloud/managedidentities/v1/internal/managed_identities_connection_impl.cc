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
// source: google/cloud/managedidentities/v1/managed_identities_service.proto

#include "google/cloud/managedidentities/v1/internal/managed_identities_connection_impl.h"
#include "google/cloud/managedidentities/v1/internal/managed_identities_option_defaults.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/common_options.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/async_long_running_operation.h"
#include "google/cloud/internal/pagination_range.h"
#include "google/cloud/internal/retry_loop.h"
#include <memory>

namespace google {
namespace cloud {
namespace managedidentities_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN
namespace {

std::unique_ptr<managedidentities_v1::ManagedIdentitiesServiceRetryPolicy>
retry_policy(Options const& options) {
  return options
      .get<managedidentities_v1::ManagedIdentitiesServiceRetryPolicyOption>()
      ->clone();
}

std::unique_ptr<BackoffPolicy> backoff_policy(Options const& options) {
  return options
      .get<managedidentities_v1::ManagedIdentitiesServiceBackoffPolicyOption>()
      ->clone();
}

std::unique_ptr<
    managedidentities_v1::ManagedIdentitiesServiceConnectionIdempotencyPolicy>
idempotency_policy(Options const& options) {
  return options
      .get<managedidentities_v1::
               ManagedIdentitiesServiceConnectionIdempotencyPolicyOption>()
      ->clone();
}

std::unique_ptr<PollingPolicy> polling_policy(Options const& options) {
  return options
      .get<managedidentities_v1::ManagedIdentitiesServicePollingPolicyOption>()
      ->clone();
}

}  // namespace

ManagedIdentitiesServiceConnectionImpl::ManagedIdentitiesServiceConnectionImpl(
    std::unique_ptr<google::cloud::BackgroundThreads> background,
    std::shared_ptr<managedidentities_v1_internal::ManagedIdentitiesServiceStub>
        stub,
    Options options)
    : background_(std::move(background)),
      stub_(std::move(stub)),
      options_(internal::MergeOptions(
          std::move(options), ManagedIdentitiesServiceConnection::options())) {}

future<StatusOr<google::cloud::managedidentities::v1::Domain>>
ManagedIdentitiesServiceConnectionImpl::CreateMicrosoftAdDomain(
    google::cloud::managedidentities::v1::CreateMicrosoftAdDomainRequest const&
        request) {
  auto current = google::cloud::internal::SaveCurrentOptions();
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::managedidentities::v1::Domain>(
      background_->cq(), request,
      [stub = stub_](google::cloud::CompletionQueue& cq,
                     std::shared_ptr<grpc::ClientContext> context,
                     google::cloud::managedidentities::v1::
                         CreateMicrosoftAdDomainRequest const& request) {
        return stub->AsyncCreateMicrosoftAdDomain(cq, std::move(context),
                                                  request);
      },
      [stub = stub_](google::cloud::CompletionQueue& cq,
                     std::shared_ptr<grpc::ClientContext> context,
                     google::longrunning::GetOperationRequest const& request) {
        return stub->AsyncGetOperation(cq, std::move(context), request);
      },
      [stub = stub_](
          google::cloud::CompletionQueue& cq,
          std::shared_ptr<grpc::ClientContext> context,
          google::longrunning::CancelOperationRequest const& request) {
        return stub->AsyncCancelOperation(cq, std::move(context), request);
      },
      &google::cloud::internal::ExtractLongRunningResultResponse<
          google::cloud::managedidentities::v1::Domain>,
      retry_policy(*current), backoff_policy(*current),
      idempotency_policy(*current)->CreateMicrosoftAdDomain(request),
      polling_policy(*current), __func__);
}

StatusOr<google::cloud::managedidentities::v1::ResetAdminPasswordResponse>
ManagedIdentitiesServiceConnectionImpl::ResetAdminPassword(
    google::cloud::managedidentities::v1::ResetAdminPasswordRequest const&
        request) {
  auto current = google::cloud::internal::SaveCurrentOptions();
  return google::cloud::internal::RetryLoop(
      retry_policy(*current), backoff_policy(*current),
      idempotency_policy(*current)->ResetAdminPassword(request),
      [this](
          grpc::ClientContext& context,
          google::cloud::managedidentities::v1::ResetAdminPasswordRequest const&
              request) { return stub_->ResetAdminPassword(context, request); },
      request, __func__);
}

StreamRange<google::cloud::managedidentities::v1::Domain>
ManagedIdentitiesServiceConnectionImpl::ListDomains(
    google::cloud::managedidentities::v1::ListDomainsRequest request) {
  request.clear_page_token();
  auto current = google::cloud::internal::SaveCurrentOptions();
  auto idempotency = idempotency_policy(*current)->ListDomains(request);
  char const* function_name = __func__;
  return google::cloud::internal::MakePaginationRange<
      StreamRange<google::cloud::managedidentities::v1::Domain>>(
      std::move(request),
      [idempotency, function_name, stub = stub_,
       retry = std::shared_ptr<
           managedidentities_v1::ManagedIdentitiesServiceRetryPolicy>(
           retry_policy(*current)),
       backoff = std::shared_ptr<BackoffPolicy>(backoff_policy(*current))](
          google::cloud::managedidentities::v1::ListDomainsRequest const& r) {
        return google::cloud::internal::RetryLoop(
            retry->clone(), backoff->clone(), idempotency,
            [stub](
                grpc::ClientContext& context,
                google::cloud::managedidentities::v1::ListDomainsRequest const&
                    request) { return stub->ListDomains(context, request); },
            r, function_name);
      },
      [](google::cloud::managedidentities::v1::ListDomainsResponse r) {
        std::vector<google::cloud::managedidentities::v1::Domain> result(
            r.domains().size());
        auto& messages = *r.mutable_domains();
        std::move(messages.begin(), messages.end(), result.begin());
        return result;
      });
}

StatusOr<google::cloud::managedidentities::v1::Domain>
ManagedIdentitiesServiceConnectionImpl::GetDomain(
    google::cloud::managedidentities::v1::GetDomainRequest const& request) {
  auto current = google::cloud::internal::SaveCurrentOptions();
  return google::cloud::internal::RetryLoop(
      retry_policy(*current), backoff_policy(*current),
      idempotency_policy(*current)->GetDomain(request),
      [this](grpc::ClientContext& context,
             google::cloud::managedidentities::v1::GetDomainRequest const&
                 request) { return stub_->GetDomain(context, request); },
      request, __func__);
}

future<StatusOr<google::cloud::managedidentities::v1::Domain>>
ManagedIdentitiesServiceConnectionImpl::UpdateDomain(
    google::cloud::managedidentities::v1::UpdateDomainRequest const& request) {
  auto current = google::cloud::internal::SaveCurrentOptions();
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::managedidentities::v1::Domain>(
      background_->cq(), request,
      [stub = stub_](
          google::cloud::CompletionQueue& cq,
          std::shared_ptr<grpc::ClientContext> context,
          google::cloud::managedidentities::v1::UpdateDomainRequest const&
              request) {
        return stub->AsyncUpdateDomain(cq, std::move(context), request);
      },
      [stub = stub_](google::cloud::CompletionQueue& cq,
                     std::shared_ptr<grpc::ClientContext> context,
                     google::longrunning::GetOperationRequest const& request) {
        return stub->AsyncGetOperation(cq, std::move(context), request);
      },
      [stub = stub_](
          google::cloud::CompletionQueue& cq,
          std::shared_ptr<grpc::ClientContext> context,
          google::longrunning::CancelOperationRequest const& request) {
        return stub->AsyncCancelOperation(cq, std::move(context), request);
      },
      &google::cloud::internal::ExtractLongRunningResultResponse<
          google::cloud::managedidentities::v1::Domain>,
      retry_policy(*current), backoff_policy(*current),
      idempotency_policy(*current)->UpdateDomain(request),
      polling_policy(*current), __func__);
}

future<StatusOr<google::cloud::managedidentities::v1::OpMetadata>>
ManagedIdentitiesServiceConnectionImpl::DeleteDomain(
    google::cloud::managedidentities::v1::DeleteDomainRequest const& request) {
  auto current = google::cloud::internal::SaveCurrentOptions();
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::managedidentities::v1::OpMetadata>(
      background_->cq(), request,
      [stub = stub_](
          google::cloud::CompletionQueue& cq,
          std::shared_ptr<grpc::ClientContext> context,
          google::cloud::managedidentities::v1::DeleteDomainRequest const&
              request) {
        return stub->AsyncDeleteDomain(cq, std::move(context), request);
      },
      [stub = stub_](google::cloud::CompletionQueue& cq,
                     std::shared_ptr<grpc::ClientContext> context,
                     google::longrunning::GetOperationRequest const& request) {
        return stub->AsyncGetOperation(cq, std::move(context), request);
      },
      [stub = stub_](
          google::cloud::CompletionQueue& cq,
          std::shared_ptr<grpc::ClientContext> context,
          google::longrunning::CancelOperationRequest const& request) {
        return stub->AsyncCancelOperation(cq, std::move(context), request);
      },
      &google::cloud::internal::ExtractLongRunningResultMetadata<
          google::cloud::managedidentities::v1::OpMetadata>,
      retry_policy(*current), backoff_policy(*current),
      idempotency_policy(*current)->DeleteDomain(request),
      polling_policy(*current), __func__);
}

future<StatusOr<google::cloud::managedidentities::v1::Domain>>
ManagedIdentitiesServiceConnectionImpl::AttachTrust(
    google::cloud::managedidentities::v1::AttachTrustRequest const& request) {
  auto current = google::cloud::internal::SaveCurrentOptions();
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::managedidentities::v1::Domain>(
      background_->cq(), request,
      [stub = stub_](
          google::cloud::CompletionQueue& cq,
          std::shared_ptr<grpc::ClientContext> context,
          google::cloud::managedidentities::v1::AttachTrustRequest const&
              request) {
        return stub->AsyncAttachTrust(cq, std::move(context), request);
      },
      [stub = stub_](google::cloud::CompletionQueue& cq,
                     std::shared_ptr<grpc::ClientContext> context,
                     google::longrunning::GetOperationRequest const& request) {
        return stub->AsyncGetOperation(cq, std::move(context), request);
      },
      [stub = stub_](
          google::cloud::CompletionQueue& cq,
          std::shared_ptr<grpc::ClientContext> context,
          google::longrunning::CancelOperationRequest const& request) {
        return stub->AsyncCancelOperation(cq, std::move(context), request);
      },
      &google::cloud::internal::ExtractLongRunningResultResponse<
          google::cloud::managedidentities::v1::Domain>,
      retry_policy(*current), backoff_policy(*current),
      idempotency_policy(*current)->AttachTrust(request),
      polling_policy(*current), __func__);
}

future<StatusOr<google::cloud::managedidentities::v1::Domain>>
ManagedIdentitiesServiceConnectionImpl::ReconfigureTrust(
    google::cloud::managedidentities::v1::ReconfigureTrustRequest const&
        request) {
  auto current = google::cloud::internal::SaveCurrentOptions();
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::managedidentities::v1::Domain>(
      background_->cq(), request,
      [stub = stub_](
          google::cloud::CompletionQueue& cq,
          std::shared_ptr<grpc::ClientContext> context,
          google::cloud::managedidentities::v1::ReconfigureTrustRequest const&
              request) {
        return stub->AsyncReconfigureTrust(cq, std::move(context), request);
      },
      [stub = stub_](google::cloud::CompletionQueue& cq,
                     std::shared_ptr<grpc::ClientContext> context,
                     google::longrunning::GetOperationRequest const& request) {
        return stub->AsyncGetOperation(cq, std::move(context), request);
      },
      [stub = stub_](
          google::cloud::CompletionQueue& cq,
          std::shared_ptr<grpc::ClientContext> context,
          google::longrunning::CancelOperationRequest const& request) {
        return stub->AsyncCancelOperation(cq, std::move(context), request);
      },
      &google::cloud::internal::ExtractLongRunningResultResponse<
          google::cloud::managedidentities::v1::Domain>,
      retry_policy(*current), backoff_policy(*current),
      idempotency_policy(*current)->ReconfigureTrust(request),
      polling_policy(*current), __func__);
}

future<StatusOr<google::cloud::managedidentities::v1::Domain>>
ManagedIdentitiesServiceConnectionImpl::DetachTrust(
    google::cloud::managedidentities::v1::DetachTrustRequest const& request) {
  auto current = google::cloud::internal::SaveCurrentOptions();
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::managedidentities::v1::Domain>(
      background_->cq(), request,
      [stub = stub_](
          google::cloud::CompletionQueue& cq,
          std::shared_ptr<grpc::ClientContext> context,
          google::cloud::managedidentities::v1::DetachTrustRequest const&
              request) {
        return stub->AsyncDetachTrust(cq, std::move(context), request);
      },
      [stub = stub_](google::cloud::CompletionQueue& cq,
                     std::shared_ptr<grpc::ClientContext> context,
                     google::longrunning::GetOperationRequest const& request) {
        return stub->AsyncGetOperation(cq, std::move(context), request);
      },
      [stub = stub_](
          google::cloud::CompletionQueue& cq,
          std::shared_ptr<grpc::ClientContext> context,
          google::longrunning::CancelOperationRequest const& request) {
        return stub->AsyncCancelOperation(cq, std::move(context), request);
      },
      &google::cloud::internal::ExtractLongRunningResultResponse<
          google::cloud::managedidentities::v1::Domain>,
      retry_policy(*current), backoff_policy(*current),
      idempotency_policy(*current)->DetachTrust(request),
      polling_policy(*current), __func__);
}

future<StatusOr<google::cloud::managedidentities::v1::Domain>>
ManagedIdentitiesServiceConnectionImpl::ValidateTrust(
    google::cloud::managedidentities::v1::ValidateTrustRequest const& request) {
  auto current = google::cloud::internal::SaveCurrentOptions();
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::managedidentities::v1::Domain>(
      background_->cq(), request,
      [stub = stub_](
          google::cloud::CompletionQueue& cq,
          std::shared_ptr<grpc::ClientContext> context,
          google::cloud::managedidentities::v1::ValidateTrustRequest const&
              request) {
        return stub->AsyncValidateTrust(cq, std::move(context), request);
      },
      [stub = stub_](google::cloud::CompletionQueue& cq,
                     std::shared_ptr<grpc::ClientContext> context,
                     google::longrunning::GetOperationRequest const& request) {
        return stub->AsyncGetOperation(cq, std::move(context), request);
      },
      [stub = stub_](
          google::cloud::CompletionQueue& cq,
          std::shared_ptr<grpc::ClientContext> context,
          google::longrunning::CancelOperationRequest const& request) {
        return stub->AsyncCancelOperation(cq, std::move(context), request);
      },
      &google::cloud::internal::ExtractLongRunningResultResponse<
          google::cloud::managedidentities::v1::Domain>,
      retry_policy(*current), backoff_policy(*current),
      idempotency_policy(*current)->ValidateTrust(request),
      polling_policy(*current), __func__);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace managedidentities_v1_internal
}  // namespace cloud
}  // namespace google
