// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from sensor_msgs:msg\LaserScan.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "sensor_msgs/msg/laser_scan.hpp"


#ifndef SENSOR_MSGS__MSG__DETAIL__LASER_SCAN__TRAITS_HPP_
#define SENSOR_MSGS__MSG__DETAIL__LASER_SCAN__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "sensor_msgs/msg/detail/laser_scan__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace sensor_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const LaserScan & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: angle_min
  {
    out << "angle_min: ";
    rosidl_generator_traits::value_to_yaml(msg.angle_min, out);
    out << ", ";
  }

  // member: angle_max
  {
    out << "angle_max: ";
    rosidl_generator_traits::value_to_yaml(msg.angle_max, out);
    out << ", ";
  }

  // member: angle_increment
  {
    out << "angle_increment: ";
    rosidl_generator_traits::value_to_yaml(msg.angle_increment, out);
    out << ", ";
  }

  // member: time_increment
  {
    out << "time_increment: ";
    rosidl_generator_traits::value_to_yaml(msg.time_increment, out);
    out << ", ";
  }

  // member: scan_time
  {
    out << "scan_time: ";
    rosidl_generator_traits::value_to_yaml(msg.scan_time, out);
    out << ", ";
  }

  // member: range_min
  {
    out << "range_min: ";
    rosidl_generator_traits::value_to_yaml(msg.range_min, out);
    out << ", ";
  }

  // member: range_max
  {
    out << "range_max: ";
    rosidl_generator_traits::value_to_yaml(msg.range_max, out);
    out << ", ";
  }

  // member: ranges
  {
    if (msg.ranges.size() == 0) {
      out << "ranges: []";
    } else {
      out << "ranges: [";
      size_t pending_items = msg.ranges.size();
      for (auto item : msg.ranges) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: intensities
  {
    if (msg.intensities.size() == 0) {
      out << "intensities: []";
    } else {
      out << "intensities: [";
      size_t pending_items = msg.intensities.size();
      for (auto item : msg.intensities) {
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
  const LaserScan & msg,
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

  // member: angle_min
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angle_min: ";
    rosidl_generator_traits::value_to_yaml(msg.angle_min, out);
    out << "\n";
  }

  // member: angle_max
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angle_max: ";
    rosidl_generator_traits::value_to_yaml(msg.angle_max, out);
    out << "\n";
  }

  // member: angle_increment
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angle_increment: ";
    rosidl_generator_traits::value_to_yaml(msg.angle_increment, out);
    out << "\n";
  }

  // member: time_increment
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "time_increment: ";
    rosidl_generator_traits::value_to_yaml(msg.time_increment, out);
    out << "\n";
  }

  // member: scan_time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "scan_time: ";
    rosidl_generator_traits::value_to_yaml(msg.scan_time, out);
    out << "\n";
  }

  // member: range_min
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "range_min: ";
    rosidl_generator_traits::value_to_yaml(msg.range_min, out);
    out << "\n";
  }

  // member: range_max
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "range_max: ";
    rosidl_generator_traits::value_to_yaml(msg.range_max, out);
    out << "\n";
  }

  // member: ranges
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.ranges.size() == 0) {
      out << "ranges: []\n";
    } else {
      out << "ranges:\n";
      for (auto item : msg.ranges) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: intensities
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.intensities.size() == 0) {
      out << "intensities: []\n";
    } else {
      out << "intensities:\n";
      for (auto item : msg.intensities) {
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

inline std::string to_yaml(const LaserScan & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, sensor_msgs::msg::LaserScan>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).header,
    std::forward<T>(msg).angle_min,
    std::forward<T>(msg).angle_max,
    std::forward<T>(msg).angle_increment,
    std::forward<T>(msg).time_increment,
    std::forward<T>(msg).scan_time,
    std::forward<T>(msg).range_min,
    std::forward<T>(msg).range_max,
    std::forward<T>(msg).ranges,
    std::forward<T>(msg).intensities);
}

}  // namespace msg

}  // namespace sensor_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<sensor_msgs::msg::LaserScan>()
{
  return "sensor_msgs::msg::LaserScan";
}

template<>
constexpr const char * name<sensor_msgs::msg::LaserScan>()
{
  return "sensor_msgs/msg/LaserScan";
}

template<>
struct has_fixed_size<sensor_msgs::msg::LaserScan>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<sensor_msgs::msg::LaserScan>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<sensor_msgs::msg::LaserScan>
  : std::true_type {};

template<>
struct MessageTraits<sensor_msgs::msg::LaserScan>
{
  static constexpr std::size_t member_count = 10;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "header",
    "angle_min",
    "angle_max",
    "angle_increment",
    "time_increment",
    "scan_time",
    "range_min",
    "range_max",
    "ranges",
    "intensities",
  };
};

}  // namespace rosidl_generator_traits

#endif  // SENSOR_MSGS__MSG__DETAIL__LASER_SCAN__TRAITS_HPP_
