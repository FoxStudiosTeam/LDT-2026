// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rosgraph_msgs:msg\Action.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosgraph_msgs/msg/action.hpp"


#ifndef ROSGRAPH_MSGS__MSG__DETAIL__ACTION__BUILDER_HPP_
#define ROSGRAPH_MSGS__MSG__DETAIL__ACTION__BUILDER_HPP_

#include <utility>

#include "rosgraph_msgs/msg/detail/action__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rosgraph_msgs
{

namespace msg
{

namespace builder
{

class Init_Action_status
{
public:
  explicit Init_Action_status(::rosgraph_msgs::msg::Action & msg)
  : msg_(msg)
  {}
  ::rosgraph_msgs::msg::Action status(::rosgraph_msgs::msg::Action::_status_type arg)
  {
    msg_.status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rosgraph_msgs::msg::Action msg_;
};

class Init_Action_feedback
{
public:
  explicit Init_Action_feedback(::rosgraph_msgs::msg::Action & msg)
  : msg_(msg)
  {}
  Init_Action_status feedback(::rosgraph_msgs::msg::Action::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return Init_Action_status(msg_);
  }

private:
  ::rosgraph_msgs::msg::Action msg_;
};

class Init_Action_cancel_goal
{
public:
  explicit Init_Action_cancel_goal(::rosgraph_msgs::msg::Action & msg)
  : msg_(msg)
  {}
  Init_Action_feedback cancel_goal(::rosgraph_msgs::msg::Action::_cancel_goal_type arg)
  {
    msg_.cancel_goal = std::move(arg);
    return Init_Action_feedback(msg_);
  }

private:
  ::rosgraph_msgs::msg::Action msg_;
};

class Init_Action_get_result
{
public:
  explicit Init_Action_get_result(::rosgraph_msgs::msg::Action & msg)
  : msg_(msg)
  {}
  Init_Action_cancel_goal get_result(::rosgraph_msgs::msg::Action::_get_result_type arg)
  {
    msg_.get_result = std::move(arg);
    return Init_Action_cancel_goal(msg_);
  }

private:
  ::rosgraph_msgs::msg::Action msg_;
};

class Init_Action_send_goal
{
public:
  explicit Init_Action_send_goal(::rosgraph_msgs::msg::Action & msg)
  : msg_(msg)
  {}
  Init_Action_get_result send_goal(::rosgraph_msgs::msg::Action::_send_goal_type arg)
  {
    msg_.send_goal = std::move(arg);
    return Init_Action_get_result(msg_);
  }

private:
  ::rosgraph_msgs::msg::Action msg_;
};

class Init_Action_name
{
public:
  Init_Action_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Action_send_goal name(::rosgraph_msgs::msg::Action::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_Action_send_goal(msg_);
  }

private:
  ::rosgraph_msgs::msg::Action msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rosgraph_msgs::msg::Action>()
{
  return rosgraph_msgs::msg::builder::Init_Action_name();
}

}  // namespace rosgraph_msgs

#endif  // ROSGRAPH_MSGS__MSG__DETAIL__ACTION__BUILDER_HPP_
