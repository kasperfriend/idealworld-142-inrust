//! Angelica 3D (`A3DDevice` / `A3DCamera` / `A3DTerrain2` / `A2DSprite`) Framebuffer Compositor.
//!
//! Left-handed DirectX/Angelica coordinate system (`+X` East, `+Y` Up, `+Z` North), matching
//! `configs\scenectrl.ini`, `configs\element_client.cfg` (`[DefEnv]`), and `A3DTerrain2`.

use pw_core::Vec3;
use pw_world::Terrain2HeightMesh;

use crate::image_dds::SurfaceImage;

#[derive(Debug, Clone)]
pub struct OverlayTextCmd {
    pub x: i32,
    pub y: i32,
    pub text: String,
    pub color: u32,
    pub font_px: u16,
    pub bold: bool,
    pub shadow: bool,
}

#[derive(Debug, Clone, Copy)]
pub struct SceneCamera3D {
    pub pos: Vec3,
    pub forward: Vec3,
    pub right: Vec3,
    pub up: Vec3,
    pub fov_y_rad: f32,
    pub aspect: f32,
    pub z_near: f32,
    pub z_far: f32,
}

impl SceneCamera3D {
    pub fn from_pos_dir(pos: Vec3, dir: Vec3, width: u32, height: u32, fov_deg: f32) -> Self {
        let f_len = (dir.x * dir.x + dir.y * dir.y + dir.z * dir.z).sqrt().max(1e-5);
        let forward = Vec3::new(dir.x / f_len, dir.y / f_len, dir.z / f_len);
        let world_up = Vec3::new(0.0, 1.0, 0.0);
        // Left-handed cross: right = world_up x forward
        let mut rx = world_up.y * forward.z - world_up.z * forward.y;
        let mut ry = world_up.z * forward.x - world_up.x * forward.z;
        let mut rz = world_up.x * forward.y - world_up.y * forward.x;
        let r_len = (rx * rx + ry * ry + rz * rz).sqrt();
        if r_len < 1e-4 {
            rx = 1.0;
            ry = 0.0;
            rz = 0.0;
        } else {
            rx /= r_len;
            ry /= r_len;
            rz /= r_len;
        }
        let right = Vec3::new(rx, ry, rz);
        // up = forward x right
        let up = Vec3::new(
            forward.y * right.z - forward.z * right.y,
            forward.z * right.x - forward.x * right.z,
            forward.x * right.y - forward.y * right.x,
        );
        let aspect = (width.max(1) as f32) / (height.max(1) as f32);
        Self {
            pos,
            forward,
            right,
            up,
            fov_y_rad: fov_deg.to_radians(),
            aspect,
            z_near: 0.5,
            z_far: 650.0,
        }
    }

    pub fn from_orbit(target: Vec3, yaw: f32, pitch: f32, dist: f32, width: u32, height: u32) -> Self {
        let cp = pitch.cos();
        let sp = pitch.sin();
        let dir = Vec3::new(yaw.sin() * cp, -sp, yaw.cos() * cp);
        let pos = Vec3::new(
            target.x - dir.x * dist,
            target.y - dir.y * dist,
            target.z - dir.z * dist,
        );
        Self::from_pos_dir(pos, dir, width, height, 60.0)
    }

    #[inline]
    pub fn project(&self, p: Vec3, fb_w: f32, fb_h: f32) -> Option<(f32, f32, f32)> {
        let dx = p.x - self.pos.x;
        let dy = p.y - self.pos.y;
        let dz = p.z - self.pos.z;
        let vz = dx * self.forward.x + dy * self.forward.y + dz * self.forward.z;
        if vz <= self.z_near || vz > self.z_far {
            return None;
        }
        let vx = dx * self.right.x + dy * self.right.y + dz * self.right.z;
        let vy = dx * self.up.x + dy * self.up.y + dz * self.up.z;

        let tan_half_y = (self.fov_y_rad * 0.5).tan();
        let tan_half_x = tan_half_y * self.aspect;
        let ndc_x = vx / (vz * tan_half_x);
        let ndc_y = vy / (vz * tan_half_y);
        if ndc_x < -1.6 || ndc_x > 1.6 || ndc_y < -1.6 || ndc_y > 1.6 {
            return None;
        }
        let sx = (ndc_x * 0.5 + 0.5) * fb_w;
        let sy = (0.5 - ndc_y * 0.5) * fb_h;
        Some((sx, sy, vz))
    }
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum EntityVisualKind {
    Player,
    Npc,
    Monster,
    Portal,
}

#[derive(Debug, Clone)]
pub struct WorldEntity3D {
    pub id: u32,
    pub name: String,
    pub title: String,
    pub kind: EntityVisualKind,
    pub pos: Vec3,
    pub yaw: f32,
    pub scale: f32,
    pub primary_color: u32,
    pub accent_color: u32,
    pub hp_ratio: f32,
    pub selected: bool,
    pub flying: bool,
}

pub struct FrameBuffer {
    pub width: u32,
    pub height: u32,
    pub pixels: Vec<u32>,
    pub zbuf: Vec<f32>,
    /// Queued ClearType GDI text commands (also drawn via software bitmap fallback if requested).
    pub text_queue: Vec<OverlayTextCmd>,
}

impl FrameBuffer {
    pub fn new(width: u32, height: u32) -> Self {
        let n = (width.max(1) as usize) * (height.max(1) as usize);
        Self {
            width: width.max(1),
            height: height.max(1),
            pixels: vec![0xFF0B_1018; n],
            zbuf: vec![f32::INFINITY; n],
            text_queue: Vec::with_capacity(256),
        }
    }

