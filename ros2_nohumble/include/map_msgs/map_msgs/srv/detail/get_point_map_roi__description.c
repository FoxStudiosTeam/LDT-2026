// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from map_msgs:srv\GetPointMapROI.idl
// generated code does not contain a copyright notice

#include "map_msgs/srv/detail/get_point_map_roi__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_map_msgs
const rosidl_type_hash_t *
map_msgs__srv__GetPointMapROI__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xc8, 0x54, 0x56, 0x9c, 0x8d, 0xb6, 0x05, 0x13,
      0x2d, 0xc3, 0x82, 0xa4, 0xc1, 0xc3, 0x3c, 0xd8,
      0x23, 0x5b, 0xe5, 0x07, 0x83, 0x17, 0xc4, 0x42,
      0xbf, 0x58, 0x16, 0x8e, 0x3e, 0xb5, 0x84, 0x1c,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_map_msgs
const rosidl_type_hash_t *
map_msgs__srv__GetPointMapROI_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xb7, 0x55, 0xa5, 0xee, 0xa9, 0x06, 0x28, 0x49,
      0x4d, 0xf6, 0x38, 0xdb, 0xc8, 0x4a, 0xb7, 0x37,
      0x04, 0xc8, 0x4f, 0x76, 0xc5, 0x84, 0xa2, 0xc6,
      0x0f, 0xdd, 0x7e, 0xac, 0x28, 0x62, 0xc6, 0xbc,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_map_msgs
const rosidl_type_hash_t *
map_msgs__srv__GetPointMapROI_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xf6, 0x3d, 0xa4, 0x11, 0x74, 0x11, 0x5a, 0xad,
      0x7c, 0xde, 0xf6, 0x99, 0x37, 0x2e, 0xdc, 0x96,
      0x6d, 0x02, 0x7d, 0x99, 0xab, 0xc6, 0x06, 0x2e,
      0xe0, 0x6a, 0x6e, 0xe0, 0x06, 0x6e, 0x0c, 0xff,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_map_msgs
const rosidl_type_hash_t *
map_msgs__srv__GetPointMapROI_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x98, 0xf0, 0x40, 0x07, 0xbe, 0x23, 0x85, 0x98,
      0xd0, 0x82, 0xd1, 0x29, 0xa3, 0xb8, 0x4f, 0xff,
      0xe8, 0x82, 0x26, 0x0d, 0xe6, 0x5f, 0xf2, 0x5c,
      0xc3, 0x0e, 0x34, 0x34, 0x23, 0xa9, 0x74, 0x8b,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "sensor_msgs/msg/detail/point_cloud2__functions.h"
#include "sensor_msgs/msg/detail/point_field__functions.h"
#include "service_msgs/msg/detail/service_event_info__functions.h"
#include "std_msgs/msg/detail/header__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t sensor_msgs__msg__PointCloud2__EXPECTED_HASH = {1, {
    0x91, 0x98, 0xca, 0xbf, 0x7d, 0xa3, 0x79, 0x6a,
    0xe6, 0xfe, 0x19, 0xc4, 0xcb, 0x3b, 0xdd, 0x35,
    0x25, 0x49, 0x29, 0x88, 0xc7, 0x05, 0x22, 0x62,
    0x8a, 0xf5, 0xda, 0xa1, 0x24, 0xba, 0xe2, 0xb5,
  }};
static const rosidl_type_hash_t sensor_msgs__msg__PointField__EXPECTED_HASH = {1, {
    0x5c, 0x6a, 0x47, 0x50, 0x72, 0x8c, 0x2b, 0xcf,
    0xbb, 0xf7, 0x03, 0x72, 0x25, 0xb2, 0x0b, 0x02,
    0xd4, 0x42, 0x96, 0x34, 0x73, 0x21, 0x46, 0xb7,
    0x42, 0xde, 0xe1, 0x72, 0x66, 0x37, 0xef, 0x01,
  }};
