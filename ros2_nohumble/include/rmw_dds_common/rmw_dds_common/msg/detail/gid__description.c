// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from rmw_dds_common:msg\Gid.idl
// generated code does not contain a copyright notice

#include "rmw_dds_common/msg/detail/gid__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_rmw_dds_common
const rosidl_type_hash_t *
rmw_dds_common__msg__Gid__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xab, 0x6f, 0x21, 0xcf, 0xbb, 0x0a, 0x6d, 0xbb,
      0x83, 0x71, 0x61, 0xe1, 0x11, 0x0c, 0x20, 0x51,
      0xa2, 0x85, 0x0e, 0xd9, 0xf9, 0xc5, 0x39, 0x44,
      0xd7, 0x11, 0x5d, 0x9b, 0xce, 0xbe, 0xdf, 0x71,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char rmw_dds_common__msg__Gid__TYPE_NAME[] = "rmw_dds_common/msg/Gid";

// Define type names, field names, and default values
static char rmw_dds_common__msg__Gid__FIELD_NAME__data[] = "data";

static rosidl_runtime_c__type_description__Field rmw_dds_common__msg__Gid__FIELDS[] = {
  {
    {rmw_dds_common__msg__Gid__FIELD_NAME__data, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8_ARRAY,
      16,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
rmw_dds_common__msg__Gid__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {rmw_dds_common__msg__Gid__TYPE_NAME, 22, 22},
      {rmw_dds_common__msg__Gid__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "char[16] data";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
rmw_dds_common__msg__Gid__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {rmw_dds_common__msg__Gid__TYPE_NAME, 22, 22},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 14, 14},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
rmw_dds_common__msg__Gid__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *rmw_dds_common__msg__Gid__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
