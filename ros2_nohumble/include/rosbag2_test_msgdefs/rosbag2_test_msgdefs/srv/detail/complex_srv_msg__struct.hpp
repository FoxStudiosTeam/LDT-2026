// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rosbag2_test_msgdefs:srv\ComplexSrvMsg.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosbag2_test_msgdefs/srv/complex_srv_msg.hpp"


#ifndef ROSBAG2_TEST_MSGDEFS__SRV__DETAIL__COMPLEX_SRV_MSG__STRUCT_HPP_
#define ROSBAG2_TEST_MSGDEFS__SRV__DETAIL__COMPLEX_SRV_MSG__STRUCT_HPP_

#include <cstdint>
#include <memory>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'req'
#include "rosbag2_test_msgdefs/msg/detail/basic_msg__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__rosbag2_test_msgdefs__srv__ComplexSrvMsg_Request __attribute__((deprecated))
#else
# define DEPRECATED__rosbag2_test_msgdefs__srv__ComplexSrvMsg_Request __declspec(deprecated)
#endif

namespace rosbag2_test_msgdefs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ComplexSrvMsg_Request_
{
  using Type = ComplexSrvMsg_Request_<ContainerAllocator>;

  explicit ComplexSrvMsg_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : req(_init)
  {
    (void)_init;
  }

