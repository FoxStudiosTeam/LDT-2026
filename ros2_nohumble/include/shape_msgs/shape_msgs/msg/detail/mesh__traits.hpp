// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from shape_msgs:msg\Mesh.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "shape_msgs/msg/mesh.hpp"


#ifndef SHAPE_MSGS__MSG__DETAIL__MESH__TRAITS_HPP_
#define SHAPE_MSGS__MSG__DETAIL__MESH__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "shape_msgs/msg/detail/mesh__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'triangles'
#include "shape_msgs/msg/detail/mesh_triangle__traits.hpp"
// Member 'vertices'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace shape_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Mesh & msg,
  std::ostream & out)
{
  out << "{";
  // member: triangles
  {
    if (msg.triangles.size() == 0) {
      out << "triangles: []";
    } else {
      out << "triangles: [";
      size_t pending_items = msg.triangles.size();
      for (auto item : msg.triangles) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: vertices
  {
    if (msg.vertices.size() == 0) {
      out << "vertices: []";
    } else {
      out << "vertices: [";
      size_t pending_items = msg.vertices.size();
      for (auto item : msg.vertices) {
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
  const Mesh & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: triangles
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.triangles.size() == 0) {
      out << "triangles: []\n";
    } else {
      out << "triangles:\n";
      for (auto item : msg.triangles) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: vertices
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.vertices.size() == 0) {
      out << "vertices: []\n";
    } else {
      out << "vertices:\n";
      for (auto item : msg.vertices) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Mesh & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, shape_msgs::msg::Mesh>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).triangles,
    std::forward<T>(msg).vertices);
}

}  // namespace msg

}  // namespace shape_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<shape_msgs::msg::Mesh>()
{
  return "shape_msgs::msg::Mesh";
}

template<>
constexpr const char * name<shape_msgs::msg::Mesh>()
{
  return "shape_msgs/msg/Mesh";
}

template<>
struct has_fixed_size<shape_msgs::msg::Mesh>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<shape_msgs::msg::Mesh>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<shape_msgs::msg::Mesh>
  : std::true_type {};

template<>
struct MessageTraits<shape_msgs::msg::Mesh>
{
  static constexpr std::size_t member_count = 2;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "triangles",
    "vertices",
  };
};

}  // namespace rosidl_generator_traits

#endif  // SHAPE_MSGS__MSG__DETAIL__MESH__TRAITS_HPP_
