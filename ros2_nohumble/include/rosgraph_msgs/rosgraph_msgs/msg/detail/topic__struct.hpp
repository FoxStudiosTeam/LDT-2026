// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rosgraph_msgs:msg\Topic.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosgraph_msgs/msg/topic.hpp"


#ifndef ROSGRAPH_MSGS__MSG__DETAIL__TOPIC__STRUCT_HPP_
#define ROSGRAPH_MSGS__MSG__DETAIL__TOPIC__STRUCT_HPP_

#include <cstdint>
#include <memory>
#include <string>

#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'type'
#include "rosgraph_msgs/msg/detail/interface_type__struct.hpp"
// Member 'qos'
#include "rosgraph_msgs/msg/detail/qo_s_profile__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__rosgraph_msgs__msg__Topic __attribute__((deprecated))
#else
# define DEPRECATED__rosgraph_msgs__msg__Topic __declspec(deprecated)
#endif

namespace rosgraph_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Topic_
{
  using Type = Topic_<ContainerAllocator>;

  explicit Topic_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : type(_init),
    qos(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
    }
  }

  explicit Topic_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : name(_alloc),
    type(_alloc, _init),
    qos(_alloc, _init)
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
  using _type_type =
    rosgraph_msgs::msg::InterfaceType_<ContainerAllocator>;
  _type_type type;
  using _qos_type =
    rosgraph_msgs::msg::QoSProfile_<ContainerAllocator>;
  _qos_type qos;

  // setters for named parameter idiom
  Type & set__name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->name = _arg;
    return *this;
  }
  Type & set__type(
    const rosgraph_msgs::msg::InterfaceType_<ContainerAllocator> & _arg)
  {
    this->type = _arg;
    return *this;
  }
  Type & set__qos(
    const rosgraph_msgs::msg::QoSProfile_<ContainerAllocator> & _arg)
  {
    this->qos = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rosgraph_msgs::msg::Topic_<ContainerAllocator> *;
  using ConstRawPtr =
    const rosgraph_msgs::msg::Topic_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rosgraph_msgs::msg::Topic_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rosgraph_msgs::msg::Topic_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rosgraph_msgs::msg::Topic_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rosgraph_msgs::msg::Topic_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rosgraph_msgs::msg::Topic_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rosgraph_msgs::msg::Topic_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rosgraph_msgs::msg::Topic_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rosgraph_msgs::msg::Topic_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rosgraph_msgs__msg__Topic
    std::shared_ptr<rosgraph_msgs::msg::Topic_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rosgraph_msgs__msg__Topic
    std::shared_ptr<rosgraph_msgs::msg::Topic_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Topic_ & other) const
  {
    if (this->name != other.name) {
      return false;
    }
    if (this->type != other.type) {
      return false;
    }
    if (this->qos != other.qos) {
      return false;
    }
    return true;
  }
  bool operator!=(const Topic_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Topic_

// alias to use template instance with default allocator
using Topic =
  rosgraph_msgs::msg::Topic_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rosgraph_msgs

#endif  // ROSGRAPH_MSGS__MSG__DETAIL__TOPIC__STRUCT_HPP_
