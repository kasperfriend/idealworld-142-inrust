//! Decompilation-exact `A3DTerrain2` (`.trn2`, `.t2mk`, `.t2lm`, `.t2lm1`) parsers.
//!
//! Grounded directly in:
//! - `A3DTerrain2::Load` (`0x0077d780`, `15_a3dterrain2_load_render.c`)
//! - `A3DTrn2SubLoaderB::LoadMaskDataFile` / `ReadAreaMaskData` (`0x007a1520` / `0x007a2410`, `16_a3dtrn2loaderb_t2bk_t2mk_t2lm.c`)
//! - `A3DTrn2SubLoaderB::LoadLightMapFile` (`0x007a18c0`, `16_a3dtrn2loaderb_t2bk_t2mk_t2lm.c`)

use pw_core::{zlib_uncompress, BinaryCursor, PwError, PwResult};

use crate::{MAGIC_T2LM, MAGIC_TMKB, MAGIC_TRN2};

/// Full `A3DTerrain2` `.trn2` descriptor (`0x0077d780`).
#[derive(Debug, Clone)]
pub struct Trn2FullDesc {
    pub version: u32,
    pub terrain_width: f32,
    pub terrain_length: f32,
    pub block_size: f32,
    pub block_grid: i32,
    pub num_blocks: i32,
    pub trn_row_blocks: i32,
    pub trn_col_blocks: i32,
    pub tex_count: usize,
    pub mask_block_grid: i32,
    pub mask_area_count: usize,
    pub sub_trn_count: usize,
    pub sub_trn_row: i32,
    pub sub_trn_col: i32,
    pub sub_trn_grid: i32,
    /// Detail texture VFS paths (e.g. `textures\terrain\tile\rock_05.dds`).
    pub texture_paths: Vec<String>,
    /// Sub-terrain base names (e.g. `login_login`, `a01_1`).
    pub sub_terrain_names: Vec<String>,
}

impl Trn2FullDesc {
    pub fn parse(bytes: &[u8]) -> PwResult<Self> {
        let mut cur = BinaryCursor::new(bytes);
        let magic = cur.read_u32_le()?;
        if magic != MAGIC_TRN2 {
            return Err(PwError::InvalidMagic {
                expected: "TRN2 (0x54524e32)",
                found: magic,
            });
        }
        let version = cur.read_u32_le()?;
        let terrain_width = cur.read_f32_le()?;
        let terrain_length = cur.read_f32_le()?;
        let block_size = cur.read_f32_le()?;
        let block_grid = cur.read_i32_le()?;
        let num_blocks = cur.read_i32_le()?;
        let trn_row_blocks = cur.read_i32_le()?;
        let trn_col_blocks = cur.read_i32_le()?;
        let tex_count = cur.read_i32_le()?.max(0) as usize; // 0x24
        let mask_area_count = cur.read_i32_le()?.max(0) as usize; // 0x28
        let _mask_col_areas = cur.read_i32_le()?; // 0x2c
        let mask_block_grid = cur.read_i32_le()?; // 0x30
        let sub_trn_count = cur.read_i32_le()?.max(0) as usize; // 0x34
        let sub_trn_row = cur.read_i32_le()?; // 0x38
        let sub_trn_col = cur.read_i32_le()?; // 0x3c
        let sub_trn_grid = cur.read_i32_le()?; // 0x40
        let _grid_size = cur.read_f32_le()?; // 0x44
        let tex_offset = cur.read_u32_le()? as usize; // 0x48
        let loader_id = cur.read_u32_le()?; // 0x4c
        let sub_trn_offset = cur.read_u32_le()? as usize; // 0x50

        let mut texture_paths = Vec::with_capacity(tex_count);
        if tex_offset <= bytes.len() {
            let mut tcur = BinaryCursor::new(&bytes[tex_offset..]);
            for _ in 0..tex_count {
                if let Ok(s) = tcur.read_astring_gbk() {
                    texture_paths.push(s);
                } else {
                    break;
                }
            }
        }

        let mut sub_terrain_names = Vec::new();
        if loader_id != 0 && sub_trn_offset + 4 <= bytes.len() {
            let mut scur = BinaryCursor::new(&bytes[sub_trn_offset..]);
            let _sub_ver = scur.read_u32_le();
            for _ in 0..sub_trn_count {
                if let Ok(name) = scur.read_astring_gbk() {
                    if !name.is_empty() {
                        sub_terrain_names.push(name);
                    }
                }
            }
        }

        Ok(Self {
            version,
            terrain_width,
            terrain_length,
            block_size,
            block_grid,
            num_blocks,
            trn_row_blocks,
            trn_col_blocks,
            tex_count,
            mask_block_grid,
            mask_area_count,
            sub_trn_count,
            sub_trn_row,
            sub_trn_col,
            sub_trn_grid,
            texture_paths,
            sub_terrain_names,
        })
    }

