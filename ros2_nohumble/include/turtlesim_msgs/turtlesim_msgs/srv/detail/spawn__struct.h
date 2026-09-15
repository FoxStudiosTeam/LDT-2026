// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from turtlesim_msgs:srv\Spawn.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "turtlesim_msgs/srv/spawn.h"


#ifndef TURTLESIM_MSGS__SRV__DETAIL__SPAWN__STRUCT_H_
#define TURTLESIM_MSGS__SRV__DETAIL__SPAWN__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/Spawn in the package turtlesim_msgs.
typedef struct turtlesim_msgs__srv__Spawn_Request
{
  float x;
  float y;
  float theta;
  /// Optional.  A unique name will be created and returned if this is empty
  rosidl_runtime_c__String name;
} turtlesim_msgs__srv__Spawn_Request;

// Struct for a sequence of turtlesim_msgs__srv__Spawn_Request.
typedef struct turtlesim_msgs__srv__Spawn_Request__Sequence
{
  turtlesim_msgs__srv__Spawn_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} turtlesim_msgs__srv__Spawn_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'name'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/Spawn in the package turtlesim_msgs.
typedef struct turtlesim_msgs__srv__Spawn_Response
{
  rosidl_runtime_c__String name;
} turtlesim_msgs__srv__Spawn_Response;

// Struct for a sequence of turtlesim_msgs__srv__Spawn_Response.
typedef struct turtlesim_msgs__srv__Spawn_Response__Sequence
{
  turtlesim_msgs__srv__Spawn_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} turtlesim_msgs__srv__Spawn_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  turtlesim_msgs__srv__Spawn_Event__request__MAX_SIZE = 1
};
// response
enum
{
  turtlesim_msgs__srv__Spawn_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/Spawn in the package turtlesim_msgs.
typedef struct turtlesim_msgs__srv__Spawn_Event
{
  service_msgs__msg__ServiceEventInfo info;
  turtlesim_msgs__srv__Spawn_Request__Sequence request;
  turtlesim_msgs__srv__Spawn_Response__Sequence response;
} turtlesim_msgs__srv__Spawn_Event;

// Struct for a sequence of turtlesim_msgs__srv__Spawn_Event.
typedef struct turtlesim_msgs__srv__Spawn_Event__Sequence
{
  turtlesim_msgs__srv__Spawn_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} turtlesim_msgs__srv__Spawn_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TURTLESIM_MSGS__SRV__DETAIL__SPAWN__STRUCT_H_
