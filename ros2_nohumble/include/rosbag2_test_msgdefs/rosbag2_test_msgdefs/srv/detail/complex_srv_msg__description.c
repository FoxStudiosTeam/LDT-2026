// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from rosbag2_test_msgdefs:srv\ComplexSrvMsg.idl
// generated code does not contain a copyright notice

#include "rosbag2_test_msgdefs/srv/detail/complex_srv_msg__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_rosbag2_test_msgdefs
const rosidl_type_hash_t *
rosbag2_test_msgdefs__srv__ComplexSrvMsg__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x0d, 0xc9, 0xcc, 0xd3, 0xad, 0xa2, 0xb1, 0xf9,
      0x79, 0x8e, 0x1e, 0xed, 0xbe, 0x8c, 0x05, 0x17,
      0x3a, 0xef, 0xf2, 0x6f, 0x60, 0xbd, 0xe8, 0x1b,
      0x3f, 0x05, 0x76, 0xe7, 0x6b, 0x80, 0x0a, 0x31,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_rosbag2_test_msgdefs
const rosidl_type_hash_t *
rosbag2_test_msgdefs__srv__ComplexSrvMsg_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x04, 0xbe, 0x36, 0xeb, 0xe4, 0xe9, 0x21, 0x9b,
      0x85, 0x0c, 0xd6, 0x3b, 0xb1, 0x29, 0x38, 0xfe,
      0x15, 0x2c, 0xc7, 0x58, 0x3c, 0xb8, 0x3c, 0x6d,
      0x5a, 0x3c, 0x70, 0x75, 0x16, 0xe3, 0x3c, 0x6b,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_rosbag2_test_msgdefs
const rosidl_type_hash_t *
rosbag2_test_msgdefs__srv__ComplexSrvMsg_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x70, 0x5a, 0xbd, 0xf2, 0xfc, 0x95, 0x5b, 0x91,
      0x53, 0x48, 0x04, 0x0b, 0xe2, 0x30, 0x09, 0xc7,
      0x68, 0x99, 0x7e, 0x8f, 0x2f, 0x1e, 0xa4, 0x90,
      0x10, 0x94, 0x5c, 0x07, 0xda, 0x43, 0x8e, 0xfe,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_rosbag2_test_msgdefs
const rosidl_type_hash_t *
rosbag2_test_msgdefs__srv__ComplexSrvMsg_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x3f, 0x55, 0xd5, 0x9d, 0xf2, 0x8f, 0x77, 0x97,
      0xb4, 0x86, 0x52, 0x8e, 0x06, 0x9b, 0x5b, 0xd7,
      0x78, 0x3a, 0x33, 0x63, 0x2d, 0x75, 0xc1, 0x7b,
      0xfb, 0x5b, 0x1d, 0x31, 0x0c, 0x1c, 0x5e, 0xcb,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "rosbag2_test_msgdefs/msg/detail/basic_msg__functions.h"
#include "service_msgs/msg/detail/service_event_info__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t rosbag2_test_msgdefs__msg__BasicMsg__EXPECTED_HASH = {1, {
    0x99, 0xf0, 0xb9, 0x73, 0x2f, 0xb9, 0xa9, 0x0d,
    0xec, 0x3b, 0xb4, 0x97, 0x15, 0xd2, 0x7c, 0xa1,
    0x19, 0x68, 0xd3, 0x15, 0x4a, 0x7e, 0xde, 0x29,
    0xfc, 0xdb, 0x50, 0x27, 0xa4, 0xd4, 0x82, 0xb4,
  }};
static const rosidl_type_hash_t service_msgs__msg__ServiceEventInfo__EXPECTED_HASH = {1, {
    0x41, 0xbc, 0xbb, 0xe0, 0x7a, 0x75, 0xc9, 0xb5,
    0x2b, 0xc9, 0x6b, 0xfd, 0x5c, 0x24, 0xd7, 0xf0,
    0xfc, 0x0a, 0x08, 0xc0, 0xcb, 0x79, 0x21, 0xb3,
    0x37, 0x3c, 0x57, 0x32, 0x34, 0x5a, 0x6f, 0x45,
  }};
#endif

