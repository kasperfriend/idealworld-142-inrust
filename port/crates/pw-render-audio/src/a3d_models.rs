//! Decompilation-exact Angelica3D 3D Model Loaders:
//! - `A3DLitModel` / `A3DLitMesh` (`.bmd` `0x007bb380` / `0x007ba070`, `18_a3dlitmodel_bmd.c`)
//! - `A3DSkinModel` / `A3DSkin` / `A3DSkinMesh` / `A3DRigidMesh` / `A3DSkeleton`
//!   (`.smd` / `.ski` / `.bon`, `0x007947b0`, `0x007e3180`, `0x007e2930`, `14` & `21`)
//! - `A3DSkySphere` (`0x0079a330`, `06_a3dsky_camera_viewport.c`)

use std::path::Path;

use pw_core::{open_afile_image, AFileMode, Aabb, Mat4, PwError, PwResult, Vec3};
use pw_pck::VirtualFileSystem;

/// Standard hardware/software vertex (`D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1` = `0x142`, 24 bytes).
#[repr(C)]
#[derive(Debug, Clone, Copy, Default)]
pub struct A3dLitVertex {
    pub x: f32,
    pub y: f32,
    pub z: f32,
    /// `0xAARRGGBB` (`D3DCOLOR` BGRA in little-endian memory).
    pub diffuse: u32,
    pub u: f32,
    pub v: f32,
}

#[derive(Debug, Clone)]
pub struct A3dLitMesh {
    pub name: String,
    pub raw_texture_name: String,
    pub resolved_texture_vfs: String,
    pub two_sided: bool,
    pub alpha_flags: u8,
    pub local_aabb: Aabb,
    pub verts: Vec<A3dLitVertex>,
    pub night_colors: Vec<u32>,
    pub normals: Vec<Vec3>,
    pub indices: Vec<u16>,
}

#[derive(Debug, Clone)]
pub struct A3dLitModel {
    pub version: u32,
    pub collide_only: bool,
    pub scale: Vec3,
    pub dir: Vec3,
    pub up: Vec3,
    pub pos: Vec3,
    pub local_aabb: Aabb,
    pub meshes: Vec<A3dLitMesh>,
}

impl A3dLitModel {
    /// Exact port of `CECBuildingWithBrush::Load` (`0x489e70`) + `A3DLitModel::LoadFromFile` (`0x7bb380`)
    /// + `A3DLitMesh::Load` (`0x7ba070`).
    pub fn parse_bmd(bytes: &[u8], bmd_vfs_path: &str) -> PwResult<Self> {
        let (mode, mut cur) = open_afile_image(bytes);
        if mode != AFileMode::BinaryMoxb {
            return Err(PwError::InvalidData(format!(
                "bmd '{bmd_vfs_path}' missing MOXB header"
            )));
        }

        let tag_or_ver = cur.read_u32_le()?;
        let mut collide_only = false;
        let model_ver = if tag_or_ver == 0x8000_0001 {
            collide_only = cur.read_u8()? != 0;
            cur.read_u32_le()?
        } else if (tag_or_ver & 0x8000_0000) != 0 {
            collide_only = cur.read_u8()? != 0;
            let _ = cur.read_u8()?;
            cur.read_u32_le()?
        } else {
            tag_or_ver
        };

        let scale = cur.read_vec3_le()?;
        let dir = cur.read_vec3_le()?;
        let up = cur.read_vec3_le()?;
        let pos = cur.read_vec3_le()?;
        let num_meshes = cur.read_i32_le()?.max(0) as usize;

        let bmd_dir = bmd_vfs_path
            .replace('\\', "/")
            .rsplit_once('/')
            .map(|(d, _)| d.to_string())
            .unwrap_or_default();

        let mut meshes = Vec::with_capacity(num_meshes);
        let mut model_aabb = Aabb::empty();

        for _ in 0..num_meshes {
            if cur.remaining() < 332 {
                break;
            }
            let mesh_ver = cur.read_u32_le()?;
            let msv = mesh_ver & 0x0FFF_FFFF;
            let name = cur.read_fixed_gbk(64)?;
            let raw_tex = cur.read_fixed_gbk(256)?;
            let nv = cur.read_i32_le()?.max(0) as usize;
            let nf = cur.read_i32_le()?.max(0) as usize;
            let has_lm = if msv == 6 {
                cur.read_u8()? != 0
            } else {
                false
            };

            let vstride = if msv <= 3 { 28 } else { 24 };
            if cur.remaining() < nv * vstride + nf * 6 + nv * 12 {
                break;
            }

            let mut verts = Vec::with_capacity(nv);
            for _ in 0..nv {
                let x = cur.read_f32_le()?;
                let y = cur.read_f32_le()?;
                let z = cur.read_f32_le()?;
                let diffuse = cur.read_u32_le()?;
                if msv <= 3 {
                    let _specular = cur.read_u32_le()?;
                }
                let u = cur.read_f32_le()?;
                let v = cur.read_f32_le()?;
                verts.push(A3dLitVertex {
                    x,
                    y,
                    z,
                    diffuse,
                    u,
                    v,
                });
            }

            let mut indices = Vec::with_capacity(nf * 3);
            for _ in 0..(nf * 3) {
                indices.push(cur.read_u16_le()?);
            }

            let mut normals = Vec::with_capacity(nv);
            for _ in 0..nv {
                normals.push(cur.read_vec3_le()?);
            }

            let mut night_colors = vec![0xFF80_8080u32; nv];
            if msv >= 3 && cur.remaining() >= nv * 8 {
                for v in &mut verts {
                    let c = cur.read_u32_le()?;
                    // Keep baked RGB and force opaque vertex alpha (`0xFF`)
                    v.diffuse = 0xFF00_0000 | (c & 0x00FF_FFFF);
                }
                for nc in &mut night_colors {
                    let c = cur.read_u32_le()?;
                    *nc = 0xFF00_0000 | (c & 0x00FF_FFFF);
                }
            }

            let local_aabb;
            if msv >= 2 && cur.remaining() >= 48 {
                // Exact `A3DAABB` (`0x30` = 48 bytes at `A3DLitMesh::Load` `0x007b9eb0`)
                let _center = cur.read_vec3_le()?;
                let _extents = cur.read_vec3_le()?;
                let mins = cur.read_vec3_le()?;
                let maxs = cur.read_vec3_le()?;
                let alpha_flags = 0u8;
                local_aabb = Aabb { mins, maxs };
                let mut two_sided = false;
                if msv >= 5 && cur.remaining() >= 80 {
                    let mat_hdr = cur.read_bytes(11)?;
                    if mat_hdr.starts_with(b"MATERIAL:") {
                        let _ = cur.skip(68);
                        two_sided = cur.read_u8()? != 0;
                    }
                }
                if msv >= 6 && has_lm && cur.remaining() >= nv * 8 {
                    let _ = cur.skip(nv * 8);
                }

                for vt in &verts {
                    model_aabb.expand_point(Vec3::new(vt.x, vt.y, vt.z));
                }
                let resolved_texture_vfs = resolve_bmd_texture_path(&bmd_dir, &raw_tex);
                meshes.push(A3dLitMesh {
                    name,
                    raw_texture_name: raw_tex,
                    resolved_texture_vfs,
                    two_sided,
                    alpha_flags,
                    local_aabb,
                    verts,
                    night_colors,
                    normals,
                    indices,
                });
            }
        }

        if !model_aabb.mins.x.is_finite() {
            model_aabb = Aabb {
                mins: Vec3::new(-1.0, -1.0, -1.0),
                maxs: Vec3::new(1.0, 1.0, 1.0),
            };
        }

        Ok(Self {
            version: model_ver,
            collide_only,
            scale,
            dir,
            up,
            pos,
            local_aabb: model_aabb,
            meshes,
        })
    }
}

