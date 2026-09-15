// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from test_msgs:msg\Strings.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "test_msgs/msg/strings.hpp"


#ifndef TEST_MSGS__MSG__DETAIL__STRINGS__TRAITS_HPP_
#define TEST_MSGS__MSG__DETAIL__STRINGS__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "test_msgs/msg/detail/strings__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace test_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Strings & msg,
  std::ostream & out)
{
  out << "{";
  // member: string_value
  {
    out << "string_value: ";
    rosidl_generator_traits::value_to_yaml(msg.string_value, out);
    out << ", ";
  }

  // member: string_value_default1
  {
    out << "string_value_default1: ";
    rosidl_generator_traits::value_to_yaml(msg.string_value_default1, out);
    out << ", ";
  }

  // member: string_value_default2
  {
    out << "string_value_default2: ";
    rosidl_generator_traits::value_to_yaml(msg.string_value_default2, out);
    out << ", ";
  }

  // member: string_value_default3
  {
    out << "string_value_default3: ";
    rosidl_generator_traits::value_to_yaml(msg.string_value_default3, out);
    out << ", ";
  }

  // member: string_value_default4
  {
    out << "string_value_default4: ";
    rosidl_generator_traits::value_to_yaml(msg.string_value_default4, out);
    out << ", ";
  }

  // member: string_value_default5
  {
    out << "string_value_default5: ";
    rosidl_generator_traits::value_to_yaml(msg.string_value_default5, out);
    out << ", ";
  }

  // member: bounded_string_value
  {
    out << "bounded_string_value: ";
    rosidl_generator_traits::value_to_yaml(msg.bounded_string_value, out);
    out << ", ";
  }

  // member: bounded_string_value_default1
  {
    out << "bounded_string_value_default1: ";
    rosidl_generator_traits::value_to_yaml(msg.bounded_string_value_default1, out);
    out << ", ";
  }

  // member: bounded_string_value_default2
  {
    out << "bounded_string_value_default2: ";
    rosidl_generator_traits::value_to_yaml(msg.bounded_string_value_default2, out);
    out << ", ";
  }

  // member: bounded_string_value_default3
  {
    out << "bounded_string_value_default3: ";
    rosidl_generator_traits::value_to_yaml(msg.bounded_string_value_default3, out);
    out << ", ";
  }

  // member: bounded_string_value_default4
  {
    out << "bounded_string_value_default4: ";
    rosidl_generator_traits::value_to_yaml(msg.bounded_string_value_default4, out);
    out << ", ";
  }

  // member: bounded_string_value_default5
  {
    out << "bounded_string_value_default5: ";
    rosidl_generator_traits::value_to_yaml(msg.bounded_string_value_default5, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Strings & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: string_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "string_value: ";
    rosidl_generator_traits::value_to_yaml(msg.string_value, out);
    out << "\n";
  }

  // member: string_value_default1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "string_value_default1: ";
    rosidl_generator_traits::value_to_yaml(msg.string_value_default1, out);
    out << "\n";
  }

  // member: string_value_default2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "string_value_default2: ";
    rosidl_generator_traits::value_to_yaml(msg.string_value_default2, out);
    out << "\n";
  }

  // member: string_value_default3
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "string_value_default3: ";
    rosidl_generator_traits::value_to_yaml(msg.string_value_default3, out);
    out << "\n";
  }

  // member: string_value_default4
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "string_value_default4: ";
    rosidl_generator_traits::value_to_yaml(msg.string_value_default4, out);
    out << "\n";
  }

  // member: string_value_default5
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "string_value_default5: ";
    rosidl_generator_traits::value_to_yaml(msg.string_value_default5, out);
    out << "\n";
  }

  // member: bounded_string_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bounded_string_value: ";
    rosidl_generator_traits::value_to_yaml(msg.bounded_string_value, out);
    out << "\n";
  }

  // member: bounded_string_value_default1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bounded_string_value_default1: ";
    rosidl_generator_traits::value_to_yaml(msg.bounded_string_value_default1, out);
    out << "\n";
  }

  // member: bounded_string_value_default2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bounded_string_value_default2: ";
    rosidl_generator_traits::value_to_yaml(msg.bounded_string_value_default2, out);
    out << "\n";
  }

  // member: bounded_string_value_default3
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bounded_string_value_default3: ";
    rosidl_generator_traits::value_to_yaml(msg.bounded_string_value_default3, out);
    out << "\n";
  }

  // member: bounded_string_value_default4
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bounded_string_value_default4: ";
    rosidl_generator_traits::value_to_yaml(msg.bounded_string_value_default4, out);
    out << "\n";
  }

  // member: bounded_string_value_default5
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bounded_string_value_default5: ";
    rosidl_generator_traits::value_to_yaml(msg.bounded_string_value_default5, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Strings & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, test_msgs::msg::Strings>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).string_value,
    std::forward<T>(msg).string_value_default1,
    std::forward<T>(msg).string_value_default2,
    std::forward<T>(msg).string_value_default3,
    std::forward<T>(msg).string_value_default4,
    std::forward<T>(msg).string_value_default5,
    std::forward<T>(msg).bounded_string_value,
    std::forward<T>(msg).bounded_string_value_default1,
    std::forward<T>(msg).bounded_string_value_default2,
    std::forward<T>(msg).bounded_string_value_default3,
    std::forward<T>(msg).bounded_string_value_default4,
    std::forward<T>(msg).bounded_string_value_default5);
}

}  // namespace msg

}  // namespace test_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<test_msgs::msg::Strings>()
{
  return "test_msgs::msg::Strings";
}

template<>
constexpr const char * name<test_msgs::msg::Strings>()
{
  return "test_msgs/msg/Strings";
}

template<>
struct has_fixed_size<test_msgs::msg::Strings>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<test_msgs::msg::Strings>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<test_msgs::msg::Strings>
  : std::true_type {};

template<>
struct MessageTraits<test_msgs::msg::Strings>
{
  static constexpr std::size_t member_count = 12;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "string_value",
    "string_value_default1",
    "string_value_default2",
    "string_value_default3",
    "string_value_default4",
    "string_value_default5",
    "bounded_string_value",
    "bounded_string_value_default1",
    "bounded_string_value_default2",
    "bounded_string_value_default3",
    "bounded_string_value_default4",
    "bounded_string_value_default5",
  };
};

}  // namespace rosidl_generator_traits

#endif  // TEST_MSGS__MSG__DETAIL__STRINGS__TRAITS_HPP_
