// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from visualization_msgs:msg\MarkerArray.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "visualization_msgs/msg/marker_array.hpp"


#ifndef VISUALIZATION_MSGS__MSG__DETAIL__MARKER_ARRAY__TRAITS_HPP_
#define VISUALIZATION_MSGS__MSG__DETAIL__MARKER_ARRAY__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "visualization_msgs/msg/detail/marker_array__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'markers'
#include "visualization_msgs/msg/detail/marker__traits.hpp"

namespace visualization_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const MarkerArray & msg,
  std::ostream & out)
{
  out << "{";
  // member: markers
  {
    if (msg.markers.size() == 0) {
      out << "markers: []";
    } else {
      out << "markers: [";
      size_t pending_items = msg.markers.size();
      for (auto item : msg.markers) {
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
  const MarkerArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: markers
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.markers.size() == 0) {
      out << "markers: []\n";
    } else {
      out << "markers:\n";
      for (auto item : msg.markers) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MarkerArray & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, visualization_msgs::msg::MarkerArray>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(std::forward<T>(msg).markers);
}

}  // namespace msg

}  // namespace visualization_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<visualization_msgs::msg::MarkerArray>()
{
  return "visualization_msgs::msg::MarkerArray";
}

template<>
constexpr const char * name<visualization_msgs::msg::MarkerArray>()
{
  return "visualization_msgs/msg/MarkerArray";
}

template<>
struct has_fixed_size<visualization_msgs::msg::MarkerArray>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<visualization_msgs::msg::MarkerArray>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<visualization_msgs::msg::MarkerArray>
  : std::true_type {};

template<>
struct MessageTraits<visualization_msgs::msg::MarkerArray>
{
  static constexpr std::size_t member_count = 1;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "markers",
  };
};

}  // namespace rosidl_generator_traits

#endif  // VISUALIZATION_MSGS__MSG__DETAIL__MARKER_ARRAY__TRAITS_HPP_
