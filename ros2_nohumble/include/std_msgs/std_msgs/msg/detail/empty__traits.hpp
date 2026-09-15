// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from std_msgs:msg\Empty.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "std_msgs/msg/empty.hpp"


#ifndef STD_MSGS__MSG__DETAIL__EMPTY__TRAITS_HPP_
#define STD_MSGS__MSG__DETAIL__EMPTY__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "std_msgs/msg/detail/empty__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace std_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Empty & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Empty & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Empty & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, std_msgs::msg::Empty>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(std::forward<T>(msg).structure_needs_at_least_one_member);
}

}  // namespace msg

}  // namespace std_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<std_msgs::msg::Empty>()
{
  return "std_msgs::msg::Empty";
}

template<>
constexpr const char * name<std_msgs::msg::Empty>()
{
  return "std_msgs/msg/Empty";
}

template<>
struct has_fixed_size<std_msgs::msg::Empty>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<std_msgs::msg::Empty>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<std_msgs::msg::Empty>
  : std::true_type {};

template<>
struct MessageTraits<std_msgs::msg::Empty>
{
  static constexpr std::size_t member_count = 1;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "structure_needs_at_least_one_member",
  };
};

}  // namespace rosidl_generator_traits

#endif  // STD_MSGS__MSG__DETAIL__EMPTY__TRAITS_HPP_