    pub fn resize(&mut self, width: u32, height: u32) {
        let w = width.max(1);
        let h = height.max(1);
        if self.width != w || self.height != h {
            self.width = w;
            self.height = h;
            let n = (w as usize) * (h as usize);
            self.pixels.resize(n, 0xFF0B_1018);
            self.zbuf.resize(n, f32::INFINITY);
        }
    }

    pub fn begin_frame(&mut self) {
        self.zbuf.fill(f32::INFINITY);
        self.text_queue.clear();
    }

    /// Encodes the 32-bit `0xAARRGGBB` framebuffer into a lossless 24-bit `.bmp` image.
    pub fn encode_bmp(&self) -> Vec<u8> {
        let w = self.width as usize;
        let h = self.height as usize;
        let row_bytes = (w * 3 + 3) & !3;
        let img_bytes = row_bytes * h;
        let file_size = 54 + img_bytes;
        let mut out = vec![0u8; file_size];
        out[0..2].copy_from_slice(b"BM");
        out[2..6].copy_from_slice(&(file_size as u32).to_le_bytes());
        out[10..14].copy_from_slice(&54u32.to_le_bytes());
        out[14..18].copy_from_slice(&40u32.to_le_bytes());
        out[18..22].copy_from_slice(&(w as i32).to_le_bytes());
        out[22..26].copy_from_slice(&(h as i32).to_le_bytes());
        out[26..28].copy_from_slice(&1u16.to_le_bytes());
        out[28..30].copy_from_slice(&24u16.to_le_bytes());
        out[34..38].copy_from_slice(&(img_bytes as u32).to_le_bytes());
        for y in 0..h {
            let src_row = (h - 1 - y) * w;
            let dst_row = 54 + y * row_bytes;
            for x in 0..w {
                let px = self.pixels[src_row + x];
                out[dst_row + x * 3] = (px & 0xFF) as u8;
                out[dst_row + x * 3 + 1] = ((px >> 8) & 0xFF) as u8;
                out[dst_row + x * 3 + 2] = ((px >> 16) & 0xFF) as u8;
            }
        }
        out
    }

    #[inline]
    pub fn blend_pixel(&mut self, x: i32, y: i32, src_argb: u32) {
        if x < 0 || y < 0 || x >= self.width as i32 || y >= self.height as i32 {
            return;
        }
        let a = (src_argb >> 24) & 0xFF;
        if a == 0 {
            return;
        }
        let idx = (y as usize) * (self.width as usize) + (x as usize);
        if a == 255 {
            self.pixels[idx] = src_argb | 0xFF00_0000;
            return;
        }
        let dst = self.pixels[idx];
        let inv_a = 255 - a;
        let r = (((src_argb >> 16) & 0xFF) * a + ((dst >> 16) & 0xFF) * inv_a) / 255;
        let g = (((src_argb >> 8) & 0xFF) * a + ((dst >> 8) & 0xFF) * inv_a) / 255;
        let b = ((src_argb & 0xFF) * a + (dst & 0xFF) * inv_a) / 255;
        self.pixels[idx] = 0xFF00_0000 | (r << 16) | (g << 8) | b;
    }

    pub fn fill_rect(&mut self, x: i32, y: i32, w: i32, h: i32, argb: u32) {
        let a = (argb >> 24) & 0xFF;
        if a == 0 || w <= 0 || h <= 0 {
            return;
        }
        let x0 = x.max(0);
        let y0 = y.max(0);
        let x1 = (x + w).min(self.width as i32);
        let y1 = (y + h).min(self.height as i32);
        if x0 >= x1 || y0 >= y1 {
            return;
        }
        let stride = self.width as usize;
        if a == 255 {
            let solid = argb | 0xFF00_0000;
            for py in y0..y1 {
                let row = (py as usize) * stride;
                self.pixels[row + x0 as usize..row + x1 as usize].fill(solid);
            }
        } else {
            let inv_a = 255 - a;
            let sr = ((argb >> 16) & 0xFF) * a;
            let sg = ((argb >> 8) & 0xFF) * a;
            let sb = (argb & 0xFF) * a;
            for py in y0..y1 {
                let row = (py as usize) * stride;
                for px in x0 as usize..x1 as usize {
                    let dst = self.pixels[row + px];
                    let r = (sr + ((dst >> 16) & 0xFF) * inv_a) / 255;
                    let g = (sg + ((dst >> 8) & 0xFF) * inv_a) / 255;
                    let b = (sb + (dst & 0xFF) * inv_a) / 255;
                    self.pixels[row + px] = 0xFF00_0000 | (r << 16) | (g << 8) | b;
                }
            }
        }
    }

