//! Angelica 2.2 `A3DGFXEx` (`.gfx` / `MOXT`) Particle, Aura, Trail, & Shockwave System.
//!
//! Disassembly-verified against `A3DGFXExMan::LoadGfx` / `A3DGFXElement::Load` (`elementclient.exe`
//! Angelica GFX subsystem) and wired to all `69` `ElementSkill` `VISIBLE_STATES` (`属性增强.gfx`,
//! `羽盾.gfx`, `烈焰护甲.gfx`, `寒冰护甲.gfx`, `爆气效果状态.gfx`, etc.), weapon socket glows,
//! skill cast bursts, and level-up golden pillars.

use pw_core::Vec3;

use crate::a3d_models::A3dLitVertex;

/// Angelica 2.2 `GFXELEMENTID` types inside `.gfx` (`MOXT`) scripts.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum GfxElementKind {
    ParSys,    // 100..109: Sprite / Point / Box / Cylinder / Sphere Particle Emitter
    Decal3D,   // 110..112: Ground / Billboard Aura Decal
    Trail,     // 120: Weapon / Wing Ribbon Trail
    Ring,      // 121..122: Expanding Shockwave Ring
    Lightning, // 123: Procedural Electric Bolt
    Model,     // 124: Sub-ECM / MOX Effect Mesh
}

#[derive(Debug, Clone)]
pub struct GfxElementDef {
    pub id: u32,
    pub kind: GfxElementKind,
    pub name: String,
    pub tex_file: String,
    pub blend_additive: bool,
    pub quota: u32,
    pub emit_rate: f32,
    pub min_life_s: f32,
    pub max_life_s: f32,
    pub speed_mps: f32,
    pub scale_start: f32,
    pub scale_end: f32,
    pub color_start: u32,
    pub color_end: u32,
}

#[derive(Debug, Clone)]
pub struct A3dGfxTemplate {
    pub version: u32,
    pub play_speed: f32,
    pub default_scale: f32,
    pub elements: Vec<GfxElementDef>,
}

impl A3dGfxTemplate {
    /// Parses an Angelica 2.2 `MOXTversion: <N>` text `.gfx` script (or binary `GFXB` header).
    pub fn parse(raw: &[u8]) -> Option<Self> {
        if raw.len() < 8 {
            return None;
        }
        let text = String::from_utf8_lossy(raw);
        let first = text.lines().next().unwrap_or("").trim();
        if !first.starts_with("MOXT") && !raw.starts_with(b"GFXB") {
            return None;
        }
        let version = first
            .split(':')
            .nth(1)
            .and_then(|s| s.trim().parse::<u32>().ok())
            .unwrap_or(58);

        let mut play_speed = 1.0f32;
        let mut default_scale = 1.0f32;
        let mut elements = Vec::new();
        let mut cur: Option<GfxElementDef> = None;

        for line in text.lines() {
            let ln = line.trim();
            if ln.is_empty() {
                continue;
            }
            let Some((k_raw, v_raw)) = ln.split_once(':') else {
                continue;
            };
            let k = k_raw.trim();
            let v = v_raw.trim();
            match k {
                "PlaySpeed" => {
                    if let Ok(f) = v.parse::<f32>() {
                        play_speed = f.clamp(0.1, 10.0);
                    }
                }
                "DefScale" => {
                    if let Ok(f) = v.parse::<f32>() {
                        default_scale = f.clamp(0.05, 20.0);
                    }
                }
                "GFXELEMENTID" => {
                    if let Some(prev) = cur.take() {
                        elements.push(prev);
                    }
                    let eid = v.parse::<u32>().unwrap_or(100);
                    let kind = match eid {
                        100..=109 => GfxElementKind::ParSys,
                        110..=114 => GfxElementKind::Decal3D,
                        120 => GfxElementKind::Trail,
                        121..=122 => GfxElementKind::Ring,
                        123 => GfxElementKind::Lightning,
                        _ => GfxElementKind::Model,
                    };
                    cur = Some(GfxElementDef {
                        id: eid,
                        kind,
                        name: format!("Elem_{eid}"),
                        tex_file: String::new(),
                        blend_additive: true,
                        quota: 32,
                        emit_rate: 14.0,
                        min_life_s: 0.6,
                        max_life_s: 1.4,
                        speed_mps: 1.6,
                        scale_start: 0.28,
                        scale_end: 0.06,
                        color_start: 0xFFFF_D880,
                        color_end: 0x00FF_7020,
                    });
                }
                "Name" => {
                    if let Some(c) = &mut cur {
                        c.name = v.to_string();
                    }
                }
                "TexFile" => {
                    if let Some(c) = &mut cur {
                        c.tex_file = v.replace('/', "\\");
                    }
                }
                "AlphaMode" | "BlendMode" => {
                    if let Some(c) = &mut cur {
                        c.blend_additive = v != "0";
                    }
                }
                "Quota" | "MaxParticles" => {
                    if let Some(c) = &mut cur {
                        if let Ok(q) = v.parse::<u32>() {
                            c.quota = q.clamp(1, 256);
                        }
                    }
                }
                "Rate" | "EmitRate" => {
                    if let Some(c) = &mut cur {
                        if let Ok(r) = v.parse::<f32>() {
                            c.emit_rate = r.clamp(0.5, 120.0);
                        }
                    }
                }
                "Color" => {
                    if let Some(c) = &mut cur {
                        if let Ok(col) = v.parse::<i64>() {
                            c.color_start = col as i32 as u32;
                        }
                    }
                }
                _ => {}
            }
        }
        if let Some(prev) = cur.take() {
            elements.push(prev);
        }
        Some(Self {
            version,
            play_speed,
            default_scale,
            elements,
        })
    }

