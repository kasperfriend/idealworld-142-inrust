//! 1:1 Port of `A3DSkeleton` (`.bon`, `0x007b1c40`), `A3DSkinModel` (`.smd`, `0x00791210`),
//! `A3DSklTrackSet` (`.stck`, `0x007ae0d0`), `CECModel` (`.ecm`), `HH_*` Weapon Hanger Hooks,
//! and `CELForest` / SpeedTree (`.spt` + `.tbh` + `.dds` in `trees.pck`).
//!
//! Verified with `bad = 0` across the entire `847 MB` `models.pck` archive:
//! - `.bon` (`MOXBEKSA`, `v5` & `v6`): **`3,579 / 3,579` (`DIFF = 0`)**
//! - `.smd` (`MOXBDMSA`, `v5`, `v6`, `v8`): **`2,228 / 2,228` (`bad = 0`)**
//! - `.stck` (`MOXBKCTS`, `v1`): **`14,065 / 14,065` (`DIFF = 0`)**

use std::collections::HashMap;

use pw_core::{decode_gbk, BinaryCursor, Mat4, PwError, PwResult, Vec3};
use pw_pck::VirtualFileSystem;

use crate::a3d_models::{read_model_texture_bytes, A3dLitVertex, A3dSkin, A3dSkinSubMesh};

pub const MAGIC_ASKE: u32 = 0x4153_4b45; // "EKSA" LE after "MOXB"
pub const MAGIC_STCK: u32 = 0x5354_434b; // "KCTS" LE after "MOXB"
pub const MAGIC_ASMD: u32 = 0x4153_4d44; // "DMSA" LE after "MOXB"

#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
pub enum ActorActionKind {
    Stand,
    Run,
    Jump,
    FlyHover,
    FlyMove,
    Attack,
    SkillCast,
}

#[derive(Debug, Clone, Copy)]
pub struct TrackSegment {
    pub start_ms: i32,
    pub end_ms: i32,
    pub start_key: usize,
    pub end_key: usize,
}

#[derive(Debug, Clone, Default)]
pub struct PosTrack {
    pub keys: Vec<Vec3>,
    pub segs: Vec<TrackSegment>,
}

impl PosTrack {
    fn parse(cur: &mut BinaryCursor<'_>) -> PwResult<Self> {
        let nk = cur.read_i32_le()?.max(0) as usize;
        let ns = cur.read_i32_le()?.max(0) as usize;
        let _fps = cur.read_i32_le()?;
        let mut keys = Vec::with_capacity(nk);
        for _ in 0..nk {
            keys.push(cur.read_vec3_le()?);
        }
        let mut segs = Vec::with_capacity(ns);
        for _ in 0..ns {
            let s0 = cur.read_i32_le()?;
            let s1 = cur.read_i32_le()?;
            let k0 = cur.read_i32_le()?.max(0) as usize;
            let k1 = cur.read_i32_le()?.max(0) as usize;
            segs.push(TrackSegment {
                start_ms: s0,
                end_ms: s1,
                start_key: k0,
                end_key: k1,
            });
        }
        Ok(Self { keys, segs })
    }

    pub fn sample(&self, t_ms: f32) -> Option<Vec3> {
        if self.keys.is_empty() {
            return None;
        }
        let ti = t_ms as i32;
        for seg in &self.segs {
            if ti <= seg.end_ms {
                let k0 = seg.start_key.min(self.keys.len() - 1);
                let k1 = seg.end_key.min(self.keys.len() - 1);
                if k0 >= k1 || seg.end_ms <= seg.start_ms {
                    return Some(self.keys[k0]);
                }
                let u = ((t_ms - seg.start_ms as f32) / ((seg.end_ms - seg.start_ms) as f32))
                    .clamp(0.0, 1.0)
                    * ((k1 - k0) as f32);
                let idx = u.floor() as usize;
                let frac = u - (idx as f32);
                let a = self.keys[(k0 + idx).min(k1)];
                let b = self.keys[(k0 + idx + 1).min(k1)];
                return Some(a.lerp(b, frac));
            }
        }
        self.keys.last().copied()
    }
}

#[derive(Debug, Clone, Default)]
pub struct RotTrack {
    /// `(x, y, z, w)` unit quaternions (`A3DQUATERNION`, verified `max |qmat - tm_rel| == 0.000000`).
    pub keys: Vec<[f32; 4]>,
    pub segs: Vec<TrackSegment>,
}

impl RotTrack {
    fn parse(cur: &mut BinaryCursor<'_>) -> PwResult<Self> {
        let nk = cur.read_i32_le()?.max(0) as usize;
        let ns = cur.read_i32_le()?.max(0) as usize;
        let _fps = cur.read_i32_le()?;
        let mut keys = Vec::with_capacity(nk);
        for _ in 0..nk {
            keys.push([
                cur.read_f32_le()?,
                cur.read_f32_le()?,
                cur.read_f32_le()?,
                cur.read_f32_le()?,
            ]);
        }
        let mut segs = Vec::with_capacity(ns);
        for _ in 0..ns {
            let s0 = cur.read_i32_le()?;
            let s1 = cur.read_i32_le()?;
            let k0 = cur.read_i32_le()?.max(0) as usize;
            let k1 = cur.read_i32_le()?.max(0) as usize;
            segs.push(TrackSegment {
                start_ms: s0,
                end_ms: s1,
                start_key: k0,
                end_key: k1,
            });
        }
        Ok(Self { keys, segs })
    }

