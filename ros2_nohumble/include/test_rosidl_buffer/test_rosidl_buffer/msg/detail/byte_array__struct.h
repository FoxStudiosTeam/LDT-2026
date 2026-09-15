// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from test_rosidl_buffer:msg\ByteArray.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "test_rosidl_buffer/msg/byte_array.h"


#ifndef TEST_ROSIDL_BUFFER__MSG__DETAIL__BYTE_ARRAY__STRUCT_H_
#define TEST_ROSIDL_BUFFER__MSG__DETAIL__BYTE_ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'data'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/ByteArray in the package test_rosidl_buffer.
/**
  * Minimal payload message used by the pub/sub launch tests.
  * The `data` field is generated as rosidl::Buffer<uint8_t>, which is the
  * feature under test.
 */
typedef struct test_rosidl_buffer__msg__ByteArray
{
  uint32_t seq;
  rosidl_runtime_c__uint8__Sequence data;
} test_rosidl_buffer__msg__ByteArray;

// Struct for a sequence of test_rosidl_buffer__msg__ByteArray.
typedef struct test_rosidl_buffer__msg__ByteArray__Sequence
{
  test_rosidl_buffer__msg__ByteArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} test_rosidl_buffer__msg__ByteArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TEST_ROSIDL_BUFFER__MSG__DETAIL__BYTE_ARRAY__STRUCT_H_