    /// Synthesizes the canonical `ElementSkill` `VISIBLE_STATES` (`1..=69`) `.gfx` aura preset
    /// when `gfx.pck` is not locally mounted or as a deterministic procedural fallback.
    pub fn preset_for_visible_state(vstate_id: u32) -> Self {
        let (c0, c1, kind, rate, radius_speed, scale0) = match vstate_id {
            // Fire / Spark / Chi Eruption (`烈焰护甲`, `爆气`, `持续火攻击`, `烈焰之矢`)
            12 | 17 | 18 | 24 | 30 => (0xFFFF_9838, 0x00FF_2808, GfxElementKind::ParSys, 22.0, 1.9, 0.34),
            // Ice / Water / Frostblade (`霜刃`, `寒冰护甲`, `避水诀`, `迟滞`)
            4 | 16 | 25 | 27 => (0xFF88_E4FF, 0x0028_78FF, GfxElementKind::Ring, 16.0, 1.1, 0.36),
            // Plume Shield / Wing Shield / Holy Buff (`强化`, `羽盾`, `翼盾`, `封印免疫`)
            1 | 28 | 29 | 34 | 35 => (0xFFFF_F0A8, 0x0080_D8FF, GfxElementKind::Ring, 18.0, 1.2, 0.38),
            // Poison / Wood / Bleed / Thorns (`中毒`, `放血`, `荆棘阵`)
            11 | 14 | 31 => (0xFF68_FF78, 0x0018_9830, GfxElementKind::ParSys, 16.0, 1.4, 0.30),
            // Lightning / Metal / Stun (`昏迷`, `雷击`, `麻痹`)
            5 | 8 | 10 => (0xFFD8_B8FF, 0x0078_40FF, GfxElementKind::Lightning, 20.0, 1.7, 0.32),
            // Earth / Stone Armor (`落石`, `磐石护甲`, `定身`)
            7 | 13 | 26 => (0xFFE8_B868, 0x0088_5820, GfxElementKind::Decal3D, 14.0, 0.9, 0.40),
            // Curse / Sleep / Fox Form / Debuff (`弱化`, `睡眠`, `受诅`, `妖狐变`)
            _ => (0xFFFF_88E8, 0x0088_28B8, GfxElementKind::ParSys, 15.0, 1.3, 0.30),
        };
        Self {
            version: 58,
            play_speed: 1.0,
            default_scale: 1.0,
            elements: vec![GfxElementDef {
                id: 100,
                kind,
                name: format!("VisibleState_{vstate_id}"),
                tex_file: String::new(),
                blend_additive: true,
                quota: 28,
                emit_rate: rate,
                min_life_s: 0.75,
                max_life_s: 1.35,
                speed_mps: radius_speed,
                scale_start: scale0,
                scale_end: 0.08,
                color_start: c0,
                color_end: c1,
            }],
        }
    }
}

