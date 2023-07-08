// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from bridge_interface:msg/Server2Robot.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "bridge_interface/msg/detail/server2_robot__rosidl_typesupport_introspection_c.h"
#include "bridge_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "bridge_interface/msg/detail/server2_robot__functions.h"
#include "bridge_interface/msg/detail/server2_robot__struct.h"


// Include directives for member types
// Member `gate`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void bridge_interface__msg__Server2Robot__rosidl_typesupport_introspection_c__Server2Robot_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  bridge_interface__msg__Server2Robot__init(message_memory);
}

void bridge_interface__msg__Server2Robot__rosidl_typesupport_introspection_c__Server2Robot_fini_function(void * message_memory)
{
  bridge_interface__msg__Server2Robot__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember bridge_interface__msg__Server2Robot__rosidl_typesupport_introspection_c__Server2Robot_message_member_array[4] = {
  {
    "gate",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(bridge_interface__msg__Server2Robot, gate),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "activate",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(bridge_interface__msg__Server2Robot, activate),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "engage",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(bridge_interface__msg__Server2Robot, engage),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "estop",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(bridge_interface__msg__Server2Robot, estop),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers bridge_interface__msg__Server2Robot__rosidl_typesupport_introspection_c__Server2Robot_message_members = {
  "bridge_interface__msg",  // message namespace
  "Server2Robot",  // message name
  4,  // number of fields
  sizeof(bridge_interface__msg__Server2Robot),
  bridge_interface__msg__Server2Robot__rosidl_typesupport_introspection_c__Server2Robot_message_member_array,  // message members
  bridge_interface__msg__Server2Robot__rosidl_typesupport_introspection_c__Server2Robot_init_function,  // function to initialize message memory (memory has to be allocated)
  bridge_interface__msg__Server2Robot__rosidl_typesupport_introspection_c__Server2Robot_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t bridge_interface__msg__Server2Robot__rosidl_typesupport_introspection_c__Server2Robot_message_type_support_handle = {
  0,
  &bridge_interface__msg__Server2Robot__rosidl_typesupport_introspection_c__Server2Robot_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_bridge_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, bridge_interface, msg, Server2Robot)() {
  if (!bridge_interface__msg__Server2Robot__rosidl_typesupport_introspection_c__Server2Robot_message_type_support_handle.typesupport_identifier) {
    bridge_interface__msg__Server2Robot__rosidl_typesupport_introspection_c__Server2Robot_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &bridge_interface__msg__Server2Robot__rosidl_typesupport_introspection_c__Server2Robot_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
