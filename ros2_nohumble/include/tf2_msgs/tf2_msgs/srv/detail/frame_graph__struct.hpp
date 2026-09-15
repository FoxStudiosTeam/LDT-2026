// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tf2_msgs:srv\FrameGraph.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tf2_msgs/srv/frame_graph.hpp"


#ifndef TF2_MSGS__SRV__DETAIL__FRAME_GRAPH__STRUCT_HPP_
#define TF2_MSGS__SRV__DETAIL__FRAME_GRAPH__STRUCT_HPP_

#include <cstdint>
#include <memory>
#include <string>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__tf2_msgs__srv__FrameGraph_Request __attribute__((deprecated))
#else
# define DEPRECATED__tf2_msgs__srv__FrameGraph_Request __declspec(deprecated)
#endif

namespace tf2_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct FrameGraph_Request_
{
  using Type = FrameGraph_Request_<ContainerAllocator>;

  explicit FrameGraph_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit FrameGraph_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    tf2_msgs::srv::FrameGraph_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const tf2_msgs::srv::FrameGraph_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tf2_msgs::srv::FrameGraph_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tf2_msgs::srv::FrameGraph_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tf2_msgs::srv::FrameGraph_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tf2_msgs::srv::FrameGraph_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tf2_msgs::srv::FrameGraph_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tf2_msgs::srv::FrameGraph_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tf2_msgs::srv::FrameGraph_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tf2_msgs::srv::FrameGraph_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tf2_msgs__srv__FrameGraph_Request
    std::shared_ptr<tf2_msgs::srv::FrameGraph_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tf2_msgs__srv__FrameGraph_Request
    std::shared_ptr<tf2_msgs::srv::FrameGraph_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FrameGraph_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const FrameGraph_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FrameGraph_Request_

// alias to use template instance with default allocator
using FrameGraph_Request =
  tf2_msgs::srv::FrameGraph_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace tf2_msgs


#ifndef _WIN32
# define DEPRECATED__tf2_msgs__srv__FrameGraph_Response __attribute__((deprecated))
#else
# define DEPRECATED__tf2_msgs__srv__FrameGraph_Response __declspec(deprecated)
#endif

namespace tf2_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct FrameGraph_Response_
{
  using Type = FrameGraph_Response_<ContainerAllocator>;

  explicit FrameGraph_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->frame_yaml = "";
    }
  }

  explicit FrameGraph_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : frame_yaml(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->frame_yaml = "";
    }
  }

  // field types and members
  using _frame_yaml_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _frame_yaml_type frame_yaml;

  // setters for named parameter idiom
  Type & set__frame_yaml(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->frame_yaml = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tf2_msgs::srv::FrameGraph_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const tf2_msgs::srv::FrameGraph_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tf2_msgs::srv::FrameGraph_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tf2_msgs::srv::FrameGraph_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tf2_msgs::srv::FrameGraph_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tf2_msgs::srv::FrameGraph_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tf2_msgs::srv::FrameGraph_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tf2_msgs::srv::FrameGraph_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tf2_msgs::srv::FrameGraph_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tf2_msgs::srv::FrameGraph_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tf2_msgs__srv__FrameGraph_Response
    std::shared_ptr<tf2_msgs::srv::FrameGraph_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tf2_msgs__srv__FrameGraph_Response
    std::shared_ptr<tf2_msgs::srv::FrameGraph_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FrameGraph_Response_ & other) const
  {
    if (this->frame_yaml != other.frame_yaml) {
      return false;
    }
    return true;
  }
  bool operator!=(const FrameGraph_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FrameGraph_Response_

// alias to use template instance with default allocator
using FrameGraph_Response =
  tf2_msgs::srv::FrameGraph_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace tf2_msgs


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__tf2_msgs__srv__FrameGraph_Event __attribute__((deprecated))
#else
# define DEPRECATED__tf2_msgs__srv__FrameGraph_Event __declspec(deprecated)
#endif

namespace tf2_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct FrameGraph_Event_
{
  using Type = FrameGraph_Event_<ContainerAllocator>;

  explicit FrameGraph_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit FrameGraph_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<tf2_msgs::srv::FrameGraph_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tf2_msgs::srv::FrameGraph_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<tf2_msgs::srv::FrameGraph_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tf2_msgs::srv::FrameGraph_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<tf2_msgs::srv::FrameGraph_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tf2_msgs::srv::FrameGraph_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<tf2_msgs::srv::FrameGraph_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tf2_msgs::srv::FrameGraph_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tf2_msgs::srv::FrameGraph_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const tf2_msgs::srv::FrameGraph_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tf2_msgs::srv::FrameGraph_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tf2_msgs::srv::FrameGraph_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tf2_msgs::srv::FrameGraph_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tf2_msgs::srv::FrameGraph_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tf2_msgs::srv::FrameGraph_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tf2_msgs::srv::FrameGraph_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tf2_msgs::srv::FrameGraph_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tf2_msgs::srv::FrameGraph_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tf2_msgs__srv__FrameGraph_Event
    std::shared_ptr<tf2_msgs::srv::FrameGraph_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tf2_msgs__srv__FrameGraph_Event
    std::shared_ptr<tf2_msgs::srv::FrameGraph_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FrameGraph_Event_ & other) const
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
  bool operator!=(const FrameGraph_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FrameGraph_Event_

// alias to use template instance with default allocator
using FrameGraph_Event =
  tf2_msgs::srv::FrameGraph_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace tf2_msgs

namespace tf2_msgs
{

namespace srv
{

struct FrameGraph
{
  using Request = tf2_msgs::srv::FrameGraph_Request;
  using Response = tf2_msgs::srv::FrameGraph_Response;
  using Event = tf2_msgs::srv::FrameGraph_Event;
};

}  // namespace srv

}  // namespace tf2_msgs

#endif  // TF2_MSGS__SRV__DETAIL__FRAME_GRAPH__STRUCT_HPP_
