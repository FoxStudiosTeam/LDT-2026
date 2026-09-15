// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rosbag2_test_msgdefs:msg\ComplexMsg.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosbag2_test_msgdefs/msg/complex_msg.hpp"


#ifndef ROSBAG2_TEST_MSGDEFS__MSG__DETAIL__COMPLEX_MSG__STRUCT_HPP_
#define ROSBAG2_TEST_MSGDEFS__MSG__DETAIL__COMPLEX_MSG__STRUCT_HPP_

#include <cstdint>
#include <memory>

#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'b'
#include "rosbag2_test_msgdefs/msg/detail/basic_msg__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__rosbag2_test_msgdefs__msg__ComplexMsg __attribute__((deprecated))
#else
# define DEPRECATED__rosbag2_test_msgdefs__msg__ComplexMsg __declspec(deprecated)
#endif

namespace rosbag2_test_msgdefs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ComplexMsg_
{
  using Type = ComplexMsg_<ContainerAllocator>;

  explicit ComplexMsg_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : b(_init)
  {
    (void)_init;
  }

  explicit ComplexMsg_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : b(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _b_type =
    rosbag2_test_msgdefs::msg::BasicMsg_<ContainerAllocator>;
  _b_type b;

  // setters for named parameter idiom
  Type & set__b(
    const rosbag2_test_msgdefs::msg::BasicMsg_<ContainerAllocator> & _arg)
  {
    this->b = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rosbag2_test_msgdefs::msg::ComplexMsg_<ContainerAllocator> *;
  using ConstRawPtr =
    const rosbag2_test_msgdefs::msg::ComplexMsg_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rosbag2_test_msgdefs::msg::ComplexMsg_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rosbag2_test_msgdefs::msg::ComplexMsg_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rosbag2_test_msgdefs::msg::ComplexMsg_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rosbag2_test_msgdefs::msg::ComplexMsg_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rosbag2_test_msgdefs::msg::ComplexMsg_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rosbag2_test_msgdefs::msg::ComplexMsg_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rosbag2_test_msgdefs::msg::ComplexMsg_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rosbag2_test_msgdefs::msg::ComplexMsg_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rosbag2_test_msgdefs__msg__ComplexMsg
    std::shared_ptr<rosbag2_test_msgdefs::msg::ComplexMsg_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rosbag2_test_msgdefs__msg__ComplexMsg
    std::shared_ptr<rosbag2_test_msgdefs::msg::ComplexMsg_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ComplexMsg_ & other) const
  {
    if (this->b != other.b) {
      return false;
    }
    return true;
  }
  bool operator!=(const ComplexMsg_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ComplexMsg_

// alias to use template instance with default allocator
using ComplexMsg =
  rosbag2_test_msgdefs::msg::ComplexMsg_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rosbag2_test_msgdefs

#endif  // ROSBAG2_TEST_MSGDEFS__MSG__DETAIL__COMPLEX_MSG__STRUCT_HPP_