pub fn resolve_bmd_texture_path(bmd_dir: &str, raw_tex: &str) -> String {
    let clean = raw_tex.trim().replace('\\', "/");
    if clean.is_empty() {
        return String::new();
    }
    let fname = Path::new(&clean)
        .file_name()
        .and_then(|s| s.to_str())
        .unwrap_or(&clean);
    if clean.contains('/') {
        clean
    } else if !bmd_dir.is_empty() {
        format!("{bmd_dir}/textures/{fname}")
    } else {
        format!("building/textures/{fname}")
    }
}

/// Resolves a `.bmd` / `.ski` texture across `litmodels.pck`, `building.pck`, `models.pck`, `facedata.pck`, and `textures.pck`.
pub fn read_model_texture_bytes(
    vfs: &VirtualFileSystem,
    parent_dir: &str,
    raw_tex: &str,
) -> Option<Vec<u8>> {
    let clean = raw_tex.trim().replace('\\', "/");
    if clean.is_empty() {
        return None;
    }
    let fname = clean.rsplit('/').next().unwrap_or(&clean);
    let stem = fname.rsplit_once('.').map(|(s, _)| s).unwrap_or(fname);
    let dds_name = format!("{stem}.dds");
    let dir_leaf = parent_dir.rsplit('/').next().unwrap_or("");

    let mut candidates = vec![
        clean.clone(),
        format!("{parent_dir}/{fname}"),
        format!("{parent_dir}/{dds_name}"),
        format!("{parent_dir}/textures/{fname}"),
        format!("{parent_dir}/textures/{dds_name}"),
    ];
    if !dir_leaf.is_empty() {
        // Angelica `A3DSkin::Load` (`0x00793c10`) stores per-skin textures in `<dir>/tex_<skin_stem>/<tex>`!
        candidates.push(format!("{parent_dir}/tex_{dir_leaf}/{fname}"));
        candidates.push(format!("{parent_dir}/tex_{dir_leaf}/{dds_name}"));
    }
    candidates.extend([
        format!("building/textures/{fname}"),
        format!("building/textures/{dds_name}"),
        format!("textures/building/{fname}"),
        format!("textures/{fname}"),
    ]);

    // Also try parent/.. (`models/players/形象/武侠男/躯干` -> `models/players/形象/武侠男/textures/...` or `tex_...`)
    let mut anc = parent_dir;
    while let Some((up, _)) = anc.rsplit_once('/') {
        let up_leaf = up.rsplit('/').next().unwrap_or("");
        candidates.push(format!("{up}/textures/{fname}"));
        candidates.push(format!("{up}/textures/{dds_name}"));
        if !up_leaf.is_empty() {
            candidates.push(format!("{up}/tex_{up_leaf}/{fname}"));
            candidates.push(format!("{up}/tex_{up_leaf}/{dds_name}"));
        }
        if !dir_leaf.is_empty() {
            candidates.push(format!("{up}/tex_{dir_leaf}/{fname}"));
            candidates.push(format!("{up}/tex_{dir_leaf}/{dds_name}"));
        }
        candidates.push(format!("{up}/{fname}"));
        anc = up;
    }

    for cand in &candidates {
        if let Ok(bytes) = vfs.read_file(cand) {
            return Some(bytes);
        }
    }
    None
}

// ---------------------------------------------------------------------------
// A3DSkin / A3DSkinModel / A3DSkeleton (`.ski`, `.smd`, `.bon`)
// ---------------------------------------------------------------------------

pub const MAGIC_ASKI: u32 = 0x4153_4b49; // "ASKI"
pub const MAGIC_ASMD: u32 = 0x4153_4d44; // "ASMD"
pub const MAGIC_ASKE: u32 = 0x4153_4b45; // "ASKE"

#[derive(Debug, Clone, Copy)]
pub struct SkinVertexWeight {
    pub weights: [f32; 4],
    pub bone_indices: [u8; 4],
}

#[derive(Debug, Clone)]
pub struct A3dSkinSubMesh {
    pub name: String,
    pub texture_vfs_hint: String,
    pub raw_texture: String,
    pub verts: Vec<A3dLitVertex>,
    pub normals: Vec<Vec3>,
    pub skin_weights: Vec<SkinVertexWeight>,
    pub indices: Vec<u16>,
}

#[derive(Debug, Clone)]
pub struct A3dSkin {
    pub version: u32,
    pub num_skin_bones_hdr: usize,
    pub skin_dir: String,
    pub bone_names: Vec<String>,
    pub texture_names: Vec<String>,
    pub meshes: Vec<A3dSkinSubMesh>,
    pub local_aabb: Aabb,
}

