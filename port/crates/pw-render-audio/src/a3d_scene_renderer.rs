//! Angelica3D Scene Graph (`CECScene` + `A3DTerrain2` + `A3DLitModel` + `A3DSkinModel` +
//! `A3DSkySphere` + `A3DWaterArea`) & `AUIManager` 2D Compositor.
//!
//! Shared by BOTH:
//! 1. Hardware Direct3D 9 (`d3d9.dll` `IDirect3DDevice9` in `d3d9_backend.rs` on Windows), and
//! 2. Perspective-correct Z-buffered rasterizer (`render_scene_and_ui_cpu`) for cross-platform
//!    headless visual verification & software fallback.

use std::collections::HashMap;

use pw_aui::{AuiControlKind, AuiDialogLayout, AuiManager, AuiRuntime};
use pw_core::{Aabb, Mat4, Vec3};
use pw_pck::VirtualFileSystem;
use pw_world::{MapInstanceBundle, SceneBoxArea, T2LmSubTerrainLightmaps, T2MkSubTerrainMasks};

use crate::a3d_models::{
    load_cec_face_bundle, load_character_customize_ini, load_player_character_skins_custom,
    ornament_world_matrix, read_model_texture_bytes, select_cec_face_submesh_tint,
    tint_surface_image_rgb, A3dLitModel, A3dLitVertex, A3dMoxMesh, A3dSkin, A3dSkinSubMesh,
    A3dSkyDome, A3dSkySphereParams,
};
use crate::a3d_skeleton::{
    build_speedtree_batches, class_signature_weapon_ski, extract_spt_bark_texture,
    load_ecm_rig_and_skins, player_smd_candidates, skin_submesh_vertices, A3dSkeleton,
    ActorActionKind, LoadedSkeletonRig,
};
use crate::icon_atlas::{
    load_minimap_composite_at, load_regional_map_texture, load_world_map_texture, IconAtlas,
};
use crate::image_dds::{decode_cur_or_ani, decode_surface_auto, SurfaceImage};
use crate::software_3d::FrameBuffer;
use crate::ttf_font::TtfFontAtlas;
use crate::A3DCamera;

/// Returns the authentic 4-race 3D aerogear `.ecm` (`models.pck`) and fallback `(up, back)` offset for class `cls`:
/// - Human (`0` Blademaster, `1` Wizard): `玄火飞剑` (`CC_feijian` <-> `HH_feijian` under character's feet)
/// - Tideborn (`2` Psychic, `5` Assassin): `幻彩翅膀` (`75KB` iridescent crystal Tideborn wings, `CC_chibang` <-> `HH_chibang`)
/// - Untamed (`3` Venomancer, `4` Barbarian): `狮鹫` (`66KB` winged griffin mount, `CC_feijian` <-> `HH_feijian`)
/// - Winged Elf (`6` Archer, `7` Cleric): `六翼天鹅之翅` (`30KB` 6-wing seraph wings, `CC_chibang` <-> `HH_chibang`)
pub fn class_aerogear_ecm(cls: i32) -> (&'static str, f32, f32) {
    match cls.clamp(0, 7) {
        0 | 1 => ("models/players/通用装备/飞剑/玄火飞剑/玄火飞剑.ecm", 0.0, 0.0),
        2 | 5 => ("models/players/通用装备/翅膀/幻彩翅膀/幻彩翅膀.ecm", 0.0, 0.0),
        3 | 4 => ("models/players/通用装备/飞剑/狮鹫/狮鹫.ecm", 0.0, 0.0),
        _ => ("models/players/通用装备/翅膀/六翼天鹅翅/六翼天鹅之翅.ecm", 0.0, 0.0),
    }
}

#[derive(Debug, Clone)]
pub struct GpuMeshBatch {
    pub tex_id: usize,
    pub two_sided: bool,
    pub alpha_test: bool,
    pub alpha_blend: bool,
    pub verts: Vec<A3dLitVertex>,
    pub indices: Vec<u16>,
}

#[derive(Debug, Clone)]
pub struct OrnamentDrawInstance {
    pub model_idx: usize,
    pub world_mat: Mat4,
    pub world_aabb: Aabb,
}

#[derive(Debug, Clone)]
pub struct TerrainBlockDraw {
    pub sub_slot: usize,
    pub area_idx: usize,
    pub tex_id: usize,
    pub world_aabb: Aabb,
    pub verts: Vec<A3dLitVertex>,
    pub indices: Vec<u16>,
}

/// Per-subterrain `.t2mk` + `.t2lm` splatting descriptor for full-resolution per-pixel `A3DTerrain2` detail shading.
pub struct TerrainSubSplat {
    pub origin_x: f32,
    pub origin_z_top: f32,
    pub world_w: f32,
    pub world_l: f32,
    pub t2mk: Option<T2MkSubTerrainMasks>,
    pub lm_day: Vec<Option<SurfaceImage>>,
    /// `.t2lm1` night lightmaps + the active day→night blend, used by the per-pixel
    /// `sample_terrain_splat_at` path so `--night`/`--time` darken the terrain live.
    pub lm_night: Vec<Option<SurfaceImage>>,
    pub night_weight: f32,
}

#[derive(Debug, Clone)]
pub struct DynamicCharacterActor {
    pub role_id: u32,
    pub name: String,
    pub cls: i32,
    pub gender: u8,
    pub appearance_preset: u8,
    pub action: ActorActionKind,
    /// When `Some(path)`, renders the real 3D NPC/Monster `.ecm` (`models/npcs/.../*.ecm`) instead of a player character.
    pub ecm_path: Option<String>,
    /// When `Some(path)`, renders the character's 3D racial aerogear `.ecm` (`飞剑` / `翅膀` / `狮鹫`) during flight.
    pub fly_ecm_path: Option<String>,
    pub pos: Vec3,
    pub dir: Vec3,
    pub scale: f32,
    pub selected: bool,
}

#[derive(Clone)]
pub struct CachedSkinSubMesh {
    pub tex_id: usize,
    pub alpha_test: bool,
    pub bone_map: Vec<usize>,
    pub submesh: A3dSkinSubMesh,
}

pub struct CachedFaceTemplate {
    pub face_skeleton: Option<A3dSkeleton>,
    pub face_submeshes: Vec<CachedSkinSubMesh>,
}

pub struct CachedEcmActor {
    pub scale: f32,
    pub rig: LoadedSkeletonRig,
    pub submeshes: Vec<CachedSkinSubMesh>,
}

#[derive(Debug, Clone)]
pub struct UiQuad2D {
    pub x0: f32,
    pub y0: f32,
    pub x1: f32,
    pub y1: f32,
    pub u0: f32,
    pub v0: f32,
    pub u1: f32,
    pub v1: f32,
    pub color: u32,
    pub tex_id: Option<usize>,
    /// Optional `(cx, cy, cw, ch)` scissor rect (`AUIObject::GetClipViewport`).
    pub clip_rect: Option<(i32, i32, i32, i32)>,
}

impl UiQuad2D {
    /// Returns this quad clipped against `self.clip_rect` with linearly adjusted UVs, or `None` if culled.
    #[inline]
    pub fn clipped(&self) -> Option<Self> {
        let Some((cx, cy, cw, ch)) = self.clip_rect else {
            return Some(self.clone());
        };
        if cw <= 0 || ch <= 0 {
            return None;
        }
        let rx0 = cx as f32;
        let ry0 = cy as f32;
        let rx1 = (cx + cw) as f32;
        let ry1 = (cy + ch) as f32;
        let nx0 = self.x0.max(rx0);
        let ny0 = self.y0.max(ry0);
        let nx1 = self.x1.min(rx1);
        let ny1 = self.y1.min(ry1);
        if nx0 >= nx1 || ny0 >= ny1 {
            return None;
        }
        let inv_w = 1.0 / (self.x1 - self.x0).max(1e-4);
        let inv_h = 1.0 / (self.y1 - self.y0).max(1e-4);
        let u_span = self.u1 - self.u0;
        let v_span = self.v1 - self.v0;
        Some(Self {
            x0: nx0,
            y0: ny0,
            x1: nx1,
            y1: ny1,
            u0: self.u0 + (nx0 - self.x0) * inv_w * u_span,
            v0: self.v0 + (ny0 - self.y0) * inv_h * v_span,
            u1: self.u0 + (nx1 - self.x0) * inv_w * u_span,
            v1: self.v0 + (ny1 - self.y0) * inv_h * v_span,
            color: self.color,
            tex_id: self.tex_id,
            clip_rect: None,
        })
    }
}

#[derive(Debug, Clone)]
pub struct UiText2D {
    pub x: i32,
    pub y: i32,
    pub size_px: u32,
    pub color: u32,
    pub text: String,
    pub shadow: bool,
    pub clip_rect: Option<(i32, i32, i32, i32)>,
}

/// Fallback `facedata.pck` texture candidates for a `CECFace` submesh whose raw texture failed
/// primary resolution. Real archive layout (verified entry-by-entry against the shipped pck):
///   facedata/{武侠男,法师女,影族男,影族女,妖兽男}/个性化/五官贴图库/{眼型,脸型,眉型,鼻型,嘴型,胡型,眼球}/*.dds
///   facedata/{...}/头发模型库/textures/*.dds   (+ 预定义/*.ini, 表情库/*.eface)
/// Only these five class folders exist; other professions share them via their 预定义 presets.
pub fn cec_face_fallback_candidates(
    cls: i32,
    gender: u8,
    hint: &str,
    raw_tex: &str,
    is_hair_skin: bool,
) -> Vec<String> {
    let is_female = match cls.clamp(0, 7) {
        3 => true,
        4 => false,
        _ => gender != 0,
    };
    let raw_low = raw_tex.to_ascii_lowercase();
    let class_dir: &str = match (cls.clamp(0, 7), is_female) {
        (2 | 5, true) => "影族女",
        (2 | 5, false) => "影族男",
        (4, _) => "妖兽男",
        (_, true) => "法师女",
        _ => "武侠男",
    };
    if is_hair_skin || hint.contains("头发") || raw_tex.contains('发') {
        let hair = if class_dir.starts_with("影族") {
            format!("facedata/{class_dir}/头发模型库/textures/影族头发a01.dds")
        } else {
            format!("facedata/{class_dir}/头发模型库/textures/头发a01.dds")
        };
        // Cross-folder fallbacks: 影族 folders only carry 影族头发*.dds, others only 头发*.dds.
        let other = if class_dir.starts_with("影族") {
            "facedata/法师女/头发模型库/textures/头发a01.dds".to_string()
        } else {
            "facedata/影族女/头发模型库/textures/影族头发a01.dds".to_string()
        };
        vec![hair, other]
    } else if raw_tex.contains("眼珠") || raw_low.contains("eyeball") || raw_tex.contains('瞳') {
        vec![
            format!("facedata/{class_dir}/个性化/五官贴图库/眼球/眼珠a01.dds"),
            "facedata/武侠男/个性化/五官贴图库/眼球/眼珠a01.dds".to_string(),
            "facedata/法师女/个性化/五官贴图库/眼球/眼珠a01.dds".to_string(),
        ]
    } else if raw_tex.contains('嘴') || raw_tex.contains('唇') || raw_low.contains("mouth") {
        // 嘴型 textures exist only in the 武侠男 / 法师女 folders.
        vec![
            format!("facedata/{class_dir}/个性化/五官贴图库/嘴型/嘴唇a01.dds"),
            "facedata/武侠男/个性化/五官贴图库/嘴型/嘴唇a01.dds".to_string(),
            "facedata/法师女/个性化/五官贴图库/嘴型/嘴唇a01.dds".to_string(),
        ]
    } else {
        let face = if class_dir.starts_with("影族") {
            format!("facedata/{class_dir}/个性化/五官贴图库/脸型/rw_头01.dds")
        } else if class_dir == "妖兽男" {
            // 妖兽男 has no 脸型 library; reuse the human face base texture.
            "facedata/武侠男/个性化/五官贴图库/脸型/头01.dds".to_string()
        } else {
            format!("facedata/{class_dir}/个性化/五官贴图库/脸型/头01.dds")
        };
        vec![
            face,
            "facedata/武侠男/个性化/五官贴图库/脸型/头01.dds".to_string(),
            "facedata/法师女/个性化/五官贴图库/脸型/头01.dds".to_string(),
            "facedata/影族女/个性化/五官贴图库/脸型/rw_头01.dds".to_string(),
        ]
    }
}

pub struct LoadedScene3D {
    pub map_name: String,
    pub world_width: f32,
    pub world_length: f32,
    pub textures: Vec<SurfaceImage>,
    pub tex_lookup: HashMap<String, usize>,
    pub font_atlas: TtfFontAtlas,
    pub skill_icons: Option<IconAtlas>,
    pub item_icons: Option<IconAtlas>,
    pub action_icons: Option<IconAtlas>,
    pub state_icons: Option<IconAtlas>,
    pub shadow_blob_tex_id: usize,
    pub particle_glow_tex_id: usize,
    pub cloud_sprite_tex_id: usize,
    pub clouds_enabled: bool,
    pub gfx_manager: crate::a3d_gfx::A3dGfxManager,
    pub custom_presets: HashMap<(i32, u8, u8), pw_data::CharacterCustomizeIni>,
    /// Loaded `.cur`/`.ani` cursors keyed by `"normal"`, `"hand"`, `"attack"`, `"talk"`: `(hx, hy, jiffies, frame_tex_ids)`.
    pub cursors: HashMap<String, (i32, i32, u32, Vec<usize>)>,
    pub active_cursor: String,
    pub show_software_cursor: bool,
    pub ui_anim_ms: u64,
    pub day_phase_frame: u32,
    pub minimap_tex_id: Option<usize>,
    pub minimap_bounds: (f32, f32, f32, f32),
    pub minimap_circle_tex_id: Option<usize>,
    pub portrait_circle_tex_id: Option<usize>,
    pub portrait_cache_key: Option<(i32, u8, u8)>,
    pub world_map_tex_id: Option<usize>,
    pub regional_map_cache: HashMap<(usize, usize), Option<usize>>,
    pub box_areas: Vec<SceneBoxArea>,
    pub default_box_area: Option<SceneBoxArea>,
    pub active_box_id: Option<u32>,
    pub sky_dome: A3dSkyDome,
    pub sky_cap_tex: usize,
    pub sky_front_tex: usize,
    pub sky_back_tex: usize,
    pub fog_start: f32,
    pub fog_end: f32,
    pub fog_color: u32,
    pub light_dir: Vec3,
    pub terrain_blocks: Vec<TerrainBlockDraw>,
    pub terrain_detail_tex: Vec<Option<SurfaceImage>>,
    pub terrain_sub_splats: Vec<TerrainSubSplat>,
    pub bmd_models: Vec<Vec<GpuMeshBatch>>,
    pub ornaments: Vec<OrnamentDrawInstance>,
    pub water_batches: Vec<GpuMeshBatch>,
    pub character_cache: HashMap<(i32, u8), Vec<GpuMeshBatch>>,
    pub player_rigs: HashMap<(i32, u8), Option<LoadedSkeletonRig>>,
    pub player_skin_templates: HashMap<(i32, u8, u8), Vec<CachedSkinSubMesh>>,
    pub player_face_templates: HashMap<(i32, u8, u8), CachedFaceTemplate>,
    pub npc_portrait_cache: HashMap<String, Option<usize>>,
    pub weapon_batches: HashMap<i32, Vec<GpuMeshBatch>>,
    pub ecm_actors: HashMap<String, Option<CachedEcmActor>>,
    /// Procedural humanoid fallbacks used when `models.pck` (888MB, unavailable in the
    /// sandbox asset set) is missing the real `.bon/.smd/.ski` player bodies: one batch
    /// per `(cls, gender, preset)`, tinted by `CECCustomizeIni.color_body` + class armor.
    pub procedural_avatars: HashMap<(i32, u8, u8), GpuMeshBatch>,
    /// Same idea for NPC/monster `.ecm` actors that live in the unavailable `models.pck`.
    pub procedural_npcs: HashMap<String, GpuMeshBatch>,
}

impl LoadedScene3D {
    pub fn build(map: &MapInstanceBundle, vfs: &VirtualFileSystem) -> Self {
        Self::build_with_night(map, vfs, 0.0)
    }

