use std::sync::{Arc, RwLock};

use ddl::{AppPointCloud};
use rerun::RecordingStream;
use ros2_data_extraction::{PointCloudStream, error::Error};

use crate::debug;

pub async fn entry(mut point_cloud_stream : PointCloudStream, recording_stream : RecordingStream, point_cloud : Arc<RwLock<AppPointCloud>>) -> Result<(), Error> {
    let mut frame_id: u64 = 0;

    while let a = point_cloud_stream.next().await? {
        frame_id = a;
        
        let point_cloud = point_cloud.read().map_err(|e| Error::AbstractError { msg: e.to_string() })?;

        let timestamp_ns = point_cloud.timestamp as i64;
        let stats = point_cloud.compute_stats();
        debug::std::print_frame_info(frame_id, timestamp_ns, &stats);
        recording_stream.set_time("ros_time", rerun::TimeCell::from_duration_nanos(timestamp_ns));
        recording_stream.set_time_sequence("frame", frame_id as i64);

        // Пушим данные в сеть (Rerun визуализация)
        debug::helper::log_raw_cloud(&recording_stream, &point_cloud)?;
        debug::helper::log_debug_overlays(&recording_stream, &point_cloud, &stats).map_err(|e| Error::AbstractError { msg: e.to_string() })?;
    }
    
    Ok(())
}