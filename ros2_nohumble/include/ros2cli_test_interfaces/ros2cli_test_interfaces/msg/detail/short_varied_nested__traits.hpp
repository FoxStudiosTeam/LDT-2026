// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ros2cli_test_interfaces:msg\ShortVariedNested.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ros2cli_test_interfaces/msg/short_varied_nested.hpp"


#ifndef ROS2CLI_TEST_INTERFACES__MSG__DETAIL__SHORT_VARIED_NESTED__TRAITS_HPP_
#define ROS2CLI_TEST_INTERFACES__MSG__DETAIL__SHORT_VARIED_NESTED__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "ros2cli_test_interfaces/msg/detail/short_varied_nested__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'short_varied'
#include "ros2cli_test_interfaces/msg/detail/short_varied__traits.hpp"

namespace ros2cli_test_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const ShortVariedNested & msg,
  std::ostream & out)
{
  out << "{";
  // member: short_varied
  {
    out << "short_varied: ";
    to_flow_style_yaml(msg.short_varied, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ShortVariedNested & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: short_varied
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "short_varied:\n";
    to_block_style_yaml(msg.short_varied, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ShortVariedNested & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, ros2cli_test_interfaces::msg::ShortVariedNested>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(std::forward<T>(msg).short_varied);
}

}  // namespace msg

}  // namespace ros2cli_test_interfaces

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<ros2cli_test_interfaces::msg::ShortVariedNested>()
{
  return "ros2cli_test_interfaces::msg::ShortVariedNested";
}

template<>
constexpr const char * name<ros2cli_test_interfaces::msg::ShortVariedNested>()
{
  return "ros2cli_test_interfaces/msg/ShortVariedNested";
}

template<>
struct has_fixed_size<ros2cli_test_interfaces::msg::ShortVariedNested>
  : std::integral_constant<bool, has_fixed_size<ros2cli_test_interfaces::msg::ShortVaried>::value> {};

template<>
struct has_bounded_size<ros2cli_test_interfaces::msg::ShortVariedNested>
  : std::integral_constant<bool, has_bounded_size<ros2cli_test_interfaces::msg::ShortVaried>::value> {};

template<>
struct is_message<ros2cli_test_interfaces::msg::ShortVariedNested>
  : std::true_type {};

template<>
struct MessageTraits<ros2cli_test_interfaces::msg::ShortVariedNested>
{
  static constexpr std::size_t member_count = 1;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "short_varied",
  };
};

}  // namespace rosidl_generator_traits

#endif  // ROS2CLI_TEST_INTERFACES__MSG__DETAIL__SHORT_VARIED_NESTED__TRAITS_HPP_
