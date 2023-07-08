// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from bridge_interface:msg/Server2Robot.idl
// generated code does not contain a copyright notice

#ifndef BRIDGE_INTERFACE__MSG__DETAIL__SERVER2_ROBOT__BUILDER_HPP_
#define BRIDGE_INTERFACE__MSG__DETAIL__SERVER2_ROBOT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "bridge_interface/msg/detail/server2_robot__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace bridge_interface
{

namespace msg
{

namespace builder
{

class Init_Server2Robot_estop
{
public:
  explicit Init_Server2Robot_estop(::bridge_interface::msg::Server2Robot & msg)
  : msg_(msg)
  {}
  ::bridge_interface::msg::Server2Robot estop(::bridge_interface::msg::Server2Robot::_estop_type arg)
  {
    msg_.estop = std::move(arg);
    return std::move(msg_);
  }

private:
  ::bridge_interface::msg::Server2Robot msg_;
};

class Init_Server2Robot_engage
{
public:
  explicit Init_Server2Robot_engage(::bridge_interface::msg::Server2Robot & msg)
  : msg_(msg)
  {}
  Init_Server2Robot_estop engage(::bridge_interface::msg::Server2Robot::_engage_type arg)
  {
    msg_.engage = std::move(arg);
    return Init_Server2Robot_estop(msg_);
  }

private:
  ::bridge_interface::msg::Server2Robot msg_;
};

class Init_Server2Robot_activate
{
public:
  explicit Init_Server2Robot_activate(::bridge_interface::msg::Server2Robot & msg)
  : msg_(msg)
  {}
  Init_Server2Robot_engage activate(::bridge_interface::msg::Server2Robot::_activate_type arg)
  {
    msg_.activate = std::move(arg);
    return Init_Server2Robot_engage(msg_);
  }

private:
  ::bridge_interface::msg::Server2Robot msg_;
};

class Init_Server2Robot_gate
{
public:
  Init_Server2Robot_gate()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Server2Robot_activate gate(::bridge_interface::msg::Server2Robot::_gate_type arg)
  {
    msg_.gate = std::move(arg);
    return Init_Server2Robot_activate(msg_);
  }

private:
  ::bridge_interface::msg::Server2Robot msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::bridge_interface::msg::Server2Robot>()
{
  return bridge_interface::msg::builder::Init_Server2Robot_gate();
}

}  // namespace bridge_interface

#endif  // BRIDGE_INTERFACE__MSG__DETAIL__SERVER2_ROBOT__BUILDER_HPP_
