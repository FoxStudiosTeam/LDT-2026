// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support_impl.hpp.em
// with input from test_msgs:msg\WStrings.idl
// generated code does not contain a copyright notice

#ifndef TEST_MSGS__MSG__DETAIL__W_STRINGS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_IMPL_HPP_
#define TEST_MSGS__MSG__DETAIL__W_STRINGS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_IMPL_HPP_

#include <cstddef>
#include <cstdio>
#include <limits>
#include <stdexcept>
#include <string>
#include <vector>
#include "rcutils/logging_macros.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/serialization_helpers.hpp"
#include "test_msgs/msg/detail/w_strings__rosidl_typesupport_fastrtps_cpp.hpp"
#include "fastcdr/Cdr.h"

// Include the inline (de)serialization headers of nested message types so
// their bodies are visible here and can be fully inlined by the compiler.


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
  const test_msgs::msg::WStrings & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: wstring_value
  {
    rosidl_typesupport_fastrtps_cpp::cdr_serialize(cdr, ros_message.wstring_value);
  }

  // Member: wstring_value_default1
  {
    rosidl_typesupport_fastrtps_cpp::cdr_serialize(cdr, ros_message.wstring_value_default1);
  }

  // Member: wstring_value_default2
  {
    rosidl_typesupport_fastrtps_cpp::cdr_serialize(cdr, ros_message.wstring_value_default2);
  }

  // Member: wstring_value_default3
  {
    rosidl_typesupport_fastrtps_cpp::cdr_serialize(cdr, ros_message.wstring_value_default3);
  }

  // Member: array_of_wstrings
  {
    for (size_t i = 0; i < 3; i++) {
      rosidl_typesupport_fastrtps_cpp::cdr_serialize(cdr, ros_message.array_of_wstrings[i]);
    }
  }

  // Member: bounded_sequence_of_wstrings
  {
    size_t size = ros_message.bounded_sequence_of_wstrings.size();
    if (size > 3) {
      throw std::runtime_error("array size exceeds upper bound");
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      rosidl_typesupport_fastrtps_cpp::cdr_serialize(cdr, ros_message.bounded_sequence_of_wstrings[i]);
    }
  }

  // Member: unbounded_sequence_of_wstrings
  {
    size_t size = ros_message.unbounded_sequence_of_wstrings.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      rosidl_typesupport_fastrtps_cpp::cdr_serialize(cdr, ros_message.unbounded_sequence_of_wstrings[i]);
    }
  }

  return true;
}

