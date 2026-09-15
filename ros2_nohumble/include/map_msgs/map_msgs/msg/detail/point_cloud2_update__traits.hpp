// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from map_msgs:msg\PointCloud2Update.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "map_msgs/msg/point_cloud2_update.hpp"


#ifndef MAP_MSGS__MSG__DETAIL__POINT_CLOUD2_UPDATE__TRAITS_HPP_
#define MAP_MSGS__MSG__DETAIL__POINT_CLOUD2_UPDATE__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "map_msgs/msg/detail/point_cloud2_update__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'points'
#include "sensor_msgs/msg/detail/point_cloud2__traits.hpp"

namespace map_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const PointCloud2Update & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: type
  {
    out << "type: ";
    rosidl_generator_traits::value_to_yaml(msg.type, out);
    out << ", ";
  }

  // member: points
  {
    out << "points: ";
    to_flow_style_yaml(msg.points, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PointCloud2Update & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "type: ";
    rosidl_generator_traits::value_to_yaml(msg.type, out);
    out << "\n";
  }

  // member: points
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "points:\n";
    to_block_style_yaml(msg.points, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PointCloud2Update & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, map_msgs::msg::PointCloud2Update>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).header,
    std::forward<T>(msg).type,
    std::forward<T>(msg).points);
}

}  // namespace msg

}  // namespace map_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<map_msgs::msg::PointCloud2Update>()
{
  return "map_msgs::msg::PointCloud2Update";
}

template<>
constexpr const char * name<map_msgs::msg::PointCloud2Update>()
{
  return "map_msgs/msg/PointCloud2Update";
}

template<>
struct has_fixed_size<map_msgs::msg::PointCloud2Update>
  : std::integral_constant<bool, has_fixed_size<sensor_msgs::msg::PointCloud2>::value && has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<map_msgs::msg::PointCloud2Update>
  : std::integral_constant<bool, has_bounded_size<sensor_msgs::msg::PointCloud2>::value && has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<map_msgs::msg::PointCloud2Update>
  : std::true_type {};

template<>
struct MessageTraits<map_msgs::msg::PointCloud2Update>
{
  static constexpr std::size_t member_count = 3;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "header",
    "type",
    "points",
  };
};

}  // namespace rosidl_generator_traits

#endif  // MAP_MSGS__MSG__DETAIL__POINT_CLOUD2_UPDATE__TRAITS_HPP_
