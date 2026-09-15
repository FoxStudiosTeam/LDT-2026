// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from resource_retriever_interfaces:srv\GetResource.idl
// generated code does not contain a copyright notice
#include "resource_retriever_interfaces/srv/detail/get_resource__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `path`
// Member `etag`
#include "rosidl_runtime_c/string_functions.h"

bool
resource_retriever_interfaces__srv__GetResource_Request__init(resource_retriever_interfaces__srv__GetResource_Request * msg)
{
  if (!msg) {
    return false;
  }
  // path
  if (!rosidl_runtime_c__String__init(&msg->path)) {
    resource_retriever_interfaces__srv__GetResource_Request__fini(msg);
    return false;
  }
  // etag
  if (!rosidl_runtime_c__String__init(&msg->etag)) {
    resource_retriever_interfaces__srv__GetResource_Request__fini(msg);
    return false;
  }
  return true;
}

void
resource_retriever_interfaces__srv__GetResource_Request__fini(resource_retriever_interfaces__srv__GetResource_Request * msg)
{
  if (!msg) {
    return;
  }
  // path
  rosidl_runtime_c__String__fini(&msg->path);
  // etag
  rosidl_runtime_c__String__fini(&msg->etag);
}

bool
resource_retriever_interfaces__srv__GetResource_Request__are_equal(const resource_retriever_interfaces__srv__GetResource_Request * lhs, const resource_retriever_interfaces__srv__GetResource_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // path
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->path), &(rhs->path)))
  {
    return false;
  }
  // etag
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->etag), &(rhs->etag)))
  {
    return false;
  }
  return true;
}

bool
resource_retriever_interfaces__srv__GetResource_Request__copy(
  const resource_retriever_interfaces__srv__GetResource_Request * input,
  resource_retriever_interfaces__srv__GetResource_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // path
  if (!rosidl_runtime_c__String__copy(
      &(input->path), &(output->path)))
  {
    return false;
  }
  // etag
  if (!rosidl_runtime_c__String__copy(
      &(input->etag), &(output->etag)))
  {
    return false;
  }
  return true;
}