    /// Maps a world-space coordinate `(wx, wz)` to `(sub_row, sub_col, sub_idx)` (`0..sub_trn_count`).
    pub fn sub_trn_for_world_pos(&self, wx: f32, wz: f32) -> (usize, usize, usize) {
        let rows = self.sub_trn_row.max(1) as usize;
        let cols = self.sub_trn_col.max(1) as usize;
        let sub_w = self.terrain_width / (cols as f32);
        let sub_l = self.terrain_length / (rows as f32);
        let left = -self.terrain_width * 0.5;
        let top = self.terrain_length * 0.5;
        let c = (((wx - left) / sub_w.max(1.0)).floor() as isize).clamp(0, (cols - 1) as isize) as usize;
        let r = (((top - wz) / sub_l.max(1.0)).floor() as isize).clamp(0, (rows - 1) as isize) as usize;
        (r, c, r * cols + c)
    }

    /// Returns `(origin_x_left, origin_z_top, sub_width, sub_length)` in world meters for `(sub_row, sub_col)`.
    pub fn sub_trn_bounds(&self, sub_row: usize, sub_col: usize) -> (f32, f32, f32, f32) {
        let rows = self.sub_trn_row.max(1) as usize;
        let cols = self.sub_trn_col.max(1) as usize;
        let sub_w = self.terrain_width / (cols as f32);
        let sub_l = self.terrain_length / (rows as f32);
        let x0 = -self.terrain_width * 0.5 + (sub_col as f32) * sub_w;
        let z_top = self.terrain_length * 0.5 - (sub_row as f32) * sub_l;
        (x0, z_top, sub_w, sub_l)
    }
}

/// 28-byte layer descriptor in `.t2mk` v2 (`24` bytes in v1).
#[derive(Debug, Clone)]
pub struct T2MkLayerDesc {
    pub texture_idx: i32,
    pub spec_map_idx: i32,
    pub mask_size: u32,
    /// `0` = X-axis (`(z, y)` cliff), `1` = Y-axis (`(x, z)` ground), `2` = Z-axis (`(x, y)` cliff).
    pub proj_axis: u8,
    pub u_scale: f32,
    pub v_scale: f32,
    pub weight: f32,
}

/// Decoded 8-bit splat alpha mask for one layer inside one `256x256m` mask area.
#[derive(Debug, Clone)]
pub struct T2MkAreaLayerMask {
    pub layer_idx: usize,
    pub mask_size: u32,
    /// Empty when `mask_size == 0` (base layer = opaque `255` everywhere).
    pub alpha_texels: Vec<u8>,
}

/// Full `.t2mk` sub-terrain texture splat mask table (`0x007a1520` / `0x007a2410`).
#[derive(Debug, Clone)]
pub struct T2MkSubTerrainMasks {
    pub version: u32,
    pub compressed: bool,
    pub layers: Vec<T2MkLayerDesc>,
    /// Length = `mask_area_count` (typically `16` for a `4x4` mask-area `1024x1024m` sub-terrain).
    pub areas: Vec<Vec<T2MkAreaLayerMask>>,
}

