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
// source: google/cloud/confidentialcomputing/v1/service.proto

#include "google/cloud/confidentialcomputing/v1/confidential_computing_client.h"
#include <memory>

namespace google {
namespace cloud {
namespace confidentialcomputing_v1 {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

ConfidentialComputingClient::ConfidentialComputingClient(
    std::shared_ptr<ConfidentialComputingConnection> connection, Options opts)
    : connection_(std::move(connection)),
      options_(
          internal::MergeOptions(std::move(opts), connection_->options())) {}
ConfidentialComputingClient::~ConfidentialComputingClient() = default;

StatusOr<google::cloud::confidentialcomputing::v1::Challenge>
ConfidentialComputingClient::CreateChallenge(
    std::string const& parent,
    google::cloud::confidentialcomputing::v1::Challenge const& challenge,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::confidentialcomputing::v1::CreateChallengeRequest request;
  request.set_parent(parent);
  *request.mutable_challenge() = challenge;
  return connection_->CreateChallenge(request);
}

StatusOr<google::cloud::confidentialcomputing::v1::Challenge>
ConfidentialComputingClient::CreateChallenge(
    google::cloud::confidentialcomputing::v1::CreateChallengeRequest const&
        request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->CreateChallenge(request);
}

StatusOr<google::cloud::confidentialcomputing::v1::VerifyAttestationResponse>
ConfidentialComputingClient::VerifyAttestation(
    google::cloud::confidentialcomputing::v1::VerifyAttestationRequest const&
        request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->VerifyAttestation(request);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace confidentialcomputing_v1
}  // namespace cloud
}  // namespace google
