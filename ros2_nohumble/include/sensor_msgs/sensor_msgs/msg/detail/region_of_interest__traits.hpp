// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from sensor_msgs:msg\RegionOfInterest.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "sensor_msgs/msg/region_of_interest.hpp"


#ifndef SENSOR_MSGS__MSG__DETAIL__REGION_OF_INTEREST__TRAITS_HPP_
#define SENSOR_MSGS__MSG__DETAIL__REGION_OF_INTEREST__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "sensor_msgs/msg/detail/region_of_interest__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace sensor_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const RegionOfInterest & msg,
  std::ostream & out)
{
  out << "{";
  // member: x_offset
  {
    out << "x_offset: ";
    rosidl_generator_traits::value_to_yaml(msg.x_offset, out);
    out << ", ";
  }

  // member: y_offset
  {
    out << "y_offset: ";
    rosidl_generator_traits::value_to_yaml(msg.y_offset, out);
    out << ", ";
  }

  // member: height
  {
    out << "height: ";
    rosidl_generator_traits::value_to_yaml(msg.height, out);
    out << ", ";
  }

  // member: width
  {
    out << "width: ";
    rosidl_generator_traits::value_to_yaml(msg.width, out);
    out << ", ";
  }

  // member: do_rectify
  {
    out << "do_rectify: ";
    rosidl_generator_traits::value_to_yaml(msg.do_rectify, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RegionOfInterest & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x_offset
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x_offset: ";
    rosidl_generator_traits::value_to_yaml(msg.x_offset, out);
    out << "\n";
  }

  // member: y_offset
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y_offset: ";
    rosidl_generator_traits::value_to_yaml(msg.y_offset, out);
    out << "\n";
  }

  // member: height
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "height: ";
    rosidl_generator_traits::value_to_yaml(msg.height, out);
    out << "\n";
  }

  // member: width
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "width: ";
    rosidl_generator_traits::value_to_yaml(msg.width, out);
    out << "\n";
  }

  // member: do_rectify
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "do_rectify: ";
    rosidl_generator_traits::value_to_yaml(msg.do_rectify, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RegionOfInterest & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, sensor_msgs::msg::RegionOfInterest>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).x_offset,
    std::forward<T>(msg).y_offset,
    std::forward<T>(msg).height,
    std::forward<T>(msg).width,
    std::forward<T>(msg).do_rectify);
}

}  // namespace msg

}  // namespace sensor_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<sensor_msgs::msg::RegionOfInterest>()
{
  return "sensor_msgs::msg::RegionOfInterest";
}

template<>
constexpr const char * name<sensor_msgs::msg::RegionOfInterest>()
{
  return "sensor_msgs/msg/RegionOfInterest";
}

template<>
struct has_fixed_size<sensor_msgs::msg::RegionOfInterest>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<sensor_msgs::msg::RegionOfInterest>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<sensor_msgs::msg::RegionOfInterest>
  : std::true_type {};

template<>
struct MessageTraits<sensor_msgs::msg::RegionOfInterest>
{
  static constexpr std::size_t member_count = 5;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "x_offset",
    "y_offset",
    "height",
    "width",
    "do_rectify",
  };
};

}  // namespace rosidl_generator_traits

#endif  // SENSOR_MSGS__MSG__DETAIL__REGION_OF_INTEREST__TRAITS_HPP_
