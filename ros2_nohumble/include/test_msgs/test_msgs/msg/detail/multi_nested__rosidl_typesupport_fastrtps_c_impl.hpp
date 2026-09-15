// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c_impl.hpp.em
// with input from test_msgs:msg\MultiNested.idl
// generated code does not contain a copyright notice

#ifndef TEST_MSGS__MSG__DETAIL__MULTI_NESTED__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
#define TEST_MSGS__MSG__DETAIL__MULTI_NESTED__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include <vector>
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "test_msgs/msg/detail/multi_nested__struct.h"
#include "test_msgs/msg/detail/multi_nested__functions.h"
#include "test_msgs/msg/detail/multi_nested__rosidl_typesupport_fastrtps_c.h"
#include "fastcdr/Cdr.h"

#include "test_msgs/msg/detail/arrays__functions.h"  // array_of_arrays, bounded_sequence_of_arrays, unbounded_sequence_of_arrays
#include "test_msgs/msg/detail/bounded_sequences__functions.h"  // array_of_bounded_sequences, bounded_sequence_of_bounded_sequences, unbounded_sequence_of_bounded_sequences
#include "test_msgs/msg/detail/unbounded_sequences__functions.h"  // array_of_unbounded_sequences, bounded_sequence_of_unbounded_sequences, unbounded_sequence_of_unbounded_sequences

// Include the inline (de)serialization headers of nested message types so
// their bodies are visible here and can be fully inlined by the compiler.
#include "test_msgs/msg/detail/arrays__rosidl_typesupport_fastrtps_c_impl.hpp"
#include "test_msgs/msg/detail/bounded_sequences__rosidl_typesupport_fastrtps_c_impl.hpp"
#include "test_msgs/msg/detail/unbounded_sequences__rosidl_typesupport_fastrtps_c_impl.hpp"

#if defined(__cplusplus)
extern "C"
{
#endif

using _MultiNested__ros_msg_type = test_msgs__msg__MultiNested;


inline
bool impl_cdr_serialize_test_msgs__msg__MultiNested(
  const test_msgs__msg__MultiNested * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: array_of_arrays
  {
    size_t size = 3;
    auto array_ptr = ros_message->array_of_arrays;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_test_msgs__msg__Arrays(
        &array_ptr[i], cdr);
    }
  }

  // Field name: array_of_bounded_sequences
  {
    size_t size = 3;
    auto array_ptr = ros_message->array_of_bounded_sequences;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_test_msgs__msg__BoundedSequences(
        &array_ptr[i], cdr);
    }
  }

  // Field name: array_of_unbounded_sequences
  {
    size_t size = 3;
    auto array_ptr = ros_message->array_of_unbounded_sequences;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_test_msgs__msg__UnboundedSequences(
        &array_ptr[i], cdr);
    }
  }

  // Field name: bounded_sequence_of_arrays
  {
    size_t size = ros_message->bounded_sequence_of_arrays.size;
    auto array_ptr = ros_message->bounded_sequence_of_arrays.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_test_msgs__msg__Arrays(
        &array_ptr[i], cdr);
    }
  }

  // Field name: bounded_sequence_of_bounded_sequences
  {
    size_t size = ros_message->bounded_sequence_of_bounded_sequences.size;
    auto array_ptr = ros_message->bounded_sequence_of_bounded_sequences.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_test_msgs__msg__BoundedSequences(
        &array_ptr[i], cdr);
    }
  }

  // Field name: bounded_sequence_of_unbounded_sequences
  {
    size_t size = ros_message->bounded_sequence_of_unbounded_sequences.size;
    auto array_ptr = ros_message->bounded_sequence_of_unbounded_sequences.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_test_msgs__msg__UnboundedSequences(
        &array_ptr[i], cdr);
    }
  }

  // Field name: unbounded_sequence_of_arrays
  {
    size_t size = ros_message->unbounded_sequence_of_arrays.size;
    auto array_ptr = ros_message->unbounded_sequence_of_arrays.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_test_msgs__msg__Arrays(
        &array_ptr[i], cdr);
    }
  }

  // Field name: unbounded_sequence_of_bounded_sequences
  {
    size_t size = ros_message->unbounded_sequence_of_bounded_sequences.size;
    auto array_ptr = ros_message->unbounded_sequence_of_bounded_sequences.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_test_msgs__msg__BoundedSequences(
        &array_ptr[i], cdr);
    }
  }

  // Field name: unbounded_sequence_of_unbounded_sequences
  {
    size_t size = ros_message->unbounded_sequence_of_unbounded_sequences.size;
    auto array_ptr = ros_message->unbounded_sequence_of_unbounded_sequences.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_test_msgs__msg__UnboundedSequences(
        &array_ptr[i], cdr);
    }
  }

  return true;
}

