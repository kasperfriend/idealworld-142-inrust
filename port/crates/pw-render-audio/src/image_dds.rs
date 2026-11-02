//! Pure-Rust Angelica Texture & Surface Decoders (`.dds`, `.tga`, `.bmp`).
//!
//! Decodes all UI & 3D texture formats used by `surfaces.pck` and `textures.pck` into
//! premultiplied/straight `0xAARRGGBB` (`BGRA` in little-endian memory, matching Win32 `DIBSection`).

use pw_core::{BinaryCursor, PwError, PwResult};

#[derive(Debug, Clone)]
pub struct SurfaceImage {
    pub width: u32,
    pub height: u32,
    /// Row-major top-to-bottom `0xAARRGGBB` Level-0 pixels.
    pub pixels: Vec<u32>,
    /// Pre-filtered mipmap chain `[(w1, h1, pixels1), (w2, h2, pixels2), ...]` down to `1x1`.
    pub mips: Vec<(u32, u32, Vec<u32>)>,
}

#[inline]
fn lerp_argb_256(c0: u32, c1: u32, t256: u32) -> u32 {
    let it = 256 - t256;
    let a = (((c0 >> 24) & 0xFF) * it + ((c1 >> 24) & 0xFF) * t256) >> 8;
    let r = (((c0 >> 16) & 0xFF) * it + ((c1 >> 16) & 0xFF) * t256) >> 8;
    let g = (((c0 >> 8) & 0xFF) * it + ((c1 >> 8) & 0xFF) * t256) >> 8;
    let b = ((c0 & 0xFF) * it + (c1 & 0xFF) * t256) >> 8;
    (a << 24) | (r << 16) | (g << 8) | b
}

#[inline]
fn sample_buf_bilinear_wrap(w: usize, h: usize, buf: &[u32], u: f32, v: f32) -> u32 {
    if w == 0 || h == 0 || buf.is_empty() {
        return 0;
    }
    if w == 1 && h == 1 {
        return buf[0];
    }
    let fx = u.rem_euclid(1.0) * (w as f32) - 0.5;
    let fy = v.rem_euclid(1.0) * (h as f32) - 0.5;
    let x0i = fx.floor() as isize;
    let y0i = fy.floor() as isize;
    let tx = ((fx - x0i as f32) * 256.0).clamp(0.0, 256.0) as u32;
    let ty = ((fy - y0i as f32) * 256.0).clamp(0.0, 256.0) as u32;
    let x0 = x0i.rem_euclid(w as isize) as usize;
    let y0 = y0i.rem_euclid(h as isize) as usize;
    let x1 = (x0 + 1) % w;
    let y1 = (y0 + 1) % h;
    let itx = 256 - tx;
    let ity = 256 - ty;
    let w00 = itx * ity;
    let w10 = tx * ity;
    let w01 = itx * ty;
    let w11 = tx * ty;
    let c00 = buf[y0 * w + x0];
    let c10 = buf[y0 * w + x1];
    let c01 = buf[y1 * w + x0];
    let c11 = buf[y1 * w + x1];
    let a = (((c00 >> 24) & 0xFF) * w00
        + ((c10 >> 24) & 0xFF) * w10
        + ((c01 >> 24) & 0xFF) * w01
        + ((c11 >> 24) & 0xFF) * w11)
        >> 16;
    let r = (((c00 >> 16) & 0xFF) * w00
        + ((c10 >> 16) & 0xFF) * w10
        + ((c01 >> 16) & 0xFF) * w01
        + ((c11 >> 16) & 0xFF) * w11)
        >> 16;
    let g = (((c00 >> 8) & 0xFF) * w00
        + ((c10 >> 8) & 0xFF) * w10
        + ((c01 >> 8) & 0xFF) * w01
        + ((c11 >> 8) & 0xFF) * w11)
        >> 16;
    let b = ((c00 & 0xFF) * w00
        + (c10 & 0xFF) * w10
        + (c01 & 0xFF) * w01
        + (c11 & 0xFF) * w11)
        >> 16;
    (a << 24) | (r << 16) | (g << 8) | b
}

impl SurfaceImage {
    pub fn from_pixels(width: u32, height: u32, pixels: Vec<u32>) -> Self {
        Self {
            width,
            height,
            pixels,
            mips: Vec::new(),
        }
    }

    pub fn from_pixels_with_mips(width: u32, height: u32, pixels: Vec<u32>) -> Self {
        let mut img = Self {
            width,
            height,
            pixels,
            mips: Vec::new(),
        };
        img.build_mipmaps();
        img
    }

    pub fn solid(width: u32, height: u32, argb: u32) -> Self {
        Self {
            width,
            height,
            pixels: vec![argb; (width as usize) * (height as usize)],
            mips: Vec::new(),
        }
    }

    /// Generates a full alpha-weighted box-filtered mipmap pyramid (`Level 1 .. 1x1`) whenever
    /// `.mips` is empty (e.g. `.tga`, `.bmp`, single-level `.dds`, or runtime-baked composites).
    pub fn build_mipmaps(&mut self) {
        self.mips.clear();
        if self.width <= 1 && self.height <= 1 {
            return;
        }
        let mut prev_w = self.width as usize;
        let mut prev_h = self.height as usize;
        let mut prev_px: &[u32] = &self.pixels;
        let mut owned_levels: Vec<(u32, u32, Vec<u32>)> = Vec::with_capacity(11);

        while prev_w > 1 || prev_h > 1 {
            let nw = (prev_w / 2).max(1);
            let nh = (prev_h / 2).max(1);
            let mut next = vec![0u32; nw * nh];
            for y in 0..nh {
                let sy0 = (y * 2).min(prev_h - 1);
                let sy1 = (y * 2 + 1).min(prev_h - 1);
                for x in 0..nw {
                    let sx0 = (x * 2).min(prev_w - 1);
                    let sx1 = (x * 2 + 1).min(prev_w - 1);
                    let samples = [
                        prev_px[sy0 * prev_w + sx0],
                        prev_px[sy0 * prev_w + sx1],
                        prev_px[sy1 * prev_w + sx0],
                        prev_px[sy1 * prev_w + sx1],
                    ];
                    let mut sum_a = 0u32;
                    let mut sum_wr = 0u32;
                    let mut sum_wg = 0u32;
                    let mut sum_wb = 0u32;
                    let mut sum_r = 0u32;
                    let mut sum_g = 0u32;
                    let mut sum_b = 0u32;
                    for c in samples {
                        let a = (c >> 24) & 0xFF;
                        let r = (c >> 16) & 0xFF;
                        let g = (c >> 8) & 0xFF;
                        let b = c & 0xFF;
                        sum_a += a;
                        sum_wr += r * a;
                        sum_wg += g * a;
                        sum_wb += b * a;
                        sum_r += r;
                        sum_g += g;
                        sum_b += b;
                    }
                    let out_a = (sum_a + 2) >> 2;
                    let (out_r, out_g, out_b) = if sum_a > 0 {
                        (
                            (sum_wr + sum_a / 2) / sum_a,
                            (sum_wg + sum_a / 2) / sum_a,
                            (sum_wb + sum_a / 2) / sum_a,
                        )
                    } else {
                        ((sum_r + 2) >> 2, (sum_g + 2) >> 2, (sum_b + 2) >> 2)
                    };
                    next[y * nw + x] = (out_a << 24) | (out_r << 16) | (out_g << 8) | out_b;
                }
            }
            owned_levels.push((nw as u32, nh as u32, next));
            let last = owned_levels.last().unwrap();
            prev_w = last.0 as usize;
            prev_h = last.1 as usize;
            prev_px = &last.2;
        }
        self.mips = owned_levels;
    }

