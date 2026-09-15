// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rosbag2_interfaces:srv\Resume.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosbag2_interfaces/srv/resume.hpp"


#ifndef ROSBAG2_INTERFACES__SRV__DETAIL__RESUME__STRUCT_HPP_
#define ROSBAG2_INTERFACES__SRV__DETAIL__RESUME__STRUCT_HPP_

#include <cstdint>
#include <memory>
#include <string>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'resume_time'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__rosbag2_interfaces__srv__Resume_Request __attribute__((deprecated))
#else
# define DEPRECATED__rosbag2_interfaces__srv__Resume_Request __declspec(deprecated)
#endif

namespace rosbag2_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Resume_Request_
{
  using Type = Resume_Request_<ContainerAllocator>;

  explicit Resume_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : resume_time(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->resume_mode = 0l;
      this->tracking_topic_name = "";
    }
  }

  explicit Resume_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : resume_time(_alloc, _init),
    tracking_topic_name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->resume_mode = 0l;
      this->tracking_topic_name = "";
    }
  }

  // field types and members
  using _resume_time_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _resume_time_type resume_time;
  using _resume_mode_type =
    int32_t;
  _resume_mode_type resume_mode;
  using _tracking_topic_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _tracking_topic_name_type tracking_topic_name;

  // setters for named parameter idiom
  Type & set__resume_time(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->resume_time = _arg;
    return *this;
  }
  Type & set__resume_mode(
    const int32_t & _arg)
  {
    this->resume_mode = _arg;
    return *this;
  }
  Type & set__tracking_topic_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->tracking_topic_name = _arg;
    return *this;
  }

  // constant declarations
  static constexpr int32_t RESUME_MODE_NODE_TIME =
    0;
  static constexpr int32_t RESUME_MODE_PUBLISH_TIME =
    1;
  static constexpr int32_t RESUME_MODE_RECEIVE_TIME =
    2;

  // pointer types
  using RawPtr =
    rosbag2_interfaces::srv::Resume_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const rosbag2_interfaces::srv::Resume_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rosbag2_interfaces::srv::Resume_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rosbag2_interfaces::srv::Resume_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rosbag2_interfaces::srv::Resume_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rosbag2_interfaces::srv::Resume_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rosbag2_interfaces::srv::Resume_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rosbag2_interfaces::srv::Resume_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rosbag2_interfaces::srv::Resume_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rosbag2_interfaces::srv::Resume_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rosbag2_interfaces__srv__Resume_Request
    std::shared_ptr<rosbag2_interfaces::srv::Resume_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rosbag2_interfaces__srv__Resume_Request
    std::shared_ptr<rosbag2_interfaces::srv::Resume_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Resume_Request_ & other) const
  {
    if (this->resume_time != other.resume_time) {
      return false;
    }
    if (this->resume_mode != other.resume_mode) {
      return false;
    }
    if (this->tracking_topic_name != other.tracking_topic_name) {
      return false;
    }
    return true;
  }
  bool operator!=(const Resume_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Resume_Request_

// alias to use template instance with default allocator
using Resume_Request =
  rosbag2_interfaces::srv::Resume_Request_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int32_t Resume_Request_<ContainerAllocator>::RESUME_MODE_NODE_TIME;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int32_t Resume_Request_<ContainerAllocator>::RESUME_MODE_PUBLISH_TIME;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int32_t Resume_Request_<ContainerAllocator>::RESUME_MODE_RECEIVE_TIME;
#endif  // __cplusplus < 201703L

}  // namespace srv

}  // namespace rosbag2_interfaces


#ifndef _WIN32
# define DEPRECATED__rosbag2_interfaces__srv__Resume_Response __attribute__((deprecated))
#else
# define DEPRECATED__rosbag2_interfaces__srv__Resume_Response __declspec(deprecated)
#endif

namespace rosbag2_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Resume_Response_
{
  using Type = Resume_Response_<ContainerAllocator>;

