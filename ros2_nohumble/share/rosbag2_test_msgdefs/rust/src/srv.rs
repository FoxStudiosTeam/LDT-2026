#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to rosbag2_test_msgdefs__srv__BasicSrv_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BasicSrv_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub req: std::string::String,

}



impl Default for BasicSrv_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::BasicSrv_Request::default())
  }
}

impl rosidl_runtime_rs::Message for BasicSrv_Request {
  type RmwMsg = super::srv::rmw::BasicSrv_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        req: msg.req.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        req: msg.req.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      req: msg.req.to_string(),
    }
  }
}


// Corresponds to rosbag2_test_msgdefs__srv__BasicSrv_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BasicSrv_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub resp: std::string::String,

}



impl Default for BasicSrv_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::BasicSrv_Response::default())
  }
}

impl rosidl_runtime_rs::Message for BasicSrv_Response {
  type RmwMsg = super::srv::rmw::BasicSrv_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        resp: msg.resp.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        resp: msg.resp.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      resp: msg.resp.to_string(),
    }
  }
}


// Corresponds to rosbag2_test_msgdefs__srv__ComplexSrvMsg_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ComplexSrvMsg_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub req: super::msg::BasicMsg,

}



impl Default for ComplexSrvMsg_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::ComplexSrvMsg_Request::default())
  }
}

impl rosidl_runtime_rs::Message for ComplexSrvMsg_Request {
  type RmwMsg = super::srv::rmw::ComplexSrvMsg_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        req: super::msg::BasicMsg::into_rmw_message(std::borrow::Cow::Owned(msg.req)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        req: super::msg::BasicMsg::into_rmw_message(std::borrow::Cow::Borrowed(&msg.req)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      req: super::msg::BasicMsg::from_rmw_message(msg.req),
    }
  }
}


// Corresponds to rosbag2_test_msgdefs__srv__ComplexSrvMsg_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ComplexSrvMsg_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub resp: super::msg::BasicMsg,

}



impl Default for ComplexSrvMsg_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::ComplexSrvMsg_Response::default())
  }
}

impl rosidl_runtime_rs::Message for ComplexSrvMsg_Response {
  type RmwMsg = super::srv::rmw::ComplexSrvMsg_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        resp: super::msg::BasicMsg::into_rmw_message(std::borrow::Cow::Owned(msg.resp)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        resp: super::msg::BasicMsg::into_rmw_message(std::borrow::Cow::Borrowed(&msg.resp)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      resp: super::msg::BasicMsg::from_rmw_message(msg.resp),
    }
  }
}


// Corresponds to rosbag2_test_msgdefs__srv__ComplexSrvIdl_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ComplexSrvIdl_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub req: super::msg::BasicIdl,

}



impl Default for ComplexSrvIdl_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::ComplexSrvIdl_Request::default())
  }
}

impl rosidl_runtime_rs::Message for ComplexSrvIdl_Request {
  type RmwMsg = super::srv::rmw::ComplexSrvIdl_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        req: super::msg::BasicIdl::into_rmw_message(std::borrow::Cow::Owned(msg.req)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        req: super::msg::BasicIdl::into_rmw_message(std::borrow::Cow::Borrowed(&msg.req)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      req: super::msg::BasicIdl::from_rmw_message(msg.req),
    }
  }
}


// Corresponds to rosbag2_test_msgdefs__srv__ComplexSrvIdl_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ComplexSrvIdl_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub resp: super::msg::BasicIdl,

}



impl Default for ComplexSrvIdl_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::ComplexSrvIdl_Response::default())
  }
}

impl rosidl_runtime_rs::Message for ComplexSrvIdl_Response {
  type RmwMsg = super::srv::rmw::ComplexSrvIdl_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        resp: super::msg::BasicIdl::into_rmw_message(std::borrow::Cow::Owned(msg.resp)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        resp: super::msg::BasicIdl::into_rmw_message(std::borrow::Cow::Borrowed(&msg.resp)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      resp: super::msg::BasicIdl::from_rmw_message(msg.resp),
    }
  }
}






#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rosbag2_test_msgdefs__srv__BasicSrv() -> *const std::ffi::c_void;
}

// Corresponds to rosbag2_test_msgdefs__srv__BasicSrv
#[allow(missing_docs, non_camel_case_types)]
pub struct BasicSrv;

impl rosidl_runtime_rs::Service for BasicSrv {
    type Request = BasicSrv_Request;
    type Response = BasicSrv_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rosbag2_test_msgdefs__srv__BasicSrv() }
    }
}




#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rosbag2_test_msgdefs__srv__ComplexSrvMsg() -> *const std::ffi::c_void;
}

// Corresponds to rosbag2_test_msgdefs__srv__ComplexSrvMsg
#[allow(missing_docs, non_camel_case_types)]
pub struct ComplexSrvMsg;

impl rosidl_runtime_rs::Service for ComplexSrvMsg {
    type Request = ComplexSrvMsg_Request;
    type Response = ComplexSrvMsg_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rosbag2_test_msgdefs__srv__ComplexSrvMsg() }
    }
}




#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rosbag2_test_msgdefs__srv__ComplexSrvIdl() -> *const std::ffi::c_void;
}

// Corresponds to rosbag2_test_msgdefs__srv__ComplexSrvIdl
#[allow(missing_docs, non_camel_case_types)]
pub struct ComplexSrvIdl;

impl rosidl_runtime_rs::Service for ComplexSrvIdl {
    type Request = ComplexSrvIdl_Request;
    type Response = ComplexSrvIdl_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rosbag2_test_msgdefs__srv__ComplexSrvIdl() }
    }
}


