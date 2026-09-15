// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from nav_msgs:msg\Goals.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nav_msgs/msg/goals.hpp"


#ifndef NAV_MSGS__MSG__DETAIL__GOALS__BUILDER_HPP_
#define NAV_MSGS__MSG__DETAIL__GOALS__BUILDER_HPP_

#include <utility>

#include "nav_msgs/msg/detail/goals__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace nav_msgs
{

namespace msg
{

namespace builder
{

class Init_Goals_goals
{
public:
  explicit Init_Goals_goals(::nav_msgs::msg::Goals & msg)
  : msg_(msg)
  {}
  ::nav_msgs::msg::Goals goals(::nav_msgs::msg::Goals::_goals_type arg)
  {
    msg_.goals = std::move(arg);
    return std::move(msg_);
  }

private:
  ::nav_msgs::msg::Goals msg_;
};

class Init_Goals_header
{
public:
  Init_Goals_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Goals_goals header(::nav_msgs::msg::Goals::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Goals_goals(msg_);
  }

private:
  ::nav_msgs::msg::Goals msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::nav_msgs::msg::Goals>()
{
  return nav_msgs::msg::builder::Init_Goals_header();
}

}  // namespace nav_msgs

#endif  // NAV_MSGS__MSG__DETAIL__GOALS__BUILDER_HPP_