    pub fn draw_border(&mut self, x: i32, y: i32, w: i32, h: i32, thickness: i32, argb: u32) {
        if w <= 0 || h <= 0 || thickness <= 0 {
            return;
        }
        self.fill_rect(x, y, w, thickness, argb);
        self.fill_rect(x, y + h - thickness, w, thickness, argb);
        self.fill_rect(x, y + thickness, thickness, h - thickness * 2, argb);
        self.fill_rect(x + w - thickness, y + thickness, thickness, h - thickness * 2, argb);
    }

    /// Draws an ornate Perfect World 1.4.2 jade-obsidian & gold-trimmed dialog panel.
    pub fn draw_pw_panel(&mut self, x: i32, y: i32, w: i32, h: i32, alpha: u8) {
        let bg = ((alpha as u32) << 24) | 0x0013_1A24;
        self.fill_rect(x, y, w, h, bg);
        // Subtle top header sheen
        self.fill_rect(x + 2, y + 2, w - 4, 26.min(h - 4), 0x442A_3C54);
        // Outer dark trim + inner PW gold trim
        self.draw_border(x, y, w, h, 1, 0xEE08_0B10);
        self.draw_border(x + 1, y + 1, w - 2, h - 2, 1, 0xCC9E_7D3B);
        self.draw_border(x + 2, y + 2, w - 4, h - 4, 1, 0x553B_4E68);
        // Corner gold accents
        for &(cx, cy) in &[(x + 1, y + 1), (x + w - 5, y + 1), (x + 1, y + h - 5), (x + w - 5, y + h - 5)] {
            self.fill_rect(cx, cy, 4, 4, 0xFFE2_B85C);
        }
    }

    pub fn draw_pw_button(&mut self, x: i32, y: i32, w: i32, h: i32, hovered: bool, pressed: bool, primary: bool) {
        let (top_c, bot_c, border_c) = if pressed {
            (0xEE2B_2214, 0xEE4A_391E, 0xFFFF_D26E)
        } else if hovered {
            if primary {
                (0xF06A_4E20, 0xF03E_2B10, 0xFFFF_DF88)
            } else {
                (0xEA2E_3F56, 0xEA1B_2636, 0xFFE6_BE64)
            }
        } else if primary {
            (0xE852_3B16, 0xE82D_1F0B, 0xFFD4_A64A)
        } else {
            (0xE022_2F42, 0xE014_1C28, 0xFFA8_8743)
        };
        let half = (h / 2).max(1);
        self.fill_rect(x, y, w, half, top_c);
        self.fill_rect(x, y + half, w, h - half, bot_c);
        self.draw_border(x, y, w, h, 1, border_c);
    }

    pub fn blit_surface_scaled(&mut self, img: &SurfaceImage, dx: i32, dy: i32, dw: i32, dh: i32, tint_alpha: u8) {
        if dw <= 0 || dh <= 0 || img.width == 0 || img.height == 0 || tint_alpha == 0 {
            return;
        }
        let x0 = dx.max(0);
        let y0 = dy.max(0);
        let x1 = (dx + dw).min(self.width as i32);
        let y1 = (dy + dh).min(self.height as i32);
        if x0 >= x1 || y0 >= y1 {
            return;
        }
        let iw = img.width as usize;
        let ih = img.height as usize;
        for py in y0..y1 {
            let sy = (((py - dy) as usize) * ih / (dh as usize)).min(ih - 1);
            let srow = sy * iw;
            for px in x0..x1 {
                let sx = (((px - dx) as usize) * iw / (dw as usize)).min(iw - 1);
                let mut c = img.pixels[srow + sx];
                let a = (((c >> 24) & 0xFF) * (tint_alpha as u32)) / 255;
                if a > 0 {
                    c = (c & 0x00FF_FFFF) | (a << 24);
                    self.blend_pixel(px, py, c);
                }
            }
        }
    }

    pub fn draw_line_2d(&mut self, mut x0: i32, mut y0: i32, x1: i32, y1: i32, argb: u32) {
        let dx = (x1 - x0).abs();
        let sx = if x0 < x1 { 1 } else { -1 };
        let dy = -(y1 - y0).abs();
        let sy = if y0 < y1 { 1 } else { -1 };
        let mut err = dx + dy;
        let mut steps = 0;
        loop {
            self.blend_pixel(x0, y0, argb);
            if x0 == x1 && y0 == y1 || steps > 4096 {
                break;
            }
            steps += 1;
            let e2 = 2 * err;
            if e2 >= dy {
                err += dy;
                x0 += sx;
            }
            if e2 <= dx {
                err += dx;
                y0 += sy;
            }
        }
    }

    /// Queues text for Win32 ClearType GDI rendering (and draws bitmap fallback if `also_raster` is set).
    pub fn push_text(&mut self, x: i32, y: i32, text: impl Into<String>, color: u32, font_px: u16, bold: bool) {
        self.text_queue.push(OverlayTextCmd {
            x,
            y,
            text: text.into(),
            color,
            font_px,
            bold,
            shadow: true,
        });
    }

