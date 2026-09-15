// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support_impl.hpp.em
// with input from test_msgs:msg\MultiNested.idl
// generated code does not contain a copyright notice

#ifndef TEST_MSGS__MSG__DETAIL__MULTI_NESTED__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_IMPL_HPP_
#define TEST_MSGS__MSG__DETAIL__MULTI_NESTED__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_IMPL_HPP_

#include <cstddef>
#include <cstdio>
#include <limits>
#include <stdexcept>
#include <string>
#include <vector>
#include "rcutils/logging_macros.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/serialization_helpers.hpp"
#include "test_msgs/msg/detail/multi_nested__rosidl_typesupport_fastrtps_cpp.hpp"
#include "fastcdr/Cdr.h"

// Include the inline (de)serialization headers of nested message types so
// their bodies are visible here and can be fully inlined by the compiler.
#include "test_msgs/msg/detail/arrays__rosidl_typesupport_fastrtps_cpp_impl.hpp"
#include "test_msgs/msg/detail/bounded_sequences__rosidl_typesupport_fastrtps_cpp_impl.hpp"
#include "test_msgs/msg/detail/unbounded_sequences__rosidl_typesupport_fastrtps_cpp_impl.hpp"
// already included above
// #include "test_msgs/msg/detail/arrays__rosidl_typesupport_fastrtps_cpp_impl.hpp"
// already included above
// #include "test_msgs/msg/detail/bounded_sequences__rosidl_typesupport_fastrtps_cpp_impl.hpp"
// already included above
// #include "test_msgs/msg/detail/unbounded_sequences__rosidl_typesupport_fastrtps_cpp_impl.hpp"
// already included above
// #include "test_msgs/msg/detail/arrays__rosidl_typesupport_fastrtps_cpp_impl.hpp"
// already included above
// #include "test_msgs/msg/detail/bounded_sequences__rosidl_typesupport_fastrtps_cpp_impl.hpp"
// already included above
// #include "test_msgs/msg/detail/unbounded_sequences__rosidl_typesupport_fastrtps_cpp_impl.hpp"


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
  const test_msgs::msg::MultiNested & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: array_of_arrays
  {
    for (size_t i = 0; i < 3; i++) {
      test_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize(
        ros_message.array_of_arrays[i],
        cdr);
    }
  }

  // Member: array_of_bounded_sequences
  {
    for (size_t i = 0; i < 3; i++) {
      test_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize(
        ros_message.array_of_bounded_sequences[i],
        cdr);
    }
  }

  // Member: array_of_unbounded_sequences
  {
    for (size_t i = 0; i < 3; i++) {
      test_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize(
        ros_message.array_of_unbounded_sequences[i],
        cdr);
    }
  }

  // Member: bounded_sequence_of_arrays
  {
    size_t size = ros_message.bounded_sequence_of_arrays.size();
    if (size > 3) {
      throw std::runtime_error("array size exceeds upper bound");
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      test_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize(
        ros_message.bounded_sequence_of_arrays[i],
        cdr);
    }
  }

  // Member: bounded_sequence_of_bounded_sequences
  {
    size_t size = ros_message.bounded_sequence_of_bounded_sequences.size();
    if (size > 3) {
      throw std::runtime_error("array size exceeds upper bound");
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      test_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize(
        ros_message.bounded_sequence_of_bounded_sequences[i],
        cdr);
    }
  }

  // Member: bounded_sequence_of_unbounded_sequences
  {
    size_t size = ros_message.bounded_sequence_of_unbounded_sequences.size();
    if (size > 3) {
      throw std::runtime_error("array size exceeds upper bound");
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      test_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize(
        ros_message.bounded_sequence_of_unbounded_sequences[i],
        cdr);
    }
  }

  // Member: unbounded_sequence_of_arrays
  {
    size_t size = ros_message.unbounded_sequence_of_arrays.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      test_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize(
        ros_message.unbounded_sequence_of_arrays[i],
        cdr);
    }
  }

  // Member: unbounded_sequence_of_bounded_sequences
  {
    size_t size = ros_message.unbounded_sequence_of_bounded_sequences.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      test_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize(
        ros_message.unbounded_sequence_of_bounded_sequences[i],
        cdr);
    }
  }

  // Member: unbounded_sequence_of_unbounded_sequences
  {
    size_t size = ros_message.unbounded_sequence_of_unbounded_sequences.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      test_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize(
        ros_message.unbounded_sequence_of_unbounded_sequences[i],
        cdr);
    }
  }

  return true;
}

