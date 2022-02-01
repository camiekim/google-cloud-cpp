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

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_IAP_IDENTITY_AWARE_PROXY_ADMIN_CLIENT_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_IAP_IDENTITY_AWARE_PROXY_ADMIN_CLIENT_H

#include "google/cloud/iap/identity_aware_proxy_admin_connection.h"
#include "google/cloud/future.h"
#include "google/cloud/options.h"
#include "google/cloud/polling_policy.h"
#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <memory>

namespace google {
namespace cloud {
namespace iap {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

///
/// APIs for Identity-Aware Proxy Admin configurations.
///
/// @par Equality
///
/// Instances of this class created via copy-construction or copy-assignment
/// always compare equal. Instances created with equal
/// `std::shared_ptr<*Connection>` objects compare equal. Objects that compare
/// equal share the same underlying resources.
///
/// @par Performance
///
/// Creating a new instance of this class is a relatively expensive operation,
/// new objects establish new connections to the service. In contrast,
/// copy-construction, move-construction, and the corresponding assignment
/// operations are relatively efficient as the copies share all underlying
/// resources.
///
/// @par Thread Safety
///
/// Concurrent access to different instances of this class, even if they compare
/// equal, is guaranteed to work. Two or more threads operating on the same
/// instance of this class is not guaranteed to work. Since copy-construction
/// and move-construction is a relatively efficient operation, consider using
/// such a copy when using this class from multiple threads.
///
class IdentityAwareProxyAdminServiceClient {
 public:
  explicit IdentityAwareProxyAdminServiceClient(
      std::shared_ptr<IdentityAwareProxyAdminServiceConnection> connection,
      Options options = {});
  ~IdentityAwareProxyAdminServiceClient();

  //@{
  // @name Copy and move support
  IdentityAwareProxyAdminServiceClient(
      IdentityAwareProxyAdminServiceClient const&) = default;
  IdentityAwareProxyAdminServiceClient& operator=(
      IdentityAwareProxyAdminServiceClient const&) = default;
  IdentityAwareProxyAdminServiceClient(IdentityAwareProxyAdminServiceClient&&) =
      default;
  IdentityAwareProxyAdminServiceClient& operator=(
      IdentityAwareProxyAdminServiceClient&&) = default;
  //@}

  //@{
  // @name Equality
  friend bool operator==(IdentityAwareProxyAdminServiceClient const& a,
                         IdentityAwareProxyAdminServiceClient const& b) {
    return a.connection_ == b.connection_;
  }
  friend bool operator!=(IdentityAwareProxyAdminServiceClient const& a,
                         IdentityAwareProxyAdminServiceClient const& b) {
    return !(a == b);
  }
  //@}

  ///
  /// Sets the access control policy for an Identity-Aware Proxy protected
  /// resource. Replaces any existing policy.
  /// More information about managing access via IAP can be found at:
  /// https://cloud.google.com/iap/docs/managing-access#managing_access_via_the_api
  ///
  /// @param request
  /// @googleapis_link{google::iam::v1::SetIamPolicyRequest,google/iam/v1/iam_policy.proto#L98}
  /// @param options  Optional. Operation options.
  /// @return
  /// @googleapis_link{google::iam::v1::Policy,google/iam/v1/policy.proto#L88}
  ///
  /// [google.iam.v1.SetIamPolicyRequest]:
  /// @googleapis_reference_link{google/iam/v1/iam_policy.proto#L98}
  /// [google.iam.v1.Policy]:
  /// @googleapis_reference_link{google/iam/v1/policy.proto#L88}
  ///
  StatusOr<google::iam::v1::Policy> SetIamPolicy(
      google::iam::v1::SetIamPolicyRequest const& request,
      Options options = {});