    /// Draws immediate crisp pixel glyphs into `self.pixels` AND queues GDI overlay command.
    pub fn draw_text(&mut self, x: i32, y: i32, text: &str, color: u32, scale: i32) {
        let sc = scale.max(1);
        let mut cx = x;
        for ch in text.chars() {
            draw_glyph_fallback(self, cx, y, ch, color, sc);
            cx += 6 * sc;
        }
        self.text_queue.push(OverlayTextCmd {
            x,
            y,
            text: text.to_string(),
            color,
            font_px: if sc >= 2 { 18 } else { 13 },
            bold: sc >= 2,
            shadow: false,
        });
    }

    /// Rasterizes queued text directly into `self.pixels` using a built-in 6x10 glyph set
    /// (used for non-Windows / headless tests & screenshots).
    pub fn rasterize_queued_text_fallback(&mut self) {
        let cmds = self.text_queue.clone();
        for cmd in cmds {
            let scale = if cmd.font_px >= 18 { 2 } else { 1 };
            let mut cx = cmd.x;
            for ch in cmd.text.chars() {
                if cmd.shadow {
                    draw_glyph_fallback(self, cx + 1, cmd.y + 1, ch, 0xCC00_0000, scale);
                }
                draw_glyph_fallback(self, cx, cmd.y, ch, cmd.color | 0xFF00_0000, scale);
                cx += 7 * scale;
            }
        }
    }