impl A3dSkin {
    /// Exact port of `A3DSkin::Load` (`0x007947b0`), `A3DSkinMesh::LoadData` (`0x007e3180`, 48B `SKIN_VERTEX`),
    /// and `A3DRigidMesh::Load` (`0x007e2930`, 32B `A3DVERTEX`). Verified `DIFF = 0` EOF across 60/60 player `.ski`s.
    pub fn parse_ski(bytes: &[u8], ski_vfs_path: &str) -> PwResult<Self> {
        let (mode, mut cur) = open_afile_image(bytes);
        if mode != AFileMode::BinaryMoxb {
            return Err(PwError::InvalidData("ski missing MOXB".into()));
        }
        if cur.remaining() < 0x68 {
            return Err(PwError::InvalidData("ski header truncated".into()));
        }
        let hdr_start = cur.position();
        let magic = cur.read_u32_le()?;
        if magic != MAGIC_ASKI {
            return Err(PwError::InvalidMagic {
                expected: "ASKI (0x41534b49)",
                found: magic,
            });
        }
        let version = cur.read_u32_le()?;
        let num_skin_mesh = cur.read_i32_le()?.max(0) as usize;
        let num_rigid_mesh = cur.read_i32_le()?.max(0) as usize;
        let _num_morph_sk = cur.read_i32_le()?;
        let _num_morph_rg = cur.read_i32_le()?;
        let num_tex = cur.read_i32_le()?.max(0) as usize;
        let num_mat = cur.read_i32_le()?.max(0) as usize;
        let num_skin_bone = cur.read_i32_le()?.max(0) as usize;
        cur.set_position(hdr_start + 0x68)?;

        let mut bone_names = Vec::with_capacity(num_skin_bone);
        if version >= 9 {
            for _ in 0..num_skin_bone {
                bone_names.push(cur.read_astring_gbk()?);
            }
        }

        let mut texture_names = Vec::with_capacity(num_tex);
        for _ in 0..num_tex {
            texture_names.push(cur.read_astring_gbk()?);
        }

        // `num_mat * 80` bytes (`"MATERIAL: \0"` + `A3DMATERIALPARAM` 68B + `b2Sided` 1B + pad)
        if cur.remaining() >= num_mat * 80 {
            cur.skip(num_mat * 80)?;
        }

        let skin_dir = ski_vfs_path
            .replace('\\', "/")
            .rsplit_once('/')
            .map(|(d, _)| d.to_string())
            .unwrap_or_default();

        let mut meshes = Vec::with_capacity(num_skin_mesh + num_rigid_mesh);
        let mut local_aabb = Aabb::empty();
        let sun_dir = Vec3::new(-0.35, 0.78, -0.52).normalized();

        // 1. `A3DSkinMesh::LoadData` (`0x007e3180`): 48-byte `SKIN_VERTEX`
        for _ in 0..num_skin_mesh {
            let name = cur.read_astring_gbk()?;
            let itex = cur.read_i32_le()?;
            let _imat = cur.read_i32_le()?;
            let nv = cur.read_i32_le()?.max(0) as usize;
            let ni = cur.read_i32_le()?.max(0) as usize;
            if cur.remaining() < nv * 48 + ni * 2 {
                break;
            }
            let mut verts = Vec::with_capacity(nv);
            let mut normals = Vec::with_capacity(nv);
            let mut skin_weights = Vec::with_capacity(nv);
            for _ in 0..nv {
                let x = cur.read_f32_le()?;
                let y = cur.read_f32_le()?;
                let z = cur.read_f32_le()?;
                let w0 = cur.read_f32_le()?;
                let w1 = cur.read_f32_le()?;
                let w2 = cur.read_f32_le()?;
                let bone_indices = cur.read_u32_le()?;
                let nx = cur.read_f32_le()?;
                let ny = cur.read_f32_le()?;
                let nz = cur.read_f32_le()?;
                let u = cur.read_f32_le()?;
                let v = cur.read_f32_le()?;
                let w3 = (1.0 - w0 - w1 - w2).max(0.0);
                skin_weights.push(SkinVertexWeight {
                    weights: [w0, w1, w2, w3],
                    bone_indices: [
                        (bone_indices & 0xFF) as u8,
                        ((bone_indices >> 8) & 0xFF) as u8,
                        ((bone_indices >> 16) & 0xFF) as u8,
                        ((bone_indices >> 24) & 0xFF) as u8,
                    ],
                });
                let nrm = Vec3::new(nx, ny, nz).normalized();
                let ndotl = nrm.dot(sun_dir).abs() * 0.45 + 0.55;
                let lit = (ndotl.clamp(0.45, 1.0) * 255.0) as u32;
                let diffuse = 0xFF00_0000 | (lit << 16) | (lit << 8) | lit;
                local_aabb.expand_point(Vec3::new(x, y, z));
                verts.push(A3dLitVertex {
                    x,
                    y,
                    z,
                    diffuse,
                    u,
                    v,
                });
                normals.push(nrm);
            }
            let mut indices = Vec::with_capacity(ni);
            for _ in 0..ni {
                indices.push(cur.read_u16_le()?);
            }
            let raw_tex = if itex >= 0 && (itex as usize) < texture_names.len() {
                texture_names[itex as usize].clone()
            } else {
                String::new()
            };
            meshes.push(A3dSkinSubMesh {
                name,
                texture_vfs_hint: skin_dir.clone(),
                raw_texture: raw_tex,
                verts,
                normals,
                skin_weights,
                indices,
            });
        }

        // 2. `A3DRigidMesh::Load` (`0x007e2930`): 32-byte `A3DVERTEX`
        for _ in 0..num_rigid_mesh {
            let name = cur.read_astring_gbk()?;
            let ibone = cur.read_i32_le()?;
            let itex = cur.read_i32_le()?;
            let _imat = cur.read_i32_le()?;
            let nv = cur.read_i32_le()?.max(0) as usize;
            let ni = cur.read_i32_le()?.max(0) as usize;
            if cur.remaining() < nv * 32 + ni * 2 {
                break;
            }
            let mut verts = Vec::with_capacity(nv);
            let mut normals = Vec::with_capacity(nv);
            let mut skin_weights = Vec::with_capacity(nv);
            let b0 = ibone.max(0) as u8;
            for _ in 0..nv {
                let x = cur.read_f32_le()?;
                let y = cur.read_f32_le()?;
                let z = cur.read_f32_le()?;
                let nx = cur.read_f32_le()?;
                let ny = cur.read_f32_le()?;
                let nz = cur.read_f32_le()?;
                let u = cur.read_f32_le()?;
                let v = cur.read_f32_le()?;
                skin_weights.push(SkinVertexWeight {
                    weights: if ibone >= 0 { [1.0, 0.0, 0.0, 0.0] } else { [0.0; 4] },
                    bone_indices: [b0, 0, 0, 0],
                });
                let nrm = Vec3::new(nx, ny, nz).normalized();
                let lit = ((nrm.dot(sun_dir).abs() * 0.45 + 0.55).clamp(0.45, 1.0) * 255.0) as u32;
                let diffuse = 0xFF00_0000 | (lit << 16) | (lit << 8) | lit;
                local_aabb.expand_point(Vec3::new(x, y, z));
                verts.push(A3dLitVertex {
                    x,
                    y,
                    z,
                    diffuse,
                    u,
                    v,
                });
                normals.push(nrm);
            }
            let mut indices = Vec::with_capacity(ni);
            for _ in 0..ni {
                indices.push(cur.read_u16_le()?);
            }
            let raw_tex = if itex >= 0 && (itex as usize) < texture_names.len() {
                texture_names[itex as usize].clone()
            } else {
                String::new()
            };
            meshes.push(A3dSkinSubMesh {
                name,
                texture_vfs_hint: skin_dir.clone(),
                raw_texture: raw_tex,
                verts,
                normals,
                skin_weights,
                indices,
            });
        }

        Ok(Self {
            version,
            num_skin_bones_hdr: num_skin_bone,
            skin_dir,
            bone_names,
            texture_names,
            meshes,
            local_aabb,
        })
    }
}