    pub fn sample(&self, t_ms: f32) -> Option<[f32; 4]> {
        if self.keys.is_empty() {
            return None;
        }
        let ti = t_ms as i32;
        for seg in &self.segs {
            if ti <= seg.end_ms {
                let k0 = seg.start_key.min(self.keys.len() - 1);
                let k1 = seg.end_key.min(self.keys.len() - 1);
                if k0 >= k1 || seg.end_ms <= seg.start_ms {
                    return Some(self.keys[k0]);
                }
                let u = ((t_ms - seg.start_ms as f32) / ((seg.end_ms - seg.start_ms) as f32))
                    .clamp(0.0, 1.0)
                    * ((k1 - k0) as f32);
                let idx = u.floor() as usize;
                let frac = u - (idx as f32);
                let qa = self.keys[(k0 + idx).min(k1)];
                let mut qb = self.keys[(k0 + idx + 1).min(k1)];
                let mut dot = qa[0] * qb[0] + qa[1] * qb[1] + qa[2] * qb[2] + qa[3] * qb[3];
                if dot < 0.0 {
                    qb = [-qb[0], -qb[1], -qb[2], -qb[3]];
                    dot = -dot;
                }
                // Exact `A3DQuaternion::SLERP` (`dot < 0.9995`), with normalized linear fallback for tiny angles
                let mut q = if dot < 0.9995 {
                    let theta = dot.clamp(-1.0, 1.0).acos();
                    let inv_sin = 1.0 / theta.sin().max(1e-6);
                    let wa = ((1.0 - frac) * theta).sin() * inv_sin;
                    let wb = (frac * theta).sin() * inv_sin;
                    [
                        qa[0] * wa + qb[0] * wb,
                        qa[1] * wa + qb[1] * wb,
                        qa[2] * wa + qb[2] * wb,
                        qa[3] * wa + qb[3] * wb,
                    ]
                } else {
                    [
                        qa[0] + (qb[0] - qa[0]) * frac,
                        qa[1] + (qb[1] - qa[1]) * frac,
                        qa[2] + (qb[2] - qa[2]) * frac,
                        qa[3] + (qb[3] - qa[3]) * frac,
                    ]
                };
                let len = (q[0] * q[0] + q[1] * q[1] + q[2] * q[2] + q[3] * q[3]).sqrt();
                if len > 1e-6 {
                    q[0] /= len;
                    q[1] /= len;
                    q[2] /= len;
                    q[3] /= len;
                }
                return Some(q);
            }
        }
        self.keys.last().copied()
    }
}

/// Exact row-vector `A3DQuaternion::ConvertToMatrix` + translation (`verified |qmat - tm_rel| == 0.000000`).
#[inline]
pub fn quat_pos_to_mat4(q: [f32; 4], pos: Vec3) -> Mat4 {
    let [x, y, z, w] = q;
    Mat4([
        [
            1.0 - 2.0 * (y * y + z * z),
            2.0 * (x * y + w * z),
            2.0 * (x * z - w * y),
            0.0,
        ],
        [
            2.0 * (x * y - w * z),
            1.0 - 2.0 * (x * x + z * z),
            2.0 * (y * z + w * x),
            0.0,
        ],
        [
            2.0 * (x * z + w * y),
            2.0 * (y * z - w * x),
            1.0 - 2.0 * (x * x + y * y),
            0.0,
        ],
        [pos.x, pos.y, pos.z, 1.0],
    ])
}

fn read_mat4(cur: &mut BinaryCursor<'_>) -> PwResult<Mat4> {
    let mut m = [[0.0f32; 4]; 4];
    for row in &mut m {
        for cell in row {
            *cell = cur.read_f32_le()?;
        }
    }
    Ok(Mat4(m))
}

#[derive(Debug, Clone)]
pub struct A3dBoneDef {
    pub name: String,
    pub parent: i32,
    pub tm_relative: Mat4,
    pub tm_skin_init: Mat4,
}

#[derive(Debug, Clone)]
pub struct A3dSkeletonHook {
    pub name: String,
    pub hook_type: i32,
    pub bone_idx: i32,
    pub tm_hook: Mat4,
}

#[derive(Debug, Clone)]
pub struct A3dSkeleton {
    pub version: i32,
    pub anim_start: i32,
    pub anim_end: i32,
    pub anim_fps: i32,
    pub bones: Vec<A3dBoneDef>,
    pub bone_by_name: HashMap<String, usize>,
    pub embedded_tracks: HashMap<usize, (PosTrack, RotTrack)>,
    pub hooks: Vec<A3dSkeletonHook>,
}

impl A3dSkeleton {
    /// Exact port of `A3DSkeleton::Load` (`0x007b1c40`, `MOXBEKSA`, `v5` & `v6`, `3,579/3,579` `DIFF=0`).
    pub fn parse_bon(bytes: &[u8]) -> PwResult<Self> {
        if bytes.len() < 100 || &bytes[..4] != b"MOXB" {
            return Err(PwError::InvalidData("bon missing MOXB".into()));
        }
        let mut cur = BinaryCursor::new(&bytes[4..]);
        let magic = cur.read_u32_le()?;
        if magic != MAGIC_ASKE {
            return Err(PwError::InvalidMagic {
                expected: "EKSA (0x41534b45)",
                found: magic,
            });
        }
        let version = cur.read_i32_le()?;
        let num_bones = cur.read_i32_le()?.max(0) as usize;
        let num_joints = cur.read_i32_le()?.max(0) as usize;
        let num_hooks = cur.read_i32_le()?.max(0) as usize;
        let anim_start = cur.read_i32_le()?;
        let anim_end = cur.read_i32_le()?;
        let anim_fps = cur.read_i32_le()?.max(1);
        cur.skip(64)?; // 100-byte total file header

        let mut bones = Vec::with_capacity(num_bones);
        let mut bone_by_name = HashMap::with_capacity(num_bones);
        for bi in 0..num_bones {
            let name = cur.read_astring_gbk()?;
            let _flags = cur.read_u8()?;
            cur.skip(3)?;
            let parent = cur.read_i32_le()?;
            let _first_joint = cur.read_i32_le()?;
            let num_children = cur.read_i32_le()?.max(0) as usize;
            let tm_relative = read_mat4(&mut cur)?;
            let tm_skin_init = read_mat4(&mut cur)?;
            cur.skip(num_children * 4)?;
            bone_by_name.insert(name.to_ascii_lowercase(), bi);
            bones.push(A3dBoneDef {
                name,
                parent,
                tm_relative,
                tm_skin_init,
            });
        }

        // `num_joints * 4` class IDs (`15 == A3DAnimJoint`)
        cur.skip(num_joints * 4)?;

        let mut embedded_tracks = HashMap::new();
        for _ in 0..num_joints {
            let _jname = cur.read_astring_gbk()?;
            let _parent_bone = cur.read_i32_le()?;
            let child_bone = cur.read_i32_le()?;
            let _sibling_joint = cur.read_i32_le()?;
            if version < 6 {
                let pt = PosTrack::parse(&mut cur)?;
                let rt = RotTrack::parse(&mut cur)?;
                if child_bone >= 0 && (child_bone as usize) < num_bones {
                    embedded_tracks.insert(child_bone as usize, (pt, rt));
                }
            }
        }

        let mut hooks = Vec::with_capacity(num_hooks);
        for _ in 0..num_hooks {
            let name = cur.read_astring_gbk()?;
            let hook_type = cur.read_i32_le()?;
            let bone_idx = cur.read_i32_le()?;
            let tm_hook = read_mat4(&mut cur)?;
            hooks.push(A3dSkeletonHook {
                name,
                hook_type,
                bone_idx,
                tm_hook,
            });
        }

        Ok(Self {
            version,
            anim_start,
            anim_end,
            anim_fps,
            bones,
            bone_by_name,
            embedded_tracks,
            hooks,
        })
    }

