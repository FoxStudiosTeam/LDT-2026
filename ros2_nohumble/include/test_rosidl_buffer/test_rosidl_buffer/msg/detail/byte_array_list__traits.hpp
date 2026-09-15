// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from test_rosidl_buffer:msg\ByteArrayList.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "test_rosidl_buffer/msg/byte_array_list.hpp"


#ifndef TEST_ROSIDL_BUFFER__MSG__DETAIL__BYTE_ARRAY_LIST__TRAITS_HPP_
#define TEST_ROSIDL_BUFFER__MSG__DETAIL__BYTE_ARRAY_LIST__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "test_rosidl_buffer/msg/detail/byte_array_list__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'items'
#include "test_rosidl_buffer/msg/detail/byte_array__traits.hpp"

namespace test_rosidl_buffer
{

namespace msg
{

inline void to_flow_style_yaml(
  const ByteArrayList & msg,
  std::ostream & out)
{
  out << "{";
  // member: items
  {
    if (msg.items.size() == 0) {
      out << "items: []";
    } else {
      out << "items: [";
      size_t pending_items = msg.items.size();
      for (auto item : msg.items) {
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
  const ByteArrayList & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: items
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.items.size() == 0) {
      out << "items: []\n";
    } else {
      out << "items:\n";
      for (auto item : msg.items) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ByteArrayList & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, test_rosidl_buffer::msg::ByteArrayList>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(std::forward<T>(msg).items);
}

}  // namespace msg

}  // namespace test_rosidl_buffer

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<test_rosidl_buffer::msg::ByteArrayList>()
{
  return "test_rosidl_buffer::msg::ByteArrayList";
}

template<>
constexpr const char * name<test_rosidl_buffer::msg::ByteArrayList>()
{
  return "test_rosidl_buffer/msg/ByteArrayList";
}

template<>
struct has_fixed_size<test_rosidl_buffer::msg::ByteArrayList>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<test_rosidl_buffer::msg::ByteArrayList>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<test_rosidl_buffer::msg::ByteArrayList>
  : std::true_type {};

template<>
struct MessageTraits<test_rosidl_buffer::msg::ByteArrayList>
{
  static constexpr std::size_t member_count = 1;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "items",
  };
};

}  // namespace rosidl_generator_traits

#endif  // TEST_ROSIDL_BUFFER__MSG__DETAIL__BYTE_ARRAY_LIST__TRAITS_HPP_