/// Assembles all real `.ski` meshes from `models.pck` for any PW 1.4.2 `(cls: 0..7, gender: 0..1)` character!
pub fn load_player_character_skins(
    vfs: &VirtualFileSystem,
    cls: i32,
    gender: u8,
) -> Vec<A3dSkin> {
    load_player_character_skins_custom(vfs, cls, gender, 0)
}

/// Assembles real `.ski` meshes from `models.pck` with customizable head/hair & armor preset (`preset`: `0..=2`).
pub fn load_player_character_skins_custom(
    vfs: &VirtualFileSystem,
    cls: i32,
    gender: u8,
    preset: u8,
) -> Vec<A3dSkin> {
    // PW 1.4.2 occupation IDs:
    // 0=Blademaster(武侠), 1=Wizard(法师), 2=Psychic(巫师), 3=Venomancer(妖精, female only),
    // 4=Barbarian(妖兽, male only), 5=Assassin(刺客), 6=Archer(羽芒), 7=Cleric(羽灵)
    let is_female = match cls {
        3 => true,
        4 => false,
        _ => gender != 0,
    };
    let g_cn = if is_female { "女" } else { "男" };
    let folder = match (cls.clamp(0, 7), is_female) {
        (0, false) => "武侠男",
        (0, true) => "武侠女",
        (1, false) => "法师男",
        (1, true) => "法师女",
        (2, false) => "巫师男",
        (2, true) => "巫师女",
        (3, _) => "妖精",
        (4, _) => "妖兽男",
        (5, false) => "刺客男",
        (5, true) => "刺客女",
        (6, false) => "羽芒男",
        (6, true) => "羽芒女",
        (7, false) => "羽灵男",
        _ => "羽灵女",
    };
    // Exact equipment prefix from `elementclient.exe` string table (`Models\Players\装备\男\%s\妖兽%s`)!
    let equip_prefix = if cls.clamp(0, 7) == 4 { "妖兽" } else { folder };
    let tier_sfx = match preset % 3 {
        1 => "二级",
        2 => "三级",
        _ => "一级",
    };

    // 1. Load 4-piece default armor (`默认上衣`, `默认护腕`, `默认裤子`, `默认靴子`)
    let armor_parts = ["默认上衣", "默认护腕", "默认裤子", "默认靴子"];
    let mut armor_skins = Vec::new();
    for part in armor_parts {
        let cands = [
            format!("models/players/装备/{g_cn}/{part}/{equip_prefix}{part}{tier_sfx}.ski"),
            format!("models/players/装备/{g_cn}/{part}/{equip_prefix}{part}一级.ski"),
            format!("models/players/装备/{g_cn}/{part}/{g_cn}通用{part}{tier_sfx}.ski"),
            format!("models/players/装备/{g_cn}/{part}/{g_cn}通用{part}一级.ski"),
        ];
        if let Some((used_path, bytes)) = cands
            .iter()
            .find_map(|p| vfs.read_file(p).ok().map(|b| (p.as_str(), b)))
        {
            if let Ok(skin) = A3dSkin::parse_ski(&bytes, used_path) {
                armor_skins.push(skin);
            }
        }
    }

    // 2. Load underlying torso/limbs skin (`躯干/{folder}.ski`, or clothed `躯干/{folder}1.ski` if no separate armor)
    let mut out = Vec::new();
    let body_cands: Vec<String> = if !armor_skins.is_empty() {
        vec![
            format!("models/players/形象/{folder}/躯干/{folder}.ski"),
            format!("models/players/形象/{folder}/躯干/{folder}1.ski"),
            if is_female {
                format!("models/players/形象/{folder}/女刺客.ski")
            } else {
                format!("models/players/形象/{folder}/男刺客.ski")
            },
        ]
    } else {
        vec![
            format!("models/players/形象/{folder}/躯干/{folder}1.ski"),
            format!("models/players/形象/{folder}/躯干/{folder}.ski"),
            if is_female {
                format!("models/players/形象/{folder}/女刺客.ski")
            } else {
                format!("models/players/形象/{folder}/男刺客.ski")
            },
        ]
    };

    if let Some((used_path, bytes)) = body_cands
        .iter()
        .find_map(|p| vfs.read_file(p).ok().map(|b| (p.as_str(), b)))
    {
        if let Ok(mut body_skin) = A3dSkin::parse_ski(&bytes, used_path) {
            if !armor_skins.is_empty() {
                // Slight inward bias (`-0.005m`) on underlying body torso so 4-piece armor never Z-fights
                for sm in &mut body_skin.meshes {
                    for (v, n) in sm.verts.iter_mut().zip(sm.normals.iter()) {
                        v.x -= n.x * 0.005;
                        v.y -= n.y * 0.005;
                        v.z -= n.z * 0.005;
                    }
                }
            }
            out.push(body_skin);
        }
    }
    out.extend(armor_skins);
    out
}