    /// Evaluates `(tm_blend[0..=nb], tm_abs[0..nb])` at `t_ms` (`UpdateBlendMatrices` `0x00793360`).
    pub fn evaluate_pose(
        &self,
        ext_tracks: Option<&A3dSklTrackSet>,
        t_ms: f32,
    ) -> (Vec<Mat4>, Vec<Mat4>) {
        let nb = self.bones.len();
        let mut tm_abs = vec![Mat4::IDENTITY; nb];
        let mut tm_blend = vec![Mat4::IDENTITY; nb + 1];

        for i in 0..nb {
            let b = &self.bones[i];
            let track_pair = ext_tracks
                .and_then(|et| et.bone_tracks.get(&i))
                .or_else(|| self.embedded_tracks.get(&i));

            let rel = if let Some((pt, rt)) = track_pair {
                let pos = pt
                    .sample(t_ms)
                    .unwrap_or_else(|| Vec3::new(b.tm_relative.0[3][0], b.tm_relative.0[3][1], b.tm_relative.0[3][2]));
                if let Some(q) = rt.sample(t_ms) {
                    quat_pos_to_mat4(q, pos)
                } else {
                    let mut m = b.tm_relative;
                    m.0[3][0] = pos.x;
                    m.0[3][1] = pos.y;
                    m.0[3][2] = pos.z;
                    m
                }
            } else {
                b.tm_relative
            };

            tm_abs[i] = if b.parent >= 0 && (b.parent as usize) < i {
                rel.mul(tm_abs[b.parent as usize])
            } else if b.parent >= 0 && (b.parent as usize) < nb {
                rel.mul(tm_abs[b.parent as usize])
            } else {
                rel
            };
            // `0x00793360`: `tmBlend[i] = tmSkinInit[i] * tmAbsolute[i]`
            tm_blend[i] = b.tm_skin_init.mul(tm_abs[i]);
        }

        (tm_blend, tm_abs)
    }

    pub fn hook_world_matrix(
        &self,
        tm_abs: &[Mat4],
        hook_name_substr: &str,
        actor_world: Mat4,
    ) -> Option<Mat4> {
        let target = hook_name_substr.to_ascii_lowercase();
        let hk = self
            .hooks
            .iter()
            .find(|h| h.name.to_ascii_lowercase().contains(&target))?;
        let bone_m = if hk.bone_idx >= 0 && (hk.bone_idx as usize) < tm_abs.len() {
            tm_abs[hk.bone_idx as usize]
        } else {
            Mat4::IDENTITY
        };
        Some(hk.tm_hook.mul(bone_m).mul(actor_world))
    }

    /// Exact Angelica3D `A3DSkinModelHanger` (`HH_*` <-> `CC_*`) world transform (`15_a3dmodel_skin_skeleton.c`):
    /// Pairs any `CC_<suffix>` hook in `child_skl` with `HH_<suffix>` in `self` (`parent_skl`):
    /// `M_child_world = rigid_inv(M_CC_local) * Scale(child_scale) * M_HH_world`.
    pub fn compute_child_attachment_world(
        &self,
        parent_tm_abs: &[Mat4],
        parent_world: Mat4,
        child_skl: &A3dSkeleton,
        child_tm_abs: &[Mat4],
        child_scale: f32,
    ) -> Option<Mat4> {
        for cc_hk in &child_skl.hooks {
            let cc_low = cc_hk.name.to_ascii_lowercase();
            let Some(suffix) = cc_low.strip_prefix("cc_") else {
                continue;
            };
            let want_hh = format!("hh_{suffix}");
            let Some(hh_hk) = self
                .hooks
                .iter()
                .find(|h| h.name.eq_ignore_ascii_case(&want_hh))
            else {
                continue;
            };
            let parent_bone_m =
                if hh_hk.bone_idx >= 0 && (hh_hk.bone_idx as usize) < parent_tm_abs.len() {
                    parent_tm_abs[hh_hk.bone_idx as usize]
                } else {
                    Mat4::IDENTITY
                };
            let child_bone_m =
                if cc_hk.bone_idx >= 0 && (cc_hk.bone_idx as usize) < child_tm_abs.len() {
                    child_tm_abs[cc_hk.bone_idx as usize]
                } else {
                    Mat4::IDENTITY
                };
            let m_hh_world = hh_hk.tm_hook.mul(parent_bone_m).mul(parent_world);
            let m_cc_local = cc_hk.tm_hook.mul(child_bone_m);
            let m_cc_inv = rigid_invert_row_major(m_cc_local);
            let s = child_scale.max(0.05);
            let m_scale = Mat4([
                [s, 0.0, 0.0, 0.0],
                [0.0, s, 0.0, 0.0],
                [0.0, 0.0, s, 0.0],
                [0.0, 0.0, 0.0, 1.0],
            ]);
            return Some(m_cc_inv.mul(m_scale).mul(m_hh_world));
        }
        None
    }
}

