// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rosbag2_interfaces:srv\Play.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosbag2_interfaces/srv/play.h"


#ifndef ROSBAG2_INTERFACES__SRV__DETAIL__PLAY__STRUCT_H_
#define ROSBAG2_INTERFACES__SRV__DETAIL__PLAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'start_offset'
// Member 'playback_until_timestamp'
#include "builtin_interfaces/msg/detail/time__struct.h"
// Member 'playback_duration'
#include "builtin_interfaces/msg/detail/duration__struct.h"

/// Struct defined in srv/Play in the package rosbag2_interfaces.
typedef struct rosbag2_interfaces__srv__Play_Request
{
  builtin_interfaces__msg__Time start_offset;
  /// See rosbag2_transport::PlayOptions::playback_duration
  builtin_interfaces__msg__Duration playback_duration;
  /// See rosbag2_transport::PlayOptions::playback_until_timestamp
  builtin_interfaces__msg__Time playback_until_timestamp;
} rosbag2_interfaces__srv__Play_Request;

// Struct for a sequence of rosbag2_interfaces__srv__Play_Request.
typedef struct rosbag2_interfaces__srv__Play_Request__Sequence
{
  rosbag2_interfaces__srv__Play_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rosbag2_interfaces__srv__Play_Request__Sequence;

// Constants defined in the message

/// Struct defined in srv/Play in the package rosbag2_interfaces.
typedef struct rosbag2_interfaces__srv__Play_Response
{
  bool success;
} rosbag2_interfaces__srv__Play_Response;

// Struct for a sequence of rosbag2_interfaces__srv__Play_Response.
typedef struct rosbag2_interfaces__srv__Play_Response__Sequence
{
  rosbag2_interfaces__srv__Play_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rosbag2_interfaces__srv__Play_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  rosbag2_interfaces__srv__Play_Event__request__MAX_SIZE = 1
};
// response
enum
{
  rosbag2_interfaces__srv__Play_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/Play in the package rosbag2_interfaces.
typedef struct rosbag2_interfaces__srv__Play_Event
{
  service_msgs__msg__ServiceEventInfo info;
  rosbag2_interfaces__srv__Play_Request__Sequence request;
  rosbag2_interfaces__srv__Play_Response__Sequence response;
} rosbag2_interfaces__srv__Play_Event;

// Struct for a sequence of rosbag2_interfaces__srv__Play_Event.
typedef struct rosbag2_interfaces__srv__Play_Event__Sequence
{
  rosbag2_interfaces__srv__Play_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rosbag2_interfaces__srv__Play_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROSBAG2_INTERFACES__SRV__DETAIL__PLAY__STRUCT_H_