static const rosidl_type_hash_t service_msgs__msg__ServiceEventInfo__EXPECTED_HASH = {1, {
    0x41, 0xbc, 0xbb, 0xe0, 0x7a, 0x75, 0xc9, 0xb5,
    0x2b, 0xc9, 0x6b, 0xfd, 0x5c, 0x24, 0xd7, 0xf0,
    0xfc, 0x0a, 0x08, 0xc0, 0xcb, 0x79, 0x21, 0xb3,
    0x37, 0x3c, 0x57, 0x32, 0x34, 0x5a, 0x6f, 0x45,
  }};
static const rosidl_type_hash_t std_msgs__msg__Header__EXPECTED_HASH = {1, {
    0xf4, 0x9f, 0xb3, 0xae, 0x2c, 0xf0, 0x70, 0xf7,
    0x93, 0x64, 0x5f, 0xf7, 0x49, 0x68, 0x3a, 0xc6,
    0xb0, 0x62, 0x03, 0xe4, 0x1c, 0x89, 0x1e, 0x17,
    0x70, 0x1b, 0x1c, 0xb5, 0x97, 0xce, 0x6a, 0x01,
  }};
#endif

static char map_msgs__srv__GetPointMapROI__TYPE_NAME[] = "map_msgs/srv/GetPointMapROI";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char map_msgs__srv__GetPointMapROI_Event__TYPE_NAME[] = "map_msgs/srv/GetPointMapROI_Event";
static char map_msgs__srv__GetPointMapROI_Request__TYPE_NAME[] = "map_msgs/srv/GetPointMapROI_Request";
static char map_msgs__srv__GetPointMapROI_Response__TYPE_NAME[] = "map_msgs/srv/GetPointMapROI_Response";
static char sensor_msgs__msg__PointCloud2__TYPE_NAME[] = "sensor_msgs/msg/PointCloud2";
static char sensor_msgs__msg__PointField__TYPE_NAME[] = "sensor_msgs/msg/PointField";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";
static char std_msgs__msg__Header__TYPE_NAME[] = "std_msgs/msg/Header";

