// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from tf2_msgs:msg\TF2Error.idl
// generated code does not contain a copyright notice

#include "tf2_msgs/msg/detail/tf2_error__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_tf2_msgs
const rosidl_type_hash_t *
tf2_msgs__msg__TF2Error__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xdb, 0x24, 0x85, 0xe7, 0xd6, 0xa0, 0xec, 0x75,
      0xbf, 0x08, 0x7e, 0x05, 0x8e, 0xe4, 0x5d, 0xf6,
      0x82, 0xac, 0xc3, 0xa6, 0x21, 0xca, 0x77, 0x80,
      0x50, 0x3d, 0x10, 0xaa, 0xc1, 0x41, 0x80, 0x9a,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char tf2_msgs__msg__TF2Error__TYPE_NAME[] = "tf2_msgs/msg/TF2Error";

// Define type names, field names, and default values
static char tf2_msgs__msg__TF2Error__FIELD_NAME__error[] = "error";
static char tf2_msgs__msg__TF2Error__FIELD_NAME__error_string[] = "error_string";

static rosidl_runtime_c__type_description__Field tf2_msgs__msg__TF2Error__FIELDS[] = {
  {
    {tf2_msgs__msg__TF2Error__FIELD_NAME__error, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {tf2_msgs__msg__TF2Error__FIELD_NAME__error_string, 12, 12},
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
tf2_msgs__msg__TF2Error__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {tf2_msgs__msg__TF2Error__TYPE_NAME, 21, 21},
      {tf2_msgs__msg__TF2Error__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "uint8 NO_ERROR = 0\n"
  "uint8 LOOKUP_ERROR = 1\n"
  "uint8 CONNECTIVITY_ERROR = 2\n"
  "uint8 EXTRAPOLATION_ERROR = 3\n"
  "uint8 INVALID_ARGUMENT_ERROR = 4\n"
  "uint8 TIMEOUT_ERROR = 5\n"
  "uint8 TRANSFORM_ERROR = 6\n"
  "\n"
  "uint8 error\n"
  "string error_string";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
tf2_msgs__msg__TF2Error__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {tf2_msgs__msg__TF2Error__TYPE_NAME, 21, 21},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 217, 217},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
tf2_msgs__msg__TF2Error__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *tf2_msgs__msg__TF2Error__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
