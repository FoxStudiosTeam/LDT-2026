// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from test_msgs:msg\Defaults.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "test_msgs/msg/defaults.hpp"


#ifndef TEST_MSGS__MSG__DETAIL__DEFAULTS__TRAITS_HPP_
#define TEST_MSGS__MSG__DETAIL__DEFAULTS__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "test_msgs/msg/detail/defaults__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace test_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Defaults & msg,
  std::ostream & out)
{
  out << "{";
  // member: bool_value
  {
    out << "bool_value: ";
    rosidl_generator_traits::value_to_yaml(msg.bool_value, out);
    out << ", ";
  }

  // member: byte_value
  {
    out << "byte_value: ";
    rosidl_generator_traits::character_value_to_yaml(msg.byte_value, out);
    out << ", ";
  }

  // member: char_value
  {
    out << "char_value: ";
    rosidl_generator_traits::value_to_yaml(msg.char_value, out);
    out << ", ";
  }

  // member: float32_value
  {
    out << "float32_value: ";
    rosidl_generator_traits::value_to_yaml(msg.float32_value, out);
    out << ", ";
  }

  // member: float64_value
  {
    out << "float64_value: ";
    rosidl_generator_traits::value_to_yaml(msg.float64_value, out);
    out << ", ";
  }

  // member: int8_value
  {
    out << "int8_value: ";
    rosidl_generator_traits::value_to_yaml(msg.int8_value, out);
    out << ", ";
  }

  // member: uint8_value
  {
    out << "uint8_value: ";
    rosidl_generator_traits::value_to_yaml(msg.uint8_value, out);
    out << ", ";
  }

  // member: int16_value
  {
    out << "int16_value: ";
    rosidl_generator_traits::value_to_yaml(msg.int16_value, out);
    out << ", ";
  }

  // member: uint16_value
  {
    out << "uint16_value: ";
    rosidl_generator_traits::value_to_yaml(msg.uint16_value, out);
    out << ", ";
  }

  // member: int32_value
  {
    out << "int32_value: ";
    rosidl_generator_traits::value_to_yaml(msg.int32_value, out);
    out << ", ";
  }

  // member: uint32_value
  {
    out << "uint32_value: ";
    rosidl_generator_traits::value_to_yaml(msg.uint32_value, out);
    out << ", ";
  }

  // member: int64_value
  {
    out << "int64_value: ";
    rosidl_generator_traits::value_to_yaml(msg.int64_value, out);
    out << ", ";
  }

  // member: uint64_value
  {
    out << "uint64_value: ";
    rosidl_generator_traits::value_to_yaml(msg.uint64_value, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Defaults & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: bool_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bool_value: ";
    rosidl_generator_traits::value_to_yaml(msg.bool_value, out);
    out << "\n";
  }

  // member: byte_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "byte_value: ";
    rosidl_generator_traits::character_value_to_yaml(msg.byte_value, out);
    out << "\n";
  }

  // member: char_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "char_value: ";
    rosidl_generator_traits::value_to_yaml(msg.char_value, out);
    out << "\n";
  }

  // member: float32_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "float32_value: ";
    rosidl_generator_traits::value_to_yaml(msg.float32_value, out);
    out << "\n";
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

  // member: int8_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "int8_value: ";
    rosidl_generator_traits::value_to_yaml(msg.int8_value, out);
    out << "\n";
  }

  // member: uint8_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "uint8_value: ";
    rosidl_generator_traits::value_to_yaml(msg.uint8_value, out);
    out << "\n";
  }

  // member: int16_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "int16_value: ";
    rosidl_generator_traits::value_to_yaml(msg.int16_value, out);
    out << "\n";
  }

  // member: uint16_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "uint16_value: ";
    rosidl_generator_traits::value_to_yaml(msg.uint16_value, out);
    out << "\n";
  }

  // member: int32_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "int32_value: ";
    rosidl_generator_traits::value_to_yaml(msg.int32_value, out);
    out << "\n";
  }

  // member: uint32_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "uint32_value: ";
    rosidl_generator_traits::value_to_yaml(msg.uint32_value, out);
    out << "\n";
  }

  // member: int64_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "int64_value: ";
    rosidl_generator_traits::value_to_yaml(msg.int64_value, out);
    out << "\n";
  }

  // member: uint64_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "uint64_value: ";
    rosidl_generator_traits::value_to_yaml(msg.uint64_value, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Defaults & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, test_msgs::msg::Defaults>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).bool_value,
    std::forward<T>(msg).byte_value,
    std::forward<T>(msg).char_value,
    std::forward<T>(msg).float32_value,
    std::forward<T>(msg).float64_value,
    std::forward<T>(msg).int8_value,
    std::forward<T>(msg).uint8_value,
    std::forward<T>(msg).int16_value,
    std::forward<T>(msg).uint16_value,
    std::forward<T>(msg).int32_value,
    std::forward<T>(msg).uint32_value,
    std::forward<T>(msg).int64_value,
    std::forward<T>(msg).uint64_value);
}

}  // namespace msg

}  // namespace test_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<test_msgs::msg::Defaults>()
{
  return "test_msgs::msg::Defaults";
}

template<>
constexpr const char * name<test_msgs::msg::Defaults>()
{
  return "test_msgs/msg/Defaults";
}

template<>
struct has_fixed_size<test_msgs::msg::Defaults>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<test_msgs::msg::Defaults>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<test_msgs::msg::Defaults>
  : std::true_type {};

template<>
struct MessageTraits<test_msgs::msg::Defaults>
{
  static constexpr std::size_t member_count = 13;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "bool_value",
    "byte_value",
    "char_value",
    "float32_value",
    "float64_value",
    "int8_value",
    "uint8_value",
    "int16_value",
    "uint16_value",
    "int32_value",
    "uint32_value",
    "int64_value",
    "uint64_value",
  };
};

}  // namespace rosidl_generator_traits

#endif  // TEST_MSGS__MSG__DETAIL__DEFAULTS__TRAITS_HPP_
