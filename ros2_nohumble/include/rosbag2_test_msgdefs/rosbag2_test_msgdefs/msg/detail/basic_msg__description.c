// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from rosbag2_test_msgdefs:msg\BasicMsg.idl
// generated code does not contain a copyright notice

#include "rosbag2_test_msgdefs/msg/detail/basic_msg__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_rosbag2_test_msgdefs
const rosidl_type_hash_t *
rosbag2_test_msgdefs__msg__BasicMsg__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x99, 0xf0, 0xb9, 0x73, 0x2f, 0xb9, 0xa9, 0x0d,
      0xec, 0x3b, 0xb4, 0x97, 0x15, 0xd2, 0x7c, 0xa1,
      0x19, 0x68, 0xd3, 0x15, 0x4a, 0x7e, 0xde, 0x29,
      0xfc, 0xdb, 0x50, 0x27, 0xa4, 0xd4, 0x82, 0xb4,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char rosbag2_test_msgdefs__msg__BasicMsg__TYPE_NAME[] = "rosbag2_test_msgdefs/msg/BasicMsg";

// Define type names, field names, and default values
static char rosbag2_test_msgdefs__msg__BasicMsg__FIELD_NAME__c[] = "c";

static rosidl_runtime_c__type_description__Field rosbag2_test_msgdefs__msg__BasicMsg__FIELDS[] = {
  {
    {rosbag2_test_msgdefs__msg__BasicMsg__FIELD_NAME__c, 1, 1},
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
rosbag2_test_msgdefs__msg__BasicMsg__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {rosbag2_test_msgdefs__msg__BasicMsg__TYPE_NAME, 33, 33},
      {rosbag2_test_msgdefs__msg__BasicMsg__FIELDS, 1, 1},
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
rosbag2_test_msgdefs__msg__BasicMsg__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {rosbag2_test_msgdefs__msg__BasicMsg__TYPE_NAME, 33, 33},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 10, 10},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
rosbag2_test_msgdefs__msg__BasicMsg__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *rosbag2_test_msgdefs__msg__BasicMsg__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
