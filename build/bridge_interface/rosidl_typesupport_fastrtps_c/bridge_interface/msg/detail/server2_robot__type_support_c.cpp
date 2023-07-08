// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from bridge_interface:msg/Server2Robot.idl
// generated code does not contain a copyright notice
#include "bridge_interface/msg/detail/server2_robot__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "bridge_interface/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "bridge_interface/msg/detail/server2_robot__struct.h"
#include "bridge_interface/msg/detail/server2_robot__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // gate
#include "rosidl_runtime_c/string_functions.h"  // gate

// forward declare type support functions


using _Server2Robot__ros_msg_type = bridge_interface__msg__Server2Robot;

static bool _Server2Robot__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Server2Robot__ros_msg_type * ros_message = static_cast<const _Server2Robot__ros_msg_type *>(untyped_ros_message);
  // Field name: gate
  {
    const rosidl_runtime_c__String * str = &ros_message->gate;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: activate
  {
    cdr << (ros_message->activate ? true : false);
  }

  // Field name: engage
  {
    cdr << (ros_message->engage ? true : false);
  }

  // Field name: estop
  {
    cdr << (ros_message->estop ? true : false);
  }

  return true;
}

static bool _Server2Robot__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Server2Robot__ros_msg_type * ros_message = static_cast<_Server2Robot__ros_msg_type *>(untyped_ros_message);
  // Field name: gate
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->gate.data) {
      rosidl_runtime_c__String__init(&ros_message->gate);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->gate,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'gate'\n");
      return false;
    }
  }

  // Field name: activate
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->activate = tmp ? true : false;
  }

  // Field name: engage
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->engage = tmp ? true : false;
  }

  // Field name: estop
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->estop = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_bridge_interface
size_t get_serialized_size_bridge_interface__msg__Server2Robot(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Server2Robot__ros_msg_type * ros_message = static_cast<const _Server2Robot__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name gate
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->gate.size + 1);
  // field.name activate
  {
    size_t item_size = sizeof(ros_message->activate);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name engage
  {
    size_t item_size = sizeof(ros_message->engage);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name estop
  {
    size_t item_size = sizeof(ros_message->estop);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Server2Robot__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_bridge_interface__msg__Server2Robot(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_bridge_interface
size_t max_serialized_size_bridge_interface__msg__Server2Robot(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: gate
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: activate
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: engage
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: estop
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static size_t _Server2Robot__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_bridge_interface__msg__Server2Robot(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Server2Robot = {
  "bridge_interface::msg",
  "Server2Robot",
  _Server2Robot__cdr_serialize,
  _Server2Robot__cdr_deserialize,
  _Server2Robot__get_serialized_size,
  _Server2Robot__max_serialized_size
};

static rosidl_message_type_support_t _Server2Robot__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Server2Robot,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, bridge_interface, msg, Server2Robot)() {
  return &_Server2Robot__type_support;
}

#if defined(__cplusplus)
}
#endif
