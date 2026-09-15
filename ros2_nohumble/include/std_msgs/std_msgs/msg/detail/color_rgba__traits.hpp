// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from std_msgs:msg\ColorRGBA.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "std_msgs/msg/color_rgba.hpp"


#ifndef STD_MSGS__MSG__DETAIL__COLOR_RGBA__TRAITS_HPP_
#define STD_MSGS__MSG__DETAIL__COLOR_RGBA__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "std_msgs/msg/detail/color_rgba__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace std_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const ColorRGBA & msg,
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
    out << ", ";
  }

  // member: a
  {
    out << "a: ";
    rosidl_generator_traits::value_to_yaml(msg.a, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ColorRGBA & msg,
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

  // member: a
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "a: ";
    rosidl_generator_traits::value_to_yaml(msg.a, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ColorRGBA & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, std_msgs::msg::ColorRGBA>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).r,
    std::forward<T>(msg).g,
    std::forward<T>(msg).b,
    std::forward<T>(msg).a);
}

}  // namespace msg

}  // namespace std_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<std_msgs::msg::ColorRGBA>()
{
  return "std_msgs::msg::ColorRGBA";
}

template<>
constexpr const char * name<std_msgs::msg::ColorRGBA>()
{
  return "std_msgs/msg/ColorRGBA";
}

template<>
struct has_fixed_size<std_msgs::msg::ColorRGBA>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<std_msgs::msg::ColorRGBA>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<std_msgs::msg::ColorRGBA>
  : std::true_type {};

template<>
struct MessageTraits<std_msgs::msg::ColorRGBA>
{
  static constexpr std::size_t member_count = 4;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "r",
    "g",
    "b",
    "a",
  };
};

}  // namespace rosidl_generator_traits

#endif  // STD_MSGS__MSG__DETAIL__COLOR_RGBA__TRAITS_HPP_
