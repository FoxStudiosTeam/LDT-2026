// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from test_rosidl_buffer:msg\ByteArray.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "test_rosidl_buffer/msg/detail/byte_array__rosidl_typesupport_introspection_c.h"
#include "test_rosidl_buffer/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "test_rosidl_buffer/msg/detail/byte_array__functions.h"
#include "test_rosidl_buffer/msg/detail/byte_array__struct.h"
#include "rosidl_buffer/c_helpers.h"


// Include directives for member types
// Member `data`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void test_rosidl_buffer__msg__ByteArray__rosidl_typesupport_introspection_c__ByteArray_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  test_rosidl_buffer__msg__ByteArray__init(message_memory);
}

void test_rosidl_buffer__msg__ByteArray__rosidl_typesupport_introspection_c__ByteArray_fini_function(void * message_memory)
{
  test_rosidl_buffer__msg__ByteArray__fini(message_memory);
}

size_t test_rosidl_buffer__msg__ByteArray__rosidl_typesupport_introspection_c__size_function__ByteArray__data(
  const void * untyped_member)
{
  const rosidl_runtime_c__uint8__Sequence * member =
    (const rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  if (member->is_rosidl_buffer) {
    rosidl_buffer_uint8_throw_if_not_cpu((const void *)member->data);
  }
  return member->size;
}

const void * test_rosidl_buffer__msg__ByteArray__rosidl_typesupport_introspection_c__get_const_function__ByteArray__data(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__uint8__Sequence * member =
    (const rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  if (member->is_rosidl_buffer) {
    rosidl_buffer_uint8_throw_if_not_cpu((const void *)member->data);
  }
  return &member->data[index];
}

void * test_rosidl_buffer__msg__ByteArray__rosidl_typesupport_introspection_c__get_function__ByteArray__data(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__uint8__Sequence * member =
    (rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  if (member->is_rosidl_buffer) {
    rosidl_buffer_uint8_throw_if_not_cpu((const void *)member->data);
  }
  return &member->data[index];
}

void test_rosidl_buffer__msg__ByteArray__rosidl_typesupport_introspection_c__fetch_function__ByteArray__data(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint8_t * item =
    ((const uint8_t *)
    test_rosidl_buffer__msg__ByteArray__rosidl_typesupport_introspection_c__get_const_function__ByteArray__data(untyped_member, index));
  uint8_t * value = (uint8_t *)(untyped_value);
  *value = *item;
}

void test_rosidl_buffer__msg__ByteArray__rosidl_typesupport_introspection_c__assign_function__ByteArray__data(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint8_t * item =
    ((uint8_t *)
    test_rosidl_buffer__msg__ByteArray__rosidl_typesupport_introspection_c__get_function__ByteArray__data(untyped_member, index));
  const uint8_t * value = (const uint8_t *)(untyped_value);
  *item = *value;
}

bool test_rosidl_buffer__msg__ByteArray__rosidl_typesupport_introspection_c__resize_function__ByteArray__data(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__uint8__Sequence * member =
    (rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  if (member->is_rosidl_buffer) {
    rosidl_buffer_uint8_throw_if_not_cpu((const void *)member->data);
  }
  rosidl_runtime_c__uint8__Sequence__fini(member);
  return rosidl_runtime_c__uint8__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember test_rosidl_buffer__msg__ByteArray__rosidl_typesupport_introspection_c__ByteArray_message_member_array[2] = {
  {
    "seq",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(test_rosidl_buffer__msg__ByteArray, seq),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL,  // resize(index) function pointer
    false  // is_rosidl_buffer
  },
  {
    "data",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(test_rosidl_buffer__msg__ByteArray, data),  // bytes offset in struct
    NULL,  // default value
    test_rosidl_buffer__msg__ByteArray__rosidl_typesupport_introspection_c__size_function__ByteArray__data,  // size() function pointer
    test_rosidl_buffer__msg__ByteArray__rosidl_typesupport_introspection_c__get_const_function__ByteArray__data,  // get_const(index) function pointer
    test_rosidl_buffer__msg__ByteArray__rosidl_typesupport_introspection_c__get_function__ByteArray__data,  // get(index) function pointer
    test_rosidl_buffer__msg__ByteArray__rosidl_typesupport_introspection_c__fetch_function__ByteArray__data,  // fetch(index, &value) function pointer
    test_rosidl_buffer__msg__ByteArray__rosidl_typesupport_introspection_c__assign_function__ByteArray__data,  // assign(index, value) function pointer
    test_rosidl_buffer__msg__ByteArray__rosidl_typesupport_introspection_c__resize_function__ByteArray__data,  // resize(index) function pointer
    true  // is_rosidl_buffer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers test_rosidl_buffer__msg__ByteArray__rosidl_typesupport_introspection_c__ByteArray_message_members = {
  "test_rosidl_buffer__msg",  // message namespace
  "ByteArray",  // message name
  2,  // number of fields
  sizeof(test_rosidl_buffer__msg__ByteArray),
  false,  // has_any_key_member_
  test_rosidl_buffer__msg__ByteArray__rosidl_typesupport_introspection_c__ByteArray_message_member_array,  // message members
  test_rosidl_buffer__msg__ByteArray__rosidl_typesupport_introspection_c__ByteArray_init_function,  // function to initialize message memory (memory has to be allocated)
  test_rosidl_buffer__msg__ByteArray__rosidl_typesupport_introspection_c__ByteArray_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t test_rosidl_buffer__msg__ByteArray__rosidl_typesupport_introspection_c__ByteArray_message_type_support_handle = {
  0,
  &test_rosidl_buffer__msg__ByteArray__rosidl_typesupport_introspection_c__ByteArray_message_members,
  get_message_typesupport_handle_function,
  &test_rosidl_buffer__msg__ByteArray__get_type_hash,
  &test_rosidl_buffer__msg__ByteArray__get_type_description,
  &test_rosidl_buffer__msg__ByteArray__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_test_rosidl_buffer
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, test_rosidl_buffer, msg, ByteArray)() {
  if (!test_rosidl_buffer__msg__ByteArray__rosidl_typesupport_introspection_c__ByteArray_message_type_support_handle.typesupport_identifier) {
    test_rosidl_buffer__msg__ByteArray__rosidl_typesupport_introspection_c__ByteArray_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &test_rosidl_buffer__msg__ByteArray__rosidl_typesupport_introspection_c__ByteArray_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
