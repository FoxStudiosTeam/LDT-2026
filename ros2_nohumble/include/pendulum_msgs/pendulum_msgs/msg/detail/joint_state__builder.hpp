// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from pendulum_msgs:msg\JointState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "pendulum_msgs/msg/joint_state.hpp"


#ifndef PENDULUM_MSGS__MSG__DETAIL__JOINT_STATE__BUILDER_HPP_
#define PENDULUM_MSGS__MSG__DETAIL__JOINT_STATE__BUILDER_HPP_

#include <utility>

#include "pendulum_msgs/msg/detail/joint_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace pendulum_msgs
{

namespace msg
{

namespace builder
{

class Init_JointState_effort
{
public:
  explicit Init_JointState_effort(::pendulum_msgs::msg::JointState & msg)
  : msg_(msg)
  {}
  ::pendulum_msgs::msg::JointState effort(::pendulum_msgs::msg::JointState::_effort_type arg)
  {
    msg_.effort = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pendulum_msgs::msg::JointState msg_;
};

class Init_JointState_velocity
{
public:
  explicit Init_JointState_velocity(::pendulum_msgs::msg::JointState & msg)
  : msg_(msg)
  {}
  Init_JointState_effort velocity(::pendulum_msgs::msg::JointState::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return Init_JointState_effort(msg_);
  }

private:
  ::pendulum_msgs::msg::JointState msg_;
};

class Init_JointState_position
{
public:
  Init_JointState_position()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_JointState_velocity position(::pendulum_msgs::msg::JointState::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_JointState_velocity(msg_);
  }

private:
  ::pendulum_msgs::msg::JointState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::pendulum_msgs::msg::JointState>()
{
  return pendulum_msgs::msg::builder::Init_JointState_position();
}

}  // namespace pendulum_msgs

#endif  // PENDULUM_MSGS__MSG__DETAIL__JOINT_STATE__BUILDER_HPP_
