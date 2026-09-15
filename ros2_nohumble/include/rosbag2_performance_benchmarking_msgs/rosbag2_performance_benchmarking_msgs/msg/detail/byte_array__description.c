// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from rosbag2_performance_benchmarking_msgs:msg\ByteArray.idl
// generated code does not contain a copyright notice

#include "rosbag2_performance_benchmarking_msgs/msg/detail/byte_array__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_rosbag2_performance_benchmarking_msgs
const rosidl_type_hash_t *
rosbag2_performance_benchmarking_msgs__msg__ByteArray__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x49, 0x0d, 0x5e, 0x21, 0x0a, 0xfc, 0x7c, 0xf3,
      0x0c, 0xfd, 0xf4, 0x31, 0xe1, 0xcc, 0x1f, 0x88,
      0x29, 0x1a, 0x9e, 0x73, 0x38, 0x57, 0x29, 0xbf,
      0x31, 0x9a, 0xfa, 0xfa, 0x90, 0x82, 0xb3, 0x28,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char rosbag2_performance_benchmarking_msgs__msg__ByteArray__TYPE_NAME[] = "rosbag2_performance_benchmarking_msgs/msg/ByteArray";

// Define type names, field names, and default values
static char rosbag2_performance_benchmarking_msgs__msg__ByteArray__FIELD_NAME__data[] = "data";

static rosidl_runtime_c__type_description__Field rosbag2_performance_benchmarking_msgs__msg__ByteArray__FIELDS[] = {
  {
    {rosbag2_performance_benchmarking_msgs__msg__ByteArray__FIELD_NAME__data, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BYTE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
rosbag2_performance_benchmarking_msgs__msg__ByteArray__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {rosbag2_performance_benchmarking_msgs__msg__ByteArray__TYPE_NAME, 51, 51},
      {rosbag2_performance_benchmarking_msgs__msg__ByteArray__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "byte[]            data          # array of data";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
rosbag2_performance_benchmarking_msgs__msg__ByteArray__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {rosbag2_performance_benchmarking_msgs__msg__ByteArray__TYPE_NAME, 51, 51},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 48, 48},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
rosbag2_performance_benchmarking_msgs__msg__ByteArray__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *rosbag2_performance_benchmarking_msgs__msg__ByteArray__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
