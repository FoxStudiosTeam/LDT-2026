use rusqlite::{Connection, OpenFlags};
use shared::configs::DetectionPreset;
use shared::rail_detection::{LidarGeometry, RailTrackDetector};
use shared::range_image::RangeImage;
use shared::transport::PointCloud2;
use std::path::Path;

fn find_pointcloud_topic_id(conn: &Connection) -> Option<i64> {
    if let Ok(mut stmt) =
        conn.prepare("SELECT id FROM topics WHERE type = 'sensor_msgs/msg/PointCloud2' LIMIT 1")
    {
        if let Ok(mut rows) = stmt.query([]) {
            if let Ok(Some(row)) = rows.next() {
                if let Ok(id) = row.get(0) {
                    return Some(id);
                }
            }
        }
    }
    None
}

fn test_file(path_str: &str) {
    println!("\n--- Testing: {} ---", path_str);
    let path = Path::new(path_str);
    let conn = match Connection::open_with_flags(path, OpenFlags::SQLITE_OPEN_READ_ONLY) {
        Ok(c) => c,
        Err(e) => {
            println!("Failed to open DB: {:?}", e);
            return;
        }
    };
    let topic_id = find_pointcloud_topic_id(&conn).unwrap_or(1);
    let mut stmt = match conn.prepare("SELECT data FROM messages WHERE topic_id = ? ORDER BY id") {
        Ok(s) => s,
        Err(e) => {
            println!("Failed to prepare query: {:?}", e);
            return;
        }
    };

    let mut rows = match stmt.query([topic_id]) {
        Ok(r) => r,
        Err(e) => {
            println!("Failed to execute query: {:?}", e);
            return;
        }
    };

    let mut detector: RailTrackDetector = DetectionPreset::current().into();
    let mut frame_idx = 0;
    let mut obstacles_found = 0;

    while let Ok(Some(row)) = rows.next() {
        frame_idx += 1;
        let raw: Vec<u8> = row.get(0).unwrap();
        if let Ok(cloud) = cdr::deserialize::<PointCloud2>(&raw) {
            if let Some(ri) = RangeImage::from_pandar128_point_cloud2(&cloud, Some(40.0)) {
                let geo = LidarGeometry::new(ri.height, ri.width, 15.0, -25.0, 40.0);
                let c_z = detector.obstacle_config.upward_curvature;
                let active_ri = if c_z.abs() > 1e-7 {
                    ri.warp_curvature(&geo, c_z)
                } else {
                    ri.clone()
                };
                if let Some(res) = detector.detect_with_raw(&active_ri, Some(&ri), None, frame_idx)
                {
                    let crit = res.obstacles.iter().filter(|o| o.is_critical).count();
                    let warn = res.obstacles.len() - crit;
                    if crit > 0 || warn > 0 {
                        obstacles_found += 1;
                        if obstacles_found <= 10 {
                            println!(
                                "Frame {}: OBSTACLES: crit={}, warn={}, total={}",
                                frame_idx,
                                crit,
                                warn,
                                res.obstacles.len()
                            );
                        }
                    }
                }
            }
        }
        if frame_idx >= 600 {
            break;
        }
    }
    println!(
        "Scanned {} frames: found obstacles in {} frames",
        frame_idx, obstacles_found
    );
}

fn main() {
    test_file("dataset/cloud_with_fake_obj/cloud_with_fake_obj_0.db3");
}
