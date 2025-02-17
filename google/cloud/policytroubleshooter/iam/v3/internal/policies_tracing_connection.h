// Copyright 2023 Google LLC
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
// source: google/iam/v2/policy.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_POLICYTROUBLESHOOTER_IAM_V3_INTERNAL_POLICIES_TRACING_CONNECTION_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_POLICYTROUBLESHOOTER_IAM_V3_INTERNAL_POLICIES_TRACING_CONNECTION_H

#include "google/cloud/policytroubleshooter/iam/v3/policies_connection.h"
#include "google/cloud/version.h"
#include <memory>

namespace google {
namespace cloud {
namespace policytroubleshooter_iam_v3_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

#ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

class PoliciesTracingConnection
    : public policytroubleshooter_iam_v3::PoliciesConnection {
 public:
  ~PoliciesTracingConnection() override = default;

  explicit PoliciesTracingConnection(
      std::shared_ptr<policytroubleshooter_iam_v3::PoliciesConnection> child);

  Options options() override { return child_->options(); }

  StreamRange<google::iam::v2::Policy> ListPolicies(
      google::iam::v2::ListPoliciesRequest request) override;

  StatusOr<google::iam::v2::Policy> GetPolicy(
      google::iam::v2::GetPolicyRequest const& request) override;

  future<StatusOr<google::iam::v2::Policy>> CreatePolicy(
      google::iam::v2::CreatePolicyRequest const& request) override;

  future<StatusOr<google::iam::v2::Policy>> UpdatePolicy(
      google::iam::v2::UpdatePolicyRequest const& request) override;

  future<StatusOr<google::iam::v2::Policy>> DeletePolicy(
      google::iam::v2::DeletePolicyRequest const& request) override;

 private:
  std::shared_ptr<policytroubleshooter_iam_v3::PoliciesConnection> child_;
};

#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

/**
 * Conditionally applies the tracing decorator to the given connection.
 *
 * The connection is only decorated if tracing is enabled (as determined by the
 * connection's options).
 */
std::shared_ptr<policytroubleshooter_iam_v3::PoliciesConnection>
MakePoliciesTracingConnection(
    std::shared_ptr<policytroubleshooter_iam_v3::PoliciesConnection> conn);

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace policytroubleshooter_iam_v3_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_POLICYTROUBLESHOOTER_IAM_V3_INTERNAL_POLICIES_TRACING_CONNECTION_H
