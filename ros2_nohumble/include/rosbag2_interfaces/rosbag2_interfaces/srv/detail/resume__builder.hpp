// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rosbag2_interfaces:srv\Resume.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosbag2_interfaces/srv/resume.hpp"


#ifndef ROSBAG2_INTERFACES__SRV__DETAIL__RESUME__BUILDER_HPP_
#define ROSBAG2_INTERFACES__SRV__DETAIL__RESUME__BUILDER_HPP_

#include <utility>

#include "rosbag2_interfaces/srv/detail/resume__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rosbag2_interfaces
{

namespace srv
{

namespace builder
{

class Init_Resume_Request_tracking_topic_name
{
public:
  explicit Init_Resume_Request_tracking_topic_name(::rosbag2_interfaces::srv::Resume_Request & msg)
  : msg_(msg)
  {}
  ::rosbag2_interfaces::srv::Resume_Request tracking_topic_name(::rosbag2_interfaces::srv::Resume_Request::_tracking_topic_name_type arg)
  {
    msg_.tracking_topic_name = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rosbag2_interfaces::srv::Resume_Request msg_;
};

class Init_Resume_Request_resume_mode
{
public:
  explicit Init_Resume_Request_resume_mode(::rosbag2_interfaces::srv::Resume_Request & msg)
  : msg_(msg)
  {}
  Init_Resume_Request_tracking_topic_name resume_mode(::rosbag2_interfaces::srv::Resume_Request::_resume_mode_type arg)
  {
    msg_.resume_mode = std::move(arg);
    return Init_Resume_Request_tracking_topic_name(msg_);
  }

private:
  ::rosbag2_interfaces::srv::Resume_Request msg_;
};

class Init_Resume_Request_resume_time
{
public:
  Init_Resume_Request_resume_time()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Resume_Request_resume_mode resume_time(::rosbag2_interfaces::srv::Resume_Request::_resume_time_type arg)
  {
    msg_.resume_time = std::move(arg);
    return Init_Resume_Request_resume_mode(msg_);
  }

private:
  ::rosbag2_interfaces::srv::Resume_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rosbag2_interfaces::srv::Resume_Request>()
{
  return rosbag2_interfaces::srv::builder::Init_Resume_Request_resume_time();
}

}  // namespace rosbag2_interfaces


namespace rosbag2_interfaces
{

namespace srv
{

namespace builder
{

class Init_Resume_Response_error_string
{
public:
  explicit Init_Resume_Response_error_string(::rosbag2_interfaces::srv::Resume_Response & msg)
  : msg_(msg)
  {}
  ::rosbag2_interfaces::srv::Resume_Response error_string(::rosbag2_interfaces::srv::Resume_Response::_error_string_type arg)
  {
    msg_.error_string = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rosbag2_interfaces::srv::Resume_Response msg_;
};

class Init_Resume_Response_return_code
{
public:
  Init_Resume_Response_return_code()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Resume_Response_error_string return_code(::rosbag2_interfaces::srv::Resume_Response::_return_code_type arg)
  {
    msg_.return_code = std::move(arg);
    return Init_Resume_Response_error_string(msg_);
  }

private:
  ::rosbag2_interfaces::srv::Resume_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rosbag2_interfaces::srv::Resume_Response>()
{
  return rosbag2_interfaces::srv::builder::Init_Resume_Response_return_code();
}

}  // namespace rosbag2_interfaces


namespace rosbag2_interfaces
{

namespace srv
{

namespace builder
{

class Init_Resume_Event_response
{
public:
  explicit Init_Resume_Event_response(::rosbag2_interfaces::srv::Resume_Event & msg)
  : msg_(msg)
  {}
  ::rosbag2_interfaces::srv::Resume_Event response(::rosbag2_interfaces::srv::Resume_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rosbag2_interfaces::srv::Resume_Event msg_;
};

class Init_Resume_Event_request
{
public:
  explicit Init_Resume_Event_request(::rosbag2_interfaces::srv::Resume_Event & msg)
  : msg_(msg)
  {}
  Init_Resume_Event_response request(::rosbag2_interfaces::srv::Resume_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_Resume_Event_response(msg_);
  }

private:
  ::rosbag2_interfaces::srv::Resume_Event msg_;
};

class Init_Resume_Event_info
{
public:
  Init_Resume_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Resume_Event_request info(::rosbag2_interfaces::srv::Resume_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_Resume_Event_request(msg_);
  }

private:
  ::rosbag2_interfaces::srv::Resume_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rosbag2_interfaces::srv::Resume_Event>()
{
  return rosbag2_interfaces::srv::builder::Init_Resume_Event_info();
}

}  // namespace rosbag2_interfaces

#endif  // ROSBAG2_INTERFACES__SRV__DETAIL__RESUME__BUILDER_HPP_
