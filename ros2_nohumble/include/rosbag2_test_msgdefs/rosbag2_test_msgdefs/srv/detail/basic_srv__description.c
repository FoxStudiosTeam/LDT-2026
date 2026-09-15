// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from rosbag2_test_msgdefs:srv\BasicSrv.idl
// generated code does not contain a copyright notice

#include "rosbag2_test_msgdefs/srv/detail/basic_srv__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_rosbag2_test_msgdefs
const rosidl_type_hash_t *
rosbag2_test_msgdefs__srv__BasicSrv__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xd6, 0x9f, 0xb5, 0xc0, 0x29, 0xd9, 0x34, 0x5e,
      0x7d, 0xf0, 0x47, 0xb1, 0xdd, 0x66, 0x13, 0xb5,
      0x8e, 0x03, 0x7b, 0x0b, 0xaa, 0x90, 0xbc, 0x56,
      0x04, 0xd7, 0x0b, 0xe4, 0x65, 0xc1, 0x67, 0xeb,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_rosbag2_test_msgdefs
const rosidl_type_hash_t *
rosbag2_test_msgdefs__srv__BasicSrv_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x37, 0xb0, 0x17, 0xa9, 0x04, 0xe6, 0x8b, 0x96,
      0xe1, 0x2b, 0x57, 0xe2, 0x49, 0xaa, 0x7f, 0x69,
      0x37, 0xdb, 0x03, 0x85, 0x23, 0xb8, 0x7d, 0xf0,
      0x05, 0xa5, 0x2d, 0xad, 0x49, 0x34, 0x9b, 0x90,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_rosbag2_test_msgdefs
const rosidl_type_hash_t *
rosbag2_test_msgdefs__srv__BasicSrv_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x7f, 0x7b, 0x33, 0xef, 0x10, 0x1e, 0x61, 0x83,
      0xc7, 0xac, 0xe0, 0x4a, 0x46, 0x81, 0x79, 0x77,
      0x1c, 0x8e, 0x3b, 0x83, 0x01, 0xaf, 0x62, 0xbd,
      0x39, 0x03, 0xad, 0xbf, 0x72, 0x20, 0x6d, 0xcf,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_rosbag2_test_msgdefs
const rosidl_type_hash_t *
rosbag2_test_msgdefs__srv__BasicSrv_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x26, 0x72, 0x60, 0x65, 0xe8, 0x1b, 0xff, 0xce,
      0xb3, 0x04, 0xf4, 0xef, 0x47, 0x56, 0x19, 0xbd,
      0x49, 0xf3, 0x20, 0x66, 0x76, 0x31, 0xcf, 0xe4,
      0x34, 0x8e, 0x05, 0xc9, 0x1c, 0x0b, 0x08, 0xf3,
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