inline
bool
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  test_msgs::msg::MultiNested & ros_message)
{
  // Member: array_of_arrays
  {
    for (size_t i = 0; i < 3; i++) {
      test_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize(
        cdr,
        ros_message.array_of_arrays[i]);
    }
  }

  // Member: array_of_bounded_sequences
  {
    for (size_t i = 0; i < 3; i++) {
      test_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize(
        cdr,
        ros_message.array_of_bounded_sequences[i]);
    }
  }

  // Member: array_of_unbounded_sequences
  {
    for (size_t i = 0; i < 3; i++) {
      test_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize(
        cdr,
        ros_message.array_of_unbounded_sequences[i]);
    }
  }

  // Member: bounded_sequence_of_arrays
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

    ros_message.bounded_sequence_of_arrays.resize(size);
    for (size_t i = 0; i < size; i++) {
      test_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize(
        cdr, ros_message.bounded_sequence_of_arrays[i]);
    }
  }

  // Member: bounded_sequence_of_bounded_sequences
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

    ros_message.bounded_sequence_of_bounded_sequences.resize(size);
    for (size_t i = 0; i < size; i++) {
      test_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize(
        cdr, ros_message.bounded_sequence_of_bounded_sequences[i]);
    }
  }

  // Member: bounded_sequence_of_unbounded_sequences
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

    ros_message.bounded_sequence_of_unbounded_sequences.resize(size);
    for (size_t i = 0; i < size; i++) {
      test_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize(
        cdr, ros_message.bounded_sequence_of_unbounded_sequences[i]);
    }
  }

  // Member: unbounded_sequence_of_arrays
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

    ros_message.unbounded_sequence_of_arrays.resize(size);
    for (size_t i = 0; i < size; i++) {
      test_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize(
        cdr, ros_message.unbounded_sequence_of_arrays[i]);
    }
  }

  // Member: unbounded_sequence_of_bounded_sequences
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

    ros_message.unbounded_sequence_of_bounded_sequences.resize(size);
    for (size_t i = 0; i < size; i++) {
      test_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize(
        cdr, ros_message.unbounded_sequence_of_bounded_sequences[i]);
    }
  }

  // Member: unbounded_sequence_of_unbounded_sequences
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

    ros_message.unbounded_sequence_of_unbounded_sequences.resize(size);
    for (size_t i = 0; i < size; i++) {
      test_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize(
        cdr, ros_message.unbounded_sequence_of_unbounded_sequences[i]);
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

// Endpoint-aware serialization. Always emitted so parent messages can recurse
// through non-Buffer intermediate message types.
inline
bool
cdr_serialize_with_endpoint(
  const test_msgs::msg::MultiNested & ros_message,
  eprosima::fastcdr::Cdr & cdr,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  try {
    // Member: array_of_arrays
    {
      for (size_t i = 0; i < 3; i++) {
        test_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_with_endpoint(
          ros_message.array_of_arrays[i],
          cdr, endpoint_info, serialization_context);
      }
    }
    // Member: array_of_bounded_sequences
    {
      for (size_t i = 0; i < 3; i++) {
        test_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_with_endpoint(
          ros_message.array_of_bounded_sequences[i],
          cdr, endpoint_info, serialization_context);
      }
    }
    // Member: array_of_unbounded_sequences
    {
      for (size_t i = 0; i < 3; i++) {
        test_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_with_endpoint(
          ros_message.array_of_unbounded_sequences[i],
          cdr, endpoint_info, serialization_context);
      }
    }
    // Member: bounded_sequence_of_arrays
    {
      size_t size = ros_message.bounded_sequence_of_arrays.size();
      if (size > 3) {
        throw std::runtime_error("array size exceeds upper bound");
      }
      cdr << static_cast<uint32_t>(size);
      for (size_t i = 0; i < size; i++) {
        test_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_with_endpoint(
          ros_message.bounded_sequence_of_arrays[i],
          cdr, endpoint_info, serialization_context);
      }
    }
    // Member: bounded_sequence_of_bounded_sequences
    {
      size_t size = ros_message.bounded_sequence_of_bounded_sequences.size();
      if (size > 3) {
        throw std::runtime_error("array size exceeds upper bound");
      }
      cdr << static_cast<uint32_t>(size);
      for (size_t i = 0; i < size; i++) {
        test_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_with_endpoint(
          ros_message.bounded_sequence_of_bounded_sequences[i],
          cdr, endpoint_info, serialization_context);
      }
    }
    // Member: bounded_sequence_of_unbounded_sequences
    {
      size_t size = ros_message.bounded_sequence_of_unbounded_sequences.size();
      if (size > 3) {
        throw std::runtime_error("array size exceeds upper bound");
      }
      cdr << static_cast<uint32_t>(size);
      for (size_t i = 0; i < size; i++) {
        test_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_with_endpoint(
          ros_message.bounded_sequence_of_unbounded_sequences[i],
          cdr, endpoint_info, serialization_context);
      }
    }
    // Member: unbounded_sequence_of_arrays
    {
      size_t size = ros_message.unbounded_sequence_of_arrays.size();
      cdr << static_cast<uint32_t>(size);
      for (size_t i = 0; i < size; i++) {
        test_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_with_endpoint(
          ros_message.unbounded_sequence_of_arrays[i],
          cdr, endpoint_info, serialization_context);
      }
    }
    // Member: unbounded_sequence_of_bounded_sequences
    {
      size_t size = ros_message.unbounded_sequence_of_bounded_sequences.size();
      cdr << static_cast<uint32_t>(size);
      for (size_t i = 0; i < size; i++) {
        test_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_with_endpoint(
          ros_message.unbounded_sequence_of_bounded_sequences[i],
          cdr, endpoint_info, serialization_context);
      }
    }
    // Member: unbounded_sequence_of_unbounded_sequences
    {
      size_t size = ros_message.unbounded_sequence_of_unbounded_sequences.size();
      cdr << static_cast<uint32_t>(size);
      for (size_t i = 0; i < size; i++) {
        test_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_with_endpoint(
          ros_message.unbounded_sequence_of_unbounded_sequences[i],
          cdr, endpoint_info, serialization_context);
      }
    }
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
  test_msgs::msg::MultiNested & ros_message,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Member: array_of_arrays
  {
    for (size_t i = 0; i < 3; i++) {
      test_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize_with_endpoint(
        cdr,
        ros_message.array_of_arrays[i],
        endpoint_info,
        serialization_context);
    }
  }

  // Member: array_of_bounded_sequences
  {
    for (size_t i = 0; i < 3; i++) {
      test_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize_with_endpoint(
        cdr,
        ros_message.array_of_bounded_sequences[i],
        endpoint_info,
        serialization_context);
    }
  }

  // Member: array_of_unbounded_sequences
  {
    for (size_t i = 0; i < 3; i++) {
      test_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize_with_endpoint(
        cdr,
        ros_message.array_of_unbounded_sequences[i],
        endpoint_info,
        serialization_context);
    }
  }

  // Member: bounded_sequence_of_arrays
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

    ros_message.bounded_sequence_of_arrays.resize(size);
    if (size > 3) {
      throw std::runtime_error("vector size exceeds upper bound");
    }
    for (size_t i = 0; i < size; i++) {
      test_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize_with_endpoint(
        cdr,
        ros_message.bounded_sequence_of_arrays[i],
        endpoint_info,
        serialization_context);
    }
  }

  // Member: bounded_sequence_of_bounded_sequences
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

    ros_message.bounded_sequence_of_bounded_sequences.resize(size);
    if (size > 3) {
      throw std::runtime_error("vector size exceeds upper bound");
    }
    for (size_t i = 0; i < size; i++) {
      test_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize_with_endpoint(
        cdr,
        ros_message.bounded_sequence_of_bounded_sequences[i],
        endpoint_info,
        serialization_context);
    }
  }

  // Member: bounded_sequence_of_unbounded_sequences
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

    ros_message.bounded_sequence_of_unbounded_sequences.resize(size);
    if (size > 3) {
      throw std::runtime_error("vector size exceeds upper bound");
    }
    for (size_t i = 0; i < size; i++) {
      test_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize_with_endpoint(
        cdr,
        ros_message.bounded_sequence_of_unbounded_sequences[i],
        endpoint_info,
        serialization_context);
    }
  }

  // Member: unbounded_sequence_of_arrays
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

    ros_message.unbounded_sequence_of_arrays.resize(size);
    for (size_t i = 0; i < size; i++) {
      test_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize_with_endpoint(
        cdr,
        ros_message.unbounded_sequence_of_arrays[i],
        endpoint_info,
        serialization_context);
    }
  }

  // Member: unbounded_sequence_of_bounded_sequences
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

    ros_message.unbounded_sequence_of_bounded_sequences.resize(size);
    for (size_t i = 0; i < size; i++) {
      test_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize_with_endpoint(
        cdr,
        ros_message.unbounded_sequence_of_bounded_sequences[i],
        endpoint_info,
        serialization_context);
    }
  }

  // Member: unbounded_sequence_of_unbounded_sequences
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

    ros_message.unbounded_sequence_of_unbounded_sequences.resize(size);
    for (size_t i = 0; i < size; i++) {
      test_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize_with_endpoint(
        cdr,
        ros_message.unbounded_sequence_of_unbounded_sequences[i],
        endpoint_info,
        serialization_context);
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

inline
size_t
get_serialized_size(
  const test_msgs::msg::MultiNested & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: array_of_arrays
  {
    size_t array_size = 3;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        test_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size(
        ros_message.array_of_arrays[index], current_alignment);
    }
  }

  // Member: array_of_bounded_sequences
  {
    size_t array_size = 3;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        test_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size(
        ros_message.array_of_bounded_sequences[index], current_alignment);
    }
  }

  // Member: array_of_unbounded_sequences
  {
    size_t array_size = 3;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        test_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size(
        ros_message.array_of_unbounded_sequences[index], current_alignment);
    }
  }

  // Member: bounded_sequence_of_arrays
  {
    size_t array_size = ros_message.bounded_sequence_of_arrays.size();
    if (array_size > 3) {
      throw std::runtime_error("array size exceeds upper bound");
    }
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        test_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size(
        ros_message.bounded_sequence_of_arrays[index], current_alignment);
    }
  }

  // Member: bounded_sequence_of_bounded_sequences
  {
    size_t array_size = ros_message.bounded_sequence_of_bounded_sequences.size();
    if (array_size > 3) {
      throw std::runtime_error("array size exceeds upper bound");
    }
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        test_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size(
        ros_message.bounded_sequence_of_bounded_sequences[index], current_alignment);
    }
  }

  // Member: bounded_sequence_of_unbounded_sequences
  {
    size_t array_size = ros_message.bounded_sequence_of_unbounded_sequences.size();
    if (array_size > 3) {
      throw std::runtime_error("array size exceeds upper bound");
    }
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        test_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size(
        ros_message.bounded_sequence_of_unbounded_sequences[index], current_alignment);
    }
  }

  // Member: unbounded_sequence_of_arrays
  {
    size_t array_size = ros_message.unbounded_sequence_of_arrays.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        test_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size(
        ros_message.unbounded_sequence_of_arrays[index], current_alignment);
    }
  }

  // Member: unbounded_sequence_of_bounded_sequences
  {
    size_t array_size = ros_message.unbounded_sequence_of_bounded_sequences.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        test_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size(
        ros_message.unbounded_sequence_of_bounded_sequences[index], current_alignment);
    }
  }

  // Member: unbounded_sequence_of_unbounded_sequences
  {
    size_t array_size = ros_message.unbounded_sequence_of_unbounded_sequences.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        test_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size(
        ros_message.unbounded_sequence_of_unbounded_sequences[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}


inline
size_t
max_serialized_size_MultiNested(
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

  // Member: array_of_arrays
  {
    size_t array_size = 3;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        test_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_Arrays(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // Member: array_of_bounded_sequences
  {
    size_t array_size = 3;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        test_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_BoundedSequences(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // Member: array_of_unbounded_sequences
  {
    size_t array_size = 3;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        test_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_UnboundedSequences(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // Member: bounded_sequence_of_arrays
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        test_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_Arrays(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // Member: bounded_sequence_of_bounded_sequences
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        test_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_BoundedSequences(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // Member: bounded_sequence_of_unbounded_sequences
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        test_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_UnboundedSequences(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // Member: unbounded_sequence_of_arrays
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
        test_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_Arrays(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // Member: unbounded_sequence_of_bounded_sequences
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
        test_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_BoundedSequences(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // Member: unbounded_sequence_of_unbounded_sequences
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
        test_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_UnboundedSequences(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = test_msgs::msg::MultiNested;
    is_plain =
      (
      offsetof(DataType, unbounded_sequence_of_unbounded_sequences) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

inline
bool
cdr_serialize_key(
  const test_msgs::msg::MultiNested & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: array_of_arrays
  {
    for (size_t i = 0; i < 3; i++) {
      test_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_key(
        ros_message.array_of_arrays[i],
        cdr);
    }
  }

  // Member: array_of_bounded_sequences
  {
    for (size_t i = 0; i < 3; i++) {
      test_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_key(
        ros_message.array_of_bounded_sequences[i],
        cdr);
    }
  }

  // Member: array_of_unbounded_sequences
  {
    for (size_t i = 0; i < 3; i++) {
      test_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_key(
        ros_message.array_of_unbounded_sequences[i],
        cdr);
    }
  }

  // Member: bounded_sequence_of_arrays
  {
    size_t size = ros_message.bounded_sequence_of_arrays.size();
    if (size > 3) {
      throw std::runtime_error("array size exceeds upper bound");
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      test_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_key(
        ros_message.bounded_sequence_of_arrays[i],
        cdr);
    }
  }

  // Member: bounded_sequence_of_bounded_sequences
  {
    size_t size = ros_message.bounded_sequence_of_bounded_sequences.size();
    if (size > 3) {
      throw std::runtime_error("array size exceeds upper bound");
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      test_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_key(
        ros_message.bounded_sequence_of_bounded_sequences[i],
        cdr);
    }
  }

  // Member: bounded_sequence_of_unbounded_sequences
  {
    size_t size = ros_message.bounded_sequence_of_unbounded_sequences.size();
    if (size > 3) {
      throw std::runtime_error("array size exceeds upper bound");
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      test_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_key(
        ros_message.bounded_sequence_of_unbounded_sequences[i],
        cdr);
    }
  }

  // Member: unbounded_sequence_of_arrays
  {
    size_t size = ros_message.unbounded_sequence_of_arrays.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      test_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_key(
        ros_message.unbounded_sequence_of_arrays[i],
        cdr);
    }
  }

  // Member: unbounded_sequence_of_bounded_sequences
  {
    size_t size = ros_message.unbounded_sequence_of_bounded_sequences.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      test_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_key(
        ros_message.unbounded_sequence_of_bounded_sequences[i],
        cdr);
    }
  }

  // Member: unbounded_sequence_of_unbounded_sequences
  {
    size_t size = ros_message.unbounded_sequence_of_unbounded_sequences.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      test_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_key(
        ros_message.unbounded_sequence_of_unbounded_sequences[i],
        cdr);
    }
  }

  return true;
}

inline
size_t
get_serialized_size_key(
  const test_msgs::msg::MultiNested & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: array_of_arrays
  {
    size_t array_size = 3;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        test_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size_key(
        ros_message.array_of_arrays[index], current_alignment);
    }
  }

  // Member: array_of_bounded_sequences
  {
    size_t array_size = 3;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        test_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size_key(
        ros_message.array_of_bounded_sequences[index], current_alignment);
    }
  }

  // Member: array_of_unbounded_sequences
  {
    size_t array_size = 3;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        test_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size_key(
        ros_message.array_of_unbounded_sequences[index], current_alignment);
    }
  }

  // Member: bounded_sequence_of_arrays
  {
    size_t array_size = ros_message.bounded_sequence_of_arrays.size();
    if (array_size > 3) {
      throw std::runtime_error("array size exceeds upper bound");
    }
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        test_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size_key(
        ros_message.bounded_sequence_of_arrays[index], current_alignment);
    }
  }

  // Member: bounded_sequence_of_bounded_sequences
  {
    size_t array_size = ros_message.bounded_sequence_of_bounded_sequences.size();
    if (array_size > 3) {
      throw std::runtime_error("array size exceeds upper bound");
    }
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        test_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size_key(
        ros_message.bounded_sequence_of_bounded_sequences[index], current_alignment);
    }
  }

  // Member: bounded_sequence_of_unbounded_sequences
  {
    size_t array_size = ros_message.bounded_sequence_of_unbounded_sequences.size();
    if (array_size > 3) {
      throw std::runtime_error("array size exceeds upper bound");
    }
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        test_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size_key(
        ros_message.bounded_sequence_of_unbounded_sequences[index], current_alignment);
    }
  }

  // Member: unbounded_sequence_of_arrays
  {
    size_t array_size = ros_message.unbounded_sequence_of_arrays.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        test_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size_key(
        ros_message.unbounded_sequence_of_arrays[index], current_alignment);
    }
  }

  // Member: unbounded_sequence_of_bounded_sequences
  {
    size_t array_size = ros_message.unbounded_sequence_of_bounded_sequences.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        test_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size_key(
        ros_message.unbounded_sequence_of_bounded_sequences[index], current_alignment);
    }
  }

  // Member: unbounded_sequence_of_unbounded_sequences
  {
    size_t array_size = ros_message.unbounded_sequence_of_unbounded_sequences.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        test_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size_key(
        ros_message.unbounded_sequence_of_unbounded_sequences[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

inline
size_t
max_serialized_size_key_MultiNested(
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

  // Member: array_of_arrays
  {
    size_t array_size = 3;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        test_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_key_Arrays(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: array_of_bounded_sequences
  {
    size_t array_size = 3;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        test_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_key_BoundedSequences(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: array_of_unbounded_sequences
  {
    size_t array_size = 3;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        test_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_key_UnboundedSequences(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: bounded_sequence_of_arrays
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        test_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_key_Arrays(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: bounded_sequence_of_bounded_sequences
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        test_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_key_BoundedSequences(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: bounded_sequence_of_unbounded_sequences
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        test_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_key_UnboundedSequences(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: unbounded_sequence_of_arrays
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
        test_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_key_Arrays(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: unbounded_sequence_of_bounded_sequences
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
        test_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_key_BoundedSequences(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: unbounded_sequence_of_unbounded_sequences
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
        test_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_key_UnboundedSequences(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = test_msgs::msg::MultiNested;
    is_plain =
      (
      offsetof(DataType, unbounded_sequence_of_unbounded_sequences) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

}  // namespace detail

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace test_msgs

#endif  // TEST_MSGS__MSG__DETAIL__MULTI_NESTED__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_IMPL_HPP_
