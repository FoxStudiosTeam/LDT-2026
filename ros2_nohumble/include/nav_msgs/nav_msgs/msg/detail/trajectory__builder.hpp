// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from nav_msgs:msg\Trajectory.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nav_msgs/msg/trajectory.hpp"


#ifndef NAV_MSGS__MSG__DETAIL__TRAJECTORY__BUILDER_HPP_
#define NAV_MSGS__MSG__DETAIL__TRAJECTORY__BUILDER_HPP_

#include <utility>

#include "nav_msgs/msg/detail/trajectory__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace nav_msgs
{

namespace msg
{

namespace builder
{

class Init_Trajectory_points
{
public:
  explicit Init_Trajectory_points(::nav_msgs::msg::Trajectory & msg)
  : msg_(msg)
  {}
  ::nav_msgs::msg::Trajectory points(::nav_msgs::msg::Trajectory::_points_type arg)
  {
    msg_.points = std::move(arg);
    return std::move(msg_);
  }

private:
  ::nav_msgs::msg::Trajectory msg_;
};

class Init_Trajectory_header
{
public:
  Init_Trajectory_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Trajectory_points header(::nav_msgs::msg::Trajectory::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Trajectory_points(msg_);
  }

private:
  ::nav_msgs::msg::Trajectory msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::nav_msgs::msg::Trajectory>()
{
  return nav_msgs::msg::builder::Init_Trajectory_header();
}

}  // namespace nav_msgs

#endif  // NAV_MSGS__MSG__DETAIL__TRAJECTORY__BUILDER_HPP_