static char rosbag2_test_msgdefs__srv__ComplexSrvMsg__TYPE_NAME[] = "rosbag2_test_msgdefs/srv/ComplexSrvMsg";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char rosbag2_test_msgdefs__msg__BasicMsg__TYPE_NAME[] = "rosbag2_test_msgdefs/msg/BasicMsg";
static char rosbag2_test_msgdefs__srv__ComplexSrvMsg_Event__TYPE_NAME[] = "rosbag2_test_msgdefs/srv/ComplexSrvMsg_Event";
static char rosbag2_test_msgdefs__srv__ComplexSrvMsg_Request__TYPE_NAME[] = "rosbag2_test_msgdefs/srv/ComplexSrvMsg_Request";
static char rosbag2_test_msgdefs__srv__ComplexSrvMsg_Response__TYPE_NAME[] = "rosbag2_test_msgdefs/srv/ComplexSrvMsg_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char rosbag2_test_msgdefs__srv__ComplexSrvMsg__FIELD_NAME__request_message[] = "request_message";
static char rosbag2_test_msgdefs__srv__ComplexSrvMsg__FIELD_NAME__response_message[] = "response_message";
static char rosbag2_test_msgdefs__srv__ComplexSrvMsg__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field rosbag2_test_msgdefs__srv__ComplexSrvMsg__FIELDS[] = {
  {
    {rosbag2_test_msgdefs__srv__ComplexSrvMsg__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {rosbag2_test_msgdefs__srv__ComplexSrvMsg_Request__TYPE_NAME, 46, 46},
    },
    {NULL, 0, 0},
  },
  {
    {rosbag2_test_msgdefs__srv__ComplexSrvMsg__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {rosbag2_test_msgdefs__srv__ComplexSrvMsg_Response__TYPE_NAME, 47, 47},
    },
    {NULL, 0, 0},
  },
  {
    {rosbag2_test_msgdefs__srv__ComplexSrvMsg__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {rosbag2_test_msgdefs__srv__ComplexSrvMsg_Event__TYPE_NAME, 44, 44},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription rosbag2_test_msgdefs__srv__ComplexSrvMsg__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {rosbag2_test_msgdefs__msg__BasicMsg__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {rosbag2_test_msgdefs__srv__ComplexSrvMsg_Event__TYPE_NAME, 44, 44},
    {NULL, 0, 0},
  },
  {
    {rosbag2_test_msgdefs__srv__ComplexSrvMsg_Request__TYPE_NAME, 46, 46},
    {NULL, 0, 0},
  },
  {
    {rosbag2_test_msgdefs__srv__ComplexSrvMsg_Response__TYPE_NAME, 47, 47},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
rosbag2_test_msgdefs__srv__ComplexSrvMsg__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {rosbag2_test_msgdefs__srv__ComplexSrvMsg__TYPE_NAME, 38, 38},
      {rosbag2_test_msgdefs__srv__ComplexSrvMsg__FIELDS, 3, 3},
    },
    {rosbag2_test_msgdefs__srv__ComplexSrvMsg__REFERENCED_TYPE_DESCRIPTIONS, 6, 6},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&rosbag2_test_msgdefs__msg__BasicMsg__EXPECTED_HASH, rosbag2_test_msgdefs__msg__BasicMsg__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = rosbag2_test_msgdefs__msg__BasicMsg__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = rosbag2_test_msgdefs__srv__ComplexSrvMsg_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = rosbag2_test_msgdefs__srv__ComplexSrvMsg_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[4].fields = rosbag2_test_msgdefs__srv__ComplexSrvMsg_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[5].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char rosbag2_test_msgdefs__srv__ComplexSrvMsg_Request__FIELD_NAME__req[] = "req";

static rosidl_runtime_c__type_description__Field rosbag2_test_msgdefs__srv__ComplexSrvMsg_Request__FIELDS[] = {
  {
    {rosbag2_test_msgdefs__srv__ComplexSrvMsg_Request__FIELD_NAME__req, 3, 3},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {rosbag2_test_msgdefs__msg__BasicMsg__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription rosbag2_test_msgdefs__srv__ComplexSrvMsg_Request__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {rosbag2_test_msgdefs__msg__BasicMsg__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
rosbag2_test_msgdefs__srv__ComplexSrvMsg_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {rosbag2_test_msgdefs__srv__ComplexSrvMsg_Request__TYPE_NAME, 46, 46},
      {rosbag2_test_msgdefs__srv__ComplexSrvMsg_Request__FIELDS, 1, 1},
    },
    {rosbag2_test_msgdefs__srv__ComplexSrvMsg_Request__REFERENCED_TYPE_DESCRIPTIONS, 1, 1},
  };
  if (!constructed) {
    assert(0 == memcmp(&rosbag2_test_msgdefs__msg__BasicMsg__EXPECTED_HASH, rosbag2_test_msgdefs__msg__BasicMsg__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = rosbag2_test_msgdefs__msg__BasicMsg__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char rosbag2_test_msgdefs__srv__ComplexSrvMsg_Response__FIELD_NAME__resp[] = "resp";

static rosidl_runtime_c__type_description__Field rosbag2_test_msgdefs__srv__ComplexSrvMsg_Response__FIELDS[] = {
  {
    {rosbag2_test_msgdefs__srv__ComplexSrvMsg_Response__FIELD_NAME__resp, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {rosbag2_test_msgdefs__msg__BasicMsg__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription rosbag2_test_msgdefs__srv__ComplexSrvMsg_Response__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {rosbag2_test_msgdefs__msg__BasicMsg__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
rosbag2_test_msgdefs__srv__ComplexSrvMsg_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {rosbag2_test_msgdefs__srv__ComplexSrvMsg_Response__TYPE_NAME, 47, 47},
      {rosbag2_test_msgdefs__srv__ComplexSrvMsg_Response__FIELDS, 1, 1},
    },
    {rosbag2_test_msgdefs__srv__ComplexSrvMsg_Response__REFERENCED_TYPE_DESCRIPTIONS, 1, 1},
  };
  if (!constructed) {
    assert(0 == memcmp(&rosbag2_test_msgdefs__msg__BasicMsg__EXPECTED_HASH, rosbag2_test_msgdefs__msg__BasicMsg__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = rosbag2_test_msgdefs__msg__BasicMsg__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char rosbag2_test_msgdefs__srv__ComplexSrvMsg_Event__FIELD_NAME__info[] = "info";
static char rosbag2_test_msgdefs__srv__ComplexSrvMsg_Event__FIELD_NAME__request[] = "request";
static char rosbag2_test_msgdefs__srv__ComplexSrvMsg_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field rosbag2_test_msgdefs__srv__ComplexSrvMsg_Event__FIELDS[] = {
  {
    {rosbag2_test_msgdefs__srv__ComplexSrvMsg_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {rosbag2_test_msgdefs__srv__ComplexSrvMsg_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {rosbag2_test_msgdefs__srv__ComplexSrvMsg_Request__TYPE_NAME, 46, 46},
    },
    {NULL, 0, 0},
  },
  {
    {rosbag2_test_msgdefs__srv__ComplexSrvMsg_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {rosbag2_test_msgdefs__srv__ComplexSrvMsg_Response__TYPE_NAME, 47, 47},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription rosbag2_test_msgdefs__srv__ComplexSrvMsg_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {rosbag2_test_msgdefs__msg__BasicMsg__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {rosbag2_test_msgdefs__srv__ComplexSrvMsg_Request__TYPE_NAME, 46, 46},
    {NULL, 0, 0},
  },
  {
    {rosbag2_test_msgdefs__srv__ComplexSrvMsg_Response__TYPE_NAME, 47, 47},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
rosbag2_test_msgdefs__srv__ComplexSrvMsg_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {rosbag2_test_msgdefs__srv__ComplexSrvMsg_Event__TYPE_NAME, 44, 44},
      {rosbag2_test_msgdefs__srv__ComplexSrvMsg_Event__FIELDS, 3, 3},
    },
    {rosbag2_test_msgdefs__srv__ComplexSrvMsg_Event__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&rosbag2_test_msgdefs__msg__BasicMsg__EXPECTED_HASH, rosbag2_test_msgdefs__msg__BasicMsg__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = rosbag2_test_msgdefs__msg__BasicMsg__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = rosbag2_test_msgdefs__srv__ComplexSrvMsg_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = rosbag2_test_msgdefs__srv__ComplexSrvMsg_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "rosbag2_test_msgdefs/BasicMsg req\n"
  "---\n"
  "rosbag2_test_msgdefs/BasicMsg resp";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
rosbag2_test_msgdefs__srv__ComplexSrvMsg__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {rosbag2_test_msgdefs__srv__ComplexSrvMsg__TYPE_NAME, 38, 38},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 73, 73},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
rosbag2_test_msgdefs__srv__ComplexSrvMsg_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {rosbag2_test_msgdefs__srv__ComplexSrvMsg_Request__TYPE_NAME, 46, 46},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
rosbag2_test_msgdefs__srv__ComplexSrvMsg_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {rosbag2_test_msgdefs__srv__ComplexSrvMsg_Response__TYPE_NAME, 47, 47},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
rosbag2_test_msgdefs__srv__ComplexSrvMsg_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {rosbag2_test_msgdefs__srv__ComplexSrvMsg_Event__TYPE_NAME, 44, 44},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
rosbag2_test_msgdefs__srv__ComplexSrvMsg__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[7];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 7, 7};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *rosbag2_test_msgdefs__srv__ComplexSrvMsg__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *rosbag2_test_msgdefs__msg__BasicMsg__get_individual_type_description_source(NULL);
    sources[3] = *rosbag2_test_msgdefs__srv__ComplexSrvMsg_Event__get_individual_type_description_source(NULL);
    sources[4] = *rosbag2_test_msgdefs__srv__ComplexSrvMsg_Request__get_individual_type_description_source(NULL);
    sources[5] = *rosbag2_test_msgdefs__srv__ComplexSrvMsg_Response__get_individual_type_description_source(NULL);
    sources[6] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
rosbag2_test_msgdefs__srv__ComplexSrvMsg_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[2];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 2, 2};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *rosbag2_test_msgdefs__srv__ComplexSrvMsg_Request__get_individual_type_description_source(NULL),
    sources[1] = *rosbag2_test_msgdefs__msg__BasicMsg__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
rosbag2_test_msgdefs__srv__ComplexSrvMsg_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[2];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 2, 2};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *rosbag2_test_msgdefs__srv__ComplexSrvMsg_Response__get_individual_type_description_source(NULL),
    sources[1] = *rosbag2_test_msgdefs__msg__BasicMsg__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
rosbag2_test_msgdefs__srv__ComplexSrvMsg_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *rosbag2_test_msgdefs__srv__ComplexSrvMsg_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *rosbag2_test_msgdefs__msg__BasicMsg__get_individual_type_description_source(NULL);
    sources[3] = *rosbag2_test_msgdefs__srv__ComplexSrvMsg_Request__get_individual_type_description_source(NULL);
    sources[4] = *rosbag2_test_msgdefs__srv__ComplexSrvMsg_Response__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
