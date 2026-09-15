// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from rosbag2_interfaces:srv\Stop.idl
// generated code does not contain a copyright notice

#include "rosbag2_interfaces/srv/detail/stop__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_rosbag2_interfaces
const rosidl_type_hash_t *
rosbag2_interfaces__srv__Stop__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x85, 0x0e, 0x22, 0x1d, 0xf0, 0xc7, 0xd2, 0xa5,
      0x52, 0x84, 0x2c, 0x27, 0x12, 0x98, 0x7c, 0x33,
      0xef, 0xd9, 0xe4, 0x69, 0x69, 0x98, 0x61, 0x78,
      0x2e, 0xd6, 0x2f, 0xb3, 0x19, 0xcc, 0xb5, 0x36,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_rosbag2_interfaces
const rosidl_type_hash_t *
rosbag2_interfaces__srv__Stop_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x2b, 0xa1, 0x3f, 0xee, 0x32, 0x07, 0x57, 0xe5,
      0x5d, 0x4c, 0x44, 0xf1, 0xde, 0x0a, 0x13, 0xe6,
      0xbb, 0x45, 0x11, 0x96, 0x8a, 0x2a, 0xec, 0x7f,
      0x01, 0x54, 0x36, 0xe1, 0xe1, 0x37, 0x67, 0x4e,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_rosbag2_interfaces
const rosidl_type_hash_t *
rosbag2_interfaces__srv__Stop_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x98, 0x3b, 0xe9, 0x24, 0xa9, 0x34, 0x4f, 0x45,
      0x0e, 0xc0, 0xb3, 0x46, 0x95, 0xba, 0xb9, 0x24,
      0xdf, 0x6f, 0x01, 0xa7, 0x38, 0x00, 0x84, 0xa2,
      0x39, 0xf5, 0x74, 0x86, 0x14, 0xc1, 0x8a, 0x04,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_rosbag2_interfaces
const rosidl_type_hash_t *
rosbag2_interfaces__srv__Stop_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x54, 0xfc, 0x7c, 0x60, 0xa7, 0xa0, 0x6d, 0x55,
      0x58, 0xcb, 0x65, 0x7e, 0xbd, 0xed, 0x45, 0x4b,
      0x41, 0xe3, 0xa3, 0xc4, 0x16, 0xb8, 0x89, 0xb9,
      0xde, 0x7f, 0x80, 0xb4, 0xf2, 0x62, 0x0f, 0x40,
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

