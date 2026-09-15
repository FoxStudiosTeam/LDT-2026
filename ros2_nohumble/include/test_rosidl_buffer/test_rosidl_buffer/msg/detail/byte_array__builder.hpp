// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from test_rosidl_buffer:msg\ByteArray.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "test_rosidl_buffer/msg/byte_array.hpp"


#ifndef TEST_ROSIDL_BUFFER__MSG__DETAIL__BYTE_ARRAY__BUILDER_HPP_
#define TEST_ROSIDL_BUFFER__MSG__DETAIL__BYTE_ARRAY__BUILDER_HPP_

#include <utility>

#include "test_rosidl_buffer/msg/detail/byte_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace test_rosidl_buffer
{

namespace msg
{

namespace builder
{

class Init_ByteArray_data
{
public:
  explicit Init_ByteArray_data(::test_rosidl_buffer::msg::ByteArray & msg)
  : msg_(msg)
  {}
  ::test_rosidl_buffer::msg::ByteArray data(::test_rosidl_buffer::msg::ByteArray::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::test_rosidl_buffer::msg::ByteArray msg_;
};

class Init_ByteArray_seq
{
public:
  Init_ByteArray_seq()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ByteArray_data seq(::test_rosidl_buffer::msg::ByteArray::_seq_type arg)
  {
    msg_.seq = std::move(arg);
    return Init_ByteArray_data(msg_);
  }

private:
  ::test_rosidl_buffer::msg::ByteArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::test_rosidl_buffer::msg::ByteArray>()
{
  return test_rosidl_buffer::msg::builder::Init_ByteArray_seq();
}

}  // namespace test_rosidl_buffer

#endif  // TEST_ROSIDL_BUFFER__MSG__DETAIL__BYTE_ARRAY__BUILDER_HPP_
