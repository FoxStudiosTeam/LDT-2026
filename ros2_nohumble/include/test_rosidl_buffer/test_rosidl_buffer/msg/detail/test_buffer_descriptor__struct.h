// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from test_rosidl_buffer:msg\TestBufferDescriptor.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "test_rosidl_buffer/msg/test_buffer_descriptor.h"


#ifndef TEST_ROSIDL_BUFFER__MSG__DETAIL__TEST_BUFFER_DESCRIPTOR__STRUCT_H_
#define TEST_ROSIDL_BUFFER__MSG__DETAIL__TEST_BUFFER_DESCRIPTOR__STRUCT_H_

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

/// Struct defined in msg/TestBufferDescriptor in the package test_rosidl_buffer.
/**
  * Wire descriptor used by the in-tree test buffer backend.
 */
typedef struct test_rosidl_buffer__msg__TestBufferDescriptor
{
  /// number of elements in the original buffer
  uint64_t size;
  /// FNV-1a hash of the element bytes
  uint64_t data_hash;
  /// raw element bytes (size * sizeof(T))
  rosidl_runtime_c__uint8__Sequence data;
} test_rosidl_buffer__msg__TestBufferDescriptor;

// Struct for a sequence of test_rosidl_buffer__msg__TestBufferDescriptor.
typedef struct test_rosidl_buffer__msg__TestBufferDescriptor__Sequence
{
  test_rosidl_buffer__msg__TestBufferDescriptor * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} test_rosidl_buffer__msg__TestBufferDescriptor__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TEST_ROSIDL_BUFFER__MSG__DETAIL__TEST_BUFFER_DESCRIPTOR__STRUCT_H_
