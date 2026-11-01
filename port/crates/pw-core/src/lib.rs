//! `pw-core` — Angelica 2.2 Core Primitives, Codecs, `zlibwapi`, `AFileImage`, and `AIniFile`.
//!
//! Directly mirrors the low-level runtime of Perfect World 1.4.2 (`elementclient.exe` Build 2305,
//! `zlibwapi.dll`, and `unicows.dll`):
//! - Binary little-endian zero-copy cursor (`BinaryCursor` / `BinaryBuilder`)
//! - `AFileImage` stream framing (`0x76da20.c`: `"MOXB"` `0x42584f4d` & `"MOXT"` `0x54584f4d` magic tags)
//! - Native `libz` (`compress2`, `uncompress`, `crc32`, `adler32`, `zlibVersion`) matching `zlibwapi.dll`
//! - `GBK` (`CP936`) <-> `UTF-8` (`glibc` `iconv`) and `UTF-16LE` (`wchar_t`) + `ATaskTempl` XOR codecs
//! - Angelica 3D math primitives (`Vec3`, `Quat`, `Mat4`, `Aabb`, `ColorRgba`, `RectI`)
//! - `IniFile` parser supporting both UTF-16LE BOM (`0xFFFE`) and GBK/ASCII `.ini`/`.cfg` files

use std::collections::BTreeMap;
pub mod zlib_fallback;
#[cfg(unix)]
use std::ffi::{c_char, c_int, c_ulong, c_void, CStr};
use std::fmt;

#[derive(Debug, Clone, PartialEq, Eq)]
pub enum PwError {
    UnexpectedEof { offset: usize, needed: usize, available: usize },
    InvalidMagic { expected: &'static str, found: u32 },
    UnsupportedVersion { format: &'static str, version: u32 },
    ZlibError(i32),
    EncodingError(String),
    InvalidData(String),
    Io(String),
}

impl fmt::Display for PwError {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self {
            PwError::UnexpectedEof { offset, needed, available } => write!(
                f,
                "unexpected EOF at offset {offset:#x}: needed {needed} bytes, {available} remaining"
            ),
            PwError::InvalidMagic { expected, found } => {
                write!(f, "invalid magic (expected {expected}, found {found:#010x})")
            }
            PwError::UnsupportedVersion { format, version } => {
                write!(f, "unsupported {format} version: {version:#x}")
            }
            PwError::ZlibError(code) => write!(f, "zlib error code {code}"),
            PwError::EncodingError(msg) => write!(f, "encoding error: {msg}"),
            PwError::InvalidData(msg) => write!(f, "invalid data: {msg}"),
            PwError::Io(msg) => write!(f, "I/O error: {msg}"),
        }
    }
}

impl std::error::Error for PwError {}

impl From<std::io::Error> for PwError {
    fn from(e: std::io::Error) -> Self {
        PwError::Io(e.to_string())
    }
}

pub type PwResult<T> = Result<T, PwError>;

// ---------------------------------------------------------------------------
// Angelica 3D Math Types (A3DVECTOR3, A3DQUATERNION, A3DMATRIX4, A3DAABB)
// ---------------------------------------------------------------------------

#[derive(Debug, Clone, Copy, PartialEq, Default)]
pub struct Vec3 {
    pub x: f32,
    pub y: f32,
    pub z: f32,
}

impl Vec3 {
    pub const ZERO: Self = Self { x: 0.0, y: 0.0, z: 0.0 };
    pub const UNIT_X: Self = Self { x: 1.0, y: 0.0, z: 0.0 };
    pub const UNIT_Y: Self = Self { x: 0.0, y: 1.0, z: 0.0 };
    pub const UNIT_Z: Self = Self { x: 0.0, y: 0.0, z: 1.0 };

    pub const fn new(x: f32, y: f32, z: f32) -> Self {
        Self { x, y, z }
    }

    pub fn add(self, rhs: Self) -> Self {
        Self::new(self.x + rhs.x, self.y + rhs.y, self.z + rhs.z)
    }

    pub fn sub(self, rhs: Self) -> Self {
        Self::new(self.x - rhs.x, self.y - rhs.y, self.z - rhs.z)
    }

    pub fn scale(self, s: f32) -> Self {
        Self::new(self.x * s, self.y * s, self.z * s)
    }

    pub fn lerp(self, rhs: Self, t: f32) -> Self {
        Self::new(
            self.x + (rhs.x - self.x) * t,
            self.y + (rhs.y - self.y) * t,
            self.z + (rhs.z - self.z) * t,
        )
    }

    pub fn dot(self, rhs: Self) -> f32 {
        self.x * rhs.x + self.y * rhs.y + self.z * rhs.z
    }

    pub fn cross(self, rhs: Self) -> Self {
        Self {
            x: self.y * rhs.z - self.z * rhs.y,
            y: self.z * rhs.x - self.x * rhs.z,
            z: self.x * rhs.y - self.y * rhs.x,
        }
    }

    pub fn length_sq(self) -> f32 {
        self.dot(self)
    }

    pub fn length(self) -> f32 {
        self.length_sq().sqrt()
    }

    pub fn normalized(self) -> Self {
        let len = self.length();
        if len > 1e-6 {
            self.scale(1.0 / len)
        } else {
            Self::UNIT_Z
        }
    }

    pub fn distance(self, other: Self) -> f32 {
        self.sub(other).length()
    }

