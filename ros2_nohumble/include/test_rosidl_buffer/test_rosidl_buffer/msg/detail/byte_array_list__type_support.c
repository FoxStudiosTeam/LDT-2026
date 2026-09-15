// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from test_rosidl_buffer:msg\ByteArrayList.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "test_rosidl_buffer/msg/detail/byte_array_list__rosidl_typesupport_introspection_c.h"
#include "test_rosidl_buffer/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "test_rosidl_buffer/msg/detail/byte_array_list__functions.h"
#include "test_rosidl_buffer/msg/detail/byte_array_list__struct.h"


// Include directives for member types
// Member `items`
#include "test_rosidl_buffer/msg/byte_array.h"
// Member `items`
#include "test_rosidl_buffer/msg/detail/byte_array__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void test_rosidl_buffer__msg__ByteArrayList__rosidl_typesupport_introspection_c__ByteArrayList_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  test_rosidl_buffer__msg__ByteArrayList__init(message_memory);
}

void test_rosidl_buffer__msg__ByteArrayList__rosidl_typesupport_introspection_c__ByteArrayList_fini_function(void * message_memory)
{
  test_rosidl_buffer__msg__ByteArrayList__fini(message_memory);
}

size_t test_rosidl_buffer__msg__ByteArrayList__rosidl_typesupport_introspection_c__size_function__ByteArrayList__items(
  const void * untyped_member)
{
  const test_rosidl_buffer__msg__ByteArray__Sequence * member =
    (const test_rosidl_buffer__msg__ByteArray__Sequence *)(untyped_member);
  return member->size;
}

const void * test_rosidl_buffer__msg__ByteArrayList__rosidl_typesupport_introspection_c__get_const_function__ByteArrayList__items(
  const void * untyped_member, size_t index)
{
  const test_rosidl_buffer__msg__ByteArray__Sequence * member =
    (const test_rosidl_buffer__msg__ByteArray__Sequence *)(untyped_member);
  return &member->data[index];
}

void * test_rosidl_buffer__msg__ByteArrayList__rosidl_typesupport_introspection_c__get_function__ByteArrayList__items(
  void * untyped_member, size_t index)
{
  test_rosidl_buffer__msg__ByteArray__Sequence * member =
    (test_rosidl_buffer__msg__ByteArray__Sequence *)(untyped_member);
  return &member->data[index];
}

void test_rosidl_buffer__msg__ByteArrayList__rosidl_typesupport_introspection_c__fetch_function__ByteArrayList__items(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const test_rosidl_buffer__msg__ByteArray * item =
    ((const test_rosidl_buffer__msg__ByteArray *)
    test_rosidl_buffer__msg__ByteArrayList__rosidl_typesupport_introspection_c__get_const_function__ByteArrayList__items(untyped_member, index));
  test_rosidl_buffer__msg__ByteArray * value =
    (test_rosidl_buffer__msg__ByteArray *)(untyped_value);
  *value = *item;
}

void test_rosidl_buffer__msg__ByteArrayList__rosidl_typesupport_introspection_c__assign_function__ByteArrayList__items(
  void * untyped_member, size_t index, const void * untyped_value)
{
  test_rosidl_buffer__msg__ByteArray * item =
    ((test_rosidl_buffer__msg__ByteArray *)
    test_rosidl_buffer__msg__ByteArrayList__rosidl_typesupport_introspection_c__get_function__ByteArrayList__items(untyped_member, index));
  const test_rosidl_buffer__msg__ByteArray * value =
    (const test_rosidl_buffer__msg__ByteArray *)(untyped_value);
  *item = *value;
}

bool test_rosidl_buffer__msg__ByteArrayList__rosidl_typesupport_introspection_c__resize_function__ByteArrayList__items(
  void * untyped_member, size_t size)
{
  test_rosidl_buffer__msg__ByteArray__Sequence * member =
    (test_rosidl_buffer__msg__ByteArray__Sequence *)(untyped_member);
  test_rosidl_buffer__msg__ByteArray__Sequence__fini(member);
  return test_rosidl_buffer__msg__ByteArray__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember test_rosidl_buffer__msg__ByteArrayList__rosidl_typesupport_introspection_c__ByteArrayList_message_member_array[1] = {
  {
    "items",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(test_rosidl_buffer__msg__ByteArrayList, items),  // bytes offset in struct
    NULL,  // default value
    test_rosidl_buffer__msg__ByteArrayList__rosidl_typesupport_introspection_c__size_function__ByteArrayList__items,  // size() function pointer
    test_rosidl_buffer__msg__ByteArrayList__rosidl_typesupport_introspection_c__get_const_function__ByteArrayList__items,  // get_const(index) function pointer
    test_rosidl_buffer__msg__ByteArrayList__rosidl_typesupport_introspection_c__get_function__ByteArrayList__items,  // get(index) function pointer
    test_rosidl_buffer__msg__ByteArrayList__rosidl_typesupport_introspection_c__fetch_function__ByteArrayList__items,  // fetch(index, &value) function pointer
    test_rosidl_buffer__msg__ByteArrayList__rosidl_typesupport_introspection_c__assign_function__ByteArrayList__items,  // assign(index, value) function pointer
    test_rosidl_buffer__msg__ByteArrayList__rosidl_typesupport_introspection_c__resize_function__ByteArrayList__items,  // resize(index) function pointer
    false  // is_rosidl_buffer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers test_rosidl_buffer__msg__ByteArrayList__rosidl_typesupport_introspection_c__ByteArrayList_message_members = {
  "test_rosidl_buffer__msg",  // message namespace
  "ByteArrayList",  // message name
  1,  // number of fields
  sizeof(test_rosidl_buffer__msg__ByteArrayList),
  false,  // has_any_key_member_
  test_rosidl_buffer__msg__ByteArrayList__rosidl_typesupport_introspection_c__ByteArrayList_message_member_array,  // message members
  test_rosidl_buffer__msg__ByteArrayList__rosidl_typesupport_introspection_c__ByteArrayList_init_function,  // function to initialize message memory (memory has to be allocated)
  test_rosidl_buffer__msg__ByteArrayList__rosidl_typesupport_introspection_c__ByteArrayList_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t test_rosidl_buffer__msg__ByteArrayList__rosidl_typesupport_introspection_c__ByteArrayList_message_type_support_handle = {
  0,
  &test_rosidl_buffer__msg__ByteArrayList__rosidl_typesupport_introspection_c__ByteArrayList_message_members,
  get_message_typesupport_handle_function,
  &test_rosidl_buffer__msg__ByteArrayList__get_type_hash,
  &test_rosidl_buffer__msg__ByteArrayList__get_type_description,
  &test_rosidl_buffer__msg__ByteArrayList__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_test_rosidl_buffer
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, test_rosidl_buffer, msg, ByteArrayList)() {
  test_rosidl_buffer__msg__ByteArrayList__rosidl_typesupport_introspection_c__ByteArrayList_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, test_rosidl_buffer, msg, ByteArray)();
  if (!test_rosidl_buffer__msg__ByteArrayList__rosidl_typesupport_introspection_c__ByteArrayList_message_type_support_handle.typesupport_identifier) {
    test_rosidl_buffer__msg__ByteArrayList__rosidl_typesupport_introspection_c__ByteArrayList_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &test_rosidl_buffer__msg__ByteArrayList__rosidl_typesupport_introspection_c__ByteArrayList_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
