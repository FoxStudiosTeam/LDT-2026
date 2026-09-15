// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rosgraph_msgs:msg\Graph.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosgraph_msgs/msg/graph.hpp"


#ifndef ROSGRAPH_MSGS__MSG__DETAIL__GRAPH__TRAITS_HPP_
#define ROSGRAPH_MSGS__MSG__DETAIL__GRAPH__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "rosgraph_msgs/msg/detail/graph__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'nodes'
#include "rosgraph_msgs/msg/detail/node__traits.hpp"

namespace rosgraph_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Graph & msg,
  std::ostream & out)
{
  out << "{";
  // member: nodes
  {
    if (msg.nodes.size() == 0) {
      out << "nodes: []";
    } else {
      out << "nodes: [";
      size_t pending_items = msg.nodes.size();
      for (auto item : msg.nodes) {
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
  const Graph & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: nodes
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.nodes.size() == 0) {
      out << "nodes: []\n";
    } else {
      out << "nodes:\n";
      for (auto item : msg.nodes) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Graph & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, rosgraph_msgs::msg::Graph>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(std::forward<T>(msg).nodes);
}

}  // namespace msg

}  // namespace rosgraph_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<rosgraph_msgs::msg::Graph>()
{
  return "rosgraph_msgs::msg::Graph";
}

template<>
constexpr const char * name<rosgraph_msgs::msg::Graph>()
{
  return "rosgraph_msgs/msg/Graph";
}

template<>
struct has_fixed_size<rosgraph_msgs::msg::Graph>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rosgraph_msgs::msg::Graph>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<rosgraph_msgs::msg::Graph>
  : std::true_type {};

template<>
struct MessageTraits<rosgraph_msgs::msg::Graph>
{
  static constexpr std::size_t member_count = 1;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "nodes",
  };
};

}  // namespace rosidl_generator_traits

#endif  // ROSGRAPH_MSGS__MSG__DETAIL__GRAPH__TRAITS_HPP_
