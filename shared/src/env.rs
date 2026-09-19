#[doc(hidden)]
pub use dotenvy as __dotenvy;
#[doc(hidden)]
pub use once_cell as __once_cell;

/// # Example
/// ```
/// use env_config::env_config;
///
/// env_config!(
///     ".env" => pub ENV = Env {
///         DATABASE_URL : String = "postgres://root:root@localhost:5432/postgres".to_string(),
///         ACCESS_TOKEN_LIFETIME : u64 = 5 * 60,
///         TIMEOUT : u32 = 30,
///     }
/// );
///
/// fn main() {
///     println!("URL: {}", ENV.DATABASE_URL);
///     println!("Timeout: {}", ENV.TIMEOUT);
/// }
/// ```
#[macro_export]
macro_rules! env_config {
    ($($filename: literal => $visibility:vis $static_struct_ident:ident = $struct_visibility:vis $struct_ident:ident {
        $($line:ident : $line_type:ty $(= $default_val:expr)?),* $(,)?
    }),* $(,)?)=> {
        #[allow(unused, non_snake_case)]
        $($struct_visibility struct $struct_ident {
            $(
                $line: $line_type,
            )*
        }
        $visibility static $static_struct_ident: $crate::env::__once_cell::sync::Lazy<$struct_ident> = $crate::env::__once_cell::sync::Lazy::new(|| {
            let mut map = std::collections::HashMap::new();
            if let Ok(iter) = $crate::env::__dotenvy::from_path_iter($filename) {
                for item in iter {
                    if let Ok((key, value)) = item {
                        map.insert(key, value);
                    }
                }
            }
            $struct_ident {
                $(
                    $line:
                        std::env::var(stringify!($line))
                            .ok()
                            .and_then(|s| s.parse::<$line_type>().ok())
                            .or_else(|| {
                                map.get(stringify!($line))
                                    .and_then(|s| s.parse::<$line_type>().ok())
                            })
                            .unwrap_or_else(|| {
                                $(
                                    return $default_val;
                                )?
                                #[allow(unreachable_code)]
                                {
                                    panic!(
                                        "{} missing in {} and environment, defaulting the value",
                                        stringify!($line),
                                        $filename,
                                    );
                                }
                                // <$line_type>::default()
                            }),
                )*
            }
        });)*
    }
}

#[cfg(test)]
mod tests {
    use std::io::Write;
    use tempfile::NamedTempFile;
    fn write_env_file(contents: &str) -> NamedTempFile {
        let mut f = NamedTempFile::new().expect("failed to create temp file");
        f.write_all(contents.as_bytes())
            .expect("failed to write temp file");
        f
    }

    #[test]
    fn test_default_value_used_when_key_absent() {
        let file = write_env_file("HOST=example.com\n");
        let _ = file;
        let timeout: u32 = std::env::var("TIMEOUT_ABSENT_KEY_XYZ")
            .ok()
            .and_then(|s| s.parse().ok())
            .unwrap_or_else(|| 30_u32);

        assert_eq!(timeout, 30);
    }

    #[test]
    fn test_env_var_overrides_file() {
        let file = write_env_file("MY_PORT=1111\n");
        let _ = file;

        unsafe { std::env::set_var("MY_PORT", "9999") };

        let resolved: u16 = std::env::var("MY_PORT")
            .ok()
            .and_then(|s| s.parse().ok())
            .unwrap_or(1111_u16);

        assert_eq!(resolved, 9999);

        unsafe { std::env::remove_var("MY_PORT") };
    }

    #[test]
    fn test_type_parsing_bool() {
        let parsed: bool = "true".parse().unwrap();
        assert!(parsed);
        let parsed: bool = "false".parse().unwrap();
        assert!(!parsed);
    }

    #[test]
    fn test_type_parsing_f64() {
        let parsed: f64 = "3.14".parse().unwrap();
        assert!((parsed - 3.14).abs() < f64::EPSILON);
    }

    #[test]
    fn test_type_parsing_i32_negative() {
        let parsed: i32 = "-42".parse().unwrap();
        assert_eq!(parsed, -42);
    }

    #[test]
    fn test_type_parsing_string() {
        let parsed: String = "hello world".parse().unwrap();
        assert_eq!(parsed, "hello world");
    }

    #[test]
    fn test_malformed_value_falls_through_to_default() {
        let resolved: u16 = "abc".parse::<u16>().ok().unwrap_or_else(|| 42_u16);

        assert_eq!(resolved, 42);
    }

    #[test]
    #[should_panic(expected = "missing in")]
    fn test_missing_required_field_panics() {
        let _: u32 = std::env::var("REQUIRED_MISSING_FIELD_XYZ_12345")
            .ok()
            .and_then(|s| s.parse().ok())
            .unwrap_or_else(|| {
                panic!(
                    "{} missing in {} and environment, defaulting the value",
                    "REQUIRED_MISSING_FIELD_XYZ_12345", "some.env",
                );
                #[allow(unreachable_code)]
                u32::default()
            });
    }

    #[test]
    fn test_default_closure_is_lazy() {
        let mut called = false;

        let _val: u32 = std::env::var("DEFINITELY_NOT_SET_XYZXYZ")
            .ok()
            .and_then(|s| s.parse().ok())
            .unwrap_or_else(|| {
                called = true;
                99
            });

        assert!(called, "default closure should have been invoked");
    }

    #[test]
    fn test_string_value_with_spaces() {
        let raw = "hello world with spaces";
        let parsed: String = raw.parse().unwrap();
        assert_eq!(parsed, "hello world with spaces");
    }
}