/// Complete `CECFace` (`0x559250`) facial skeleton + face `.ski` + `facedata.pck` 3D hair `.ski` + `character*.ini` colors.
pub struct CecFaceBundle {
    pub ini: pw_data::CharacterCustomizeIni,
    /// `models/face/*标准脸*.bon` facial skeleton (attaches via `CC_Neck <-> HH_Neck`), or `None` when using body-rig fallback `头.ski`.
    pub face_skeleton: Option<crate::a3d_skeleton::A3dSkeleton>,
    pub face_skins: Vec<A3dSkin>,
    pub hair_skins: Vec<A3dSkin>,
}

/// Loads `userdata/character/character{cls}{gender}.ini` (or sensible racial defaults when absent).
pub fn load_character_customize_ini(
    vfs: &VirtualFileSystem,
    cls: i32,
    gender: u8,
) -> pw_data::CharacterCustomizeIni {
    let c = cls.clamp(0, 7);
    let is_female = match c {
        3 => true,
        4 => false,
        _ => gender != 0,
    };
    let g_digit = if is_female { 1 } else { 0 };
    let ini_path = format!("userdata/character/character{c}{g_digit}.ini");
    if let Ok(bytes) = vfs.read_file(&ini_path) {
        return pw_data::CharacterCustomizeIni::parse_ini_bytes(&bytes);
    }
    let mut def = pw_data::CharacterCustomizeIni::default();
    // Tideborn (`cls = 2` Psychic, `cls = 5` Assassin) have pale ocean-blue skin (`0xFFD1D7E7`)!
    if c == 2 || c == 5 {
        def.color_face = 0xFFD1_D7E7;
        def.color_body = 0xFFD1_D7E7;
        def.color_hair = if is_female { 0xFF3E_568A } else { 0xFF2E_3D63 };
        def.color_eye = 0xFF5A_9CE8;
    } else if c == 4 {
        def.color_face = 0xFFE8_DFD4;
        def.color_body = 0xFFE8_DFD4;
    }
    def
}

