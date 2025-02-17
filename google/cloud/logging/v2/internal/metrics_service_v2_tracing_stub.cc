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
// source: google/logging/v2/logging_metrics.proto

#include "google/cloud/logging/v2/internal/metrics_service_v2_tracing_stub.h"
#include "google/cloud/internal/grpc_opentelemetry.h"

namespace google {
namespace cloud {
namespace logging_v2_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

#ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

MetricsServiceV2TracingStub::MetricsServiceV2TracingStub(
    std::shared_ptr<MetricsServiceV2Stub> child)
    : child_(std::move(child)) {}

StatusOr<google::logging::v2::ListLogMetricsResponse>
MetricsServiceV2TracingStub::ListLogMetrics(
    grpc::ClientContext& context,
    google::logging::v2::ListLogMetricsRequest const& request) {
  auto span = internal::MakeSpanGrpc("google.logging.v2.MetricsServiceV2",
                                     "ListLogMetrics");
  auto scope = opentelemetry::trace::Scope(span);
  internal::InjectTraceContext(context, internal::CurrentOptions());
  return internal::EndSpan(context, *span,
                           child_->ListLogMetrics(context, request));
}

StatusOr<google::logging::v2::LogMetric>
MetricsServiceV2TracingStub::GetLogMetric(
    grpc::ClientContext& context,
    google::logging::v2::GetLogMetricRequest const& request) {
  auto span = internal::MakeSpanGrpc("google.logging.v2.MetricsServiceV2",
                                     "GetLogMetric");
  auto scope = opentelemetry::trace::Scope(span);
  internal::InjectTraceContext(context, internal::CurrentOptions());
  return internal::EndSpan(context, *span,
                           child_->GetLogMetric(context, request));
}

StatusOr<google::logging::v2::LogMetric>
MetricsServiceV2TracingStub::CreateLogMetric(
    grpc::ClientContext& context,
    google::logging::v2::CreateLogMetricRequest const& request) {
  auto span = internal::MakeSpanGrpc("google.logging.v2.MetricsServiceV2",
                                     "CreateLogMetric");
  auto scope = opentelemetry::trace::Scope(span);
  internal::InjectTraceContext(context, internal::CurrentOptions());
  return internal::EndSpan(context, *span,
                           child_->CreateLogMetric(context, request));
}

StatusOr<google::logging::v2::LogMetric>
MetricsServiceV2TracingStub::UpdateLogMetric(
    grpc::ClientContext& context,
    google::logging::v2::UpdateLogMetricRequest const& request) {
  auto span = internal::MakeSpanGrpc("google.logging.v2.MetricsServiceV2",
                                     "UpdateLogMetric");
  auto scope = opentelemetry::trace::Scope(span);
  internal::InjectTraceContext(context, internal::CurrentOptions());
  return internal::EndSpan(context, *span,
                           child_->UpdateLogMetric(context, request));
}

Status MetricsServiceV2TracingStub::DeleteLogMetric(
    grpc::ClientContext& context,
    google::logging::v2::DeleteLogMetricRequest const& request) {
  auto span = internal::MakeSpanGrpc("google.logging.v2.MetricsServiceV2",
                                     "DeleteLogMetric");
  auto scope = opentelemetry::trace::Scope(span);
  internal::InjectTraceContext(context, internal::CurrentOptions());
  return internal::EndSpan(context, *span,
                           child_->DeleteLogMetric(context, request));
}

#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

std::shared_ptr<MetricsServiceV2Stub> MakeMetricsServiceV2TracingStub(
    std::shared_ptr<MetricsServiceV2Stub> stub) {
#ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
  return std::make_shared<MetricsServiceV2TracingStub>(std::move(stub));
#else
  return stub;
#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace logging_v2_internal
}  // namespace cloud
}  // namespace google
