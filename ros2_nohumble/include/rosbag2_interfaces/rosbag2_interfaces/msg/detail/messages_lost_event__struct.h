// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rosbag2_interfaces:msg\MessagesLostEvent.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosbag2_interfaces/msg/messages_lost_event.h"


#ifndef ROSBAG2_INTERFACES__MSG__DETAIL__MESSAGES_LOST_EVENT__STRUCT_H_
#define ROSBAG2_INTERFACES__MSG__DETAIL__MESSAGES_LOST_EVENT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'node_name'
#include "rosidl_runtime_c/string.h"
// Member 'messages_lost_statistics'
#include "rosbag2_interfaces/msg/detail/messages_lost_event_topic_stat__struct.h"

/// Struct defined in msg/MessagesLostEvent in the package rosbag2_interfaces.
/**
  * The fully qualified node name of the event sender
 */
typedef struct rosbag2_interfaces__msg__MessagesLostEvent
{
  rosidl_runtime_c__String node_name;
  /// Per topic statistics about messages lost since the last event. Topics with no lost messages
  /// will not be included
  rosbag2_interfaces__msg__MessagesLostEventTopicStat__Sequence messages_lost_statistics;
} rosbag2_interfaces__msg__MessagesLostEvent;

// Struct for a sequence of rosbag2_interfaces__msg__MessagesLostEvent.
typedef struct rosbag2_interfaces__msg__MessagesLostEvent__Sequence
{
  rosbag2_interfaces__msg__MessagesLostEvent * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rosbag2_interfaces__msg__MessagesLostEvent__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROSBAG2_INTERFACES__MSG__DETAIL__MESSAGES_LOST_EVENT__STRUCT_H_
