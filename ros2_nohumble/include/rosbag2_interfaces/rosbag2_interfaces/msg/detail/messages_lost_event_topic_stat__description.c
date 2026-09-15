// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from rosbag2_interfaces:msg\MessagesLostEventTopicStat.idl
// generated code does not contain a copyright notice

#include "rosbag2_interfaces/msg/detail/messages_lost_event_topic_stat__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_rosbag2_interfaces
const rosidl_type_hash_t *
rosbag2_interfaces__msg__MessagesLostEventTopicStat__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xe4, 0x6b, 0x2b, 0x21, 0x16, 0x80, 0xa2, 0x00,
      0xb6, 0x25, 0xf3, 0x19, 0xb6, 0x31, 0x85, 0x96,
      0xe2, 0x8f, 0x9e, 0xd3, 0xc5, 0xbc, 0x24, 0x1d,
      0x1b, 0x95, 0xb2, 0x60, 0x28, 0xb9, 0x17, 0xb7,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char rosbag2_interfaces__msg__MessagesLostEventTopicStat__TYPE_NAME[] = "rosbag2_interfaces/msg/MessagesLostEventTopicStat";

// Define type names, field names, and default values
static char rosbag2_interfaces__msg__MessagesLostEventTopicStat__FIELD_NAME__topic_name[] = "topic_name";
static char rosbag2_interfaces__msg__MessagesLostEventTopicStat__FIELD_NAME__messages_lost_in_transport[] = "messages_lost_in_transport";
static char rosbag2_interfaces__msg__MessagesLostEventTopicStat__FIELD_NAME__messages_lost_in_recorder[] = "messages_lost_in_recorder";

static rosidl_runtime_c__type_description__Field rosbag2_interfaces__msg__MessagesLostEventTopicStat__FIELDS[] = {
  {
    {rosbag2_interfaces__msg__MessagesLostEventTopicStat__FIELD_NAME__topic_name, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {rosbag2_interfaces__msg__MessagesLostEventTopicStat__FIELD_NAME__messages_lost_in_transport, 26, 26},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {rosbag2_interfaces__msg__MessagesLostEventTopicStat__FIELD_NAME__messages_lost_in_recorder, 25, 25},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
rosbag2_interfaces__msg__MessagesLostEventTopicStat__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {rosbag2_interfaces__msg__MessagesLostEventTopicStat__TYPE_NAME, 49, 49},
      {rosbag2_interfaces__msg__MessagesLostEventTopicStat__FIELDS, 3, 3},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# The name of the topic on which the messages were lost\n"
  "string topic_name\n"
  "\n"
  "# The number of messages lost since the last event on a DDS transport layer\n"
  "uint64 messages_lost_in_transport\n"
  "\n"
  "# The number of messages lost since the last event in the Rosbag2 recorder\n"
  "uint64 messages_lost_in_recorder";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
rosbag2_interfaces__msg__MessagesLostEventTopicStat__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {rosbag2_interfaces__msg__MessagesLostEventTopicStat__TYPE_NAME, 49, 49},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 294, 294},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
rosbag2_interfaces__msg__MessagesLostEventTopicStat__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *rosbag2_interfaces__msg__MessagesLostEventTopicStat__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
