#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to ros2cli_test_interfaces__msg__ShortVaried
/// A constant

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ShortVaried {
    /// Bool and array of bools
    pub bool_value: bool,

    /// Comment - Nesting Level 1: 2 of 2
    pub bool_values: rosidl_runtime_rs::BoundedSequence<bool, 3>,

}

impl ShortVaried {
    /// Comment - Nesting Level 1: 1 of 2
    pub const BOOL_CONST: bool = true;

}


impl Default for ShortVaried {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::ShortVaried::default())
  }
}

impl rosidl_runtime_rs::Message for ShortVaried {
  type RmwMsg = super::msg::rmw::ShortVaried;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        bool_value: msg.bool_value,
        bool_values: msg.bool_values,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      bool_value: msg.bool_value,
        bool_values: msg.bool_values.clone(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      bool_value: msg.bool_value,
      bool_values: msg.bool_values,
    }
  }
}


// Corresponds to ros2cli_test_interfaces__msg__ShortVariedMultiNested
/// A short, varied, and nested type

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ShortVariedMultiNested {
    /// Comment - Nesting Level 3: 1 of 1
    pub short_varied_nested: super::msg::ShortVariedNested,

}



impl Default for ShortVariedMultiNested {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::ShortVariedMultiNested::default())
  }
}

impl rosidl_runtime_rs::Message for ShortVariedMultiNested {
  type RmwMsg = super::msg::rmw::ShortVariedMultiNested;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        short_varied_nested: super::msg::ShortVariedNested::into_rmw_message(std::borrow::Cow::Owned(msg.short_varied_nested)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        short_varied_nested: super::msg::ShortVariedNested::into_rmw_message(std::borrow::Cow::Borrowed(&msg.short_varied_nested)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      short_varied_nested: super::msg::ShortVariedNested::from_rmw_message(msg.short_varied_nested),
    }
  }
}


// Corresponds to ros2cli_test_interfaces__msg__ShortVariedNested
/// A short, varied type

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ShortVariedNested {
    /// Comment - Nesting Level 2: 1 of 1
    pub short_varied: super::msg::ShortVaried,

}



impl Default for ShortVariedNested {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::ShortVariedNested::default())
  }
}

impl rosidl_runtime_rs::Message for ShortVariedNested {
  type RmwMsg = super::msg::rmw::ShortVariedNested;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        short_varied: super::msg::ShortVaried::into_rmw_message(std::borrow::Cow::Owned(msg.short_varied)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        short_varied: super::msg::ShortVaried::into_rmw_message(std::borrow::Cow::Borrowed(&msg.short_varied)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      short_varied: super::msg::ShortVaried::from_rmw_message(msg.short_varied),
    }
  }
}


