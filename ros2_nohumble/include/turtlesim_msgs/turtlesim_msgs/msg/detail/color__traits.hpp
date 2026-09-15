// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from turtlesim_msgs:msg\Color.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "turtlesim_msgs/msg/color.hpp"


#ifndef TURTLESIM_MSGS__MSG__DETAIL__COLOR__TRAITS_HPP_
#define TURTLESIM_MSGS__MSG__DETAIL__COLOR__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "turtlesim_msgs/msg/detail/color__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace turtlesim_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Color & msg,
  std::ostream & out)
{
  out << "{";
  // member: r
  {
    out << "r: ";
    rosidl_generator_traits::value_to_yaml(msg.r, out);
    out << ", ";
  }

  // member: g
  {
    out << "g: ";
    rosidl_generator_traits::value_to_yaml(msg.g, out);
    out << ", ";
  }

  // member: b
  {
    out << "b: ";
    rosidl_generator_traits::value_to_yaml(msg.b, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Color & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: r
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "r: ";
    rosidl_generator_traits::value_to_yaml(msg.r, out);
    out << "\n";
  }

  // member: g
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "g: ";
    rosidl_generator_traits::value_to_yaml(msg.g, out);
    out << "\n";
  }

  // member: b
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "b: ";
    rosidl_generator_traits::value_to_yaml(msg.b, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Color & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, turtlesim_msgs::msg::Color>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).r,
    std::forward<T>(msg).g,
    std::forward<T>(msg).b);
}

}  // namespace msg

}  // namespace turtlesim_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<turtlesim_msgs::msg::Color>()
{
  return "turtlesim_msgs::msg::Color";
}

template<>
constexpr const char * name<turtlesim_msgs::msg::Color>()
{
  return "turtlesim_msgs/msg/Color";
}

template<>
struct has_fixed_size<turtlesim_msgs::msg::Color>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<turtlesim_msgs::msg::Color>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<turtlesim_msgs::msg::Color>
  : std::true_type {};

template<>
struct MessageTraits<turtlesim_msgs::msg::Color>
{
  static constexpr std::size_t member_count = 3;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "r",
    "g",
    "b",
  };
};

}  // namespace rosidl_generator_traits

#endif  // TURTLESIM_MSGS__MSG__DETAIL__COLOR__TRAITS_HPP_
