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

#ifndef RESOURCE_RETRIEVER_SERVICE_PLUGIN__RESOURCE_RETRIEVER_SERVICE_PLUGIN_HPP_
#define RESOURCE_RETRIEVER_SERVICE_PLUGIN__RESOURCE_RETRIEVER_SERVICE_PLUGIN_HPP_

#include <resource_retriever_service_plugin/visibility_control.h>

#include <mutex>
#include <string>
#include <string_view>
#include <unordered_map>
#include <utility>

#include <rclcpp/callback_group.hpp>
#include <rclcpp/client.hpp>
#include <rclcpp/executors/single_threaded_executor.hpp>
#include <rclcpp/logger.hpp>
#include <rclcpp/node_interfaces/node_base_interface.hpp>
#include <rclcpp/node_interfaces/node_interfaces.hpp>
#include <rclcpp/node_interfaces/node_graph_interface.hpp>
#include <rclcpp/node_interfaces/node_logging_interface.hpp>
#include <rclcpp/node_interfaces/node_services_interface.hpp>
#include <resource_retriever/plugins/retriever_plugin.hpp>
#include <resource_retriever_interfaces/srv/get_resource.hpp>

namespace resource_retriever_service_plugin
{

/// Plugin for resource_retriever that loads resources from a ROS service interface.
class RESOURCE_RETRIEVER_SERVICE_PLUGIN_PUBLIC RosServiceResourceRetriever : public
  resource_retriever::plugins::RetrieverPlugin
{
  static constexpr std::string_view service_uri_prefix = "service://";
  static constexpr std::string_view service_uri_delimiter = ":";
  using GetResource = resource_retriever_interfaces::srv::GetResource;

  RosServiceResourceRetriever() = delete;

public:
  using NodeType = rclcpp::node_interfaces::NodeInterfaces<
    rclcpp::node_interfaces::NodeBaseInterface,
    rclcpp::node_interfaces::NodeGraphInterface,
    rclcpp::node_interfaces::NodeLoggingInterface,
    rclcpp::node_interfaces::NodeServicesInterface>;

  explicit RosServiceResourceRetriever(NodeType ros_node);

  ~RosServiceResourceRetriever() override = default;

  std::string name() override;

  bool can_handle(const std::string & url) override;

  resource_retriever::ResourceSharedPtr get_shared(const std::string & url) override;

private:
  rclcpp::Client<GetResource>::SharedPtr getServiceClient(const std::string & service_name);

  // It should be safe to keep a reference to the node interfaces here, because this
  // plugin will be destroyed with the resource retriever it is used with,
  // which should be destroyed along before the node abstraction is destroyed.
  // Also, since we're keeping callback groups and clients around, we need to
  // ensure the node stays around too.
  NodeType ros_node_;
  rclcpp::CallbackGroup::SharedPtr callback_group_;

  // Maps between the server name and the client pointer that we use
  std::unordered_map<
    std::string,
    rclcpp::Client<GetResource>::SharedPtr
  > clients_;
  std::mutex clients_mutex_;

  rclcpp::executors::SingleThreadedExecutor executor_;
  rclcpp::Logger logger_;

  // Maps [service name][resource path] => pair(etag, resource).
  std::unordered_map<
    std::string,
    std::unordered_map<
      std::string,
      std::pair<std::string, resource_retriever::ResourceSharedPtr>>
  > cached_resources_;
};

}  // namespace resource_retriever_service_plugin

#endif  // RESOURCE_RETRIEVER_SERVICE_PLUGIN__RESOURCE_RETRIEVER_SERVICE_PLUGIN_HPP_
