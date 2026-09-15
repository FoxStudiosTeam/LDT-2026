// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from nav_msgs:msg\TrajectoryPoint.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nav_msgs/msg/trajectory_point.hpp"


#ifndef NAV_MSGS__MSG__DETAIL__TRAJECTORY_POINT__BUILDER_HPP_
#define NAV_MSGS__MSG__DETAIL__TRAJECTORY_POINT__BUILDER_HPP_

#include <utility>

#include "nav_msgs/msg/detail/trajectory_point__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace nav_msgs
{

namespace msg
{

namespace builder
{

class Init_TrajectoryPoint_effort
{
public:
  explicit Init_TrajectoryPoint_effort(::nav_msgs::msg::TrajectoryPoint & msg)
  : msg_(msg)
  {}
  ::nav_msgs::msg::TrajectoryPoint effort(::nav_msgs::msg::TrajectoryPoint::_effort_type arg)
  {
    msg_.effort = std::move(arg);
    return std::move(msg_);
  }

private:
  ::nav_msgs::msg::TrajectoryPoint msg_;
};

class Init_TrajectoryPoint_acceleration
{
public:
  explicit Init_TrajectoryPoint_acceleration(::nav_msgs::msg::TrajectoryPoint & msg)
  : msg_(msg)
  {}
  Init_TrajectoryPoint_effort acceleration(::nav_msgs::msg::TrajectoryPoint::_acceleration_type arg)
  {
    msg_.acceleration = std::move(arg);
    return Init_TrajectoryPoint_effort(msg_);
  }

private:
  ::nav_msgs::msg::TrajectoryPoint msg_;
};

class Init_TrajectoryPoint_velocity
{
public:
  explicit Init_TrajectoryPoint_velocity(::nav_msgs::msg::TrajectoryPoint & msg)
  : msg_(msg)
  {}
  Init_TrajectoryPoint_acceleration velocity(::nav_msgs::msg::TrajectoryPoint::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return Init_TrajectoryPoint_acceleration(msg_);
  }

private:
  ::nav_msgs::msg::TrajectoryPoint msg_;
};

class Init_TrajectoryPoint_pose
{
public:
  explicit Init_TrajectoryPoint_pose(::nav_msgs::msg::TrajectoryPoint & msg)
  : msg_(msg)
  {}
  Init_TrajectoryPoint_velocity pose(::nav_msgs::msg::TrajectoryPoint::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return Init_TrajectoryPoint_velocity(msg_);
  }

private:
  ::nav_msgs::msg::TrajectoryPoint msg_;
};

class Init_TrajectoryPoint_header
{
public:
  Init_TrajectoryPoint_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TrajectoryPoint_pose header(::nav_msgs::msg::TrajectoryPoint::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_TrajectoryPoint_pose(msg_);
  }

private:
  ::nav_msgs::msg::TrajectoryPoint msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::nav_msgs::msg::TrajectoryPoint>()
{
  return nav_msgs::msg::builder::Init_TrajectoryPoint_header();
}

}  // namespace nav_msgs

#endif  // NAV_MSGS__MSG__DETAIL__TRAJECTORY_POINT__BUILDER_HPP_
