// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from rosbag2_interfaces:srv\Resume.idl
// generated code does not contain a copyright notice

#include "rosbag2_interfaces/srv/detail/resume__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_rosbag2_interfaces
const rosidl_type_hash_t *
rosbag2_interfaces__srv__Resume__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xfb, 0x0c, 0xcd, 0x61, 0xea, 0xd1, 0x93, 0xe5,
      0x40, 0x18, 0x2f, 0xd8, 0x27, 0xf7, 0x7e, 0xa6,
      0x72, 0xe8, 0x8e, 0x00, 0xce, 0xf9, 0x2b, 0x36,
      0x10, 0x46, 0xe6, 0x11, 0x3c, 0xcc, 0x6f, 0xdc,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_rosbag2_interfaces
const rosidl_type_hash_t *
rosbag2_interfaces__srv__Resume_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x55, 0x20, 0xbb, 0x24, 0xaa, 0xa6, 0x55, 0x9c,
      0xee, 0xca, 0x6d, 0xb8, 0x69, 0xc4, 0xd1, 0x09,
      0x89, 0x9d, 0x91, 0x77, 0xeb, 0x73, 0x0d, 0xbf,
      0x01, 0xe6, 0xa4, 0xd1, 0x62, 0x83, 0x78, 0xbe,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_rosbag2_interfaces
const rosidl_type_hash_t *
rosbag2_interfaces__srv__Resume_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x5e, 0x54, 0xa7, 0x3d, 0x60, 0x7f, 0x7f, 0x40,
      0x6b, 0x28, 0x2f, 0xa3, 0x06, 0xca, 0x6d, 0x43,
      0xdf, 0x71, 0x50, 0x2a, 0xd8, 0xfe, 0x94, 0xa7,
      0xda, 0xbb, 0xd6, 0x87, 0x70, 0x05, 0x6d, 0x0e,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_rosbag2_interfaces
const rosidl_type_hash_t *
rosbag2_interfaces__srv__Resume_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xf5, 0xe7, 0x92, 0x5a, 0xb4, 0x10, 0x65, 0x02,
      0x6b, 0x69, 0x91, 0xeb, 0x48, 0xa0, 0xf4, 0xf9,
      0x4c, 0x98, 0xa0, 0xd4, 0x66, 0x87, 0x8e, 0x31,
      0x99, 0x06, 0x6f, 0x51, 0x17, 0x1f, 0x2e, 0x8f,
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

