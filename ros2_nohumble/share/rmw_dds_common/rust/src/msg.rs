#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to rmw_dds_common__msg__Gid

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Gid {

    // This member is not documented.
    #[allow(missing_docs)]
    pub data: [u8; 16],

}



impl Default for Gid {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Gid::default())
  }
}

impl rosidl_runtime_rs::Message for Gid {
  type RmwMsg = super::msg::rmw::Gid;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        data: msg.data,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        data: msg.data,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      data: msg.data,
    }
  }
}


// Corresponds to rmw_dds_common__msg__NodeEntitiesInfo

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct NodeEntitiesInfo {

    // This member is not documented.
    #[allow(missing_docs)]
    pub node_namespace: rosidl_runtime_rs::BoundedString<256>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub node_name: rosidl_runtime_rs::BoundedString<256>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub reader_gid_seq: Vec<super::msg::Gid>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub writer_gid_seq: Vec<super::msg::Gid>,

}



impl Default for NodeEntitiesInfo {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::NodeEntitiesInfo::default())
  }
}

impl rosidl_runtime_rs::Message for NodeEntitiesInfo {
  type RmwMsg = super::msg::rmw::NodeEntitiesInfo;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        node_namespace: msg.node_namespace,
        node_name: msg.node_name,
        reader_gid_seq: msg.reader_gid_seq
          .into_iter()
          .map(|elem| super::msg::Gid::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        writer_gid_seq: msg.writer_gid_seq
          .into_iter()
          .map(|elem| super::msg::Gid::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        node_namespace: msg.node_namespace.clone(),
        node_name: msg.node_name.clone(),
        reader_gid_seq: msg.reader_gid_seq
          .iter()
          .map(|elem| super::msg::Gid::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
        writer_gid_seq: msg.writer_gid_seq
          .iter()
          .map(|elem| super::msg::Gid::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      node_namespace: msg.node_namespace,
      node_name: msg.node_name,
      reader_gid_seq: msg.reader_gid_seq
          .into_iter()
          .map(super::msg::Gid::from_rmw_message)
          .collect(),
      writer_gid_seq: msg.writer_gid_seq
          .into_iter()
          .map(super::msg::Gid::from_rmw_message)
          .collect(),
    }
  }
}


// Corresponds to rmw_dds_common__msg__ParticipantEntitiesInfo

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ParticipantEntitiesInfo {

    // This member is not documented.
    #[allow(missing_docs)]
    pub gid: super::msg::Gid,


    // This member is not documented.
    #[allow(missing_docs)]
    pub node_entities_info_seq: Vec<super::msg::NodeEntitiesInfo>,

}



impl Default for ParticipantEntitiesInfo {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::ParticipantEntitiesInfo::default())
  }
}

impl rosidl_runtime_rs::Message for ParticipantEntitiesInfo {
  type RmwMsg = super::msg::rmw::ParticipantEntitiesInfo;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        gid: super::msg::Gid::into_rmw_message(std::borrow::Cow::Owned(msg.gid)).into_owned(),
        node_entities_info_seq: msg.node_entities_info_seq
          .into_iter()
          .map(|elem| super::msg::NodeEntitiesInfo::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        gid: super::msg::Gid::into_rmw_message(std::borrow::Cow::Borrowed(&msg.gid)).into_owned(),
        node_entities_info_seq: msg.node_entities_info_seq
          .iter()
          .map(|elem| super::msg::NodeEntitiesInfo::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      gid: super::msg::Gid::from_rmw_message(msg.gid),
      node_entities_info_seq: msg.node_entities_info_seq
          .into_iter()
          .map(super::msg::NodeEntitiesInfo::from_rmw_message)
          .collect(),
    }
  }
}