    pub fn distance_xz(self, other: Self) -> f32 {
        let dx = self.x - other.x;
        let dz = self.z - other.z;
        (dx * dx + dz * dz).sqrt()
    }
}

#[derive(Debug, Clone, Copy, PartialEq)]
pub struct Quat {
    pub x: f32,
    pub y: f32,
    pub z: f32,
    pub w: f32,
}

impl Default for Quat {
    fn default() -> Self {
        Self { x: 0.0, y: 0.0, z: 0.0, w: 1.0 }
    }
}

#[derive(Debug, Clone, Copy, PartialEq)]
pub struct Mat4(pub [[f32; 4]; 4]);

impl Default for Mat4 {
    fn default() -> Self {
        Self::IDENTITY
    }
}

impl Mat4 {
    pub const IDENTITY: Self = Self([
        [1.0, 0.0, 0.0, 0.0],
        [0.0, 1.0, 0.0, 0.0],
        [0.0, 0.0, 1.0, 0.0],
        [0.0, 0.0, 0.0, 1.0],
    ]);

    /// Exact port of Angelica3D `a3d_TransformMatrix` (`elementclient.exe` `0x00788960`):
    /// - `vDir` = normalized forward (`+Z`)
    /// - `vRight = normalize(Cross(vUp, vDir))` (`Up x Dir` in left-handed space)
    /// - `vRealUp = Cross(vDir, vRight)`
    /// - Row-vector `A3DMATRIX4`: `p_out = p_local * M` where rows 0..2 are scaled `vRight`, `vRealUp`, `vDir`,
    ///   and row 3 is `[pos.x, pos.y, pos.z, 1.0]`.
    pub fn a3d_transform_matrix(dir: Vec3, up: Vec3, pos: Vec3, scale: Vec3) -> Self {
        let v_dir = dir.normalized();
        let mut right_raw = up.cross(v_dir);
        if right_raw.length_sq() < 1e-8 {
            let fallback_up = if v_dir.y.abs() < 0.99 { Vec3::UNIT_Y } else { Vec3::UNIT_X };
            right_raw = fallback_up.cross(v_dir);
        }
        let v_right = right_raw.normalized();
        let v_up = v_dir.cross(v_right).normalized();

        Self([
            [v_right.x * scale.x, v_right.y * scale.x, v_right.z * scale.x, 0.0],
            [v_up.x * scale.y, v_up.y * scale.y, v_up.z * scale.y, 0.0],
            [v_dir.x * scale.z, v_dir.y * scale.z, v_dir.z * scale.z, 0.0],
            [pos.x, pos.y, pos.z, 1.0],
        ])
    }

    /// Exact port of Angelica3D `a3d_ViewMatrix` (`A3DCameraBase::UpdateViewTM` left-handed row-vector view matrix).
    pub fn look_to_lh(eye: Vec3, dir: Vec3, up: Vec3) -> Self {
        let zaxis = dir.normalized();
        let mut xaxis_raw = up.cross(zaxis);
        if xaxis_raw.length_sq() < 1e-8 {
            let fallback_up = if zaxis.y.abs() < 0.99 { Vec3::UNIT_Y } else { Vec3::UNIT_Z };
            xaxis_raw = fallback_up.cross(zaxis);
        }
        let xaxis = xaxis_raw.normalized();
        let yaxis = zaxis.cross(xaxis).normalized();

        Self([
            [xaxis.x, yaxis.x, zaxis.x, 0.0],
            [xaxis.y, yaxis.y, zaxis.y, 0.0],
            [xaxis.z, yaxis.z, zaxis.z, 0.0],
            [-xaxis.dot(eye), -yaxis.dot(eye), -zaxis.dot(eye), 1.0],
        ])
    }

    /// Exact port of D3D8/D3D9 `D3DXMatrixPerspectiveFovLH` (row-vector, clip `z in [0, w]`).
    pub fn perspective_fov_lh(fov_y_radians: f32, aspect: f32, zn: f32, zf: f32) -> Self {
        let y_scale = 1.0 / (fov_y_radians * 0.5).tan().max(1e-5);
        let x_scale = y_scale / aspect.max(1e-5);
        let z_range = zf / (zf - zn).max(1e-5);
        Self([
            [x_scale, 0.0, 0.0, 0.0],
            [0.0, y_scale, 0.0, 0.0],
            [0.0, 0.0, z_range, 1.0],
            [0.0, 0.0, -zn * z_range, 0.0],
        ])
    }

    pub fn mul(self, rhs: Self) -> Self {
        let mut out = [[0.0f32; 4]; 4];
        for r in 0..4 {
            for c in 0..4 {
                out[r][c] = self.0[r][0] * rhs.0[0][c]
                    + self.0[r][1] * rhs.0[1][c]
                    + self.0[r][2] * rhs.0[2][c]
                    + self.0[r][3] * rhs.0[3][c];
            }
        }
        Self(out)
    }

    #[inline]
    pub fn transform_point(self, p: Vec3) -> Vec3 {
        let m = &self.0;
        Vec3::new(
            p.x * m[0][0] + p.y * m[1][0] + p.z * m[2][0] + m[3][0],
            p.x * m[0][1] + p.y * m[1][1] + p.z * m[2][1] + m[3][1],
            p.x * m[0][2] + p.y * m[1][2] + p.z * m[2][2] + m[3][2],
        )
    }

    #[inline]
    pub fn transform_vector(self, v: Vec3) -> Vec3 {
        let m = &self.0;
        Vec3::new(
            v.x * m[0][0] + v.y * m[1][0] + v.z * m[2][0],
            v.x * m[0][1] + v.y * m[1][1] + v.z * m[2][1],
            v.x * m[0][2] + v.y * m[1][2] + v.z * m[2][2],
        )
    }

