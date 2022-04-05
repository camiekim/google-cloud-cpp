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

#include "google/cloud/retail/internal/product_stub.h"
#include "google/cloud/grpc_error_delegate.h"
#include "google/cloud/status_or.h"
#include <google/cloud/retail/v2/product_service.grpc.pb.h>
#include <google/longrunning/operations.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace retail_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

ProductServiceStub::~ProductServiceStub() = default;

StatusOr<google::cloud::retail::v2::Product>
DefaultProductServiceStub::CreateProduct(
    grpc::ClientContext& client_context,
    google::cloud::retail::v2::CreateProductRequest const& request) {
  google::cloud::retail::v2::Product response;
  auto status = grpc_stub_->CreateProduct(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

StatusOr<google::cloud::retail::v2::Product>
DefaultProductServiceStub::GetProduct(
    grpc::ClientContext& client_context,
    google::cloud::retail::v2::GetProductRequest const& request) {
  google::cloud::retail::v2::Product response;
  auto status = grpc_stub_->GetProduct(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

StatusOr<google::cloud::retail::v2::ListProductsResponse>
DefaultProductServiceStub::ListProducts(
    grpc::ClientContext& client_context,
    google::cloud::retail::v2::ListProductsRequest const& request) {
  google::cloud::retail::v2::ListProductsResponse response;
  auto status = grpc_stub_->ListProducts(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

StatusOr<google::cloud::retail::v2::Product>
DefaultProductServiceStub::UpdateProduct(
    grpc::ClientContext& client_context,
    google::cloud::retail::v2::UpdateProductRequest const& request) {
  google::cloud::retail::v2::Product response;
  auto status = grpc_stub_->UpdateProduct(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

Status DefaultProductServiceStub::DeleteProduct(
    grpc::ClientContext& client_context,
    google::cloud::retail::v2::DeleteProductRequest const& request) {
  google::protobuf::Empty response;
  auto status = grpc_stub_->DeleteProduct(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return google::cloud::Status();
}

future<StatusOr<google::longrunning::Operation>>
DefaultProductServiceStub::AsyncImportProducts(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::retail::v2::ImportProductsRequest const& request) {
  return cq.MakeUnaryRpc(
      [this](grpc::ClientContext* context,
             google::cloud::retail::v2::ImportProductsRequest const& request,
             grpc::CompletionQueue* cq) {
        return grpc_stub_->AsyncImportProducts(context, request, cq);
      },
      request, std::move(context));
}

future<StatusOr<google::longrunning::Operation>>
DefaultProductServiceStub::AsyncSetInventory(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::retail::v2::SetInventoryRequest const& request) {
  return cq.MakeUnaryRpc(
      [this](grpc::ClientContext* context,
             google::cloud::retail::v2::SetInventoryRequest const& request,
             grpc::CompletionQueue* cq) {
        return grpc_stub_->AsyncSetInventory(context, request, cq);
      },
      request, std::move(context));
}

future<StatusOr<google::longrunning::Operation>>
DefaultProductServiceStub::AsyncAddFulfillmentPlaces(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::retail::v2::AddFulfillmentPlacesRequest const& request) {
  return cq.MakeUnaryRpc(
      [this](
          grpc::ClientContext* context,
          google::cloud::retail::v2::AddFulfillmentPlacesRequest const& request,
          grpc::CompletionQueue* cq) {
        return grpc_stub_->AsyncAddFulfillmentPlaces(context, request, cq);
      },
      request, std::move(context));
}

future<StatusOr<google::longrunning::Operation>>
DefaultProductServiceStub::AsyncRemoveFulfillmentPlaces(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::retail::v2::RemoveFulfillmentPlacesRequest const& request) {
  return cq.MakeUnaryRpc(
      [this](grpc::ClientContext* context,
             google::cloud::retail::v2::RemoveFulfillmentPlacesRequest const&
                 request,
             grpc::CompletionQueue* cq) {
        return grpc_stub_->AsyncRemoveFulfillmentPlaces(context, request, cq);
      },
      request, std::move(context));
}

future<StatusOr<google::longrunning::Operation>>
DefaultProductServiceStub::AsyncAddLocalInventories(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::retail::v2::AddLocalInventoriesRequest const& request) {
  return cq.MakeUnaryRpc(
      [this](
          grpc::ClientContext* context,
          google::cloud::retail::v2::AddLocalInventoriesRequest const& request,
          grpc::CompletionQueue* cq) {
        return grpc_stub_->AsyncAddLocalInventories(context, request, cq);
      },
      request, std::move(context));
}

future<StatusOr<google::longrunning::Operation>>
DefaultProductServiceStub::AsyncRemoveLocalInventories(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::retail::v2::RemoveLocalInventoriesRequest const& request) {
  return cq.MakeUnaryRpc(
      [this](grpc::ClientContext* context,
             google::cloud::retail::v2::RemoveLocalInventoriesRequest const&
                 request,
             grpc::CompletionQueue* cq) {
        return grpc_stub_->AsyncRemoveLocalInventories(context, request, cq);
      },
      request, std::move(context));
}

future<StatusOr<google::longrunning::Operation>>
DefaultProductServiceStub::AsyncGetOperation(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::longrunning::GetOperationRequest const& request) {
  return cq.MakeUnaryRpc(
      [this](grpc::ClientContext* context,
             google::longrunning::GetOperationRequest const& request,
             grpc::CompletionQueue* cq) {
        return operations_->AsyncGetOperation(context, request, cq);
      },
      request, std::move(context));
}

future<Status> DefaultProductServiceStub::AsyncCancelOperation(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::longrunning::CancelOperationRequest const& request) {
  return cq
      .MakeUnaryRpc(
          [this](grpc::ClientContext* context,
                 google::longrunning::CancelOperationRequest const& request,
                 grpc::CompletionQueue* cq) {
            return operations_->AsyncCancelOperation(context, request, cq);
          },
          request, std::move(context))
      .then([](future<StatusOr<google::protobuf::Empty>> f) {
        return f.get().status();
      });
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace retail_internal
}  // namespace cloud
}  // namespace google
