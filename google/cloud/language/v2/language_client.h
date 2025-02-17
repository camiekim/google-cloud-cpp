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
// source: google/cloud/language/v2/language_service.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_LANGUAGE_V2_LANGUAGE_CLIENT_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_LANGUAGE_V2_LANGUAGE_CLIENT_H

#include "google/cloud/language/v2/language_connection.h"
#include "google/cloud/future.h"
#include "google/cloud/options.h"
#include "google/cloud/polling_policy.h"
#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <memory>

namespace google {
namespace cloud {
namespace language_v2 {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

///
/// Provides text analysis operations such as sentiment analysis and entity
/// recognition.
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
class LanguageServiceClient {
 public:
  explicit LanguageServiceClient(
      std::shared_ptr<LanguageServiceConnection> connection, Options opts = {});
  ~LanguageServiceClient();

  ///@{
  /// @name Copy and move support
  LanguageServiceClient(LanguageServiceClient const&) = default;
  LanguageServiceClient& operator=(LanguageServiceClient const&) = default;
  LanguageServiceClient(LanguageServiceClient&&) = default;
  LanguageServiceClient& operator=(LanguageServiceClient&&) = default;
  ///@}

  ///@{
  /// @name Equality
  friend bool operator==(LanguageServiceClient const& a,
                         LanguageServiceClient const& b) {
    return a.connection_ == b.connection_;
  }
  friend bool operator!=(LanguageServiceClient const& a,
                         LanguageServiceClient const& b) {
    return !(a == b);
  }
  ///@}

