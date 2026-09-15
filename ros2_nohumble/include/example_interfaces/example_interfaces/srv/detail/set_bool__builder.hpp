// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from example_interfaces:srv\SetBool.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "example_interfaces/srv/set_bool.hpp"


#ifndef EXAMPLE_INTERFACES__SRV__DETAIL__SET_BOOL__BUILDER_HPP_
#define EXAMPLE_INTERFACES__SRV__DETAIL__SET_BOOL__BUILDER_HPP_

#include <utility>

#include "example_interfaces/srv/detail/set_bool__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace example_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetBool_Request_data
{
public:
  Init_SetBool_Request_data()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::example_interfaces::srv::SetBool_Request data(::example_interfaces::srv::SetBool_Request::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::example_interfaces::srv::SetBool_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::example_interfaces::srv::SetBool_Request>()
{
  return example_interfaces::srv::builder::Init_SetBool_Request_data();
}

}  // namespace example_interfaces


namespace example_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetBool_Response_message
{
public:
  explicit Init_SetBool_Response_message(::example_interfaces::srv::SetBool_Response & msg)
  : msg_(msg)
  {}
  ::example_interfaces::srv::SetBool_Response message(::example_interfaces::srv::SetBool_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::example_interfaces::srv::SetBool_Response msg_;
};

class Init_SetBool_Response_success
{
public:
  Init_SetBool_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetBool_Response_message success(::example_interfaces::srv::SetBool_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_SetBool_Response_message(msg_);
  }

private:
  ::example_interfaces::srv::SetBool_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::example_interfaces::srv::SetBool_Response>()
{
  return example_interfaces::srv::builder::Init_SetBool_Response_success();
}

}  // namespace example_interfaces


namespace example_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetBool_Event_response
{
public:
  explicit Init_SetBool_Event_response(::example_interfaces::srv::SetBool_Event & msg)
  : msg_(msg)
  {}
  ::example_interfaces::srv::SetBool_Event response(::example_interfaces::srv::SetBool_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::example_interfaces::srv::SetBool_Event msg_;
};

class Init_SetBool_Event_request
{
public:
  explicit Init_SetBool_Event_request(::example_interfaces::srv::SetBool_Event & msg)
  : msg_(msg)
  {}
  Init_SetBool_Event_response request(::example_interfaces::srv::SetBool_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_SetBool_Event_response(msg_);
  }

private:
  ::example_interfaces::srv::SetBool_Event msg_;
};

class Init_SetBool_Event_info
{
public:
  Init_SetBool_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetBool_Event_request info(::example_interfaces::srv::SetBool_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_SetBool_Event_request(msg_);
  }

private:
  ::example_interfaces::srv::SetBool_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::example_interfaces::srv::SetBool_Event>()
{
  return example_interfaces::srv::builder::Init_SetBool_Event_info();
}

}  // namespace example_interfaces

#endif  // EXAMPLE_INTERFACES__SRV__DETAIL__SET_BOOL__BUILDER_HPP_
