use std::{
    sync::{
        Arc, RwLock,
        atomic::{AtomicUsize, Ordering},
    },
    time::Duration,
};

use rerun::RecordingStream;
use ros2_data_extraction::PointCloudStream;
use shared::error::AppError;
use shared::types::AppPointCloud;
use tokio::{sync::Semaphore, time};
use tracing::*;

use crate::debug;

struct TaskGuard {
    counter: Arc<AtomicUsize>,
}

impl Drop for TaskGuard {
    fn drop(&mut self) {
        // Гарантированный декремент при любом исходе (паника, ошибка, выход)
        self.counter.fetch_sub(1, Ordering::SeqCst);
    }
}

pub async fn entry(
    mut point_cloud_stream: PointCloudStream,
    recording_stream: RecordingStream,
    point_cloud: Arc<RwLock<AppPointCloud>>,
) -> Result<(), AppError> {
    let mut frame_id: u64 = 0;
    let recording_stream = Arc::new(recording_stream);

    while let Some(a) = point_cloud_stream.next().await? {
        frame_id = a;

        info!("[Frame {a}] frame took");

        let point_cloud = point_cloud.clone();
        let recording_stream = recording_stream.clone();

        {
            let mut point_cloud_write = point_cloud.write().expect(&format!("⚠️ Мутекс отравился ☠️ {} {}", file!(), line!()));
            point_cloud_write.can_write = false;
            point_cloud_write.change_state(shared::types::ProcessingQueue::NEXT, shared::types::ProcessingQueue::READ);
            
            // if point_cloud_write.x[queue].len() > 0{
            //     let mut ix = 0; 
            //     let mut i = 0;
            //     tracing::info!("[FRAME] loaded points raw:");
            //     for point in point_cloud_write.iter(queue) {
            //         if *point.0 > 0.0 && ix < 10{
            //             tracing::info!("point {} (x): {:?}, point last (x): {:?}, queue: {}, length: {}, cap: {}", i, point.0, point_cloud_write.x[queue].last(), queue, point_cloud_write.len(queue),AppPointCloud::CAP);
            //             queue.next_step();
            //             tracing::info!("point {} (y): {:?}, point last (y): {:?}, queue: {}, length: {}, cap: {}", i, point.1, point_cloud_write.y[queue].last(), queue, point_cloud_write.len(queue),AppPointCloud::CAP);
            //             queue.next_step();
            //             tracing::info!("point {} (z): {:?}, point last (z): {:?}, queue: {}, length: {}, cap: {}", i, point.2, point_cloud_write.z[queue].last(), queue, point_cloud_write.len(queue),AppPointCloud::CAP);    
            //             ix += 1;
            //         }
            //         i+=1;
            //     }
            //     tracing::info!("[FRAME] loaded points next:");
            //     ix = 0;
            //     i = 0;
            //     queue.
            //     for point in point_cloud_write.iter(queue) {
            //         if *point.0 > 0.0 && ix < 10{
            //             tracing::info!("point {} (x): {:?}, point last (x): {:?}, queue: {}, length: {}, cap: {}", i, point.0, point_cloud_write.x[queue].last(), queue, point_cloud_write.len(queue),AppPointCloud::CAP);
            //             queue.next_step();
            //             tracing::info!("point {} (y): {:?}, point last (y): {:?}, queue: {}, length: {}, cap: {}", i, point.1, point_cloud_write.y[queue].last(), queue, point_cloud_write.len(queue),AppPointCloud::CAP);
            //             queue.next_step();
            //             tracing::info!("point {} (z): {:?}, point last (z): {:?}, queue: {}, length: {}, cap: {}", i, point.2, point_cloud_write.z[queue].last(), queue, point_cloud_write.len(queue),AppPointCloud::CAP);    
            //             ix += 1;
            //         }
            //         i+=1;
            //     }
            // }

            point_cloud_write.can_write = true;
        }
            
        let point_cloud = point_cloud
            .read()
            // отъебнет так, что в логах не покажется
            // .map_err(|e| Error::AbstractError { msg: e.to_string() }).unwrap()
            .expect(&format!("⚠️ Мутекс отравился ☠️ {} {}", file!(), line!()));
            
        let number = shared::types::ProcessingQueue::READ;
            
            
        let timestamp_ns = point_cloud.timestamp[number];
        let stats = point_cloud.compute_stats(number);
            
        //debug::std::print_frame_info(frame_id, timestamp_ns, &stats);
        recording_stream.set_time(
            "ros_time",
                rerun::TimeCell::from_duration_nanos(timestamp_ns),
        );
        recording_stream.set_time_sequence("frame", frame_id as i64);
        // Пушим данные в сеть (Rerun визуализация)
        debug::helper::log_raw_cloud(&recording_stream, &point_cloud).unwrap();
        debug::helper::log_debug_overlays(&recording_stream, &point_cloud, &stats)
        // .map_err(|e| Error::AbstractError { msg: e.to_string() })
        .expect(&format!("⚠️ Мутекс отравился ☠️ {} {}", file!(), line!()));
    }

    Ok(())
}
