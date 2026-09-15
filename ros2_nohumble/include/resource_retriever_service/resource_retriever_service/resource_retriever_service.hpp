// Copyright 2026 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef RESOURCE_RETRIEVER_SERVICE__RESOURCE_RETRIEVER_SERVICE_HPP_
#define RESOURCE_RETRIEVER_SERVICE__RESOURCE_RETRIEVER_SERVICE_HPP_

#include <resource_retriever_service/visibility_control.h>

#include <memory>
#include <optional>
#include <shared_mutex>
#include <string>
#include <string_view>
#include <unordered_map>
#include <utility>
#include <vector>

#include <rclcpp/logger.hpp>
#include <rclcpp/node_interfaces/node_base_interface.hpp>
#include <rclcpp/node_interfaces/node_interfaces.hpp>
#include <rclcpp/node_interfaces/node_logging_interface.hpp>
#include <rclcpp/node_interfaces/node_services_interface.hpp>
#include <rclcpp/service.hpp>
#include <resource_retriever_interfaces/srv/get_resource.hpp>

namespace resource_retriever_service
{

/// Implementation of the resource retriever service using an in memory map of
/// meshes.
class RESOURCE_RETRIEVER_SERVICE_PUBLIC ResourceRetrieverService
{
public:
  static constexpr std::string_view kDefaultServiceName = "resource_provider";
  using NodeType = rclcpp::node_interfaces::NodeInterfaces<
    rclcpp::node_interfaces::NodeBaseInterface,
    rclcpp::node_interfaces::NodeLoggingInterface,
    rclcpp::node_interfaces::NodeServicesInterface>;

  static std::unique_ptr<ResourceRetrieverService> Create(
    NodeType node, std::string_view service_name = kDefaultServiceName);

  // Remove all resource data currently stored in the service.
  void ClearResourceData();

  // Update the stored resource data with the given map
  void SetResourceData(
    std::unordered_map<std::string, std::vector<uint8_t>> resource_data);

  // Update a specific resource with new data
  void UpdateResourceData(
    const std::string & resource_path,
    std::vector<uint8_t> resource_data);

  // Returns the etag value for the given resource path if one exists, nullopt
  // otherwise
  std::optional<std::string> GetEtagForResourcePath(
    const std::string & resource_path) const;

private:
  using GetResource = ::resource_retriever_interfaces::srv::GetResource;

  void Get(
    const std::shared_ptr<GetResource::Request> request,
    std::shared_ptr<GetResource::Response> response);

  explicit ResourceRetrieverService(NodeType node);
  void Init(NodeType node, std::string_view service_name);

  rclcpp::Service<GetResource>::SharedPtr service_ = nullptr;
  rclcpp::Logger logger_;

  // A map of resource data, where we go from [resource_id] => [etag, datablob]
  // Guarded by data_mutex_ for read/write access.
  std::unordered_map<std::string, std::pair<std::string, std::vector<uint8_t>>>
  data_;
  // Guarded by the data_mutex and used to generate new etags for resources
  int64_t next_etag_value_ = 17;
  mutable std::shared_mutex data_mutex_;
};

}  // namespace resource_retriever_service

#endif  // RESOURCE_RETRIEVER_SERVICE__RESOURCE_RETRIEVER_SERVICE_HPP_