    #[inline]
    pub fn transform_vec4(self, p: Vec3) -> [f32; 4] {
        let m = &self.0;
        [
            p.x * m[0][0] + p.y * m[1][0] + p.z * m[2][0] + m[3][0],
            p.x * m[0][1] + p.y * m[1][1] + p.z * m[2][1] + m[3][1],
            p.x * m[0][2] + p.y * m[1][2] + p.z * m[2][2] + m[3][2],
            p.x * m[0][3] + p.y * m[1][3] + p.z * m[2][3] + m[3][3],
        ]
    }
}

#[derive(Debug, Clone, Copy, PartialEq, Default)]
pub struct Aabb {
    pub mins: Vec3,
    pub maxs: Vec3,
}

impl Aabb {
    pub fn empty() -> Self {
        Self {
            mins: Vec3::new(f32::INFINITY, f32::INFINITY, f32::INFINITY),
            maxs: Vec3::new(f32::NEG_INFINITY, f32::NEG_INFINITY, f32::NEG_INFINITY),
        }
    }

    pub fn expand_point(&mut self, p: Vec3) {
        self.mins.x = self.mins.x.min(p.x);
        self.mins.y = self.mins.y.min(p.y);
        self.mins.z = self.mins.z.min(p.z);
        self.maxs.x = self.maxs.x.max(p.x);
        self.maxs.y = self.maxs.y.max(p.y);
        self.maxs.z = self.maxs.z.max(p.z);
    }

    pub fn center(&self) -> Vec3 {
        self.mins.add(self.maxs).scale(0.5)
    }

    pub fn radius(&self) -> f32 {
        self.maxs.sub(self.mins).length() * 0.5
    }

    pub fn transform(&self, mat: Mat4) -> Self {
        let mut out = Self::empty();
        let xs = [self.mins.x, self.maxs.x];
        let ys = [self.mins.y, self.maxs.y];
        let zs = [self.mins.z, self.maxs.z];
        for &x in &xs {
            for &y in &ys {
                for &z in &zs {
                    out.expand_point(mat.transform_point(Vec3::new(x, y, z)));
                }
            }
        }
        out
    }
}

#[derive(Debug, Clone, Copy, PartialEq, Eq, Default)]
pub struct RectI {
    pub left: i32,
    pub top: i32,
    pub right: i32,
    pub bottom: i32,
}

#[derive(Debug, Clone, Copy, PartialEq, Eq, Default)]
pub struct ColorRgba {
    pub r: u8,
    pub g: u8,
    pub b: u8,
    pub a: u8,
}

impl ColorRgba {
    pub const fn from_argb_u32(v: u32) -> Self {
        Self {
            a: ((v >> 24) & 0xff) as u8,
            r: ((v >> 16) & 0xff) as u8,
            g: ((v >> 8) & 0xff) as u8,
            b: (v & 0xff) as u8,
        }
    }
}

// ---------------------------------------------------------------------------
// Binary Little-Endian Cursor & Builder
// ---------------------------------------------------------------------------

#[derive(Clone, Copy)]
pub struct BinaryCursor<'a> {
    buf: &'a [u8],
    pos: usize,
}

impl<'a> BinaryCursor<'a> {
    pub fn new(buf: &'a [u8]) -> Self {
        Self { buf, pos: 0 }
    }

    pub fn position(&self) -> usize {
        self.pos
    }

    pub fn len(&self) -> usize {
        self.buf.len()
    }

    pub fn is_empty(&self) -> bool {
        self.buf.is_empty()
    }

    pub fn remaining(&self) -> usize {
        self.buf.len().saturating_sub(self.pos)
    }

