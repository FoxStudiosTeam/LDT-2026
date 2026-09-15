// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from rosbag2_interfaces:msg\MessagesLostEvent.idl
// generated code does not contain a copyright notice

#include "rosbag2_interfaces/msg/detail/messages_lost_event__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_rosbag2_interfaces
const rosidl_type_hash_t *
rosbag2_interfaces__msg__MessagesLostEvent__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xb4, 0xa1, 0xd6, 0x32, 0x2a, 0x23, 0x2c, 0x78,
      0xfb, 0xb6, 0x89, 0x76, 0xbd, 0xa0, 0xb2, 0x31,
      0x3d, 0x80, 0x83, 0xb2, 0x92, 0x59, 0xea, 0xf6,
      0xc6, 0x38, 0x48, 0xa4, 0xc4, 0x7a, 0xe9, 0x67,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "rosbag2_interfaces/msg/detail/messages_lost_event_topic_stat__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t rosbag2_interfaces__msg__MessagesLostEventTopicStat__EXPECTED_HASH = {1, {
    0xe4, 0x6b, 0x2b, 0x21, 0x16, 0x80, 0xa2, 0x00,
    0xb6, 0x25, 0xf3, 0x19, 0xb6, 0x31, 0x85, 0x96,
    0xe2, 0x8f, 0x9e, 0xd3, 0xc5, 0xbc, 0x24, 0x1d,
    0x1b, 0x95, 0xb2, 0x60, 0x28, 0xb9, 0x17, 0xb7,
  }};
#endif

static char rosbag2_interfaces__msg__MessagesLostEvent__TYPE_NAME[] = "rosbag2_interfaces/msg/MessagesLostEvent";
static char rosbag2_interfaces__msg__MessagesLostEventTopicStat__TYPE_NAME[] = "rosbag2_interfaces/msg/MessagesLostEventTopicStat";

// Define type names, field names, and default values
static char rosbag2_interfaces__msg__MessagesLostEvent__FIELD_NAME__node_name[] = "node_name";
static char rosbag2_interfaces__msg__MessagesLostEvent__FIELD_NAME__messages_lost_statistics[] = "messages_lost_statistics";

static rosidl_runtime_c__type_description__Field rosbag2_interfaces__msg__MessagesLostEvent__FIELDS[] = {
  {
    {rosbag2_interfaces__msg__MessagesLostEvent__FIELD_NAME__node_name, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {rosbag2_interfaces__msg__MessagesLostEvent__FIELD_NAME__messages_lost_statistics, 24, 24},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {rosbag2_interfaces__msg__MessagesLostEventTopicStat__TYPE_NAME, 49, 49},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription rosbag2_interfaces__msg__MessagesLostEvent__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {rosbag2_interfaces__msg__MessagesLostEventTopicStat__TYPE_NAME, 49, 49},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
rosbag2_interfaces__msg__MessagesLostEvent__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {rosbag2_interfaces__msg__MessagesLostEvent__TYPE_NAME, 40, 40},
      {rosbag2_interfaces__msg__MessagesLostEvent__FIELDS, 2, 2},
    },
    {rosbag2_interfaces__msg__MessagesLostEvent__REFERENCED_TYPE_DESCRIPTIONS, 1, 1},
  };
  if (!constructed) {
    assert(0 == memcmp(&rosbag2_interfaces__msg__MessagesLostEventTopicStat__EXPECTED_HASH, rosbag2_interfaces__msg__MessagesLostEventTopicStat__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = rosbag2_interfaces__msg__MessagesLostEventTopicStat__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# The fully qualified node name of the event sender\n"
  "string node_name\n"
  "\n"
  "# Per topic statistics about messages lost since the last event. Topics with no lost messages\n"
  "# will not be included\n"
  "MessagesLostEventTopicStat[] messages_lost_statistics";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
rosbag2_interfaces__msg__MessagesLostEvent__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {rosbag2_interfaces__msg__MessagesLostEvent__TYPE_NAME, 40, 40},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 241, 241},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
rosbag2_interfaces__msg__MessagesLostEvent__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[2];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 2, 2};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *rosbag2_interfaces__msg__MessagesLostEvent__get_individual_type_description_source(NULL),
    sources[1] = *rosbag2_interfaces__msg__MessagesLostEventTopicStat__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
