// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rosgraph_msgs:msg\TypeHash.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosgraph_msgs/msg/type_hash.hpp"


#ifndef ROSGRAPH_MSGS__MSG__DETAIL__TYPE_HASH__TRAITS_HPP_
#define ROSGRAPH_MSGS__MSG__DETAIL__TYPE_HASH__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "rosgraph_msgs/msg/detail/type_hash__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace rosgraph_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const TypeHash & msg,
  std::ostream & out)
{
  out << "{";
  // member: version
  {
    out << "version: ";
    rosidl_generator_traits::value_to_yaml(msg.version, out);
    out << ", ";
  }

  // member: value
  {
    if (msg.value.size() == 0) {
      out << "value: []";
    } else {
      out << "value: [";
      size_t pending_items = msg.value.size();
      for (auto item : msg.value) {
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
  const TypeHash & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: version
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "version: ";
    rosidl_generator_traits::value_to_yaml(msg.version, out);
    out << "\n";
  }

  // member: value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.value.size() == 0) {
      out << "value: []\n";
    } else {
      out << "value:\n";
      for (auto item : msg.value) {
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

inline std::string to_yaml(const TypeHash & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, rosgraph_msgs::msg::TypeHash>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).version,
    std::forward<T>(msg).value);
}

}  // namespace msg

}  // namespace rosgraph_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<rosgraph_msgs::msg::TypeHash>()
{
  return "rosgraph_msgs::msg::TypeHash";
}

template<>
constexpr const char * name<rosgraph_msgs::msg::TypeHash>()
{
  return "rosgraph_msgs/msg/TypeHash";
}

template<>
struct has_fixed_size<rosgraph_msgs::msg::TypeHash>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<rosgraph_msgs::msg::TypeHash>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<rosgraph_msgs::msg::TypeHash>
  : std::true_type {};

template<>
struct MessageTraits<rosgraph_msgs::msg::TypeHash>
{
  static constexpr std::size_t member_count = 2;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "version",
    "value",
  };
};

}  // namespace rosidl_generator_traits

#endif  // ROSGRAPH_MSGS__MSG__DETAIL__TYPE_HASH__TRAITS_HPP_
