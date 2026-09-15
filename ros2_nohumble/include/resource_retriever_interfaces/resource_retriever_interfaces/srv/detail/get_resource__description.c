// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from resource_retriever_interfaces:srv\GetResource.idl
// generated code does not contain a copyright notice

#include "resource_retriever_interfaces/srv/detail/get_resource__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_resource_retriever_interfaces
const rosidl_type_hash_t *
resource_retriever_interfaces__srv__GetResource__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xb3, 0x05, 0x7d, 0x45, 0xe2, 0xa3, 0xf1, 0x30,
      0xfd, 0xf7, 0xb9, 0xee, 0x90, 0xda, 0x80, 0xcd,
      0x1a, 0x3d, 0xe6, 0xed, 0x02, 0x91, 0x5d, 0xd4,
      0xbf, 0xf7, 0x00, 0xc5, 0xb0, 0x4c, 0x91, 0x86,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_resource_retriever_interfaces
const rosidl_type_hash_t *
resource_retriever_interfaces__srv__GetResource_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x7b, 0xca, 0xea, 0x26, 0x26, 0x19, 0xa7, 0xc4,
      0xcf, 0xab, 0x28, 0x6c, 0x8f, 0x39, 0x09, 0x12,
      0x3b, 0xc9, 0x13, 0x33, 0xb8, 0xe7, 0xd7, 0x32,
      0x59, 0x1b, 0x81, 0xed, 0x68, 0x22, 0x90, 0xe8,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_resource_retriever_interfaces
const rosidl_type_hash_t *
resource_retriever_interfaces__srv__GetResource_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x0f, 0x86, 0x40, 0x47, 0x80, 0x09, 0xb2, 0xe7,
      0x5d, 0x50, 0x08, 0x04, 0x82, 0x5d, 0xe8, 0xd1,
      0x26, 0xf2, 0xc8, 0x25, 0xe8, 0xfb, 0xbb, 0x81,
      0x5e, 0x27, 0x75, 0x52, 0x3b, 0x02, 0xac, 0x41,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_resource_retriever_interfaces
const rosidl_type_hash_t *
resource_retriever_interfaces__srv__GetResource_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x1d, 0xe5, 0x5e, 0xab, 0x66, 0x5d, 0x4f, 0x6b,
      0x13, 0xf8, 0xe0, 0xab, 0x76, 0x17, 0xd0, 0x2e,
      0x61, 0x4f, 0xc2, 0xe0, 0x77, 0x9a, 0xac, 0x4b,
      0x7a, 0x24, 0xe9, 0xfc, 0x80, 0x04, 0x11, 0xe1,
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

