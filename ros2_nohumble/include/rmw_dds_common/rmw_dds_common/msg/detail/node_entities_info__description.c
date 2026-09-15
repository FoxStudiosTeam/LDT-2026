// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from rmw_dds_common:msg\NodeEntitiesInfo.idl
// generated code does not contain a copyright notice

#include "rmw_dds_common/msg/detail/node_entities_info__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_rmw_dds_common
const rosidl_type_hash_t *
rmw_dds_common__msg__NodeEntitiesInfo__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x8f, 0xfe, 0xf6, 0x5e, 0xe2, 0xd0, 0x88, 0xc6,
      0x3b, 0x1e, 0x8f, 0xcd, 0x31, 0xe8, 0x00, 0xba,
      0x9f, 0xc8, 0xdb, 0xe0, 0xee, 0x15, 0xca, 0x60,
      0xd1, 0x67, 0x6d, 0xe5, 0x21, 0x80, 0x87, 0xa7,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "rmw_dds_common/msg/detail/gid__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t rmw_dds_common__msg__Gid__EXPECTED_HASH = {1, {
    0xab, 0x6f, 0x21, 0xcf, 0xbb, 0x0a, 0x6d, 0xbb,
    0x83, 0x71, 0x61, 0xe1, 0x11, 0x0c, 0x20, 0x51,
    0xa2, 0x85, 0x0e, 0xd9, 0xf9, 0xc5, 0x39, 0x44,
    0xd7, 0x11, 0x5d, 0x9b, 0xce, 0xbe, 0xdf, 0x71,
  }};
#endif

static char rmw_dds_common__msg__NodeEntitiesInfo__TYPE_NAME[] = "rmw_dds_common/msg/NodeEntitiesInfo";
static char rmw_dds_common__msg__Gid__TYPE_NAME[] = "rmw_dds_common/msg/Gid";

// Define type names, field names, and default values
static char rmw_dds_common__msg__NodeEntitiesInfo__FIELD_NAME__node_namespace[] = "node_namespace";
static char rmw_dds_common__msg__NodeEntitiesInfo__FIELD_NAME__node_name[] = "node_name";
static char rmw_dds_common__msg__NodeEntitiesInfo__FIELD_NAME__reader_gid_seq[] = "reader_gid_seq";
static char rmw_dds_common__msg__NodeEntitiesInfo__FIELD_NAME__writer_gid_seq[] = "writer_gid_seq";

static rosidl_runtime_c__type_description__Field rmw_dds_common__msg__NodeEntitiesInfo__FIELDS[] = {
  {
    {rmw_dds_common__msg__NodeEntitiesInfo__FIELD_NAME__node_namespace, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOUNDED_STRING,
      0,
      256,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {rmw_dds_common__msg__NodeEntitiesInfo__FIELD_NAME__node_name, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOUNDED_STRING,
      0,
      256,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {rmw_dds_common__msg__NodeEntitiesInfo__FIELD_NAME__reader_gid_seq, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {rmw_dds_common__msg__Gid__TYPE_NAME, 22, 22},
    },
    {NULL, 0, 0},
  },
  {
    {rmw_dds_common__msg__NodeEntitiesInfo__FIELD_NAME__writer_gid_seq, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {rmw_dds_common__msg__Gid__TYPE_NAME, 22, 22},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription rmw_dds_common__msg__NodeEntitiesInfo__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {rmw_dds_common__msg__Gid__TYPE_NAME, 22, 22},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
rmw_dds_common__msg__NodeEntitiesInfo__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {rmw_dds_common__msg__NodeEntitiesInfo__TYPE_NAME, 35, 35},
      {rmw_dds_common__msg__NodeEntitiesInfo__FIELDS, 4, 4},
    },
    {rmw_dds_common__msg__NodeEntitiesInfo__REFERENCED_TYPE_DESCRIPTIONS, 1, 1},
  };
  if (!constructed) {
    assert(0 == memcmp(&rmw_dds_common__msg__Gid__EXPECTED_HASH, rmw_dds_common__msg__Gid__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = rmw_dds_common__msg__Gid__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string<=256 node_namespace\n"
  "string<=256 node_name\n"
  "Gid[] reader_gid_seq\n"
  "Gid[] writer_gid_seq";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
rmw_dds_common__msg__NodeEntitiesInfo__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {rmw_dds_common__msg__NodeEntitiesInfo__TYPE_NAME, 35, 35},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 91, 91},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
rmw_dds_common__msg__NodeEntitiesInfo__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[2];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 2, 2};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *rmw_dds_common__msg__NodeEntitiesInfo__get_individual_type_description_source(NULL),
    sources[1] = *rmw_dds_common__msg__Gid__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