    pub fn as_slice(&self) -> &'a [u8] {
        self.buf
    }

    pub fn remaining_slice(&self) -> &'a [u8] {
        &self.buf[self.pos..]
    }

    pub fn set_position(&mut self, pos: usize) -> PwResult<()> {
        if pos > self.buf.len() {
            return Err(PwError::UnexpectedEof {
                offset: self.pos,
                needed: pos - self.pos,
                available: self.remaining(),
            });
        }
        self.pos = pos;
        Ok(())
    }

    pub fn skip(&mut self, count: usize) -> PwResult<()> {
        let _ = self.read_bytes(count)?;
        Ok(())
    }

    pub fn read_bytes(&mut self, count: usize) -> PwResult<&'a [u8]> {
        if self.remaining() < count {
            return Err(PwError::UnexpectedEof {
                offset: self.pos,
                needed: count,
                available: self.remaining(),
            });
        }
        let s = &self.buf[self.pos..self.pos + count];
        self.pos += count;
        Ok(s)
    }

    pub fn read_u8(&mut self) -> PwResult<u8> {
        Ok(self.read_bytes(1)?[0])
    }

    pub fn read_i8(&mut self) -> PwResult<i8> {
        Ok(self.read_u8()? as i8)
    }

    pub fn read_bool_u8(&mut self) -> PwResult<bool> {
        Ok(self.read_u8()? != 0)
    }

    pub fn read_u16_le(&mut self) -> PwResult<u16> {
        let b = self.read_bytes(2)?;
        Ok(u16::from_le_bytes([b[0], b[1]]))
    }

    pub fn read_i16_le(&mut self) -> PwResult<i16> {
        Ok(self.read_u16_le()? as i16)
    }

    pub fn read_u32_le(&mut self) -> PwResult<u32> {
        let b = self.read_bytes(4)?;
        Ok(u32::from_le_bytes([b[0], b[1], b[2], b[3]]))
    }

    pub fn read_i32_le(&mut self) -> PwResult<i32> {
        Ok(self.read_u32_le()? as i32)
    }

    pub fn read_u64_le(&mut self) -> PwResult<u64> {
        let b = self.read_bytes(8)?;
        Ok(u64::from_le_bytes([b[0], b[1], b[2], b[3], b[4], b[5], b[6], b[7]]))
    }

    pub fn read_f32_le(&mut self) -> PwResult<f32> {
        Ok(f32::from_bits(self.read_u32_le()?))
    }

    pub fn read_vec3_le(&mut self) -> PwResult<Vec3> {
        Ok(Vec3 {
            x: self.read_f32_le()?,
            y: self.read_f32_le()?,
            z: self.read_f32_le()?,
        })
    }

    pub fn read_fixed_utf16le(&mut self, byte_len: usize) -> PwResult<String> {
        let raw = self.read_bytes(byte_len)?;
        Ok(decode_utf16le_null_terminated(raw))
    }

    pub fn read_fixed_gbk(&mut self, byte_len: usize) -> PwResult<String> {
        let raw = self.read_bytes(byte_len)?;
        Ok(decode_gbk_null_terminated(raw))
    }

    /// Reads an Angelica `AFile::ReadString` length-prefixed GBK string (`i32 byte_len` + `byte_len` bytes).
    pub fn read_astring_gbk(&mut self) -> PwResult<String> {
        let len = self.read_i32_le()?;
        if len <= 0 {
            return Ok(String::new());
        }
        let raw = self.read_bytes(len as usize)?;
        Ok(decode_gbk_null_terminated(raw))
    }

    pub fn read_mat4_le(&mut self) -> PwResult<Mat4> {
        let mut m = [[0.0f32; 4]; 4];
        for r in &mut m {
            for c in r {
                *c = self.read_f32_le()?;
            }
        }
        Ok(Mat4(m))
    }
}

#[derive(Default, Clone)]
pub struct BinaryBuilder {
    buf: Vec<u8>,
}

impl BinaryBuilder {
    pub fn with_capacity(cap: usize) -> Self {
        Self { buf: Vec::with_capacity(cap) }
    }

    pub fn len(&self) -> usize {
        self.buf.len()
    }

    pub fn is_empty(&self) -> bool {
        self.buf.is_empty()
    }

    pub fn into_vec(self) -> Vec<u8> {
        self.buf
    }

    pub fn as_slice(&self) -> &[u8] {
        &self.buf
    }

    pub fn write_bytes(&mut self, data: &[u8]) {
        self.buf.extend_from_slice(data);
    }

    pub fn write_u8(&mut self, v: u8) {
        self.buf.push(v);
    }

    pub fn write_u16_le(&mut self, v: u16) {
        self.buf.extend_from_slice(&v.to_le_bytes());
    }

    pub fn write_i16_le(&mut self, v: i16) {
        self.buf.extend_from_slice(&v.to_le_bytes());
    }

    pub fn write_u32_le(&mut self, v: u32) {
        self.buf.extend_from_slice(&v.to_le_bytes());
    }

    pub fn write_i32_le(&mut self, v: i32) {
        self.buf.extend_from_slice(&v.to_le_bytes());
    }

    pub fn write_f32_le(&mut self, v: f32) {
        self.buf.extend_from_slice(&v.to_bits().to_le_bytes());
    }

    pub fn patch_u32_le(&mut self, offset: usize, v: u32) {
        self.buf[offset..offset + 4].copy_from_slice(&v.to_le_bytes());
    }
}

// ---------------------------------------------------------------------------
// AFileImage Magic Framing (`0x76da20.c`: "MOXB" / "MOXT")
// ---------------------------------------------------------------------------

/// `0x42584f4d` (`"MOXB"` in little-endian).
pub const AFILE_MAGIC_MOXB: u32 = 0x4258_4f4d;
/// `0x54584f4d` (`"MOXT"` in little-endian).
pub const AFILE_MAGIC_MOXT: u32 = 0x5458_4f4d;

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum AFileMode {
    BinaryMoxb,
    TextMoxt,
    RawUnprefixed,
}

/// Mirrors `AFileImage::Open` (`0x76da20.c`): strips `"MOXB"` or `"MOXT"` 4-byte prefix if present.
pub fn open_afile_image(data: &[u8]) -> (AFileMode, BinaryCursor<'_>) {
    if data.len() >= 4 {
        let tag = u32::from_le_bytes([data[0], data[1], data[2], data[3]]);
        if tag == AFILE_MAGIC_MOXB {
            return (AFileMode::BinaryMoxb, BinaryCursor::new(&data[4..]));
        }
        if tag == AFILE_MAGIC_MOXT {
            return (AFileMode::TextMoxt, BinaryCursor::new(&data[4..]));
        }
    }
    (AFileMode::RawUnprefixed, BinaryCursor::new(data))
}

// ---------------------------------------------------------------------------
// Cross-Platform `zlib` (`zlibwapi.dll` 1:1 FFI on Unix + Pure-Rust RFC 1950/1951 on Windows)
// ---------------------------------------------------------------------------

#[cfg(unix)]
#[link(name = "z")]
unsafe extern "C" {
    fn uncompress(
        dest: *mut u8,
        dest_len: *mut c_ulong,
        source: *const u8,
        source_len: c_ulong,
    ) -> c_int;
    fn compress2(
        dest: *mut u8,
        dest_len: *mut c_ulong,
        source: *const u8,
        source_len: c_ulong,
        level: c_int,
    ) -> c_int;
    fn crc32(crc: c_ulong, buf: *const u8, len: u32) -> c_ulong;
    fn adler32(adler: c_ulong, buf: *const u8, len: u32) -> c_ulong;
    fn zlibVersion() -> *const c_char;
}

