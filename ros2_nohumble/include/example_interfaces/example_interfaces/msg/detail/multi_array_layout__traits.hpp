// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from example_interfaces:msg\MultiArrayLayout.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "example_interfaces/msg/multi_array_layout.hpp"


#ifndef EXAMPLE_INTERFACES__MSG__DETAIL__MULTI_ARRAY_LAYOUT__TRAITS_HPP_
#define EXAMPLE_INTERFACES__MSG__DETAIL__MULTI_ARRAY_LAYOUT__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "example_interfaces/msg/detail/multi_array_layout__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'dim'
#include "example_interfaces/msg/detail/multi_array_dimension__traits.hpp"

namespace example_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const MultiArrayLayout & msg,
  std::ostream & out)
{
  out << "{";
  // member: dim
  {
    if (msg.dim.size() == 0) {
      out << "dim: []";
    } else {
      out << "dim: [";
      size_t pending_items = msg.dim.size();
      for (auto item : msg.dim) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: data_offset
  {
    out << "data_offset: ";
    rosidl_generator_traits::value_to_yaml(msg.data_offset, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MultiArrayLayout & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: dim
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.dim.size() == 0) {
      out << "dim: []\n";
    } else {
      out << "dim:\n";
      for (auto item : msg.dim) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: data_offset
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "data_offset: ";
    rosidl_generator_traits::value_to_yaml(msg.data_offset, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MultiArrayLayout & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, example_interfaces::msg::MultiArrayLayout>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).dim,
    std::forward<T>(msg).data_offset);
}

}  // namespace msg

}  // namespace example_interfaces

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<example_interfaces::msg::MultiArrayLayout>()
{
  return "example_interfaces::msg::MultiArrayLayout";
}

template<>
constexpr const char * name<example_interfaces::msg::MultiArrayLayout>()
{
  return "example_interfaces/msg/MultiArrayLayout";
}

template<>
struct has_fixed_size<example_interfaces::msg::MultiArrayLayout>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<example_interfaces::msg::MultiArrayLayout>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<example_interfaces::msg::MultiArrayLayout>
  : std::true_type {};

template<>
struct MessageTraits<example_interfaces::msg::MultiArrayLayout>
{
  static constexpr std::size_t member_count = 2;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "dim",
    "data_offset",
  };
};

}  // namespace rosidl_generator_traits

#endif  // EXAMPLE_INTERFACES__MSG__DETAIL__MULTI_ARRAY_LAYOUT__TRAITS_HPP_
