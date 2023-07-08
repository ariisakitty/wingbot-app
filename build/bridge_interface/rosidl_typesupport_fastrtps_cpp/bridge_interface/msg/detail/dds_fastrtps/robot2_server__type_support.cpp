// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from bridge_interface:msg/Robot2Server.idl
// generated code does not contain a copyright notice
#include "bridge_interface/msg/detail/robot2_server__rosidl_typesupport_fastrtps_cpp.hpp"
#include "bridge_interface/msg/detail/robot2_server__struct.hpp"

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
  const bridge_interface::msg::Robot2Server & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: gate
  cdr << ros_message.gate;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_bridge_interface
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  bridge_interface::msg::Robot2Server & ros_message)
{
  // Member: gate
  cdr >> ros_message.gate;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_bridge_interface
get_serialized_size(
  const bridge_interface::msg::Robot2Server & ros_message,
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

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_bridge_interface
max_serialized_size_Robot2Server(
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

  return current_alignment - initial_alignment;
}

static bool _Robot2Server__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const bridge_interface::msg::Robot2Server *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Robot2Server__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<bridge_interface::msg::Robot2Server *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Robot2Server__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const bridge_interface::msg::Robot2Server *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Robot2Server__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_Robot2Server(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _Robot2Server__callbacks = {
  "bridge_interface::msg",
  "Robot2Server",
  _Robot2Server__cdr_serialize,
  _Robot2Server__cdr_deserialize,
  _Robot2Server__get_serialized_size,
  _Robot2Server__max_serialized_size
};

static rosidl_message_type_support_t _Robot2Server__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Robot2Server__callbacks,
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
get_message_type_support_handle<bridge_interface::msg::Robot2Server>()
{
  return &bridge_interface::msg::typesupport_fastrtps_cpp::_Robot2Server__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, bridge_interface, msg, Robot2Server)() {
  return &bridge_interface::msg::typesupport_fastrtps_cpp::_Robot2Server__handle;
}

#ifdef __cplusplus
}
#endif
