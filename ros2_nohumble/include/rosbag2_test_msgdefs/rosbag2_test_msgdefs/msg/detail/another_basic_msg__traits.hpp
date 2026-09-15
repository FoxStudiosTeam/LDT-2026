// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rosbag2_test_msgdefs:msg\AnotherBasicMsg.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosbag2_test_msgdefs/msg/another_basic_msg.hpp"


#ifndef ROSBAG2_TEST_MSGDEFS__MSG__DETAIL__ANOTHER_BASIC_MSG__TRAITS_HPP_
#define ROSBAG2_TEST_MSGDEFS__MSG__DETAIL__ANOTHER_BASIC_MSG__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "rosbag2_test_msgdefs/msg/detail/another_basic_msg__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace rosbag2_test_msgdefs
{

namespace msg
{

inline void to_flow_style_yaml(
  const AnotherBasicMsg & msg,
  std::ostream & out)
{
  out << "{";
  // member: c
  {
    out << "c: ";
    rosidl_generator_traits::value_to_yaml(msg.c, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const AnotherBasicMsg & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: c
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "c: ";
    rosidl_generator_traits::value_to_yaml(msg.c, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const AnotherBasicMsg & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, rosbag2_test_msgdefs::msg::AnotherBasicMsg>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(std::forward<T>(msg).c);
}

}  // namespace msg

}  // namespace rosbag2_test_msgdefs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<rosbag2_test_msgdefs::msg::AnotherBasicMsg>()
{
  return "rosbag2_test_msgdefs::msg::AnotherBasicMsg";
}

template<>
constexpr const char * name<rosbag2_test_msgdefs::msg::AnotherBasicMsg>()
{
  return "rosbag2_test_msgdefs/msg/AnotherBasicMsg";
}

template<>
struct has_fixed_size<rosbag2_test_msgdefs::msg::AnotherBasicMsg>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<rosbag2_test_msgdefs::msg::AnotherBasicMsg>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<rosbag2_test_msgdefs::msg::AnotherBasicMsg>
  : std::true_type {};

template<>
struct MessageTraits<rosbag2_test_msgdefs::msg::AnotherBasicMsg>
{
  static constexpr std::size_t member_count = 1;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "c",
  };
};

}  // namespace rosidl_generator_traits

#endif  // ROSBAG2_TEST_MSGDEFS__MSG__DETAIL__ANOTHER_BASIC_MSG__TRAITS_HPP_
