use rusqlite::{Connection, OpenFlags};
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
    if let Ok(mut stmt) = conn.prepare(
        "SELECT id FROM topics WHERE type LIKE '%PointCloud%' OR name LIKE '%point%' LIMIT 1",
    ) {
        if let Ok(mut rows) = stmt.query([]) {
            if let Ok(Some(row)) = rows.next() {
                if let Ok(id) = row.get(0) {
                    return Some(id);
                }
            }
        }
    }
    if let Ok(mut stmt) = conn.prepare("SELECT id FROM topics LIMIT 1") {
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
    println!("Found topic_id: {}", topic_id);

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

    let mut ok_count = 0;
    let mut err_count = 0;

    for i in 0..10 {
        match rows.next() {
            Ok(Some(row)) => {
                let raw: Vec<u8> = row.get(0).unwrap();
                match cdr::deserialize::<PointCloud2>(&raw) {
                    Ok(cloud) => {
                        match RangeImage::from_pandar128_point_cloud2(&cloud, Some(40.0)) {
                            Some(ri) => {
                                ok_count += 1;
                                if i == 0 {
                                    println!(
                                        "Frame 0 OK: {}x{}, points={}",
                                        ri.width,
                                        ri.height,
                                        cloud.width * cloud.height
                                    );
                                }
                            }
                            None => {
                                println!("Frame {}: from_pandar128_point_cloud2 returned None", i);
                                err_count += 1;
                            }
                        }
                    }
                    Err(e) => {
                        println!("Frame {}: cdr::deserialize error: {:?}", i, e);
                        err_count += 1;
                    }
                }
            }
            Ok(None) => {
                println!("Rows ended at i={}", i);
                break;
            }
            Err(e) => {
                println!("Query row error: {:?}", e);
                break;
            }
        }
    }
    println!("Result: {} OK, {} ERR", ok_count, err_count);
}

fn main() {
    test_file("dataset/cloud_with_fake_obj/cloud_with_fake_obj_0.db3");
    test_file("dataset/doubleT_obstacle/doubleT_obstacle_0.db3");
}
