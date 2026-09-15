// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support_impl.hpp.em
// with input from test_msgs:msg\UnboundedSequences.idl
// generated code does not contain a copyright notice

#ifndef TEST_MSGS__MSG__DETAIL__UNBOUNDED_SEQUENCES__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_IMPL_HPP_
#define TEST_MSGS__MSG__DETAIL__UNBOUNDED_SEQUENCES__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_IMPL_HPP_

#include <cstddef>
#include <cstdio>
#include <limits>
#include <stdexcept>
#include <string>
#include <vector>
#include "rcutils/logging_macros.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/serialization_helpers.hpp"
#include "test_msgs/msg/detail/unbounded_sequences__rosidl_typesupport_fastrtps_cpp.hpp"
#include "fastcdr/Cdr.h"
#include "rosidl_typesupport_fastrtps_cpp/buffer_serialization.hpp"

// Include the inline (de)serialization headers of nested message types so
// their bodies are visible here and can be fully inlined by the compiler.
#include "test_msgs/msg/detail/basic_types__rosidl_typesupport_fastrtps_cpp_impl.hpp"
#include "test_msgs/msg/detail/constants__rosidl_typesupport_fastrtps_cpp_impl.hpp"
#include "test_msgs/msg/detail/defaults__rosidl_typesupport_fastrtps_cpp_impl.hpp"


namespace test_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

// Inline implementations of the (de)serialization family of functions.
// Kept separate from the public, exported wrappers (see the generated
// `..._type_support.cpp`) so that nested-message call sites elsewhere can
// `#include` this header and let the compiler fully inline the recursive
// (de)serialization logic instead of making an opaque cross-library call.
namespace detail
{


inline
bool
cdr_serialize(
  const test_msgs::msg::UnboundedSequences & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: bool_values
  {
    cdr << ros_message.bool_values;
  }

  // Member: byte_values
  {
    cdr << ros_message.byte_values;
  }

  // Member: char_values
  {
    if (ros_message.char_values.get_backend_type() == "cpu") {
      const std::vector<uint8_t> & vec = ros_message.char_values;
      cdr << vec;
    } else {
      std::vector<uint8_t> vec = ros_message.char_values.to_vector();
      cdr << vec;
    }
  }

  // Member: float32_values
  {
    cdr << ros_message.float32_values;
  }

  // Member: float64_values
  {
    cdr << ros_message.float64_values;
  }

  // Member: int8_values
  {
    cdr << ros_message.int8_values;
  }

  // Member: uint8_values
  {
    if (ros_message.uint8_values.get_backend_type() == "cpu") {
      const std::vector<uint8_t> & vec = ros_message.uint8_values;
      cdr << vec;
    } else {
      std::vector<uint8_t> vec = ros_message.uint8_values.to_vector();
      cdr << vec;
    }
  }

  // Member: int16_values
  {
    cdr << ros_message.int16_values;
  }

  // Member: uint16_values
  {
    cdr << ros_message.uint16_values;
  }

  // Member: int32_values
  {
    cdr << ros_message.int32_values;
  }

  // Member: uint32_values
  {
    cdr << ros_message.uint32_values;
  }

  // Member: int64_values
  {
    cdr << ros_message.int64_values;
  }

  // Member: uint64_values
  {
    cdr << ros_message.uint64_values;
  }

  // Member: string_values
  {
    cdr << ros_message.string_values;
  }

  // Member: basic_types_values
  {
    size_t size = ros_message.basic_types_values.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      test_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize(
        ros_message.basic_types_values[i],
        cdr);
    }
  }

