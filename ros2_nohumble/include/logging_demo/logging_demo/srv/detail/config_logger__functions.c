// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from logging_demo:srv\ConfigLogger.idl
// generated code does not contain a copyright notice
#include "logging_demo/srv/detail/config_logger__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `logger_name`
// Member `level`
#include "rosidl_runtime_c/string_functions.h"

bool
logging_demo__srv__ConfigLogger_Request__init(logging_demo__srv__ConfigLogger_Request * msg)
{
  if (!msg) {
    return false;
  }
  // logger_name
  if (!rosidl_runtime_c__String__init(&msg->logger_name)) {
    logging_demo__srv__ConfigLogger_Request__fini(msg);
    return false;
  }
  // level
  if (!rosidl_runtime_c__String__init(&msg->level)) {
    logging_demo__srv__ConfigLogger_Request__fini(msg);
    return false;
  }
  return true;
}

void
logging_demo__srv__ConfigLogger_Request__fini(logging_demo__srv__ConfigLogger_Request * msg)
{
  if (!msg) {
    return;
  }
  // logger_name
  rosidl_runtime_c__String__fini(&msg->logger_name);
  // level
  rosidl_runtime_c__String__fini(&msg->level);
}

bool
logging_demo__srv__ConfigLogger_Request__are_equal(const logging_demo__srv__ConfigLogger_Request * lhs, const logging_demo__srv__ConfigLogger_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // logger_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->logger_name), &(rhs->logger_name)))
  {
    return false;
  }
  // level
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->level), &(rhs->level)))
  {
    return false;
  }
  return true;
}

bool
logging_demo__srv__ConfigLogger_Request__copy(
  const logging_demo__srv__ConfigLogger_Request * input,
  logging_demo__srv__ConfigLogger_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // logger_name
  if (!rosidl_runtime_c__String__copy(
      &(input->logger_name), &(output->logger_name)))
  {
    return false;
  }
  // level
  if (!rosidl_runtime_c__String__copy(
      &(input->level), &(output->level)))
  {
    return false;
  }
  return true;
}

