// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from trajectory_msgs:msg\MultiDOFJointTrajectoryPoint.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "trajectory_msgs/msg/multi_dof_joint_trajectory_point.hpp"


#ifndef TRAJECTORY_MSGS__MSG__DETAIL__MULTI_DOF_JOINT_TRAJECTORY_POINT__TRAITS_HPP_
#define TRAJECTORY_MSGS__MSG__DETAIL__MULTI_DOF_JOINT_TRAJECTORY_POINT__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "trajectory_msgs/msg/detail/multi_dof_joint_trajectory_point__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'transforms'
#include "geometry_msgs/msg/detail/transform__traits.hpp"
// Member 'velocities'
// Member 'accelerations'
#include "geometry_msgs/msg/detail/twist__traits.hpp"
// Member 'time_from_start'
#include "builtin_interfaces/msg/detail/duration__traits.hpp"

namespace trajectory_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const MultiDOFJointTrajectoryPoint & msg,
  std::ostream & out)
{
  out << "{";
  // member: transforms
  {
    if (msg.transforms.size() == 0) {
      out << "transforms: []";
    } else {
      out << "transforms: [";
      size_t pending_items = msg.transforms.size();
      for (auto item : msg.transforms) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: velocities
  {
    if (msg.velocities.size() == 0) {
      out << "velocities: []";
    } else {
      out << "velocities: [";
      size_t pending_items = msg.velocities.size();
      for (auto item : msg.velocities) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: accelerations
  {
    if (msg.accelerations.size() == 0) {
      out << "accelerations: []";
    } else {
      out << "accelerations: [";
      size_t pending_items = msg.accelerations.size();
      for (auto item : msg.accelerations) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: time_from_start
  {
    out << "time_from_start: ";
    to_flow_style_yaml(msg.time_from_start, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MultiDOFJointTrajectoryPoint & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: transforms
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.transforms.size() == 0) {
      out << "transforms: []\n";
    } else {
      out << "transforms:\n";
      for (auto item : msg.transforms) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: velocities
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.velocities.size() == 0) {
      out << "velocities: []\n";
    } else {
      out << "velocities:\n";
      for (auto item : msg.velocities) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: accelerations
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.accelerations.size() == 0) {
      out << "accelerations: []\n";
    } else {
      out << "accelerations:\n";
      for (auto item : msg.accelerations) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: time_from_start
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "time_from_start:\n";
    to_block_style_yaml(msg.time_from_start, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MultiDOFJointTrajectoryPoint & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, trajectory_msgs::msg::MultiDOFJointTrajectoryPoint>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).transforms,
    std::forward<T>(msg).velocities,
    std::forward<T>(msg).accelerations,
    std::forward<T>(msg).time_from_start);
}

}  // namespace msg

}  // namespace trajectory_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<trajectory_msgs::msg::MultiDOFJointTrajectoryPoint>()
{
  return "trajectory_msgs::msg::MultiDOFJointTrajectoryPoint";
}

template<>
constexpr const char * name<trajectory_msgs::msg::MultiDOFJointTrajectoryPoint>()
{
  return "trajectory_msgs/msg/MultiDOFJointTrajectoryPoint";
}

template<>
struct has_fixed_size<trajectory_msgs::msg::MultiDOFJointTrajectoryPoint>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<trajectory_msgs::msg::MultiDOFJointTrajectoryPoint>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<trajectory_msgs::msg::MultiDOFJointTrajectoryPoint>
  : std::true_type {};

template<>
struct MessageTraits<trajectory_msgs::msg::MultiDOFJointTrajectoryPoint>
{
  static constexpr std::size_t member_count = 4;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "transforms",
    "velocities",
    "accelerations",
    "time_from_start",
  };
};

}  // namespace rosidl_generator_traits

#endif  // TRAJECTORY_MSGS__MSG__DETAIL__MULTI_DOF_JOINT_TRAJECTORY_POINT__TRAITS_HPP_