inline
bool
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  test_msgs::msg::WStrings & ros_message)
{
  // Member: wstring_value
  {
    bool succeeded = rosidl_typesupport_fastrtps_cpp::cdr_deserialize(cdr, ros_message.wstring_value);
    if (!succeeded) {
      fprintf(stderr, "failed to deserialize u16string\n");
      return false;
    }
  }

  // Member: wstring_value_default1
  {
    bool succeeded = rosidl_typesupport_fastrtps_cpp::cdr_deserialize(cdr, ros_message.wstring_value_default1);
    if (!succeeded) {
      fprintf(stderr, "failed to deserialize u16string\n");
      return false;
    }
  }

  // Member: wstring_value_default2
  {
    bool succeeded = rosidl_typesupport_fastrtps_cpp::cdr_deserialize(cdr, ros_message.wstring_value_default2);
    if (!succeeded) {
      fprintf(stderr, "failed to deserialize u16string\n");
      return false;
    }
  }

  // Member: wstring_value_default3
  {
    bool succeeded = rosidl_typesupport_fastrtps_cpp::cdr_deserialize(cdr, ros_message.wstring_value_default3);
    if (!succeeded) {
      fprintf(stderr, "failed to deserialize u16string\n");
      return false;
    }
  }

  // Member: array_of_wstrings
  {
    for (size_t i = 0; i < 3; i++) {
      bool succeeded = rosidl_typesupport_fastrtps_cpp::cdr_deserialize(cdr, ros_message.array_of_wstrings[i]);
      if (!succeeded) {
        fprintf(stderr, "failed to deserialize u16string\n");
        return false;
      }
    }
  }

  // Member: bounded_sequence_of_wstrings
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

    ros_message.bounded_sequence_of_wstrings.resize(size);
    for (size_t i = 0; i < size; i++) {
      bool succeeded = rosidl_typesupport_fastrtps_cpp::cdr_deserialize(cdr, ros_message.bounded_sequence_of_wstrings[i]);
      if (!succeeded) {
        fprintf(stderr, "failed to deserialize u16string\n");
        return false;
      }
    }
  }

  // Member: unbounded_sequence_of_wstrings
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

    ros_message.unbounded_sequence_of_wstrings.resize(size);
    for (size_t i = 0; i < size; i++) {
      bool succeeded = rosidl_typesupport_fastrtps_cpp::cdr_deserialize(cdr, ros_message.unbounded_sequence_of_wstrings[i]);
      if (!succeeded) {
        fprintf(stderr, "failed to deserialize u16string\n");
        return false;
      }
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

// Endpoint-aware serialization. Always emitted so parent messages can recurse
// through non-Buffer intermediate message types.
inline
bool
cdr_serialize_with_endpoint(
  const test_msgs::msg::WStrings & ros_message,
  eprosima::fastcdr::Cdr & cdr,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  try {
    // Member: wstring_value
    {
      rosidl_typesupport_fastrtps_cpp::cdr_serialize(cdr, ros_message.wstring_value);
    }
    // Member: wstring_value_default1
    {
      rosidl_typesupport_fastrtps_cpp::cdr_serialize(cdr, ros_message.wstring_value_default1);
    }
    // Member: wstring_value_default2
    {
      rosidl_typesupport_fastrtps_cpp::cdr_serialize(cdr, ros_message.wstring_value_default2);
    }
    // Member: wstring_value_default3
    {
      rosidl_typesupport_fastrtps_cpp::cdr_serialize(cdr, ros_message.wstring_value_default3);
    }
    // Member: array_of_wstrings
    {
      for (size_t i = 0; i < 3; i++) {
        rosidl_typesupport_fastrtps_cpp::cdr_serialize(cdr, ros_message.array_of_wstrings[i]);
      }
    }
    // Member: bounded_sequence_of_wstrings
    {
      size_t size = ros_message.bounded_sequence_of_wstrings.size();
      if (size > 3) {
        throw std::runtime_error("array size exceeds upper bound");
      }
      cdr << static_cast<uint32_t>(size);
      for (size_t i = 0; i < size; i++) {
        rosidl_typesupport_fastrtps_cpp::cdr_serialize(cdr, ros_message.bounded_sequence_of_wstrings[i]);
      }
    }
    // Member: unbounded_sequence_of_wstrings
    {
      size_t size = ros_message.unbounded_sequence_of_wstrings.size();
      cdr << static_cast<uint32_t>(size);
      for (size_t i = 0; i < size; i++) {
        rosidl_typesupport_fastrtps_cpp::cdr_serialize(cdr, ros_message.unbounded_sequence_of_wstrings[i]);
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
  test_msgs::msg::WStrings & ros_message,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Member: wstring_value
  {
    bool succeeded = rosidl_typesupport_fastrtps_cpp::cdr_deserialize(cdr, ros_message.wstring_value);
    if (!succeeded) {
      fprintf(stderr, "failed to deserialize u16string\n");
      return false;
    }
  }

  // Member: wstring_value_default1
  {
    bool succeeded = rosidl_typesupport_fastrtps_cpp::cdr_deserialize(cdr, ros_message.wstring_value_default1);
    if (!succeeded) {
      fprintf(stderr, "failed to deserialize u16string\n");
      return false;
    }
  }

  // Member: wstring_value_default2
  {
    bool succeeded = rosidl_typesupport_fastrtps_cpp::cdr_deserialize(cdr, ros_message.wstring_value_default2);
    if (!succeeded) {
      fprintf(stderr, "failed to deserialize u16string\n");
      return false;
    }
  }

  // Member: wstring_value_default3
  {
    bool succeeded = rosidl_typesupport_fastrtps_cpp::cdr_deserialize(cdr, ros_message.wstring_value_default3);
    if (!succeeded) {
      fprintf(stderr, "failed to deserialize u16string\n");
      return false;
    }
  }

  // Member: array_of_wstrings
  {
    for (size_t i = 0; i < 3; i++) {
      bool succeeded = rosidl_typesupport_fastrtps_cpp::cdr_deserialize(cdr, ros_message.array_of_wstrings[i]);
      if (!succeeded) {
        fprintf(stderr, "failed to deserialize u16string\n");
        return false;
      }
    }
  }

  // Member: bounded_sequence_of_wstrings
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

    ros_message.bounded_sequence_of_wstrings.resize(size);
    if (size > 3) {
      throw std::runtime_error("vector size exceeds upper bound");
    }
    for (size_t i = 0; i < size; i++) {
      bool succeeded = rosidl_typesupport_fastrtps_cpp::cdr_deserialize(cdr, ros_message.bounded_sequence_of_wstrings[i]);
      if (!succeeded) {
        fprintf(stderr, "failed to deserialize u16string\n");
        return false;
      }
    }
  }

  // Member: unbounded_sequence_of_wstrings
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

    ros_message.unbounded_sequence_of_wstrings.resize(size);
    for (size_t i = 0; i < size; i++) {
      bool succeeded = rosidl_typesupport_fastrtps_cpp::cdr_deserialize(cdr, ros_message.unbounded_sequence_of_wstrings[i]);
      if (!succeeded) {
        fprintf(stderr, "failed to deserialize u16string\n");
        return false;
      }
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

inline
size_t
get_serialized_size(
  const test_msgs::msg::WStrings & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: wstring_value
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    wchar_size *
    (ros_message.wstring_value.size() + 1);

  // Member: wstring_value_default1
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    wchar_size *
    (ros_message.wstring_value_default1.size() + 1);

  // Member: wstring_value_default2
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    wchar_size *
    (ros_message.wstring_value_default2.size() + 1);

  // Member: wstring_value_default3
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    wchar_size *
    (ros_message.wstring_value_default3.size() + 1);

  // Member: array_of_wstrings
  {
    size_t array_size = 3;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        wchar_size *
        (ros_message.array_of_wstrings[index].size() + 1);
    }
  }

  // Member: bounded_sequence_of_wstrings
  {
    size_t array_size = ros_message.bounded_sequence_of_wstrings.size();
    if (array_size > 3) {
      throw std::runtime_error("array size exceeds upper bound");
    }
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        wchar_size *
        (ros_message.bounded_sequence_of_wstrings[index].size() + 1);
    }
  }

  // Member: unbounded_sequence_of_wstrings
  {
    size_t array_size = ros_message.unbounded_sequence_of_wstrings.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        wchar_size *
        (ros_message.unbounded_sequence_of_wstrings[index].size() + 1);
    }
  }

  return current_alignment - initial_alignment;
}


inline
size_t
max_serialized_size_WStrings(
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

  // Member: wstring_value
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        wchar_size *
        1;
    }
  }
  // Member: wstring_value_default1
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        wchar_size *
        1;
    }
  }
  // Member: wstring_value_default2
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        wchar_size *
        1;
    }
  }
  // Member: wstring_value_default3
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        wchar_size *
        1;
    }
  }
  // Member: array_of_wstrings
  {
    size_t array_size = 3;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        wchar_size *
        1;
    }
  }
  // Member: bounded_sequence_of_wstrings
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        wchar_size *
        1;
    }
  }
  // Member: unbounded_sequence_of_wstrings
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
        wchar_size *
        1;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = test_msgs::msg::WStrings;
    is_plain =
      (
      offsetof(DataType, unbounded_sequence_of_wstrings) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

inline
bool
cdr_serialize_key(
  const test_msgs::msg::WStrings & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: wstring_value
  {
    rosidl_typesupport_fastrtps_cpp::cdr_serialize(cdr, ros_message.wstring_value);
  }

  // Member: wstring_value_default1
  {
    rosidl_typesupport_fastrtps_cpp::cdr_serialize(cdr, ros_message.wstring_value_default1);
  }

  // Member: wstring_value_default2
  {
    rosidl_typesupport_fastrtps_cpp::cdr_serialize(cdr, ros_message.wstring_value_default2);
  }

  // Member: wstring_value_default3
  {
    rosidl_typesupport_fastrtps_cpp::cdr_serialize(cdr, ros_message.wstring_value_default3);
  }

  // Member: array_of_wstrings
  {
    for (size_t i = 0; i < 3; i++) {
      rosidl_typesupport_fastrtps_cpp::cdr_serialize(cdr, ros_message.array_of_wstrings[i]);
    }
  }

  // Member: bounded_sequence_of_wstrings
  {
    size_t size = ros_message.bounded_sequence_of_wstrings.size();
    if (size > 3) {
      throw std::runtime_error("array size exceeds upper bound");
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      rosidl_typesupport_fastrtps_cpp::cdr_serialize(cdr, ros_message.bounded_sequence_of_wstrings[i]);
    }
  }

  // Member: unbounded_sequence_of_wstrings
  {
    size_t size = ros_message.unbounded_sequence_of_wstrings.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      rosidl_typesupport_fastrtps_cpp::cdr_serialize(cdr, ros_message.unbounded_sequence_of_wstrings[i]);
    }
  }

  return true;
}

