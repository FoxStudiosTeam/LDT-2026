// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from rosbag2_interfaces:msg\WriteSplitEvent.idl
// generated code does not contain a copyright notice

#include "rosbag2_interfaces/msg/detail/write_split_event__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_rosbag2_interfaces
const rosidl_type_hash_t *
rosbag2_interfaces__msg__WriteSplitEvent__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x4a, 0x50, 0x73, 0x3d, 0x58, 0xc4, 0x8f, 0xe3,
      0x19, 0x19, 0xae, 0x8c, 0x85, 0x16, 0xbe, 0xda,
      0x73, 0x26, 0xd7, 0x0c, 0x8e, 0x99, 0xae, 0xe9,
      0x8a, 0xf3, 0xfd, 0xfd, 0x44, 0xec, 0x5a, 0xe6,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char rosbag2_interfaces__msg__WriteSplitEvent__TYPE_NAME[] = "rosbag2_interfaces/msg/WriteSplitEvent";

// Define type names, field names, and default values
static char rosbag2_interfaces__msg__WriteSplitEvent__FIELD_NAME__closed_file[] = "closed_file";
static char rosbag2_interfaces__msg__WriteSplitEvent__FIELD_NAME__opened_file[] = "opened_file";
static char rosbag2_interfaces__msg__WriteSplitEvent__FIELD_NAME__node_name[] = "node_name";

static rosidl_runtime_c__type_description__Field rosbag2_interfaces__msg__WriteSplitEvent__FIELDS[] = {
  {
    {rosbag2_interfaces__msg__WriteSplitEvent__FIELD_NAME__closed_file, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {rosbag2_interfaces__msg__WriteSplitEvent__FIELD_NAME__opened_file, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {rosbag2_interfaces__msg__WriteSplitEvent__FIELD_NAME__node_name, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
rosbag2_interfaces__msg__WriteSplitEvent__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {rosbag2_interfaces__msg__WriteSplitEvent__TYPE_NAME, 38, 38},
      {rosbag2_interfaces__msg__WriteSplitEvent__FIELDS, 3, 3},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# The full path of the file that was finished and closed\n"
  "string closed_file\n"
  "\n"
  "# The full path of the new file that was created to continue recording\n"
  "string opened_file\n"
  "\n"
  "# The fully qualified node name of the event sender\n"
  "string node_name";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
rosbag2_interfaces__msg__WriteSplitEvent__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {rosbag2_interfaces__msg__WriteSplitEvent__TYPE_NAME, 38, 38},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 237, 237},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
rosbag2_interfaces__msg__WriteSplitEvent__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *rosbag2_interfaces__msg__WriteSplitEvent__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
