// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from visualization_msgs:msg\UVCoordinate.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "visualization_msgs/msg/uv_coordinate.hpp"


#ifndef VISUALIZATION_MSGS__MSG__DETAIL__UV_COORDINATE__TRAITS_HPP_
#define VISUALIZATION_MSGS__MSG__DETAIL__UV_COORDINATE__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "visualization_msgs/msg/detail/uv_coordinate__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace visualization_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const UVCoordinate & msg,
  std::ostream & out)
{
  out << "{";
  // member: u
  {
    out << "u: ";
    rosidl_generator_traits::value_to_yaml(msg.u, out);
    out << ", ";
  }

  // member: v
  {
    out << "v: ";
    rosidl_generator_traits::value_to_yaml(msg.v, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const UVCoordinate & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: u
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "u: ";
    rosidl_generator_traits::value_to_yaml(msg.u, out);
    out << "\n";
  }

  // member: v
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "v: ";
    rosidl_generator_traits::value_to_yaml(msg.v, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const UVCoordinate & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, visualization_msgs::msg::UVCoordinate>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).u,
    std::forward<T>(msg).v);
}

}  // namespace msg

}  // namespace visualization_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<visualization_msgs::msg::UVCoordinate>()
{
  return "visualization_msgs::msg::UVCoordinate";
}

template<>
constexpr const char * name<visualization_msgs::msg::UVCoordinate>()
{
  return "visualization_msgs/msg/UVCoordinate";
}

template<>
struct has_fixed_size<visualization_msgs::msg::UVCoordinate>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<visualization_msgs::msg::UVCoordinate>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<visualization_msgs::msg::UVCoordinate>
  : std::true_type {};

template<>
struct MessageTraits<visualization_msgs::msg::UVCoordinate>
{
  static constexpr std::size_t member_count = 2;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "u",
    "v",
  };
};

}  // namespace rosidl_generator_traits

#endif  // VISUALIZATION_MSGS__MSG__DETAIL__UV_COORDINATE__TRAITS_HPP_
