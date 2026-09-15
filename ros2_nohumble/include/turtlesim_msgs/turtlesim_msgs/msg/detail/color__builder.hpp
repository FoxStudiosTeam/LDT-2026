// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from turtlesim_msgs:msg\Color.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "turtlesim_msgs/msg/color.hpp"


#ifndef TURTLESIM_MSGS__MSG__DETAIL__COLOR__BUILDER_HPP_
#define TURTLESIM_MSGS__MSG__DETAIL__COLOR__BUILDER_HPP_

#include <utility>

#include "turtlesim_msgs/msg/detail/color__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace turtlesim_msgs
{

namespace msg
{

namespace builder
{

class Init_Color_b
{
public:
  explicit Init_Color_b(::turtlesim_msgs::msg::Color & msg)
  : msg_(msg)
  {}
  ::turtlesim_msgs::msg::Color b(::turtlesim_msgs::msg::Color::_b_type arg)
  {
    msg_.b = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtlesim_msgs::msg::Color msg_;
};

class Init_Color_g
{
public:
  explicit Init_Color_g(::turtlesim_msgs::msg::Color & msg)
  : msg_(msg)
  {}
  Init_Color_b g(::turtlesim_msgs::msg::Color::_g_type arg)
  {
    msg_.g = std::move(arg);
    return Init_Color_b(msg_);
  }

private:
  ::turtlesim_msgs::msg::Color msg_;
};

class Init_Color_r
{
public:
  Init_Color_r()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Color_g r(::turtlesim_msgs::msg::Color::_r_type arg)
  {
    msg_.r = std::move(arg);
    return Init_Color_g(msg_);
  }

private:
  ::turtlesim_msgs::msg::Color msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtlesim_msgs::msg::Color>()
{
  return turtlesim_msgs::msg::builder::Init_Color_r();
}

}  // namespace turtlesim_msgs

#endif  // TURTLESIM_MSGS__MSG__DETAIL__COLOR__BUILDER_HPP_
