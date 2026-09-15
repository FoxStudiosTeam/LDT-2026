#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "type_description_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__type_description_interfaces__msg__Field() -> *const std::ffi::c_void;
}

#[link(name = "type_description_interfaces__rosidl_generator_c")]
extern "C" {
    fn type_description_interfaces__msg__Field__init(msg: *mut Field) -> bool;
    fn type_description_interfaces__msg__Field__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Field>, size: usize) -> bool;
    fn type_description_interfaces__msg__Field__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Field>);
    fn type_description_interfaces__msg__Field__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Field>, out_seq: *mut rosidl_runtime_rs::Sequence<Field>) -> bool;
}

// Corresponds to type_description_interfaces__msg__Field
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Represents a single field in a type.

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Field {
    /// Name of the field.
    pub name: rosidl_runtime_rs::String,

    /// Type of the field, including details about the type like length, nested name, etc.
    pub type_: super::super::msg::rmw::FieldType,

    /// Literal default value of the field as a string, as it appeared in the original
    /// message description file, whether that be .msg/.srv/.action or .idl.
    pub default_value: rosidl_runtime_rs::String,

}



impl Default for Field {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !type_description_interfaces__msg__Field__init(&mut msg as *mut _) {
        panic!("Call to type_description_interfaces__msg__Field__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Field {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { type_description_interfaces__msg__Field__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { type_description_interfaces__msg__Field__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { type_description_interfaces__msg__Field__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Field {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Field where Self: Sized {
  const TYPE_NAME: &'static str = "type_description_interfaces/msg/Field";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__type_description_interfaces__msg__Field() }
  }
}


#[link(name = "type_description_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__type_description_interfaces__msg__FieldType() -> *const std::ffi::c_void;
}

#[link(name = "type_description_interfaces__rosidl_generator_c")]
extern "C" {
    fn type_description_interfaces__msg__FieldType__init(msg: *mut FieldType) -> bool;
    fn type_description_interfaces__msg__FieldType__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<FieldType>, size: usize) -> bool;
    fn type_description_interfaces__msg__FieldType__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<FieldType>);
    fn type_description_interfaces__msg__FieldType__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<FieldType>, out_seq: *mut rosidl_runtime_rs::Sequence<FieldType>) -> bool;
}

// Corresponds to type_description_interfaces__msg__FieldType
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Represents the type of a field and related meta-data.

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct FieldType {
    /// Identifying number for the type of the field, using one of the above constants.
    pub type_id: u8,

    /// Only used when the type is an array or a bounded sequence.
    /// In the case of an array, this is the fixed capacity of the array.
    /// In the case of a bounded sequence, this is the maximum capacity of the sequence.
    /// In all other cases this field is unused.
    pub capacity: u64,

    /// Only used when the type is a fixed or bounded string/wstring, or a array/sequence of those.
    /// In the case of a fixed string/wstring, it is the fixed length of the string.
    /// In the case of a bounded string/wstring, it is the maximum capacity of the string.
    /// In the case of an array/sequence of fixed string/wstring, it is the fixed length of the strings.
    /// In the case of an array/sequence of bounded string/wstring, it is the maximum capacity of the strings.
    /// It is not currently possible to have different string capacities per element in the array/sequence.
    pub string_capacity: u64,

    /// Only used when the type is a nested type or array/sequence of nested types.
    /// This is limited to 255 characters.
    /// TODO(wjwwood): this 255 character limit was chosen due to this being the limit
    ///   for DDSI-RTPS based middlewares, which is the most commonly used right now.
    ///   We lack a ROS 2 specific limit in our design documents, but we should update
    ///   this and/or link to the design doc when that is available.
    pub nested_type_name: rosidl_runtime_rs::BoundedString<255>,

}

impl FieldType {
    /// A constant for each type supported according to:
    ///   http://design.ros2.org/articles/legacy_interface_definition.html
    /// and:
    ///   http://design.ros2.org/articles/idl_interface_definition.html
    /// Order is loosely coupled to the order of appearance in the IDL 4.2 spec:
    ///  https://www.omg.org/spec/IDL/4.2
    /// Layout of constants across the 0-255 decimal values in the uint8:
    ///
    /// - 000    : Reserved for "not set"
    /// - 001-048: Primitive types, strings, and reserved space for future primitive types
    /// - 049-096: Fixed sized array of primitive and string types
    /// - 097-144: Bounded Sequences of primitive and string types
    /// - 145-192: Unbounded Sequences of primitive and string types
    /// - 193-255: Reserved space for future array/sequence-like types
    pub const FIELD_TYPE_NOT_SET: u8 = 0;

    /// Nested type defined in other .msg/.idl files.
    pub const FIELD_TYPE_NESTED_TYPE: u8 = 1;

