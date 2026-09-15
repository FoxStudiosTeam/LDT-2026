// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rosbag2_interfaces:srv\SplitBagfile.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosbag2_interfaces/srv/split_bagfile.hpp"


#ifndef ROSBAG2_INTERFACES__SRV__DETAIL__SPLIT_BAGFILE__STRUCT_HPP_
#define ROSBAG2_INTERFACES__SRV__DETAIL__SPLIT_BAGFILE__STRUCT_HPP_

#include <cstdint>
#include <memory>
#include <string>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'split_time'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__rosbag2_interfaces__srv__SplitBagfile_Request __attribute__((deprecated))
#else
# define DEPRECATED__rosbag2_interfaces__srv__SplitBagfile_Request __declspec(deprecated)
#endif

namespace rosbag2_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SplitBagfile_Request_
{
  using Type = SplitBagfile_Request_<ContainerAllocator>;

  explicit SplitBagfile_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : split_time(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->split_mode = 0l;
      this->tracking_topic_name = "";
    }
  }

  explicit SplitBagfile_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : split_time(_alloc, _init),
    tracking_topic_name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->split_mode = 0l;
      this->tracking_topic_name = "";
    }
  }

  // field types and members
  using _split_time_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _split_time_type split_time;
  using _split_mode_type =
    int32_t;
  _split_mode_type split_mode;
  using _tracking_topic_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _tracking_topic_name_type tracking_topic_name;

  // setters for named parameter idiom
  Type & set__split_time(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->split_time = _arg;
    return *this;
  }
  Type & set__split_mode(
    const int32_t & _arg)
  {
    this->split_mode = _arg;
    return *this;
  }
  Type & set__tracking_topic_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->tracking_topic_name = _arg;
    return *this;
  }

  // constant declarations
  static constexpr int32_t SPLIT_MODE_NODE_TIME =
    0;
  static constexpr int32_t SPLIT_MODE_PUBLISH_TIME =
    1;
  static constexpr int32_t SPLIT_MODE_RECEIVE_TIME =
    2;

  // pointer types
  using RawPtr =
    rosbag2_interfaces::srv::SplitBagfile_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const rosbag2_interfaces::srv::SplitBagfile_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rosbag2_interfaces::srv::SplitBagfile_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rosbag2_interfaces::srv::SplitBagfile_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rosbag2_interfaces::srv::SplitBagfile_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rosbag2_interfaces::srv::SplitBagfile_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rosbag2_interfaces::srv::SplitBagfile_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rosbag2_interfaces::srv::SplitBagfile_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rosbag2_interfaces::srv::SplitBagfile_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rosbag2_interfaces::srv::SplitBagfile_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rosbag2_interfaces__srv__SplitBagfile_Request
    std::shared_ptr<rosbag2_interfaces::srv::SplitBagfile_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rosbag2_interfaces__srv__SplitBagfile_Request
    std::shared_ptr<rosbag2_interfaces::srv::SplitBagfile_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SplitBagfile_Request_ & other) const
  {
    if (this->split_time != other.split_time) {
      return false;
    }
    if (this->split_mode != other.split_mode) {
      return false;
    }
    if (this->tracking_topic_name != other.tracking_topic_name) {
      return false;
    }
    return true;
  }
  bool operator!=(const SplitBagfile_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SplitBagfile_Request_

// alias to use template instance with default allocator
using SplitBagfile_Request =
  rosbag2_interfaces::srv::SplitBagfile_Request_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int32_t SplitBagfile_Request_<ContainerAllocator>::SPLIT_MODE_NODE_TIME;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int32_t SplitBagfile_Request_<ContainerAllocator>::SPLIT_MODE_PUBLISH_TIME;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int32_t SplitBagfile_Request_<ContainerAllocator>::SPLIT_MODE_RECEIVE_TIME;
#endif  // __cplusplus < 201703L

}  // namespace srv

}  // namespace rosbag2_interfaces


#ifndef _WIN32
# define DEPRECATED__rosbag2_interfaces__srv__SplitBagfile_Response __attribute__((deprecated))
#else
# define DEPRECATED__rosbag2_interfaces__srv__SplitBagfile_Response __declspec(deprecated)
#endif

namespace rosbag2_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SplitBagfile_Response_
{
  using Type = SplitBagfile_Response_<ContainerAllocator>;

