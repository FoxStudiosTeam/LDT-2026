// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from rosbag2_interfaces:srv\SplitBagfile.idl
// generated code does not contain a copyright notice

#include "rosbag2_interfaces/srv/detail/split_bagfile__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_rosbag2_interfaces
const rosidl_type_hash_t *
rosbag2_interfaces__srv__SplitBagfile__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xd2, 0xff, 0xa1, 0x05, 0x57, 0x4b, 0x58, 0xe4,
      0x48, 0x89, 0xdf, 0x96, 0x74, 0xf8, 0x7d, 0xcb,
      0x3d, 0x65, 0x3b, 0x7e, 0x8a, 0x2b, 0x44, 0xc2,
      0xf1, 0x7e, 0xe1, 0xdd, 0xdb, 0x9e, 0xaa, 0x1e,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_rosbag2_interfaces
const rosidl_type_hash_t *
rosbag2_interfaces__srv__SplitBagfile_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x45, 0x9a, 0x71, 0xe7, 0x82, 0xa9, 0x2f, 0x9c,
      0x3f, 0xa2, 0x23, 0x52, 0x84, 0xe4, 0xdc, 0x64,
      0x53, 0x6b, 0x61, 0xb3, 0x4c, 0x17, 0x56, 0x76,
      0x27, 0x31, 0xad, 0xf6, 0xdb, 0xa5, 0xd6, 0xf4,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_rosbag2_interfaces
const rosidl_type_hash_t *
rosbag2_interfaces__srv__SplitBagfile_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xee, 0x56, 0xbc, 0xf8, 0x11, 0xb3, 0xb0, 0xa2,
      0x90, 0xc3, 0xcf, 0x8b, 0x24, 0x04, 0x8a, 0x68,
      0x0d, 0x01, 0x14, 0xac, 0x00, 0x1a, 0xa3, 0x70,
      0xee, 0x88, 0x82, 0x14, 0x10, 0xd6, 0xda, 0x7e,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_rosbag2_interfaces
const rosidl_type_hash_t *
rosbag2_interfaces__srv__SplitBagfile_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x1f, 0xe8, 0xe2, 0x3e, 0x71, 0xcb, 0x08, 0x1e,
      0x7c, 0x8f, 0xa2, 0x7c, 0xfe, 0x3e, 0x1a, 0x55,
      0xc9, 0x60, 0xd9, 0x6f, 0x0d, 0x5b, 0x8e, 0x84,
      0x8f, 0x70, 0x39, 0xd1, 0x43, 0x6b, 0xbf, 0xa7,
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

