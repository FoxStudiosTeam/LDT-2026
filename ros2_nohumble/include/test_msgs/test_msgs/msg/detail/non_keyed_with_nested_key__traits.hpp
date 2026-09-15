// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from test_msgs:msg\NonKeyedWithNestedKey.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "test_msgs/msg/non_keyed_with_nested_key.hpp"


#ifndef TEST_MSGS__MSG__DETAIL__NON_KEYED_WITH_NESTED_KEY__TRAITS_HPP_
#define TEST_MSGS__MSG__DETAIL__NON_KEYED_WITH_NESTED_KEY__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "test_msgs/msg/detail/non_keyed_with_nested_key__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'nested_data'
#include "test_msgs/msg/detail/keyed_string__traits.hpp"

namespace test_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const NonKeyedWithNestedKey & msg,
  std::ostream & out)
{
  out << "{";
  // member: nested_data
  {
    out << "nested_data: ";
    to_flow_style_yaml(msg.nested_data, out);
    out << ", ";
  }

  // member: some_int
  {
    out << "some_int: ";
    rosidl_generator_traits::value_to_yaml(msg.some_int, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NonKeyedWithNestedKey & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: nested_data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "nested_data:\n";
    to_block_style_yaml(msg.nested_data, out, indentation + 2);
  }

  // member: some_int
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "some_int: ";
    rosidl_generator_traits::value_to_yaml(msg.some_int, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NonKeyedWithNestedKey & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, test_msgs::msg::NonKeyedWithNestedKey>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).nested_data,
    std::forward<T>(msg).some_int);
}

}  // namespace msg

}  // namespace test_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<test_msgs::msg::NonKeyedWithNestedKey>()
{
  return "test_msgs::msg::NonKeyedWithNestedKey";
}

template<>
constexpr const char * name<test_msgs::msg::NonKeyedWithNestedKey>()
{
  return "test_msgs/msg/NonKeyedWithNestedKey";
}

template<>
struct has_fixed_size<test_msgs::msg::NonKeyedWithNestedKey>
  : std::integral_constant<bool, has_fixed_size<test_msgs::msg::KeyedString>::value> {};

template<>
struct has_bounded_size<test_msgs::msg::NonKeyedWithNestedKey>
  : std::integral_constant<bool, has_bounded_size<test_msgs::msg::KeyedString>::value> {};

template<>
struct is_message<test_msgs::msg::NonKeyedWithNestedKey>
  : std::true_type {};

template<>
struct MessageTraits<test_msgs::msg::NonKeyedWithNestedKey>
{
  static constexpr std::size_t member_count = 2;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "nested_data",
    "some_int",
  };
};

}  // namespace rosidl_generator_traits

#endif  // TEST_MSGS__MSG__DETAIL__NON_KEYED_WITH_NESTED_KEY__TRAITS_HPP_