  explicit Resume_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->return_code = 0l;
      this->error_string = "";
    }
  }

  explicit Resume_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
  static constexpr int32_t RETURN_CODE_INVALID_RESUME_MODE =
    1;
  static constexpr int32_t RETURN_CODE_INVALID_TRACKING_TOPIC =
    2;
  static constexpr int32_t RETURN_CODE_RESUME_FAILED =
    3;

  // pointer types
  using RawPtr =
    rosbag2_interfaces::srv::Resume_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const rosbag2_interfaces::srv::Resume_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rosbag2_interfaces::srv::Resume_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rosbag2_interfaces::srv::Resume_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rosbag2_interfaces::srv::Resume_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rosbag2_interfaces::srv::Resume_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rosbag2_interfaces::srv::Resume_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rosbag2_interfaces::srv::Resume_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rosbag2_interfaces::srv::Resume_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rosbag2_interfaces::srv::Resume_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rosbag2_interfaces__srv__Resume_Response
    std::shared_ptr<rosbag2_interfaces::srv::Resume_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rosbag2_interfaces__srv__Resume_Response
    std::shared_ptr<rosbag2_interfaces::srv::Resume_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Resume_Response_ & other) const
  {
    if (this->return_code != other.return_code) {
      return false;
    }
    if (this->error_string != other.error_string) {
      return false;
    }
    return true;
  }
  bool operator!=(const Resume_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Resume_Response_

// alias to use template instance with default allocator
using Resume_Response =
  rosbag2_interfaces::srv::Resume_Response_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int32_t Resume_Response_<ContainerAllocator>::RETURN_CODE_SUCCESS;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int32_t Resume_Response_<ContainerAllocator>::RETURN_CODE_INVALID_RESUME_MODE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int32_t Resume_Response_<ContainerAllocator>::RETURN_CODE_INVALID_TRACKING_TOPIC;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int32_t Resume_Response_<ContainerAllocator>::RETURN_CODE_RESUME_FAILED;
#endif  // __cplusplus < 201703L

}  // namespace srv

}  // namespace rosbag2_interfaces


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__rosbag2_interfaces__srv__Resume_Event __attribute__((deprecated))
#else
# define DEPRECATED__rosbag2_interfaces__srv__Resume_Event __declspec(deprecated)
#endif

namespace rosbag2_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Resume_Event_
{
  using Type = Resume_Event_<ContainerAllocator>;

  explicit Resume_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit Resume_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<rosbag2_interfaces::srv::Resume_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<rosbag2_interfaces::srv::Resume_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<rosbag2_interfaces::srv::Resume_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<rosbag2_interfaces::srv::Resume_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<rosbag2_interfaces::srv::Resume_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<rosbag2_interfaces::srv::Resume_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<rosbag2_interfaces::srv::Resume_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<rosbag2_interfaces::srv::Resume_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rosbag2_interfaces::srv::Resume_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const rosbag2_interfaces::srv::Resume_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rosbag2_interfaces::srv::Resume_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rosbag2_interfaces::srv::Resume_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rosbag2_interfaces::srv::Resume_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rosbag2_interfaces::srv::Resume_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rosbag2_interfaces::srv::Resume_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rosbag2_interfaces::srv::Resume_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rosbag2_interfaces::srv::Resume_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rosbag2_interfaces::srv::Resume_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rosbag2_interfaces__srv__Resume_Event
    std::shared_ptr<rosbag2_interfaces::srv::Resume_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rosbag2_interfaces__srv__Resume_Event
    std::shared_ptr<rosbag2_interfaces::srv::Resume_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Resume_Event_ & other) const
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
  bool operator!=(const Resume_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Resume_Event_

// alias to use template instance with default allocator
using Resume_Event =
  rosbag2_interfaces::srv::Resume_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace rosbag2_interfaces

namespace rosbag2_interfaces
{

namespace srv
{

struct Resume
{
  using Request = rosbag2_interfaces::srv::Resume_Request;
  using Response = rosbag2_interfaces::srv::Resume_Response;
  using Event = rosbag2_interfaces::srv::Resume_Event;
};

}  // namespace srv

}  // namespace rosbag2_interfaces

#endif  // ROSBAG2_INTERFACES__SRV__DETAIL__RESUME__STRUCT_HPP_