  // Member: constants_values
  {
    size_t size = ros_message.constants_values.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      test_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize(
        ros_message.constants_values[i],
        cdr);
    }
  }

  // Member: defaults_values
  {
    size_t size = ros_message.defaults_values.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      test_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize(
        ros_message.defaults_values[i],
        cdr);
    }
  }

  // Member: bool_values_default
  {
    cdr << ros_message.bool_values_default;
  }

  // Member: byte_values_default
  {
    cdr << ros_message.byte_values_default;
  }

  // Member: char_values_default
  {
    if (ros_message.char_values_default.get_backend_type() == "cpu") {
      const std::vector<uint8_t> & vec = ros_message.char_values_default;
      cdr << vec;
    } else {
      std::vector<uint8_t> vec = ros_message.char_values_default.to_vector();
      cdr << vec;
    }
  }

  // Member: float32_values_default
  {
    cdr << ros_message.float32_values_default;
  }

  // Member: float64_values_default
  {
    cdr << ros_message.float64_values_default;
  }

  // Member: int8_values_default
  {
    cdr << ros_message.int8_values_default;
  }

  // Member: uint8_values_default
  {
    if (ros_message.uint8_values_default.get_backend_type() == "cpu") {
      const std::vector<uint8_t> & vec = ros_message.uint8_values_default;
      cdr << vec;
    } else {
      std::vector<uint8_t> vec = ros_message.uint8_values_default.to_vector();
      cdr << vec;
    }
  }

  // Member: int16_values_default
  {
    cdr << ros_message.int16_values_default;
  }

  // Member: uint16_values_default
  {
    cdr << ros_message.uint16_values_default;
  }

  // Member: int32_values_default
  {
    cdr << ros_message.int32_values_default;
  }

  // Member: uint32_values_default
  {
    cdr << ros_message.uint32_values_default;
  }

  // Member: int64_values_default
  {
    cdr << ros_message.int64_values_default;
  }

  // Member: uint64_values_default
  {
    cdr << ros_message.uint64_values_default;
  }

  // Member: string_values_default
  {
    cdr << ros_message.string_values_default;
  }

  // Member: alignment_check
  cdr << ros_message.alignment_check;

  return true;
}

inline
bool
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  test_msgs::msg::UnboundedSequences & ros_message)
{
  // Member: bool_values
  {
    cdr >> ros_message.bool_values;
  }

  // Member: byte_values
  {
    cdr >> ros_message.byte_values;
  }

  // Member: char_values
  {
    cdr >> ros_message.char_values;
  }

  // Member: float32_values
  {
    cdr >> ros_message.float32_values;
  }

  // Member: float64_values
  {
    cdr >> ros_message.float64_values;
  }

  // Member: int8_values
  {
    cdr >> ros_message.int8_values;
  }

  // Member: uint8_values
  {
    cdr >> ros_message.uint8_values;
  }

  // Member: int16_values
  {
    cdr >> ros_message.int16_values;
  }

  // Member: uint16_values
  {
    cdr >> ros_message.uint16_values;
  }

  // Member: int32_values
  {
    cdr >> ros_message.int32_values;
  }

  // Member: uint32_values
  {
    cdr >> ros_message.uint32_values;
  }

  // Member: int64_values
  {
    cdr >> ros_message.int64_values;
  }

  // Member: uint64_values
  {
    cdr >> ros_message.uint64_values;
  }

  // Member: string_values
  {
    cdr >> ros_message.string_values;
  }

  // Member: basic_types_values
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);

    // Check there are at least 'size' remaining bytes in the CDR stream before resizing
    auto old_state = cdr.get_state();
    bool correct_size = cdr.jump(size);
    cdr.set_state(old_state);
    if (!correct_size) {
      fprintf(stderr, "sequence size exceeds remaining buffer\n");
      return false;
    }

    ros_message.basic_types_values.resize(size);
    for (size_t i = 0; i < size; i++) {
      test_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize(
        cdr, ros_message.basic_types_values[i]);
    }
  }

  // Member: constants_values
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);

    // Check there are at least 'size' remaining bytes in the CDR stream before resizing
    auto old_state = cdr.get_state();
    bool correct_size = cdr.jump(size);
    cdr.set_state(old_state);
    if (!correct_size) {
      fprintf(stderr, "sequence size exceeds remaining buffer\n");
      return false;
    }

    ros_message.constants_values.resize(size);
    for (size_t i = 0; i < size; i++) {
      test_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize(
        cdr, ros_message.constants_values[i]);
    }
  }

  // Member: defaults_values
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);

    // Check there are at least 'size' remaining bytes in the CDR stream before resizing
    auto old_state = cdr.get_state();
    bool correct_size = cdr.jump(size);
    cdr.set_state(old_state);
    if (!correct_size) {
      fprintf(stderr, "sequence size exceeds remaining buffer\n");
      return false;
    }

    ros_message.defaults_values.resize(size);
    for (size_t i = 0; i < size; i++) {
      test_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize(
        cdr, ros_message.defaults_values[i]);
    }
  }

  // Member: bool_values_default
  {
    cdr >> ros_message.bool_values_default;
  }

  // Member: byte_values_default
  {
    cdr >> ros_message.byte_values_default;
  }

  // Member: char_values_default
  {
    cdr >> ros_message.char_values_default;
  }

  // Member: float32_values_default
  {
    cdr >> ros_message.float32_values_default;
  }

  // Member: float64_values_default
  {
    cdr >> ros_message.float64_values_default;
  }

  // Member: int8_values_default
  {
    cdr >> ros_message.int8_values_default;
  }

  // Member: uint8_values_default
  {
    cdr >> ros_message.uint8_values_default;
  }

  // Member: int16_values_default
  {
    cdr >> ros_message.int16_values_default;
  }

  // Member: uint16_values_default
  {
    cdr >> ros_message.uint16_values_default;
  }

  // Member: int32_values_default
  {
    cdr >> ros_message.int32_values_default;
  }

  // Member: uint32_values_default
  {
    cdr >> ros_message.uint32_values_default;
  }

  // Member: int64_values_default
  {
    cdr >> ros_message.int64_values_default;
  }

  // Member: uint64_values_default
  {
    cdr >> ros_message.uint64_values_default;
  }

  // Member: string_values_default
  {
    cdr >> ros_message.string_values_default;
  }

  // Member: alignment_check
  cdr >> ros_message.alignment_check;

  return true;
}  // NOLINT(readability/fn_size)

