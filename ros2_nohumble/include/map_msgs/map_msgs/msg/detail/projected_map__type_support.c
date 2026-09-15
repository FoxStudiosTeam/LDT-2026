// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from map_msgs:msg\ProjectedMap.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "map_msgs/msg/detail/projected_map__rosidl_typesupport_introspection_c.h"
#include "map_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "map_msgs/msg/detail/projected_map__functions.h"
#include "map_msgs/msg/detail/projected_map__struct.h"


// Include directives for member types
// Member `map`
#include "nav_msgs/msg/occupancy_grid.h"
// Member `map`
#include "nav_msgs/msg/detail/occupancy_grid__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void map_msgs__msg__ProjectedMap__rosidl_typesupport_introspection_c__ProjectedMap_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  map_msgs__msg__ProjectedMap__init(message_memory);
}

void map_msgs__msg__ProjectedMap__rosidl_typesupport_introspection_c__ProjectedMap_fini_function(void * message_memory)
{
  map_msgs__msg__ProjectedMap__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember map_msgs__msg__ProjectedMap__rosidl_typesupport_introspection_c__ProjectedMap_message_member_array[3] = {
  {
    "map",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(map_msgs__msg__ProjectedMap, map),  // bytes offset in struct
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
    "min_z",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(map_msgs__msg__ProjectedMap, min_z),  // bytes offset in struct
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
    "max_z",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(map_msgs__msg__ProjectedMap, max_z),  // bytes offset in struct
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

static const rosidl_typesupport_introspection_c__MessageMembers map_msgs__msg__ProjectedMap__rosidl_typesupport_introspection_c__ProjectedMap_message_members = {
  "map_msgs__msg",  // message namespace
  "ProjectedMap",  // message name
  3,  // number of fields
  sizeof(map_msgs__msg__ProjectedMap),
  false,  // has_any_key_member_
  map_msgs__msg__ProjectedMap__rosidl_typesupport_introspection_c__ProjectedMap_message_member_array,  // message members
  map_msgs__msg__ProjectedMap__rosidl_typesupport_introspection_c__ProjectedMap_init_function,  // function to initialize message memory (memory has to be allocated)
  map_msgs__msg__ProjectedMap__rosidl_typesupport_introspection_c__ProjectedMap_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t map_msgs__msg__ProjectedMap__rosidl_typesupport_introspection_c__ProjectedMap_message_type_support_handle = {
  0,
  &map_msgs__msg__ProjectedMap__rosidl_typesupport_introspection_c__ProjectedMap_message_members,
  get_message_typesupport_handle_function,
  &map_msgs__msg__ProjectedMap__get_type_hash,
  &map_msgs__msg__ProjectedMap__get_type_description,
  &map_msgs__msg__ProjectedMap__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_map_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, map_msgs, msg, ProjectedMap)() {
  map_msgs__msg__ProjectedMap__rosidl_typesupport_introspection_c__ProjectedMap_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, nav_msgs, msg, OccupancyGrid)();
  if (!map_msgs__msg__ProjectedMap__rosidl_typesupport_introspection_c__ProjectedMap_message_type_support_handle.typesupport_identifier) {
    map_msgs__msg__ProjectedMap__rosidl_typesupport_introspection_c__ProjectedMap_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &map_msgs__msg__ProjectedMap__rosidl_typesupport_introspection_c__ProjectedMap_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
