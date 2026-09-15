// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from tf2_msgs:srv\FrameGraph.idl
// generated code does not contain a copyright notice

#include "tf2_msgs/srv/detail/frame_graph__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_tf2_msgs
const rosidl_type_hash_t *
tf2_msgs__srv__FrameGraph__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x0d, 0x1f, 0xbc, 0x62, 0x22, 0xc0, 0x18, 0xba,
      0x5f, 0x33, 0x82, 0x29, 0x04, 0xa2, 0xfd, 0xd4,
      0x06, 0x37, 0x05, 0x28, 0x99, 0x56, 0xd3, 0xfd,
      0xde, 0x07, 0xcd, 0x8c, 0x50, 0xfe, 0x80, 0x67,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_tf2_msgs
const rosidl_type_hash_t *
tf2_msgs__srv__FrameGraph_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x4c, 0xc5, 0x65, 0xda, 0x6b, 0x64, 0x72, 0x6d,
      0x0b, 0x0b, 0xe1, 0xce, 0x20, 0xf3, 0xa3, 0xa6,
      0x95, 0x67, 0x9b, 0x84, 0x1a, 0x79, 0xab, 0xfc,
      0xa2, 0xfc, 0xdc, 0x94, 0xf5, 0x62, 0xb0, 0x8d,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_tf2_msgs
const rosidl_type_hash_t *
tf2_msgs__srv__FrameGraph_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xe3, 0x3d, 0x54, 0x73, 0xce, 0x0f, 0xac, 0x04,
      0xc6, 0x62, 0x03, 0x77, 0x9f, 0x2b, 0x71, 0x9a,
      0x9d, 0xe0, 0xf8, 0x38, 0x8b, 0x24, 0x88, 0x52,
      0xd3, 0xa4, 0x7a, 0x01, 0x9e, 0x62, 0xe3, 0x6d,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_tf2_msgs
const rosidl_type_hash_t *
tf2_msgs__srv__FrameGraph_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x97, 0xe5, 0x49, 0x4f, 0x0a, 0xf6, 0x40, 0x46,
      0xab, 0xdb, 0x3f, 0x1f, 0xc9, 0x1a, 0x91, 0xf0,
      0xa3, 0xac, 0x7f, 0x11, 0x32, 0xdc, 0xfe, 0x32,
      0xf3, 0x50, 0x60, 0x12, 0x27, 0xda, 0xa8, 0x17,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "service_msgs/msg/detail/service_event_info__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t service_msgs__msg__ServiceEventInfo__EXPECTED_HASH = {1, {
    0x41, 0xbc, 0xbb, 0xe0, 0x7a, 0x75, 0xc9, 0xb5,
    0x2b, 0xc9, 0x6b, 0xfd, 0x5c, 0x24, 0xd7, 0xf0,
    0xfc, 0x0a, 0x08, 0xc0, 0xcb, 0x79, 0x21, 0xb3,
    0x37, 0x3c, 0x57, 0x32, 0x34, 0x5a, 0x6f, 0x45,
  }};
#endif

static char tf2_msgs__srv__FrameGraph__TYPE_NAME[] = "tf2_msgs/srv/FrameGraph";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";
static char tf2_msgs__srv__FrameGraph_Event__TYPE_NAME[] = "tf2_msgs/srv/FrameGraph_Event";
static char tf2_msgs__srv__FrameGraph_Request__TYPE_NAME[] = "tf2_msgs/srv/FrameGraph_Request";
static char tf2_msgs__srv__FrameGraph_Response__TYPE_NAME[] = "tf2_msgs/srv/FrameGraph_Response";

