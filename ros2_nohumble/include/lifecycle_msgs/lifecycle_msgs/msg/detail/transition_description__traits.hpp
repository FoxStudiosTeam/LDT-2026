// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from lifecycle_msgs:msg\TransitionDescription.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "lifecycle_msgs/msg/transition_description.hpp"


#ifndef LIFECYCLE_MSGS__MSG__DETAIL__TRANSITION_DESCRIPTION__TRAITS_HPP_
#define LIFECYCLE_MSGS__MSG__DETAIL__TRANSITION_DESCRIPTION__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "lifecycle_msgs/msg/detail/transition_description__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'transition'
#include "lifecycle_msgs/msg/detail/transition__traits.hpp"
// Member 'start_state'
// Member 'goal_state'
#include "lifecycle_msgs/msg/detail/state__traits.hpp"

namespace lifecycle_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const TransitionDescription & msg,
  std::ostream & out)
{
  out << "{";
  // member: transition
  {
    out << "transition: ";
    to_flow_style_yaml(msg.transition, out);
    out << ", ";
  }

  // member: start_state
  {
    out << "start_state: ";
    to_flow_style_yaml(msg.start_state, out);
    out << ", ";
  }

  // member: goal_state
  {
    out << "goal_state: ";
    to_flow_style_yaml(msg.goal_state, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TransitionDescription & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: transition
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "transition:\n";
    to_block_style_yaml(msg.transition, out, indentation + 2);
  }

  // member: start_state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "start_state:\n";
    to_block_style_yaml(msg.start_state, out, indentation + 2);
  }

  // member: goal_state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_state:\n";
    to_block_style_yaml(msg.goal_state, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TransitionDescription & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, lifecycle_msgs::msg::TransitionDescription>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).transition,
    std::forward<T>(msg).start_state,
    std::forward<T>(msg).goal_state);
}

}  // namespace msg

}  // namespace lifecycle_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<lifecycle_msgs::msg::TransitionDescription>()
{
  return "lifecycle_msgs::msg::TransitionDescription";
}

template<>
constexpr const char * name<lifecycle_msgs::msg::TransitionDescription>()
{
  return "lifecycle_msgs/msg/TransitionDescription";
}

template<>
struct has_fixed_size<lifecycle_msgs::msg::TransitionDescription>
  : std::integral_constant<bool, has_fixed_size<lifecycle_msgs::msg::State>::value && has_fixed_size<lifecycle_msgs::msg::Transition>::value> {};

template<>
struct has_bounded_size<lifecycle_msgs::msg::TransitionDescription>
  : std::integral_constant<bool, has_bounded_size<lifecycle_msgs::msg::State>::value && has_bounded_size<lifecycle_msgs::msg::Transition>::value> {};

template<>
struct is_message<lifecycle_msgs::msg::TransitionDescription>
  : std::true_type {};

template<>
struct MessageTraits<lifecycle_msgs::msg::TransitionDescription>
{
  static constexpr std::size_t member_count = 3;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "transition",
    "start_state",
    "goal_state",
  };
};

}  // namespace rosidl_generator_traits

#endif  // LIFECYCLE_MSGS__MSG__DETAIL__TRANSITION_DESCRIPTION__TRAITS_HPP_
