// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ros2cli_test_interfaces:msg\ShortVaried.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ros2cli_test_interfaces/msg/short_varied.hpp"


#ifndef ROS2CLI_TEST_INTERFACES__MSG__DETAIL__SHORT_VARIED__TRAITS_HPP_
#define ROS2CLI_TEST_INTERFACES__MSG__DETAIL__SHORT_VARIED__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "ros2cli_test_interfaces/msg/detail/short_varied__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ros2cli_test_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const ShortVaried & msg,
  std::ostream & out)
{
  out << "{";
  // member: bool_value
  {
    out << "bool_value: ";
    rosidl_generator_traits::value_to_yaml(msg.bool_value, out);
    out << ", ";
  }

  // member: bool_values
  {
    if (msg.bool_values.size() == 0) {
      out << "bool_values: []";
    } else {
      out << "bool_values: [";
      size_t pending_items = msg.bool_values.size();
      for (auto item : msg.bool_values) {
        rosidl_generator_traits::value_to_yaml(item, out);
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
  const ShortVaried & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: bool_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bool_value: ";
    rosidl_generator_traits::value_to_yaml(msg.bool_value, out);
    out << "\n";
  }

  // member: bool_values
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.bool_values.size() == 0) {
      out << "bool_values: []\n";
    } else {
      out << "bool_values:\n";
      for (auto item : msg.bool_values) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ShortVaried & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, ros2cli_test_interfaces::msg::ShortVaried>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).bool_value,
    std::forward<T>(msg).bool_values);
}

}  // namespace msg

}  // namespace ros2cli_test_interfaces

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<ros2cli_test_interfaces::msg::ShortVaried>()
{
  return "ros2cli_test_interfaces::msg::ShortVaried";
}

template<>
constexpr const char * name<ros2cli_test_interfaces::msg::ShortVaried>()
{
  return "ros2cli_test_interfaces/msg/ShortVaried";
}

template<>
struct has_fixed_size<ros2cli_test_interfaces::msg::ShortVaried>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ros2cli_test_interfaces::msg::ShortVaried>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ros2cli_test_interfaces::msg::ShortVaried>
  : std::true_type {};

template<>
struct MessageTraits<ros2cli_test_interfaces::msg::ShortVaried>
{
  static constexpr std::size_t member_count = 2;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "bool_value",
    "bool_values",
  };
};

}  // namespace rosidl_generator_traits

#endif  // ROS2CLI_TEST_INTERFACES__MSG__DETAIL__SHORT_VARIED__TRAITS_HPP_