    /// Builds the scene with a day→night lightmap blend (`night_weight` 0.0 = full day `.t2lm`,
    /// 1.0 = full night `.t2lm1` baked lightmaps on terrain).
    pub fn build_with_night(map: &MapInstanceBundle, vfs: &VirtualFileSystem, night_weight: f32) -> Self {
        let mut textures = Vec::new();
        let mut tex_lookup = HashMap::new();

        // Slot 0 = fallback solid white texture
        textures.push(SurfaceImage::solid(4, 4, 0xFFFF_FFFF));

        let load_vfs_tex = |vfs: &VirtualFileSystem,
                            path: &str,
                            colorkey_bmp: bool,
                            textures: &mut Vec<SurfaceImage>,
                            lookup: &mut HashMap<String, usize>|
         -> Option<usize> {
            let norm = path.trim().replace('\\', "/").to_ascii_lowercase();
            if norm.is_empty() {
                return None;
            }
            if let Some(&id) = lookup.get(&norm) {
                return Some(id);
            }
            let bytes = vfs.read_file(path).ok()?;
            let mut img = decode_surface_auto(&bytes).ok()?;
            if colorkey_bmp && norm.ends_with(".bmp") {
                img.apply_magenta_colorkey();
            }
            let id = textures.len();
            textures.push(img);
            lookup.insert(norm, id);
            Some(id)
        };

        // 1. Environment & Sky (`CECScnBoxArea` `def_flag` + `A3DSkySphere`)
        let def_box = map.scene.default_box_area.as_ref();
        let fog_color = def_box
            .map(|b| 0xFF00_0000 | (b.fog_color & 0x00FF_FFFF))
            .unwrap_or(0xFF5A_8898);
        let fog_start = def_box.map(|b| b.fog_start.max(180.0)).unwrap_or(320.0);
        let fog_end = def_box.map(|b| b.fog_end.max(fog_start + 200.0)).unwrap_or(950.0);
        let light_dir = def_box
            .map(|b| b.light_dir.normalized())
            .unwrap_or_else(|| Vec3::new(-0.305, -0.656, 0.691).normalized());

        let resolve_sky = |rel: &str,
                           fallback_argb: u32,
                           textures: &mut Vec<SurfaceImage>,
                           lookup: &mut HashMap<String, usize>|
         -> usize {
            if !rel.is_empty() {
                for cand in [format!("textures/sky/{rel}"), format!("sky/{rel}"), rel.to_string()] {
                    if let Some(id) = load_vfs_tex(vfs, &cand, false, textures, lookup) {
                        return id;
                    }
                }
            }
            let id = textures.len();
            textures.push(SurfaceImage::solid(8, 8, fallback_argb));
            id
        };

        let sky_cap_tex = resolve_sky(
            def_box.map(|b| b.sky_tex0.as_str()).unwrap_or("clear\\Roof.bmp"),
            0xFF3E_78B2,
            &mut textures,
            &mut tex_lookup,
        );
        let sky_front_tex = resolve_sky(
            def_box.map(|b| b.sky_tex1.as_str()).unwrap_or("clear\\01.bmp"),
            0xFF78_A8C8,
            &mut textures,
            &mut tex_lookup,
        );
        let sky_back_tex = resolve_sky(
            def_box.map(|b| b.sky_tex2.as_str()).unwrap_or("clear\\02.bmp"),
            0xFF78_A8C8,
            &mut textures,
            &mut tex_lookup,
        );
        let sky_dome = A3dSkyDome::build(A3dSkySphereParams::DEFAULT_RADIUS);

        // 2. Terrain (`A3DTerrain2` 16-area tri-planar splat + `.t2lm` DXT1 `MODULATE2X` lightmap compositor)
        let (terrain_blocks, terrain_detail_tex, terrain_sub_splats) =
            build_terrain_blocks(map, vfs, &mut textures, &mut tex_lookup, night_weight);

        // 3. Ornaments (`CECOrnament` + `A3DLitModel` `.bmd`)
        let mut bmd_path_to_idx: HashMap<String, usize> = HashMap::new();
        let mut bmd_models: Vec<Vec<GpuMeshBatch>> = Vec::new();
        let mut bmd_local_aabbs: Vec<(Vec3, Aabb)> = Vec::new();
        let mut ornaments: Vec<OrnamentDrawInstance> = Vec::new();

        for orn in &map.scene.ornaments {
            let rel_norm = orn.bmd_rel_path.replace('\\', "/");
            let vfs_bmd = if rel_norm.to_ascii_lowercase().starts_with("litmodels/")
                || rel_norm.to_ascii_lowercase().starts_with("building/")
            {
                rel_norm.clone()
            } else {
                format!("litmodels/{}/{}", map.map_name, rel_norm)
            };
            let lookup_key = vfs_bmd.to_ascii_lowercase();

            let model_idx = if let Some(&existing) = bmd_path_to_idx.get(&lookup_key) {
                existing
            } else {
                let bytes_opt = vfs
                    .read_file(&vfs_bmd)
                    .ok()
                    .or_else(|| vfs.read_file(&format!("litmodels/{rel_norm}")).ok());
                let Some(bmd_bytes) = bytes_opt else {
                    continue;
                };
                let Ok(parsed) = A3dLitModel::parse_bmd(&bmd_bytes, &vfs_bmd) else {
                    continue;
                };
                if parsed.collide_only || parsed.meshes.is_empty() {
                    continue;
                }
                let bmd_dir = vfs_bmd
                    .rsplit_once('/')
                    .map(|(d, _)| d)
                    .unwrap_or("");

                let mut batches = Vec::with_capacity(parsed.meshes.len());
                for m in parsed.meshes {
                    if m.verts.is_empty() || m.indices.is_empty() {
                        continue;
                    }
                    let tex_cache_key = format!("bmdtex:{bmd_dir}/{}", m.raw_texture_name.to_ascii_lowercase());
                    let (tex_id, has_alpha_tex, tex_missing) = if let Some(&tid) = tex_lookup.get(&tex_cache_key) {
                        let ha = surface_has_cutout_alpha(&textures[tid]);
                        (tid, ha, false)
                    } else if let Some(tb) = read_model_texture_bytes(vfs, bmd_dir, &m.raw_texture_name) {
                        if let Ok(mut simg) = decode_surface_auto(&tb) {
                            if m.raw_texture_name.to_ascii_lowercase().ends_with(".bmp") {
                                simg.apply_magenta_colorkey();
                            }
                            let ha = surface_has_cutout_alpha(&simg);
                            let tid = textures.len();
                            textures.push(simg);
                            tex_lookup.insert(tex_cache_key, tid);
                            (tid, ha, false)
                        } else {
                            (0, false, true)
                        }
                    } else {
                        (0, false, true)
                    };

                    let mut verts = m.verts;
                    if tex_missing {
                        // `textures.pck` unavailable -> tint the white fallback by a stable
                        // per-model color so buildings read as distinct structures, not blank boxes.
                        let tint = bmd_placeholder_tint(&lookup_key);
                        for v in &mut verts {
                            v.diffuse = mul_color(v.diffuse, tint);
                        }
                    }

                    batches.push(GpuMeshBatch {
                        tex_id,
                        two_sided: m.two_sided || has_alpha_tex,
                        alpha_test: has_alpha_tex,
                        alpha_blend: false,
                        verts,
                        indices: m.indices,
                    });
                }
                let idx = bmd_models.len();
                bmd_models.push(batches);
                bmd_local_aabbs.push((parsed.scale, parsed.local_aabb));
                bmd_path_to_idx.insert(lookup_key, idx);
                idx
            };

            let (bmd_scale, local_aabb) = bmd_local_aabbs[model_idx];
            let world_mat = ornament_world_matrix(orn.dir, orn.up, orn.pos, bmd_scale);
            let world_aabb = local_aabb.transform(world_mat);
            ornaments.push(OrnamentDrawInstance {
                model_idx,
                world_mat,
                world_aabb,
            });
        }

        // 4. Water (`A3DWaterArea` translucent animated ocean/lake quads from `bsdata/<map>.dat`)
        let water_tex_id = build_water_surface_texture(&mut textures);
        let mut water_batches = Vec::new();
        for wa in &map.scene.water_areas {
            let half_w = (wa.width_grids as f32) * wa.grid_size * 0.5;
            let half_h = (wa.height_grids as f32) * wa.grid_size * 0.5;
            let x_origin = wa.center.x - half_w;
            let z_top = wa.center.z + half_h;
            let mut verts = Vec::new();
            let mut indices = Vec::new();
            let water_vert = |wx: f32, wz: f32, y: f32| -> (A3dLitVertex, f32) {
                let ty = map.sample_world_height(wx, wz);
                let depth = y - ty;
                let t = ((depth - 0.03) / 2.25).clamp(0.0, 1.0);
                let smooth = t * t * (3.0 - 2.0 * t);
                let alpha = (smooth * 194.0) as u32;
                let deep_t = ((depth - 0.5) / 5.5).clamp(0.0, 1.0);
                let r = (74.0 + (34.0 - 74.0) * deep_t) as u32;
                let g = (158.0 + (104.0 - 158.0) * deep_t) as u32;
                let b = (182.0 + (136.0 - 182.0) * deep_t) as u32;
                (
                    A3dLitVertex {
                        x: wx,
                        y,
                        z: wz,
                        diffuse: (alpha << 24) | (r << 16) | (g << 8) | b,
                        u: wx * 0.04,
                        v: wz * 0.04,
                    },
                    depth,
                )
            };
            for gz in 0..wa.height_grids {
                for gx in 0..wa.width_grids {
                    let vis = wa
                        .visible_cells
                        .get(gz * wa.width_grids + gx)
                        .copied()
                        .unwrap_or(1);
                    if vis == 0 || verts.len() + 68 > 65000 {
                        continue;
                    }
                    let x0 = x_origin + (gx as f32) * wa.grid_size;
                    let x1 = x0 + wa.grid_size;
                    let z0 = z_top - (gz as f32) * wa.grid_size;
                    let z1 = z0 - wa.grid_size;
                    let y = wa.water_height;
                    let d00 = y - map.sample_world_height(x0, z0);
                    let d10 = y - map.sample_world_height(x1, z0);
                    let d01 = y - map.sample_world_height(x0, z1);
                    let d11 = y - map.sample_world_height(x1, z1);
                    let max_d = d00.max(d10).max(d01).max(d11);
                    let min_d = d00.min(d10).min(d01).min(d11);
                    if max_d <= -0.35 {
                        continue;
                    }
                    // Subdivide shallow shoreline cells (`4x4` = `8m`) for smooth beach/riverbank fade!
                    let subdiv = if min_d < 3.4 { 4usize } else { 1usize };
                    let step = wa.grid_size / (subdiv as f32);
                    for sz in 0..subdiv {
                        for sx in 0..subdiv {
                            if verts.len() + 4 > 65000 {
                                break;
                            }
                            let sx0 = x0 + (sx as f32) * step;
                            let sx1 = sx0 + step;
                            let sz0 = z0 - (sz as f32) * step;
                            let sz1 = sz0 - step;
                            let (v00, dp0) = water_vert(sx0, sz0, y);
                            let (v10, dp1) = water_vert(sx1, sz0, y);
                            let (v01, dp2) = water_vert(sx0, sz1, y);
                            let (v11, dp3) = water_vert(sx1, sz1, y);
                            if dp0.max(dp1).max(dp2).max(dp3) <= 0.02 {
                                continue;
                            }
                            let base = verts.len() as u16;
                            verts.extend_from_slice(&[v00, v10, v01, v11]);
                            indices.extend_from_slice(&[
                                base,
                                base + 1,
                                base + 2,
                                base + 1,
                                base + 3,
                                base + 2,
                            ]);
                        }
                    }
                }
            }
            if !indices.is_empty() {
                water_batches.push(GpuMeshBatch {
                    tex_id: water_tex_id,
                    two_sided: true,
                    alpha_test: false,
                    alpha_blend: true,
                    verts,
                    indices,
                });
            }
        }
        // Also add outer horizon ocean ring ONLY on dedicated island maps (`Maps\Login`)
        if map.map_name.eq_ignore_ascii_case("login") {
            if let Some(wa0) = map.scene.water_areas.first() {
                if wa0.water_height > 200.0 {
                    let y = wa0.water_height - 0.15;
                    let r = 900.0f32;
                    let c = 0xB024_6682u32;
                    let verts = vec![
                        A3dLitVertex { x: -r, y, z: r, diffuse: c, u: -36.0, v: 36.0 },
                        A3dLitVertex { x: r, y, z: r, diffuse: c, u: 36.0, v: 36.0 },
                        A3dLitVertex { x: -r, y, z: -r, diffuse: c, u: -36.0, v: -36.0 },
                        A3dLitVertex { x: r, y, z: -r, diffuse: c, u: 36.0, v: -36.0 },
                    ];
                    water_batches.push(GpuMeshBatch {
                        tex_id: water_tex_id,
                        two_sided: true,
                        alpha_test: false,
                        alpha_blend: true,
                        verts,
                        indices: vec![0, 1, 2, 1, 3, 2],
                    });
                }
            }
        }

        // 5. SpeedTree Foliage (`CELForest` `map.scene.tree_types` + `map.scene.trees` from `trees.pck`)
        if !map.scene.tree_types.is_empty() && !map.scene.trees.is_empty() {
            let mut tree_model_indices: Vec<Option<usize>> = Vec::with_capacity(map.scene.tree_types.len());
            for tt in &map.scene.tree_types {
                let leaf_clean = tt.dds_path.replace('\\', "/");
                let leaf_tid = load_vfs_tex(vfs, &leaf_clean, true, &mut textures, &mut tex_lookup);
                let bark_tid = extract_spt_bark_texture(vfs, &tt.spt_path)
                    .and_then(|tb| decode_surface_auto(&tb).ok())
                    .map(|img| {
                        let id = textures.len();
                        textures.push(img);
                        id
                    })
                    .unwrap_or(0);
                if let Some(ltid) = leaf_tid {
                    let is_bamboo = leaf_clean.to_ascii_lowercase().contains("bamboo");
                    let height = if is_bamboo { 11.5 } else { 9.5 };
                    let canopy_r = if is_bamboo { 2.6 } else { 4.2 };
                    let ((tv, ti), (cv, ci)) = build_speedtree_batches(height, canopy_r, is_bamboo);
                    let batches = vec![
                        GpuMeshBatch {
                            tex_id: bark_tid,
                            two_sided: true,
                            alpha_test: false,
                            alpha_blend: false,
                            verts: tv,
                            indices: ti,
                        },
                        GpuMeshBatch {
                            tex_id: ltid,
                            two_sided: true,
                            alpha_test: true,
                            alpha_blend: false,
                            verts: cv,
                            indices: ci,
                        },
                    ];
                    let midx = bmd_models.len();
                    bmd_models.push(batches);
                    tree_model_indices.push(Some(midx));
                } else {
                    tree_model_indices.push(None);
                }
            }

            for tp in &map.scene.trees {
                if let Some(&Some(midx)) = tree_model_indices.get(tp.tree_type) {
                    let wy = if tp.pos.y.abs() > 0.01 {
                        tp.pos.y
                    } else {
                        map.sample_world_height(tp.pos.x, tp.pos.z)
                    };
                    let wpos = Vec3::new(tp.pos.x, wy, tp.pos.z);
                    let world_mat = Mat4::a3d_transform_matrix(
                        Vec3::UNIT_Z,
                        Vec3::UNIT_Y,
                        wpos,
                        Vec3::new(1.0, 1.0, 1.0),
                    );
                    let world_aabb = Aabb {
                        mins: Vec3::new(wpos.x - 4.5, wpos.y, wpos.z - 4.5),
                        maxs: Vec3::new(wpos.x + 4.5, wpos.y + 12.0, wpos.z + 4.5),
                    };
                    ornaments.push(OrnamentDrawInstance {
                        model_idx: midx,
                        world_mat,
                        world_aabb,
                    });
                }
            }
        }

        // 5b. 3D Grass BitsMap Instancing (`CELGrassLand` + `grasses.pck` `.mox` `155/155` `bad=0`)
        if !map.scene.grass_types.is_empty() && !map.scene.grass_instances.is_empty() {
            let mut grass_model_indices: Vec<Option<(usize, Aabb)>> =
                Vec::with_capacity(map.scene.grass_types.len());
            for gt in &map.scene.grass_types {
                let mox_clean = gt.mox_path.replace('\\', "/");
                let cands = [mox_clean.clone(), format!("grasses/{mox_clean}")];
                let parsed_opt = cands.iter().find_map(|p| {
                    let b = vfs.read_file(p).ok()?;
                    A3dMoxMesh::parse_mox(&b).ok().map(|m| (p.clone(), m))
                });
                if let Some((used_path, mox)) = parsed_opt {
                    let mox_dir = used_path.rsplit_once('/').map(|(d, _)| d).unwrap_or("grasses");
                    let mut batches = Vec::new();
                    let mut local_aabb = Aabb::empty();
                    for sm in mox.sub_meshes {
                        let tex_key = format!("grasstex:{mox_dir}/{}", sm.texture_file.to_ascii_lowercase());
                        let tid = if let Some(&id) = tex_lookup.get(&tex_key) {
                            id
                        } else if let Some(tb) =
                            read_model_texture_bytes(vfs, mox_dir, &sm.texture_file)
                        {
                            if let Ok(mut simg) = decode_surface_auto(&tb) {
                                if sm.texture_file.to_ascii_lowercase().ends_with(".bmp") {
                                    simg.apply_magenta_colorkey();
                                }
                                let id = textures.len();
                                textures.push(simg);
                                tex_lookup.insert(tex_key, id);
                                id
                            } else {
                                0
                            }
                        } else {
                            0
                        };
                        let mut verts = Vec::with_capacity(sm.verts.len());
                        for (p, n, u, v) in sm.verts {
                            local_aabb.expand_point(p);
                            let ndotl = (n.normalized().dot(light_dir.scale(-1.0))).max(0.25);
                            let shade = (155.0 + ndotl * 98.0).clamp(0.0, 255.0) as u32;
                            let diff = 0xFF00_0000 | (shade << 16) | ((shade.min(255)) << 8) | (shade * 92 / 100);
                            verts.push(A3dLitVertex {
                                x: p.x,
                                y: p.y,
                                z: p.z,
                                diffuse: diff,
                                u,
                                v,
                            });
                        }
                        batches.push(GpuMeshBatch {
                            tex_id: tid,
                            two_sided: true,
                            alpha_test: true,
                            alpha_blend: false,
                            verts,
                            indices: sm.indices,
                        });
                    }
                    if !batches.is_empty() {
                        let midx = bmd_models.len();
                        bmd_models.push(batches);
                        grass_model_indices.push(Some((midx, local_aabb)));
                    } else {
                        grass_model_indices.push(None);
                    }
                } else {
                    grass_model_indices.push(None);
                }
            }

            for gi in &map.scene.grass_instances {
                if let Some(&Some((midx, local_aabb))) = grass_model_indices.get(gi.grass_type) {
                    let wy = map.sample_world_height(gi.wx, gi.wz);
                    let wpos = Vec3::new(gi.wx, wy, gi.wz);
                    let dir = Vec3::new(gi.yaw.sin(), 0.0, gi.yaw.cos());
                    let sc = Vec3::new(gi.scale, gi.scale, gi.scale);
                    let wm = ornament_world_matrix(dir, Vec3::UNIT_Y, wpos, sc);
                    let wa = local_aabb.transform(wm);
                    ornaments.push(OrnamentDrawInstance {
                        model_idx: midx,
                        world_mat: wm,
                        world_aabb: wa,
                    });
                }
            }
        }

        // 6. Static World `ECModels` (`map.scene.ecmodels` from `models.pck`)
        for secm in &map.scene.ecmodels {
            let ecm_norm = secm.ecm_path.replace('\\', "/");
            let cands = [ecm_norm.clone(), format!("models/{ecm_norm}")];
            if let Some((desc, mut rig, skins)) = cands
                .iter()
                .find_map(|p| load_ecm_rig_and_skins(vfs, p))
            {
                let (tm_blend, _) = rig.evaluate_action_pose(vfs, ActorActionKind::Stand, 0.0);
                let mut batches = Vec::new();
                let mut local_aabb = Aabb::empty();
                for sk in skins {
                    let bmap = rig.build_bone_map(&sk);
                    for sm in sk.meshes {
                        let skinned = skin_submesh_vertices(&sm, &bmap, &tm_blend, light_dir.scale(-1.0));
                        for v in &skinned {
                            local_aabb.expand_point(Vec3::new(v.x, v.y, v.z));
                        }
                        let tid = read_model_texture_bytes(vfs, &sm.texture_vfs_hint, &sm.raw_texture)
                            .and_then(|tb| decode_surface_auto(&tb).ok())
                            .map(|img| {
                                let id = textures.len();
                                textures.push(img);
                                id
                            })
                            .unwrap_or(0);
                        let ha = tid != 0 && surface_has_cutout_alpha(&textures[tid]);
                        batches.push(GpuMeshBatch {
                            tex_id: tid,
                            two_sided: true,
                            alpha_test: ha,
                            alpha_blend: false,
                            verts: skinned,
                            indices: sm.indices,
                        });
                    }
                }
                if !batches.is_empty() {
                    let midx = bmd_models.len();
                    bmd_models.push(batches);
                    let sc = Vec3::new(desc.scale, desc.scale, desc.scale);
                    let wm = ornament_world_matrix(secm.dir, secm.up, secm.pos, sc);
                    let wa = local_aabb.transform(wm);
                    ornaments.push(OrnamentDrawInstance {
                        model_idx: midx,
                        world_mat: wm,
                        world_aabb: wa,
                    });
                }
            }
        }

        // 7. TrueType Font Atlas (`fonts/fzl2jw.ttf` / `fonts/fzxh1jw.ttf`), `iconlist_*`, & Minimap
        let ttf_bytes = ["fonts/fzl2jw.ttf", "fonts/fzxh1jw.ttf"]
            .iter()
            .find_map(|p| vfs.read_file(p).ok());
        let font_atlas = TtfFontAtlas::new(ttf_bytes, &mut textures);
        let skill_icons = IconAtlas::load_from_vfs(vfs, "iconlist_skill", &mut textures);
        let item_icons = IconAtlas::load_from_vfs(vfs, "iconlist_ivtrm", &mut textures);
        let action_icons = IconAtlas::load_from_vfs(vfs, "iconlist_action", &mut textures);
        let state_icons = IconAtlas::load_from_vfs(vfs, "iconlist_state", &mut textures);
        // Smooth radial contact shadow texture (`CECShadowRender` `64x64` soft dark Gaussian disc)
        let shadow_blob_tex_id = {
            let sz = 64u32;
            let mut spx = vec![0u32; (sz * sz) as usize];
            let c = (sz as f32) * 0.5;
            for y in 0..sz {
                for x in 0..sz {
                    let dx = ((x as f32 + 0.5) - c) / c;
                    let dy = ((y as f32 + 0.5) - c) / c;
                    let r2 = dx * dx + dy * dy;
                    let a = if r2 >= 1.0 {
                        0u32
                    } else {
                        (((1.0 - r2).powi(2) * 124.0).round() as u32).min(124)
                    };
                    spx[(y * sz + x) as usize] = a << 24;
                }
            }
            let id = textures.len();
            textures.push(SurfaceImage::from_pixels_with_mips(sz, sz, spx));
            id
        };
        // Luminous radial glow sprite (`64x64`) for `A3DGFXEx` `.gfx` particles, skill bursts, & weapon sockets
        let particle_glow_tex_id = {
            let sz = 64u32;
            let mut gpx = vec![0u32; (sz * sz) as usize];
            let c = (sz as f32) * 0.5;
            for y in 0..sz {
                for x in 0..sz {
                    let dx = ((x as f32 + 0.5) - c) / c;
                    let dy = ((y as f32 + 0.5) - c) / c;
                    let r = (dx * dx + dy * dy).sqrt();
                    if r < 1.0 {
                        let fall = (1.0 - r).powf(2.2);
                        let core = (1.0 - (r * 2.1).min(1.0)).powi(2);
                        let a = (fall * 255.0).round().clamp(0.0, 255.0) as u32;
                        let lum = (210.0 + core * 45.0).round().clamp(0.0, 255.0) as u32;
                        gpx[(y * sz + x) as usize] = (a << 24) | (lum << 16) | (lum << 8) | lum;
                    }
                }
            }
            let id = textures.len();
            textures.push(SurfaceImage::from_pixels_with_mips(sz, sz, gpx));
            id
        };
        // Multi-lobe procedural cumulus cloud puff (`128x64`, `CELCloudCreator` / `CloudSprite`)
        let cloud_sprite_tex_id = {
            let cw = 128u32;
            let ch = 64u32;
            let mut cpx = vec![0u32; (cw * ch) as usize];
            let lobes: [(f32, f32, f32, f32, f32); 5] = [
                (0.50, 0.46, 0.28, 0.34, 1.00),
                (0.32, 0.54, 0.24, 0.28, 0.88),
                (0.69, 0.53, 0.24, 0.29, 0.90),
                (0.20, 0.62, 0.17, 0.20, 0.68),
                (0.81, 0.61, 0.17, 0.21, 0.70),
            ];
            for y in 0..ch {
                let ny = (y as f32 + 0.5) / (ch as f32);
                for x in 0..cw {
                    let nx = (x as f32 + 0.5) / (cw as f32);
                    let mut dens = 0.0f32;
                    for &(lx, ly, rx, ry, w) in &lobes {
                        let dx = (nx - lx) / rx;
                        let dy = (ny - ly) / ry;
                        let d2 = dx * dx + dy * dy;
                        if d2 < 1.0 {
                            dens = dens.max((1.0 - d2).powi(2) * w);
                        }
                    }
                    if dens > 0.01 {
                        // Sunlit warm ivory top (`ny < 0.45`) transitioning to cool silver-blue cloud base
                        let sun_t = (1.0 - ny * 1.15).clamp(0.0, 1.0);
                        let r = (212.0 + sun_t * 42.0).clamp(0.0, 255.0) as u32;
                        let g = (222.0 + sun_t * 31.0).clamp(0.0, 255.0) as u32;
                        let b = (238.0 + sun_t * 16.0).clamp(0.0, 255.0) as u32;
                        let a = (dens * 168.0).round().clamp(0.0, 185.0) as u32;
                        cpx[(y * cw + x) as usize] = (a << 24) | (r << 16) | (g << 8) | b;
                    }
                }
            }
            let id = textures.len();
            textures.push(SurfaceImage::from_pixels_with_mips(cw, ch, cpx));
            id
        };
        // Pre-populate real `userdata/character/character{cls}{gender}.ini` presets for `[Body]` & `CECFace` morphing!
        let mut custom_presets = HashMap::new();
        for cls in 0..=7i32 {
            for gender in 0..=1u8 {
                if (cls == 3 && gender == 0) || (cls == 4 && gender == 1) {
                    continue;
                }
                let ini_rel = format!("userdata/character/character{cls}{gender}.ini");
                if let Ok(raw) = vfs.read_file(&ini_rel) {
                    let parsed = pw_data::CharacterCustomizeIni::parse_ini_bytes(&raw);
                    for preset in 0..3u8 {
                        custom_presets.insert((cls, gender, preset), parsed.clone());
                    }
                }
            }
        }
        let (minimap_tex_id, minimap_bounds) = load_minimap_composite_at(
            vfs,
            &map.map_name,
            map.load_center.x,
            map.load_center.z,
            &mut textures,
        )
        .map(|(tid, b)| (Some(tid), b))
        .unwrap_or((None, (-512.0, 512.0, -512.0, 512.0)));
        let world_map_tex_id = load_world_map_texture(vfs, &mut textures);

        Self {
            map_name: map.map_name.clone(),
            world_width: map
                .trn2_full
                .as_ref()
                .map(|t| t.terrain_width)
                .unwrap_or(map.height_mesh.world_width)
                .max(1024.0),
            world_length: map
                .trn2_full
                .as_ref()
                .map(|t| t.terrain_length)
                .unwrap_or(map.height_mesh.world_length)
                .max(1024.0),
            textures,
            tex_lookup,
            font_atlas,
            skill_icons,
            item_icons,
            action_icons,
            state_icons,
            shadow_blob_tex_id,
            particle_glow_tex_id,
            cloud_sprite_tex_id,
            clouds_enabled: true,
            gfx_manager: crate::a3d_gfx::A3dGfxManager::new(),
            custom_presets,
            cursors: HashMap::new(),
            active_cursor: "normal".to_string(),
            show_software_cursor: false,
            ui_anim_ms: 0,
            day_phase_frame: 0,
            minimap_tex_id,
            minimap_bounds,
            minimap_circle_tex_id: None,
            portrait_circle_tex_id: None,
            portrait_cache_key: None,
            world_map_tex_id,
            regional_map_cache: HashMap::new(),
            box_areas: map.scene.box_areas.clone(),
            default_box_area: map.scene.default_box_area.clone(),
            active_box_id: def_box.map(|b| b.id),
            sky_dome,
            sky_cap_tex,
            sky_front_tex,
            sky_back_tex,
            fog_start,
            fog_end,
            fog_color,
            light_dir,
            terrain_blocks,
            terrain_detail_tex,
            terrain_sub_splats,
            bmd_models,
            ornaments,
            water_batches,
            character_cache: HashMap::new(),
            player_rigs: HashMap::new(),
            player_skin_templates: HashMap::new(),
            player_face_templates: HashMap::new(),
            npc_portrait_cache: HashMap::new(),
            weapon_batches: HashMap::new(),
            ecm_actors: HashMap::new(),
            procedural_avatars: HashMap::new(),
            procedural_npcs: HashMap::new(),
        }
    }

    /// Loads real Win32 `.ani`/`.cur` cursors (`normal.ani`, `hand.cur`, `attack.cur`, `talk.cur`, `pick.cur`)
    /// from `<element_root>/cursors/` into `self.textures` for 1:1 cursor rendering.
    pub fn load_cursors_from_dir(&mut self, element_root: &std::path::Path) {
        let cdir = element_root.join("cursors");
        for (key, fname) in [
            ("normal", "normal.ani"),
            ("hand", "hand.cur"),
            ("attack", "attack.cur"),
            ("talk", "talk.cur"),
            ("pick", "pick.cur"),
        ] {
            if self.cursors.contains_key(key) {
                continue;
            }
            let p = cdir.join(fname);
            if let Ok(bytes) = std::fs::read(&p) {
                if let Ok(cur) = decode_cur_or_ani(&bytes) {
                    let mut ids = Vec::with_capacity(cur.frames.len());
                    for img in cur.frames {
                        let id = self.textures.len();
                        self.textures.push(img);
                        ids.push(id);
                    }
                    self.cursors
                        .insert(key.to_string(), (cur.hotspot_x, cur.hotspot_y, cur.jiffies_per_frame, ids));
                }
            }
        }
    }

    /// Updates `sky_*_tex`, `fog_start`, `fog_end`, `fog_color`, and `light_dir` dynamically from
    /// whichever `SceneBoxArea` OBB contains `eye` (`CECScene::UpdateBoxAreas`).
    pub fn sync_environment_for_camera(&mut self, vfs: &VirtualFileSystem, eye: Vec3) {
        let mut best: Option<(&SceneBoxArea, f32)> = None;
        for ba in &self.box_areas {
            if !ba.is_default && ba.contains_point(eye) {
                let vol = ba.ext.x.abs() * ba.ext.y.abs() * ba.ext.z.abs();
                if best.map(|(_, bv)| vol < bv).unwrap_or(true) {
                    best = Some((ba, vol));
                }
            }
        }
        let chosen = best.map(|(b, _)| b).or(self.default_box_area.as_ref());
        let Some(ba) = chosen.cloned() else {
            return;
        };
        if self.active_box_id == Some(ba.id) {
            return;
        }
        self.active_box_id = Some(ba.id);
        self.fog_color = 0xFF00_0000 | (ba.fog_color & 0x00FF_FFFF);
        self.fog_start = ba.fog_start.max(95.0);
        self.fog_end = ba.fog_end.max(self.fog_start + 180.0);
        if ba.light_dir.length_sq() > 0.05 {
            self.light_dir = ba.light_dir.normalized();
        }
        if let Some(id) = self.load_sky_tex(vfs, &ba.sky_tex0) {
            self.sky_cap_tex = id;
        }
        if let Some(id) = self.load_sky_tex(vfs, &ba.sky_tex1) {
            self.sky_front_tex = id;
        }
        if let Some(id) = self.load_sky_tex(vfs, &ba.sky_tex2) {
            self.sky_back_tex = id;
        }
    }

    fn load_sky_tex(&mut self, vfs: &VirtualFileSystem, rel: &str) -> Option<usize> {
        let clean = rel.trim();
        if clean.is_empty() {
            return None;
        }
        for cand in [format!("textures/sky/{clean}"), format!("sky/{clean}"), clean.to_string()] {
            let norm = cand.replace('\\', "/").to_ascii_lowercase();
            if let Some(&id) = self.tex_lookup.get(&norm) {
                return Some(id);
            }
            if let Ok(bytes) = vfs.read_file(&cand) {
                if let Ok(img) = decode_surface_auto(&bytes) {
                    let id = self.textures.len();
                    self.textures.push(img);
                    self.tex_lookup.insert(norm, id);
                    return Some(id);
                }
            }
        }
        None
    }

    fn resolve_skin_submesh_tex(
        &mut self,
        vfs: &VirtualFileSystem,
        hint: &str,
        raw_tex: &str,
        force_opaque_gloss: bool,
    ) -> (usize, bool) {
        let hint_low = hint.to_ascii_lowercase();
        let raw_low = raw_tex.to_ascii_lowercase();
        let is_cutout = !force_opaque_gloss
            || hint_low.contains("face")
            || raw_low.contains("hair")
            || raw_tex.contains('发')
            || raw_tex.contains('胡')
            || raw_tex.contains('睫');
        let cache_k = format!("skitex:{hint_low}/{raw_low}:{is_cutout}");
        if let Some(&id) = self.tex_lookup.get(&cache_k) {
            let ha = is_cutout && surface_has_cutout_alpha(&self.textures[id]);
            return (id, ha);
        }
        if let Some(tb) = read_model_texture_bytes(vfs, hint, raw_tex) {
            if let Ok(mut simg) = decode_surface_auto(&tb) {
                let ha = if is_cutout {
                    surface_has_cutout_alpha(&simg)
                } else {
                    for px in &mut simg.pixels {
                        *px |= 0xFF00_0000;
                    }
                    false
                };
                let id = self.textures.len();
                self.textures.push(simg);
                self.tex_lookup.insert(cache_k, id);
                return (id, ha);
            }
        }
        (0, false)
    }

    fn resolve_cec_face_submesh_tex(
        &mut self,
        vfs: &VirtualFileSystem,
        cls: i32,
        gender: u8,
        hint: &str,
        raw_tex: &str,
        ini: &pw_data::CharacterCustomizeIni,
        is_hair_skin: bool,
    ) -> (usize, bool) {
        let (tint, preserve_alpha) = select_cec_face_submesh_tint(hint, raw_tex, ini, is_hair_skin);
        let hint_low = hint.to_ascii_lowercase();
        let raw_low = raw_tex.to_ascii_lowercase();
        let cache_k = format!("cecface:{cls}:{gender}:{hint_low}/{raw_low}:{tint:08x}:{preserve_alpha}");
        if let Some(&id) = self.tex_lookup.get(&cache_k) {
            let ha = preserve_alpha && surface_has_cutout_alpha(&self.textures[id]);
            return (id, ha);
        }

        let fallback_facedata_candidates =
            cec_face_fallback_candidates(cls, gender, hint, raw_tex, is_hair_skin);

        let tex_bytes = read_model_texture_bytes(vfs, hint, raw_tex).or_else(|| {
            fallback_facedata_candidates
                .iter()
                .find_map(|p| vfs.read_file(p).ok())
        });
        if let Some(tb) = tex_bytes {
            if let Ok(simg) = decode_surface_auto(&tb) {
                let tinted = tint_surface_image_rgb(&simg, tint, preserve_alpha);
                let ha = preserve_alpha && surface_has_cutout_alpha(&tinted);
                let id = self.textures.len();
                self.textures.push(tinted);
                self.tex_lookup.insert(cache_k, id);
                return (id, ha);
            }
        }
        // Guaranteed non-white fallback skin/hair swatch if archive is not yet mounted
        let id = self.textures.len();
        self.textures.push(SurfaceImage::solid(8, 8, 0xFF00_0000 | (tint & 0x00FF_FFFF)));
        self.tex_lookup.insert(cache_k, id);
        (id, false)
    }

