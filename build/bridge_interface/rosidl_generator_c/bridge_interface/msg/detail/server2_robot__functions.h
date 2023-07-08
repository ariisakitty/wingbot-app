// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from bridge_interface:msg/Server2Robot.idl
// generated code does not contain a copyright notice

#ifndef BRIDGE_INTERFACE__MSG__DETAIL__SERVER2_ROBOT__FUNCTIONS_H_
#define BRIDGE_INTERFACE__MSG__DETAIL__SERVER2_ROBOT__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "bridge_interface/msg/rosidl_generator_c__visibility_control.h"

#include "bridge_interface/msg/detail/server2_robot__struct.h"

/// Initialize msg/Server2Robot message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * bridge_interface__msg__Server2Robot
 * )) before or use
 * bridge_interface__msg__Server2Robot__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_bridge_interface
bool
bridge_interface__msg__Server2Robot__init(bridge_interface__msg__Server2Robot * msg);

/// Finalize msg/Server2Robot message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_bridge_interface
void
bridge_interface__msg__Server2Robot__fini(bridge_interface__msg__Server2Robot * msg);

/// Create msg/Server2Robot message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * bridge_interface__msg__Server2Robot__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_bridge_interface
bridge_interface__msg__Server2Robot *
bridge_interface__msg__Server2Robot__create();

/// Destroy msg/Server2Robot message.
/**
 * It calls
 * bridge_interface__msg__Server2Robot__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_bridge_interface
void
bridge_interface__msg__Server2Robot__destroy(bridge_interface__msg__Server2Robot * msg);

/// Check for msg/Server2Robot message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_bridge_interface
bool
bridge_interface__msg__Server2Robot__are_equal(const bridge_interface__msg__Server2Robot * lhs, const bridge_interface__msg__Server2Robot * rhs);

/// Copy a msg/Server2Robot message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_bridge_interface
bool
bridge_interface__msg__Server2Robot__copy(
  const bridge_interface__msg__Server2Robot * input,
  bridge_interface__msg__Server2Robot * output);

/// Initialize array of msg/Server2Robot messages.
/**
 * It allocates the memory for the number of elements and calls
 * bridge_interface__msg__Server2Robot__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_bridge_interface
bool
bridge_interface__msg__Server2Robot__Sequence__init(bridge_interface__msg__Server2Robot__Sequence * array, size_t size);

/// Finalize array of msg/Server2Robot messages.
/**
 * It calls
 * bridge_interface__msg__Server2Robot__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_bridge_interface
void
bridge_interface__msg__Server2Robot__Sequence__fini(bridge_interface__msg__Server2Robot__Sequence * array);

/// Create array of msg/Server2Robot messages.
/**
 * It allocates the memory for the array and calls
 * bridge_interface__msg__Server2Robot__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_bridge_interface
bridge_interface__msg__Server2Robot__Sequence *
bridge_interface__msg__Server2Robot__Sequence__create(size_t size);

/// Destroy array of msg/Server2Robot messages.
/**
 * It calls
 * bridge_interface__msg__Server2Robot__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_bridge_interface
void
bridge_interface__msg__Server2Robot__Sequence__destroy(bridge_interface__msg__Server2Robot__Sequence * array);

/// Check for msg/Server2Robot message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_bridge_interface
bool
bridge_interface__msg__Server2Robot__Sequence__are_equal(const bridge_interface__msg__Server2Robot__Sequence * lhs, const bridge_interface__msg__Server2Robot__Sequence * rhs);

/// Copy an array of msg/Server2Robot messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_bridge_interface
bool
bridge_interface__msg__Server2Robot__Sequence__copy(
  const bridge_interface__msg__Server2Robot__Sequence * input,
  bridge_interface__msg__Server2Robot__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // BRIDGE_INTERFACE__MSG__DETAIL__SERVER2_ROBOT__FUNCTIONS_H_