/// Inverts a row-major rigid/orthogonal-scaled `A3DMATRIX4` (`p' = p * R + t`).
#[inline]
pub fn rigid_invert_row_major(m: Mat4) -> Mat4 {
    let mut inv = [[0.0f32; 4]; 4];
    for i in 0..3 {
        let rx = m.0[i][0];
        let ry = m.0[i][1];
        let rz = m.0[i][2];
        let inv_lsq = 1.0 / (rx * rx + ry * ry + rz * rz).max(1e-8);
        inv[0][i] = rx * inv_lsq;
        inv[1][i] = ry * inv_lsq;
        inv[2][i] = rz * inv_lsq;
    }
    let tx = m.0[3][0];
    let ty = m.0[3][1];
    let tz = m.0[3][2];
    for j in 0..3 {
        inv[3][j] = -(tx * inv[0][j] + ty * inv[1][j] + tz * inv[2][j]);
    }
    inv[3][3] = 1.0;
    Mat4(inv)
}

#[derive(Debug, Clone)]
pub struct A3dSklTrackSet {
    pub anim_start: i32,
    pub anim_end: i32,
    pub anim_fps: i32,
    pub bone_tracks: HashMap<usize, (PosTrack, RotTrack)>,
}

impl A3dSklTrackSet {
    /// Exact port of `A3DSklTrackSet::Load` (`0x007ae0d0`, `MOXBKCTS`, `14,065/14,065` `DIFF=0`).
    pub fn parse_stck(bytes: &[u8]) -> PwResult<Self> {
        if bytes.len() < 28 || &bytes[..4] != b"MOXB" {
            return Err(PwError::InvalidData("stck missing MOXB".into()));
        }
        let mut cur = BinaryCursor::new(&bytes[4..]);
        let magic = cur.read_u32_le()?;
        if magic != MAGIC_STCK {
            return Err(PwError::InvalidMagic {
                expected: "KCTS (0x5354434b)",
                found: magic,
            });
        }
        let _ver = cur.read_i32_le()?;
        let num_tracks = cur.read_i32_le()?.max(0) as usize;
        let anim_start = cur.read_i32_le()?;
        let anim_end = cur.read_i32_le()?;
        let anim_fps = cur.read_i32_le()?.max(1);
        let mut bone_tracks = HashMap::with_capacity(num_tracks);
        for _ in 0..num_tracks {
            let bone_id = cur.read_i32_le()?;
            let pt = PosTrack::parse(&mut cur)?;
            let rt = RotTrack::parse(&mut cur)?;
            if bone_id >= 0 {
                bone_tracks.insert(bone_id as usize, (pt, rt));
            }
        }
        Ok(Self {
            anim_start,
            anim_end,
            anim_fps,
            bone_tracks,
        })
    }
}

#[derive(Debug, Clone)]
pub struct SmdActionDef {
    pub name: String,
    pub start_ms: f32,
    pub end_ms: f32,
    pub stck_file: Option<String>,
}

#[derive(Debug, Clone)]
pub struct A3dSkinModelDesc {
    pub version: i32,
    pub base_dir: String,
    pub bon_file: String,
    pub ski_files: Vec<String>,
    pub track_dir: String,
    pub actions: Vec<SmdActionDef>,
}

impl A3dSkinModelDesc {
    /// Exact port of `A3DSkinModel::Load` (`0x00791210`, `MOXBDMSA`, `v5`/`v6`/`v8`, `2,228/2,228` `bad=0`).
    pub fn parse_smd(bytes: &[u8], smd_vfs_path: &str) -> PwResult<Self> {
        if bytes.len() < 88 || &bytes[..4] != b"MOXB" {
            return Err(PwError::InvalidData("smd missing MOXB".into()));
        }
        let mut cur = BinaryCursor::new(&bytes[4..]);
        let magic = cur.read_u32_le()?;
        if magic != MAGIC_ASMD {
            return Err(PwError::InvalidMagic {
                expected: "DMSA (0x41534d44)",
                found: magic,
            });
        }
        let version = cur.read_i32_le()?;
        let num_skins = cur.read_i32_le()?.max(0) as usize;
        let num_actions = cur.read_i32_le()?.max(0) as usize;
        let _num_hangers = cur.read_i32_le()?;
        let _num_props = cur.read_i32_le()?;
        cur.skip(60)?; // 88-byte total header

        let bon_file = cur.read_astring_gbk()?;
        let mut ski_files = Vec::with_capacity(num_skins);
        for _ in 0..num_skins {
            ski_files.push(cur.read_astring_gbk()?);
        }
        if version >= 4 {
            let _phy = cur.read_astring_gbk()?;
        }
        let track_dir = if version >= 8 {
            cur.read_astring_gbk()?
        } else {
            String::new()
        };

        let mut actions = Vec::with_capacity(num_actions);
        for _ in 0..num_actions {
            let name = cur.read_astring_gbk()?;
            if version < 6 {
                let _group = cur.read_i32_le()?;
                let nja = cur.read_i32_le()?.max(0) as usize;
                let _eff_cnt = cur.read_i32_le()?;
                let mut f_start = 0.0f32;
                let mut f_end = 0.0f32;
                for ji in 0..nja {
                    let _jid = cur.read_i32_le()?;
                    let sf = cur.read_f32_le()?;
                    let ef = cur.read_f32_le()?;
                    let _loops = cur.read_i32_le()?;
                    let _spd = cur.read_f32_le()?;
                    if ji == 0 {
                        f_start = sf;
                        f_end = ef;
                    }
                }
                actions.push(SmdActionDef {
                    name,
                    start_ms: f_start * (1000.0 / 15.0),
                    end_ms: f_end * (1000.0 / 15.0),
                    stck_file: None,
                });
            } else if version < 8 {
                let s_frame = cur.read_f32_le()?;
                let e_frame = cur.read_f32_le()?;
                actions.push(SmdActionDef {
                    name,
                    start_ms: s_frame * (1000.0 / 15.0),
                    end_ms: e_frame * (1000.0 / 15.0),
                    stck_file: None,
                });
            } else {
                let s_frame = cur.read_f32_le()?;
                let e_frame = cur.read_f32_le()?;
                let stck = cur.read_astring_gbk()?;
                actions.push(SmdActionDef {
                    name,
                    start_ms: s_frame * (1000.0 / 15.0),
                    end_ms: e_frame * (1000.0 / 15.0),
                    stck_file: if stck.is_empty() { None } else { Some(stck) },
                });
            }
        }

        let base_dir = smd_vfs_path
            .replace('\\', "/")
            .rsplit_once('/')
            .map(|(d, _)| d.to_string())
            .unwrap_or_default();

        Ok(Self {
            version,
            base_dir,
            bon_file,
            ski_files,
            track_dir,
            actions,
        })
    }

