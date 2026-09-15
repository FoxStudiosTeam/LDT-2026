// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from rosbag2_performance_benchmarking_msgs:msg\ByteArray.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "rosbag2_performance_benchmarking_msgs/msg/detail/byte_array__rosidl_typesupport_introspection_c.h"
#include "rosbag2_performance_benchmarking_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "rosbag2_performance_benchmarking_msgs/msg/detail/byte_array__functions.h"
#include "rosbag2_performance_benchmarking_msgs/msg/detail/byte_array__struct.h"


// Include directives for member types
// Member `data`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void rosbag2_performance_benchmarking_msgs__msg__ByteArray__rosidl_typesupport_introspection_c__ByteArray_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rosbag2_performance_benchmarking_msgs__msg__ByteArray__init(message_memory);
}

void rosbag2_performance_benchmarking_msgs__msg__ByteArray__rosidl_typesupport_introspection_c__ByteArray_fini_function(void * message_memory)
{
  rosbag2_performance_benchmarking_msgs__msg__ByteArray__fini(message_memory);
}

size_t rosbag2_performance_benchmarking_msgs__msg__ByteArray__rosidl_typesupport_introspection_c__size_function__ByteArray__data(
  const void * untyped_member)
{
  const rosidl_runtime_c__octet__Sequence * member =
    (const rosidl_runtime_c__octet__Sequence *)(untyped_member);
  return member->size;
}

const void * rosbag2_performance_benchmarking_msgs__msg__ByteArray__rosidl_typesupport_introspection_c__get_const_function__ByteArray__data(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__octet__Sequence * member =
    (const rosidl_runtime_c__octet__Sequence *)(untyped_member);
  return &member->data[index];
}

void * rosbag2_performance_benchmarking_msgs__msg__ByteArray__rosidl_typesupport_introspection_c__get_function__ByteArray__data(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__octet__Sequence * member =
    (rosidl_runtime_c__octet__Sequence *)(untyped_member);
  return &member->data[index];
}

void rosbag2_performance_benchmarking_msgs__msg__ByteArray__rosidl_typesupport_introspection_c__fetch_function__ByteArray__data(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint8_t * item =
    ((const uint8_t *)
    rosbag2_performance_benchmarking_msgs__msg__ByteArray__rosidl_typesupport_introspection_c__get_const_function__ByteArray__data(untyped_member, index));
  uint8_t * value =
    (uint8_t *)(untyped_value);
  *value = *item;
}

void rosbag2_performance_benchmarking_msgs__msg__ByteArray__rosidl_typesupport_introspection_c__assign_function__ByteArray__data(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint8_t * item =
    ((uint8_t *)
    rosbag2_performance_benchmarking_msgs__msg__ByteArray__rosidl_typesupport_introspection_c__get_function__ByteArray__data(untyped_member, index));
  const uint8_t * value =
    (const uint8_t *)(untyped_value);
  *item = *value;
}

bool rosbag2_performance_benchmarking_msgs__msg__ByteArray__rosidl_typesupport_introspection_c__resize_function__ByteArray__data(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__octet__Sequence * member =
    (rosidl_runtime_c__octet__Sequence *)(untyped_member);
  rosidl_runtime_c__octet__Sequence__fini(member);
  return rosidl_runtime_c__octet__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember rosbag2_performance_benchmarking_msgs__msg__ByteArray__rosidl_typesupport_introspection_c__ByteArray_message_member_array[1] = {
  {
    "data",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_OCTET,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rosbag2_performance_benchmarking_msgs__msg__ByteArray, data),  // bytes offset in struct
    NULL,  // default value
    rosbag2_performance_benchmarking_msgs__msg__ByteArray__rosidl_typesupport_introspection_c__size_function__ByteArray__data,  // size() function pointer
    rosbag2_performance_benchmarking_msgs__msg__ByteArray__rosidl_typesupport_introspection_c__get_const_function__ByteArray__data,  // get_const(index) function pointer
    rosbag2_performance_benchmarking_msgs__msg__ByteArray__rosidl_typesupport_introspection_c__get_function__ByteArray__data,  // get(index) function pointer
    rosbag2_performance_benchmarking_msgs__msg__ByteArray__rosidl_typesupport_introspection_c__fetch_function__ByteArray__data,  // fetch(index, &value) function pointer
    rosbag2_performance_benchmarking_msgs__msg__ByteArray__rosidl_typesupport_introspection_c__assign_function__ByteArray__data,  // assign(index, value) function pointer
    rosbag2_performance_benchmarking_msgs__msg__ByteArray__rosidl_typesupport_introspection_c__resize_function__ByteArray__data,  // resize(index) function pointer
    false  // is_rosidl_buffer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers rosbag2_performance_benchmarking_msgs__msg__ByteArray__rosidl_typesupport_introspection_c__ByteArray_message_members = {
  "rosbag2_performance_benchmarking_msgs__msg",  // message namespace
  "ByteArray",  // message name
  1,  // number of fields
  sizeof(rosbag2_performance_benchmarking_msgs__msg__ByteArray),
  false,  // has_any_key_member_
  rosbag2_performance_benchmarking_msgs__msg__ByteArray__rosidl_typesupport_introspection_c__ByteArray_message_member_array,  // message members
  rosbag2_performance_benchmarking_msgs__msg__ByteArray__rosidl_typesupport_introspection_c__ByteArray_init_function,  // function to initialize message memory (memory has to be allocated)
  rosbag2_performance_benchmarking_msgs__msg__ByteArray__rosidl_typesupport_introspection_c__ByteArray_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t rosbag2_performance_benchmarking_msgs__msg__ByteArray__rosidl_typesupport_introspection_c__ByteArray_message_type_support_handle = {
  0,
  &rosbag2_performance_benchmarking_msgs__msg__ByteArray__rosidl_typesupport_introspection_c__ByteArray_message_members,
  get_message_typesupport_handle_function,
  &rosbag2_performance_benchmarking_msgs__msg__ByteArray__get_type_hash,
  &rosbag2_performance_benchmarking_msgs__msg__ByteArray__get_type_description,
  &rosbag2_performance_benchmarking_msgs__msg__ByteArray__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rosbag2_performance_benchmarking_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rosbag2_performance_benchmarking_msgs, msg, ByteArray)() {
  if (!rosbag2_performance_benchmarking_msgs__msg__ByteArray__rosidl_typesupport_introspection_c__ByteArray_message_type_support_handle.typesupport_identifier) {
    rosbag2_performance_benchmarking_msgs__msg__ByteArray__rosidl_typesupport_introspection_c__ByteArray_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &rosbag2_performance_benchmarking_msgs__msg__ByteArray__rosidl_typesupport_introspection_c__ByteArray_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