    #[inline]
    pub fn mip_count(&self) -> usize {
        1 + self.mips.len()
    }

    #[inline]
    pub fn sample_clamped(&self, x: i32, y: i32) -> u32 {
        if self.width == 0 || self.height == 0 {
            return 0;
        }
        let cx = x.clamp(0, self.width as i32 - 1) as usize;
        let cy = y.clamp(0, self.height as i32 - 1) as usize;
        self.pixels[cy * (self.width as usize) + cx]
    }

    #[inline]
    pub fn sample_uv(&self, u: f32, v: f32) -> u32 {
        if self.width == 0 || self.height == 0 {
            return 0;
        }
        let uw = u.rem_euclid(1.0);
        let vw = v.rem_euclid(1.0);
        let x = ((uw * self.width as f32) as usize).min(self.width as usize - 1);
        let y = ((vw * self.height as f32) as usize).min(self.height as usize - 1);
        self.pixels[y * (self.width as usize) + x]
    }

    #[inline]
    pub fn sample_uv_clamp(&self, u: f32, v: f32) -> u32 {
        if self.width == 0 || self.height == 0 {
            return 0;
        }
        let x = ((u.clamp(0.0, 0.99999) * self.width as f32) as usize).min(self.width as usize - 1);
        let y = ((v.clamp(0.0, 0.99999) * self.height as f32) as usize).min(self.height as usize - 1);
        self.pixels[y * (self.width as usize) + x]
    }

    /// Seamless wrap-around bilinear filter (`D3DTADDRESS_WRAP` + `D3DTEXF_LINEAR`).
    #[inline]
    pub fn sample_uv_bilinear(&self, u: f32, v: f32) -> u32 {
        sample_buf_bilinear_wrap(self.width as usize, self.height as usize, &self.pixels, u, v)
    }

    /// Edge-clamped bilinear filter (`D3DTADDRESS_CLAMP` + `D3DTEXF_LINEAR`) — used for sky domes,
    /// portraits, UI icons, and regional/world maps so magnification has zero staircase pixels.
    #[inline]
    pub fn sample_uv_bilinear_clamp(&self, u: f32, v: f32) -> u32 {
        if self.width == 0 || self.height == 0 || self.pixels.is_empty() {
            return 0;
        }
        let w = self.width as usize;
        let h = self.height as usize;
        let fx = (u.clamp(0.0, 1.0) * (w as f32) - 0.5).clamp(0.0, (w.saturating_sub(1)) as f32);
        let fy = (v.clamp(0.0, 1.0) * (h as f32) - 0.5).clamp(0.0, (h.saturating_sub(1)) as f32);
        let x0 = (fx as usize).min(w - 1);
        let y0 = (fy as usize).min(h - 1);
        let x1 = (x0 + 1).min(w - 1);
        let y1 = (y0 + 1).min(h - 1);
        let tx = ((fx - x0 as f32) * 256.0) as u32;
        let ty = ((fy - y0 as f32) * 256.0) as u32;
        let itx = 256 - tx;
        let ity = 256 - ty;
        let w00 = itx * ity;
        let w10 = tx * ity;
        let w01 = itx * ty;
        let w11 = tx * ty;
        let c00 = self.pixels[y0 * w + x0];
        let c10 = self.pixels[y0 * w + x1];
        let c01 = self.pixels[y1 * w + x0];
        let c11 = self.pixels[y1 * w + x1];
        let a = (((c00 >> 24) & 0xFF) * w00
            + ((c10 >> 24) & 0xFF) * w10
            + ((c01 >> 24) & 0xFF) * w01
            + ((c11 >> 24) & 0xFF) * w11)
            >> 16;
        let r = (((c00 >> 16) & 0xFF) * w00
            + ((c10 >> 16) & 0xFF) * w10
            + ((c01 >> 16) & 0xFF) * w01
            + ((c11 >> 16) & 0xFF) * w11)
            >> 16;
        let g = (((c00 >> 8) & 0xFF) * w00
            + ((c10 >> 8) & 0xFF) * w10
            + ((c01 >> 8) & 0xFF) * w01
            + ((c11 >> 8) & 0xFF) * w11)
            >> 16;
        let b = ((c00 & 0xFF) * w00
            + (c10 & 0xFF) * w10
            + (c01 & 0xFF) * w01
            + (c11 & 0xFF) * w11)
            >> 16;
        (a << 24) | (r << 16) | (g << 8) | b
    }

    #[inline]
    pub fn sample_mip_bilinear(&self, level: usize, u: f32, v: f32) -> u32 {
        if level == 0 || self.mips.is_empty() {
            return self.sample_uv_bilinear(u, v);
        }
        let idx = (level - 1).min(self.mips.len() - 1);
        let (mw, mh, ref mbuf) = self.mips[idx];
        sample_buf_bilinear_wrap(mw as usize, mh as usize, mbuf, u, v)
    }

    /// True trilinear mipmap interpolation (`D3DSAMP_MIPFILTER = D3DTEXF_LINEAR`).
    #[inline]
    pub fn sample_uv_trilinear(&self, u: f32, v: f32, lod: f32) -> u32 {
        if lod <= 0.0 || self.mips.is_empty() {
            return self.sample_uv_bilinear(u, v);
        }
        let max_lod = self.mips.len() as f32;
        let clamped = lod.min(max_lod);
        let lo = clamped.floor() as usize;
        let frac = ((clamped - lo as f32) * 256.0) as u32;
        if frac == 0 || lo >= self.mips.len() {
            return self.sample_mip_bilinear(lo, u, v);
        }
        let c0 = self.sample_mip_bilinear(lo, u, v);
        let c1 = self.sample_mip_bilinear(lo + 1, u, v);
        lerp_argb_256(c0, c1, frac)
    }

    /// 4x Anisotropic + Trilinear mipmap sampler driven by screen-space UV Jacobian `(dudx, dvdx, dudy, dvdy)`.
    #[inline]
    pub fn sample_uv_anisotropic(
        &self,
        u: f32,
        v: f32,
        dudx: f32,
        dvdx: f32,
        dudy: f32,
        dvdy: f32,
    ) -> u32 {
        let wf = self.width as f32;
        let hf = self.height as f32;
        let jx_u = dudx * wf;
        let jx_v = dvdx * hf;
        let jy_u = dudy * wf;
        let jy_v = dvdy * hf;
        let len_x2 = jx_u * jx_u + jx_v * jx_v;
        let len_y2 = jy_u * jy_u + jy_v * jy_v;
        let (maj_u, maj_v, maj2, min2) = if len_x2 >= len_y2 {
            (dudx, dvdx, len_x2, len_y2)
        } else {
            (dudy, dvdy, len_y2, len_x2)
        };
        if maj2 <= 1.10 || self.mips.is_empty() {
            return self.sample_uv_bilinear(u, v);
        }
        let maj_len = maj2.sqrt();
        let min_len = min2.sqrt().max(0.25);
        let ratio = (maj_len / min_len).min(4.0);
        if ratio <= 1.65 {
            let lod = 0.5 * maj2.log2() - 0.15;
            return self.sample_uv_trilinear(u, v, lod);
        }
        // 4-tap anisotropic line integration along major screen-space footprint axis:
        let iso_lod = (maj_len * 0.25).max(min_len).log2() - 0.10;
        let s0 = self.sample_uv_trilinear(u - maj_u * 0.375, v - maj_v * 0.375, iso_lod);
        let s1 = self.sample_uv_trilinear(u - maj_u * 0.125, v - maj_v * 0.125, iso_lod);
        let s2 = self.sample_uv_trilinear(u + maj_u * 0.125, v + maj_v * 0.125, iso_lod);
        let s3 = self.sample_uv_trilinear(u + maj_u * 0.375, v + maj_v * 0.375, iso_lod);
        let a = (((s0 >> 24) & 0xFF) + ((s1 >> 24) & 0xFF) + ((s2 >> 24) & 0xFF) + ((s3 >> 24) & 0xFF) + 2) >> 2;
        let r = (((s0 >> 16) & 0xFF) + ((s1 >> 16) & 0xFF) + ((s2 >> 16) & 0xFF) + ((s3 >> 16) & 0xFF) + 2) >> 2;
        let g = (((s0 >> 8) & 0xFF) + ((s1 >> 8) & 0xFF) + ((s2 >> 8) & 0xFF) + ((s3 >> 8) & 0xFF) + 2) >> 2;
        let b = ((s0 & 0xFF) + (s1 & 0xFF) + (s2 & 0xFF) + (s3 & 0xFF) + 2) >> 2;
        (a << 24) | (r << 16) | (g << 8) | b
    }