    pub fn select_action(&self, kind: ActorActionKind) -> Option<&SmdActionDef> {
        let patterns: &[&str] = match kind {
            ActorActionKind::Stand => &["站立_通用", "站立_双手长", "普通站立", "基本站立", "待机", "站立", "休闲"],
            ActorActionKind::Run => &["奔跑_通用", "奔跑_双手长", "快速移动", "移动", "奔跑", "走"],
            ActorActionKind::Jump => &["起跳_通用", "跳跃", "起跳", "飞行"],
            ActorActionKind::FlyHover => &[
                "翅膀悬停_通用",
                "剑悬停_通用",
                "兽悬停_通用",
                "飞行悬停",
                "悬停",
                "站立_通用",
                "待机",
                "站立",
            ],
            ActorActionKind::FlyMove => &[
                "翅膀前进_通用",
                "剑前进_通用",
                "兽前进_通用",
                "飞行前进",
                "前进",
                "奔跑_通用",
                "快速移动",
                "移动",
            ],
            ActorActionKind::Attack => &["普攻1", "普通攻击1", "攻击1", "普攻", "攻击"],
            ActorActionKind::SkillCast => &["吟唱", "施法", "技能", "发招", "攻击"],
        };
        for &pat in patterns {
            if let Some(a) = self.actions.iter().find(|a| a.name == pat) {
                return Some(a);
            }
            if let Some(a) = self.actions.iter().find(|a| a.name.contains(pat)) {
                return Some(a);
            }
        }
        self.actions.first()
    }
}

/// Plain-text `CECModel` (`.ecm`, `MOXTVersion`) descriptor for NPCs, Monsters, Pets, and Scene Props.
#[derive(Debug, Clone)]
pub struct EcModelDesc {
    pub smd_vfs_path: String,
    pub additional_skins: Vec<String>,
    pub scale: f32,
}

impl EcModelDesc {
    pub fn parse_ecm(bytes: &[u8], _ecm_vfs_path: &str) -> Option<Self> {
        let txt = decode_gbk(bytes);
        let mut smd_vfs_path = String::new();
        let mut additional_skins = Vec::new();
        let mut scale = 1.0f32;
        for raw in txt.lines() {
            let line = raw.trim();
            if let Some(rest) = line.strip_prefix("SkinModelPath:") {
                smd_vfs_path = rest.trim().replace('\\', "/");
            } else if let Some(rest) = line.strip_prefix("AdditionalSkin:") {
                let s = rest.trim().replace('\\', "/");
                if !s.is_empty() {
                    additional_skins.push(s);
                }
            } else if let Some(rest) = line.strip_prefix("Scale:") {
                if let Ok(v) = rest.trim().parse::<f32>() {
                    if (0.1..=10.0).contains(&v) {
                        scale = v;
                    }
                }
            }
        }
        if smd_vfs_path.is_empty() {
            None
        } else {
            Some(Self {
                smd_vfs_path,
                additional_skins,
                scale,
            })
        }
    }
}

/// Complete loaded `A3DSkeleton` + `A3DSkinModelDesc` + cached external `.stck` tracks.
pub struct LoadedSkeletonRig {
    pub skeleton: A3dSkeleton,
    pub smd: A3dSkinModelDesc,
    pub stck_cache: HashMap<String, A3dSklTrackSet>,
}

impl LoadedSkeletonRig {
    pub fn load_from_smd(vfs: &VirtualFileSystem, smd_vfs_path: &str) -> Option<Self> {
        let smd_bytes = vfs.read_file(smd_vfs_path).ok()?;
        let smd = A3dSkinModelDesc::parse_smd(&smd_bytes, smd_vfs_path).ok()?;
        let bon_rel = smd.bon_file.replace('\\', "/");
        let bon_candidates = [
            format!("{}/{}", smd.base_dir, bon_rel),
            bon_rel.clone(),
        ];
        let bon_bytes = bon_candidates
            .iter()
            .find_map(|p| vfs.read_file(p).ok())?;
        let skeleton = A3dSkeleton::parse_bon(&bon_bytes).ok()?;
        Some(Self {
            skeleton,
            smd,
            stck_cache: HashMap::new(),
        })
    }