static char rosbag2_interfaces__srv__Stop__TYPE_NAME[] = "rosbag2_interfaces/srv/Stop";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char rosbag2_interfaces__srv__Stop_Event__TYPE_NAME[] = "rosbag2_interfaces/srv/Stop_Event";
static char rosbag2_interfaces__srv__Stop_Request__TYPE_NAME[] = "rosbag2_interfaces/srv/Stop_Request";
static char rosbag2_interfaces__srv__Stop_Response__TYPE_NAME[] = "rosbag2_interfaces/srv/Stop_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char rosbag2_interfaces__srv__Stop__FIELD_NAME__request_message[] = "request_message";
static char rosbag2_interfaces__srv__Stop__FIELD_NAME__response_message[] = "response_message";
static char rosbag2_interfaces__srv__Stop__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field rosbag2_interfaces__srv__Stop__FIELDS[] = {
  {
    {rosbag2_interfaces__srv__Stop__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {rosbag2_interfaces__srv__Stop_Request__TYPE_NAME, 35, 35},
    },
    {NULL, 0, 0},
  },
  {
    {rosbag2_interfaces__srv__Stop__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {rosbag2_interfaces__srv__Stop_Response__TYPE_NAME, 36, 36},
    },
    {NULL, 0, 0},
  },
  {
    {rosbag2_interfaces__srv__Stop__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {rosbag2_interfaces__srv__Stop_Event__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription rosbag2_interfaces__srv__Stop__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {rosbag2_interfaces__srv__Stop_Event__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {rosbag2_interfaces__srv__Stop_Request__TYPE_NAME, 35, 35},
    {NULL, 0, 0},
  },
  {
    {rosbag2_interfaces__srv__Stop_Response__TYPE_NAME, 36, 36},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
rosbag2_interfaces__srv__Stop__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {rosbag2_interfaces__srv__Stop__TYPE_NAME, 27, 27},
      {rosbag2_interfaces__srv__Stop__FIELDS, 3, 3},
    },
    {rosbag2_interfaces__srv__Stop__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = rosbag2_interfaces__srv__Stop_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = rosbag2_interfaces__srv__Stop_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = rosbag2_interfaces__srv__Stop_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char rosbag2_interfaces__srv__Stop_Request__FIELD_NAME__structure_needs_at_least_one_member[] = "structure_needs_at_least_one_member";

static rosidl_runtime_c__type_description__Field rosbag2_interfaces__srv__Stop_Request__FIELDS[] = {
  {
    {rosbag2_interfaces__srv__Stop_Request__FIELD_NAME__structure_needs_at_least_one_member, 35, 35},
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
rosbag2_interfaces__srv__Stop_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {rosbag2_interfaces__srv__Stop_Request__TYPE_NAME, 35, 35},
      {rosbag2_interfaces__srv__Stop_Request__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char rosbag2_interfaces__srv__Stop_Response__FIELD_NAME__return_code[] = "return_code";
static char rosbag2_interfaces__srv__Stop_Response__FIELD_NAME__error_string[] = "error_string";

static rosidl_runtime_c__type_description__Field rosbag2_interfaces__srv__Stop_Response__FIELDS[] = {
  {
    {rosbag2_interfaces__srv__Stop_Response__FIELD_NAME__return_code, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {rosbag2_interfaces__srv__Stop_Response__FIELD_NAME__error_string, 12, 12},
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
rosbag2_interfaces__srv__Stop_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {rosbag2_interfaces__srv__Stop_Response__TYPE_NAME, 36, 36},
      {rosbag2_interfaces__srv__Stop_Response__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char rosbag2_interfaces__srv__Stop_Event__FIELD_NAME__info[] = "info";
static char rosbag2_interfaces__srv__Stop_Event__FIELD_NAME__request[] = "request";
static char rosbag2_interfaces__srv__Stop_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field rosbag2_interfaces__srv__Stop_Event__FIELDS[] = {
  {
    {rosbag2_interfaces__srv__Stop_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {rosbag2_interfaces__srv__Stop_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {rosbag2_interfaces__srv__Stop_Request__TYPE_NAME, 35, 35},
    },
    {NULL, 0, 0},
  },
  {
    {rosbag2_interfaces__srv__Stop_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {rosbag2_interfaces__srv__Stop_Response__TYPE_NAME, 36, 36},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription rosbag2_interfaces__srv__Stop_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {rosbag2_interfaces__srv__Stop_Request__TYPE_NAME, 35, 35},
    {NULL, 0, 0},
  },
  {
    {rosbag2_interfaces__srv__Stop_Response__TYPE_NAME, 36, 36},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
rosbag2_interfaces__srv__Stop_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {rosbag2_interfaces__srv__Stop_Event__TYPE_NAME, 33, 33},
      {rosbag2_interfaces__srv__Stop_Event__FIELDS, 3, 3},
    },
    {rosbag2_interfaces__srv__Stop_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = rosbag2_interfaces__srv__Stop_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = rosbag2_interfaces__srv__Stop_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "---\n"
  "# Return code. Returns 1 when recording or playback is already stopped or in case of error, otherwise 0.\n"
  "int32 return_code\n"
  "\n"
  "# Error string. Empty if no error occurred.\n"
  "string error_string";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
rosbag2_interfaces__srv__Stop__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {rosbag2_interfaces__srv__Stop__TYPE_NAME, 27, 27},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 192, 192},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
rosbag2_interfaces__srv__Stop_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {rosbag2_interfaces__srv__Stop_Request__TYPE_NAME, 35, 35},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
rosbag2_interfaces__srv__Stop_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {rosbag2_interfaces__srv__Stop_Response__TYPE_NAME, 36, 36},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
rosbag2_interfaces__srv__Stop_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {rosbag2_interfaces__srv__Stop_Event__TYPE_NAME, 33, 33},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
rosbag2_interfaces__srv__Stop__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *rosbag2_interfaces__srv__Stop__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *rosbag2_interfaces__srv__Stop_Event__get_individual_type_description_source(NULL);
    sources[3] = *rosbag2_interfaces__srv__Stop_Request__get_individual_type_description_source(NULL);
    sources[4] = *rosbag2_interfaces__srv__Stop_Response__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
rosbag2_interfaces__srv__Stop_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *rosbag2_interfaces__srv__Stop_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
rosbag2_interfaces__srv__Stop_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *rosbag2_interfaces__srv__Stop_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
rosbag2_interfaces__srv__Stop_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *rosbag2_interfaces__srv__Stop_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *rosbag2_interfaces__srv__Stop_Request__get_individual_type_description_source(NULL);
    sources[3] = *rosbag2_interfaces__srv__Stop_Response__get_individual_type_description_source(NULL);
    sources[4] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
