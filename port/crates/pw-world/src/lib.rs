//! `pw-world` — 1:1 Port of `CECWorld`, `CECScene`, & `A3DTerrain2` Map Formats.
//!
//! Verified directly against `source/pw142/element/maps/a01/*` and `maps/login/*`
//! (`0x4294a0.c`, `0x434b80.c`, `0x7a1ce0.c`, `0x41bb30.c`).

pub mod cec_scene;
pub mod trn2_full;

pub use cec_scene::{
    CecSceneData, EcwldGrassType, EcwldTreeType, SceneBoxArea, SceneGrassInstance,
    SceneOrnamentInstance, SceneStaticEcModel, SceneTreePlacement, WaterAreaMesh,
};
pub use trn2_full::{T2LmSubTerrainLightmaps, T2MkAreaLayerMask, T2MkLayerDesc, T2MkSubTerrainMasks, Trn2FullDesc};

use std::path::{Path, PathBuf};

use pw_core::{
    decode_utf16le_null_terminated, find_path_case_insensitive, open_afile_image, zlib_uncompress,
    AFileMode, BinaryCursor, IniFile, PwError, PwResult, Vec3,
};

/// Single camera rig from `configs\scenectrl.ini` `[Camera]`.
#[derive(Debug, Clone, Copy)]
pub struct SceneCamRig {
    pub pos: Vec3,
    pub dir: Vec3,
    pub up: Vec3,
}

/// Exact parser for `configs\scenectrl.ini` (`CECLoginUIMan`, `08_cecloginuiman.c`):
/// - `cameras[0..26]` (`[Camera]` `PosX{i}/PosY{i}/PosZ{i}`, `DirX{i}/DirY{i}/DirZ{i}`, `UpX{i}/UpY{i}/UpZ{i}`)
/// - `sel_char[0..9]` (`[SelChar]` `PosX{i}/PosY{i}/PosZ{i}`; slot `7` is the active Character Select pedestal paired with `cameras[6]`)
/// - `new_char[0..8]` (`[NewChar]` `PosX{i}/PosY{i}/PosZ{i}` for all 8 classes `0..=7`)
#[derive(Debug, Clone)]
pub struct SceneCtrlConfig {
    pub cameras: Vec<SceneCamRig>,
    pub sel_char: Vec<Vec3>,
    pub new_char: Vec<Vec3>,
}

impl SceneCtrlConfig {
    /// Camera index in `self.cameras` for Character Creation preview of `cls` (`0..=7`).
    /// Verified directly against `configs\scenectrl.ini`:
    /// `Cam[0]` = Login, `Cam[1]` = Tideborn intro, `Cam[2..=9]` = Create Character (`[NewChar] Pos[0..=7]`),
    /// `Cam[10..=17]` = Select Character (`[NewChar] Pos[0..=7]`), `Cam[18..=25]` = Face Customize Zoom.
    pub const CREATE_CAM_FOR_CLASS: [usize; 8] = [2, 3, 4, 5, 6, 7, 8, 9];

    pub fn from_ini(ini: &IniFile) -> Self {
        let get_f = |sec: &str, k: &str| -> Option<f32> {
            ini.get(sec, k)?.trim().parse::<f32>().ok()
        };
        let mut cameras = Vec::new();
        for i in 0..32 {
            let Some(px) = get_f("Camera", &format!("PosX{i}")) else {
                break;
            };
            let py = get_f("Camera", &format!("PosY{i}")).unwrap_or(240.0);
            let pz = get_f("Camera", &format!("PosZ{i}")).unwrap_or(-478.0);
            let dx = get_f("Camera", &format!("DirX{i}")).unwrap_or(0.0);
            let dy = get_f("Camera", &format!("DirY{i}")).unwrap_or(0.0);
            let dz = get_f("Camera", &format!("DirZ{i}")).unwrap_or(1.0);
            let ux = get_f("Camera", &format!("UpX{i}")).unwrap_or(0.0);
            let uy = get_f("Camera", &format!("UpY{i}")).unwrap_or(1.0);
            let uz = get_f("Camera", &format!("UpZ{i}")).unwrap_or(0.0);
            cameras.push(SceneCamRig {
                pos: Vec3::new(px, py, pz),
                dir: Vec3::new(dx, dy, dz).normalized(),
                up: Vec3::new(ux, uy, uz).normalized(),
            });
        }
        if cameras.is_empty() {
            cameras.push(SceneCamRig {
                pos: Vec3::new(-78.0, 240.0, -478.0),
                dir: Vec3::new(1.101, -0.061049, 0.998135).normalized(),
                up: Vec3::UNIT_Y,
            });
        }

        let mut sel_char = Vec::new();
        for i in 0..12 {
            let Some(px) = get_f("SelChar", &format!("PosX{i}")) else {
                break;
            };
            let py = get_f("SelChar", &format!("PosY{i}")).unwrap_or(243.28);
            let pz = get_f("SelChar", &format!("PosZ{i}")).unwrap_or(20.14);
            sel_char.push(Vec3::new(px, py, pz));
        }

        let mut new_char = Vec::new();
        for i in 0..12 {
            let Some(px) = get_f("NewChar", &format!("PosX{i}")) else {
                break;
            };
            let py = get_f("NewChar", &format!("PosY{i}")).unwrap_or(229.0);
            let pz = get_f("NewChar", &format!("PosZ{i}")).unwrap_or(286.6);
            new_char.push(Vec3::new(px, py, pz));
        }

        Self {
            cameras,
            sel_char,
            new_char,
        }
    }

    pub fn login_camera(&self) -> SceneCamRig {
        self.cameras[0]
    }

    /// Returns `(camera_rig, pedestal_pos, character_facing_dir)` for Character Select of a role with `cls` (`0..=7`).
    /// Verified directly against `configs\scenectrl.ini`:
    /// `[Camera]` slots `10..=17` pair 1:1 with `[NewChar]` slots `0..=7` across all 4 races / 8 classes.
    pub fn select_rig_for_class(&self, cls: usize) -> (SceneCamRig, Vec3, Vec3) {
        let c = cls.min(7);
        let cam_idx = 10 + c;
        let cam = self
            .cameras
            .get(cam_idx)
            .copied()
            .or_else(|| self.cameras.get(10).copied())
            .unwrap_or(self.cameras[0]);
        let pos = self
            .new_char
            .get(c)
            .copied()
            .unwrap_or_else(|| cam.pos.add(cam.dir.scale(2.8)));
        let face_dir = Vec3::new(cam.pos.x - pos.x, 0.0, cam.pos.z - pos.z).normalized();
        (cam, pos, face_dir)
    }

    /// Returns `(camera_rig, pedestal_pos, character_facing_dir)` for Character Select (`Cam[10]` + `NewChar[0]`).
    pub fn select_rig(&self) -> (SceneCamRig, Vec3, Vec3) {
        self.select_rig_for_class(0)
    }