inline
bool impl_cdr_deserialize_test_msgs__msg__MultiNested(
  eprosima::fastcdr::Cdr & cdr,
  test_msgs__msg__MultiNested * ros_message)
{
  // Field name: array_of_arrays
  {
    size_t size = 3;
    auto array_ptr = ros_message->array_of_arrays;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_test_msgs__msg__Arrays(cdr, &array_ptr[i]);
    }
  }

  // Field name: array_of_bounded_sequences
  {
    size_t size = 3;
    auto array_ptr = ros_message->array_of_bounded_sequences;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_test_msgs__msg__BoundedSequences(cdr, &array_ptr[i]);
    }
  }

  // Field name: array_of_unbounded_sequences
  {
    size_t size = 3;
    auto array_ptr = ros_message->array_of_unbounded_sequences;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_test_msgs__msg__UnboundedSequences(cdr, &array_ptr[i]);
    }
  }

  // Field name: bounded_sequence_of_arrays
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

    if (ros_message->bounded_sequence_of_arrays.data) {
      test_msgs__msg__Arrays__Sequence__fini(&ros_message->bounded_sequence_of_arrays);
    }
    if (!test_msgs__msg__Arrays__Sequence__init(&ros_message->bounded_sequence_of_arrays, size)) {
      fprintf(stderr, "failed to create array for field 'bounded_sequence_of_arrays'");
      return false;
    }
    auto array_ptr = ros_message->bounded_sequence_of_arrays.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_test_msgs__msg__Arrays(cdr, &array_ptr[i]);
    }
  }

  // Field name: bounded_sequence_of_bounded_sequences
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

    if (ros_message->bounded_sequence_of_bounded_sequences.data) {
      test_msgs__msg__BoundedSequences__Sequence__fini(&ros_message->bounded_sequence_of_bounded_sequences);
    }
    if (!test_msgs__msg__BoundedSequences__Sequence__init(&ros_message->bounded_sequence_of_bounded_sequences, size)) {
      fprintf(stderr, "failed to create array for field 'bounded_sequence_of_bounded_sequences'");
      return false;
    }
    auto array_ptr = ros_message->bounded_sequence_of_bounded_sequences.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_test_msgs__msg__BoundedSequences(cdr, &array_ptr[i]);
    }
  }

  // Field name: bounded_sequence_of_unbounded_sequences
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

    if (ros_message->bounded_sequence_of_unbounded_sequences.data) {
      test_msgs__msg__UnboundedSequences__Sequence__fini(&ros_message->bounded_sequence_of_unbounded_sequences);
    }
    if (!test_msgs__msg__UnboundedSequences__Sequence__init(&ros_message->bounded_sequence_of_unbounded_sequences, size)) {
      fprintf(stderr, "failed to create array for field 'bounded_sequence_of_unbounded_sequences'");
      return false;
    }
    auto array_ptr = ros_message->bounded_sequence_of_unbounded_sequences.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_test_msgs__msg__UnboundedSequences(cdr, &array_ptr[i]);
    }
  }

  // Field name: unbounded_sequence_of_arrays
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

    if (ros_message->unbounded_sequence_of_arrays.data) {
      test_msgs__msg__Arrays__Sequence__fini(&ros_message->unbounded_sequence_of_arrays);
    }
    if (!test_msgs__msg__Arrays__Sequence__init(&ros_message->unbounded_sequence_of_arrays, size)) {
      fprintf(stderr, "failed to create array for field 'unbounded_sequence_of_arrays'");
      return false;
    }
    auto array_ptr = ros_message->unbounded_sequence_of_arrays.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_test_msgs__msg__Arrays(cdr, &array_ptr[i]);
    }
  }

  // Field name: unbounded_sequence_of_bounded_sequences
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

    if (ros_message->unbounded_sequence_of_bounded_sequences.data) {
      test_msgs__msg__BoundedSequences__Sequence__fini(&ros_message->unbounded_sequence_of_bounded_sequences);
    }
    if (!test_msgs__msg__BoundedSequences__Sequence__init(&ros_message->unbounded_sequence_of_bounded_sequences, size)) {
      fprintf(stderr, "failed to create array for field 'unbounded_sequence_of_bounded_sequences'");
      return false;
    }
    auto array_ptr = ros_message->unbounded_sequence_of_bounded_sequences.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_test_msgs__msg__BoundedSequences(cdr, &array_ptr[i]);
    }
  }

  // Field name: unbounded_sequence_of_unbounded_sequences
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

    if (ros_message->unbounded_sequence_of_unbounded_sequences.data) {
      test_msgs__msg__UnboundedSequences__Sequence__fini(&ros_message->unbounded_sequence_of_unbounded_sequences);
    }
    if (!test_msgs__msg__UnboundedSequences__Sequence__init(&ros_message->unbounded_sequence_of_unbounded_sequences, size)) {
      fprintf(stderr, "failed to create array for field 'unbounded_sequence_of_unbounded_sequences'");
      return false;
    }
    auto array_ptr = ros_message->unbounded_sequence_of_unbounded_sequences.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_test_msgs__msg__UnboundedSequences(cdr, &array_ptr[i]);
    }
  }

  return true;
}  // NOLINT(readability/fn_size)