    /// Applies Angelica `A2DSprite` `RGB(255, 0, 255)` color-key transparency (used by UI `.bmp` files
    /// like `Window\对话框_透明色.bmp`).
    pub fn apply_magenta_colorkey(&mut self) {
        let mut changed = false;
        for px in &mut self.pixels {
            let r = (*px >> 16) & 0xFF;
            let g = (*px >> 8) & 0xFF;
            let b = *px & 0xFF;
            if r >= 250 && g <= 5 && b >= 250 {
                *px = 0x0000_0000;
                changed = true;
            }
        }
        if changed && !self.mips.is_empty() {
            self.build_mipmaps();
        }
    }

    /// Encodes a `0xAARRGGBB` buffer as a standard 24-bit `.bmp` image for visual verification.
    pub fn encode_bmp_24(width: u32, height: u32, pixels: &[u32]) -> Vec<u8> {
        let w = width as usize;
        let h = height as usize;
        let row_stride = (w * 3 + 3) & !3;
        let img_bytes = row_stride * h;
        let file_bytes = 54 + img_bytes;
        let mut out = Vec::with_capacity(file_bytes);
        out.extend_from_slice(b"BM");
        out.extend_from_slice(&(file_bytes as u32).to_le_bytes());
        out.extend_from_slice(&0u32.to_le_bytes());
        out.extend_from_slice(&54u32.to_le_bytes());
        out.extend_from_slice(&40u32.to_le_bytes());
        out.extend_from_slice(&(width as i32).to_le_bytes());
        out.extend_from_slice(&(height as i32).to_le_bytes());
        out.extend_from_slice(&1u16.to_le_bytes());
        out.extend_from_slice(&24u16.to_le_bytes());
        out.extend_from_slice(&0u32.to_le_bytes());
        out.extend_from_slice(&(img_bytes as u32).to_le_bytes());
        out.extend_from_slice(&2835i32.to_le_bytes());
        out.extend_from_slice(&2835i32.to_le_bytes());
        out.extend_from_slice(&0u32.to_le_bytes());
        out.extend_from_slice(&0u32.to_le_bytes());
        let pad = [0u8; 3];
        for y in (0..h).rev() {
            let row = &pixels[y * w..(y + 1) * w];
            for &px in row {
                out.push((px & 0xFF) as u8);
                out.push(((px >> 8) & 0xFF) as u8);
                out.push(((px >> 16) & 0xFF) as u8);
            }
            let rem = row_stride - w * 3;
            if rem > 0 {
                out.extend_from_slice(&pad[..rem]);
            }
        }
        out
    }
}

/// Auto-detects `.dds`, `.bmp`, or `.tga` by magic / header and decodes into `SurfaceImage`.
pub fn decode_surface_auto(bytes: &[u8]) -> PwResult<SurfaceImage> {
    if bytes.len() >= 4 && &bytes[0..4] == b"DDS " {
        return decode_dds(bytes);
    }
    if bytes.len() >= 2 && &bytes[0..2] == b"BM" {
        return decode_bmp(bytes);
    }
    if bytes.len() >= 3 && bytes[0..3] == [0xFF, 0xD8, 0xFF] {
        return Err(PwError::InvalidData("JPEG stream requires WIC/GDI+ rather than DDS/BMP/TGA".into()));
    }
    if bytes.len() >= 4 && &bytes[0..4] == b"\x89PNG" {
        return Err(PwError::InvalidData("PNG stream requires WIC/GDI+ rather than DDS/BMP/TGA".into()));
    }
    decode_tga(bytes)
}

#[inline]
fn pack_argb(a: u8, r: u8, g: u8, b: u8) -> u32 {
    ((a as u32) << 24) | ((r as u32) << 16) | ((g as u32) << 8) | (b as u32)
}

#[inline]
fn rgb565_to_rgb(c: u16) -> (u8, u8, u8) {
    let r5 = ((c >> 11) & 0x1F) as u32;
    let g6 = ((c >> 5) & 0x3F) as u32;
    let b5 = (c & 0x1F) as u32;
    let r = ((r5 * 255 + 15) / 31) as u8;
    let g = ((g6 * 255 + 31) / 63) as u8;
    let b = ((b5 * 255 + 15) / 31) as u8;
    (r, g, b)
}

