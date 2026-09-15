// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from turtlesim_msgs:msg\Pose.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "turtlesim_msgs/msg/pose.hpp"


#ifndef TURTLESIM_MSGS__MSG__DETAIL__POSE__BUILDER_HPP_
#define TURTLESIM_MSGS__MSG__DETAIL__POSE__BUILDER_HPP_

#include <utility>

#include "turtlesim_msgs/msg/detail/pose__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace turtlesim_msgs
{

namespace msg
{

namespace builder
{

class Init_Pose_angular_velocity
{
public:
  explicit Init_Pose_angular_velocity(::turtlesim_msgs::msg::Pose & msg)
  : msg_(msg)
  {}
  ::turtlesim_msgs::msg::Pose angular_velocity(::turtlesim_msgs::msg::Pose::_angular_velocity_type arg)
  {
    msg_.angular_velocity = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtlesim_msgs::msg::Pose msg_;
};

class Init_Pose_linear_velocity
{
public:
  explicit Init_Pose_linear_velocity(::turtlesim_msgs::msg::Pose & msg)
  : msg_(msg)
  {}
  Init_Pose_angular_velocity linear_velocity(::turtlesim_msgs::msg::Pose::_linear_velocity_type arg)
  {
    msg_.linear_velocity = std::move(arg);
    return Init_Pose_angular_velocity(msg_);
  }

private:
  ::turtlesim_msgs::msg::Pose msg_;
};

class Init_Pose_theta
{
public:
  explicit Init_Pose_theta(::turtlesim_msgs::msg::Pose & msg)
  : msg_(msg)
  {}
  Init_Pose_linear_velocity theta(::turtlesim_msgs::msg::Pose::_theta_type arg)
  {
    msg_.theta = std::move(arg);
    return Init_Pose_linear_velocity(msg_);
  }

private:
  ::turtlesim_msgs::msg::Pose msg_;
};

class Init_Pose_y
{
public:
  explicit Init_Pose_y(::turtlesim_msgs::msg::Pose & msg)
  : msg_(msg)
  {}
  Init_Pose_theta y(::turtlesim_msgs::msg::Pose::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_Pose_theta(msg_);
  }

private:
  ::turtlesim_msgs::msg::Pose msg_;
};

class Init_Pose_x
{
public:
  Init_Pose_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Pose_y x(::turtlesim_msgs::msg::Pose::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Pose_y(msg_);
  }

private:
  ::turtlesim_msgs::msg::Pose msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtlesim_msgs::msg::Pose>()
{
  return turtlesim_msgs::msg::builder::Init_Pose_x();
}

}  // namespace turtlesim_msgs

#endif  // TURTLESIM_MSGS__MSG__DETAIL__POSE__BUILDER_HPP_
