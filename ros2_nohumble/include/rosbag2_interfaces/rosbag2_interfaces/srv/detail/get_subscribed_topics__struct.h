// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rosbag2_interfaces:srv\GetSubscribedTopics.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosbag2_interfaces/srv/get_subscribed_topics.h"


#ifndef ROSBAG2_INTERFACES__SRV__DETAIL__GET_SUBSCRIBED_TOPICS__STRUCT_H_
#define ROSBAG2_INTERFACES__SRV__DETAIL__GET_SUBSCRIBED_TOPICS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/GetSubscribedTopics in the package rosbag2_interfaces.
typedef struct rosbag2_interfaces__srv__GetSubscribedTopics_Request
{
  uint8_t structure_needs_at_least_one_member;
} rosbag2_interfaces__srv__GetSubscribedTopics_Request;

// Struct for a sequence of rosbag2_interfaces__srv__GetSubscribedTopics_Request.
typedef struct rosbag2_interfaces__srv__GetSubscribedTopics_Request__Sequence
{
  rosbag2_interfaces__srv__GetSubscribedTopics_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rosbag2_interfaces__srv__GetSubscribedTopics_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'topics'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/GetSubscribedTopics in the package rosbag2_interfaces.
typedef struct rosbag2_interfaces__srv__GetSubscribedTopics_Response
{
  rosidl_runtime_c__String__Sequence topics;
} rosbag2_interfaces__srv__GetSubscribedTopics_Response;

// Struct for a sequence of rosbag2_interfaces__srv__GetSubscribedTopics_Response.
typedef struct rosbag2_interfaces__srv__GetSubscribedTopics_Response__Sequence
{
  rosbag2_interfaces__srv__GetSubscribedTopics_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rosbag2_interfaces__srv__GetSubscribedTopics_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  rosbag2_interfaces__srv__GetSubscribedTopics_Event__request__MAX_SIZE = 1
};
// response
enum
{
  rosbag2_interfaces__srv__GetSubscribedTopics_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/GetSubscribedTopics in the package rosbag2_interfaces.
typedef struct rosbag2_interfaces__srv__GetSubscribedTopics_Event
{
  service_msgs__msg__ServiceEventInfo info;
  rosbag2_interfaces__srv__GetSubscribedTopics_Request__Sequence request;
  rosbag2_interfaces__srv__GetSubscribedTopics_Response__Sequence response;
} rosbag2_interfaces__srv__GetSubscribedTopics_Event;

// Struct for a sequence of rosbag2_interfaces__srv__GetSubscribedTopics_Event.
typedef struct rosbag2_interfaces__srv__GetSubscribedTopics_Event__Sequence
{
  rosbag2_interfaces__srv__GetSubscribedTopics_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rosbag2_interfaces__srv__GetSubscribedTopics_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROSBAG2_INTERFACES__SRV__DETAIL__GET_SUBSCRIBED_TOPICS__STRUCT_H_
