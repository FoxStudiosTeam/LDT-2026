// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from map_msgs:msg\ProjectedMapInfo.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "map_msgs/msg/projected_map_info.h"


#ifndef MAP_MSGS__MSG__DETAIL__PROJECTED_MAP_INFO__FUNCTIONS_H_
#define MAP_MSGS__MSG__DETAIL__PROJECTED_MAP_INFO__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_runtime_c/type_description/type_description__struct.h"
#include "rosidl_runtime_c/type_description/type_source__struct.h"
#include "rosidl_runtime_c/type_hash.h"
#include "rosidl_runtime_c/visibility_control.h"
#include "map_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "map_msgs/msg/detail/projected_map_info__struct.h"

/// Initialize msg/ProjectedMapInfo message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * map_msgs__msg__ProjectedMapInfo
 * )) before or use
 * map_msgs__msg__ProjectedMapInfo__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_map_msgs
bool
map_msgs__msg__ProjectedMapInfo__init(map_msgs__msg__ProjectedMapInfo * msg);

/// Finalize msg/ProjectedMapInfo message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_map_msgs
void
map_msgs__msg__ProjectedMapInfo__fini(map_msgs__msg__ProjectedMapInfo * msg);

/// Create msg/ProjectedMapInfo message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * map_msgs__msg__ProjectedMapInfo__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_map_msgs
map_msgs__msg__ProjectedMapInfo *
map_msgs__msg__ProjectedMapInfo__create(void);

/// Destroy msg/ProjectedMapInfo message.
/**
 * It calls
 * map_msgs__msg__ProjectedMapInfo__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_map_msgs
void
map_msgs__msg__ProjectedMapInfo__destroy(map_msgs__msg__ProjectedMapInfo * msg);

/// Check for msg/ProjectedMapInfo message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_map_msgs
bool
map_msgs__msg__ProjectedMapInfo__are_equal(const map_msgs__msg__ProjectedMapInfo * lhs, const map_msgs__msg__ProjectedMapInfo * rhs);

/// Copy a msg/ProjectedMapInfo message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_map_msgs
bool
map_msgs__msg__ProjectedMapInfo__copy(
  const map_msgs__msg__ProjectedMapInfo * input,
  map_msgs__msg__ProjectedMapInfo * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_map_msgs
const rosidl_type_hash_t *
map_msgs__msg__ProjectedMapInfo__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_map_msgs
const rosidl_runtime_c__type_description__TypeDescription *
map_msgs__msg__ProjectedMapInfo__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_map_msgs
const rosidl_runtime_c__type_description__TypeSource *
map_msgs__msg__ProjectedMapInfo__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_map_msgs
const rosidl_runtime_c__type_description__TypeSource__Sequence *
map_msgs__msg__ProjectedMapInfo__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of msg/ProjectedMapInfo messages.
/**
 * It allocates the memory for the number of elements and calls
 * map_msgs__msg__ProjectedMapInfo__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_map_msgs
bool
map_msgs__msg__ProjectedMapInfo__Sequence__init(map_msgs__msg__ProjectedMapInfo__Sequence * array, size_t size);

/// Finalize array of msg/ProjectedMapInfo messages.
/**
 * It calls
 * map_msgs__msg__ProjectedMapInfo__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_map_msgs
void
map_msgs__msg__ProjectedMapInfo__Sequence__fini(map_msgs__msg__ProjectedMapInfo__Sequence * array);

/// Create array of msg/ProjectedMapInfo messages.
/**
 * It allocates the memory for the array and calls
 * map_msgs__msg__ProjectedMapInfo__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_map_msgs
map_msgs__msg__ProjectedMapInfo__Sequence *
map_msgs__msg__ProjectedMapInfo__Sequence__create(size_t size);

/// Destroy array of msg/ProjectedMapInfo messages.
/**
 * It calls
 * map_msgs__msg__ProjectedMapInfo__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_map_msgs
void
map_msgs__msg__ProjectedMapInfo__Sequence__destroy(map_msgs__msg__ProjectedMapInfo__Sequence * array);

/// Check for msg/ProjectedMapInfo message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_map_msgs
bool
map_msgs__msg__ProjectedMapInfo__Sequence__are_equal(const map_msgs__msg__ProjectedMapInfo__Sequence * lhs, const map_msgs__msg__ProjectedMapInfo__Sequence * rhs);

/// Copy an array of msg/ProjectedMapInfo messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_map_msgs
bool
map_msgs__msg__ProjectedMapInfo__Sequence__copy(
  const map_msgs__msg__ProjectedMapInfo__Sequence * input,
  map_msgs__msg__ProjectedMapInfo__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // MAP_MSGS__MSG__DETAIL__PROJECTED_MAP_INFO__FUNCTIONS_H_
