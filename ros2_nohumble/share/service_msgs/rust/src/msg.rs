#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to service_msgs__msg__ServiceEventInfo

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ServiceEventInfo {
    /// The type of event this message represents
    pub event_type: u8,

    /// Timestamp for when the event occurred (sent or received time)
    pub stamp: builtin_interfaces::msg::Time,

    /// Unique identifier for the client that sent the service request
    /// Note, this is only unique for the current session.
    /// The size here has to match the size of rmw_dds_common/msg/Gid,
    /// but unfortunately we cannot use that message directly due to a
    /// circular dependency.
    pub client_gid: [u8; 16],

    /// Sequence number for the request
    /// Combined with the client ID, this creates a unique ID for the service transaction
    pub sequence_number: i64,

}

impl ServiceEventInfo {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const REQUEST_SENT: u8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const REQUEST_RECEIVED: u8 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const RESPONSE_SENT: u8 = 2;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const RESPONSE_RECEIVED: u8 = 3;

}


impl Default for ServiceEventInfo {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::ServiceEventInfo::default())
  }
}

impl rosidl_runtime_rs::Message for ServiceEventInfo {
  type RmwMsg = super::msg::rmw::ServiceEventInfo;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        event_type: msg.event_type,
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(msg.stamp)).into_owned(),
        client_gid: msg.client_gid,
        sequence_number: msg.sequence_number,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      event_type: msg.event_type,
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(&msg.stamp)).into_owned(),
        client_gid: msg.client_gid,
      sequence_number: msg.sequence_number,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      event_type: msg.event_type,
      stamp: builtin_interfaces::msg::Time::from_rmw_message(msg.stamp),
      client_gid: msg.client_gid,
      sequence_number: msg.sequence_number,
    }
  }
}


