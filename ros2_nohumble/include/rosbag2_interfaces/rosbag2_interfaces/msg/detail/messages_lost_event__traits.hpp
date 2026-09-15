// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rosbag2_interfaces:msg\MessagesLostEvent.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosbag2_interfaces/msg/messages_lost_event.hpp"


#ifndef ROSBAG2_INTERFACES__MSG__DETAIL__MESSAGES_LOST_EVENT__TRAITS_HPP_
#define ROSBAG2_INTERFACES__MSG__DETAIL__MESSAGES_LOST_EVENT__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "rosbag2_interfaces/msg/detail/messages_lost_event__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'messages_lost_statistics'
#include "rosbag2_interfaces/msg/detail/messages_lost_event_topic_stat__traits.hpp"

namespace rosbag2_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const MessagesLostEvent & msg,
  std::ostream & out)
{
  out << "{";
  // member: node_name
  {
    out << "node_name: ";
    rosidl_generator_traits::value_to_yaml(msg.node_name, out);
    out << ", ";
  }

  // member: messages_lost_statistics
  {
    if (msg.messages_lost_statistics.size() == 0) {
      out << "messages_lost_statistics: []";
    } else {
      out << "messages_lost_statistics: [";
      size_t pending_items = msg.messages_lost_statistics.size();
      for (auto item : msg.messages_lost_statistics) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MessagesLostEvent & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: node_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "node_name: ";
    rosidl_generator_traits::value_to_yaml(msg.node_name, out);
    out << "\n";
  }

  // member: messages_lost_statistics
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.messages_lost_statistics.size() == 0) {
      out << "messages_lost_statistics: []\n";
    } else {
      out << "messages_lost_statistics:\n";
      for (auto item : msg.messages_lost_statistics) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MessagesLostEvent & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, rosbag2_interfaces::msg::MessagesLostEvent>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).node_name,
    std::forward<T>(msg).messages_lost_statistics);
}

}  // namespace msg

}  // namespace rosbag2_interfaces

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<rosbag2_interfaces::msg::MessagesLostEvent>()
{
  return "rosbag2_interfaces::msg::MessagesLostEvent";
}

template<>
constexpr const char * name<rosbag2_interfaces::msg::MessagesLostEvent>()
{
  return "rosbag2_interfaces/msg/MessagesLostEvent";
}

template<>
struct has_fixed_size<rosbag2_interfaces::msg::MessagesLostEvent>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rosbag2_interfaces::msg::MessagesLostEvent>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<rosbag2_interfaces::msg::MessagesLostEvent>
  : std::true_type {};

template<>
struct MessageTraits<rosbag2_interfaces::msg::MessagesLostEvent>
{
  static constexpr std::size_t member_count = 2;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "node_name",
    "messages_lost_statistics",
  };
};

}  // namespace rosidl_generator_traits

#endif  // ROSBAG2_INTERFACES__MSG__DETAIL__MESSAGES_LOST_EVENT__TRAITS_HPP_
