// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from test_rosidl_buffer:msg\ByteArray.idl
// generated code does not contain a copyright notice

#include "test_rosidl_buffer/msg/detail/byte_array__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_test_rosidl_buffer
const rosidl_type_hash_t *
test_rosidl_buffer__msg__ByteArray__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xbb, 0x2f, 0x83, 0x86, 0x20, 0x24, 0x46, 0x28,
      0xb4, 0x64, 0x5d, 0xb1, 0xe5, 0x2e, 0x63, 0x5e,
      0xb5, 0x7f, 0x56, 0x90, 0xef, 0xe3, 0xd9, 0x77,
      0x57, 0x34, 0xfe, 0x2e, 0x41, 0x9a, 0x6d, 0xa4,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char test_rosidl_buffer__msg__ByteArray__TYPE_NAME[] = "test_rosidl_buffer/msg/ByteArray";

// Define type names, field names, and default values
static char test_rosidl_buffer__msg__ByteArray__FIELD_NAME__seq[] = "seq";
static char test_rosidl_buffer__msg__ByteArray__FIELD_NAME__data[] = "data";

static rosidl_runtime_c__type_description__Field test_rosidl_buffer__msg__ByteArray__FIELDS[] = {
  {
    {test_rosidl_buffer__msg__ByteArray__FIELD_NAME__seq, 3, 3},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {test_rosidl_buffer__msg__ByteArray__FIELD_NAME__data, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
test_rosidl_buffer__msg__ByteArray__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {test_rosidl_buffer__msg__ByteArray__TYPE_NAME, 32, 32},
      {test_rosidl_buffer__msg__ByteArray__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# Minimal payload message used by the pub/sub launch tests.\n"
  "# The `data` field is generated as rosidl::Buffer<uint8_t>, which is the\n"
  "# feature under test.\n"
  "\n"
  "uint32 seq\n"
  "uint8[] data";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
test_rosidl_buffer__msg__ByteArray__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {test_rosidl_buffer__msg__ByteArray__TYPE_NAME, 32, 32},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 180, 180},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
test_rosidl_buffer__msg__ByteArray__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *test_rosidl_buffer__msg__ByteArray__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
