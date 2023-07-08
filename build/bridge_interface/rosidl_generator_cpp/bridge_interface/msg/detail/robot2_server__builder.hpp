// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from bridge_interface:msg/Robot2Server.idl
// generated code does not contain a copyright notice

#ifndef BRIDGE_INTERFACE__MSG__DETAIL__ROBOT2_SERVER__BUILDER_HPP_
#define BRIDGE_INTERFACE__MSG__DETAIL__ROBOT2_SERVER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "bridge_interface/msg/detail/robot2_server__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace bridge_interface
{

namespace msg
{

namespace builder
{

class Init_Robot2Server_gate
{
public:
  Init_Robot2Server_gate()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::bridge_interface::msg::Robot2Server gate(::bridge_interface::msg::Robot2Server::_gate_type arg)
  {
    msg_.gate = std::move(arg);
    return std::move(msg_);
  }

private:
  ::bridge_interface::msg::Robot2Server msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::bridge_interface::msg::Robot2Server>()
{
  return bridge_interface::msg::builder::Init_Robot2Server_gate();
}

}  // namespace bridge_interface

#endif  // BRIDGE_INTERFACE__MSG__DETAIL__ROBOT2_SERVER__BUILDER_HPP_
