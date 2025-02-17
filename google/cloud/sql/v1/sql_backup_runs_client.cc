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
// source: google/cloud/sql/v1/cloud_sql_backup_runs.proto

#include "google/cloud/sql/v1/sql_backup_runs_client.h"
#include <memory>

namespace google {
namespace cloud {
namespace sql_v1 {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

SqlBackupRunsServiceClient::SqlBackupRunsServiceClient(
    ExperimentalTag, std::shared_ptr<SqlBackupRunsServiceConnection> connection,
    Options opts)
    : connection_(std::move(connection)),
      options_(
          internal::MergeOptions(std::move(opts), connection_->options())) {}
SqlBackupRunsServiceClient::~SqlBackupRunsServiceClient() = default;

StatusOr<google::cloud::sql::v1::Operation> SqlBackupRunsServiceClient::Delete(
    google::cloud::sql::v1::SqlBackupRunsDeleteRequest const& request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->Delete(request);
}

StatusOr<google::cloud::sql::v1::BackupRun> SqlBackupRunsServiceClient::Get(
    google::cloud::sql::v1::SqlBackupRunsGetRequest const& request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->Get(request);
}

StatusOr<google::cloud::sql::v1::Operation> SqlBackupRunsServiceClient::Insert(
    google::cloud::sql::v1::SqlBackupRunsInsertRequest const& request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->Insert(request);
}

StatusOr<google::cloud::sql::v1::BackupRunsListResponse>
SqlBackupRunsServiceClient::List(
    google::cloud::sql::v1::SqlBackupRunsListRequest const& request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->List(request);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace sql_v1
}  // namespace cloud
}  // namespace google
