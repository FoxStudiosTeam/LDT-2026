// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from action_msgs:msg\GoalStatusArray.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "action_msgs/msg/goal_status_array.hpp"


#ifndef ACTION_MSGS__MSG__DETAIL__GOAL_STATUS_ARRAY__TRAITS_HPP_
#define ACTION_MSGS__MSG__DETAIL__GOAL_STATUS_ARRAY__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "action_msgs/msg/detail/goal_status_array__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'status_list'
#include "action_msgs/msg/detail/goal_status__traits.hpp"

namespace action_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const GoalStatusArray & msg,
  std::ostream & out)
{
  out << "{";
  // member: status_list
  {
    if (msg.status_list.size() == 0) {
      out << "status_list: []";
    } else {
      out << "status_list: [";
      size_t pending_items = msg.status_list.size();
      for (auto item : msg.status_list) {
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
  const GoalStatusArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status_list
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.status_list.size() == 0) {
      out << "status_list: []\n";
    } else {
      out << "status_list:\n";
      for (auto item : msg.status_list) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GoalStatusArray & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, action_msgs::msg::GoalStatusArray>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(std::forward<T>(msg).status_list);
}

}  // namespace msg

}  // namespace action_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<action_msgs::msg::GoalStatusArray>()
{
  return "action_msgs::msg::GoalStatusArray";
}

template<>
constexpr const char * name<action_msgs::msg::GoalStatusArray>()
{
  return "action_msgs/msg/GoalStatusArray";
}

template<>
struct has_fixed_size<action_msgs::msg::GoalStatusArray>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<action_msgs::msg::GoalStatusArray>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<action_msgs::msg::GoalStatusArray>
  : std::true_type {};

template<>
struct MessageTraits<action_msgs::msg::GoalStatusArray>
{
  static constexpr std::size_t member_count = 1;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "status_list",
  };
};

}  // namespace rosidl_generator_traits

#endif  // ACTION_MSGS__MSG__DETAIL__GOAL_STATUS_ARRAY__TRAITS_HPP_
