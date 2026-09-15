// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from turtlesim_msgs:msg\Pose.idl
// generated code does not contain a copyright notice

#include "turtlesim_msgs/msg/detail/pose__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_turtlesim_msgs
const rosidl_type_hash_t *
turtlesim_msgs__msg__Pose__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x37, 0xb0, 0x7a, 0xce, 0x09, 0xa0, 0xed, 0x2c,
      0x5b, 0x77, 0x4b, 0x14, 0x10, 0xde, 0xc9, 0x72,
      0xdf, 0xd1, 0xd2, 0x92, 0xde, 0x56, 0x56, 0xeb,
      0xc2, 0xb0, 0x75, 0xac, 0x64, 0x6e, 0x09, 0xc8,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char turtlesim_msgs__msg__Pose__TYPE_NAME[] = "turtlesim_msgs/msg/Pose";

// Define type names, field names, and default values
static char turtlesim_msgs__msg__Pose__FIELD_NAME__x[] = "x";
static char turtlesim_msgs__msg__Pose__FIELD_NAME__y[] = "y";
static char turtlesim_msgs__msg__Pose__FIELD_NAME__theta[] = "theta";
static char turtlesim_msgs__msg__Pose__FIELD_NAME__linear_velocity[] = "linear_velocity";
static char turtlesim_msgs__msg__Pose__FIELD_NAME__angular_velocity[] = "angular_velocity";

static rosidl_runtime_c__type_description__Field turtlesim_msgs__msg__Pose__FIELDS[] = {
  {
    {turtlesim_msgs__msg__Pose__FIELD_NAME__x, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {turtlesim_msgs__msg__Pose__FIELD_NAME__y, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {turtlesim_msgs__msg__Pose__FIELD_NAME__theta, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {turtlesim_msgs__msg__Pose__FIELD_NAME__linear_velocity, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {turtlesim_msgs__msg__Pose__FIELD_NAME__angular_velocity, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
turtlesim_msgs__msg__Pose__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {turtlesim_msgs__msg__Pose__TYPE_NAME, 23, 23},
      {turtlesim_msgs__msg__Pose__FIELDS, 5, 5},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float32 x\n"
  "float32 y\n"
  "float32 theta\n"
  "\n"
  "float32 linear_velocity\n"
  "float32 angular_velocity";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
turtlesim_msgs__msg__Pose__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {turtlesim_msgs__msg__Pose__TYPE_NAME, 23, 23},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 83, 83},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
turtlesim_msgs__msg__Pose__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *turtlesim_msgs__msg__Pose__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
