// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from bridge_interface:msg/Server2Robot.idl
// generated code does not contain a copyright notice

#ifndef BRIDGE_INTERFACE__MSG__DETAIL__SERVER2_ROBOT__STRUCT_HPP_
#define BRIDGE_INTERFACE__MSG__DETAIL__SERVER2_ROBOT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__bridge_interface__msg__Server2Robot __attribute__((deprecated))
#else
# define DEPRECATED__bridge_interface__msg__Server2Robot __declspec(deprecated)
#endif

namespace bridge_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Server2Robot_
{
  using Type = Server2Robot_<ContainerAllocator>;

  explicit Server2Robot_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->gate = "";
      this->activate = false;
      this->engage = false;
      this->estop = false;
    }
  }

  explicit Server2Robot_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : gate(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->gate = "";
      this->activate = false;
      this->engage = false;
      this->estop = false;
    }
  }

  // field types and members
  using _gate_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _gate_type gate;
  using _activate_type =
    bool;
  _activate_type activate;
  using _engage_type =
    bool;
  _engage_type engage;
  using _estop_type =
    bool;
  _estop_type estop;

  // setters for named parameter idiom
  Type & set__gate(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->gate = _arg;
    return *this;
  }
  Type & set__activate(
    const bool & _arg)
  {
    this->activate = _arg;
    return *this;
  }
  Type & set__engage(
    const bool & _arg)
  {
    this->engage = _arg;
    return *this;
  }
  Type & set__estop(
    const bool & _arg)
  {
    this->estop = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    bridge_interface::msg::Server2Robot_<ContainerAllocator> *;
  using ConstRawPtr =
    const bridge_interface::msg::Server2Robot_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<bridge_interface::msg::Server2Robot_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<bridge_interface::msg::Server2Robot_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      bridge_interface::msg::Server2Robot_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<bridge_interface::msg::Server2Robot_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      bridge_interface::msg::Server2Robot_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<bridge_interface::msg::Server2Robot_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<bridge_interface::msg::Server2Robot_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<bridge_interface::msg::Server2Robot_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__bridge_interface__msg__Server2Robot
    std::shared_ptr<bridge_interface::msg::Server2Robot_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__bridge_interface__msg__Server2Robot
    std::shared_ptr<bridge_interface::msg::Server2Robot_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Server2Robot_ & other) const
  {
    if (this->gate != other.gate) {
      return false;
    }
    if (this->activate != other.activate) {
      return false;
    }
    if (this->engage != other.engage) {
      return false;
    }
    if (this->estop != other.estop) {
      return false;
    }
    return true;
  }
  bool operator!=(const Server2Robot_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Server2Robot_

// alias to use template instance with default allocator
using Server2Robot =
  bridge_interface::msg::Server2Robot_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace bridge_interface

#endif  // BRIDGE_INTERFACE__MSG__DETAIL__SERVER2_ROBOT__STRUCT_HPP_