pub fn zlib_version() -> &'static str {
    #[cfg(unix)]
    unsafe {
        let ptr = zlibVersion();
        if ptr.is_null() {
            "unknown"
        } else {
            CStr::from_ptr(ptr).to_str().unwrap_or("unknown")
        }
    }
    #[cfg(not(unix))]
    {
        "1.2.13-pure-rust-rfc1950"
    }
}

pub fn zlib_uncompress(compressed: &[u8], expected_uncompressed_len: usize) -> PwResult<Vec<u8>> {
    #[cfg(unix)]
    {
        if expected_uncompressed_len == 0 {
            return Ok(Vec::new());
        }
        let mut out = vec![0u8; expected_uncompressed_len];
        let mut dst_len = expected_uncompressed_len as c_ulong;
        let rc = unsafe {
            uncompress(
                out.as_mut_ptr(),
                &mut dst_len,
                compressed.as_ptr(),
                compressed.len() as c_ulong,
            )
        };
        if rc != 0 {
            return Err(PwError::ZlibError(rc));
        }
        out.truncate(dst_len as usize);
        Ok(out)
    }
    #[cfg(not(unix))]
    {
        zlib_fallback::pure_zlib_uncompress(compressed, expected_uncompressed_len)
    }
}

pub fn zlib_compress(input: &[u8], _level: i32) -> PwResult<Vec<u8>> {
    #[cfg(unix)]
    {
        let bound = input.len() + (input.len() >> 12) + (input.len() >> 14) + (input.len() >> 25) + 32;
        let mut out = vec![0u8; bound];
        let mut dst_len = bound as c_ulong;
        let rc = unsafe {
            compress2(
                out.as_mut_ptr(),
                &mut dst_len,
                input.as_ptr(),
                input.len() as c_ulong,
                _level as c_int,
            )
        };
        if rc != 0 {
            return Err(PwError::ZlibError(rc));
        }
        out.truncate(dst_len as usize);
        Ok(out)
    }
    #[cfg(not(unix))]
    {
        Ok(zlib_fallback::pure_zlib_compress(input))
    }
}

pub fn zlib_crc32(data: &[u8]) -> u32 {
    #[cfg(unix)]
    unsafe {
        let init = crc32(0, std::ptr::null(), 0);
        crc32(init, data.as_ptr(), data.len() as u32) as u32
    }
    #[cfg(not(unix))]
    {
        zlib_fallback::pure_crc32(data)
    }
}

pub fn zlib_adler32(data: &[u8]) -> u32 {
    #[cfg(unix)]
    unsafe {
        let init = adler32(0, std::ptr::null(), 0);
        adler32(init, data.as_ptr(), data.len() as u32) as u32
    }
    #[cfg(not(unix))]
    {
        zlib_fallback::pure_adler32(data)
    }
}

// ---------------------------------------------------------------------------
// GBK (`CP936`) & UTF-16LE (`wchar_t` + `ATaskTempl` XOR) String Codecs
// (`iconv` on Linux/macOS, `kernel32` CodePage 936 on Windows)
// ---------------------------------------------------------------------------

#[cfg(unix)]
#[cfg_attr(target_os = "macos", link(name = "iconv"))]
unsafe extern "C" {
    fn iconv_open(tocode: *const c_char, fromcode: *const c_char) -> *mut c_void;
    fn iconv(
        cd: *mut c_void,
        inbuf: *mut *const u8,
        inbytesleft: *mut usize,
        outbuf: *mut *mut u8,
        outbytesleft: *mut usize,
    ) -> usize;
    fn iconv_close(cd: *mut c_void) -> c_int;
}

#[cfg(unix)]
fn iconv_convert(from: &[u8], to_enc: &[u8], from_enc: &[u8]) -> Option<Vec<u8>> {
    if from.is_empty() {
        return Some(Vec::new());
    }
    unsafe {
        let cd = iconv_open(to_enc.as_ptr() as *const c_char, from_enc.as_ptr() as *const c_char);
        if (cd as isize) == -1 {
            return None;
        }
        let mut out = vec![0u8; from.len() * 4 + 16];
        let mut in_ptr = from.as_ptr();
        let mut in_left = from.len();
        let mut out_ptr = out.as_mut_ptr();
        let mut out_left = out.len();
        let rc = iconv(cd, &mut in_ptr, &mut in_left, &mut out_ptr, &mut out_left);
        iconv_close(cd);
        if rc == usize::MAX {
            return None;
        }
        let written = out.len() - out_left;
        out.truncate(written);
        Some(out)
    }
}

#[cfg(windows)]
#[link(name = "kernel32")]
unsafe extern "system" {
    fn MultiByteToWideChar(
        code_page: u32,
        dw_flags: u32,
        lp_multi_byte_str: *const u8,
        cb_multi_byte: i32,
        lp_wide_char_str: *mut u16,
        cch_wide_char: i32,
    ) -> i32;
    fn WideCharToMultiByte(
        code_page: u32,
        dw_flags: u32,
        lp_wide_char_str: *const u16,
        cch_wide_char: i32,
        lp_multi_byte_str: *mut u8,
        cb_multi_byte: i32,
        lp_default_char: *const u8,
        lp_used_default_char: *mut i32,
    ) -> i32;
}