    /// Renders the full 3D Angelica scene: Sky + Sun + Fog + `Terrain2HeightMesh` + Water + Entities.
    pub fn render_world_3d(
        &mut self,
        cam: &SceneCamera3D,
        mesh: &Terrain2HeightMesh,
        entities: &[WorldEntity3D],
        time_of_day_hours: f32,
        water_level: f32,
        anim_seconds: f32,
    ) {
        let h = self.height as i32;
        let wf = self.width as f32;
        let hf = self.height as f32;

        // 1. Day / Twilight / Night atmospheric palette
        let day_phase = ((time_of_day_hours - 6.0) / 12.0 * core::f32::consts::PI).sin().clamp(-1.0, 1.0);
        let night_factor = ((-day_phase + 0.25) / 1.25).clamp(0.0, 1.0);
        let dusk_factor = (1.0 - day_phase.abs() * 2.2).clamp(0.0, 1.0);

        let lerp_rgb = |c0: u32, c1: u32, t: f32| -> (u32, u32, u32) {
            let t = t.clamp(0.0, 1.0);
            let r = ((c0 >> 16 & 0xFF) as f32 * (1.0 - t) + (c1 >> 16 & 0xFF) as f32 * t) as u32;
            let g = ((c0 >> 8 & 0xFF) as f32 * (1.0 - t) + (c1 >> 8 & 0xFF) as f32 * t) as u32;
            let b = ((c0 & 0xFF) as f32 * (1.0 - t) + (c1 & 0xFF) as f32 * t) as u32;
            (r, g, b)
        };

        let (zen_r, zen_g, zen_b) = lerp_rgb(0x1E4B8A, 0x090F22, night_factor);
        let (mut hor_r, mut hor_g, mut hor_b) = lerp_rgb(0x7DA8D4, 0x1D2842, night_factor);
        if dusk_factor > 0.01 {
            hor_r = (hor_r as f32 * (1.0 - dusk_factor * 0.55) + 228.0 * dusk_factor * 0.55) as u32;
            hor_g = (hor_g as f32 * (1.0 - dusk_factor * 0.45) + 132.0 * dusk_factor * 0.45) as u32;
            hor_b = (hor_b as f32 * (1.0 - dusk_factor * 0.45) + 92.0 * dusk_factor * 0.45) as u32;
        }
        let fog_rgb = (hor_r, hor_g, hor_b);

        // Sky gradient + horizon haze + animated cloud wisps
        let horizon_y = (hf * (0.5 + cam.forward.y * 0.65)).clamp(0.0, hf);
        let stride = self.width as usize;
        for py in 0..h {
            let t = (py as f32 / horizon_y.max(1.0)).clamp(0.0, 1.0);
            let t_smooth = t * t * (3.0 - 2.0 * t);
            let mut r = zen_r + ((hor_r as i32 - zen_r as i32) * (t_smooth * 256.0) as i32 / 256) as u32;
            let mut g = zen_g + ((hor_g as i32 - zen_g as i32) * (t_smooth * 256.0) as i32 / 256) as u32;
            let mut b = zen_b + ((hor_b as i32 - zen_b as i32) * (t_smooth * 256.0) as i32 / 256) as u32;
            if (py as f32) > horizon_y {
                // Below horizon fallback (deep water/mist)
                let bt = (((py as f32) - horizon_y) / (hf - horizon_y).max(1.0)).clamp(0.0, 1.0);
                r = (hor_r as f32 * (1.0 - bt * 0.55)) as u32;
                g = (hor_g as f32 * (1.0 - bt * 0.45)) as u32;
                b = (hor_b as f32 * (1.0 - bt * 0.35)) as u32;
            }
            let row_off = (py as usize) * stride;
            let base_c = 0xFF00_0000 | (r.min(255) << 16) | (g.min(255) << 8) | b.min(255);
            self.pixels[row_off..row_off + stride].fill(base_c);
        }

        // Sun / Moon celestial halo
        let sun_angle = (time_of_day_hours - 6.0) / 24.0 * core::f32::consts::TAU;
        let sun_pos = Vec3::new(
            cam.pos.x + sun_angle.cos() * 420.0,
            cam.pos.y + sun_angle.sin().abs() * 220.0 + 45.0,
            cam.pos.z + 320.0,
        );
        if let Some((sx, sy, _)) = cam.project(sun_pos, wf, hf) {
            let sun_r = (hf * 0.065) as i32;
            let scx = sx as i32;
            let scy = sy as i32;
            for oy in -sun_r..=sun_r {
                for ox in -sun_r..=sun_r {
                    let d2 = ox * ox + oy * oy;
                    if d2 <= sun_r * sun_r {
                        let falloff = 1.0 - (d2 as f32 / (sun_r * sun_r) as f32).sqrt();
                        let a = (falloff * falloff * 190.0) as u32;
                        let col = if night_factor > 0.6 {
                            (a << 24) | 0x00D8_E8FF
                        } else {
                            (a << 24) | 0x00FF_ECA8
                        };
                        self.blend_pixel(scx + ox, scy + oy, col);
                    }
                }
            }
        }

        // 2. Angelica Terrain2 + Water Heightfield Rasterizer (2-ring adaptive grid around camera)
        let rings: &[(f32, f32, f32)] = &[
            (0.0, 128.0, 4.0),
            (120.0, 340.0, 12.0),
        ];

        for &(r_min, r_max, step) in rings {
            let snap = |v: f32| (v / step).floor() * step;
            let min_x = snap(cam.pos.x - r_max);
            let max_x = snap(cam.pos.x + r_max);
            let min_z = snap(cam.pos.z - r_max);
            let max_z = snap(cam.pos.z + r_max);

            let mut gz = min_z;
            while gz < max_z {
                let mut gx = min_x;
                while gx < max_x {
                    let cx = gx + step * 0.5 - cam.pos.x;
                    let cz = gz + step * 0.5 - cam.pos.z;
                    // Quick frustum dot check
                    let fwd_dot = cx * cam.forward.x + cz * cam.forward.z;
                    let dist_sq = cx * cx + cz * cz;
                    if fwd_dot > -step * 2.0
                        && dist_sq >= r_min * r_min * 0.75
                        && dist_sq <= r_max * r_max
                    {
                        let h00 = mesh.sample_height(gx, gz);
                        let h10 = mesh.sample_height(gx + step, gz);
                        let h01 = mesh.sample_height(gx, gz + step);
                        let h11 = mesh.sample_height(gx + step, gz + step);

                        let y00 = h00.max(water_level);
                        let y10 = h10.max(water_level);
                        let y01 = h01.max(water_level);
                        let y11 = h11.max(water_level);

                        if let (
                            Some(p00),
                            Some(p10),
                            Some(p01),
                            Some(p11),
                        ) = (
                            cam.project(Vec3::new(gx, y00, gz), wf, hf),
                            cam.project(Vec3::new(gx + step, y10, gz), wf, hf),
                            cam.project(Vec3::new(gx, y01, gz + step), wf, hf),
                            cam.project(Vec3::new(gx + step, y11, gz + step), wf, hf),
                        ) {
                            let avg_h = (h00 + h10 + h01 + h11) * 0.25;
                            let is_water = avg_h < water_level + 0.05;
                            let shade_col = if is_water {
                                let depth = (water_level - avg_h).clamp(0.0, 25.0) / 25.0;
                                let wave = ((gx * 0.14 + anim_seconds * 2.1).sin()
                                    * (gz * 0.13 - anim_seconds * 1.7).cos())
                                    * 14.0;
                                let wr = ((26.0 * (1.0 - depth) + 12.0 * depth + wave).clamp(8.0, 90.0)
                                    * (1.0 - night_factor * 0.55)) as u32;
                                let wg = ((92.0 * (1.0 - depth) + 46.0 * depth + wave).clamp(20.0, 165.0)
                                    * (1.0 - night_factor * 0.5)) as u32;
                                let wb = ((148.0 * (1.0 - depth) + 96.0 * depth + wave * 1.3)
                                    .clamp(45.0, 225.0)
                                    * (1.0 - night_factor * 0.4)) as u32;
                                0xFF00_0000 | (wr << 16) | (wg << 8) | wb
                            } else {
                                let base = mesh.sample_color(gx + step * 0.5, gz + step * 0.5, night_factor);
                                // Directional sunlight modulation (`light_dir = (0.15, -0.70, 0.695)`)
                                let dx_h = (h10 - h00) / step;
                                let dz_h = (h01 - h00) / step;
                                let sun_lit = (0.78 - dx_h * 0.22 - dz_h * 0.28).clamp(0.42, 1.28);
                                let br = (((base >> 16) & 0xFF) as f32 * sun_lit).clamp(0.0, 255.0) as u32;
                                let bg = (((base >> 8) & 0xFF) as f32 * sun_lit).clamp(0.0, 255.0) as u32;
                                let bb = ((base & 0xFF) as f32 * sun_lit).clamp(0.0, 255.0) as u32;
                                0xFF00_0000 | (br << 16) | (bg << 8) | bb
                            };

                            let avg_z = (p00.2 + p10.2 + p01.2 + p11.2) * 0.25;
                            let fog_t = ((avg_z - 65.0) / 275.0).clamp(0.0, 1.0);
                            let final_col = apply_fog(shade_col, fog_rgb, fog_t);

                            self.raster_tri_flat(p00, p01, p10, final_col);
                            self.raster_tri_flat(p10, p01, p11, final_col);
                        }
                    }
                    gx += step;
                }
                gz += step;
            }
        }

        // 3. Render 3D World Entities (Players, NPCs, Monsters, Portals)
        for ent in entities {
            self.render_entity_3d(cam, ent, anim_seconds);
        }
    }