fn decode_dxt_level(fourcc: &[u8], w: usize, h: usize, data: &[u8]) -> PwResult<(Vec<u32>, usize)> {
    let bx = (w + 3) / 4;
    let by = (h + 3) / 4;
    let mut pixels = vec![0u32; w * h];
    let mut pos = 0usize;
    match fourcc {
        b"DXT1" => {
            for gy in 0..by {
                for gx in 0..bx {
                    if pos + 8 > data.len() {
                        break;
                    }
                    let c0 = u16::from_le_bytes([data[pos], data[pos + 1]]);
                    let c1 = u16::from_le_bytes([data[pos + 2], data[pos + 3]]);
                    let bits = u32::from_le_bytes([
                        data[pos + 4],
                        data[pos + 5],
                        data[pos + 6],
                        data[pos + 7],
                    ]);
                    pos += 8;

                    let (r0, g0, b0) = rgb565_to_rgb(c0);
                    let (r1, g1, b1) = rgb565_to_rgb(c1);
                    let palette = if c0 > c1 {
                        [
                            pack_argb(255, r0, g0, b0),
                            pack_argb(255, r1, g1, b1),
                            pack_argb(
                                255,
                                ((2 * r0 as u16 + r1 as u16 + 1) / 3) as u8,
                                ((2 * g0 as u16 + g1 as u16 + 1) / 3) as u8,
                                ((2 * b0 as u16 + b1 as u16 + 1) / 3) as u8,
                            ),
                            pack_argb(
                                255,
                                ((r0 as u16 + 2 * r1 as u16 + 1) / 3) as u8,
                                ((g0 as u16 + 2 * g1 as u16 + 1) / 3) as u8,
                                ((b0 as u16 + 2 * b1 as u16 + 1) / 3) as u8,
                            ),
                        ]
                    } else {
                        [
                            pack_argb(255, r0, g0, b0),
                            pack_argb(255, r1, g1, b1),
                            pack_argb(
                                255,
                                ((r0 as u16 + r1 as u16) / 2) as u8,
                                ((g0 as u16 + g1 as u16) / 2) as u8,
                                ((b0 as u16 + b1 as u16) / 2) as u8,
                            ),
                            pack_argb(0, 0, 0, 0),
                        ]
                    };

                    for py in 0..4 {
                        let y = gy * 4 + py;
                        if y >= h {
                            continue;
                        }
                        for px in 0..4 {
                            let x = gx * 4 + px;
                            if x >= w {
                                continue;
                            }
                            let idx = ((bits >> (2 * (py * 4 + px))) & 0x3) as usize;
                            pixels[y * w + x] = palette[idx];
                        }
                    }
                }
            }
        }
        b"DXT3" => {
            for gy in 0..by {
                for gx in 0..bx {
                    if pos + 16 > data.len() {
                        break;
                    }
                    let alpha_bits = u64::from_le_bytes([
                        data[pos],
                        data[pos + 1],
                        data[pos + 2],
                        data[pos + 3],
                        data[pos + 4],
                        data[pos + 5],
                        data[pos + 6],
                        data[pos + 7],
                    ]);
                    let c0 = u16::from_le_bytes([data[pos + 8], data[pos + 9]]);
                    let c1 = u16::from_le_bytes([data[pos + 10], data[pos + 11]]);
                    let bits = u32::from_le_bytes([
                        data[pos + 12],
                        data[pos + 13],
                        data[pos + 14],
                        data[pos + 15],
                    ]);
                    pos += 16;

                    let (r0, g0, b0) = rgb565_to_rgb(c0);
                    let (r1, g1, b1) = rgb565_to_rgb(c1);
                    let rgb_pal = [
                        (r0, g0, b0),
                        (r1, g1, b1),
                        (
                            ((2 * r0 as u16 + r1 as u16 + 1) / 3) as u8,
                            ((2 * g0 as u16 + g1 as u16 + 1) / 3) as u8,
                            ((2 * b0 as u16 + b1 as u16 + 1) / 3) as u8,
                        ),
                        (
                            ((r0 as u16 + 2 * r1 as u16 + 1) / 3) as u8,
                            ((g0 as u16 + 2 * g1 as u16 + 1) / 3) as u8,
                            ((b0 as u16 + 2 * b1 as u16 + 1) / 3) as u8,
                        ),
                    ];

                    for py in 0..4 {
                        let y = gy * 4 + py;
                        if y >= h {
                            continue;
                        }
                        for px in 0..4 {
                            let x = gx * 4 + px;
                            if x >= w {
                                continue;
                            }
                            let p_idx = py * 4 + px;
                            let a4 = ((alpha_bits >> (p_idx * 4)) & 0xF) as u8;
                            let a = (a4 << 4) | a4;
                            let c_idx = ((bits >> (p_idx * 2)) & 0x3) as usize;
                            let (r, g, b) = rgb_pal[c_idx];
                            pixels[y * w + x] = pack_argb(a, r, g, b);
                        }
                    }
                }
            }
        }
        b"DXT5" => {
            for gy in 0..by {
                for gx in 0..bx {
                    if pos + 16 > data.len() {
                        break;
                    }
                    let a0 = data[pos];
                    let a1 = data[pos + 1];
                    let a_idx_bits: u64 = (data[pos + 2] as u64)
                        | ((data[pos + 3] as u64) << 8)
                        | ((data[pos + 4] as u64) << 16)
                        | ((data[pos + 5] as u64) << 24)
                        | ((data[pos + 6] as u64) << 32)
                        | ((data[pos + 7] as u64) << 40);

                    let mut a_pal = [0u8; 8];
                    a_pal[0] = a0;
                    a_pal[1] = a1;
                    if a0 > a1 {
                        for k in 1..7 {
                            a_pal[k + 1] =
                                (((7 - k) as u16 * a0 as u16 + k as u16 * a1 as u16 + 3) / 7)
                                    as u8;
                        }
                    } else {
                        for k in 1..5 {
                            a_pal[k + 1] =
                                (((5 - k) as u16 * a0 as u16 + k as u16 * a1 as u16 + 2) / 5)
                                    as u8;
                        }
                        a_pal[6] = 0;
                        a_pal[7] = 255;
                    }

                    let c0 = u16::from_le_bytes([data[pos + 8], data[pos + 9]]);
                    let c1 = u16::from_le_bytes([data[pos + 10], data[pos + 11]]);
                    let bits = u32::from_le_bytes([
                        data[pos + 12],
                        data[pos + 13],
                        data[pos + 14],
                        data[pos + 15],
                    ]);
                    pos += 16;

                    let (r0, g0, b0) = rgb565_to_rgb(c0);
                    let (r1, g1, b1) = rgb565_to_rgb(c1);
                    let rgb_pal = [
                        (r0, g0, b0),
                        (r1, g1, b1),
                        (
                            ((2 * r0 as u16 + r1 as u16 + 1) / 3) as u8,
                            ((2 * g0 as u16 + g1 as u16 + 1) / 3) as u8,
                            ((2 * b0 as u16 + b1 as u16 + 1) / 3) as u8,
                        ),
                        (
                            ((r0 as u16 + 2 * r1 as u16 + 1) / 3) as u8,
                            ((g0 as u16 + 2 * g1 as u16 + 1) / 3) as u8,
                            ((b0 as u16 + 2 * b1 as u16 + 1) / 3) as u8,
                        ),
                    ];

                    for py in 0..4 {
                        let y = gy * 4 + py;
                        if y >= h {
                            continue;
                        }
                        for px in 0..4 {
                            let x = gx * 4 + px;
                            if x >= w {
                                continue;
                            }
                            let p_idx = py * 4 + px;
                            let ai = ((a_idx_bits >> (p_idx * 3)) & 0x7) as usize;
                            let ci = ((bits >> (p_idx * 2)) & 0x3) as usize;
                            let (r, g, b) = rgb_pal[ci];
                            pixels[y * w + x] = pack_argb(a_pal[ai], r, g, b);
                        }
                    }
                }
            }
        }
        _ => {
            return Err(PwError::InvalidData(format!(
                "unsupported DDS FourCC {:?}",
                String::from_utf8_lossy(fourcc)
            )));
        }
    }
    Ok((pixels, pos))
}