inline
size_t
get_serialized_size_key(
  const test_msgs::msg::WStrings & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: wstring_value
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    wchar_size *
    (ros_message.wstring_value.size() + 1);

  // Member: wstring_value_default1
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    wchar_size *
    (ros_message.wstring_value_default1.size() + 1);

  // Member: wstring_value_default2
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    wchar_size *
    (ros_message.wstring_value_default2.size() + 1);

  // Member: wstring_value_default3
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    wchar_size *
    (ros_message.wstring_value_default3.size() + 1);

  // Member: array_of_wstrings
  {
    size_t array_size = 3;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        wchar_size *
        (ros_message.array_of_wstrings[index].size() + 1);
    }
  }

  // Member: bounded_sequence_of_wstrings
  {
    size_t array_size = ros_message.bounded_sequence_of_wstrings.size();
    if (array_size > 3) {
      throw std::runtime_error("array size exceeds upper bound");
    }
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        wchar_size *
        (ros_message.bounded_sequence_of_wstrings[index].size() + 1);
    }
  }

  // Member: unbounded_sequence_of_wstrings
  {
    size_t array_size = ros_message.unbounded_sequence_of_wstrings.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        wchar_size *
        (ros_message.unbounded_sequence_of_wstrings[index].size() + 1);
    }
  }

  return current_alignment - initial_alignment;
}

inline
size_t
max_serialized_size_key_WStrings(
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

  // Member: wstring_value
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        wchar_size *
        1;
    }
  }

  // Member: wstring_value_default1
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        wchar_size *
        1;
    }
  }

  // Member: wstring_value_default2
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        wchar_size *
        1;
    }
  }

  // Member: wstring_value_default3
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        wchar_size *
        1;
    }
  }

  // Member: array_of_wstrings
  {
    size_t array_size = 3;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        wchar_size *
        1;
    }
  }

  // Member: bounded_sequence_of_wstrings
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        wchar_size *
        1;
    }
  }

  // Member: unbounded_sequence_of_wstrings
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
        wchar_size *
        1;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = test_msgs::msg::WStrings;
    is_plain =
      (
      offsetof(DataType, unbounded_sequence_of_wstrings) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

}  // namespace detail

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace test_msgs

#endif  // TEST_MSGS__MSG__DETAIL__W_STRINGS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_IMPL_HPP_