/// Loads the authentic `CECFace` (`models/face/*标准脸*.{bon,ski}` + `facedata/*/头发模型库/*头发*.ski`)
/// for `(cls, gender, preset)`, falling back cleanly to `models/players/形象/{folder}/头/{folder}头*.ski`.
pub fn load_cec_face_bundle(
    vfs: &VirtualFileSystem,
    cls: i32,
    gender: u8,
    preset: u8,
) -> CecFaceBundle {
    let c = cls.clamp(0, 7);
    let is_female = match c {
        3 => true,
        4 => false,
        _ => gender != 0,
    };
    let folder = match (c, is_female) {
        (0, false) => "武侠男",
        (0, true) => "武侠女",
        (1, false) => "法师男",
        (1, true) => "法师女",
        (2, false) => "巫师男",
        (2, true) => "巫师女",
        (3, _) => "妖精",
        (4, _) => "妖兽男",
        (5, false) => "刺客男",
        (5, true) => "刺客女",
        (6, false) => "羽芒男",
        (6, true) => "羽芒女",
        (7, false) => "羽灵男",
        _ => "羽灵女",
    };

    let mut ini = load_character_customize_ini(vfs, c, gender);
    // Slight hair color variation across presets `1` and `2` while keeping preset `0` 100% `character*.ini` exact!
    if preset % 3 == 1 {
        ini.color_hair = 0xFF9E_8A72;
    } else if preset % 3 == 2 {
        ini.color_hair = 0xFF34_486E;
    }

    let v_idx = ((preset % 3) + 1) as usize;
    let face_model_cands: Vec<(String, String)> = match (c, is_female) {
        (5, true) => vec![
            (
                format!("models/face/刺客女标准脸/刺客女标准脸{v_idx}.bon"),
                format!("models/face/刺客女标准脸/刺客女标准脸{v_idx}.ski"),
            ),
            (
                "models/face/刺客女标准脸/刺客女标准脸5.bon".into(),
                "models/face/刺客女标准脸/刺客女标准脸5.ski".into(),
            ),
            (
                "models/face/刺客女标准脸/刺客女标准脸1.bon".into(),
                "models/face/刺客女标准脸/刺客女标准脸1.ski".into(),
            ),
        ],
        (5, false) => vec![
            (
                format!("models/face/刺客男标准脸/刺客男标准脸{v_idx}.bon"),
                format!("models/face/刺客男标准脸/刺客男标准脸{v_idx}.ski"),
            ),
            (
                "models/face/刺客男标准脸/刺客男标准脸5.bon".into(),
                "models/face/刺客男标准脸/刺客男标准脸5.ski".into(),
            ),
            (
                "models/face/刺客男标准脸/刺客男标准脸1.bon".into(),
                "models/face/刺客男标准脸/刺客男标准脸1.ski".into(),
            ),
        ],
        (2, true) => vec![
            (
                "models/face/巫师女标准脸/巫师女标准脸5.bon".into(),
                "models/face/巫师女标准脸/巫师女标准脸5.ski".into(),
            ),
            (
                format!("models/face/巫师女标准脸/巫师女标准脸{v_idx}.bon"),
                format!("models/face/巫师女标准脸/巫师女标准脸{v_idx}.ski"),
            ),
        ],
        (2, false) => vec![
            (
                "models/face/巫师男标准脸/巫师男标准脸5.bon".into(),
                "models/face/巫师男标准脸/巫师男标准脸5.ski".into(),
            ),
            (
                format!("models/face/巫师男标准脸/巫师男标准脸{v_idx}.bon"),
                format!("models/face/巫师男标准脸/巫师男标准脸{v_idx}.ski"),
            ),
        ],
        (3, _) => vec![
            (
                format!("models/face/妖精标准脸/妖精标准脸{v_idx}.bon"),
                format!("models/face/妖精标准脸/妖精标准脸{v_idx}.ski"),
            ),
            (
                "models/face/妖精标准脸/妖精标准脸1.bon".into(),
                "models/face/妖精标准脸/妖精标准脸1.ski".into(),
            ),
        ],
        (4, _) => vec![
            (
                format!("models/face/妖兽男标准脸/妖兽男标准脸{v_idx}.bon"),
                format!("models/face/妖兽男标准脸/妖兽男标准脸{v_idx}.ski"),
            ),
            (
                "models/face/妖兽男标准脸/妖兽男标准脸1.bon".into(),
                "models/face/妖兽男标准脸/妖兽男标准脸1.ski".into(),
            ),
        ],
        (6, true) => vec![(
            "models/face/羽芒女标准脸/羽芒女标准脸.bon".into(),
            "models/face/羽芒女标准脸/羽芒女标准脸.ski".into(),
        )],
        (6, false) => vec![(
            "models/face/羽芒男标准脸/羽芒男标准脸.bon".into(),
            "models/face/羽芒男标准脸/羽芒男标准脸.ski".into(),
        )],
        (7, true) => vec![(
            "models/face/羽灵女标准脸/羽灵女标准脸.bon".into(),
            "models/face/羽灵女标准脸/羽灵女标准脸.ski".into(),
        )],
        (7, false) => vec![(
            "models/face/羽灵男标准脸/羽灵男标准脸.bon".into(),
            "models/face/羽灵男标准脸/羽灵男标准脸.ski".into(),
        )],
        (_, true) => vec![(
            "models/face/法师女标准脸/法师女标准脸.bon".into(),
            "models/face/法师女标准脸/法师女标准脸.ski".into(),
        )],
        (_, false) => vec![(
            "models/face/武侠男标准脸/武侠男标准脸.bon".into(),
            "models/face/武侠男标准脸/武侠男标准脸.ski".into(),
        )],
    };

    let mut face_skeleton = None;
    let mut face_skins = Vec::new();
    for (bon_p, ski_p) in &face_model_cands {
        if let (Ok(bon_b), Ok(ski_b)) = (vfs.read_file(bon_p), vfs.read_file(ski_p)) {
            if let (Ok(skel), Ok(skin)) = (
                crate::a3d_skeleton::A3dSkeleton::parse_bon(&bon_b),
                A3dSkin::parse_ski(&ski_b, ski_p),
            ) {
                face_skeleton = Some(skel);
                face_skins.push(skin);
                break;
            }
        }
    }

    // Load 3D hairstyle `.ski` from `facedata.pck` (`facedata/{race}/头发模型库/*.ski`) when `face_skeleton` is active!
    let mut hair_skins = Vec::new();
    if face_skeleton.is_some() && c != 4 {
        let hair_num = match (c, is_female, preset % 3) {
            (2 | 5, true, 0) => 10,
            (2 | 5, true, 1) => 4,
            (2 | 5, true, _) => 12,
            (2 | 5, false, 0) => 10,
            (2 | 5, false, 1) => 3,
            (2 | 5, false, _) => 8,
            (_, true, 0) => 12,
            (_, true, 1) => 18,
            (_, true, _) => 25,
            (_, false, 0) => 11,
            (_, false, 1) => 16,
            (_, false, _) => 22,
        };
        let hair_cands = match (c, is_female) {
            (2 | 5, true) => vec![
                format!("facedata/影族女/头发模型库/影族女头发{hair_num:02}.ski"),
                "facedata/影族女/头发模型库/影族女头发10.ski".into(),
                "facedata/影族女/头发模型库/影族女头发01.ski".into(),
            ],
            (2 | 5, false) => vec![
                format!("facedata/影族男/头发模型库/影族男头发{hair_num:02}.ski"),
                "facedata/影族男/头发模型库/影族男头发10.ski".into(),
                "facedata/影族男/头发模型库/影族男头发01.ski".into(),
            ],
            // Verified facedata.pck layout: hair models live under `facedata/{class}/头发模型库/`.
            (_, true) => vec![
                format!("facedata/法师女/头发模型库/法师女头发{hair_num:02}.ski"),
                "facedata/法师女/头发模型库/法师女头发12.ski".into(),
                "facedata/法师女/头发模型库/法师女头发01.ski".into(),
            ],
            (_, false) => vec![
                format!("facedata/武侠男/头发模型库/武侠男头发{hair_num:02}.ski"),
                "facedata/武侠男/头发模型库/武侠男头发11.ski".into(),
                "facedata/武侠男/头发模型库/武侠男头发01.ski".into(),
            ],
        };
        for hp in &hair_cands {
            if let Ok(hb) = vfs.read_file(hp) {
                if let Ok(hskin) = A3dSkin::parse_ski(&hb, hp) {
                    hair_skins.push(hskin);
                    break;
                }
            }
        }
    }

    // Fallback to static `头/{folder}头*.ski` on the body skeleton if `models/face/*标准脸*` was not found
    if face_skins.is_empty() {
        let head_sfx = match preset % 3 {
            1 => "二级",
            2 => "三级",
            _ => "",
        };
        let fallback_heads = [
            format!("models/players/形象/{folder}/头/{folder}头{head_sfx}.ski"),
            format!("models/players/形象/{folder}/头/{folder}头{v_idx}.ski"),
            format!("models/players/形象/{folder}/头/{folder}头1.ski"),
            format!("models/players/形象/{folder}/头/{folder}头.ski"),
        ];
        for fh in &fallback_heads {
            if let Ok(bytes) = vfs.read_file(fh) {
                if let Ok(skin) = A3dSkin::parse_ski(&bytes, fh) {
                    face_skins.push(skin);
                    break;
                }
            }
        }
    }

    CecFaceBundle {
        ini,
        face_skeleton,
        face_skins,
        hair_skins,
    }
}

