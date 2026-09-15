// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rosbag2_interfaces:srv\Resume.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosbag2_interfaces/srv/resume.h"


#ifndef ROSBAG2_INTERFACES__SRV__DETAIL__RESUME__STRUCT_H_
#define ROSBAG2_INTERFACES__SRV__DETAIL__RESUME__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'RESUME_MODE_NODE_TIME'.
enum
{
  rosbag2_interfaces__srv__Resume_Request__RESUME_MODE_NODE_TIME = 0l
};

/// Constant 'RESUME_MODE_PUBLISH_TIME'.
enum
{
  rosbag2_interfaces__srv__Resume_Request__RESUME_MODE_PUBLISH_TIME = 1l
};

/// Constant 'RESUME_MODE_RECEIVE_TIME'.
enum
{
  rosbag2_interfaces__srv__Resume_Request__RESUME_MODE_RECEIVE_TIME = 2l
};

// Include directives for member types
// Member 'resume_time'
#include "builtin_interfaces/msg/detail/time__struct.h"
// Member 'tracking_topic_name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/Resume in the package rosbag2_interfaces.
typedef struct rosbag2_interfaces__srv__Resume_Request
{
  /// Timestamp in the future when to resume recording/playback.
  /// If empty or time in the past, resumes recording/playback immediately.
  /// Note: The resume_time is not supported by player and shall be set to zero when using Resume with
  /// player.
  builtin_interfaces__msg__Time resume_time;
  /// Resume mode to use for the resume_time request.
  int32_t resume_mode;
  /// Topic name to use for timestamp-based resume evaluation.
  /// If empty, evaluate using messages from all topics.
  rosidl_runtime_c__String tracking_topic_name;
} rosbag2_interfaces__srv__Resume_Request;

// Struct for a sequence of rosbag2_interfaces__srv__Resume_Request.
typedef struct rosbag2_interfaces__srv__Resume_Request__Sequence
{
  rosbag2_interfaces__srv__Resume_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rosbag2_interfaces__srv__Resume_Request__Sequence;

// Constants defined in the message

/// Constant 'RETURN_CODE_SUCCESS'.
enum
{
  rosbag2_interfaces__srv__Resume_Response__RETURN_CODE_SUCCESS = 0l
};

/// Constant 'RETURN_CODE_INVALID_RESUME_MODE'.
enum
{
  rosbag2_interfaces__srv__Resume_Response__RETURN_CODE_INVALID_RESUME_MODE = 1l
};

/// Constant 'RETURN_CODE_INVALID_TRACKING_TOPIC'.
enum
{
  rosbag2_interfaces__srv__Resume_Response__RETURN_CODE_INVALID_TRACKING_TOPIC = 2l
};

/// Constant 'RETURN_CODE_RESUME_FAILED'.
enum
{
  rosbag2_interfaces__srv__Resume_Response__RETURN_CODE_RESUME_FAILED = 3l
};

// Include directives for member types
// Member 'error_string'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/Resume in the package rosbag2_interfaces.
typedef struct rosbag2_interfaces__srv__Resume_Response
{
  /// Return code. Use RETURN_CODE_SUCCESS on success; otherwise use one of the error codes.
  int32_t return_code;
  /// Error string. Empty if no error occurred.
  rosidl_runtime_c__String error_string;
} rosbag2_interfaces__srv__Resume_Response;

// Struct for a sequence of rosbag2_interfaces__srv__Resume_Response.
typedef struct rosbag2_interfaces__srv__Resume_Response__Sequence
{
  rosbag2_interfaces__srv__Resume_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rosbag2_interfaces__srv__Resume_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  rosbag2_interfaces__srv__Resume_Event__request__MAX_SIZE = 1
};
// response
enum
{
  rosbag2_interfaces__srv__Resume_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/Resume in the package rosbag2_interfaces.
typedef struct rosbag2_interfaces__srv__Resume_Event
{
  service_msgs__msg__ServiceEventInfo info;
  rosbag2_interfaces__srv__Resume_Request__Sequence request;
  rosbag2_interfaces__srv__Resume_Response__Sequence response;
} rosbag2_interfaces__srv__Resume_Event;

// Struct for a sequence of rosbag2_interfaces__srv__Resume_Event.
typedef struct rosbag2_interfaces__srv__Resume_Event__Sequence
{
  rosbag2_interfaces__srv__Resume_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rosbag2_interfaces__srv__Resume_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROSBAG2_INTERFACES__SRV__DETAIL__RESUME__STRUCT_H_
