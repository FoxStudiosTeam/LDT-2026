// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from rmw_dds_common:msg\ParticipantEntitiesInfo.idl
// generated code does not contain a copyright notice

#include "rmw_dds_common/msg/detail/participant_entities_info__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_rmw_dds_common
const rosidl_type_hash_t *
rmw_dds_common__msg__ParticipantEntitiesInfo__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x91, 0xa0, 0x59, 0x3b, 0xac, 0xdc, 0xc5, 0x0e,
      0xa9, 0xbd, 0xcf, 0x84, 0x9a, 0x93, 0x8b, 0x12,
      0x84, 0x12, 0xcc, 0x1e, 0xa8, 0x21, 0x24, 0x5c,
      0x66, 0x3b, 0xcd, 0x26, 0xf8, 0x3c, 0x29, 0x5e,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "rmw_dds_common/msg/detail/gid__functions.h"
#include "rmw_dds_common/msg/detail/node_entities_info__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t rmw_dds_common__msg__Gid__EXPECTED_HASH = {1, {
    0xab, 0x6f, 0x21, 0xcf, 0xbb, 0x0a, 0x6d, 0xbb,
    0x83, 0x71, 0x61, 0xe1, 0x11, 0x0c, 0x20, 0x51,
    0xa2, 0x85, 0x0e, 0xd9, 0xf9, 0xc5, 0x39, 0x44,
    0xd7, 0x11, 0x5d, 0x9b, 0xce, 0xbe, 0xdf, 0x71,
  }};
static const rosidl_type_hash_t rmw_dds_common__msg__NodeEntitiesInfo__EXPECTED_HASH = {1, {
    0x8f, 0xfe, 0xf6, 0x5e, 0xe2, 0xd0, 0x88, 0xc6,
    0x3b, 0x1e, 0x8f, 0xcd, 0x31, 0xe8, 0x00, 0xba,
    0x9f, 0xc8, 0xdb, 0xe0, 0xee, 0x15, 0xca, 0x60,
    0xd1, 0x67, 0x6d, 0xe5, 0x21, 0x80, 0x87, 0xa7,
  }};
#endif

static char rmw_dds_common__msg__ParticipantEntitiesInfo__TYPE_NAME[] = "rmw_dds_common/msg/ParticipantEntitiesInfo";
static char rmw_dds_common__msg__Gid__TYPE_NAME[] = "rmw_dds_common/msg/Gid";
static char rmw_dds_common__msg__NodeEntitiesInfo__TYPE_NAME[] = "rmw_dds_common/msg/NodeEntitiesInfo";

// Define type names, field names, and default values
static char rmw_dds_common__msg__ParticipantEntitiesInfo__FIELD_NAME__gid[] = "gid";
static char rmw_dds_common__msg__ParticipantEntitiesInfo__FIELD_NAME__node_entities_info_seq[] = "node_entities_info_seq";

static rosidl_runtime_c__type_description__Field rmw_dds_common__msg__ParticipantEntitiesInfo__FIELDS[] = {
  {
    {rmw_dds_common__msg__ParticipantEntitiesInfo__FIELD_NAME__gid, 3, 3},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {rmw_dds_common__msg__Gid__TYPE_NAME, 22, 22},
    },
    {NULL, 0, 0},
  },
  {
    {rmw_dds_common__msg__ParticipantEntitiesInfo__FIELD_NAME__node_entities_info_seq, 22, 22},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {rmw_dds_common__msg__NodeEntitiesInfo__TYPE_NAME, 35, 35},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription rmw_dds_common__msg__ParticipantEntitiesInfo__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {rmw_dds_common__msg__Gid__TYPE_NAME, 22, 22},
    {NULL, 0, 0},
  },
  {
    {rmw_dds_common__msg__NodeEntitiesInfo__TYPE_NAME, 35, 35},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
rmw_dds_common__msg__ParticipantEntitiesInfo__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {rmw_dds_common__msg__ParticipantEntitiesInfo__TYPE_NAME, 42, 42},
      {rmw_dds_common__msg__ParticipantEntitiesInfo__FIELDS, 2, 2},
    },
    {rmw_dds_common__msg__ParticipantEntitiesInfo__REFERENCED_TYPE_DESCRIPTIONS, 2, 2},
  };
  if (!constructed) {
    assert(0 == memcmp(&rmw_dds_common__msg__Gid__EXPECTED_HASH, rmw_dds_common__msg__Gid__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = rmw_dds_common__msg__Gid__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&rmw_dds_common__msg__NodeEntitiesInfo__EXPECTED_HASH, rmw_dds_common__msg__NodeEntitiesInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = rmw_dds_common__msg__NodeEntitiesInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "Gid gid\n"
  "NodeEntitiesInfo[] node_entities_info_seq";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
rmw_dds_common__msg__ParticipantEntitiesInfo__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {rmw_dds_common__msg__ParticipantEntitiesInfo__TYPE_NAME, 42, 42},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 50, 50},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
rmw_dds_common__msg__ParticipantEntitiesInfo__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[3];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 3, 3};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *rmw_dds_common__msg__ParticipantEntitiesInfo__get_individual_type_description_source(NULL),
    sources[1] = *rmw_dds_common__msg__Gid__get_individual_type_description_source(NULL);
    sources[2] = *rmw_dds_common__msg__NodeEntitiesInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
