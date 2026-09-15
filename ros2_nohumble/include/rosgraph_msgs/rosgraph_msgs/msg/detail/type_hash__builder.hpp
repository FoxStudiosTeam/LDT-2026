// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rosgraph_msgs:msg\TypeHash.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosgraph_msgs/msg/type_hash.hpp"


#ifndef ROSGRAPH_MSGS__MSG__DETAIL__TYPE_HASH__BUILDER_HPP_
#define ROSGRAPH_MSGS__MSG__DETAIL__TYPE_HASH__BUILDER_HPP_

#include <utility>

#include "rosgraph_msgs/msg/detail/type_hash__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rosgraph_msgs
{

namespace msg
{

namespace builder
{

class Init_TypeHash_value
{
public:
  explicit Init_TypeHash_value(::rosgraph_msgs::msg::TypeHash & msg)
  : msg_(msg)
  {}
  ::rosgraph_msgs::msg::TypeHash value(::rosgraph_msgs::msg::TypeHash::_value_type arg)
  {
    msg_.value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rosgraph_msgs::msg::TypeHash msg_;
};

class Init_TypeHash_version
{
public:
  Init_TypeHash_version()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TypeHash_value version(::rosgraph_msgs::msg::TypeHash::_version_type arg)
  {
    msg_.version = std::move(arg);
    return Init_TypeHash_value(msg_);
  }

private:
  ::rosgraph_msgs::msg::TypeHash msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rosgraph_msgs::msg::TypeHash>()
{
  return rosgraph_msgs::msg::builder::Init_TypeHash_version();
}

}  // namespace rosgraph_msgs

#endif  // ROSGRAPH_MSGS__MSG__DETAIL__TYPE_HASH__BUILDER_HPP_
