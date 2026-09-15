#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to rosbag2_test_msgdefs__msg__ComplexIdl

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ComplexIdl {

    // This member is not documented.
    #[allow(missing_docs)]
    pub a: super::msg::BasicIdl,

}



impl Default for ComplexIdl {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::ComplexIdl::default())
  }
}

impl rosidl_runtime_rs::Message for ComplexIdl {
  type RmwMsg = super::msg::rmw::ComplexIdl;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        a: super::msg::BasicIdl::into_rmw_message(std::borrow::Cow::Owned(msg.a)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        a: super::msg::BasicIdl::into_rmw_message(std::borrow::Cow::Borrowed(&msg.a)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      a: super::msg::BasicIdl::from_rmw_message(msg.a),
    }
  }
}


// Corresponds to rosbag2_test_msgdefs__msg__BasicIdl

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BasicIdl {

    // This member is not documented.
    #[allow(missing_docs)]
    pub x: f32,

}



impl Default for BasicIdl {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::BasicIdl::default())
  }
}

impl rosidl_runtime_rs::Message for BasicIdl {
  type RmwMsg = super::msg::rmw::BasicIdl;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        x: msg.x,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      x: msg.x,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      x: msg.x,
    }
  }
}


// Corresponds to rosbag2_test_msgdefs__msg__ComplexWithRelativeDep

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ComplexWithRelativeDep {

    // This member is not documented.
    #[allow(missing_docs)]
    pub a: super::msg::BasicIdl,

}



impl Default for ComplexWithRelativeDep {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::ComplexWithRelativeDep::default())
  }
}

impl rosidl_runtime_rs::Message for ComplexWithRelativeDep {
  type RmwMsg = super::msg::rmw::ComplexWithRelativeDep;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        a: super::msg::BasicIdl::into_rmw_message(std::borrow::Cow::Owned(msg.a)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        a: super::msg::BasicIdl::into_rmw_message(std::borrow::Cow::Borrowed(&msg.a)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      a: super::msg::BasicIdl::from_rmw_message(msg.a),
    }
  }
}


// Corresponds to rosbag2_test_msgdefs__msg__BasicMsg

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BasicMsg {

    // This member is not documented.
    #[allow(missing_docs)]
    pub c: f32,

}



impl Default for BasicMsg {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::BasicMsg::default())
  }
}

impl rosidl_runtime_rs::Message for BasicMsg {
  type RmwMsg = super::msg::rmw::BasicMsg;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        c: msg.c,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      c: msg.c,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      c: msg.c,
    }
  }
}


// Corresponds to rosbag2_test_msgdefs__msg__AnotherBasicMsg

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct AnotherBasicMsg {

    // This member is not documented.
    #[allow(missing_docs)]
    pub c: f32,

}



impl Default for AnotherBasicMsg {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::AnotherBasicMsg::default())
  }
}

impl rosidl_runtime_rs::Message for AnotherBasicMsg {
  type RmwMsg = super::msg::rmw::AnotherBasicMsg;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        c: msg.c,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      c: msg.c,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      c: msg.c,
    }
  }
}


// Corresponds to rosbag2_test_msgdefs__msg__ComplexMsg

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ComplexMsg {

    // This member is not documented.
    #[allow(missing_docs)]
    pub b: super::msg::BasicMsg,

}



impl Default for ComplexMsg {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::ComplexMsg::default())
  }
}

impl rosidl_runtime_rs::Message for ComplexMsg {
  type RmwMsg = super::msg::rmw::ComplexMsg;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        b: super::msg::BasicMsg::into_rmw_message(std::borrow::Cow::Owned(msg.b)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        b: super::msg::BasicMsg::into_rmw_message(std::borrow::Cow::Borrowed(&msg.b)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      b: super::msg::BasicMsg::from_rmw_message(msg.b),
    }
  }
}


// Corresponds to rosbag2_test_msgdefs__msg__ComplexMsgDependsOnIdl

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ComplexMsgDependsOnIdl {

    // This member is not documented.
    #[allow(missing_docs)]
    pub a: super::msg::BasicIdl,

}



impl Default for ComplexMsgDependsOnIdl {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::ComplexMsgDependsOnIdl::default())
  }
}

impl rosidl_runtime_rs::Message for ComplexMsgDependsOnIdl {
  type RmwMsg = super::msg::rmw::ComplexMsgDependsOnIdl;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        a: super::msg::BasicIdl::into_rmw_message(std::borrow::Cow::Owned(msg.a)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        a: super::msg::BasicIdl::into_rmw_message(std::borrow::Cow::Borrowed(&msg.a)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      a: super::msg::BasicIdl::from_rmw_message(msg.a),
    }
  }
}


