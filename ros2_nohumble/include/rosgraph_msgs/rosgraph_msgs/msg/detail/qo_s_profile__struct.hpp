// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rosgraph_msgs:msg\QoSProfile.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosgraph_msgs/msg/qo_s_profile.hpp"


#ifndef ROSGRAPH_MSGS__MSG__DETAIL__QO_S_PROFILE__STRUCT_HPP_
#define ROSGRAPH_MSGS__MSG__DETAIL__QO_S_PROFILE__STRUCT_HPP_

#include <cstdint>
#include <memory>

#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'deadline'
// Member 'lifespan'
// Member 'liveliness_lease_duration'
#include "builtin_interfaces/msg/detail/duration__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__rosgraph_msgs__msg__QoSProfile __attribute__((deprecated))
#else
# define DEPRECATED__rosgraph_msgs__msg__QoSProfile __declspec(deprecated)
#endif

namespace rosgraph_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct QoSProfile_
{
  using Type = QoSProfile_<ContainerAllocator>;

  explicit QoSProfile_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : deadline(_init),
    lifespan(_init),
    liveliness_lease_duration(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->depth = 0ul;
      this->history = 0;
      this->reliability = 0;
      this->durability = 0;
      this->liveliness = 0;
    }
  }

  explicit QoSProfile_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : deadline(_alloc, _init),
    lifespan(_alloc, _init),
    liveliness_lease_duration(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->depth = 0ul;
      this->history = 0;
      this->reliability = 0;
      this->durability = 0;
      this->liveliness = 0;
    }
  }

  // field types and members
  using _depth_type =
    uint32_t;
  _depth_type depth;
  using _deadline_type =
    builtin_interfaces::msg::Duration_<ContainerAllocator>;
  _deadline_type deadline;
  using _lifespan_type =
    builtin_interfaces::msg::Duration_<ContainerAllocator>;
  _lifespan_type lifespan;
  using _history_type =
    uint8_t;
  _history_type history;
  using _reliability_type =
    uint8_t;
  _reliability_type reliability;
  using _durability_type =
    uint8_t;
  _durability_type durability;
  using _liveliness_type =
    uint8_t;
  _liveliness_type liveliness;
  using _liveliness_lease_duration_type =
    builtin_interfaces::msg::Duration_<ContainerAllocator>;
  _liveliness_lease_duration_type liveliness_lease_duration;

  // setters for named parameter idiom
  Type & set__depth(
    const uint32_t & _arg)
  {
    this->depth = _arg;
    return *this;
  }
  Type & set__deadline(
    const builtin_interfaces::msg::Duration_<ContainerAllocator> & _arg)
  {
    this->deadline = _arg;
    return *this;
  }
  Type & set__lifespan(
    const builtin_interfaces::msg::Duration_<ContainerAllocator> & _arg)
  {
    this->lifespan = _arg;
    return *this;
  }
  Type & set__history(
    const uint8_t & _arg)
  {
    this->history = _arg;
    return *this;
  }
  Type & set__reliability(
    const uint8_t & _arg)
  {
    this->reliability = _arg;
    return *this;
  }
  Type & set__durability(
    const uint8_t & _arg)
  {
    this->durability = _arg;
    return *this;
  }
  Type & set__liveliness(
    const uint8_t & _arg)
  {
    this->liveliness = _arg;
    return *this;
  }
  Type & set__liveliness_lease_duration(
    const builtin_interfaces::msg::Duration_<ContainerAllocator> & _arg)
  {
    this->liveliness_lease_duration = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t HISTORY_SYSTEM_DEFAULT =
    0u;
  static constexpr uint8_t HISTORY_KEEP_LAST =
    1u;
  static constexpr uint8_t HISTORY_KEEP_ALL =
    2u;
  static constexpr uint8_t HISTORY_UNKNOWN =
    3u;
  static constexpr uint8_t RELIABILITY_SYSTEM_DEFAULT =
    0u;
  static constexpr uint8_t RELIABILITY_RELIABLE =
    1u;
  static constexpr uint8_t RELIABILITY_BEST_EFFORT =
    2u;
  static constexpr uint8_t RELIABILITY_UNKNOWN =
    3u;
  static constexpr uint8_t RELIABILITY_BEST_AVAILABLE =
    4u;
  static constexpr uint8_t DURABILITY_SYSTEM_DEFAULT =
    0u;
  static constexpr uint8_t DURABILITY_TRANSIENT_LOCAL =
    1u;
  static constexpr uint8_t DURABILITY_VOLATILE =
    2u;
  static constexpr uint8_t DURABILITY_UNKNOWN =
    3u;
  static constexpr uint8_t DURABILITY_BEST_AVAILABLE =
    4u;
  static constexpr uint8_t LIVELINESS_SYSTEM_DEFAULT =
    0u;
  static constexpr uint8_t LIVELINESS_AUTOMATIC =
    1u;
  static constexpr uint8_t LIVELINESS_MANUAL_BY_TOPIC =
    3u;
  static constexpr uint8_t LIVELINESS_UNKNOWN =
    4u;
  static constexpr uint8_t LIVELINESS_BEST_AVAILABLE =
    5u;

  // pointer types
  using RawPtr =
    rosgraph_msgs::msg::QoSProfile_<ContainerAllocator> *;
  using ConstRawPtr =
    const rosgraph_msgs::msg::QoSProfile_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rosgraph_msgs::msg::QoSProfile_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rosgraph_msgs::msg::QoSProfile_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rosgraph_msgs::msg::QoSProfile_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rosgraph_msgs::msg::QoSProfile_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rosgraph_msgs::msg::QoSProfile_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rosgraph_msgs::msg::QoSProfile_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rosgraph_msgs::msg::QoSProfile_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rosgraph_msgs::msg::QoSProfile_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rosgraph_msgs__msg__QoSProfile
    std::shared_ptr<rosgraph_msgs::msg::QoSProfile_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rosgraph_msgs__msg__QoSProfile
    std::shared_ptr<rosgraph_msgs::msg::QoSProfile_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const QoSProfile_ & other) const
  {
    if (this->depth != other.depth) {
      return false;
    }
    if (this->deadline != other.deadline) {
      return false;
    }
    if (this->lifespan != other.lifespan) {
      return false;
    }
    if (this->history != other.history) {
      return false;
    }
    if (this->reliability != other.reliability) {
      return false;
    }
    if (this->durability != other.durability) {
      return false;
    }
    if (this->liveliness != other.liveliness) {
      return false;
    }
    if (this->liveliness_lease_duration != other.liveliness_lease_duration) {
      return false;
    }
    return true;
  }
  bool operator!=(const QoSProfile_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct QoSProfile_

// alias to use template instance with default allocator
using QoSProfile =
  rosgraph_msgs::msg::QoSProfile_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t QoSProfile_<ContainerAllocator>::HISTORY_SYSTEM_DEFAULT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t QoSProfile_<ContainerAllocator>::HISTORY_KEEP_LAST;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t QoSProfile_<ContainerAllocator>::HISTORY_KEEP_ALL;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t QoSProfile_<ContainerAllocator>::HISTORY_UNKNOWN;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t QoSProfile_<ContainerAllocator>::RELIABILITY_SYSTEM_DEFAULT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t QoSProfile_<ContainerAllocator>::RELIABILITY_RELIABLE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t QoSProfile_<ContainerAllocator>::RELIABILITY_BEST_EFFORT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t QoSProfile_<ContainerAllocator>::RELIABILITY_UNKNOWN;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t QoSProfile_<ContainerAllocator>::RELIABILITY_BEST_AVAILABLE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t QoSProfile_<ContainerAllocator>::DURABILITY_SYSTEM_DEFAULT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t QoSProfile_<ContainerAllocator>::DURABILITY_TRANSIENT_LOCAL;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t QoSProfile_<ContainerAllocator>::DURABILITY_VOLATILE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t QoSProfile_<ContainerAllocator>::DURABILITY_UNKNOWN;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t QoSProfile_<ContainerAllocator>::DURABILITY_BEST_AVAILABLE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t QoSProfile_<ContainerAllocator>::LIVELINESS_SYSTEM_DEFAULT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t QoSProfile_<ContainerAllocator>::LIVELINESS_AUTOMATIC;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t QoSProfile_<ContainerAllocator>::LIVELINESS_MANUAL_BY_TOPIC;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t QoSProfile_<ContainerAllocator>::LIVELINESS_UNKNOWN;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t QoSProfile_<ContainerAllocator>::LIVELINESS_BEST_AVAILABLE;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace rosgraph_msgs

#endif  // ROSGRAPH_MSGS__MSG__DETAIL__QO_S_PROFILE__STRUCT_HPP_