    /// Returns `(camera_rig, pedestal_pos, character_facing_dir)` for Character Creation (`cls` `0..=7`).
    pub fn create_rig(&self, cls: usize) -> (SceneCamRig, Vec3, Vec3) {
        let c = cls.min(7);
        let cam_idx = Self::CREATE_CAM_FOR_CLASS[c];
        let cam = self.cameras.get(cam_idx).copied().unwrap_or(self.cameras[0]);
        let pos = self
            .new_char
            .get(c)
            .copied()
            .unwrap_or_else(|| cam.pos.add(cam.dir.scale(3.0)));
        let face_dir = Vec3::new(cam.pos.x - pos.x, 0.0, cam.pos.z - pos.z).normalized();
        (cam, pos, face_dir)
    }
}

pub const MAGIC_TRN2: u32 = 0x5452_4e32; // "TRN2"
pub const MAGIC_TBKB: u32 = 0x5442_4b42; // "TBKB"
pub const MAGIC_TMKB: u32 = 0x544d_4b42; // "TMKB"
pub const MAGIC_T2LM: u32 = 0x5432_4c4d; // "T2LM"
pub const MAGIC_T2HC: u32 = 0x5432_4843; // "T2HC"
pub const MAGIC_ECWD: u32 = 0x4543_5744; // "ECWD"
pub const MAGIC_BSDF: u32 = 0x4253_4446; // "BSDF"

#[derive(Debug, Clone)]
pub struct Terrain2Header {
    pub version: u32,
    pub terrain_width: f32,
    pub terrain_length: f32,
    pub block_size: f32,
    pub block_grid: i32,
    pub num_blocks: i32,
    pub trn_row_blocks: i32,
}

impl Terrain2Header {
    pub fn parse(bytes: &[u8]) -> PwResult<Self> {
        let mut cur = BinaryCursor::new(bytes);
        let magic = cur.read_u32_le()?;
        if magic != MAGIC_TRN2 {
            return Err(PwError::InvalidMagic {
                expected: "TRN2 (0x54524e32)",
                found: magic,
            });
        }
        Ok(Self {
            version: cur.read_u32_le()?,
            terrain_width: cur.read_f32_le()?,
            terrain_length: cur.read_f32_le()?,
            block_size: cur.read_f32_le()?,
            block_grid: cur.read_i32_le()?,
            num_blocks: cur.read_i32_le()?,
            trn_row_blocks: cur.read_i32_le()?,
        })
    }
}

#[derive(Debug, Clone)]
pub struct Terrain2BlockFile {
    pub version: u32,
    pub num_blocks: usize,
    pub compression_flags: u32,
    pub block_offsets: Vec<u32>,
}

impl Terrain2BlockFile {
    pub fn parse(bytes: &[u8]) -> PwResult<Self> {
        let mut cur = BinaryCursor::new(bytes);
        let magic = cur.read_u32_le()?;
        if magic != MAGIC_TBKB {
            return Err(PwError::InvalidMagic {
                expected: "TBKB (0x54424b42)",
                found: magic,
            });
        }
        let version = cur.read_u32_le()?;
        let num_blocks = cur.read_u32_le()? as usize;
        let compression_flags = cur.read_u32_le()?;
        let mut block_offsets = Vec::with_capacity(num_blocks);
        for _ in 0..num_blocks {
            let off = cur.read_u32_le()?;
            if (off as usize) >= bytes.len() {
                return Err(PwError::InvalidData(format!(
                    "t2bk block offset {off:#x} out of range"
                )));
            }
            block_offsets.push(off);
        }
        Ok(Self {
            version,
            num_blocks,
            compression_flags,
            block_offsets,
        })
    }
}

/// Decoded high-resolution `A3DTerrain2` heightfield & baked day/night vertex colors (`0x7a1ce0.c`).
#[derive(Debug, Clone)]
pub struct Terrain2HeightMesh {
    pub verts_per_side: usize,
    pub origin_x: f32,
    pub origin_z_top: f32,
    pub world_width: f32,
    pub world_length: f32,
    pub min_height: f32,
    pub max_height: f32,
    pub heights: Vec<f32>,
    /// Pre-baked `0xFFRRGGBB` day vertex lighting from `.t2bk`.
    pub day_colors: Vec<u32>,
    /// Pre-baked `0xFFRRGGBB` night vertex lighting from `.t2bk`.
    pub night_colors: Vec<u32>,
}

impl Terrain2HeightMesh {
    /// Decodes a `16x16`-block (`513x513`-vertex) `.t2bk` sub-terrain file (`v2..v5`) centered at `(0, 0)`.
    pub fn from_t2bk_bytes(bytes: &[u8], world_width: f32, world_length: f32, block_grid: usize) -> PwResult<Self> {
        Self::from_t2bk_bytes_at(
            bytes,
            -world_width * 0.5,
            world_length * 0.5,
            world_width,
            world_length,
            block_grid,
        )
    }