    fn resolve_body_submesh_tex(
        &mut self,
        vfs: &VirtualFileSystem,
        hint: &str,
        raw_tex: &str,
        body_tint: Option<u32>,
    ) -> (usize, bool) {
        let Some(tint) = body_tint.filter(|&c| (c & 0x00FF_FFFF) != 0x00FF_FFFF) else {
            return self.resolve_skin_submesh_tex(vfs, hint, raw_tex, true);
        };
        let hint_low = hint.to_ascii_lowercase();
        let raw_low = raw_tex.to_ascii_lowercase();
        let cache_k = format!("bodytex:{hint_low}/{raw_low}:{tint:08x}");
        if let Some(&id) = self.tex_lookup.get(&cache_k) {
            return (id, false);
        }
        if let Some(tb) = read_model_texture_bytes(vfs, hint, raw_tex) {
            if let Ok(simg) = decode_surface_auto(&tb) {
                let tinted = tint_surface_image_rgb(&simg, tint, false);
                let id = self.textures.len();
                self.textures.push(tinted);
                self.tex_lookup.insert(cache_k, id);
                return (id, false);
            }
        }
        self.resolve_skin_submesh_tex(vfs, hint, raw_tex, true)
    }

    fn ensure_weapon_batches(&mut self, vfs: &VirtualFileSystem, cls: i32) {
        let c = cls.clamp(0, 7);
        if self.weapon_batches.contains_key(&c) {
            return;
        }
        let (_, weap_path, _) = class_signature_weapon_ski(c);
        let mut batches = Vec::new();
        if let Ok(bytes) = vfs.read_file(weap_path) {
            if let Ok(sk) = A3dSkin::parse_ski(&bytes, weap_path) {
                for sm in sk.meshes {
                    let (tid, ha) =
                        self.resolve_skin_submesh_tex(vfs, &sm.texture_vfs_hint, &sm.raw_texture, true);
                    batches.push(GpuMeshBatch {
                        tex_id: tid,
                        two_sided: true,
                        alpha_test: ha,
                        alpha_blend: false,
                        verts: sm.verts,
                        indices: sm.indices,
                    });
                }
            }
        }
        self.weapon_batches.insert(c, batches);
    }

    /// Evaluates skeletal animation (`.bon` + `.smd` + `.stck`), linear-blend vertex skinning,
    /// `HH_*` 3D weapon attachment, and real `.ecm` NPC/Monster poses for BOTH `D3d9Renderer` and CPU!
    pub fn build_actor_draw_calls(
        &mut self,
        vfs: &VirtualFileSystem,
        actor: &DynamicCharacterActor,
        anim_time: f32,
    ) -> Vec<(Mat4, GpuMeshBatch)> {
        let mut draws = Vec::new();
        let sun_dir = Vec3::new(-0.35, 0.78, -0.52).normalized();
        // Phase-offset animation slightly by `role_id` so nearby actors don't breathe/step in robotic lockstep
        let phase = (actor.role_id % 17) as f32 * 0.23;
        let actor_time = anim_time + phase;

        // Branch A: Real 3D NPC or Monster `.ecm` (`models/npcs/.../*.ecm`)
        if let Some(ecm_path) = &actor.ecm_path {
            let ecm_norm = ecm_path.replace('\\', "/");
            if !self.ecm_actors.contains_key(&ecm_norm) {
                let cands = [ecm_norm.clone(), format!("models/{ecm_norm}")];
                let loaded = cands
                    .iter()
                    .find_map(|p| load_ecm_rig_and_skins(vfs, p))
                    .map(|(desc, rig, skins)| {
                        let mut submeshes = Vec::new();
                        for sk in skins {
                            let bone_map = rig.build_bone_map(&sk);
                            for sm in sk.meshes {
                                let (tex_id, alpha_test) = self.resolve_skin_submesh_tex(
                                    vfs,
                                    &sm.texture_vfs_hint,
                                    &sm.raw_texture,
                                    false,
                                );
                                submeshes.push(CachedSkinSubMesh {
                                    tex_id,
                                    alpha_test,
                                    bone_map: bone_map.clone(),
                                    submesh: sm,
                                });
                            }
                        }
                        CachedEcmActor {
                            scale: desc.scale,
                            rig,
                            submeshes,
                        }
                    });
                self.ecm_actors.insert(ecm_norm.clone(), loaded);
            }
            if let Some(Some(cached)) = self.ecm_actors.get_mut(&ecm_norm) {
                let total_scale = actor.scale * cached.scale;
                let actor_world = Mat4::a3d_transform_matrix(
                    actor.dir,
                    Vec3::UNIT_Y,
                    actor.pos,
                    Vec3::new(total_scale, total_scale, total_scale),
                );
                let (tm_blend, _) =
                    cached.rig.evaluate_action_pose(vfs, actor.action, actor_time);
                for csm in &cached.submeshes {
                    let verts =
                        skin_submesh_vertices(&csm.submesh, &csm.bone_map, &tm_blend, sun_dir);
                    draws.push((
                        actor_world,
                        GpuMeshBatch {
                            tex_id: csm.tex_id,
                            two_sided: true,
                            alpha_test: csm.alpha_test,
                            alpha_blend: false,
                            verts,
                            indices: csm.submesh.indices.clone(),
                        },
                    ));
                }
                if actor.fly_ecm_path.is_none() {
                    draws.push((
                        Mat4::IDENTITY,
                        build_ground_shadow_batch(self.shadow_blob_tex_id, actor.pos, 0.92 * actor.scale),
                    ));
                }
                if actor.selected {
                    draws.push((Mat4::IDENTITY, build_target_ring_batch(actor.pos, 1.05, 0xCCFF_4838)));
                }
                return draws;
            }
            // `models.pck` unavailable -> `.ecm` failed to load: draw a tinted procedural
            // placeholder so the NPC/monster is still visible next to its name label.
            if self
                .ecm_actors
                .get(&ecm_norm)
                .map(|c| c.is_none())
                .unwrap_or(false)
            {
                if !self.procedural_npcs.contains_key(&ecm_norm) {
                    let tint = npc_placeholder_tint(&ecm_norm);
                    self.procedural_npcs.insert(
                        ecm_norm.clone(),
                        build_procedural_humanoid_batch(tint, tint, 0xFF3A_3F4A),
                    );
                }
                let actor_world = Mat4::a3d_transform_matrix(
                    actor.dir,
                    Vec3::UNIT_Y,
                    actor.pos,
                    Vec3::new(actor.scale, actor.scale, actor.scale),
                );
                if let Some(b) = self.procedural_npcs.get(&ecm_norm) {
                    draws.push((actor_world, b.clone()));
                }
                draws.push((
                    Mat4::IDENTITY,
                    build_ground_shadow_batch(self.shadow_blob_tex_id, actor.pos, 0.92 * actor.scale),
                ));
                if actor.selected {
                    draws.push((Mat4::IDENTITY, build_target_ring_batch(actor.pos, 1.05, 0xCCFF_4838)));
                }
                return draws;
            }
        }

        // Branch B: Animated Player Character (`.bon` + `.smd` + `.ski` + `CECFace` `CC_Neck<->HH_Neck` + `HH_*` Weapon)
        let cls = actor.cls.clamp(0, 7);
        let gender = actor.gender & 1;
        let preset = actor.appearance_preset % 3;

        if !self.player_rigs.contains_key(&(cls, gender)) {
            let rig = player_smd_candidates(cls, gender)
                .into_iter()
                .find_map(|p| LoadedSkeletonRig::load_from_smd(vfs, &p));
            self.player_rigs.insert((cls, gender), rig);
        }

        let tpl_key = (cls, gender, preset);
        if !self.player_skin_templates.contains_key(&tpl_key) {
            let ini = load_character_customize_ini(vfs, cls, gender);
            let skins = load_player_character_skins_custom(vfs, cls, gender, preset);
            let mut list = Vec::new();
            for (skin_idx, sk) in skins.into_iter().enumerate() {
                let bone_map = self
                    .player_rigs
                    .get(&(cls, gender))
                    .and_then(|r| r.as_ref())
                    .map(|r| r.build_bone_map(&sk))
                    .unwrap_or_else(|| (0..64).collect());
                // First skin in `load_player_character_skins_custom` is `躯干/{folder}.ski` (bare body limbs/torso -> `color_body`!)
                let body_tint = if skin_idx == 0 { Some(ini.color_body) } else { None };
                for sm in sk.meshes {
                    let (tex_id, alpha_test) = self.resolve_body_submesh_tex(
                        vfs,
                        &sm.texture_vfs_hint,
                        &sm.raw_texture,
                        body_tint,
                    );
                    list.push(CachedSkinSubMesh {
                        tex_id,
                        alpha_test,
                        bone_map: bone_map.clone(),
                        submesh: sm,
                    });
                }
            }
            self.player_skin_templates.insert(tpl_key, list);
        }

        if !self.player_face_templates.contains_key(&tpl_key) {
            let fb = load_cec_face_bundle(vfs, cls, gender, preset);
            let mut face_submeshes = Vec::new();
            for (is_hair, skin_vec) in [(false, fb.face_skins), (true, fb.hair_skins)] {
                for sk in skin_vec {
                    let bone_map = if let Some(ref fskel) = fb.face_skeleton {
                        sk.bone_names
                            .iter()
                            .map(|bn| {
                                fskel
                                    .bones
                                    .iter()
                                    .position(|b| b.name.eq_ignore_ascii_case(bn))
                                    .unwrap_or(0)
                            })
                            .collect()
                    } else {
                        self.player_rigs
                            .get(&(cls, gender))
                            .and_then(|r| r.as_ref())
                            .map(|r| r.build_bone_map(&sk))
                            .unwrap_or_else(|| (0..64).collect())
                    };
                    for sm in sk.meshes {
                        let (tex_id, alpha_test) = self.resolve_cec_face_submesh_tex(
                            vfs,
                            cls,
                            gender,
                            &sm.texture_vfs_hint,
                            &sm.raw_texture,
                            &fb.ini,
                            is_hair,
                        );
                        face_submeshes.push(CachedSkinSubMesh {
                            tex_id,
                            alpha_test,
                            bone_map: bone_map.clone(),
                            submesh: sm,
                        });
                    }
                }
            }
            self.player_face_templates.insert(
                tpl_key,
                CachedFaceTemplate {
                    face_skeleton: fb.face_skeleton,
                    face_submeshes,
                },
            );
        }
        self.ensure_weapon_batches(vfs, cls);

        let actor_world = Mat4::a3d_transform_matrix(
            actor.dir,
            Vec3::UNIT_Y,
            actor.pos,
            Vec3::new(actor.scale, actor.scale, actor.scale),
        );

        let pose_opt = self
            .player_rigs
            .get_mut(&(cls, gender))
            .and_then(|r| r.as_mut())
            .map(|rig| {
                let (tm_blend, tm_abs) = rig.evaluate_action_pose(vfs, actor.action, actor_time);
                let (hook_sub, _, dual_left) = class_signature_weapon_ski(cls);
                let r_hook = rig
                    .skeleton
                    .hook_world_matrix(&tm_abs, hook_sub, actor_world);
                let l_hook = if dual_left {
                    rig.skeleton
                        .hook_world_matrix(&tm_abs, "lefthandweapon", actor_world)
                } else {
                    None
                };
                (tm_blend, tm_abs, r_hook, l_hook)
            });

        let custom_ini = self
            .custom_presets
            .get(&tpl_key)
            .cloned();

        let body_drawn = match self.player_skin_templates.get(&tpl_key) {
            Some(submeshes) if !submeshes.is_empty() => {
                for csm in submeshes {
                    let mut verts = if let Some((ref tm_blend, _, _, _)) = pose_opt {
                        skin_submesh_vertices(&csm.submesh, &csm.bone_map, tm_blend, sun_dir)
                    } else {
                        csm.submesh.verts.clone()
                    };
                    if let Some(ref ini) = custom_ini {
                        apply_body_proportions_to_vertices(&mut verts, ini);
                    }
                    draws.push((
                        actor_world,
                        GpuMeshBatch {
                            tex_id: csm.tex_id,
                            two_sided: true,
                            alpha_test: csm.alpha_test,
                            alpha_blend: false,
                            verts,
                            indices: csm.submesh.indices.clone(),
                        },
                    ));
                }
                true
            }
            _ => false,
        };
        // `models.pck` unavailable -> no `.ski` body: procedural humanoid tinted by the
        // real `CECCustomizeIni.color_body` + class color (real facedata head still attaches above).
        if !body_drawn {
            if !self.procedural_avatars.contains_key(&tpl_key) {
                let ini = load_character_customize_ini(vfs, cls, gender);
                let armor = class_armor_tint(cls, gender);
                self.procedural_avatars.insert(
                    tpl_key,
                    build_procedural_humanoid_batch(ini.color_body, armor, 0xFF3A_3F4A),
                );
            }
            if let Some(b) = self.procedural_avatars.get(&tpl_key) {
                draws.push((actor_world, b.clone()));
            }
        }

        // Attach `CECFace` (`models/face/*标准脸*.{bon,ski}` + `facedata/*/头发模型库/*头发*.ski`)
        // to the body skeleton via `CC_Neck <-> HH_Neck` (`0x559250`) in `actor_world` local space!
        if let Some(ftpl) = self.player_face_templates.get(&tpl_key) {
            if let Some(ref fskel) = ftpl.face_skeleton {
                let (face_tm_blend, face_tm_abs) = fskel.evaluate_pose(None, 0.0);
                let neck_to_actor = match (
                    pose_opt.as_ref(),
                    self.player_rigs.get(&(cls, gender)).and_then(|r| r.as_ref()),
                ) {
                    (Some((_, ref parent_tm_abs, _, _)), Some(p_rig)) => p_rig
                        .skeleton
                        .compute_child_attachment_world(
                            parent_tm_abs,
                            Mat4::IDENTITY,
                            fskel,
                            &face_tm_abs,
                            1.0,
                        )
                        .or_else(|| {
                            p_rig
                                .skeleton
                                .hook_world_matrix(parent_tm_abs, "neck", Mat4::IDENTITY)
                        }),
                    _ => None,
                }
                .unwrap_or_else(|| {
                    Mat4([
                        [1.0, 0.0, 0.0, 0.0],
                        [0.0, 1.0, 0.0, 0.0],
                        [0.0, 0.0, 1.0, 0.0],
                        [0.0, 1.50, 0.0, 1.0],
                    ])
                });

                for csm in &ftpl.face_submeshes {
                    let mut verts =
                        skin_submesh_vertices(&csm.submesh, &csm.bone_map, &face_tm_blend, sun_dir);
                    if let Some(ref ini) = custom_ini {
                        apply_cecface_morph_to_vertices(&mut verts, ini, true);
                    }
                    for vt in &mut verts {
                        let p = neck_to_actor.transform_point(Vec3::new(vt.x, vt.y, vt.z));
                        vt.x = p.x;
                        vt.y = p.y;
                        vt.z = p.z;
                    }
                    draws.push((
                        actor_world,
                        GpuMeshBatch {
                            tex_id: csm.tex_id,
                            two_sided: true,
                            alpha_test: csm.alpha_test,
                            alpha_blend: false,
                            verts,
                            indices: csm.submesh.indices.clone(),
                        },
                    ));
                }
            } else {
                for csm in &ftpl.face_submeshes {
                    let mut verts = if let Some((ref tm_blend, _, _, _)) = pose_opt {
                        skin_submesh_vertices(&csm.submesh, &csm.bone_map, tm_blend, sun_dir)
                    } else {
                        csm.submesh.verts.clone()
                    };
                    if pose_opt.is_none() {
                        for vt in &mut verts {
                            vt.y += 1.52;
                        }
                    }
                    if let Some(ref ini) = custom_ini {
                        apply_cecface_morph_to_vertices(&mut verts, ini, false);
                    }
                    draws.push((
                        actor_world,
                        GpuMeshBatch {
                            tex_id: csm.tex_id,
                            two_sided: true,
                            alpha_test: csm.alpha_test,
                            alpha_blend: false,
                            verts,
                            indices: csm.submesh.indices.clone(),
                        },
                    ));
                }
            }
        }

        if let (Some((_, ref parent_tm_abs, r_hook, l_hook)), Some(wbatches)) =
            (pose_opt.as_ref(), self.weapon_batches.get(&cls))
        {
            if let Some(&wm) = r_hook.as_ref() {
                for wb in wbatches {
                    draws.push((wm, wb.clone()));
                }
            }
            if let Some(&wm) = l_hook.as_ref() {
                for wb in wbatches {
                    draws.push((wm, wb.clone()));
                }
            }
            let _ = parent_tm_abs;
        }

        // 3D Racial Aerogear (`飞剑` / `翅膀` / `狮鹫` `.ecm`) attached via exact `HH_*` <-> `CC_*` bone hooks!
        if let Some(fly_ecm_raw) = &actor.fly_ecm_path {
            let fly_norm = fly_ecm_raw.replace('\\', "/");
            if !self.ecm_actors.contains_key(&fly_norm) {
                let cands = [fly_norm.clone(), format!("models/{fly_norm}")];
                let loaded = cands
                    .iter()
                    .find_map(|p| load_ecm_rig_and_skins(vfs, p))
                    .map(|(desc, rig, skins)| {
                        let mut submeshes = Vec::new();
                        for sk in skins {
                            let bone_map = rig.build_bone_map(&sk);
                            for sm in sk.meshes {
                                let (tex_id, alpha_test) = self.resolve_skin_submesh_tex(
                                    vfs,
                                    &sm.texture_vfs_hint,
                                    &sm.raw_texture,
                                    false,
                                );
                                submeshes.push(CachedSkinSubMesh {
                                    tex_id,
                                    alpha_test,
                                    bone_map: bone_map.clone(),
                                    submesh: sm,
                                });
                            }
                        }
                        CachedEcmActor {
                            scale: desc.scale,
                            rig,
                            submeshes,
                        }
                    });
                self.ecm_actors.insert(fly_norm.clone(), loaded);
            }
            let child_eval = if let Some(Some(cached)) = self.ecm_actors.get_mut(&fly_norm) {
                let fly_act = match actor.action {
                    ActorActionKind::FlyMove | ActorActionKind::Run => ActorActionKind::FlyMove,
                    _ => ActorActionKind::FlyHover,
                };
                let (child_tm_blend, child_tm_abs) =
                    cached.rig.evaluate_action_pose(vfs, fly_act, actor_time);
                Some((cached.scale, child_tm_blend, child_tm_abs))
            } else {
                None
            };
            if let Some((c_scale, child_tm_blend, child_tm_abs)) = child_eval {
                let exact_hook_world = match (
                    pose_opt.as_ref(),
                    self.player_rigs.get(&(cls, gender)).and_then(|r| r.as_ref()),
                    self.ecm_actors.get(&fly_norm).and_then(|c| c.as_ref()),
                ) {
                    (Some((_, parent_tm_abs, _, _)), Some(p_rig), Some(c_ecm)) => p_rig
                        .skeleton
                        .compute_child_attachment_world(
                            parent_tm_abs,
                            actor_world,
                            &c_ecm.rig.skeleton,
                            &child_tm_abs,
                            c_scale,
                        ),
                    _ => None,
                };
                let fly_world = exact_hook_world.unwrap_or_else(|| {
                    let (_, dy, dback) = class_aerogear_ecm(actor.cls);
                    let fly_pos = Vec3::new(
                        actor.pos.x + actor.dir.x * dback,
                        actor.pos.y + dy,
                        actor.pos.z + actor.dir.z * dback,
                    );
                    let fscale = actor.scale * c_scale;
                    Mat4::a3d_transform_matrix(
                        actor.dir,
                        Vec3::UNIT_Y,
                        fly_pos,
                        Vec3::new(fscale, fscale, fscale),
                    )
                });
                if let Some(Some(cached)) = self.ecm_actors.get(&fly_norm) {
                    for csm in &cached.submeshes {
                        let verts = skin_submesh_vertices(
                            &csm.submesh,
                            &csm.bone_map,
                            &child_tm_blend,
                            sun_dir,
                        );
                        draws.push((
                            fly_world,
                            GpuMeshBatch {
                                tex_id: csm.tex_id,
                                two_sided: true,
                                alpha_test: csm.alpha_test,
                                alpha_blend: false,
                                verts,
                                indices: csm.submesh.indices.clone(),
                            },
                        ));
                    }
                }
            }
        }

        if actor.fly_ecm_path.is_none() {
            draws.push((
                Mat4::IDENTITY,
                build_ground_shadow_batch(self.shadow_blob_tex_id, actor.pos, 0.78 * actor.scale),
            ));
        }
        if actor.selected {
            draws.push((Mat4::IDENTITY, build_target_ring_batch(actor.pos, 0.85, 0xCCFF_D458)));
        }

        draws
    }

    /// Updates a `(cls, gender, preset)` `CharacterCustomizeIni` live (used by `Win_Create` sliders
    /// & `character*.ini`) and invalidates the cached `64x64` portrait so headshot proportions stay 1:1!
    pub fn set_custom_appearance(
        &mut self,
        cls: i32,
        gender: u8,
        preset: u8,
        ini: pw_data::CharacterCustomizeIni,
    ) {
        let key = (cls.clamp(0, 7), gender & 1, preset % 3);
        self.custom_presets.insert(key, ini);
        if self.portrait_cache_key == Some(key) {
            self.portrait_cache_key = None;
        }
    }

    pub fn get_custom_appearance(
        &self,
        cls: i32,
        gender: u8,
        preset: u8,
    ) -> pw_data::CharacterCustomizeIni {
        let key = (cls.clamp(0, 7), gender & 1, preset % 3);
        self.custom_presets.get(&key).cloned().unwrap_or_default()
    }

    /// Generates `CELCloudCreator` (`CloudSprite`) drifting horizon & mid-sky cumulus billboards around `eye`.
    pub fn build_cloud_ring_mesh(&self, eye: Vec3, anim_time: f32) -> (Vec<A3dLitVertex>, Vec<u16>) {
        if !self.clouds_enabled {
            return (Vec::new(), Vec::new());
        }
        const CLOUD_COUNT: usize = 18;
        let mut verts = Vec::with_capacity(CLOUD_COUNT * 4);
        let mut indices = Vec::with_capacity(CLOUD_COUNT * 6);
        let drift = anim_time * 0.0085;

        for i in 0..CLOUD_COUNT {
            let fi = i as f32;
            let base_ang = (fi / CLOUD_COUNT as f32) * std::f32::consts::TAU + ((i * 7) % 5) as f32 * 0.11;
            let ang = base_ang + drift * (0.75 + (i % 3) as f32 * 0.25);
            let dist = 340.0 + ((i * 13) % 7) as f32 * 22.0;
            let elev = 78.0 + ((i * 11) % 6) as f32 * 16.0;
            let half_w = 54.0 + ((i * 5) % 4) as f32 * 14.0;
            let half_h = half_w * 0.46;

            let cx = eye.x + ang.cos() * dist;
            let cy = eye.y + elev;
            let cz = eye.z + ang.sin() * dist;
            // Tangent vector perpendicular to view ray `(cos, 0, sin)` is `(-sin, 0, cos)`
            let tx = -ang.sin() * half_w;
            let tz = ang.cos() * half_w;
            let col = 0xD8FF_FFFFu32;

            let b = verts.len() as u16;
            verts.push(A3dLitVertex { x: cx - tx, y: cy + half_h, z: cz - tz, diffuse: col, u: 0.0, v: 0.0 });
            verts.push(A3dLitVertex { x: cx + tx, y: cy + half_h, z: cz + tz, diffuse: col, u: 1.0, v: 0.0 });
            verts.push(A3dLitVertex { x: cx + tx, y: cy - half_h, z: cz + tz, diffuse: col, u: 1.0, v: 1.0 });
            verts.push(A3dLitVertex { x: cx - tx, y: cy - half_h, z: cz - tz, diffuse: col, u: 0.0, v: 1.0 });
            indices.extend_from_slice(&[b, b + 1, b + 2, b, b + 2, b + 3]);
        }
        (verts, indices)
    }

    /// Re-centers the `4x4` (`2048m x 2048m`) `minimaps/world/{rr:02}{cc:02}.dds` radar composite when
    /// the player travels near the border of the active radar window.
    pub fn refresh_minimap_for_pos(&mut self, vfs: &VirtualFileSystem, wx: f32, wz: f32) {
        if !self.map_name.eq_ignore_ascii_case("world") {
            return;
        }
        let (min_x, max_x, min_z, max_z) = self.minimap_bounds;
        if wx < min_x + 380.0
            || wx > max_x - 380.0
            || wz < min_z + 380.0
            || wz > max_z - 380.0
        {
            if let Some((tid, bounds)) =
                load_minimap_composite_at(vfs, &self.map_name, wx, wz, &mut self.textures)
            {
                self.minimap_tex_id = Some(tid);
                self.minimap_bounds = bounds;
            }
        }
    }

    /// Lazily loads and caches a `1024m x 1024m` regional map tile `surfaces/maps/{sr:02}{sc:01}.dds` (`000..107.dds`).
    pub fn ensure_regional_map_tex(
        &mut self,
        vfs: &VirtualFileSystem,
        sub_row: usize,
        sub_col: usize,
    ) -> Option<usize> {
        let key = (sub_row, sub_col);
        if !self.regional_map_cache.contains_key(&key) {
            let tid = load_regional_map_texture(vfs, sub_row, sub_col, &mut self.textures);
            self.regional_map_cache.insert(key, tid);
        }
        self.regional_map_cache.get(&key).copied().flatten()
    }

