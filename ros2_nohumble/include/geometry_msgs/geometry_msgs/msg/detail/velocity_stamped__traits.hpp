// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from geometry_msgs:msg\VelocityStamped.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "geometry_msgs/msg/velocity_stamped.hpp"


#ifndef GEOMETRY_MSGS__MSG__DETAIL__VELOCITY_STAMPED__TRAITS_HPP_
#define GEOMETRY_MSGS__MSG__DETAIL__VELOCITY_STAMPED__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "geometry_msgs/msg/detail/velocity_stamped__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'velocity'
#include "geometry_msgs/msg/detail/twist__traits.hpp"

namespace geometry_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const VelocityStamped & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: body_frame_id
  {
    out << "body_frame_id: ";
    rosidl_generator_traits::value_to_yaml(msg.body_frame_id, out);
    out << ", ";
  }

  // member: reference_frame_id
  {
    out << "reference_frame_id: ";
    rosidl_generator_traits::value_to_yaml(msg.reference_frame_id, out);
    out << ", ";
  }

  // member: velocity
  {
    out << "velocity: ";
    to_flow_style_yaml(msg.velocity, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const VelocityStamped & msg,
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

  // member: body_frame_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "body_frame_id: ";
    rosidl_generator_traits::value_to_yaml(msg.body_frame_id, out);
    out << "\n";
  }

  // member: reference_frame_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "reference_frame_id: ";
    rosidl_generator_traits::value_to_yaml(msg.reference_frame_id, out);
    out << "\n";
  }

  // member: velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "velocity:\n";
    to_block_style_yaml(msg.velocity, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const VelocityStamped & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, geometry_msgs::msg::VelocityStamped>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).header,
    std::forward<T>(msg).body_frame_id,
    std::forward<T>(msg).reference_frame_id,
    std::forward<T>(msg).velocity);
}

}  // namespace msg

}  // namespace geometry_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<geometry_msgs::msg::VelocityStamped>()
{
  return "geometry_msgs::msg::VelocityStamped";
}

template<>
constexpr const char * name<geometry_msgs::msg::VelocityStamped>()
{
  return "geometry_msgs/msg/VelocityStamped";
}

template<>
struct has_fixed_size<geometry_msgs::msg::VelocityStamped>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<geometry_msgs::msg::VelocityStamped>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<geometry_msgs::msg::VelocityStamped>
  : std::true_type {};

template<>
struct MessageTraits<geometry_msgs::msg::VelocityStamped>
{
  static constexpr std::size_t member_count = 4;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "header",
    "body_frame_id",
    "reference_frame_id",
    "velocity",
  };
};

}  // namespace rosidl_generator_traits

#endif  // GEOMETRY_MSGS__MSG__DETAIL__VELOCITY_STAMPED__TRAITS_HPP_
