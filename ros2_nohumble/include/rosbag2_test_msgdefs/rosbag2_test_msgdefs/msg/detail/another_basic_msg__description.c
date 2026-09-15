// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from rosbag2_test_msgdefs:msg\AnotherBasicMsg.idl
// generated code does not contain a copyright notice

#include "rosbag2_test_msgdefs/msg/detail/another_basic_msg__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_rosbag2_test_msgdefs
const rosidl_type_hash_t *
rosbag2_test_msgdefs__msg__AnotherBasicMsg__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x03, 0xf6, 0x74, 0x12, 0x5e, 0xa1, 0xfc, 0x2d,
      0xb2, 0x62, 0xd4, 0x4c, 0x67, 0x63, 0xd0, 0x8f,
      0x9d, 0xb2, 0x6b, 0xa6, 0xb6, 0xd9, 0xc2, 0x14,
      0x6e, 0x03, 0x2f, 0x1a, 0x6a, 0xcd, 0xbe, 0x82,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char rosbag2_test_msgdefs__msg__AnotherBasicMsg__TYPE_NAME[] = "rosbag2_test_msgdefs/msg/AnotherBasicMsg";

// Define type names, field names, and default values
static char rosbag2_test_msgdefs__msg__AnotherBasicMsg__FIELD_NAME__c[] = "c";

static rosidl_runtime_c__type_description__Field rosbag2_test_msgdefs__msg__AnotherBasicMsg__FIELDS[] = {
  {
    {rosbag2_test_msgdefs__msg__AnotherBasicMsg__FIELD_NAME__c, 1, 1},
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
rosbag2_test_msgdefs__msg__AnotherBasicMsg__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {rosbag2_test_msgdefs__msg__AnotherBasicMsg__TYPE_NAME, 40, 40},
      {rosbag2_test_msgdefs__msg__AnotherBasicMsg__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float32 c";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
rosbag2_test_msgdefs__msg__AnotherBasicMsg__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {rosbag2_test_msgdefs__msg__AnotherBasicMsg__TYPE_NAME, 40, 40},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 10, 10},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
rosbag2_test_msgdefs__msg__AnotherBasicMsg__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *rosbag2_test_msgdefs__msg__AnotherBasicMsg__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
