#[derive(Debug, serde::Deserialize)]
struct PointCloud2 {
    header: Header,
    height: u32,
    width: u32,
    fields: Vec<PointField>,
    is_bigendian: bool,
    point_step: u32,
    row_step: u32,
    data: Vec<u8>,
    is_dense: bool,
}

#[derive(Debug, serde::Deserialize)]
struct Header {
    stamp: Time,
    frame_id: String,
}

#[derive(Debug, serde::Deserialize)]
struct Time {
    sec: i32,
    nanosec: u32,
}

#[derive(Debug, serde::Deserialize)]
struct PointField {
    name: String,
    offset: u32,
    datatype: u8,
    count: u32,
}
