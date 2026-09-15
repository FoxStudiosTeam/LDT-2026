// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from example_interfaces:msg\Float32MultiArray.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "example_interfaces/msg/float32_multi_array.hpp"


#ifndef EXAMPLE_INTERFACES__MSG__DETAIL__FLOAT32_MULTI_ARRAY__TRAITS_HPP_
#define EXAMPLE_INTERFACES__MSG__DETAIL__FLOAT32_MULTI_ARRAY__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "example_interfaces/msg/detail/float32_multi_array__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'layout'
#include "example_interfaces/msg/detail/multi_array_layout__traits.hpp"

namespace example_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Float32MultiArray & msg,
  std::ostream & out)
{
  out << "{";
  // member: layout
  {
    out << "layout: ";
    to_flow_style_yaml(msg.layout, out);
    out << ", ";
  }

  // member: data
  {
    if (msg.data.size() == 0) {
      out << "data: []";
    } else {
      out << "data: [";
      size_t pending_items = msg.data.size();
      for (auto item : msg.data) {
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
  const Float32MultiArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: layout
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "layout:\n";
    to_block_style_yaml(msg.layout, out, indentation + 2);
  }

  // member: data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.data.size() == 0) {
      out << "data: []\n";
    } else {
      out << "data:\n";
      for (auto item : msg.data) {
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

inline std::string to_yaml(const Float32MultiArray & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, example_interfaces::msg::Float32MultiArray>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).layout,
    std::forward<T>(msg).data);
}

}  // namespace msg

}  // namespace example_interfaces

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<example_interfaces::msg::Float32MultiArray>()
{
  return "example_interfaces::msg::Float32MultiArray";
}

template<>
constexpr const char * name<example_interfaces::msg::Float32MultiArray>()
{
  return "example_interfaces/msg/Float32MultiArray";
}

template<>
struct has_fixed_size<example_interfaces::msg::Float32MultiArray>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<example_interfaces::msg::Float32MultiArray>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<example_interfaces::msg::Float32MultiArray>
  : std::true_type {};

template<>
struct MessageTraits<example_interfaces::msg::Float32MultiArray>
{
  static constexpr std::size_t member_count = 2;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "layout",
    "data",
  };
};

}  // namespace rosidl_generator_traits

#endif  // EXAMPLE_INTERFACES__MSG__DETAIL__FLOAT32_MULTI_ARRAY__TRAITS_HPP_
