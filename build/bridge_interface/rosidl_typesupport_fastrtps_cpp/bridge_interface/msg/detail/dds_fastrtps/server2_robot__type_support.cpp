// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from bridge_interface:msg/Server2Robot.idl
// generated code does not contain a copyright notice
#include "bridge_interface/msg/detail/server2_robot__rosidl_typesupport_fastrtps_cpp.hpp"
#include "bridge_interface/msg/detail/server2_robot__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace bridge_interface
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_bridge_interface
cdr_serialize(
  const bridge_interface::msg::Server2Robot & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: gate
  cdr << ros_message.gate;
  // Member: activate
  cdr << (ros_message.activate ? true : false);
  // Member: engage
  cdr << (ros_message.engage ? true : false);
  // Member: estop
  cdr << (ros_message.estop ? true : false);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_bridge_interface
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  bridge_interface::msg::Server2Robot & ros_message)
{
  // Member: gate
  cdr >> ros_message.gate;

  // Member: activate
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.activate = tmp ? true : false;
  }

  // Member: engage
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.engage = tmp ? true : false;
  }

  // Member: estop
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.estop = tmp ? true : false;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_bridge_interface
get_serialized_size(
  const bridge_interface::msg::Server2Robot & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: gate
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.gate.size() + 1);
  // Member: activate
  {
    size_t item_size = sizeof(ros_message.activate);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: engage
  {
    size_t item_size = sizeof(ros_message.engage);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: estop
  {
    size_t item_size = sizeof(ros_message.estop);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_bridge_interface
max_serialized_size_Server2Robot(
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


  // Member: gate
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

  // Member: activate
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: engage
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: estop
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static bool _Server2Robot__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const bridge_interface::msg::Server2Robot *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Server2Robot__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<bridge_interface::msg::Server2Robot *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Server2Robot__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const bridge_interface::msg::Server2Robot *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Server2Robot__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_Server2Robot(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _Server2Robot__callbacks = {
  "bridge_interface::msg",
  "Server2Robot",
  _Server2Robot__cdr_serialize,
  _Server2Robot__cdr_deserialize,
  _Server2Robot__get_serialized_size,
  _Server2Robot__max_serialized_size
};

static rosidl_message_type_support_t _Server2Robot__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Server2Robot__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace bridge_interface

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_bridge_interface
const rosidl_message_type_support_t *
get_message_type_support_handle<bridge_interface::msg::Server2Robot>()
{
  return &bridge_interface::msg::typesupport_fastrtps_cpp::_Server2Robot__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, bridge_interface, msg, Server2Robot)() {
  return &bridge_interface::msg::typesupport_fastrtps_cpp::_Server2Robot__handle;
}

#ifdef __cplusplus
}
#endif