    /// Decodes a `16x16`-block (`513x513`-vertex) `.t2bk` sub-terrain file (`v2..v5`) at explicit `(origin_x, origin_z_top)`.
    pub fn from_t2bk_bytes_at(
        bytes: &[u8],
        origin_x: f32,
        origin_z_top: f32,
        world_width: f32,
        world_length: f32,
        block_grid: usize,
    ) -> PwResult<Self> {
        let header = Terrain2BlockFile::parse(bytes)?;
        let grid = block_grid.max(16);
        let block_verts = grid + 1;
        let blocks_per_side = (header.num_blocks as f64).sqrt().round().max(1.0) as usize;
        let verts_per_side = blocks_per_side * grid + 1;
        let total_verts = verts_per_side * verts_per_side;

        let mut heights = vec![100.0f32; total_verts];
        let mut day_colors = vec![0xFF5A_7248u32; total_verts];
        let mut night_colors = vec![0xFF28_344Au32; total_verts];
        let mut min_height = f32::INFINITY;
        let mut max_height = f32::NEG_INFINITY;

        let expected_float_bytes = block_verts * block_verts * 4;
        let expected_saturn_bytes = 8 + block_verts * block_verts * 2;

        for (bi, &off_u32) in header.block_offsets.iter().enumerate() {
            let off = off_u32 as usize;
            let hdr_len = if header.version < 2 {
                16
            } else if header.version == 2 {
                24
            } else if header.version == 3 {
                28
            } else {
                32
            };
            if off + hdr_len > bytes.len() {
                continue;
            }
            let mut bcur = BinaryCursor::new(&bytes[off..]);
            let _mask_area = bcur.read_i32_le()?;
            let row = bcur.read_u16_le()? as usize;
            let col = bcur.read_u16_le()? as usize;
            let _lod_scale = if header.version >= 2 { bcur.read_f32_le()? } else { 1.0 };
            let _layer_flags = if header.version >= 2 { bcur.read_u32_le()? } else { 1 };
            let hei_sz = bcur.read_u32_le()? as usize;
            let nrm_sz = bcur.read_u32_le()? as usize;
            let diff_sz = if header.version >= 3 { bcur.read_u32_le()? as usize } else { 0 };
            let diff1_sz = if header.version >= 4 { bcur.read_u32_le()? as usize } else { 0 };

            // In multi-subterrain worlds (`world_1..88.t2bk`), `(row, col)` are global (`0..175, 0..127`),
            // so `row % blocks_per_side` and `col % blocks_per_side` give the exact local `(0..15, 0..15)` indices!
            let _ = bi;
            let br = row % blocks_per_side;
            let bc = col % blocks_per_side;
            if br >= blocks_per_side || bc >= blocks_per_side {
                continue;
            }

            let mut p = off + hdr_len;
            if hei_sz > 0 && p + hei_sz <= bytes.len() {
                let h_slice = &bytes[p..p + hei_sz];
                p += hei_sz;
                // Exact `A3DTrn2SubLoaderB::ReadBlockData` (`0x007a1ce0`):
                // bit `0x04` = zlib compressed; bit `0x08` = Saturn u16 quantized (`8 + block_verts^2 * 2` bytes).
                let expect_sz = if (header.compression_flags & 0x08) != 0 {
                    expected_saturn_bytes
                } else {
                    expected_float_bytes
                };
                let h_decoded = if (header.compression_flags & 0x04) != 0 {
                    zlib_uncompress(h_slice, expect_sz)
                        .or_else(|_| zlib_uncompress(h_slice, expected_float_bytes))
                        .or_else(|_| zlib_uncompress(h_slice, expected_saturn_bytes))
                        .ok()
                } else {
                    Some(h_slice.to_vec())
                };

                if let Some(hb) = h_decoded {
                    if (header.compression_flags & 0x08) == 0 && hb.len() >= expected_float_bytes {
                        for lz in 0..block_verts {
                            for lx in 0..block_verts {
                                let idx = (lz * block_verts + lx) * 4;
                                let h = f32::from_le_bytes([hb[idx], hb[idx + 1], hb[idx + 2], hb[idx + 3]]);
                                if h.is_finite() {
                                    min_height = min_height.min(h);
                                    max_height = max_height.max(h);
                                    let gz = br * grid + lz;
                                    let gx = bc * grid + lx;
                                    heights[gz * verts_per_side + gx] = h;
                                }
                            }
                        }
                    } else if hb.len() >= expected_saturn_bytes {
                        let min_y = f32::from_le_bytes([hb[0], hb[1], hb[2], hb[3]]);
                        let scale = f32::from_le_bytes([hb[4], hb[5], hb[6], hb[7]]);
                        for lz in 0..block_verts {
                            for lx in 0..block_verts {
                                let idx = 8 + (lz * block_verts + lx) * 2;
                                let q = u16::from_le_bytes([hb[idx], hb[idx + 1]]) as f32;
                                let h = min_y + q * scale;
                                if h.is_finite() {
                                    min_height = min_height.min(h);
                                    max_height = max_height.max(h);
                                    let gz = br * grid + lz;
                                    let gx = bc * grid + lx;
                                    heights[gz * verts_per_side + gx] = h;
                                }
                            }
                        }
                    }
                }
            } else {
                p += hei_sz;
            }

            p = p.saturating_add(nrm_sz);

            if diff_sz > 0 && p + diff_sz <= bytes.len() {
                let d_slice = &bytes[p..p + diff_sz];
                p += diff_sz;
                let d_decoded = if (header.compression_flags & 0x01) != 0 {
                    zlib_uncompress(d_slice, expected_float_bytes).ok()
                } else if d_slice.len() >= expected_float_bytes {
                    Some(d_slice.to_vec())
                } else {
                    None
                };
                if let Some(db) = d_decoded {
                    if db.len() >= expected_float_bytes {
                        for lz in 0..block_verts {
                            for lx in 0..block_verts {
                                let idx = (lz * block_verts + lx) * 4;
                                let b0 = db[idx] as u32;
                                let g0 = db[idx + 1] as u32;
                                let r0 = db[idx + 2] as u32;
                                let gz = br * grid + lz;
                                let gx = bc * grid + lx;
                                day_colors[gz * verts_per_side + gx] = 0xFF00_0000 | (r0 << 16) | (g0 << 8) | b0;
                            }
                        }
                    }
                }
            } else {
                p += diff_sz;
            }

            if diff1_sz > 0 && p + diff1_sz <= bytes.len() {
                let d1_slice = &bytes[p..p + diff1_sz];
                let d1_decoded = if (header.compression_flags & 0x01) != 0 {
                    zlib_uncompress(d1_slice, expected_float_bytes).ok()
                } else if d1_slice.len() >= expected_float_bytes {
                    Some(d1_slice.to_vec())
                } else {
                    None
                };
                if let Some(db) = d1_decoded {
                    if db.len() >= expected_float_bytes {
                        for lz in 0..block_verts {
                            for lx in 0..block_verts {
                                let idx = (lz * block_verts + lx) * 4;
                                let b0 = db[idx] as u32;
                                let g0 = db[idx + 1] as u32;
                                let r0 = db[idx + 2] as u32;
                                let gz = br * grid + lz;
                                let gx = bc * grid + lx;
                                night_colors[gz * verts_per_side + gx] = 0xFF00_0000 | (r0 << 16) | (g0 << 8) | b0;
                            }
                        }
                    }
                }
            }
        }

        if !min_height.is_finite() {
            min_height = 100.0;
            max_height = 100.0;
        }

        Ok(Self {
            verts_per_side,
            origin_x,
            origin_z_top,
            world_width: world_width.max(64.0),
            world_length: world_length.max(64.0),
            min_height,
            max_height,
            heights,
            day_colors,
            night_colors,
        })
    }

    /// Creates a fallback terrain mesh from `.t2hc` collision heights or procedural hills.
    pub fn from_collision_or_procedural(
        hc: Option<&Terrain2HeightCollision>,
        world_width: f32,
        world_length: f32,
    ) -> Self {
        let w = world_width.max(512.0);
        let l = world_length.max(512.0);
        let n = 129usize;
        let mut heights = vec![0.0f32; n * n];
        let mut day_colors = vec![0u32; n * n];
        let mut night_colors = vec![0u32; n * n];
        let mut min_h = f32::INFINITY;
        let mut max_h = f32::NEG_INFINITY;

        for gz in 0..n {
            for gx in 0..n {
                let u = gx as f32 / (n - 1) as f32;
                let v = gz as f32 / (n - 1) as f32;
                let wx = (u - 0.5) * w;
                let wz = (0.5 - v) * l;
                let base_h = if let Some(c) = hc {
                    if !c.heights.is_empty() {
                        let idx = ((v * (c.heights.len() - 1) as f32) as usize).min(c.heights.len() - 1);
                        c.heights[idx]
                    } else {
                        215.0
                    }
                } else {
                    215.0
                };
                let ridge = (wx * 0.012).sin() * (wz * 0.011).cos() * 24.0
                    + (wx * 0.031 + 1.2).cos() * (wz * 0.027).sin() * 9.5
                    + ((wx * wx + wz * wz).sqrt() * 0.008).sin() * 14.0;
                let h = base_h + ridge;
                min_h = min_h.min(h);
                max_h = max_h.max(h);
                heights[gz * n + gx] = h;
                let t = ((h - base_h + 30.0) / 60.0).clamp(0.0, 1.0);
                let r = (58.0 + t * 88.0) as u32;
                let g = (86.0 + t * 76.0) as u32;
                let b = (56.0 + t * 52.0) as u32;
                day_colors[gz * n + gx] = 0xFF00_0000 | (r << 16) | (g << 8) | b;
                night_colors[gz * n + gx] =
                    0xFF00_0000 | ((r / 2) << 16) | ((g / 2) << 8) | ((b * 3 / 4).min(255));
            }
        }

        Self {
            verts_per_side: n,
            origin_x: -w * 0.5,
            origin_z_top: l * 0.5,
            world_width: w,
            world_length: l,
            min_height: min_h,
            max_height: max_h,
            heights,
            day_colors,
            night_colors,
        }
    }

