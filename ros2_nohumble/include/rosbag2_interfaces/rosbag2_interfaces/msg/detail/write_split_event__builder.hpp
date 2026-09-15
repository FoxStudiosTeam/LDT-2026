// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rosbag2_interfaces:msg\WriteSplitEvent.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosbag2_interfaces/msg/write_split_event.hpp"


#ifndef ROSBAG2_INTERFACES__MSG__DETAIL__WRITE_SPLIT_EVENT__BUILDER_HPP_
#define ROSBAG2_INTERFACES__MSG__DETAIL__WRITE_SPLIT_EVENT__BUILDER_HPP_

#include <utility>

#include "rosbag2_interfaces/msg/detail/write_split_event__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rosbag2_interfaces
{

namespace msg
{

namespace builder
{

class Init_WriteSplitEvent_node_name
{
public:
  explicit Init_WriteSplitEvent_node_name(::rosbag2_interfaces::msg::WriteSplitEvent & msg)
  : msg_(msg)
  {}
  ::rosbag2_interfaces::msg::WriteSplitEvent node_name(::rosbag2_interfaces::msg::WriteSplitEvent::_node_name_type arg)
  {
    msg_.node_name = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rosbag2_interfaces::msg::WriteSplitEvent msg_;
};

class Init_WriteSplitEvent_opened_file
{
public:
  explicit Init_WriteSplitEvent_opened_file(::rosbag2_interfaces::msg::WriteSplitEvent & msg)
  : msg_(msg)
  {}
  Init_WriteSplitEvent_node_name opened_file(::rosbag2_interfaces::msg::WriteSplitEvent::_opened_file_type arg)
  {
    msg_.opened_file = std::move(arg);
    return Init_WriteSplitEvent_node_name(msg_);
  }

private:
  ::rosbag2_interfaces::msg::WriteSplitEvent msg_;
};

class Init_WriteSplitEvent_closed_file
{
public:
  Init_WriteSplitEvent_closed_file()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_WriteSplitEvent_opened_file closed_file(::rosbag2_interfaces::msg::WriteSplitEvent::_closed_file_type arg)
  {
    msg_.closed_file = std::move(arg);
    return Init_WriteSplitEvent_opened_file(msg_);
  }

private:
  ::rosbag2_interfaces::msg::WriteSplitEvent msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rosbag2_interfaces::msg::WriteSplitEvent>()
{
  return rosbag2_interfaces::msg::builder::Init_WriteSplitEvent_closed_file();
}

}  // namespace rosbag2_interfaces

#endif  // ROSBAG2_INTERFACES__MSG__DETAIL__WRITE_SPLIT_EVENT__BUILDER_HPP_