pub fn decode_gbk(bytes: &[u8]) -> String {
    if bytes.is_empty() || bytes.iter().all(|&b| b < 0x80) {
        return String::from_utf8_lossy(bytes).into_owned();
    }
    #[cfg(unix)]
    if let Some(utf8) = iconv_convert(bytes, b"UTF-8//IGNORE\0", b"GBK\0") {
        if let Ok(s) = String::from_utf8(utf8) {
            return s;
        }
    }
    #[cfg(windows)]
    unsafe {
        const CP_GBK: u32 = 936;
        let wlen = MultiByteToWideChar(CP_GBK, 0, bytes.as_ptr(), bytes.len() as i32, std::ptr::null_mut(), 0);
        if wlen > 0 {
            let mut wide = vec![0u16; wlen as usize];
            let written = MultiByteToWideChar(CP_GBK, 0, bytes.as_ptr(), bytes.len() as i32, wide.as_mut_ptr(), wlen);
            if written > 0 {
                return String::from_utf16_lossy(&wide[..written as usize]);
            }
        }
    }
    String::from_utf8_lossy(bytes).into_owned()
}

pub fn decode_gbk_null_terminated(bytes: &[u8]) -> String {
    let end = bytes.iter().position(|&b| b == 0).unwrap_or(bytes.len());
    decode_gbk(&bytes[..end])
}

pub fn encode_gbk(text: &str) -> Vec<u8> {
    if text.is_empty() || text.is_ascii() {
        return text.as_bytes().to_vec();
    }
    #[cfg(unix)]
    if let Some(gbk) = iconv_convert(text.as_bytes(), b"GBK//IGNORE\0", b"UTF-8\0") {
        return gbk;
    }
    #[cfg(windows)]
    unsafe {
        const CP_GBK: u32 = 936;
        let wide: Vec<u16> = text.encode_utf16().collect();
        let blen = WideCharToMultiByte(
            CP_GBK, 0, wide.as_ptr(), wide.len() as i32,
            std::ptr::null_mut(), 0, std::ptr::null(), std::ptr::null_mut(),
        );
        if blen > 0 {
            let mut out = vec![0u8; blen as usize];
            let written = WideCharToMultiByte(
                CP_GBK, 0, wide.as_ptr(), wide.len() as i32,
                out.as_mut_ptr(), blen, std::ptr::null(), std::ptr::null_mut(),
            );
            if written > 0 {
                out.truncate(written as usize);
                return out;
            }
        }
    }
    text.as_bytes().to_vec()
}

pub fn decode_utf16le_null_terminated(bytes: &[u8]) -> String {
    decode_utf16le_xor_null_terminated(bytes, 0)
}

/// Decodes UTF-16LE `wchar_t` buffer where each 16-bit code unit is XORed with `xor_key`
/// (`key = 0` for plain UTF-16LE, or `key = (m_ID & 0xFFFF) as u16` for `ATaskTempl` strings).
pub fn decode_utf16le_xor_null_terminated(bytes: &[u8], xor_key: u16) -> String {
    let mut units = Vec::with_capacity(bytes.len() / 2);
    for chunk in bytes.chunks_exact(2) {
        let u = u16::from_le_bytes([chunk[0], chunk[1]]) ^ xor_key;
        if u == 0 {
            break;
        }
        units.push(u);
    }
    String::from_utf16_lossy(&units)
}

pub fn encode_utf16le_xor(text: &str, xor_key: u16, null_terminate: bool) -> Vec<u8> {
    let mut out = Vec::with_capacity((text.len() + 1) * 2);
    for u in text.encode_utf16() {
        out.extend_from_slice(&(u ^ xor_key).to_le_bytes());
    }
    if null_terminate {
        out.extend_from_slice(&xor_key.to_le_bytes());
    }
    out
}

/// Normalizes an Angelica VFS path: trims leading slashes, converts `/` -> `\`, ASCII-lowercases.
pub fn normalize_vfs_path(path: &str) -> String {
    let trimmed = path.trim().trim_start_matches(['/', '\\']);
    let mut out = String::with_capacity(trimmed.len());
    for ch in trimmed.chars() {
        if ch == '/' {
            out.push('\\');
        } else {
            out.push(ch.to_ascii_lowercase());
        }
    }
    out
}

// ---------------------------------------------------------------------------
// Angelica INI / CFG Parser (`AIniFile`: UTF-16LE BOM + GBK/UTF-8)
// ---------------------------------------------------------------------------

#[derive(Debug, Clone, Default)]
pub struct IniFile {
    pub sections: BTreeMap<String, BTreeMap<String, String>>,
}

impl IniFile {
    pub fn parse_bytes(bytes: &[u8]) -> Self {
        let content = if bytes.starts_with(&[0xFF, 0xFE]) {
            decode_utf16le_null_terminated(&bytes[2..])
        } else if bytes.starts_with(&[0xEF, 0xBB, 0xBF]) {
            String::from_utf8_lossy(&bytes[3..]).into_owned()
        } else {
            decode_gbk(bytes)
        };
        Self::parse_str(&content)
    }

    pub fn parse_str(text: &str) -> Self {
        let mut sections: BTreeMap<String, BTreeMap<String, String>> = BTreeMap::new();
        let mut current_section = String::new();

        for raw_line in text.lines() {
            let line = raw_line.trim();
            if line.is_empty() || line.starts_with(';') || line.starts_with('#') || line.starts_with("//") {
                continue;
            }
            if line.starts_with('[') && line.ends_with(']') {
                current_section = line[1..line.len() - 1].trim().to_string();
                sections.entry(current_section.clone()).or_default();
                continue;
            }
            if let Some((k, v)) = line.split_once('=') {
                sections
                    .entry(current_section.clone())
                    .or_default()
                    .insert(k.trim().to_string(), v.trim().to_string());
            }
        }

        Self { sections }
    }

