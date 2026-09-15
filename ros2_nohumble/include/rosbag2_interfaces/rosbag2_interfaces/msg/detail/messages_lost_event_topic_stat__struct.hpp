// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rosbag2_interfaces:msg\MessagesLostEventTopicStat.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosbag2_interfaces/msg/messages_lost_event_topic_stat.hpp"


#ifndef ROSBAG2_INTERFACES__MSG__DETAIL__MESSAGES_LOST_EVENT_TOPIC_STAT__STRUCT_HPP_
#define ROSBAG2_INTERFACES__MSG__DETAIL__MESSAGES_LOST_EVENT_TOPIC_STAT__STRUCT_HPP_

#include <cstdint>
#include <memory>
#include <string>

#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rosbag2_interfaces__msg__MessagesLostEventTopicStat __attribute__((deprecated))
#else
# define DEPRECATED__rosbag2_interfaces__msg__MessagesLostEventTopicStat __declspec(deprecated)
#endif

namespace rosbag2_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MessagesLostEventTopicStat_
{
  using Type = MessagesLostEventTopicStat_<ContainerAllocator>;

  explicit MessagesLostEventTopicStat_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->topic_name = "";
      this->messages_lost_in_transport = 0ull;
      this->messages_lost_in_recorder = 0ull;
    }
  }

  explicit MessagesLostEventTopicStat_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : topic_name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->topic_name = "";
      this->messages_lost_in_transport = 0ull;
      this->messages_lost_in_recorder = 0ull;
    }
  }

  // field types and members
  using _topic_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _topic_name_type topic_name;
  using _messages_lost_in_transport_type =
    uint64_t;
  _messages_lost_in_transport_type messages_lost_in_transport;
  using _messages_lost_in_recorder_type =
    uint64_t;
  _messages_lost_in_recorder_type messages_lost_in_recorder;

  // setters for named parameter idiom
  Type & set__topic_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->topic_name = _arg;
    return *this;
  }
  Type & set__messages_lost_in_transport(
    const uint64_t & _arg)
  {
    this->messages_lost_in_transport = _arg;
    return *this;
  }
  Type & set__messages_lost_in_recorder(
    const uint64_t & _arg)
  {
    this->messages_lost_in_recorder = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rosbag2_interfaces::msg::MessagesLostEventTopicStat_<ContainerAllocator> *;
  using ConstRawPtr =
    const rosbag2_interfaces::msg::MessagesLostEventTopicStat_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rosbag2_interfaces::msg::MessagesLostEventTopicStat_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rosbag2_interfaces::msg::MessagesLostEventTopicStat_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rosbag2_interfaces::msg::MessagesLostEventTopicStat_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rosbag2_interfaces::msg::MessagesLostEventTopicStat_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rosbag2_interfaces::msg::MessagesLostEventTopicStat_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rosbag2_interfaces::msg::MessagesLostEventTopicStat_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rosbag2_interfaces::msg::MessagesLostEventTopicStat_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rosbag2_interfaces::msg::MessagesLostEventTopicStat_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rosbag2_interfaces__msg__MessagesLostEventTopicStat
    std::shared_ptr<rosbag2_interfaces::msg::MessagesLostEventTopicStat_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rosbag2_interfaces__msg__MessagesLostEventTopicStat
    std::shared_ptr<rosbag2_interfaces::msg::MessagesLostEventTopicStat_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MessagesLostEventTopicStat_ & other) const
  {
    if (this->topic_name != other.topic_name) {
      return false;
    }
    if (this->messages_lost_in_transport != other.messages_lost_in_transport) {
      return false;
    }
    if (this->messages_lost_in_recorder != other.messages_lost_in_recorder) {
      return false;
    }
    return true;
  }
  bool operator!=(const MessagesLostEventTopicStat_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MessagesLostEventTopicStat_

// alias to use template instance with default allocator
using MessagesLostEventTopicStat =
  rosbag2_interfaces::msg::MessagesLostEventTopicStat_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rosbag2_interfaces

#endif  // ROSBAG2_INTERFACES__MSG__DETAIL__MESSAGES_LOST_EVENT_TOPIC_STAT__STRUCT_HPP_
