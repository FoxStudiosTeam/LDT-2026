// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from turtlesim_msgs:srv\Kill.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "turtlesim_msgs/srv/kill.hpp"


#ifndef TURTLESIM_MSGS__SRV__DETAIL__KILL__BUILDER_HPP_
#define TURTLESIM_MSGS__SRV__DETAIL__KILL__BUILDER_HPP_

#include <utility>

#include "turtlesim_msgs/srv/detail/kill__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace turtlesim_msgs
{

namespace srv
{

namespace builder
{

class Init_Kill_Request_name
{
public:
  Init_Kill_Request_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::turtlesim_msgs::srv::Kill_Request name(::turtlesim_msgs::srv::Kill_Request::_name_type arg)
  {
    msg_.name = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtlesim_msgs::srv::Kill_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtlesim_msgs::srv::Kill_Request>()
{
  return turtlesim_msgs::srv::builder::Init_Kill_Request_name();
}

}  // namespace turtlesim_msgs


namespace turtlesim_msgs
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtlesim_msgs::srv::Kill_Response>()
{
  return ::turtlesim_msgs::srv::Kill_Response(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace turtlesim_msgs


namespace turtlesim_msgs
{

namespace srv
{

namespace builder
{

class Init_Kill_Event_response
{
public:
  explicit Init_Kill_Event_response(::turtlesim_msgs::srv::Kill_Event & msg)
  : msg_(msg)
  {}
  ::turtlesim_msgs::srv::Kill_Event response(::turtlesim_msgs::srv::Kill_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtlesim_msgs::srv::Kill_Event msg_;
};

class Init_Kill_Event_request
{
public:
  explicit Init_Kill_Event_request(::turtlesim_msgs::srv::Kill_Event & msg)
  : msg_(msg)
  {}
  Init_Kill_Event_response request(::turtlesim_msgs::srv::Kill_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_Kill_Event_response(msg_);
  }

private:
  ::turtlesim_msgs::srv::Kill_Event msg_;
};

class Init_Kill_Event_info
{
public:
  Init_Kill_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Kill_Event_request info(::turtlesim_msgs::srv::Kill_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_Kill_Event_request(msg_);
  }

private:
  ::turtlesim_msgs::srv::Kill_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtlesim_msgs::srv::Kill_Event>()
{
  return turtlesim_msgs::srv::builder::Init_Kill_Event_info();
}

}  // namespace turtlesim_msgs

#endif  // TURTLESIM_MSGS__SRV__DETAIL__KILL__BUILDER_HPP_
