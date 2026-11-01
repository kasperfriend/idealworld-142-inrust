//! Decompilation-exact `CECScene` (`.ecwld`, `.ecbsd`, `bsdata/<map>.dat`) parsers.
//!
//! Grounded directly in:
//! - `CECScene::OpenSceneFile` (`0x0041bd00`, `01_cecscene_ecwld_ecbsd.c`)
//! - `CECScene::OpenBSDFile` (`0x0041be00`, `01_cecscene_ecwld_ecbsd.c`)
//! - `CECSceneBlock::Load` (`0x00422390` + `0x423170..0x423a50`, `19_cecsceneblock_water.c`)
//! - `CECOrnament::Load` (`0x00489e70`, `04_cecornament_bmd_litmodel.c`)
//! - `CECScnBoxArea::Load` (`0x0048a510`, `04_cecornament_bmd_litmodel.c`)
//! - `A3DWaterArea::Load` (`0x00780d30`, `19_cecsceneblock_water.c`)

use std::collections::{BTreeMap, HashMap, HashSet};
use std::path::Path;

use pw_core::{
    find_path_case_insensitive, open_afile_image, zlib_uncompress, AFileMode, BinaryCursor,
    PwError, PwResult, Vec3,
};

use crate::{MAGIC_BSDF, MAGIC_ECWD};

#[derive(Debug, Clone)]
pub struct EcwldTreeType {
    pub spt_path: String,
    pub dds_path: String,
}

#[derive(Debug, Clone)]
pub struct EcwldGrassType {
    pub grass_id: i32,
    pub alpha_blend: bool,
    pub alpha_ref: i32,
    pub scale: f32,
    pub size_var: f32,
    pub softness: f32,
    pub sight_range: f32,
    pub mox_path: String,
}

#[derive(Debug, Clone)]
pub struct SceneTreePlacement {
    pub tree_type: usize,
    pub pos: Vec3,
}

#[derive(Debug, Clone)]
pub struct SceneGrassInstance {
    pub grass_type: usize,
    pub wx: f32,
    pub wz: f32,
    pub scale: f32,
    pub yaw: f32,
}

#[derive(Debug, Clone)]
pub struct SceneOrnamentInstance {
    pub id: u32,
    pub pos: Vec3,
    pub dir: Vec3,
    pub up: Vec3,
    pub reflect: bool,
    pub refract: bool,
    /// Relative `.bmd` path inside `<map>/` (full VFS path = `litmodels\<map>\<bmd_rel_path>`).
    pub bmd_rel_path: String,
}

#[derive(Debug, Clone)]
pub struct SceneStaticEcModel {
    pub id: u32,
    pub pos: Vec3,
    pub dir: Vec3,
    pub up: Vec3,
    pub ecm_path: String,
    pub act_name: String,
}

#[derive(Debug, Clone)]
pub struct SceneBoxArea {
    pub id: u32,
    pub is_default: bool,
    pub flags: u32,
    pub pos: Vec3,
    pub ext: Vec3,
    pub axis_x: Vec3,
    pub dir: Vec3,
    pub up: Vec3,
    pub fog_start: f32,
    pub fog_end: f32,
    pub fog_density: f32,
    pub fog_color: u32,
    pub under_water_fog_start: f32,
    pub under_water_fog_end: f32,
    pub under_water_fog_density: f32,
    pub under_water_fog_color: u32,
    pub fog_start_night: f32,
    pub fog_end_night: f32,
    pub fog_density_night: f32,
    pub fog_color_night: u32,
    pub light_dir: Vec3,
    pub ambient: u32,
    pub directional: u32,
    pub ambient_night: u32,
    pub directional_night: u32,
    pub sky_speed_u: f32,
    pub sky_speed_v: f32,
    pub sky_tex0: String,
    pub sky_tex1: String,
    pub sky_tex2: String,
    pub sky_tex0_night: String,
    pub sky_tex1_night: String,
    pub sky_tex2_night: String,
    pub ambient_sfx: String,
    pub transform_time: u32,
}

#[derive(Debug, Clone)]
pub struct WaterAreaMesh {
    pub id: u32,
    pub water_height: f32,
    pub water_color: u32,
    pub edge_height: f32,
    pub width_grids: usize,
    pub height_grids: usize,
    pub grid_size: f32,
    pub center: Vec3,
    pub minor_water: bool,
    /// `width_grids * height_grids` visibility flags (`!= 0` means water quad at `(gx, gz)` is active).
    pub visible_cells: Vec<u8>,
}