    fn raster_tri_flat(
        &mut self,
        v0: (f32, f32, f32),
        v1: (f32, f32, f32),
        v2: (f32, f32, f32),
        color: u32,
    ) {
        let min_x = v0.0.min(v1.0).min(v2.0).floor().max(0.0) as i32;
        let max_x = v0.0.max(v1.0).max(v2.0).ceil().min(self.width as f32 - 1.0) as i32;
        let min_y = v0.1.min(v1.1).min(v2.1).floor().max(0.0) as i32;
        let max_y = v0.1.max(v1.1).max(v2.1).ceil().min(self.height as f32 - 1.0) as i32;
        if min_x > max_x || min_y > max_y {
            return;
        }
        let area = (v1.0 - v0.0) * (v2.1 - v0.1) - (v1.1 - v0.1) * (v2.0 - v0.0);
        if area.abs() < 0.25 {
            return;
        }
        let inv_area = 1.0 / area;
        let stride = self.width as usize;

        for py in min_y..=max_y {
            let fy = py as f32 + 0.5;
            let row = (py as usize) * stride;
            for px in min_x..=max_x {
                let fx = px as f32 + 0.5;
                let w0 = ((v1.0 - fx) * (v2.1 - fy) - (v1.1 - fy) * (v2.0 - fx)) * inv_area;
                let w1 = ((v2.0 - fx) * (v0.1 - fy) - (v2.1 - fy) * (v0.0 - fx)) * inv_area;
                let w2 = 1.0 - w0 - w1;
                if w0 >= -0.001 && w1 >= -0.001 && w2 >= -0.001 {
                    let z = w0 * v0.2 + w1 * v1.2 + w2 * v2.2;
                    let idx = row + px as usize;
                    if z < self.zbuf[idx] {
                        self.zbuf[idx] = z;
                        self.pixels[idx] = color;
                    }
                }
            }
        }
    }