    /// Updates and returns the `104x104` circular-masked radar texture (`CDlgMiniMap`, `surfaces/ingame/minimapmask.tga`)
    /// centered at `(player_x, player_z)` with NPC/monster blips and player directional arrow strictly inside `r <= 50px`!
    pub fn update_circular_minimap(
        &mut self,
        vfs: &VirtualFileSystem,
        player_x: f32,
        player_z: f32,
        player_yaw: f32,
        radar_half_span_m: f32,
        markers: &[(f32, f32, u32)],
    ) -> Option<usize> {
        self.refresh_minimap_for_pos(vfs, player_x, player_z);
        let src_tid = self.minimap_tex_id?;
        let mask_tid = self.ensure_ui_surface(vfs, "InGame\\minimapmask.tga");
        let sz = 104u32;
        let half = 52.0f32;
        let (min_x, max_x, min_z, max_z) = self.minimap_bounds;
        let span_x = (max_x - min_x).max(1.0);
        let span_z = (max_z - min_z).max(1.0);
        let half_m = radar_half_span_m.clamp(80.0, 480.0);

        let mut pixels = vec![0u32; (sz * sz) as usize];
        {
            let src_img = &self.textures[src_tid];
            let mask_img = mask_tid.and_then(|id| self.textures.get(id));
            for py in 0..sz {
                let dy = (py as f32 + 0.5) - half;
                let wz = player_z - (dy / half) * half_m;
                let v = ((max_z - wz) / span_z).clamp(0.0, 1.0);
                for px in 0..sz {
                    let dx = (px as f32 + 0.5) - half;
                    let r = (dx * dx + dy * dy).sqrt();
                    if r > 51.4 {
                        continue;
                    }
                    let wx = player_x + (dx / half) * half_m;
                    let u = ((wx - min_x) / span_x).clamp(0.0, 1.0);
                    let rgb = src_img.sample_uv_bilinear(u, v) & 0x00FF_FFFF;
                    let mask_a = if let Some(m) = mask_img {
                        let mc = m.sample_uv_clamp(
                            (px as f32 + 0.5) / (sz as f32),
                            (py as f32 + 0.5) / (sz as f32),
                        );
                        (mc >> 24) & 0xFF
                    } else {
                        ((51.4 - r).clamp(0.0, 1.4) / 1.4 * 255.0) as u32
                    };
                    // Enforce BOTH `minimapmask.tga` AND hard geometric `r <= 51.0` circle so zero pixels ever bleed outside `cover`!
                    let geom_a = (((51.2 - r) * 180.0).clamp(0.0, 255.0)) as u32;
                    let final_a = mask_a.min(geom_a);
                    if final_a > 0 {
                        pixels[(py * sz + px) as usize] = (final_a << 24) | rgb;
                    }
                }
            }
        }

        // Draw NPC/monster blips strictly inside `r <= 46px`
        for &(mx, mz, col) in markers {
            let fx = (mx - player_x) / half_m * half;
            let fy = (player_z - mz) / half_m * half;
            if fx * fx + fy * fy > 46.0 * 46.0 {
                continue;
            }
            let cx = (half + fx).round() as i32;
            let cy = (half + fy).round() as i32;
            for oy in -2..=2 {
                for ox in -2..=2 {
                    if ox * ox + oy * oy > 5 {
                        continue;
                    }
                    let px = cx + ox;
                    let py = cy + oy;
                    if px >= 0 && py >= 0 && px < sz as i32 && py < sz as i32 {
                        let c = if ox * ox + oy * oy == 5 {
                            0xFF0A_1218
                        } else {
                            col | 0xFF00_0000
                        };
                        pixels[(py as u32 * sz + px as u32) as usize] = c;
                    }
                }
            }
        }

        // Draw rotating green/white player directional arrow at `(52, 52)` (`North = -Y`, `+X = East`)
        let dir_x = player_yaw.sin();
        let dir_y = -player_yaw.cos();
        let perp_x = -dir_y;
        let perp_y = dir_x;
        let tip = (half + dir_x * 6.5, half + dir_y * 6.5);
        let bl = (
            half - dir_x * 4.5 + perp_x * 4.2,
            half - dir_y * 4.5 + perp_y * 4.2,
        );
        let br = (
            half - dir_x * 4.5 - perp_x * 4.2,
            half - dir_y * 4.5 - perp_y * 4.2,
        );
        let area = (bl.0 - tip.0) * (br.1 - tip.1) - (bl.1 - tip.1) * (br.0 - tip.0);
        if area.abs() > 0.1 {
            let inv_a = 1.0 / area;
            for py in 42..62 {
                for px in 42..62 {
                    let x = px as f32 + 0.5;
                    let y = py as f32 + 0.5;
                    let w0 = ((bl.0 - x) * (br.1 - y) - (bl.1 - y) * (br.0 - x)) * inv_a;
                    let w1 = ((br.0 - x) * (tip.1 - y) - (br.1 - y) * (tip.0 - x)) * inv_a;
                    let w2 = 1.0 - w0 - w1;
                    if w0 >= -0.12 && w1 >= -0.12 && w2 >= -0.12 {
                        let c = if w0 < 0.08 || w1 < 0.08 || w2 < 0.08 {
                            0xFF0B_2A10
                        } else {
                            0xFF7C_FF68
                        };
                        pixels[(py * sz + px) as usize] = c;
                    }
                }
            }
        }

        if let Some(tid) = self.minimap_circle_tex_id {
            self.textures[tid] = SurfaceImage::from_pixels(sz, sz, pixels);
            Some(tid)
        } else {
            let tid = self.textures.len();
            self.textures.push(SurfaceImage::from_pixels(sz, sz, pixels));
            self.minimap_circle_tex_id = Some(tid);
            Some(tid)
        }
    }

    /// Renders a genuine `64x64` 3D character headshot portrait (`CECImageRes` / `Win_Hpmpxp::Size`) masked to a circle!
    pub fn ensure_player_portrait_tex(
        &mut self,
        vfs: &VirtualFileSystem,
        cls: i32,
        gender: u8,
        preset: u8,
    ) -> Option<usize> {
        let key = (cls.clamp(0, 7), gender & 1, preset % 3);
        if self.portrait_cache_key == Some(key) {
            if let Some(tid) = self.portrait_circle_tex_id {
                return Some(tid);
            }
        }
        let actor = DynamicCharacterActor {
            role_id: 1,
            name: String::new(),
            cls: key.0,
            gender: key.1,
            appearance_preset: key.2,
            action: ActorActionKind::Stand,
            ecm_path: None,
            fly_ecm_path: None,
            pos: Vec3::ZERO,
            dir: Vec3::new(0.18, 0.0, 0.98).normalized(),
            scale: 1.0,
            selected: false,
        };
        let draws = self.build_actor_draw_calls(vfs, &actor, 0.0);
        // Locate exact `Bip01 Head` 3D bone origin from `player_rigs` (`tm_abs[head_bi] * actor_world`)
        // so crouching poses (e.g. Tideborn Female Assassin) and tall poses (Untamed Barbarian) always center the face!
        let actor_world = Mat4::a3d_transform_matrix(actor.dir, Vec3::UNIT_Y, Vec3::ZERO, Vec3::new(1.0, 1.0, 1.0));
        let bone_head = self
            .player_rigs
            .get_mut(&(key.0, key.1))
            .and_then(|r| r.as_mut())
            .and_then(|rig| {
                let (_, tm_abs) = rig.evaluate_action_pose(vfs, ActorActionKind::Stand, 0.23);
                let hbi = rig
                    .skeleton
                    .bones
                    .iter()
                    .position(|b| b.name.eq_ignore_ascii_case("Bip01 Head"))
                    .or_else(|| {
                        rig.skeleton.bones.iter().position(|b| {
                            let bl = b.name.to_ascii_lowercase();
                            bl.contains("head") && !bl.contains("nub")
                        })
                    })?;
                let hm = tm_abs.get(hbi)?.mul(actor_world);
                Some(Vec3::new(hm.0[3][0], hm.0[3][1], hm.0[3][2]))
            });

        let target = if let Some(hp) = bone_head {
            Vec3::new(hp.x, hp.y + 0.075, hp.z)
        } else {
            let mut max_y = 0.0f32;
            for (wm, b) in &draws {
                if b.alpha_blend || wm.0[3][0].abs() > 0.05 || wm.0[3][1].abs() > 0.05 || wm.0[3][2].abs() > 0.05 {
                    continue;
                }
                for vt in &b.verts {
                    if vt.y.is_finite() && vt.y < 2.35 && vt.y > max_y {
                        max_y = vt.y;
                    }
                }
            }
            if max_y < 1.15 {
                max_y = 1.68;
            }
            Vec3::new(0.0, (max_y - 0.14).clamp(1.20, 2.15), 0.0)
        };
        let eye = Vec3::new(target.x + 0.04, target.y + 0.025, target.z + 0.54);
        let look_dir = target.sub(eye).normalized();
        let view = Mat4::look_to_lh(eye, look_dir, Vec3::UNIT_Y);
        let proj = Mat4::perspective_fov_lh(33.0f32.to_radians(), 1.0, 0.12, 8.0);
        let vp = view.mul(proj);

        let sz = 64u32;
        let mut pfb = FrameBuffer::new(sz, sz);
        for y in 0..sz {
            let gy = y as f32 / sz as f32;
            let r = (24.0 + gy * 18.0) as u32;
            let g = (38.0 + gy * 26.0) as u32;
            let b = (58.0 + gy * 32.0) as u32;
            for x in 0..sz {
                pfb.pixels[(y * sz + x) as usize] = 0xFF00_0000 | (r << 16) | (g << 8) | b;
            }
        }
        pfb.zbuf.fill(1.0);
        for (wm, batch) in &draws {
            if batch.alpha_blend || wm.0[3][0].abs() > 0.05 || wm.0[3][1].abs() > 0.05 || wm.0[3][2].abs() > 0.05 {
                continue;
            }
            let mvp = wm.mul(vp);
            rasterize_batch(
                &mut pfb,
                &batch.verts,
                &batch.indices,
                mvp,
                *wm,
                eye,
                &self.textures[batch.tex_id],
                None,
                batch.two_sided,
                batch.alpha_test,
                batch.alpha_blend,
                !batch.alpha_blend,
                false,
                100.0,
                500.0,
                0xFF18_263A,
                0.0,
            );
        }
        let half = (sz as f32) * 0.5;
        for y in 0..sz {
            for x in 0..sz {
                let dx = (x as f32 + 0.5) - half;
                let dy = (y as f32 + 0.5) - half;
                let r = (dx * dx + dy * dy).sqrt();
                let a = (((half - 0.8 - r) * 180.0).clamp(0.0, 255.0)) as u32;
                let i = (y * sz + x) as usize;
                pfb.pixels[i] = (a << 24) | (pfb.pixels[i] & 0x00FF_FFFF);
            }
        }
        let img = SurfaceImage::from_pixels_with_mips(sz, sz, pfb.pixels);
        self.portrait_cache_key = Some(key);
        if let Some(tid) = self.portrait_circle_tex_id {
            self.textures[tid] = img;
            Some(tid)
        } else {
            let tid = self.textures.len();
            self.textures.push(img);
            self.portrait_circle_tex_id = Some(tid);
            Some(tid)
        }
    }

    /// Renders a genuine `64x64` circular-masked 3D headshot portrait of an `.ecm` NPC (`Win_HpmpOther::Size`)!
    pub fn ensure_ecm_portrait_tex(
        &mut self,
        vfs: &VirtualFileSystem,
        ecm_path: &str,
    ) -> Option<usize> {
        let key = ecm_path.replace('\\', "/").to_ascii_lowercase();
        if let Some(&cached) = self.npc_portrait_cache.get(&key) {
            return cached;
        }
        let actor = DynamicCharacterActor {
            role_id: 2,
            name: String::new(),
            cls: 0,
            gender: 0,
            appearance_preset: 0,
            action: ActorActionKind::Stand,
            ecm_path: Some(ecm_path.to_string()),
            fly_ecm_path: None,
            pos: Vec3::ZERO,
            dir: Vec3::new(0.15, 0.0, 0.99).normalized(),
            scale: 1.0,
            selected: false,
        };
        let draws = self.build_actor_draw_calls(vfs, &actor, 0.0);
        if draws.is_empty() {
            self.npc_portrait_cache.insert(key, None);
            return None;
        }
        let mut min_y = f32::INFINITY;
        let mut max_y = f32::NEG_INFINITY;
        for (wm, b) in &draws {
            if b.alpha_blend {
                continue;
            }
            for vt in &b.verts {
                let p = wm.transform_point(Vec3::new(vt.x, vt.y, vt.z));
                if p.y.is_finite() && p.y > -0.2 && p.y < 3.6 {
                    min_y = min_y.min(p.y);
                    max_y = max_y.max(p.y);
                }
            }
        }
        if !max_y.is_finite() || max_y <= min_y + 0.2 {
            min_y = 0.0;
            max_y = 1.78;
        }
        let h_span = (max_y - min_y).clamp(0.8, 3.2);
        let target = Vec3::new(0.0, max_y - h_span * 0.14, 0.0);
        let eye = Vec3::new(0.04, target.y + 0.02, target.z + (h_span * 0.34).clamp(0.50, 1.10));
        let view = Mat4::look_to_lh(eye, target.sub(eye).normalized(), Vec3::UNIT_Y);
        let proj = Mat4::perspective_fov_lh(34.0f32.to_radians(), 1.0, 0.10, 10.0);
        let vp = view.mul(proj);

        let sz = 64u32;
        let mut pfb = FrameBuffer::new(sz, sz);
        for y in 0..sz {
            let gy = y as f32 / sz as f32;
            let r = (24.0 + gy * 18.0) as u32;
            let g = (38.0 + gy * 26.0) as u32;
            let b = (58.0 + gy * 32.0) as u32;
            for x in 0..sz {
                pfb.pixels[(y * sz + x) as usize] = 0xFF00_0000 | (r << 16) | (g << 8) | b;
            }
        }
        pfb.zbuf.fill(1.0);
        for (wm, batch) in &draws {
            if batch.alpha_blend {
                continue;
            }
            rasterize_batch(
                &mut pfb,
                &batch.verts,
                &batch.indices,
                wm.mul(vp),
                *wm,
                eye,
                &self.textures[batch.tex_id],
                None,
                batch.two_sided,
                batch.alpha_test,
                batch.alpha_blend,
                true,
                false,
                100.0,
                500.0,
                0xFF18_263A,
                0.0,
            );
        }
        let half = (sz as f32) * 0.5;
        for y in 0..sz {
            for x in 0..sz {
                let dx = (x as f32 + 0.5) - half;
                let dy = (y as f32 + 0.5) - half;
                let r = (dx * dx + dy * dy).sqrt();
                let a = (((half - 0.8 - r) * 180.0).clamp(0.0, 255.0)) as u32;
                let i = (y * sz + x) as usize;
                pfb.pixels[i] = (a << 24) | (pfb.pixels[i] & 0x00FF_FFFF);
            }
        }
        let tid = self.textures.len();
        self.textures
            .push(SurfaceImage::from_pixels_with_mips(sz, sz, pfb.pixels));
        self.npc_portrait_cache.insert(key, Some(tid));
        Some(tid)
    }

    /// Evaluates full-resolution per-pixel `A3DTerrain2` (`t2_lm_f2lays_*.txt`) `.t2mk` detail `.dds`
    /// with 4x Anisotropic + Trilinear Mipmap filtering + `.t2lm` `MODULATE2X` splatting!
    #[inline]
    #[allow(clippy::too_many_arguments)]
    pub fn sample_terrain_splat_at(
        &self,
        sub_slot: usize,
        area_idx: usize,
        wx: f32,
        wy: f32,
        wz: f32,
        dwx_dx: f32,
        dwz_dx: f32,
        dwx_dy: f32,
        dwz_dy: f32,
    ) -> Option<u32> {
        let splat = self.terrain_sub_splats.get(sub_slot)?;
        let T2MkSubTerrainMasks { layers, areas, .. } = splat.t2mk.as_ref()?;
        let area_masks = areas.get(area_idx)?;
        let ar = area_idx / 4;
        let ac = area_idx % 4;
        let span_x = splat.world_w * 0.25;
        let span_z = splat.world_l * 0.25;
        let ax0 = splat.origin_x + (ac as f32) * span_x;
        let az0 = splat.origin_z_top - (ar as f32) * span_z;
        let uf = ((wx - ax0) / span_x).clamp(0.0, 1.0);
        let vf = ((az0 - wz) / span_z).clamp(0.0, 1.0);

        let (mut r_acc, mut g_acc, mut b_acc) = (112.0f32, 124.0f32, 92.0f32);
        let mut any_sampled = false;
        for (mi, am) in area_masks.iter().enumerate() {
            let Some(ldesc) = layers.get(am.layer_idx) else {
                continue;
            };
            let alpha = if mi == 0 || am.mask_size == 0 || am.alpha_texels.is_empty() {
                1.0f32
            } else {
                let msz = am.mask_size as usize;
                let fx = (uf * (msz as f32) - 0.5).clamp(0.0, (msz - 1) as f32);
                let fy = (vf * (msz as f32) - 0.5).clamp(0.0, (msz - 1) as f32);
                let x0 = fx as usize;
                let y0 = fy as usize;
                let x1 = (x0 + 1).min(msz - 1);
                let y1 = (y0 + 1).min(msz - 1);
                let tx = fx - x0 as f32;
                let ty = fy - y0 as f32;
                let a00 = am.alpha_texels[y0 * msz + x0] as f32;
                let a10 = am.alpha_texels[y0 * msz + x1] as f32;
                let a01 = am.alpha_texels[y1 * msz + x0] as f32;
                let a11 = am.alpha_texels[y1 * msz + x1] as f32;
                let top = a00 + (a10 - a00) * tx;
                let bot = a01 + (a11 - a01) * tx;
                (top + (bot - top) * ty) * (1.0 / 255.0)
            };
            if alpha <= 0.004 {
                continue;
            }
            if ldesc.texture_idx >= 0 {
                if let Some(Some(dtex)) = self.terrain_detail_tex.get(ldesc.texture_idx as usize) {
                    let (tu, tv, dudx, dvdx, dudy, dvdy) = match ldesc.proj_axis {
                        0 => (
                            wz * ldesc.u_scale,
                            wy * ldesc.v_scale,
                            dwz_dx * ldesc.u_scale,
                            0.0,
                            dwz_dy * ldesc.u_scale,
                            0.0,
                        ),
                        2 => (
                            wx * ldesc.u_scale,
                            wy * ldesc.v_scale,
                            dwx_dx * ldesc.u_scale,
                            0.0,
                            dwx_dy * ldesc.u_scale,
                            0.0,
                        ),
                        _ => (
                            wx * ldesc.u_scale,
                            wz * ldesc.v_scale,
                            dwx_dx * ldesc.u_scale,
                            dwz_dx * ldesc.v_scale,
                            dwx_dy * ldesc.u_scale,
                            dwz_dy * ldesc.v_scale,
                        ),
                    };
                    let c = dtex.sample_uv_anisotropic(tu, tv, dudx, dvdx, dudy, dvdy);
                    let tr = ((c >> 16) & 0xFF) as f32;
                    let tg = ((c >> 8) & 0xFF) as f32;
                    let tb = (c & 0xFF) as f32;
                    if !any_sampled && alpha < 0.999 {
                        r_acc = tr;
                        g_acc = tg;
                        b_acc = tb;
                    } else {
                        r_acc += (tr - r_acc) * alpha;
                        g_acc += (tg - g_acc) * alpha;
                        b_acc += (tb - b_acc) * alpha;
                    }
                    any_sampled = true;
                }
            }
        }
        if !any_sampled {
            return None;
        }

        if let Some(Some(lm)) = splat.lm_day.get(area_idx) {
            let lc = lm.sample_uv_bilinear_clamp(uf, vf);
            let mut lr = (((lc >> 16) & 0xFF) as f32) * (2.0 / 255.0);
            let mut lg = (((lc >> 8) & 0xFF) as f32) * (2.0 / 255.0);
            let mut lb = ((lc & 0xFF) as f32) * (2.0 / 255.0);
            // `.t2lm1` night lightmap blend (sandbox `--night` / `--time HH` after dusk)
            if splat.night_weight > 0.001 {
                if let Some(Some(nlm)) = splat.lm_night.get(area_idx) {
                    let nlc = nlm.sample_uv_bilinear_clamp(uf, vf);
                    let nlr = (((nlc >> 16) & 0xFF) as f32) * (2.0 / 255.0);
                    let nlg = (((nlc >> 8) & 0xFF) as f32) * (2.0 / 255.0);
                    let nlb = ((nlc & 0xFF) as f32) * (2.0 / 255.0);
                    lr += (nlr - lr) * splat.night_weight;
                    lg += (nlg - lg) * splat.night_weight;
                    lb += (nlb - lb) * splat.night_weight;
                }
            }
            r_acc = (r_acc * lr).clamp(0.0, 255.0);
            g_acc = (g_acc * lg).clamp(0.0, 255.0);
            b_acc = (b_acc * lb).clamp(0.0, 255.0);
        }

        Some(0xFF00_0000 | ((r_acc as u32) << 16) | ((g_acc as u32) << 8) | (b_acc as u32))
    }

    /// Converts queued `UiText2D` commands into anti-aliased `UiQuad2D` TrueType glyph quads
    /// using `fzl2jw.ttf` (`fonts.pck`), shared identically by D3D9 and CPU!
    pub fn flush_texts_to_quads(&mut self, quads: &mut Vec<UiQuad2D>, texts: &mut Vec<UiText2D>) {
        for t in texts.drain(..) {
            self.font_atlas.emit_text_quads_clipped(
                &mut self.textures,
                quads,
                t.x,
                t.y,
                t.size_px,
                t.color,
                t.shadow,
                &t.text,
                t.clip_rect,
            );
        }
    }

    /// Downward vertical raycast (`CECWorld::RayTrace`) against both `A3DTerrain2` and walkable `.bmd`
    /// ornament surfaces (dungeon floors, stone bridges, stairs, and platforms) at `(x, z)` up to `ref_y + 2.2`.
    pub fn sample_walkable_height(&self, x: f32, ref_y: f32, z: f32, terrain_y: f32) -> f32 {
        let mut best_y = terrain_y;
        let max_y = ref_y + 2.2;
        for inst in &self.ornaments {
            let b = &inst.world_aabb;
            if x < b.mins.x - 0.05
                || x > b.maxs.x + 0.05
                || z < b.mins.z - 0.05
                || z > b.maxs.z + 0.05
                || b.maxs.y < best_y
                || b.mins.y > max_y
            {
                continue;
            }
            let wm = inst.world_mat;
            for batch in &self.bmd_models[inst.model_idx] {
                if batch.alpha_test || batch.alpha_blend {
                    continue;
                }
                for tri in batch.indices.chunks_exact(3) {
                    let (i0, i1, i2) = (tri[0] as usize, tri[1] as usize, tri[2] as usize);
                    if i0 >= batch.verts.len() || i1 >= batch.verts.len() || i2 >= batch.verts.len()
                    {
                        continue;
                    }
                    let p0 = wm.transform_point(Vec3::new(
                        batch.verts[i0].x,
                        batch.verts[i0].y,
                        batch.verts[i0].z,
                    ));
                    let p1 = wm.transform_point(Vec3::new(
                        batch.verts[i1].x,
                        batch.verts[i1].y,
                        batch.verts[i1].z,
                    ));
                    let p2 = wm.transform_point(Vec3::new(
                        batch.verts[i2].x,
                        batch.verts[i2].y,
                        batch.verts[i2].z,
                    ));
                    let min_x = p0.x.min(p1.x).min(p2.x);
                    let max_x = p0.x.max(p1.x).max(p2.x);
                    let min_z = p0.z.min(p1.z).min(p2.z);
                    let max_z = p0.z.max(p1.z).max(p2.z);
                    if x < min_x || x > max_x || z < min_z || z > max_z {
                        continue;
                    }
                    let denom = (p1.z - p2.z) * (p0.x - p2.x) + (p2.x - p1.x) * (p0.z - p2.z);
                    if denom.abs() < 1e-5 {
                        continue;
                    }
                    let inv_d = 1.0 / denom;
                    let w0 = ((p1.z - p2.z) * (x - p2.x) + (p2.x - p1.x) * (z - p2.z)) * inv_d;
                    let w1 = ((p2.z - p0.z) * (x - p2.x) + (p0.x - p2.x) * (z - p2.z)) * inv_d;
                    let w2 = 1.0 - w0 - w1;
                    if w0 >= -0.002 && w1 >= -0.002 && w2 >= -0.002 {
                        let hit_y = w0 * p0.y + w1 * p1.y + w2 * p2.y;
                        if hit_y <= max_y && hit_y > best_y {
                            // Verify walkable slope (|ny| >= 0.45)
                            let n = p1.sub(p0).cross(p2.sub(p0)).normalized();
                            if n.y.abs() >= 0.45 {
                                best_y = hit_y;
                            }
                        }
                    }
                }
            }
        }
        best_y
    }

    /// Lazily loads & caches real `.ski` 3D character meshes + `.dds` textures from `models.pck` for `(cls, gender)`.
    pub fn ensure_character_model(
        &mut self,
        vfs: &VirtualFileSystem,
        cls: i32,
        gender: u8,
    ) -> &[GpuMeshBatch] {
        let key = (cls.clamp(0, 7), gender & 1);
        if !self.character_cache.contains_key(&key) {
            let skins: Vec<A3dSkin> = load_player_character_skins_custom(vfs, key.0, key.1, 0);
            let mut batches = Vec::new();
            for skin in skins {
                for sm in skin.meshes {
                    let hint_low = sm.texture_vfs_hint.to_ascii_lowercase();
                    let raw_low = sm.raw_texture.to_ascii_lowercase();
                    // In Angelica3D (`A3DShader` `body_t2`), player equipment/body `.dds` textures store
                    // specular/skin-gloss intensity (`0..68`) in DXT3 alpha — ONLY hair/lashes/beards use cutout alpha!
                    let is_hair_cutout = hint_low.contains("face")
                        || raw_low.contains("hair")
                        || sm.raw_texture.contains('发')
                        || sm.raw_texture.contains('胡')
                        || sm.raw_texture.contains('睫');
                    let cache_k = format!("skitex:{hint_low}/{raw_low}:{is_hair_cutout}");
                    let (tid, has_alpha) = if let Some(&id) = self.tex_lookup.get(&cache_k) {
                        (id, is_hair_cutout && surface_has_cutout_alpha(&self.textures[id]))
                    } else if let Some(tb) =
                        read_model_texture_bytes(vfs, &sm.texture_vfs_hint, &sm.raw_texture)
                    {
                        if let Ok(mut simg) = decode_surface_auto(&tb) {
                            let ha = if is_hair_cutout {
                                surface_has_cutout_alpha(&simg)
                            } else {
                                for px in &mut simg.pixels {
                                    *px |= 0xFF00_0000;
                                }
                                false
                            };
                            let id = self.textures.len();
                            self.textures.push(simg);
                            self.tex_lookup.insert(cache_k, id);
                            (id, ha)
                        } else {
                            (0, false)
                        }
                    } else {
                        (0, false)
                    };
                    batches.push(GpuMeshBatch {
                        tex_id: tid,
                        two_sided: true,
                        alpha_test: has_alpha,
                        alpha_blend: false,
                        verts: sm.verts,
                        indices: sm.indices,
                    });
                }
            }
            self.character_cache.insert(key, batches);
        }
        self.character_cache.get(&key).map(Vec::as_slice).unwrap_or(&[])
    }

