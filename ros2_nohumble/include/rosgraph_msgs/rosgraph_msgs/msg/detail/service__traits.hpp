// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rosgraph_msgs:msg\Service.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosgraph_msgs/msg/service.hpp"


#ifndef ROSGRAPH_MSGS__MSG__DETAIL__SERVICE__TRAITS_HPP_
#define ROSGRAPH_MSGS__MSG__DETAIL__SERVICE__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "rosgraph_msgs/msg/detail/service__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'request_type'
// Member 'response_type'
#include "rosgraph_msgs/msg/detail/interface_type__traits.hpp"
// Member 'request_qos'
// Member 'response_qos'
#include "rosgraph_msgs/msg/detail/qo_s_profile__traits.hpp"

namespace rosgraph_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Service & msg,
  std::ostream & out)
{
  out << "{";
  // member: name
  {
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << ", ";
  }

  // member: request_type
  {
    out << "request_type: ";
    to_flow_style_yaml(msg.request_type, out);
    out << ", ";
  }

  // member: request_qos
  {
    out << "request_qos: ";
    to_flow_style_yaml(msg.request_qos, out);
    out << ", ";
  }

  // member: response_type
  {
    out << "response_type: ";
    to_flow_style_yaml(msg.response_type, out);
    out << ", ";
  }

  // member: response_qos
  {
    out << "response_qos: ";
    to_flow_style_yaml(msg.response_qos, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Service & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << "\n";
  }

  // member: request_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "request_type:\n";
    to_block_style_yaml(msg.request_type, out, indentation + 2);
  }

  // member: request_qos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "request_qos:\n";
    to_block_style_yaml(msg.request_qos, out, indentation + 2);
  }

  // member: response_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "response_type:\n";
    to_block_style_yaml(msg.response_type, out, indentation + 2);
  }

  // member: response_qos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "response_qos:\n";
    to_block_style_yaml(msg.response_qos, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Service & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, rosgraph_msgs::msg::Service>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).name,
    std::forward<T>(msg).request_type,
    std::forward<T>(msg).request_qos,
    std::forward<T>(msg).response_type,
    std::forward<T>(msg).response_qos);
}

}  // namespace msg

}  // namespace rosgraph_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<rosgraph_msgs::msg::Service>()
{
  return "rosgraph_msgs::msg::Service";
}

template<>
constexpr const char * name<rosgraph_msgs::msg::Service>()
{
  return "rosgraph_msgs/msg/Service";
}

template<>
struct has_fixed_size<rosgraph_msgs::msg::Service>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rosgraph_msgs::msg::Service>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<rosgraph_msgs::msg::Service>
  : std::true_type {};

template<>
struct MessageTraits<rosgraph_msgs::msg::Service>
{
  static constexpr std::size_t member_count = 5;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "name",
    "request_type",
    "request_qos",
    "response_type",
    "response_qos",
  };
};

}  // namespace rosidl_generator_traits

#endif  // ROSGRAPH_MSGS__MSG__DETAIL__SERVICE__TRAITS_HPP_
