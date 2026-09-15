// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from sensor_msgs:msg\TimeReference.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "sensor_msgs/msg/time_reference.hpp"


#ifndef SENSOR_MSGS__MSG__DETAIL__TIME_REFERENCE__TRAITS_HPP_
#define SENSOR_MSGS__MSG__DETAIL__TIME_REFERENCE__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "sensor_msgs/msg/detail/time_reference__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'time_ref'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace sensor_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const TimeReference & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: time_ref
  {
    out << "time_ref: ";
    to_flow_style_yaml(msg.time_ref, out);
    out << ", ";
  }

  // member: source
  {
    out << "source: ";
    rosidl_generator_traits::value_to_yaml(msg.source, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TimeReference & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: time_ref
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "time_ref:\n";
    to_block_style_yaml(msg.time_ref, out, indentation + 2);
  }

  // member: source
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "source: ";
    rosidl_generator_traits::value_to_yaml(msg.source, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TimeReference & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, sensor_msgs::msg::TimeReference>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).header,
    std::forward<T>(msg).time_ref,
    std::forward<T>(msg).source);
}

}  // namespace msg

}  // namespace sensor_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<sensor_msgs::msg::TimeReference>()
{
  return "sensor_msgs::msg::TimeReference";
}

template<>
constexpr const char * name<sensor_msgs::msg::TimeReference>()
{
  return "sensor_msgs/msg/TimeReference";
}

template<>
struct has_fixed_size<sensor_msgs::msg::TimeReference>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<sensor_msgs::msg::TimeReference>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<sensor_msgs::msg::TimeReference>
  : std::true_type {};

template<>
struct MessageTraits<sensor_msgs::msg::TimeReference>
{
  static constexpr std::size_t member_count = 3;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "header",
    "time_ref",
    "source",
  };
};

}  // namespace rosidl_generator_traits

#endif  // SENSOR_MSGS__MSG__DETAIL__TIME_REFERENCE__TRAITS_HPP_
