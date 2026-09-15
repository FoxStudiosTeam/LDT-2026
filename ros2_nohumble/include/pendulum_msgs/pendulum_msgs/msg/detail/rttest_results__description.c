// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from pendulum_msgs:msg\RttestResults.idl
// generated code does not contain a copyright notice

#include "pendulum_msgs/msg/detail/rttest_results__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_pendulum_msgs
const rosidl_type_hash_t *
pendulum_msgs__msg__RttestResults__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x80, 0x59, 0xa0, 0xec, 0x73, 0x85, 0x8a, 0x30,
      0x30, 0x21, 0x80, 0xc8, 0xdf, 0xef, 0x9b, 0xa8,
      0x1a, 0x24, 0xa7, 0x71, 0x5c, 0x9c, 0x87, 0xc4,
      0x21, 0xfc, 0x07, 0xe1, 0x0a, 0xfa, 0x3e, 0xe3,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "pendulum_msgs/msg/detail/joint_command__functions.h"
#include "pendulum_msgs/msg/detail/joint_state__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t pendulum_msgs__msg__JointCommand__EXPECTED_HASH = {1, {
    0xda, 0x37, 0x80, 0x09, 0x45, 0xf2, 0x77, 0x0f,
    0x8f, 0xcd, 0x60, 0xf9, 0x60, 0xda, 0x63, 0x35,
    0x00, 0x65, 0xe1, 0x28, 0xbe, 0xf7, 0x4f, 0x02,
    0x75, 0xea, 0x29, 0x4e, 0x4d, 0xae, 0x0f, 0xeb,
  }};
static const rosidl_type_hash_t pendulum_msgs__msg__JointState__EXPECTED_HASH = {1, {
    0x59, 0x03, 0x47, 0xc9, 0x15, 0x73, 0x6e, 0x70,
    0x06, 0xc4, 0x68, 0xda, 0x18, 0xb7, 0x27, 0x7d,
    0x64, 0xf7, 0x5a, 0xbb, 0x20, 0x17, 0xcb, 0xc5,
    0x6e, 0x9e, 0x7f, 0x84, 0x3e, 0xf3, 0xa4, 0x0c,
  }};
#endif

static char pendulum_msgs__msg__RttestResults__TYPE_NAME[] = "pendulum_msgs/msg/RttestResults";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char pendulum_msgs__msg__JointCommand__TYPE_NAME[] = "pendulum_msgs/msg/JointCommand";
static char pendulum_msgs__msg__JointState__TYPE_NAME[] = "pendulum_msgs/msg/JointState";

// Define type names, field names, and default values
static char pendulum_msgs__msg__RttestResults__FIELD_NAME__stamp[] = "stamp";
static char pendulum_msgs__msg__RttestResults__FIELD_NAME__command[] = "command";
static char pendulum_msgs__msg__RttestResults__FIELD_NAME__state[] = "state";
static char pendulum_msgs__msg__RttestResults__FIELD_NAME__cur_latency[] = "cur_latency";
static char pendulum_msgs__msg__RttestResults__FIELD_NAME__mean_latency[] = "mean_latency";
static char pendulum_msgs__msg__RttestResults__FIELD_NAME__min_latency[] = "min_latency";
static char pendulum_msgs__msg__RttestResults__FIELD_NAME__max_latency[] = "max_latency";
static char pendulum_msgs__msg__RttestResults__FIELD_NAME__minor_pagefaults[] = "minor_pagefaults";
static char pendulum_msgs__msg__RttestResults__FIELD_NAME__major_pagefaults[] = "major_pagefaults";

static rosidl_runtime_c__type_description__Field pendulum_msgs__msg__RttestResults__FIELDS[] = {
  {
    {pendulum_msgs__msg__RttestResults__FIELD_NAME__stamp, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    },
    {NULL, 0, 0},
  },
  {
    {pendulum_msgs__msg__RttestResults__FIELD_NAME__command, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {pendulum_msgs__msg__JointCommand__TYPE_NAME, 30, 30},
    },
    {NULL, 0, 0},
  },
  {
    {pendulum_msgs__msg__RttestResults__FIELD_NAME__state, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {pendulum_msgs__msg__JointState__TYPE_NAME, 28, 28},
    },
    {NULL, 0, 0},
  },
  {
    {pendulum_msgs__msg__RttestResults__FIELD_NAME__cur_latency, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {pendulum_msgs__msg__RttestResults__FIELD_NAME__mean_latency, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {pendulum_msgs__msg__RttestResults__FIELD_NAME__min_latency, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {pendulum_msgs__msg__RttestResults__FIELD_NAME__max_latency, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {pendulum_msgs__msg__RttestResults__FIELD_NAME__minor_pagefaults, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {pendulum_msgs__msg__RttestResults__FIELD_NAME__major_pagefaults, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription pendulum_msgs__msg__RttestResults__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {pendulum_msgs__msg__JointCommand__TYPE_NAME, 30, 30},
    {NULL, 0, 0},
  },
  {
    {pendulum_msgs__msg__JointState__TYPE_NAME, 28, 28},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
pendulum_msgs__msg__RttestResults__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {pendulum_msgs__msg__RttestResults__TYPE_NAME, 31, 31},
      {pendulum_msgs__msg__RttestResults__FIELDS, 9, 9},
    },
    {pendulum_msgs__msg__RttestResults__REFERENCED_TYPE_DESCRIPTIONS, 3, 3},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&pendulum_msgs__msg__JointCommand__EXPECTED_HASH, pendulum_msgs__msg__JointCommand__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = pendulum_msgs__msg__JointCommand__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&pendulum_msgs__msg__JointState__EXPECTED_HASH, pendulum_msgs__msg__JointState__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = pendulum_msgs__msg__JointState__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "builtin_interfaces/Time stamp\n"
  "\n"
  "JointCommand command\n"
  "JointState state\n"
  "\n"
  "uint64 cur_latency\n"
  "float64 mean_latency\n"
  "uint64 min_latency\n"
  "uint64 max_latency\n"
  "uint64 minor_pagefaults \n"
  "uint64 major_pagefaults ";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
pendulum_msgs__msg__RttestResults__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {pendulum_msgs__msg__RttestResults__TYPE_NAME, 31, 31},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 198, 198},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
pendulum_msgs__msg__RttestResults__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[4];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 4, 4};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *pendulum_msgs__msg__RttestResults__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *pendulum_msgs__msg__JointCommand__get_individual_type_description_source(NULL);
    sources[3] = *pendulum_msgs__msg__JointState__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
