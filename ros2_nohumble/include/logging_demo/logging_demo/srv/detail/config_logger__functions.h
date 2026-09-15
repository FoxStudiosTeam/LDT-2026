// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from logging_demo:srv\ConfigLogger.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "logging_demo/srv/config_logger.h"


#ifndef LOGGING_DEMO__SRV__DETAIL__CONFIG_LOGGER__FUNCTIONS_H_
#define LOGGING_DEMO__SRV__DETAIL__CONFIG_LOGGER__FUNCTIONS_H_

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
#include "logging_demo/msg/rosidl_generator_c__visibility_control.h"

#include "logging_demo/srv/detail/config_logger__struct.h"

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_logging_demo
const rosidl_type_hash_t *
logging_demo__srv__ConfigLogger__get_type_hash(
  const rosidl_service_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_logging_demo
const rosidl_runtime_c__type_description__TypeDescription *
logging_demo__srv__ConfigLogger__get_type_description(
  const rosidl_service_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_logging_demo
const rosidl_runtime_c__type_description__TypeSource *
logging_demo__srv__ConfigLogger__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_logging_demo
const rosidl_runtime_c__type_description__TypeSource__Sequence *
logging_demo__srv__ConfigLogger__get_type_description_sources(
  const rosidl_service_type_support_t * type_support);

/// Initialize srv/ConfigLogger message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * logging_demo__srv__ConfigLogger_Request
 * )) before or use
 * logging_demo__srv__ConfigLogger_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_logging_demo
bool
logging_demo__srv__ConfigLogger_Request__init(logging_demo__srv__ConfigLogger_Request * msg);

/// Finalize srv/ConfigLogger message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_logging_demo
void
logging_demo__srv__ConfigLogger_Request__fini(logging_demo__srv__ConfigLogger_Request * msg);

/// Create srv/ConfigLogger message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * logging_demo__srv__ConfigLogger_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_logging_demo
logging_demo__srv__ConfigLogger_Request *
logging_demo__srv__ConfigLogger_Request__create(void);