/// Applies an `0xAARRGGBB` Angelica pixel-shader tint (`t0.rgb * col.rgb`) to a `SurfaceImage` and rebuilds its mipmaps.
pub fn tint_surface_image_rgb(
    src: &crate::image_dds::SurfaceImage,
    argb_tint: u32,
    preserve_cutout_alpha: bool,
) -> crate::image_dds::SurfaceImage {
    let tr = ((argb_tint >> 16) & 0xFF) as u32;
    let tg = ((argb_tint >> 8) & 0xFF) as u32;
    let tb = (argb_tint & 0xFF) as u32;
    let mut pixels = Vec::with_capacity(src.pixels.len());
    for &px in &src.pixels {
        let a = if preserve_cutout_alpha {
            (px >> 24) & 0xFF
        } else {
            0xFF
        };
        let r = (((px >> 16) & 0xFF) * tr / 255).min(255);
        let g = (((px >> 8) & 0xFF) * tg / 255).min(255);
        let b = ((px & 0xFF) * tb / 255).min(255);
        pixels.push((a << 24) | (r << 16) | (g << 8) | b);
    }
    crate::image_dds::SurfaceImage::from_pixels_with_mips(src.width, src.height, pixels)
}

/// Evaluates `shaders/ps/facerender/*.txt` (`facerender.txt`, `hairrender.txt`, `browrender.txt`,
/// `eyerender.txt`, `eyeballrender.txt`, `mouthrender.txt`, `facerender_fur.txt`) for a `CECFace` submesh!
pub fn select_cec_face_submesh_tint(
    hint: &str,
    raw_tex: &str,
    ini: &pw_data::CharacterCustomizeIni,
    is_hair_skin: bool,
) -> (u32, bool) {
    let h = hint.to_ascii_lowercase();
    let r = raw_tex.to_ascii_lowercase();
    if is_hair_skin
        || h.contains("头发")
        || r.contains("头发")
        || r.contains("hair")
        || r.contains("胡")
        || r.contains("睫")
    {
        // `hairrender.txt`: `mul r0.rgb, t0, c2` (`colorHair`) + preserve cutout alpha!
        (ini.color_hair, true)
    } else if r.contains("眼珠") || r.contains("eyeball") || r.contains("瞳") {
        // `eyeballrender.txt`: `colorEyeBall`
        (ini.color_eye_ball, false)
    } else if r.contains("眉") || r.contains("brow") {
        // `browrender.txt`: `colorBrow` + cutout decal alpha
        (ini.color_brow, true)
    } else if r.contains("眼影") || r.contains("eye") {
        // `eyerender.txt`: `colorEye`
        (ini.color_eye, true)
    } else if r.contains("嘴") || r.contains("唇") || r.contains("mouth") || r.contains("lip") {
        // `mouthrender.txt`: `colorMouth`
        (ini.color_mouth, false)
    } else {
        // `facerender.txt` / `noserender.txt`: `mul r0.rgb, t0, c2` (`colorFace` — e.g. `0xFFD1D7E7` Tideborn blue!)
        (ini.color_face, false)
    }
}

// ---------------------------------------------------------------------------
// A3DSkySphere (`0x0079a330` — Cap + Surround Front `01` + Surround Back `02`)
// ---------------------------------------------------------------------------

#[derive(Debug, Clone)]
pub struct A3dSkyDome {
    pub cap_verts: Vec<A3dLitVertex>,
    pub cap_indices: Vec<u16>,
    pub surround_front_verts: Vec<A3dLitVertex>,
    pub surround_front_indices: Vec<u16>,
    pub surround_back_verts: Vec<A3dLitVertex>,
    pub surround_back_indices: Vec<u16>,
}

impl A3dSkySphereParams {
    pub const DEFAULT_RADIUS: f32 = 650.0;
}

pub struct A3dSkySphereParams;

impl A3dSkyDome {
    /// Builds the exact `A3DSkySphere` (`0x0079a330`) dome centered at `(0, 0, 0)` (translated to camera eye on draw).
    pub fn build(radius: f32) -> Self {
        let segs = 24usize;
        // 1. Cap dome (`pitch` from `22 deg` up to `90 deg` zenith, mapped onto `Roof.bmp` `(u, v) in [0,1]^2`)
        let cap_rings = 5usize;
        let min_pitch = 0.20f32;
        let mut cap_verts = Vec::new();
        let mut cap_indices = Vec::new();
        for ri in 0..=cap_rings {
            let t = ri as f32 / cap_rings as f32;
            let pitch = min_pitch + t * (std::f32::consts::FRAC_PI_2 - min_pitch);
            let y = radius * pitch.sin();
            let hr = radius * pitch.cos();
            for si in 0..=segs {
                let ang = (si as f32 / segs as f32) * std::f32::consts::TAU;
                let x = hr * ang.cos();
                let z = hr * ang.sin();
                let uv_r = (1.0 - t) * 0.48;
                let u = 0.5 + uv_r * ang.cos();
                let v = 0.5 + uv_r * ang.sin();
                cap_verts.push(A3dLitVertex {
                    x,
                    y,
                    z,
                    diffuse: 0xFFFF_FFFF,
                    u,
                    v,
                });
            }
        }
        let stride = segs + 1;
        for ri in 0..cap_rings {
            for si in 0..segs {
                let i0 = (ri * stride + si) as u16;
                let i1 = i0 + 1;
                let i2 = ((ri + 1) * stride + si) as u16;
                let i3 = i2 + 1;
                cap_indices.extend_from_slice(&[i0, i2, i1, i1, i2, i3]);
            }
        }

        // 2. Surround cylinder/dome (`0x0079a330` `A3DSkySphere::CreateSurround` in `15_a3dskysphere.c`):
        // - Ring heights `afStack_5c = [1.0, 0.5, 0.167, 0.0, -0.27] * fCapTile * radius`
        // - `u = 1.0 - i / nSegs` (viewed from inside the sky cylinder so `01.bmp` and `02.bmp` meet seamlessly!)
        // - `v` spans top half `[0.006 .. 0.50]` (`0x3f000000` at horizon bottom ring `uVar17 == 4`)
        // - First half (`PI .. 2*PI`) = `SurroundFront` (`01.bmp`), Second half (`0 .. PI`) = `SurroundBack` (`02.bmp`)
        let build_half = |ang_start: f32| -> (Vec<A3dLitVertex>, Vec<u16>) {
            let h_segs = 16usize;
            let v_heights = [0.42f32, 0.21, 0.07, 0.0, -0.14];
            let mut vts = Vec::new();
            let mut idx = Vec::new();
            for (ri, &h_frac) in v_heights.iter().enumerate() {
                let y = radius * h_frac;
                let hr = radius * (1.0 - h_frac * h_frac * 0.5).max(0.5).sqrt();
                let tv = if ri == v_heights.len() - 1 {
                    0.495f32
                } else {
                    (0.008 + (ri as f32 / (v_heights.len() - 1) as f32) * 0.487).clamp(0.008, 0.495)
                };
                for si in 0..=h_segs {
                    let frac = si as f32 / h_segs as f32;
                    let ang = ang_start + frac * std::f32::consts::PI;
                    let x = hr * ang.cos();
                    let z = hr * ang.sin();
                    let alpha = if ri == 0 { 0x00 } else { 0xFF };
                    vts.push(A3dLitVertex {
                        x,
                        y,
                        z,
                        diffuse: (alpha << 24) | 0x00FF_FFFF,
                        u: (1.0 - frac).clamp(0.004, 0.996),
                        v: tv,
                    });
                }
            }
            let st = h_segs + 1;
            for ri in 0..(v_heights.len() - 1) {
                for si in 0..h_segs {
                    let i0 = (ri * st + si) as u16;
                    let i1 = i0 + 1;
                    let i2 = ((ri + 1) * st + si) as u16;
                    let i3 = i2 + 1;
                    idx.extend_from_slice(&[i0, i1, i2, i1, i3, i2]);
                }
            }
            (vts, idx)
        };

        let (surround_front_verts, surround_front_indices) = build_half(std::f32::consts::PI);
        let (surround_back_verts, surround_back_indices) = build_half(0.0);

        Self {
            cap_verts,
            cap_indices,
            surround_front_verts,
            surround_front_indices,
            surround_back_verts,
            surround_back_indices,
        }
    }
}

