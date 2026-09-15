// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from resource_retriever_interfaces:srv\GetResource.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "resource_retriever_interfaces/srv/get_resource.hpp"


#ifndef RESOURCE_RETRIEVER_INTERFACES__SRV__DETAIL__GET_RESOURCE__BUILDER_HPP_
#define RESOURCE_RETRIEVER_INTERFACES__SRV__DETAIL__GET_RESOURCE__BUILDER_HPP_

#include <utility>

#include "resource_retriever_interfaces/srv/detail/get_resource__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace resource_retriever_interfaces
{

namespace srv
{

namespace builder
{

class Init_GetResource_Request_etag
{
public:
  explicit Init_GetResource_Request_etag(::resource_retriever_interfaces::srv::GetResource_Request & msg)
  : msg_(msg)
  {}
  ::resource_retriever_interfaces::srv::GetResource_Request etag(::resource_retriever_interfaces::srv::GetResource_Request::_etag_type arg)
  {
    msg_.etag = std::move(arg);
    return std::move(msg_);
  }

private:
  ::resource_retriever_interfaces::srv::GetResource_Request msg_;
};

class Init_GetResource_Request_path
{
public:
  Init_GetResource_Request_path()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetResource_Request_etag path(::resource_retriever_interfaces::srv::GetResource_Request::_path_type arg)
  {
    msg_.path = std::move(arg);
    return Init_GetResource_Request_etag(msg_);
  }

private:
  ::resource_retriever_interfaces::srv::GetResource_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::resource_retriever_interfaces::srv::GetResource_Request>()
{
  return resource_retriever_interfaces::srv::builder::Init_GetResource_Request_path();
}

}  // namespace resource_retriever_interfaces


namespace resource_retriever_interfaces
{

namespace srv
{

namespace builder
{

class Init_GetResource_Response_body
{
public:
  explicit Init_GetResource_Response_body(::resource_retriever_interfaces::srv::GetResource_Response & msg)
  : msg_(msg)
  {}
  ::resource_retriever_interfaces::srv::GetResource_Response body(::resource_retriever_interfaces::srv::GetResource_Response::_body_type arg)
  {
    msg_.body = std::move(arg);
    return std::move(msg_);
  }

private:
  ::resource_retriever_interfaces::srv::GetResource_Response msg_;
};

class Init_GetResource_Response_etag
{
public:
  explicit Init_GetResource_Response_etag(::resource_retriever_interfaces::srv::GetResource_Response & msg)
  : msg_(msg)
  {}
  Init_GetResource_Response_body etag(::resource_retriever_interfaces::srv::GetResource_Response::_etag_type arg)
  {
    msg_.etag = std::move(arg);
    return Init_GetResource_Response_body(msg_);
  }

private:
  ::resource_retriever_interfaces::srv::GetResource_Response msg_;
};

class Init_GetResource_Response_expanded_path
{
public:
  explicit Init_GetResource_Response_expanded_path(::resource_retriever_interfaces::srv::GetResource_Response & msg)
  : msg_(msg)
  {}
  Init_GetResource_Response_etag expanded_path(::resource_retriever_interfaces::srv::GetResource_Response::_expanded_path_type arg)
  {
    msg_.expanded_path = std::move(arg);
    return Init_GetResource_Response_etag(msg_);
  }

private:
  ::resource_retriever_interfaces::srv::GetResource_Response msg_;
};

class Init_GetResource_Response_error_reason
{
public:
  explicit Init_GetResource_Response_error_reason(::resource_retriever_interfaces::srv::GetResource_Response & msg)
  : msg_(msg)
  {}
  Init_GetResource_Response_expanded_path error_reason(::resource_retriever_interfaces::srv::GetResource_Response::_error_reason_type arg)
  {
    msg_.error_reason = std::move(arg);
    return Init_GetResource_Response_expanded_path(msg_);
  }

private:
  ::resource_retriever_interfaces::srv::GetResource_Response msg_;
};

class Init_GetResource_Response_status_code
{
public:
  Init_GetResource_Response_status_code()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetResource_Response_error_reason status_code(::resource_retriever_interfaces::srv::GetResource_Response::_status_code_type arg)
  {
    msg_.status_code = std::move(arg);
    return Init_GetResource_Response_error_reason(msg_);
  }

private:
  ::resource_retriever_interfaces::srv::GetResource_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::resource_retriever_interfaces::srv::GetResource_Response>()
{
  return resource_retriever_interfaces::srv::builder::Init_GetResource_Response_status_code();
}

}  // namespace resource_retriever_interfaces


namespace resource_retriever_interfaces
{

namespace srv
{

namespace builder
{

class Init_GetResource_Event_response
{
public:
  explicit Init_GetResource_Event_response(::resource_retriever_interfaces::srv::GetResource_Event & msg)
  : msg_(msg)
  {}
  ::resource_retriever_interfaces::srv::GetResource_Event response(::resource_retriever_interfaces::srv::GetResource_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::resource_retriever_interfaces::srv::GetResource_Event msg_;
};

class Init_GetResource_Event_request
{
public:
  explicit Init_GetResource_Event_request(::resource_retriever_interfaces::srv::GetResource_Event & msg)
  : msg_(msg)
  {}
  Init_GetResource_Event_response request(::resource_retriever_interfaces::srv::GetResource_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_GetResource_Event_response(msg_);
  }

private:
  ::resource_retriever_interfaces::srv::GetResource_Event msg_;
};

class Init_GetResource_Event_info
{
public:
  Init_GetResource_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetResource_Event_request info(::resource_retriever_interfaces::srv::GetResource_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_GetResource_Event_request(msg_);
  }

private:
  ::resource_retriever_interfaces::srv::GetResource_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::resource_retriever_interfaces::srv::GetResource_Event>()
{
  return resource_retriever_interfaces::srv::builder::Init_GetResource_Event_info();
}

}  // namespace resource_retriever_interfaces

#endif  // RESOURCE_RETRIEVER_INTERFACES__SRV__DETAIL__GET_RESOURCE__BUILDER_HPP_
