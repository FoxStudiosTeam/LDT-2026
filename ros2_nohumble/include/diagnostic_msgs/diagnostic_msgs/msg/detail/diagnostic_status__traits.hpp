// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from diagnostic_msgs:msg\DiagnosticStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "diagnostic_msgs/msg/diagnostic_status.hpp"


#ifndef DIAGNOSTIC_MSGS__MSG__DETAIL__DIAGNOSTIC_STATUS__TRAITS_HPP_
#define DIAGNOSTIC_MSGS__MSG__DETAIL__DIAGNOSTIC_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "diagnostic_msgs/msg/detail/diagnostic_status__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'values'
#include "diagnostic_msgs/msg/detail/key_value__traits.hpp"

namespace diagnostic_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const DiagnosticStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: level
  {
    out << "level: ";
    rosidl_generator_traits::character_value_to_yaml(msg.level, out);
    out << ", ";
  }

  // member: name
  {
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << ", ";
  }

  // member: hardware_id
  {
    out << "hardware_id: ";
    rosidl_generator_traits::value_to_yaml(msg.hardware_id, out);
    out << ", ";
  }

  // member: values
  {
    if (msg.values.size() == 0) {
      out << "values: []";
    } else {
      out << "values: [";
      size_t pending_items = msg.values.size();
      for (auto item : msg.values) {
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
  const DiagnosticStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: level
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "level: ";
    rosidl_generator_traits::character_value_to_yaml(msg.level, out);
    out << "\n";
  }

  // member: name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }

  // member: hardware_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "hardware_id: ";
    rosidl_generator_traits::value_to_yaml(msg.hardware_id, out);
    out << "\n";
  }

  // member: values
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.values.size() == 0) {
      out << "values: []\n";
    } else {
      out << "values:\n";
      for (auto item : msg.values) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DiagnosticStatus & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, diagnostic_msgs::msg::DiagnosticStatus>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).level,
    std::forward<T>(msg).name,
    std::forward<T>(msg).message,
    std::forward<T>(msg).hardware_id,
    std::forward<T>(msg).values);
}

}  // namespace msg

}  // namespace diagnostic_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<diagnostic_msgs::msg::DiagnosticStatus>()
{
  return "diagnostic_msgs::msg::DiagnosticStatus";
}

template<>
constexpr const char * name<diagnostic_msgs::msg::DiagnosticStatus>()
{
  return "diagnostic_msgs/msg/DiagnosticStatus";
}

template<>
struct has_fixed_size<diagnostic_msgs::msg::DiagnosticStatus>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<diagnostic_msgs::msg::DiagnosticStatus>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<diagnostic_msgs::msg::DiagnosticStatus>
  : std::true_type {};

template<>
struct MessageTraits<diagnostic_msgs::msg::DiagnosticStatus>
{
  static constexpr std::size_t member_count = 5;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "level",
    "name",
    "message",
    "hardware_id",
    "values",
  };
};

}  // namespace rosidl_generator_traits

#endif  // DIAGNOSTIC_MSGS__MSG__DETAIL__DIAGNOSTIC_STATUS__TRAITS_HPP_
