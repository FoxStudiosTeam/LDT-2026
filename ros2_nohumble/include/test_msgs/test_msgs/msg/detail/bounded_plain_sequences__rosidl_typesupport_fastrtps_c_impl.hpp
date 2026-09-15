// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c_impl.hpp.em
// with input from test_msgs:msg\BoundedPlainSequences.idl
// generated code does not contain a copyright notice

#ifndef TEST_MSGS__MSG__DETAIL__BOUNDED_PLAIN_SEQUENCES__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
#define TEST_MSGS__MSG__DETAIL__BOUNDED_PLAIN_SEQUENCES__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include <vector>
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "test_msgs/msg/detail/bounded_plain_sequences__struct.h"
#include "test_msgs/msg/detail/bounded_plain_sequences__functions.h"
#include "test_msgs/msg/detail/bounded_plain_sequences__rosidl_typesupport_fastrtps_c.h"
#include "fastcdr/Cdr.h"

#include "rosidl_runtime_c/primitives_sequence.h"  // bool_values, bool_values_default, byte_values, byte_values_default, char_values, char_values_default, float32_values, float32_values_default, float64_values, float64_values_default, int16_values, int16_values_default, int32_values, int32_values_default, int64_values, int64_values_default, int8_values, int8_values_default, uint16_values, uint16_values_default, uint32_values, uint32_values_default, uint64_values, uint64_values_default, uint8_values, uint8_values_default
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // bool_values, bool_values_default, byte_values, byte_values_default, char_values, char_values_default, float32_values, float32_values_default, float64_values, float64_values_default, int16_values, int16_values_default, int32_values, int32_values_default, int64_values, int64_values_default, int8_values, int8_values_default, uint16_values, uint16_values_default, uint32_values, uint32_values_default, uint64_values, uint64_values_default, uint8_values, uint8_values_default
#include "test_msgs/msg/detail/basic_types__functions.h"  // basic_types_values
#include "test_msgs/msg/detail/constants__functions.h"  // constants_values
#include "test_msgs/msg/detail/defaults__functions.h"  // defaults_values

// Include the inline (de)serialization headers of nested message types so
// their bodies are visible here and can be fully inlined by the compiler.
#include "test_msgs/msg/detail/basic_types__rosidl_typesupport_fastrtps_c_impl.hpp"
#include "test_msgs/msg/detail/constants__rosidl_typesupport_fastrtps_c_impl.hpp"
#include "test_msgs/msg/detail/defaults__rosidl_typesupport_fastrtps_c_impl.hpp"

