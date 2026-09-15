// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rcl_interfaces:msg\ParameterEventDescriptors.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rcl_interfaces/msg/parameter_event_descriptors.hpp"


#ifndef RCL_INTERFACES__MSG__DETAIL__PARAMETER_EVENT_DESCRIPTORS__TRAITS_HPP_
#define RCL_INTERFACES__MSG__DETAIL__PARAMETER_EVENT_DESCRIPTORS__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "rcl_interfaces/msg/detail/parameter_event_descriptors__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'new_parameters'
// Member 'changed_parameters'
// Member 'deleted_parameters'
#include "rcl_interfaces/msg/detail/parameter_descriptor__traits.hpp"

namespace rcl_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const ParameterEventDescriptors & msg,
  std::ostream & out)
{
  out << "{";
  // member: new_parameters
  {
    if (msg.new_parameters.size() == 0) {
      out << "new_parameters: []";
    } else {
      out << "new_parameters: [";
      size_t pending_items = msg.new_parameters.size();
      for (auto item : msg.new_parameters) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: changed_parameters
  {
    if (msg.changed_parameters.size() == 0) {
      out << "changed_parameters: []";
    } else {
      out << "changed_parameters: [";
      size_t pending_items = msg.changed_parameters.size();
      for (auto item : msg.changed_parameters) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: deleted_parameters
  {
    if (msg.deleted_parameters.size() == 0) {
      out << "deleted_parameters: []";
    } else {
      out << "deleted_parameters: [";
      size_t pending_items = msg.deleted_parameters.size();
      for (auto item : msg.deleted_parameters) {
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
  const ParameterEventDescriptors & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: new_parameters
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.new_parameters.size() == 0) {
      out << "new_parameters: []\n";
    } else {
      out << "new_parameters:\n";
      for (auto item : msg.new_parameters) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: changed_parameters
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.changed_parameters.size() == 0) {
      out << "changed_parameters: []\n";
    } else {
      out << "changed_parameters:\n";
      for (auto item : msg.changed_parameters) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: deleted_parameters
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.deleted_parameters.size() == 0) {
      out << "deleted_parameters: []\n";
    } else {
      out << "deleted_parameters:\n";
      for (auto item : msg.deleted_parameters) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ParameterEventDescriptors & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, rcl_interfaces::msg::ParameterEventDescriptors>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).new_parameters,
    std::forward<T>(msg).changed_parameters,
    std::forward<T>(msg).deleted_parameters);
}

}  // namespace msg

}  // namespace rcl_interfaces

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<rcl_interfaces::msg::ParameterEventDescriptors>()
{
  return "rcl_interfaces::msg::ParameterEventDescriptors";
}

template<>
constexpr const char * name<rcl_interfaces::msg::ParameterEventDescriptors>()
{
  return "rcl_interfaces/msg/ParameterEventDescriptors";
}

template<>
struct has_fixed_size<rcl_interfaces::msg::ParameterEventDescriptors>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rcl_interfaces::msg::ParameterEventDescriptors>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<rcl_interfaces::msg::ParameterEventDescriptors>
  : std::true_type {};

template<>
struct MessageTraits<rcl_interfaces::msg::ParameterEventDescriptors>
{
  static constexpr std::size_t member_count = 3;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "new_parameters",
    "changed_parameters",
    "deleted_parameters",
  };
};

}  // namespace rosidl_generator_traits

#endif  // RCL_INTERFACES__MSG__DETAIL__PARAMETER_EVENT_DESCRIPTORS__TRAITS_HPP_