/// Complete parsed `CECScene` instance combining `.ecwld`, `.ecbsd`, and `bsdata/<map>.dat`.
#[derive(Debug, Clone)]
pub struct CecSceneData {
    pub map_name: String,
    pub ecwld_version: u32,
    pub ecbsd_version: u32,
    pub world_width: f32,
    pub world_length: f32,
    pub block_size: f32,
    pub num_blocks: usize,
    pub row_blocks: usize,
    pub col_blocks: usize,
    pub tree_types: Vec<EcwldTreeType>,
    pub grass_types: Vec<EcwldGrassType>,
    pub trees: Vec<SceneTreePlacement>,
    pub grass_instances: Vec<SceneGrassInstance>,
    pub ornaments: Vec<SceneOrnamentInstance>,
    pub ecmodels: Vec<SceneStaticEcModel>,
    pub default_box_area: Option<SceneBoxArea>,
    pub box_areas: Vec<SceneBoxArea>,
    pub water_areas: Vec<WaterAreaMesh>,
}

impl CecSceneData {
    pub fn parse(
        map_name: &str,
        ecwld_bytes: &[u8],
        ecbsd_bytes: Option<&[u8]>,
        bsdata_bytes: Option<&[u8]>,
    ) -> PwResult<Self> {
        Self::parse_streaming(map_name, None, ecwld_bytes, ecbsd_bytes, bsdata_bytes, None)
    }

