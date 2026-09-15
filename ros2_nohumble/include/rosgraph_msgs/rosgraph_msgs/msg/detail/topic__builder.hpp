// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rosgraph_msgs:msg\Topic.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosgraph_msgs/msg/topic.hpp"


#ifndef ROSGRAPH_MSGS__MSG__DETAIL__TOPIC__BUILDER_HPP_
#define ROSGRAPH_MSGS__MSG__DETAIL__TOPIC__BUILDER_HPP_

#include <utility>

#include "rosgraph_msgs/msg/detail/topic__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rosgraph_msgs
{

namespace msg
{

namespace builder
{

class Init_Topic_qos
{
public:
  explicit Init_Topic_qos(::rosgraph_msgs::msg::Topic & msg)
  : msg_(msg)
  {}
  ::rosgraph_msgs::msg::Topic qos(::rosgraph_msgs::msg::Topic::_qos_type arg)
  {
    msg_.qos = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rosgraph_msgs::msg::Topic msg_;
};

class Init_Topic_type
{
public:
  explicit Init_Topic_type(::rosgraph_msgs::msg::Topic & msg)
  : msg_(msg)
  {}
  Init_Topic_qos type(::rosgraph_msgs::msg::Topic::_type_type arg)
  {
    msg_.type = std::move(arg);
    return Init_Topic_qos(msg_);
  }

private:
  ::rosgraph_msgs::msg::Topic msg_;
};

class Init_Topic_name
{
public:
  Init_Topic_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Topic_type name(::rosgraph_msgs::msg::Topic::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_Topic_type(msg_);
  }

private:
  ::rosgraph_msgs::msg::Topic msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rosgraph_msgs::msg::Topic>()
{
  return rosgraph_msgs::msg::builder::Init_Topic_name();
}

}  // namespace rosgraph_msgs

#endif  // ROSGRAPH_MSGS__MSG__DETAIL__TOPIC__BUILDER_HPP_
