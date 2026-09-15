// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from test_rosidl_buffer:msg\ByteArrayList.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "test_rosidl_buffer/msg/byte_array_list.h"


#ifndef TEST_ROSIDL_BUFFER__MSG__DETAIL__BYTE_ARRAY_LIST__STRUCT_H_
#define TEST_ROSIDL_BUFFER__MSG__DETAIL__BYTE_ARRAY_LIST__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'items'
#include "test_rosidl_buffer/msg/detail/byte_array__struct.h"

/// Struct defined in msg/ByteArrayList in the package test_rosidl_buffer.
/**
  * Minimal nested payload used by the pub/sub launch tests.
  * Each ByteArray item contains a uint8[] field generated as rosidl::Buffer<uint8_t>.
 */
typedef struct test_rosidl_buffer__msg__ByteArrayList
{
  test_rosidl_buffer__msg__ByteArray__Sequence items;
} test_rosidl_buffer__msg__ByteArrayList;

// Struct for a sequence of test_rosidl_buffer__msg__ByteArrayList.
typedef struct test_rosidl_buffer__msg__ByteArrayList__Sequence
{
  test_rosidl_buffer__msg__ByteArrayList * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} test_rosidl_buffer__msg__ByteArrayList__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TEST_ROSIDL_BUFFER__MSG__DETAIL__BYTE_ARRAY_LIST__STRUCT_H_
