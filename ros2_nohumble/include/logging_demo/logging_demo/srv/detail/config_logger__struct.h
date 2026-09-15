// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from logging_demo:srv\ConfigLogger.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "logging_demo/srv/config_logger.h"


#ifndef LOGGING_DEMO__SRV__DETAIL__CONFIG_LOGGER__STRUCT_H_
#define LOGGING_DEMO__SRV__DETAIL__CONFIG_LOGGER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'logger_name'
// Member 'level'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/ConfigLogger in the package logging_demo.
typedef struct logging_demo__srv__ConfigLogger_Request
{
  rosidl_runtime_c__String logger_name;
  rosidl_runtime_c__String level;
} logging_demo__srv__ConfigLogger_Request;

// Struct for a sequence of logging_demo__srv__ConfigLogger_Request.
typedef struct logging_demo__srv__ConfigLogger_Request__Sequence
{
  logging_demo__srv__ConfigLogger_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} logging_demo__srv__ConfigLogger_Request__Sequence;

// Constants defined in the message

/// Struct defined in srv/ConfigLogger in the package logging_demo.
typedef struct logging_demo__srv__ConfigLogger_Response
{
  bool success;
} logging_demo__srv__ConfigLogger_Response;

// Struct for a sequence of logging_demo__srv__ConfigLogger_Response.
typedef struct logging_demo__srv__ConfigLogger_Response__Sequence
{
  logging_demo__srv__ConfigLogger_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} logging_demo__srv__ConfigLogger_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  logging_demo__srv__ConfigLogger_Event__request__MAX_SIZE = 1
};
// response
enum
{
  logging_demo__srv__ConfigLogger_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/ConfigLogger in the package logging_demo.
typedef struct logging_demo__srv__ConfigLogger_Event
{
  service_msgs__msg__ServiceEventInfo info;
  logging_demo__srv__ConfigLogger_Request__Sequence request;
  logging_demo__srv__ConfigLogger_Response__Sequence response;
} logging_demo__srv__ConfigLogger_Event;

// Struct for a sequence of logging_demo__srv__ConfigLogger_Event.
typedef struct logging_demo__srv__ConfigLogger_Event__Sequence
{
  logging_demo__srv__ConfigLogger_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} logging_demo__srv__ConfigLogger_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // LOGGING_DEMO__SRV__DETAIL__CONFIG_LOGGER__STRUCT_H_
