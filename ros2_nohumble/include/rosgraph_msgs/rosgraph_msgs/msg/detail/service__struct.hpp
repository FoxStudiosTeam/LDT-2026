// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rosgraph_msgs:msg\Service.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosgraph_msgs/msg/service.hpp"


#ifndef ROSGRAPH_MSGS__MSG__DETAIL__SERVICE__STRUCT_HPP_
#define ROSGRAPH_MSGS__MSG__DETAIL__SERVICE__STRUCT_HPP_

#include <cstdint>
#include <memory>
#include <string>

#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'request_type'
// Member 'response_type'
#include "rosgraph_msgs/msg/detail/interface_type__struct.hpp"
// Member 'request_qos'
// Member 'response_qos'
#include "rosgraph_msgs/msg/detail/qo_s_profile__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__rosgraph_msgs__msg__Service __attribute__((deprecated))
#else
# define DEPRECATED__rosgraph_msgs__msg__Service __declspec(deprecated)
#endif

namespace rosgraph_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Service_
{
  using Type = Service_<ContainerAllocator>;

  explicit Service_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : request_type(_init),
    request_qos(_init),
    response_type(_init),
    response_qos(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
    }
  }

  explicit Service_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : name(_alloc),
    request_type(_alloc, _init),
    request_qos(_alloc, _init),
    response_type(_alloc, _init),
    response_qos(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
    }
  }

  // field types and members
  using _name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _name_type name;
  using _request_type_type =
    rosgraph_msgs::msg::InterfaceType_<ContainerAllocator>;
  _request_type_type request_type;
  using _request_qos_type =
    rosgraph_msgs::msg::QoSProfile_<ContainerAllocator>;
  _request_qos_type request_qos;
  using _response_type_type =
    rosgraph_msgs::msg::InterfaceType_<ContainerAllocator>;
  _response_type_type response_type;
  using _response_qos_type =
    rosgraph_msgs::msg::QoSProfile_<ContainerAllocator>;
  _response_qos_type response_qos;

  // setters for named parameter idiom
  Type & set__name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->name = _arg;
    return *this;
  }
  Type & set__request_type(
    const rosgraph_msgs::msg::InterfaceType_<ContainerAllocator> & _arg)
  {
    this->request_type = _arg;
    return *this;
  }
  Type & set__request_qos(
    const rosgraph_msgs::msg::QoSProfile_<ContainerAllocator> & _arg)
  {
    this->request_qos = _arg;
    return *this;
  }
  Type & set__response_type(
    const rosgraph_msgs::msg::InterfaceType_<ContainerAllocator> & _arg)
  {
    this->response_type = _arg;
    return *this;
  }
  Type & set__response_qos(
    const rosgraph_msgs::msg::QoSProfile_<ContainerAllocator> & _arg)
  {
    this->response_qos = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rosgraph_msgs::msg::Service_<ContainerAllocator> *;
  using ConstRawPtr =
    const rosgraph_msgs::msg::Service_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rosgraph_msgs::msg::Service_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rosgraph_msgs::msg::Service_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rosgraph_msgs::msg::Service_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rosgraph_msgs::msg::Service_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rosgraph_msgs::msg::Service_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rosgraph_msgs::msg::Service_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rosgraph_msgs::msg::Service_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rosgraph_msgs::msg::Service_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rosgraph_msgs__msg__Service
    std::shared_ptr<rosgraph_msgs::msg::Service_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rosgraph_msgs__msg__Service
    std::shared_ptr<rosgraph_msgs::msg::Service_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Service_ & other) const
  {
    if (this->name != other.name) {
      return false;
    }
    if (this->request_type != other.request_type) {
      return false;
    }
    if (this->request_qos != other.request_qos) {
      return false;
    }
    if (this->response_type != other.response_type) {
      return false;
    }
    if (this->response_qos != other.response_qos) {
      return false;
    }
    return true;
  }
  bool operator!=(const Service_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Service_

// alias to use template instance with default allocator
using Service =
  rosgraph_msgs::msg::Service_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rosgraph_msgs

#endif  // ROSGRAPH_MSGS__MSG__DETAIL__SERVICE__STRUCT_HPP_