  // clang-format off
  ///
  /// Analyzes the sentiment of the provided text.
  ///
  /// @param document  Required. Input document.
  /// @param encoding_type  The encoding type used by the API to calculate sentence offsets.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.language.v2.AnalyzeSentimentResponse])
  ///     is mapped to a C++ class using the [Protobuf mapping rules].
  ///     If the request fails, the [`StatusOr`] contains the error details.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [Long Running Operation]: https://google.aip.dev/151
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.language.v2.AnalyzeSentimentRequest]: @googleapis_reference_link{google/cloud/language/v2/language_service.proto#L346}
  /// [google.cloud.language.v2.AnalyzeSentimentResponse]: @googleapis_reference_link{google/cloud/language/v2/language_service.proto#L355}
  ///
  // clang-format on
  StatusOr<google::cloud::language::v2::AnalyzeSentimentResponse>
  AnalyzeSentiment(google::cloud::language::v2::Document const& document,
                   google::cloud::language::v2::EncodingType encoding_type,
                   Options opts = {});

  // clang-format off
  ///
  /// Analyzes the sentiment of the provided text.
  ///
  /// @param document  Required. Input document.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.language.v2.AnalyzeSentimentResponse])
  ///     is mapped to a C++ class using the [Protobuf mapping rules].
  ///     If the request fails, the [`StatusOr`] contains the error details.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [Long Running Operation]: https://google.aip.dev/151
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.language.v2.AnalyzeSentimentRequest]: @googleapis_reference_link{google/cloud/language/v2/language_service.proto#L346}
  /// [google.cloud.language.v2.AnalyzeSentimentResponse]: @googleapis_reference_link{google/cloud/language/v2/language_service.proto#L355}
  ///
  // clang-format on
  StatusOr<google::cloud::language::v2::AnalyzeSentimentResponse>
  AnalyzeSentiment(google::cloud::language::v2::Document const& document,
                   Options opts = {});

  // clang-format off
  ///
  /// Analyzes the sentiment of the provided text.
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.cloud.language.v2.AnalyzeSentimentRequest].
  ///     Proto messages are converted to C++ classes by Protobuf, using the
  ///     [Protobuf mapping rules].
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.language.v2.AnalyzeSentimentResponse])
  ///     is mapped to a C++ class using the [Protobuf mapping rules].
  ///     If the request fails, the [`StatusOr`] contains the error details.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [Long Running Operation]: https://google.aip.dev/151
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.language.v2.AnalyzeSentimentRequest]: @googleapis_reference_link{google/cloud/language/v2/language_service.proto#L346}
  /// [google.cloud.language.v2.AnalyzeSentimentResponse]: @googleapis_reference_link{google/cloud/language/v2/language_service.proto#L355}
  ///
  // clang-format on
  StatusOr<google::cloud::language::v2::AnalyzeSentimentResponse>
  AnalyzeSentiment(
      google::cloud::language::v2::AnalyzeSentimentRequest const& request,
      Options opts = {});

  // clang-format off
  ///
  /// Finds named entities (currently proper names and common nouns) in the text
  /// along with entity types, probability, mentions for each entity, and
  /// other properties.
  ///
  /// @param document  Required. Input document.
  /// @param encoding_type  The encoding type used by the API to calculate offsets.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.language.v2.AnalyzeEntitiesResponse])
  ///     is mapped to a C++ class using the [Protobuf mapping rules].
  ///     If the request fails, the [`StatusOr`] contains the error details.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [Long Running Operation]: https://google.aip.dev/151
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.language.v2.AnalyzeEntitiesRequest]: @googleapis_reference_link{google/cloud/language/v2/language_service.proto#L374}
  /// [google.cloud.language.v2.AnalyzeEntitiesResponse]: @googleapis_reference_link{google/cloud/language/v2/language_service.proto#L383}
  ///
  // clang-format on
  StatusOr<google::cloud::language::v2::AnalyzeEntitiesResponse>
  AnalyzeEntities(google::cloud::language::v2::Document const& document,
                  google::cloud::language::v2::EncodingType encoding_type,
                  Options opts = {});

  // clang-format off
  ///
  /// Finds named entities (currently proper names and common nouns) in the text
  /// along with entity types, probability, mentions for each entity, and
  /// other properties.
  ///
  /// @param document  Required. Input document.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.language.v2.AnalyzeEntitiesResponse])
  ///     is mapped to a C++ class using the [Protobuf mapping rules].
  ///     If the request fails, the [`StatusOr`] contains the error details.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [Long Running Operation]: https://google.aip.dev/151
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.language.v2.AnalyzeEntitiesRequest]: @googleapis_reference_link{google/cloud/language/v2/language_service.proto#L374}
  /// [google.cloud.language.v2.AnalyzeEntitiesResponse]: @googleapis_reference_link{google/cloud/language/v2/language_service.proto#L383}
  ///
  // clang-format on
  StatusOr<google::cloud::language::v2::AnalyzeEntitiesResponse>
  AnalyzeEntities(google::cloud::language::v2::Document const& document,
                  Options opts = {});

  // clang-format off
  ///
  /// Finds named entities (currently proper names and common nouns) in the text
  /// along with entity types, probability, mentions for each entity, and
  /// other properties.
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.cloud.language.v2.AnalyzeEntitiesRequest].
  ///     Proto messages are converted to C++ classes by Protobuf, using the
  ///     [Protobuf mapping rules].
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.language.v2.AnalyzeEntitiesResponse])
  ///     is mapped to a C++ class using the [Protobuf mapping rules].
  ///     If the request fails, the [`StatusOr`] contains the error details.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [Long Running Operation]: https://google.aip.dev/151
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.language.v2.AnalyzeEntitiesRequest]: @googleapis_reference_link{google/cloud/language/v2/language_service.proto#L374}
  /// [google.cloud.language.v2.AnalyzeEntitiesResponse]: @googleapis_reference_link{google/cloud/language/v2/language_service.proto#L383}
  ///
  // clang-format on
  StatusOr<google::cloud::language::v2::AnalyzeEntitiesResponse>
  AnalyzeEntities(
      google::cloud::language::v2::AnalyzeEntitiesRequest const& request,
      Options opts = {});

  // clang-format off
  ///
  /// Classifies a document into categories.
  ///
  /// @param document  Required. Input document.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.language.v2.ClassifyTextResponse])
  ///     is mapped to a C++ class using the [Protobuf mapping rules].
  ///     If the request fails, the [`StatusOr`] contains the error details.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [Long Running Operation]: https://google.aip.dev/151
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.language.v2.ClassifyTextRequest]: @googleapis_reference_link{google/cloud/language/v2/language_service.proto#L399}
  /// [google.cloud.language.v2.ClassifyTextResponse]: @googleapis_reference_link{google/cloud/language/v2/language_service.proto#L405}
  ///
  // clang-format on
  StatusOr<google::cloud::language::v2::ClassifyTextResponse> ClassifyText(
      google::cloud::language::v2::Document const& document, Options opts = {});

  // clang-format off
  ///
  /// Classifies a document into categories.
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.cloud.language.v2.ClassifyTextRequest].
  ///     Proto messages are converted to C++ classes by Protobuf, using the
  ///     [Protobuf mapping rules].
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.language.v2.ClassifyTextResponse])
  ///     is mapped to a C++ class using the [Protobuf mapping rules].
  ///     If the request fails, the [`StatusOr`] contains the error details.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [Long Running Operation]: https://google.aip.dev/151
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.language.v2.ClassifyTextRequest]: @googleapis_reference_link{google/cloud/language/v2/language_service.proto#L399}
  /// [google.cloud.language.v2.ClassifyTextResponse]: @googleapis_reference_link{google/cloud/language/v2/language_service.proto#L405}
  ///
  // clang-format on
  StatusOr<google::cloud::language::v2::ClassifyTextResponse> ClassifyText(
      google::cloud::language::v2::ClassifyTextRequest const& request,
      Options opts = {});

  // clang-format off
  ///
  /// Moderates a document for harmful and sensitive categories.
  ///
  /// @param document  Required. Input document.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.language.v2.ModerateTextResponse])
  ///     is mapped to a C++ class using the [Protobuf mapping rules].
  ///     If the request fails, the [`StatusOr`] contains the error details.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [Long Running Operation]: https://google.aip.dev/151
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.language.v2.ModerateTextRequest]: @googleapis_reference_link{google/cloud/language/v2/language_service.proto#L421}
  /// [google.cloud.language.v2.ModerateTextResponse]: @googleapis_reference_link{google/cloud/language/v2/language_service.proto#L427}
  ///
  // clang-format on
  StatusOr<google::cloud::language::v2::ModerateTextResponse> ModerateText(
      google::cloud::language::v2::Document const& document, Options opts = {});

  // clang-format off
  ///
  /// Moderates a document for harmful and sensitive categories.
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.cloud.language.v2.ModerateTextRequest].
  ///     Proto messages are converted to C++ classes by Protobuf, using the
  ///     [Protobuf mapping rules].
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.language.v2.ModerateTextResponse])
  ///     is mapped to a C++ class using the [Protobuf mapping rules].
  ///     If the request fails, the [`StatusOr`] contains the error details.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [Long Running Operation]: https://google.aip.dev/151
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.language.v2.ModerateTextRequest]: @googleapis_reference_link{google/cloud/language/v2/language_service.proto#L421}
  /// [google.cloud.language.v2.ModerateTextResponse]: @googleapis_reference_link{google/cloud/language/v2/language_service.proto#L427}
  ///
  // clang-format on
  StatusOr<google::cloud::language::v2::ModerateTextResponse> ModerateText(
      google::cloud::language::v2::ModerateTextRequest const& request,
      Options opts = {});

  // clang-format off
  ///
  /// A convenience method that provides all features in one call.
  ///
  /// @param document  Required. Input document.
  /// @param features  Required. The enabled features.
  /// @param encoding_type  The encoding type used by the API to calculate offsets.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.language.v2.AnnotateTextResponse])
  ///     is mapped to a C++ class using the [Protobuf mapping rules].
  ///     If the request fails, the [`StatusOr`] contains the error details.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [Long Running Operation]: https://google.aip.dev/151
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.language.v2.AnnotateTextRequest]: @googleapis_reference_link{google/cloud/language/v2/language_service.proto#L444}
  /// [google.cloud.language.v2.AnnotateTextResponse]: @googleapis_reference_link{google/cloud/language/v2/language_service.proto#L473}
  ///
  // clang-format on
  StatusOr<google::cloud::language::v2::AnnotateTextResponse> AnnotateText(
      google::cloud::language::v2::Document const& document,
      google::cloud::language::v2::AnnotateTextRequest::Features const&
          features,
      google::cloud::language::v2::EncodingType encoding_type,
      Options opts = {});

  // clang-format off
  ///
  /// A convenience method that provides all features in one call.
  ///
  /// @param document  Required. Input document.
  /// @param features  Required. The enabled features.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.language.v2.AnnotateTextResponse])
  ///     is mapped to a C++ class using the [Protobuf mapping rules].
  ///     If the request fails, the [`StatusOr`] contains the error details.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [Long Running Operation]: https://google.aip.dev/151
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.language.v2.AnnotateTextRequest]: @googleapis_reference_link{google/cloud/language/v2/language_service.proto#L444}
  /// [google.cloud.language.v2.AnnotateTextResponse]: @googleapis_reference_link{google/cloud/language/v2/language_service.proto#L473}
  ///
  // clang-format on
  StatusOr<google::cloud::language::v2::AnnotateTextResponse> AnnotateText(
      google::cloud::language::v2::Document const& document,
      google::cloud::language::v2::AnnotateTextRequest::Features const&
          features,
      Options opts = {});

  // clang-format off
  ///
  /// A convenience method that provides all features in one call.
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.cloud.language.v2.AnnotateTextRequest].
  ///     Proto messages are converted to C++ classes by Protobuf, using the
  ///     [Protobuf mapping rules].
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.language.v2.AnnotateTextResponse])
  ///     is mapped to a C++ class using the [Protobuf mapping rules].
  ///     If the request fails, the [`StatusOr`] contains the error details.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [Long Running Operation]: https://google.aip.dev/151
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.language.v2.AnnotateTextRequest]: @googleapis_reference_link{google/cloud/language/v2/language_service.proto#L444}
  /// [google.cloud.language.v2.AnnotateTextResponse]: @googleapis_reference_link{google/cloud/language/v2/language_service.proto#L473}
  ///
  // clang-format on
  StatusOr<google::cloud::language::v2::AnnotateTextResponse> AnnotateText(
      google::cloud::language::v2::AnnotateTextRequest const& request,
      Options opts = {});

 private:
  std::shared_ptr<LanguageServiceConnection> connection_;
  Options options_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace language_v2
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_LANGUAGE_V2_LANGUAGE_CLIENT_H