/// Destroy srv/ConfigLogger message.
/**
 * It calls
 * logging_demo__srv__ConfigLogger_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_logging_demo
void
logging_demo__srv__ConfigLogger_Request__destroy(logging_demo__srv__ConfigLogger_Request * msg);

/// Check for srv/ConfigLogger message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_logging_demo
bool
logging_demo__srv__ConfigLogger_Request__are_equal(const logging_demo__srv__ConfigLogger_Request * lhs, const logging_demo__srv__ConfigLogger_Request * rhs);

/// Copy a srv/ConfigLogger message.
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
ROSIDL_GENERATOR_C_PUBLIC_logging_demo
bool
logging_demo__srv__ConfigLogger_Request__copy(
  const logging_demo__srv__ConfigLogger_Request * input,
  logging_demo__srv__ConfigLogger_Request * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_logging_demo
const rosidl_type_hash_t *
logging_demo__srv__ConfigLogger_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_logging_demo
const rosidl_runtime_c__type_description__TypeDescription *
logging_demo__srv__ConfigLogger_Request__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_logging_demo
const rosidl_runtime_c__type_description__TypeSource *
logging_demo__srv__ConfigLogger_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_logging_demo
const rosidl_runtime_c__type_description__TypeSource__Sequence *
logging_demo__srv__ConfigLogger_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of srv/ConfigLogger messages.
/**
 * It allocates the memory for the number of elements and calls
 * logging_demo__srv__ConfigLogger_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_logging_demo
bool
logging_demo__srv__ConfigLogger_Request__Sequence__init(logging_demo__srv__ConfigLogger_Request__Sequence * array, size_t size);

/// Finalize array of srv/ConfigLogger messages.
/**
 * It calls
 * logging_demo__srv__ConfigLogger_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_logging_demo
void
logging_demo__srv__ConfigLogger_Request__Sequence__fini(logging_demo__srv__ConfigLogger_Request__Sequence * array);

/// Create array of srv/ConfigLogger messages.
/**
 * It allocates the memory for the array and calls
 * logging_demo__srv__ConfigLogger_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_logging_demo
logging_demo__srv__ConfigLogger_Request__Sequence *
logging_demo__srv__ConfigLogger_Request__Sequence__create(size_t size);

/// Destroy array of srv/ConfigLogger messages.
/**
 * It calls
 * logging_demo__srv__ConfigLogger_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_logging_demo
void
logging_demo__srv__ConfigLogger_Request__Sequence__destroy(logging_demo__srv__ConfigLogger_Request__Sequence * array);

/// Check for srv/ConfigLogger message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_logging_demo
bool
logging_demo__srv__ConfigLogger_Request__Sequence__are_equal(const logging_demo__srv__ConfigLogger_Request__Sequence * lhs, const logging_demo__srv__ConfigLogger_Request__Sequence * rhs);

/// Copy an array of srv/ConfigLogger messages.
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
ROSIDL_GENERATOR_C_PUBLIC_logging_demo
bool
logging_demo__srv__ConfigLogger_Request__Sequence__copy(
  const logging_demo__srv__ConfigLogger_Request__Sequence * input,
  logging_demo__srv__ConfigLogger_Request__Sequence * output);

/// Initialize srv/ConfigLogger message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * logging_demo__srv__ConfigLogger_Response
 * )) before or use
 * logging_demo__srv__ConfigLogger_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_logging_demo
bool
logging_demo__srv__ConfigLogger_Response__init(logging_demo__srv__ConfigLogger_Response * msg);

/// Finalize srv/ConfigLogger message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_logging_demo
void
logging_demo__srv__ConfigLogger_Response__fini(logging_demo__srv__ConfigLogger_Response * msg);

/// Create srv/ConfigLogger message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * logging_demo__srv__ConfigLogger_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_logging_demo
logging_demo__srv__ConfigLogger_Response *
logging_demo__srv__ConfigLogger_Response__create(void);

/// Destroy srv/ConfigLogger message.
/**
 * It calls
 * logging_demo__srv__ConfigLogger_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_logging_demo
void
logging_demo__srv__ConfigLogger_Response__destroy(logging_demo__srv__ConfigLogger_Response * msg);

/// Check for srv/ConfigLogger message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_logging_demo
bool
logging_demo__srv__ConfigLogger_Response__are_equal(const logging_demo__srv__ConfigLogger_Response * lhs, const logging_demo__srv__ConfigLogger_Response * rhs);

/// Copy a srv/ConfigLogger message.
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
ROSIDL_GENERATOR_C_PUBLIC_logging_demo
bool
logging_demo__srv__ConfigLogger_Response__copy(
  const logging_demo__srv__ConfigLogger_Response * input,
  logging_demo__srv__ConfigLogger_Response * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_logging_demo
const rosidl_type_hash_t *
logging_demo__srv__ConfigLogger_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_logging_demo
const rosidl_runtime_c__type_description__TypeDescription *
logging_demo__srv__ConfigLogger_Response__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_logging_demo
const rosidl_runtime_c__type_description__TypeSource *
logging_demo__srv__ConfigLogger_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_logging_demo
const rosidl_runtime_c__type_description__TypeSource__Sequence *
logging_demo__srv__ConfigLogger_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of srv/ConfigLogger messages.
/**
 * It allocates the memory for the number of elements and calls
 * logging_demo__srv__ConfigLogger_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_logging_demo
bool
logging_demo__srv__ConfigLogger_Response__Sequence__init(logging_demo__srv__ConfigLogger_Response__Sequence * array, size_t size);

/// Finalize array of srv/ConfigLogger messages.
/**
 * It calls
 * logging_demo__srv__ConfigLogger_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_logging_demo
void
logging_demo__srv__ConfigLogger_Response__Sequence__fini(logging_demo__srv__ConfigLogger_Response__Sequence * array);

/// Create array of srv/ConfigLogger messages.
/**
 * It allocates the memory for the array and calls
 * logging_demo__srv__ConfigLogger_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_logging_demo
logging_demo__srv__ConfigLogger_Response__Sequence *
logging_demo__srv__ConfigLogger_Response__Sequence__create(size_t size);

/// Destroy array of srv/ConfigLogger messages.
/**
 * It calls
 * logging_demo__srv__ConfigLogger_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_logging_demo
void
logging_demo__srv__ConfigLogger_Response__Sequence__destroy(logging_demo__srv__ConfigLogger_Response__Sequence * array);

/// Check for srv/ConfigLogger message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_logging_demo
bool
logging_demo__srv__ConfigLogger_Response__Sequence__are_equal(const logging_demo__srv__ConfigLogger_Response__Sequence * lhs, const logging_demo__srv__ConfigLogger_Response__Sequence * rhs);

/// Copy an array of srv/ConfigLogger messages.
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
ROSIDL_GENERATOR_C_PUBLIC_logging_demo
bool
logging_demo__srv__ConfigLogger_Response__Sequence__copy(
  const logging_demo__srv__ConfigLogger_Response__Sequence * input,
  logging_demo__srv__ConfigLogger_Response__Sequence * output);

/// Initialize srv/ConfigLogger message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * logging_demo__srv__ConfigLogger_Event
 * )) before or use
 * logging_demo__srv__ConfigLogger_Event__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_logging_demo
bool
logging_demo__srv__ConfigLogger_Event__init(logging_demo__srv__ConfigLogger_Event * msg);

/// Finalize srv/ConfigLogger message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_logging_demo
void
logging_demo__srv__ConfigLogger_Event__fini(logging_demo__srv__ConfigLogger_Event * msg);

/// Create srv/ConfigLogger message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * logging_demo__srv__ConfigLogger_Event__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_logging_demo
logging_demo__srv__ConfigLogger_Event *
logging_demo__srv__ConfigLogger_Event__create(void);

/// Destroy srv/ConfigLogger message.
/**
 * It calls
 * logging_demo__srv__ConfigLogger_Event__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_logging_demo
void
logging_demo__srv__ConfigLogger_Event__destroy(logging_demo__srv__ConfigLogger_Event * msg);

/// Check for srv/ConfigLogger message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_logging_demo
bool
logging_demo__srv__ConfigLogger_Event__are_equal(const logging_demo__srv__ConfigLogger_Event * lhs, const logging_demo__srv__ConfigLogger_Event * rhs);

/// Copy a srv/ConfigLogger message.
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
ROSIDL_GENERATOR_C_PUBLIC_logging_demo
bool
logging_demo__srv__ConfigLogger_Event__copy(
  const logging_demo__srv__ConfigLogger_Event * input,
  logging_demo__srv__ConfigLogger_Event * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_logging_demo
const rosidl_type_hash_t *
logging_demo__srv__ConfigLogger_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_logging_demo
const rosidl_runtime_c__type_description__TypeDescription *
logging_demo__srv__ConfigLogger_Event__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_logging_demo
const rosidl_runtime_c__type_description__TypeSource *
logging_demo__srv__ConfigLogger_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_logging_demo
const rosidl_runtime_c__type_description__TypeSource__Sequence *
logging_demo__srv__ConfigLogger_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of srv/ConfigLogger messages.
/**
 * It allocates the memory for the number of elements and calls
 * logging_demo__srv__ConfigLogger_Event__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_logging_demo
bool
logging_demo__srv__ConfigLogger_Event__Sequence__init(logging_demo__srv__ConfigLogger_Event__Sequence * array, size_t size);

/// Finalize array of srv/ConfigLogger messages.
/**
 * It calls
 * logging_demo__srv__ConfigLogger_Event__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_logging_demo
void
logging_demo__srv__ConfigLogger_Event__Sequence__fini(logging_demo__srv__ConfigLogger_Event__Sequence * array);

/// Create array of srv/ConfigLogger messages.
/**
 * It allocates the memory for the array and calls
 * logging_demo__srv__ConfigLogger_Event__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_logging_demo
logging_demo__srv__ConfigLogger_Event__Sequence *
logging_demo__srv__ConfigLogger_Event__Sequence__create(size_t size);

/// Destroy array of srv/ConfigLogger messages.
/**
 * It calls
 * logging_demo__srv__ConfigLogger_Event__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_logging_demo
void
logging_demo__srv__ConfigLogger_Event__Sequence__destroy(logging_demo__srv__ConfigLogger_Event__Sequence * array);

/// Check for srv/ConfigLogger message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_logging_demo
bool
logging_demo__srv__ConfigLogger_Event__Sequence__are_equal(const logging_demo__srv__ConfigLogger_Event__Sequence * lhs, const logging_demo__srv__ConfigLogger_Event__Sequence * rhs);

/// Copy an array of srv/ConfigLogger messages.
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
ROSIDL_GENERATOR_C_PUBLIC_logging_demo
bool
logging_demo__srv__ConfigLogger_Event__Sequence__copy(
  const logging_demo__srv__ConfigLogger_Event__Sequence * input,
  logging_demo__srv__ConfigLogger_Event__Sequence * output);
#ifdef __cplusplus
}
#endif

#endif  // LOGGING_DEMO__SRV__DETAIL__CONFIG_LOGGER__FUNCTIONS_H_