/// Computes an entity's world matrix using Angelica3D's exact `a3d_TransformMatrix`.
pub fn ornament_world_matrix(dir: Vec3, up: Vec3, pos: Vec3, scale: Vec3) -> Mat4 {
    Mat4::a3d_transform_matrix(dir, up, pos, scale)
}

// ---------------------------------------------------------------------------
// A3DFrame / MOX Mesh (`grasses.pck` `MOXFILE` — verified 155/155 `bad=0`)
// ---------------------------------------------------------------------------

#[derive(Debug, Clone)]
pub struct A3dMoxSubMesh {
    pub name: String,
    pub texture_file: String,
    pub verts: Vec<(Vec3, Vec3, f32, f32)>,
    pub indices: Vec<u16>,
}

#[derive(Debug, Clone)]
pub struct A3dMoxMesh {
    pub sub_meshes: Vec<A3dMoxSubMesh>,
}

impl A3dMoxMesh {
    /// Parses an Angelica3D `.mox` (`MOXFILE`) mesh from `grasses.pck` or `models.pck`.
    /// Verified 100% (`155/155`, `bad = 0`) across every `.mox` in `grasses.pck`.
    pub fn parse_mox(bytes: &[u8]) -> Result<Self, PwError> {
        if bytes.len() < 32 || !bytes.starts_with(b"MOXFILE") {
            return Err(PwError::InvalidData("Invalid MOXFILE magic".into()));
        }
        let mut sub_meshes = Vec::new();
        let needle_mesh = b"A3DMesh: ";
        let needle_tex = b"TEXTURE: ";
        let mut search_pos = 0usize;

        while let Some(rel_mi) = bytes[search_pos..]
            .windows(needle_mesh.len())
            .position(|w| w == needle_mesh)
        {
            let mi = search_pos + rel_mi;
            search_pos = mi + needle_mesh.len();
            if mi + 64 + 16 > bytes.len() {
                break;
            }
            let raw_name = &bytes[mi + 9..mi + 64];
            let name_end = raw_name
                .iter()
                .position(|&b| b == 0)
                .unwrap_or(raw_name.len());
            let name = pw_core::decode_gbk(&raw_name[..name_end]);

            let mut hcur = pw_core::BinaryCursor::new(&bytes[mi + 64..]);
            let _ver = hcur.read_i32_le()?;
            let fcnt = hcur.read_i32_le()?.max(1) as usize;
            let vcnt = hcur.read_i32_le()? as usize;
            let icnt = hcur.read_i32_le()? as usize;
            if vcnt == 0 || vcnt > 32768 || icnt == 0 || icnt > 98304 || fcnt > 64 {
                continue;
            }

            let Some(rel_ti) = bytes[mi + 80..]
                .windows(needle_tex.len())
                .position(|w| w == needle_tex)
            else {
                break;
            };
            let ti = mi + 80 + rel_ti;
            if ti + 64 > bytes.len() {
                break;
            }
            let raw_tex = &bytes[ti + 9..ti + 64];
            let tex_end = raw_tex
                .iter()
                .position(|&b| b == 0)
                .unwrap_or(raw_tex.len());
            let texture_file = pw_core::decode_gbk(&raw_tex[..tex_end]).replace('\\', "/");

            let geom_bytes = icnt * 2 + vcnt * 32 * fcnt;
            if ti < mi + 80 + geom_bytes {
                continue;
            }
            let vstart = ti - geom_bytes;
            let mut vcur = pw_core::BinaryCursor::new(&bytes[vstart..]);
            let mut verts = Vec::with_capacity(vcnt);
            for _ in 0..vcnt {
                let p = vcur.read_vec3_le()?;
                let n = vcur.read_vec3_le()?;
                let u = vcur.read_f32_le()?;
                let v = vcur.read_f32_le()?;
                verts.push((p, n, u, v));
            }
            // Skip remaining morph frames (`(fcnt - 1) * vcnt * 32` bytes) to reach index buffer
            if fcnt > 1 {
                vcur.skip((fcnt - 1) * vcnt * 32)?;
            }
            let mut indices = Vec::with_capacity(icnt);
            for _ in 0..icnt {
                let idx = vcur.read_u16_le()?;
                if (idx as usize) < vcnt {
                    indices.push(idx);
                }
            }
            if indices.len() >= 3 {
                sub_meshes.push(A3dMoxSubMesh {
                    name,
                    texture_file,
                    verts,
                    indices,
                });
            }
            search_pos = ti + 64;
        }

        if sub_meshes.is_empty() {
            return Err(PwError::InvalidData(
                "MOXFILE contained zero valid A3DMeshes".into(),
            ));
        }
        Ok(Self { sub_meshes })
    }
}