    /// Resolves and caches a `surfaces.pck` texture for `AUIManager` 2D controls.
    pub fn ensure_ui_surface(&mut self, vfs: &VirtualFileSystem, rel_surface: &str) -> Option<usize> {
        let clean = rel_surface.trim().replace('\\', "/");
        if clean.is_empty() {
            return None;
        }
        let norm = format!("ui:{}", clean.to_ascii_lowercase());
        if let Some(&id) = self.tex_lookup.get(&norm) {
            return Some(id);
        }
        let bytes = vfs.read_ui_surface(rel_surface)?;
        let mut img = decode_surface_auto(&bytes).ok()?;
        if norm.ends_with(".bmp") || bytes.starts_with(b"BM") {
            img.apply_magenta_colorkey();
        }
        let id = self.textures.len();
        self.textures.push(img);
        self.tex_lookup.insert(norm, id);
        Some(id)
    }
}

fn surface_has_cutout_alpha(img: &SurfaceImage) -> bool {
    let mut transparent = 0usize;
    let step = (img.pixels.len() / 512).max(1);
    for i in (0..img.pixels.len()).step_by(step) {
        let a = img.pixels[i] >> 24;
        if a < 180 {
            transparent += 1;
            if transparent >= 3 {
                return true;
            }
        }
    }
    false
}

fn build_water_surface_texture(textures: &mut Vec<SurfaceImage>) -> usize {
    let sz = 64u32;
    let mut pixels = vec![0u32; (sz * sz) as usize];
    for y in 0..sz {
        for x in 0..sz {
            let fx = (x as f32 / sz as f32) * std::f32::consts::TAU;
            let fy = (y as f32 / sz as f32) * std::f32::consts::TAU;
            let wave = ((fx * 2.0 + fy).sin() * 0.5 + (fx - fy * 2.0).cos() * 0.5) * 0.14 + 0.88;
            let r = (52.0 * wave).clamp(0.0, 255.0) as u32;
            let g = (148.0 * wave).clamp(0.0, 255.0) as u32;
            let b = (182.0 * wave).clamp(0.0, 255.0) as u32;
            pixels[(y * sz + x) as usize] = 0xC400_0000 | (r << 16) | (g << 8) | b;
        }
    }
    let id = textures.len();
    textures.push(SurfaceImage::from_pixels_with_mips(sz, sz, pixels));
    id
}

fn build_terrain_blocks(
    map: &MapInstanceBundle,
    vfs: &VirtualFileSystem,
    textures: &mut Vec<SurfaceImage>,
    tex_lookup: &mut HashMap<String, usize>,
    night_weight: f32,
) -> (
    Vec<TerrainBlockDraw>,
    Vec<Option<SurfaceImage>>,
    Vec<TerrainSubSplat>,
) {
    // Decode all detail textures referenced by `.trn2` once across all active sub-terrains
    let mut detail_imgs: Vec<Option<SurfaceImage>> = Vec::new();
    if let Some(trn) = &map.trn2_full {
        for tp in &trn.texture_paths {
            let img = vfs
                .read_file(tp)
                .ok()
                .or_else(|| {
                    let clean = tp.replace('\\', "/");
                    vfs.read_file(&format!("textures/{clean}")).ok()
                })
                .and_then(|b| decode_surface_auto(&b).ok());
            detail_imgs.push(img);
        }
    }

    // Multi-SubTerrain path (`maps/world` Midlands: primary `1024m` tile + adjacent neighbor `1024m` tiles)
    if !map.active_sub_terrains.is_empty() {
        let mut all_blocks = Vec::with_capacity(map.active_sub_terrains.len() * 256);
        let mut splats = Vec::with_capacity(map.active_sub_terrains.len());
        for (si, sub) in map.active_sub_terrains.iter().enumerate() {
            let area_sz = if si == 0 { 768u32 } else { 384u32 };
            let (sub_blocks, splat) = build_subterrain_blocks_one(
                map,
                si,
                &sub.height_mesh,
                sub.t2mk.as_ref(),
                sub.t2lm_day.as_ref(),
                sub.t2lm_night.as_ref(),
                night_weight,
                &detail_imgs,
                &format!("{}_{}", map.map_name, sub.sub_idx + 1),
                area_sz,
                textures,
                tex_lookup,
            );
            all_blocks.extend(sub_blocks);
            splats.push(splat);
        }
        return (all_blocks, detail_imgs, splats);
    }

    // Single-SubTerrain path (`a01`, `login`, dungeons)
    let (blocks, splat) = build_subterrain_blocks_one(
        map,
        0,
        &map.height_mesh,
        map.t2mk.as_ref(),
        map.t2lm_day.as_ref(),
        map.t2lm_night.as_ref(),
        night_weight,
        &detail_imgs,
        &map.map_name,
        768,
        textures,
        tex_lookup,
    );
    (blocks, detail_imgs, vec![splat])
}

#[allow(clippy::too_many_arguments)]
fn build_subterrain_blocks_one(
    map: &MapInstanceBundle,
    sub_slot: usize,
    hm: &pw_world::Terrain2HeightMesh,
    t2mk: Option<&T2MkSubTerrainMasks>,
    t2lm_day: Option<&T2LmSubTerrainLightmaps>,
    t2lm_night: Option<&T2LmSubTerrainLightmaps>,
    night_weight: f32,
    detail_imgs: &[Option<SurfaceImage>],
    cache_tag: &str,
    area_tex_sz: u32,
    textures: &mut Vec<SurfaceImage>,
    tex_lookup: &mut HashMap<String, usize>,
) -> (Vec<TerrainBlockDraw>, TerrainSubSplat) {
    let world_w = hm.world_width;
    let world_l = hm.world_length;
    let left = hm.origin_x;
    let top = hm.origin_z_top;

    // Decode 16 `.t2lm` day & `.t2lm1` night lightmaps (`256x256` DXT1 DDS)
    let mut lm_day_imgs: Vec<Option<SurfaceImage>> = Vec::new();
    if let Some(T2LmSubTerrainLightmaps { area_dds_blobs, .. }) = t2lm_day {
        for blob in area_dds_blobs {
            lm_day_imgs.push(decode_surface_auto(blob).ok());
        }
    }
    let mut lm_night_imgs: Vec<Option<SurfaceImage>> = Vec::new();
    if night_weight > 0.001 {
        if let Some(T2LmSubTerrainLightmaps { area_dds_blobs, .. }) = t2lm_night {
            for blob in area_dds_blobs {
                lm_night_imgs.push(decode_surface_auto(blob).ok());
            }
        }
    }

    // Composite 16 `256x256m` mask-area textures (tri-planar splat + `.t2lm`/`.t2lm1` DXT1 MODULATE2X lightmaps)
    let area_grid = 4usize;
    let area_world_span_x = world_w / (area_grid as f32);
    let area_world_span_z = world_l / (area_grid as f32);
    let mut area_tex_ids = Vec::with_capacity(area_grid * area_grid);

    for ar in 0..area_grid {
        for ac in 0..area_grid {
            let ai = ar * area_grid + ac;
            let area_x0 = left + (ac as f32) * area_world_span_x;
            let area_z0 = top - (ar as f32) * area_world_span_z;
            let mut pixels = vec![0xFF6E_7C58u32; (area_tex_sz * area_tex_sz) as usize];

            for py in 0..area_tex_sz {
                let vf = (py as f32 + 0.5) / (area_tex_sz as f32);
                let wz = area_z0 - vf * area_world_span_z;
                for px in 0..area_tex_sz {
                    let uf = (px as f32 + 0.5) / (area_tex_sz as f32);
                    let wx = area_x0 + uf * area_world_span_x;
                    let wy = hm.sample_height(wx, wz);

                    let (mut r_acc, mut g_acc, mut b_acc) = (112.0f32, 124.0f32, 92.0f32);

                    if let Some(T2MkSubTerrainMasks { layers, areas, .. }) = t2mk {
                        if let Some(area_masks) = areas.get(ai) {
                            for (mi, am) in area_masks.iter().enumerate() {
                                let Some(ldesc) = layers.get(am.layer_idx) else {
                                    continue;
                                };
                                let alpha = if mi == 0 || am.mask_size == 0 || am.alpha_texels.is_empty() {
                                    1.0f32
                                } else {
                                    let mx = ((uf * am.mask_size as f32) as usize)
                                        .min(am.mask_size as usize - 1);
                                    let my = ((vf * am.mask_size as f32) as usize)
                                        .min(am.mask_size as usize - 1);
                                    (am.alpha_texels[my * (am.mask_size as usize) + mx] as f32)
                                        * (1.0 / 255.0)
                                };
                                if alpha <= 0.004 {
                                    continue;
                                }
                                if ldesc.texture_idx >= 0 {
                                    if let Some(Some(dtex)) = detail_imgs.get(ldesc.texture_idx as usize) {
                                        let (tu, tv) = match ldesc.proj_axis {
                                            0 => (wz * ldesc.u_scale, wy * ldesc.v_scale),
                                            2 => (wx * ldesc.u_scale, wy * ldesc.v_scale),
                                            _ => (wx * ldesc.u_scale, wz * ldesc.v_scale),
                                        };
                                        let c = dtex.sample_uv(tu, tv);
                                        let tr = ((c >> 16) & 0xFF) as f32;
                                        let tg = ((c >> 8) & 0xFF) as f32;
                                        let tb = (c & 0xFF) as f32;
                                        r_acc += (tr - r_acc) * alpha;
                                        g_acc += (tg - g_acc) * alpha;
                                        b_acc += (tb - b_acc) * alpha;
                                    }
                                }
                            }
                        }
                    }

                    // Apply `.t2lm` (day) / `.t2lm1` (night) DXT1 `MODULATE2X` (`* 2.0`) baked sunlight & shadow lightmap!
                    if let Some(Some(lm)) = lm_day_imgs.get(ai) {
                        let lc = lm.sample_uv_clamp(uf, vf);
                        let mut lr = (((lc >> 16) & 0xFF) as f32) * (2.0 / 255.0);
                        let mut lg = (((lc >> 8) & 0xFF) as f32) * (2.0 / 255.0);
                        let mut lb = ((lc & 0xFF) as f32) * (2.0 / 255.0);
                        if night_weight > 0.001 {
                            if let Some(Some(nlm)) = lm_night_imgs.get(ai) {
                                let nlc = nlm.sample_uv_clamp(uf, vf);
                                let nlr = (((nlc >> 16) & 0xFF) as f32) * (2.0 / 255.0);
                                let nlg = (((nlc >> 8) & 0xFF) as f32) * (2.0 / 255.0);
                                let nlb = ((nlc & 0xFF) as f32) * (2.0 / 255.0);
                                lr += (nlr - lr) * night_weight;
                                lg += (nlg - lg) * night_weight;
                                lb += (nlb - lb) * night_weight;
                            }
                        }
                        r_acc = (r_acc * lr).clamp(0.0, 255.0);
                        g_acc = (g_acc * lg).clamp(0.0, 255.0);
                        b_acc = (b_acc * lb).clamp(0.0, 255.0);
                    }

                    pixels[(py * area_tex_sz + px) as usize] = 0xFF00_0000
                        | ((r_acc as u32) << 16)
                        | ((g_acc as u32) << 8)
                        | (b_acc as u32);
                }
            }

            let tid = textures.len();
            textures.push(SurfaceImage::from_pixels_with_mips(
                area_tex_sz,
                area_tex_sz,
                pixels,
            ));
            tex_lookup.insert(format!("trn2_area_{}_{}", cache_tag, ai), tid);
            area_tex_ids.push(tid);
        }
    }

    // Build `16x16` terrain blocks (`16x16` cells = `17x17` vertices per `64m` block => `4.0m` grid, zero seams!)
    let blocks_per_side = 16usize;
    let step_cells = 2usize;
    let cells_per_block = ((hm.verts_per_side - 1) / blocks_per_side / step_cells).max(4);
    let mut out_blocks = Vec::with_capacity(blocks_per_side * blocks_per_side);

    for br in 0..blocks_per_side {
        for bc in 0..blocks_per_side {
            let ar = (br * area_grid) / blocks_per_side;
            let ac = (bc * area_grid) / blocks_per_side;
            let area_idx = ar * area_grid + ac;
            let tex_id = area_tex_ids[area_idx];

            let area_x0 = left + (ac as f32) * area_world_span_x;
            let area_z0 = top - (ar as f32) * area_world_span_z;

            let bx0 = left + (bc as f32) * (world_w / blocks_per_side as f32);
            let bz0 = top - (br as f32) * (world_l / blocks_per_side as f32);
            let bspan_x = world_w / blocks_per_side as f32;
            let bspan_z = world_l / blocks_per_side as f32;

            let vstride = cells_per_block + 1;
            let mut verts = Vec::with_capacity(vstride * vstride);
            let mut indices = Vec::with_capacity(cells_per_block * cells_per_block * 6);
            let mut aabb = Aabb::empty();

            for lz in 0..=cells_per_block {
                let tz = lz as f32 / cells_per_block as f32;
                let wz = bz0 - tz * bspan_z;
                let v_area = ((area_z0 - wz) / area_world_span_z).clamp(0.002, 0.998);
                for lx in 0..=cells_per_block {
                    let tx = lx as f32 / cells_per_block as f32;
                    let wx = bx0 + tx * bspan_x;
                    // Sample across `map.sample_world_height` on outer tile borders so adjacent `1024m` tiles stitch with 0.000m seam!
                    let on_border = (br == 0 && lz == 0)
                        || (br + 1 == blocks_per_side && lz == cells_per_block)
                        || (bc == 0 && lx == 0)
                        || (bc + 1 == blocks_per_side && lx == cells_per_block);
                    let wy = if on_border {
                        map.sample_world_height(wx, wz)
                    } else {
                        hm.sample_height(wx, wz)
                    };
                    let u_area = ((wx - area_x0) / area_world_span_x).clamp(0.002, 0.998);
                    aabb.expand_point(Vec3::new(wx, wy, wz));
                    verts.push(A3dLitVertex {
                        x: wx,
                        y: wy,
                        z: wz,
                        diffuse: 0xFFFF_FFFF,
                        u: u_area,
                        v: v_area,
                    });
                }
            }

            for lz in 0..cells_per_block {
                for lx in 0..cells_per_block {
                    let i0 = (lz * vstride + lx) as u16;
                    let i1 = i0 + 1;
                    let i2 = ((lz + 1) * vstride + lx) as u16;
                    let i3 = i2 + 1;
                    indices.extend_from_slice(&[i0, i1, i2, i1, i3, i2]);
                }
            }

            out_blocks.push(TerrainBlockDraw {
                sub_slot,
                area_idx,
                tex_id,
                world_aabb: aabb,
                verts,
                indices,
            });
        }
    }

    let splat = TerrainSubSplat {
        origin_x: left,
        origin_z_top: top,
        world_w,
        world_l,
        t2mk: t2mk.cloned(),
        lm_day: lm_day_imgs,
        lm_night: lm_night_imgs,
        night_weight,
    };

    (out_blocks, splat)
}

// ---------------------------------------------------------------------------
// AUIManager 2D Draw-List Builder (shared by D3D9 & CPU reference backend)
// ---------------------------------------------------------------------------