    /// Exact port of `CECScene::OpenSceneFile` + `CECScene::SetCenter` (`0x0041bd00` / `0x0041c8b0`):
    /// - For single-subterrain maps (`num_blocks <= 1024`) or when `stream_window` is `None`, loads all blocks.
    /// - For multi-subterrain continents (`maps/world` = `22,528` blocks across `88` sub-terrains), streams
    ///   `CECSceneBlock`s within `(center, load_radius)` and resolves `(iSubTrn, iDataIdx)` against
    ///   `bsdata/{iSubTrn + 1}.dat` for both `A3DWaterArea` and `CECGrassLand` 1-bit `512x512` bitmaps!
    pub fn parse_streaming(
        map_name: &str,
        map_dir: Option<&Path>,
        ecwld_bytes: &[u8],
        ecbsd_bytes: Option<&[u8]>,
        bsdata_bytes: Option<&[u8]>,
        stream_window: Option<(Vec3, f32)>,
    ) -> PwResult<Self> {
        let mut cur = BinaryCursor::new(ecwld_bytes);
        let magic = cur.read_u32_le()?;
        if magic != MAGIC_ECWD {
            return Err(PwError::InvalidMagic {
                expected: "ECWD (0x45435744)",
                found: magic,
            });
        }
        let version = cur.read_u32_le()?;
        let world_width = cur.read_f32_le()?;
        let world_length = cur.read_f32_le()?;
        let block_size = cur.read_f32_le()?;
        let _block_grid = cur.read_i32_le()?;
        let num_blocks = cur.read_i32_le()?.max(0) as usize;
        let row_blocks = cur.read_i32_le()?.max(1) as usize;
        let col_blocks = cur.read_i32_le()?.max(1) as usize;

        // Remaining ECWDFILEHEADER fields (`0x74` total header in v>=7):
        // `+0x24`: `tree_off` (`u32`), `+0x28`: `grass_off` (`u32`),
        // `+0x2c`: `num_tree_types` (`i32`), `+0x30`: `num_grass_types` (`i32`).
        let tree_off = cur.read_u32_le().unwrap_or(0) as usize;
        let grass_off = cur.read_u32_le().unwrap_or(0) as usize;
        let num_tree_types = cur.read_i32_le().unwrap_or(0).max(0) as usize;
        let num_grass_types = cur.read_i32_le().unwrap_or(0).max(0) as usize;
        if version >= 4 {
            let _ = cur.skip(64.min(cur.remaining()));
        }

        let block_table_off = if version >= 7 { 0x74 } else { cur.position() };
        let mut bcur = BinaryCursor::new(&ecwld_bytes[block_table_off.min(ecwld_bytes.len())..]);
        let mut block_offsets = Vec::with_capacity(num_blocks);
        for _ in 0..num_blocks {
            if bcur.remaining() < 4 {
                break;
            }
            block_offsets.push(bcur.read_u32_le()? as usize);
        }

        let mut tree_types = Vec::with_capacity(num_tree_types);
        if tree_off > 0 && tree_off < ecwld_bytes.len() {
            let mut tcur = BinaryCursor::new(&ecwld_bytes[tree_off..]);
            for _ in 0..num_tree_types {
                let Ok(spt_path) = tcur.read_astring_gbk() else { break };
                let Ok(dds_path) = tcur.read_astring_gbk() else { break };
                tree_types.push(EcwldTreeType { spt_path, dds_path });
            }
        }

        let mut grass_types = Vec::with_capacity(num_grass_types);
        if grass_off > 0 && grass_off < ecwld_bytes.len() {
            let mut gcur = BinaryCursor::new(&ecwld_bytes[grass_off..]);
            for gid in 0..num_grass_types {
                if gcur.remaining() < 24 {
                    break;
                }
                let alpha_blend = gcur.read_u8()? != 0;
                gcur.skip(3)?;
                let alpha_ref = gcur.read_i32_le()?;
                let scale = gcur.read_f32_le()?;
                let size_var = gcur.read_f32_le()?;
                let softness = gcur.read_f32_le()?;
                let sight_range = gcur.read_f32_le().unwrap_or(100.0);
                let mox_path = gcur.read_astring_gbk().unwrap_or_default();
                grass_types.push(EcwldGrassType {
                    grass_id: gid as i32,
                    alpha_blend,
                    alpha_ref,
                    scale,
                    size_var,
                    softness,
                    sight_range,
                    mox_path,
                });
            }
        }

        let ecbsd_version = if let Some(bsd) = ecbsd_bytes {
            let (mode, mut c) = open_afile_image(bsd);
            if mode == AFileMode::BinaryMoxb && c.read_u32_le().unwrap_or(0) == MAGIC_BSDF {
                c.read_u32_le().unwrap_or(12)
            } else {
                12
            }
        } else {
            12
        };

        let left = -world_width * 0.5;
        let top = world_length * 0.5;
        let use_streaming = num_blocks > 1024 && stream_window.is_some();

        let mut trees = Vec::new();
        let mut seen_trees: HashSet<(usize, i32, i32)> = HashSet::new();
        let mut ornament_map: BTreeMap<u32, usize> = BTreeMap::new();
        let mut ornaments = Vec::new();
        let mut ecmodels = Vec::new();
        let mut seen_ecmodels = HashSet::new();
        let mut seen_water_offs = HashSet::new();
        let mut water_bsd_offs = Vec::new();
        let mut seen_box_offs = HashSet::new();
        let mut box_bsd_offs = Vec::new();
        let mut seen_grass_offs = HashSet::new();
        let mut grass_bsd_offs = Vec::new();

        for (blk_idx, &boff) in block_offsets.iter().enumerate() {
            if boff + 0x2c > ecwld_bytes.len() {
                continue;
            }
            let r_est = blk_idx / col_blocks.max(1);
            let c_est = blk_idx % col_blocks.max(1);
            let bx_est = left + (c_est as f32 + 0.5) * block_size;
            let bz_est = top - (r_est as f32 + 0.5) * block_size;

            let in_geom_window = if let Some((center, rad)) = stream_window {
                !use_streaming
                    || ((bx_est - center.x).abs() <= rad && (bz_est - center.z).abs() <= rad)
            } else {
                true
            };
            // Always scan block 0 (`default_box_area`) + wide `2400m` box-area window so sky/fog OBBs are always available!
            let in_box_window = if let Some((center, _)) = stream_window {
                !use_streaming
                    || blk_idx == 0
                    || ((bx_est - center.x).abs() <= 2400.0 && (bz_est - center.z).abs() <= 2400.0)
            } else {
                true
            };
            if !in_geom_window && !in_box_window {
                continue;
            }

            let mut sc = BinaryCursor::new(&ecwld_bytes[boff..]);
            let r = sc.read_u16_le()? as usize;
            let c = sc.read_u16_le()? as usize;
            let mut counts = [0usize; 10];
            for slot in &mut counts {
                *slot = sc.read_i32_le()?.max(0) as usize;
            }

            if !in_geom_window {
                // Fast-path skip to Stream 3 (`counts[4]` BoxAreas) only
                let tree_bytes = counts[0] * if version < 5 { 12 } else { 16 };
                let water_bytes = counts[1] * 8;
                let orn_bytes = if version < 4 { 0 } else { counts[3] * 8 };
                let skip_total = tree_bytes + water_bytes + orn_bytes;
                if version >= 4 && sc.remaining() >= skip_total + counts[4] * 8 {
                    let _ = sc.skip(skip_total);
                    for _ in 0..counts[4] {
                        let bid = sc.read_u32_le()?;
                        let boff_bsd = sc.read_u32_le()? as usize;
                        if seen_box_offs.insert(boff_bsd) {
                            box_bsd_offs.push((bid, boff_bsd));
                        }
                    }
                }
                continue;
            }

            let bx = left + (c as f32) * block_size;
            let bz = top - (r as f32) * block_size;

            // Stream 0: Trees (`c[0]`) — 16 bytes in v>=5 (`u32 type, f32 wx, f32 wy, f32 wz` in world space!), 12 bytes in v<5
            for _ in 0..counts[0] {
                if version < 5 {
                    if sc.remaining() < 12 {
                        break;
                    }
                    let tp = sc.read_u32_le()? as usize;
                    let lx = sc.read_f32_le()?;
                    let lz = sc.read_f32_le()?;
                    let wx = bx + lx;
                    let wz = bz - lz;
                    if seen_trees.insert((tp, (wx * 10.0) as i32, (wz * 10.0) as i32)) {
                        trees.push(SceneTreePlacement {
                            tree_type: tp,
                            pos: Vec3::new(wx, 0.0, wz),
                        });
                    }
                } else {
                    if sc.remaining() < 16 {
                        break;
                    }
                    let tp = sc.read_u32_le()? as usize;
                    let wx = sc.read_f32_le()?;
                    let wy = sc.read_f32_le()?;
                    let wz = sc.read_f32_le()?;
                    if seen_trees.insert((tp, (wx * 10.0) as i32, (wz * 10.0) as i32)) {
                        trees.push(SceneTreePlacement {
                            tree_type: tp,
                            pos: Vec3::new(wx, wy, wz),
                        });
                    }
                }
            }

            // Stream 1: Water (`c[1]`) — `(u32 id, u32 bsd_off)`
            for _ in 0..counts[1] {
                if sc.remaining() < 8 {
                    break;
                }
                let wid = sc.read_u32_le()?;
                let woff = sc.read_u32_le()? as usize;
                if seen_water_offs.insert(woff) {
                    water_bsd_offs.push((wid, woff));
                }
            }

            // Stream 2 in file = `c[3]` Ornaments! (`0x422390` calls `LoadOrnaments` BEFORE `LoadBoxAreas` & `LoadGrasses`)
            if version < 4 {
                if let Some(bsd) = ecbsd_bytes {
                    for idx in 0..counts[3] {
                        if let Some(orn) =
                            parse_ornament_at_cur(&mut sc, ecbsd_version, idx as u32)
                        {
                            let _ = bsd;
                            ornaments.push(orn);
                        } else {
                            break;
                        }
                    }
                }
            } else {
                for _ in 0..counts[3] {
                    if sc.remaining() < 8 {
                        break;
                    }
                    let oid = sc.read_u32_le()?;
                    let ooff = sc.read_u32_le()?;
                    if !ornament_map.contains_key(&ooff) {
                        if let Some(bsd) = ecbsd_bytes {
                            if (ooff as usize) < bsd.len() {
                                let mut ocur = BinaryCursor::new(&bsd[ooff as usize..]);
                                if let Some(orn) =
                                    parse_ornament_at_cur(&mut ocur, ecbsd_version, oid)
                                {
                                    let new_idx = ornaments.len();
                                    ornament_map.insert(ooff, new_idx);
                                    ornaments.push(orn);
                                }
                            }
                        }
                    }
                }
            }

            // Stream 3 in file = `c[4]` BoxAreas (`(u32 id, u32 bsd_off)`)
            for _ in 0..counts[4] {
                if sc.remaining() < 8 {
                    break;
                }
                let bid = sc.read_u32_le()?;
                let boff_bsd = sc.read_u32_le()? as usize;
                if seen_box_offs.insert(boff_bsd) {
                    box_bsd_offs.push((bid, boff_bsd));
                }
            }

            // Stream 4 in file = `c[2]` Grasses (`(u32 id, u32 bsd_off)`)
            for _ in 0..counts[2] {
                if sc.remaining() < 8 {
                    break;
                }
                let gid = sc.read_u32_le()?;
                let goff_bsd = sc.read_u32_le()? as usize;
                if seen_grass_offs.insert(goff_bsd) {
                    grass_bsd_offs.push((gid, goff_bsd));
                }
            }

            // Stream 5 in file = `c[5]` Effects (`0x3c` in v>=12 + `AString`, + `AString` in v>=6)
            let eff_hdr = if version < 3 {
                0x28
            } else if version < 6 {
                0x2c
            } else if version < 8 {
                0x30
            } else if version < 12 {
                0x38
            } else {
                0x3c
            };
            for _ in 0..counts[5] {
                if sc.remaining() < eff_hdr {
                    break;
                }
                let _ = sc.skip(eff_hdr);
                let _ = sc.read_astring_gbk();
                if version >= 6 {
                    let _ = sc.read_astring_gbk();
                }
            }

            // Stream 6 in file = `c[6]` ECModels (`0x28` + 2 `AString`s)
            for _ in 0..counts[6] {
                if sc.remaining() < 0x28 {
                    break;
                }
                let eid = sc.read_u32_le()?;
                let pos = sc.read_vec3_le()?;
                let dir = sc.read_vec3_le()?;
                let up = sc.read_vec3_le()?;
                let ecm_path = sc.read_astring_gbk().unwrap_or_default();
                let act_name = sc.read_astring_gbk().unwrap_or_default();
                if !ecm_path.is_empty() && seen_ecmodels.insert(eid) {
                    ecmodels.push(SceneStaticEcModel {
                        id: eid,
                        pos,
                        dir,
                        up,
                        ecm_path,
                        act_name,
                    });
                }
            }
        }

        // Parse BoxAreas from `.ecbsd`
        let mut default_box_area = None;
        let mut box_areas = Vec::new();
        if let Some(bsd) = ecbsd_bytes {
            for (bid, boff_bsd) in box_bsd_offs {
                if let Some(ba) = parse_box_area(bsd, boff_bsd, bid, ecbsd_version) {
                    if ba.is_default && default_box_area.is_none() {
                        default_box_area = Some(ba.clone());
                    }
                    box_areas.push(ba);
                }
            }
        }

        // Lazy per-subterrain `bsdata/{sub_trn + 1}.dat` cache (`a01.dat` / `1..88.dat`)
        let mut bsdata_cache: HashMap<i32, Option<(Vec<u8>, Vec<usize>)>> = HashMap::new();
        if let Some(bs) = bsdata_bytes {
            let offs = parse_bsdata_offset_table(bs);
            bsdata_cache.insert(-1, Some((bs.to_vec(), offs)));
        }

        // Parse WaterAreas from `.ecbsd` `(iSubTrn, iDataIdx)` -> `bsdata/{iSubTrn + 1}.dat` (`0x00780d30`)
        let mut water_areas = Vec::new();
        if let Some(bsd) = ecbsd_bytes {
            for (_wid, woff) in water_bsd_offs {
                if woff + 8 <= bsd.len() {
                    let mut wcur = BinaryCursor::new(&bsd[woff..]);
                    let sub_trn = wcur.read_i32_le().unwrap_or(0);
                    let data_idx = wcur.read_u32_le().unwrap_or(0) as usize;
                    if let Some((bsdat, chunk_offsets)) =
                        get_or_load_bsdata(&mut bsdata_cache, map_dir, map_name, sub_trn)
                    {
                        if let Some(&chunk_off) = chunk_offsets.get(data_idx) {
                            if let Some(wa) = parse_water_area(bsdat, chunk_off) {
                                water_areas.push(wa);
                            }
                        }
                    }
                }
            }
        }

        // Parse 3D Grass BitsMaps (`ECBSDFILEGRASS` `36B`: `<iffffiiii` + `bsdata/{iSubTrn + 1}.dat` zlib 1-bit `512x512` grids!)
        let mut grass_instances = Vec::new();
        let grass_focus = stream_window.map(|(c, _)| c);
        if let Some(bsd) = ecbsd_bytes {
            for (_gid, goff) in grass_bsd_offs {
                if grass_instances.len() >= 1800 || goff + 36 > bsd.len() {
                    continue;
                }
                let mut gcur = BinaryCursor::new(&bsd[goff..]);
                let Ok(gtype_i) = gcur.read_i32_le() else { continue };
                if gtype_i < 0 || (gtype_i as usize) >= grass_types.len() {
                    continue;
                }
                let gtype = gtype_i as usize;
                let Ok(gcenter) = gcur.read_vec3_le() else { continue };
                let Ok(grid_sz) = gcur.read_f32_le() else { continue };
                let Ok(gw_i) = gcur.read_i32_le() else { continue };
                let Ok(gh_i) = gcur.read_i32_le() else { continue };
                let Ok(sub_trn) = gcur.read_i32_le() else { continue };
                let Ok(data_idx_i) = gcur.read_i32_le() else { continue };
                if gw_i <= 0 || gh_i <= 0 || data_idx_i < 0 {
                    continue;
                }
                if let Some(fc) = grass_focus {
                    let dx = gcenter.x - fc.x;
                    let dz = gcenter.z - fc.z;
                    if dx * dx + dz * dz > 260.0 * 260.0 {
                        continue;
                    }
                }
                let gw = gw_i as usize;
                let gh = gh_i as usize;
                let data_idx = data_idx_i as usize;
                let Some((bsdat, chunk_offsets)) =
                    get_or_load_bsdata(&mut bsdata_cache, map_dir, map_name, sub_trn)
                else {
                    continue;
                };
                let Some(&c_off) = chunk_offsets.get(data_idx) else {
                    continue;
                };
                if c_off + 8 > bsdat.len() {
                    continue;
                }
                let comp_sz = u32::from_le_bytes([
                    bsdat[c_off],
                    bsdat[c_off + 1],
                    bsdat[c_off + 2],
                    bsdat[c_off + 3],
                ]) as usize;
                let uncomp_sz = u32::from_le_bytes([
                    bsdat[c_off + 4],
                    bsdat[c_off + 5],
                    bsdat[c_off + 6],
                    bsdat[c_off + 7],
                ]) as usize;
                if c_off + 8 + comp_sz > bsdat.len() || uncomp_sz == 0 || uncomp_sz > 262_144 {
                    continue;
                }
                let Ok(bits) = zlib_uncompress(&bsdat[c_off + 8..c_off + 8 + comp_sz], uncomp_sz)
                else {
                    continue;
                };
                let half_w = (gw as f32) * grid_sz * 0.5;
                let half_h = (gh as f32) * grid_sz * 0.5;
                let x0 = gcenter.x - half_w;
                let z0 = gcenter.z + half_h;
                let base_scale = grass_types[gtype].scale.clamp(0.4, 3.0);
                // Sample stride = 3 cells (`1.5m`) to keep dense lush meadows well within real-time vertex budgets
                let step = 3usize;
                for gz in (0..gh).step_by(step) {
                    for gx in (0..gw).step_by(step) {
                        let bit_idx = gz * gw + gx;
                        let byte_i = bit_idx >> 3;
                        if byte_i >= bits.len() {
                            break;
                        }
                        if (bits[byte_i] & (1 << (bit_idx & 7))) != 0 {
                            let h_hash = ((bit_idx as u32).wrapping_mul(2654435761)) >> 16;
                            let jx = ((h_hash & 0xFF) as f32 / 255.0 - 0.5) * grid_sz * 1.4;
                            let jz = (((h_hash >> 8) & 0xFF) as f32 / 255.0 - 0.5) * grid_sz * 1.4;
                            let wx = x0 + (gx as f32) * grid_sz + jx;
                            let wz = z0 - (gz as f32) * grid_sz + jz;
                            if let Some(fc) = grass_focus {
                                let d2 = (wx - fc.x) * (wx - fc.x) + (wz - fc.z) * (wz - fc.z);
                                if d2 > 135.0 * 135.0 {
                                    continue;
                                }
                            }
                            let yaw = ((h_hash & 0x3FF) as f32 / 1024.0) * core::f32::consts::TAU;
                            let sc_var = 0.85 + ((h_hash & 0x3F) as f32 / 63.0) * 0.35;
                            grass_instances.push(SceneGrassInstance {
                                grass_type: gtype,
                                wx,
                                wz,
                                scale: base_scale * sc_var,
                                yaw,
                            });
                            if grass_instances.len() >= 1800 {
                                break;
                            }
                        }
                    }
                    if grass_instances.len() >= 1800 {
                        break;
                    }
                }
            }
        }

        Ok(Self {
            map_name: map_name.to_string(),
            ecwld_version: version,
            ecbsd_version,
            world_width,
            world_length,
            block_size,
            num_blocks,
            row_blocks,
            col_blocks,
            tree_types,
            grass_types,
            trees,
            grass_instances,
            ornaments,
            ecmodels,
            default_box_area,
            box_areas,
            water_areas,
        })
    }

