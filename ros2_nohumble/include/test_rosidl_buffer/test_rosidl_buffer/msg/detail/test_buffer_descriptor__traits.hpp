// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from test_rosidl_buffer:msg\TestBufferDescriptor.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "test_rosidl_buffer/msg/test_buffer_descriptor.hpp"


#ifndef TEST_ROSIDL_BUFFER__MSG__DETAIL__TEST_BUFFER_DESCRIPTOR__TRAITS_HPP_
#define TEST_ROSIDL_BUFFER__MSG__DETAIL__TEST_BUFFER_DESCRIPTOR__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "test_rosidl_buffer/msg/detail/test_buffer_descriptor__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace test_rosidl_buffer
{

namespace msg
{

inline void to_flow_style_yaml(
  const TestBufferDescriptor & msg,
  std::ostream & out)
{
  out << "{";
  // member: size
  {
    out << "size: ";
    rosidl_generator_traits::value_to_yaml(msg.size, out);
    out << ", ";
  }

  // member: data_hash
  {
    out << "data_hash: ";
    rosidl_generator_traits::value_to_yaml(msg.data_hash, out);
    out << ", ";
  }

  // member: data
  {
    if (msg.data.size() == 0) {
      out << "data: []";
    } else {
      out << "data: [";
      size_t pending_items = msg.data.size();
      for (auto item : msg.data) {
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
  const TestBufferDescriptor & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: size
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "size: ";
    rosidl_generator_traits::value_to_yaml(msg.size, out);
    out << "\n";
  }

  // member: data_hash
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "data_hash: ";
    rosidl_generator_traits::value_to_yaml(msg.data_hash, out);
    out << "\n";
  }

  // member: data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.data.size() == 0) {
      out << "data: []\n";
    } else {
      out << "data:\n";
      for (auto item : msg.data) {
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

inline std::string to_yaml(const TestBufferDescriptor & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, test_rosidl_buffer::msg::TestBufferDescriptor>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).size,
    std::forward<T>(msg).data_hash,
    std::forward<T>(msg).data);
}

}  // namespace msg

}  // namespace test_rosidl_buffer

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<test_rosidl_buffer::msg::TestBufferDescriptor>()
{
  return "test_rosidl_buffer::msg::TestBufferDescriptor";
}

template<>
constexpr const char * name<test_rosidl_buffer::msg::TestBufferDescriptor>()
{
  return "test_rosidl_buffer/msg/TestBufferDescriptor";
}

template<>
struct has_fixed_size<test_rosidl_buffer::msg::TestBufferDescriptor>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<test_rosidl_buffer::msg::TestBufferDescriptor>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<test_rosidl_buffer::msg::TestBufferDescriptor>
  : std::true_type {};

template<>
struct MessageTraits<test_rosidl_buffer::msg::TestBufferDescriptor>
{
  static constexpr std::size_t member_count = 3;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "size",
    "data_hash",
    "data",
  };
};

}  // namespace rosidl_generator_traits

#endif  // TEST_ROSIDL_BUFFER__MSG__DETAIL__TEST_BUFFER_DESCRIPTOR__TRAITS_HPP_