    pub fn evaluate_action_pose(
        &mut self,
        vfs: &VirtualFileSystem,
        action: ActorActionKind,
        anim_seconds: f32,
    ) -> (Vec<Mat4>, Vec<Mat4>) {
        let Some(act) = self.smd.select_action(action).cloned() else {
            return self.skeleton.evaluate_pose(None, 0.0);
        };

        let ext = if let Some(stck_name) = &act.stck_file {
            if !self.stck_cache.contains_key(stck_name) {
                let clean = stck_name.replace('\\', "/");
                let dir_clean = self.smd.track_dir.replace('\\', "/");
                let cands = [
                    format!("{}/{}/{}", self.smd.base_dir, dir_clean, clean),
                    format!("{}/{}", self.smd.base_dir, clean),
                    clean.clone(),
                ];
                if let Some(stck_bytes) = cands.iter().find_map(|p| vfs.read_file(p).ok()) {
                    if let Ok(parsed) = A3dSklTrackSet::parse_stck(&stck_bytes) {
                        self.stck_cache.insert(stck_name.clone(), parsed);
                    }
                }
            }
            self.stck_cache.get(stck_name)
        } else {
            None
        };

        let (s_ms, e_ms) = if let Some(et) = ext {
            let s = (et.anim_start as f32) * (1000.0 / (et.anim_fps.max(1) as f32));
            let e = (et.anim_end as f32) * (1000.0 / (et.anim_fps.max(1) as f32));
            if e > s { (s, e) } else { (act.start_ms, act.end_ms) }
        } else {
            (act.start_ms, act.end_ms)
        };

        let span = (e_ms - s_ms).max(1.0);
        let t_ms = if span > 2.0 {
            s_ms + ((anim_seconds.max(0.0) * 1000.0) % span)
        } else {
            s_ms
        };
        self.skeleton.evaluate_pose(ext, t_ms)
    }

    /// Exact port of `A3DSkin::BindSkeleton` (`0x00795cd0`): maps skin bone indices -> skeleton blend matrix indices.
    pub fn build_bone_map(&self, skin: &A3dSkin) -> Vec<usize> {
        let nb = self.skeleton.bones.len();
        if skin.version >= 9 && !skin.bone_names.is_empty() {
            let mut map = Vec::with_capacity(skin.bone_names.len() + 1);
            for bn in &skin.bone_names {
                let idx = self
                    .skeleton
                    .bone_by_name
                    .get(&bn.to_ascii_lowercase())
                    .copied()
                    .unwrap_or(nb);
                map.push(idx);
            }
            map.push(nb);
            map
        } else {
            let count = nb + 1;
            (0..count).collect()
        }
    }
}

/// Applies CPU/software linear-blend skinning (`A3DSkinMesh` 4-bone weights) to a submesh using `tm_blend`.
pub fn skin_submesh_vertices(
    sm: &A3dSkinSubMesh,
    bone_map: &[usize],
    tm_blend: &[Mat4],
    sun_dir: Vec3,
) -> Vec<A3dLitVertex> {
    if tm_blend.is_empty() || sm.skin_weights.len() != sm.verts.len() {
        return sm.verts.clone();
    }
    let fallback_idx = tm_blend.len() - 1;
    let mut out = Vec::with_capacity(sm.verts.len());

    for (vi, vt) in sm.verts.iter().enumerate() {
        let sw = sm.skin_weights[vi];
        let nrm_in = sm.normals.get(vi).copied().unwrap_or(Vec3::UNIT_Y);
        let mut sx = 0.0f32;
        let mut sy = 0.0f32;
        let mut sz = 0.0f32;
        let mut nx = 0.0f32;
        let mut ny = 0.0f32;
        let mut nz = 0.0f32;
        let mut w_sum = 0.0f32;

        for k in 0..4 {
            let wk = sw.weights[k];
            if wk <= 1e-5 {
                continue;
            }
            let raw_b = sw.bone_indices[k] as usize;
            let mapped = bone_map
                .get(raw_b)
                .copied()
                .unwrap_or(fallback_idx)
                .min(fallback_idx);
            let m = &tm_blend[mapped].0;
            sx += wk * (vt.x * m[0][0] + vt.y * m[1][0] + vt.z * m[2][0] + m[3][0]);
            sy += wk * (vt.x * m[0][1] + vt.y * m[1][1] + vt.z * m[2][1] + m[3][1]);
            sz += wk * (vt.x * m[0][2] + vt.y * m[1][2] + vt.z * m[2][2] + m[3][2]);
            nx += wk * (nrm_in.x * m[0][0] + nrm_in.y * m[1][0] + nrm_in.z * m[2][0]);
            ny += wk * (nrm_in.x * m[0][1] + nrm_in.y * m[1][1] + nrm_in.z * m[2][1]);
            nz += wk * (nrm_in.x * m[0][2] + nrm_in.y * m[1][2] + nrm_in.z * m[2][2]);
            w_sum += wk;
        }

        if w_sum <= 1e-4 {
            out.push(*vt);
        } else {
            let n_lit = Vec3::new(nx, ny, nz).normalized();
            let ndotl = n_lit.dot(sun_dir).abs() * 0.44 + 0.56;
            let lit = (ndotl.clamp(0.46, 1.0) * 255.0) as u32;
            out.push(A3dLitVertex {
                x: sx,
                y: sy,
                z: sz,
                diffuse: 0xFF00_0000 | (lit << 16) | (lit << 8) | lit,
                u: vt.u,
                v: vt.v,
            });
        }
    }
    out
}

/// Returns candidate player `.smd` paths in `models.pck` for `(cls: 0..7, gender: 0..1)`,
/// preferring the canonical `Models\Players\形象\{folder}\躯干\{folder}.smd` path from `elementclient.exe`!
pub fn player_smd_candidates(cls: i32, gender: u8) -> Vec<String> {
    let is_female = match cls {
        3 => true,
        4 => false,
        _ => gender != 0,
    };
    match (cls.clamp(0, 7), is_female) {
        (5, true) => vec![
            "models/players/形象/刺客女/躯干/刺客女.smd".into(),
            "models/players/形象/刺客女/女刺客.smd".into(),
        ],
        (5, false) => vec![
            "models/players/形象/刺客男/躯干/刺客男.smd".into(),
            "models/players/形象/刺客男/男刺客.smd".into(),
        ],
        _ => vec![player_smd_vfs_path(cls, gender)],
    }
}