pub fn build_aui_draw_list(
    scene: &mut LoadedScene3D,
    vfs: &VirtualFileSystem,
    mgr: &AuiManager,
    ui: &AuiRuntime,
    screen_w: u32,
    screen_h: u32,
) -> (Vec<UiQuad2D>, Vec<UiText2D>) {
    let mut quads = Vec::new();
    let mut texts = Vec::new();
    let scale = AuiRuntime::compute_ui_scale(screen_w, screen_h);

    for dstate in &ui.dialog_order {
        if !dstate.visible {
            continue;
        }
        let Some(layout) = mgr.dialogs.get(&dstate.dialog_name) else {
            continue;
        };
        let (dx, dy, dw, dh) =
            ui.dialog_screen_rect(dstate, layout, screen_w as i32, screen_h as i32, scale);

        // Dialog frame (`AUIFrame` 9-slice or transparent BMP)
        emit_dialog_background(scene, vfs, layout, dx, dy, dw, dh, &mut quads);

        for ctrl in &layout.controls {
            if !ui.is_control_visible(&dstate.dialog_name, &ctrl.name) {
                continue;
            }
            let cx = dx + ((ctrl.x as f32) * scale).round() as i32;
            let cy = dy + ((ctrl.y as f32) * scale).round() as i32;
            let cw = ((ctrl.width as f32) * scale).round() as i32;
            let ch = ((ctrl.height as f32) * scale).round() as i32;

            let is_hovered = ui
                .hovered_control
                .as_ref()
                .map(|k| k.0 == dstate.dialog_name && k.1 == ctrl.name)
                .unwrap_or(false);
            let is_pressed = ui
                .pressed_control
                .as_ref()
                .map(|k| k.0 == dstate.dialog_name && k.1 == ctrl.name)
                .unwrap_or(false);
            let is_focused = ui
                .focused_edit
                .as_ref()
                .map(|k| k.0 == dstate.dialog_name && k.1 == ctrl.name)
                .unwrap_or(false);

            let label_str = ui
                .text_overrides
                .get(&(dstate.dialog_name.clone(), ctrl.name.clone()))
                .cloned()
                .unwrap_or_else(|| ctrl.resolved_text.trim_matches('"').to_string());

            match ctrl.kind {
                AuiControlKind::ImagePicture => {
                    if let Some(tid) = scene.ensure_ui_surface(vfs, &ctrl.tex_up) {
                        let n_frames = ctrl.sprite_frames.max(1);
                        let f_idx = if n_frames > 1 {
                            if ctrl.name.eq_ignore_ascii_case("Img_SystemTime") {
                                scene.day_phase_frame % n_frames
                            } else if ctrl.sprite_interval_ms > 0 {
                                ((scene.ui_anim_ms / (ctrl.sprite_interval_ms.max(25) as u64)) as u32)
                                    % n_frames
                            } else {
                                0
                            }
                        } else {
                            0
                        };
                        let v0 = f_idx as f32 / n_frames as f32;
                        let v1 = (f_idx + 1) as f32 / n_frames as f32;
                        emit_tex_quad(&mut quads, cx, cy, cw, ch, 0.0, v0, 1.0, v1, 0xFFFF_FFFF, Some(tid));
                    }
                }
                AuiControlKind::StillImageButton => {
                    let chosen_tex = if is_pressed && !ctrl.tex_down.is_empty() {
                        &ctrl.tex_down
                    } else if is_hovered && !ctrl.tex_hilite.is_empty() {
                        &ctrl.tex_hilite
                    } else {
                        &ctrl.tex_up
                    };
                    let tint = if is_hovered && !is_pressed {
                        0xFFFF_F4D8
                    } else {
                        0xFFFF_FFFF
                    };
                    if let Some(tid) = scene.ensure_ui_surface(vfs, chosen_tex) {
                        if ctrl.frame_mode != 0
                            && scene.textures[tid].width >= 6
                            && (scene.textures[tid].width as i32) + 8 < cw
                        {
                            emit_9slice_quad(scene, &mut quads, tid, cx, cy, cw, ch, tint);
                        } else {
                            emit_tex_quad(&mut quads, cx, cy, cw, ch, 0.0, 0.0, 1.0, 1.0, tint, Some(tid));
                        }
                    }
                    if !label_str.is_empty() {
                        let mut fsz = (((ctrl.font_size.max(9) as f32) * scale).round() as u32).max(10);
                        let mut tw = scene
                            .font_atlas
                            .measure_text_px(&mut scene.textures, &label_str, fsz);
                        while tw > cw - 4 && fsz > 9 {
                            fsz -= 1;
                            tw = scene
                                .font_atlas
                                .measure_text_px(&mut scene.textures, &label_str, fsz);
                        }
                        let tx = cx + (cw - tw) / 2 + i32::from(is_pressed);
                        let ty = cy + (ch - fsz as i32) / 2 + i32::from(is_pressed);
                        texts.push(UiText2D {
                            x: tx,
                            y: ty,
                            size_px: fsz,
                            color: ctrl.text_color,
                            text: label_str,
                            shadow: true,
                            clip_rect: Some((cx, cy, cw, ch)),
                        });
                    }
                }
                AuiControlKind::EditBox => {
                    if let Some(tid) = scene.ensure_ui_surface(vfs, &ctrl.tex_up) {
                        if ctrl.frame_mode != 0 && scene.textures[tid].width >= 6 && ctrl.name != "Img_Title" {
                            emit_9slice_quad(scene, &mut quads, tid, cx, cy, cw, ch, 0xFFFF_FFFF);
                        } else {
                            emit_tex_quad(&mut quads, cx, cy, cw, ch, 0.0, 0.0, 1.0, 1.0, 0xFFFF_FFFF, Some(tid));
                        }
                    }
                    if !ctrl.read_only {
                        if is_focused {
                            emit_tex_quad(&mut quads, cx, cy + ch - 2, cw, 2, 0.0, 0.0, 1.0, 1.0, 0xCCFF_CB4A, None);
                        }
                        let raw_val = ui.get_edit_text(&dstate.dialog_name, &ctrl.name);
                        let disp = if ctrl.is_password {
                            "*".repeat(raw_val.chars().count())
                        } else {
                            raw_val.to_string()
                        };
                        let with_caret = if is_focused {
                            format!("{disp}|")
                        } else {
                            disp
                        };
                        if !with_caret.is_empty() {
                            let fsz = (((ctrl.font_size.max(10) as f32) * scale).round() as u32).max(11);
                            texts.push(UiText2D {
                                x: cx + 5,
                                y: cy + (ch - fsz as i32) / 2,
                                size_px: fsz,
                                color: ctrl.text_color | 0xFF00_0000,
                                text: with_caret,
                                shadow: true,
                                clip_rect: Some((cx + 2, cy, (cw - 4).max(4), ch)),
                            });
                        }
                    }
                }
                AuiControlKind::Label | AuiControlKind::TextArea => {
                    if ctrl.kind == AuiControlKind::TextArea
                        && !ctrl.tex_up.is_empty()
                        && !ctrl.tex_up.contains("透明色")
                    {
                        if let Some(tid) = scene.ensure_ui_surface(vfs, &ctrl.tex_up) {
                            if scene.textures[tid].width >= 6 {
                                emit_9slice_quad(scene, &mut quads, tid, cx, cy, cw, ch, 0xE8FF_FFFF);
                            } else {
                                emit_tex_quad(&mut quads, cx, cy, cw, ch, 0.0, 0.0, 1.0, 1.0, 0xE8FF_FFFF, Some(tid));
                            }
                        }
                    }
                    if !label_str.is_empty() {
                        let fsz = (((ctrl.font_size.max(9) as f32) * scale).round() as u32).max(11);
                        let is_multiline = ctrl.kind == AuiControlKind::TextArea
                            || label_str.contains('\n')
                            || label_str.contains("\\r")
                            || (ctrl.width >= 90 && ctrl.height >= (ctrl.font_size.max(9) as i32) * 2);
                        if is_multiline {
                            let is_chat_box = ctrl.name.eq_ignore_ascii_case("Txt_Content")
                                && dstate.dialog_name.to_ascii_lowercase().contains("chat");
                            let pad = if is_chat_box { 2 } else { 5 };
                            let clip = Some((cx, cy, cw.max(12), ch.max(12)));
                            let max_w = (cw - pad * 2 - 4).max(32);
                            let line_step = (fsz as i32) + 3;
                            let wrapped = scene
                                .font_atlas
                                .wrap_text_lines(&mut scene.textures, &label_str, fsz, max_w);
                            let max_vis_lines = ((ch.max(line_step) - pad) / line_step).max(1) as usize;
                            let slice = if is_chat_box && wrapped.len() > max_vis_lines {
                                &wrapped[wrapped.len() - max_vis_lines..]
                            } else {
                                &wrapped[..wrapped.len().min(max_vis_lines)]
                            };
                            let mut cur_y = if is_chat_box {
                                // Bottom-anchor chat lines inside `Win_Chat` right above `Pic_BG`, matching `real_12_inworld_hud.png`!
                                (cy + ch - (slice.len() as i32) * line_step).max(cy)
                            } else {
                                cy + pad
                            };
                            for wline in slice {
                                texts.push(UiText2D {
                                    x: cx + pad,
                                    y: cur_y,
                                    size_px: fsz,
                                    color: ctrl.text_color,
                                    text: wline.clone(),
                                    shadow: true,
                                    clip_rect: clip,
                                });
                                cur_y += line_step;
                            }
                        } else {
                            let mut fit_fsz = (((ctrl.font_size.max(9) as f32) * scale).round() as u32).max(10);
                            if cw > 14 {
                                let mut cur_w = scene.font_atlas.measure_text_px(
                                    &mut scene.textures,
                                    &label_str,
                                    fit_fsz,
                                );
                                while cur_w > cw + 6 && fit_fsz > 9 {
                                    fit_fsz -= 1;
                                    cur_w = scene.font_atlas.measure_text_px(
                                        &mut scene.textures,
                                        &label_str,
                                        fit_fsz,
                                    );
                                }
                            }
                            let is_centered_point_lbl = ctrl.width == 0
                                && ctrl.height == 0
                                && ((ctrl.x - layout.width / 2).abs() <= 45
                                    || ctrl.name.eq_ignore_ascii_case("Txt_ItemName"));
                            let tx = if is_centered_point_lbl {
                                let tw = scene.font_atlas.measure_text_px(
                                    &mut scene.textures,
                                    &label_str,
                                    fit_fsz,
                                );
                                cx - tw / 2
                            } else {
                                cx
                            };
                            texts.push(UiText2D {
                                x: tx,
                                y: cy,
                                size_px: fit_fsz,
                                color: ctrl.text_color,
                                text: label_str,
                                shadow: true,
                                clip_rect: None,
                            });
                        }
                    }
                }
                AuiControlKind::CheckBox => {
                    let checked = ui
                        .check_states
                        .get(&(dstate.dialog_name.clone(), ctrl.name.clone()))
                        .copied()
                        .unwrap_or(false);
                    let chosen = if checked && !ctrl.tex_down.is_empty() {
                        &ctrl.tex_down
                    } else {
                        &ctrl.tex_up
                    };
                    if let Some(tid) = scene.ensure_ui_surface(vfs, chosen) {
                        let img = &scene.textures[tid];
                        // `Extra\复选框_标准.tga` (`18x54`) & `复选框_1.tga` (`16x48`) have 3 vertical frames:
                        // `[0 = Unchecked, 1 = Checked, 2 = Disabled/Hover]`.
                        let n_frames = (img.height / img.width.max(1)).max(1);
                        if ctrl.tex_down.is_empty() && n_frames >= 2 {
                            let slice = if checked { 1 } else { 0 };
                            let v0 = slice as f32 / (n_frames as f32);
                            let v1 = (slice + 1) as f32 / (n_frames as f32);
                            emit_tex_quad(&mut quads, cx, cy, cw, ch, 0.0, v0, 1.0, v1, 0xFFFF_FFFF, Some(tid));
                        } else {
                            emit_tex_quad(&mut quads, cx, cy, cw, ch, 0.0, 0.0, 1.0, 1.0, 0xFFFF_FFFF, Some(tid));
                        }
                    }
                    if !label_str.is_empty() {
                        let fsz = (((ctrl.font_size.max(9) as f32) * scale).round() as u32).max(11);
                        texts.push(UiText2D {
                            x: cx + ch + 4,
                            y: cy + (ch - fsz as i32) / 2,
                            size_px: fsz,
                            color: ctrl.text_color,
                            text: label_str,
                            shadow: true,
                            clip_rect: None,
                        });
                    }
                }
                AuiControlKind::RadioButton => {
                    let sel_btn = ui
                        .radio_groups
                        .get(&(dstate.dialog_name.clone(), ctrl.radio_group_id))
                        .copied()
                        .unwrap_or(-1);
                    let is_checked = sel_btn == ctrl.radio_button_id;
                    if let Some(tid) = scene.ensure_ui_surface(vfs, &ctrl.tex_up) {
                        let img = &scene.textures[tid];
                        // `Extra\单选框_标准.tga` (`22x66`) & `Extra\复选框_角色.tga` (`141x135`) have 3 vertical slices:
                        // `[0 = Unchecked, 1 = Checked/Selected, 2 = Disabled]` (`AUIRadioButton`).
                        let ref_h = (ctrl.height.max(1) as u32).max(12);
                        let n_frames = (img.height / ref_h).clamp(1, 4);
                        if ctrl.tex_down.is_empty() && n_frames >= 2 {
                            let slice = if is_checked || is_hovered { 1 } else { 0 };
                            let v0 = slice as f32 / (n_frames as f32);
                            let v1 = (slice + 1) as f32 / (n_frames as f32);
                            emit_tex_quad(&mut quads, cx, cy, cw, ch, 0.0, v0, 1.0, v1, 0xFFFF_FFFF, Some(tid));
                        } else {
                            let use_tid = if is_checked && !ctrl.tex_down.is_empty() {
                                scene.ensure_ui_surface(vfs, &ctrl.tex_down).unwrap_or(tid)
                            } else {
                                tid
                            };
                            emit_tex_quad(&mut quads, cx, cy, cw, ch, 0.0, 0.0, 1.0, 1.0, 0xFFFF_FFFF, Some(use_tid));
                        }
                    }
                }
                AuiControlKind::ComboBox => {
                    if let Some(tid) = scene.ensure_ui_surface(vfs, &ctrl.tex_up) {
                        if scene.textures[tid].width >= 6 {
                            emit_9slice_quad(scene, &mut quads, tid, cx, cy, cw, ch, 0xFFFF_FFFF);
                        } else {
                            emit_tex_quad(&mut quads, cx, cy, cw, ch, 0.0, 0.0, 1.0, 1.0, 0xFFFF_FFFF, Some(tid));
                        }
                    }
                    let key = (dstate.dialog_name.clone(), ctrl.name.clone());
                    let val = ui
                        .list_items
                        .get(&key)
                        .and_then(|items| {
                            let idx = ui.list_selected.get(&key).copied().unwrap_or(0);
                            items.get(idx)
                        })
                        .cloned()
                        .unwrap_or(label_str);
                    if !val.is_empty() {
                        let fsz = (((ctrl.font_size.max(9) as f32) * scale).round() as u32).max(11);
                        texts.push(UiText2D {
                            x: cx + 6,
                            y: cy + (ch - fsz as i32) / 2,
                            size_px: fsz,
                            color: ctrl.text_color,
                            text: val,
                            shadow: true,
                            clip_rect: Some((cx, cy, cw, ch)),
                        });
                    }
                }
                AuiControlKind::ListBox | AuiControlKind::TreeView => {
                    let is_tree = ctrl.kind == AuiControlKind::TreeView;
                    if !ctrl.tex_up.is_empty() && !ctrl.tex_up.contains("透明色") {
                        if let Some(tid) = scene.ensure_ui_surface(vfs, &ctrl.tex_up) {
                            if scene.textures[tid].width >= 6 {
                                emit_9slice_quad(scene, &mut quads, tid, cx, cy, cw, ch, 0xE8FF_FFFF);
                            } else {
                                emit_tex_quad(&mut quads, cx, cy, cw, ch, 0.0, 0.0, 1.0, 1.0, 0xE8FF_FFFF, Some(tid));
                            }
                        }
                    }
                    let key = (dstate.dialog_name.clone(), ctrl.name.clone());
                    if let Some(items) = ui.list_items.get(&key) {
                        let sel = ui.list_selected.get(&key).copied().unwrap_or(0);
                        let row_h = (20.0 * scale).max(15.0) as i32;
                        let fsz = (((ctrl.font_size.max(9) as f32) * scale).round() as u32).max(11);
                        let hilite_tid = scene.ensure_ui_surface(vfs, &ctrl.tex_hilite);
                        for (ri, item) in items.iter().enumerate() {
                            let ry = cy + 4 + (ri as i32) * row_h;
                            if ry + row_h > cy + ch {
                                break;
                            }
                            if ri == sel {
                                emit_tex_quad(
                                    &mut quads,
                                    cx + 3,
                                    ry,
                                    cw - 6,
                                    row_h - 1,
                                    0.0,
                                    0.0,
                                    1.0,
                                    1.0,
                                    0xCC48_78B8,
                                    hilite_tid,
                                );
                            }
                            let is_hdr = is_tree && (item.starts_with("[-]") || item.starts_with("[+]"));
                            let indent = if is_tree && !is_hdr && item.starts_with("  ") { 10 } else { 6 };
                            let col = if ri == sel {
                                0xFFFF_E484
                            } else if is_hdr {
                                0xFFFF_CB4A
                            } else {
                                ctrl.text_color
                            };
                            texts.push(UiText2D {
                                x: cx + indent,
                                y: ry + 2,
                                size_px: fsz,
                                color: col,
                                text: item.clone(),
                                shadow: true,
                                clip_rect: Some((cx + 2, cy + 2, (cw - 4).max(8), (ch - 4).max(8))),
                            });
                        }
                    }
                }
                AuiControlKind::Slider => {
                    let (cur_lv, max_lv) =
                        ui.get_slider(&dstate.dialog_name, &ctrl.name, ctrl.slider_max);
                    let frac = (cur_lv as f32 / (max_lv.max(1) as f32)).clamp(0.0, 1.0);
                    let track_h = (ch / 2).clamp(4, 10);
                    let track_y = cy + (ch - track_h) / 2;
                    if let Some(ttid) = scene.ensure_ui_surface(vfs, &ctrl.tex_up) {
                        if scene.textures[ttid].width >= 6 {
                            emit_9slice_quad(scene, &mut quads, ttid, cx, track_y, cw, track_h, 0xFFFF_FFFF);
                        } else {
                            emit_tex_quad(&mut quads, cx, track_y, cw, track_h, 0.0, 0.0, 1.0, 1.0, 0xFFFF_FFFF, Some(ttid));
                        }
                    } else {
                        emit_tex_quad(&mut quads, cx, track_y, cw, track_h, 0.0, 0.0, 1.0, 1.0, 0xD024_2834, None);
                    }
                    let fill_w = ((cw as f32) * frac).round() as i32;
                    if fill_w > 2 {
                        emit_tex_quad(
                            &mut quads,
                            cx + 1,
                            track_y + 1,
                            (fill_w - 2).max(1),
                            (track_h - 2).max(2),
                            0.0,
                            0.0,
                            1.0,
                            1.0,
                            0xB8C8_9A42,
                            None,
                        );
                    }
                    if let Some(btid) = scene.ensure_ui_surface(vfs, &ctrl.tex_down) {
                        let bw = (scene.textures[btid].width as i32).clamp(8, 20);
                        let bh = (scene.textures[btid].height as i32).clamp(10, ch.max(12));
                        let bx = cx + (((cw - bw).max(0) as f32) * frac).round() as i32;
                        let by = cy + (ch - bh) / 2;
                        emit_tex_quad(&mut quads, bx, by, bw, bh, 0.0, 0.0, 1.0, 1.0, 0xFFFF_FFFF, Some(btid));
                    }
                }
                AuiControlKind::Scroll => {
                    if let Some(ttid) = scene.ensure_ui_surface(vfs, &ctrl.tex_up) {
                        emit_tex_quad(&mut quads, cx, cy, cw, ch, 0.0, 0.0, 1.0, 1.0, 0xD8FF_FFFF, Some(ttid));
                    }
                    if let Some(btid) = scene.ensure_ui_surface(vfs, &ctrl.tex_down) {
                        let bh = (ch / 3).clamp(12, 36);
                        emit_tex_quad(&mut quads, cx, cy + 12, cw, bh, 0.0, 0.0, 1.0, 1.0, 0xFFFF_FFFF, Some(btid));
                    }
                }
                AuiControlKind::Progress => {
                    if let Some(tid) = scene.ensure_ui_surface(vfs, &ctrl.tex_up) {
                        emit_tex_quad(&mut quads, cx, cy, cw, ch, 0.0, 0.0, 1.0, 1.0, 0xFFFF_FFFF, Some(tid));
                    }
                    let frac = ui
                        .progress_values
                        .get(&(dstate.dialog_name.clone(), ctrl.name.clone()))
                        .copied()
                        .unwrap_or(1.0)
                        .clamp(0.0, 1.0);
                    let (ml, mt, mr, mb) = ctrl.progress_margins;
                    let inner_w = (cw - ml - mr).max(1);
                    let inner_h = (ch - mt - mb).max(1);
                    let fw = ((inner_w as f32) * frac).round() as i32;
                    if fw > 0 {
                        if let Some(ftid) = scene.ensure_ui_surface(vfs, &ctrl.tex_down) {
                            emit_tex_quad(
                                &mut quads,
                                cx + ml,
                                cy + mt,
                                fw,
                                inner_h,
                                0.0,
                                0.0,
                                frac,
                                1.0,
                                0xFFFF_FFFF,
                                Some(ftid),
                            );
                        }
                    }
                }
                _ => {}
            }
        }

        // Dialog-level title text (`m_szText` resolved from `title_stf_id`) & right-aligned close button (`m_pA2DSpriteClose`)!
        if !layout.resolved_title.is_empty() {
            let already_has_title_lbl = layout.controls.iter().any(|c| {
                c.kind == AuiControlKind::Label
                    && c.y <= 45
                    && c.resolved_text
                        .trim_matches('"')
                        .eq_ignore_ascii_case(layout.resolved_title.trim_matches('"'))
            });
            if !already_has_title_lbl {
                let title_str = layout.resolved_title.trim_matches('"').to_string();
                let fsz = (((layout.font_size.max(10) as f32) * scale).round() as u32).max(12);
                let tw = scene
                    .font_atlas
                    .measure_text_px(&mut scene.textures, &title_str, fsz);
                let title_y = if let Some(img_t) =
                    layout.controls.iter().find(|c| c.name.eq_ignore_ascii_case("Img_Title"))
                {
                    dy + (((img_t.y + (img_t.height - fsz as i32) / 2) as f32) * scale).round()
                        as i32
                } else if layout.title_rect.3 > 0 {
                    dy + (((layout.title_rect.1 + (layout.title_rect.3 - fsz as i32) / 2) as f32)
                        * scale)
                        .round() as i32
                } else {
                    dy + (8.0 * scale).round() as i32
                };
                texts.push(UiText2D {
                    x: dx + (dw - tw) / 2,
                    y: title_y,
                    size_px: fsz,
                    color: 0xFFFF_E8B0,
                    text: title_str,
                    shadow: true,
                    clip_rect: Some((dx, dy, dw, dh)),
                });
            }
        }

        if !layout.close_texture.is_empty() && layout.close_pos.0 > 0 {
            if let Some(ctid) = scene.ensure_ui_surface(vfs, &layout.close_texture) {
                let cimg_w = scene.textures[ctid].width.max(16) as i32;
                let cimg_h = scene.textures[ctid].height.max(16) as i32;
                let frames = if cimg_h >= cimg_w * 3 { 3 } else { 1 };
                let is_hov = ui
                    .hovered_control
                    .as_ref()
                    .map(|k| k.0 == dstate.dialog_name && k.1 == "__DLG_CLOSE__")
                    .unwrap_or(false);
                let is_prs = ui
                    .pressed_control
                    .as_ref()
                    .map(|k| k.0 == dstate.dialog_name && k.1 == "__DLG_CLOSE__")
                    .unwrap_or(false);
                let frame_idx = if frames == 3 {
                    if is_prs {
                        1
                    } else if is_hov {
                        2
                    } else {
                        0
                    }
                } else {
                    0
                };
                let v0 = frame_idx as f32 / frames as f32;
                let v1 = (frame_idx + 1) as f32 / frames as f32;
                let btn_w = ((cimg_w as f32) * scale).round() as i32;
                let btn_h = (((cimg_h / frames) as f32) * scale).round() as i32;
                let cl_x = dx + dw - ((layout.close_pos.0 as f32) * scale).round() as i32;
                let cl_y = dy + ((layout.close_pos.1 as f32) * scale).round() as i32;
                emit_tex_quad(
                    &mut quads,
                    cl_x,
                    cl_y,
                    btn_w,
                    btn_h,
                    0.0,
                    v0,
                    1.0,
                    v1,
                    0xFFFF_FFFF,
                    Some(ctid),
                );
            }
        }
    }

    (quads, texts)
}

/// Emits the floating `.htf` / Item / Skill Hover Tooltip (`AUIManager::RenderHint` using `Hint\InGameHintFrame.dds`)
/// as the topmost UI layer above all dialog frames and slot icons.
pub fn emit_aui_hover_tooltip(
    scene: &mut LoadedScene3D,
    vfs: &VirtualFileSystem,
    mgr: &AuiManager,
    ui: &AuiRuntime,
    screen_w: u32,
    screen_h: u32,
    quads: &mut Vec<UiQuad2D>,
    texts: &mut Vec<UiText2D>,
) {
    if ui.mouse_x > 0 || ui.mouse_y > 0 {
        if let Some(raw_hint) = ui.active_hover_hint(mgr) {
            emit_hover_tooltip(
                scene,
                vfs,
                &raw_hint,
                ui.mouse_x,
                ui.mouse_y,
                screen_w as i32,
                screen_h as i32,
                quads,
                texts,
            );
        }
    }
}

/// Strips Angelica `^RRGGBB` inline hex color tags while returning `(line_color, plain_line)` per line.
fn parse_aui_hint_lines(raw: &str) -> Vec<(u32, String)> {
    let normalized = raw.replace("\\r", "\n");
    let mut out = Vec::new();
    let mut cur_col = 0xFFFF_FFFFu32;
    for line in normalized.lines() {
        let mut plain = String::new();
        let mut line_col: Option<u32> = None;
        let chars: Vec<char> = line.chars().collect();
        let mut i = 0usize;
        while i < chars.len() {
            if chars[i] == '^' && i + 6 < chars.len() {
                let hex: String = chars[i + 1..i + 7].iter().collect();
                if let Ok(rgb) = u32::from_str_radix(&hex, 16) {
                    cur_col = 0xFF00_0000 | rgb;
                    if line_col.is_none() {
                        line_col = Some(cur_col);
                    }
                    i += 7;
                    continue;
                }
            }
            plain.push(chars[i]);
            i += 1;
        }
        if !plain.trim().is_empty() {
            out.push((line_col.unwrap_or(cur_col), plain));
        }
    }
    out
}

#[allow(clippy::too_many_arguments)]
fn emit_hover_tooltip(
    scene: &mut LoadedScene3D,
    vfs: &VirtualFileSystem,
    raw_hint: &str,
    mx: i32,
    my: i32,
    screen_w: i32,
    screen_h: i32,
    quads: &mut Vec<UiQuad2D>,
    texts: &mut Vec<UiText2D>,
) {
    let lines = parse_aui_hint_lines(raw_hint);
    if lines.is_empty() {
        return;
    }
    let fsz = 12u32;
    let line_h = 16i32;
    let mut max_w = 64i32;
    for (_, s) in &lines {
        let w = scene.font_atlas.measure_text_px(&mut scene.textures, s, fsz);
        if w > max_w {
            max_w = w;
        }
    }
    let pad_x = 10i32;
    let pad_y = 8i32;
    let box_w = (max_w + pad_x * 2).min(screen_w - 16);
    let box_h = (lines.len() as i32) * line_h + pad_y * 2;
    let mut bx = mx + 16;
    let mut by = my + 18;
    if bx + box_w > screen_w - 6 {
        bx = (mx - box_w - 8).max(6);
    }
    if by + box_h > screen_h - 6 {
        by = (my - box_h - 8).max(6);
    }

    if let Some(htid) = scene.ensure_ui_surface(vfs, "Hint\\InGameHintFrame.dds") {
        emit_9slice_quad(scene, quads, htid, bx, by, box_w, box_h, 0xEEFF_FFFF);
    } else {
        emit_tex_quad(quads, bx, by, box_w, box_h, 0.0, 0.0, 1.0, 1.0, 0xE610_141E, None);
        emit_tex_quad(quads, bx, by, box_w, 1, 0.0, 0.0, 1.0, 1.0, 0xFFD4_A854, None);
        emit_tex_quad(quads, bx, by + box_h - 1, box_w, 1, 0.0, 0.0, 1.0, 1.0, 0xFFD4_A854, None);
    }
    for (idx, (col, s)) in lines.iter().enumerate() {
        texts.push(UiText2D {
            x: bx + pad_x,
            y: by + pad_y + (idx as i32) * line_h,
            size_px: fsz,
            color: *col,
            text: s.clone(),
            shadow: true,
            clip_rect: Some((bx + 2, by + 2, box_w - 4, box_h - 4)),
        });
    }
}

/// Emits the authentic `cursors\normal.ani` / `hand.cur` / `attack.cur` / `talk.cur` hardware-accurate cursor sprite.
pub fn emit_software_cursor_quad(
    scene: &LoadedScene3D,
    mx: i32,
    my: i32,
    quads: &mut Vec<UiQuad2D>,
) {
    if !scene.show_software_cursor || (mx <= 0 && my <= 0) {
        return;
    }
    let entry = scene
        .cursors
        .get(&scene.active_cursor)
        .or_else(|| scene.cursors.get("normal"));
    if let Some((hx, hy, jiffies, fids)) = entry {
        if !fids.is_empty() {
            let step_ms = (*jiffies as u64 * 1000 / 60).max(50);
            let fidx = ((scene.ui_anim_ms / step_ms) as usize) % fids.len();
            let tid = fids[fidx];
            let w = scene.textures[tid].width as i32;
            let h = scene.textures[tid].height as i32;
            emit_tex_quad(
                quads,
                mx - *hx,
                my - *hy,
                w,
                h,
                0.0,
                0.0,
                1.0,
                1.0,
                0xFFFF_FFFF,
                Some(tid),
            );
        }
    }
}

fn emit_dialog_background(
    scene: &mut LoadedScene3D,
    vfs: &VirtualFileSystem,
    layout: &AuiDialogLayout,
    dx: i32,
    dy: i32,
    dw: i32,
    dh: i32,
    quads: &mut Vec<UiQuad2D>,
) {
    let dlg_alpha = ((layout.bg_color >> 24) & 0xFF).max(216);
    let tint = (dlg_alpha << 24) | 0x00FF_FFFF;
    if !layout.bg_texture.is_empty() && !layout.bg_texture.contains("对话框_透明色") {
        if let Some(btid) = scene.ensure_ui_surface(vfs, &layout.bg_texture) {
            emit_tex_quad(quads, dx + 4, dy + 4, dw - 8, dh - 8, 0.0, 0.0, 1.0, 1.0, tint, Some(btid));
        }
    }
    if !layout.frame_texture.is_empty() && !layout.frame_texture.contains("对话框_透明色") {
        if let Some(tid) = scene.ensure_ui_surface(vfs, &layout.frame_texture) {
            if scene.textures[tid].width >= 24 {
                emit_9slice_quad(scene, quads, tid, dx, dy, dw, dh, tint);
            } else {
                emit_tex_quad(quads, dx, dy, dw, dh, 0.0, 0.0, 1.0, 1.0, tint, Some(tid));
            }
        }
    }
    if !layout.title_texture.is_empty() && !layout.title_texture.contains("对话框_透明色") {
        if let Some(ttid) = scene.ensure_ui_surface(vfs, &layout.title_texture) {
            let tw = if layout.title_rect.2 > 0 {
                layout.title_rect.2
            } else {
                scene.textures[ttid].width as i32
            };
            let th = if layout.title_rect.3 > 0 {
                layout.title_rect.3
            } else {
                scene.textures[ttid].height as i32
            };
            emit_tex_quad(
                quads,
                dx + layout.title_rect.0,
                dy + layout.title_rect.1,
                tw,
                th,
                0.0,
                0.0,
                1.0,
                1.0,
                0xFFFF_FFFF,
                Some(ttid),
            );
        }
    }
}

fn emit_9slice_quad(
    scene: &LoadedScene3D,
    quads: &mut Vec<UiQuad2D>,
    tid: usize,
    x: i32,
    y: i32,
    w: i32,
    h: i32,
    color: u32,
) {
    let img = &scene.textures[tid];
    let src_cw = (img.width / 4).clamp(2, 32) as i32;
    let src_ch = (img.height / 4).clamp(2, 32) as i32;
    let cw = src_cw.min((w / 3).max(2));
    let ch = src_ch.min((h / 3).max(2));
    let xs = [x, x + cw, (x + w - cw).max(x + cw), x + w];
    let ys = [y, y + ch, (y + h - ch).max(y + ch), y + h];
    let ub = (src_cw as f32 / img.width.max(1) as f32).clamp(0.05, 0.45);
    let vb = (src_ch as f32 / img.height.max(1) as f32).clamp(0.05, 0.45);
    let us = [0.0f32, ub, 1.0 - ub, 1.0];
    let vs = [0.0f32, vb, 1.0 - vb, 1.0];
    for ry in 0..3 {
        for rx in 0..3 {
            let sw = xs[rx + 1] - xs[rx];
            let sh = ys[ry + 1] - ys[ry];
            if sw > 0 && sh > 0 {
                emit_tex_quad(
                    quads,
                    xs[rx],
                    ys[ry],
                    sw,
                    sh,
                    us[rx],
                    vs[ry],
                    us[rx + 1],
                    vs[ry + 1],
                    color,
                    Some(tid),
                );
            }
        }
    }
}

#[allow(clippy::too_many_arguments)]
fn emit_tex_quad(
    quads: &mut Vec<UiQuad2D>,
    x: i32,
    y: i32,
    w: i32,
    h: i32,
    u0: f32,
    v0: f32,
    u1: f32,
    v1: f32,
    color: u32,
    tex_id: Option<usize>,
) {
    if w <= 0 || h <= 0 {
        return;
    }
    quads.push(UiQuad2D {
        x0: x as f32,
        y0: y as f32,
        x1: (x + w) as f32,
        y1: (y + h) as f32,
        u0,
        v0,
        u1,
        v1,
        color,
        tex_id,
        clip_rect: None,
    });
}

/// Projects a 3D world point to `(screen_x, screen_y, dist)` for floating nameplates & combat numbers.
pub fn project_world_to_screen(
    eye: Vec3,
    dir: Vec3,
    up: Vec3,
    cam_proj: &A3DCamera,
    screen_w: u32,
    screen_h: u32,
    world_pt: Vec3,
) -> Option<(i32, i32, f32)> {
    let aspect = (screen_w.max(1) as f32) / (screen_h.max(1) as f32);
    let view = Mat4::look_to_lh(eye, dir, up);
    let proj = Mat4::perspective_fov_lh(
        cam_proj.fov_degrees.to_radians(),
        aspect,
        cam_proj.near_clip.max(0.25),
        cam_proj.far_clip.max(1100.0),
    );
    let c = view.mul(proj).transform_vec4(world_pt);
    if c[3] <= 0.35 {
        return None;
    }
    let inv_w = 1.0 / c[3];
    let ndc_x = c[0] * inv_w;
    let ndc_y = c[1] * inv_w;
    if !(-1.15..=1.15).contains(&ndc_x) || !(-1.15..=1.15).contains(&ndc_y) {
        return None;
    }
    let sx = ((ndc_x * 0.5 + 0.5) * (screen_w as f32)).round() as i32;
    let sy = ((0.5 - ndc_y * 0.5) * (screen_h as f32)).round() as i32;
    Some((sx, sy, world_pt.sub(eye).length()))
}

