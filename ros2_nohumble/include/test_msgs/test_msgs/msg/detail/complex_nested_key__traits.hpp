// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from test_msgs:msg\ComplexNestedKey.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "test_msgs/msg/complex_nested_key.hpp"


#ifndef TEST_MSGS__MSG__DETAIL__COMPLEX_NESTED_KEY__TRAITS_HPP_
#define TEST_MSGS__MSG__DETAIL__COMPLEX_NESTED_KEY__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "test_msgs/msg/detail/complex_nested_key__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'nested_keys'
#include "test_msgs/msg/detail/non_keyed_with_nested_key__traits.hpp"

namespace test_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const ComplexNestedKey & msg,
  std::ostream & out)
{
  out << "{";
  // member: uint32_key
  {
    out << "uint32_key: ";
    rosidl_generator_traits::value_to_yaml(msg.uint32_key, out);
    out << ", ";
  }

  // member: nested_keys
  {
    out << "nested_keys: ";
    to_flow_style_yaml(msg.nested_keys, out);
    out << ", ";
  }

  // member: float64_value
  {
    out << "float64_value: ";
    rosidl_generator_traits::value_to_yaml(msg.float64_value, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ComplexNestedKey & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: uint32_key
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "uint32_key: ";
    rosidl_generator_traits::value_to_yaml(msg.uint32_key, out);
    out << "\n";
  }

  // member: nested_keys
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "nested_keys:\n";
    to_block_style_yaml(msg.nested_keys, out, indentation + 2);
  }

  // member: float64_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "float64_value: ";
    rosidl_generator_traits::value_to_yaml(msg.float64_value, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ComplexNestedKey & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, test_msgs::msg::ComplexNestedKey>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).uint32_key,
    std::forward<T>(msg).nested_keys,
    std::forward<T>(msg).float64_value);
}

}  // namespace msg

}  // namespace test_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<test_msgs::msg::ComplexNestedKey>()
{
  return "test_msgs::msg::ComplexNestedKey";
}

template<>
constexpr const char * name<test_msgs::msg::ComplexNestedKey>()
{
  return "test_msgs/msg/ComplexNestedKey";
}

template<>
struct has_fixed_size<test_msgs::msg::ComplexNestedKey>
  : std::integral_constant<bool, has_fixed_size<test_msgs::msg::NonKeyedWithNestedKey>::value> {};

template<>
struct has_bounded_size<test_msgs::msg::ComplexNestedKey>
  : std::integral_constant<bool, has_bounded_size<test_msgs::msg::NonKeyedWithNestedKey>::value> {};

template<>
struct is_message<test_msgs::msg::ComplexNestedKey>
  : std::true_type {};

template<>
struct MessageTraits<test_msgs::msg::ComplexNestedKey>
{
  static constexpr std::size_t member_count = 3;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "uint32_key",
    "nested_keys",
    "float64_value",
  };
};

}  // namespace rosidl_generator_traits

#endif  // TEST_MSGS__MSG__DETAIL__COMPLEX_NESTED_KEY__TRAITS_HPP_