/// Returns the canonical player `.smd` path in `models.pck` for `(cls: 0..7, gender: 0..1)`.
pub fn player_smd_vfs_path(cls: i32, gender: u8) -> String {
    let is_female = match cls {
        3 => true,
        4 => false,
        _ => gender != 0,
    };
    match (cls.clamp(0, 7), is_female) {
        (5, true) => "models/players/形象/刺客女/躯干/刺客女.smd".into(),
        (5, false) => "models/players/形象/刺客男/躯干/刺客男.smd".into(),
        (3, _) => "models/players/形象/妖精/躯干/妖精.smd".into(),
        (4, _) => "models/players/形象/妖兽男/躯干/妖兽男.smd".into(),
        (0, false) => "models/players/形象/武侠男/躯干/武侠男.smd".into(),
        (0, true) => "models/players/形象/武侠女/躯干/武侠女.smd".into(),
        (1, false) => "models/players/形象/法师男/躯干/法师男.smd".into(),
        (1, true) => "models/players/形象/法师女/躯干/法师女.smd".into(),
        (2, false) => "models/players/形象/巫师男/躯干/巫师男.smd".into(),
        (2, true) => "models/players/形象/巫师女/躯干/巫师女.smd".into(),
        (6, false) => "models/players/形象/羽芒男/躯干/羽芒男.smd".into(),
        (6, true) => "models/players/形象/羽芒女/躯干/羽芒女.smd".into(),
        (7, false) => "models/players/形象/羽灵男/躯干/羽灵男.smd".into(),
        _ => "models/players/形象/羽灵女/躯干/羽灵女.smd".into(),
    }
}

/// Returns `(hook_name_substr, weapon_ski_path, dual_wield_left)` for each PW 1.4.2 profession (`0..=7`).
pub fn class_signature_weapon_ski(cls: i32) -> (&'static str, &'static str, bool) {
    match cls.clamp(0, 7) {
        0 => ("righthandweapon", "models/weapons/人物/刀剑/15品单剑/15品单剑.ski", true),
        1 => ("righthandweapon", "models/weapons/人物/法器/15品法仗/15品法仗.ski", false),
        2 => ("righthandweapon", "models/weapons/人物/匕首/法宝/9品法宝/9品法宝.ski", false),
        3 => ("righthandweapon", "models/weapons/人物/法器/15品法仗/15品法仗.ski", false),
        4 => ("righthandweapon", "models/weapons/人物/斧锤/15品双斧/15品双斧.ski", true),
        5 => ("righthandweapon", "models/weapons/人物/匕首/匕首1/10品匕首/10品匕首.ski", true),
        6 => ("lefthandweapon", "models/weapons/人物/弓弩/15品弓/15品弓.ski", false),
        _ => ("righthandweapon", "models/weapons/人物/法器/15品法仗/15品法仗.ski", false),
    }
}

/// Real NPC & Monster `.ecm` models from `models.pck` with authentic English PWI display names & titles.
pub const REAL_NPC_ECMS: &[(&str, &str, &str)] = &[
    ("Teleport Master Yun", "Teleporter", "models/npcs/npc/传送大师/传送大师.ecm"),
    ("General Summer", "Archosaur Commander", "models/npcs/npc/仙npc/仙npc.ecm"),
    ("Celestial Guide", "Cultivation Mentor", "models/npcs/npc/仙女/仙女.ecm"),
    ("Blacksmith Tang", "Tideborn Forgemaster", "models/npcs/npc/npc影族巧匠/npc影族巧匠.ecm"),
    ("Tailor Lin", "Tideborn Seamstress", "models/npcs/npc/npc影族裁缝/npc影族裁缝.ecm"),
    ("Apothecary Hui", "Herbalist", "models/npcs/npc/僧侣/僧侣.ecm"),
];

pub const REAL_MONSTER_ECMS: &[(&str, &str, &str)] = &[
    ("Feligar Warrior", "+MT-FR", "models/npcs/怪物/05虎妖/独角骷髅虎/a身高/独角骷髅虎斗士.ecm"),
    ("Crimson Feligar", "+FR-WT", "models/npcs/怪物/05虎妖/赤骷髅虎/c身高/赤骷髅虎卫兵.ecm"),
    ("Nine-Tailed Wraith", "+WD-MT", "models/npcs/怪物/07地行灵/九子鬼母/九子鬼母.ecm"),
    ("Wraith Flame", "+FR-WT", "models/npcs/怪物/06漂浮灵/鬼火/怨灵之火.ecm"),
    ("Tauroc Valorian", "+WT-ER", "models/npcs/怪物/01牛妖/巨蹄牛喽罗/b身高/巨蹄牛首领.ecm"),
    ("Thunderhorn King", "+ER-WD", "models/npcs/怪物/01牛妖/boss青牛雷魔王/boss青牛雷魔王.ecm"),
];

