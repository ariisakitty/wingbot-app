// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from bridge_interface:msg/Robot2Server.idl
// generated code does not contain a copyright notice
#include "bridge_interface/msg/detail/robot2_server__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `gate`
#include "rosidl_runtime_c/string_functions.h"

bool
bridge_interface__msg__Robot2Server__init(bridge_interface__msg__Robot2Server * msg)
{
  if (!msg) {
    return false;
  }
  // gate
  if (!rosidl_runtime_c__String__init(&msg->gate)) {
    bridge_interface__msg__Robot2Server__fini(msg);
    return false;
  }
  return true;
}

void
bridge_interface__msg__Robot2Server__fini(bridge_interface__msg__Robot2Server * msg)
{
  if (!msg) {
    return;
  }
  // gate
  rosidl_runtime_c__String__fini(&msg->gate);
}

bool
bridge_interface__msg__Robot2Server__are_equal(const bridge_interface__msg__Robot2Server * lhs, const bridge_interface__msg__Robot2Server * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // gate
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->gate), &(rhs->gate)))
  {
    return false;
  }
  return true;
}

bool
bridge_interface__msg__Robot2Server__copy(
  const bridge_interface__msg__Robot2Server * input,
  bridge_interface__msg__Robot2Server * output)
{
  if (!input || !output) {
    return false;
  }
  // gate
  if (!rosidl_runtime_c__String__copy(
      &(input->gate), &(output->gate)))
  {
    return false;
  }
  return true;
}

bridge_interface__msg__Robot2Server *
bridge_interface__msg__Robot2Server__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  bridge_interface__msg__Robot2Server * msg = (bridge_interface__msg__Robot2Server *)allocator.allocate(sizeof(bridge_interface__msg__Robot2Server), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(bridge_interface__msg__Robot2Server));
  bool success = bridge_interface__msg__Robot2Server__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
bridge_interface__msg__Robot2Server__destroy(bridge_interface__msg__Robot2Server * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    bridge_interface__msg__Robot2Server__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
bridge_interface__msg__Robot2Server__Sequence__init(bridge_interface__msg__Robot2Server__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  bridge_interface__msg__Robot2Server * data = NULL;

  if (size) {
    data = (bridge_interface__msg__Robot2Server *)allocator.zero_allocate(size, sizeof(bridge_interface__msg__Robot2Server), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = bridge_interface__msg__Robot2Server__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        bridge_interface__msg__Robot2Server__fini(&data[i - 1]);
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
bridge_interface__msg__Robot2Server__Sequence__fini(bridge_interface__msg__Robot2Server__Sequence * array)
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
      bridge_interface__msg__Robot2Server__fini(&array->data[i]);
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

bridge_interface__msg__Robot2Server__Sequence *
bridge_interface__msg__Robot2Server__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  bridge_interface__msg__Robot2Server__Sequence * array = (bridge_interface__msg__Robot2Server__Sequence *)allocator.allocate(sizeof(bridge_interface__msg__Robot2Server__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = bridge_interface__msg__Robot2Server__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
bridge_interface__msg__Robot2Server__Sequence__destroy(bridge_interface__msg__Robot2Server__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    bridge_interface__msg__Robot2Server__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
bridge_interface__msg__Robot2Server__Sequence__are_equal(const bridge_interface__msg__Robot2Server__Sequence * lhs, const bridge_interface__msg__Robot2Server__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!bridge_interface__msg__Robot2Server__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
bridge_interface__msg__Robot2Server__Sequence__copy(
  const bridge_interface__msg__Robot2Server__Sequence * input,
  bridge_interface__msg__Robot2Server__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(bridge_interface__msg__Robot2Server);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    bridge_interface__msg__Robot2Server * data =
      (bridge_interface__msg__Robot2Server *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!bridge_interface__msg__Robot2Server__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          bridge_interface__msg__Robot2Server__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!bridge_interface__msg__Robot2Server__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
