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

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_IAP_IDENTITY_AWARE_PROXY_O_AUTH_CONNECTION_IDEMPOTENCY_POLICY_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_IAP_IDENTITY_AWARE_PROXY_O_AUTH_CONNECTION_IDEMPOTENCY_POLICY_H

#include "google/cloud/idempotency.h"
#include "google/cloud/internal/retry_policy.h"
#include "google/cloud/version.h"
#include <google/cloud/iap/v1/service.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace iap {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class IdentityAwareProxyOAuthServiceConnectionIdempotencyPolicy {
 public:
  virtual ~IdentityAwareProxyOAuthServiceConnectionIdempotencyPolicy() = 0;

  /// Create a new copy of this object.
  virtual std::unique_ptr<
      IdentityAwareProxyOAuthServiceConnectionIdempotencyPolicy>
  clone() const = 0;

  virtual google::cloud::Idempotency ListBrands(
      google::cloud::iap::v1::ListBrandsRequest const& request) = 0;

  virtual google::cloud::Idempotency CreateBrand(
      google::cloud::iap::v1::CreateBrandRequest const& request) = 0;

  virtual google::cloud::Idempotency GetBrand(
      google::cloud::iap::v1::GetBrandRequest const& request) = 0;

  virtual google::cloud::Idempotency CreateIdentityAwareProxyClient(
      google::cloud::iap::v1::CreateIdentityAwareProxyClientRequest const&
          request) = 0;

  virtual google::cloud::Idempotency ListIdentityAwareProxyClients(
      google::cloud::iap::v1::ListIdentityAwareProxyClientsRequest request) = 0;

  virtual google::cloud::Idempotency GetIdentityAwareProxyClient(
      google::cloud::iap::v1::GetIdentityAwareProxyClientRequest const&
          request) = 0;

  virtual google::cloud::Idempotency ResetIdentityAwareProxyClientSecret(
      google::cloud::iap::v1::ResetIdentityAwareProxyClientSecretRequest const&
          request) = 0;

  virtual google::cloud::Idempotency DeleteIdentityAwareProxyClient(
      google::cloud::iap::v1::DeleteIdentityAwareProxyClientRequest const&
          request) = 0;
};

std::unique_ptr<IdentityAwareProxyOAuthServiceConnectionIdempotencyPolicy>
MakeDefaultIdentityAwareProxyOAuthServiceConnectionIdempotencyPolicy();

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace iap
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_IAP_IDENTITY_AWARE_PROXY_O_AUTH_CONNECTION_IDEMPOTENCY_POLICY_H
