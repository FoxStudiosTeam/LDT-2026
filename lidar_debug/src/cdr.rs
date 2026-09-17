//! Очень маленький ручной парсер CDR (Common Data Representation), который
//! умеет вытащить из сырых байт `messages.data` (rosbag2 / sqlite3) ровно то,
//! что нам нужно из `sensor_msgs/msg/PointCloud2`: `point_step`, смещения
//! полей x/y/z и сам буфер точек `data`.
//!
//! Предположения (верны для стандартного ROS 2 Humble + rmw_fastrtps/cyclonedds):
//! - Little-endian CDR2 encapsulation (4-байтный заголовок в начале блоба).
//! - Обычная выравненная CDR-схема (align member по его размеру).
//!
//! Если у вас другой RMW/энкапсуляция — потребуется адаптация `align()`.

use anyhow::{Result, anyhow};

pub struct CdrReader<'a> {
    buf: &'a [u8],
    pos: usize,
}

impl<'a> CdrReader<'a> {
    /// `raw` — это ровно то, что лежит в колонке `data` таблицы `messages`.
    /// Первые 4 байта — RTPS encapsulation header, их пропускаем.
    pub fn new(raw: &'a [u8]) -> Result<Self> {
        if raw.len() < 4 {
            return Err(anyhow!("сообщение короче 4 байт заголовка CDR"));
        }
        Ok(Self { buf: raw, pos: 4 })
    }

    fn align(&mut self, sz: usize) {
        let rem = self.pos % sz;
        if rem != 0 {
            self.pos += sz - rem;
        }
    }

    fn take(&mut self, n: usize) -> Result<&'a [u8]> {
        if self.pos + n > self.buf.len() {
            return Err(anyhow!("CDR: неожиданный конец буфера"));
        }
        let s = &self.buf[self.pos..self.pos + n];
        self.pos += n;
        Ok(s)
    }

    pub fn read_u8(&mut self) -> Result<u8> {
        Ok(self.take(1)?[0])
    }

    pub fn read_bool(&mut self) -> Result<bool> {
        Ok(self.read_u8()? != 0)
    }

    pub fn read_u32(&mut self) -> Result<u32> {
        self.align(4);
        let b = self.take(4)?;
        Ok(u32::from_le_bytes(b.try_into().unwrap()))
    }

    pub fn read_i32(&mut self) -> Result<i32> {
        self.align(4);
        let b = self.take(4)?;
        Ok(i32::from_le_bytes(b.try_into().unwrap()))
    }

    /// CDR string: uint32 length (включая завершающий '\0') + байты.
    pub fn read_string(&mut self) -> Result<String> {
        let len = self.read_u32()? as usize;
        let b = self.take(len)?;
        // отбрасываем завершающий нулевой байт, если он есть
        let s = if len > 0 { &b[..len - 1] } else { b };
        Ok(String::from_utf8_lossy(s).into_owned())
    }

    /// sequence<uint8> data: uint32 length + сырые байты (без доп. выравнивания).
    pub fn read_byte_seq(&mut self) -> Result<&'a [u8]> {
        let len = self.read_u32()? as usize;
        self.take(len)
    }
}

#[derive(Debug, Clone)]
pub struct PointField {
    pub name: String,
    pub offset: u32,
    pub datatype: u8,
    pub count: u32,
}

#[derive(Debug)]
pub struct PointCloud2Header {
    pub height: u32,
    pub width: u32,
    pub fields: Vec<PointField>,
    pub is_bigendian: bool,
    pub point_step: u32,
    pub row_step: u32,
}

/// Разбирает заголовок PointCloud2 и возвращает (header, срез с телом `data`).
pub fn parse_point_cloud2<'a>(raw: &'a [u8]) -> Result<(PointCloud2Header, &'a [u8])> {
    let mut r = CdrReader::new(raw)?;

    // std_msgs/Header
    let _sec = r.read_i32()?;
    let _nanosec = r.read_u32()?;
    let _frame_id = r.read_string()?;

    let height = r.read_u32()?;
    let width = r.read_u32()?;

    let n_fields = r.read_u32()?;
    let mut fields = Vec::with_capacity(n_fields as usize);
    for _ in 0..n_fields {
        let name = r.read_string()?;
        let offset = r.read_u32()?;
        let datatype = r.read_u8()?;
        let count = r.read_u32()?;
        fields.push(PointField {
            name,
            offset,
            datatype,
            count,
        });
    }

    let is_bigendian = r.read_bool()?;
    let point_step = r.read_u32()?;
    let row_step = r.read_u32()?;
    let data = r.read_byte_seq()?;
    let _is_dense = r.read_bool()?;

    Ok((
        PointCloud2Header {
            height,
            width,
            fields,
            is_bigendian,
            point_step,
            row_step,
        },
        data,
    ))
}

/// Достаёт x,y,z (f32) из тела `data`, используя смещения полей.
pub fn extract_xyz(header: &PointCloud2Header, data: &[u8]) -> Result<Vec<[f32; 3]>> {
    if header.is_bigendian {
        return Err(anyhow!("big-endian PointCloud2 не поддержан"));
    }
    let off_x = header
        .fields
        .iter()
        .find(|f| f.name == "x")
        .ok_or_else(|| anyhow!("нет поля x"))?
        .offset as usize;
    let off_y = header
        .fields
        .iter()
        .find(|f| f.name == "y")
        .ok_or_else(|| anyhow!("нет поля y"))?
        .offset as usize;
    let off_z = header
        .fields
        .iter()
        .find(|f| f.name == "z")
        .ok_or_else(|| anyhow!("нет поля z"))?
        .offset as usize;

    let step = header.point_step as usize;
    if step == 0 {
        return Ok(Vec::new());
    }
    let n_points = data.len() / step;
    let mut out = Vec::with_capacity(n_points);

    let read_f32 = |base: &[u8], off: usize| -> f32 {
        f32::from_le_bytes(base[off..off + 4].try_into().unwrap())
    };

    for i in 0..n_points {
        let base = &data[i * step..(i + 1) * step];
        out.push([
            read_f32(base, off_x),
            read_f32(base, off_y),
            read_f32(base, off_z),
        ]);
    }
    Ok(out)
}
