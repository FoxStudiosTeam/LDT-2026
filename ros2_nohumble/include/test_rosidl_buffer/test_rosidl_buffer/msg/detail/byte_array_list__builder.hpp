// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from test_rosidl_buffer:msg\ByteArrayList.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "test_rosidl_buffer/msg/byte_array_list.hpp"


#ifndef TEST_ROSIDL_BUFFER__MSG__DETAIL__BYTE_ARRAY_LIST__BUILDER_HPP_
#define TEST_ROSIDL_BUFFER__MSG__DETAIL__BYTE_ARRAY_LIST__BUILDER_HPP_

#include <utility>

#include "test_rosidl_buffer/msg/detail/byte_array_list__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace test_rosidl_buffer
{

namespace msg
{

namespace builder
{

class Init_ByteArrayList_items
{
public:
  Init_ByteArrayList_items()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::test_rosidl_buffer::msg::ByteArrayList items(::test_rosidl_buffer::msg::ByteArrayList::_items_type arg)
  {
    msg_.items = std::move(arg);
    return std::move(msg_);
  }

private:
  ::test_rosidl_buffer::msg::ByteArrayList msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::test_rosidl_buffer::msg::ByteArrayList>()
{
  return test_rosidl_buffer::msg::builder::Init_ByteArrayList_items();
}

}  // namespace test_rosidl_buffer

#endif  // TEST_ROSIDL_BUFFER__MSG__DETAIL__BYTE_ARRAY_LIST__BUILDER_HPP_