    /// Integer Types
    pub const FIELD_TYPE_INT8: u8 = 2;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_UINT8: u8 = 3;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_INT16: u8 = 4;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_UINT16: u8 = 5;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_INT32: u8 = 6;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_UINT32: u8 = 7;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_INT64: u8 = 8;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_UINT64: u8 = 9;

    /// Floating-Point Types
    pub const FIELD_TYPE_FLOAT: u8 = 10;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_DOUBLE: u8 = 11;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_LONG_DOUBLE: u8 = 12;

    /// Char and WChar Types
    pub const FIELD_TYPE_CHAR: u8 = 13;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_WCHAR: u8 = 14;

    /// Boolean Type
    pub const FIELD_TYPE_BOOLEAN: u8 = 15;

    /// Byte/Octet Type
    pub const FIELD_TYPE_BYTE: u8 = 16;

    /// String Types
    pub const FIELD_TYPE_STRING: u8 = 17;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_WSTRING: u8 = 18;

    /// Fixed String Types
    pub const FIELD_TYPE_FIXED_STRING: u8 = 19;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_FIXED_WSTRING: u8 = 20;

    /// Bounded String Types
    pub const FIELD_TYPE_BOUNDED_STRING: u8 = 21;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_BOUNDED_WSTRING: u8 = 22;

    /// Fixed Sized Array Types
    pub const FIELD_TYPE_NESTED_TYPE_ARRAY: u8 = 49;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_INT8_ARRAY: u8 = 50;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_UINT8_ARRAY: u8 = 51;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_INT16_ARRAY: u8 = 52;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_UINT16_ARRAY: u8 = 53;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_INT32_ARRAY: u8 = 54;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_UINT32_ARRAY: u8 = 55;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_INT64_ARRAY: u8 = 56;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_UINT64_ARRAY: u8 = 57;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_FLOAT_ARRAY: u8 = 58;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_DOUBLE_ARRAY: u8 = 59;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_LONG_DOUBLE_ARRAY: u8 = 60;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_CHAR_ARRAY: u8 = 61;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_WCHAR_ARRAY: u8 = 62;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_BOOLEAN_ARRAY: u8 = 63;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_BYTE_ARRAY: u8 = 64;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_STRING_ARRAY: u8 = 65;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_WSTRING_ARRAY: u8 = 66;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_FIXED_STRING_ARRAY: u8 = 67;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_FIXED_WSTRING_ARRAY: u8 = 68;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_BOUNDED_STRING_ARRAY: u8 = 69;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_BOUNDED_WSTRING_ARRAY: u8 = 70;

    /// Bounded Sequence Types
    pub const FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE: u8 = 97;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_INT8_BOUNDED_SEQUENCE: u8 = 98;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_UINT8_BOUNDED_SEQUENCE: u8 = 99;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_INT16_BOUNDED_SEQUENCE: u8 = 100;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_UINT16_BOUNDED_SEQUENCE: u8 = 101;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_INT32_BOUNDED_SEQUENCE: u8 = 102;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_UINT32_BOUNDED_SEQUENCE: u8 = 103;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_INT64_BOUNDED_SEQUENCE: u8 = 104;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_UINT64_BOUNDED_SEQUENCE: u8 = 105;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_FLOAT_BOUNDED_SEQUENCE: u8 = 106;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_DOUBLE_BOUNDED_SEQUENCE: u8 = 107;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_LONG_DOUBLE_BOUNDED_SEQUENCE: u8 = 108;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_CHAR_BOUNDED_SEQUENCE: u8 = 109;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_WCHAR_BOUNDED_SEQUENCE: u8 = 110;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_BOOLEAN_BOUNDED_SEQUENCE: u8 = 111;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_BYTE_BOUNDED_SEQUENCE: u8 = 112;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_STRING_BOUNDED_SEQUENCE: u8 = 113;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_WSTRING_BOUNDED_SEQUENCE: u8 = 114;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_FIXED_STRING_BOUNDED_SEQUENCE: u8 = 115;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_FIXED_WSTRING_BOUNDED_SEQUENCE: u8 = 116;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_BOUNDED_STRING_BOUNDED_SEQUENCE: u8 = 117;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_BOUNDED_WSTRING_BOUNDED_SEQUENCE: u8 = 118;

