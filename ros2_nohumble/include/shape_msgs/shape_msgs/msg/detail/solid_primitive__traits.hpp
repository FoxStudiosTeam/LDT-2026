// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from shape_msgs:msg\SolidPrimitive.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "shape_msgs/msg/solid_primitive.hpp"


#ifndef SHAPE_MSGS__MSG__DETAIL__SOLID_PRIMITIVE__TRAITS_HPP_
#define SHAPE_MSGS__MSG__DETAIL__SOLID_PRIMITIVE__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "shape_msgs/msg/detail/solid_primitive__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'polygon'
#include "geometry_msgs/msg/detail/polygon__traits.hpp"

namespace shape_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const SolidPrimitive & msg,
  std::ostream & out)
{
  out << "{";
  // member: type
  {
    out << "type: ";
    rosidl_generator_traits::value_to_yaml(msg.type, out);
    out << ", ";
  }

  // member: dimensions
  {
    if (msg.dimensions.size() == 0) {
      out << "dimensions: []";
    } else {
      out << "dimensions: [";
      size_t pending_items = msg.dimensions.size();
      for (auto item : msg.dimensions) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: polygon
  {
    out << "polygon: ";
    to_flow_style_yaml(msg.polygon, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SolidPrimitive & msg,
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

  // member: dimensions
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.dimensions.size() == 0) {
      out << "dimensions: []\n";
    } else {
      out << "dimensions:\n";
      for (auto item : msg.dimensions) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: polygon
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "polygon:\n";
    to_block_style_yaml(msg.polygon, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SolidPrimitive & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, shape_msgs::msg::SolidPrimitive>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).type,
    std::forward<T>(msg).dimensions,
    std::forward<T>(msg).polygon);
}

}  // namespace msg

}  // namespace shape_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<shape_msgs::msg::SolidPrimitive>()
{
  return "shape_msgs::msg::SolidPrimitive";
}

template<>
constexpr const char * name<shape_msgs::msg::SolidPrimitive>()
{
  return "shape_msgs/msg/SolidPrimitive";
}

template<>
struct has_fixed_size<shape_msgs::msg::SolidPrimitive>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<shape_msgs::msg::SolidPrimitive>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Polygon>::value> {};

template<>
struct is_message<shape_msgs::msg::SolidPrimitive>
  : std::true_type {};

template<>
struct MessageTraits<shape_msgs::msg::SolidPrimitive>
{
  static constexpr std::size_t member_count = 3;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "type",
    "dimensions",
    "polygon",
  };
};

}  // namespace rosidl_generator_traits

#endif  // SHAPE_MSGS__MSG__DETAIL__SOLID_PRIMITIVE__TRAITS_HPP_
