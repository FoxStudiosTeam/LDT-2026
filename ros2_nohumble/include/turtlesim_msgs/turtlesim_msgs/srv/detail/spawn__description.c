// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from turtlesim_msgs:srv\Spawn.idl
// generated code does not contain a copyright notice

#include "turtlesim_msgs/srv/detail/spawn__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_turtlesim_msgs
const rosidl_type_hash_t *
turtlesim_msgs__srv__Spawn__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x15, 0x38, 0xb7, 0xb6, 0x68, 0xcc, 0xe0, 0x07,
      0x4f, 0x0c, 0xa9, 0xfa, 0x99, 0x2b, 0xde, 0xb6,
      0x97, 0x9b, 0xda, 0x1f, 0x72, 0x2f, 0xc7, 0xea,
      0x33, 0xca, 0x47, 0xb4, 0x08, 0xaa, 0x32, 0xe9,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_turtlesim_msgs
const rosidl_type_hash_t *
turtlesim_msgs__srv__Spawn_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xf1, 0xc8, 0x5c, 0xfd, 0xae, 0x55, 0x16, 0x41,
      0x90, 0xe2, 0x50, 0x34, 0xec, 0x31, 0xf8, 0x30,
      0x93, 0x6d, 0xe5, 0xe7, 0xe6, 0xc0, 0xb2, 0x0d,
      0x1e, 0xbb, 0xfe, 0xe2, 0xde, 0xeb, 0x2b, 0x39,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_turtlesim_msgs
const rosidl_type_hash_t *
turtlesim_msgs__srv__Spawn_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xad, 0xd4, 0x0f, 0xd4, 0xf4, 0x89, 0x28, 0x78,
      0x49, 0x8f, 0x6f, 0xe0, 0x1a, 0xf6, 0x29, 0xb1,
      0x71, 0xfb, 0xf2, 0xb7, 0x6f, 0xcc, 0x4f, 0x47,
      0x3e, 0x8f, 0x9b, 0x65, 0xbe, 0x37, 0x35, 0xbb,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_turtlesim_msgs
const rosidl_type_hash_t *
turtlesim_msgs__srv__Spawn_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xcc, 0x95, 0x3f, 0x0c, 0xf1, 0xe0, 0xcc, 0x3f,
      0xb9, 0x11, 0xd0, 0xc3, 0xe2, 0xc0, 0x45, 0xa5,
      0x63, 0x1c, 0x21, 0xb3, 0xe2, 0x39, 0x62, 0x8e,
      0x79, 0x57, 0x51, 0xf1, 0x18, 0x32, 0x46, 0x8c,
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

static char turtlesim_msgs__srv__Spawn__TYPE_NAME[] = "turtlesim_msgs/srv/Spawn";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";
static char turtlesim_msgs__srv__Spawn_Event__TYPE_NAME[] = "turtlesim_msgs/srv/Spawn_Event";
static char turtlesim_msgs__srv__Spawn_Request__TYPE_NAME[] = "turtlesim_msgs/srv/Spawn_Request";
static char turtlesim_msgs__srv__Spawn_Response__TYPE_NAME[] = "turtlesim_msgs/srv/Spawn_Response";

