// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rosbag2_interfaces:msg\MessagesLostEventTopicStat.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosbag2_interfaces/msg/messages_lost_event_topic_stat.hpp"


#ifndef ROSBAG2_INTERFACES__MSG__DETAIL__MESSAGES_LOST_EVENT_TOPIC_STAT__TRAITS_HPP_
#define ROSBAG2_INTERFACES__MSG__DETAIL__MESSAGES_LOST_EVENT_TOPIC_STAT__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "rosbag2_interfaces/msg/detail/messages_lost_event_topic_stat__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace rosbag2_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const MessagesLostEventTopicStat & msg,
  std::ostream & out)
{
  out << "{";
  // member: topic_name
  {
    out << "topic_name: ";
    rosidl_generator_traits::value_to_yaml(msg.topic_name, out);
    out << ", ";
  }

  // member: messages_lost_in_transport
  {
    out << "messages_lost_in_transport: ";
    rosidl_generator_traits::value_to_yaml(msg.messages_lost_in_transport, out);
    out << ", ";
  }

  // member: messages_lost_in_recorder
  {
    out << "messages_lost_in_recorder: ";
    rosidl_generator_traits::value_to_yaml(msg.messages_lost_in_recorder, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MessagesLostEventTopicStat & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: topic_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "topic_name: ";
    rosidl_generator_traits::value_to_yaml(msg.topic_name, out);
    out << "\n";
  }

  // member: messages_lost_in_transport
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "messages_lost_in_transport: ";
    rosidl_generator_traits::value_to_yaml(msg.messages_lost_in_transport, out);
    out << "\n";
  }

  // member: messages_lost_in_recorder
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "messages_lost_in_recorder: ";
    rosidl_generator_traits::value_to_yaml(msg.messages_lost_in_recorder, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MessagesLostEventTopicStat & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, rosbag2_interfaces::msg::MessagesLostEventTopicStat>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).topic_name,
    std::forward<T>(msg).messages_lost_in_transport,
    std::forward<T>(msg).messages_lost_in_recorder);
}

}  // namespace msg

}  // namespace rosbag2_interfaces

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<rosbag2_interfaces::msg::MessagesLostEventTopicStat>()
{
  return "rosbag2_interfaces::msg::MessagesLostEventTopicStat";
}

template<>
constexpr const char * name<rosbag2_interfaces::msg::MessagesLostEventTopicStat>()
{
  return "rosbag2_interfaces/msg/MessagesLostEventTopicStat";
}

template<>
struct has_fixed_size<rosbag2_interfaces::msg::MessagesLostEventTopicStat>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rosbag2_interfaces::msg::MessagesLostEventTopicStat>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<rosbag2_interfaces::msg::MessagesLostEventTopicStat>
  : std::true_type {};

template<>
struct MessageTraits<rosbag2_interfaces::msg::MessagesLostEventTopicStat>
{
  static constexpr std::size_t member_count = 3;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "topic_name",
    "messages_lost_in_transport",
    "messages_lost_in_recorder",
  };
};

}  // namespace rosidl_generator_traits

#endif  // ROSBAG2_INTERFACES__MSG__DETAIL__MESSAGES_LOST_EVENT_TOPIC_STAT__TRAITS_HPP_