logging_demo__srv__ConfigLogger_Request *
logging_demo__srv__ConfigLogger_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  logging_demo__srv__ConfigLogger_Request * msg = (logging_demo__srv__ConfigLogger_Request *)allocator.allocate(sizeof(logging_demo__srv__ConfigLogger_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(logging_demo__srv__ConfigLogger_Request));
  bool success = logging_demo__srv__ConfigLogger_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
logging_demo__srv__ConfigLogger_Request__destroy(logging_demo__srv__ConfigLogger_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    logging_demo__srv__ConfigLogger_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
logging_demo__srv__ConfigLogger_Request__Sequence__init(logging_demo__srv__ConfigLogger_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  logging_demo__srv__ConfigLogger_Request * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(logging_demo__srv__ConfigLogger_Request)) {
      return false;
    }
    data = (logging_demo__srv__ConfigLogger_Request *)allocator.zero_allocate(size, sizeof(logging_demo__srv__ConfigLogger_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = logging_demo__srv__ConfigLogger_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        logging_demo__srv__ConfigLogger_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
logging_demo__srv__ConfigLogger_Request__Sequence__fini(logging_demo__srv__ConfigLogger_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      logging_demo__srv__ConfigLogger_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

logging_demo__srv__ConfigLogger_Request__Sequence *
logging_demo__srv__ConfigLogger_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  logging_demo__srv__ConfigLogger_Request__Sequence * array = (logging_demo__srv__ConfigLogger_Request__Sequence *)allocator.allocate(sizeof(logging_demo__srv__ConfigLogger_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = logging_demo__srv__ConfigLogger_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
logging_demo__srv__ConfigLogger_Request__Sequence__destroy(logging_demo__srv__ConfigLogger_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    logging_demo__srv__ConfigLogger_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
logging_demo__srv__ConfigLogger_Request__Sequence__are_equal(const logging_demo__srv__ConfigLogger_Request__Sequence * lhs, const logging_demo__srv__ConfigLogger_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!logging_demo__srv__ConfigLogger_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
logging_demo__srv__ConfigLogger_Request__Sequence__copy(
  const logging_demo__srv__ConfigLogger_Request__Sequence * input,
  logging_demo__srv__ConfigLogger_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(logging_demo__srv__ConfigLogger_Request)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(logging_demo__srv__ConfigLogger_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    logging_demo__srv__ConfigLogger_Request * data =
      (logging_demo__srv__ConfigLogger_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!logging_demo__srv__ConfigLogger_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          logging_demo__srv__ConfigLogger_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!logging_demo__srv__ConfigLogger_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
logging_demo__srv__ConfigLogger_Response__init(logging_demo__srv__ConfigLogger_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  return true;
}

void
logging_demo__srv__ConfigLogger_Response__fini(logging_demo__srv__ConfigLogger_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
}

bool
logging_demo__srv__ConfigLogger_Response__are_equal(const logging_demo__srv__ConfigLogger_Response * lhs, const logging_demo__srv__ConfigLogger_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  return true;
}

bool
logging_demo__srv__ConfigLogger_Response__copy(
  const logging_demo__srv__ConfigLogger_Response * input,
  logging_demo__srv__ConfigLogger_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  return true;
}

logging_demo__srv__ConfigLogger_Response *
logging_demo__srv__ConfigLogger_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  logging_demo__srv__ConfigLogger_Response * msg = (logging_demo__srv__ConfigLogger_Response *)allocator.allocate(sizeof(logging_demo__srv__ConfigLogger_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(logging_demo__srv__ConfigLogger_Response));
  bool success = logging_demo__srv__ConfigLogger_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
logging_demo__srv__ConfigLogger_Response__destroy(logging_demo__srv__ConfigLogger_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    logging_demo__srv__ConfigLogger_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
logging_demo__srv__ConfigLogger_Response__Sequence__init(logging_demo__srv__ConfigLogger_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  logging_demo__srv__ConfigLogger_Response * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(logging_demo__srv__ConfigLogger_Response)) {
      return false;
    }
    data = (logging_demo__srv__ConfigLogger_Response *)allocator.zero_allocate(size, sizeof(logging_demo__srv__ConfigLogger_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = logging_demo__srv__ConfigLogger_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        logging_demo__srv__ConfigLogger_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
logging_demo__srv__ConfigLogger_Response__Sequence__fini(logging_demo__srv__ConfigLogger_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      logging_demo__srv__ConfigLogger_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

logging_demo__srv__ConfigLogger_Response__Sequence *
logging_demo__srv__ConfigLogger_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  logging_demo__srv__ConfigLogger_Response__Sequence * array = (logging_demo__srv__ConfigLogger_Response__Sequence *)allocator.allocate(sizeof(logging_demo__srv__ConfigLogger_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = logging_demo__srv__ConfigLogger_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
logging_demo__srv__ConfigLogger_Response__Sequence__destroy(logging_demo__srv__ConfigLogger_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    logging_demo__srv__ConfigLogger_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
logging_demo__srv__ConfigLogger_Response__Sequence__are_equal(const logging_demo__srv__ConfigLogger_Response__Sequence * lhs, const logging_demo__srv__ConfigLogger_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!logging_demo__srv__ConfigLogger_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
logging_demo__srv__ConfigLogger_Response__Sequence__copy(
  const logging_demo__srv__ConfigLogger_Response__Sequence * input,
  logging_demo__srv__ConfigLogger_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(logging_demo__srv__ConfigLogger_Response)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(logging_demo__srv__ConfigLogger_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    logging_demo__srv__ConfigLogger_Response * data =
      (logging_demo__srv__ConfigLogger_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!logging_demo__srv__ConfigLogger_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          logging_demo__srv__ConfigLogger_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!logging_demo__srv__ConfigLogger_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
#include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "logging_demo/srv/detail/config_logger__functions.h"

bool
logging_demo__srv__ConfigLogger_Event__init(logging_demo__srv__ConfigLogger_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    logging_demo__srv__ConfigLogger_Event__fini(msg);
    return false;
  }
  // request
  if (!logging_demo__srv__ConfigLogger_Request__Sequence__init(&msg->request, 0)) {
    logging_demo__srv__ConfigLogger_Event__fini(msg);
    return false;
  }
  // response
  if (!logging_demo__srv__ConfigLogger_Response__Sequence__init(&msg->response, 0)) {
    logging_demo__srv__ConfigLogger_Event__fini(msg);
    return false;
  }
  return true;
}

void
logging_demo__srv__ConfigLogger_Event__fini(logging_demo__srv__ConfigLogger_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  logging_demo__srv__ConfigLogger_Request__Sequence__fini(&msg->request);
  // response
  logging_demo__srv__ConfigLogger_Response__Sequence__fini(&msg->response);
}

bool
logging_demo__srv__ConfigLogger_Event__are_equal(const logging_demo__srv__ConfigLogger_Event * lhs, const logging_demo__srv__ConfigLogger_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!logging_demo__srv__ConfigLogger_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!logging_demo__srv__ConfigLogger_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
logging_demo__srv__ConfigLogger_Event__copy(
  const logging_demo__srv__ConfigLogger_Event * input,
  logging_demo__srv__ConfigLogger_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!logging_demo__srv__ConfigLogger_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!logging_demo__srv__ConfigLogger_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

logging_demo__srv__ConfigLogger_Event *
logging_demo__srv__ConfigLogger_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  logging_demo__srv__ConfigLogger_Event * msg = (logging_demo__srv__ConfigLogger_Event *)allocator.allocate(sizeof(logging_demo__srv__ConfigLogger_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(logging_demo__srv__ConfigLogger_Event));
  bool success = logging_demo__srv__ConfigLogger_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
logging_demo__srv__ConfigLogger_Event__destroy(logging_demo__srv__ConfigLogger_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    logging_demo__srv__ConfigLogger_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
logging_demo__srv__ConfigLogger_Event__Sequence__init(logging_demo__srv__ConfigLogger_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  logging_demo__srv__ConfigLogger_Event * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(logging_demo__srv__ConfigLogger_Event)) {
      return false;
    }
    data = (logging_demo__srv__ConfigLogger_Event *)allocator.zero_allocate(size, sizeof(logging_demo__srv__ConfigLogger_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = logging_demo__srv__ConfigLogger_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        logging_demo__srv__ConfigLogger_Event__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
logging_demo__srv__ConfigLogger_Event__Sequence__fini(logging_demo__srv__ConfigLogger_Event__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      logging_demo__srv__ConfigLogger_Event__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

logging_demo__srv__ConfigLogger_Event__Sequence *
logging_demo__srv__ConfigLogger_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  logging_demo__srv__ConfigLogger_Event__Sequence * array = (logging_demo__srv__ConfigLogger_Event__Sequence *)allocator.allocate(sizeof(logging_demo__srv__ConfigLogger_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = logging_demo__srv__ConfigLogger_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
logging_demo__srv__ConfigLogger_Event__Sequence__destroy(logging_demo__srv__ConfigLogger_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    logging_demo__srv__ConfigLogger_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
logging_demo__srv__ConfigLogger_Event__Sequence__are_equal(const logging_demo__srv__ConfigLogger_Event__Sequence * lhs, const logging_demo__srv__ConfigLogger_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!logging_demo__srv__ConfigLogger_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
logging_demo__srv__ConfigLogger_Event__Sequence__copy(
  const logging_demo__srv__ConfigLogger_Event__Sequence * input,
  logging_demo__srv__ConfigLogger_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(logging_demo__srv__ConfigLogger_Event)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(logging_demo__srv__ConfigLogger_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    logging_demo__srv__ConfigLogger_Event * data =
      (logging_demo__srv__ConfigLogger_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!logging_demo__srv__ConfigLogger_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          logging_demo__srv__ConfigLogger_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!logging_demo__srv__ConfigLogger_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
