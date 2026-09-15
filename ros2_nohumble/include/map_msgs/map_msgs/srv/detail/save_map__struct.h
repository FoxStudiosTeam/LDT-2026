// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from map_msgs:srv\SaveMap.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "map_msgs/srv/save_map.h"


#ifndef MAP_MSGS__SRV__DETAIL__SAVE_MAP__STRUCT_H_
#define MAP_MSGS__SRV__DETAIL__SAVE_MAP__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'filename'
#include "std_msgs/msg/detail/string__struct.h"

/// Struct defined in srv/SaveMap in the package map_msgs.
typedef struct map_msgs__srv__SaveMap_Request
{
  std_msgs__msg__String filename;
} map_msgs__srv__SaveMap_Request;

// Struct for a sequence of map_msgs__srv__SaveMap_Request.
typedef struct map_msgs__srv__SaveMap_Request__Sequence
{
  map_msgs__srv__SaveMap_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} map_msgs__srv__SaveMap_Request__Sequence;

// Constants defined in the message

/// Struct defined in srv/SaveMap in the package map_msgs.
typedef struct map_msgs__srv__SaveMap_Response
{
  uint8_t structure_needs_at_least_one_member;
} map_msgs__srv__SaveMap_Response;

// Struct for a sequence of map_msgs__srv__SaveMap_Response.
typedef struct map_msgs__srv__SaveMap_Response__Sequence
{
  map_msgs__srv__SaveMap_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} map_msgs__srv__SaveMap_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  map_msgs__srv__SaveMap_Event__request__MAX_SIZE = 1
};
// response
enum
{
  map_msgs__srv__SaveMap_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/SaveMap in the package map_msgs.
typedef struct map_msgs__srv__SaveMap_Event
{
  service_msgs__msg__ServiceEventInfo info;
  map_msgs__srv__SaveMap_Request__Sequence request;
  map_msgs__srv__SaveMap_Response__Sequence response;
} map_msgs__srv__SaveMap_Event;

// Struct for a sequence of map_msgs__srv__SaveMap_Event.
typedef struct map_msgs__srv__SaveMap_Event__Sequence
{
  map_msgs__srv__SaveMap_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} map_msgs__srv__SaveMap_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MAP_MSGS__SRV__DETAIL__SAVE_MAP__STRUCT_H_
