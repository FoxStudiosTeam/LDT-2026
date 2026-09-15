// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rosbag2_test_msgdefs:msg\ComplexMsgDependsOnIdl.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosbag2_test_msgdefs/msg/complex_msg_depends_on_idl.hpp"


#ifndef ROSBAG2_TEST_MSGDEFS__MSG__DETAIL__COMPLEX_MSG_DEPENDS_ON_IDL__TRAITS_HPP_
#define ROSBAG2_TEST_MSGDEFS__MSG__DETAIL__COMPLEX_MSG_DEPENDS_ON_IDL__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "rosbag2_test_msgdefs/msg/detail/complex_msg_depends_on_idl__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'a'
#include "rosbag2_test_msgdefs/msg/detail/basic_idl__traits.hpp"

namespace rosbag2_test_msgdefs
{

namespace msg
{

inline void to_flow_style_yaml(
  const ComplexMsgDependsOnIdl & msg,
  std::ostream & out)
{
  out << "{";
  // member: a
  {
    out << "a: ";
    to_flow_style_yaml(msg.a, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ComplexMsgDependsOnIdl & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: a
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "a:\n";
    to_block_style_yaml(msg.a, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ComplexMsgDependsOnIdl & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, rosbag2_test_msgdefs::msg::ComplexMsgDependsOnIdl>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(std::forward<T>(msg).a);
}

}  // namespace msg

}  // namespace rosbag2_test_msgdefs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<rosbag2_test_msgdefs::msg::ComplexMsgDependsOnIdl>()
{
  return "rosbag2_test_msgdefs::msg::ComplexMsgDependsOnIdl";
}

template<>
constexpr const char * name<rosbag2_test_msgdefs::msg::ComplexMsgDependsOnIdl>()
{
  return "rosbag2_test_msgdefs/msg/ComplexMsgDependsOnIdl";
}

template<>
struct has_fixed_size<rosbag2_test_msgdefs::msg::ComplexMsgDependsOnIdl>
  : std::integral_constant<bool, has_fixed_size<rosbag2_test_msgdefs::msg::BasicIdl>::value> {};

template<>
struct has_bounded_size<rosbag2_test_msgdefs::msg::ComplexMsgDependsOnIdl>
  : std::integral_constant<bool, has_bounded_size<rosbag2_test_msgdefs::msg::BasicIdl>::value> {};

template<>
struct is_message<rosbag2_test_msgdefs::msg::ComplexMsgDependsOnIdl>
  : std::true_type {};

template<>
struct MessageTraits<rosbag2_test_msgdefs::msg::ComplexMsgDependsOnIdl>
{
  static constexpr std::size_t member_count = 1;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "a",
  };
};

}  // namespace rosidl_generator_traits

#endif  // ROSBAG2_TEST_MSGDEFS__MSG__DETAIL__COMPLEX_MSG_DEPENDS_ON_IDL__TRAITS_HPP_