  explicit ComplexSrvMsg_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : req(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _req_type =
    rosbag2_test_msgdefs::msg::BasicMsg_<ContainerAllocator>;
  _req_type req;

  // setters for named parameter idiom
  Type & set__req(
    const rosbag2_test_msgdefs::msg::BasicMsg_<ContainerAllocator> & _arg)
  {
    this->req = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rosbag2_test_msgdefs::srv::ComplexSrvMsg_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const rosbag2_test_msgdefs::srv::ComplexSrvMsg_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rosbag2_test_msgdefs::srv::ComplexSrvMsg_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rosbag2_test_msgdefs::srv::ComplexSrvMsg_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rosbag2_test_msgdefs::srv::ComplexSrvMsg_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rosbag2_test_msgdefs::srv::ComplexSrvMsg_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rosbag2_test_msgdefs::srv::ComplexSrvMsg_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rosbag2_test_msgdefs::srv::ComplexSrvMsg_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rosbag2_test_msgdefs::srv::ComplexSrvMsg_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rosbag2_test_msgdefs::srv::ComplexSrvMsg_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rosbag2_test_msgdefs__srv__ComplexSrvMsg_Request
    std::shared_ptr<rosbag2_test_msgdefs::srv::ComplexSrvMsg_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rosbag2_test_msgdefs__srv__ComplexSrvMsg_Request
    std::shared_ptr<rosbag2_test_msgdefs::srv::ComplexSrvMsg_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ComplexSrvMsg_Request_ & other) const
  {
    if (this->req != other.req) {
      return false;
    }
    return true;
  }
  bool operator!=(const ComplexSrvMsg_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ComplexSrvMsg_Request_

// alias to use template instance with default allocator
using ComplexSrvMsg_Request =
  rosbag2_test_msgdefs::srv::ComplexSrvMsg_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace rosbag2_test_msgdefs


// Include directives for member types
// Member 'resp'
// already included above
// #include "rosbag2_test_msgdefs/msg/detail/basic_msg__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__rosbag2_test_msgdefs__srv__ComplexSrvMsg_Response __attribute__((deprecated))
#else
# define DEPRECATED__rosbag2_test_msgdefs__srv__ComplexSrvMsg_Response __declspec(deprecated)
#endif

namespace rosbag2_test_msgdefs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ComplexSrvMsg_Response_
{
  using Type = ComplexSrvMsg_Response_<ContainerAllocator>;

  explicit ComplexSrvMsg_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : resp(_init)
  {
    (void)_init;
  }

  explicit ComplexSrvMsg_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : resp(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _resp_type =
    rosbag2_test_msgdefs::msg::BasicMsg_<ContainerAllocator>;
  _resp_type resp;

  // setters for named parameter idiom
  Type & set__resp(
    const rosbag2_test_msgdefs::msg::BasicMsg_<ContainerAllocator> & _arg)
  {
    this->resp = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rosbag2_test_msgdefs::srv::ComplexSrvMsg_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const rosbag2_test_msgdefs::srv::ComplexSrvMsg_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rosbag2_test_msgdefs::srv::ComplexSrvMsg_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rosbag2_test_msgdefs::srv::ComplexSrvMsg_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rosbag2_test_msgdefs::srv::ComplexSrvMsg_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rosbag2_test_msgdefs::srv::ComplexSrvMsg_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rosbag2_test_msgdefs::srv::ComplexSrvMsg_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rosbag2_test_msgdefs::srv::ComplexSrvMsg_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rosbag2_test_msgdefs::srv::ComplexSrvMsg_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rosbag2_test_msgdefs::srv::ComplexSrvMsg_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rosbag2_test_msgdefs__srv__ComplexSrvMsg_Response
    std::shared_ptr<rosbag2_test_msgdefs::srv::ComplexSrvMsg_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rosbag2_test_msgdefs__srv__ComplexSrvMsg_Response
    std::shared_ptr<rosbag2_test_msgdefs::srv::ComplexSrvMsg_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ComplexSrvMsg_Response_ & other) const
  {
    if (this->resp != other.resp) {
      return false;
    }
    return true;
  }
  bool operator!=(const ComplexSrvMsg_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ComplexSrvMsg_Response_

// alias to use template instance with default allocator
using ComplexSrvMsg_Response =
  rosbag2_test_msgdefs::srv::ComplexSrvMsg_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace rosbag2_test_msgdefs


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__rosbag2_test_msgdefs__srv__ComplexSrvMsg_Event __attribute__((deprecated))
#else
# define DEPRECATED__rosbag2_test_msgdefs__srv__ComplexSrvMsg_Event __declspec(deprecated)
#endif

namespace rosbag2_test_msgdefs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ComplexSrvMsg_Event_
{
  using Type = ComplexSrvMsg_Event_<ContainerAllocator>;

  explicit ComplexSrvMsg_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit ComplexSrvMsg_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<rosbag2_test_msgdefs::srv::ComplexSrvMsg_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<rosbag2_test_msgdefs::srv::ComplexSrvMsg_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<rosbag2_test_msgdefs::srv::ComplexSrvMsg_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<rosbag2_test_msgdefs::srv::ComplexSrvMsg_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<rosbag2_test_msgdefs::srv::ComplexSrvMsg_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<rosbag2_test_msgdefs::srv::ComplexSrvMsg_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<rosbag2_test_msgdefs::srv::ComplexSrvMsg_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<rosbag2_test_msgdefs::srv::ComplexSrvMsg_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rosbag2_test_msgdefs::srv::ComplexSrvMsg_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const rosbag2_test_msgdefs::srv::ComplexSrvMsg_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rosbag2_test_msgdefs::srv::ComplexSrvMsg_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rosbag2_test_msgdefs::srv::ComplexSrvMsg_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rosbag2_test_msgdefs::srv::ComplexSrvMsg_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rosbag2_test_msgdefs::srv::ComplexSrvMsg_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rosbag2_test_msgdefs::srv::ComplexSrvMsg_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rosbag2_test_msgdefs::srv::ComplexSrvMsg_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rosbag2_test_msgdefs::srv::ComplexSrvMsg_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rosbag2_test_msgdefs::srv::ComplexSrvMsg_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rosbag2_test_msgdefs__srv__ComplexSrvMsg_Event
    std::shared_ptr<rosbag2_test_msgdefs::srv::ComplexSrvMsg_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rosbag2_test_msgdefs__srv__ComplexSrvMsg_Event
    std::shared_ptr<rosbag2_test_msgdefs::srv::ComplexSrvMsg_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ComplexSrvMsg_Event_ & other) const
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
  bool operator!=(const ComplexSrvMsg_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ComplexSrvMsg_Event_

// alias to use template instance with default allocator
using ComplexSrvMsg_Event =
  rosbag2_test_msgdefs::srv::ComplexSrvMsg_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace rosbag2_test_msgdefs

namespace rosbag2_test_msgdefs
{

namespace srv
{

struct ComplexSrvMsg
{
  using Request = rosbag2_test_msgdefs::srv::ComplexSrvMsg_Request;
  using Response = rosbag2_test_msgdefs::srv::ComplexSrvMsg_Response;
  using Event = rosbag2_test_msgdefs::srv::ComplexSrvMsg_Event;
};

}  // namespace srv

}  // namespace rosbag2_test_msgdefs

#endif  // ROSBAG2_TEST_MSGDEFS__SRV__DETAIL__COMPLEX_SRV_MSG__STRUCT_HPP_