inline
size_t impl_get_serialized_size_test_msgs__msg__MultiNested(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _MultiNested__ros_msg_type * ros_message = static_cast<const _MultiNested__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: array_of_arrays
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->array_of_arrays;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_test_msgs__msg__Arrays(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: array_of_bounded_sequences
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->array_of_bounded_sequences;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_test_msgs__msg__BoundedSequences(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: array_of_unbounded_sequences
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->array_of_unbounded_sequences;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_test_msgs__msg__UnboundedSequences(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: bounded_sequence_of_arrays
  {
    size_t array_size = ros_message->bounded_sequence_of_arrays.size;
    auto array_ptr = ros_message->bounded_sequence_of_arrays.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_test_msgs__msg__Arrays(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: bounded_sequence_of_bounded_sequences
  {
    size_t array_size = ros_message->bounded_sequence_of_bounded_sequences.size;
    auto array_ptr = ros_message->bounded_sequence_of_bounded_sequences.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_test_msgs__msg__BoundedSequences(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: bounded_sequence_of_unbounded_sequences
  {
    size_t array_size = ros_message->bounded_sequence_of_unbounded_sequences.size;
    auto array_ptr = ros_message->bounded_sequence_of_unbounded_sequences.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_test_msgs__msg__UnboundedSequences(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: unbounded_sequence_of_arrays
  {
    size_t array_size = ros_message->unbounded_sequence_of_arrays.size;
    auto array_ptr = ros_message->unbounded_sequence_of_arrays.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_test_msgs__msg__Arrays(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: unbounded_sequence_of_bounded_sequences
  {
    size_t array_size = ros_message->unbounded_sequence_of_bounded_sequences.size;
    auto array_ptr = ros_message->unbounded_sequence_of_bounded_sequences.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_test_msgs__msg__BoundedSequences(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: unbounded_sequence_of_unbounded_sequences
  {
    size_t array_size = ros_message->unbounded_sequence_of_unbounded_sequences.size;
    auto array_ptr = ros_message->unbounded_sequence_of_unbounded_sequences.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_test_msgs__msg__UnboundedSequences(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}


inline
size_t impl_max_serialized_size_test_msgs__msg__MultiNested(
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

  // Field name: array_of_arrays
  {
    size_t array_size = 3;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_test_msgs__msg__Arrays(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: array_of_bounded_sequences
  {
    size_t array_size = 3;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_test_msgs__msg__BoundedSequences(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: array_of_unbounded_sequences
  {
    size_t array_size = 3;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_test_msgs__msg__UnboundedSequences(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: bounded_sequence_of_arrays
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_test_msgs__msg__Arrays(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: bounded_sequence_of_bounded_sequences
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_test_msgs__msg__BoundedSequences(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: bounded_sequence_of_unbounded_sequences
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_test_msgs__msg__UnboundedSequences(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: unbounded_sequence_of_arrays
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
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_test_msgs__msg__Arrays(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: unbounded_sequence_of_bounded_sequences
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
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_test_msgs__msg__BoundedSequences(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: unbounded_sequence_of_unbounded_sequences
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
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_test_msgs__msg__UnboundedSequences(
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
    using DataType = test_msgs__msg__MultiNested;
    is_plain =
      (
      offsetof(DataType, unbounded_sequence_of_unbounded_sequences) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_key_test_msgs__msg__MultiNested(
  const test_msgs__msg__MultiNested * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: array_of_arrays
  {
    size_t size = 3;
    auto array_ptr = ros_message->array_of_arrays;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_key_test_msgs__msg__Arrays(
        &array_ptr[i], cdr);
    }
  }

  // Field name: array_of_bounded_sequences
  {
    size_t size = 3;
    auto array_ptr = ros_message->array_of_bounded_sequences;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_key_test_msgs__msg__BoundedSequences(
        &array_ptr[i], cdr);
    }
  }

  // Field name: array_of_unbounded_sequences
  {
    size_t size = 3;
    auto array_ptr = ros_message->array_of_unbounded_sequences;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_key_test_msgs__msg__UnboundedSequences(
        &array_ptr[i], cdr);
    }
  }

  // Field name: bounded_sequence_of_arrays
  {
    size_t size = ros_message->bounded_sequence_of_arrays.size;
    auto array_ptr = ros_message->bounded_sequence_of_arrays.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_key_test_msgs__msg__Arrays(
        &array_ptr[i], cdr);
    }
  }

  // Field name: bounded_sequence_of_bounded_sequences
  {
    size_t size = ros_message->bounded_sequence_of_bounded_sequences.size;
    auto array_ptr = ros_message->bounded_sequence_of_bounded_sequences.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_key_test_msgs__msg__BoundedSequences(
        &array_ptr[i], cdr);
    }
  }

  // Field name: bounded_sequence_of_unbounded_sequences
  {
    size_t size = ros_message->bounded_sequence_of_unbounded_sequences.size;
    auto array_ptr = ros_message->bounded_sequence_of_unbounded_sequences.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_key_test_msgs__msg__UnboundedSequences(
        &array_ptr[i], cdr);
    }
  }

  // Field name: unbounded_sequence_of_arrays
  {
    size_t size = ros_message->unbounded_sequence_of_arrays.size;
    auto array_ptr = ros_message->unbounded_sequence_of_arrays.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_key_test_msgs__msg__Arrays(
        &array_ptr[i], cdr);
    }
  }

  // Field name: unbounded_sequence_of_bounded_sequences
  {
    size_t size = ros_message->unbounded_sequence_of_bounded_sequences.size;
    auto array_ptr = ros_message->unbounded_sequence_of_bounded_sequences.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_key_test_msgs__msg__BoundedSequences(
        &array_ptr[i], cdr);
    }
  }

  // Field name: unbounded_sequence_of_unbounded_sequences
  {
    size_t size = ros_message->unbounded_sequence_of_unbounded_sequences.size;
    auto array_ptr = ros_message->unbounded_sequence_of_unbounded_sequences.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_key_test_msgs__msg__UnboundedSequences(
        &array_ptr[i], cdr);
    }
  }

  return true;
}

inline
size_t impl_get_serialized_size_key_test_msgs__msg__MultiNested(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _MultiNested__ros_msg_type * ros_message = static_cast<const _MultiNested__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: array_of_arrays
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->array_of_arrays;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_key_test_msgs__msg__Arrays(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: array_of_bounded_sequences
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->array_of_bounded_sequences;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_key_test_msgs__msg__BoundedSequences(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: array_of_unbounded_sequences
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->array_of_unbounded_sequences;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_key_test_msgs__msg__UnboundedSequences(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: bounded_sequence_of_arrays
  {
    size_t array_size = ros_message->bounded_sequence_of_arrays.size;
    auto array_ptr = ros_message->bounded_sequence_of_arrays.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_key_test_msgs__msg__Arrays(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: bounded_sequence_of_bounded_sequences
  {
    size_t array_size = ros_message->bounded_sequence_of_bounded_sequences.size;
    auto array_ptr = ros_message->bounded_sequence_of_bounded_sequences.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_key_test_msgs__msg__BoundedSequences(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: bounded_sequence_of_unbounded_sequences
  {
    size_t array_size = ros_message->bounded_sequence_of_unbounded_sequences.size;
    auto array_ptr = ros_message->bounded_sequence_of_unbounded_sequences.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_key_test_msgs__msg__UnboundedSequences(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: unbounded_sequence_of_arrays
  {
    size_t array_size = ros_message->unbounded_sequence_of_arrays.size;
    auto array_ptr = ros_message->unbounded_sequence_of_arrays.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_key_test_msgs__msg__Arrays(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: unbounded_sequence_of_bounded_sequences
  {
    size_t array_size = ros_message->unbounded_sequence_of_bounded_sequences.size;
    auto array_ptr = ros_message->unbounded_sequence_of_bounded_sequences.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_key_test_msgs__msg__BoundedSequences(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: unbounded_sequence_of_unbounded_sequences
  {
    size_t array_size = ros_message->unbounded_sequence_of_unbounded_sequences.size;
    auto array_ptr = ros_message->unbounded_sequence_of_unbounded_sequences.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_key_test_msgs__msg__UnboundedSequences(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

inline
size_t impl_max_serialized_size_key_test_msgs__msg__MultiNested(
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
  // Field name: array_of_arrays
  {
    size_t array_size = 3;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_key_test_msgs__msg__Arrays(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: array_of_bounded_sequences
  {
    size_t array_size = 3;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_key_test_msgs__msg__BoundedSequences(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: array_of_unbounded_sequences
  {
    size_t array_size = 3;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_key_test_msgs__msg__UnboundedSequences(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: bounded_sequence_of_arrays
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_key_test_msgs__msg__Arrays(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: bounded_sequence_of_bounded_sequences
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_key_test_msgs__msg__BoundedSequences(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: bounded_sequence_of_unbounded_sequences
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_key_test_msgs__msg__UnboundedSequences(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: unbounded_sequence_of_arrays
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
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_key_test_msgs__msg__Arrays(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: unbounded_sequence_of_bounded_sequences
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
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_key_test_msgs__msg__BoundedSequences(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: unbounded_sequence_of_unbounded_sequences
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
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_key_test_msgs__msg__UnboundedSequences(
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
    using DataType = test_msgs__msg__MultiNested;
    is_plain =
      (
      offsetof(DataType, unbounded_sequence_of_unbounded_sequences) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_with_endpoint_test_msgs__msg__MultiNested(
  const test_msgs__msg__MultiNested * ros_message,
  eprosima::fastcdr::Cdr & cdr,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: array_of_arrays
  {
    size_t size = 3;
    auto array_ptr = ros_message->array_of_arrays;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_with_endpoint_test_msgs__msg__Arrays(
        &array_ptr[i], cdr, endpoint_info, serialization_context);
    }
  }

  // Field name: array_of_bounded_sequences
  {
    size_t size = 3;
    auto array_ptr = ros_message->array_of_bounded_sequences;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_with_endpoint_test_msgs__msg__BoundedSequences(
        &array_ptr[i], cdr, endpoint_info, serialization_context);
    }
  }

  // Field name: array_of_unbounded_sequences
  {
    size_t size = 3;
    auto array_ptr = ros_message->array_of_unbounded_sequences;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_with_endpoint_test_msgs__msg__UnboundedSequences(
        &array_ptr[i], cdr, endpoint_info, serialization_context);
    }
  }

  // Field name: bounded_sequence_of_arrays
  {
    size_t size = ros_message->bounded_sequence_of_arrays.size;
    auto array_ptr = ros_message->bounded_sequence_of_arrays.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_with_endpoint_test_msgs__msg__Arrays(
        &array_ptr[i], cdr, endpoint_info, serialization_context);
    }
  }

  // Field name: bounded_sequence_of_bounded_sequences
  {
    size_t size = ros_message->bounded_sequence_of_bounded_sequences.size;
    auto array_ptr = ros_message->bounded_sequence_of_bounded_sequences.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_with_endpoint_test_msgs__msg__BoundedSequences(
        &array_ptr[i], cdr, endpoint_info, serialization_context);
    }
  }

  // Field name: bounded_sequence_of_unbounded_sequences
  {
    size_t size = ros_message->bounded_sequence_of_unbounded_sequences.size;
    auto array_ptr = ros_message->bounded_sequence_of_unbounded_sequences.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_with_endpoint_test_msgs__msg__UnboundedSequences(
        &array_ptr[i], cdr, endpoint_info, serialization_context);
    }
  }

  // Field name: unbounded_sequence_of_arrays
  {
    size_t size = ros_message->unbounded_sequence_of_arrays.size;
    auto array_ptr = ros_message->unbounded_sequence_of_arrays.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_with_endpoint_test_msgs__msg__Arrays(
        &array_ptr[i], cdr, endpoint_info, serialization_context);
    }
  }

  // Field name: unbounded_sequence_of_bounded_sequences
  {
    size_t size = ros_message->unbounded_sequence_of_bounded_sequences.size;
    auto array_ptr = ros_message->unbounded_sequence_of_bounded_sequences.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_with_endpoint_test_msgs__msg__BoundedSequences(
        &array_ptr[i], cdr, endpoint_info, serialization_context);
    }
  }

  // Field name: unbounded_sequence_of_unbounded_sequences
  {
    size_t size = ros_message->unbounded_sequence_of_unbounded_sequences.size;
    auto array_ptr = ros_message->unbounded_sequence_of_unbounded_sequences.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_with_endpoint_test_msgs__msg__UnboundedSequences(
        &array_ptr[i], cdr, endpoint_info, serialization_context);
    }
  }

  return true;
}

inline
bool impl_cdr_deserialize_with_endpoint_test_msgs__msg__MultiNested(
  eprosima::fastcdr::Cdr & cdr,
  test_msgs__msg__MultiNested * ros_message,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: array_of_arrays
  {
    size_t size = 3;
    auto array_ptr = ros_message->array_of_arrays;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_with_endpoint_test_msgs__msg__Arrays(cdr, &array_ptr[i], endpoint_info, serialization_context);
    }
  }

  // Field name: array_of_bounded_sequences
  {
    size_t size = 3;
    auto array_ptr = ros_message->array_of_bounded_sequences;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_with_endpoint_test_msgs__msg__BoundedSequences(cdr, &array_ptr[i], endpoint_info, serialization_context);
    }
  }

  // Field name: array_of_unbounded_sequences
  {
    size_t size = 3;
    auto array_ptr = ros_message->array_of_unbounded_sequences;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_with_endpoint_test_msgs__msg__UnboundedSequences(cdr, &array_ptr[i], endpoint_info, serialization_context);
    }
  }

  // Field name: bounded_sequence_of_arrays
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

    if (ros_message->bounded_sequence_of_arrays.data) {
      test_msgs__msg__Arrays__Sequence__fini(&ros_message->bounded_sequence_of_arrays);
    }
    if (!test_msgs__msg__Arrays__Sequence__init(&ros_message->bounded_sequence_of_arrays, size)) {
      fprintf(stderr, "failed to create array for field 'bounded_sequence_of_arrays'");
      return false;
    }
    auto array_ptr = ros_message->bounded_sequence_of_arrays.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_with_endpoint_test_msgs__msg__Arrays(cdr, &array_ptr[i], endpoint_info, serialization_context);
    }
  }

  // Field name: bounded_sequence_of_bounded_sequences
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

    if (ros_message->bounded_sequence_of_bounded_sequences.data) {
      test_msgs__msg__BoundedSequences__Sequence__fini(&ros_message->bounded_sequence_of_bounded_sequences);
    }
    if (!test_msgs__msg__BoundedSequences__Sequence__init(&ros_message->bounded_sequence_of_bounded_sequences, size)) {
      fprintf(stderr, "failed to create array for field 'bounded_sequence_of_bounded_sequences'");
      return false;
    }
    auto array_ptr = ros_message->bounded_sequence_of_bounded_sequences.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_with_endpoint_test_msgs__msg__BoundedSequences(cdr, &array_ptr[i], endpoint_info, serialization_context);
    }
  }

  // Field name: bounded_sequence_of_unbounded_sequences
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

    if (ros_message->bounded_sequence_of_unbounded_sequences.data) {
      test_msgs__msg__UnboundedSequences__Sequence__fini(&ros_message->bounded_sequence_of_unbounded_sequences);
    }
    if (!test_msgs__msg__UnboundedSequences__Sequence__init(&ros_message->bounded_sequence_of_unbounded_sequences, size)) {
      fprintf(stderr, "failed to create array for field 'bounded_sequence_of_unbounded_sequences'");
      return false;
    }
    auto array_ptr = ros_message->bounded_sequence_of_unbounded_sequences.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_with_endpoint_test_msgs__msg__UnboundedSequences(cdr, &array_ptr[i], endpoint_info, serialization_context);
    }
  }

  // Field name: unbounded_sequence_of_arrays
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

    if (ros_message->unbounded_sequence_of_arrays.data) {
      test_msgs__msg__Arrays__Sequence__fini(&ros_message->unbounded_sequence_of_arrays);
    }
    if (!test_msgs__msg__Arrays__Sequence__init(&ros_message->unbounded_sequence_of_arrays, size)) {
      fprintf(stderr, "failed to create array for field 'unbounded_sequence_of_arrays'");
      return false;
    }
    auto array_ptr = ros_message->unbounded_sequence_of_arrays.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_with_endpoint_test_msgs__msg__Arrays(cdr, &array_ptr[i], endpoint_info, serialization_context);
    }
  }

  // Field name: unbounded_sequence_of_bounded_sequences
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

    if (ros_message->unbounded_sequence_of_bounded_sequences.data) {
      test_msgs__msg__BoundedSequences__Sequence__fini(&ros_message->unbounded_sequence_of_bounded_sequences);
    }
    if (!test_msgs__msg__BoundedSequences__Sequence__init(&ros_message->unbounded_sequence_of_bounded_sequences, size)) {
      fprintf(stderr, "failed to create array for field 'unbounded_sequence_of_bounded_sequences'");
      return false;
    }
    auto array_ptr = ros_message->unbounded_sequence_of_bounded_sequences.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_with_endpoint_test_msgs__msg__BoundedSequences(cdr, &array_ptr[i], endpoint_info, serialization_context);
    }
  }

  // Field name: unbounded_sequence_of_unbounded_sequences
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

    if (ros_message->unbounded_sequence_of_unbounded_sequences.data) {
      test_msgs__msg__UnboundedSequences__Sequence__fini(&ros_message->unbounded_sequence_of_unbounded_sequences);
    }
    if (!test_msgs__msg__UnboundedSequences__Sequence__init(&ros_message->unbounded_sequence_of_unbounded_sequences, size)) {
      fprintf(stderr, "failed to create array for field 'unbounded_sequence_of_unbounded_sequences'");
      return false;
    }
    auto array_ptr = ros_message->unbounded_sequence_of_unbounded_sequences.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_with_endpoint_test_msgs__msg__UnboundedSequences(cdr, &array_ptr[i], endpoint_info, serialization_context);
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

#if defined(__cplusplus)
}
#endif

#endif  // TEST_MSGS__MSG__DETAIL__MULTI_NESTED__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
