// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from test_msgs:msg\WStrings.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "test_msgs/msg/w_strings.hpp"


#ifndef TEST_MSGS__MSG__DETAIL__W_STRINGS__TRAITS_HPP_
#define TEST_MSGS__MSG__DETAIL__W_STRINGS__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "test_msgs/msg/detail/w_strings__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace test_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const WStrings & msg,
  std::ostream & out)
{
  out << "{";
  // member: wstring_value
  {
    out << "wstring_value: ";
    rosidl_generator_traits::value_to_yaml(msg.wstring_value, out);
    out << ", ";
  }

  // member: wstring_value_default1
  {
    out << "wstring_value_default1: ";
    rosidl_generator_traits::value_to_yaml(msg.wstring_value_default1, out);
    out << ", ";
  }

  // member: wstring_value_default2
  {
    out << "wstring_value_default2: ";
    rosidl_generator_traits::value_to_yaml(msg.wstring_value_default2, out);
    out << ", ";
  }

  // member: wstring_value_default3
  {
    out << "wstring_value_default3: ";
    rosidl_generator_traits::value_to_yaml(msg.wstring_value_default3, out);
    out << ", ";
  }

  // member: array_of_wstrings
  {
    if (msg.array_of_wstrings.size() == 0) {
      out << "array_of_wstrings: []";
    } else {
      out << "array_of_wstrings: [";
      size_t pending_items = msg.array_of_wstrings.size();
      for (auto item : msg.array_of_wstrings) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: bounded_sequence_of_wstrings
  {
    if (msg.bounded_sequence_of_wstrings.size() == 0) {
      out << "bounded_sequence_of_wstrings: []";
    } else {
      out << "bounded_sequence_of_wstrings: [";
      size_t pending_items = msg.bounded_sequence_of_wstrings.size();
      for (auto item : msg.bounded_sequence_of_wstrings) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: unbounded_sequence_of_wstrings
  {
    if (msg.unbounded_sequence_of_wstrings.size() == 0) {
      out << "unbounded_sequence_of_wstrings: []";
    } else {
      out << "unbounded_sequence_of_wstrings: [";
      size_t pending_items = msg.unbounded_sequence_of_wstrings.size();
      for (auto item : msg.unbounded_sequence_of_wstrings) {
        rosidl_generator_traits::value_to_yaml(item, out);
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
  const WStrings & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: wstring_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "wstring_value: ";
    rosidl_generator_traits::value_to_yaml(msg.wstring_value, out);
    out << "\n";
  }

  // member: wstring_value_default1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "wstring_value_default1: ";
    rosidl_generator_traits::value_to_yaml(msg.wstring_value_default1, out);
    out << "\n";
  }

  // member: wstring_value_default2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "wstring_value_default2: ";
    rosidl_generator_traits::value_to_yaml(msg.wstring_value_default2, out);
    out << "\n";
  }

  // member: wstring_value_default3
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "wstring_value_default3: ";
    rosidl_generator_traits::value_to_yaml(msg.wstring_value_default3, out);
    out << "\n";
  }

  // member: array_of_wstrings
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.array_of_wstrings.size() == 0) {
      out << "array_of_wstrings: []\n";
    } else {
      out << "array_of_wstrings:\n";
      for (auto item : msg.array_of_wstrings) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: bounded_sequence_of_wstrings
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.bounded_sequence_of_wstrings.size() == 0) {
      out << "bounded_sequence_of_wstrings: []\n";
    } else {
      out << "bounded_sequence_of_wstrings:\n";
      for (auto item : msg.bounded_sequence_of_wstrings) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: unbounded_sequence_of_wstrings
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.unbounded_sequence_of_wstrings.size() == 0) {
      out << "unbounded_sequence_of_wstrings: []\n";
    } else {
      out << "unbounded_sequence_of_wstrings:\n";
      for (auto item : msg.unbounded_sequence_of_wstrings) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const WStrings & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, test_msgs::msg::WStrings>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).wstring_value,
    std::forward<T>(msg).wstring_value_default1,
    std::forward<T>(msg).wstring_value_default2,
    std::forward<T>(msg).wstring_value_default3,
    std::forward<T>(msg).array_of_wstrings,
    std::forward<T>(msg).bounded_sequence_of_wstrings,
    std::forward<T>(msg).unbounded_sequence_of_wstrings);
}

}  // namespace msg

}  // namespace test_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<test_msgs::msg::WStrings>()
{
  return "test_msgs::msg::WStrings";
}

template<>
constexpr const char * name<test_msgs::msg::WStrings>()
{
  return "test_msgs/msg/WStrings";
}

template<>
struct has_fixed_size<test_msgs::msg::WStrings>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<test_msgs::msg::WStrings>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<test_msgs::msg::WStrings>
  : std::true_type {};

template<>
struct MessageTraits<test_msgs::msg::WStrings>
{
  static constexpr std::size_t member_count = 7;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "wstring_value",
    "wstring_value_default1",
    "wstring_value_default2",
    "wstring_value_default3",
    "array_of_wstrings",
    "bounded_sequence_of_wstrings",
    "unbounded_sequence_of_wstrings",
  };
};

}  // namespace rosidl_generator_traits

#endif  // TEST_MSGS__MSG__DETAIL__W_STRINGS__TRAITS_HPP_
