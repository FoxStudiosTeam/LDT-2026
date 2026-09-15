// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from diagnostic_msgs:msg\KeyValue.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "diagnostic_msgs/msg/key_value.hpp"


#ifndef DIAGNOSTIC_MSGS__MSG__DETAIL__KEY_VALUE__TRAITS_HPP_
#define DIAGNOSTIC_MSGS__MSG__DETAIL__KEY_VALUE__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "diagnostic_msgs/msg/detail/key_value__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace diagnostic_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const KeyValue & msg,
  std::ostream & out)
{
  out << "{";
  // member: key
  {
    out << "key: ";
    rosidl_generator_traits::value_to_yaml(msg.key, out);
    out << ", ";
  }

  // member: value
  {
    out << "value: ";
    rosidl_generator_traits::value_to_yaml(msg.value, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const KeyValue & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: key
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "key: ";
    rosidl_generator_traits::value_to_yaml(msg.key, out);
    out << "\n";
  }

  // member: value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "value: ";
    rosidl_generator_traits::value_to_yaml(msg.value, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const KeyValue & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, diagnostic_msgs::msg::KeyValue>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).key,
    std::forward<T>(msg).value);
}

}  // namespace msg

}  // namespace diagnostic_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<diagnostic_msgs::msg::KeyValue>()
{
  return "diagnostic_msgs::msg::KeyValue";
}

template<>
constexpr const char * name<diagnostic_msgs::msg::KeyValue>()
{
  return "diagnostic_msgs/msg/KeyValue";
}

template<>
struct has_fixed_size<diagnostic_msgs::msg::KeyValue>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<diagnostic_msgs::msg::KeyValue>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<diagnostic_msgs::msg::KeyValue>
  : std::true_type {};

template<>
struct MessageTraits<diagnostic_msgs::msg::KeyValue>
{
  static constexpr std::size_t member_count = 2;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "key",
    "value",
  };
};

}  // namespace rosidl_generator_traits

#endif  // DIAGNOSTIC_MSGS__MSG__DETAIL__KEY_VALUE__TRAITS_HPP_