/// Decodes DirectDraw Surface (`.dds`) INCLUDING full pre-filtered mipmap chains (`mip_map_count`):
/// `DXT1`, `DXT3`, `DXT5`, `A8R8G8B8`, `X8R8G8B8`, `A8B8G8R8`, `R8G8B8`, `R5G6B5`, `A1R5G5B5`, `A4R4G4B4`, `L8`, `A8L8`.
pub fn decode_dds(bytes: &[u8]) -> PwResult<SurfaceImage> {
    if bytes.len() < 128 || &bytes[0..4] != b"DDS " {
        return Err(PwError::InvalidData("invalid DDS header".into()));
    }
    let mut cur = BinaryCursor::new(&bytes[4..128]);
    let _hdr_size = cur.read_u32_le()?;
    let flags = cur.read_u32_le()?;
    let height = cur.read_u32_le()?.max(1);
    let width = cur.read_u32_le()?.max(1);
    let _pitch_or_linear = cur.read_u32_le()?;
    let _depth = cur.read_u32_le()?;
    let raw_mip_count = cur.read_u32_le()?;
    let _reserved = cur.read_bytes(44)?;

    // DDS_PIXELFORMAT (32 bytes at file offset 76)
    let _pf_size = cur.read_u32_le()?;
    let pf_flags = cur.read_u32_le()?;
    let fourcc = cur.read_bytes(4)?;
    let rgb_bit_count = cur.read_u32_le()?;
    let r_mask = cur.read_u32_le()?;
    let g_mask = cur.read_u32_le()?;
    let b_mask = cur.read_u32_le()?;
    let a_mask = cur.read_u32_le()?;

    const DDSD_MIPMAPCOUNT: u32 = 0x0002_0000;
    let mip_levels = if (flags & DDSD_MIPMAPCOUNT) != 0 && raw_mip_count >= 2 {
        (raw_mip_count as usize).min(14)
    } else {
        1usize
    };

    let data = &bytes[128..];
    let w = width as usize;
    let h = height as usize;

    const DDPF_FOURCC: u32 = 0x0000_0004;
    const DDPF_ALPHAPIXELS: u32 = 0x0000_0001;

    if (pf_flags & DDPF_FOURCC) != 0 {
        let (pixels0, mut consumed) = decode_dxt_level(fourcc, w, h, data)?;
        let mut mips = Vec::new();
        let mut mw = w;
        let mut mh = h;
        for _ in 1..mip_levels {
            if mw == 1 && mh == 1 {
                break;
            }
            mw = (mw / 2).max(1);
            mh = (mh / 2).max(1);
            let block_bytes = if fourcc == b"DXT1" { 8 } else { 16 };
            let need = ((mw + 3) / 4) * ((mh + 3) / 4) * block_bytes;
            if consumed + need > data.len() {
                break;
            }
            let (mpx, step) = decode_dxt_level(fourcc, mw, mh, &data[consumed..])?;
            consumed += step;
            mips.push((mw as u32, mh as u32, mpx));
        }
        let mut img = SurfaceImage {
            width,
            height,
            pixels: pixels0,
            mips,
        };
        if img.mips.is_empty() && (width > 1 || height > 1) {
            img.build_mipmaps();
        }
        return Ok(img);
    }

    let mut pixels = vec![0u32; w * h];

    // Uncompressed RGB / Luminance DDS
    let has_alpha = (pf_flags & DDPF_ALPHAPIXELS) != 0 && a_mask != 0;
    let extract_chan = |val: u32, mask: u32, default_v: u8| -> u8 {
        if mask == 0 {
            return default_v;
        }
        let shift = mask.trailing_zeros();
        let bits = (mask >> shift).count_ones();
        let raw = (val & mask) >> shift;
        let max_v = (1u32 << bits) - 1;
        ((raw * 255 + max_v / 2) / max_v) as u8
    };

    match rgb_bit_count {
        32 => {
            for (i, dst) in pixels.iter_mut().enumerate() {
                let p = i * 4;
                if p + 4 > data.len() {
                    break;
                }
                let v = u32::from_le_bytes([data[p], data[p + 1], data[p + 2], data[p + 3]]);
                let r = extract_chan(v, if r_mask != 0 { r_mask } else { 0x00FF_0000 }, 255);
                let g = extract_chan(v, if g_mask != 0 { g_mask } else { 0x0000_FF00 }, 255);
                let b = extract_chan(v, if b_mask != 0 { b_mask } else { 0x0000_00FF }, 255);
                let a = if has_alpha {
                    extract_chan(v, a_mask, 255)
                } else {
                    255
                };
                *dst = pack_argb(a, r, g, b);
            }
        }
        24 => {
            for (i, dst) in pixels.iter_mut().enumerate() {
                let p = i * 3;
                if p + 3 > data.len() {
                    break;
                }
                let v = (data[p] as u32) | ((data[p + 1] as u32) << 8) | ((data[p + 2] as u32) << 16);
                let r = extract_chan(v, if r_mask != 0 { r_mask } else { 0x00FF_0000 }, 255);
                let g = extract_chan(v, if g_mask != 0 { g_mask } else { 0x0000_FF00 }, 255);
                let b = extract_chan(v, if b_mask != 0 { b_mask } else { 0x0000_00FF }, 255);
                *dst = pack_argb(255, r, g, b);
            }
        }
        16 => {
            for (i, dst) in pixels.iter_mut().enumerate() {
                let p = i * 2;
                if p + 2 > data.len() {
                    break;
                }
                let v = u16::from_le_bytes([data[p], data[p + 1]]) as u32;
                if r_mask == 0 && g_mask == 0 && b_mask == 0 {
                    // A8L8
                    let l = (v & 0xFF) as u8;
                    let a = ((v >> 8) & 0xFF) as u8;
                    *dst = pack_argb(a, l, l, l);
                } else {
                    let r = extract_chan(v, r_mask, 0);
                    let g = extract_chan(v, g_mask, 0);
                    let b = extract_chan(v, b_mask, 0);
                    let a = if has_alpha {
                        extract_chan(v, a_mask, 255)
                    } else {
                        255
                    };
                    *dst = pack_argb(a, r, g, b);
                }
            }
        }
        8 => {
            for (i, dst) in pixels.iter_mut().enumerate() {
                if i >= data.len() {
                    break;
                }
                let l = data[i];
                *dst = if has_alpha {
                    pack_argb(l, 255, 255, 255)
                } else {
                    pack_argb(255, l, l, l)
                };
            }
        }
        _ => {
            return Err(PwError::InvalidData(format!(
                "unsupported DDS bit depth {rgb_bit_count}"
            )));
        }
    }

    Ok(SurfaceImage::from_pixels_with_mips(width, height, pixels))
}