    /// Unbounded Sequence Types
    pub const FIELD_TYPE_NESTED_TYPE_UNBOUNDED_SEQUENCE: u8 = 145;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_INT8_UNBOUNDED_SEQUENCE: u8 = 146;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_UINT8_UNBOUNDED_SEQUENCE: u8 = 147;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_INT16_UNBOUNDED_SEQUENCE: u8 = 148;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_UINT16_UNBOUNDED_SEQUENCE: u8 = 149;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_INT32_UNBOUNDED_SEQUENCE: u8 = 150;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_UINT32_UNBOUNDED_SEQUENCE: u8 = 151;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_INT64_UNBOUNDED_SEQUENCE: u8 = 152;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_UINT64_UNBOUNDED_SEQUENCE: u8 = 153;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_FLOAT_UNBOUNDED_SEQUENCE: u8 = 154;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_DOUBLE_UNBOUNDED_SEQUENCE: u8 = 155;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_LONG_DOUBLE_UNBOUNDED_SEQUENCE: u8 = 156;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_CHAR_UNBOUNDED_SEQUENCE: u8 = 157;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_WCHAR_UNBOUNDED_SEQUENCE: u8 = 158;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_BOOLEAN_UNBOUNDED_SEQUENCE: u8 = 159;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_BYTE_UNBOUNDED_SEQUENCE: u8 = 160;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_STRING_UNBOUNDED_SEQUENCE: u8 = 161;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_WSTRING_UNBOUNDED_SEQUENCE: u8 = 162;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_FIXED_STRING_UNBOUNDED_SEQUENCE: u8 = 163;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_FIXED_WSTRING_UNBOUNDED_SEQUENCE: u8 = 164;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_BOUNDED_STRING_UNBOUNDED_SEQUENCE: u8 = 165;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_BOUNDED_WSTRING_UNBOUNDED_SEQUENCE: u8 = 166;

}


impl Default for FieldType {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !type_description_interfaces__msg__FieldType__init(&mut msg as *mut _) {
        panic!("Call to type_description_interfaces__msg__FieldType__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for FieldType {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { type_description_interfaces__msg__FieldType__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { type_description_interfaces__msg__FieldType__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { type_description_interfaces__msg__FieldType__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for FieldType {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for FieldType where Self: Sized {
  const TYPE_NAME: &'static str = "type_description_interfaces/msg/FieldType";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__type_description_interfaces__msg__FieldType() }
  }
}


#[link(name = "type_description_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__type_description_interfaces__msg__IndividualTypeDescription() -> *const std::ffi::c_void;
}

#[link(name = "type_description_interfaces__rosidl_generator_c")]
extern "C" {
    fn type_description_interfaces__msg__IndividualTypeDescription__init(msg: *mut IndividualTypeDescription) -> bool;
    fn type_description_interfaces__msg__IndividualTypeDescription__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<IndividualTypeDescription>, size: usize) -> bool;
    fn type_description_interfaces__msg__IndividualTypeDescription__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<IndividualTypeDescription>);
    fn type_description_interfaces__msg__IndividualTypeDescription__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<IndividualTypeDescription>, out_seq: *mut rosidl_runtime_rs::Sequence<IndividualTypeDescription>) -> bool;
}

// Corresponds to type_description_interfaces__msg__IndividualTypeDescription
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Represents a single type, without the types it references, if any.

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct IndividualTypeDescription {
    /// Name of the type.
    /// This is limited to 255 characters.
    /// TODO(wjwwood): this 255 character limit was chosen due to this being the limit
    ///   for DDSI-RTPS based middlewares, which is the most commonly used right now.
    ///   We lack a ROS 2 specific limit in our design documents, but we should update
    ///   this and/or link to the design doc when that is available.
    pub type_name: rosidl_runtime_rs::BoundedString<255>,

    /// Fields of the type.
    pub fields: rosidl_runtime_rs::Sequence<super::super::msg::rmw::Field>,

}



impl Default for IndividualTypeDescription {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !type_description_interfaces__msg__IndividualTypeDescription__init(&mut msg as *mut _) {
        panic!("Call to type_description_interfaces__msg__IndividualTypeDescription__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for IndividualTypeDescription {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { type_description_interfaces__msg__IndividualTypeDescription__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { type_description_interfaces__msg__IndividualTypeDescription__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { type_description_interfaces__msg__IndividualTypeDescription__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for IndividualTypeDescription {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for IndividualTypeDescription where Self: Sized {
  const TYPE_NAME: &'static str = "type_description_interfaces/msg/IndividualTypeDescription";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__type_description_interfaces__msg__IndividualTypeDescription() }
  }
}


#[link(name = "type_description_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__type_description_interfaces__msg__KeyValue() -> *const std::ffi::c_void;
}

#[link(name = "type_description_interfaces__rosidl_generator_c")]
extern "C" {
    fn type_description_interfaces__msg__KeyValue__init(msg: *mut KeyValue) -> bool;
    fn type_description_interfaces__msg__KeyValue__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<KeyValue>, size: usize) -> bool;
    fn type_description_interfaces__msg__KeyValue__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<KeyValue>);
    fn type_description_interfaces__msg__KeyValue__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<KeyValue>, out_seq: *mut rosidl_runtime_rs::Sequence<KeyValue>) -> bool;
}