// Define type names, field names, and default values
static char map_msgs__srv__GetPointMapROI__FIELD_NAME__request_message[] = "request_message";
static char map_msgs__srv__GetPointMapROI__FIELD_NAME__response_message[] = "response_message";
static char map_msgs__srv__GetPointMapROI__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field map_msgs__srv__GetPointMapROI__FIELDS[] = {
  {
    {map_msgs__srv__GetPointMapROI__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {map_msgs__srv__GetPointMapROI_Request__TYPE_NAME, 35, 35},
    },
    {NULL, 0, 0},
  },
  {
    {map_msgs__srv__GetPointMapROI__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {map_msgs__srv__GetPointMapROI_Response__TYPE_NAME, 36, 36},
    },
    {NULL, 0, 0},
  },
  {
    {map_msgs__srv__GetPointMapROI__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {map_msgs__srv__GetPointMapROI_Event__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription map_msgs__srv__GetPointMapROI__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {map_msgs__srv__GetPointMapROI_Event__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {map_msgs__srv__GetPointMapROI_Request__TYPE_NAME, 35, 35},
    {NULL, 0, 0},
  },
  {
    {map_msgs__srv__GetPointMapROI_Response__TYPE_NAME, 36, 36},
    {NULL, 0, 0},
  },
  {
    {sensor_msgs__msg__PointCloud2__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {sensor_msgs__msg__PointField__TYPE_NAME, 26, 26},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
map_msgs__srv__GetPointMapROI__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {map_msgs__srv__GetPointMapROI__TYPE_NAME, 27, 27},
      {map_msgs__srv__GetPointMapROI__FIELDS, 3, 3},
    },
    {map_msgs__srv__GetPointMapROI__REFERENCED_TYPE_DESCRIPTIONS, 8, 8},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = map_msgs__srv__GetPointMapROI_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = map_msgs__srv__GetPointMapROI_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = map_msgs__srv__GetPointMapROI_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&sensor_msgs__msg__PointCloud2__EXPECTED_HASH, sensor_msgs__msg__PointCloud2__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = sensor_msgs__msg__PointCloud2__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&sensor_msgs__msg__PointField__EXPECTED_HASH, sensor_msgs__msg__PointField__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[5].fields = sensor_msgs__msg__PointField__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[6].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__Header__EXPECTED_HASH, std_msgs__msg__Header__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[7].fields = std_msgs__msg__Header__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char map_msgs__srv__GetPointMapROI_Request__FIELD_NAME__x[] = "x";
static char map_msgs__srv__GetPointMapROI_Request__FIELD_NAME__y[] = "y";
static char map_msgs__srv__GetPointMapROI_Request__FIELD_NAME__z[] = "z";
static char map_msgs__srv__GetPointMapROI_Request__FIELD_NAME__r[] = "r";
static char map_msgs__srv__GetPointMapROI_Request__FIELD_NAME__l_x[] = "l_x";
static char map_msgs__srv__GetPointMapROI_Request__FIELD_NAME__l_y[] = "l_y";
static char map_msgs__srv__GetPointMapROI_Request__FIELD_NAME__l_z[] = "l_z";

static rosidl_runtime_c__type_description__Field map_msgs__srv__GetPointMapROI_Request__FIELDS[] = {
  {
    {map_msgs__srv__GetPointMapROI_Request__FIELD_NAME__x, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {map_msgs__srv__GetPointMapROI_Request__FIELD_NAME__y, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {map_msgs__srv__GetPointMapROI_Request__FIELD_NAME__z, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {map_msgs__srv__GetPointMapROI_Request__FIELD_NAME__r, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {map_msgs__srv__GetPointMapROI_Request__FIELD_NAME__l_x, 3, 3},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {map_msgs__srv__GetPointMapROI_Request__FIELD_NAME__l_y, 3, 3},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {map_msgs__srv__GetPointMapROI_Request__FIELD_NAME__l_z, 3, 3},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
map_msgs__srv__GetPointMapROI_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {map_msgs__srv__GetPointMapROI_Request__TYPE_NAME, 35, 35},
      {map_msgs__srv__GetPointMapROI_Request__FIELDS, 7, 7},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char map_msgs__srv__GetPointMapROI_Response__FIELD_NAME__sub_map[] = "sub_map";

static rosidl_runtime_c__type_description__Field map_msgs__srv__GetPointMapROI_Response__FIELDS[] = {
  {
    {map_msgs__srv__GetPointMapROI_Response__FIELD_NAME__sub_map, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {sensor_msgs__msg__PointCloud2__TYPE_NAME, 27, 27},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription map_msgs__srv__GetPointMapROI_Response__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {sensor_msgs__msg__PointCloud2__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {sensor_msgs__msg__PointField__TYPE_NAME, 26, 26},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
map_msgs__srv__GetPointMapROI_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {map_msgs__srv__GetPointMapROI_Response__TYPE_NAME, 36, 36},
      {map_msgs__srv__GetPointMapROI_Response__FIELDS, 1, 1},
    },
    {map_msgs__srv__GetPointMapROI_Response__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&sensor_msgs__msg__PointCloud2__EXPECTED_HASH, sensor_msgs__msg__PointCloud2__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = sensor_msgs__msg__PointCloud2__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&sensor_msgs__msg__PointField__EXPECTED_HASH, sensor_msgs__msg__PointField__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = sensor_msgs__msg__PointField__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__Header__EXPECTED_HASH, std_msgs__msg__Header__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = std_msgs__msg__Header__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char map_msgs__srv__GetPointMapROI_Event__FIELD_NAME__info[] = "info";
static char map_msgs__srv__GetPointMapROI_Event__FIELD_NAME__request[] = "request";
static char map_msgs__srv__GetPointMapROI_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field map_msgs__srv__GetPointMapROI_Event__FIELDS[] = {
  {
    {map_msgs__srv__GetPointMapROI_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {map_msgs__srv__GetPointMapROI_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {map_msgs__srv__GetPointMapROI_Request__TYPE_NAME, 35, 35},
    },
    {NULL, 0, 0},
  },
  {
    {map_msgs__srv__GetPointMapROI_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {map_msgs__srv__GetPointMapROI_Response__TYPE_NAME, 36, 36},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription map_msgs__srv__GetPointMapROI_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {map_msgs__srv__GetPointMapROI_Request__TYPE_NAME, 35, 35},
    {NULL, 0, 0},
  },
  {
    {map_msgs__srv__GetPointMapROI_Response__TYPE_NAME, 36, 36},
    {NULL, 0, 0},
  },
  {
    {sensor_msgs__msg__PointCloud2__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {sensor_msgs__msg__PointField__TYPE_NAME, 26, 26},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
map_msgs__srv__GetPointMapROI_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {map_msgs__srv__GetPointMapROI_Event__TYPE_NAME, 33, 33},
      {map_msgs__srv__GetPointMapROI_Event__FIELDS, 3, 3},
    },
    {map_msgs__srv__GetPointMapROI_Event__REFERENCED_TYPE_DESCRIPTIONS, 7, 7},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = map_msgs__srv__GetPointMapROI_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = map_msgs__srv__GetPointMapROI_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&sensor_msgs__msg__PointCloud2__EXPECTED_HASH, sensor_msgs__msg__PointCloud2__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = sensor_msgs__msg__PointCloud2__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&sensor_msgs__msg__PointField__EXPECTED_HASH, sensor_msgs__msg__PointField__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = sensor_msgs__msg__PointField__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[5].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__Header__EXPECTED_HASH, std_msgs__msg__Header__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[6].fields = std_msgs__msg__Header__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float64 x\n"
  "float64 y\n"
  "float64 z\n"
  "float64 r    # if != 0, circular ROI of radius r\n"
  "float64 l_x  # if r == 0, length of AABB on x\n"
  "float64 l_y  # if r == 0, length of AABB on y\n"
  "float64 l_z  # if r == 0, length of AABB on z\n"
  "---\n"
  "sensor_msgs/PointCloud2 sub_map";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
map_msgs__srv__GetPointMapROI__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {map_msgs__srv__GetPointMapROI__TYPE_NAME, 27, 27},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 252, 252},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
map_msgs__srv__GetPointMapROI_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {map_msgs__srv__GetPointMapROI_Request__TYPE_NAME, 35, 35},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
map_msgs__srv__GetPointMapROI_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {map_msgs__srv__GetPointMapROI_Response__TYPE_NAME, 36, 36},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
map_msgs__srv__GetPointMapROI_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {map_msgs__srv__GetPointMapROI_Event__TYPE_NAME, 33, 33},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
map_msgs__srv__GetPointMapROI__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[9];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 9, 9};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *map_msgs__srv__GetPointMapROI__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *map_msgs__srv__GetPointMapROI_Event__get_individual_type_description_source(NULL);
    sources[3] = *map_msgs__srv__GetPointMapROI_Request__get_individual_type_description_source(NULL);
    sources[4] = *map_msgs__srv__GetPointMapROI_Response__get_individual_type_description_source(NULL);
    sources[5] = *sensor_msgs__msg__PointCloud2__get_individual_type_description_source(NULL);
    sources[6] = *sensor_msgs__msg__PointField__get_individual_type_description_source(NULL);
    sources[7] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    sources[8] = *std_msgs__msg__Header__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
map_msgs__srv__GetPointMapROI_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *map_msgs__srv__GetPointMapROI_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
map_msgs__srv__GetPointMapROI_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *map_msgs__srv__GetPointMapROI_Response__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *sensor_msgs__msg__PointCloud2__get_individual_type_description_source(NULL);
    sources[3] = *sensor_msgs__msg__PointField__get_individual_type_description_source(NULL);
    sources[4] = *std_msgs__msg__Header__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
map_msgs__srv__GetPointMapROI_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[8];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 8, 8};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *map_msgs__srv__GetPointMapROI_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *map_msgs__srv__GetPointMapROI_Request__get_individual_type_description_source(NULL);
    sources[3] = *map_msgs__srv__GetPointMapROI_Response__get_individual_type_description_source(NULL);
    sources[4] = *sensor_msgs__msg__PointCloud2__get_individual_type_description_source(NULL);
    sources[5] = *sensor_msgs__msg__PointField__get_individual_type_description_source(NULL);
    sources[6] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    sources[7] = *std_msgs__msg__Header__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
