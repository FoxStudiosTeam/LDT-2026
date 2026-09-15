// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rosbag2_interfaces:srv\IsDiscoveryRunning.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosbag2_interfaces/srv/is_discovery_running.hpp"


#ifndef ROSBAG2_INTERFACES__SRV__DETAIL__IS_DISCOVERY_RUNNING__BUILDER_HPP_
#define ROSBAG2_INTERFACES__SRV__DETAIL__IS_DISCOVERY_RUNNING__BUILDER_HPP_

#include <utility>

#include "rosbag2_interfaces/srv/detail/is_discovery_running__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rosbag2_interfaces
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rosbag2_interfaces::srv::IsDiscoveryRunning_Request>()
{
  return ::rosbag2_interfaces::srv::IsDiscoveryRunning_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace rosbag2_interfaces


namespace rosbag2_interfaces
{

namespace srv
{

namespace builder
{

class Init_IsDiscoveryRunning_Response_running
{
public:
  Init_IsDiscoveryRunning_Response_running()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rosbag2_interfaces::srv::IsDiscoveryRunning_Response running(::rosbag2_interfaces::srv::IsDiscoveryRunning_Response::_running_type arg)
  {
    msg_.running = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rosbag2_interfaces::srv::IsDiscoveryRunning_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rosbag2_interfaces::srv::IsDiscoveryRunning_Response>()
{
  return rosbag2_interfaces::srv::builder::Init_IsDiscoveryRunning_Response_running();
}

}  // namespace rosbag2_interfaces


namespace rosbag2_interfaces
{

namespace srv
{

namespace builder
{

class Init_IsDiscoveryRunning_Event_response
{
public:
  explicit Init_IsDiscoveryRunning_Event_response(::rosbag2_interfaces::srv::IsDiscoveryRunning_Event & msg)
  : msg_(msg)
  {}
  ::rosbag2_interfaces::srv::IsDiscoveryRunning_Event response(::rosbag2_interfaces::srv::IsDiscoveryRunning_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rosbag2_interfaces::srv::IsDiscoveryRunning_Event msg_;
};

class Init_IsDiscoveryRunning_Event_request
{
public:
  explicit Init_IsDiscoveryRunning_Event_request(::rosbag2_interfaces::srv::IsDiscoveryRunning_Event & msg)
  : msg_(msg)
  {}
  Init_IsDiscoveryRunning_Event_response request(::rosbag2_interfaces::srv::IsDiscoveryRunning_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_IsDiscoveryRunning_Event_response(msg_);
  }

private:
  ::rosbag2_interfaces::srv::IsDiscoveryRunning_Event msg_;
};

class Init_IsDiscoveryRunning_Event_info
{
public:
  Init_IsDiscoveryRunning_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_IsDiscoveryRunning_Event_request info(::rosbag2_interfaces::srv::IsDiscoveryRunning_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_IsDiscoveryRunning_Event_request(msg_);
  }

private:
  ::rosbag2_interfaces::srv::IsDiscoveryRunning_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rosbag2_interfaces::srv::IsDiscoveryRunning_Event>()
{
  return rosbag2_interfaces::srv::builder::Init_IsDiscoveryRunning_Event_info();
}

}  // namespace rosbag2_interfaces

#endif  // ROSBAG2_INTERFACES__SRV__DETAIL__IS_DISCOVERY_RUNNING__BUILDER_HPP_
