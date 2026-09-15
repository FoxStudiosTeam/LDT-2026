// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rosbag2_interfaces:msg\MessagesLostEvent.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosbag2_interfaces/msg/messages_lost_event.hpp"


#ifndef ROSBAG2_INTERFACES__MSG__DETAIL__MESSAGES_LOST_EVENT__STRUCT_HPP_
#define ROSBAG2_INTERFACES__MSG__DETAIL__MESSAGES_LOST_EVENT__STRUCT_HPP_

#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'messages_lost_statistics'
#include "rosbag2_interfaces/msg/detail/messages_lost_event_topic_stat__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__rosbag2_interfaces__msg__MessagesLostEvent __attribute__((deprecated))
#else
# define DEPRECATED__rosbag2_interfaces__msg__MessagesLostEvent __declspec(deprecated)
#endif

namespace rosbag2_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MessagesLostEvent_
{
  using Type = MessagesLostEvent_<ContainerAllocator>;

  explicit MessagesLostEvent_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->node_name = "";
    }
  }

  explicit MessagesLostEvent_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : node_name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->node_name = "";
    }
  }

  // field types and members
  using _node_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _node_name_type node_name;
  using _messages_lost_statistics_type =
    std::vector<rosbag2_interfaces::msg::MessagesLostEventTopicStat_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<rosbag2_interfaces::msg::MessagesLostEventTopicStat_<ContainerAllocator>>>;
  _messages_lost_statistics_type messages_lost_statistics;

  // setters for named parameter idiom
  Type & set__node_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->node_name = _arg;
    return *this;
  }
  Type & set__messages_lost_statistics(
    const std::vector<rosbag2_interfaces::msg::MessagesLostEventTopicStat_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<rosbag2_interfaces::msg::MessagesLostEventTopicStat_<ContainerAllocator>>> & _arg)
  {
    this->messages_lost_statistics = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rosbag2_interfaces::msg::MessagesLostEvent_<ContainerAllocator> *;
  using ConstRawPtr =
    const rosbag2_interfaces::msg::MessagesLostEvent_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rosbag2_interfaces::msg::MessagesLostEvent_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rosbag2_interfaces::msg::MessagesLostEvent_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rosbag2_interfaces::msg::MessagesLostEvent_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rosbag2_interfaces::msg::MessagesLostEvent_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rosbag2_interfaces::msg::MessagesLostEvent_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rosbag2_interfaces::msg::MessagesLostEvent_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rosbag2_interfaces::msg::MessagesLostEvent_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rosbag2_interfaces::msg::MessagesLostEvent_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rosbag2_interfaces__msg__MessagesLostEvent
    std::shared_ptr<rosbag2_interfaces::msg::MessagesLostEvent_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rosbag2_interfaces__msg__MessagesLostEvent
    std::shared_ptr<rosbag2_interfaces::msg::MessagesLostEvent_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MessagesLostEvent_ & other) const
  {
    if (this->node_name != other.node_name) {
      return false;
    }
    if (this->messages_lost_statistics != other.messages_lost_statistics) {
      return false;
    }
    return true;
  }
  bool operator!=(const MessagesLostEvent_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MessagesLostEvent_

// alias to use template instance with default allocator
using MessagesLostEvent =
  rosbag2_interfaces::msg::MessagesLostEvent_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rosbag2_interfaces

#endif  // ROSBAG2_INTERFACES__MSG__DETAIL__MESSAGES_LOST_EVENT__STRUCT_HPP_
