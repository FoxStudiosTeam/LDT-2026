// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from test_rosidl_buffer:msg\ByteArrayList.idl
// generated code does not contain a copyright notice

#include "test_rosidl_buffer/msg/detail/byte_array_list__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_test_rosidl_buffer
const rosidl_type_hash_t *
test_rosidl_buffer__msg__ByteArrayList__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x07, 0x8d, 0xa2, 0x6d, 0x1f, 0x5e, 0x0b, 0x51,
      0x20, 0x0c, 0x84, 0x6b, 0xdf, 0x5d, 0x92, 0xfb,
      0x00, 0xd3, 0xf2, 0x7f, 0x42, 0xa1, 0x87, 0x7e,
      0x9d, 0x5c, 0x17, 0x17, 0x2f, 0x43, 0x52, 0xa5,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "test_rosidl_buffer/msg/detail/byte_array__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t test_rosidl_buffer__msg__ByteArray__EXPECTED_HASH = {1, {
    0xbb, 0x2f, 0x83, 0x86, 0x20, 0x24, 0x46, 0x28,
    0xb4, 0x64, 0x5d, 0xb1, 0xe5, 0x2e, 0x63, 0x5e,
    0xb5, 0x7f, 0x56, 0x90, 0xef, 0xe3, 0xd9, 0x77,
    0x57, 0x34, 0xfe, 0x2e, 0x41, 0x9a, 0x6d, 0xa4,
  }};
#endif

static char test_rosidl_buffer__msg__ByteArrayList__TYPE_NAME[] = "test_rosidl_buffer/msg/ByteArrayList";
static char test_rosidl_buffer__msg__ByteArray__TYPE_NAME[] = "test_rosidl_buffer/msg/ByteArray";

// Define type names, field names, and default values
static char test_rosidl_buffer__msg__ByteArrayList__FIELD_NAME__items[] = "items";

static rosidl_runtime_c__type_description__Field test_rosidl_buffer__msg__ByteArrayList__FIELDS[] = {
  {
    {test_rosidl_buffer__msg__ByteArrayList__FIELD_NAME__items, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {test_rosidl_buffer__msg__ByteArray__TYPE_NAME, 32, 32},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription test_rosidl_buffer__msg__ByteArrayList__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {test_rosidl_buffer__msg__ByteArray__TYPE_NAME, 32, 32},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
test_rosidl_buffer__msg__ByteArrayList__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {test_rosidl_buffer__msg__ByteArrayList__TYPE_NAME, 36, 36},
      {test_rosidl_buffer__msg__ByteArrayList__FIELDS, 1, 1},
    },
    {test_rosidl_buffer__msg__ByteArrayList__REFERENCED_TYPE_DESCRIPTIONS, 1, 1},
  };
  if (!constructed) {
    assert(0 == memcmp(&test_rosidl_buffer__msg__ByteArray__EXPECTED_HASH, test_rosidl_buffer__msg__ByteArray__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = test_rosidl_buffer__msg__ByteArray__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# Minimal nested payload used by the pub/sub launch tests.\n"
  "# Each ByteArray item contains a uint8[] field generated as rosidl::Buffer<uint8_t>.\n"
  "\n"
  "ByteArray[] items";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
test_rosidl_buffer__msg__ByteArrayList__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {test_rosidl_buffer__msg__ByteArrayList__TYPE_NAME, 36, 36},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 163, 163},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
test_rosidl_buffer__msg__ByteArrayList__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[2];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 2, 2};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *test_rosidl_buffer__msg__ByteArrayList__get_individual_type_description_source(NULL),
    sources[1] = *test_rosidl_buffer__msg__ByteArray__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
