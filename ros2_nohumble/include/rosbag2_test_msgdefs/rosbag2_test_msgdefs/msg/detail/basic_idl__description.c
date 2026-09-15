// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from rosbag2_test_msgdefs:msg\BasicIdl.idl
// generated code does not contain a copyright notice

#include "rosbag2_test_msgdefs/msg/detail/basic_idl__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_rosbag2_test_msgdefs
const rosidl_type_hash_t *
rosbag2_test_msgdefs__msg__BasicIdl__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x87, 0x5f, 0x81, 0x53, 0x79, 0x65, 0xa2, 0x1b,
      0xe3, 0x70, 0x3b, 0xe4, 0x99, 0x22, 0x18, 0x40,
      0x55, 0x80, 0x37, 0xd2, 0xc3, 0xfb, 0xc5, 0x05,
      0x9c, 0x40, 0xa6, 0xb0, 0xd9, 0x4d, 0x67, 0x5f,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char rosbag2_test_msgdefs__msg__BasicIdl__TYPE_NAME[] = "rosbag2_test_msgdefs/msg/BasicIdl";

// Define type names, field names, and default values
static char rosbag2_test_msgdefs__msg__BasicIdl__FIELD_NAME__x[] = "x";

static rosidl_runtime_c__type_description__Field rosbag2_test_msgdefs__msg__BasicIdl__FIELDS[] = {
  {
    {rosbag2_test_msgdefs__msg__BasicIdl__FIELD_NAME__x, 1, 1},
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
rosbag2_test_msgdefs__msg__BasicIdl__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {rosbag2_test_msgdefs__msg__BasicIdl__TYPE_NAME, 33, 33},
      {rosbag2_test_msgdefs__msg__BasicIdl__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "module rosbag2_test_msgdefs {\n"
  "  module msg {\n"
  "    struct BasicIdl {\n"
  "        float x;\n"
  "    };\n"
  "  };\n"
  "};";

static char idl_encoding[] = "idl";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
rosbag2_test_msgdefs__msg__BasicIdl__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {rosbag2_test_msgdefs__msg__BasicIdl__TYPE_NAME, 33, 33},
    {idl_encoding, 3, 3},
    {toplevel_type_raw_source, 99, 99},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
rosbag2_test_msgdefs__msg__BasicIdl__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *rosbag2_test_msgdefs__msg__BasicIdl__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
