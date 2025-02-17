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
// source: google/cloud/osconfig/v1/osconfig_zonal_service.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_OSCONFIG_V1_INTERNAL_OS_CONFIG_ZONAL_LOGGING_DECORATOR_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_OSCONFIG_V1_INTERNAL_OS_CONFIG_ZONAL_LOGGING_DECORATOR_H

#include "google/cloud/osconfig/v1/internal/os_config_zonal_stub.h"
#include "google/cloud/tracing_options.h"
#include "google/cloud/version.h"
#include <google/longrunning/operations.grpc.pb.h>
#include <memory>
#include <set>
#include <string>

namespace google {
namespace cloud {
namespace osconfig_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class OsConfigZonalServiceLogging : public OsConfigZonalServiceStub {
 public:
  ~OsConfigZonalServiceLogging() override = default;
  OsConfigZonalServiceLogging(std::shared_ptr<OsConfigZonalServiceStub> child,
                              TracingOptions tracing_options,
                              std::set<std::string> const& components);

  future<StatusOr<google::longrunning::Operation>>
  AsyncCreateOSPolicyAssignment(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::osconfig::v1::CreateOSPolicyAssignmentRequest const&
          request) override;

  future<StatusOr<google::longrunning::Operation>>
  AsyncUpdateOSPolicyAssignment(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::osconfig::v1::UpdateOSPolicyAssignmentRequest const&
          request) override;

  StatusOr<google::cloud::osconfig::v1::OSPolicyAssignment>
  GetOSPolicyAssignment(
      grpc::ClientContext& context,
      google::cloud::osconfig::v1::GetOSPolicyAssignmentRequest const& request)
      override;

  StatusOr<google::cloud::osconfig::v1::ListOSPolicyAssignmentsResponse>
  ListOSPolicyAssignments(
      grpc::ClientContext& context,
      google::cloud::osconfig::v1::ListOSPolicyAssignmentsRequest const&
          request) override;

  StatusOr<google::cloud::osconfig::v1::ListOSPolicyAssignmentRevisionsResponse>
  ListOSPolicyAssignmentRevisions(
      grpc::ClientContext& context,
      google::cloud::osconfig::v1::ListOSPolicyAssignmentRevisionsRequest const&
          request) override;

  future<StatusOr<google::longrunning::Operation>>
  AsyncDeleteOSPolicyAssignment(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::osconfig::v1::DeleteOSPolicyAssignmentRequest const&
          request) override;

  StatusOr<google::cloud::osconfig::v1::OSPolicyAssignmentReport>
  GetOSPolicyAssignmentReport(
      grpc::ClientContext& context,
      google::cloud::osconfig::v1::GetOSPolicyAssignmentReportRequest const&
          request) override;

  StatusOr<google::cloud::osconfig::v1::ListOSPolicyAssignmentReportsResponse>
  ListOSPolicyAssignmentReports(
      grpc::ClientContext& context,
      google::cloud::osconfig::v1::ListOSPolicyAssignmentReportsRequest const&
          request) override;

  StatusOr<google::cloud::osconfig::v1::Inventory> GetInventory(
      grpc::ClientContext& context,
      google::cloud::osconfig::v1::GetInventoryRequest const& request) override;

  StatusOr<google::cloud::osconfig::v1::ListInventoriesResponse>
  ListInventories(grpc::ClientContext& context,
                  google::cloud::osconfig::v1::ListInventoriesRequest const&
                      request) override;

  StatusOr<google::cloud::osconfig::v1::VulnerabilityReport>
  GetVulnerabilityReport(
      grpc::ClientContext& context,
      google::cloud::osconfig::v1::GetVulnerabilityReportRequest const& request)
      override;

  StatusOr<google::cloud::osconfig::v1::ListVulnerabilityReportsResponse>
  ListVulnerabilityReports(
      grpc::ClientContext& context,
      google::cloud::osconfig::v1::ListVulnerabilityReportsRequest const&
          request) override;

  future<StatusOr<google::longrunning::Operation>> AsyncGetOperation(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::longrunning::GetOperationRequest const& request) override;

  future<Status> AsyncCancelOperation(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::longrunning::CancelOperationRequest const& request) override;

 private:
  std::shared_ptr<OsConfigZonalServiceStub> child_;
  TracingOptions tracing_options_;
  bool stream_logging_;
};  // OsConfigZonalServiceLogging

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace osconfig_v1_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_OSCONFIG_V1_INTERNAL_OS_CONFIG_ZONAL_LOGGING_DECORATOR_H