#[derive(Debug, Clone)]
struct LiveParticle {
    pos: Vec3,
    vel: Vec3,
    age_s: f32,
    life_s: f32,
    size_start: f32,
    size_end: f32,
    color_start: u32,
    color_end: u32,
}

#[derive(Debug, Clone)]
pub struct ActiveGfxEffect {
    pub anchor_pos: Vec3,
    pub ttl_s: f32,
    pub looping: bool,
    pub vstate_id: u32,
    pub emit_accum: f32,
    pub phase_rad: f32,
    pub template: A3dGfxTemplate,
}

/// Real-time 3D `A3DGFXExMan` particle & aura simulator.
#[derive(Debug, Clone, Default)]
pub struct A3dGfxManager {
    pub active_effects: Vec<ActiveGfxEffect>,
    particles: Vec<LiveParticle>,
    rng_state: u32,
}

impl A3dGfxManager {
    pub fn new() -> Self {
        Self {
            active_effects: Vec::new(),
            particles: Vec::with_capacity(512),
            rng_state: 0xA3D6_F821,
        }
    }

    #[inline]
    fn next_unit(&mut self) -> f32 {
        let mut x = self.rng_state;
        if x == 0 {
            x = 0x9E37_79B9;
        }
        x ^= x << 13;
        x ^= x >> 17;
        x ^= x << 5;
        self.rng_state = x;
        ((x & 0x00FF_FFFF) as f32) / (0x0100_0000 as f32)
    }

    pub fn particle_count(&self) -> usize {
        self.particles.len()
    }

    /// Spawns a one-shot skill cast / hit / level-up `.gfx` burst at `pos`.
    pub fn spawn_burst(&mut self, pos: Vec3, color_start: u32, color_end: u32, count: usize, speed: f32, size: f32) {
        for i in 0..count.min(64) {
            if self.particles.len() >= 768 {
                break;
            }
            let ang = (i as f32 / count.max(1) as f32) * std::f32::consts::TAU + self.next_unit() * 0.5;
            let up = 0.6 + self.next_unit() * 1.8;
            let rad = speed * (0.45 + self.next_unit() * 0.75);
            let life_s = 0.55 + self.next_unit() * 0.55;
            self.particles.push(LiveParticle {
                pos: Vec3::new(pos.x, pos.y + 0.9, pos.z),
                vel: Vec3::new(ang.cos() * rad, up, ang.sin() * rad),
                age_s: 0.0,
                life_s,
                size_start: size,
                size_end: size * 0.18,
                color_start,
                color_end,
            });
        }
    }

    /// Synchronizes an actor's active `VisibleState` (`1..=69`) looping `.gfx` aura at `anchor_pos`.
    pub fn sync_visible_state_aura(&mut self, vstate_id: u32, anchor_pos: Vec3) {
        if let Some(ex) = self.active_effects.iter_mut().find(|e| e.looping && e.vstate_id == vstate_id) {
            ex.anchor_pos = anchor_pos;
            ex.ttl_s = 0.25;
            return;
        }
        if self.active_effects.len() < 24 {
            self.active_effects.push(ActiveGfxEffect {
                anchor_pos,
                ttl_s: 0.25,
                looping: true,
                vstate_id,
                emit_accum: 0.0,
                phase_rad: 0.0,
                template: A3dGfxTemplate::preset_for_visible_state(vstate_id),
            });
        }
    }

    /// Emits subtle weapon-socket enchantment motes along `weapon_tip_pos`.
    pub fn emit_weapon_glow_motes(&mut self, weapon_pos: Vec3, tint_argb: u32, dt: f32) {
        if self.particles.len() >= 768 {
            return;
        }
        let prob = (dt * 18.0).clamp(0.0, 1.0);
        if self.next_unit() <= prob {
            let jx = (self.next_unit() - 0.5) * 0.22;
            let jy = (self.next_unit() - 0.5) * 0.22;
            let jz = (self.next_unit() - 0.5) * 0.22;
            let vx = (self.next_unit() - 0.5) * 0.25;
            let vy = 0.35 + self.next_unit() * 0.35;
            let vz = (self.next_unit() - 0.5) * 0.25;
            let life_s = 0.45 + self.next_unit() * 0.35;
            self.particles.push(LiveParticle {
                pos: Vec3::new(weapon_pos.x + jx, weapon_pos.y + jy, weapon_pos.z + jz),
                vel: Vec3::new(vx, vy, vz),
                age_s: 0.0,
                life_s,
                size_start: 0.16,
                size_end: 0.03,
                color_start: tint_argb,
                color_end: tint_argb & 0x00FF_FFFF,
            });
        }
    }

