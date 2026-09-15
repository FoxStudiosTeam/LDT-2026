// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rosbag2_interfaces:srv\Seek.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosbag2_interfaces/srv/seek.hpp"


#ifndef ROSBAG2_INTERFACES__SRV__DETAIL__SEEK__BUILDER_HPP_
#define ROSBAG2_INTERFACES__SRV__DETAIL__SEEK__BUILDER_HPP_

#include <utility>

#include "rosbag2_interfaces/srv/detail/seek__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rosbag2_interfaces
{

namespace srv
{

namespace builder
{

class Init_Seek_Request_time
{
public:
  Init_Seek_Request_time()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rosbag2_interfaces::srv::Seek_Request time(::rosbag2_interfaces::srv::Seek_Request::_time_type arg)
  {
    msg_.time = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rosbag2_interfaces::srv::Seek_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rosbag2_interfaces::srv::Seek_Request>()
{
  return rosbag2_interfaces::srv::builder::Init_Seek_Request_time();
}

}  // namespace rosbag2_interfaces


namespace rosbag2_interfaces
{

namespace srv
{

namespace builder
{

class Init_Seek_Response_success
{
public:
  Init_Seek_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rosbag2_interfaces::srv::Seek_Response success(::rosbag2_interfaces::srv::Seek_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rosbag2_interfaces::srv::Seek_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rosbag2_interfaces::srv::Seek_Response>()
{
  return rosbag2_interfaces::srv::builder::Init_Seek_Response_success();
}

}  // namespace rosbag2_interfaces


namespace rosbag2_interfaces
{

namespace srv
{

namespace builder
{

class Init_Seek_Event_response
{
public:
  explicit Init_Seek_Event_response(::rosbag2_interfaces::srv::Seek_Event & msg)
  : msg_(msg)
  {}
  ::rosbag2_interfaces::srv::Seek_Event response(::rosbag2_interfaces::srv::Seek_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rosbag2_interfaces::srv::Seek_Event msg_;
};

class Init_Seek_Event_request
{
public:
  explicit Init_Seek_Event_request(::rosbag2_interfaces::srv::Seek_Event & msg)
  : msg_(msg)
  {}
  Init_Seek_Event_response request(::rosbag2_interfaces::srv::Seek_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_Seek_Event_response(msg_);
  }

private:
  ::rosbag2_interfaces::srv::Seek_Event msg_;
};

class Init_Seek_Event_info
{
public:
  Init_Seek_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Seek_Event_request info(::rosbag2_interfaces::srv::Seek_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_Seek_Event_request(msg_);
  }

private:
  ::rosbag2_interfaces::srv::Seek_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rosbag2_interfaces::srv::Seek_Event>()
{
  return rosbag2_interfaces::srv::builder::Init_Seek_Event_info();
}

}  // namespace rosbag2_interfaces

#endif  // ROSBAG2_INTERFACES__SRV__DETAIL__SEEK__BUILDER_HPP_
