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
// source: google/cloud/policysimulator/v1/simulator.proto

#include "google/cloud/policysimulator/v1/internal/simulator_option_defaults.h"
#include "google/cloud/policysimulator/v1/simulator_connection.h"
#include "google/cloud/policysimulator/v1/simulator_options.h"
#include "google/cloud/internal/populate_common_options.h"
#include "google/cloud/internal/populate_grpc_options.h"
#include <memory>

namespace google {
namespace cloud {
namespace policysimulator_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

namespace {
auto constexpr kBackoffScaling = 2.0;
}  // namespace

Options SimulatorDefaultOptions(Options options) {
  options = google::cloud::internal::PopulateCommonOptions(
      std::move(options), "GOOGLE_CLOUD_CPP_SIMULATOR_ENDPOINT", "",
      "GOOGLE_CLOUD_CPP_SIMULATOR_AUTHORITY", "policysimulator.googleapis.com");
  options =
      google::cloud::internal::PopulateGrpcOptions(std::move(options), "");
  if (!options.has<policysimulator_v1::SimulatorRetryPolicyOption>()) {
    options.set<policysimulator_v1::SimulatorRetryPolicyOption>(
        policysimulator_v1::SimulatorLimitedTimeRetryPolicy(
            std::chrono::minutes(30))
            .clone());
  }
  if (!options.has<policysimulator_v1::SimulatorBackoffPolicyOption>()) {
    options.set<policysimulator_v1::SimulatorBackoffPolicyOption>(
        ExponentialBackoffPolicy(
            std::chrono::seconds(0), std::chrono::seconds(1),
            std::chrono::minutes(5), kBackoffScaling, kBackoffScaling)
            .clone());
  }
  if (!options.has<policysimulator_v1::SimulatorPollingPolicyOption>()) {
    options.set<policysimulator_v1::SimulatorPollingPolicyOption>(
        GenericPollingPolicy<
            policysimulator_v1::SimulatorRetryPolicyOption::Type,
            policysimulator_v1::SimulatorBackoffPolicyOption::Type>(
            options.get<policysimulator_v1::SimulatorRetryPolicyOption>()
                ->clone(),
            ExponentialBackoffPolicy(std::chrono::seconds(1),
                                     std::chrono::minutes(5), kBackoffScaling)
                .clone())
            .clone());
  }
  if (!options.has<
          policysimulator_v1::SimulatorConnectionIdempotencyPolicyOption>()) {
    options.set<policysimulator_v1::SimulatorConnectionIdempotencyPolicyOption>(
        policysimulator_v1::MakeDefaultSimulatorConnectionIdempotencyPolicy());
  }

  return options;
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace policysimulator_v1_internal
}  // namespace cloud
}  // namespace google
