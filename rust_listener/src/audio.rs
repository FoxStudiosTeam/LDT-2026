use std::path::{Path, PathBuf};

fn resolve_sfx_path(rel_path: &str) -> Option<PathBuf> {
    let p = Path::new(rel_path);
    if p.exists() {
        return Some(p.to_path_buf());
    }

    let candidates = [
        PathBuf::from(rel_path),
        PathBuf::from("../").join(rel_path),
        PathBuf::from("../../").join(rel_path),
    ];

    for c in &candidates {
        if c.exists() {
            return Some(c.clone());
        }
    }

    if let Ok(exe) = std::env::current_exe() {
        if let Some(parent) = exe.parent() {
            let from_exe = parent.join(rel_path);
            if from_exe.exists() {
                return Some(from_exe);
            }
            let from_repo = parent.join("../../../").join(rel_path);
            if from_repo.exists() {
                return Some(from_repo);
            }
        }
    }

    None
}

#[cfg(target_os = "windows")]
mod platform {
    use std::ffi::OsStr;
    use std::os::windows::ffi::OsStrExt;
    use std::path::Path;

    #[link(name = "winmm")]
    unsafe extern "system" {
        fn mciSendStringW(
            lpstrCommand: *const u16,
            lpstrReturnString: *mut u16,
            uReturnLength: u32,
            hwndCallback: usize,
        ) -> u32;
    }

    pub fn play_file(resolved: &Path) {
        let abs = match std::fs::canonicalize(resolved) {
            Ok(p) => p.to_string_lossy().to_string(),
            Err(_) => resolved.to_string_lossy().to_string(),
        };
        let clean = abs.strip_prefix(r"\\?\").unwrap_or(&abs).to_string();

        std::thread::spawn(move || {
            let alias = format!(
                "sfx_{}_{}",
                std::process::id(),
                std::time::SystemTime::now()
                    .duration_since(std::time::UNIX_EPOCH)
                    .unwrap_or_default()
                    .as_nanos()
            );

            let to_wide = |s: &str| -> Vec<u16> {
                OsStr::new(s)
                    .encode_wide()
                    .chain(std::iter::once(0))
                    .collect()
            };

            let open_cmd = to_wide(&format!(
                "open \"{}\" type mpegvideo alias {}",
                clean, alias
            ));
            let play_cmd = to_wide(&format!("play {} wait", alias));
            let close_cmd = to_wide(&format!("close {}", alias));

            unsafe {
                mciSendStringW(open_cmd.as_ptr(), std::ptr::null_mut(), 0, 0);
                mciSendStringW(play_cmd.as_ptr(), std::ptr::null_mut(), 0, 0);
                mciSendStringW(close_cmd.as_ptr(), std::ptr::null_mut(), 0, 0);
            }
        });
    }
}

#[cfg(not(target_os = "windows"))]
mod platform {
    use std::path::Path;

    pub fn play_file(resolved: &Path) {
        let path = resolved.to_string_lossy().to_string();
        std::thread::spawn(move || {
            let _ = std::process::Command::new("ffplay")
                .args(["-nodisp", "-autoexit", &path])
                .output()
                .or_else(|_| {
                    std::process::Command::new("mpv")
                        .args(["--no-video", &path])
                        .output()
                })
                .or_else(|_| std::process::Command::new("paplay").arg(&path).output())
                .or_else(|_| std::process::Command::new("aplay").arg(&path).output())
                .or_else(|_| std::process::Command::new("afplay").arg(&path).output());
        });
    }
}

/// Воспроизводит аудиофайл в неблокирующем фоновом потоке
pub fn play_sound(rel_path: &str) {
    if let Some(path) = resolve_sfx_path(rel_path) {
        platform::play_file(&path);
    } else {
        eprintln!("[Audio] SFX file not found: {}", rel_path);
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_resolve_sfx_files() {
        assert!(resolve_sfx_path("sfx/pop.mp3").is_some());
        assert!(resolve_sfx_path("sfx/music.mp3").is_some());
    }
}
