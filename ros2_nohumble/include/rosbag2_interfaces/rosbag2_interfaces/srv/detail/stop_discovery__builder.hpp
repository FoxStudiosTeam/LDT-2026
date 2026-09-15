// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rosbag2_interfaces:srv\StopDiscovery.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosbag2_interfaces/srv/stop_discovery.hpp"


#ifndef ROSBAG2_INTERFACES__SRV__DETAIL__STOP_DISCOVERY__BUILDER_HPP_
#define ROSBAG2_INTERFACES__SRV__DETAIL__STOP_DISCOVERY__BUILDER_HPP_

#include <utility>

#include "rosbag2_interfaces/srv/detail/stop_discovery__struct.hpp"
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
auto build<::rosbag2_interfaces::srv::StopDiscovery_Request>()
{
  return ::rosbag2_interfaces::srv::StopDiscovery_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace rosbag2_interfaces


namespace rosbag2_interfaces
{

namespace srv
{

namespace builder
{

class Init_StopDiscovery_Response_error_string
{
public:
  explicit Init_StopDiscovery_Response_error_string(::rosbag2_interfaces::srv::StopDiscovery_Response & msg)
  : msg_(msg)
  {}
  ::rosbag2_interfaces::srv::StopDiscovery_Response error_string(::rosbag2_interfaces::srv::StopDiscovery_Response::_error_string_type arg)
  {
    msg_.error_string = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rosbag2_interfaces::srv::StopDiscovery_Response msg_;
};

class Init_StopDiscovery_Response_return_code
{
public:
  Init_StopDiscovery_Response_return_code()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_StopDiscovery_Response_error_string return_code(::rosbag2_interfaces::srv::StopDiscovery_Response::_return_code_type arg)
  {
    msg_.return_code = std::move(arg);
    return Init_StopDiscovery_Response_error_string(msg_);
  }

private:
  ::rosbag2_interfaces::srv::StopDiscovery_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rosbag2_interfaces::srv::StopDiscovery_Response>()
{
  return rosbag2_interfaces::srv::builder::Init_StopDiscovery_Response_return_code();
}

}  // namespace rosbag2_interfaces


namespace rosbag2_interfaces
{

namespace srv
{

namespace builder
{

class Init_StopDiscovery_Event_response
{
public:
  explicit Init_StopDiscovery_Event_response(::rosbag2_interfaces::srv::StopDiscovery_Event & msg)
  : msg_(msg)
  {}
  ::rosbag2_interfaces::srv::StopDiscovery_Event response(::rosbag2_interfaces::srv::StopDiscovery_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rosbag2_interfaces::srv::StopDiscovery_Event msg_;
};

class Init_StopDiscovery_Event_request
{
public:
  explicit Init_StopDiscovery_Event_request(::rosbag2_interfaces::srv::StopDiscovery_Event & msg)
  : msg_(msg)
  {}
  Init_StopDiscovery_Event_response request(::rosbag2_interfaces::srv::StopDiscovery_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_StopDiscovery_Event_response(msg_);
  }

private:
  ::rosbag2_interfaces::srv::StopDiscovery_Event msg_;
};

class Init_StopDiscovery_Event_info
{
public:
  Init_StopDiscovery_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_StopDiscovery_Event_request info(::rosbag2_interfaces::srv::StopDiscovery_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_StopDiscovery_Event_request(msg_);
  }

private:
  ::rosbag2_interfaces::srv::StopDiscovery_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rosbag2_interfaces::srv::StopDiscovery_Event>()
{
  return rosbag2_interfaces::srv::builder::Init_StopDiscovery_Event_info();
}

}  // namespace rosbag2_interfaces

#endif  // ROSBAG2_INTERFACES__SRV__DETAIL__STOP_DISCOVERY__BUILDER_HPP_