    /// Exact port of `CECScene::UpdateBoxAreas` (`CECScnBoxArea` OBB camera lookup):
    /// selects the tightest non-default `SceneBoxArea` whose oriented bounding box contains `pos`,
    /// falling back to `self.default_box_area`.
    pub fn active_box_area_at(&self, pos: Vec3) -> Option<&SceneBoxArea> {
        let mut best: Option<(&SceneBoxArea, f32)> = None;
        for ba in &self.box_areas {
            if ba.is_default {
                continue;
            }
            if ba.contains_point(pos) {
                let vol = ba.ext.x.abs() * ba.ext.y.abs() * ba.ext.z.abs();
                if best.map(|(_, bv)| vol < bv).unwrap_or(true) {
                    best = Some((ba, vol));
                }
            }
        }
        best.map(|(b, _)| b).or(self.default_box_area.as_ref())
    }
}

impl SceneBoxArea {
    /// Oriented bounding box containment test (`|dot(p - pos, axis)| <= ext`).
    pub fn contains_point(&self, p: Vec3) -> bool {
        let d = p.sub(self.pos);
        let ax = if self.axis_x.length_sq() > 0.25 {
            self.axis_x.normalized()
        } else {
            self.up.cross(self.dir).normalized()
        };
        let ay = if self.up.length_sq() > 0.25 {
            self.up.normalized()
        } else {
            Vec3::UNIT_Y
        };
        let az = if self.dir.length_sq() > 0.25 {
            self.dir.normalized()
        } else {
            Vec3::UNIT_Z
        };
        d.dot(ax).abs() <= self.ext.x.abs()
            && d.dot(ay).abs() <= self.ext.y.abs()
            && d.dot(az).abs() <= self.ext.z.abs()
    }
}

