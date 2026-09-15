#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to test_msgs__msg__KeyedLong

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct KeyedLong {

    // This member is not documented.
    #[allow(missing_docs)]
    pub key: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub value: i32,

}



impl Default for KeyedLong {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::KeyedLong::default())
  }
}

impl rosidl_runtime_rs::Message for KeyedLong {
  type RmwMsg = super::msg::rmw::KeyedLong;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        key: msg.key,
        value: msg.value,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      key: msg.key,
      value: msg.value,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      key: msg.key,
      value: msg.value,
    }
  }
}


// Corresponds to test_msgs__msg__KeyedString

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct KeyedString {

    // This member is not documented.
    #[allow(missing_docs)]
    pub key: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub value: std::string::String,

}



impl Default for KeyedString {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::KeyedString::default())
  }
}

impl rosidl_runtime_rs::Message for KeyedString {
  type RmwMsg = super::msg::rmw::KeyedString;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        key: msg.key.as_str().into(),
        value: msg.value.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        key: msg.key.as_str().into(),
        value: msg.value.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      key: msg.key.to_string(),
      value: msg.value.to_string(),
    }
  }
}


// Corresponds to test_msgs__msg__NonKeyedWithNestedKey

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct NonKeyedWithNestedKey {

    // This member is not documented.
    #[allow(missing_docs)]
    pub nested_data: super::msg::KeyedString,


    // This member is not documented.
    #[allow(missing_docs)]
    pub some_int: i32,

}



impl Default for NonKeyedWithNestedKey {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::NonKeyedWithNestedKey::default())
  }
}

impl rosidl_runtime_rs::Message for NonKeyedWithNestedKey {
  type RmwMsg = super::msg::rmw::NonKeyedWithNestedKey;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        nested_data: super::msg::KeyedString::into_rmw_message(std::borrow::Cow::Owned(msg.nested_data)).into_owned(),
        some_int: msg.some_int,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        nested_data: super::msg::KeyedString::into_rmw_message(std::borrow::Cow::Borrowed(&msg.nested_data)).into_owned(),
      some_int: msg.some_int,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      nested_data: super::msg::KeyedString::from_rmw_message(msg.nested_data),
      some_int: msg.some_int,
    }
  }
}


// Corresponds to test_msgs__msg__ComplexNestedKey

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ComplexNestedKey {

    // This member is not documented.
    #[allow(missing_docs)]
    pub uint32_key: u32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub nested_keys: super::msg::NonKeyedWithNestedKey,


    // This member is not documented.
    #[allow(missing_docs)]
    pub float64_value: f64,

}



impl Default for ComplexNestedKey {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::ComplexNestedKey::default())
  }
}

impl rosidl_runtime_rs::Message for ComplexNestedKey {
  type RmwMsg = super::msg::rmw::ComplexNestedKey;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        uint32_key: msg.uint32_key,
        nested_keys: super::msg::NonKeyedWithNestedKey::into_rmw_message(std::borrow::Cow::Owned(msg.nested_keys)).into_owned(),
        float64_value: msg.float64_value,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      uint32_key: msg.uint32_key,
        nested_keys: super::msg::NonKeyedWithNestedKey::into_rmw_message(std::borrow::Cow::Borrowed(&msg.nested_keys)).into_owned(),
      float64_value: msg.float64_value,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      uint32_key: msg.uint32_key,
      nested_keys: super::msg::NonKeyedWithNestedKey::from_rmw_message(msg.nested_keys),
      float64_value: msg.float64_value,
    }
  }
}


