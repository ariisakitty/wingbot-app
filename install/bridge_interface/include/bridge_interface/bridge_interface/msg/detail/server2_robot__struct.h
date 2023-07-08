// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from bridge_interface:msg/Server2Robot.idl
// generated code does not contain a copyright notice

#ifndef BRIDGE_INTERFACE__MSG__DETAIL__SERVER2_ROBOT__STRUCT_H_
#define BRIDGE_INTERFACE__MSG__DETAIL__SERVER2_ROBOT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'gate'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Server2Robot in the package bridge_interface.
typedef struct bridge_interface__msg__Server2Robot
{
  rosidl_runtime_c__String gate;
  bool activate;
  bool engage;
  bool estop;
} bridge_interface__msg__Server2Robot;

// Struct for a sequence of bridge_interface__msg__Server2Robot.
typedef struct bridge_interface__msg__Server2Robot__Sequence
{
  bridge_interface__msg__Server2Robot * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} bridge_interface__msg__Server2Robot__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BRIDGE_INTERFACE__MSG__DETAIL__SERVER2_ROBOT__STRUCT_H_
