#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to test_rosidl_buffer__msg__ByteArray
/// Minimal payload message used by the pub/sub launch tests.
/// The `data` field is generated as rosidl::Buffer<uint8_t>, which is the
/// feature under test.

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ByteArray {

    // This member is not documented.
    #[allow(missing_docs)]
    pub seq: u32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub data: Vec<u8>,

}



impl Default for ByteArray {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::ByteArray::default())
  }
}

impl rosidl_runtime_rs::Message for ByteArray {
  type RmwMsg = super::msg::rmw::ByteArray;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        seq: msg.seq,
        data: msg.data.as_slice().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      seq: msg.seq,
        data: msg.data.as_slice().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      seq: msg.seq,
      data: msg.data.into(),
    }
  }
}


// Corresponds to test_rosidl_buffer__msg__ByteArrayList
/// Minimal nested payload used by the pub/sub launch tests.
/// Each ByteArray item contains a uint8[] field generated as rosidl::Buffer<uint8_t>.

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ByteArrayList {

    // This member is not documented.
    #[allow(missing_docs)]
    pub items: Vec<super::msg::ByteArray>,

}



impl Default for ByteArrayList {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::ByteArrayList::default())
  }
}

impl rosidl_runtime_rs::Message for ByteArrayList {
  type RmwMsg = super::msg::rmw::ByteArrayList;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        items: msg.items
          .into_iter()
          .map(|elem| super::msg::ByteArray::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        items: msg.items
          .iter()
          .map(|elem| super::msg::ByteArray::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      items: msg.items
          .into_iter()
          .map(super::msg::ByteArray::from_rmw_message)
          .collect(),
    }
  }
}


// Corresponds to test_rosidl_buffer__msg__TestBufferDescriptor
/// Wire descriptor used by the in-tree test buffer backend.

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TestBufferDescriptor {
    /// number of elements in the original buffer
    pub size: u64,

    /// FNV-1a hash of the element bytes
    pub data_hash: u64,

    /// raw element bytes (size * sizeof(T))
    pub data: Vec<u8>,

}



impl Default for TestBufferDescriptor {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::TestBufferDescriptor::default())
  }
}

impl rosidl_runtime_rs::Message for TestBufferDescriptor {
  type RmwMsg = super::msg::rmw::TestBufferDescriptor;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        size: msg.size,
        data_hash: msg.data_hash,
        data: msg.data.as_slice().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      size: msg.size,
      data_hash: msg.data_hash,
        data: msg.data.as_slice().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      size: msg.size,
      data_hash: msg.data_hash,
      data: msg.data.into(),
    }
  }
}