// Corresponds to test_msgs__msg__Arrays
/// Arrays of different types

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Arrays {

    // This member is not documented.
    #[allow(missing_docs)]
    pub bool_values: [bool; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub byte_values: [u8; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub char_values: [u8; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub float32_values: [f32; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub float64_values: [f64; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub int8_values: [i8; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint8_values: [u8; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub int16_values: [i16; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint16_values: [u16; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub int32_values: [i32; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint32_values: [u32; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub int64_values: [i64; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint64_values: [u64; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub string_values: [std::string::String; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub basic_types_values: [super::msg::BasicTypes; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub constants_values: [super::msg::Constants; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub defaults_values: [super::msg::Defaults; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub bool_values_default: [bool; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub byte_values_default: [u8; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub char_values_default: [u8; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub float32_values_default: [f32; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub float64_values_default: [f64; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub int8_values_default: [i8; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint8_values_default: [u8; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub int16_values_default: [i16; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint16_values_default: [u16; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub int32_values_default: [i32; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint32_values_default: [u32; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub int64_values_default: [i64; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint64_values_default: [u64; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub string_values_default: [std::string::String; 3],

    /// Regression test: check alignment of basic field after an array field is correct
    pub alignment_check: i32,

}



impl Default for Arrays {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Arrays::default())
  }
}

impl rosidl_runtime_rs::Message for Arrays {
  type RmwMsg = super::msg::rmw::Arrays;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        bool_values: msg.bool_values,
        byte_values: msg.byte_values,
        char_values: msg.char_values,
        float32_values: msg.float32_values,
        float64_values: msg.float64_values,
        int8_values: msg.int8_values,
        uint8_values: msg.uint8_values,
        int16_values: msg.int16_values,
        uint16_values: msg.uint16_values,
        int32_values: msg.int32_values,
        uint32_values: msg.uint32_values,
        int64_values: msg.int64_values,
        uint64_values: msg.uint64_values,
        string_values: msg.string_values
          .map(|elem| elem.as_str().into()),
        basic_types_values: msg.basic_types_values
          .map(|elem| super::msg::BasicTypes::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned()),
        constants_values: msg.constants_values
          .map(|elem| super::msg::Constants::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned()),
        defaults_values: msg.defaults_values
          .map(|elem| super::msg::Defaults::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned()),
        bool_values_default: msg.bool_values_default,
        byte_values_default: msg.byte_values_default,
        char_values_default: msg.char_values_default,
        float32_values_default: msg.float32_values_default,
        float64_values_default: msg.float64_values_default,
        int8_values_default: msg.int8_values_default,
        uint8_values_default: msg.uint8_values_default,
        int16_values_default: msg.int16_values_default,
        uint16_values_default: msg.uint16_values_default,
        int32_values_default: msg.int32_values_default,
        uint32_values_default: msg.uint32_values_default,
        int64_values_default: msg.int64_values_default,
        uint64_values_default: msg.uint64_values_default,
        string_values_default: msg.string_values_default
          .map(|elem| elem.as_str().into()),
        alignment_check: msg.alignment_check,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        bool_values: msg.bool_values,
        byte_values: msg.byte_values,
        char_values: msg.char_values,
        float32_values: msg.float32_values,
        float64_values: msg.float64_values,
        int8_values: msg.int8_values,
        uint8_values: msg.uint8_values,
        int16_values: msg.int16_values,
        uint16_values: msg.uint16_values,
        int32_values: msg.int32_values,
        uint32_values: msg.uint32_values,
        int64_values: msg.int64_values,
        uint64_values: msg.uint64_values,
        string_values: msg.string_values
          .iter()
          .map(|elem| elem.as_str().into())
          .collect::<Vec<_>>()
          .try_into()
          .unwrap(),
        basic_types_values: msg.basic_types_values
          .iter()
          .map(|elem| super::msg::BasicTypes::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect::<Vec<_>>()
          .try_into()
          .unwrap(),
        constants_values: msg.constants_values
          .iter()
          .map(|elem| super::msg::Constants::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect::<Vec<_>>()
          .try_into()
          .unwrap(),
        defaults_values: msg.defaults_values
          .iter()
          .map(|elem| super::msg::Defaults::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect::<Vec<_>>()
          .try_into()
          .unwrap(),
        bool_values_default: msg.bool_values_default,
        byte_values_default: msg.byte_values_default,
        char_values_default: msg.char_values_default,
        float32_values_default: msg.float32_values_default,
        float64_values_default: msg.float64_values_default,
        int8_values_default: msg.int8_values_default,
        uint8_values_default: msg.uint8_values_default,
        int16_values_default: msg.int16_values_default,
        uint16_values_default: msg.uint16_values_default,
        int32_values_default: msg.int32_values_default,
        uint32_values_default: msg.uint32_values_default,
        int64_values_default: msg.int64_values_default,
        uint64_values_default: msg.uint64_values_default,
        string_values_default: msg.string_values_default
          .iter()
          .map(|elem| elem.as_str().into())
          .collect::<Vec<_>>()
          .try_into()
          .unwrap(),
      alignment_check: msg.alignment_check,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      bool_values: msg.bool_values,
      byte_values: msg.byte_values,
      char_values: msg.char_values,
      float32_values: msg.float32_values,
      float64_values: msg.float64_values,
      int8_values: msg.int8_values,
      uint8_values: msg.uint8_values,
      int16_values: msg.int16_values,
      uint16_values: msg.uint16_values,
      int32_values: msg.int32_values,
      uint32_values: msg.uint32_values,
      int64_values: msg.int64_values,
      uint64_values: msg.uint64_values,
      string_values: msg.string_values
        .map(|elem| elem.to_string()),
      basic_types_values: msg.basic_types_values
        .map(super::msg::BasicTypes::from_rmw_message),
      constants_values: msg.constants_values
        .map(super::msg::Constants::from_rmw_message),
      defaults_values: msg.defaults_values
        .map(super::msg::Defaults::from_rmw_message),
      bool_values_default: msg.bool_values_default,
      byte_values_default: msg.byte_values_default,
      char_values_default: msg.char_values_default,
      float32_values_default: msg.float32_values_default,
      float64_values_default: msg.float64_values_default,
      int8_values_default: msg.int8_values_default,
      uint8_values_default: msg.uint8_values_default,
      int16_values_default: msg.int16_values_default,
      uint16_values_default: msg.uint16_values_default,
      int32_values_default: msg.int32_values_default,
      uint32_values_default: msg.uint32_values_default,
      int64_values_default: msg.int64_values_default,
      uint64_values_default: msg.uint64_values_default,
      string_values_default: msg.string_values_default
        .map(|elem| elem.to_string()),
      alignment_check: msg.alignment_check,
    }
  }
}


// Corresponds to test_msgs__msg__BasicTypes

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BasicTypes {

    // This member is not documented.
    #[allow(missing_docs)]
    pub bool_value: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub byte_value: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub char_value: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub float32_value: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub float64_value: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int8_value: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint8_value: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int16_value: i16,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint16_value: u16,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int32_value: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint32_value: u32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int64_value: i64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint64_value: u64,

}



impl Default for BasicTypes {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::BasicTypes::default())
  }
}

impl rosidl_runtime_rs::Message for BasicTypes {
  type RmwMsg = super::msg::rmw::BasicTypes;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        bool_value: msg.bool_value,
        byte_value: msg.byte_value,
        char_value: msg.char_value,
        float32_value: msg.float32_value,
        float64_value: msg.float64_value,
        int8_value: msg.int8_value,
        uint8_value: msg.uint8_value,
        int16_value: msg.int16_value,
        uint16_value: msg.uint16_value,
        int32_value: msg.int32_value,
        uint32_value: msg.uint32_value,
        int64_value: msg.int64_value,
        uint64_value: msg.uint64_value,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      bool_value: msg.bool_value,
      byte_value: msg.byte_value,
      char_value: msg.char_value,
      float32_value: msg.float32_value,
      float64_value: msg.float64_value,
      int8_value: msg.int8_value,
      uint8_value: msg.uint8_value,
      int16_value: msg.int16_value,
      uint16_value: msg.uint16_value,
      int32_value: msg.int32_value,
      uint32_value: msg.uint32_value,
      int64_value: msg.int64_value,
      uint64_value: msg.uint64_value,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      bool_value: msg.bool_value,
      byte_value: msg.byte_value,
      char_value: msg.char_value,
      float32_value: msg.float32_value,
      float64_value: msg.float64_value,
      int8_value: msg.int8_value,
      uint8_value: msg.uint8_value,
      int16_value: msg.int16_value,
      uint16_value: msg.uint16_value,
      int32_value: msg.int32_value,
      uint32_value: msg.uint32_value,
      int64_value: msg.int64_value,
      uint64_value: msg.uint64_value,
    }
  }
}


// Corresponds to test_msgs__msg__BoundedPlainSequences
/// Bounded sequences of different POD types

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BoundedPlainSequences {

    // This member is not documented.
    #[allow(missing_docs)]
    pub bool_values: rosidl_runtime_rs::BoundedSequence<bool, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub byte_values: rosidl_runtime_rs::BoundedSequence<u8, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub char_values: rosidl_runtime_rs::BoundedSequence<u8, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub float32_values: rosidl_runtime_rs::BoundedSequence<f32, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub float64_values: rosidl_runtime_rs::BoundedSequence<f64, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int8_values: rosidl_runtime_rs::BoundedSequence<i8, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint8_values: rosidl_runtime_rs::BoundedSequence<u8, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int16_values: rosidl_runtime_rs::BoundedSequence<i16, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint16_values: rosidl_runtime_rs::BoundedSequence<u16, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int32_values: rosidl_runtime_rs::BoundedSequence<i32, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint32_values: rosidl_runtime_rs::BoundedSequence<u32, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int64_values: rosidl_runtime_rs::BoundedSequence<i64, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint64_values: rosidl_runtime_rs::BoundedSequence<u64, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub basic_types_values: rosidl_runtime_rs::BoundedSequence<super::msg::rmw::BasicTypes, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub constants_values: rosidl_runtime_rs::BoundedSequence<super::msg::rmw::Constants, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub defaults_values: rosidl_runtime_rs::BoundedSequence<super::msg::rmw::Defaults, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub bool_values_default: rosidl_runtime_rs::BoundedSequence<bool, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub byte_values_default: rosidl_runtime_rs::BoundedSequence<u8, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub char_values_default: rosidl_runtime_rs::BoundedSequence<u8, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub float32_values_default: rosidl_runtime_rs::BoundedSequence<f32, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub float64_values_default: rosidl_runtime_rs::BoundedSequence<f64, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int8_values_default: rosidl_runtime_rs::BoundedSequence<i8, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint8_values_default: rosidl_runtime_rs::BoundedSequence<u8, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int16_values_default: rosidl_runtime_rs::BoundedSequence<i16, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint16_values_default: rosidl_runtime_rs::BoundedSequence<u16, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int32_values_default: rosidl_runtime_rs::BoundedSequence<i32, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint32_values_default: rosidl_runtime_rs::BoundedSequence<u32, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int64_values_default: rosidl_runtime_rs::BoundedSequence<i64, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint64_values_default: rosidl_runtime_rs::BoundedSequence<u64, 3>,

    /// Regression test: check alignment of basic field after a sequence field is correct
    pub alignment_check: i32,

}



impl Default for BoundedPlainSequences {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::BoundedPlainSequences::default())
  }
}

impl rosidl_runtime_rs::Message for BoundedPlainSequences {
  type RmwMsg = super::msg::rmw::BoundedPlainSequences;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        bool_values: msg.bool_values,
        byte_values: msg.byte_values,
        char_values: msg.char_values,
        float32_values: msg.float32_values,
        float64_values: msg.float64_values,
        int8_values: msg.int8_values,
        uint8_values: msg.uint8_values,
        int16_values: msg.int16_values,
        uint16_values: msg.uint16_values,
        int32_values: msg.int32_values,
        uint32_values: msg.uint32_values,
        int64_values: msg.int64_values,
        uint64_values: msg.uint64_values,
        basic_types_values: msg.basic_types_values,
        constants_values: msg.constants_values,
        defaults_values: msg.defaults_values,
        bool_values_default: msg.bool_values_default,
        byte_values_default: msg.byte_values_default,
        char_values_default: msg.char_values_default,
        float32_values_default: msg.float32_values_default,
        float64_values_default: msg.float64_values_default,
        int8_values_default: msg.int8_values_default,
        uint8_values_default: msg.uint8_values_default,
        int16_values_default: msg.int16_values_default,
        uint16_values_default: msg.uint16_values_default,
        int32_values_default: msg.int32_values_default,
        uint32_values_default: msg.uint32_values_default,
        int64_values_default: msg.int64_values_default,
        uint64_values_default: msg.uint64_values_default,
        alignment_check: msg.alignment_check,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        bool_values: msg.bool_values.clone(),
        byte_values: msg.byte_values.clone(),
        char_values: msg.char_values.clone(),
        float32_values: msg.float32_values.clone(),
        float64_values: msg.float64_values.clone(),
        int8_values: msg.int8_values.clone(),
        uint8_values: msg.uint8_values.clone(),
        int16_values: msg.int16_values.clone(),
        uint16_values: msg.uint16_values.clone(),
        int32_values: msg.int32_values.clone(),
        uint32_values: msg.uint32_values.clone(),
        int64_values: msg.int64_values.clone(),
        uint64_values: msg.uint64_values.clone(),
        basic_types_values: msg.basic_types_values.clone(),
        constants_values: msg.constants_values.clone(),
        defaults_values: msg.defaults_values.clone(),
        bool_values_default: msg.bool_values_default.clone(),
        byte_values_default: msg.byte_values_default.clone(),
        char_values_default: msg.char_values_default.clone(),
        float32_values_default: msg.float32_values_default.clone(),
        float64_values_default: msg.float64_values_default.clone(),
        int8_values_default: msg.int8_values_default.clone(),
        uint8_values_default: msg.uint8_values_default.clone(),
        int16_values_default: msg.int16_values_default.clone(),
        uint16_values_default: msg.uint16_values_default.clone(),
        int32_values_default: msg.int32_values_default.clone(),
        uint32_values_default: msg.uint32_values_default.clone(),
        int64_values_default: msg.int64_values_default.clone(),
        uint64_values_default: msg.uint64_values_default.clone(),
      alignment_check: msg.alignment_check,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      bool_values: msg.bool_values,
      byte_values: msg.byte_values,
      char_values: msg.char_values,
      float32_values: msg.float32_values,
      float64_values: msg.float64_values,
      int8_values: msg.int8_values,
      uint8_values: msg.uint8_values,
      int16_values: msg.int16_values,
      uint16_values: msg.uint16_values,
      int32_values: msg.int32_values,
      uint32_values: msg.uint32_values,
      int64_values: msg.int64_values,
      uint64_values: msg.uint64_values,
      basic_types_values: msg.basic_types_values,
      constants_values: msg.constants_values,
      defaults_values: msg.defaults_values,
      bool_values_default: msg.bool_values_default,
      byte_values_default: msg.byte_values_default,
      char_values_default: msg.char_values_default,
      float32_values_default: msg.float32_values_default,
      float64_values_default: msg.float64_values_default,
      int8_values_default: msg.int8_values_default,
      uint8_values_default: msg.uint8_values_default,
      int16_values_default: msg.int16_values_default,
      uint16_values_default: msg.uint16_values_default,
      int32_values_default: msg.int32_values_default,
      uint32_values_default: msg.uint32_values_default,
      int64_values_default: msg.int64_values_default,
      uint64_values_default: msg.uint64_values_default,
      alignment_check: msg.alignment_check,
    }
  }
}


// Corresponds to test_msgs__msg__BoundedSequences
/// Bounded sequences of different types

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BoundedSequences {

    // This member is not documented.
    #[allow(missing_docs)]
    pub bool_values: rosidl_runtime_rs::BoundedSequence<bool, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub byte_values: rosidl_runtime_rs::BoundedSequence<u8, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub char_values: rosidl_runtime_rs::BoundedSequence<u8, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub float32_values: rosidl_runtime_rs::BoundedSequence<f32, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub float64_values: rosidl_runtime_rs::BoundedSequence<f64, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int8_values: rosidl_runtime_rs::BoundedSequence<i8, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint8_values: rosidl_runtime_rs::BoundedSequence<u8, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int16_values: rosidl_runtime_rs::BoundedSequence<i16, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint16_values: rosidl_runtime_rs::BoundedSequence<u16, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int32_values: rosidl_runtime_rs::BoundedSequence<i32, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint32_values: rosidl_runtime_rs::BoundedSequence<u32, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int64_values: rosidl_runtime_rs::BoundedSequence<i64, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint64_values: rosidl_runtime_rs::BoundedSequence<u64, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub string_values: rosidl_runtime_rs::BoundedSequence<rosidl_runtime_rs::String, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub basic_types_values: rosidl_runtime_rs::BoundedSequence<super::msg::rmw::BasicTypes, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub constants_values: rosidl_runtime_rs::BoundedSequence<super::msg::rmw::Constants, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub defaults_values: rosidl_runtime_rs::BoundedSequence<super::msg::rmw::Defaults, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub bool_values_default: rosidl_runtime_rs::BoundedSequence<bool, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub byte_values_default: rosidl_runtime_rs::BoundedSequence<u8, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub char_values_default: rosidl_runtime_rs::BoundedSequence<u8, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub float32_values_default: rosidl_runtime_rs::BoundedSequence<f32, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub float64_values_default: rosidl_runtime_rs::BoundedSequence<f64, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int8_values_default: rosidl_runtime_rs::BoundedSequence<i8, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint8_values_default: rosidl_runtime_rs::BoundedSequence<u8, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int16_values_default: rosidl_runtime_rs::BoundedSequence<i16, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint16_values_default: rosidl_runtime_rs::BoundedSequence<u16, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int32_values_default: rosidl_runtime_rs::BoundedSequence<i32, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint32_values_default: rosidl_runtime_rs::BoundedSequence<u32, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int64_values_default: rosidl_runtime_rs::BoundedSequence<i64, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint64_values_default: rosidl_runtime_rs::BoundedSequence<u64, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub string_values_default: rosidl_runtime_rs::BoundedSequence<rosidl_runtime_rs::String, 3>,

    /// Regression test: check alignment of basic field after a sequence field is correct
    pub alignment_check: i32,

}



impl Default for BoundedSequences {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::BoundedSequences::default())
  }
}

impl rosidl_runtime_rs::Message for BoundedSequences {
  type RmwMsg = super::msg::rmw::BoundedSequences;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        bool_values: msg.bool_values,
        byte_values: msg.byte_values,
        char_values: msg.char_values,
        float32_values: msg.float32_values,
        float64_values: msg.float64_values,
        int8_values: msg.int8_values,
        uint8_values: msg.uint8_values,
        int16_values: msg.int16_values,
        uint16_values: msg.uint16_values,
        int32_values: msg.int32_values,
        uint32_values: msg.uint32_values,
        int64_values: msg.int64_values,
        uint64_values: msg.uint64_values,
        string_values: msg.string_values,
        basic_types_values: msg.basic_types_values,
        constants_values: msg.constants_values,
        defaults_values: msg.defaults_values,
        bool_values_default: msg.bool_values_default,
        byte_values_default: msg.byte_values_default,
        char_values_default: msg.char_values_default,
        float32_values_default: msg.float32_values_default,
        float64_values_default: msg.float64_values_default,
        int8_values_default: msg.int8_values_default,
        uint8_values_default: msg.uint8_values_default,
        int16_values_default: msg.int16_values_default,
        uint16_values_default: msg.uint16_values_default,
        int32_values_default: msg.int32_values_default,
        uint32_values_default: msg.uint32_values_default,
        int64_values_default: msg.int64_values_default,
        uint64_values_default: msg.uint64_values_default,
        string_values_default: msg.string_values_default,
        alignment_check: msg.alignment_check,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        bool_values: msg.bool_values.clone(),
        byte_values: msg.byte_values.clone(),
        char_values: msg.char_values.clone(),
        float32_values: msg.float32_values.clone(),
        float64_values: msg.float64_values.clone(),
        int8_values: msg.int8_values.clone(),
        uint8_values: msg.uint8_values.clone(),
        int16_values: msg.int16_values.clone(),
        uint16_values: msg.uint16_values.clone(),
        int32_values: msg.int32_values.clone(),
        uint32_values: msg.uint32_values.clone(),
        int64_values: msg.int64_values.clone(),
        uint64_values: msg.uint64_values.clone(),
        string_values: msg.string_values.clone(),
        basic_types_values: msg.basic_types_values.clone(),
        constants_values: msg.constants_values.clone(),
        defaults_values: msg.defaults_values.clone(),
        bool_values_default: msg.bool_values_default.clone(),
        byte_values_default: msg.byte_values_default.clone(),
        char_values_default: msg.char_values_default.clone(),
        float32_values_default: msg.float32_values_default.clone(),
        float64_values_default: msg.float64_values_default.clone(),
        int8_values_default: msg.int8_values_default.clone(),
        uint8_values_default: msg.uint8_values_default.clone(),
        int16_values_default: msg.int16_values_default.clone(),
        uint16_values_default: msg.uint16_values_default.clone(),
        int32_values_default: msg.int32_values_default.clone(),
        uint32_values_default: msg.uint32_values_default.clone(),
        int64_values_default: msg.int64_values_default.clone(),
        uint64_values_default: msg.uint64_values_default.clone(),
        string_values_default: msg.string_values_default.clone(),
      alignment_check: msg.alignment_check,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      bool_values: msg.bool_values,
      byte_values: msg.byte_values,
      char_values: msg.char_values,
      float32_values: msg.float32_values,
      float64_values: msg.float64_values,
      int8_values: msg.int8_values,
      uint8_values: msg.uint8_values,
      int16_values: msg.int16_values,
      uint16_values: msg.uint16_values,
      int32_values: msg.int32_values,
      uint32_values: msg.uint32_values,
      int64_values: msg.int64_values,
      uint64_values: msg.uint64_values,
      string_values: msg.string_values,
      basic_types_values: msg.basic_types_values,
      constants_values: msg.constants_values,
      defaults_values: msg.defaults_values,
      bool_values_default: msg.bool_values_default,
      byte_values_default: msg.byte_values_default,
      char_values_default: msg.char_values_default,
      float32_values_default: msg.float32_values_default,
      float64_values_default: msg.float64_values_default,
      int8_values_default: msg.int8_values_default,
      uint8_values_default: msg.uint8_values_default,
      int16_values_default: msg.int16_values_default,
      uint16_values_default: msg.uint16_values_default,
      int32_values_default: msg.int32_values_default,
      uint32_values_default: msg.uint32_values_default,
      int64_values_default: msg.int64_values_default,
      uint64_values_default: msg.uint64_values_default,
      string_values_default: msg.string_values_default,
      alignment_check: msg.alignment_check,
    }
  }
}


// Corresponds to test_msgs__msg__Constants

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Constants {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}

impl Constants {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const BOOL_CONST: bool = true;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const BYTE_CONST: u8 = 50;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const CHAR_CONST: u8 = 100;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FLOAT32_CONST: f32 = 1.125;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FLOAT64_CONST: f64 = 1.125;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const INT8_CONST: i8 = -50;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const UINT8_CONST: u8 = 200;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const INT16_CONST: i16 = -1000;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const UINT16_CONST: u16 = 2000;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const INT32_CONST: i32 = -30000;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const UINT32_CONST: u32 = 60000;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const INT64_CONST: i64 = -40000000;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const UINT64_CONST: u64 = 50000000;

}


impl Default for Constants {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Constants::default())
  }
}

impl rosidl_runtime_rs::Message for Constants {
  type RmwMsg = super::msg::rmw::Constants;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        structure_needs_at_least_one_member: msg.structure_needs_at_least_one_member,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      structure_needs_at_least_one_member: msg.structure_needs_at_least_one_member,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      structure_needs_at_least_one_member: msg.structure_needs_at_least_one_member,
    }
  }
}


// Corresponds to test_msgs__msg__Defaults

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Defaults {

    // This member is not documented.
    #[allow(missing_docs)]
    pub bool_value: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub byte_value: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub char_value: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub float32_value: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub float64_value: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int8_value: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint8_value: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int16_value: i16,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint16_value: u16,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int32_value: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint32_value: u32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int64_value: i64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint64_value: u64,

}



impl Default for Defaults {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Defaults::default())
  }
}

impl rosidl_runtime_rs::Message for Defaults {
  type RmwMsg = super::msg::rmw::Defaults;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        bool_value: msg.bool_value,
        byte_value: msg.byte_value,
        char_value: msg.char_value,
        float32_value: msg.float32_value,
        float64_value: msg.float64_value,
        int8_value: msg.int8_value,
        uint8_value: msg.uint8_value,
        int16_value: msg.int16_value,
        uint16_value: msg.uint16_value,
        int32_value: msg.int32_value,
        uint32_value: msg.uint32_value,
        int64_value: msg.int64_value,
        uint64_value: msg.uint64_value,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      bool_value: msg.bool_value,
      byte_value: msg.byte_value,
      char_value: msg.char_value,
      float32_value: msg.float32_value,
      float64_value: msg.float64_value,
      int8_value: msg.int8_value,
      uint8_value: msg.uint8_value,
      int16_value: msg.int16_value,
      uint16_value: msg.uint16_value,
      int32_value: msg.int32_value,
      uint32_value: msg.uint32_value,
      int64_value: msg.int64_value,
      uint64_value: msg.uint64_value,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      bool_value: msg.bool_value,
      byte_value: msg.byte_value,
      char_value: msg.char_value,
      float32_value: msg.float32_value,
      float64_value: msg.float64_value,
      int8_value: msg.int8_value,
      uint8_value: msg.uint8_value,
      int16_value: msg.int16_value,
      uint16_value: msg.uint16_value,
      int32_value: msg.int32_value,
      uint32_value: msg.uint32_value,
      int64_value: msg.int64_value,
      uint64_value: msg.uint64_value,
    }
  }
}


// Corresponds to test_msgs__msg__Empty

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Empty {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for Empty {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Empty::default())
  }
}

impl rosidl_runtime_rs::Message for Empty {
  type RmwMsg = super::msg::rmw::Empty;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        structure_needs_at_least_one_member: msg.structure_needs_at_least_one_member,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      structure_needs_at_least_one_member: msg.structure_needs_at_least_one_member,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      structure_needs_at_least_one_member: msg.structure_needs_at_least_one_member,
    }
  }
}


// Corresponds to test_msgs__msg__MultiNested
/// Mulitple levels of nested messages

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MultiNested {

    // This member is not documented.
    #[allow(missing_docs)]
    pub array_of_arrays: [super::msg::Arrays; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub array_of_bounded_sequences: [super::msg::BoundedSequences; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub array_of_unbounded_sequences: [super::msg::UnboundedSequences; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub bounded_sequence_of_arrays: rosidl_runtime_rs::BoundedSequence<super::msg::rmw::Arrays, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub bounded_sequence_of_bounded_sequences: rosidl_runtime_rs::BoundedSequence<super::msg::rmw::BoundedSequences, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub bounded_sequence_of_unbounded_sequences: rosidl_runtime_rs::BoundedSequence<super::msg::rmw::UnboundedSequences, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub unbounded_sequence_of_arrays: Vec<super::msg::Arrays>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub unbounded_sequence_of_bounded_sequences: Vec<super::msg::BoundedSequences>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub unbounded_sequence_of_unbounded_sequences: Vec<super::msg::UnboundedSequences>,

}



impl Default for MultiNested {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::MultiNested::default())
  }
}

impl rosidl_runtime_rs::Message for MultiNested {
  type RmwMsg = super::msg::rmw::MultiNested;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        array_of_arrays: msg.array_of_arrays
          .map(|elem| super::msg::Arrays::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned()),
        array_of_bounded_sequences: msg.array_of_bounded_sequences
          .map(|elem| super::msg::BoundedSequences::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned()),
        array_of_unbounded_sequences: msg.array_of_unbounded_sequences
          .map(|elem| super::msg::UnboundedSequences::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned()),
        bounded_sequence_of_arrays: msg.bounded_sequence_of_arrays,
        bounded_sequence_of_bounded_sequences: msg.bounded_sequence_of_bounded_sequences,
        bounded_sequence_of_unbounded_sequences: msg.bounded_sequence_of_unbounded_sequences,
        unbounded_sequence_of_arrays: msg.unbounded_sequence_of_arrays
          .into_iter()
          .map(|elem| super::msg::Arrays::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        unbounded_sequence_of_bounded_sequences: msg.unbounded_sequence_of_bounded_sequences
          .into_iter()
          .map(|elem| super::msg::BoundedSequences::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        unbounded_sequence_of_unbounded_sequences: msg.unbounded_sequence_of_unbounded_sequences
          .into_iter()
          .map(|elem| super::msg::UnboundedSequences::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        array_of_arrays: msg.array_of_arrays
          .iter()
          .map(|elem| super::msg::Arrays::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect::<Vec<_>>()
          .try_into()
          .unwrap(),
        array_of_bounded_sequences: msg.array_of_bounded_sequences
          .iter()
          .map(|elem| super::msg::BoundedSequences::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect::<Vec<_>>()
          .try_into()
          .unwrap(),
        array_of_unbounded_sequences: msg.array_of_unbounded_sequences
          .iter()
          .map(|elem| super::msg::UnboundedSequences::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect::<Vec<_>>()
          .try_into()
          .unwrap(),
        bounded_sequence_of_arrays: msg.bounded_sequence_of_arrays.clone(),
        bounded_sequence_of_bounded_sequences: msg.bounded_sequence_of_bounded_sequences.clone(),
        bounded_sequence_of_unbounded_sequences: msg.bounded_sequence_of_unbounded_sequences.clone(),
        unbounded_sequence_of_arrays: msg.unbounded_sequence_of_arrays
          .iter()
          .map(|elem| super::msg::Arrays::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
        unbounded_sequence_of_bounded_sequences: msg.unbounded_sequence_of_bounded_sequences
          .iter()
          .map(|elem| super::msg::BoundedSequences::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
        unbounded_sequence_of_unbounded_sequences: msg.unbounded_sequence_of_unbounded_sequences
          .iter()
          .map(|elem| super::msg::UnboundedSequences::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      array_of_arrays: msg.array_of_arrays
        .map(super::msg::Arrays::from_rmw_message),
      array_of_bounded_sequences: msg.array_of_bounded_sequences
        .map(super::msg::BoundedSequences::from_rmw_message),
      array_of_unbounded_sequences: msg.array_of_unbounded_sequences
        .map(super::msg::UnboundedSequences::from_rmw_message),
      bounded_sequence_of_arrays: msg.bounded_sequence_of_arrays,
      bounded_sequence_of_bounded_sequences: msg.bounded_sequence_of_bounded_sequences,
      bounded_sequence_of_unbounded_sequences: msg.bounded_sequence_of_unbounded_sequences,
      unbounded_sequence_of_arrays: msg.unbounded_sequence_of_arrays
          .into_iter()
          .map(super::msg::Arrays::from_rmw_message)
          .collect(),
      unbounded_sequence_of_bounded_sequences: msg.unbounded_sequence_of_bounded_sequences
          .into_iter()
          .map(super::msg::BoundedSequences::from_rmw_message)
          .collect(),
      unbounded_sequence_of_unbounded_sequences: msg.unbounded_sequence_of_unbounded_sequences
          .into_iter()
          .map(super::msg::UnboundedSequences::from_rmw_message)
          .collect(),
    }
  }
}


// Corresponds to test_msgs__msg__Nested

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Nested {

    // This member is not documented.
    #[allow(missing_docs)]
    pub basic_types_value: super::msg::BasicTypes,

}



impl Default for Nested {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Nested::default())
  }
}

impl rosidl_runtime_rs::Message for Nested {
  type RmwMsg = super::msg::rmw::Nested;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        basic_types_value: super::msg::BasicTypes::into_rmw_message(std::borrow::Cow::Owned(msg.basic_types_value)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        basic_types_value: super::msg::BasicTypes::into_rmw_message(std::borrow::Cow::Borrowed(&msg.basic_types_value)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      basic_types_value: super::msg::BasicTypes::from_rmw_message(msg.basic_types_value),
    }
  }
}


// Corresponds to test_msgs__msg__Strings

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Strings {

    // This member is not documented.
    #[allow(missing_docs)]
    pub string_value: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub string_value_default1: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub string_value_default2: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub string_value_default3: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub string_value_default4: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub string_value_default5: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub bounded_string_value: rosidl_runtime_rs::BoundedString<22>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub bounded_string_value_default1: rosidl_runtime_rs::BoundedString<22>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub bounded_string_value_default2: rosidl_runtime_rs::BoundedString<22>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub bounded_string_value_default3: rosidl_runtime_rs::BoundedString<22>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub bounded_string_value_default4: rosidl_runtime_rs::BoundedString<22>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub bounded_string_value_default5: rosidl_runtime_rs::BoundedString<22>,

}

impl Strings {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const STRING_CONST: &'static str = "Hello world!";

}


impl Default for Strings {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Strings::default())
  }
}

impl rosidl_runtime_rs::Message for Strings {
  type RmwMsg = super::msg::rmw::Strings;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        string_value: msg.string_value.as_str().into(),
        string_value_default1: msg.string_value_default1.as_str().into(),
        string_value_default2: msg.string_value_default2.as_str().into(),
        string_value_default3: msg.string_value_default3.as_str().into(),
        string_value_default4: msg.string_value_default4.as_str().into(),
        string_value_default5: msg.string_value_default5.as_str().into(),
        bounded_string_value: msg.bounded_string_value,
        bounded_string_value_default1: msg.bounded_string_value_default1,
        bounded_string_value_default2: msg.bounded_string_value_default2,
        bounded_string_value_default3: msg.bounded_string_value_default3,
        bounded_string_value_default4: msg.bounded_string_value_default4,
        bounded_string_value_default5: msg.bounded_string_value_default5,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        string_value: msg.string_value.as_str().into(),
        string_value_default1: msg.string_value_default1.as_str().into(),
        string_value_default2: msg.string_value_default2.as_str().into(),
        string_value_default3: msg.string_value_default3.as_str().into(),
        string_value_default4: msg.string_value_default4.as_str().into(),
        string_value_default5: msg.string_value_default5.as_str().into(),
        bounded_string_value: msg.bounded_string_value.clone(),
        bounded_string_value_default1: msg.bounded_string_value_default1.clone(),
        bounded_string_value_default2: msg.bounded_string_value_default2.clone(),
        bounded_string_value_default3: msg.bounded_string_value_default3.clone(),
        bounded_string_value_default4: msg.bounded_string_value_default4.clone(),
        bounded_string_value_default5: msg.bounded_string_value_default5.clone(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      string_value: msg.string_value.to_string(),
      string_value_default1: msg.string_value_default1.to_string(),
      string_value_default2: msg.string_value_default2.to_string(),
      string_value_default3: msg.string_value_default3.to_string(),
      string_value_default4: msg.string_value_default4.to_string(),
      string_value_default5: msg.string_value_default5.to_string(),
      bounded_string_value: msg.bounded_string_value,
      bounded_string_value_default1: msg.bounded_string_value_default1,
      bounded_string_value_default2: msg.bounded_string_value_default2,
      bounded_string_value_default3: msg.bounded_string_value_default3,
      bounded_string_value_default4: msg.bounded_string_value_default4,
      bounded_string_value_default5: msg.bounded_string_value_default5,
    }
  }
}


// Corresponds to test_msgs__msg__UnboundedSequences
/// Unbounded sequences of different types

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct UnboundedSequences {

    // This member is not documented.
    #[allow(missing_docs)]
    pub bool_values: Vec<bool>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub byte_values: Vec<u8>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub char_values: Vec<u8>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub float32_values: Vec<f32>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub float64_values: Vec<f64>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int8_values: Vec<i8>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint8_values: Vec<u8>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int16_values: Vec<i16>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint16_values: Vec<u16>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int32_values: Vec<i32>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint32_values: Vec<u32>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int64_values: Vec<i64>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint64_values: Vec<u64>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub string_values: Vec<std::string::String>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub basic_types_values: Vec<super::msg::BasicTypes>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub constants_values: Vec<super::msg::Constants>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub defaults_values: Vec<super::msg::Defaults>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub bool_values_default: Vec<bool>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub byte_values_default: Vec<u8>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub char_values_default: Vec<u8>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub float32_values_default: Vec<f32>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub float64_values_default: Vec<f64>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int8_values_default: Vec<i8>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint8_values_default: Vec<u8>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int16_values_default: Vec<i16>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint16_values_default: Vec<u16>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int32_values_default: Vec<i32>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint32_values_default: Vec<u32>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int64_values_default: Vec<i64>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint64_values_default: Vec<u64>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub string_values_default: Vec<std::string::String>,

    /// Regression test: check alignment of basic field after a sequence field is correct
    pub alignment_check: i32,

}



impl Default for UnboundedSequences {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::UnboundedSequences::default())
  }
}

impl rosidl_runtime_rs::Message for UnboundedSequences {
  type RmwMsg = super::msg::rmw::UnboundedSequences;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        bool_values: msg.bool_values.as_slice().into(),
        byte_values: msg.byte_values.as_slice().into(),
        char_values: msg.char_values.as_slice().into(),
        float32_values: msg.float32_values.as_slice().into(),
        float64_values: msg.float64_values.as_slice().into(),
        int8_values: msg.int8_values.as_slice().into(),
        uint8_values: msg.uint8_values.as_slice().into(),
        int16_values: msg.int16_values.as_slice().into(),
        uint16_values: msg.uint16_values.as_slice().into(),
        int32_values: msg.int32_values.as_slice().into(),
        uint32_values: msg.uint32_values.as_slice().into(),
        int64_values: msg.int64_values.as_slice().into(),
        uint64_values: msg.uint64_values.as_slice().into(),
        string_values: msg.string_values
          .into_iter()
          .map(|elem| elem.as_str().into())
          .collect(),
        basic_types_values: msg.basic_types_values
          .into_iter()
          .map(|elem| super::msg::BasicTypes::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        constants_values: msg.constants_values
          .into_iter()
          .map(|elem| super::msg::Constants::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        defaults_values: msg.defaults_values
          .into_iter()
          .map(|elem| super::msg::Defaults::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        bool_values_default: msg.bool_values_default.as_slice().into(),
        byte_values_default: msg.byte_values_default.as_slice().into(),
        char_values_default: msg.char_values_default.as_slice().into(),
        float32_values_default: msg.float32_values_default.as_slice().into(),
        float64_values_default: msg.float64_values_default.as_slice().into(),
        int8_values_default: msg.int8_values_default.as_slice().into(),
        uint8_values_default: msg.uint8_values_default.as_slice().into(),
        int16_values_default: msg.int16_values_default.as_slice().into(),
        uint16_values_default: msg.uint16_values_default.as_slice().into(),
        int32_values_default: msg.int32_values_default.as_slice().into(),
        uint32_values_default: msg.uint32_values_default.as_slice().into(),
        int64_values_default: msg.int64_values_default.as_slice().into(),
        uint64_values_default: msg.uint64_values_default.as_slice().into(),
        string_values_default: msg.string_values_default
          .into_iter()
          .map(|elem| elem.as_str().into())
          .collect(),
        alignment_check: msg.alignment_check,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        bool_values: msg.bool_values.as_slice().into(),
        byte_values: msg.byte_values.as_slice().into(),
        char_values: msg.char_values.as_slice().into(),
        float32_values: msg.float32_values.as_slice().into(),
        float64_values: msg.float64_values.as_slice().into(),
        int8_values: msg.int8_values.as_slice().into(),
        uint8_values: msg.uint8_values.as_slice().into(),
        int16_values: msg.int16_values.as_slice().into(),
        uint16_values: msg.uint16_values.as_slice().into(),
        int32_values: msg.int32_values.as_slice().into(),
        uint32_values: msg.uint32_values.as_slice().into(),
        int64_values: msg.int64_values.as_slice().into(),
        uint64_values: msg.uint64_values.as_slice().into(),
        string_values: msg.string_values
          .iter()
          .map(|elem| elem.as_str().into())
          .collect(),
        basic_types_values: msg.basic_types_values
          .iter()
          .map(|elem| super::msg::BasicTypes::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
        constants_values: msg.constants_values
          .iter()
          .map(|elem| super::msg::Constants::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
        defaults_values: msg.defaults_values
          .iter()
          .map(|elem| super::msg::Defaults::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
        bool_values_default: msg.bool_values_default.as_slice().into(),
        byte_values_default: msg.byte_values_default.as_slice().into(),
        char_values_default: msg.char_values_default.as_slice().into(),
        float32_values_default: msg.float32_values_default.as_slice().into(),
        float64_values_default: msg.float64_values_default.as_slice().into(),
        int8_values_default: msg.int8_values_default.as_slice().into(),
        uint8_values_default: msg.uint8_values_default.as_slice().into(),
        int16_values_default: msg.int16_values_default.as_slice().into(),
        uint16_values_default: msg.uint16_values_default.as_slice().into(),
        int32_values_default: msg.int32_values_default.as_slice().into(),
        uint32_values_default: msg.uint32_values_default.as_slice().into(),
        int64_values_default: msg.int64_values_default.as_slice().into(),
        uint64_values_default: msg.uint64_values_default.as_slice().into(),
        string_values_default: msg.string_values_default
          .iter()
          .map(|elem| elem.as_str().into())
          .collect(),
      alignment_check: msg.alignment_check,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      bool_values: msg.bool_values.into(),
      byte_values: msg.byte_values.into(),
      char_values: msg.char_values.into(),
      float32_values: msg.float32_values.into(),
      float64_values: msg.float64_values.into(),
      int8_values: msg.int8_values.into(),
      uint8_values: msg.uint8_values.into(),
      int16_values: msg.int16_values.into(),
      uint16_values: msg.uint16_values.into(),
      int32_values: msg.int32_values.into(),
      uint32_values: msg.uint32_values.into(),
      int64_values: msg.int64_values.into(),
      uint64_values: msg.uint64_values.into(),
      string_values: msg.string_values
          .into_iter()
          .map(|elem| elem.to_string())
          .collect(),
      basic_types_values: msg.basic_types_values
          .into_iter()
          .map(super::msg::BasicTypes::from_rmw_message)
          .collect(),
      constants_values: msg.constants_values
          .into_iter()
          .map(super::msg::Constants::from_rmw_message)
          .collect(),
      defaults_values: msg.defaults_values
          .into_iter()
          .map(super::msg::Defaults::from_rmw_message)
          .collect(),
      bool_values_default: msg.bool_values_default.into(),
      byte_values_default: msg.byte_values_default.into(),
      char_values_default: msg.char_values_default.into(),
      float32_values_default: msg.float32_values_default.into(),
      float64_values_default: msg.float64_values_default.into(),
      int8_values_default: msg.int8_values_default.into(),
      uint8_values_default: msg.uint8_values_default.into(),
      int16_values_default: msg.int16_values_default.into(),
      uint16_values_default: msg.uint16_values_default.into(),
      int32_values_default: msg.int32_values_default.into(),
      uint32_values_default: msg.uint32_values_default.into(),
      int64_values_default: msg.int64_values_default.into(),
      uint64_values_default: msg.uint64_values_default.into(),
      string_values_default: msg.string_values_default
          .into_iter()
          .map(|elem| elem.to_string())
          .collect(),
      alignment_check: msg.alignment_check,
    }
  }
}


// Corresponds to test_msgs__msg__WStrings

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct WStrings {

    // This member is not documented.
    #[allow(missing_docs)]
    pub wstring_value: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub wstring_value_default1: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub wstring_value_default2: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub wstring_value_default3: std::string::String,

    /// wstring WSTRING_CONST="Hello world!"
    /// wstring<=22 bounded_wstring_value
    /// wstring<=22 bounded_wstring_value_default1 "Hello world!"
    pub array_of_wstrings: [std::string::String; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub bounded_sequence_of_wstrings: rosidl_runtime_rs::BoundedSequence<rosidl_runtime_rs::WString, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub unbounded_sequence_of_wstrings: Vec<std::string::String>,

}



impl Default for WStrings {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::WStrings::default())
  }
}

impl rosidl_runtime_rs::Message for WStrings {
  type RmwMsg = super::msg::rmw::WStrings;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        wstring_value: msg.wstring_value.as_str().into(),
        wstring_value_default1: msg.wstring_value_default1.as_str().into(),
        wstring_value_default2: msg.wstring_value_default2.as_str().into(),
        wstring_value_default3: msg.wstring_value_default3.as_str().into(),
        array_of_wstrings: msg.array_of_wstrings
          .map(|elem| elem.as_str().into()),
        bounded_sequence_of_wstrings: msg.bounded_sequence_of_wstrings,
        unbounded_sequence_of_wstrings: msg.unbounded_sequence_of_wstrings
          .into_iter()
          .map(|elem| elem.as_str().into())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        wstring_value: msg.wstring_value.as_str().into(),
        wstring_value_default1: msg.wstring_value_default1.as_str().into(),
        wstring_value_default2: msg.wstring_value_default2.as_str().into(),
        wstring_value_default3: msg.wstring_value_default3.as_str().into(),
        array_of_wstrings: msg.array_of_wstrings
          .iter()
          .map(|elem| elem.as_str().into())
          .collect::<Vec<_>>()
          .try_into()
          .unwrap(),
        bounded_sequence_of_wstrings: msg.bounded_sequence_of_wstrings.clone(),
        unbounded_sequence_of_wstrings: msg.unbounded_sequence_of_wstrings
          .iter()
          .map(|elem| elem.as_str().into())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      wstring_value: msg.wstring_value.to_string(),
      wstring_value_default1: msg.wstring_value_default1.to_string(),
      wstring_value_default2: msg.wstring_value_default2.to_string(),
      wstring_value_default3: msg.wstring_value_default3.to_string(),
      array_of_wstrings: msg.array_of_wstrings
        .map(|elem| elem.to_string()),
      bounded_sequence_of_wstrings: msg.bounded_sequence_of_wstrings,
      unbounded_sequence_of_wstrings: msg.unbounded_sequence_of_wstrings
          .into_iter()
          .map(|elem| elem.to_string())
          .collect(),
    }
  }
}


// Corresponds to test_msgs__msg__Builtins

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Builtins {

    // This member is not documented.
    #[allow(missing_docs)]
    pub duration_value: builtin_interfaces::msg::Duration,


    // This member is not documented.
    #[allow(missing_docs)]
    pub time_value: builtin_interfaces::msg::Time,

}



impl Default for Builtins {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Builtins::default())
  }
}

impl rosidl_runtime_rs::Message for Builtins {
  type RmwMsg = super::msg::rmw::Builtins;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        duration_value: builtin_interfaces::msg::Duration::into_rmw_message(std::borrow::Cow::Owned(msg.duration_value)).into_owned(),
        time_value: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(msg.time_value)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        duration_value: builtin_interfaces::msg::Duration::into_rmw_message(std::borrow::Cow::Borrowed(&msg.duration_value)).into_owned(),
        time_value: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(&msg.time_value)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      duration_value: builtin_interfaces::msg::Duration::from_rmw_message(msg.duration_value),
      time_value: builtin_interfaces::msg::Time::from_rmw_message(msg.time_value),
    }
  }
}


