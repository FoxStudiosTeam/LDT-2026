// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from map_msgs:msg\ProjectedMapInfo.idl
// generated code does not contain a copyright notice

#include "map_msgs/msg/detail/projected_map_info__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_map_msgs
const rosidl_type_hash_t *
map_msgs__msg__ProjectedMapInfo__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x99, 0xf9, 0x57, 0x92, 0xa7, 0xed, 0x7a, 0x78,
      0x45, 0x66, 0xad, 0xd9, 0x25, 0xce, 0x2a, 0xc1,
      0x3e, 0x61, 0xcd, 0xb1, 0x4e, 0x1e, 0x68, 0x04,
      0xca, 0x8e, 0x3f, 0xe0, 0xa5, 0xba, 0xaf, 0x13,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char map_msgs__msg__ProjectedMapInfo__TYPE_NAME[] = "map_msgs/msg/ProjectedMapInfo";

// Define type names, field names, and default values
static char map_msgs__msg__ProjectedMapInfo__FIELD_NAME__frame_id[] = "frame_id";
static char map_msgs__msg__ProjectedMapInfo__FIELD_NAME__x[] = "x";
static char map_msgs__msg__ProjectedMapInfo__FIELD_NAME__y[] = "y";
static char map_msgs__msg__ProjectedMapInfo__FIELD_NAME__width[] = "width";
static char map_msgs__msg__ProjectedMapInfo__FIELD_NAME__height[] = "height";
static char map_msgs__msg__ProjectedMapInfo__FIELD_NAME__min_z[] = "min_z";
static char map_msgs__msg__ProjectedMapInfo__FIELD_NAME__max_z[] = "max_z";

static rosidl_runtime_c__type_description__Field map_msgs__msg__ProjectedMapInfo__FIELDS[] = {
  {
    {map_msgs__msg__ProjectedMapInfo__FIELD_NAME__frame_id, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {map_msgs__msg__ProjectedMapInfo__FIELD_NAME__x, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {map_msgs__msg__ProjectedMapInfo__FIELD_NAME__y, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {map_msgs__msg__ProjectedMapInfo__FIELD_NAME__width, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {map_msgs__msg__ProjectedMapInfo__FIELD_NAME__height, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {map_msgs__msg__ProjectedMapInfo__FIELD_NAME__min_z, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {map_msgs__msg__ProjectedMapInfo__FIELD_NAME__max_z, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
map_msgs__msg__ProjectedMapInfo__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {map_msgs__msg__ProjectedMapInfo__TYPE_NAME, 29, 29},
      {map_msgs__msg__ProjectedMapInfo__FIELDS, 7, 7},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string frame_id\n"
  "float64 x\n"
  "float64 y\n"
  "float64 width\n"
  "float64 height\n"
  "float64 min_z\n"
  "float64 max_z";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
map_msgs__msg__ProjectedMapInfo__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {map_msgs__msg__ProjectedMapInfo__TYPE_NAME, 29, 29},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 92, 92},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
map_msgs__msg__ProjectedMapInfo__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *map_msgs__msg__ProjectedMapInfo__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