fn parse_ornament_at_cur(
    cur: &mut BinaryCursor<'_>,
    ecbsd_ver: u32,
    id: u32,
) -> Option<SceneOrnamentInstance> {
    let pos = cur.read_vec3_le().ok()?;
    let dir = cur.read_vec3_le().ok()?;
    let up = cur.read_vec3_le().ok()?;
    let (reflect, refract) = if ecbsd_ver >= 2 {
        let rf = cur.read_u8().ok()? != 0;
        let rr = cur.read_u8().ok()? != 0;
        let _ = cur.skip(2);
        (rf, rr)
    } else {
        (false, false)
    };
    let bmd_rel_path = cur.read_astring_gbk().ok()?;
    if bmd_rel_path.is_empty() {
        return None;
    }
    Some(SceneOrnamentInstance {
        id,
        pos,
        dir,
        up,
        reflect,
        refract,
        bmd_rel_path,
    })
}

fn parse_box_area(bsd: &[u8], off: usize, id: u32, ver: u32) -> Option<SceneBoxArea> {
    if off + 140 > bsd.len() {
        return None;
    }
    let mut c = BinaryCursor::new(&bsd[off..]);
    let is_default = c.read_i32_le().ok()? != 0;
    // Read `ECWDFILEBOXAREA11` (`0xc8` bytes in v12, `0xb8` in v11, etc.)
    let hdr_bytes = if ver >= 12 {
        0xdc
    } else if ver >= 11 {
        0xc8
    } else if ver >= 9 {
        0xb8
    } else {
        0x8c
    };
    if c.remaining() < hdr_bytes {
        return None;
    }
    let raw_hdr = c.read_bytes(hdr_bytes).ok()?;
    let mut hc = BinaryCursor::new(raw_hdr);
    let flags = hc.read_u32_le().ok()?;
    let pos = hc.read_vec3_le().ok()?;
    let ext = hc.read_vec3_le().ok()?;
    let axis_x = hc.read_vec3_le().ok()?;
    let up = hc.read_vec3_le().ok()?;
    let dir = hc.read_vec3_le().ok()?;
    let fog_start = hc.read_f32_le().ok()?;
    let fog_end = hc.read_f32_le().ok()?;
    let fog_density = hc.read_f32_le().ok()?;
    let fog_color = hc.read_u32_le().ok()?;
    let under_water_fog_start = hc.read_f32_le().ok()?;
    let under_water_fog_end = hc.read_f32_le().ok()?;
    let under_water_fog_density = hc.read_f32_le().ok()?;
    let under_water_fog_color = hc.read_u32_le().ok()?;
    // Above-cloud fog quadruple (`+0x60..+0x70` inside `ECWDFILEBOXAREA`)
    let _cloud_fog_start = hc.read_f32_le().unwrap_or(50.0);
    let _cloud_fog_end = hc.read_f32_le().unwrap_or(500.0);
    let _cloud_fog_density = hc.read_f32_le().unwrap_or(0.5);
    let _cloud_fog_color = hc.read_u32_le().unwrap_or(0xFFFF_FFFF);
    let light_dir = hc.read_vec3_le().ok()?;
    let ambient = hc.read_u32_le().ok()?;
    let directional = hc.read_u32_le().ok()?;
    let _cloud_amb = if ver >= 8 { hc.read_u32_le().unwrap_or(ambient) } else { ambient };
    let _cloud_dir = if ver >= 8 { hc.read_u32_le().unwrap_or(directional) } else { directional };
    let sky_speed_u = hc.read_f32_le().unwrap_or(0.02);
    let sky_speed_v = hc.read_f32_le().unwrap_or(0.02);
    let _unk_98 = hc.read_u32_le().unwrap_or(0);
    let transform_time = hc.read_u32_le().unwrap_or(2000);
    let _rain_speed = hc.read_i32_le().unwrap_or(0);
    let _rain_size = hc.read_f32_le().unwrap_or(0.0);
    let _rain_color = hc.read_u32_le().unwrap_or(0);
    let _snow_speed = hc.read_i32_le().unwrap_or(0);
    let _snow_size = hc.read_f32_le().unwrap_or(0.0);
    let _snow_color = hc.read_u32_le().unwrap_or(0);
    let _sun_power = if ver >= 7 { hc.read_f32_le().unwrap_or(1.0) } else { 1.0 };
    let _sun_power_n = if ver >= 9 { hc.read_f32_le().unwrap_or(1.0) } else { 1.0 };
    let ambient_night = if ver >= 9 { hc.read_u32_le().unwrap_or(ambient) } else { ambient };
    let directional_night = if ver >= 9 { hc.read_u32_le().unwrap_or(directional) } else { directional };
    let _cloud_amb_n = if ver >= 9 { hc.read_u32_le().unwrap_or(ambient_night) } else { ambient_night };
    let _cloud_dir_n = if ver >= 9 { hc.read_u32_le().unwrap_or(directional_night) } else { directional_night };
    let fog_start_night = if ver >= 10 { hc.read_f32_le().unwrap_or(fog_start) } else { fog_start };
    let fog_end_night = if ver >= 10 { hc.read_f32_le().unwrap_or(fog_end) } else { fog_end };
    let fog_density_night = if ver >= 10 { hc.read_f32_le().unwrap_or(fog_density) } else { fog_density };
    let fog_color_night = if ver >= 10 { hc.read_u32_le().unwrap_or(fog_color) } else { fog_color };

    let sky_tex0 = c.read_astring_gbk().unwrap_or_default();
    let sky_tex1 = c.read_astring_gbk().unwrap_or_default();
    let sky_tex2 = c.read_astring_gbk().unwrap_or_default();
    let ambient_sfx = c.read_astring_gbk().unwrap_or_default();
    let (sky_tex0_night, sky_tex1_night, sky_tex2_night) = if ver >= 9 {
        (
            c.read_astring_gbk().unwrap_or_default(),
            c.read_astring_gbk().unwrap_or_default(),
            c.read_astring_gbk().unwrap_or_default(),
        )
    } else {
        (String::new(), String::new(), String::new())
    };

    Some(SceneBoxArea {
        id,
        is_default,
        flags,
        pos,
        ext,
        axis_x,
        dir,
        up,
        fog_start,
        fog_end,
        fog_density,
        fog_color,
        under_water_fog_start,
        under_water_fog_end,
        under_water_fog_density,
        under_water_fog_color,
        fog_start_night,
        fog_end_night,
        fog_density_night,
        fog_color_night,
        light_dir,
        ambient,
        directional,
        ambient_night,
        directional_night,
        sky_speed_u,
        sky_speed_v,
        sky_tex0,
        sky_tex1,
        sky_tex2,
        sky_tex0_night,
        sky_tex1_night,
        sky_tex2_night,
        ambient_sfx,
        transform_time,
    })
}