    pub fn contains_xz(&self, x: f32, z: f32) -> bool {
        x >= self.origin_x
            && x <= self.origin_x + self.world_width
            && z <= self.origin_z_top
            && z >= self.origin_z_top - self.world_length
    }

    fn world_to_grid(&self, x: f32, z: f32) -> (f32, f32) {
        let lx = (x - self.origin_x).clamp(0.0, self.world_width);
        let lz = (self.origin_z_top - z).clamp(0.0, self.world_length);
        let u = (lx / self.world_width.max(1.0)) * (self.verts_per_side - 1) as f32;
        let v = (lz / self.world_length.max(1.0)) * (self.verts_per_side - 1) as f32;
        (u, v)
    }

    pub fn sample_height(&self, x: f32, z: f32) -> f32 {
        let (u, v) = self.world_to_grid(x, z);
        let max_i = (self.verts_per_side - 1) as f32;
        let uc = u.clamp(0.0, max_i);
        let vc = v.clamp(0.0, max_i);
        let x0 = (uc.floor() as usize).min(self.verts_per_side - 1);
        let z0 = (vc.floor() as usize).min(self.verts_per_side - 1);
        let x1 = (x0 + 1).min(self.verts_per_side - 1);
        let z1 = (z0 + 1).min(self.verts_per_side - 1);
        let tx = uc - x0 as f32;
        let tz = vc - z0 as f32;
        let n = self.verts_per_side;
        let h00 = self.heights[z0 * n + x0];
        let h10 = self.heights[z0 * n + x1];
        let h01 = self.heights[z1 * n + x0];
        let h11 = self.heights[z1 * n + x1];
        let top = h00 + (h10 - h00) * tx;
        let bot = h01 + (h11 - h01) * tx;
        top + (bot - top) * tz
    }

    pub fn sample_color(&self, x: f32, z: f32, night_factor: f32) -> u32 {
        let (u, v) = self.world_to_grid(x, z);
        let xi = (u.round() as usize).min(self.verts_per_side - 1);
        let zi = (v.round() as usize).min(self.verts_per_side - 1);
        let idx = zi * self.verts_per_side + xi;
        let day = self.day_colors[idx];
        if night_factor <= 0.01 {
            return day;
        }
        let night = self.night_colors[idx];
        let nf = night_factor.clamp(0.0, 1.0);
        let blend = |shift: u32| -> u32 {
            let a = ((day >> shift) & 0xFF) as f32;
            let b = ((night >> shift) & 0xFF) as f32;
            (a + (b - a) * nf) as u32
        };
        0xFF00_0000 | (blend(16) << 16) | (blend(8) << 8) | blend(0)
    }
}

#[derive(Debug, Clone)]
pub struct Terrain2MaskFile {
    pub version: u32,
    pub mask_area_count: usize,
}

impl Terrain2MaskFile {
    pub fn parse(bytes: &[u8]) -> PwResult<Self> {
        let mut cur = BinaryCursor::new(bytes);
        let magic = cur.read_u32_le()?;
        if magic != MAGIC_TMKB {
            return Err(PwError::InvalidMagic {
                expected: "TMKB (0x544d4b42)",
                found: magic,
            });
        }
        Ok(Self {
            version: cur.read_u32_le()?,
            mask_area_count: cur.read_u32_le()? as usize,
        })
    }
}

#[derive(Debug, Clone)]
pub struct Terrain2LightmapFile {
    pub version: u32,
    pub mask_grid: i32,
    pub mask_tex_size: i32,
    pub flags: u32,
    pub area_data_size: u32,
}

impl Terrain2LightmapFile {
    pub fn parse(bytes: &[u8]) -> PwResult<Self> {
        let mut cur = BinaryCursor::new(bytes);
        let magic = cur.read_u32_le()?;
        if magic != MAGIC_T2LM {
            return Err(PwError::InvalidMagic {
                expected: "T2LM (0x54324c4d)",
                found: magic,
            });
        }
        Ok(Self {
            version: cur.read_u32_le()?,
            mask_grid: cur.read_i32_le()?,
            mask_tex_size: cur.read_i32_le()?,
            flags: cur.read_u32_le()?,
            area_data_size: cur.read_u32_le()?,
        })
    }
}

#[derive(Debug, Clone)]
pub struct Terrain2HeightCollision {
    pub version: u32,
    pub rows: i32,
    pub cols: i32,
    pub sample_pairs: usize,
    pub heights: Vec<f32>,
}

impl Terrain2HeightCollision {
    pub fn parse_exact(bytes: &[u8]) -> PwResult<Self> {
        let mut cur = BinaryCursor::new(bytes);
        let magic = cur.read_u32_le()?;
        if magic != MAGIC_T2HC {
            return Err(PwError::InvalidMagic {
                expected: "T2HC (0x54324843)",
                found: magic,
            });
        }
        let version = cur.read_u32_le()?;
        let rows = cur.read_i32_le()?;
        let cols = cur.read_i32_le()?;
        let sample_pairs = cur.read_u32_le()? as usize;
        let float_count = cur.remaining() / 4;
        let mut heights = Vec::with_capacity(float_count);
        for _ in 0..float_count {
            heights.push(cur.read_f32_le()?);
        }
        if cur.remaining() != 0 {
            return Err(PwError::InvalidData("t2hc unaligned trailing bytes".into()));
        }
        Ok(Self {
            version,
            rows,
            cols,
            sample_pairs,
            heights,
        })
    }
}

#[derive(Debug, Clone)]
pub struct EcWorldFile {
    pub version: u32,
    pub world_width: f32,
    pub world_length: f32,
    pub block_size: f32,
    pub block_grid: i32,
    pub num_blocks: i32,
    pub row_blocks: i32,
}

impl EcWorldFile {
    pub fn parse(bytes: &[u8]) -> PwResult<Self> {
        let mut cur = BinaryCursor::new(bytes);
        let magic = cur.read_u32_le()?;
        if magic != MAGIC_ECWD {
            return Err(PwError::InvalidMagic {
                expected: "ECWD (0x45435744)",
                found: magic,
            });
        }
        Ok(Self {
            version: cur.read_u32_le()?,
            world_width: cur.read_f32_le()?,
            world_length: cur.read_f32_le()?,
            block_size: cur.read_f32_le()?,
            block_grid: cur.read_i32_le()?,
            num_blocks: cur.read_i32_le()?,
            row_blocks: cur.read_i32_le()?,
        })
    }
}

#[derive(Debug, Clone)]
pub struct EcBsdFile {
    pub version: u32,
    pub sub_block_count: u32,
}

impl EcBsdFile {
    pub fn parse(bytes: &[u8]) -> PwResult<Self> {
        let (mode, mut cur) = open_afile_image(bytes);
        if mode != AFileMode::BinaryMoxb {
            return Err(PwError::InvalidData("ecbsd missing MOXB header".into()));
        }
        let magic = cur.read_u32_le()?;
        if magic != MAGIC_BSDF {
            return Err(PwError::InvalidMagic {
                expected: "BSDF (0x42534446)",
                found: magic,
            });
        }
        Ok(Self {
            version: cur.read_u32_le()?,
            sub_block_count: cur.read_u32_le()?,
        })
    }
}