// Endpoint-aware serialization. Always emitted so parent messages can recurse
// through non-Buffer intermediate message types.
inline
bool
cdr_serialize_with_endpoint(
  const test_msgs::msg::UnboundedSequences & ros_message,
  eprosima::fastcdr::Cdr & cdr,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  try {
    // Member: bool_values
    {
      cdr << ros_message.bool_values;
    }
    // Member: byte_values
    {
      cdr << ros_message.byte_values;
    }
    // Member: char_values
    {
      rosidl_typesupport_fastrtps_cpp::serialize_buffer_with_endpoint(
        cdr, ros_message.char_values, endpoint_info, serialization_context);
    }
    // Member: float32_values
    {
      cdr << ros_message.float32_values;
    }
    // Member: float64_values
    {
      cdr << ros_message.float64_values;
    }
    // Member: int8_values
    {
      cdr << ros_message.int8_values;
    }
    // Member: uint8_values
    {
      rosidl_typesupport_fastrtps_cpp::serialize_buffer_with_endpoint(
        cdr, ros_message.uint8_values, endpoint_info, serialization_context);
    }
    // Member: int16_values
    {
      cdr << ros_message.int16_values;
    }
    // Member: uint16_values
    {
      cdr << ros_message.uint16_values;
    }
    // Member: int32_values
    {
      cdr << ros_message.int32_values;
    }
    // Member: uint32_values
    {
      cdr << ros_message.uint32_values;
    }
    // Member: int64_values
    {
      cdr << ros_message.int64_values;
    }
    // Member: uint64_values
    {
      cdr << ros_message.uint64_values;
    }
    // Member: string_values
    {
      cdr << ros_message.string_values;
    }
    // Member: basic_types_values
    {
      size_t size = ros_message.basic_types_values.size();
      cdr << static_cast<uint32_t>(size);
      for (size_t i = 0; i < size; i++) {
        test_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_with_endpoint(
          ros_message.basic_types_values[i],
          cdr, endpoint_info, serialization_context);
      }
    }
    // Member: constants_values
    {
      size_t size = ros_message.constants_values.size();
      cdr << static_cast<uint32_t>(size);
      for (size_t i = 0; i < size; i++) {
        test_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_with_endpoint(
          ros_message.constants_values[i],
          cdr, endpoint_info, serialization_context);
      }
    }
    // Member: defaults_values
    {
      size_t size = ros_message.defaults_values.size();
      cdr << static_cast<uint32_t>(size);
      for (size_t i = 0; i < size; i++) {
        test_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_with_endpoint(
          ros_message.defaults_values[i],
          cdr, endpoint_info, serialization_context);
      }
    }
    // Member: bool_values_default
    {
      cdr << ros_message.bool_values_default;
    }
    // Member: byte_values_default
    {
      cdr << ros_message.byte_values_default;
    }
    // Member: char_values_default
    {
      rosidl_typesupport_fastrtps_cpp::serialize_buffer_with_endpoint(
        cdr, ros_message.char_values_default, endpoint_info, serialization_context);
    }
    // Member: float32_values_default
    {
      cdr << ros_message.float32_values_default;
    }
    // Member: float64_values_default
    {
      cdr << ros_message.float64_values_default;
    }
    // Member: int8_values_default
    {
      cdr << ros_message.int8_values_default;
    }
    // Member: uint8_values_default
    {
      rosidl_typesupport_fastrtps_cpp::serialize_buffer_with_endpoint(
        cdr, ros_message.uint8_values_default, endpoint_info, serialization_context);
    }
    // Member: int16_values_default
    {
      cdr << ros_message.int16_values_default;
    }
    // Member: uint16_values_default
    {
      cdr << ros_message.uint16_values_default;
    }
    // Member: int32_values_default
    {
      cdr << ros_message.int32_values_default;
    }
    // Member: uint32_values_default
    {
      cdr << ros_message.uint32_values_default;
    }
    // Member: int64_values_default
    {
      cdr << ros_message.int64_values_default;
    }
    // Member: uint64_values_default
    {
      cdr << ros_message.uint64_values_default;
    }
    // Member: string_values_default
    {
      cdr << ros_message.string_values_default;
    }
    // Member: alignment_check
    cdr << ros_message.alignment_check;
  } catch (const std::exception & e) {
    RCUTILS_LOG_ERROR_NAMED(
      "test_msgs.typesupport_fastrtps_cpp",
      "cdr_serialize_with_endpoint failed: %s", e.what());
    return false;
  }
  return true;
}

