// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from bridge_interface:msg/Server2Robot.idl
// generated code does not contain a copyright notice
#include "bridge_interface/msg/detail/server2_robot__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `gate`
#include "rosidl_runtime_c/string_functions.h"

bool
bridge_interface__msg__Server2Robot__init(bridge_interface__msg__Server2Robot * msg)
{
  if (!msg) {
    return false;
  }
  // gate
  if (!rosidl_runtime_c__String__init(&msg->gate)) {
    bridge_interface__msg__Server2Robot__fini(msg);
    return false;
  }
  // activate
  // engage
  // estop
  return true;
}

void
bridge_interface__msg__Server2Robot__fini(bridge_interface__msg__Server2Robot * msg)
{
  if (!msg) {
    return;
  }
  // gate
  rosidl_runtime_c__String__fini(&msg->gate);
  // activate
  // engage
  // estop
}

bool
bridge_interface__msg__Server2Robot__are_equal(const bridge_interface__msg__Server2Robot * lhs, const bridge_interface__msg__Server2Robot * rhs)
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
  // activate
  if (lhs->activate != rhs->activate) {
    return false;
  }
  // engage
  if (lhs->engage != rhs->engage) {
    return false;
  }
  // estop
  if (lhs->estop != rhs->estop) {
    return false;
  }
  return true;
}

bool
bridge_interface__msg__Server2Robot__copy(
  const bridge_interface__msg__Server2Robot * input,
  bridge_interface__msg__Server2Robot * output)
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
  // activate
  output->activate = input->activate;
  // engage
  output->engage = input->engage;
  // estop
  output->estop = input->estop;
  return true;
}

bridge_interface__msg__Server2Robot *
bridge_interface__msg__Server2Robot__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  bridge_interface__msg__Server2Robot * msg = (bridge_interface__msg__Server2Robot *)allocator.allocate(sizeof(bridge_interface__msg__Server2Robot), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(bridge_interface__msg__Server2Robot));
  bool success = bridge_interface__msg__Server2Robot__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
bridge_interface__msg__Server2Robot__destroy(bridge_interface__msg__Server2Robot * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    bridge_interface__msg__Server2Robot__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
bridge_interface__msg__Server2Robot__Sequence__init(bridge_interface__msg__Server2Robot__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  bridge_interface__msg__Server2Robot * data = NULL;

  if (size) {
    data = (bridge_interface__msg__Server2Robot *)allocator.zero_allocate(size, sizeof(bridge_interface__msg__Server2Robot), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = bridge_interface__msg__Server2Robot__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        bridge_interface__msg__Server2Robot__fini(&data[i - 1]);
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
bridge_interface__msg__Server2Robot__Sequence__fini(bridge_interface__msg__Server2Robot__Sequence * array)
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
      bridge_interface__msg__Server2Robot__fini(&array->data[i]);
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

bridge_interface__msg__Server2Robot__Sequence *
bridge_interface__msg__Server2Robot__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  bridge_interface__msg__Server2Robot__Sequence * array = (bridge_interface__msg__Server2Robot__Sequence *)allocator.allocate(sizeof(bridge_interface__msg__Server2Robot__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = bridge_interface__msg__Server2Robot__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
bridge_interface__msg__Server2Robot__Sequence__destroy(bridge_interface__msg__Server2Robot__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    bridge_interface__msg__Server2Robot__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
bridge_interface__msg__Server2Robot__Sequence__are_equal(const bridge_interface__msg__Server2Robot__Sequence * lhs, const bridge_interface__msg__Server2Robot__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!bridge_interface__msg__Server2Robot__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
bridge_interface__msg__Server2Robot__Sequence__copy(
  const bridge_interface__msg__Server2Robot__Sequence * input,
  bridge_interface__msg__Server2Robot__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(bridge_interface__msg__Server2Robot);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    bridge_interface__msg__Server2Robot * data =
      (bridge_interface__msg__Server2Robot *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!bridge_interface__msg__Server2Robot__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          bridge_interface__msg__Server2Robot__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!bridge_interface__msg__Server2Robot__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