#[derive(Debug, Clone)]
pub struct SceneLightsFile {
    pub version: u32,
    pub count: usize,
    pub light_positions: Vec<Vec3>,
}

impl SceneLightsFile {
    pub fn parse_exact(bytes: &[u8]) -> PwResult<Self> {
        let mut cur = BinaryCursor::new(bytes);
        let version = cur.read_u32_le()?;
        let count = cur.read_u32_le()? as usize;
        if count == 0 {
            return Ok(Self {
                version,
                count: 0,
                light_positions: Vec::new(),
            });
        }
        let stride = cur.remaining() / count;
        let mut light_positions = Vec::with_capacity(count);
        for _ in 0..count {
            let block = cur.read_bytes(stride)?;
            let mut bcur = BinaryCursor::new(block);
            light_positions.push(bcur.read_vec3_le()?);
        }
        if cur.remaining() != 0 {
            return Err(PwError::InvalidData("scenelights.dat trailing bytes".into()));
        }
        Ok(Self {
            version,
            count,
            light_positions,
        })
    }
}

#[derive(Debug, Clone)]
pub struct ClientPrecinct {
    pub id: u32,
    pub name: String,
    pub spawn_pos: Vec3,
    pub polygon_xz: Vec<(f32, f32)>,
    pub bgm_music: String,
}

impl ClientPrecinct {
    pub fn contains_xz(&self, wx: f32, wz: f32) -> bool {
        if self.polygon_xz.len() < 3 {
            return false;
        }
        let mut inside = false;
        let n = self.polygon_xz.len();
        let mut j = n - 1;
        for i in 0..n {
            let (xi, zi) = self.polygon_xz[i];
            let (xj, zj) = self.polygon_xz[j];
            if ((zi > wz) != (zj > wz))
                && (wx < (xj - xi) * (wz - zi) / ((zj - zi) + 1e-6) + xi)
            {
                inside = !inside;
            }
            j = i;
        }
        inside
    }
}

/// Teleport / WorldMap target landmark parsed from `maps/world/world_targets.txt`.
#[derive(Debug, Clone)]
pub struct WorldTargetPoint {
    pub id: u32,
    pub name: String,
    pub map_id: u32,
    pub pos: Vec3,
    pub domain_id: i32,
}

impl WorldTargetPoint {
    pub fn parse_targets_file(bytes: &[u8]) -> Vec<Self> {
        let body = if bytes.starts_with(&[0xFF, 0xFE]) {
            decode_utf16le_null_terminated(&bytes[2..])
        } else {
            String::from_utf8_lossy(bytes).into_owned()
        };
        let mut out = Vec::new();
        for raw_ln in body.lines() {
            let ln = raw_ln.trim().trim_start_matches('\u{feff}');
            if ln.is_empty() || ln.starts_with("//") || ln.starts_with('#') {
                continue;
            }
            // Format: `3801\t"Archosaur, North District"\t1\t"1470.490,219.608,1180.864"\t23`
            let cols: Vec<&str> = ln.split('\t').map(str::trim).filter(|s| !s.is_empty()).collect();
            if cols.len() < 4 {
                continue;
            }
            let Ok(id) = cols[0].parse::<u32>() else { continue };
            let name = cols[1].trim_matches('"').trim().to_string();
            let map_id = cols[2].parse::<u32>().unwrap_or(1);
            let coords: Vec<f32> = cols[3]
                .trim_matches('"')
                .split(|c: char| c == ',' || c.is_whitespace())
                .filter(|s| !s.is_empty())
                .filter_map(|s| s.parse::<f32>().ok())
                .collect();
            if coords.len() < 3 {
                continue;
            }
            let domain_id = cols
                .get(4)
                .and_then(|s| s.parse::<i32>().ok())
                .unwrap_or(0);
            out.push(Self {
                id,
                name,
                map_id,
                pos: Vec3::new(coords[0], coords[1], coords[2]),
                domain_id,
            });
        }
        out
    }
}

/// Active streamed `1024m x 1024m` sub-terrain (`A3DTrn2SubLoaderB`: `world_1..88`, `a01_1`, `login_Login`).
#[derive(Debug, Clone)]
pub struct LoadedSubTerrain {
    pub sub_idx: usize,
    pub sub_row: usize,
    pub sub_col: usize,
    pub sub_name: String,
    pub height_mesh: Terrain2HeightMesh,
    pub t2mk: Option<T2MkSubTerrainMasks>,
    pub t2lm_day: Option<T2LmSubTerrainLightmaps>,
    pub t2lm_night: Option<T2LmSubTerrainLightmaps>,
}

#[derive(Debug, Clone)]
pub struct ClientZoneText {
    pub lines: Vec<String>,
}

impl ClientZoneText {
    pub fn parse_clt(bytes: &[u8]) -> PwResult<Self> {
        let body = if bytes.starts_with(&[0xFF, 0xFE]) {
            decode_utf16le_null_terminated(&bytes[2..])
        } else {
            String::from_utf8_lossy(bytes).into_owned()
        };
        let lines = body
            .lines()
            .map(str::trim)
            .filter(|l| !l.is_empty() && !l.starts_with("//"))
            .map(ToOwned::to_owned)
            .collect();
        Ok(Self { lines })
    }

    /// Parses `CELPrecinctSet::Load` (`precinct.clt` version 6) quoted zone names, resurrection `x, y, z`,
    /// polygon boundary vertices (`hdr_nums[1]`), and `Music\*.mp3` BGM path!
    pub fn parse_precincts(&self) -> Vec<ClientPrecinct> {
        let mut out = Vec::new();
        let mut i = 0usize;
        while i + 2 < self.lines.len() {
            let line = &self.lines[i];
            if line.starts_with('"') && line.ends_with('"') && line.len() > 2 {
                let name = line.trim_matches('"').trim().to_string();
                let hdr_nums: Vec<u32> = self.lines[i + 1]
                    .split_whitespace()
                    .filter_map(|t| t.parse::<u32>().ok())
                    .collect();
                if hdr_nums.len() >= 4 {
                    let coords: Vec<f32> = self.lines[i + 2]
                        .split(|c: char| c == ',' || c.is_whitespace())
                        .filter(|s| !s.is_empty())
                        .filter_map(|t| t.parse::<f32>().ok())
                        .collect();
                    if coords.len() >= 3 {
                        let poly_cnt = hdr_nums[1] as usize;
                        let mut polygon_xz = Vec::with_capacity(poly_cnt);
                        let mut k = i + 3;
                        for _ in 0..poly_cnt {
                            if k >= self.lines.len() {
                                break;
                            }
                            let pvals: Vec<f32> = self.lines[k]
                                .split(|c: char| c == ',' || c.is_whitespace())
                                .filter(|s| !s.is_empty())
                                .filter_map(|t| t.parse::<f32>().ok())
                                .collect();
                            if pvals.len() >= 3 {
                                polygon_xz.push((pvals[0], pvals[2]));
                                k += 1;
                            } else {
                                break;
                            }
                        }
                        let mut bgm_music = String::new();
                        let scan_end = (k + 24).min(self.lines.len());
                        for mline in &self.lines[k..scan_end] {
                            let low = mline.to_ascii_lowercase();
                            if low.contains("music\\") && low.contains(".mp3") {
                                bgm_music = mline.trim_matches('"').to_string();
                                break;
                            }
                        }
                        out.push(ClientPrecinct {
                            id: hdr_nums[0],
                            name,
                            spawn_pos: Vec3::new(coords[0], coords[1], coords[2]),
                            polygon_xz,
                            bgm_music,
                        });
                        i = k.max(i + 3);
                        continue;
                    }
                }
            }
            i += 1;
        }
        out
    }
}