// Define type names, field names, and default values
static char tf2_msgs__srv__FrameGraph__FIELD_NAME__request_message[] = "request_message";
static char tf2_msgs__srv__FrameGraph__FIELD_NAME__response_message[] = "response_message";
static char tf2_msgs__srv__FrameGraph__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field tf2_msgs__srv__FrameGraph__FIELDS[] = {
  {
    {tf2_msgs__srv__FrameGraph__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {tf2_msgs__srv__FrameGraph_Request__TYPE_NAME, 31, 31},
    },
    {NULL, 0, 0},
  },
  {
    {tf2_msgs__srv__FrameGraph__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {tf2_msgs__srv__FrameGraph_Response__TYPE_NAME, 32, 32},
    },
    {NULL, 0, 0},
  },
  {
    {tf2_msgs__srv__FrameGraph__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {tf2_msgs__srv__FrameGraph_Event__TYPE_NAME, 29, 29},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription tf2_msgs__srv__FrameGraph__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {tf2_msgs__srv__FrameGraph_Event__TYPE_NAME, 29, 29},
    {NULL, 0, 0},
  },
  {
    {tf2_msgs__srv__FrameGraph_Request__TYPE_NAME, 31, 31},
    {NULL, 0, 0},
  },
  {
    {tf2_msgs__srv__FrameGraph_Response__TYPE_NAME, 32, 32},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
tf2_msgs__srv__FrameGraph__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {tf2_msgs__srv__FrameGraph__TYPE_NAME, 23, 23},
      {tf2_msgs__srv__FrameGraph__FIELDS, 3, 3},
    },
    {tf2_msgs__srv__FrameGraph__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = tf2_msgs__srv__FrameGraph_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = tf2_msgs__srv__FrameGraph_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[4].fields = tf2_msgs__srv__FrameGraph_Response__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char tf2_msgs__srv__FrameGraph_Request__FIELD_NAME__structure_needs_at_least_one_member[] = "structure_needs_at_least_one_member";

static rosidl_runtime_c__type_description__Field tf2_msgs__srv__FrameGraph_Request__FIELDS[] = {
  {
    {tf2_msgs__srv__FrameGraph_Request__FIELD_NAME__structure_needs_at_least_one_member, 35, 35},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
tf2_msgs__srv__FrameGraph_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {tf2_msgs__srv__FrameGraph_Request__TYPE_NAME, 31, 31},
      {tf2_msgs__srv__FrameGraph_Request__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char tf2_msgs__srv__FrameGraph_Response__FIELD_NAME__frame_yaml[] = "frame_yaml";

static rosidl_runtime_c__type_description__Field tf2_msgs__srv__FrameGraph_Response__FIELDS[] = {
  {
    {tf2_msgs__srv__FrameGraph_Response__FIELD_NAME__frame_yaml, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
tf2_msgs__srv__FrameGraph_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {tf2_msgs__srv__FrameGraph_Response__TYPE_NAME, 32, 32},
      {tf2_msgs__srv__FrameGraph_Response__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char tf2_msgs__srv__FrameGraph_Event__FIELD_NAME__info[] = "info";
static char tf2_msgs__srv__FrameGraph_Event__FIELD_NAME__request[] = "request";
static char tf2_msgs__srv__FrameGraph_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field tf2_msgs__srv__FrameGraph_Event__FIELDS[] = {
  {
    {tf2_msgs__srv__FrameGraph_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {tf2_msgs__srv__FrameGraph_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {tf2_msgs__srv__FrameGraph_Request__TYPE_NAME, 31, 31},
    },
    {NULL, 0, 0},
  },
  {
    {tf2_msgs__srv__FrameGraph_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {tf2_msgs__srv__FrameGraph_Response__TYPE_NAME, 32, 32},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription tf2_msgs__srv__FrameGraph_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {tf2_msgs__srv__FrameGraph_Request__TYPE_NAME, 31, 31},
    {NULL, 0, 0},
  },
  {
    {tf2_msgs__srv__FrameGraph_Response__TYPE_NAME, 32, 32},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
tf2_msgs__srv__FrameGraph_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {tf2_msgs__srv__FrameGraph_Event__TYPE_NAME, 29, 29},
      {tf2_msgs__srv__FrameGraph_Event__FIELDS, 3, 3},
    },
    {tf2_msgs__srv__FrameGraph_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = tf2_msgs__srv__FrameGraph_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = tf2_msgs__srv__FrameGraph_Response__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "---\n"
  "string frame_yaml";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
tf2_msgs__srv__FrameGraph__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {tf2_msgs__srv__FrameGraph__TYPE_NAME, 23, 23},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 22, 22},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
tf2_msgs__srv__FrameGraph_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {tf2_msgs__srv__FrameGraph_Request__TYPE_NAME, 31, 31},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
tf2_msgs__srv__FrameGraph_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {tf2_msgs__srv__FrameGraph_Response__TYPE_NAME, 32, 32},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
tf2_msgs__srv__FrameGraph_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {tf2_msgs__srv__FrameGraph_Event__TYPE_NAME, 29, 29},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
tf2_msgs__srv__FrameGraph__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *tf2_msgs__srv__FrameGraph__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    sources[3] = *tf2_msgs__srv__FrameGraph_Event__get_individual_type_description_source(NULL);
    sources[4] = *tf2_msgs__srv__FrameGraph_Request__get_individual_type_description_source(NULL);
    sources[5] = *tf2_msgs__srv__FrameGraph_Response__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
tf2_msgs__srv__FrameGraph_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *tf2_msgs__srv__FrameGraph_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
tf2_msgs__srv__FrameGraph_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *tf2_msgs__srv__FrameGraph_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
tf2_msgs__srv__FrameGraph_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *tf2_msgs__srv__FrameGraph_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    sources[3] = *tf2_msgs__srv__FrameGraph_Request__get_individual_type_description_source(NULL);
    sources[4] = *tf2_msgs__srv__FrameGraph_Response__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