/// Decodes Truevision `.tga` (uncompressed & RLE types 1, 2, 3, 9, 10, 11; 8/16/24/32-bit).
pub fn decode_tga(bytes: &[u8]) -> PwResult<SurfaceImage> {
    if bytes.len() < 18 {
        return Err(PwError::InvalidData("TGA shorter than 18-byte header".into()));
    }
    let id_len = bytes[0] as usize;
    let cmap_type = bytes[1];
    let img_type = bytes[2];
    let cmap_first = u16::from_le_bytes([bytes[3], bytes[4]]) as usize;
    let cmap_len = u16::from_le_bytes([bytes[5], bytes[6]]) as usize;
    let cmap_bpp = bytes[7] as usize;
    let width = u16::from_le_bytes([bytes[12], bytes[13]]) as u32;
    let height = u16::from_le_bytes([bytes[14], bytes[15]]) as u32;
    let bpp = bytes[16] as usize;
    let desc = bytes[17];

    if width == 0 || height == 0 || width > 8192 || height > 8192 {
        return Err(PwError::InvalidData(format!(
            "invalid TGA dimensions {width}x{height}"
        )));
    }
    let top_origin = (desc & 0x20) != 0;
    let mut pos = 18 + id_len;

    let mut palette = Vec::new();
    if cmap_type == 1 && cmap_len > 0 {
        let entry_bytes = (cmap_bpp + 7) / 8;
        palette.resize(cmap_first + cmap_len, pack_argb(255, 0, 0, 0));
        for i in 0..cmap_len {
            if pos + entry_bytes > bytes.len() {
                break;
            }
            let px = decode_tga_pixel(&bytes[pos..pos + entry_bytes], cmap_bpp);
            palette[cmap_first + i] = px;
            pos += entry_bytes;
        }
    }

    let bytes_per_px = (bpp + 7) / 8;
    if bytes_per_px == 0 {
        return Err(PwError::InvalidData("TGA 0 bpp".into()));
    }
    let total_px = (width as usize) * (height as usize);
    let mut raw_pixels = Vec::with_capacity(total_px);

    let read_one = |slice: &[u8]| -> u32 {
        if (img_type == 1 || img_type == 9) && !palette.is_empty() {
            let idx = slice[0] as usize;
            *palette.get(idx).unwrap_or(&0)
        } else {
            decode_tga_pixel(slice, bpp)
        }
    };

    let is_rle = img_type >= 9;
    if !is_rle {
        for _ in 0..total_px {
            if pos + bytes_per_px > bytes.len() {
                raw_pixels.push(0);
            } else {
                raw_pixels.push(read_one(&bytes[pos..pos + bytes_per_px]));
                pos += bytes_per_px;
            }
        }
    } else {
        while raw_pixels.len() < total_px && pos < bytes.len() {
            let hdr = bytes[pos];
            pos += 1;
            let count = ((hdr & 0x7F) as usize) + 1;
            if (hdr & 0x80) != 0 {
                if pos + bytes_per_px > bytes.len() {
                    break;
                }
                let px = read_one(&bytes[pos..pos + bytes_per_px]);
                pos += bytes_per_px;
                for _ in 0..count {
                    if raw_pixels.len() >= total_px {
                        break;
                    }
                    raw_pixels.push(px);
                }
            } else {
                for _ in 0..count {
                    if raw_pixels.len() >= total_px || pos + bytes_per_px > bytes.len() {
                        break;
                    }
                    raw_pixels.push(read_one(&bytes[pos..pos + bytes_per_px]));
                    pos += bytes_per_px;
                }
            }
        }
        raw_pixels.resize(total_px, 0);
    }

    let pixels = if top_origin {
        raw_pixels
    } else {
        let w = width as usize;
        let h = height as usize;
        let mut flipped = vec![0u32; total_px];
        for y in 0..h {
            let src_row = (h - 1 - y) * w;
            let dst_row = y * w;
            flipped[dst_row..dst_row + w].copy_from_slice(&raw_pixels[src_row..src_row + w]);
        }
        flipped
    };

    Ok(SurfaceImage::from_pixels_with_mips(width, height, pixels))
}

#[inline]
fn decode_tga_pixel(p: &[u8], bpp: usize) -> u32 {
    match bpp {
        32 => pack_argb(p[3], p[2], p[1], p[0]),
        24 => pack_argb(255, p[2], p[1], p[0]),
        16 | 15 => {
            let v = u16::from_le_bytes([p[0], p[1]]);
            let r = ((((v >> 10) & 0x1F) as u32 * 255 + 15) / 31) as u8;
            let g = ((((v >> 5) & 0x1F) as u32 * 255 + 15) / 31) as u8;
            let b = (((v & 0x1F) as u32 * 255 + 15) / 31) as u8;
            let a = if bpp == 16 && (v & 0x8000) == 0 { 0 } else { 255 };
            pack_argb(a, r, g, b)
        }
        8 => pack_argb(255, p[0], p[0], p[0]),
        _ => 0,
    }
}

/// Decodes Windows `.bmp` (8/16/24/32-bit) and applies Angelica UI's `RGB(255, 0, 255)` magic-pink
/// transparency key used across `interfaces.pck` (`Window\对话框_透明色.bmp`, menu icons, etc.).
pub fn decode_bmp(bytes: &[u8]) -> PwResult<SurfaceImage> {
    if bytes.len() < 54 || &bytes[0..2] != b"BM" {
        return Err(PwError::InvalidData("invalid BMP header".into()));
    }
    let pixel_offset = u32::from_le_bytes([bytes[10], bytes[11], bytes[12], bytes[13]]) as usize;
    let dib_size = u32::from_le_bytes([bytes[14], bytes[15], bytes[16], bytes[17]]) as usize;
    let width = i32::from_le_bytes([bytes[18], bytes[19], bytes[20], bytes[21]]);
    let height_signed = i32::from_le_bytes([bytes[22], bytes[23], bytes[24], bytes[25]]);
    let bpp = u16::from_le_bytes([bytes[28], bytes[29]]) as usize;
    let clr_used = u32::from_le_bytes([bytes[46], bytes[47], bytes[48], bytes[49]]) as usize;

    if width <= 0 || height_signed == 0 {
        return Err(PwError::InvalidData("invalid BMP dimensions".into()));
    }
    let top_down = height_signed < 0;
    let w = width as usize;
    let h = height_signed.unsigned_abs() as usize;

    let mut palette = [0u32; 256];
    if bpp == 8 {
        let pal_off = 14 + dib_size;
        let count = if clr_used > 0 { clr_used.min(256) } else { 256 };
        for i in 0..count {
            let o = pal_off + i * 4;
            if o + 4 <= bytes.len() {
                let (b, g, r) = (bytes[o], bytes[o + 1], bytes[o + 2]);
                let a = if r == 255 && g == 0 && b == 255 { 0 } else { 255 };
                palette[i] = pack_argb(a, r, g, b);
            }
        }
    }

    let stride = ((w * bpp + 31) / 32) * 4;
    let mut pixels = vec![0u32; w * h];
    for row in 0..h {
        let src_y = if top_down { row } else { h - 1 - row };
        let row_off = pixel_offset + src_y * stride;
        if row_off >= bytes.len() {
            continue;
        }
        for x in 0..w {
            let px = match bpp {
                32 => {
                    let o = row_off + x * 4;
                    if o + 4 > bytes.len() {
                        0
                    } else {
                        let (b, g, r, a0) = (bytes[o], bytes[o + 1], bytes[o + 2], bytes[o + 3]);
                        let a = if r == 255 && g == 0 && b == 255 {
                            0
                        } else if a0 == 0 {
                            255
                        } else {
                            a0
                        };
                        pack_argb(a, r, g, b)
                    }
                }
                24 => {
                    let o = row_off + x * 3;
                    if o + 3 > bytes.len() {
                        0
                    } else {
                        let (b, g, r) = (bytes[o], bytes[o + 1], bytes[o + 2]);
                        let a = if r == 255 && g == 0 && b == 255 { 0 } else { 255 };
                        pack_argb(a, r, g, b)
                    }
                }
                16 => {
                    let o = row_off + x * 2;
                    if o + 2 > bytes.len() {
                        0
                    } else {
                        let v = u16::from_le_bytes([bytes[o], bytes[o + 1]]);
                        let r = ((((v >> 10) & 0x1F) as u32 * 255 + 15) / 31) as u8;
                        let g = ((((v >> 5) & 0x1F) as u32 * 255 + 15) / 31) as u8;
                        let b = (((v & 0x1F) as u32 * 255 + 15) / 31) as u8;
                        let a = if r >= 248 && g == 0 && b >= 248 { 0 } else { 255 };
                        pack_argb(a, r, g, b)
                    }
                }
                8 => {
                    let o = row_off + x;
                    if o >= bytes.len() { 0 } else { palette[bytes[o] as usize] }
                }
                _ => 0,
            };
            pixels[row * w + x] = px;
        }
    }

    Ok(SurfaceImage::from_pixels_with_mips(w as u32, h as u32, pixels))
}