#[derive(Debug, Clone)]
pub struct MapInstanceBundle {
    pub map_name: String,
    pub map_dir: PathBuf,
    pub load_center: Vec3,
    pub world: EcWorldFile,
    pub scene: CecSceneData,
    pub terrain: Option<Terrain2Header>,
    pub trn2_full: Option<Trn2FullDesc>,
    pub terrain_blocks: Option<Terrain2BlockFile>,
    pub t2mk: Option<T2MkSubTerrainMasks>,
    pub t2lm_day: Option<T2LmSubTerrainLightmaps>,
    pub t2lm_night: Option<T2LmSubTerrainLightmaps>,
    pub active_sub_terrains: Vec<LoadedSubTerrain>,
    pub height_mesh: Terrain2HeightMesh,
    pub height_collision: Option<Terrain2HeightCollision>,
    pub scene_lights: Option<SceneLightsFile>,
    pub precincts: Vec<ClientPrecinct>,
    pub world_targets: Vec<WorldTargetPoint>,
    pub precinct_lines: usize,
    pub region_lines: usize,
}

impl MapInstanceBundle {
    /// Default Archosaur (`祖龙城` West/Central Plaza) load center for Midlands (`maps/world`).
    pub const ARCHOSAUR_DEFAULT_CENTER: Vec3 = Vec3 {
        x: 1318.0,
        y: 220.0,
        z: 1085.0,
    };

    pub fn load_map_dir(map_dir: impl AsRef<Path>, map_name: &str) -> PwResult<Self> {
        Self::load_map_dir_at(map_dir, map_name, None)
    }

    pub fn load_map_dir_at(
        map_dir: impl AsRef<Path>,
        map_name: &str,
        initial_center: Option<Vec3>,
    ) -> PwResult<Self> {
        let dir = map_dir.as_ref();
        let ecwld_path = find_path_case_insensitive(dir, &format!("{map_name}.ecwld"))
            .or_else(|| find_path_case_insensitive(dir, "Login.ecwld"))
            .unwrap_or_else(|| dir.join(format!("{map_name}.ecwld")));
        let ecwld_bytes = pw_core::read_file_checked(&ecwld_path)?;
        let world = EcWorldFile::parse(&ecwld_bytes)?;

        let trn_path = find_path_case_insensitive(dir, &format!("{map_name}.trn2"));
        let (terrain, trn2_full) = match trn_path {
            Some(p) if p.is_file() => {
                let raw_trn = pw_core::read_file_checked(p)?;
                (
                    Some(Terrain2Header::parse(&raw_trn)?),
                    Trn2FullDesc::parse(&raw_trn).ok(),
                )
            }
            _ => (None, None),
        };

        let is_multi_sub = trn2_full
            .as_ref()
            .map(|t| t.sub_trn_count > 1)
            .unwrap_or(world.num_blocks > 1024);

        let center = initial_center.unwrap_or_else(|| {
            if is_multi_sub {
                Self::ARCHOSAUR_DEFAULT_CENTER
            } else {
                Vec3::ZERO
            }
        });

        let ecbsd_bytes = find_path_case_insensitive(dir, &format!("{map_name}.ecbsd"))
            .or_else(|| find_path_case_insensitive(dir, "Login.ecbsd"))
            .and_then(|p| pw_core::read_file_checked(p).ok());

        let bsdata_bytes = find_path_case_insensitive(dir, &format!("bsdata/{map_name}.dat"))
            .or_else(|| find_path_case_insensitive(dir, "bsdata/1.dat"))
            .and_then(|p| pw_core::read_file_checked(p).ok());

        let stream_win = if is_multi_sub {
            Some((center, 820.0))
        } else {
            None
        };
        let scene = CecSceneData::parse_streaming(
            map_name,
            Some(dir),
            &ecwld_bytes,
            ecbsd_bytes.as_deref(),
            bsdata_bytes.as_deref(),
            stream_win,
        )?;

        let hc_path = find_path_case_insensitive(dir, &format!("{map_name}.t2hc"));
        let height_collision = match hc_path {
            Some(p) if p.is_file() => {
                Terrain2HeightCollision::parse_exact(&pw_core::read_file_checked(p)?).ok()
            }
            _ => None,
        };

        let active_sub_terrains = Self::load_sub_terrains_around(
            dir,
            map_name,
            &world,
            terrain.as_ref(),
            trn2_full.as_ref(),
            height_collision.as_ref(),
            center,
        );

        let primary_sub = active_sub_terrains.first().cloned();
        let height_mesh = primary_sub
            .as_ref()
            .map(|s| s.height_mesh.clone())
            .unwrap_or_else(|| {
                Terrain2HeightMesh::from_collision_or_procedural(
                    height_collision.as_ref(),
                    world.world_width.min(1024.0),
                    world.world_length.min(1024.0),
                )
            });
        let t2mk = primary_sub.as_ref().and_then(|s| s.t2mk.clone());
        let t2lm_day = primary_sub.as_ref().and_then(|s| s.t2lm_day.clone());
        let t2lm_night = primary_sub.as_ref().and_then(|s| s.t2lm_night.clone());

        let terrain_blocks = primary_sub
            .as_ref()
            .and_then(|s| find_path_case_insensitive(dir, &format!("{}.t2bk", s.sub_name)))
            .and_then(|p| pw_core::read_file_checked(p).ok())
            .and_then(|b| Terrain2BlockFile::parse(&b).ok());

        let scene_lights = match find_path_case_insensitive(dir, "scenelights.dat") {
            Some(p) if p.is_file() => {
                SceneLightsFile::parse_exact(&pw_core::read_file_checked(p)?).ok()
            }
            _ => None,
        };

        let (precincts, precinct_lines) = match find_path_case_insensitive(dir, "precinct.clt") {
            Some(p) if p.is_file() => match ClientZoneText::parse_clt(&pw_core::read_file_checked(p)?) {
                Ok(c) => (c.parse_precincts(), c.lines.len()),
                Err(_) => (Vec::new(), 0),
            },
            _ => (Vec::new(), 0),
        };
        let region_lines = match find_path_case_insensitive(dir, "region.clt") {
            Some(p) if p.is_file() => {
                ClientZoneText::parse_clt(&pw_core::read_file_checked(p)?)
                    .map(|c| c.lines.len())
                    .unwrap_or(0)
            }
            _ => 0,
        };
        let world_targets = find_path_case_insensitive(dir, "world_targets.txt")
            .or_else(|| find_path_case_insensitive(dir, &format!("{map_name}_targets.txt")))
            .and_then(|p| pw_core::read_file_checked(p).ok())
            .map(|b| WorldTargetPoint::parse_targets_file(&b))
            .unwrap_or_default();

        Ok(Self {
            map_name: map_name.to_string(),
            map_dir: dir.to_path_buf(),
            load_center: center,
            world,
            scene,
            terrain,
            trn2_full,
            terrain_blocks,
            t2mk,
            t2lm_day,
            t2lm_night,
            active_sub_terrains,
            height_mesh,
            height_collision,
            scene_lights,
            precincts,
            world_targets,
            precinct_lines,
            region_lines,
        })
    }

