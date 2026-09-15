// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rosgraph_msgs:msg\Topic.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosgraph_msgs/msg/topic.hpp"


#ifndef ROSGRAPH_MSGS__MSG__DETAIL__TOPIC__TRAITS_HPP_
#define ROSGRAPH_MSGS__MSG__DETAIL__TOPIC__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "rosgraph_msgs/msg/detail/topic__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'type'
#include "rosgraph_msgs/msg/detail/interface_type__traits.hpp"
// Member 'qos'
#include "rosgraph_msgs/msg/detail/qo_s_profile__traits.hpp"

namespace rosgraph_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Topic & msg,
  std::ostream & out)
{
  out << "{";
  // member: name
  {
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << ", ";
  }

  // member: type
  {
    out << "type: ";
    to_flow_style_yaml(msg.type, out);
    out << ", ";
  }

  // member: qos
  {
    out << "qos: ";
    to_flow_style_yaml(msg.qos, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Topic & msg,
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

  // member: type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "type:\n";
    to_block_style_yaml(msg.type, out, indentation + 2);
  }

  // member: qos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "qos:\n";
    to_block_style_yaml(msg.qos, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Topic & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, rosgraph_msgs::msg::Topic>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).name,
    std::forward<T>(msg).type,
    std::forward<T>(msg).qos);
}

}  // namespace msg

}  // namespace rosgraph_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<rosgraph_msgs::msg::Topic>()
{
  return "rosgraph_msgs::msg::Topic";
}

template<>
constexpr const char * name<rosgraph_msgs::msg::Topic>()
{
  return "rosgraph_msgs/msg/Topic";
}

template<>
struct has_fixed_size<rosgraph_msgs::msg::Topic>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rosgraph_msgs::msg::Topic>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<rosgraph_msgs::msg::Topic>
  : std::true_type {};

template<>
struct MessageTraits<rosgraph_msgs::msg::Topic>
{
  static constexpr std::size_t member_count = 3;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "name",
    "type",
    "qos",
  };
};

}  // namespace rosidl_generator_traits

#endif  // ROSGRAPH_MSGS__MSG__DETAIL__TOPIC__TRAITS_HPP_