static char rosbag2_test_msgdefs__srv__BasicSrv__TYPE_NAME[] = "rosbag2_test_msgdefs/srv/BasicSrv";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char rosbag2_test_msgdefs__srv__BasicSrv_Event__TYPE_NAME[] = "rosbag2_test_msgdefs/srv/BasicSrv_Event";
static char rosbag2_test_msgdefs__srv__BasicSrv_Request__TYPE_NAME[] = "rosbag2_test_msgdefs/srv/BasicSrv_Request";
static char rosbag2_test_msgdefs__srv__BasicSrv_Response__TYPE_NAME[] = "rosbag2_test_msgdefs/srv/BasicSrv_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char rosbag2_test_msgdefs__srv__BasicSrv__FIELD_NAME__request_message[] = "request_message";
static char rosbag2_test_msgdefs__srv__BasicSrv__FIELD_NAME__response_message[] = "response_message";
static char rosbag2_test_msgdefs__srv__BasicSrv__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field rosbag2_test_msgdefs__srv__BasicSrv__FIELDS[] = {
  {
    {rosbag2_test_msgdefs__srv__BasicSrv__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {rosbag2_test_msgdefs__srv__BasicSrv_Request__TYPE_NAME, 41, 41},
    },
    {NULL, 0, 0},
  },
  {
    {rosbag2_test_msgdefs__srv__BasicSrv__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {rosbag2_test_msgdefs__srv__BasicSrv_Response__TYPE_NAME, 42, 42},
    },
    {NULL, 0, 0},
  },
  {
    {rosbag2_test_msgdefs__srv__BasicSrv__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {rosbag2_test_msgdefs__srv__BasicSrv_Event__TYPE_NAME, 39, 39},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription rosbag2_test_msgdefs__srv__BasicSrv__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {rosbag2_test_msgdefs__srv__BasicSrv_Event__TYPE_NAME, 39, 39},
    {NULL, 0, 0},
  },
  {
    {rosbag2_test_msgdefs__srv__BasicSrv_Request__TYPE_NAME, 41, 41},
    {NULL, 0, 0},
  },
  {
    {rosbag2_test_msgdefs__srv__BasicSrv_Response__TYPE_NAME, 42, 42},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
rosbag2_test_msgdefs__srv__BasicSrv__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {rosbag2_test_msgdefs__srv__BasicSrv__TYPE_NAME, 33, 33},
      {rosbag2_test_msgdefs__srv__BasicSrv__FIELDS, 3, 3},
    },
    {rosbag2_test_msgdefs__srv__BasicSrv__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = rosbag2_test_msgdefs__srv__BasicSrv_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = rosbag2_test_msgdefs__srv__BasicSrv_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = rosbag2_test_msgdefs__srv__BasicSrv_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char rosbag2_test_msgdefs__srv__BasicSrv_Request__FIELD_NAME__req[] = "req";

static rosidl_runtime_c__type_description__Field rosbag2_test_msgdefs__srv__BasicSrv_Request__FIELDS[] = {
  {
    {rosbag2_test_msgdefs__srv__BasicSrv_Request__FIELD_NAME__req, 3, 3},
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
rosbag2_test_msgdefs__srv__BasicSrv_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {rosbag2_test_msgdefs__srv__BasicSrv_Request__TYPE_NAME, 41, 41},
      {rosbag2_test_msgdefs__srv__BasicSrv_Request__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char rosbag2_test_msgdefs__srv__BasicSrv_Response__FIELD_NAME__resp[] = "resp";

static rosidl_runtime_c__type_description__Field rosbag2_test_msgdefs__srv__BasicSrv_Response__FIELDS[] = {
  {
    {rosbag2_test_msgdefs__srv__BasicSrv_Response__FIELD_NAME__resp, 4, 4},
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
rosbag2_test_msgdefs__srv__BasicSrv_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {rosbag2_test_msgdefs__srv__BasicSrv_Response__TYPE_NAME, 42, 42},
      {rosbag2_test_msgdefs__srv__BasicSrv_Response__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char rosbag2_test_msgdefs__srv__BasicSrv_Event__FIELD_NAME__info[] = "info";
static char rosbag2_test_msgdefs__srv__BasicSrv_Event__FIELD_NAME__request[] = "request";
static char rosbag2_test_msgdefs__srv__BasicSrv_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field rosbag2_test_msgdefs__srv__BasicSrv_Event__FIELDS[] = {
  {
    {rosbag2_test_msgdefs__srv__BasicSrv_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {rosbag2_test_msgdefs__srv__BasicSrv_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {rosbag2_test_msgdefs__srv__BasicSrv_Request__TYPE_NAME, 41, 41},
    },
    {NULL, 0, 0},
  },
  {
    {rosbag2_test_msgdefs__srv__BasicSrv_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {rosbag2_test_msgdefs__srv__BasicSrv_Response__TYPE_NAME, 42, 42},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription rosbag2_test_msgdefs__srv__BasicSrv_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {rosbag2_test_msgdefs__srv__BasicSrv_Request__TYPE_NAME, 41, 41},
    {NULL, 0, 0},
  },
  {
    {rosbag2_test_msgdefs__srv__BasicSrv_Response__TYPE_NAME, 42, 42},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
rosbag2_test_msgdefs__srv__BasicSrv_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {rosbag2_test_msgdefs__srv__BasicSrv_Event__TYPE_NAME, 39, 39},
      {rosbag2_test_msgdefs__srv__BasicSrv_Event__FIELDS, 3, 3},
    },
    {rosbag2_test_msgdefs__srv__BasicSrv_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = rosbag2_test_msgdefs__srv__BasicSrv_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = rosbag2_test_msgdefs__srv__BasicSrv_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string req\n"
  "---\n"
  "string resp";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
rosbag2_test_msgdefs__srv__BasicSrv__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {rosbag2_test_msgdefs__srv__BasicSrv__TYPE_NAME, 33, 33},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 27, 27},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
rosbag2_test_msgdefs__srv__BasicSrv_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {rosbag2_test_msgdefs__srv__BasicSrv_Request__TYPE_NAME, 41, 41},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
rosbag2_test_msgdefs__srv__BasicSrv_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {rosbag2_test_msgdefs__srv__BasicSrv_Response__TYPE_NAME, 42, 42},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
rosbag2_test_msgdefs__srv__BasicSrv_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {rosbag2_test_msgdefs__srv__BasicSrv_Event__TYPE_NAME, 39, 39},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
rosbag2_test_msgdefs__srv__BasicSrv__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *rosbag2_test_msgdefs__srv__BasicSrv__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *rosbag2_test_msgdefs__srv__BasicSrv_Event__get_individual_type_description_source(NULL);
    sources[3] = *rosbag2_test_msgdefs__srv__BasicSrv_Request__get_individual_type_description_source(NULL);
    sources[4] = *rosbag2_test_msgdefs__srv__BasicSrv_Response__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
rosbag2_test_msgdefs__srv__BasicSrv_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *rosbag2_test_msgdefs__srv__BasicSrv_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
rosbag2_test_msgdefs__srv__BasicSrv_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *rosbag2_test_msgdefs__srv__BasicSrv_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
rosbag2_test_msgdefs__srv__BasicSrv_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *rosbag2_test_msgdefs__srv__BasicSrv_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *rosbag2_test_msgdefs__srv__BasicSrv_Request__get_individual_type_description_source(NULL);
    sources[3] = *rosbag2_test_msgdefs__srv__BasicSrv_Response__get_individual_type_description_source(NULL);
    sources[4] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
