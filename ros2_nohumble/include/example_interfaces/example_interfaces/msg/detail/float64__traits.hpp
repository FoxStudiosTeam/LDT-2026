// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from example_interfaces:msg\Float64.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "example_interfaces/msg/float64.hpp"


#ifndef EXAMPLE_INTERFACES__MSG__DETAIL__FLOAT64__TRAITS_HPP_
#define EXAMPLE_INTERFACES__MSG__DETAIL__FLOAT64__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "example_interfaces/msg/detail/float64__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace example_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Float64 & msg,
  std::ostream & out)
{
  out << "{";
  // member: data
  {
    out << "data: ";
    rosidl_generator_traits::value_to_yaml(msg.data, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Float64 & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "data: ";
    rosidl_generator_traits::value_to_yaml(msg.data, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Float64 & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, example_interfaces::msg::Float64>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(std::forward<T>(msg).data);
}

}  // namespace msg

}  // namespace example_interfaces

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<example_interfaces::msg::Float64>()
{
  return "example_interfaces::msg::Float64";
}

template<>
constexpr const char * name<example_interfaces::msg::Float64>()
{
  return "example_interfaces/msg/Float64";
}

template<>
struct has_fixed_size<example_interfaces::msg::Float64>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<example_interfaces::msg::Float64>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<example_interfaces::msg::Float64>
  : std::true_type {};

template<>
struct MessageTraits<example_interfaces::msg::Float64>
{
  static constexpr std::size_t member_count = 1;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "data",
  };
};

}  // namespace rosidl_generator_traits

#endif  // EXAMPLE_INTERFACES__MSG__DETAIL__FLOAT64__TRAITS_HPP_