#if defined(__cplusplus)
extern "C"
{
#endif

using _BoundedPlainSequences__ros_msg_type = test_msgs__msg__BoundedPlainSequences;


inline
bool impl_cdr_serialize_test_msgs__msg__BoundedPlainSequences(
  const test_msgs__msg__BoundedPlainSequences * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: bool_values
  {
    size_t size = ros_message->bool_values.size;
    auto array_ptr = ros_message->bool_values.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: byte_values
  {
    size_t size = ros_message->byte_values.size;
    auto array_ptr = ros_message->byte_values.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: char_values
  {
    size_t size = ros_message->char_values.size;
    auto array_ptr = ros_message->char_values.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: float32_values
  {
    size_t size = ros_message->float32_values.size;
    auto array_ptr = ros_message->float32_values.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: float64_values
  {
    size_t size = ros_message->float64_values.size;
    auto array_ptr = ros_message->float64_values.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int8_values
  {
    size_t size = ros_message->int8_values.size;
    auto array_ptr = ros_message->int8_values.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint8_values
  {
    size_t size = ros_message->uint8_values.size;
    auto array_ptr = ros_message->uint8_values.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int16_values
  {
    size_t size = ros_message->int16_values.size;
    auto array_ptr = ros_message->int16_values.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint16_values
  {
    size_t size = ros_message->uint16_values.size;
    auto array_ptr = ros_message->uint16_values.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int32_values
  {
    size_t size = ros_message->int32_values.size;
    auto array_ptr = ros_message->int32_values.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint32_values
  {
    size_t size = ros_message->uint32_values.size;
    auto array_ptr = ros_message->uint32_values.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int64_values
  {
    size_t size = ros_message->int64_values.size;
    auto array_ptr = ros_message->int64_values.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint64_values
  {
    size_t size = ros_message->uint64_values.size;
    auto array_ptr = ros_message->uint64_values.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: basic_types_values
  {
    size_t size = ros_message->basic_types_values.size;
    auto array_ptr = ros_message->basic_types_values.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_test_msgs__msg__BasicTypes(
        &array_ptr[i], cdr);
    }
  }

  // Field name: constants_values
  {
    size_t size = ros_message->constants_values.size;
    auto array_ptr = ros_message->constants_values.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_test_msgs__msg__Constants(
        &array_ptr[i], cdr);
    }
  }

  // Field name: defaults_values
  {
    size_t size = ros_message->defaults_values.size;
    auto array_ptr = ros_message->defaults_values.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_test_msgs__msg__Defaults(
        &array_ptr[i], cdr);
    }
  }

  // Field name: bool_values_default
  {
    size_t size = ros_message->bool_values_default.size;
    auto array_ptr = ros_message->bool_values_default.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: byte_values_default
  {
    size_t size = ros_message->byte_values_default.size;
    auto array_ptr = ros_message->byte_values_default.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: char_values_default
  {
    size_t size = ros_message->char_values_default.size;
    auto array_ptr = ros_message->char_values_default.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: float32_values_default
  {
    size_t size = ros_message->float32_values_default.size;
    auto array_ptr = ros_message->float32_values_default.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: float64_values_default
  {
    size_t size = ros_message->float64_values_default.size;
    auto array_ptr = ros_message->float64_values_default.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int8_values_default
  {
    size_t size = ros_message->int8_values_default.size;
    auto array_ptr = ros_message->int8_values_default.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint8_values_default
  {
    size_t size = ros_message->uint8_values_default.size;
    auto array_ptr = ros_message->uint8_values_default.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int16_values_default
  {
    size_t size = ros_message->int16_values_default.size;
    auto array_ptr = ros_message->int16_values_default.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint16_values_default
  {
    size_t size = ros_message->uint16_values_default.size;
    auto array_ptr = ros_message->uint16_values_default.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int32_values_default
  {
    size_t size = ros_message->int32_values_default.size;
    auto array_ptr = ros_message->int32_values_default.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint32_values_default
  {
    size_t size = ros_message->uint32_values_default.size;
    auto array_ptr = ros_message->uint32_values_default.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int64_values_default
  {
    size_t size = ros_message->int64_values_default.size;
    auto array_ptr = ros_message->int64_values_default.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint64_values_default
  {
    size_t size = ros_message->uint64_values_default.size;
    auto array_ptr = ros_message->uint64_values_default.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: alignment_check
  {
    cdr << ros_message->alignment_check;
  }

  return true;
}

inline
bool impl_cdr_deserialize_test_msgs__msg__BoundedPlainSequences(
  eprosima::fastcdr::Cdr & cdr,
  test_msgs__msg__BoundedPlainSequences * ros_message)
{
  // Field name: bool_values
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

    if (ros_message->bool_values.data) {
      rosidl_runtime_c__boolean__Sequence__fini(&ros_message->bool_values);
    }
    if (!rosidl_runtime_c__boolean__Sequence__init(&ros_message->bool_values, size)) {
      fprintf(stderr, "failed to create array for field 'bool_values'");
      return false;
    }
    auto array_ptr = ros_message->bool_values.data;
    for (size_t i = 0; i < size; ++i) {
      uint8_t tmp;
      cdr >> tmp;
      array_ptr[i] = tmp ? true : false;
    }
  }

  // Field name: byte_values
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

    if (ros_message->byte_values.data) {
      rosidl_runtime_c__octet__Sequence__fini(&ros_message->byte_values);
    }
    if (!rosidl_runtime_c__octet__Sequence__init(&ros_message->byte_values, size)) {
      fprintf(stderr, "failed to create array for field 'byte_values'");
      return false;
    }
    auto array_ptr = ros_message->byte_values.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: char_values
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

    if (ros_message->char_values.data) {
      rosidl_runtime_c__uint8__Sequence__fini(&ros_message->char_values);
    }
    if (!rosidl_runtime_c__uint8__Sequence__init(&ros_message->char_values, size)) {
      fprintf(stderr, "failed to create array for field 'char_values'");
      return false;
    }
    auto array_ptr = ros_message->char_values.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: float32_values
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

    if (ros_message->float32_values.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->float32_values);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->float32_values, size)) {
      fprintf(stderr, "failed to create array for field 'float32_values'");
      return false;
    }
    auto array_ptr = ros_message->float32_values.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: float64_values
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

    if (ros_message->float64_values.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->float64_values);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->float64_values, size)) {
      fprintf(stderr, "failed to create array for field 'float64_values'");
      return false;
    }
    auto array_ptr = ros_message->float64_values.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: int8_values
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

    if (ros_message->int8_values.data) {
      rosidl_runtime_c__int8__Sequence__fini(&ros_message->int8_values);
    }
    if (!rosidl_runtime_c__int8__Sequence__init(&ros_message->int8_values, size)) {
      fprintf(stderr, "failed to create array for field 'int8_values'");
      return false;
    }
    auto array_ptr = ros_message->int8_values.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: uint8_values
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

    if (ros_message->uint8_values.data) {
      rosidl_runtime_c__uint8__Sequence__fini(&ros_message->uint8_values);
    }
    if (!rosidl_runtime_c__uint8__Sequence__init(&ros_message->uint8_values, size)) {
      fprintf(stderr, "failed to create array for field 'uint8_values'");
      return false;
    }
    auto array_ptr = ros_message->uint8_values.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: int16_values
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

    if (ros_message->int16_values.data) {
      rosidl_runtime_c__int16__Sequence__fini(&ros_message->int16_values);
    }
    if (!rosidl_runtime_c__int16__Sequence__init(&ros_message->int16_values, size)) {
      fprintf(stderr, "failed to create array for field 'int16_values'");
      return false;
    }
    auto array_ptr = ros_message->int16_values.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: uint16_values
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

    if (ros_message->uint16_values.data) {
      rosidl_runtime_c__uint16__Sequence__fini(&ros_message->uint16_values);
    }
    if (!rosidl_runtime_c__uint16__Sequence__init(&ros_message->uint16_values, size)) {
      fprintf(stderr, "failed to create array for field 'uint16_values'");
      return false;
    }
    auto array_ptr = ros_message->uint16_values.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: int32_values
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

    if (ros_message->int32_values.data) {
      rosidl_runtime_c__int32__Sequence__fini(&ros_message->int32_values);
    }
    if (!rosidl_runtime_c__int32__Sequence__init(&ros_message->int32_values, size)) {
      fprintf(stderr, "failed to create array for field 'int32_values'");
      return false;
    }
    auto array_ptr = ros_message->int32_values.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: uint32_values
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

    if (ros_message->uint32_values.data) {
      rosidl_runtime_c__uint32__Sequence__fini(&ros_message->uint32_values);
    }
    if (!rosidl_runtime_c__uint32__Sequence__init(&ros_message->uint32_values, size)) {
      fprintf(stderr, "failed to create array for field 'uint32_values'");
      return false;
    }
    auto array_ptr = ros_message->uint32_values.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: int64_values
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

    if (ros_message->int64_values.data) {
      rosidl_runtime_c__int64__Sequence__fini(&ros_message->int64_values);
    }
    if (!rosidl_runtime_c__int64__Sequence__init(&ros_message->int64_values, size)) {
      fprintf(stderr, "failed to create array for field 'int64_values'");
      return false;
    }
    auto array_ptr = ros_message->int64_values.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: uint64_values
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

    if (ros_message->uint64_values.data) {
      rosidl_runtime_c__uint64__Sequence__fini(&ros_message->uint64_values);
    }
    if (!rosidl_runtime_c__uint64__Sequence__init(&ros_message->uint64_values, size)) {
      fprintf(stderr, "failed to create array for field 'uint64_values'");
      return false;
    }
    auto array_ptr = ros_message->uint64_values.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: basic_types_values
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

    if (ros_message->basic_types_values.data) {
      test_msgs__msg__BasicTypes__Sequence__fini(&ros_message->basic_types_values);
    }
    if (!test_msgs__msg__BasicTypes__Sequence__init(&ros_message->basic_types_values, size)) {
      fprintf(stderr, "failed to create array for field 'basic_types_values'");
      return false;
    }
    auto array_ptr = ros_message->basic_types_values.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_test_msgs__msg__BasicTypes(cdr, &array_ptr[i]);
    }
  }

  // Field name: constants_values
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

    if (ros_message->constants_values.data) {
      test_msgs__msg__Constants__Sequence__fini(&ros_message->constants_values);
    }
    if (!test_msgs__msg__Constants__Sequence__init(&ros_message->constants_values, size)) {
      fprintf(stderr, "failed to create array for field 'constants_values'");
      return false;
    }
    auto array_ptr = ros_message->constants_values.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_test_msgs__msg__Constants(cdr, &array_ptr[i]);
    }
  }

  // Field name: defaults_values
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

    if (ros_message->defaults_values.data) {
      test_msgs__msg__Defaults__Sequence__fini(&ros_message->defaults_values);
    }
    if (!test_msgs__msg__Defaults__Sequence__init(&ros_message->defaults_values, size)) {
      fprintf(stderr, "failed to create array for field 'defaults_values'");
      return false;
    }
    auto array_ptr = ros_message->defaults_values.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_test_msgs__msg__Defaults(cdr, &array_ptr[i]);
    }
  }

  // Field name: bool_values_default
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

    if (ros_message->bool_values_default.data) {
      rosidl_runtime_c__boolean__Sequence__fini(&ros_message->bool_values_default);
    }
    if (!rosidl_runtime_c__boolean__Sequence__init(&ros_message->bool_values_default, size)) {
      fprintf(stderr, "failed to create array for field 'bool_values_default'");
      return false;
    }
    auto array_ptr = ros_message->bool_values_default.data;
    for (size_t i = 0; i < size; ++i) {
      uint8_t tmp;
      cdr >> tmp;
      array_ptr[i] = tmp ? true : false;
    }
  }

  // Field name: byte_values_default
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

    if (ros_message->byte_values_default.data) {
      rosidl_runtime_c__octet__Sequence__fini(&ros_message->byte_values_default);
    }
    if (!rosidl_runtime_c__octet__Sequence__init(&ros_message->byte_values_default, size)) {
      fprintf(stderr, "failed to create array for field 'byte_values_default'");
      return false;
    }
    auto array_ptr = ros_message->byte_values_default.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: char_values_default
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

    if (ros_message->char_values_default.data) {
      rosidl_runtime_c__uint8__Sequence__fini(&ros_message->char_values_default);
    }
    if (!rosidl_runtime_c__uint8__Sequence__init(&ros_message->char_values_default, size)) {
      fprintf(stderr, "failed to create array for field 'char_values_default'");
      return false;
    }
    auto array_ptr = ros_message->char_values_default.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: float32_values_default
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

    if (ros_message->float32_values_default.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->float32_values_default);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->float32_values_default, size)) {
      fprintf(stderr, "failed to create array for field 'float32_values_default'");
      return false;
    }
    auto array_ptr = ros_message->float32_values_default.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: float64_values_default
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

    if (ros_message->float64_values_default.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->float64_values_default);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->float64_values_default, size)) {
      fprintf(stderr, "failed to create array for field 'float64_values_default'");
      return false;
    }
    auto array_ptr = ros_message->float64_values_default.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: int8_values_default
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

    if (ros_message->int8_values_default.data) {
      rosidl_runtime_c__int8__Sequence__fini(&ros_message->int8_values_default);
    }
    if (!rosidl_runtime_c__int8__Sequence__init(&ros_message->int8_values_default, size)) {
      fprintf(stderr, "failed to create array for field 'int8_values_default'");
      return false;
    }
    auto array_ptr = ros_message->int8_values_default.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: uint8_values_default
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

    if (ros_message->uint8_values_default.data) {
      rosidl_runtime_c__uint8__Sequence__fini(&ros_message->uint8_values_default);
    }
    if (!rosidl_runtime_c__uint8__Sequence__init(&ros_message->uint8_values_default, size)) {
      fprintf(stderr, "failed to create array for field 'uint8_values_default'");
      return false;
    }
    auto array_ptr = ros_message->uint8_values_default.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: int16_values_default
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

    if (ros_message->int16_values_default.data) {
      rosidl_runtime_c__int16__Sequence__fini(&ros_message->int16_values_default);
    }
    if (!rosidl_runtime_c__int16__Sequence__init(&ros_message->int16_values_default, size)) {
      fprintf(stderr, "failed to create array for field 'int16_values_default'");
      return false;
    }
    auto array_ptr = ros_message->int16_values_default.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: uint16_values_default
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

    if (ros_message->uint16_values_default.data) {
      rosidl_runtime_c__uint16__Sequence__fini(&ros_message->uint16_values_default);
    }
    if (!rosidl_runtime_c__uint16__Sequence__init(&ros_message->uint16_values_default, size)) {
      fprintf(stderr, "failed to create array for field 'uint16_values_default'");
      return false;
    }
    auto array_ptr = ros_message->uint16_values_default.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: int32_values_default
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

    if (ros_message->int32_values_default.data) {
      rosidl_runtime_c__int32__Sequence__fini(&ros_message->int32_values_default);
    }
    if (!rosidl_runtime_c__int32__Sequence__init(&ros_message->int32_values_default, size)) {
      fprintf(stderr, "failed to create array for field 'int32_values_default'");
      return false;
    }
    auto array_ptr = ros_message->int32_values_default.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: uint32_values_default
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

    if (ros_message->uint32_values_default.data) {
      rosidl_runtime_c__uint32__Sequence__fini(&ros_message->uint32_values_default);
    }
    if (!rosidl_runtime_c__uint32__Sequence__init(&ros_message->uint32_values_default, size)) {
      fprintf(stderr, "failed to create array for field 'uint32_values_default'");
      return false;
    }
    auto array_ptr = ros_message->uint32_values_default.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: int64_values_default
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

    if (ros_message->int64_values_default.data) {
      rosidl_runtime_c__int64__Sequence__fini(&ros_message->int64_values_default);
    }
    if (!rosidl_runtime_c__int64__Sequence__init(&ros_message->int64_values_default, size)) {
      fprintf(stderr, "failed to create array for field 'int64_values_default'");
      return false;
    }
    auto array_ptr = ros_message->int64_values_default.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: uint64_values_default
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

    if (ros_message->uint64_values_default.data) {
      rosidl_runtime_c__uint64__Sequence__fini(&ros_message->uint64_values_default);
    }
    if (!rosidl_runtime_c__uint64__Sequence__init(&ros_message->uint64_values_default, size)) {
      fprintf(stderr, "failed to create array for field 'uint64_values_default'");
      return false;
    }
    auto array_ptr = ros_message->uint64_values_default.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: alignment_check
  {
    cdr >> ros_message->alignment_check;
  }

  return true;
}  // NOLINT(readability/fn_size)


inline
size_t impl_get_serialized_size_test_msgs__msg__BoundedPlainSequences(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _BoundedPlainSequences__ros_msg_type * ros_message = static_cast<const _BoundedPlainSequences__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: bool_values
  {
    size_t array_size = ros_message->bool_values.size;
    auto array_ptr = ros_message->bool_values.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: byte_values
  {
    size_t array_size = ros_message->byte_values.size;
    auto array_ptr = ros_message->byte_values.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: char_values
  {
    size_t array_size = ros_message->char_values.size;
    auto array_ptr = ros_message->char_values.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: float32_values
  {
    size_t array_size = ros_message->float32_values.size;
    auto array_ptr = ros_message->float32_values.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: float64_values
  {
    size_t array_size = ros_message->float64_values.size;
    auto array_ptr = ros_message->float64_values.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: int8_values
  {
    size_t array_size = ros_message->int8_values.size;
    auto array_ptr = ros_message->int8_values.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: uint8_values
  {
    size_t array_size = ros_message->uint8_values.size;
    auto array_ptr = ros_message->uint8_values.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: int16_values
  {
    size_t array_size = ros_message->int16_values.size;
    auto array_ptr = ros_message->int16_values.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: uint16_values
  {
    size_t array_size = ros_message->uint16_values.size;
    auto array_ptr = ros_message->uint16_values.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: int32_values
  {
    size_t array_size = ros_message->int32_values.size;
    auto array_ptr = ros_message->int32_values.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: uint32_values
  {
    size_t array_size = ros_message->uint32_values.size;
    auto array_ptr = ros_message->uint32_values.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: int64_values
  {
    size_t array_size = ros_message->int64_values.size;
    auto array_ptr = ros_message->int64_values.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: uint64_values
  {
    size_t array_size = ros_message->uint64_values.size;
    auto array_ptr = ros_message->uint64_values.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: basic_types_values
  {
    size_t array_size = ros_message->basic_types_values.size;
    auto array_ptr = ros_message->basic_types_values.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_test_msgs__msg__BasicTypes(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: constants_values
  {
    size_t array_size = ros_message->constants_values.size;
    auto array_ptr = ros_message->constants_values.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_test_msgs__msg__Constants(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: defaults_values
  {
    size_t array_size = ros_message->defaults_values.size;
    auto array_ptr = ros_message->defaults_values.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_test_msgs__msg__Defaults(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: bool_values_default
  {
    size_t array_size = ros_message->bool_values_default.size;
    auto array_ptr = ros_message->bool_values_default.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: byte_values_default
  {
    size_t array_size = ros_message->byte_values_default.size;
    auto array_ptr = ros_message->byte_values_default.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: char_values_default
  {
    size_t array_size = ros_message->char_values_default.size;
    auto array_ptr = ros_message->char_values_default.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: float32_values_default
  {
    size_t array_size = ros_message->float32_values_default.size;
    auto array_ptr = ros_message->float32_values_default.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: float64_values_default
  {
    size_t array_size = ros_message->float64_values_default.size;
    auto array_ptr = ros_message->float64_values_default.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: int8_values_default
  {
    size_t array_size = ros_message->int8_values_default.size;
    auto array_ptr = ros_message->int8_values_default.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: uint8_values_default
  {
    size_t array_size = ros_message->uint8_values_default.size;
    auto array_ptr = ros_message->uint8_values_default.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: int16_values_default
  {
    size_t array_size = ros_message->int16_values_default.size;
    auto array_ptr = ros_message->int16_values_default.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: uint16_values_default
  {
    size_t array_size = ros_message->uint16_values_default.size;
    auto array_ptr = ros_message->uint16_values_default.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: int32_values_default
  {
    size_t array_size = ros_message->int32_values_default.size;
    auto array_ptr = ros_message->int32_values_default.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: uint32_values_default
  {
    size_t array_size = ros_message->uint32_values_default.size;
    auto array_ptr = ros_message->uint32_values_default.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: int64_values_default
  {
    size_t array_size = ros_message->int64_values_default.size;
    auto array_ptr = ros_message->int64_values_default.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: uint64_values_default
  {
    size_t array_size = ros_message->uint64_values_default.size;
    auto array_ptr = ros_message->uint64_values_default.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: alignment_check
  {
    size_t item_size = sizeof(ros_message->alignment_check);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


inline
size_t impl_max_serialized_size_test_msgs__msg__BoundedPlainSequences(
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

  // Field name: bool_values
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: byte_values
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: char_values
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: float32_values
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: float64_values
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: int8_values
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: uint8_values
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: int16_values
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: uint16_values
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: int32_values
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: uint32_values
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: int64_values
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: uint64_values
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: basic_types_values
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
        impl_max_serialized_size_test_msgs__msg__BasicTypes(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: constants_values
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
        impl_max_serialized_size_test_msgs__msg__Constants(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: defaults_values
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
        impl_max_serialized_size_test_msgs__msg__Defaults(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: bool_values_default
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: byte_values_default
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: char_values_default
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: float32_values_default
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: float64_values_default
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: int8_values_default
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: uint8_values_default
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: int16_values_default
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: uint16_values_default
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: int32_values_default
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: uint32_values_default
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: int64_values_default
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: uint64_values_default
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: alignment_check
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
    using DataType = test_msgs__msg__BoundedPlainSequences;
    is_plain =
      (
      offsetof(DataType, alignment_check) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_key_test_msgs__msg__BoundedPlainSequences(
  const test_msgs__msg__BoundedPlainSequences * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: bool_values
  {
    size_t size = ros_message->bool_values.size;
    auto array_ptr = ros_message->bool_values.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: byte_values
  {
    size_t size = ros_message->byte_values.size;
    auto array_ptr = ros_message->byte_values.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: char_values
  {
    size_t size = ros_message->char_values.size;
    auto array_ptr = ros_message->char_values.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: float32_values
  {
    size_t size = ros_message->float32_values.size;
    auto array_ptr = ros_message->float32_values.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: float64_values
  {
    size_t size = ros_message->float64_values.size;
    auto array_ptr = ros_message->float64_values.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int8_values
  {
    size_t size = ros_message->int8_values.size;
    auto array_ptr = ros_message->int8_values.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint8_values
  {
    size_t size = ros_message->uint8_values.size;
    auto array_ptr = ros_message->uint8_values.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int16_values
  {
    size_t size = ros_message->int16_values.size;
    auto array_ptr = ros_message->int16_values.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint16_values
  {
    size_t size = ros_message->uint16_values.size;
    auto array_ptr = ros_message->uint16_values.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int32_values
  {
    size_t size = ros_message->int32_values.size;
    auto array_ptr = ros_message->int32_values.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint32_values
  {
    size_t size = ros_message->uint32_values.size;
    auto array_ptr = ros_message->uint32_values.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int64_values
  {
    size_t size = ros_message->int64_values.size;
    auto array_ptr = ros_message->int64_values.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint64_values
  {
    size_t size = ros_message->uint64_values.size;
    auto array_ptr = ros_message->uint64_values.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: basic_types_values
  {
    size_t size = ros_message->basic_types_values.size;
    auto array_ptr = ros_message->basic_types_values.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_key_test_msgs__msg__BasicTypes(
        &array_ptr[i], cdr);
    }
  }

  // Field name: constants_values
  {
    size_t size = ros_message->constants_values.size;
    auto array_ptr = ros_message->constants_values.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_key_test_msgs__msg__Constants(
        &array_ptr[i], cdr);
    }
  }

  // Field name: defaults_values
  {
    size_t size = ros_message->defaults_values.size;
    auto array_ptr = ros_message->defaults_values.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_key_test_msgs__msg__Defaults(
        &array_ptr[i], cdr);
    }
  }

  // Field name: bool_values_default
  {
    size_t size = ros_message->bool_values_default.size;
    auto array_ptr = ros_message->bool_values_default.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: byte_values_default
  {
    size_t size = ros_message->byte_values_default.size;
    auto array_ptr = ros_message->byte_values_default.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: char_values_default
  {
    size_t size = ros_message->char_values_default.size;
    auto array_ptr = ros_message->char_values_default.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: float32_values_default
  {
    size_t size = ros_message->float32_values_default.size;
    auto array_ptr = ros_message->float32_values_default.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: float64_values_default
  {
    size_t size = ros_message->float64_values_default.size;
    auto array_ptr = ros_message->float64_values_default.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int8_values_default
  {
    size_t size = ros_message->int8_values_default.size;
    auto array_ptr = ros_message->int8_values_default.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint8_values_default
  {
    size_t size = ros_message->uint8_values_default.size;
    auto array_ptr = ros_message->uint8_values_default.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int16_values_default
  {
    size_t size = ros_message->int16_values_default.size;
    auto array_ptr = ros_message->int16_values_default.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint16_values_default
  {
    size_t size = ros_message->uint16_values_default.size;
    auto array_ptr = ros_message->uint16_values_default.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int32_values_default
  {
    size_t size = ros_message->int32_values_default.size;
    auto array_ptr = ros_message->int32_values_default.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint32_values_default
  {
    size_t size = ros_message->uint32_values_default.size;
    auto array_ptr = ros_message->uint32_values_default.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int64_values_default
  {
    size_t size = ros_message->int64_values_default.size;
    auto array_ptr = ros_message->int64_values_default.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint64_values_default
  {
    size_t size = ros_message->uint64_values_default.size;
    auto array_ptr = ros_message->uint64_values_default.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: alignment_check
  {
    cdr << ros_message->alignment_check;
  }

  return true;
}

inline
size_t impl_get_serialized_size_key_test_msgs__msg__BoundedPlainSequences(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _BoundedPlainSequences__ros_msg_type * ros_message = static_cast<const _BoundedPlainSequences__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: bool_values
  {
    size_t array_size = ros_message->bool_values.size;
    auto array_ptr = ros_message->bool_values.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: byte_values
  {
    size_t array_size = ros_message->byte_values.size;
    auto array_ptr = ros_message->byte_values.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: char_values
  {
    size_t array_size = ros_message->char_values.size;
    auto array_ptr = ros_message->char_values.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: float32_values
  {
    size_t array_size = ros_message->float32_values.size;
    auto array_ptr = ros_message->float32_values.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: float64_values
  {
    size_t array_size = ros_message->float64_values.size;
    auto array_ptr = ros_message->float64_values.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: int8_values
  {
    size_t array_size = ros_message->int8_values.size;
    auto array_ptr = ros_message->int8_values.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: uint8_values
  {
    size_t array_size = ros_message->uint8_values.size;
    auto array_ptr = ros_message->uint8_values.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: int16_values
  {
    size_t array_size = ros_message->int16_values.size;
    auto array_ptr = ros_message->int16_values.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: uint16_values
  {
    size_t array_size = ros_message->uint16_values.size;
    auto array_ptr = ros_message->uint16_values.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: int32_values
  {
    size_t array_size = ros_message->int32_values.size;
    auto array_ptr = ros_message->int32_values.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: uint32_values
  {
    size_t array_size = ros_message->uint32_values.size;
    auto array_ptr = ros_message->uint32_values.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: int64_values
  {
    size_t array_size = ros_message->int64_values.size;
    auto array_ptr = ros_message->int64_values.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: uint64_values
  {
    size_t array_size = ros_message->uint64_values.size;
    auto array_ptr = ros_message->uint64_values.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: basic_types_values
  {
    size_t array_size = ros_message->basic_types_values.size;
    auto array_ptr = ros_message->basic_types_values.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_key_test_msgs__msg__BasicTypes(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: constants_values
  {
    size_t array_size = ros_message->constants_values.size;
    auto array_ptr = ros_message->constants_values.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_key_test_msgs__msg__Constants(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: defaults_values
  {
    size_t array_size = ros_message->defaults_values.size;
    auto array_ptr = ros_message->defaults_values.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_key_test_msgs__msg__Defaults(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: bool_values_default
  {
    size_t array_size = ros_message->bool_values_default.size;
    auto array_ptr = ros_message->bool_values_default.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: byte_values_default
  {
    size_t array_size = ros_message->byte_values_default.size;
    auto array_ptr = ros_message->byte_values_default.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: char_values_default
  {
    size_t array_size = ros_message->char_values_default.size;
    auto array_ptr = ros_message->char_values_default.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: float32_values_default
  {
    size_t array_size = ros_message->float32_values_default.size;
    auto array_ptr = ros_message->float32_values_default.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: float64_values_default
  {
    size_t array_size = ros_message->float64_values_default.size;
    auto array_ptr = ros_message->float64_values_default.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: int8_values_default
  {
    size_t array_size = ros_message->int8_values_default.size;
    auto array_ptr = ros_message->int8_values_default.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: uint8_values_default
  {
    size_t array_size = ros_message->uint8_values_default.size;
    auto array_ptr = ros_message->uint8_values_default.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: int16_values_default
  {
    size_t array_size = ros_message->int16_values_default.size;
    auto array_ptr = ros_message->int16_values_default.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: uint16_values_default
  {
    size_t array_size = ros_message->uint16_values_default.size;
    auto array_ptr = ros_message->uint16_values_default.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: int32_values_default
  {
    size_t array_size = ros_message->int32_values_default.size;
    auto array_ptr = ros_message->int32_values_default.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: uint32_values_default
  {
    size_t array_size = ros_message->uint32_values_default.size;
    auto array_ptr = ros_message->uint32_values_default.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: int64_values_default
  {
    size_t array_size = ros_message->int64_values_default.size;
    auto array_ptr = ros_message->int64_values_default.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: uint64_values_default
  {
    size_t array_size = ros_message->uint64_values_default.size;
    auto array_ptr = ros_message->uint64_values_default.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: alignment_check
  {
    size_t item_size = sizeof(ros_message->alignment_check);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

inline
size_t impl_max_serialized_size_key_test_msgs__msg__BoundedPlainSequences(
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
  // Field name: bool_values
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: byte_values
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: char_values
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: float32_values
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: float64_values
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: int8_values
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: uint8_values
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: int16_values
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: uint16_values
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: int32_values
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: uint32_values
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: int64_values
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: uint64_values
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: basic_types_values
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
        impl_max_serialized_size_key_test_msgs__msg__BasicTypes(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: constants_values
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
        impl_max_serialized_size_key_test_msgs__msg__Constants(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: defaults_values
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
        impl_max_serialized_size_key_test_msgs__msg__Defaults(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: bool_values_default
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: byte_values_default
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: char_values_default
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: float32_values_default
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: float64_values_default
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: int8_values_default
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: uint8_values_default
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: int16_values_default
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: uint16_values_default
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: int32_values_default
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: uint32_values_default
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: int64_values_default
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: uint64_values_default
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: alignment_check
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
    using DataType = test_msgs__msg__BoundedPlainSequences;
    is_plain =
      (
      offsetof(DataType, alignment_check) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_with_endpoint_test_msgs__msg__BoundedPlainSequences(
  const test_msgs__msg__BoundedPlainSequences * ros_message,
  eprosima::fastcdr::Cdr & cdr,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: bool_values
  {
    size_t size = ros_message->bool_values.size;
    auto array_ptr = ros_message->bool_values.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: byte_values
  {
    size_t size = ros_message->byte_values.size;
    auto array_ptr = ros_message->byte_values.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: char_values
  {
    size_t size = ros_message->char_values.size;
    auto array_ptr = ros_message->char_values.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: float32_values
  {
    size_t size = ros_message->float32_values.size;
    auto array_ptr = ros_message->float32_values.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: float64_values
  {
    size_t size = ros_message->float64_values.size;
    auto array_ptr = ros_message->float64_values.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int8_values
  {
    size_t size = ros_message->int8_values.size;
    auto array_ptr = ros_message->int8_values.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint8_values
  {
    size_t size = ros_message->uint8_values.size;
    auto array_ptr = ros_message->uint8_values.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int16_values
  {
    size_t size = ros_message->int16_values.size;
    auto array_ptr = ros_message->int16_values.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint16_values
  {
    size_t size = ros_message->uint16_values.size;
    auto array_ptr = ros_message->uint16_values.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int32_values
  {
    size_t size = ros_message->int32_values.size;
    auto array_ptr = ros_message->int32_values.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint32_values
  {
    size_t size = ros_message->uint32_values.size;
    auto array_ptr = ros_message->uint32_values.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int64_values
  {
    size_t size = ros_message->int64_values.size;
    auto array_ptr = ros_message->int64_values.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint64_values
  {
    size_t size = ros_message->uint64_values.size;
    auto array_ptr = ros_message->uint64_values.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: basic_types_values
  {
    size_t size = ros_message->basic_types_values.size;
    auto array_ptr = ros_message->basic_types_values.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_with_endpoint_test_msgs__msg__BasicTypes(
        &array_ptr[i], cdr, endpoint_info, serialization_context);
    }
  }

  // Field name: constants_values
  {
    size_t size = ros_message->constants_values.size;
    auto array_ptr = ros_message->constants_values.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_with_endpoint_test_msgs__msg__Constants(
        &array_ptr[i], cdr, endpoint_info, serialization_context);
    }
  }

  // Field name: defaults_values
  {
    size_t size = ros_message->defaults_values.size;
    auto array_ptr = ros_message->defaults_values.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_with_endpoint_test_msgs__msg__Defaults(
        &array_ptr[i], cdr, endpoint_info, serialization_context);
    }
  }

  // Field name: bool_values_default
  {
    size_t size = ros_message->bool_values_default.size;
    auto array_ptr = ros_message->bool_values_default.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: byte_values_default
  {
    size_t size = ros_message->byte_values_default.size;
    auto array_ptr = ros_message->byte_values_default.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: char_values_default
  {
    size_t size = ros_message->char_values_default.size;
    auto array_ptr = ros_message->char_values_default.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: float32_values_default
  {
    size_t size = ros_message->float32_values_default.size;
    auto array_ptr = ros_message->float32_values_default.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: float64_values_default
  {
    size_t size = ros_message->float64_values_default.size;
    auto array_ptr = ros_message->float64_values_default.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int8_values_default
  {
    size_t size = ros_message->int8_values_default.size;
    auto array_ptr = ros_message->int8_values_default.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint8_values_default
  {
    size_t size = ros_message->uint8_values_default.size;
    auto array_ptr = ros_message->uint8_values_default.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int16_values_default
  {
    size_t size = ros_message->int16_values_default.size;
    auto array_ptr = ros_message->int16_values_default.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint16_values_default
  {
    size_t size = ros_message->uint16_values_default.size;
    auto array_ptr = ros_message->uint16_values_default.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int32_values_default
  {
    size_t size = ros_message->int32_values_default.size;
    auto array_ptr = ros_message->int32_values_default.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint32_values_default
  {
    size_t size = ros_message->uint32_values_default.size;
    auto array_ptr = ros_message->uint32_values_default.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int64_values_default
  {
    size_t size = ros_message->int64_values_default.size;
    auto array_ptr = ros_message->int64_values_default.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint64_values_default
  {
    size_t size = ros_message->uint64_values_default.size;
    auto array_ptr = ros_message->uint64_values_default.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: alignment_check
  {
    cdr << ros_message->alignment_check;
  }

  return true;
}

inline
bool impl_cdr_deserialize_with_endpoint_test_msgs__msg__BoundedPlainSequences(
  eprosima::fastcdr::Cdr & cdr,
  test_msgs__msg__BoundedPlainSequences * ros_message,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: bool_values
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

    if (ros_message->bool_values.data) {
      rosidl_runtime_c__boolean__Sequence__fini(&ros_message->bool_values);
    }
    if (!rosidl_runtime_c__boolean__Sequence__init(&ros_message->bool_values, size)) {
      fprintf(stderr, "failed to create array for field 'bool_values'");
      return false;
    }
    auto array_ptr = ros_message->bool_values.data;
    for (size_t i = 0; i < size; ++i) {
      uint8_t tmp;
      cdr >> tmp;
      array_ptr[i] = tmp ? true : false;
    }
  }

  // Field name: byte_values
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

    if (ros_message->byte_values.data) {
      rosidl_runtime_c__octet__Sequence__fini(&ros_message->byte_values);
    }
    if (!rosidl_runtime_c__octet__Sequence__init(&ros_message->byte_values, size)) {
      fprintf(stderr, "failed to create array for field 'byte_values'");
      return false;
    }
    auto array_ptr = ros_message->byte_values.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: char_values
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

    if (ros_message->char_values.data) {
      rosidl_runtime_c__uint8__Sequence__fini(&ros_message->char_values);
    }
    if (!rosidl_runtime_c__uint8__Sequence__init(&ros_message->char_values, size)) {
      fprintf(stderr, "failed to create array for field 'char_values'");
      return false;
    }
    auto array_ptr = ros_message->char_values.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: float32_values
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

    if (ros_message->float32_values.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->float32_values);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->float32_values, size)) {
      fprintf(stderr, "failed to create array for field 'float32_values'");
      return false;
    }
    auto array_ptr = ros_message->float32_values.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: float64_values
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

    if (ros_message->float64_values.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->float64_values);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->float64_values, size)) {
      fprintf(stderr, "failed to create array for field 'float64_values'");
      return false;
    }
    auto array_ptr = ros_message->float64_values.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: int8_values
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

    if (ros_message->int8_values.data) {
      rosidl_runtime_c__int8__Sequence__fini(&ros_message->int8_values);
    }
    if (!rosidl_runtime_c__int8__Sequence__init(&ros_message->int8_values, size)) {
      fprintf(stderr, "failed to create array for field 'int8_values'");
      return false;
    }
    auto array_ptr = ros_message->int8_values.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: uint8_values
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

    if (ros_message->uint8_values.data) {
      rosidl_runtime_c__uint8__Sequence__fini(&ros_message->uint8_values);
    }
    if (!rosidl_runtime_c__uint8__Sequence__init(&ros_message->uint8_values, size)) {
      fprintf(stderr, "failed to create array for field 'uint8_values'");
      return false;
    }
    auto array_ptr = ros_message->uint8_values.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: int16_values
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

    if (ros_message->int16_values.data) {
      rosidl_runtime_c__int16__Sequence__fini(&ros_message->int16_values);
    }
    if (!rosidl_runtime_c__int16__Sequence__init(&ros_message->int16_values, size)) {
      fprintf(stderr, "failed to create array for field 'int16_values'");
      return false;
    }
    auto array_ptr = ros_message->int16_values.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: uint16_values
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

    if (ros_message->uint16_values.data) {
      rosidl_runtime_c__uint16__Sequence__fini(&ros_message->uint16_values);
    }
    if (!rosidl_runtime_c__uint16__Sequence__init(&ros_message->uint16_values, size)) {
      fprintf(stderr, "failed to create array for field 'uint16_values'");
      return false;
    }
    auto array_ptr = ros_message->uint16_values.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: int32_values
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

    if (ros_message->int32_values.data) {
      rosidl_runtime_c__int32__Sequence__fini(&ros_message->int32_values);
    }
    if (!rosidl_runtime_c__int32__Sequence__init(&ros_message->int32_values, size)) {
      fprintf(stderr, "failed to create array for field 'int32_values'");
      return false;
    }
    auto array_ptr = ros_message->int32_values.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: uint32_values
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

    if (ros_message->uint32_values.data) {
      rosidl_runtime_c__uint32__Sequence__fini(&ros_message->uint32_values);
    }
    if (!rosidl_runtime_c__uint32__Sequence__init(&ros_message->uint32_values, size)) {
      fprintf(stderr, "failed to create array for field 'uint32_values'");
      return false;
    }
    auto array_ptr = ros_message->uint32_values.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: int64_values
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

    if (ros_message->int64_values.data) {
      rosidl_runtime_c__int64__Sequence__fini(&ros_message->int64_values);
    }
    if (!rosidl_runtime_c__int64__Sequence__init(&ros_message->int64_values, size)) {
      fprintf(stderr, "failed to create array for field 'int64_values'");
      return false;
    }
    auto array_ptr = ros_message->int64_values.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: uint64_values
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

    if (ros_message->uint64_values.data) {
      rosidl_runtime_c__uint64__Sequence__fini(&ros_message->uint64_values);
    }
    if (!rosidl_runtime_c__uint64__Sequence__init(&ros_message->uint64_values, size)) {
      fprintf(stderr, "failed to create array for field 'uint64_values'");
      return false;
    }
    auto array_ptr = ros_message->uint64_values.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: basic_types_values
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

    if (ros_message->basic_types_values.data) {
      test_msgs__msg__BasicTypes__Sequence__fini(&ros_message->basic_types_values);
    }
    if (!test_msgs__msg__BasicTypes__Sequence__init(&ros_message->basic_types_values, size)) {
      fprintf(stderr, "failed to create array for field 'basic_types_values'");
      return false;
    }
    auto array_ptr = ros_message->basic_types_values.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_with_endpoint_test_msgs__msg__BasicTypes(cdr, &array_ptr[i], endpoint_info, serialization_context);
    }
  }

  // Field name: constants_values
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

    if (ros_message->constants_values.data) {
      test_msgs__msg__Constants__Sequence__fini(&ros_message->constants_values);
    }
    if (!test_msgs__msg__Constants__Sequence__init(&ros_message->constants_values, size)) {
      fprintf(stderr, "failed to create array for field 'constants_values'");
      return false;
    }
    auto array_ptr = ros_message->constants_values.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_with_endpoint_test_msgs__msg__Constants(cdr, &array_ptr[i], endpoint_info, serialization_context);
    }
  }

  // Field name: defaults_values
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

    if (ros_message->defaults_values.data) {
      test_msgs__msg__Defaults__Sequence__fini(&ros_message->defaults_values);
    }
    if (!test_msgs__msg__Defaults__Sequence__init(&ros_message->defaults_values, size)) {
      fprintf(stderr, "failed to create array for field 'defaults_values'");
      return false;
    }
    auto array_ptr = ros_message->defaults_values.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_with_endpoint_test_msgs__msg__Defaults(cdr, &array_ptr[i], endpoint_info, serialization_context);
    }
  }

  // Field name: bool_values_default
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

    if (ros_message->bool_values_default.data) {
      rosidl_runtime_c__boolean__Sequence__fini(&ros_message->bool_values_default);
    }
    if (!rosidl_runtime_c__boolean__Sequence__init(&ros_message->bool_values_default, size)) {
      fprintf(stderr, "failed to create array for field 'bool_values_default'");
      return false;
    }
    auto array_ptr = ros_message->bool_values_default.data;
    for (size_t i = 0; i < size; ++i) {
      uint8_t tmp;
      cdr >> tmp;
      array_ptr[i] = tmp ? true : false;
    }
  }

  // Field name: byte_values_default
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

    if (ros_message->byte_values_default.data) {
      rosidl_runtime_c__octet__Sequence__fini(&ros_message->byte_values_default);
    }
    if (!rosidl_runtime_c__octet__Sequence__init(&ros_message->byte_values_default, size)) {
      fprintf(stderr, "failed to create array for field 'byte_values_default'");
      return false;
    }
    auto array_ptr = ros_message->byte_values_default.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: char_values_default
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

    if (ros_message->char_values_default.data) {
      rosidl_runtime_c__uint8__Sequence__fini(&ros_message->char_values_default);
    }
    if (!rosidl_runtime_c__uint8__Sequence__init(&ros_message->char_values_default, size)) {
      fprintf(stderr, "failed to create array for field 'char_values_default'");
      return false;
    }
    auto array_ptr = ros_message->char_values_default.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: float32_values_default
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

    if (ros_message->float32_values_default.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->float32_values_default);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->float32_values_default, size)) {
      fprintf(stderr, "failed to create array for field 'float32_values_default'");
      return false;
    }
    auto array_ptr = ros_message->float32_values_default.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: float64_values_default
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

    if (ros_message->float64_values_default.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->float64_values_default);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->float64_values_default, size)) {
      fprintf(stderr, "failed to create array for field 'float64_values_default'");
      return false;
    }
    auto array_ptr = ros_message->float64_values_default.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: int8_values_default
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

    if (ros_message->int8_values_default.data) {
      rosidl_runtime_c__int8__Sequence__fini(&ros_message->int8_values_default);
    }
    if (!rosidl_runtime_c__int8__Sequence__init(&ros_message->int8_values_default, size)) {
      fprintf(stderr, "failed to create array for field 'int8_values_default'");
      return false;
    }
    auto array_ptr = ros_message->int8_values_default.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: uint8_values_default
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

    if (ros_message->uint8_values_default.data) {
      rosidl_runtime_c__uint8__Sequence__fini(&ros_message->uint8_values_default);
    }
    if (!rosidl_runtime_c__uint8__Sequence__init(&ros_message->uint8_values_default, size)) {
      fprintf(stderr, "failed to create array for field 'uint8_values_default'");
      return false;
    }
    auto array_ptr = ros_message->uint8_values_default.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: int16_values_default
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

    if (ros_message->int16_values_default.data) {
      rosidl_runtime_c__int16__Sequence__fini(&ros_message->int16_values_default);
    }
    if (!rosidl_runtime_c__int16__Sequence__init(&ros_message->int16_values_default, size)) {
      fprintf(stderr, "failed to create array for field 'int16_values_default'");
      return false;
    }
    auto array_ptr = ros_message->int16_values_default.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: uint16_values_default
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

    if (ros_message->uint16_values_default.data) {
      rosidl_runtime_c__uint16__Sequence__fini(&ros_message->uint16_values_default);
    }
    if (!rosidl_runtime_c__uint16__Sequence__init(&ros_message->uint16_values_default, size)) {
      fprintf(stderr, "failed to create array for field 'uint16_values_default'");
      return false;
    }
    auto array_ptr = ros_message->uint16_values_default.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: int32_values_default
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

    if (ros_message->int32_values_default.data) {
      rosidl_runtime_c__int32__Sequence__fini(&ros_message->int32_values_default);
    }
    if (!rosidl_runtime_c__int32__Sequence__init(&ros_message->int32_values_default, size)) {
      fprintf(stderr, "failed to create array for field 'int32_values_default'");
      return false;
    }
    auto array_ptr = ros_message->int32_values_default.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: uint32_values_default
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

    if (ros_message->uint32_values_default.data) {
      rosidl_runtime_c__uint32__Sequence__fini(&ros_message->uint32_values_default);
    }
    if (!rosidl_runtime_c__uint32__Sequence__init(&ros_message->uint32_values_default, size)) {
      fprintf(stderr, "failed to create array for field 'uint32_values_default'");
      return false;
    }
    auto array_ptr = ros_message->uint32_values_default.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: int64_values_default
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

    if (ros_message->int64_values_default.data) {
      rosidl_runtime_c__int64__Sequence__fini(&ros_message->int64_values_default);
    }
    if (!rosidl_runtime_c__int64__Sequence__init(&ros_message->int64_values_default, size)) {
      fprintf(stderr, "failed to create array for field 'int64_values_default'");
      return false;
    }
    auto array_ptr = ros_message->int64_values_default.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: uint64_values_default
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

    if (ros_message->uint64_values_default.data) {
      rosidl_runtime_c__uint64__Sequence__fini(&ros_message->uint64_values_default);
    }
    if (!rosidl_runtime_c__uint64__Sequence__init(&ros_message->uint64_values_default, size)) {
      fprintf(stderr, "failed to create array for field 'uint64_values_default'");
      return false;
    }
    auto array_ptr = ros_message->uint64_values_default.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: alignment_check
  {
    cdr >> ros_message->alignment_check;
  }

  return true;
}  // NOLINT(readability/fn_size)

#if defined(__cplusplus)
}
#endif

#endif  // TEST_MSGS__MSG__DETAIL__BOUNDED_PLAIN_SEQUENCES__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