/// Pushes an axis-aligned box (6 faces x 4 verts) into `verts`/`indices` with per-face
/// sun-berthed diffuse shading (`0xAARRGGBB`). Used by the procedural avatar fallbacks.
fn push_box(
    verts: &mut Vec<A3dLitVertex>,
    indices: &mut Vec<u16>,
    min: Vec3,
    max: Vec3,
    color: u32,
    sun_dir: Vec3,
) {
    let sun = sun_dir.normalized();
    let shade = |nx: f32, ny: f32, nz: f32| -> u32 {
        let n = Vec3::new(nx, ny, nz).normalized();
        let l = (n.x * sun.x + n.y * sun.y + n.z * sun.z).max(0.0);
        let f = 0.55 + 0.45 * l;
        let r = (((color >> 16) & 0xFF) as f32 * f).clamp(0.0, 255.0) as u32;
        let g = (((color >> 8) & 0xFF) as f32 * f).clamp(0.0, 255.0) as u32;
        let b = ((color & 0xFF) as f32 * f).clamp(0.0, 255.0) as u32;
        0xFF00_0000 | (r << 16) | (g << 8) | b
    };
    // (normal, 4 corners CCW seen from outside)
    let faces: [([f32; 3], [[f32; 3]; 4]); 6] = [
        ([1.0, 0.0, 0.0], [[max.x, min.y, min.z], [max.x, min.y, max.z], [max.x, max.y, max.z], [max.x, max.y, min.z]]),
        ([-1.0, 0.0, 0.0], [[min.x, min.y, max.z], [min.x, min.y, min.z], [min.x, max.y, min.z], [min.x, max.y, max.z]]),
        ([0.0, 1.0, 0.0], [[min.x, max.y, min.z], [max.x, max.y, min.z], [max.x, max.y, max.z], [min.x, max.y, max.z]]),
        ([0.0, -1.0, 0.0], [[min.x, min.y, max.z], [max.x, min.y, max.z], [max.x, min.y, min.z], [min.x, min.y, min.z]]),
        ([0.0, 0.0, 1.0], [[max.x, min.y, max.z], [min.x, min.y, max.z], [min.x, max.y, max.z], [max.x, max.y, max.z]]),
        ([0.0, 0.0, -1.0], [[min.x, min.y, min.z], [max.x, min.y, min.z], [max.x, max.y, min.z], [min.x, max.y, min.z]]),
    ];
    for (n, corners) in faces {
        let base = verts.len() as u16;
        let c = shade(n[0], n[1], n[2]);
        for [x, y, z] in corners {
            verts.push(A3dLitVertex { x, y, z, diffuse: c, u: 0.5, v: 0.5 });
        }
        indices.extend_from_slice(&[base, base + 1, base + 2, base, base + 2, base + 3]);
    }
}

/// Per-class armor tint for the procedural fallback avatar (Perfect World 8 classes).
fn class_armor_tint(cls: i32, gender: u8) -> u32 {
    let base = match cls {
        0 => 0xFFC8_4030u32, // Blademaster - red
        1 => 0xFF3A_5F_C8, // Wizard - blue
        2 => 0xFFD8_C8_6A, // Cleric - gold
        3 => 0xFF4A_A0_50, // Venomancer - green
        4 => 0xFFB0_6A_30, // Barbarian - orange
        5 => 0xFF6A_4A_90, // Assassin - purple
        6 => 0xFF50_A0_60, // Archer - forest green
        _ => 0xFF7A_C8_E0, // Hierophant - cyan
    };
    if gender & 1 == 1 {
        let r = (((base >> 16) & 0xFF) * 220 / 255) << 16;
        let g = (((base >> 8) & 0xFF) * 220 / 255) << 8;
        let b = ((base & 0xFF) * 220 / 255) & 0xFF;
        0xFF00_0000 | r | g | b
    } else {
        base
    }
}

/// Builds a simple humanoid (~1.78m tall, origin at feet, facing +Z) used when the real
/// `.ski` body from `models.pck` is unavailable: legs, torso, arms in `armor`, head/neck in
/// `skin`. Real `facedata.pck` face/hair submeshes still attach on top at neck height.
fn build_procedural_humanoid_batch(skin: u32, armor: u32, pants: u32) -> GpuMeshBatch {
    let sun = Vec3::new(-0.35, 0.78, -0.52);
    let mut verts = Vec::with_capacity(24 * 7);
    let mut indices = Vec::with_capacity(36 * 7);
    // legs
    push_box(&mut verts, &mut indices, Vec3::new(-0.20, 0.0, -0.10), Vec3::new(-0.03, 0.92, 0.10), pants, sun);
    push_box(&mut verts, &mut indices, Vec3::new(0.03, 0.0, -0.10), Vec3::new(0.20, 0.92, 0.10), pants, sun);
    // torso
    push_box(&mut verts, &mut indices, Vec3::new(-0.23, 0.92, -0.13), Vec3::new(0.23, 1.48, 0.13), armor, sun);
    // arms
    push_box(&mut verts, &mut indices, Vec3::new(-0.37, 0.98, -0.08), Vec3::new(-0.24, 1.46, 0.08), armor, sun);
    push_box(&mut verts, &mut indices, Vec3::new(0.24, 0.98, -0.08), Vec3::new(0.37, 1.46, 0.08), armor, sun);
    // neck + head
    push_box(&mut verts, &mut indices, Vec3::new(-0.06, 1.46, -0.06), Vec3::new(0.06, 1.56, 0.06), skin, sun);
    push_box(&mut verts, &mut indices, Vec3::new(-0.13, 1.56, -0.13), Vec3::new(0.13, 1.80, 0.13), skin, sun);
    GpuMeshBatch {
        tex_id: 0, // `textures[0]` is the solid-white 4x4
        two_sided: false,
        alpha_test: false,
        alpha_blend: false,
        verts,
        indices,
    }
}

/// `a * b` per-channel multiply for `0xAARRGGBB` colors (alpha preserved from `a`).
fn mul_color(a: u32, b: u32) -> u32 {
    let r = (((a >> 16) & 0xFF) * ((b >> 16) & 0xFF) / 255) << 16;
    let g = (((a >> 8) & 0xFF) * ((b >> 8) & 0xFF) / 255) << 8;
    let bl = ((a & 0xFF) * (b & 0xFF) / 255) & 0xFF;
    (a & 0xFF00_0000) | r | g | bl
}

/// Muted stone/plaster palette for `.bmd` buildings whose textures live in the
/// unavailable `textures.pck` — hashed by model path so neighbors differ.
fn bmd_placeholder_tint(path: &str) -> u32 {
    const PALETTE: [u32; 10] = [
        0xFFC8_BBA8, 0xFFB8_A890, 0xFFC0_B0_98, 0xFF9A_A8B0, 0xFFB0_A8_98,
        0xFFC8_C0_B0, 0xFFA8_B098, 0xFFB8_C0_A8, 0xFF98_A898, 0xFFC0_B8_C8,
    ];
    let h = path.bytes().fold(0u32, |a, b| a.wrapping_mul(31).wrapping_add(b as u32));
    PALETTE[(h as usize) % PALETTE.len()]
}

/// Stable per-path tint so different NPC/monster placeholders don't all share one color.
fn npc_placeholder_tint(path: &str) -> u32 {
    const PALETTE: [u32; 8] = [
        0xFF8A_9A_B0, 0xFFB0_8A_6A, 0xFF8A_B0_8A, 0xFFA0_7A_B0,
        0xFF7A_A0_B8, 0xFFB0_A0_70, 0xFF90_80_A8, 0xFF88_98_80,
    ];
    let h = path.bytes().fold(0u32, |a, b| a.wrapping_mul(31).wrapping_add(b as u32));
    PALETTE[(h as usize) % PALETTE.len()]
}

fn build_ground_shadow_batch(tex_id: usize, center: Vec3, radius: f32) -> GpuMeshBatch {
    let y = center.y + 0.045;
    let r = radius.max(0.35);
    let c = 0xFFFF_FFFFu32;
    let verts = vec![
        A3dLitVertex { x: center.x - r, y, z: center.z + r, diffuse: c, u: 0.0, v: 0.0 },
        A3dLitVertex { x: center.x + r, y, z: center.z + r, diffuse: c, u: 1.0, v: 0.0 },
        A3dLitVertex { x: center.x - r, y, z: center.z - r, diffuse: c, u: 0.0, v: 1.0 },
        A3dLitVertex { x: center.x + r, y, z: center.z - r, diffuse: c, u: 1.0, v: 1.0 },
    ];
    GpuMeshBatch {
        tex_id,
        two_sided: true,
        alpha_test: false,
        alpha_blend: true,
        verts,
        indices: vec![0, 1, 2, 1, 3, 2],
    }
}

fn build_target_ring_batch(center: Vec3, radius: f32, color: u32) -> GpuMeshBatch {
    let segs = 20usize;
    let r_in = radius * 0.78;
    let r_out = radius;
    let y = center.y + 0.06;
    let mut verts = Vec::with_capacity((segs + 1) * 2);
    let mut indices = Vec::with_capacity(segs * 6);
    for s in 0..=segs {
        let ang = (s as f32 / segs as f32) * core::f32::consts::TAU;
        let cs = ang.cos();
        let sn = ang.sin();
        verts.push(A3dLitVertex {
            x: center.x + r_in * cs,
            y,
            z: center.z + r_in * sn,
            diffuse: color,
            u: 0.5,
            v: 0.5,
        });
        verts.push(A3dLitVertex {
            x: center.x + r_out * cs,
            y,
            z: center.z + r_out * sn,
            diffuse: color,
            u: 0.5,
            v: 0.5,
        });
    }
    for s in 0..segs {
        let b = (s * 2) as u16;
        indices.extend_from_slice(&[b, b + 1, b + 2, b + 1, b + 3, b + 2]);
    }
    GpuMeshBatch {
        tex_id: 0,
        two_sided: true,
        alpha_test: false,
        alpha_blend: true,
        verts,
        indices,
    }
}

// ---------------------------------------------------------------------------
// Perspective-Correct Z-Buffered Reference Rasterizer (`render_scene_and_ui_cpu`)
// ---------------------------------------------------------------------------

#[derive(Clone, Copy)]
struct ClipVert {
    cx: f32,
    cy: f32,
    cz: f32,
    cw: f32,
    wx: f32,
    wy: f32,
    wz: f32,
    u: f32,
    v: f32,
    r: f32,
    g: f32,
    b: f32,
    a: f32,
    dist: f32,
}

#[allow(clippy::too_many_arguments)]
pub fn render_scene_and_ui_cpu(
    fb: &mut FrameBuffer,
    scene: &mut LoadedScene3D,
    vfs: &VirtualFileSystem,
    eye: Vec3,
    dir: Vec3,
    up: Vec3,
    cam_proj: &A3DCamera,
    actors: &[DynamicCharacterActor],
    ui_quads: &[UiQuad2D],
    ui_texts: &[UiText2D],
    anim_time: f32,
) {
    let w = fb.width.max(1) as usize;
    let h = fb.height.max(1) as usize;
    if fb.pixels.len() != w * h {
        fb.resize(w as u32, h as u32);
    }

    // Dynamically update `SceneBoxArea` sky dome & distance fog for current camera position!
    scene.sync_environment_for_camera(vfs, eye);

    // Pre-build animated character/monster/weapon draw batches & TrueType glyph quads before borrowing `scene.textures`!
    let mut actor_draws = Vec::with_capacity(actors.len());
    for actor in actors {
        actor_draws.push(scene.build_actor_draw_calls(vfs, actor, anim_time));
    }
    let mut text_quads = Vec::new();
    let mut tmp_texts = ui_texts.to_vec();
    scene.flush_texts_to_quads(&mut text_quads, &mut tmp_texts);

    // Clear color & Z-buffer (`z in [0, 1]`, 1.0 = far clip)
    fb.pixels.fill(scene.fog_color);
    fb.zbuf.fill(1.0);

    let aspect = (w as f32) / (h as f32);
    let view = Mat4::look_to_lh(eye, dir, up);
    let proj = Mat4::perspective_fov_lh(
        cam_proj.fov_degrees.to_radians(),
        aspect,
        cam_proj.near_clip.max(0.25),
        cam_proj.far_clip.max(1100.0),
    );
    let view_proj = view.mul(proj);
    let fwd = dir.normalized();

    // 1. Sky Dome (`A3DSkySphere`, depth-write OFF, centered on `eye`, no fog)
    let sky_world = Mat4([
        [1.0, 0.0, 0.0, 0.0],
        [0.0, 1.0, 0.0, 0.0],
        [0.0, 0.0, 1.0, 0.0],
        [eye.x, eye.y - 35.0, eye.z, 1.0],
    ]);
    let sky_mvp = sky_world.mul(view_proj);
    rasterize_batch(
        fb,
        &scene.sky_dome.cap_verts,
        &scene.sky_dome.cap_indices,
        sky_mvp,
        sky_world,
        eye,
        &scene.textures[scene.sky_cap_tex],
        None,
        true,
        false,
        false,
        false,
        false,
        scene.fog_start,
        scene.fog_end,
        scene.fog_color,
        0.0,
    );
    rasterize_batch(
        fb,
        &scene.sky_dome.surround_front_verts,
        &scene.sky_dome.surround_front_indices,
        sky_mvp,
        sky_world,
        eye,
        &scene.textures[scene.sky_front_tex],
        None,
        true,
        false,
        true,
        false,
        false,
        scene.fog_start,
        scene.fog_end,
        scene.fog_color,
        0.0,
    );
    rasterize_batch(
        fb,
        &scene.sky_dome.surround_back_verts,
        &scene.sky_dome.surround_back_indices,
        sky_mvp,
        sky_world,
        eye,
        &scene.textures[scene.sky_back_tex],
        None,
        true,
        false,
        true,
        false,
        false,
        scene.fog_start,
        scene.fog_end,
        scene.fog_color,
        0.0,
    );

    // 1b. Dynamic Sky Clouds (`CELCloudCreator` / `CloudSprite` horizon & mid-sky cumulus ring)
    if scene.clouds_enabled {
        let (cverts, cindices) = scene.build_cloud_ring_mesh(eye, anim_time);
        if !cverts.is_empty() {
            rasterize_batch(
                fb,
                &cverts,
                &cindices,
                view_proj,
                Mat4::IDENTITY,
                eye,
                &scene.textures[scene.cloud_sprite_tex_id],
                None,
                true,
                false,
                true,
                false,
                false,
                scene.fog_start,
                scene.fog_end,
                scene.fog_color,
                0.0,
            );
        }
    }

    // 2. Terrain (`A3DTerrain2` 16x16 blocks with frustum cone culling + per-pixel near-camera `.t2mk` detail splatting!)
    for blk in &scene.terrain_blocks {
        if !aabb_visible(&blk.world_aabb, eye, fwd, 1050.0) {
            continue;
        }
        let near_splat = if blk.world_aabb.center().sub(eye).length_sq() <= 275.0 * 275.0 {
            Some((&*scene, blk.sub_slot, blk.area_idx))
        } else {
            None
        };
        rasterize_batch(
            fb,
            &blk.verts,
            &blk.indices,
            view_proj,
            Mat4::IDENTITY,
            eye,
            &scene.textures[blk.tex_id],
            near_splat,
            true,
            false,
            false,
            true,
            true,
            scene.fog_start,
            scene.fog_end,
            scene.fog_color,
            0.0,
        );
    }

    // 3. Ornaments (`CECOrnament` `.bmd` `A3DLitModel` instances with world AABB culling)
    for inst in &scene.ornaments {
        if !aabb_visible(&inst.world_aabb, eye, fwd, 950.0) {
            continue;
        }
        let mvp = inst.world_mat.mul(view_proj);
        for batch in &scene.bmd_models[inst.model_idx] {
            rasterize_batch(
                fb,
                &batch.verts,
                &batch.indices,
                mvp,
                inst.world_mat,
                eye,
                &scene.textures[batch.tex_id],
                None,
                batch.two_sided,
                batch.alpha_test,
                false,
                true,
                true,
                scene.fog_start,
                scene.fog_end,
                scene.fog_color,
                0.0,
            );
        }
    }

    // 4. Dynamic 3D Characters, Real `.ecm` NPCs/Monsters, & `HH_*` Attached Weapons
    for draws in &actor_draws {
        for (world_m, batch) in draws {
            let mvp = world_m.mul(view_proj);
            rasterize_batch(
                fb,
                &batch.verts,
                &batch.indices,
                mvp,
                *world_m,
                eye,
                &scene.textures[batch.tex_id],
                None,
                batch.two_sided,
                batch.alpha_test,
                batch.alpha_blend,
                !batch.alpha_blend,
                true,
                scene.fog_start,
                scene.fog_end,
                scene.fog_color,
                0.0,
            );
        }
    }

    // 5. Water (`A3DWaterArea` translucent animated water planes, depth-test ON, depth-write OFF)
    let uv_scroll = anim_time * 0.035;
    for wb in &scene.water_batches {
        rasterize_batch(
            fb,
            &wb.verts,
            &wb.indices,
            view_proj,
            Mat4::IDENTITY,
            eye,
            &scene.textures[wb.tex_id],
            None,
            true,
            false,
            true,
            false,
            true,
            scene.fog_start,
            scene.fog_end,
            scene.fog_color,
            uv_scroll,
        );
    }

    // 5b. `A3DGFXEx` (`.gfx` / `MOXT`) Additive Particle, Weapon Glow, & `VisibleState` Aura Billboards
    if scene.gfx_manager.particle_count() > 0 {
        let cam_right = Vec3::new(-fwd.z, 0.0, fwd.x).normalized();
        let cam_up = cam_right.cross(fwd).normalized();
        let (pverts, pindices) = scene.gfx_manager.build_billboard_mesh(cam_right, cam_up);
        if !pverts.is_empty() {
            rasterize_batch(
                fb,
                &pverts,
                &pindices,
                view_proj,
                Mat4::IDENTITY,
                eye,
                &scene.textures[scene.particle_glow_tex_id],
                None,
                true,
                false,
                true,
                false,
                false,
                scene.fog_start,
                scene.fog_end,
                scene.fog_color,
                -1000.0, // Additive `D3DBLEND_ONE` `.gfx` pass
            );
        }
    }

    // 6. `AUIManager` 2D Quads & TrueType (`fzl2jw.ttf`) Glyph Atlas Quads
    for q in ui_quads {
        let tex_opt = q.tex_id.and_then(|id| scene.textures.get(id));
        draw_ui_quad_cpu(fb, q, tex_opt);
    }
    for q in &text_quads {
        let tex_opt = q.tex_id.and_then(|id| scene.textures.get(id));
        draw_ui_quad_cpu(fb, q, tex_opt);
    }
}

#[inline]
fn aabb_visible(aabb: &Aabb, eye: Vec3, fwd: Vec3, max_dist: f32) -> bool {
    let center = aabb.center();
    let radius = aabb.radius().max(4.0);
    let delta = center.sub(eye);
    let dist_sq = delta.length_sq();
    let limit = max_dist + radius;
    if dist_sq > limit * limit {
        return false;
    }
    // Behind-camera plane test (`dot(center - eye, fwd) < -radius`)
    if delta.dot(fwd) < -radius * 1.15 {
        return false;
    }
    true
}

#[allow(clippy::too_many_arguments)]
fn rasterize_batch(
    fb: &mut FrameBuffer,
    verts: &[A3dLitVertex],
    indices: &[u16],
    mvp: Mat4,
    world_mat: Mat4,
    eye: Vec3,
    tex: &SurfaceImage,
    terrain_splat_ctx: Option<(&LoadedScene3D, usize, usize)>,
    two_sided: bool,
    alpha_test: bool,
    alpha_blend: bool,
    depth_write: bool,
    apply_fog: bool,
    fog_start: f32,
    fog_end: f32,
    fog_color: u32,
    uv_scroll: f32,
) {
    let w_f = fb.width as f32;
    let h_f = fb.height as f32;
    let w_i = fb.width as i32;
    let h_i = fb.height as i32;

    let eff_scroll = if uv_scroll <= -999.0 { 0.0 } else { uv_scroll };
    let mut xformed = Vec::with_capacity(verts.len());
    for vt in verts {
        let lp = Vec3::new(vt.x, vt.y, vt.z);
        let c = mvp.transform_vec4(lp);
        let wp = world_mat.transform_point(lp);
        let dist = wp.sub(eye).length();
        xformed.push(ClipVert {
            cx: c[0],
            cy: c[1],
            cz: c[2],
            cw: c[3],
            wx: wp.x,
            wy: wp.y,
            wz: wp.z,
            u: vt.u + eff_scroll,
            v: vt.v + eff_scroll * 0.7,
            r: ((vt.diffuse >> 16) & 0xFF) as f32 * (1.0 / 255.0),
            g: ((vt.diffuse >> 8) & 0xFF) as f32 * (1.0 / 255.0),
            b: (vt.diffuse & 0xFF) as f32 * (1.0 / 255.0),
            a: ((vt.diffuse >> 24) & 0xFF) as f32 * (1.0 / 255.0),
            dist,
        });
    }

    let near_w = 0.25f32;
    for tri in indices.chunks_exact(3) {
        let (i0, i1, i2) = (tri[0] as usize, tri[1] as usize, tri[2] as usize);
        if i0 >= xformed.len() || i1 >= xformed.len() || i2 >= xformed.len() {
            continue;
        }
        let v0 = xformed[i0];
        let v1 = xformed[i1];
        let v2 = xformed[i2];

        // Trivial frustum plane reject when all 3 verts lie outside one clip plane
        if v0.cw < near_w && v1.cw < near_w && v2.cw < near_w {
            continue;
        }
        if (v0.cx < -v0.cw && v1.cx < -v1.cw && v2.cx < -v2.cw)
            || (v0.cx > v0.cw && v1.cx > v1.cw && v2.cx > v2.cw)
            || (v0.cy < -v0.cw && v1.cy < -v1.cw && v2.cy < -v2.cw)
            || (v0.cy > v0.cw && v1.cy > v1.cw && v2.cy > v2.cw)
        {
            continue;
        }

        // Near-plane (`cw >= near_w`) Sutherland-Hodgman clip -> 1 or 2 triangles
        let mut poly = [v0; 4];
        let mut n_out = 0usize;
        let in_tri = [v0, v1, v2];
        for e in 0..3 {
            let a = in_tri[e];
            let b = in_tri[(e + 1) % 3];
            let a_in = a.cw >= near_w;
            let b_in = b.cw >= near_w;
            if a_in && b_in {
                poly[n_out] = b;
                n_out += 1;
            } else if a_in && !b_in {
                let t = (a.cw - near_w) / (a.cw - b.cw);
                poly[n_out] = lerp_clip(a, b, t);
                n_out += 1;
            } else if !a_in && b_in {
                let t = (near_w - a.cw) / (b.cw - a.cw);
                poly[n_out] = lerp_clip(a, b, t);
                n_out += 1;
                poly[n_out] = b;
                n_out += 1;
            }
        }
        if n_out < 3 {
            continue;
        }

        for ti in 0..(n_out - 2) {
            let p0 = poly[0];
            let p1 = poly[ti + 1];
            let p2 = poly[ti + 2];
            draw_clipped_tri(
                fb,
                p0,
                p1,
                p2,
                w_f,
                h_f,
                w_i,
                h_i,
                tex,
                terrain_splat_ctx,
                two_sided,
                alpha_test,
                alpha_blend,
                depth_write,
                apply_fog,
                fog_start,
                fog_end,
                fog_color,
                eye,
                uv_scroll,
            );
        }
    }
}

#[inline]
fn lerp_clip(a: ClipVert, b: ClipVert, t: f32) -> ClipVert {
    ClipVert {
        cx: a.cx + (b.cx - a.cx) * t,
        cy: a.cy + (b.cy - a.cy) * t,
        cz: a.cz + (b.cz - a.cz) * t,
        cw: a.cw + (b.cw - a.cw) * t,
        wx: a.wx + (b.wx - a.wx) * t,
        wy: a.wy + (b.wy - a.wy) * t,
        wz: a.wz + (b.wz - a.wz) * t,
        u: a.u + (b.u - a.u) * t,
        v: a.v + (b.v - a.v) * t,
        r: a.r + (b.r - a.r) * t,
        g: a.g + (b.g - a.g) * t,
        b: a.b + (b.b - a.b) * t,
        a: a.a + (b.a - a.a) * t,
        dist: a.dist + (b.dist - a.dist) * t,
    }
}

