// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from turtlesim_msgs:msg\Pose.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "turtlesim_msgs/msg/pose.h"


#ifndef TURTLESIM_MSGS__MSG__DETAIL__POSE__FUNCTIONS_H_
#define TURTLESIM_MSGS__MSG__DETAIL__POSE__FUNCTIONS_H_

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
#include "turtlesim_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "turtlesim_msgs/msg/detail/pose__struct.h"

/// Initialize msg/Pose message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * turtlesim_msgs__msg__Pose
 * )) before or use
 * turtlesim_msgs__msg__Pose__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_turtlesim_msgs
bool
turtlesim_msgs__msg__Pose__init(turtlesim_msgs__msg__Pose * msg);

/// Finalize msg/Pose message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_turtlesim_msgs
void
turtlesim_msgs__msg__Pose__fini(turtlesim_msgs__msg__Pose * msg);

/// Create msg/Pose message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * turtlesim_msgs__msg__Pose__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_turtlesim_msgs
turtlesim_msgs__msg__Pose *
turtlesim_msgs__msg__Pose__create(void);

/// Destroy msg/Pose message.
/**
 * It calls
 * turtlesim_msgs__msg__Pose__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_turtlesim_msgs
void
turtlesim_msgs__msg__Pose__destroy(turtlesim_msgs__msg__Pose * msg);

/// Check for msg/Pose message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_turtlesim_msgs
bool
turtlesim_msgs__msg__Pose__are_equal(const turtlesim_msgs__msg__Pose * lhs, const turtlesim_msgs__msg__Pose * rhs);

/// Copy a msg/Pose message.
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
ROSIDL_GENERATOR_C_PUBLIC_turtlesim_msgs
bool
turtlesim_msgs__msg__Pose__copy(
  const turtlesim_msgs__msg__Pose * input,
  turtlesim_msgs__msg__Pose * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_turtlesim_msgs
const rosidl_type_hash_t *
turtlesim_msgs__msg__Pose__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_turtlesim_msgs
const rosidl_runtime_c__type_description__TypeDescription *
turtlesim_msgs__msg__Pose__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_turtlesim_msgs
const rosidl_runtime_c__type_description__TypeSource *
turtlesim_msgs__msg__Pose__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_turtlesim_msgs
const rosidl_runtime_c__type_description__TypeSource__Sequence *
turtlesim_msgs__msg__Pose__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of msg/Pose messages.
/**
 * It allocates the memory for the number of elements and calls
 * turtlesim_msgs__msg__Pose__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_turtlesim_msgs
bool
turtlesim_msgs__msg__Pose__Sequence__init(turtlesim_msgs__msg__Pose__Sequence * array, size_t size);

/// Finalize array of msg/Pose messages.
/**
 * It calls
 * turtlesim_msgs__msg__Pose__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_turtlesim_msgs
void
turtlesim_msgs__msg__Pose__Sequence__fini(turtlesim_msgs__msg__Pose__Sequence * array);

/// Create array of msg/Pose messages.
/**
 * It allocates the memory for the array and calls
 * turtlesim_msgs__msg__Pose__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_turtlesim_msgs
turtlesim_msgs__msg__Pose__Sequence *
turtlesim_msgs__msg__Pose__Sequence__create(size_t size);

/// Destroy array of msg/Pose messages.
/**
 * It calls
 * turtlesim_msgs__msg__Pose__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_turtlesim_msgs
void
turtlesim_msgs__msg__Pose__Sequence__destroy(turtlesim_msgs__msg__Pose__Sequence * array);

/// Check for msg/Pose message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_turtlesim_msgs
bool
turtlesim_msgs__msg__Pose__Sequence__are_equal(const turtlesim_msgs__msg__Pose__Sequence * lhs, const turtlesim_msgs__msg__Pose__Sequence * rhs);

/// Copy an array of msg/Pose messages.
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
ROSIDL_GENERATOR_C_PUBLIC_turtlesim_msgs
bool
turtlesim_msgs__msg__Pose__Sequence__copy(
  const turtlesim_msgs__msg__Pose__Sequence * input,
  turtlesim_msgs__msg__Pose__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // TURTLESIM_MSGS__MSG__DETAIL__POSE__FUNCTIONS_H_