static char rosbag2_interfaces__srv__Resume__TYPE_NAME[] = "rosbag2_interfaces/srv/Resume";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char rosbag2_interfaces__srv__Resume_Event__TYPE_NAME[] = "rosbag2_interfaces/srv/Resume_Event";
static char rosbag2_interfaces__srv__Resume_Request__TYPE_NAME[] = "rosbag2_interfaces/srv/Resume_Request";
static char rosbag2_interfaces__srv__Resume_Response__TYPE_NAME[] = "rosbag2_interfaces/srv/Resume_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char rosbag2_interfaces__srv__Resume__FIELD_NAME__request_message[] = "request_message";
static char rosbag2_interfaces__srv__Resume__FIELD_NAME__response_message[] = "response_message";
static char rosbag2_interfaces__srv__Resume__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field rosbag2_interfaces__srv__Resume__FIELDS[] = {
  {
    {rosbag2_interfaces__srv__Resume__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {rosbag2_interfaces__srv__Resume_Request__TYPE_NAME, 37, 37},
    },
    {NULL, 0, 0},
  },
  {
    {rosbag2_interfaces__srv__Resume__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {rosbag2_interfaces__srv__Resume_Response__TYPE_NAME, 38, 38},
    },
    {NULL, 0, 0},
  },
  {
    {rosbag2_interfaces__srv__Resume__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {rosbag2_interfaces__srv__Resume_Event__TYPE_NAME, 35, 35},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription rosbag2_interfaces__srv__Resume__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {rosbag2_interfaces__srv__Resume_Event__TYPE_NAME, 35, 35},
    {NULL, 0, 0},
  },
  {
    {rosbag2_interfaces__srv__Resume_Request__TYPE_NAME, 37, 37},
    {NULL, 0, 0},
  },
  {
    {rosbag2_interfaces__srv__Resume_Response__TYPE_NAME, 38, 38},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
rosbag2_interfaces__srv__Resume__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {rosbag2_interfaces__srv__Resume__TYPE_NAME, 29, 29},
      {rosbag2_interfaces__srv__Resume__FIELDS, 3, 3},
    },
    {rosbag2_interfaces__srv__Resume__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = rosbag2_interfaces__srv__Resume_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = rosbag2_interfaces__srv__Resume_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = rosbag2_interfaces__srv__Resume_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char rosbag2_interfaces__srv__Resume_Request__FIELD_NAME__resume_time[] = "resume_time";
static char rosbag2_interfaces__srv__Resume_Request__FIELD_NAME__resume_mode[] = "resume_mode";
static char rosbag2_interfaces__srv__Resume_Request__FIELD_NAME__tracking_topic_name[] = "tracking_topic_name";

static rosidl_runtime_c__type_description__Field rosbag2_interfaces__srv__Resume_Request__FIELDS[] = {
  {
    {rosbag2_interfaces__srv__Resume_Request__FIELD_NAME__resume_time, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    },
    {NULL, 0, 0},
  },
  {
    {rosbag2_interfaces__srv__Resume_Request__FIELD_NAME__resume_mode, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {rosbag2_interfaces__srv__Resume_Request__FIELD_NAME__tracking_topic_name, 19, 19},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription rosbag2_interfaces__srv__Resume_Request__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
rosbag2_interfaces__srv__Resume_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {rosbag2_interfaces__srv__Resume_Request__TYPE_NAME, 37, 37},
      {rosbag2_interfaces__srv__Resume_Request__FIELDS, 3, 3},
    },
    {rosbag2_interfaces__srv__Resume_Request__REFERENCED_TYPE_DESCRIPTIONS, 1, 1},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char rosbag2_interfaces__srv__Resume_Response__FIELD_NAME__return_code[] = "return_code";
static char rosbag2_interfaces__srv__Resume_Response__FIELD_NAME__error_string[] = "error_string";

static rosidl_runtime_c__type_description__Field rosbag2_interfaces__srv__Resume_Response__FIELDS[] = {
  {
    {rosbag2_interfaces__srv__Resume_Response__FIELD_NAME__return_code, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {rosbag2_interfaces__srv__Resume_Response__FIELD_NAME__error_string, 12, 12},
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
rosbag2_interfaces__srv__Resume_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {rosbag2_interfaces__srv__Resume_Response__TYPE_NAME, 38, 38},
      {rosbag2_interfaces__srv__Resume_Response__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char rosbag2_interfaces__srv__Resume_Event__FIELD_NAME__info[] = "info";
static char rosbag2_interfaces__srv__Resume_Event__FIELD_NAME__request[] = "request";
static char rosbag2_interfaces__srv__Resume_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field rosbag2_interfaces__srv__Resume_Event__FIELDS[] = {
  {
    {rosbag2_interfaces__srv__Resume_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {rosbag2_interfaces__srv__Resume_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {rosbag2_interfaces__srv__Resume_Request__TYPE_NAME, 37, 37},
    },
    {NULL, 0, 0},
  },
  {
    {rosbag2_interfaces__srv__Resume_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {rosbag2_interfaces__srv__Resume_Response__TYPE_NAME, 38, 38},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription rosbag2_interfaces__srv__Resume_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {rosbag2_interfaces__srv__Resume_Request__TYPE_NAME, 37, 37},
    {NULL, 0, 0},
  },
  {
    {rosbag2_interfaces__srv__Resume_Response__TYPE_NAME, 38, 38},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
rosbag2_interfaces__srv__Resume_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {rosbag2_interfaces__srv__Resume_Event__TYPE_NAME, 35, 35},
      {rosbag2_interfaces__srv__Resume_Event__FIELDS, 3, 3},
    },
    {rosbag2_interfaces__srv__Resume_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = rosbag2_interfaces__srv__Resume_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = rosbag2_interfaces__srv__Resume_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# Resume mode to interpret resume_time:\n"
  "# 0 = node_time, 1 = publish_time, 2 = receive_time.\n"
  "int32 RESUME_MODE_NODE_TIME=0\n"
  "int32 RESUME_MODE_PUBLISH_TIME=1\n"
  "int32 RESUME_MODE_RECEIVE_TIME=2\n"
  "\n"
  "# Timestamp in the future when to resume recording/playback.\n"
  "# If empty or time in the past, resumes recording/playback immediately.\n"
  "# Note: The resume_time is not supported by player and shall be set to zero when using Resume with\n"
  "# player.\n"
  "builtin_interfaces/Time resume_time\n"
  "\n"
  "# Resume mode to use for the resume_time request.\n"
  "int32 resume_mode\n"
  "\n"
  "# Topic name to use for timestamp-based resume evaluation.\n"
  "# If empty, evaluate using messages from all topics.\n"
  "string tracking_topic_name\n"
  "---\n"
  "# Return codes for Resume response.\n"
  "int32 RETURN_CODE_SUCCESS=0\n"
  "int32 RETURN_CODE_INVALID_RESUME_MODE=1\n"
  "int32 RETURN_CODE_INVALID_TRACKING_TOPIC=2\n"
  "int32 RETURN_CODE_RESUME_FAILED=3\n"
  "\n"
  "# Return code. Use RETURN_CODE_SUCCESS on success; otherwise use one of the error codes.\n"
  "int32 return_code\n"
  "\n"
  "# Error string. Empty if no error occurred.\n"
  "string error_string";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
rosbag2_interfaces__srv__Resume__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {rosbag2_interfaces__srv__Resume__TYPE_NAME, 29, 29},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 1035, 1035},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
rosbag2_interfaces__srv__Resume_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {rosbag2_interfaces__srv__Resume_Request__TYPE_NAME, 37, 37},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
rosbag2_interfaces__srv__Resume_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {rosbag2_interfaces__srv__Resume_Response__TYPE_NAME, 38, 38},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
rosbag2_interfaces__srv__Resume_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {rosbag2_interfaces__srv__Resume_Event__TYPE_NAME, 35, 35},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
rosbag2_interfaces__srv__Resume__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *rosbag2_interfaces__srv__Resume__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *rosbag2_interfaces__srv__Resume_Event__get_individual_type_description_source(NULL);
    sources[3] = *rosbag2_interfaces__srv__Resume_Request__get_individual_type_description_source(NULL);
    sources[4] = *rosbag2_interfaces__srv__Resume_Response__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
rosbag2_interfaces__srv__Resume_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[2];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 2, 2};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *rosbag2_interfaces__srv__Resume_Request__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
rosbag2_interfaces__srv__Resume_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *rosbag2_interfaces__srv__Resume_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
rosbag2_interfaces__srv__Resume_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *rosbag2_interfaces__srv__Resume_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *rosbag2_interfaces__srv__Resume_Request__get_individual_type_description_source(NULL);
    sources[3] = *rosbag2_interfaces__srv__Resume_Response__get_individual_type_description_source(NULL);
    sources[4] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
