// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from test_msgs:msg\Builtins.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "test_msgs/msg/builtins.hpp"


#ifndef TEST_MSGS__MSG__DETAIL__BUILTINS__TRAITS_HPP_
#define TEST_MSGS__MSG__DETAIL__BUILTINS__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "test_msgs/msg/detail/builtins__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'duration_value'
#include "builtin_interfaces/msg/detail/duration__traits.hpp"
// Member 'time_value'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace test_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Builtins & msg,
  std::ostream & out)
{
  out << "{";
  // member: duration_value
  {
    out << "duration_value: ";
    to_flow_style_yaml(msg.duration_value, out);
    out << ", ";
  }

  // member: time_value
  {
    out << "time_value: ";
    to_flow_style_yaml(msg.time_value, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Builtins & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: duration_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "duration_value:\n";
    to_block_style_yaml(msg.duration_value, out, indentation + 2);
  }

  // member: time_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "time_value:\n";
    to_block_style_yaml(msg.time_value, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Builtins & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, test_msgs::msg::Builtins>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).duration_value,
    std::forward<T>(msg).time_value);
}

}  // namespace msg

}  // namespace test_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<test_msgs::msg::Builtins>()
{
  return "test_msgs::msg::Builtins";
}

template<>
constexpr const char * name<test_msgs::msg::Builtins>()
{
  return "test_msgs/msg/Builtins";
}

template<>
struct has_fixed_size<test_msgs::msg::Builtins>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Duration>::value && has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<test_msgs::msg::Builtins>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Duration>::value && has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<test_msgs::msg::Builtins>
  : std::true_type {};

template<>
struct MessageTraits<test_msgs::msg::Builtins>
{
  static constexpr std::size_t member_count = 2;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "duration_value",
    "time_value",
  };
};

}  // namespace rosidl_generator_traits

#endif  // TEST_MSGS__MSG__DETAIL__BUILTINS__TRAITS_HPP_