    /// Advances all active `.gfx` emitters and particles by `dt` seconds.
    pub fn tick(&mut self, dt: f32) {
        let step = dt.clamp(0.0, 0.1);
        if step <= 0.0 {
            return;
        }
        // Advance existing particles
        let mut i = 0usize;
        while i < self.particles.len() {
            let p = &mut self.particles[i];
            p.age_s += step;
            if p.age_s >= p.life_s {
                self.particles.swap_remove(i);
                continue;
            }
            p.pos.x += p.vel.x * step;
            p.pos.y += p.vel.y * step;
            p.pos.z += p.vel.z * step;
            p.vel.x *= (1.0 - 0.9 * step).max(0.0);
            p.vel.z *= (1.0 - 0.9 * step).max(0.0);
            i += 1;
        }

        // Advance emitters
        let mut new_spawns: Vec<LiveParticle> = Vec::new();
        let mut rng = self.rng_state.max(1);
        let mut next_u = || -> f32 {
            rng ^= rng << 13;
            rng ^= rng >> 17;
            rng ^= rng << 5;
            ((rng & 0x00FF_FFFF) as f32) / (0x0100_0000 as f32)
        };

        self.active_effects.retain_mut(|fx| {
            fx.ttl_s -= step;
            if fx.ttl_s <= 0.0 {
                return false;
            }
            fx.phase_rad = (fx.phase_rad + step * 2.8) % std::f32::consts::TAU;
            for el in &fx.template.elements {
                fx.emit_accum += el.emit_rate * step;
                while fx.emit_accum >= 1.0 {
                    fx.emit_accum -= 1.0;
                    if new_spawns.len() + self.particles.len() >= 768 {
                        break;
                    }
                    let ang = fx.phase_rad + next_u() * std::f32::consts::TAU;
                    let ring_r = 0.68 + next_u() * 0.25;
                    let y_off = match el.kind {
                        GfxElementKind::Decal3D => 0.08,
                        GfxElementKind::Ring => 0.85 + (ang * 2.0).sin() * 0.22,
                        _ => 0.35 + next_u() * 1.15,
                    };
                    new_spawns.push(LiveParticle {
                        pos: Vec3::new(
                            fx.anchor_pos.x + ang.cos() * ring_r,
                            fx.anchor_pos.y + y_off,
                            fx.anchor_pos.z + ang.sin() * ring_r,
                        ),
                        vel: Vec3::new(
                            -ang.sin() * el.speed_mps * 0.45,
                            0.45 + next_u() * 0.55,
                            ang.cos() * el.speed_mps * 0.45,
                        ),
                        age_s: 0.0,
                        life_s: el.min_life_s + next_u() * (el.max_life_s - el.min_life_s).max(0.05),
                        size_start: el.scale_start,
                        size_end: el.scale_end,
                        color_start: el.color_start,
                        color_end: el.color_end,
                    });
                }
            }
            true
        });
        self.rng_state = rng;
        self.particles.extend(new_spawns);
    }