fn get_or_load_bsdata<'a>(
    bsdata_cache: &'a mut HashMap<i32, Option<(Vec<u8>, Vec<usize>)>>,
    map_dir: Option<&Path>,
    map_name: &str,
    sub_trn: i32,
) -> Option<&'a (Vec<u8>, Vec<usize>)> {
    if !bsdata_cache.contains_key(&sub_trn) {
        let loaded = map_dir
            .and_then(|dir| {
                let cand1 = format!("bsdata/{}.dat", sub_trn + 1);
                let cand2 = format!("bsdata/{map_name}.dat");
                find_path_case_insensitive(dir, &cand1)
                    .or_else(|| find_path_case_insensitive(dir, &cand2))
                    .and_then(|p| pw_core::read_file_checked(p).ok())
            })
            .map(|bytes| {
                let offs = parse_bsdata_offset_table(&bytes);
                (bytes, offs)
            });
        bsdata_cache.insert(sub_trn, loaded);
    }
    if bsdata_cache.get(&sub_trn).and_then(|v| v.as_ref()).is_some() {
        bsdata_cache.get(&sub_trn).and_then(|v| v.as_ref())
    } else {
        bsdata_cache.get(&-1).and_then(|v| v.as_ref())
    }
}

fn parse_bsdata_offset_table(bsdat: &[u8]) -> Vec<usize> {
    if bsdat.len() < 12 {
        return Vec::new();
    }
    let count = u32::from_le_bytes([
        bsdat[bsdat.len() - 4],
        bsdat[bsdat.len() - 3],
        bsdat[bsdat.len() - 2],
        bsdat[bsdat.len() - 1],
    ]) as usize;
    let table_bytes = count.saturating_mul(4);
    if count == 0 || count > 65536 || bsdat.len() < 4 + table_bytes {
        return Vec::new();
    }
    let start = bsdat.len() - 4 - table_bytes;
    let mut cur = BinaryCursor::new(&bsdat[start..bsdat.len() - 4]);
    let mut offs = Vec::with_capacity(count);
    for _ in 0..count {
        if let Ok(o) = cur.read_u32_le() {
            offs.push(o as usize);
        }
    }
    offs
}

