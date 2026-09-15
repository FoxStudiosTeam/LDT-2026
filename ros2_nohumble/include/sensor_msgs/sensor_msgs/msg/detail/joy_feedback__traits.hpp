// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from sensor_msgs:msg\JoyFeedback.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "sensor_msgs/msg/joy_feedback.hpp"


#ifndef SENSOR_MSGS__MSG__DETAIL__JOY_FEEDBACK__TRAITS_HPP_
#define SENSOR_MSGS__MSG__DETAIL__JOY_FEEDBACK__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "sensor_msgs/msg/detail/joy_feedback__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace sensor_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const JoyFeedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: type
  {
    out << "type: ";
    rosidl_generator_traits::value_to_yaml(msg.type, out);
    out << ", ";
  }

  // member: id
  {
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << ", ";
  }

  // member: intensity
  {
    out << "intensity: ";
    rosidl_generator_traits::value_to_yaml(msg.intensity, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const JoyFeedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "type: ";
    rosidl_generator_traits::value_to_yaml(msg.type, out);
    out << "\n";
  }

  // member: id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << "\n";
  }

  // member: intensity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "intensity: ";
    rosidl_generator_traits::value_to_yaml(msg.intensity, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const JoyFeedback & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, sensor_msgs::msg::JoyFeedback>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).type,
    std::forward<T>(msg).id,
    std::forward<T>(msg).intensity);
}

}  // namespace msg

}  // namespace sensor_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<sensor_msgs::msg::JoyFeedback>()
{
  return "sensor_msgs::msg::JoyFeedback";
}

template<>
constexpr const char * name<sensor_msgs::msg::JoyFeedback>()
{
  return "sensor_msgs/msg/JoyFeedback";
}

template<>
struct has_fixed_size<sensor_msgs::msg::JoyFeedback>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<sensor_msgs::msg::JoyFeedback>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<sensor_msgs::msg::JoyFeedback>
  : std::true_type {};

template<>
struct MessageTraits<sensor_msgs::msg::JoyFeedback>
{
  static constexpr std::size_t member_count = 3;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "type",
    "id",
    "intensity",
  };
};

}  // namespace rosidl_generator_traits

#endif  // SENSOR_MSGS__MSG__DETAIL__JOY_FEEDBACK__TRAITS_HPP_
