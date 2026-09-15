// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from turtlesim_msgs:msg\Color.idl
// generated code does not contain a copyright notice

#include "turtlesim_msgs/msg/detail/color__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_turtlesim_msgs
const rosidl_type_hash_t *
turtlesim_msgs__msg__Color__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xf5, 0xb5, 0x66, 0x6d, 0xa8, 0xf1, 0x9d, 0x47,
      0x42, 0x00, 0x26, 0x18, 0x73, 0x89, 0xc7, 0x50,
      0xb6, 0x69, 0x98, 0x43, 0x68, 0x78, 0xdd, 0x63,
      0x1a, 0xe8, 0x34, 0x98, 0x05, 0x9a, 0x59, 0xe2,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char turtlesim_msgs__msg__Color__TYPE_NAME[] = "turtlesim_msgs/msg/Color";

// Define type names, field names, and default values
static char turtlesim_msgs__msg__Color__FIELD_NAME__r[] = "r";
static char turtlesim_msgs__msg__Color__FIELD_NAME__g[] = "g";
static char turtlesim_msgs__msg__Color__FIELD_NAME__b[] = "b";

static rosidl_runtime_c__type_description__Field turtlesim_msgs__msg__Color__FIELDS[] = {
  {
    {turtlesim_msgs__msg__Color__FIELD_NAME__r, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {turtlesim_msgs__msg__Color__FIELD_NAME__g, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {turtlesim_msgs__msg__Color__FIELD_NAME__b, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
turtlesim_msgs__msg__Color__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {turtlesim_msgs__msg__Color__TYPE_NAME, 24, 24},
      {turtlesim_msgs__msg__Color__FIELDS, 3, 3},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "uint8 r\n"
  "uint8 g\n"
  "uint8 b";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
turtlesim_msgs__msg__Color__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {turtlesim_msgs__msg__Color__TYPE_NAME, 24, 24},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 24, 24},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
turtlesim_msgs__msg__Color__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *turtlesim_msgs__msg__Color__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