  ///
  /// Gets the access control policy for an Identity-Aware Proxy protected
  /// resource.
  /// More information about managing access via IAP can be found at:
  /// https://cloud.google.com/iap/docs/managing-access#managing_access_via_the_api
  ///
  /// @param request
  /// @googleapis_link{google::iam::v1::GetIamPolicyRequest,google/iam/v1/iam_policy.proto#L113}
  /// @param options  Optional. Operation options.
  /// @return
  /// @googleapis_link{google::iam::v1::Policy,google/iam/v1/policy.proto#L88}
  ///
  /// [google.iam.v1.GetIamPolicyRequest]:
  /// @googleapis_reference_link{google/iam/v1/iam_policy.proto#L113}
  /// [google.iam.v1.Policy]:
  /// @googleapis_reference_link{google/iam/v1/policy.proto#L88}
  ///
  StatusOr<google::iam::v1::Policy> GetIamPolicy(
      google::iam::v1::GetIamPolicyRequest const& request,
      Options options = {});

  ///
  /// Returns permissions that a caller has on the Identity-Aware Proxy
  /// protected resource. More information about managing access via IAP can be
  /// found at:
  /// https://cloud.google.com/iap/docs/managing-access#managing_access_via_the_api
  ///
  /// @param request
  /// @googleapis_link{google::iam::v1::TestIamPermissionsRequest,google/iam/v1/iam_policy.proto#L126}
  /// @param options  Optional. Operation options.
  /// @return
  /// @googleapis_link{google::iam::v1::TestIamPermissionsResponse,google/iam/v1/iam_policy.proto#L141}
  ///
  /// [google.iam.v1.TestIamPermissionsRequest]:
  /// @googleapis_reference_link{google/iam/v1/iam_policy.proto#L126}
  /// [google.iam.v1.TestIamPermissionsResponse]:
  /// @googleapis_reference_link{google/iam/v1/iam_policy.proto#L141}
  ///
  StatusOr<google::iam::v1::TestIamPermissionsResponse> TestIamPermissions(
      google::iam::v1::TestIamPermissionsRequest const& request,
      Options options = {});

  ///
  /// Gets the IAP settings on a particular IAP protected resource.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::iap::v1::GetIapSettingsRequest,google/cloud/iap/v1/service.proto#L91}
  /// @param options  Optional. Operation options.
  /// @return
  /// @googleapis_link{google::cloud::iap::v1::IapSettings,google/cloud/iap/v1/service.proto#L112}
  ///
  /// [google.cloud.iap.v1.GetIapSettingsRequest]:
  /// @googleapis_reference_link{google/cloud/iap/v1/service.proto#L91}
  /// [google.cloud.iap.v1.IapSettings]:
  /// @googleapis_reference_link{google/cloud/iap/v1/service.proto#L112}
  ///
  StatusOr<google::cloud::iap::v1::IapSettings> GetIapSettings(
      google::cloud::iap::v1::GetIapSettingsRequest const& request,
      Options options = {});

  ///
  /// Updates the IAP settings on a particular IAP protected resource. It
  /// replaces all fields unless the `update_mask` is set.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::iap::v1::UpdateIapSettingsRequest,google/cloud/iap/v1/service.proto#L99}
  /// @param options  Optional. Operation options.
  /// @return
  /// @googleapis_link{google::cloud::iap::v1::IapSettings,google/cloud/iap/v1/service.proto#L112}
  ///
  /// [google.cloud.iap.v1.UpdateIapSettingsRequest]:
  /// @googleapis_reference_link{google/cloud/iap/v1/service.proto#L99}
  /// [google.cloud.iap.v1.IapSettings]:
  /// @googleapis_reference_link{google/cloud/iap/v1/service.proto#L112}
  ///
  StatusOr<google::cloud::iap::v1::IapSettings> UpdateIapSettings(
      google::cloud::iap::v1::UpdateIapSettingsRequest const& request,
      Options options = {});

 private:
  std::shared_ptr<IdentityAwareProxyAdminServiceConnection> connection_;
  Options options_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace iap
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_IAP_IDENTITY_AWARE_PROXY_ADMIN_CLIENT_H