    fn render_entity_3d(&mut self, cam: &SceneCamera3D, ent: &WorldEntity3D, anim_s: f32) {
        let wf = self.width as f32;
        let hf = self.height as f32;
        let bob = if ent.flying {
            (anim_s * 3.0 + ent.id as f32).sin() * 0.18
        } else {
            0.0
        };
        let base = Vec3::new(ent.pos.x, ent.pos.y + bob, ent.pos.z);
        let head_top = Vec3::new(ent.pos.x, ent.pos.y + 1.9 * ent.scale + bob, ent.pos.z);

        let Some((bx, by, bz)) = cam.project(base, wf, hf) else {
            return;
        };
        let Some((tx, ty, _)) = cam.project(head_top, wf, hf) else {
            return;
        };
        let sprite_h = (by - ty).abs().max(6.0);
        let sprite_w = (sprite_h * 0.42).max(4.0);
        let cx = ((bx + tx) * 0.5) as i32;
        let top_y = ty.min(by) as i32;
        let bot_y = by.max(ty) as i32;

        // Ground selection / aura ring
        if ent.selected || ent.kind == EntityVisualKind::Portal || ent.flying {
            let ring_col = if ent.selected {
                0xDDFF_D84D
            } else if ent.kind == EntityVisualKind::Portal {
                0xBB56_D8FF
            } else {
                0x9980_E4FF
            };
            let rx = (sprite_w * 0.95) as i32;
            let ry = (rx / 3).max(2);
            for deg in (0..360).step_by(12) {
                let rad = (deg as f32).to_radians();
                let px = cx + (rad.cos() * rx as f32) as i32;
                let py = bot_y + (rad.sin() * ry as f32) as i32;
                self.blend_pixel(px, py, ring_col);
                self.blend_pixel(px + 1, py, ring_col);
            }
        }

        // Depth test center against terrain z-buffer
        let check_x = cx.clamp(0, self.width as i32 - 1) as usize;
        let check_y = ((top_y + bot_y) / 2).clamp(0, self.height as i32 - 1) as usize;
        if bz > self.zbuf[check_y * (self.width as usize) + check_x] + 2.5 {
            return;
        }

        if ent.kind == EntityVisualKind::Portal {
            let r = (sprite_w as i32).max(8);
            for oy in -r * 2..=0 {
                let w_slice = ((1.0 - (oy as f32 / (-r as f32) - 1.0).powi(2)).max(0.0).sqrt() * r as f32) as i32;
                self.fill_rect(cx - w_slice, bot_y + oy, w_slice * 2, 1, 0x8844_CCFF);
            }
        } else {
            // Stylized 3D character silhouette: legs + armored torso + shoulders + head + flying sword/wings
            let head_r = (sprite_h * 0.13).max(2.0) as i32;
            let torso_w = (sprite_w * 0.68).max(3.0) as i32;
            let torso_h = (sprite_h * 0.42).max(4.0) as i32;
            let leg_h = (sprite_h * 0.36).max(3.0) as i32;
            let torso_y = top_y + head_r * 2 + 1;

            if ent.flying {
                // Flying sword / wings beneath/behind avatar
                let wing_span = (sprite_w * 1.45) as i32;
                self.draw_line_2d(cx - wing_span, bot_y + 2, cx + wing_span, bot_y + 2, 0xDD78_E8FF);
                self.draw_line_2d(cx - wing_span + 2, bot_y + 3, cx + wing_span - 2, bot_y + 3, 0xAAFFFFFF);
            }

            // Cloak / accent
            self.fill_rect(
                cx - torso_w / 2 - 2,
                torso_y + 2,
                torso_w + 4,
                torso_h + leg_h / 2,
                (ent.accent_color & 0x00FF_FFFF) | 0xAA00_0000,
            );
            // Legs
            let leg_w = (torso_w / 3).max(2);
            self.fill_rect(cx - torso_w / 2 + 1, torso_y + torso_h, leg_w, leg_h, 0xFF28_2E3C);
            self.fill_rect(cx + torso_w / 2 - leg_w - 1, torso_y + torso_h, leg_w, leg_h, 0xFF28_2E3C);
            // Torso armor
            self.fill_rect(cx - torso_w / 2, torso_y, torso_w, torso_h, ent.primary_color | 0xFF00_0000);
            self.draw_border(cx - torso_w / 2, torso_y, torso_w, torso_h, 1, ent.accent_color | 0xFF00_0000);
            // Head
            self.fill_rect(cx - head_r, top_y, head_r * 2, head_r * 2, 0xFFF0_C8A4);
            self.fill_rect(cx - head_r, top_y, head_r * 2, head_r.max(1), 0xFF2B_221C);
        }

        // Floating Nameplate & HP bar (for close/medium range)
        if bz < 135.0 && !ent.name.is_empty() {
            let name_col = match ent.kind {
                EntityVisualKind::Player => 0xFFFF_F2B2,
                EntityVisualKind::Npc => 0xFF7C_FF8A,
                EntityVisualKind::Monster => 0xFFFF_7A7A,
                EntityVisualKind::Portal => 0xFF7A_E6FF,
            };
            let approx_w = (ent.name.chars().count() as i32) * 7;
            if ent.selected || ent.hp_ratio < 0.999 {
                let bar_w = 48;
                self.fill_rect(cx - bar_w / 2, top_y - 22, bar_w, 5, 0xCC10_141C);
                self.fill_rect(
                    cx - bar_w / 2 + 1,
                    top_y - 21,
                    ((bar_w - 2) as f32 * ent.hp_ratio.clamp(0.0, 1.0)) as i32,
                    3,
                    0xFFE8_3C3C,
                );
            }
            self.push_text(cx - approx_w / 2, top_y - 15, ent.name.clone(), name_col, 12, true);
        }
    }
}

#[inline]
fn apply_fog(color: u32, fog_rgb: (u32, u32, u32), fog_t: f32) -> u32 {
    if fog_t <= 0.005 {
        return color;
    }
    let inv = 1.0 - fog_t;
    let r = (((color >> 16) & 0xFF) as f32 * inv + fog_rgb.0 as f32 * fog_t) as u32;
    let g = (((color >> 8) & 0xFF) as f32 * inv + fog_rgb.1 as f32 * fog_t) as u32;
    let b = ((color & 0xFF) as f32 * inv + fog_rgb.2 as f32 * fog_t) as u32;
    0xFF00_0000 | (r.min(255) << 16) | (g.min(255) << 8) | b.min(255)
}

/// Compact 5x7 crisp pixel font for headless / non-Windows fallback text rendering.
fn draw_glyph_fallback(fb: &mut FrameBuffer, x: i32, y: i32, ch: char, col: u32, scale: i32) {
    let rows: [u8; 7] = match ch.to_ascii_uppercase() {
        'A' => [0x0E, 0x11, 0x11, 0x1F, 0x11, 0x11, 0x11],
        'B' => [0x1E, 0x11, 0x11, 0x1E, 0x11, 0x11, 0x1E],
        'C' => [0x0E, 0x11, 0x10, 0x10, 0x10, 0x11, 0x0E],
        'D' => [0x1E, 0x11, 0x11, 0x11, 0x11, 0x11, 0x1E],
        'E' => [0x1F, 0x10, 0x10, 0x1E, 0x10, 0x10, 0x1F],
        'F' => [0x1F, 0x10, 0x10, 0x1E, 0x10, 0x10, 0x10],
        'G' => [0x0E, 0x11, 0x10, 0x17, 0x11, 0x11, 0x0F],
        'H' => [0x11, 0x11, 0x11, 0x1F, 0x11, 0x11, 0x11],
        'I' => [0x0E, 0x04, 0x04, 0x04, 0x04, 0x04, 0x0E],
        'J' => [0x07, 0x02, 0x02, 0x02, 0x12, 0x12, 0x0C],
        'K' => [0x11, 0x12, 0x14, 0x18, 0x14, 0x12, 0x11],
        'L' => [0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x1F],
        'M' => [0x11, 0x1B, 0x15, 0x15, 0x11, 0x11, 0x11],
        'N' => [0x11, 0x19, 0x15, 0x13, 0x11, 0x11, 0x11],
        'O' => [0x0E, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0E],
        'P' => [0x1E, 0x11, 0x11, 0x1E, 0x10, 0x10, 0x10],
        'Q' => [0x0E, 0x11, 0x11, 0x11, 0x15, 0x12, 0x0D],
        'R' => [0x1E, 0x11, 0x11, 0x1E, 0x14, 0x12, 0x11],
        'S' => [0x0F, 0x10, 0x10, 0x0E, 0x01, 0x01, 0x1E],
        'T' => [0x1F, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04],
        'U' => [0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0E],
        'V' => [0x11, 0x11, 0x11, 0x11, 0x11, 0x0A, 0x04],
        'W' => [0x11, 0x11, 0x11, 0x15, 0x15, 0x1B, 0x11],
        'X' => [0x11, 0x11, 0x0A, 0x04, 0x0A, 0x11, 0x11],
        'Y' => [0x11, 0x11, 0x0A, 0x04, 0x04, 0x04, 0x04],
        'Z' => [0x1F, 0x01, 0x02, 0x04, 0x08, 0x10, 0x1F],
        '0' => [0x0E, 0x11, 0x13, 0x15, 0x19, 0x11, 0x0E],
        '1' => [0x04, 0x0C, 0x04, 0x04, 0x04, 0x04, 0x0E],
        '2' => [0x0E, 0x11, 0x01, 0x06, 0x08, 0x10, 0x1F],
        '3' => [0x1F, 0x02, 0x04, 0x06, 0x01, 0x11, 0x0E],
        '4' => [0x02, 0x06, 0x0A, 0x12, 0x1F, 0x02, 0x02],
        '5' => [0x1F, 0x10, 0x1E, 0x01, 0x01, 0x11, 0x0E],
        '6' => [0x06, 0x08, 0x10, 0x1E, 0x11, 0x11, 0x0E],
        '7' => [0x1F, 0x01, 0x02, 0x04, 0x08, 0x08, 0x08],
        '8' => [0x0E, 0x11, 0x11, 0x0E, 0x11, 0x11, 0x0E],
        '9' => [0x0E, 0x11, 0x11, 0x0F, 0x01, 0x02, 0x0C],
        ':' => [0x00, 0x04, 0x04, 0x00, 0x04, 0x04, 0x00],
        '.' => [0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x06],
        ',' => [0x00, 0x00, 0x00, 0x00, 0x04, 0x04, 0x08],
        '-' => [0x00, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x00],
        '+' => [0x00, 0x04, 0x04, 0x1F, 0x04, 0x04, 0x00],
        '/' => [0x01, 0x02, 0x02, 0x04, 0x08, 0x08, 0x10],
        '(' | '[' => [0x06, 0x08, 0x08, 0x08, 0x08, 0x08, 0x06],
        ')' | ']' => [0x0C, 0x02, 0x02, 0x02, 0x02, 0x02, 0x0C],
        '*' => [0x00, 0x15, 0x0E, 0x1F, 0x0E, 0x15, 0x00],
        '_' => [0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F],
        '%' => [0x18, 0x19, 0x02, 0x04, 0x08, 0x13, 0x03],
        '!' => [0x04, 0x04, 0x04, 0x04, 0x04, 0x00, 0x04],
        '?' => [0x0E, 0x11, 0x01, 0x06, 0x04, 0x00, 0x04],
        '|' => [0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04],
        '\'' => [0x04, 0x04, 0x08, 0x00, 0x00, 0x00, 0x00],
        '"' => [0x0A, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00],
        '<' => [0x02, 0x04, 0x08, 0x10, 0x08, 0x04, 0x02],
        '>' => [0x08, 0x04, 0x02, 0x01, 0x02, 0x04, 0x08],
        '=' => [0x00, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x00],
        '@' => [0x0E, 0x11, 0x17, 0x15, 0x17, 0x10, 0x0E],
        ' ' => return,
        _ => [0x0E, 0x11, 0x15, 0x11, 0x15, 0x11, 0x0E],
    };
    for (ry, &bits) in rows.iter().enumerate() {
        for rx in 0..5 {
            if (bits & (1 << (4 - rx))) != 0 {
                fb.fill_rect(x + (rx as i32) * scale, y + (ry as i32) * scale, scale, scale, col);
            }
        }
    }
}