    fn load_sub_terrains_around(
        dir: &Path,
        map_name: &str,
        world: &EcWorldFile,
        terrain: Option<&Terrain2Header>,
        trn2_full: Option<&Trn2FullDesc>,
        height_collision: Option<&Terrain2HeightCollision>,
        center: Vec3,
    ) -> Vec<LoadedSubTerrain> {
        let bgrid = terrain.map(|t| t.block_grid.max(16) as usize).unwrap_or(32);

        if let Some(trn) = trn2_full {
            if trn.sub_trn_count > 1 {
                let rows = trn.sub_trn_row.max(1) as usize;
                let cols = trn.sub_trn_col.max(1) as usize;
                let (cr, cc, cidx) = trn.sub_trn_for_world_pos(center.x, center.z);
                // Gather primary sub-terrain + any immediately adjacent sub-terrain within `360m` of `center`
                // so border crossings (like Archosaur East Gate / North Outskirts) have zero void seams!
                let mut candidates = vec![(cr, cc, cidx)];
                let border_pad = 360.0f32;
                for dr in -1isize..=1 {
                    for dc in -1isize..=1 {
                        if dr == 0 && dc == 0 {
                            continue;
                        }
                        let nr = cr as isize + dr;
                        let nc = cc as isize + dc;
                        if nr < 0 || nr >= rows as isize || nc < 0 || nc >= cols as isize {
                            continue;
                        }
                        let (rx0, rz_top, rw, rl) = trn.sub_trn_bounds(nr as usize, nc as usize);
                        let dx = if center.x < rx0 {
                            rx0 - center.x
                        } else if center.x > rx0 + rw {
                            center.x - (rx0 + rw)
                        } else {
                            0.0
                        };
                        let dz = if center.z > rz_top {
                            center.z - rz_top
                        } else if center.z < rz_top - rl {
                            (rz_top - rl) - center.z
                        } else {
                            0.0
                        };
                        if dx <= border_pad && dz <= border_pad && candidates.len() < 4 {
                            let nidx = (nr as usize) * cols + (nc as usize);
                            candidates.push((nr as usize, nc as usize, nidx));
                        }
                    }
                }

                let mut out = Vec::new();
                for (sr, sc, sidx) in candidates {
                    let sub_name = trn
                        .sub_terrain_names
                        .get(sidx)
                        .cloned()
                        .unwrap_or_else(|| format!("{map_name}_{}", sidx + 1));
                    let Some(bk_p) = find_path_case_insensitive(dir, &format!("{sub_name}.t2bk"))
                    else {
                        continue;
                    };
                    let Ok(raw_bk) = pw_core::read_file_checked(&bk_p) else {
                        continue;
                    };
                    let (ox, oz_top, sw, sl) = trn.sub_trn_bounds(sr, sc);
                    let Ok(mesh) =
                        Terrain2HeightMesh::from_t2bk_bytes_at(&raw_bk, ox, oz_top, sw, sl, bgrid)
                    else {
                        continue;
                    };
                    let t2mk = find_path_case_insensitive(dir, &format!("{sub_name}.t2mk"))
                        .and_then(|p| pw_core::read_file_checked(p).ok())
                        .and_then(|b| T2MkSubTerrainMasks::parse(&b).ok());
                    let t2lm_day = find_path_case_insensitive(dir, &format!("{sub_name}.t2lm"))
                        .and_then(|p| pw_core::read_file_checked(p).ok())
                        .and_then(|b| T2LmSubTerrainLightmaps::parse(&b).ok());
                    let t2lm_night = find_path_case_insensitive(dir, &format!("{sub_name}.t2lm1"))
                        .and_then(|p| pw_core::read_file_checked(p).ok())
                        .and_then(|b| T2LmSubTerrainLightmaps::parse(&b).ok());
                    out.push(LoadedSubTerrain {
                        sub_idx: sidx,
                        sub_row: sr,
                        sub_col: sc,
                        sub_name,
                        height_mesh: mesh,
                        t2mk,
                        t2lm_day,
                        t2lm_night,
                    });
                }
                if !out.is_empty() {
                    return out;
                }
            }
        }

        // Single-subterrain map (`a01`, `login`, etc.)
        let find_sub_ext = |ext: &str| -> Option<PathBuf> {
            if let Some(trn) = trn2_full {
                if let Some(first_nm) = trn.sub_terrain_names.first() {
                    if let Some(p) = find_path_case_insensitive(dir, &format!("{first_nm}.{ext}")) {
                        return Some(p);
                    }
                }
            }
            find_path_case_insensitive(dir, &format!("{map_name}_1.{ext}"))
                .or_else(|| find_path_case_insensitive(dir, &format!("{map_name}_{map_name}.{ext}")))
                .or_else(|| {
                    std::fs::read_dir(dir).ok()?.flatten().map(|e| e.path()).find(|p| {
                        p.extension()
                            .and_then(|s| s.to_str())
                            .map(|s| s.eq_ignore_ascii_case(ext))
                            .unwrap_or(false)
                    })
                })
        };

        let sub_w = terrain
            .map(|t| t.terrain_width.min(1024.0))
            .unwrap_or(world.world_width.min(1024.0));
        let sub_l = terrain
            .map(|t| t.terrain_length.min(1024.0))
            .unwrap_or(world.world_length.min(1024.0));
        let bk_path = find_sub_ext("t2bk");
        let sub_name = bk_path
            .as_ref()
            .and_then(|p| p.file_stem())
            .and_then(|s| s.to_str())
            .unwrap_or(map_name)
            .to_string();

        let height_mesh = bk_path
            .as_ref()
            .and_then(|p| pw_core::read_file_checked(p).ok())
            .and_then(|raw_bk| {
                Terrain2HeightMesh::from_t2bk_bytes(&raw_bk, sub_w, sub_l, bgrid).ok()
            })
            .unwrap_or_else(|| {
                Terrain2HeightMesh::from_collision_or_procedural(height_collision, sub_w, sub_l)
            });
        let t2mk = find_sub_ext("t2mk")
            .and_then(|p| pw_core::read_file_checked(p).ok())
            .and_then(|b| T2MkSubTerrainMasks::parse(&b).ok());
        let t2lm_day = find_sub_ext("t2lm")
            .and_then(|p| pw_core::read_file_checked(p).ok())
            .and_then(|b| T2LmSubTerrainLightmaps::parse(&b).ok());
        let t2lm_night = find_sub_ext("t2lm1")
            .and_then(|p| pw_core::read_file_checked(p).ok())
            .and_then(|b| T2LmSubTerrainLightmaps::parse(&b).ok());

        vec![LoadedSubTerrain {
            sub_idx: 0,
            sub_row: 0,
            sub_col: 0,
            sub_name,
            height_mesh,
            t2mk,
            t2lm_day,
            t2lm_night,
        }]
    }