// Corresponds to type_description_interfaces__msg__KeyValue
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Represents an arbitrary key-value pair for application-specific information.

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct KeyValue {

    // This member is not documented.
    #[allow(missing_docs)]
    pub key: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub value: rosidl_runtime_rs::String,

}



impl Default for KeyValue {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !type_description_interfaces__msg__KeyValue__init(&mut msg as *mut _) {
        panic!("Call to type_description_interfaces__msg__KeyValue__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for KeyValue {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { type_description_interfaces__msg__KeyValue__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { type_description_interfaces__msg__KeyValue__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { type_description_interfaces__msg__KeyValue__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for KeyValue {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for KeyValue where Self: Sized {
  const TYPE_NAME: &'static str = "type_description_interfaces/msg/KeyValue";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__type_description_interfaces__msg__KeyValue() }
  }
}


#[link(name = "type_description_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__type_description_interfaces__msg__TypeDescription() -> *const std::ffi::c_void;
}

#[link(name = "type_description_interfaces__rosidl_generator_c")]
extern "C" {
    fn type_description_interfaces__msg__TypeDescription__init(msg: *mut TypeDescription) -> bool;
    fn type_description_interfaces__msg__TypeDescription__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<TypeDescription>, size: usize) -> bool;
    fn type_description_interfaces__msg__TypeDescription__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<TypeDescription>);
    fn type_description_interfaces__msg__TypeDescription__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<TypeDescription>, out_seq: *mut rosidl_runtime_rs::Sequence<TypeDescription>) -> bool;
}

// Corresponds to type_description_interfaces__msg__TypeDescription
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Represents a complete type description, including the type itself as well as the types it references.

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TypeDescription {
    /// Description of the type.
    pub type_description: super::super::msg::rmw::IndividualTypeDescription,

    /// Descriptions of all referenced types, recursively.
    pub referenced_type_descriptions: rosidl_runtime_rs::Sequence<super::super::msg::rmw::IndividualTypeDescription>,

}



impl Default for TypeDescription {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !type_description_interfaces__msg__TypeDescription__init(&mut msg as *mut _) {
        panic!("Call to type_description_interfaces__msg__TypeDescription__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for TypeDescription {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { type_description_interfaces__msg__TypeDescription__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { type_description_interfaces__msg__TypeDescription__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { type_description_interfaces__msg__TypeDescription__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for TypeDescription {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for TypeDescription where Self: Sized {
  const TYPE_NAME: &'static str = "type_description_interfaces/msg/TypeDescription";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__type_description_interfaces__msg__TypeDescription() }
  }
}


#[link(name = "type_description_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__type_description_interfaces__msg__TypeSource() -> *const std::ffi::c_void;
}

#[link(name = "type_description_interfaces__rosidl_generator_c")]
extern "C" {
    fn type_description_interfaces__msg__TypeSource__init(msg: *mut TypeSource) -> bool;
    fn type_description_interfaces__msg__TypeSource__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<TypeSource>, size: usize) -> bool;
    fn type_description_interfaces__msg__TypeSource__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<TypeSource>);
    fn type_description_interfaces__msg__TypeSource__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<TypeSource>, out_seq: *mut rosidl_runtime_rs::Sequence<TypeSource>) -> bool;
}

// Corresponds to type_description_interfaces__msg__TypeSource
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Represents the original source of a ROS 2 interface definition.

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TypeSource {
    /// ROS interface type name, in PACKAGE/NAMESPACE/TYPENAME format.
    pub type_name: rosidl_runtime_rs::String,

    /// The type of the original source file, typically matching the file extension.
    /// Well-known encodings: "idl", "msg", "srv", "action", "dynamic", "implicit".
    /// "dynamic" specifies a type created programmatically by a user, thus having no source.
    /// "implicit" specifies a type created automatically as a subtype of a
    /// complex type (service or action) - such as the request message for a service.
    /// Implicit types will have no contents, the full source will be available on the parent srv/action.
    pub encoding: rosidl_runtime_rs::String,

    /// Dumped contents of the interface definition source file.
    /// If `encoding` is "dynamic" or "implicit", this field will be empty.
    pub raw_file_contents: rosidl_runtime_rs::String,

}



impl Default for TypeSource {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !type_description_interfaces__msg__TypeSource__init(&mut msg as *mut _) {
        panic!("Call to type_description_interfaces__msg__TypeSource__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for TypeSource {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { type_description_interfaces__msg__TypeSource__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { type_description_interfaces__msg__TypeSource__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { type_description_interfaces__msg__TypeSource__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for TypeSource {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for TypeSource where Self: Sized {
  const TYPE_NAME: &'static str = "type_description_interfaces/msg/TypeSource";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__type_description_interfaces__msg__TypeSource() }
  }
}