static char rosbag2_interfaces__srv__SplitBagfile__TYPE_NAME[] = "rosbag2_interfaces/srv/SplitBagfile";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char rosbag2_interfaces__srv__SplitBagfile_Event__TYPE_NAME[] = "rosbag2_interfaces/srv/SplitBagfile_Event";
static char rosbag2_interfaces__srv__SplitBagfile_Request__TYPE_NAME[] = "rosbag2_interfaces/srv/SplitBagfile_Request";
static char rosbag2_interfaces__srv__SplitBagfile_Response__TYPE_NAME[] = "rosbag2_interfaces/srv/SplitBagfile_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char rosbag2_interfaces__srv__SplitBagfile__FIELD_NAME__request_message[] = "request_message";
static char rosbag2_interfaces__srv__SplitBagfile__FIELD_NAME__response_message[] = "response_message";
static char rosbag2_interfaces__srv__SplitBagfile__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field rosbag2_interfaces__srv__SplitBagfile__FIELDS[] = {
  {
    {rosbag2_interfaces__srv__SplitBagfile__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {rosbag2_interfaces__srv__SplitBagfile_Request__TYPE_NAME, 43, 43},
    },
    {NULL, 0, 0},
  },
  {
    {rosbag2_interfaces__srv__SplitBagfile__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {rosbag2_interfaces__srv__SplitBagfile_Response__TYPE_NAME, 44, 44},
    },
    {NULL, 0, 0},
  },
  {
    {rosbag2_interfaces__srv__SplitBagfile__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {rosbag2_interfaces__srv__SplitBagfile_Event__TYPE_NAME, 41, 41},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription rosbag2_interfaces__srv__SplitBagfile__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {rosbag2_interfaces__srv__SplitBagfile_Event__TYPE_NAME, 41, 41},
    {NULL, 0, 0},
  },
  {
    {rosbag2_interfaces__srv__SplitBagfile_Request__TYPE_NAME, 43, 43},
    {NULL, 0, 0},
  },
  {
    {rosbag2_interfaces__srv__SplitBagfile_Response__TYPE_NAME, 44, 44},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
rosbag2_interfaces__srv__SplitBagfile__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {rosbag2_interfaces__srv__SplitBagfile__TYPE_NAME, 35, 35},
      {rosbag2_interfaces__srv__SplitBagfile__FIELDS, 3, 3},
    },
    {rosbag2_interfaces__srv__SplitBagfile__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = rosbag2_interfaces__srv__SplitBagfile_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = rosbag2_interfaces__srv__SplitBagfile_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = rosbag2_interfaces__srv__SplitBagfile_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char rosbag2_interfaces__srv__SplitBagfile_Request__FIELD_NAME__split_time[] = "split_time";
static char rosbag2_interfaces__srv__SplitBagfile_Request__FIELD_NAME__split_mode[] = "split_mode";
static char rosbag2_interfaces__srv__SplitBagfile_Request__FIELD_NAME__tracking_topic_name[] = "tracking_topic_name";

static rosidl_runtime_c__type_description__Field rosbag2_interfaces__srv__SplitBagfile_Request__FIELDS[] = {
  {
    {rosbag2_interfaces__srv__SplitBagfile_Request__FIELD_NAME__split_time, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    },
    {NULL, 0, 0},
  },
  {
    {rosbag2_interfaces__srv__SplitBagfile_Request__FIELD_NAME__split_mode, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {rosbag2_interfaces__srv__SplitBagfile_Request__FIELD_NAME__tracking_topic_name, 19, 19},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription rosbag2_interfaces__srv__SplitBagfile_Request__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
rosbag2_interfaces__srv__SplitBagfile_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {rosbag2_interfaces__srv__SplitBagfile_Request__TYPE_NAME, 43, 43},
      {rosbag2_interfaces__srv__SplitBagfile_Request__FIELDS, 3, 3},
    },
    {rosbag2_interfaces__srv__SplitBagfile_Request__REFERENCED_TYPE_DESCRIPTIONS, 1, 1},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char rosbag2_interfaces__srv__SplitBagfile_Response__FIELD_NAME__return_code[] = "return_code";
static char rosbag2_interfaces__srv__SplitBagfile_Response__FIELD_NAME__error_string[] = "error_string";

static rosidl_runtime_c__type_description__Field rosbag2_interfaces__srv__SplitBagfile_Response__FIELDS[] = {
  {
    {rosbag2_interfaces__srv__SplitBagfile_Response__FIELD_NAME__return_code, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {rosbag2_interfaces__srv__SplitBagfile_Response__FIELD_NAME__error_string, 12, 12},
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
rosbag2_interfaces__srv__SplitBagfile_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {rosbag2_interfaces__srv__SplitBagfile_Response__TYPE_NAME, 44, 44},
      {rosbag2_interfaces__srv__SplitBagfile_Response__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char rosbag2_interfaces__srv__SplitBagfile_Event__FIELD_NAME__info[] = "info";
static char rosbag2_interfaces__srv__SplitBagfile_Event__FIELD_NAME__request[] = "request";
static char rosbag2_interfaces__srv__SplitBagfile_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field rosbag2_interfaces__srv__SplitBagfile_Event__FIELDS[] = {
  {
    {rosbag2_interfaces__srv__SplitBagfile_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {rosbag2_interfaces__srv__SplitBagfile_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {rosbag2_interfaces__srv__SplitBagfile_Request__TYPE_NAME, 43, 43},
    },
    {NULL, 0, 0},
  },
  {
    {rosbag2_interfaces__srv__SplitBagfile_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {rosbag2_interfaces__srv__SplitBagfile_Response__TYPE_NAME, 44, 44},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription rosbag2_interfaces__srv__SplitBagfile_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {rosbag2_interfaces__srv__SplitBagfile_Request__TYPE_NAME, 43, 43},
    {NULL, 0, 0},
  },
  {
    {rosbag2_interfaces__srv__SplitBagfile_Response__TYPE_NAME, 44, 44},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
rosbag2_interfaces__srv__SplitBagfile_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {rosbag2_interfaces__srv__SplitBagfile_Event__TYPE_NAME, 41, 41},
      {rosbag2_interfaces__srv__SplitBagfile_Event__FIELDS, 3, 3},
    },
    {rosbag2_interfaces__srv__SplitBagfile_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = rosbag2_interfaces__srv__SplitBagfile_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = rosbag2_interfaces__srv__SplitBagfile_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# Split mode to interpret split_time:\n"
  "# 0 = node_time, 1 = publish_time, 2 = receive_time.\n"
  "int32 SPLIT_MODE_NODE_TIME=0\n"
  "int32 SPLIT_MODE_PUBLISH_TIME=1\n"
  "int32 SPLIT_MODE_RECEIVE_TIME=2\n"
  "\n"
  "# Timestamp in the future when to split bag file.\n"
  "# If empty or time in the past, split bag file immediately.\n"
  "builtin_interfaces/Time split_time\n"
  "\n"
  "# Split mode to use for the split_time request.\n"
  "int32 split_mode\n"
  "\n"
  "# Topic name to use for timestamp-based split evaluation.\n"
  "# If empty, evaluate using messages from all topics.\n"
  "string tracking_topic_name\n"
  "---\n"
  "# Return codes for SplitBagfile response.\n"
  "int32 RETURN_CODE_SUCCESS=0\n"
  "int32 RETURN_CODE_NOT_RECORDING=1\n"
  "int32 RETURN_CODE_INVALID_SPLIT_MODE=2\n"
  "int32 RETURN_CODE_INVALID_TRACKING_TOPIC=3\n"
  "int32 RETURN_CODE_SPLIT_FAILED=4\n"
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
rosbag2_interfaces__srv__SplitBagfile__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {rosbag2_interfaces__srv__SplitBagfile__TYPE_NAME, 35, 35},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 931, 931},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
rosbag2_interfaces__srv__SplitBagfile_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {rosbag2_interfaces__srv__SplitBagfile_Request__TYPE_NAME, 43, 43},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
rosbag2_interfaces__srv__SplitBagfile_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {rosbag2_interfaces__srv__SplitBagfile_Response__TYPE_NAME, 44, 44},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
rosbag2_interfaces__srv__SplitBagfile_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {rosbag2_interfaces__srv__SplitBagfile_Event__TYPE_NAME, 41, 41},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
rosbag2_interfaces__srv__SplitBagfile__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *rosbag2_interfaces__srv__SplitBagfile__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *rosbag2_interfaces__srv__SplitBagfile_Event__get_individual_type_description_source(NULL);
    sources[3] = *rosbag2_interfaces__srv__SplitBagfile_Request__get_individual_type_description_source(NULL);
    sources[4] = *rosbag2_interfaces__srv__SplitBagfile_Response__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
rosbag2_interfaces__srv__SplitBagfile_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[2];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 2, 2};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *rosbag2_interfaces__srv__SplitBagfile_Request__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
rosbag2_interfaces__srv__SplitBagfile_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *rosbag2_interfaces__srv__SplitBagfile_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
rosbag2_interfaces__srv__SplitBagfile_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *rosbag2_interfaces__srv__SplitBagfile_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *rosbag2_interfaces__srv__SplitBagfile_Request__get_individual_type_description_source(NULL);
    sources[3] = *rosbag2_interfaces__srv__SplitBagfile_Response__get_individual_type_description_source(NULL);
    sources[4] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
