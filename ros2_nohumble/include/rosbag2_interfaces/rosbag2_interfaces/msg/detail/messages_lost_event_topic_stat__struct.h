// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rosbag2_interfaces:msg\MessagesLostEventTopicStat.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosbag2_interfaces/msg/messages_lost_event_topic_stat.h"


#ifndef ROSBAG2_INTERFACES__MSG__DETAIL__MESSAGES_LOST_EVENT_TOPIC_STAT__STRUCT_H_
#define ROSBAG2_INTERFACES__MSG__DETAIL__MESSAGES_LOST_EVENT_TOPIC_STAT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'topic_name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/MessagesLostEventTopicStat in the package rosbag2_interfaces.
/**
  * The name of the topic on which the messages were lost
 */
typedef struct rosbag2_interfaces__msg__MessagesLostEventTopicStat
{
  rosidl_runtime_c__String topic_name;
  /// The number of messages lost since the last event on a DDS transport layer
  uint64_t messages_lost_in_transport;
  /// The number of messages lost since the last event in the Rosbag2 recorder
  uint64_t messages_lost_in_recorder;
} rosbag2_interfaces__msg__MessagesLostEventTopicStat;

// Struct for a sequence of rosbag2_interfaces__msg__MessagesLostEventTopicStat.
typedef struct rosbag2_interfaces__msg__MessagesLostEventTopicStat__Sequence
{
  rosbag2_interfaces__msg__MessagesLostEventTopicStat * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rosbag2_interfaces__msg__MessagesLostEventTopicStat__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROSBAG2_INTERFACES__MSG__DETAIL__MESSAGES_LOST_EVENT_TOPIC_STAT__STRUCT_H_
