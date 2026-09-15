// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rosbag2_interfaces:msg\MessagesLostEventTopicStat.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosbag2_interfaces/msg/messages_lost_event_topic_stat.hpp"


#ifndef ROSBAG2_INTERFACES__MSG__DETAIL__MESSAGES_LOST_EVENT_TOPIC_STAT__BUILDER_HPP_
#define ROSBAG2_INTERFACES__MSG__DETAIL__MESSAGES_LOST_EVENT_TOPIC_STAT__BUILDER_HPP_

#include <utility>

#include "rosbag2_interfaces/msg/detail/messages_lost_event_topic_stat__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rosbag2_interfaces
{

namespace msg
{

namespace builder
{

class Init_MessagesLostEventTopicStat_messages_lost_in_recorder
{
public:
  explicit Init_MessagesLostEventTopicStat_messages_lost_in_recorder(::rosbag2_interfaces::msg::MessagesLostEventTopicStat & msg)
  : msg_(msg)
  {}
  ::rosbag2_interfaces::msg::MessagesLostEventTopicStat messages_lost_in_recorder(::rosbag2_interfaces::msg::MessagesLostEventTopicStat::_messages_lost_in_recorder_type arg)
  {
    msg_.messages_lost_in_recorder = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rosbag2_interfaces::msg::MessagesLostEventTopicStat msg_;
};

class Init_MessagesLostEventTopicStat_messages_lost_in_transport
{
public:
  explicit Init_MessagesLostEventTopicStat_messages_lost_in_transport(::rosbag2_interfaces::msg::MessagesLostEventTopicStat & msg)
  : msg_(msg)
  {}
  Init_MessagesLostEventTopicStat_messages_lost_in_recorder messages_lost_in_transport(::rosbag2_interfaces::msg::MessagesLostEventTopicStat::_messages_lost_in_transport_type arg)
  {
    msg_.messages_lost_in_transport = std::move(arg);
    return Init_MessagesLostEventTopicStat_messages_lost_in_recorder(msg_);
  }

private:
  ::rosbag2_interfaces::msg::MessagesLostEventTopicStat msg_;
};

class Init_MessagesLostEventTopicStat_topic_name
{
public:
  Init_MessagesLostEventTopicStat_topic_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MessagesLostEventTopicStat_messages_lost_in_transport topic_name(::rosbag2_interfaces::msg::MessagesLostEventTopicStat::_topic_name_type arg)
  {
    msg_.topic_name = std::move(arg);
    return Init_MessagesLostEventTopicStat_messages_lost_in_transport(msg_);
  }

private:
  ::rosbag2_interfaces::msg::MessagesLostEventTopicStat msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rosbag2_interfaces::msg::MessagesLostEventTopicStat>()
{
  return rosbag2_interfaces::msg::builder::Init_MessagesLostEventTopicStat_topic_name();
}

}  // namespace rosbag2_interfaces

#endif  // ROSBAG2_INTERFACES__MSG__DETAIL__MESSAGES_LOST_EVENT_TOPIC_STAT__BUILDER_HPP_
