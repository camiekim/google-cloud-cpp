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
// source: google/cloud/retail/v2/product_service.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_RETAIL_PRODUCT_CONNECTION_IDEMPOTENCY_POLICY_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_RETAIL_PRODUCT_CONNECTION_IDEMPOTENCY_POLICY_H

#include "google/cloud/idempotency.h"
#include "google/cloud/internal/retry_policy.h"
#include "google/cloud/version.h"
#include <google/cloud/retail/v2/product_service.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace retail {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class ProductServiceConnectionIdempotencyPolicy {
 public:
  virtual ~ProductServiceConnectionIdempotencyPolicy() = 0;

  /// Create a new copy of this object.
  virtual std::unique_ptr<ProductServiceConnectionIdempotencyPolicy> clone()
      const = 0;

  virtual google::cloud::Idempotency CreateProduct(
      google::cloud::retail::v2::CreateProductRequest const& request) = 0;

  virtual google::cloud::Idempotency GetProduct(
      google::cloud::retail::v2::GetProductRequest const& request) = 0;

  virtual google::cloud::Idempotency ListProducts(
      google::cloud::retail::v2::ListProductsRequest request) = 0;

  virtual google::cloud::Idempotency UpdateProduct(
      google::cloud::retail::v2::UpdateProductRequest const& request) = 0;

  virtual google::cloud::Idempotency DeleteProduct(
      google::cloud::retail::v2::DeleteProductRequest const& request) = 0;

  virtual google::cloud::Idempotency ImportProducts(
      google::cloud::retail::v2::ImportProductsRequest const& request) = 0;

  virtual google::cloud::Idempotency SetInventory(
      google::cloud::retail::v2::SetInventoryRequest const& request) = 0;

  virtual google::cloud::Idempotency AddFulfillmentPlaces(
      google::cloud::retail::v2::AddFulfillmentPlacesRequest const&
          request) = 0;

  virtual google::cloud::Idempotency RemoveFulfillmentPlaces(
      google::cloud::retail::v2::RemoveFulfillmentPlacesRequest const&
          request) = 0;

  virtual google::cloud::Idempotency AddLocalInventories(
      google::cloud::retail::v2::AddLocalInventoriesRequest const& request) = 0;

  virtual google::cloud::Idempotency RemoveLocalInventories(
      google::cloud::retail::v2::RemoveLocalInventoriesRequest const&
          request) = 0;
};

std::unique_ptr<ProductServiceConnectionIdempotencyPolicy>
MakeDefaultProductServiceConnectionIdempotencyPolicy();

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace retail
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_RETAIL_PRODUCT_CONNECTION_IDEMPOTENCY_POLICY_H