/// Decoded Win32 static `.cur` or animated RIFF `ACON` `.ani` game cursor (`cursors\normal.ani`, `hand.cur`, etc.).
#[derive(Debug, Clone)]
pub struct DecodedCursor {
    pub hotspot_x: i32,
    pub hotspot_y: i32,
    pub jiffies_per_frame: u32,
    pub frames: Vec<SurfaceImage>,
}

fn decode_single_cur_frame(bytes: &[u8]) -> PwResult<(i32, i32, SurfaceImage)> {
    if bytes.len() < 22 {
        return Err(PwError::UnexpectedEof {
            offset: 0,
            needed: 22,
            available: bytes.len(),
        });
    }
    let count = u16::from_le_bytes([bytes[4], bytes[5]]) as usize;
    if count == 0 {
        return Err(PwError::InvalidData("CUR frame count is 0".into()));
    }
    let dir_w = if bytes[6] == 0 { 256usize } else { bytes[6] as usize };
    let dir_h = if bytes[7] == 0 { 256usize } else { bytes[7] as usize };
    let hx = u16::from_le_bytes([bytes[10], bytes[11]]) as i32;
    let hy = u16::from_le_bytes([bytes[12], bytes[13]]) as i32;
    let dib_off = u32::from_le_bytes([bytes[18], bytes[19], bytes[20], bytes[21]]) as usize;
    if dib_off + 40 > bytes.len() {
        return Err(PwError::InvalidData("CUR DIB offset out of range".into()));
    }
    let bi_size = u32::from_le_bytes([
        bytes[dib_off],
        bytes[dib_off + 1],
        bytes[dib_off + 2],
        bytes[dib_off + 3],
    ]) as usize;
    let bi_w = i32::from_le_bytes([
        bytes[dib_off + 4],
        bytes[dib_off + 5],
        bytes[dib_off + 6],
        bytes[dib_off + 7],
    ]).unsigned_abs() as usize;
    let bi_h_raw = i32::from_le_bytes([
        bytes[dib_off + 8],
        bytes[dib_off + 9],
        bytes[dib_off + 10],
        bytes[dib_off + 11],
    ]);
    let bpp = u16::from_le_bytes([bytes[dib_off + 14], bytes[dib_off + 15]]);
    let w = if bi_w > 0 { bi_w } else { dir_w };
    let h = if bi_h_raw.unsigned_abs() as usize >= dir_h * 2 {
        (bi_h_raw.unsigned_abs() as usize) / 2
    } else {
        dir_h
    };
    let xor_off = dib_off + bi_size;
    if bpp != 32 || xor_off + w * h * 4 > bytes.len() {
        return Err(PwError::InvalidData(format!("Unsupported CUR bpp={bpp}")));
    }
    let xor_bytes = &bytes[xor_off..xor_off + w * h * 4];
    let and_off = xor_off + w * h * 4;
    let and_stride = ((w + 31) / 32) * 4;
    let has_any_alpha = xor_bytes.chunks_exact(4).any(|px| px[3] != 0);

    let mut pixels = vec![0u32; w * h];
    for row in 0..h {
        let src_y = h - 1 - row;
        for col in 0..w {
            let p = (src_y * w + col) * 4;
            let (b, g, r, a0) = (xor_bytes[p], xor_bytes[p + 1], xor_bytes[p + 2], xor_bytes[p + 3]);
            let and_transparent = if and_off + (src_y + 1) * and_stride <= bytes.len() {
                let mask_byte = bytes[and_off + src_y * and_stride + (col >> 3)];
                ((mask_byte >> (7 - (col & 7))) & 1) != 0
            } else {
                false
            };
            let a = if has_any_alpha {
                a0
            } else if and_transparent {
                0
            } else {
                255
            };
            pixels[row * w + col] = pack_argb(a, r, g, b);
        }
    }

    Ok((
        hx,
        hy,
        SurfaceImage::from_pixels(w as u32, h as u32, pixels),
    ))
}

