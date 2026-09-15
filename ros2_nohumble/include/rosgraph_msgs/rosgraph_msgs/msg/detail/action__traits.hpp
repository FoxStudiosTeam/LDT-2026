// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rosgraph_msgs:msg\Action.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosgraph_msgs/msg/action.hpp"


#ifndef ROSGRAPH_MSGS__MSG__DETAIL__ACTION__TRAITS_HPP_
#define ROSGRAPH_MSGS__MSG__DETAIL__ACTION__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "rosgraph_msgs/msg/detail/action__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'send_goal'
// Member 'get_result'
// Member 'cancel_goal'
#include "rosgraph_msgs/msg/detail/service__traits.hpp"
// Member 'feedback'
// Member 'status'
#include "rosgraph_msgs/msg/detail/topic__traits.hpp"

namespace rosgraph_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Action & msg,
  std::ostream & out)
{
  out << "{";
  // member: name
  {
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << ", ";
  }

  // member: send_goal
  {
    out << "send_goal: ";
    to_flow_style_yaml(msg.send_goal, out);
    out << ", ";
  }

  // member: get_result
  {
    out << "get_result: ";
    to_flow_style_yaml(msg.get_result, out);
    out << ", ";
  }

  // member: cancel_goal
  {
    out << "cancel_goal: ";
    to_flow_style_yaml(msg.cancel_goal, out);
    out << ", ";
  }

  // member: feedback
  {
    out << "feedback: ";
    to_flow_style_yaml(msg.feedback, out);
    out << ", ";
  }

  // member: status
  {
    out << "status: ";
    to_flow_style_yaml(msg.status, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Action & msg,
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

  // member: send_goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "send_goal:\n";
    to_block_style_yaml(msg.send_goal, out, indentation + 2);
  }

  // member: get_result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "get_result:\n";
    to_block_style_yaml(msg.get_result, out, indentation + 2);
  }

  // member: cancel_goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cancel_goal:\n";
    to_block_style_yaml(msg.cancel_goal, out, indentation + 2);
  }

  // member: feedback
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feedback:\n";
    to_block_style_yaml(msg.feedback, out, indentation + 2);
  }

  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status:\n";
    to_block_style_yaml(msg.status, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Action & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, rosgraph_msgs::msg::Action>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).name,
    std::forward<T>(msg).send_goal,
    std::forward<T>(msg).get_result,
    std::forward<T>(msg).cancel_goal,
    std::forward<T>(msg).feedback,
    std::forward<T>(msg).status);
}

}  // namespace msg

}  // namespace rosgraph_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<rosgraph_msgs::msg::Action>()
{
  return "rosgraph_msgs::msg::Action";
}

template<>
constexpr const char * name<rosgraph_msgs::msg::Action>()
{
  return "rosgraph_msgs/msg/Action";
}

template<>
struct has_fixed_size<rosgraph_msgs::msg::Action>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rosgraph_msgs::msg::Action>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<rosgraph_msgs::msg::Action>
  : std::true_type {};

template<>
struct MessageTraits<rosgraph_msgs::msg::Action>
{
  static constexpr std::size_t member_count = 6;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "name",
    "send_goal",
    "get_result",
    "cancel_goal",
    "feedback",
    "status",
  };
};

}  // namespace rosidl_generator_traits

#endif  // ROSGRAPH_MSGS__MSG__DETAIL__ACTION__TRAITS_HPP_