resource_retriever_interfaces__srv__GetResource_Request *
resource_retriever_interfaces__srv__GetResource_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  resource_retriever_interfaces__srv__GetResource_Request * msg = (resource_retriever_interfaces__srv__GetResource_Request *)allocator.allocate(sizeof(resource_retriever_interfaces__srv__GetResource_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(resource_retriever_interfaces__srv__GetResource_Request));
  bool success = resource_retriever_interfaces__srv__GetResource_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
resource_retriever_interfaces__srv__GetResource_Request__destroy(resource_retriever_interfaces__srv__GetResource_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    resource_retriever_interfaces__srv__GetResource_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
resource_retriever_interfaces__srv__GetResource_Request__Sequence__init(resource_retriever_interfaces__srv__GetResource_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  resource_retriever_interfaces__srv__GetResource_Request * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(resource_retriever_interfaces__srv__GetResource_Request)) {
      return false;
    }
    data = (resource_retriever_interfaces__srv__GetResource_Request *)allocator.zero_allocate(size, sizeof(resource_retriever_interfaces__srv__GetResource_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = resource_retriever_interfaces__srv__GetResource_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        resource_retriever_interfaces__srv__GetResource_Request__fini(&data[i - 1]);
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
resource_retriever_interfaces__srv__GetResource_Request__Sequence__fini(resource_retriever_interfaces__srv__GetResource_Request__Sequence * array)
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
      resource_retriever_interfaces__srv__GetResource_Request__fini(&array->data[i]);
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

resource_retriever_interfaces__srv__GetResource_Request__Sequence *
resource_retriever_interfaces__srv__GetResource_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  resource_retriever_interfaces__srv__GetResource_Request__Sequence * array = (resource_retriever_interfaces__srv__GetResource_Request__Sequence *)allocator.allocate(sizeof(resource_retriever_interfaces__srv__GetResource_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = resource_retriever_interfaces__srv__GetResource_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
resource_retriever_interfaces__srv__GetResource_Request__Sequence__destroy(resource_retriever_interfaces__srv__GetResource_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    resource_retriever_interfaces__srv__GetResource_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
resource_retriever_interfaces__srv__GetResource_Request__Sequence__are_equal(const resource_retriever_interfaces__srv__GetResource_Request__Sequence * lhs, const resource_retriever_interfaces__srv__GetResource_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!resource_retriever_interfaces__srv__GetResource_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
resource_retriever_interfaces__srv__GetResource_Request__Sequence__copy(
  const resource_retriever_interfaces__srv__GetResource_Request__Sequence * input,
  resource_retriever_interfaces__srv__GetResource_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(resource_retriever_interfaces__srv__GetResource_Request)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(resource_retriever_interfaces__srv__GetResource_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    resource_retriever_interfaces__srv__GetResource_Request * data =
      (resource_retriever_interfaces__srv__GetResource_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!resource_retriever_interfaces__srv__GetResource_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          resource_retriever_interfaces__srv__GetResource_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!resource_retriever_interfaces__srv__GetResource_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `error_reason`
// Member `expanded_path`
// Member `etag`
// already included above
// #include "rosidl_runtime_c/string_functions.h"
// Member `body`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
resource_retriever_interfaces__srv__GetResource_Response__init(resource_retriever_interfaces__srv__GetResource_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status_code
  // error_reason
  if (!rosidl_runtime_c__String__init(&msg->error_reason)) {
    resource_retriever_interfaces__srv__GetResource_Response__fini(msg);
    return false;
  }
  // expanded_path
  if (!rosidl_runtime_c__String__init(&msg->expanded_path)) {
    resource_retriever_interfaces__srv__GetResource_Response__fini(msg);
    return false;
  }
  // etag
  if (!rosidl_runtime_c__String__init(&msg->etag)) {
    resource_retriever_interfaces__srv__GetResource_Response__fini(msg);
    return false;
  }
  // body
  if (!rosidl_runtime_c__uint8__Sequence__init(&msg->body, 0)) {
    resource_retriever_interfaces__srv__GetResource_Response__fini(msg);
    return false;
  }
  return true;
}

void
resource_retriever_interfaces__srv__GetResource_Response__fini(resource_retriever_interfaces__srv__GetResource_Response * msg)
{
  if (!msg) {
    return;
  }
  // status_code
  // error_reason
  rosidl_runtime_c__String__fini(&msg->error_reason);
  // expanded_path
  rosidl_runtime_c__String__fini(&msg->expanded_path);
  // etag
  rosidl_runtime_c__String__fini(&msg->etag);
  // body
  rosidl_runtime_c__uint8__Sequence__fini(&msg->body);
}

bool
resource_retriever_interfaces__srv__GetResource_Response__are_equal(const resource_retriever_interfaces__srv__GetResource_Response * lhs, const resource_retriever_interfaces__srv__GetResource_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status_code
  if (lhs->status_code != rhs->status_code) {
    return false;
  }
  // error_reason
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->error_reason), &(rhs->error_reason)))
  {
    return false;
  }
  // expanded_path
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->expanded_path), &(rhs->expanded_path)))
  {
    return false;
  }
  // etag
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->etag), &(rhs->etag)))
  {
    return false;
  }
  // body
  if (!rosidl_runtime_c__uint8__Sequence__are_equal(
      &(lhs->body), &(rhs->body)))
  {
    return false;
  }
  return true;
}

bool
resource_retriever_interfaces__srv__GetResource_Response__copy(
  const resource_retriever_interfaces__srv__GetResource_Response * input,
  resource_retriever_interfaces__srv__GetResource_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status_code
  output->status_code = input->status_code;
  // error_reason
  if (!rosidl_runtime_c__String__copy(
      &(input->error_reason), &(output->error_reason)))
  {
    return false;
  }
  // expanded_path
  if (!rosidl_runtime_c__String__copy(
      &(input->expanded_path), &(output->expanded_path)))
  {
    return false;
  }
  // etag
  if (!rosidl_runtime_c__String__copy(
      &(input->etag), &(output->etag)))
  {
    return false;
  }
  // body
  if (!rosidl_runtime_c__uint8__Sequence__copy(
      &(input->body), &(output->body)))
  {
    return false;
  }
  return true;
}

resource_retriever_interfaces__srv__GetResource_Response *
resource_retriever_interfaces__srv__GetResource_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  resource_retriever_interfaces__srv__GetResource_Response * msg = (resource_retriever_interfaces__srv__GetResource_Response *)allocator.allocate(sizeof(resource_retriever_interfaces__srv__GetResource_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(resource_retriever_interfaces__srv__GetResource_Response));
  bool success = resource_retriever_interfaces__srv__GetResource_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
resource_retriever_interfaces__srv__GetResource_Response__destroy(resource_retriever_interfaces__srv__GetResource_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    resource_retriever_interfaces__srv__GetResource_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
resource_retriever_interfaces__srv__GetResource_Response__Sequence__init(resource_retriever_interfaces__srv__GetResource_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  resource_retriever_interfaces__srv__GetResource_Response * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(resource_retriever_interfaces__srv__GetResource_Response)) {
      return false;
    }
    data = (resource_retriever_interfaces__srv__GetResource_Response *)allocator.zero_allocate(size, sizeof(resource_retriever_interfaces__srv__GetResource_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = resource_retriever_interfaces__srv__GetResource_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        resource_retriever_interfaces__srv__GetResource_Response__fini(&data[i - 1]);
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
resource_retriever_interfaces__srv__GetResource_Response__Sequence__fini(resource_retriever_interfaces__srv__GetResource_Response__Sequence * array)
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
      resource_retriever_interfaces__srv__GetResource_Response__fini(&array->data[i]);
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

resource_retriever_interfaces__srv__GetResource_Response__Sequence *
resource_retriever_interfaces__srv__GetResource_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  resource_retriever_interfaces__srv__GetResource_Response__Sequence * array = (resource_retriever_interfaces__srv__GetResource_Response__Sequence *)allocator.allocate(sizeof(resource_retriever_interfaces__srv__GetResource_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = resource_retriever_interfaces__srv__GetResource_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
resource_retriever_interfaces__srv__GetResource_Response__Sequence__destroy(resource_retriever_interfaces__srv__GetResource_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    resource_retriever_interfaces__srv__GetResource_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
resource_retriever_interfaces__srv__GetResource_Response__Sequence__are_equal(const resource_retriever_interfaces__srv__GetResource_Response__Sequence * lhs, const resource_retriever_interfaces__srv__GetResource_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!resource_retriever_interfaces__srv__GetResource_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
resource_retriever_interfaces__srv__GetResource_Response__Sequence__copy(
  const resource_retriever_interfaces__srv__GetResource_Response__Sequence * input,
  resource_retriever_interfaces__srv__GetResource_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(resource_retriever_interfaces__srv__GetResource_Response)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(resource_retriever_interfaces__srv__GetResource_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    resource_retriever_interfaces__srv__GetResource_Response * data =
      (resource_retriever_interfaces__srv__GetResource_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!resource_retriever_interfaces__srv__GetResource_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          resource_retriever_interfaces__srv__GetResource_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!resource_retriever_interfaces__srv__GetResource_Response__copy(
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
// #include "resource_retriever_interfaces/srv/detail/get_resource__functions.h"

bool
resource_retriever_interfaces__srv__GetResource_Event__init(resource_retriever_interfaces__srv__GetResource_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    resource_retriever_interfaces__srv__GetResource_Event__fini(msg);
    return false;
  }
  // request
  if (!resource_retriever_interfaces__srv__GetResource_Request__Sequence__init(&msg->request, 0)) {
    resource_retriever_interfaces__srv__GetResource_Event__fini(msg);
    return false;
  }
  // response
  if (!resource_retriever_interfaces__srv__GetResource_Response__Sequence__init(&msg->response, 0)) {
    resource_retriever_interfaces__srv__GetResource_Event__fini(msg);
    return false;
  }
  return true;
}

void
resource_retriever_interfaces__srv__GetResource_Event__fini(resource_retriever_interfaces__srv__GetResource_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  resource_retriever_interfaces__srv__GetResource_Request__Sequence__fini(&msg->request);
  // response
  resource_retriever_interfaces__srv__GetResource_Response__Sequence__fini(&msg->response);
}

bool
resource_retriever_interfaces__srv__GetResource_Event__are_equal(const resource_retriever_interfaces__srv__GetResource_Event * lhs, const resource_retriever_interfaces__srv__GetResource_Event * rhs)
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
  if (!resource_retriever_interfaces__srv__GetResource_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!resource_retriever_interfaces__srv__GetResource_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
resource_retriever_interfaces__srv__GetResource_Event__copy(
  const resource_retriever_interfaces__srv__GetResource_Event * input,
  resource_retriever_interfaces__srv__GetResource_Event * output)
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
  if (!resource_retriever_interfaces__srv__GetResource_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!resource_retriever_interfaces__srv__GetResource_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

resource_retriever_interfaces__srv__GetResource_Event *
resource_retriever_interfaces__srv__GetResource_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  resource_retriever_interfaces__srv__GetResource_Event * msg = (resource_retriever_interfaces__srv__GetResource_Event *)allocator.allocate(sizeof(resource_retriever_interfaces__srv__GetResource_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(resource_retriever_interfaces__srv__GetResource_Event));
  bool success = resource_retriever_interfaces__srv__GetResource_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
resource_retriever_interfaces__srv__GetResource_Event__destroy(resource_retriever_interfaces__srv__GetResource_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    resource_retriever_interfaces__srv__GetResource_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
resource_retriever_interfaces__srv__GetResource_Event__Sequence__init(resource_retriever_interfaces__srv__GetResource_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  resource_retriever_interfaces__srv__GetResource_Event * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(resource_retriever_interfaces__srv__GetResource_Event)) {
      return false;
    }
    data = (resource_retriever_interfaces__srv__GetResource_Event *)allocator.zero_allocate(size, sizeof(resource_retriever_interfaces__srv__GetResource_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = resource_retriever_interfaces__srv__GetResource_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        resource_retriever_interfaces__srv__GetResource_Event__fini(&data[i - 1]);
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
resource_retriever_interfaces__srv__GetResource_Event__Sequence__fini(resource_retriever_interfaces__srv__GetResource_Event__Sequence * array)
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
      resource_retriever_interfaces__srv__GetResource_Event__fini(&array->data[i]);
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

resource_retriever_interfaces__srv__GetResource_Event__Sequence *
resource_retriever_interfaces__srv__GetResource_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  resource_retriever_interfaces__srv__GetResource_Event__Sequence * array = (resource_retriever_interfaces__srv__GetResource_Event__Sequence *)allocator.allocate(sizeof(resource_retriever_interfaces__srv__GetResource_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = resource_retriever_interfaces__srv__GetResource_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
resource_retriever_interfaces__srv__GetResource_Event__Sequence__destroy(resource_retriever_interfaces__srv__GetResource_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    resource_retriever_interfaces__srv__GetResource_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
resource_retriever_interfaces__srv__GetResource_Event__Sequence__are_equal(const resource_retriever_interfaces__srv__GetResource_Event__Sequence * lhs, const resource_retriever_interfaces__srv__GetResource_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!resource_retriever_interfaces__srv__GetResource_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
resource_retriever_interfaces__srv__GetResource_Event__Sequence__copy(
  const resource_retriever_interfaces__srv__GetResource_Event__Sequence * input,
  resource_retriever_interfaces__srv__GetResource_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(resource_retriever_interfaces__srv__GetResource_Event)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(resource_retriever_interfaces__srv__GetResource_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    resource_retriever_interfaces__srv__GetResource_Event * data =
      (resource_retriever_interfaces__srv__GetResource_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!resource_retriever_interfaces__srv__GetResource_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          resource_retriever_interfaces__srv__GetResource_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!resource_retriever_interfaces__srv__GetResource_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
