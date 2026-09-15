// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from pendulum_msgs:msg\JointCommand.idl
// generated code does not contain a copyright notice

#include "pendulum_msgs/msg/detail/joint_command__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_pendulum_msgs
const rosidl_type_hash_t *
pendulum_msgs__msg__JointCommand__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xda, 0x37, 0x80, 0x09, 0x45, 0xf2, 0x77, 0x0f,
      0x8f, 0xcd, 0x60, 0xf9, 0x60, 0xda, 0x63, 0x35,
      0x00, 0x65, 0xe1, 0x28, 0xbe, 0xf7, 0x4f, 0x02,
      0x75, 0xea, 0x29, 0x4e, 0x4d, 0xae, 0x0f, 0xeb,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char pendulum_msgs__msg__JointCommand__TYPE_NAME[] = "pendulum_msgs/msg/JointCommand";

// Define type names, field names, and default values
static char pendulum_msgs__msg__JointCommand__FIELD_NAME__position[] = "position";

static rosidl_runtime_c__type_description__Field pendulum_msgs__msg__JointCommand__FIELDS[] = {
  {
    {pendulum_msgs__msg__JointCommand__FIELD_NAME__position, 8, 8},
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
pendulum_msgs__msg__JointCommand__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {pendulum_msgs__msg__JointCommand__TYPE_NAME, 30, 30},
      {pendulum_msgs__msg__JointCommand__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float64 position";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
pendulum_msgs__msg__JointCommand__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {pendulum_msgs__msg__JointCommand__TYPE_NAME, 30, 30},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 17, 17},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
pendulum_msgs__msg__JointCommand__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *pendulum_msgs__msg__JointCommand__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
