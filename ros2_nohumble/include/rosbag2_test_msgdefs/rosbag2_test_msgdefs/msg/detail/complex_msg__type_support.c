// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from rosbag2_test_msgdefs:msg\ComplexMsg.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "rosbag2_test_msgdefs/msg/detail/complex_msg__rosidl_typesupport_introspection_c.h"
#include "rosbag2_test_msgdefs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "rosbag2_test_msgdefs/msg/detail/complex_msg__functions.h"
#include "rosbag2_test_msgdefs/msg/detail/complex_msg__struct.h"


// Include directives for member types
// Member `b`
#include "rosbag2_test_msgdefs/msg/basic_msg.h"
// Member `b`
#include "rosbag2_test_msgdefs/msg/detail/basic_msg__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void rosbag2_test_msgdefs__msg__ComplexMsg__rosidl_typesupport_introspection_c__ComplexMsg_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rosbag2_test_msgdefs__msg__ComplexMsg__init(message_memory);
}

void rosbag2_test_msgdefs__msg__ComplexMsg__rosidl_typesupport_introspection_c__ComplexMsg_fini_function(void * message_memory)
{
  rosbag2_test_msgdefs__msg__ComplexMsg__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember rosbag2_test_msgdefs__msg__ComplexMsg__rosidl_typesupport_introspection_c__ComplexMsg_message_member_array[1] = {
  {
    "b",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rosbag2_test_msgdefs__msg__ComplexMsg, b),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL,  // resize(index) function pointer
    false  // is_rosidl_buffer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers rosbag2_test_msgdefs__msg__ComplexMsg__rosidl_typesupport_introspection_c__ComplexMsg_message_members = {
  "rosbag2_test_msgdefs__msg",  // message namespace
  "ComplexMsg",  // message name
  1,  // number of fields
  sizeof(rosbag2_test_msgdefs__msg__ComplexMsg),
  false,  // has_any_key_member_
  rosbag2_test_msgdefs__msg__ComplexMsg__rosidl_typesupport_introspection_c__ComplexMsg_message_member_array,  // message members
  rosbag2_test_msgdefs__msg__ComplexMsg__rosidl_typesupport_introspection_c__ComplexMsg_init_function,  // function to initialize message memory (memory has to be allocated)
  rosbag2_test_msgdefs__msg__ComplexMsg__rosidl_typesupport_introspection_c__ComplexMsg_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t rosbag2_test_msgdefs__msg__ComplexMsg__rosidl_typesupport_introspection_c__ComplexMsg_message_type_support_handle = {
  0,
  &rosbag2_test_msgdefs__msg__ComplexMsg__rosidl_typesupport_introspection_c__ComplexMsg_message_members,
  get_message_typesupport_handle_function,
  &rosbag2_test_msgdefs__msg__ComplexMsg__get_type_hash,
  &rosbag2_test_msgdefs__msg__ComplexMsg__get_type_description,
  &rosbag2_test_msgdefs__msg__ComplexMsg__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rosbag2_test_msgdefs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rosbag2_test_msgdefs, msg, ComplexMsg)() {
  rosbag2_test_msgdefs__msg__ComplexMsg__rosidl_typesupport_introspection_c__ComplexMsg_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rosbag2_test_msgdefs, msg, BasicMsg)();
  if (!rosbag2_test_msgdefs__msg__ComplexMsg__rosidl_typesupport_introspection_c__ComplexMsg_message_type_support_handle.typesupport_identifier) {
    rosbag2_test_msgdefs__msg__ComplexMsg__rosidl_typesupport_introspection_c__ComplexMsg_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &rosbag2_test_msgdefs__msg__ComplexMsg__rosidl_typesupport_introspection_c__ComplexMsg_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
