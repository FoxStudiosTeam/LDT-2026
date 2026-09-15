// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from test_rosidl_buffer:msg\TestBufferDescriptor.idl
// generated code does not contain a copyright notice

#include "test_rosidl_buffer/msg/detail/test_buffer_descriptor__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_test_rosidl_buffer
const rosidl_type_hash_t *
test_rosidl_buffer__msg__TestBufferDescriptor__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xaa, 0x79, 0x70, 0x96, 0xa7, 0x6e, 0x8e, 0xf6,
      0xc5, 0x55, 0x41, 0xe7, 0x94, 0x57, 0x2e, 0x82,
      0xdf, 0x2a, 0x65, 0x69, 0xa7, 0x93, 0xf6, 0x4c,
      0x52, 0xbf, 0x61, 0xae, 0xc7, 0x6a, 0x24, 0x4c,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char test_rosidl_buffer__msg__TestBufferDescriptor__TYPE_NAME[] = "test_rosidl_buffer/msg/TestBufferDescriptor";

// Define type names, field names, and default values
static char test_rosidl_buffer__msg__TestBufferDescriptor__FIELD_NAME__size[] = "size";
static char test_rosidl_buffer__msg__TestBufferDescriptor__FIELD_NAME__data_hash[] = "data_hash";
static char test_rosidl_buffer__msg__TestBufferDescriptor__FIELD_NAME__data[] = "data";

static rosidl_runtime_c__type_description__Field test_rosidl_buffer__msg__TestBufferDescriptor__FIELDS[] = {
  {
    {test_rosidl_buffer__msg__TestBufferDescriptor__FIELD_NAME__size, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {test_rosidl_buffer__msg__TestBufferDescriptor__FIELD_NAME__data_hash, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {test_rosidl_buffer__msg__TestBufferDescriptor__FIELD_NAME__data, 4, 4},
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
test_rosidl_buffer__msg__TestBufferDescriptor__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {test_rosidl_buffer__msg__TestBufferDescriptor__TYPE_NAME, 43, 43},
      {test_rosidl_buffer__msg__TestBufferDescriptor__FIELDS, 3, 3},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# Wire descriptor used by the in-tree test buffer backend.\n"
  "\n"
  "uint64 size                    # number of elements in the original buffer\n"
  "uint64 data_hash               # FNV-1a hash of the element bytes\n"
  "uint8[] data                   # raw element bytes (size * sizeof(T))";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
test_rosidl_buffer__msg__TestBufferDescriptor__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {test_rosidl_buffer__msg__TestBufferDescriptor__TYPE_NAME, 43, 43},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 271, 271},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
test_rosidl_buffer__msg__TestBufferDescriptor__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *test_rosidl_buffer__msg__TestBufferDescriptor__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