impl T2MkSubTerrainMasks {
    pub fn parse(bytes: &[u8]) -> PwResult<Self> {
        let mut cur = BinaryCursor::new(bytes);
        let magic = cur.read_u32_le()?;
        if magic != MAGIC_TMKB {
            return Err(PwError::InvalidMagic {
                expected: "TMKB (0x544d4b42)",
                found: magic,
            });
        }
        let version = cur.read_u32_le()?;
        if version > 2 {
            return Err(PwError::UnsupportedVersion {
                format: "TMKB",
                version,
            });
        }
        let area_count = cur.read_i32_le()?.max(0) as usize;
        let layer_count = cur.read_i32_le()?.max(0) as usize;
        let compressed = if version >= 2 {
            let flag = cur.read_u8()? != 0;
            cur.skip(3)?;
            flag
        } else {
            false
        };

        let mut area_offsets = Vec::with_capacity(area_count);
        for _ in 0..area_count {
            area_offsets.push(cur.read_u32_le()? as usize);
        }

        let mut layers = Vec::with_capacity(layer_count);
        for _ in 0..layer_count {
            let texture_idx = cur.read_i32_le()?;
            let spec_map_idx = cur.read_i32_le()?;
            let mask_size = cur.read_i32_le()?.max(0) as u32;
            let proj_axis = cur.read_u8()?;
            cur.skip(3)?;
            let u_scale = cur.read_f32_le()?;
            let v_scale = cur.read_f32_le()?;
            let weight = if version >= 2 { cur.read_f32_le()? } else { 0.0 };
            layers.push(T2MkLayerDesc {
                texture_idx,
                spec_map_idx,
                mask_size,
                proj_axis,
                u_scale,
                v_scale,
                weight,
            });
        }

        let mut areas = Vec::with_capacity(area_count);
        for &aoff in &area_offsets {
            if aoff + 4 > bytes.len() {
                areas.push(Vec::new());
                continue;
            }
            let mut acur = BinaryCursor::new(&bytes[aoff..]);
            let n = acur.read_i32_le()?.max(0) as usize;
            let mut entries = Vec::with_capacity(n);
            for _ in 0..n {
                let li = acur.read_i32_le()?;
                let moff = acur.read_u32_le()? as usize;
                let dsz = acur.read_u32_le()? as usize;
                entries.push((li, moff, dsz));
            }

            let mut area_masks = Vec::with_capacity(n);
            for (li, moff, dsz) in entries {
                if li < 0 || (li as usize) >= layers.len() {
                    continue;
                }
                let layer_idx = li as usize;
                let msz = layers[layer_idx].mask_size;
                if msz == 0 || dsz == 0 {
                    area_masks.push(T2MkAreaLayerMask {
                        layer_idx,
                        mask_size: 0,
                        alpha_texels: Vec::new(),
                    });
                    continue;
                }
                if moff + dsz > bytes.len() {
                    continue;
                }
                let raw_slice = &bytes[moff..moff + dsz];
                let expected = (msz as usize) * (msz as usize);
                let decoded = if compressed {
                    zlib_uncompress(raw_slice, expected).unwrap_or_else(|_| vec![0u8; expected])
                } else if raw_slice.len() >= expected {
                    raw_slice[..expected].to_vec()
                } else {
                    zlib_uncompress(raw_slice, expected).unwrap_or_else(|_| vec![0u8; expected])
                };
                area_masks.push(T2MkAreaLayerMask {
                    layer_idx,
                    mask_size: msz,
                    alpha_texels: decoded,
                });
            }
            areas.push(area_masks);
        }

        Ok(Self {
            version,
            compressed,
            layers,
            areas,
        })
    }
}

/// Full `.t2lm` / `.t2lm1` sub-terrain lightmap set (`0x007a18c0`, verified `DIFF = 0` EOF).
#[derive(Debug, Clone)]
pub struct T2LmSubTerrainLightmaps {
    pub version: u32,
    pub area_count: usize,
    pub mask_tex_size: u32,
    pub flags: u32,
    pub area_data_size: usize,
    /// Raw `DDS ` (`DXT1`) or `BGR` lightmap payloads per mask area (`0..16`).
    pub area_dds_blobs: Vec<Vec<u8>>,
}

impl T2LmSubTerrainLightmaps {
    pub fn parse(bytes: &[u8]) -> PwResult<Self> {
        let mut cur = BinaryCursor::new(bytes);
        let magic = cur.read_u32_le()?;
        if magic != MAGIC_T2LM {
            return Err(PwError::InvalidMagic {
                expected: "T2LM (0x54324c4d)",
                found: magic,
            });
        }
        let version = cur.read_u32_le()?;
        let area_count = cur.read_i32_le()?.max(0) as usize;
        let mask_tex_size = cur.read_i32_le()?.max(1) as u32;
        let flags = cur.read_u32_le()?;
        let area_data_size = cur.read_u32_le()? as usize;

        let mut offsets = Vec::with_capacity(area_count);
        for _ in 0..area_count {
            offsets.push(cur.read_u32_le()? as usize);
        }

        let mut area_dds_blobs = Vec::with_capacity(area_count);
        for &off in &offsets {
            if off + area_data_size <= bytes.len() && area_data_size > 0 {
                area_dds_blobs.push(bytes[off..off + area_data_size].to_vec());
            } else {
                area_dds_blobs.push(Vec::new());
            }
        }

        Ok(Self {
            version,
            area_count,
            mask_tex_size,
            flags,
            area_data_size,
            area_dds_blobs,
        })
    }
}