  explicit SplitBagfile_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->return_code = 0l;
      this->error_string = "";
    }
  }

  explicit SplitBagfile_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : error_string(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->return_code = 0l;
      this->error_string = "";
    }
  }

  // field types and members
  using _return_code_type =
    int32_t;
  _return_code_type return_code;
  using _error_string_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _error_string_type error_string;

  // setters for named parameter idiom
  Type & set__return_code(
    const int32_t & _arg)
  {
    this->return_code = _arg;
    return *this;
  }
  Type & set__error_string(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->error_string = _arg;
    return *this;
  }

  // constant declarations
  static constexpr int32_t RETURN_CODE_SUCCESS =
    0;
  static constexpr int32_t RETURN_CODE_NOT_RECORDING =
    1;
  static constexpr int32_t RETURN_CODE_INVALID_SPLIT_MODE =
    2;
  static constexpr int32_t RETURN_CODE_INVALID_TRACKING_TOPIC =
    3;
  static constexpr int32_t RETURN_CODE_SPLIT_FAILED =
    4;

  // pointer types
  using RawPtr =
    rosbag2_interfaces::srv::SplitBagfile_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const rosbag2_interfaces::srv::SplitBagfile_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rosbag2_interfaces::srv::SplitBagfile_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rosbag2_interfaces::srv::SplitBagfile_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rosbag2_interfaces::srv::SplitBagfile_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rosbag2_interfaces::srv::SplitBagfile_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rosbag2_interfaces::srv::SplitBagfile_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rosbag2_interfaces::srv::SplitBagfile_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rosbag2_interfaces::srv::SplitBagfile_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rosbag2_interfaces::srv::SplitBagfile_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rosbag2_interfaces__srv__SplitBagfile_Response
    std::shared_ptr<rosbag2_interfaces::srv::SplitBagfile_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rosbag2_interfaces__srv__SplitBagfile_Response
    std::shared_ptr<rosbag2_interfaces::srv::SplitBagfile_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SplitBagfile_Response_ & other) const
  {
    if (this->return_code != other.return_code) {
      return false;
    }
    if (this->error_string != other.error_string) {
      return false;
    }
    return true;
  }
  bool operator!=(const SplitBagfile_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SplitBagfile_Response_

// alias to use template instance with default allocator
using SplitBagfile_Response =
  rosbag2_interfaces::srv::SplitBagfile_Response_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int32_t SplitBagfile_Response_<ContainerAllocator>::RETURN_CODE_SUCCESS;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int32_t SplitBagfile_Response_<ContainerAllocator>::RETURN_CODE_NOT_RECORDING;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int32_t SplitBagfile_Response_<ContainerAllocator>::RETURN_CODE_INVALID_SPLIT_MODE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int32_t SplitBagfile_Response_<ContainerAllocator>::RETURN_CODE_INVALID_TRACKING_TOPIC;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int32_t SplitBagfile_Response_<ContainerAllocator>::RETURN_CODE_SPLIT_FAILED;
#endif  // __cplusplus < 201703L

}  // namespace srv

}  // namespace rosbag2_interfaces


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__rosbag2_interfaces__srv__SplitBagfile_Event __attribute__((deprecated))
#else
# define DEPRECATED__rosbag2_interfaces__srv__SplitBagfile_Event __declspec(deprecated)
#endif

namespace rosbag2_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SplitBagfile_Event_
{
  using Type = SplitBagfile_Event_<ContainerAllocator>;

  explicit SplitBagfile_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit SplitBagfile_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<rosbag2_interfaces::srv::SplitBagfile_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<rosbag2_interfaces::srv::SplitBagfile_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<rosbag2_interfaces::srv::SplitBagfile_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<rosbag2_interfaces::srv::SplitBagfile_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<rosbag2_interfaces::srv::SplitBagfile_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<rosbag2_interfaces::srv::SplitBagfile_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<rosbag2_interfaces::srv::SplitBagfile_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<rosbag2_interfaces::srv::SplitBagfile_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rosbag2_interfaces::srv::SplitBagfile_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const rosbag2_interfaces::srv::SplitBagfile_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rosbag2_interfaces::srv::SplitBagfile_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rosbag2_interfaces::srv::SplitBagfile_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rosbag2_interfaces::srv::SplitBagfile_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rosbag2_interfaces::srv::SplitBagfile_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rosbag2_interfaces::srv::SplitBagfile_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rosbag2_interfaces::srv::SplitBagfile_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rosbag2_interfaces::srv::SplitBagfile_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rosbag2_interfaces::srv::SplitBagfile_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rosbag2_interfaces__srv__SplitBagfile_Event
    std::shared_ptr<rosbag2_interfaces::srv::SplitBagfile_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rosbag2_interfaces__srv__SplitBagfile_Event
    std::shared_ptr<rosbag2_interfaces::srv::SplitBagfile_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SplitBagfile_Event_ & other) const
  {
    if (this->info != other.info) {
      return false;
    }
    if (this->request != other.request) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const SplitBagfile_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SplitBagfile_Event_

// alias to use template instance with default allocator
using SplitBagfile_Event =
  rosbag2_interfaces::srv::SplitBagfile_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace rosbag2_interfaces

namespace rosbag2_interfaces
{

namespace srv
{

struct SplitBagfile
{
  using Request = rosbag2_interfaces::srv::SplitBagfile_Request;
  using Response = rosbag2_interfaces::srv::SplitBagfile_Response;
  using Event = rosbag2_interfaces::srv::SplitBagfile_Event;
};

}  // namespace srv

}  // namespace rosbag2_interfaces

#endif  // ROSBAG2_INTERFACES__SRV__DETAIL__SPLIT_BAGFILE__STRUCT_HPP_
