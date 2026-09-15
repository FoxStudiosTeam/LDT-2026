// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from visualization_msgs:msg\InteractiveMarkerFeedback.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "visualization_msgs/msg/interactive_marker_feedback.hpp"


#ifndef VISUALIZATION_MSGS__MSG__DETAIL__INTERACTIVE_MARKER_FEEDBACK__TRAITS_HPP_
#define VISUALIZATION_MSGS__MSG__DETAIL__INTERACTIVE_MARKER_FEEDBACK__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "visualization_msgs/msg/detail/interactive_marker_feedback__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__traits.hpp"
// Member 'mouse_point'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace visualization_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const InteractiveMarkerFeedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: client_id
  {
    out << "client_id: ";
    rosidl_generator_traits::value_to_yaml(msg.client_id, out);
    out << ", ";
  }

  // member: marker_name
  {
    out << "marker_name: ";
    rosidl_generator_traits::value_to_yaml(msg.marker_name, out);
    out << ", ";
  }

  // member: control_name
  {
    out << "control_name: ";
    rosidl_generator_traits::value_to_yaml(msg.control_name, out);
    out << ", ";
  }

  // member: event_type
  {
    out << "event_type: ";
    rosidl_generator_traits::value_to_yaml(msg.event_type, out);
    out << ", ";
  }

  // member: pose
  {
    out << "pose: ";
    to_flow_style_yaml(msg.pose, out);
    out << ", ";
  }

  // member: menu_entry_id
  {
    out << "menu_entry_id: ";
    rosidl_generator_traits::value_to_yaml(msg.menu_entry_id, out);
    out << ", ";
  }

  // member: mouse_point
  {
    out << "mouse_point: ";
    to_flow_style_yaml(msg.mouse_point, out);
    out << ", ";
  }

  // member: mouse_point_valid
  {
    out << "mouse_point_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.mouse_point_valid, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const InteractiveMarkerFeedback & msg,
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

  // member: client_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "client_id: ";
    rosidl_generator_traits::value_to_yaml(msg.client_id, out);
    out << "\n";
  }

  // member: marker_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "marker_name: ";
    rosidl_generator_traits::value_to_yaml(msg.marker_name, out);
    out << "\n";
  }

  // member: control_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "control_name: ";
    rosidl_generator_traits::value_to_yaml(msg.control_name, out);
    out << "\n";
  }

  // member: event_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "event_type: ";
    rosidl_generator_traits::value_to_yaml(msg.event_type, out);
    out << "\n";
  }

  // member: pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose:\n";
    to_block_style_yaml(msg.pose, out, indentation + 2);
  }

  // member: menu_entry_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "menu_entry_id: ";
    rosidl_generator_traits::value_to_yaml(msg.menu_entry_id, out);
    out << "\n";
  }

  // member: mouse_point
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mouse_point:\n";
    to_block_style_yaml(msg.mouse_point, out, indentation + 2);
  }

  // member: mouse_point_valid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mouse_point_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.mouse_point_valid, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const InteractiveMarkerFeedback & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, visualization_msgs::msg::InteractiveMarkerFeedback>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).header,
    std::forward<T>(msg).client_id,
    std::forward<T>(msg).marker_name,
    std::forward<T>(msg).control_name,
    std::forward<T>(msg).event_type,
    std::forward<T>(msg).pose,
    std::forward<T>(msg).menu_entry_id,
    std::forward<T>(msg).mouse_point,
    std::forward<T>(msg).mouse_point_valid);
}

}  // namespace msg

}  // namespace visualization_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<visualization_msgs::msg::InteractiveMarkerFeedback>()
{
  return "visualization_msgs::msg::InteractiveMarkerFeedback";
}

template<>
constexpr const char * name<visualization_msgs::msg::InteractiveMarkerFeedback>()
{
  return "visualization_msgs/msg/InteractiveMarkerFeedback";
}

template<>
struct has_fixed_size<visualization_msgs::msg::InteractiveMarkerFeedback>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<visualization_msgs::msg::InteractiveMarkerFeedback>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<visualization_msgs::msg::InteractiveMarkerFeedback>
  : std::true_type {};

template<>
struct MessageTraits<visualization_msgs::msg::InteractiveMarkerFeedback>
{
  static constexpr std::size_t member_count = 9;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "header",
    "client_id",
    "marker_name",
    "control_name",
    "event_type",
    "pose",
    "menu_entry_id",
    "mouse_point",
    "mouse_point_valid",
  };
};

}  // namespace rosidl_generator_traits

#endif  // VISUALIZATION_MSGS__MSG__DETAIL__INTERACTIVE_MARKER_FEEDBACK__TRAITS_HPP_
