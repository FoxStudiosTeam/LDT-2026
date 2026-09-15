// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from test_rosidl_buffer:msg\ByteArray.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "test_rosidl_buffer/msg/byte_array.hpp"


#ifndef TEST_ROSIDL_BUFFER__MSG__DETAIL__BYTE_ARRAY__STRUCT_HPP_
#define TEST_ROSIDL_BUFFER__MSG__DETAIL__BYTE_ARRAY__STRUCT_HPP_

#include <cstdint>
#include <memory>

#include "rosidl_buffer/buffer.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__test_rosidl_buffer__msg__ByteArray __attribute__((deprecated))
#else
# define DEPRECATED__test_rosidl_buffer__msg__ByteArray __declspec(deprecated)
#endif

namespace test_rosidl_buffer
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ByteArray_
{
  using Type = ByteArray_<ContainerAllocator>;

  explicit ByteArray_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->seq = 0ul;
    }
  }

  explicit ByteArray_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->seq = 0ul;
    }
  }

  // field types and members
  using _seq_type =
    uint32_t;
  _seq_type seq;
  using _data_type =
    rosidl::Buffer<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>>;
  _data_type data;

  // setters for named parameter idiom
  Type & set__seq(
    const uint32_t & _arg)
  {
    this->seq = _arg;
    return *this;
  }
  Type & set__data(
    const rosidl::Buffer<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>> & _arg)
  {
    this->data = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    test_rosidl_buffer::msg::ByteArray_<ContainerAllocator> *;
  using ConstRawPtr =
    const test_rosidl_buffer::msg::ByteArray_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<test_rosidl_buffer::msg::ByteArray_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<test_rosidl_buffer::msg::ByteArray_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      test_rosidl_buffer::msg::ByteArray_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<test_rosidl_buffer::msg::ByteArray_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      test_rosidl_buffer::msg::ByteArray_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<test_rosidl_buffer::msg::ByteArray_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<test_rosidl_buffer::msg::ByteArray_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<test_rosidl_buffer::msg::ByteArray_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__test_rosidl_buffer__msg__ByteArray
    std::shared_ptr<test_rosidl_buffer::msg::ByteArray_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__test_rosidl_buffer__msg__ByteArray
    std::shared_ptr<test_rosidl_buffer::msg::ByteArray_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ByteArray_ & other) const
  {
    if (this->seq != other.seq) {
      return false;
    }
    if (this->data != other.data) {
      return false;
    }
    return true;
  }
  bool operator!=(const ByteArray_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ByteArray_

// alias to use template instance with default allocator
using ByteArray =
  test_rosidl_buffer::msg::ByteArray_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace test_rosidl_buffer

#endif  // TEST_ROSIDL_BUFFER__MSG__DETAIL__BYTE_ARRAY__STRUCT_HPP_