    /// Dynamically streams `A3DTerrain2` sub-terrains & `CECScene` blocks around `new_center`
    /// (`A3DTerrain2::SetLoadCenter` + `CECScene::SetCenter`). Returns `Ok(true)` if the streaming window updated.
    pub fn set_load_center(&mut self, new_center: Vec3) -> PwResult<bool> {
        let is_multi_sub = self
            .trn2_full
            .as_ref()
            .map(|t| t.sub_trn_count > 1)
            .unwrap_or(self.world.num_blocks > 1024);
        if !is_multi_sub {
            return Ok(false);
        }
        let dx = new_center.x - self.load_center.x;
        let dz = new_center.z - self.load_center.z;
        if dx * dx + dz * dz < 260.0 * 260.0 {
            return Ok(false);
        }
        let reloaded = Self::load_map_dir_at(&self.map_dir, &self.map_name, Some(new_center))?;
        *self = reloaded;
        Ok(true)
    }

    /// Samples the exact `A3DTerrain2` ground height at world `(wx, wz)` across all active streamed sub-terrains.
    pub fn sample_world_height(&self, wx: f32, wz: f32) -> f32 {
        for sub in &self.active_sub_terrains {
            if sub.height_mesh.contains_xz(wx, wz) {
                return sub.height_mesh.sample_height(wx, wz);
            }
        }
        self.height_mesh.sample_height(wx, wz)
    }

    /// Returns the local `A3DWaterArea` surface height at `(wx, wz)` ONLY if `(wx, wz)` lies inside an active water cell!
    pub fn sample_water_height_at(&self, wx: f32, wz: f32) -> Option<f32> {
        let mut best: Option<f32> = None;
        for wa in &self.scene.water_areas {
            let half_w = (wa.width_grids as f32) * wa.grid_size * 0.5;
            let half_h = (wa.height_grids as f32) * wa.grid_size * 0.5;
            let x0 = wa.center.x - half_w;
            let z_top = wa.center.z + half_h;
            if wx >= x0 && wx <= x0 + half_w * 2.0 && wz <= z_top && wz >= z_top - half_h * 2.0 {
                let gx = (((wx - x0) / wa.grid_size.max(0.5)).floor() as usize)
                    .min(wa.width_grids.saturating_sub(1));
                let gz = (((z_top - wz) / wa.grid_size.max(0.5)).floor() as usize)
                    .min(wa.height_grids.saturating_sub(1));
                let vis = wa
                    .visible_cells
                    .get(gz * wa.width_grids + gx)
                    .copied()
                    .unwrap_or(1);
                if vis != 0 {
                    best = Some(best.map_or(wa.water_height, |b| b.max(wa.water_height)));
                }
            }
        }
        best
    }

    /// Resolves the live `ClientPrecinct` containing `(wx, wz)` (polygon test first, then nearest landmark).
    pub fn precinct_at(&self, wx: f32, wz: f32) -> Option<&ClientPrecinct> {
        for p in &self.precincts {
            if !p.name.eq_ignore_ascii_case("upcoming") && p.contains_xz(wx, wz) {
                return Some(p);
            }
        }
        self.precincts
            .iter()
            .filter(|p| !p.name.eq_ignore_ascii_case("upcoming"))
            .min_by(|a, b| {
                let da = (a.spawn_pos.x - wx).powi(2) + (a.spawn_pos.z - wz).powi(2);
                let db = (b.spawn_pos.x - wx).powi(2) + (b.spawn_pos.z - wz).powi(2);
                da.partial_cmp(&db).unwrap_or(std::cmp::Ordering::Equal)
            })
            .or_else(|| self.precincts.first())
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_real_a01_login_and_midlands_world_maps() {
        let Some(elem) = pw_core::find_test_pw142_element(env!("CARGO_MANIFEST_DIR")) else {
            return;
        };
        let a01 = MapInstanceBundle::load_map_dir(elem.join("maps/a01"), "a01").unwrap();
        assert_eq!(a01.world.version, 12);
        assert_eq!(a01.world.world_width, 1024.0);
        assert_eq!(a01.world.num_blocks, 256);
        assert_eq!(a01.terrain.as_ref().unwrap().version, 1);
        assert_eq!(a01.terrain_blocks.as_ref().unwrap().num_blocks, 256);
        assert_eq!(a01.height_mesh.verts_per_side, 513);
        assert!(a01.sample_world_height(0.0, 0.0).is_finite());
        assert!(!a01.scene.ornaments.is_empty());
        assert_eq!(a01.height_collision.as_ref().unwrap().rows, 16);
        assert_eq!(a01.scene_lights.as_ref().unwrap().count, 103);
        assert!(a01.precinct_lines > 0);
        assert!(a01.region_lines > 0);

        let login = MapInstanceBundle::load_map_dir(elem.join("maps/login"), "login").unwrap();
        assert_eq!(login.world.version, 12);
        assert!(
            (login.height_mesh.min_height - 172.37).abs() < 0.5,
            "min_height={}",
            login.height_mesh.min_height
        );
        assert!(
            (login.height_mesh.max_height - 416.57).abs() < 0.5,
            "max_height={}",
            login.height_mesh.max_height
        );
        assert_eq!(login.trn2_full.as_ref().unwrap().texture_paths.len(), 17);
        assert_eq!(login.t2mk.as_ref().unwrap().layers.len(), 18);
        assert_eq!(login.t2mk.as_ref().unwrap().areas.len(), 16);
        assert_eq!(login.t2lm_day.as_ref().unwrap().area_dds_blobs.len(), 16);
        assert!(login.scene.ornaments.len() >= 190);
        let def_box = login.scene.default_box_area.as_ref().expect("default box");
        assert!(def_box.sky_tex0.to_ascii_lowercase().contains("roof.bmp"));
        assert_eq!(login.scene.water_areas.len(), 4);
        assert!((login.scene.water_areas[0].water_height - 229.0).abs() < 0.1);

        // Verify real Midlands (`maps/world` — `8192m x 11264m`, `88` sub-terrains, Archosaur `world_38`)!
        let world_map = MapInstanceBundle::load_map_dir(elem.join("maps/world"), "world").unwrap();
        let trn = world_map.trn2_full.as_ref().expect("world.trn2");
        assert_eq!(trn.sub_trn_count, 88);
        assert_eq!(trn.sub_trn_row, 11);
        assert_eq!(trn.sub_trn_col, 8);
        assert_eq!(trn.sub_terrain_names.len(), 88);
        assert_eq!(trn.sub_terrain_names[37], "world_38");
        assert_eq!(world_map.world_targets.len(), 54);
        assert_eq!(world_map.active_sub_terrains[0].sub_name, "world_38");
        // Verify Archosaur West District (`1285.395, 219.608, 1139.265`) exact height == `219.608m`!
        let arch_h = world_map.sample_world_height(1285.395, 1139.265);
        assert!(
            (arch_h - 219.608).abs() < 0.25,
            "Archosaur height mismatch: got {arch_h}"
        );
        assert!(
            world_map.scene.ornaments.len() >= 400,
            "Archosaur ornaments={}",
            world_map.scene.ornaments.len()
        );
        assert!(!world_map.scene.water_areas.is_empty());
        assert!(!world_map.scene.grass_instances.is_empty());
    }
}