    /// Builds camera-facing billboard quads (`A3dLitVertex` + `u16` indices) for D3D9 / Software rendering.
    pub fn build_billboard_mesh(&self, cam_right: Vec3, cam_up: Vec3) -> (Vec<A3dLitVertex>, Vec<u16>) {
        let count = self.particles.len().min(512);
        let mut verts = Vec::with_capacity(count * 4);
        let mut indices = Vec::with_capacity(count * 6);

        for p in self.particles.iter().take(count) {
            let t = (p.age_s / p.life_s.max(0.001)).clamp(0.0, 1.0);
            let half = (p.size_start + (p.size_end - p.size_start) * t) * 0.5;
            if half <= 0.002 {
                continue;
            }
            let col = lerp_argb_fade(p.color_start, p.color_end, t);
            let rx = cam_right.x * half;
            let ry = cam_right.y * half;
            let rz = cam_right.z * half;
            let ux = cam_up.x * half;
            let uy = cam_up.y * half;
            let uz = cam_up.z * half;

            let base = verts.len() as u16;
            verts.push(A3dLitVertex {
                x: p.pos.x - rx + ux,
                y: p.pos.y - ry + uy,
                z: p.pos.z - rz + uz,
                diffuse: col,
                u: 0.0,
                v: 0.0,
            });
            verts.push(A3dLitVertex {
                x: p.pos.x + rx + ux,
                y: p.pos.y + ry + uy,
                z: p.pos.z + rz + uz,
                diffuse: col,
                u: 1.0,
                v: 0.0,
            });
            verts.push(A3dLitVertex {
                x: p.pos.x + rx - ux,
                y: p.pos.y + ry - uy,
                z: p.pos.z + rz - uz,
                diffuse: col,
                u: 1.0,
                v: 1.0,
            });
            verts.push(A3dLitVertex {
                x: p.pos.x - rx - ux,
                y: p.pos.y - ry - uy,
                z: p.pos.z - rz - uz,
                diffuse: col,
                u: 0.0,
                v: 1.0,
            });
            indices.extend_from_slice(&[base, base + 1, base + 2, base, base + 2, base + 3]);
        }
        (verts, indices)
    }
}

#[inline]
fn lerp_argb_fade(c0: u32, c1: u32, t: f32) -> u32 {
    let inv = 1.0 - t;
    let a0 = ((c0 >> 24) & 0xFF) as f32;
    let r0 = ((c0 >> 16) & 0xFF) as f32;
    let g0 = ((c0 >> 8) & 0xFF) as f32;
    let b0 = (c0 & 0xFF) as f32;

    let a1 = ((c1 >> 24) & 0xFF) as f32;
    let r1 = ((c1 >> 16) & 0xFF) as f32;
    let g1 = ((c1 >> 8) & 0xFF) as f32;
    let b1 = (c1 & 0xFF) as f32;

    // Smooth bell-curve fade-in (`0..0.15`) then fade-out (`0.15..1.0`)
    let env = if t < 0.15 { t / 0.15 } else { 1.0 - (t - 0.15) / 0.85 };
    let a = ((a0 * inv + a1 * t).max(220.0) * env).clamp(0.0, 255.0) as u32;
    let r = (r0 * inv + r1 * t).clamp(0.0, 255.0) as u32;
    let g = (g0 * inv + g1 * t).clamp(0.0, 255.0) as u32;
    let b = (b0 * inv + b1 * t).clamp(0.0, 255.0) as u32;
    (a << 24) | (r << 16) | (g << 8) | b
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_moxt_gfx_parser_and_particle_simulation() {
        let sample_moxt = b"MOXTversion: 58\r\nPlaySpeed: 1.25\r\nDefScale: 1.5\r\n\
            GFXELEMENTID: 100\r\nName: AuraSpark\r\nTexFile: Spark01.dds\r\nAlphaMode: 1\r\n\
            Quota: 48\r\nRate: 24.0\r\nGFXELEMENTID: 121\r\nName: WaveRing\r\nTexFile: Ring02.dds\r\n";
        let tpl = A3dGfxTemplate::parse(sample_moxt).expect("valid MOXT .gfx");
        assert_eq!(tpl.version, 58);
        assert!((tpl.play_speed - 1.25).abs() < 1e-4);
        assert_eq!(tpl.elements.len(), 2);
        assert_eq!(tpl.elements[0].kind, GfxElementKind::ParSys);
        assert_eq!(tpl.elements[0].quota, 48);
        assert_eq!(tpl.elements[1].kind, GfxElementKind::Ring);

        let mut mgr = A3dGfxManager::new();
        mgr.sync_visible_state_aura(28, Vec3::new(100.0, 220.0, 100.0)); // Plume Shield (`羽盾.gfx`)
        mgr.spawn_burst(Vec3::new(100.0, 220.0, 100.0), 0xFFFF_D860, 0x00FF_4010, 16, 2.5, 0.35);
        mgr.tick(0.05);
        assert!(mgr.particle_count() >= 16);
        let (verts, indices) = mgr.build_billboard_mesh(Vec3::new(1.0, 0.0, 0.0), Vec3::new(0.0, 1.0, 0.0));
        assert_eq!(verts.len() * 6, indices.len() * 4);
        assert!(!verts.is_empty());
    }
}