// Define type names, field names, and default values
static char turtlesim_msgs__srv__Spawn__FIELD_NAME__request_message[] = "request_message";
static char turtlesim_msgs__srv__Spawn__FIELD_NAME__response_message[] = "response_message";
static char turtlesim_msgs__srv__Spawn__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field turtlesim_msgs__srv__Spawn__FIELDS[] = {
  {
    {turtlesim_msgs__srv__Spawn__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {turtlesim_msgs__srv__Spawn_Request__TYPE_NAME, 32, 32},
    },
    {NULL, 0, 0},
  },
  {
    {turtlesim_msgs__srv__Spawn__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {turtlesim_msgs__srv__Spawn_Response__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {turtlesim_msgs__srv__Spawn__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {turtlesim_msgs__srv__Spawn_Event__TYPE_NAME, 30, 30},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription turtlesim_msgs__srv__Spawn__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {turtlesim_msgs__srv__Spawn_Event__TYPE_NAME, 30, 30},
    {NULL, 0, 0},
  },
  {
    {turtlesim_msgs__srv__Spawn_Request__TYPE_NAME, 32, 32},
    {NULL, 0, 0},
  },
  {
    {turtlesim_msgs__srv__Spawn_Response__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
turtlesim_msgs__srv__Spawn__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {turtlesim_msgs__srv__Spawn__TYPE_NAME, 24, 24},
      {turtlesim_msgs__srv__Spawn__FIELDS, 3, 3},
    },
    {turtlesim_msgs__srv__Spawn__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = turtlesim_msgs__srv__Spawn_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = turtlesim_msgs__srv__Spawn_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[4].fields = turtlesim_msgs__srv__Spawn_Response__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char turtlesim_msgs__srv__Spawn_Request__FIELD_NAME__x[] = "x";
static char turtlesim_msgs__srv__Spawn_Request__FIELD_NAME__y[] = "y";
static char turtlesim_msgs__srv__Spawn_Request__FIELD_NAME__theta[] = "theta";
static char turtlesim_msgs__srv__Spawn_Request__FIELD_NAME__name[] = "name";

static rosidl_runtime_c__type_description__Field turtlesim_msgs__srv__Spawn_Request__FIELDS[] = {
  {
    {turtlesim_msgs__srv__Spawn_Request__FIELD_NAME__x, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {turtlesim_msgs__srv__Spawn_Request__FIELD_NAME__y, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {turtlesim_msgs__srv__Spawn_Request__FIELD_NAME__theta, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {turtlesim_msgs__srv__Spawn_Request__FIELD_NAME__name, 4, 4},
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
turtlesim_msgs__srv__Spawn_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {turtlesim_msgs__srv__Spawn_Request__TYPE_NAME, 32, 32},
      {turtlesim_msgs__srv__Spawn_Request__FIELDS, 4, 4},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char turtlesim_msgs__srv__Spawn_Response__FIELD_NAME__name[] = "name";

static rosidl_runtime_c__type_description__Field turtlesim_msgs__srv__Spawn_Response__FIELDS[] = {
  {
    {turtlesim_msgs__srv__Spawn_Response__FIELD_NAME__name, 4, 4},
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
turtlesim_msgs__srv__Spawn_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {turtlesim_msgs__srv__Spawn_Response__TYPE_NAME, 33, 33},
      {turtlesim_msgs__srv__Spawn_Response__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char turtlesim_msgs__srv__Spawn_Event__FIELD_NAME__info[] = "info";
static char turtlesim_msgs__srv__Spawn_Event__FIELD_NAME__request[] = "request";
static char turtlesim_msgs__srv__Spawn_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field turtlesim_msgs__srv__Spawn_Event__FIELDS[] = {
  {
    {turtlesim_msgs__srv__Spawn_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {turtlesim_msgs__srv__Spawn_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {turtlesim_msgs__srv__Spawn_Request__TYPE_NAME, 32, 32},
    },
    {NULL, 0, 0},
  },
  {
    {turtlesim_msgs__srv__Spawn_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {turtlesim_msgs__srv__Spawn_Response__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription turtlesim_msgs__srv__Spawn_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {turtlesim_msgs__srv__Spawn_Request__TYPE_NAME, 32, 32},
    {NULL, 0, 0},
  },
  {
    {turtlesim_msgs__srv__Spawn_Response__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
turtlesim_msgs__srv__Spawn_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {turtlesim_msgs__srv__Spawn_Event__TYPE_NAME, 30, 30},
      {turtlesim_msgs__srv__Spawn_Event__FIELDS, 3, 3},
    },
    {turtlesim_msgs__srv__Spawn_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = turtlesim_msgs__srv__Spawn_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = turtlesim_msgs__srv__Spawn_Response__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float32 x\n"
  "float32 y\n"
  "float32 theta\n"
  "string name # Optional.  A unique name will be created and returned if this is empty\n"
  "---\n"
  "string name";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
turtlesim_msgs__srv__Spawn__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {turtlesim_msgs__srv__Spawn__TYPE_NAME, 24, 24},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 134, 134},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
turtlesim_msgs__srv__Spawn_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {turtlesim_msgs__srv__Spawn_Request__TYPE_NAME, 32, 32},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
turtlesim_msgs__srv__Spawn_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {turtlesim_msgs__srv__Spawn_Response__TYPE_NAME, 33, 33},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
turtlesim_msgs__srv__Spawn_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {turtlesim_msgs__srv__Spawn_Event__TYPE_NAME, 30, 30},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
turtlesim_msgs__srv__Spawn__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *turtlesim_msgs__srv__Spawn__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    sources[3] = *turtlesim_msgs__srv__Spawn_Event__get_individual_type_description_source(NULL);
    sources[4] = *turtlesim_msgs__srv__Spawn_Request__get_individual_type_description_source(NULL);
    sources[5] = *turtlesim_msgs__srv__Spawn_Response__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
turtlesim_msgs__srv__Spawn_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *turtlesim_msgs__srv__Spawn_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
turtlesim_msgs__srv__Spawn_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *turtlesim_msgs__srv__Spawn_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
turtlesim_msgs__srv__Spawn_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *turtlesim_msgs__srv__Spawn_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    sources[3] = *turtlesim_msgs__srv__Spawn_Request__get_individual_type_description_source(NULL);
    sources[4] = *turtlesim_msgs__srv__Spawn_Response__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
