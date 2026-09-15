// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rosbag2_interfaces:srv\Record.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosbag2_interfaces/srv/record.h"


#ifndef ROSBAG2_INTERFACES__SRV__DETAIL__RECORD__STRUCT_H_
#define ROSBAG2_INTERFACES__SRV__DETAIL__RECORD__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'uri'
#include "rosidl_runtime_c/string.h"
// Member 'start_time'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in srv/Record in the package rosbag2_interfaces.
typedef struct rosbag2_interfaces__srv__Record_Request
{
  rosidl_runtime_c__String uri;
  /// Timestamp in the future when to start recording.
  /// If empty or time in the past, recording starts immediately.
  builtin_interfaces__msg__Time start_time;
} rosbag2_interfaces__srv__Record_Request;

// Struct for a sequence of rosbag2_interfaces__srv__Record_Request.
typedef struct rosbag2_interfaces__srv__Record_Request__Sequence
{
  rosbag2_interfaces__srv__Record_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rosbag2_interfaces__srv__Record_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'error_string'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/Record in the package rosbag2_interfaces.
typedef struct rosbag2_interfaces__srv__Record_Response
{
  int32_t return_code;
  /// Error string. Empty if no error occurred.
  rosidl_runtime_c__String error_string;
} rosbag2_interfaces__srv__Record_Response;

// Struct for a sequence of rosbag2_interfaces__srv__Record_Response.
typedef struct rosbag2_interfaces__srv__Record_Response__Sequence
{
  rosbag2_interfaces__srv__Record_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rosbag2_interfaces__srv__Record_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  rosbag2_interfaces__srv__Record_Event__request__MAX_SIZE = 1
};
// response
enum
{
  rosbag2_interfaces__srv__Record_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/Record in the package rosbag2_interfaces.
typedef struct rosbag2_interfaces__srv__Record_Event
{
  service_msgs__msg__ServiceEventInfo info;
  rosbag2_interfaces__srv__Record_Request__Sequence request;
  rosbag2_interfaces__srv__Record_Response__Sequence response;
} rosbag2_interfaces__srv__Record_Event;

// Struct for a sequence of rosbag2_interfaces__srv__Record_Event.
typedef struct rosbag2_interfaces__srv__Record_Event__Sequence
{
  rosbag2_interfaces__srv__Record_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rosbag2_interfaces__srv__Record_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROSBAG2_INTERFACES__SRV__DETAIL__RECORD__STRUCT_H_
