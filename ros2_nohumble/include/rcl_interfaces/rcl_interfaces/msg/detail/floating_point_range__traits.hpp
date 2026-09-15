// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rcl_interfaces:msg\FloatingPointRange.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rcl_interfaces/msg/floating_point_range.hpp"


#ifndef RCL_INTERFACES__MSG__DETAIL__FLOATING_POINT_RANGE__TRAITS_HPP_
#define RCL_INTERFACES__MSG__DETAIL__FLOATING_POINT_RANGE__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "rcl_interfaces/msg/detail/floating_point_range__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace rcl_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const FloatingPointRange & msg,
  std::ostream & out)
{
  out << "{";
  // member: from_value
  {
    out << "from_value: ";
    rosidl_generator_traits::value_to_yaml(msg.from_value, out);
    out << ", ";
  }

  // member: to_value
  {
    out << "to_value: ";
    rosidl_generator_traits::value_to_yaml(msg.to_value, out);
    out << ", ";
  }

  // member: step
  {
    out << "step: ";
    rosidl_generator_traits::value_to_yaml(msg.step, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FloatingPointRange & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: from_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "from_value: ";
    rosidl_generator_traits::value_to_yaml(msg.from_value, out);
    out << "\n";
  }

  // member: to_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "to_value: ";
    rosidl_generator_traits::value_to_yaml(msg.to_value, out);
    out << "\n";
  }

  // member: step
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "step: ";
    rosidl_generator_traits::value_to_yaml(msg.step, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FloatingPointRange & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, rcl_interfaces::msg::FloatingPointRange>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).from_value,
    std::forward<T>(msg).to_value,
    std::forward<T>(msg).step);
}

}  // namespace msg

}  // namespace rcl_interfaces

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<rcl_interfaces::msg::FloatingPointRange>()
{
  return "rcl_interfaces::msg::FloatingPointRange";
}

template<>
constexpr const char * name<rcl_interfaces::msg::FloatingPointRange>()
{
  return "rcl_interfaces/msg/FloatingPointRange";
}

template<>
struct has_fixed_size<rcl_interfaces::msg::FloatingPointRange>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<rcl_interfaces::msg::FloatingPointRange>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<rcl_interfaces::msg::FloatingPointRange>
  : std::true_type {};

template<>
struct MessageTraits<rcl_interfaces::msg::FloatingPointRange>
{
  static constexpr std::size_t member_count = 3;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "from_value",
    "to_value",
    "step",
  };
};

}  // namespace rosidl_generator_traits

#endif  // RCL_INTERFACES__MSG__DETAIL__FLOATING_POINT_RANGE__TRAITS_HPP_