    pub fn get(&self, section: &str, key: &str) -> Option<&str> {
        self.sections
            .get(section)
            .and_then(|sec| sec.get(key))
            .map(String::as_str)
    }

    pub fn get_i32(&self, section: &str, key: &str) -> Option<i32> {
        self.get(section, key)?.parse().ok()
    }

    pub fn get_f32(&self, section: &str, key: &str) -> Option<f32> {
        self.get(section, key)?.parse().ok()
    }
}


/// Reads a file from disk and attaches the full path on failure (avoiding bare OS error 2/3 messages).
pub fn read_file_checked(path: impl AsRef<std::path::Path>) -> PwResult<Vec<u8>> {
    let p = path.as_ref();
    std::fs::read(p).map_err(|e| PwError::Io(format!("'{}': {}", p.display(), e)))
}

/// Resolves a relative path inside `base` case-insensitively (matching Windows NTFS semantics on Unix).
pub fn find_path_case_insensitive(
    base: impl AsRef<std::path::Path>,
    rel: &str,
) -> Option<std::path::PathBuf> {
    let mut cur = base.as_ref().to_path_buf();
    let direct = cur.join(rel.replace('\\', "/"));
    if direct.exists() {
        return Some(direct);
    }
    for part in rel.split(['/', '\\']).filter(|s| !s.is_empty() && *s != ".") {
        let exact = cur.join(part);
        if exact.exists() {
            cur = exact;
            continue;
        }
        let entries = std::fs::read_dir(&cur).ok()?;
        let mut matched = None;
        for ent in entries.flatten() {
            if ent
                .file_name()
                .to_str()
                .map(|n| n.eq_ignore_ascii_case(part))
                .unwrap_or(false)
            {
                matched = Some(ent.path());
                break;
            }
        }
        cur = matched?;
    }
    Some(cur)
}

/// Returns `true` if a CLI token is an `elementclient.exe` / `eSTART.bat` or Rust port flag rather than a directory path.
pub fn is_cli_flag_token(tok: &str) -> bool {
    let t = tok.trim().to_ascii_lowercase();
    t.starts_with('-')
        || t == "nocheck"
        || t == "startbypatcher"
        || t == "nofullscreen"
        || t.starts_with("game:")
        || t.starts_with("console:")
        || t.starts_with("server:")
        || t.starts_with("user:")
        || t.starts_with("pwd:")
        || t.starts_with("role:")
}

/// Resolves the `pw142/element` directory from an optional CLI argument, executable directory,
/// working directory, or sibling `../source/pw142/element` directory.
/// Also accepts the parent `pw142` directory and automatically descends into `element/`.
pub fn resolve_element_root(cli_arg: Option<&str>) -> PwResult<std::path::PathBuf> {
    let normalize_candidate = |cand: &std::path::Path| -> Option<std::path::PathBuf> {
        if find_path_case_insensitive(cand, "configs.pck").is_some()
            || find_path_case_insensitive(cand, "data/elements.data").is_some()
        {
            return Some(cand.to_path_buf());
        }
        if let Some(sub) = find_path_case_insensitive(cand, "element") {
            if find_path_case_insensitive(&sub, "configs.pck").is_some()
                || find_path_case_insensitive(&sub, "data/elements.data").is_some()
            {
                return Some(sub);
            }
        }
        None
    };

    if let Some(arg) = cli_arg.filter(|a| !is_cli_flag_token(a)) {
        let p = std::path::PathBuf::from(arg.trim_matches('"'));
        if let Some(found) = normalize_candidate(&p) {
            return Ok(found);
        }
        return Err(PwError::Io(format!(
            "Could not find Perfect World 1.4.2 'element' files (configs.pck / data/elements.data) inside '{}'",
            p.display()
        )));
    }

    let mut search_roots: Vec<std::path::PathBuf> = Vec::new();
    if let Ok(exe) = std::env::current_exe() {
        if let Some(exe_dir) = exe.parent() {
            search_roots.push(exe_dir.to_path_buf());
            if let Some(p1) = exe_dir.parent() {
                search_roots.push(p1.to_path_buf());
                if let Some(p2) = p1.parent() {
                    search_roots.push(p2.to_path_buf());
                    search_roots.push(p2.join("../source/pw142"));
                }
            }
        }
    }
    if let Ok(cwd) = std::env::current_dir() {
        search_roots.push(cwd.clone());
        search_roots.push(cwd.join("pw142"));
        search_roots.push(cwd.join("source/pw142"));
        search_roots.push(cwd.join("../pw142"));
        search_roots.push(cwd.join("../source/pw142"));
        search_roots.push(cwd.join("../../source/pw142"));
        search_roots.push(cwd.join("../../../source/pw142"));
    }
    if let Ok(env_elem) = std::env::var("PW142_ELEMENT_DIR") {
        search_roots.insert(0, std::path::PathBuf::from(env_elem));
    }
    if let Ok(env_root) = std::env::var("PW142_ROOT") {
        search_roots.insert(0, std::path::PathBuf::from(env_root));
    }

    for cand in &search_roots {
        if let Some(found) = normalize_candidate(cand) {
            return Ok(found);
        }
    }

    Err(PwError::Io(
        "Could not auto-locate your 'pw142/element' folder. Pass its path explicitly:\n  pw-elementclient \"C:\\path\\to\\pw142\\element\""
            .to_string(),
    ))
}