#[allow(clippy::too_many_arguments)]
fn draw_clipped_tri(
    fb: &mut FrameBuffer,
    p0: ClipVert,
    p1: ClipVert,
    p2: ClipVert,
    w_f: f32,
    h_f: f32,
    w_i: i32,
    h_i: i32,
    tex: &SurfaceImage,
    terrain_splat_ctx: Option<(&LoadedScene3D, usize, usize)>,
    two_sided: bool,
    alpha_test: bool,
    alpha_blend: bool,
    depth_write: bool,
    apply_fog: bool,
    fog_start: f32,
    fog_end: f32,
    fog_color: u32,
    eye: Vec3,
    uv_scroll: f32,
) {
    let inv_w0 = 1.0 / p0.cw;
    let inv_w1 = 1.0 / p1.cw;
    let inv_w2 = 1.0 / p2.cw;

    let sx0 = (p0.cx * inv_w0 * 0.5 + 0.5) * w_f;
    let sy0 = (0.5 - p0.cy * inv_w0 * 0.5) * h_f;
    let sx1 = (p1.cx * inv_w1 * 0.5 + 0.5) * w_f;
    let sy1 = (0.5 - p1.cy * inv_w1 * 0.5) * h_f;
    let sx2 = (p2.cx * inv_w2 * 0.5 + 0.5) * w_f;
    let sy2 = (0.5 - p2.cy * inv_w2 * 0.5) * h_f;

    let area = (sx1 - sx0) * (sy2 - sy0) - (sy1 - sy0) * (sx2 - sx0);
    if !two_sided && area <= 0.0 {
        return;
    }
    if area.abs() < 1e-4 {
        return;
    }

    let min_x = sx0.min(sx1).min(sx2).floor().max(0.0) as i32;
    let max_x = sx0.max(sx1).max(sx2).ceil().min((w_i - 1) as f32) as i32;
    let min_y = sy0.min(sy1).min(sy2).floor().max(0.0) as i32;
    let max_y = sy0.max(sy1).max(sy2).ceil().min((h_i - 1) as f32) as i32;
    if min_x > max_x || min_y > max_y {
        return;
    }

    let inv_area = 1.0 / area;
    let z0 = (p0.cz * inv_w0).clamp(0.0, 1.0);
    let z1 = (p1.cz * inv_w1).clamp(0.0, 1.0);
    let z2 = (p2.cz * inv_w2).clamp(0.0, 1.0);

    let u0w = p0.u * inv_w0;
    let u1w = p1.u * inv_w1;
    let u2w = p2.u * inv_w2;
    let v0w = p0.v * inv_w0;
    let v1w = p1.v * inv_w1;
    let v2w = p2.v * inv_w2;
    let wx0w = p0.wx * inv_w0;
    let wx1w = p1.wx * inv_w1;
    let wx2w = p2.wx * inv_w2;
    let wy0w = p0.wy * inv_w0;
    let wy1w = p1.wy * inv_w1;
    let wy2w = p2.wy * inv_w2;
    let wz0w = p0.wz * inv_w0;
    let wz1w = p1.wz * inv_w1;
    let wz2w = p2.wz * inv_w2;

    // Exact screen-space barycentric derivatives (`dw_i/dx`, `dw_i/dy`) for perspective-exact
    // 4x Anisotropic + Trilinear Mipmap filtering (`q = q_w / iw` => `dq/dx = (dq_w/dx - q * diw/dx) / iw`)!
    let dw0_dx = (sy1 - sy2) * inv_area;
    let dw1_dx = (sy2 - sy0) * inv_area;
    let dw2_dx = -(dw0_dx + dw1_dx);
    let dw0_dy = (sx2 - sx1) * inv_area;
    let dw1_dy = (sx0 - sx2) * inv_area;
    let dw2_dy = -(dw0_dy + dw1_dy);

    let diw_dx = dw0_dx * inv_w0 + dw1_dx * inv_w1 + dw2_dx * inv_w2;
    let diw_dy = dw0_dy * inv_w0 + dw1_dy * inv_w1 + dw2_dy * inv_w2;
    let duw_dx = dw0_dx * u0w + dw1_dx * u1w + dw2_dx * u2w;
    let duw_dy = dw0_dy * u0w + dw1_dy * u1w + dw2_dy * u2w;
    let dvw_dx = dw0_dx * v0w + dw1_dx * v1w + dw2_dx * v2w;
    let dvw_dy = dw0_dy * v0w + dw1_dy * v1w + dw2_dy * v2w;
    let dwxw_dx = dw0_dx * wx0w + dw1_dx * wx1w + dw2_dx * wx2w;
    let dwxw_dy = dw0_dy * wx0w + dw1_dy * wx1w + dw2_dy * wx2w;
    let dwzw_dx = dw0_dx * wz0w + dw1_dx * wz1w + dw2_dx * wz2w;
    let dwzw_dy = dw0_dy * wz0w + dw1_dy * wz1w + dw2_dy * wz2w;

    let is_water_shader = alpha_blend && uv_scroll > 1e-6;
    let is_additive_gfx = alpha_blend && uv_scroll <= -999.0;
    let sun_dir = Vec3::new(-0.35, 0.78, -0.52).normalized();

    let fr = ((fog_color >> 16) & 0xFF) as f32;
    let fg = ((fog_color >> 8) & 0xFF) as f32;
    let fb_c = (fog_color & 0xFF) as f32;
    let inv_fog_span = 1.0 / (fog_end - fog_start).max(1.0);
    let stride = fb.width as usize;

    for py in min_y..=max_y {
        let fy = py as f32 + 0.5;
        let row_off = (py as usize) * stride;
        for px in min_x..=max_x {
            let fx = px as f32 + 0.5;
            let w0 = ((sx1 - fx) * (sy2 - fy) - (sy1 - fy) * (sx2 - fx)) * inv_area;
            let w1 = ((sx2 - fx) * (sy0 - fy) - (sy2 - fy) * (sx0 - fx)) * inv_area;
            let w2 = 1.0 - w0 - w1;
            if w0 < 0.0 || w1 < 0.0 || w2 < 0.0 {
                continue;
            }

            let z = if depth_write || alpha_blend {
                w0 * z0 + w1 * z1 + w2 * z2
            } else {
                0.9999
            };
            let idx = row_off + (px as usize);
            if z > fb.zbuf[idx] {
                continue;
            }

            let iw = (w0 * inv_w0 + w1 * inv_w1 + w2 * inv_w2).max(1e-7);
            let w_persp = 1.0 / iw;
            let u = (w0 * u0w + w1 * u1w + w2 * u2w) * w_persp;
            let v = (w0 * v0w + w1 * v1w + w2 * v2w) * w_persp;
            let dudx = (duw_dx - u * diw_dx) * w_persp;
            let dvdx = (dvw_dx - v * diw_dx) * w_persp;
            let dudy = (duw_dy - u * diw_dy) * w_persp;
            let dvdy = (dvw_dy - v * diw_dy) * w_persp;
            let dist = w0 * p0.dist + w1 * p1.dist + w2 * p2.dist;

            let tc = if let Some((scn, sub_slot, area_idx)) = terrain_splat_ctx {
                if dist < 245.0 {
                    let wx = (w0 * wx0w + w1 * wx1w + w2 * wx2w) * w_persp;
                    let wy = (w0 * wy0w + w1 * wy1w + w2 * wy2w) * w_persp;
                    let wz = (w0 * wz0w + w1 * wz1w + w2 * wz2w) * w_persp;
                    let dwx_dx = (dwxw_dx - wx * diw_dx) * w_persp;
                    let dwx_dy = (dwxw_dy - wx * diw_dy) * w_persp;
                    let dwz_dx = (dwzw_dx - wz * diw_dx) * w_persp;
                    let dwz_dy = (dwzw_dy - wz * diw_dy) * w_persp;
                    if let Some(detail_c) = scn.sample_terrain_splat_at(
                        sub_slot, area_idx, wx, wy, wz, dwx_dx, dwz_dx, dwx_dy, dwz_dy,
                    ) {
                        if dist > 195.0 {
                            let baked = tex.sample_uv_anisotropic(u, v, dudx, dvdx, dudy, dvdy);
                            let bf = ((dist - 195.0) * (1.0 / 50.0)).clamp(0.0, 1.0);
                            let mix_ch = |sh: u32| -> u32 {
                                let a = ((detail_c >> sh) & 0xFF) as f32;
                                let b = ((baked >> sh) & 0xFF) as f32;
                                (a + (b - a) * bf) as u32
                            };
                            0xFF00_0000 | (mix_ch(16) << 16) | (mix_ch(8) << 8) | mix_ch(0)
                        } else {
                            detail_c
                        }
                    } else {
                        tex.sample_uv_anisotropic(u, v, dudx, dvdx, dudy, dvdy)
                    }
                } else {
                    tex.sample_uv_anisotropic(u, v, dudx, dvdx, dudy, dvdy)
                }
            } else if !apply_fog {
                // Sky dome (`A3DSkySphere`) or portrait render: smooth clamped bilinear!
                if alpha_test {
                    tex.sample_uv_anisotropic(u, v, dudx, dvdx, dudy, dvdy)
                } else {
                    tex.sample_uv_bilinear_clamp(u, v)
                }
            } else {
                tex.sample_uv_anisotropic(u, v, dudx, dvdx, dudy, dvdy)
            };
            let ta = (tc >> 24) & 0xFF;
            if alpha_test && ta < 96 {
                continue;
            }

            let vr = w0 * p0.r + w1 * p1.r + w2 * p2.r;
            let vg = w0 * p0.g + w1 * p1.g + w2 * p2.g;
            let vb = w0 * p0.b + w1 * p1.b + w2 * p2.b;

            let mod_scale = if vr < 0.98 || vg < 0.98 || vb < 0.98 {
                1.85
            } else {
                1.0
            };
            let mut sr = (((tc >> 16) & 0xFF) as f32 * vr * mod_scale).clamp(0.0, 255.0);
            let mut sg = (((tc >> 8) & 0xFF) as f32 * vg * mod_scale).clamp(0.0, 255.0);
            let mut sb = ((tc & 0xFF) as f32 * vb * mod_scale).clamp(0.0, 255.0);
            let mut water_fresnel_boost = 0.0f32;

            // Angelica `shaders/ps/water/water_expensive.txt`:
            // Dual-scrolling tangent-space normal perturbation + `(1 - saturate(N·V))^5` Fresnel + sun specular!
            if is_water_shader {
                let wx = (w0 * wx0w + w1 * wx1w + w2 * wx2w) * w_persp;
                let wy = (w0 * wy0w + w1 * wy1w + w2 * wy2w) * w_persp;
                let wz = (w0 * wz0w + w1 * wz1w + w2 * wz2w) * w_persp;
                let ph1 = wx * 0.42 + wz * 0.31 + uv_scroll * 18.0;
                let ph2 = wx * 0.27 - wz * 0.49 - uv_scroll * 13.0;
                let nx = (ph1.sin() * 0.065 + ph2.cos() * 0.045).clamp(-0.18, 0.18);
                let nz = (ph1.cos() * 0.055 - ph2.sin() * 0.060).clamp(-0.18, 0.18);
                let n_vec = Vec3::new(nx, 1.0, nz).normalized();
                let v_vec = eye.sub(Vec3::new(wx, wy, wz)).normalized();
                let ndotv = n_vec.dot(v_vec).clamp(0.0, 1.0);
                let fresnel = (0.06 + 0.94 * (1.0 - ndotv).powi(5)).clamp(0.0, 0.92);
                let sky_r = (fr * 0.82 + 42.0).clamp(0.0, 255.0);
                let sky_g = (fg * 0.88 + 38.0).clamp(0.0, 255.0);
                let sky_b = (fb_c * 0.92 + 34.0).clamp(0.0, 255.0);
                sr = sr + (sky_r - sr) * (fresnel * 0.72);
                sg = sg + (sky_g - sg) * (fresnel * 0.72);
                sb = sb + (sky_b - sb) * (fresnel * 0.72);
                let h_vec = sun_dir.add(v_vec).normalized();
                let spec = n_vec.dot(h_vec).max(0.0).powi(40) * 195.0;
                sr = (sr + spec).clamp(0.0, 255.0);
                sg = (sg + spec * 0.97).clamp(0.0, 255.0);
                sb = (sb + spec * 0.90).clamp(0.0, 255.0);
                water_fresnel_boost = fresnel * 0.28;
            }

            if apply_fog && dist > fog_start {
                let f = ((dist - fog_start) * inv_fog_span).clamp(0.0, 0.92);
                sr += (fr - sr) * f;
                sg += (fg - sg) * f;
                sb += (fb_c - sb) * f;
            }

            if alpha_blend {
                let va = (w0 * p0.a + w1 * p1.a + w2 * p2.a).clamp(0.0, 1.0);
                let sa = (ta as f32 * (1.0 / 255.0) * va + water_fresnel_boost).clamp(0.0, 0.98);
                if sa <= 0.01 {
                    continue;
                }
                let dst = fb.pixels[idx];
                let dr = ((dst >> 16) & 0xFF) as f32;
                let dg = ((dst >> 8) & 0xFF) as f32;
                let db = (dst & 0xFF) as f32;
                let (nr, ng, nb) = if is_additive_gfx {
                    (
                        (dr + sr * sa).min(255.0) as u32,
                        (dg + sg * sa).min(255.0) as u32,
                        (db + sb * sa).min(255.0) as u32,
                    )
                } else {
                    (
                        (dr + (sr - dr) * sa) as u32,
                        (dg + (sg - dg) * sa) as u32,
                        (db + (sb - db) * sa) as u32,
                    )
                };
                fb.pixels[idx] = 0xFF00_0000 | (nr << 16) | (ng << 8) | nb;
            } else {
                if depth_write {
                    fb.zbuf[idx] = z;
                }
                fb.pixels[idx] =
                    0xFF00_0000 | ((sr as u32) << 16) | ((sg as u32) << 8) | (sb as u32);
            }
        }
    }
}

/// Applies `CharacterCustomizeIni` `[Body]` 6-axis proportion sliders (`upScale`, `waistScale`,
/// `armWidth`, `legWidth`, `breastScale` around `128 = 1.0`) smoothly across the character body mesh.
fn apply_body_proportions_to_vertices(
    verts: &mut [A3dLitVertex],
    ini: &pw_data::CharacterCustomizeIni,
) {
    if ini.up_scale == 128
        && ini.waist_scale == 128
        && ini.arm_width == 128
        && ini.leg_width == 128
        && ini.breast_scale == 128
    {
        return;
    }
    let up_sc = pw_data::CharacterCustomizeIni::slider_to_scale(ini.up_scale, 0.22);
    let waist_sc = pw_data::CharacterCustomizeIni::slider_to_scale(ini.waist_scale, 0.22);
    let arm_sc = pw_data::CharacterCustomizeIni::slider_to_scale(ini.arm_width, 0.24);
    let leg_sc = pw_data::CharacterCustomizeIni::slider_to_scale(ini.leg_width, 0.22);
    let breast_sc = pw_data::CharacterCustomizeIni::slider_to_scale(ini.breast_scale, 0.20);

    for vt in verts.iter_mut() {
        let y = vt.y;
        if y < 0.08 || y > 1.54 {
            continue;
        }
        if vt.x.abs() > 0.20 && y > 0.85 {
            // Arms (`Bip01 *UpperArm` / `Forearm`)
            let sign = vt.x.signum();
            vt.x = sign * (0.20 + (vt.x.abs() - 0.20) * arm_sc);
            vt.z *= 0.5 + 0.5 * arm_sc;
        } else if y < 0.88 {
            // Legs / thighs / calves (`Bip01 *Thigh` / `Calf`)
            let center_x = vt.x.signum() * 0.09;
            vt.x = center_x + (vt.x - center_x) * leg_sc;
            vt.z *= leg_sc;
        } else if y < 1.14 {
            // Waist / pelvis (`Bip01 Pelvis` / `Spine`)
            let t = ((y - 0.88) / 0.26).clamp(0.0, 1.0);
            let s = leg_sc * (1.0 - t) + waist_sc * t;
            vt.x *= s;
            vt.z *= s;
        } else {
            // Upper torso / shoulders / chest (`Bip01 Spine1` / `Clavicle` / `Breast`)
            let t = ((y - 1.14) / 0.28).clamp(0.0, 1.0);
            let s = waist_sc * (1.0 - t) + up_sc * t;
            vt.x *= s;
            if vt.z > 0.01 && y < 1.38 {
                vt.z *= s * (0.65 + 0.35 * breast_sc);
            } else {
                vt.z *= s;
            }
        }
    }
}

/// Applies `CECFace` (`0x559250`) `[Face]`, `[3Parts]`, asymmetric `[Eye]`/`[Brow]`, `[Nose]`,
/// `[Mouth]`, `[Jaw]`, `[Cheek]`, `[Forehead]`, `[YokeBone]`, `[Ear]`, & `[Body]::headScale`
/// bone-controller deformations while keeping `CC_Neck` (`y = 0`) 100% locked!
fn apply_cecface_morph_to_vertices(
    verts: &mut [A3dLitVertex],
    ini: &pw_data::CharacterCustomizeIni,
    face_local_space: bool,
) {
    let head_sc = pw_data::CharacterCustomizeIni::slider_to_scale(ini.head_scale, 0.18);
    let face_h = pw_data::CharacterCustomizeIni::slider_to_scale(ini.scale_face_h, 0.16) * head_sc;
    let face_v = pw_data::CharacterCustomizeIni::slider_to_scale(ini.scale_face_v, 0.16) * head_sc;
    let sc_up = pw_data::CharacterCustomizeIni::slider_to_scale(ini.scale_up, 0.12);
    let sc_mid = pw_data::CharacterCustomizeIni::slider_to_scale(ini.scale_middle, 0.12);
    let sc_dn = pw_data::CharacterCustomizeIni::slider_to_scale(ini.scale_down, 0.12);
    let sc_ear = pw_data::CharacterCustomizeIni::slider_to_scale(ini.scale_ear, 0.22);
    let off_ear_v = pw_data::CharacterCustomizeIni::slider_to_offset(ini.offset_ear_v, 0.012);
    let sc_jaw = pw_data::CharacterCustomizeIni::slider_to_scale(ini.scale_jaw_h, 0.14);
    let sc_cheek = pw_data::CharacterCustomizeIni::slider_to_scale(ini.scale_cheek, 0.14);
    let off_yoke_h = pw_data::CharacterCustomizeIni::slider_to_offset(ini.offset_yokebone_h, 0.010);
    let off_fore_z = pw_data::CharacterCustomizeIni::slider_to_offset(ini.offset_forehead_z, 0.012);

    // Asymmetric Left (`x < 0`) vs Right (`x >= 0`) `[Eye]` & `[Brow]` + `[Nose]` + `[Mouth]`
    let eye_l_v = pw_data::CharacterCustomizeIni::slider_to_offset(ini.offset_eye_v, 0.010);
    let eye_r_v = pw_data::CharacterCustomizeIni::slider_to_offset(ini.offset_eye_v2, 0.010);
    let eye_l_z = pw_data::CharacterCustomizeIni::slider_to_offset(ini.offset_eye_z, 0.010);
    let eye_r_z = pw_data::CharacterCustomizeIni::slider_to_offset(ini.offset_eye_z2, 0.010);
    let brow_l_v = pw_data::CharacterCustomizeIni::slider_to_offset(ini.offset_brow_v, 0.010);
    let brow_r_v = pw_data::CharacterCustomizeIni::slider_to_offset(ini.offset_brow_v2, 0.010);
    let nose_z = pw_data::CharacterCustomizeIni::slider_to_offset(ini.offset_bridge_tip_z, 0.014);
    let nose_v = pw_data::CharacterCustomizeIni::slider_to_offset(ini.offset_nose_tip_v, 0.010);
    let mouth_w = pw_data::CharacterCustomizeIni::slider_to_scale(ini.scale_mouth_h, 0.18);
    let mouth_z = pw_data::CharacterCustomizeIni::slider_to_offset(ini.offset_mouth_z, 0.010);

    let is_neutral = (face_h - 1.0).abs() < 1e-3
        && (face_v - 1.0).abs() < 1e-3
        && (sc_up - 1.0).abs() < 1e-3
        && (sc_mid - 1.0).abs() < 1e-3
        && (sc_dn - 1.0).abs() < 1e-3
        && (sc_ear - 1.0).abs() < 1e-3
        && (mouth_w - 1.0).abs() < 1e-3
        && eye_l_v.abs() < 1e-4
        && eye_r_v.abs() < 1e-4
        && nose_z.abs() < 1e-4;
    if is_neutral {
        return;
    }

    let neck_y = if face_local_space { 0.0 } else { 1.50 };
    for vt in verts.iter_mut() {
        let rel_y = vt.y - neck_y;
        if rel_y <= 0.008 {
            continue; // Keep `CC_Neck <-> HH_Neck` seam 100% locked!
        }
        let neck_weight = ((rel_y - 0.008) / 0.025).clamp(0.0, 1.0);
        let band_h = if rel_y < 0.065 {
            sc_dn * sc_jaw
        } else if rel_y < 0.135 {
            sc_mid * sc_cheek
        } else {
            sc_up
        };
        let abs_x = vt.x.abs();
        let mut dx = 0.0f32;
        let mut dy = 0.0f32;
        let mut dz = 0.0f32;
        let mut local_x_mult = 1.0f32;

        // Ear zone (`|x| > 0.072`)
        if abs_x > 0.072 && rel_y > 0.04 && rel_y < 0.15 {
            local_x_mult *= sc_ear;
            dy += off_ear_v;
        }
        // Cheek / YokeBone zone
        if abs_x > 0.038 && abs_x <= 0.072 && (0.065..0.125).contains(&rel_y) {
            dx += vt.x.signum() * off_yoke_h;
        }
        // Eye & Brow asymmetric left/right zones (`z > 0.045`, `|x| in 0.015..0.058`)
        if vt.z > 0.045 && (0.014..0.058).contains(&abs_x) {
            if (0.095..0.128).contains(&rel_y) {
                dy += if vt.x < 0.0 { eye_l_v } else { eye_r_v };
                dz += if vt.x < 0.0 { eye_l_z } else { eye_r_z };
            } else if (0.128..0.155).contains(&rel_y) {
                dy += if vt.x < 0.0 { brow_l_v } else { brow_r_v };
            }
        }
        // Central Nose tip (`|x| < 0.020`, `rel_y in 0.068..0.112`, `z > 0.065`)
        if abs_x < 0.020 && (0.068..0.112).contains(&rel_y) && vt.z > 0.065 {
            dy += nose_v;
            dz += nose_z;
        }
        // Mouth / Lips (`|x| < 0.032`, `rel_y in 0.032..0.068`, `z > 0.055`)
        if abs_x < 0.032 && (0.032..0.068).contains(&rel_y) && vt.z > 0.055 {
            local_x_mult *= mouth_w;
            dz += mouth_z;
        }
        // Forehead (`rel_y >= 0.145`, `z > 0.04`)
        if rel_y >= 0.145 && vt.z > 0.04 {
            dz += off_fore_z;
        }

        let target_x = vt.x * face_h * band_h * local_x_mult + dx;
        let target_y = neck_y + rel_y * face_v + dy;
        let target_z = vt.z * head_sc + dz;
        vt.x = vt.x + (target_x - vt.x) * neck_weight;
        vt.y = vt.y + (target_y - vt.y) * neck_weight;
        vt.z = vt.z + (target_z - vt.z) * neck_weight;
    }
}

fn draw_ui_quad_cpu(fb: &mut FrameBuffer, raw_q: &UiQuad2D, tex: Option<&SurfaceImage>) {
    let Some(q) = raw_q.clipped() else {
        return;
    };
    let x0 = (q.x0.round() as i32).max(0);
    let y0 = (q.y0.round() as i32).max(0);
    let x1 = (q.x1.round() as i32).min(fb.width as i32);
    let y1 = (q.y1.round() as i32).min(fb.height as i32);
    if x0 >= x1 || y0 >= y1 {
        return;
    }

    let ca = ((q.color >> 24) & 0xFF) as u32;
    let cr = ((q.color >> 16) & 0xFF) as u32;
    let cg = ((q.color >> 8) & 0xFF) as u32;
    let cb = (q.color & 0xFF) as u32;
    let inv_w = 1.0 / (q.x1 - q.x0).max(1.0);
    let inv_h = 1.0 / (q.y1 - q.y0).max(1.0);
    let du_px = (q.u1 - q.u0).abs() * inv_w;
    let dv_px = (q.v1 - q.v0).abs() * inv_h;
    // Use exact nearest texel for `1:1` unscaled UI borders & TTF glyphs, and smooth clamped bilinear/trilinear
    // whenever icons, portraits, minimaps, or world maps are scaled!
    let (use_bilinear, ui_lod) = if let Some(t) = tex {
        let sx = du_px * (t.width as f32);
        let sy = dv_px * (t.height as f32);
        let is_exact_1to1 = (sx - 1.0).abs() < 0.05 && (sy - 1.0).abs() < 0.05;
        let max_rho = sx.max(sy);
        let lod = if max_rho > 1.25 && !t.mips.is_empty() {
            max_rho.log2().max(0.0)
        } else {
            0.0
        };
        (!is_exact_1to1 && t.width >= 8 && t.height >= 8, lod)
    } else {
        (false, 0.0)
    };
    let stride = fb.width as usize;

    for py in y0..y1 {
        let tv = q.v0 + ((py as f32 + 0.5 - q.y0) * inv_h) * (q.v1 - q.v0);
        let row = (py as usize) * stride;
        for px in x0..x1 {
            let tu = q.u0 + ((px as f32 + 0.5 - q.x0) * inv_w) * (q.u1 - q.u0);
            let tc = match tex {
                Some(t) if ui_lod > 0.05 => t.sample_uv_trilinear(tu.clamp(0.0, 1.0), tv.clamp(0.0, 1.0), ui_lod),
                Some(t) if use_bilinear => t.sample_uv_bilinear_clamp(tu, tv),
                Some(t) => t.sample_uv_clamp(tu, tv),
                None => 0xFFFF_FFFF,
            };
            let sa = (((tc >> 24) & 0xFF) * ca) / 255;
            if sa == 0 {
                continue;
            }
            let sr = (((tc >> 16) & 0xFF) * cr) / 255;
            let sg = (((tc >> 8) & 0xFF) * cg) / 255;
            let sb = ((tc & 0xFF) * cb) / 255;
            let idx = row + (px as usize);
            if sa >= 252 {
                fb.pixels[idx] = 0xFF00_0000 | (sr << 16) | (sg << 8) | sb;
            } else {
                let dst = fb.pixels[idx];
                let dr = (dst >> 16) & 0xFF;
                let dg = (dst >> 8) & 0xFF;
                let db = dst & 0xFF;
                let inv_a = 255 - sa;
                let nr = (sr * sa + dr * inv_a) / 255;
                let ng = (sg * sa + dg * inv_a) / 255;
                let nb = (sb * sa + db * inv_a) / 255;
                fb.pixels[idx] = 0xFF00_0000 | (nr << 16) | (ng << 8) | nb;
            }
        }
    }
}

#[cfg(test)]
mod procedural_fallback_tests {
    use super::*;

    #[test]
    fn humanoid_batch_has_7_boxes_and_valid_indices() {
        let b = build_procedural_humanoid_batch(0xFFE8_DFD4, 0xFFC8_4030, 0xFF3A_3F4A);
        assert_eq!(b.verts.len(), 7 * 24);
        assert_eq!(b.indices.len(), 7 * 36);
        assert!(b.indices.iter().all(|&i| (i as usize) < b.verts.len()));
        assert_eq!(b.tex_id, 0); // solid-white texture slot
        // head box (last, +Y top face) is skin-tinted, torso (+Y top) is armor-tinted:
        // sun-shaded skin red (0xE8*0.90≈0xD0) must stay well above armor red (0xC8*0.90≈0xB4)
        let head_top = b.verts[6 * 24 + 8].diffuse;
        let torso_top = b.verts[2 * 24 + 8].diffuse;
        assert!(
            ((head_top >> 16) & 0xFF) > ((torso_top >> 16) & 0xFF) + 10,
            "head {head_top:#x} vs torso {torso_top:#x}"
        );
    }

    #[test]
    fn mul_color_multiplies_rgb_keeps_alpha() {
        assert_eq!(mul_color(0xFFFF_FFFF, 0xFF80_8040), 0xFF80_8040);
        assert_eq!(mul_color(0xFF40_80C0, 0xFF20_2020), 0xFF08_1018);
        assert_eq!(mul_color(0x80FF_0000, 0xFFFF_FFFF) & 0xFF00_0000, 0x8000_0000);
    }

    #[test]
    fn placeholder_tints_are_stable_and_in_palette() {
        let a = npc_placeholder_tint("models/npcs/teleport/tp_yao.ecm");
        let b = npc_placeholder_tint("models/npcs/teleport/tp_yao.ecm");
        assert_eq!(a, b);
        let t = bmd_placeholder_tint("litmodels/world/01/litmodel_5.bmd");
        assert_eq!(t, bmd_placeholder_tint("litmodels/world/01/litmodel_5.bmd"));
        assert_eq!(t & 0xFF00_0000, 0xFF00_0000);
    }

    #[test]
    fn class_armor_tint_varies_by_class_and_gender() {
        let m = class_armor_tint(0, 0);
        let f = class_armor_tint(0, 1);
        assert_ne!(m, f);
        assert_ne!(class_armor_tint(0, 0), class_armor_tint(1, 0));
        assert_eq!(class_armor_tint(2, 0) & 0xFF00_0000, 0xFF00_0000);
    }
}
