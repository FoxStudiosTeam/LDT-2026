// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rcl_interfaces:msg\SetLoggerLevelsResult.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rcl_interfaces/msg/set_logger_levels_result.hpp"


#ifndef RCL_INTERFACES__MSG__DETAIL__SET_LOGGER_LEVELS_RESULT__TRAITS_HPP_
#define RCL_INTERFACES__MSG__DETAIL__SET_LOGGER_LEVELS_RESULT__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "rcl_interfaces/msg/detail/set_logger_levels_result__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace rcl_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const SetLoggerLevelsResult & msg,
  std::ostream & out)
{
  out << "{";
  // member: successful
  {
    out << "successful: ";
    rosidl_generator_traits::value_to_yaml(msg.successful, out);
    out << ", ";
  }

  // member: reason
  {
    out << "reason: ";
    rosidl_generator_traits::value_to_yaml(msg.reason, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetLoggerLevelsResult & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: successful
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "successful: ";
    rosidl_generator_traits::value_to_yaml(msg.successful, out);
    out << "\n";
  }

  // member: reason
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "reason: ";
    rosidl_generator_traits::value_to_yaml(msg.reason, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetLoggerLevelsResult & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, rcl_interfaces::msg::SetLoggerLevelsResult>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).successful,
    std::forward<T>(msg).reason);
}

}  // namespace msg

}  // namespace rcl_interfaces

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<rcl_interfaces::msg::SetLoggerLevelsResult>()
{
  return "rcl_interfaces::msg::SetLoggerLevelsResult";
}

template<>
constexpr const char * name<rcl_interfaces::msg::SetLoggerLevelsResult>()
{
  return "rcl_interfaces/msg/SetLoggerLevelsResult";
}

template<>
struct has_fixed_size<rcl_interfaces::msg::SetLoggerLevelsResult>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rcl_interfaces::msg::SetLoggerLevelsResult>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<rcl_interfaces::msg::SetLoggerLevelsResult>
  : std::true_type {};

template<>
struct MessageTraits<rcl_interfaces::msg::SetLoggerLevelsResult>
{
  static constexpr std::size_t member_count = 2;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "successful",
    "reason",
  };
};

}  // namespace rosidl_generator_traits

#endif  // RCL_INTERFACES__MSG__DETAIL__SET_LOGGER_LEVELS_RESULT__TRAITS_HPP_
