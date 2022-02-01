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
// source: google/cloud/iap/v1/service.proto

#include "google/cloud/iap/internal/identity_aware_proxy_o_auth_connection_impl.h"
#include "google/cloud/iap/internal/identity_aware_proxy_o_auth_option_defaults.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/common_options.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/pagination_range.h"
#include "google/cloud/internal/retry_loop.h"
#include <memory>

namespace google {
namespace cloud {
namespace iap_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

IdentityAwareProxyOAuthServiceConnectionImpl::
    IdentityAwareProxyOAuthServiceConnectionImpl(
        std::unique_ptr<google::cloud::BackgroundThreads> background,
        std::shared_ptr<iap_internal::IdentityAwareProxyOAuthServiceStub> stub,
        Options options)
    : background_(std::move(background)),
      stub_(std::move(stub)),
      options_(internal::MergeOptions(
          std::move(options),
          iap_internal::IdentityAwareProxyOAuthServiceDefaultOptions(
              IdentityAwareProxyOAuthServiceConnection::options()))) {}

StatusOr<google::cloud::iap::v1::ListBrandsResponse>
IdentityAwareProxyOAuthServiceConnectionImpl::ListBrands(
    google::cloud::iap::v1::ListBrandsRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->ListBrands(request),
      [this](grpc::ClientContext& context,
             google::cloud::iap::v1::ListBrandsRequest const& request) {
        return stub_->ListBrands(context, request);
      },
      request, __func__);
}

StatusOr<google::cloud::iap::v1::Brand>
IdentityAwareProxyOAuthServiceConnectionImpl::CreateBrand(
    google::cloud::iap::v1::CreateBrandRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->CreateBrand(request),
      [this](grpc::ClientContext& context,
             google::cloud::iap::v1::CreateBrandRequest const& request) {
        return stub_->CreateBrand(context, request);
      },
      request, __func__);
}

StatusOr<google::cloud::iap::v1::Brand>
IdentityAwareProxyOAuthServiceConnectionImpl::GetBrand(
    google::cloud::iap::v1::GetBrandRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(), idempotency_policy()->GetBrand(request),
      [this](grpc::ClientContext& context,
             google::cloud::iap::v1::GetBrandRequest const& request) {
        return stub_->GetBrand(context, request);
      },
      request, __func__);
}

StatusOr<google::cloud::iap::v1::IdentityAwareProxyClient>
IdentityAwareProxyOAuthServiceConnectionImpl::CreateIdentityAwareProxyClient(
    google::cloud::iap::v1::CreateIdentityAwareProxyClientRequest const&
        request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->CreateIdentityAwareProxyClient(request),
      [this](
          grpc::ClientContext& context,
          google::cloud::iap::v1::CreateIdentityAwareProxyClientRequest const&
              request) {
        return stub_->CreateIdentityAwareProxyClient(context, request);
      },
      request, __func__);
}

StreamRange<google::cloud::iap::v1::IdentityAwareProxyClient>
IdentityAwareProxyOAuthServiceConnectionImpl::ListIdentityAwareProxyClients(
    google::cloud::iap::v1::ListIdentityAwareProxyClientsRequest request) {
  request.clear_page_token();
  auto stub = stub_;
  auto retry =
      std::shared_ptr<iap::IdentityAwareProxyOAuthServiceRetryPolicy const>(
          retry_policy());
  auto backoff = std::shared_ptr<BackoffPolicy const>(backoff_policy());
  auto idempotency =
      idempotency_policy()->ListIdentityAwareProxyClients(request);
  char const* function_name = __func__;
  return google::cloud::internal::MakePaginationRange<
      StreamRange<google::cloud::iap::v1::IdentityAwareProxyClient>>(
      std::move(request),
      [stub, retry, backoff, idempotency, function_name](
          google::cloud::iap::v1::ListIdentityAwareProxyClientsRequest const&
              r) {
        return google::cloud::internal::RetryLoop(
            retry->clone(), backoff->clone(), idempotency,
            [stub](grpc::ClientContext& context,
                   google::cloud::iap::v1::
                       ListIdentityAwareProxyClientsRequest const& request) {
              return stub->ListIdentityAwareProxyClients(context, request);
            },
            r, function_name);
      },
      [](google::cloud::iap::v1::ListIdentityAwareProxyClientsResponse r) {
        std::vector<google::cloud::iap::v1::IdentityAwareProxyClient> result(
            r.identity_aware_proxy_clients().size());
        auto& messages = *r.mutable_identity_aware_proxy_clients();
        std::move(messages.begin(), messages.end(), result.begin());
        return result;
      });
}

StatusOr<google::cloud::iap::v1::IdentityAwareProxyClient>
IdentityAwareProxyOAuthServiceConnectionImpl::GetIdentityAwareProxyClient(
    google::cloud::iap::v1::GetIdentityAwareProxyClientRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->GetIdentityAwareProxyClient(request),
      [this](grpc::ClientContext& context,
             google::cloud::iap::v1::GetIdentityAwareProxyClientRequest const&
                 request) {
        return stub_->GetIdentityAwareProxyClient(context, request);
      },
      request, __func__);
}

StatusOr<google::cloud::iap::v1::IdentityAwareProxyClient>
IdentityAwareProxyOAuthServiceConnectionImpl::
    ResetIdentityAwareProxyClientSecret(
        google::cloud::iap::v1::
            ResetIdentityAwareProxyClientSecretRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->ResetIdentityAwareProxyClientSecret(request),
      [this](grpc::ClientContext& context,
             google::cloud::iap::v1::
                 ResetIdentityAwareProxyClientSecretRequest const& request) {
        return stub_->ResetIdentityAwareProxyClientSecret(context, request);
      },
      request, __func__);
}

Status
IdentityAwareProxyOAuthServiceConnectionImpl::DeleteIdentityAwareProxyClient(
    google::cloud::iap::v1::DeleteIdentityAwareProxyClientRequest const&
        request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->DeleteIdentityAwareProxyClient(request),
      [this](
          grpc::ClientContext& context,
          google::cloud::iap::v1::DeleteIdentityAwareProxyClientRequest const&
              request) {
        return stub_->DeleteIdentityAwareProxyClient(context, request);
      },
      request, __func__);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace iap_internal
}  // namespace cloud
}  // namespace google
