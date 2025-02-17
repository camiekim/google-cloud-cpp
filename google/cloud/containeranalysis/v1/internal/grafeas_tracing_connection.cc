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
// source: grafeas/v1/grafeas.proto

#include "google/cloud/containeranalysis/v1/internal/grafeas_tracing_connection.h"
#include "google/cloud/internal/opentelemetry.h"
#include "google/cloud/internal/traced_stream_range.h"
#include <memory>

namespace google {
namespace cloud {
namespace containeranalysis_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

#ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

GrafeasTracingConnection::GrafeasTracingConnection(
    std::shared_ptr<containeranalysis_v1::GrafeasConnection> child)
    : child_(std::move(child)) {}

StatusOr<grafeas::v1::Occurrence> GrafeasTracingConnection::GetOccurrence(
    grafeas::v1::GetOccurrenceRequest const& request) {
  auto span = internal::MakeSpan(
      "containeranalysis_v1::GrafeasConnection::GetOccurrence");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->GetOccurrence(request));
}

StreamRange<grafeas::v1::Occurrence> GrafeasTracingConnection::ListOccurrences(
    grafeas::v1::ListOccurrencesRequest request) {
  auto span = internal::MakeSpan(
      "containeranalysis_v1::GrafeasConnection::ListOccurrences");
  auto scope = opentelemetry::trace::Scope(span);
  auto sr = child_->ListOccurrences(std::move(request));
  return internal::MakeTracedStreamRange<grafeas::v1::Occurrence>(
      std::move(span), std::move(sr));
}

Status GrafeasTracingConnection::DeleteOccurrence(
    grafeas::v1::DeleteOccurrenceRequest const& request) {
  auto span = internal::MakeSpan(
      "containeranalysis_v1::GrafeasConnection::DeleteOccurrence");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->DeleteOccurrence(request));
}

StatusOr<grafeas::v1::Occurrence> GrafeasTracingConnection::CreateOccurrence(
    grafeas::v1::CreateOccurrenceRequest const& request) {
  auto span = internal::MakeSpan(
      "containeranalysis_v1::GrafeasConnection::CreateOccurrence");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->CreateOccurrence(request));
}

StatusOr<grafeas::v1::BatchCreateOccurrencesResponse>
GrafeasTracingConnection::BatchCreateOccurrences(
    grafeas::v1::BatchCreateOccurrencesRequest const& request) {
  auto span = internal::MakeSpan(
      "containeranalysis_v1::GrafeasConnection::BatchCreateOccurrences");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->BatchCreateOccurrences(request));
}

StatusOr<grafeas::v1::Occurrence> GrafeasTracingConnection::UpdateOccurrence(
    grafeas::v1::UpdateOccurrenceRequest const& request) {
  auto span = internal::MakeSpan(
      "containeranalysis_v1::GrafeasConnection::UpdateOccurrence");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->UpdateOccurrence(request));
}

StatusOr<grafeas::v1::Note> GrafeasTracingConnection::GetOccurrenceNote(
    grafeas::v1::GetOccurrenceNoteRequest const& request) {
  auto span = internal::MakeSpan(
      "containeranalysis_v1::GrafeasConnection::GetOccurrenceNote");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->GetOccurrenceNote(request));
}

StatusOr<grafeas::v1::Note> GrafeasTracingConnection::GetNote(
    grafeas::v1::GetNoteRequest const& request) {
  auto span =
      internal::MakeSpan("containeranalysis_v1::GrafeasConnection::GetNote");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->GetNote(request));
}

StreamRange<grafeas::v1::Note> GrafeasTracingConnection::ListNotes(
    grafeas::v1::ListNotesRequest request) {
  auto span =
      internal::MakeSpan("containeranalysis_v1::GrafeasConnection::ListNotes");
  auto scope = opentelemetry::trace::Scope(span);
  auto sr = child_->ListNotes(std::move(request));
  return internal::MakeTracedStreamRange<grafeas::v1::Note>(std::move(span),
                                                            std::move(sr));
}

Status GrafeasTracingConnection::DeleteNote(
    grafeas::v1::DeleteNoteRequest const& request) {
  auto span =
      internal::MakeSpan("containeranalysis_v1::GrafeasConnection::DeleteNote");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->DeleteNote(request));
}

StatusOr<grafeas::v1::Note> GrafeasTracingConnection::CreateNote(
    grafeas::v1::CreateNoteRequest const& request) {
  auto span =
      internal::MakeSpan("containeranalysis_v1::GrafeasConnection::CreateNote");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->CreateNote(request));
}

StatusOr<grafeas::v1::BatchCreateNotesResponse>
GrafeasTracingConnection::BatchCreateNotes(
    grafeas::v1::BatchCreateNotesRequest const& request) {
  auto span = internal::MakeSpan(
      "containeranalysis_v1::GrafeasConnection::BatchCreateNotes");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->BatchCreateNotes(request));
}

StatusOr<grafeas::v1::Note> GrafeasTracingConnection::UpdateNote(
    grafeas::v1::UpdateNoteRequest const& request) {
  auto span =
      internal::MakeSpan("containeranalysis_v1::GrafeasConnection::UpdateNote");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->UpdateNote(request));
}

StreamRange<grafeas::v1::Occurrence>
GrafeasTracingConnection::ListNoteOccurrences(
    grafeas::v1::ListNoteOccurrencesRequest request) {
  auto span = internal::MakeSpan(
      "containeranalysis_v1::GrafeasConnection::ListNoteOccurrences");
  auto scope = opentelemetry::trace::Scope(span);
  auto sr = child_->ListNoteOccurrences(std::move(request));
  return internal::MakeTracedStreamRange<grafeas::v1::Occurrence>(
      std::move(span), std::move(sr));
}

#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

std::shared_ptr<containeranalysis_v1::GrafeasConnection>
MakeGrafeasTracingConnection(
    std::shared_ptr<containeranalysis_v1::GrafeasConnection> conn) {
#ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
  if (internal::TracingEnabled(conn->options())) {
    conn = std::make_shared<GrafeasTracingConnection>(std::move(conn));
  }
#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
  return conn;
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace containeranalysis_v1_internal
}  // namespace cloud
}  // namespace google
