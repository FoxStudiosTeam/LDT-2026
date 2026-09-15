// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rosbag2_interfaces:msg\MessagesLostEvent.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosbag2_interfaces/msg/messages_lost_event.hpp"


#ifndef ROSBAG2_INTERFACES__MSG__DETAIL__MESSAGES_LOST_EVENT__BUILDER_HPP_
#define ROSBAG2_INTERFACES__MSG__DETAIL__MESSAGES_LOST_EVENT__BUILDER_HPP_

#include <utility>

#include "rosbag2_interfaces/msg/detail/messages_lost_event__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rosbag2_interfaces
{

namespace msg
{

namespace builder
{

class Init_MessagesLostEvent_messages_lost_statistics
{
public:
  explicit Init_MessagesLostEvent_messages_lost_statistics(::rosbag2_interfaces::msg::MessagesLostEvent & msg)
  : msg_(msg)
  {}
  ::rosbag2_interfaces::msg::MessagesLostEvent messages_lost_statistics(::rosbag2_interfaces::msg::MessagesLostEvent::_messages_lost_statistics_type arg)
  {
    msg_.messages_lost_statistics = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rosbag2_interfaces::msg::MessagesLostEvent msg_;
};

class Init_MessagesLostEvent_node_name
{
public:
  Init_MessagesLostEvent_node_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MessagesLostEvent_messages_lost_statistics node_name(::rosbag2_interfaces::msg::MessagesLostEvent::_node_name_type arg)
  {
    msg_.node_name = std::move(arg);
    return Init_MessagesLostEvent_messages_lost_statistics(msg_);
  }

private:
  ::rosbag2_interfaces::msg::MessagesLostEvent msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rosbag2_interfaces::msg::MessagesLostEvent>()
{
  return rosbag2_interfaces::msg::builder::Init_MessagesLostEvent_node_name();
}

}  // namespace rosbag2_interfaces

#endif  // ROSBAG2_INTERFACES__MSG__DETAIL__MESSAGES_LOST_EVENT__BUILDER_HPP_