/// Resolves the top-level `pw142` installation directory (parent of `element/`, `launcher/`, `patcher/`).
pub fn resolve_pw142_root(cli_arg: Option<&str>) -> PwResult<std::path::PathBuf> {
    if let Some(arg) = cli_arg {
        let p = std::path::PathBuf::from(arg.trim_matches('"'));
        if p.join("element").is_dir() || p.join("patcher").is_dir() || p.join("launcher").is_dir() {
            return Ok(p);
        }
        if p.file_name().and_then(|n| n.to_str()).map(|s| s.eq_ignore_ascii_case("element")).unwrap_or(false) {
            if let Some(parent) = p.parent() {
                return Ok(parent.to_path_buf());
            }
        }
    }
    let elem = resolve_element_root(cli_arg)?;
    Ok(elem.parent().map(|p| p.to_path_buf()).unwrap_or(elem))
}

/// Resolves the `pw142/element/data` directory.
pub fn resolve_data_dir(cli_arg: Option<&str>) -> PwResult<std::path::PathBuf> {
    if let Some(arg) = cli_arg {
        let p = std::path::PathBuf::from(arg.trim_matches('"'));
        if p.join("elements.data").is_file() {
            return Ok(p);
        }
        if p.join("data").join("elements.data").is_file() {
            return Ok(p.join("data"));
        }
        if p.join("element").join("data").join("elements.data").is_file() {
            return Ok(p.join("element").join("data"));
        }
    }
    Ok(resolve_element_root(cli_arg)?.join("data"))
}

/// Locates the `pw142` root directory for integration tests via `PW142_ROOT` or `../../../source/pw142`.
pub fn find_test_pw142_root(manifest_dir: &str) -> Option<std::path::PathBuf> {
    if let Ok(env_root) = std::env::var("PW142_ROOT") {
        let p = std::path::PathBuf::from(env_root);
        if p.join("element").is_dir() {
            return Some(p);
        }
    }
    let rel = std::path::Path::new(manifest_dir).join("../../../source/pw142");
    if rel.join("element/configs.pck").is_file() {
        return Some(rel);
    }
    None
}

/// Locates the `pw142/element` directory for integration tests via `PW142_ELEMENT_DIR`, `PW142_ROOT`, or `../../../source/pw142/element`.
pub fn find_test_pw142_element(manifest_dir: &str) -> Option<std::path::PathBuf> {
    if let Ok(env_elem) = std::env::var("PW142_ELEMENT_DIR") {
        let p = std::path::PathBuf::from(env_elem);
        if p.join("configs.pck").is_file() {
            return Some(p);
        }
    }
    if let Some(root) = find_test_pw142_root(manifest_dir) {
        let elem = root.join("element");
        if elem.join("configs.pck").is_file() {
            return Some(elem);
        }
    }
    let rel = std::path::Path::new(manifest_dir).join("../../../source/pw142/element");
    if rel.join("configs.pck").is_file() {
        return Some(rel);
    }
    None
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_zlib_roundtrip_and_checksums() {
        let sample = b"Angelica File Package, Perfect World Co. Ltd. 2002~2008. All Rights Reserved. ".repeat(8);
        let compressed = zlib_compress(&sample, 6).expect("compress");
        assert!(compressed.len() < sample.len());
        let restored = zlib_uncompress(&compressed, sample.len()).expect("uncompress");
        assert_eq!(restored, sample);
        assert!(!zlib_version().is_empty());
        assert_ne!(zlib_crc32(&sample), 0);
        assert_ne!(zlib_adler32(&sample), 1);
        assert_eq!(zlib_fallback::pure_crc32(&sample), zlib_crc32(&sample));
        assert_eq!(zlib_fallback::pure_adler32(&sample), zlib_crc32(&sample) ^ zlib_crc32(&sample) ^ zlib_adler32(&sample));
        assert_eq!(zlib_fallback::pure_zlib_uncompress(&compressed, sample.len()).unwrap(), sample);
        let pure_comp = zlib_fallback::pure_zlib_compress(&sample);
        assert_eq!(zlib_uncompress(&pure_comp, sample.len()).unwrap(), sample);
    }

    #[test]
    fn test_gbk_and_utf16_xor_roundtrip() {
        let cn = "完美世界新手卡活动";
        let gbk = encode_gbk(cn);
        assert_ne!(gbk, cn.as_bytes());
        assert_eq!(decode_gbk(&gbk), cn);

        let key: u16 = 2758;
        let enc = encode_utf16le_xor(cn, key, true);
        assert_eq!(decode_utf16le_xor_null_terminated(&enc, key), cn);
    }

    #[test]
    fn test_afile_image_moxb_and_ini() {
        let mut buf = Vec::new();
        buf.extend_from_slice(&AFILE_MAGIC_MOXB.to_le_bytes());
        buf.extend_from_slice(&47u32.to_le_bytes());
        let (mode, mut cur) = open_afile_image(&buf);
        assert_eq!(mode, AFileMode::BinaryMoxb);
        assert_eq!(cur.read_u32_le().unwrap(), 47);

        let sys_ini = std::fs::read(std::path::Path::new(env!("CARGO_MANIFEST_DIR")).join("../../../source/pw142/config/default/SystemSettings.ini"))
            .unwrap_or_else(|_| b"[Video]\nLevel = 2\nSight = 2\n".to_vec());
        let ini = IniFile::parse_bytes(&sys_ini);
        assert!(!ini.sections.is_empty());
    }
}
