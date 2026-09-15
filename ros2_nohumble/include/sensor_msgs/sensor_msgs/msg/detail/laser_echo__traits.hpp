// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from sensor_msgs:msg\LaserEcho.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "sensor_msgs/msg/laser_echo.hpp"


#ifndef SENSOR_MSGS__MSG__DETAIL__LASER_ECHO__TRAITS_HPP_
#define SENSOR_MSGS__MSG__DETAIL__LASER_ECHO__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "sensor_msgs/msg/detail/laser_echo__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace sensor_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const LaserEcho & msg,
  std::ostream & out)
{
  out << "{";
  // member: echoes
  {
    if (msg.echoes.size() == 0) {
      out << "echoes: []";
    } else {
      out << "echoes: [";
      size_t pending_items = msg.echoes.size();
      for (auto item : msg.echoes) {
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
  const LaserEcho & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: echoes
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.echoes.size() == 0) {
      out << "echoes: []\n";
    } else {
      out << "echoes:\n";
      for (auto item : msg.echoes) {
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

inline std::string to_yaml(const LaserEcho & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, sensor_msgs::msg::LaserEcho>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(std::forward<T>(msg).echoes);
}

}  // namespace msg

}  // namespace sensor_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<sensor_msgs::msg::LaserEcho>()
{
  return "sensor_msgs::msg::LaserEcho";
}

template<>
constexpr const char * name<sensor_msgs::msg::LaserEcho>()
{
  return "sensor_msgs/msg/LaserEcho";
}

template<>
struct has_fixed_size<sensor_msgs::msg::LaserEcho>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<sensor_msgs::msg::LaserEcho>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<sensor_msgs::msg::LaserEcho>
  : std::true_type {};

template<>
struct MessageTraits<sensor_msgs::msg::LaserEcho>
{
  static constexpr std::size_t member_count = 1;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "echoes",
  };
};

}  // namespace rosidl_generator_traits

#endif  // SENSOR_MSGS__MSG__DETAIL__LASER_ECHO__TRAITS_HPP_