fn parse_water_area(bsdat: &[u8], off: usize) -> Option<WaterAreaMesh> {
    if off + 44 > bsdat.len() {
        return None;
    }
    let mut c = BinaryCursor::new(&bsdat[off..]);
    let ver = c.read_u32_le().ok()?;
    if ver != 0x1000_1000 && ver != 0x1000_2000 && ver != 0x1000_3000 {
        return None;
    }
    let id = c.read_u32_le().ok()?;
    let water_color = if ver >= 0x1000_3000 {
        c.read_u32_le().ok()?
    } else {
        0xA030_6878
    };
    let water_height = c.read_f32_le().ok()?;
    let edge_height = c.read_f32_le().ok()?;
    let width_grids = c.read_i32_le().ok()?.max(0) as usize;
    let height_grids = c.read_i32_le().ok()?.max(0) as usize;
    let grid_size = c.read_f32_le().ok()?;
    let center = c.read_vec3_le().ok()?;
    let minor_water = if ver >= 0x1000_2000 {
        c.read_u8().ok()? != 0
    } else {
        false
    };
    let n_cells = width_grids.saturating_mul(height_grids);
    let visible_cells = if n_cells > 0 && c.remaining() >= n_cells {
        c.read_bytes(n_cells).ok()?.to_vec()
    } else {
        vec![1u8; n_cells]
    };

    Some(WaterAreaMesh {
        id,
        water_height,
        water_color,
        edge_height,
        width_grids,
        height_grids,
        grid_size,
        center,
        minor_water,
        visible_cells,
    })
}
