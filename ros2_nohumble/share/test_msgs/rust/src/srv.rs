#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to test_msgs__srv__Arrays_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Arrays_Request {

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

}



impl Default for Arrays_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::Arrays_Request::default())
  }
}

impl rosidl_runtime_rs::Message for Arrays_Request {
  type RmwMsg = super::srv::rmw::Arrays_Request;

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
    }
  }
}


// Corresponds to test_msgs__srv__Arrays_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Arrays_Response {

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

}



impl Default for Arrays_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::Arrays_Response::default())
  }
}

impl rosidl_runtime_rs::Message for Arrays_Response {
  type RmwMsg = super::srv::rmw::Arrays_Response;

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
    }
  }
}


// Corresponds to test_msgs__srv__BasicTypes_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BasicTypes_Request {

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


    // This member is not documented.
    #[allow(missing_docs)]
    pub string_value: std::string::String,

}



impl Default for BasicTypes_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::BasicTypes_Request::default())
  }
}

impl rosidl_runtime_rs::Message for BasicTypes_Request {
  type RmwMsg = super::srv::rmw::BasicTypes_Request;

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
        string_value: msg.string_value.as_str().into(),
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
        string_value: msg.string_value.as_str().into(),
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
      string_value: msg.string_value.to_string(),
    }
  }
}


// Corresponds to test_msgs__srv__BasicTypes_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BasicTypes_Response {

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


    // This member is not documented.
    #[allow(missing_docs)]
    pub string_value: std::string::String,

}



impl Default for BasicTypes_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::BasicTypes_Response::default())
  }
}

impl rosidl_runtime_rs::Message for BasicTypes_Response {
  type RmwMsg = super::srv::rmw::BasicTypes_Response;

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
        string_value: msg.string_value.as_str().into(),
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
        string_value: msg.string_value.as_str().into(),
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
      string_value: msg.string_value.to_string(),
    }
  }
}


// Corresponds to test_msgs__srv__Empty_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Empty_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for Empty_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::Empty_Request::default())
  }
}

impl rosidl_runtime_rs::Message for Empty_Request {
  type RmwMsg = super::srv::rmw::Empty_Request;

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


// Corresponds to test_msgs__srv__Empty_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Empty_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for Empty_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::Empty_Response::default())
  }
}

impl rosidl_runtime_rs::Message for Empty_Response {
  type RmwMsg = super::srv::rmw::Empty_Response;

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






#[link(name = "test_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__test_msgs__srv__Arrays() -> *const std::ffi::c_void;
}

// Corresponds to test_msgs__srv__Arrays
#[allow(missing_docs, non_camel_case_types)]
pub struct Arrays;

impl rosidl_runtime_rs::Service for Arrays {
    type Request = Arrays_Request;
    type Response = Arrays_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__test_msgs__srv__Arrays() }
    }
}




#[link(name = "test_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__test_msgs__srv__BasicTypes() -> *const std::ffi::c_void;
}

// Corresponds to test_msgs__srv__BasicTypes
#[allow(missing_docs, non_camel_case_types)]
pub struct BasicTypes;

impl rosidl_runtime_rs::Service for BasicTypes {
    type Request = BasicTypes_Request;
    type Response = BasicTypes_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__test_msgs__srv__BasicTypes() }
    }
}




#[link(name = "test_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__test_msgs__srv__Empty() -> *const std::ffi::c_void;
}

// Corresponds to test_msgs__srv__Empty
#[allow(missing_docs, non_camel_case_types)]
pub struct Empty;

impl rosidl_runtime_rs::Service for Empty {
    type Request = Empty_Request;
    type Response = Empty_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__test_msgs__srv__Empty() }
    }
}


