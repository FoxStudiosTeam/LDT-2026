// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rosgraph_msgs:msg\InterfaceType.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosgraph_msgs/msg/interface_type.hpp"


#ifndef ROSGRAPH_MSGS__MSG__DETAIL__INTERFACE_TYPE__BUILDER_HPP_
#define ROSGRAPH_MSGS__MSG__DETAIL__INTERFACE_TYPE__BUILDER_HPP_

#include <utility>

#include "rosgraph_msgs/msg/detail/interface_type__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rosgraph_msgs
{

namespace msg
{

namespace builder
{

class Init_InterfaceType_hash
{
public:
  explicit Init_InterfaceType_hash(::rosgraph_msgs::msg::InterfaceType & msg)
  : msg_(msg)
  {}
  ::rosgraph_msgs::msg::InterfaceType hash(::rosgraph_msgs::msg::InterfaceType::_hash_type arg)
  {
    msg_.hash = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rosgraph_msgs::msg::InterfaceType msg_;
};

class Init_InterfaceType_name
{
public:
  Init_InterfaceType_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_InterfaceType_hash name(::rosgraph_msgs::msg::InterfaceType::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_InterfaceType_hash(msg_);
  }

private:
  ::rosgraph_msgs::msg::InterfaceType msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rosgraph_msgs::msg::InterfaceType>()
{
  return rosgraph_msgs::msg::builder::Init_InterfaceType_name();
}

}  // namespace rosgraph_msgs

#endif  // ROSGRAPH_MSGS__MSG__DETAIL__INTERFACE_TYPE__BUILDER_HPP_