/// Decodes either a static `.cur`/`.ico` cursor or a multi-frame RIFF `ACON` `.ani` animated cursor.
pub fn decode_cur_or_ani(bytes: &[u8]) -> PwResult<DecodedCursor> {
    if bytes.starts_with(b"RIFF") && bytes.len() >= 12 && &bytes[8..12] == b"ACON" {
        let mut frames = Vec::new();
        let mut hx = 0i32;
        let mut hy = 0i32;
        let mut jiffies = 5u32;
        let mut pos = 12usize;
        while pos + 8 <= bytes.len() {
            let cid = &bytes[pos..pos + 4];
            let csz = u32::from_le_bytes([
                bytes[pos + 4],
                bytes[pos + 5],
                bytes[pos + 6],
                bytes[pos + 7],
            ]) as usize;
            let chunk_end = (pos + 8 + csz).min(bytes.len());
            if cid == b"anih" && csz >= 36 && pos + 8 + 32 <= bytes.len() {
                let rate = u32::from_le_bytes([
                    bytes[pos + 8 + 28],
                    bytes[pos + 8 + 29],
                    bytes[pos + 8 + 30],
                    bytes[pos + 8 + 31],
                ]);
                if rate > 0 {
                    jiffies = rate;
                }
            } else if cid == b"LIST" && pos + 12 <= chunk_end && &bytes[pos + 8..pos + 12] == b"fram" {
                let mut spos = pos + 12;
                while spos + 8 <= chunk_end {
                    let scid = &bytes[spos..spos + 4];
                    let scsz = u32::from_le_bytes([
                        bytes[spos + 4],
                        bytes[spos + 5],
                        bytes[spos + 6],
                        bytes[spos + 7],
                    ]) as usize;
                    let sub_end = (spos + 8 + scsz).min(chunk_end);
                    if scid == b"icon" {
                        if let Ok((fx, fy, img)) = decode_single_cur_frame(&bytes[spos + 8..sub_end]) {
                            if frames.is_empty() {
                                hx = fx;
                                hy = fy;
                            }
                            frames.push(img);
                        }
                    }
                    spos = sub_end + (scsz & 1);
                }
            }
            pos = chunk_end + (csz & 1);
        }
        if frames.is_empty() {
            return Err(PwError::InvalidData("ANI contained 0 icon frames".into()));
        }
        Ok(DecodedCursor {
            hotspot_x: hx,
            hotspot_y: hy,
            jiffies_per_frame: jiffies,
            frames,
        })
    } else {
        let (hx, hy, img) = decode_single_cur_frame(bytes)?;
        Ok(DecodedCursor {
            hotspot_x: hx,
            hotspot_y: hy,
            jiffies_per_frame: 60,
            frames: vec![img],
        })
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_bmp_tga_and_dds_dxt1_decoders() {
        // Test 24-bit BMP with Angelica UI RGB(255, 0, 255) colorkey transparency
        let mut bmp = vec![0u8; 54 + 8];
        bmp[0..2].copy_from_slice(b"BM");
        bmp[2..6].copy_from_slice(&62u32.to_le_bytes());
        bmp[10..14].copy_from_slice(&54u32.to_le_bytes());
        bmp[14..18].copy_from_slice(&40u32.to_le_bytes());
        bmp[18..22].copy_from_slice(&2i32.to_le_bytes());
        bmp[22..26].copy_from_slice(&1i32.to_le_bytes());
        bmp[26..28].copy_from_slice(&1u16.to_le_bytes());
        bmp[28..30].copy_from_slice(&24u16.to_le_bytes());
        // Pixel 0: BGR(255, 0, 255) -> transparent! Pixel 1: BGR(0, 128, 255) -> opaque!
        bmp[54..60].copy_from_slice(&[255, 0, 255, 0, 128, 255]);
        let bmp_img = decode_surface_auto(&bmp).unwrap();
        assert_eq!(bmp_img.pixels[0] >> 24, 0);
        assert_eq!(bmp_img.pixels[1], 0xFFFF_8000);

        // Synthetic 2x1 32-bit TGA
        let mut tga = vec![0u8; 18 + 8];
        tga[2] = 2;
        tga[12..14].copy_from_slice(&2u16.to_le_bytes());
        tga[14..16].copy_from_slice(&1u16.to_le_bytes());
        tga[16] = 32;
        tga[17] = 0x20;
        tga[18..26].copy_from_slice(&[0x11, 0x22, 0x33, 0xFF, 0x44, 0x55, 0x66, 0x80]);
        let tga_img = decode_surface_auto(&tga).unwrap();
        assert_eq!(tga_img.pixels[0], 0xFF33_2211);
        assert_eq!(tga_img.pixels[1], 0x8066_5544);

        // Synthetic 4x4 DXT1 DDS
        let mut dds = vec![0u8; 128 + 8];
        dds[0..4].copy_from_slice(b"DDS ");
        dds[4..8].copy_from_slice(&124u32.to_le_bytes());
        dds[12..16].copy_from_slice(&4u32.to_le_bytes());
        dds[16..20].copy_from_slice(&4u32.to_le_bytes());
        dds[76..80].copy_from_slice(&32u32.to_le_bytes());
        dds[80..84].copy_from_slice(&0x4u32.to_le_bytes());
        dds[84..88].copy_from_slice(b"DXT1");
        dds[128..130].copy_from_slice(&0xF800u16.to_le_bytes()); // pure red
        dds[130..132].copy_from_slice(&0x001Fu16.to_le_bytes()); // pure blue
        let decoded = decode_dds(&dds).unwrap();
        assert_eq!(decoded.width, 4);
        assert_eq!(decoded.height, 4);
        assert_eq!(decoded.pixels[0], 0xFFFF_0000);

        // Real PW 1.4.2 animated `normal.ani` (12 frames) & `hand.cur`
        let cur_dir = std::path::Path::new(env!("CARGO_MANIFEST_DIR"))
            .join("../../../source/pw142/element/cursors");
        if cur_dir.join("normal.ani").exists() {
            let ani = decode_cur_or_ani(&std::fs::read(cur_dir.join("normal.ani")).unwrap()).unwrap();
            assert_eq!(ani.frames.len(), 12);
            assert_eq!((ani.frames[0].width, ani.frames[0].height), (32, 32));
            let hand = decode_cur_or_ani(&std::fs::read(cur_dir.join("hand.cur")).unwrap()).unwrap();
            assert_eq!(hand.frames.len(), 1);
            assert_eq!((hand.hotspot_x, hand.hotspot_y), (7, 2));
        }
    }

    #[test]
    fn test_dds_mipmap_pyramid_trilinear_and_anisotropic_filtering() {
        // 64x64 alternating black/white checkerboard (mean RGB = 127.5)
        let mut px = vec![0u32; 64 * 64];
        for y in 0..64usize {
            for x in 0..64usize {
                px[y * 64 + x] = if (x + y) % 2 == 0 {
                    0xFFFF_FFFF
                } else {
                    0xFF00_0000
                };
            }
        }
        let img = SurfaceImage::from_pixels_with_mips(64, 64, px);
        // 64 -> 32 -> 16 -> 8 -> 4 -> 2 -> 1 = 7 total levels (level 0 + 6 generated mips)
        assert_eq!(img.mip_count(), 7);
        assert_eq!(img.mips.len(), 6);
        assert_eq!((img.mips[0].0, img.mips[0].1), (32, 32));
        assert_eq!((img.mips[5].0, img.mips[5].1), (1, 1));

        // Trilinear at high LOD (`5.5`) converges cleanly to mid-gray (~127..128) with zero checkerboard aliasing
        let hi_lod = img.sample_uv_trilinear(0.37, 0.61, 5.5);
        let r = ((hi_lod >> 16) & 0xFF) as i32;
        assert!((r - 127).abs() <= 2, "expected ~127 gray at LOD 5.5, got {r}");

        // 4x Anisotropic along grazing X derivative (`du_dx = 0.25`, `dv_dy = 0.03125`) eliminates aliasing
        let aniso = img.sample_uv_anisotropic(0.25, 0.25, 0.25, 0.0, 0.0, 0.03125);
        let ar = ((aniso >> 16) & 0xFF) as i32;
        assert!((ar - 127).abs() <= 3, "expected smooth anisotropic filter ~127, got {ar}");

        // Clamped bilinear never bleeds left edge (`x=0` pure red) with right edge (`x=7` pure blue)
        let mut ramp = vec![0xFF00_00FFu32; 8 * 8];
        for y in 0..8usize {
            ramp[y * 8] = 0xFFFF_0000;
        }
        let rimg = SurfaceImage::from_pixels_with_mips(8, 8, ramp);
        let left_edge = rimg.sample_uv_bilinear_clamp(0.0, 0.5);
        assert_eq!(left_edge, 0xFFFF_0000, "clamped bilinear must not wrap u=0 with u=1");
    }

    #[test]
    fn test_real_surfaces_pck_dds_decode_all_formats() {
        // Decode real DDS payloads from the shipped `surfaces.pck` (DXT1/DXT3/DXT5 + mipmaps).
        let Some(elem) = pw_core::find_test_pw142_element(env!("CARGO_MANIFEST_DIR")) else {
            return;
        };
        let pck_path = elem.join("surfaces.pck");
        if !pck_path.is_file() {
            return;
        }
        let pck = pw_pck::PckArchive::open_path(pck_path).unwrap();
        let mut dds_entries = 0usize;
        let mut decoded = 0usize;
        let mut checked = 0usize;
        for entry in &pck.entries {
            let path = entry.path.to_ascii_lowercase();
            if !path.ends_with(".dds") {
                continue;
            }
            dds_entries += 1;
            // Sample every 37th entry to keep the test fast, but always include a few known icons.
            checked += 1;
            if checked % 37 != 0 && !path.contains("minimaps/a01/") && !path.contains("ingame/a01") {
                continue;
            }
            let bytes = pck.read_entry(entry).unwrap();
            let img = decode_surface_auto(&bytes)
                .unwrap_or_else(|e| panic!("DDS decode failed for {}: {e}", entry.path));
            assert!(img.width >= 4 && img.height >= 4, "bad dims for {}", entry.path);
            assert_eq!(img.pixels.len(), img.width as usize * img.height as usize);
            // Mip chain must be strictly decreasing and end at 1x1.
            let mut pw = img.width as usize;
            let mut ph = img.height as usize;
            for (mw, mh, _) in &img.mips {
                // DDS mip halving is floor (`max(1, prev/2)`), not ceil.
                assert_eq!((*mw as usize, *mh as usize), ((pw / 2).max(1), (ph / 2).max(1)), "mip step for {}", entry.path);
                pw = *mw as usize;
                ph = *mh as usize;
            }
            assert_eq!((pw, ph), (1, 1), "mip chain must end at 1x1 for {}", entry.path);
            decoded += 1;
        }
        assert!(dds_entries > 2000, "surfaces.pck should hold thousands of DDS, got {dds_entries}");
        assert!(decoded > 50, "expected to decode >50 sampled DDS, got {decoded}");
    }
}