// Endpoint-aware deserialization. Always emitted so parent messages can recurse
// through non-Buffer intermediate message types.
inline
bool
cdr_deserialize_with_endpoint(
  eprosima::fastcdr::Cdr & cdr,
  test_msgs::msg::UnboundedSequences & ros_message,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Member: bool_values
  {
    cdr >> ros_message.bool_values;
  }

  // Member: byte_values
  {
    cdr >> ros_message.byte_values;
  }

  // Member: char_values
  {
    if (!rosidl_typesupport_fastrtps_cpp::deserialize_buffer_with_endpoint(
        cdr, ros_message.char_values, endpoint_info, serialization_context))
    {
      RCUTILS_LOG_ERROR_NAMED(
        "test_msgs.typesupport_fastrtps_cpp",
        "cdr_deserialize_with_endpoint: failed to deserialize 'char_values'");
      return false;
    }
  }

  // Member: float32_values
  {
    cdr >> ros_message.float32_values;
  }

  // Member: float64_values
  {
    cdr >> ros_message.float64_values;
  }

  // Member: int8_values
  {
    cdr >> ros_message.int8_values;
  }

  // Member: uint8_values
  {
    if (!rosidl_typesupport_fastrtps_cpp::deserialize_buffer_with_endpoint(
        cdr, ros_message.uint8_values, endpoint_info, serialization_context))
    {
      RCUTILS_LOG_ERROR_NAMED(
        "test_msgs.typesupport_fastrtps_cpp",
        "cdr_deserialize_with_endpoint: failed to deserialize 'uint8_values'");
      return false;
    }
  }

  // Member: int16_values
  {
    cdr >> ros_message.int16_values;
  }

  // Member: uint16_values
  {
    cdr >> ros_message.uint16_values;
  }

  // Member: int32_values
  {
    cdr >> ros_message.int32_values;
  }

  // Member: uint32_values
  {
    cdr >> ros_message.uint32_values;
  }

  // Member: int64_values
  {
    cdr >> ros_message.int64_values;
  }

  // Member: uint64_values
  {
    cdr >> ros_message.uint64_values;
  }

  // Member: string_values
  {
    cdr >> ros_message.string_values;
  }

  // Member: basic_types_values
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);

    // Check there are at least 'size' remaining bytes in the CDR stream before resizing
    auto old_state = cdr.get_state();
    bool correct_size = cdr.jump(size);
    cdr.set_state(old_state);
    if (!correct_size) {
      fprintf(stderr, "sequence size exceeds remaining buffer\n");
      return false;
    }

    ros_message.basic_types_values.resize(size);
    for (size_t i = 0; i < size; i++) {
      test_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize_with_endpoint(
        cdr,
        ros_message.basic_types_values[i],
        endpoint_info,
        serialization_context);
    }
  }

  // Member: constants_values
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);

    // Check there are at least 'size' remaining bytes in the CDR stream before resizing
    auto old_state = cdr.get_state();
    bool correct_size = cdr.jump(size);
    cdr.set_state(old_state);
    if (!correct_size) {
      fprintf(stderr, "sequence size exceeds remaining buffer\n");
      return false;
    }

    ros_message.constants_values.resize(size);
    for (size_t i = 0; i < size; i++) {
      test_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize_with_endpoint(
        cdr,
        ros_message.constants_values[i],
        endpoint_info,
        serialization_context);
    }
  }

  // Member: defaults_values
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);

    // Check there are at least 'size' remaining bytes in the CDR stream before resizing
    auto old_state = cdr.get_state();
    bool correct_size = cdr.jump(size);
    cdr.set_state(old_state);
    if (!correct_size) {
      fprintf(stderr, "sequence size exceeds remaining buffer\n");
      return false;
    }

    ros_message.defaults_values.resize(size);
    for (size_t i = 0; i < size; i++) {
      test_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize_with_endpoint(
        cdr,
        ros_message.defaults_values[i],
        endpoint_info,
        serialization_context);
    }
  }

  // Member: bool_values_default
  {
    cdr >> ros_message.bool_values_default;
  }

  // Member: byte_values_default
  {
    cdr >> ros_message.byte_values_default;
  }

  // Member: char_values_default
  {
    if (!rosidl_typesupport_fastrtps_cpp::deserialize_buffer_with_endpoint(
        cdr, ros_message.char_values_default, endpoint_info, serialization_context))
    {
      RCUTILS_LOG_ERROR_NAMED(
        "test_msgs.typesupport_fastrtps_cpp",
        "cdr_deserialize_with_endpoint: failed to deserialize 'char_values_default'");
      return false;
    }
  }

  // Member: float32_values_default
  {
    cdr >> ros_message.float32_values_default;
  }

  // Member: float64_values_default
  {
    cdr >> ros_message.float64_values_default;
  }

  // Member: int8_values_default
  {
    cdr >> ros_message.int8_values_default;
  }

  // Member: uint8_values_default
  {
    if (!rosidl_typesupport_fastrtps_cpp::deserialize_buffer_with_endpoint(
        cdr, ros_message.uint8_values_default, endpoint_info, serialization_context))
    {
      RCUTILS_LOG_ERROR_NAMED(
        "test_msgs.typesupport_fastrtps_cpp",
        "cdr_deserialize_with_endpoint: failed to deserialize 'uint8_values_default'");
      return false;
    }
  }

  // Member: int16_values_default
  {
    cdr >> ros_message.int16_values_default;
  }

  // Member: uint16_values_default
  {
    cdr >> ros_message.uint16_values_default;
  }

  // Member: int32_values_default
  {
    cdr >> ros_message.int32_values_default;
  }

  // Member: uint32_values_default
  {
    cdr >> ros_message.uint32_values_default;
  }

  // Member: int64_values_default
  {
    cdr >> ros_message.int64_values_default;
  }

  // Member: uint64_values_default
  {
    cdr >> ros_message.uint64_values_default;
  }

  // Member: string_values_default
  {
    cdr >> ros_message.string_values_default;
  }

  // Member: alignment_check
  cdr >> ros_message.alignment_check;

  return true;
}  // NOLINT(readability/fn_size)

