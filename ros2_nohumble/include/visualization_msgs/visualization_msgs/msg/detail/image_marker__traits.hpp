// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from visualization_msgs:msg\ImageMarker.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "visualization_msgs/msg/image_marker.hpp"


#ifndef VISUALIZATION_MSGS__MSG__DETAIL__IMAGE_MARKER__TRAITS_HPP_
#define VISUALIZATION_MSGS__MSG__DETAIL__IMAGE_MARKER__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "visualization_msgs/msg/detail/image_marker__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'position'
// Member 'points'
#include "geometry_msgs/msg/detail/point__traits.hpp"
// Member 'outline_color'
// Member 'fill_color'
// Member 'outline_colors'
#include "std_msgs/msg/detail/color_rgba__traits.hpp"
// Member 'lifetime'
#include "builtin_interfaces/msg/detail/duration__traits.hpp"

namespace visualization_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const ImageMarker & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: ns
  {
    out << "ns: ";
    rosidl_generator_traits::value_to_yaml(msg.ns, out);
    out << ", ";
  }

  // member: id
  {
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << ", ";
  }

  // member: type
  {
    out << "type: ";
    rosidl_generator_traits::value_to_yaml(msg.type, out);
    out << ", ";
  }

  // member: action
  {
    out << "action: ";
    rosidl_generator_traits::value_to_yaml(msg.action, out);
    out << ", ";
  }

  // member: position
  {
    out << "position: ";
    to_flow_style_yaml(msg.position, out);
    out << ", ";
  }

  // member: scale
  {
    out << "scale: ";
    rosidl_generator_traits::value_to_yaml(msg.scale, out);
    out << ", ";
  }

  // member: outline_color
  {
    out << "outline_color: ";
    to_flow_style_yaml(msg.outline_color, out);
    out << ", ";
  }

  // member: filled
  {
    out << "filled: ";
    rosidl_generator_traits::value_to_yaml(msg.filled, out);
    out << ", ";
  }

  // member: fill_color
  {
    out << "fill_color: ";
    to_flow_style_yaml(msg.fill_color, out);
    out << ", ";
  }

  // member: lifetime
  {
    out << "lifetime: ";
    to_flow_style_yaml(msg.lifetime, out);
    out << ", ";
  }

  // member: points
  {
    if (msg.points.size() == 0) {
      out << "points: []";
    } else {
      out << "points: [";
      size_t pending_items = msg.points.size();
      for (auto item : msg.points) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: outline_colors
  {
    if (msg.outline_colors.size() == 0) {
      out << "outline_colors: []";
    } else {
      out << "outline_colors: [";
      size_t pending_items = msg.outline_colors.size();
      for (auto item : msg.outline_colors) {
        to_flow_style_yaml(item, out);
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
  const ImageMarker & msg,
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

  // member: ns
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ns: ";
    rosidl_generator_traits::value_to_yaml(msg.ns, out);
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

  // member: type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "type: ";
    rosidl_generator_traits::value_to_yaml(msg.type, out);
    out << "\n";
  }

  // member: action
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "action: ";
    rosidl_generator_traits::value_to_yaml(msg.action, out);
    out << "\n";
  }

  // member: position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "position:\n";
    to_block_style_yaml(msg.position, out, indentation + 2);
  }

  // member: scale
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "scale: ";
    rosidl_generator_traits::value_to_yaml(msg.scale, out);
    out << "\n";
  }

  // member: outline_color
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "outline_color:\n";
    to_block_style_yaml(msg.outline_color, out, indentation + 2);
  }

  // member: filled
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "filled: ";
    rosidl_generator_traits::value_to_yaml(msg.filled, out);
    out << "\n";
  }

  // member: fill_color
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "fill_color:\n";
    to_block_style_yaml(msg.fill_color, out, indentation + 2);
  }

  // member: lifetime
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "lifetime:\n";
    to_block_style_yaml(msg.lifetime, out, indentation + 2);
  }

  // member: points
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.points.size() == 0) {
      out << "points: []\n";
    } else {
      out << "points:\n";
      for (auto item : msg.points) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: outline_colors
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.outline_colors.size() == 0) {
      out << "outline_colors: []\n";
    } else {
      out << "outline_colors:\n";
      for (auto item : msg.outline_colors) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ImageMarker & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, visualization_msgs::msg::ImageMarker>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).header,
    std::forward<T>(msg).ns,
    std::forward<T>(msg).id,
    std::forward<T>(msg).type,
    std::forward<T>(msg).action,
    std::forward<T>(msg).position,
    std::forward<T>(msg).scale,
    std::forward<T>(msg).outline_color,
    std::forward<T>(msg).filled,
    std::forward<T>(msg).fill_color,
    std::forward<T>(msg).lifetime,
    std::forward<T>(msg).points,
    std::forward<T>(msg).outline_colors);
}

}  // namespace msg

}  // namespace visualization_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<visualization_msgs::msg::ImageMarker>()
{
  return "visualization_msgs::msg::ImageMarker";
}

template<>
constexpr const char * name<visualization_msgs::msg::ImageMarker>()
{
  return "visualization_msgs/msg/ImageMarker";
}

template<>
struct has_fixed_size<visualization_msgs::msg::ImageMarker>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<visualization_msgs::msg::ImageMarker>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<visualization_msgs::msg::ImageMarker>
  : std::true_type {};

template<>
struct MessageTraits<visualization_msgs::msg::ImageMarker>
{
  static constexpr std::size_t member_count = 13;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "header",
    "ns",
    "id",
    "type",
    "action",
    "position",
    "scale",
    "outline_color",
    "filled",
    "fill_color",
    "lifetime",
    "points",
    "outline_colors",
  };
};

}  // namespace rosidl_generator_traits

#endif  // VISUALIZATION_MSGS__MSG__DETAIL__IMAGE_MARKER__TRAITS_HPP_
