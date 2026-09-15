// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from test_rosidl_buffer:msg\TestBufferDescriptor.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "test_rosidl_buffer/msg/test_buffer_descriptor.hpp"


#ifndef TEST_ROSIDL_BUFFER__MSG__DETAIL__TEST_BUFFER_DESCRIPTOR__BUILDER_HPP_
#define TEST_ROSIDL_BUFFER__MSG__DETAIL__TEST_BUFFER_DESCRIPTOR__BUILDER_HPP_

#include <utility>

#include "test_rosidl_buffer/msg/detail/test_buffer_descriptor__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace test_rosidl_buffer
{

namespace msg
{

namespace builder
{

class Init_TestBufferDescriptor_data
{
public:
  explicit Init_TestBufferDescriptor_data(::test_rosidl_buffer::msg::TestBufferDescriptor & msg)
  : msg_(msg)
  {}
  ::test_rosidl_buffer::msg::TestBufferDescriptor data(::test_rosidl_buffer::msg::TestBufferDescriptor::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::test_rosidl_buffer::msg::TestBufferDescriptor msg_;
};

class Init_TestBufferDescriptor_data_hash
{
public:
  explicit Init_TestBufferDescriptor_data_hash(::test_rosidl_buffer::msg::TestBufferDescriptor & msg)
  : msg_(msg)
  {}
  Init_TestBufferDescriptor_data data_hash(::test_rosidl_buffer::msg::TestBufferDescriptor::_data_hash_type arg)
  {
    msg_.data_hash = std::move(arg);
    return Init_TestBufferDescriptor_data(msg_);
  }

private:
  ::test_rosidl_buffer::msg::TestBufferDescriptor msg_;
};

class Init_TestBufferDescriptor_size
{
public:
  Init_TestBufferDescriptor_size()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TestBufferDescriptor_data_hash size(::test_rosidl_buffer::msg::TestBufferDescriptor::_size_type arg)
  {
    msg_.size = std::move(arg);
    return Init_TestBufferDescriptor_data_hash(msg_);
  }

private:
  ::test_rosidl_buffer::msg::TestBufferDescriptor msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::test_rosidl_buffer::msg::TestBufferDescriptor>()
{
  return test_rosidl_buffer::msg::builder::Init_TestBufferDescriptor_size();
}

}  // namespace test_rosidl_buffer

#endif  // TEST_ROSIDL_BUFFER__MSG__DETAIL__TEST_BUFFER_DESCRIPTOR__BUILDER_HPP_