static char resource_retriever_interfaces__srv__GetResource__TYPE_NAME[] = "resource_retriever_interfaces/srv/GetResource";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char resource_retriever_interfaces__srv__GetResource_Event__TYPE_NAME[] = "resource_retriever_interfaces/srv/GetResource_Event";
static char resource_retriever_interfaces__srv__GetResource_Request__TYPE_NAME[] = "resource_retriever_interfaces/srv/GetResource_Request";
static char resource_retriever_interfaces__srv__GetResource_Response__TYPE_NAME[] = "resource_retriever_interfaces/srv/GetResource_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char resource_retriever_interfaces__srv__GetResource__FIELD_NAME__request_message[] = "request_message";
static char resource_retriever_interfaces__srv__GetResource__FIELD_NAME__response_message[] = "response_message";
static char resource_retriever_interfaces__srv__GetResource__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field resource_retriever_interfaces__srv__GetResource__FIELDS[] = {
  {
    {resource_retriever_interfaces__srv__GetResource__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {resource_retriever_interfaces__srv__GetResource_Request__TYPE_NAME, 53, 53},
    },
    {NULL, 0, 0},
  },
  {
    {resource_retriever_interfaces__srv__GetResource__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {resource_retriever_interfaces__srv__GetResource_Response__TYPE_NAME, 54, 54},
    },
    {NULL, 0, 0},
  },
  {
    {resource_retriever_interfaces__srv__GetResource__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {resource_retriever_interfaces__srv__GetResource_Event__TYPE_NAME, 51, 51},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription resource_retriever_interfaces__srv__GetResource__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {resource_retriever_interfaces__srv__GetResource_Event__TYPE_NAME, 51, 51},
    {NULL, 0, 0},
  },
  {
    {resource_retriever_interfaces__srv__GetResource_Request__TYPE_NAME, 53, 53},
    {NULL, 0, 0},
  },
  {
    {resource_retriever_interfaces__srv__GetResource_Response__TYPE_NAME, 54, 54},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
resource_retriever_interfaces__srv__GetResource__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {resource_retriever_interfaces__srv__GetResource__TYPE_NAME, 45, 45},
      {resource_retriever_interfaces__srv__GetResource__FIELDS, 3, 3},
    },
    {resource_retriever_interfaces__srv__GetResource__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = resource_retriever_interfaces__srv__GetResource_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = resource_retriever_interfaces__srv__GetResource_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = resource_retriever_interfaces__srv__GetResource_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char resource_retriever_interfaces__srv__GetResource_Request__FIELD_NAME__path[] = "path";
static char resource_retriever_interfaces__srv__GetResource_Request__FIELD_NAME__etag[] = "etag";

static rosidl_runtime_c__type_description__Field resource_retriever_interfaces__srv__GetResource_Request__FIELDS[] = {
  {
    {resource_retriever_interfaces__srv__GetResource_Request__FIELD_NAME__path, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {resource_retriever_interfaces__srv__GetResource_Request__FIELD_NAME__etag, 4, 4},
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
resource_retriever_interfaces__srv__GetResource_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {resource_retriever_interfaces__srv__GetResource_Request__TYPE_NAME, 53, 53},
      {resource_retriever_interfaces__srv__GetResource_Request__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char resource_retriever_interfaces__srv__GetResource_Response__FIELD_NAME__status_code[] = "status_code";
static char resource_retriever_interfaces__srv__GetResource_Response__FIELD_NAME__error_reason[] = "error_reason";
static char resource_retriever_interfaces__srv__GetResource_Response__FIELD_NAME__expanded_path[] = "expanded_path";
static char resource_retriever_interfaces__srv__GetResource_Response__FIELD_NAME__etag[] = "etag";
static char resource_retriever_interfaces__srv__GetResource_Response__FIELD_NAME__body[] = "body";

static rosidl_runtime_c__type_description__Field resource_retriever_interfaces__srv__GetResource_Response__FIELDS[] = {
  {
    {resource_retriever_interfaces__srv__GetResource_Response__FIELD_NAME__status_code, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {resource_retriever_interfaces__srv__GetResource_Response__FIELD_NAME__error_reason, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {resource_retriever_interfaces__srv__GetResource_Response__FIELD_NAME__expanded_path, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {resource_retriever_interfaces__srv__GetResource_Response__FIELD_NAME__etag, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {resource_retriever_interfaces__srv__GetResource_Response__FIELD_NAME__body, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
resource_retriever_interfaces__srv__GetResource_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {resource_retriever_interfaces__srv__GetResource_Response__TYPE_NAME, 54, 54},
      {resource_retriever_interfaces__srv__GetResource_Response__FIELDS, 5, 5},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char resource_retriever_interfaces__srv__GetResource_Event__FIELD_NAME__info[] = "info";
static char resource_retriever_interfaces__srv__GetResource_Event__FIELD_NAME__request[] = "request";
static char resource_retriever_interfaces__srv__GetResource_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field resource_retriever_interfaces__srv__GetResource_Event__FIELDS[] = {
  {
    {resource_retriever_interfaces__srv__GetResource_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {resource_retriever_interfaces__srv__GetResource_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {resource_retriever_interfaces__srv__GetResource_Request__TYPE_NAME, 53, 53},
    },
    {NULL, 0, 0},
  },
  {
    {resource_retriever_interfaces__srv__GetResource_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {resource_retriever_interfaces__srv__GetResource_Response__TYPE_NAME, 54, 54},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription resource_retriever_interfaces__srv__GetResource_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {resource_retriever_interfaces__srv__GetResource_Request__TYPE_NAME, 53, 53},
    {NULL, 0, 0},
  },
  {
    {resource_retriever_interfaces__srv__GetResource_Response__TYPE_NAME, 54, 54},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
resource_retriever_interfaces__srv__GetResource_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {resource_retriever_interfaces__srv__GetResource_Event__TYPE_NAME, 51, 51},
      {resource_retriever_interfaces__srv__GetResource_Event__FIELDS, 3, 3},
    },
    {resource_retriever_interfaces__srv__GetResource_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = resource_retriever_interfaces__srv__GetResource_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = resource_retriever_interfaces__srv__GetResource_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# Resource path of the requested resource.\n"
  "string path\n"
  "\n"
  "# HTTP-style ETag value for the requested resource.\n"
  "# See: https://en.wikipedia.org/wiki/HTTP_ETag\n"
  "#\n"
  "# If this value is empty, then the server shall respond with the current\n"
  "# version of the resource and the ETag value, if it can be loaded.\n"
  "# If this value is not-empty, then the server may respond with a new resource\n"
  "# and ETag value.\n"
  "# However, if the ETag value for the resource has not changed, then the server\n"
  "# may respond with NOT_MODIFIED as the status_code, similar to\n"
  "# \"HTTP 304: Not Modified\".\n"
  "# See: https://en.wikipedia.org/wiki/List_of_HTTP_status_codes#304\n"
  "# The server may also ignore this value and always send the current version\n"
  "# of the resource and its ETag value, if caching is not implemented.\n"
  "string etag\n"
  "\n"
  "---\n"
  "\n"
  "# An unspecified error occurred, check the error_reason string.\n"
  "int32 ERROR=0\n"
  "\n"
  "# The request was successful, etag and body will be set with valid values,\n"
  "# though etag may be empty.\n"
  "# The error_reason will be empty.\n"
  "int32 OK=1\n"
  "\n"
  "# The request was successful, but the etag value has not changed.\n"
  "# The etag value will be set to the requested etag value, but the body value\n"
  "# will be empty.\n"
  "# The error_reason should also be empty.\n"
  "int32 NOT_MODIFIED=2\n"
  "\n"
  "# Status code for the request, can be one of the above options.\n"
  "int32 status_code\n"
  "\n"
  "# Optionally set error reason string.\n"
  "string error_reason\n"
  "\n"
  "# Expanded path, which may or may not be different from the given path.\n"
  "# The Service may expand, extend, or otherwise further qualify the path as it\n"
  "# resolves it, any of which would be reflected in this expanded path.\n"
  "string expanded_path\n"
  "\n"
  "# HTTP-style ETag value for the requested resource.\n"
  "# See: https://en.wikipedia.org/wiki/HTTP_ETag\n"
  "#\n"
  "# As with the HTTP ETag, the value is unspecified, but it is described as:\n"
  "#\n"
  "# > Common methods of ETag generation include using a collision-resistant hash\n"
  "# > function of the resource's content, a hash of the last modification\n"
  "# > timestamp, or even just a revision number.\n"
  "#\n"
  "# This value may be empty if the server does not implement cache checking.\n"
  "#\n"
  "# This can be sent on subsequent requests to avoid getting the same unchanged\n"
  "# resource multiple times.\n"
  "string etag\n"
  "\n"
  "# Opaque value of the resource.\n"
  "uint8[] body";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
resource_retriever_interfaces__srv__GetResource__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {resource_retriever_interfaces__srv__GetResource__TYPE_NAME, 45, 45},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 2246, 2246},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
resource_retriever_interfaces__srv__GetResource_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {resource_retriever_interfaces__srv__GetResource_Request__TYPE_NAME, 53, 53},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
resource_retriever_interfaces__srv__GetResource_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {resource_retriever_interfaces__srv__GetResource_Response__TYPE_NAME, 54, 54},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
resource_retriever_interfaces__srv__GetResource_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {resource_retriever_interfaces__srv__GetResource_Event__TYPE_NAME, 51, 51},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
resource_retriever_interfaces__srv__GetResource__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *resource_retriever_interfaces__srv__GetResource__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *resource_retriever_interfaces__srv__GetResource_Event__get_individual_type_description_source(NULL);
    sources[3] = *resource_retriever_interfaces__srv__GetResource_Request__get_individual_type_description_source(NULL);
    sources[4] = *resource_retriever_interfaces__srv__GetResource_Response__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
resource_retriever_interfaces__srv__GetResource_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *resource_retriever_interfaces__srv__GetResource_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
resource_retriever_interfaces__srv__GetResource_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *resource_retriever_interfaces__srv__GetResource_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
resource_retriever_interfaces__srv__GetResource_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *resource_retriever_interfaces__srv__GetResource_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *resource_retriever_interfaces__srv__GetResource_Request__get_individual_type_description_source(NULL);
    sources[3] = *resource_retriever_interfaces__srv__GetResource_Response__get_individual_type_description_source(NULL);
    sources[4] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
