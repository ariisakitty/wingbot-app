// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from bridge_interface:msg/Server2Robot.idl
// generated code does not contain a copyright notice

#ifndef BRIDGE_INTERFACE__MSG__DETAIL__SERVER2_ROBOT__TRAITS_HPP_
#define BRIDGE_INTERFACE__MSG__DETAIL__SERVER2_ROBOT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "bridge_interface/msg/detail/server2_robot__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace bridge_interface
{

namespace msg
{

inline void to_flow_style_yaml(
  const Server2Robot & msg,
  std::ostream & out)
{
  out << "{";
  // member: gate
  {
    out << "gate: ";
    rosidl_generator_traits::value_to_yaml(msg.gate, out);
    out << ", ";
  }

  // member: activate
  {
    out << "activate: ";
    rosidl_generator_traits::value_to_yaml(msg.activate, out);
    out << ", ";
  }

  // member: engage
  {
    out << "engage: ";
    rosidl_generator_traits::value_to_yaml(msg.engage, out);
    out << ", ";
  }

  // member: estop
  {
    out << "estop: ";
    rosidl_generator_traits::value_to_yaml(msg.estop, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Server2Robot & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: gate
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gate: ";
    rosidl_generator_traits::value_to_yaml(msg.gate, out);
    out << "\n";
  }

  // member: activate
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "activate: ";
    rosidl_generator_traits::value_to_yaml(msg.activate, out);
    out << "\n";
  }

  // member: engage
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "engage: ";
    rosidl_generator_traits::value_to_yaml(msg.engage, out);
    out << "\n";
  }

  // member: estop
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "estop: ";
    rosidl_generator_traits::value_to_yaml(msg.estop, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Server2Robot & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace bridge_interface

namespace rosidl_generator_traits
{

[[deprecated("use bridge_interface::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const bridge_interface::msg::Server2Robot & msg,
  std::ostream & out, size_t indentation = 0)
{
  bridge_interface::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use bridge_interface::msg::to_yaml() instead")]]
inline std::string to_yaml(const bridge_interface::msg::Server2Robot & msg)
{
  return bridge_interface::msg::to_yaml(msg);
}

template<>
inline const char * data_type<bridge_interface::msg::Server2Robot>()
{
  return "bridge_interface::msg::Server2Robot";
}

template<>
inline const char * name<bridge_interface::msg::Server2Robot>()
{
  return "bridge_interface/msg/Server2Robot";
}

template<>
struct has_fixed_size<bridge_interface::msg::Server2Robot>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<bridge_interface::msg::Server2Robot>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<bridge_interface::msg::Server2Robot>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // BRIDGE_INTERFACE__MSG__DETAIL__SERVER2_ROBOT__TRAITS_HPP_
