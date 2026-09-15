// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from turtlesim_msgs:srv\SetPen.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "turtlesim_msgs/srv/set_pen.hpp"


#ifndef TURTLESIM_MSGS__SRV__DETAIL__SET_PEN__BUILDER_HPP_
#define TURTLESIM_MSGS__SRV__DETAIL__SET_PEN__BUILDER_HPP_

#include <utility>

#include "turtlesim_msgs/srv/detail/set_pen__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace turtlesim_msgs
{

namespace srv
{

namespace builder
{

class Init_SetPen_Request_off
{
public:
  explicit Init_SetPen_Request_off(::turtlesim_msgs::srv::SetPen_Request & msg)
  : msg_(msg)
  {}
  ::turtlesim_msgs::srv::SetPen_Request off(::turtlesim_msgs::srv::SetPen_Request::_off_type arg)
  {
    msg_.off = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtlesim_msgs::srv::SetPen_Request msg_;
};

class Init_SetPen_Request_width
{
public:
  explicit Init_SetPen_Request_width(::turtlesim_msgs::srv::SetPen_Request & msg)
  : msg_(msg)
  {}
  Init_SetPen_Request_off width(::turtlesim_msgs::srv::SetPen_Request::_width_type arg)
  {
    msg_.width = std::move(arg);
    return Init_SetPen_Request_off(msg_);
  }

private:
  ::turtlesim_msgs::srv::SetPen_Request msg_;
};

class Init_SetPen_Request_b
{
public:
  explicit Init_SetPen_Request_b(::turtlesim_msgs::srv::SetPen_Request & msg)
  : msg_(msg)
  {}
  Init_SetPen_Request_width b(::turtlesim_msgs::srv::SetPen_Request::_b_type arg)
  {
    msg_.b = std::move(arg);
    return Init_SetPen_Request_width(msg_);
  }

private:
  ::turtlesim_msgs::srv::SetPen_Request msg_;
};

class Init_SetPen_Request_g
{
public:
  explicit Init_SetPen_Request_g(::turtlesim_msgs::srv::SetPen_Request & msg)
  : msg_(msg)
  {}
  Init_SetPen_Request_b g(::turtlesim_msgs::srv::SetPen_Request::_g_type arg)
  {
    msg_.g = std::move(arg);
    return Init_SetPen_Request_b(msg_);
  }

private:
  ::turtlesim_msgs::srv::SetPen_Request msg_;
};

class Init_SetPen_Request_r
{
public:
  Init_SetPen_Request_r()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetPen_Request_g r(::turtlesim_msgs::srv::SetPen_Request::_r_type arg)
  {
    msg_.r = std::move(arg);
    return Init_SetPen_Request_g(msg_);
  }

private:
  ::turtlesim_msgs::srv::SetPen_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtlesim_msgs::srv::SetPen_Request>()
{
  return turtlesim_msgs::srv::builder::Init_SetPen_Request_r();
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
auto build<::turtlesim_msgs::srv::SetPen_Response>()
{
  return ::turtlesim_msgs::srv::SetPen_Response(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace turtlesim_msgs


namespace turtlesim_msgs
{

namespace srv
{

namespace builder
{

class Init_SetPen_Event_response
{
public:
  explicit Init_SetPen_Event_response(::turtlesim_msgs::srv::SetPen_Event & msg)
  : msg_(msg)
  {}
  ::turtlesim_msgs::srv::SetPen_Event response(::turtlesim_msgs::srv::SetPen_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtlesim_msgs::srv::SetPen_Event msg_;
};

class Init_SetPen_Event_request
{
public:
  explicit Init_SetPen_Event_request(::turtlesim_msgs::srv::SetPen_Event & msg)
  : msg_(msg)
  {}
  Init_SetPen_Event_response request(::turtlesim_msgs::srv::SetPen_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_SetPen_Event_response(msg_);
  }

private:
  ::turtlesim_msgs::srv::SetPen_Event msg_;
};

class Init_SetPen_Event_info
{
public:
  Init_SetPen_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetPen_Event_request info(::turtlesim_msgs::srv::SetPen_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_SetPen_Event_request(msg_);
  }

private:
  ::turtlesim_msgs::srv::SetPen_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtlesim_msgs::srv::SetPen_Event>()
{
  return turtlesim_msgs::srv::builder::Init_SetPen_Event_info();
}

}  // namespace turtlesim_msgs

#endif  // TURTLESIM_MSGS__SRV__DETAIL__SET_PEN__BUILDER_HPP_