inline
size_t
get_serialized_size(
  const test_msgs::msg::UnboundedSequences & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: bool_values
  {
    size_t array_size = ros_message.bool_values.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.bool_values[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: byte_values
  {
    size_t array_size = ros_message.byte_values.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.byte_values[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: char_values
  current_alignment +=
    rosidl_typesupport_fastrtps_cpp::get_buffer_serialized_size(
    ros_message.char_values, current_alignment);

  // Member: float32_values
  {
    size_t array_size = ros_message.float32_values.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.float32_values[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: float64_values
  {
    size_t array_size = ros_message.float64_values.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.float64_values[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: int8_values
  {
    size_t array_size = ros_message.int8_values.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.int8_values[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: uint8_values
  current_alignment +=
    rosidl_typesupport_fastrtps_cpp::get_buffer_serialized_size(
    ros_message.uint8_values, current_alignment);

  // Member: int16_values
  {
    size_t array_size = ros_message.int16_values.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.int16_values[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: uint16_values
  {
    size_t array_size = ros_message.uint16_values.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.uint16_values[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: int32_values
  {
    size_t array_size = ros_message.int32_values.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.int32_values[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: uint32_values
  {
    size_t array_size = ros_message.uint32_values.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.uint32_values[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: int64_values
  {
    size_t array_size = ros_message.int64_values.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.int64_values[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: uint64_values
  {
    size_t array_size = ros_message.uint64_values.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.uint64_values[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: string_values
  {
    size_t array_size = ros_message.string_values.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        (ros_message.string_values[index].size() + 1);
    }
  }

  // Member: basic_types_values
  {
    size_t array_size = ros_message.basic_types_values.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        test_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size(
        ros_message.basic_types_values[index], current_alignment);
    }
  }

  // Member: constants_values
  {
    size_t array_size = ros_message.constants_values.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        test_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size(
        ros_message.constants_values[index], current_alignment);
    }
  }

  // Member: defaults_values
  {
    size_t array_size = ros_message.defaults_values.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        test_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size(
        ros_message.defaults_values[index], current_alignment);
    }
  }

  // Member: bool_values_default
  {
    size_t array_size = ros_message.bool_values_default.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.bool_values_default[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: byte_values_default
  {
    size_t array_size = ros_message.byte_values_default.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.byte_values_default[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: char_values_default
  current_alignment +=
    rosidl_typesupport_fastrtps_cpp::get_buffer_serialized_size(
    ros_message.char_values_default, current_alignment);

  // Member: float32_values_default
  {
    size_t array_size = ros_message.float32_values_default.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.float32_values_default[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: float64_values_default
  {
    size_t array_size = ros_message.float64_values_default.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.float64_values_default[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: int8_values_default
  {
    size_t array_size = ros_message.int8_values_default.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.int8_values_default[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: uint8_values_default
  current_alignment +=
    rosidl_typesupport_fastrtps_cpp::get_buffer_serialized_size(
    ros_message.uint8_values_default, current_alignment);

  // Member: int16_values_default
  {
    size_t array_size = ros_message.int16_values_default.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.int16_values_default[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: uint16_values_default
  {
    size_t array_size = ros_message.uint16_values_default.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.uint16_values_default[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: int32_values_default
  {
    size_t array_size = ros_message.int32_values_default.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.int32_values_default[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: uint32_values_default
  {
    size_t array_size = ros_message.uint32_values_default.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.uint32_values_default[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: int64_values_default
  {
    size_t array_size = ros_message.int64_values_default.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.int64_values_default[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: uint64_values_default
  {
    size_t array_size = ros_message.uint64_values_default.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.uint64_values_default[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: string_values_default
  {
    size_t array_size = ros_message.string_values_default.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        (ros_message.string_values_default[index].size() + 1);
    }
  }

  // Member: alignment_check
  {
    size_t item_size = sizeof(ros_message.alignment_check);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


inline
size_t
max_serialized_size_UnboundedSequences(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Member: bool_values
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: byte_values
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: char_values
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: float32_values
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: float64_values
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // Member: int8_values
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: uint8_values
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: int16_values
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // Member: uint16_values
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // Member: int32_values
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: uint32_values
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: int64_values
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // Member: uint64_values
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // Member: string_values
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // Member: basic_types_values
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        test_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_BasicTypes(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // Member: constants_values
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        test_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_Constants(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // Member: defaults_values
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        test_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_Defaults(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // Member: bool_values_default
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: byte_values_default
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: char_values_default
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: float32_values_default
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: float64_values_default
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // Member: int8_values_default
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: uint8_values_default
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: int16_values_default
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // Member: uint16_values_default
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // Member: int32_values_default
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: uint32_values_default
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: int64_values_default
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // Member: uint64_values_default
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // Member: string_values_default
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // Member: alignment_check
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = test_msgs::msg::UnboundedSequences;
    is_plain =
      (
      offsetof(DataType, alignment_check) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

inline
bool
cdr_serialize_key(
  const test_msgs::msg::UnboundedSequences & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: bool_values
  {
    cdr << ros_message.bool_values;
  }

  // Member: byte_values
  {
    cdr << ros_message.byte_values;
  }

  // Member: char_values
  {
    if (ros_message.char_values.get_backend_type() == "cpu") {
      const std::vector<uint8_t> & vec = ros_message.char_values;
      cdr << vec;
    } else {
      std::vector<uint8_t> vec = ros_message.char_values.to_vector();
      cdr << vec;
    }
  }

  // Member: float32_values
  {
    cdr << ros_message.float32_values;
  }

  // Member: float64_values
  {
    cdr << ros_message.float64_values;
  }

  // Member: int8_values
  {
    cdr << ros_message.int8_values;
  }

  // Member: uint8_values
  {
    if (ros_message.uint8_values.get_backend_type() == "cpu") {
      const std::vector<uint8_t> & vec = ros_message.uint8_values;
      cdr << vec;
    } else {
      std::vector<uint8_t> vec = ros_message.uint8_values.to_vector();
      cdr << vec;
    }
  }

  // Member: int16_values
  {
    cdr << ros_message.int16_values;
  }

  // Member: uint16_values
  {
    cdr << ros_message.uint16_values;
  }

  // Member: int32_values
  {
    cdr << ros_message.int32_values;
  }

  // Member: uint32_values
  {
    cdr << ros_message.uint32_values;
  }

  // Member: int64_values
  {
    cdr << ros_message.int64_values;
  }

  // Member: uint64_values
  {
    cdr << ros_message.uint64_values;
  }

  // Member: string_values
  {
    cdr << ros_message.string_values;
  }

  // Member: basic_types_values
  {
    size_t size = ros_message.basic_types_values.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      test_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_key(
        ros_message.basic_types_values[i],
        cdr);
    }
  }

  // Member: constants_values
  {
    size_t size = ros_message.constants_values.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      test_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_key(
        ros_message.constants_values[i],
        cdr);
    }
  }

  // Member: defaults_values
  {
    size_t size = ros_message.defaults_values.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      test_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_key(
        ros_message.defaults_values[i],
        cdr);
    }
  }

  // Member: bool_values_default
  {
    cdr << ros_message.bool_values_default;
  }

  // Member: byte_values_default
  {
    cdr << ros_message.byte_values_default;
  }

  // Member: char_values_default
  {
    if (ros_message.char_values_default.get_backend_type() == "cpu") {
      const std::vector<uint8_t> & vec = ros_message.char_values_default;
      cdr << vec;
    } else {
      std::vector<uint8_t> vec = ros_message.char_values_default.to_vector();
      cdr << vec;
    }
  }

  // Member: float32_values_default
  {
    cdr << ros_message.float32_values_default;
  }

  // Member: float64_values_default
  {
    cdr << ros_message.float64_values_default;
  }

  // Member: int8_values_default
  {
    cdr << ros_message.int8_values_default;
  }

  // Member: uint8_values_default
  {
    if (ros_message.uint8_values_default.get_backend_type() == "cpu") {
      const std::vector<uint8_t> & vec = ros_message.uint8_values_default;
      cdr << vec;
    } else {
      std::vector<uint8_t> vec = ros_message.uint8_values_default.to_vector();
      cdr << vec;
    }
  }

  // Member: int16_values_default
  {
    cdr << ros_message.int16_values_default;
  }

  // Member: uint16_values_default
  {
    cdr << ros_message.uint16_values_default;
  }

  // Member: int32_values_default
  {
    cdr << ros_message.int32_values_default;
  }

  // Member: uint32_values_default
  {
    cdr << ros_message.uint32_values_default;
  }

  // Member: int64_values_default
  {
    cdr << ros_message.int64_values_default;
  }

  // Member: uint64_values_default
  {
    cdr << ros_message.uint64_values_default;
  }

  // Member: string_values_default
  {
    cdr << ros_message.string_values_default;
  }

  // Member: alignment_check
  cdr << ros_message.alignment_check;

  return true;
}

inline
size_t
get_serialized_size_key(
  const test_msgs::msg::UnboundedSequences & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: bool_values
  {
    size_t array_size = ros_message.bool_values.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.bool_values[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: byte_values
  {
    size_t array_size = ros_message.byte_values.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.byte_values[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: char_values
  current_alignment +=
    rosidl_typesupport_fastrtps_cpp::get_buffer_serialized_size(
    ros_message.char_values, current_alignment);

  // Member: float32_values
  {
    size_t array_size = ros_message.float32_values.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.float32_values[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: float64_values
  {
    size_t array_size = ros_message.float64_values.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.float64_values[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: int8_values
  {
    size_t array_size = ros_message.int8_values.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.int8_values[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: uint8_values
  current_alignment +=
    rosidl_typesupport_fastrtps_cpp::get_buffer_serialized_size(
    ros_message.uint8_values, current_alignment);

  // Member: int16_values
  {
    size_t array_size = ros_message.int16_values.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.int16_values[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: uint16_values
  {
    size_t array_size = ros_message.uint16_values.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.uint16_values[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: int32_values
  {
    size_t array_size = ros_message.int32_values.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.int32_values[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: uint32_values
  {
    size_t array_size = ros_message.uint32_values.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.uint32_values[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: int64_values
  {
    size_t array_size = ros_message.int64_values.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.int64_values[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: uint64_values
  {
    size_t array_size = ros_message.uint64_values.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.uint64_values[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: string_values
  {
    size_t array_size = ros_message.string_values.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        (ros_message.string_values[index].size() + 1);
    }
  }

  // Member: basic_types_values
  {
    size_t array_size = ros_message.basic_types_values.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        test_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size_key(
        ros_message.basic_types_values[index], current_alignment);
    }
  }

  // Member: constants_values
  {
    size_t array_size = ros_message.constants_values.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        test_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size_key(
        ros_message.constants_values[index], current_alignment);
    }
  }

  // Member: defaults_values
  {
    size_t array_size = ros_message.defaults_values.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        test_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size_key(
        ros_message.defaults_values[index], current_alignment);
    }
  }

  // Member: bool_values_default
  {
    size_t array_size = ros_message.bool_values_default.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.bool_values_default[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: byte_values_default
  {
    size_t array_size = ros_message.byte_values_default.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.byte_values_default[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: char_values_default
  current_alignment +=
    rosidl_typesupport_fastrtps_cpp::get_buffer_serialized_size(
    ros_message.char_values_default, current_alignment);

  // Member: float32_values_default
  {
    size_t array_size = ros_message.float32_values_default.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.float32_values_default[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: float64_values_default
  {
    size_t array_size = ros_message.float64_values_default.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.float64_values_default[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: int8_values_default
  {
    size_t array_size = ros_message.int8_values_default.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.int8_values_default[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: uint8_values_default
  current_alignment +=
    rosidl_typesupport_fastrtps_cpp::get_buffer_serialized_size(
    ros_message.uint8_values_default, current_alignment);

  // Member: int16_values_default
  {
    size_t array_size = ros_message.int16_values_default.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.int16_values_default[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: uint16_values_default
  {
    size_t array_size = ros_message.uint16_values_default.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.uint16_values_default[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: int32_values_default
  {
    size_t array_size = ros_message.int32_values_default.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.int32_values_default[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: uint32_values_default
  {
    size_t array_size = ros_message.uint32_values_default.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.uint32_values_default[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: int64_values_default
  {
    size_t array_size = ros_message.int64_values_default.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.int64_values_default[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: uint64_values_default
  {
    size_t array_size = ros_message.uint64_values_default.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.uint64_values_default[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: string_values_default
  {
    size_t array_size = ros_message.string_values_default.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        (ros_message.string_values_default[index].size() + 1);
    }
  }

  // Member: alignment_check
  {
    size_t item_size = sizeof(ros_message.alignment_check);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

inline
size_t
max_serialized_size_key_UnboundedSequences(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Member: bool_values
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: byte_values
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: char_values
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: float32_values
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: float64_values
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: int8_values
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: uint8_values
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: int16_values
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: uint16_values
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: int32_values
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: uint32_values
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: int64_values
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: uint64_values
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: string_values
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: basic_types_values
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        test_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_key_BasicTypes(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: constants_values
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        test_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_key_Constants(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: defaults_values
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        test_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_key_Defaults(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: bool_values_default
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: byte_values_default
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: char_values_default
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: float32_values_default
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: float64_values_default
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: int8_values_default
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: uint8_values_default
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: int16_values_default
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: uint16_values_default
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: int32_values_default
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: uint32_values_default
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: int64_values_default
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: uint64_values_default
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: string_values_default
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: alignment_check
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = test_msgs::msg::UnboundedSequences;
    is_plain =
      (
      offsetof(DataType, alignment_check) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

}  // namespace detail

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace test_msgs

#endif  // TEST_MSGS__MSG__DETAIL__UNBOUNDED_SEQUENCES__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_IMPL_HPP_
