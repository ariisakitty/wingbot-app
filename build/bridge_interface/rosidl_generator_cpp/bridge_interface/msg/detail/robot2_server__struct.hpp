// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from bridge_interface:msg/Robot2Server.idl
// generated code does not contain a copyright notice

#ifndef BRIDGE_INTERFACE__MSG__DETAIL__ROBOT2_SERVER__STRUCT_HPP_
#define BRIDGE_INTERFACE__MSG__DETAIL__ROBOT2_SERVER__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__bridge_interface__msg__Robot2Server __attribute__((deprecated))
#else
# define DEPRECATED__bridge_interface__msg__Robot2Server __declspec(deprecated)
#endif

namespace bridge_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Robot2Server_
{
  using Type = Robot2Server_<ContainerAllocator>;

  explicit Robot2Server_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->gate = "";
    }
  }

  explicit Robot2Server_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : gate(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->gate = "";
    }
  }

  // field types and members
  using _gate_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _gate_type gate;

  // setters for named parameter idiom
  Type & set__gate(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->gate = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    bridge_interface::msg::Robot2Server_<ContainerAllocator> *;
  using ConstRawPtr =
    const bridge_interface::msg::Robot2Server_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<bridge_interface::msg::Robot2Server_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<bridge_interface::msg::Robot2Server_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      bridge_interface::msg::Robot2Server_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<bridge_interface::msg::Robot2Server_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      bridge_interface::msg::Robot2Server_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<bridge_interface::msg::Robot2Server_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<bridge_interface::msg::Robot2Server_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<bridge_interface::msg::Robot2Server_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__bridge_interface__msg__Robot2Server
    std::shared_ptr<bridge_interface::msg::Robot2Server_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__bridge_interface__msg__Robot2Server
    std::shared_ptr<bridge_interface::msg::Robot2Server_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Robot2Server_ & other) const
  {
    if (this->gate != other.gate) {
      return false;
    }
    return true;
  }
  bool operator!=(const Robot2Server_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Robot2Server_

// alias to use template instance with default allocator
using Robot2Server =
  bridge_interface::msg::Robot2Server_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace bridge_interface

#endif  // BRIDGE_INTERFACE__MSG__DETAIL__ROBOT2_SERVER__STRUCT_HPP_
