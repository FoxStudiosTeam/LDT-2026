// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rosbag2_interfaces:srv\Record.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosbag2_interfaces/srv/record.hpp"


#ifndef ROSBAG2_INTERFACES__SRV__DETAIL__RECORD__BUILDER_HPP_
#define ROSBAG2_INTERFACES__SRV__DETAIL__RECORD__BUILDER_HPP_

#include <utility>

#include "rosbag2_interfaces/srv/detail/record__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rosbag2_interfaces
{

namespace srv
{

namespace builder
{

class Init_Record_Request_start_time
{
public:
  explicit Init_Record_Request_start_time(::rosbag2_interfaces::srv::Record_Request & msg)
  : msg_(msg)
  {}
  ::rosbag2_interfaces::srv::Record_Request start_time(::rosbag2_interfaces::srv::Record_Request::_start_time_type arg)
  {
    msg_.start_time = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rosbag2_interfaces::srv::Record_Request msg_;
};

class Init_Record_Request_uri
{
public:
  Init_Record_Request_uri()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Record_Request_start_time uri(::rosbag2_interfaces::srv::Record_Request::_uri_type arg)
  {
    msg_.uri = std::move(arg);
    return Init_Record_Request_start_time(msg_);
  }

private:
  ::rosbag2_interfaces::srv::Record_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rosbag2_interfaces::srv::Record_Request>()
{
  return rosbag2_interfaces::srv::builder::Init_Record_Request_uri();
}

}  // namespace rosbag2_interfaces


namespace rosbag2_interfaces
{

namespace srv
{

namespace builder
{

class Init_Record_Response_error_string
{
public:
  explicit Init_Record_Response_error_string(::rosbag2_interfaces::srv::Record_Response & msg)
  : msg_(msg)
  {}
  ::rosbag2_interfaces::srv::Record_Response error_string(::rosbag2_interfaces::srv::Record_Response::_error_string_type arg)
  {
    msg_.error_string = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rosbag2_interfaces::srv::Record_Response msg_;
};

class Init_Record_Response_return_code
{
public:
  Init_Record_Response_return_code()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Record_Response_error_string return_code(::rosbag2_interfaces::srv::Record_Response::_return_code_type arg)
  {
    msg_.return_code = std::move(arg);
    return Init_Record_Response_error_string(msg_);
  }

private:
  ::rosbag2_interfaces::srv::Record_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rosbag2_interfaces::srv::Record_Response>()
{
  return rosbag2_interfaces::srv::builder::Init_Record_Response_return_code();
}

}  // namespace rosbag2_interfaces


namespace rosbag2_interfaces
{

namespace srv
{

namespace builder
{

class Init_Record_Event_response
{
public:
  explicit Init_Record_Event_response(::rosbag2_interfaces::srv::Record_Event & msg)
  : msg_(msg)
  {}
  ::rosbag2_interfaces::srv::Record_Event response(::rosbag2_interfaces::srv::Record_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rosbag2_interfaces::srv::Record_Event msg_;
};

class Init_Record_Event_request
{
public:
  explicit Init_Record_Event_request(::rosbag2_interfaces::srv::Record_Event & msg)
  : msg_(msg)
  {}
  Init_Record_Event_response request(::rosbag2_interfaces::srv::Record_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_Record_Event_response(msg_);
  }

private:
  ::rosbag2_interfaces::srv::Record_Event msg_;
};

class Init_Record_Event_info
{
public:
  Init_Record_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Record_Event_request info(::rosbag2_interfaces::srv::Record_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_Record_Event_request(msg_);
  }

private:
  ::rosbag2_interfaces::srv::Record_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rosbag2_interfaces::srv::Record_Event>()
{
  return rosbag2_interfaces::srv::builder::Init_Record_Event_info();
}

}  // namespace rosbag2_interfaces

#endif  // ROSBAG2_INTERFACES__SRV__DETAIL__RECORD__BUILDER_HPP_
