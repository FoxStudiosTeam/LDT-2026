// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from pendulum_msgs:msg\JointCommand.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "pendulum_msgs/msg/joint_command.hpp"


#ifndef PENDULUM_MSGS__MSG__DETAIL__JOINT_COMMAND__BUILDER_HPP_
#define PENDULUM_MSGS__MSG__DETAIL__JOINT_COMMAND__BUILDER_HPP_

#include <utility>

#include "pendulum_msgs/msg/detail/joint_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace pendulum_msgs
{

namespace msg
{

namespace builder
{

class Init_JointCommand_position
{
public:
  Init_JointCommand_position()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::pendulum_msgs::msg::JointCommand position(::pendulum_msgs::msg::JointCommand::_position_type arg)
  {
    msg_.position = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pendulum_msgs::msg::JointCommand msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::pendulum_msgs::msg::JointCommand>()
{
  return pendulum_msgs::msg::builder::Init_JointCommand_position();
}

}  // namespace pendulum_msgs

#endif  // PENDULUM_MSGS__MSG__DETAIL__JOINT_COMMAND__BUILDER_HPP_
