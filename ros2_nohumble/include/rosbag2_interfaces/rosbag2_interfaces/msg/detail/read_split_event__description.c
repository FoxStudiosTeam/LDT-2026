// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from rosbag2_interfaces:msg\ReadSplitEvent.idl
// generated code does not contain a copyright notice

#include "rosbag2_interfaces/msg/detail/read_split_event__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_rosbag2_interfaces
const rosidl_type_hash_t *
rosbag2_interfaces__msg__ReadSplitEvent__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x6f, 0x21, 0xc9, 0xb5, 0x2d, 0x78, 0x83, 0x38,
      0xb0, 0x77, 0x5c, 0xec, 0xcb, 0x49, 0xf3, 0x8e,
      0x7a, 0x8b, 0xaa, 0xd7, 0xb9, 0x54, 0xf7, 0x9d,
      0xd2, 0x80, 0xba, 0xed, 0x91, 0x14, 0x5a, 0xd7,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char rosbag2_interfaces__msg__ReadSplitEvent__TYPE_NAME[] = "rosbag2_interfaces/msg/ReadSplitEvent";

// Define type names, field names, and default values
static char rosbag2_interfaces__msg__ReadSplitEvent__FIELD_NAME__closed_file[] = "closed_file";
static char rosbag2_interfaces__msg__ReadSplitEvent__FIELD_NAME__opened_file[] = "opened_file";
static char rosbag2_interfaces__msg__ReadSplitEvent__FIELD_NAME__node_name[] = "node_name";

static rosidl_runtime_c__type_description__Field rosbag2_interfaces__msg__ReadSplitEvent__FIELDS[] = {
  {
    {rosbag2_interfaces__msg__ReadSplitEvent__FIELD_NAME__closed_file, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {rosbag2_interfaces__msg__ReadSplitEvent__FIELD_NAME__opened_file, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {rosbag2_interfaces__msg__ReadSplitEvent__FIELD_NAME__node_name, 9, 9},
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
rosbag2_interfaces__msg__ReadSplitEvent__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {rosbag2_interfaces__msg__ReadSplitEvent__TYPE_NAME, 37, 37},
      {rosbag2_interfaces__msg__ReadSplitEvent__FIELDS, 3, 3},
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
  "# The full path of the new file that was opened to continue playback\n"
  "string opened_file\n"
  "\n"
  "# The fully qualified node name of the event sender\n"
  "string node_name";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
rosbag2_interfaces__msg__ReadSplitEvent__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {rosbag2_interfaces__msg__ReadSplitEvent__TYPE_NAME, 37, 37},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 235, 235},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
rosbag2_interfaces__msg__ReadSplitEvent__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *rosbag2_interfaces__msg__ReadSplitEvent__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
