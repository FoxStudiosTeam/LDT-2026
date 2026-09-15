// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rosbag2_interfaces:msg\WriteSplitEvent.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosbag2_interfaces/msg/write_split_event.hpp"


#ifndef ROSBAG2_INTERFACES__MSG__DETAIL__WRITE_SPLIT_EVENT__TRAITS_HPP_
#define ROSBAG2_INTERFACES__MSG__DETAIL__WRITE_SPLIT_EVENT__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "rosbag2_interfaces/msg/detail/write_split_event__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace rosbag2_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const WriteSplitEvent & msg,
  std::ostream & out)
{
  out << "{";
  // member: closed_file
  {
    out << "closed_file: ";
    rosidl_generator_traits::value_to_yaml(msg.closed_file, out);
    out << ", ";
  }

  // member: opened_file
  {
    out << "opened_file: ";
    rosidl_generator_traits::value_to_yaml(msg.opened_file, out);
    out << ", ";
  }

  // member: node_name
  {
    out << "node_name: ";
    rosidl_generator_traits::value_to_yaml(msg.node_name, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const WriteSplitEvent & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: closed_file
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "closed_file: ";
    rosidl_generator_traits::value_to_yaml(msg.closed_file, out);
    out << "\n";
  }

  // member: opened_file
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "opened_file: ";
    rosidl_generator_traits::value_to_yaml(msg.opened_file, out);
    out << "\n";
  }

  // member: node_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "node_name: ";
    rosidl_generator_traits::value_to_yaml(msg.node_name, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const WriteSplitEvent & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, rosbag2_interfaces::msg::WriteSplitEvent>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).closed_file,
    std::forward<T>(msg).opened_file,
    std::forward<T>(msg).node_name);
}

}  // namespace msg

}  // namespace rosbag2_interfaces

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<rosbag2_interfaces::msg::WriteSplitEvent>()
{
  return "rosbag2_interfaces::msg::WriteSplitEvent";
}

template<>
constexpr const char * name<rosbag2_interfaces::msg::WriteSplitEvent>()
{
  return "rosbag2_interfaces/msg/WriteSplitEvent";
}

template<>
struct has_fixed_size<rosbag2_interfaces::msg::WriteSplitEvent>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rosbag2_interfaces::msg::WriteSplitEvent>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<rosbag2_interfaces::msg::WriteSplitEvent>
  : std::true_type {};

template<>
struct MessageTraits<rosbag2_interfaces::msg::WriteSplitEvent>
{
  static constexpr std::size_t member_count = 3;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "closed_file",
    "opened_file",
    "node_name",
  };
};

}  // namespace rosidl_generator_traits

#endif  // ROSBAG2_INTERFACES__MSG__DETAIL__WRITE_SPLIT_EVENT__TRAITS_HPP_
