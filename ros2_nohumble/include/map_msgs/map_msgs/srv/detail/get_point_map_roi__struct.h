// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from map_msgs:srv\GetPointMapROI.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "map_msgs/srv/get_point_map_roi.h"


#ifndef MAP_MSGS__SRV__DETAIL__GET_POINT_MAP_ROI__STRUCT_H_
#define MAP_MSGS__SRV__DETAIL__GET_POINT_MAP_ROI__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/GetPointMapROI in the package map_msgs.
typedef struct map_msgs__srv__GetPointMapROI_Request
{
  double x;
  double y;
  double z;
  /// if != 0, circular ROI of radius r
  double r;
  /// if r == 0, length of AABB on x
  double l_x;
  /// if r == 0, length of AABB on y
  double l_y;
  /// if r == 0, length of AABB on z
  double l_z;
} map_msgs__srv__GetPointMapROI_Request;

// Struct for a sequence of map_msgs__srv__GetPointMapROI_Request.
typedef struct map_msgs__srv__GetPointMapROI_Request__Sequence
{
  map_msgs__srv__GetPointMapROI_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} map_msgs__srv__GetPointMapROI_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'sub_map'
#include "sensor_msgs/msg/detail/point_cloud2__struct.h"

/// Struct defined in srv/GetPointMapROI in the package map_msgs.
typedef struct map_msgs__srv__GetPointMapROI_Response
{
  sensor_msgs__msg__PointCloud2 sub_map;
} map_msgs__srv__GetPointMapROI_Response;

// Struct for a sequence of map_msgs__srv__GetPointMapROI_Response.
typedef struct map_msgs__srv__GetPointMapROI_Response__Sequence
{
  map_msgs__srv__GetPointMapROI_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} map_msgs__srv__GetPointMapROI_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  map_msgs__srv__GetPointMapROI_Event__request__MAX_SIZE = 1
};
// response
enum
{
  map_msgs__srv__GetPointMapROI_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/GetPointMapROI in the package map_msgs.
typedef struct map_msgs__srv__GetPointMapROI_Event
{
  service_msgs__msg__ServiceEventInfo info;
  map_msgs__srv__GetPointMapROI_Request__Sequence request;
  map_msgs__srv__GetPointMapROI_Response__Sequence response;
} map_msgs__srv__GetPointMapROI_Event;

// Struct for a sequence of map_msgs__srv__GetPointMapROI_Event.
typedef struct map_msgs__srv__GetPointMapROI_Event__Sequence
{
  map_msgs__srv__GetPointMapROI_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} map_msgs__srv__GetPointMapROI_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MAP_MSGS__SRV__DETAIL__GET_POINT_MAP_ROI__STRUCT_H_
