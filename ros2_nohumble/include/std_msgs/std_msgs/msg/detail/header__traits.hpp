// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from std_msgs:msg\Header.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "std_msgs/msg/header.hpp"


#ifndef STD_MSGS__MSG__DETAIL__HEADER__TRAITS_HPP_
#define STD_MSGS__MSG__DETAIL__HEADER__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "std_msgs/msg/detail/header__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace std_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Header & msg,
  std::ostream & out)
{
  out << "{";
  // member: stamp
  {
    out << "stamp: ";
    to_flow_style_yaml(msg.stamp, out);
    out << ", ";
  }

  // member: frame_id
  {
    out << "frame_id: ";
    rosidl_generator_traits::value_to_yaml(msg.frame_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Header & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_block_style_yaml(msg.stamp, out, indentation + 2);
  }

  // member: frame_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "frame_id: ";
    rosidl_generator_traits::value_to_yaml(msg.frame_id, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Header & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, std_msgs::msg::Header>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).stamp,
    std::forward<T>(msg).frame_id);
}

}  // namespace msg

}  // namespace std_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<std_msgs::msg::Header>()
{
  return "std_msgs::msg::Header";
}

template<>
constexpr const char * name<std_msgs::msg::Header>()
{
  return "std_msgs/msg/Header";
}

template<>
struct has_fixed_size<std_msgs::msg::Header>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<std_msgs::msg::Header>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<std_msgs::msg::Header>
  : std::true_type {};

template<>
struct MessageTraits<std_msgs::msg::Header>
{
  static constexpr std::size_t member_count = 2;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "stamp",
    "frame_id",
  };
};

}  // namespace rosidl_generator_traits

#endif  // STD_MSGS__MSG__DETAIL__HEADER__TRAITS_HPP_
