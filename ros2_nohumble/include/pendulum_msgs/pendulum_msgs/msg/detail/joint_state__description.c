// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from pendulum_msgs:msg\JointState.idl
// generated code does not contain a copyright notice

#include "pendulum_msgs/msg/detail/joint_state__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_pendulum_msgs
const rosidl_type_hash_t *
pendulum_msgs__msg__JointState__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x59, 0x03, 0x47, 0xc9, 0x15, 0x73, 0x6e, 0x70,
      0x06, 0xc4, 0x68, 0xda, 0x18, 0xb7, 0x27, 0x7d,
      0x64, 0xf7, 0x5a, 0xbb, 0x20, 0x17, 0xcb, 0xc5,
      0x6e, 0x9e, 0x7f, 0x84, 0x3e, 0xf3, 0xa4, 0x0c,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char pendulum_msgs__msg__JointState__TYPE_NAME[] = "pendulum_msgs/msg/JointState";

// Define type names, field names, and default values
static char pendulum_msgs__msg__JointState__FIELD_NAME__position[] = "position";
static char pendulum_msgs__msg__JointState__FIELD_NAME__velocity[] = "velocity";
static char pendulum_msgs__msg__JointState__FIELD_NAME__effort[] = "effort";

static rosidl_runtime_c__type_description__Field pendulum_msgs__msg__JointState__FIELDS[] = {
  {
    {pendulum_msgs__msg__JointState__FIELD_NAME__position, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {pendulum_msgs__msg__JointState__FIELD_NAME__velocity, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {pendulum_msgs__msg__JointState__FIELD_NAME__effort, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
pendulum_msgs__msg__JointState__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {pendulum_msgs__msg__JointState__TYPE_NAME, 28, 28},
      {pendulum_msgs__msg__JointState__FIELDS, 3, 3},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float64 position\n"
  "float64 velocity\n"
  "float64 effort";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
pendulum_msgs__msg__JointState__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {pendulum_msgs__msg__JointState__TYPE_NAME, 28, 28},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 49, 49},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
pendulum_msgs__msg__JointState__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *pendulum_msgs__msg__JointState__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