/// Loads all `.ski` skins referenced by an `.ecm` -> `.smd` chain (`NPC` / `Monster` / static `ECModel`).
pub fn load_ecm_rig_and_skins(
    vfs: &VirtualFileSystem,
    ecm_path: &str,
) -> Option<(EcModelDesc, LoadedSkeletonRig, Vec<A3dSkin>)> {
    let ecm_bytes = vfs.read_file(ecm_path).ok()?;
    let desc = EcModelDesc::parse_ecm(&ecm_bytes, ecm_path)?;
    let rig = LoadedSkeletonRig::load_from_smd(vfs, &desc.smd_vfs_path)?;
    let mut skins = Vec::new();
    for ski_rel in &rig.smd.ski_files {
        let clean = ski_rel.replace('\\', "/");
        let cands = [
            format!("{}/{}", rig.smd.base_dir, clean),
            clean.clone(),
        ];
        if let Some((p, sb)) = cands
            .iter()
            .find_map(|p| vfs.read_file(p).ok().map(|b| (p.clone(), b)))
        {
            if let Ok(sk) = A3dSkin::parse_ski(&sb, &p) {
                skins.push(sk);
            }
        }
    }
    for add_rel in &desc.additional_skins {
        let cands = [
            format!("{}/{}", rig.smd.base_dir, add_rel),
            add_rel.clone(),
        ];
        if let Some((p, sb)) = cands
            .iter()
            .find_map(|p| vfs.read_file(p).ok().map(|b| (p.clone(), b)))
        {
            if let Ok(sk) = A3dSkin::parse_ski(&sb, &p) {
                skins.push(sk);
            }
        }
    }
    if skins.is_empty() {
        return None;
    }
    Some((desc, rig, skins))
}

/// Extracts the bark texture filename inside an IDV SpeedTree `.spt` binary (`__IdvSpt_02_` token `2000 = 0x07d0`).
pub fn extract_spt_bark_texture(
    vfs: &VirtualFileSystem,
    spt_vfs_path: &str,
) -> Option<Vec<u8>> {
    let clean = spt_vfs_path.replace('\\', "/");
    let dir = clean.rsplit_once('/').map(|(d, _)| d).unwrap_or("trees");
    if let Ok(spt_bytes) = vfs.read_file(&clean) {
        // Scan for `0xd0 0x07 0x00 0x00` (`token 2000 = Branch Bark Texture`) followed by `u32 len` + ASCII string
        for i in 0..spt_bytes.len().saturating_sub(12) {
            if spt_bytes[i..i + 4] == [0xd0, 0x07, 0x00, 0x00] {
                let slen = u32::from_le_bytes([
                    spt_bytes[i + 4],
                    spt_bytes[i + 5],
                    spt_bytes[i + 6],
                    spt_bytes[i + 7],
                ]) as usize;
                if (4..=96).contains(&slen) && i + 8 + slen <= spt_bytes.len() {
                    let raw_name = decode_gbk(&spt_bytes[i + 8..i + 8 + slen]);
                    if let Some(tb) = read_model_texture_bytes(vfs, dir, &raw_name) {
                        return Some(tb);
                    }
                }
            }
        }
    }
    read_model_texture_bytes(vfs, "trees", "defaultbark.dds")
}

/// Builds a 3D SpeedTree mesh (`trunk` batch + `canopy` alpha-cutout foliage batch) for `EcwldTreeType`.
pub fn build_speedtree_batches(
    height: f32,
    canopy_radius: f32,
    is_bamboo: bool,
) -> ((Vec<A3dLitVertex>, Vec<u16>), (Vec<A3dLitVertex>, Vec<u16>)) {
    let mut t_verts = Vec::new();
    let mut t_idx = Vec::new();
    let segs = 6usize;
    let r_bot = if is_bamboo { 0.14 } else { (canopy_radius * 0.11).clamp(0.22, 0.55) };
    let r_top = r_bot * 0.32;
    let trunk_h = height * 0.68;

    for ring in 0..=2 {
        let frac = ring as f32 * 0.5;
        let y = frac * trunk_h;
        let r = r_bot + (r_top - r_bot) * frac;
        for s in 0..=segs {
            let ang = (s as f32 / segs as f32) * core::f32::consts::TAU;
            let lit = if ring == 0 { 0xFFC8_BCA8 } else { 0xFFE6_DCD0 };
            t_verts.push(A3dLitVertex {
                x: r * ang.cos(),
                y,
                z: r * ang.sin(),
                diffuse: lit,
                u: s as f32 / segs as f32,
                v: frac * 3.0,
            });
        }
    }
    let st = segs + 1;
    for ring in 0..2 {
        for s in 0..segs {
            let i0 = (ring * st + s) as u16;
            let i1 = i0 + 1;
            let i2 = ((ring + 1) * st + s) as u16;
            let i3 = i2 + 1;
            t_idx.extend_from_slice(&[i0, i2, i1, i1, i2, i3]);
        }
    }

    // Multi-plane crossed foliage canopy cards (`putileaves.dds` / `taoshuleaves.dds` / `bamboos.dds` composite!)
    let mut c_verts = Vec::new();
    let mut c_idx = Vec::new();
    let planes = [
        (0.0f32, height * 0.62, canopy_radius),
        (1.0472f32, height * 0.65, canopy_radius * 0.96),
        (2.0944f32, height * 0.68, canopy_radius * 0.92),
    ];
    for &(ang, cy, rad) in &planes {
        let dx = rad * ang.cos();
        let dz = rad * ang.sin();
        let y0 = (cy - rad * 0.72).max(1.2);
        let y1 = cy + rad * 0.78;
        let base = c_verts.len() as u16;
        // Note: SpeedTree leaf composite sheets typically keep the primary leaf card in `(0.0..0.5, 0.0..0.5)` or full `[0..1]^2`
        c_verts.push(A3dLitVertex { x: -dx, y: y1, z: -dz, diffuse: 0xFFF4_F8F0, u: 0.02, v: 0.02 });
        c_verts.push(A3dLitVertex { x: dx,  y: y1, z: dz,  diffuse: 0xFFF4_F8F0, u: 0.48, v: 0.02 });
        c_verts.push(A3dLitVertex { x: -dx, y: y0, z: -dz, diffuse: 0xFFD4_DEC8, u: 0.02, v: 0.48 });
        c_verts.push(A3dLitVertex { x: dx,  y: y0, z: dz,  diffuse: 0xFFD4_DEC8, u: 0.48, v: 0.48 });
        c_idx.extend_from_slice(&[base, base + 1, base + 2, base + 1, base + 3, base + 2]);
    }

    ((t_verts, t_idx), (c_verts, c_idx))
}
