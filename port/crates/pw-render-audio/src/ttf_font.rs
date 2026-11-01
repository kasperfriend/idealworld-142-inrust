//! Zero-dependency TrueType (`.ttf` SFNT) outline font parser, anti-aliased scanline rasterizer,
//! and shelf-packed GPU/CPU texture atlas for Perfect World 1.4.2 (`fonts/fzl2jw.ttf`, `fonts/fzxh1jw.ttf`).
//!
//! Supports:
//! - SFNT tables: `head`, `hhea`, `maxp`, `hmtx`, `loca` (short & long), `glyf` (simple & composite), `cmap` (Format 4 BMP Unicode)
//! - Full GB2312/GBK CJK Unified Ideographs (`8,106` glyphs in `fzl2jw.ttf`), ASCII, punctuation, arrows (`↑↓`), and symbols
//! - Quadratic Bézier flattening + `4x` supersampled non-zero winding scanline AA rasterization
//! - Perfect World `^RRGGBB` inline AUI rich-text color tags (`AUITextArea` / `AUILabel`)
//! - Shared `SurfaceImage` shelf atlas (`1024x1024`) consumed identically by BOTH Windows `D3d9Renderer` (`d3d9.dll`)
//!   and the CPU reference rasterizer (`draw_ui_quad_cpu`).

use std::collections::HashMap;

use crate::a3d_scene_renderer::UiQuad2D;
use crate::image_dds::SurfaceImage;

#[derive(Clone, Copy, Debug)]
struct TtfPoint {
    x: f32,
    y: f32,
    on_curve: bool,
}

#[derive(Clone, Debug)]
pub struct TrueTypeFont {
    data: Vec<u8>,
    pub units_per_em: u16,
    pub ascent: i16,
    pub descent: i16,
    index_to_loc_format: i16,
    num_glyphs: u16,
    num_h_metrics: u16,
    hmtx_off: usize,
    loca_off: usize,
    glyf_off: usize,
    glyf_end: usize,
    cmap_fmt4_off: usize,
}

#[inline]
fn rd_u16_be(b: &[u8], off: usize) -> u16 {
    if off + 2 <= b.len() {
        u16::from_be_bytes([b[off], b[off + 1]])
    } else {
        0
    }
}

#[inline]
fn rd_i16_be(b: &[u8], off: usize) -> i16 {
    rd_u16_be(b, off) as i16
}

#[inline]
fn rd_u32_be(b: &[u8], off: usize) -> u32 {
    if off + 4 <= b.len() {
        u32::from_be_bytes([b[off], b[off + 1], b[off + 2], b[off + 3]])
    } else {
        0
    }
}

impl TrueTypeFont {
    pub fn parse(data: Vec<u8>) -> Option<Self> {
        if data.len() < 12 {
            return None;
        }
        let num_tables = rd_u16_be(&data, 4) as usize;
        if 12 + num_tables * 16 > data.len() {
            return None;
        }
        let mut head = None;
        let mut hhea = None;
        let mut maxp = None;
        let mut hmtx = None;
        let mut loca = None;
        let mut glyf = None;
        let mut cmap = None;

        for i in 0..num_tables {
            let rec = 12 + i * 16;
            let tag = &data[rec..rec + 4];
            let off = rd_u32_be(&data, rec + 8) as usize;
            let len = rd_u32_be(&data, rec + 12) as usize;
            if off.saturating_add(len) > data.len() {
                continue;
            }
            match tag {
                b"head" => head = Some((off, len)),
                b"hhea" => hhea = Some((off, len)),
                b"maxp" => maxp = Some((off, len)),
                b"hmtx" => hmtx = Some((off, len)),
                b"loca" => loca = Some((off, len)),
                b"glyf" => glyf = Some((off, len)),
                b"cmap" => cmap = Some((off, len)),
                _ => {}
            }
        }

        let (head_off, _) = head?;
        let (hhea_off, _) = hhea?;
        let (maxp_off, _) = maxp?;
        let (hmtx_off, _) = hmtx?;
        let (loca_off, _) = loca?;
        let (glyf_off, glyf_len) = glyf?;
        let (cmap_off, _) = cmap?;

        let units_per_em = rd_u16_be(&data, head_off + 18).max(16);
        let index_to_loc_format = rd_i16_be(&data, head_off + 50);
        let ascent = rd_i16_be(&data, hhea_off + 4);
        let descent = rd_i16_be(&data, hhea_off + 6);
        let num_h_metrics = rd_u16_be(&data, hhea_off + 34).max(1);
        let num_glyphs = rd_u16_be(&data, maxp_off + 4).max(1);

        // Locate Format 4 Unicode BMP subtable inside `cmap`
        let n_sub = rd_u16_be(&data, cmap_off + 2) as usize;
        let mut cmap_fmt4_off = 0usize;
        for i in 0..n_sub {
            let sub_rec = cmap_off + 4 + i * 8;
            let pid = rd_u16_be(&data, sub_rec);
            let eid = rd_u16_be(&data, sub_rec + 2);
            let rel = rd_u32_be(&data, sub_rec + 4) as usize;
            let abs = cmap_off.saturating_add(rel);
            if abs + 14 <= data.len() && rd_u16_be(&data, abs) == 4 {
                if (pid == 3 && (eid == 1 || eid == 10)) || pid == 0 {
                    cmap_fmt4_off = abs;
                    break;
                }
                if cmap_fmt4_off == 0 {
                    cmap_fmt4_off = abs;
                }
            }
        }
        if cmap_fmt4_off == 0 {
            return None;
        }

        Some(Self {
            data,
            units_per_em,
            ascent,
            descent,
            index_to_loc_format,
            num_glyphs,
            num_h_metrics,
            hmtx_off,
            loca_off,
            glyf_off,
            glyf_end: glyf_off + glyf_len,
            cmap_fmt4_off,
        })
    }

    pub fn glyph_index(&self, ch: char) -> u16 {
        let code = ch as u32;
        if code > 0xFFFF {
            return 0;
        }
        let c = code as u16;
        let base = self.cmap_fmt4_off;
        let seg_count = (rd_u16_be(&self.data, base + 6) / 2) as usize;
        let end_codes = base + 14;
        let start_codes = end_codes + seg_count * 2 + 2;
        let id_deltas = start_codes + seg_count * 2;
        let id_range_offs = id_deltas + seg_count * 2;
        if id_range_offs + seg_count * 2 > self.data.len() {
            return 0;
        }

        // Binary search `endCode[i] >= c`
        let mut lo = 0usize;
        let mut hi = seg_count;
        while lo < hi {
            let mid = (lo + hi) / 2;
            if rd_u16_be(&self.data, end_codes + mid * 2) < c {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        if lo >= seg_count {
            return 0;
        }
        let start = rd_u16_be(&self.data, start_codes + lo * 2);
        if c < start {
            return 0;
        }
        let delta = rd_i16_be(&self.data, id_deltas + lo * 2) as i32;
        let ro_pos = id_range_offs + lo * 2;
        let ro = rd_u16_be(&self.data, ro_pos) as usize;
        if ro == 0 {
            ((c as i32 + delta) as u16) % self.num_glyphs
        } else {
            let glyph_addr = ro_pos + ro + ((c - start) as usize) * 2;
            let gid = rd_u16_be(&self.data, glyph_addr);
            if gid == 0 {
                0
            } else {
                ((gid as i32 + delta) as u16) % self.num_glyphs
            }
        }
    }

    pub fn advance_and_lsb(&self, gid: u16) -> (u16, i16) {
        let idx = gid.min(self.num_glyphs.saturating_sub(1)) as usize;
        let nhm = self.num_h_metrics as usize;
        if idx < nhm {
            let off = self.hmtx_off + idx * 4;
            (rd_u16_be(&self.data, off), rd_i16_be(&self.data, off + 2))
        } else {
            let adv = rd_u16_be(&self.data, self.hmtx_off + (nhm - 1) * 4);
            let lsb_off = self.hmtx_off + nhm * 4 + (idx - nhm) * 2;
            (adv, rd_i16_be(&self.data, lsb_off))
        }
    }

    fn glyph_data_range(&self, gid: u16) -> Option<(usize, usize)> {
        if gid >= self.num_glyphs {
            return None;
        }
        let i = gid as usize;
        let (o0, o1) = if self.index_to_loc_format == 0 {
            (
                (rd_u16_be(&self.data, self.loca_off + i * 2) as usize) * 2,
                (rd_u16_be(&self.data, self.loca_off + (i + 1) * 2) as usize) * 2,
            )
        } else {
            (
                rd_u32_be(&self.data, self.loca_off + i * 4) as usize,
                rd_u32_be(&self.data, self.loca_off + (i + 1) * 4) as usize,
            )
        };
        if o1 <= o0 {
            return None;
        }
        let s = self.glyf_off + o0;
        let e = (self.glyf_off + o1).min(self.glyf_end);
        if s + 10 <= e && e <= self.data.len() {
            Some((s, e))
        } else {
            None
        }
    }

    fn collect_contours(&self, gid: u16, xform: [f32; 6], depth: u8, out: &mut Vec<Vec<TtfPoint>>) {
        if depth > 6 {
            return;
        }
        let Some((s, e)) = self.glyph_data_range(gid) else {
            return;
        };
        let n_contours = rd_i16_be(&self.data, s);
        if n_contours >= 0 {
            let nc = n_contours as usize;
            if nc == 0 || s + 10 + nc * 2 + 2 > e {
                return;
            }
            let mut end_pts = Vec::with_capacity(nc);
            for c in 0..nc {
                end_pts.push(rd_u16_be(&self.data, s + 10 + c * 2) as usize);
            }
            let n_pts = end_pts[nc - 1] + 1;
            let ins_len = rd_u16_be(&self.data, s + 10 + nc * 2) as usize;
            let mut p = s + 10 + nc * 2 + 2 + ins_len;
            if p >= e {
                return;
            }

            let mut flags = Vec::with_capacity(n_pts);
            while flags.len() < n_pts && p < e {
                let fl = self.data[p];
                p += 1;
                flags.push(fl);
                if (fl & 0x08) != 0 && p < e {
                    let rep = self.data[p] as usize;
                    p += 1;
                    for _ in 0..rep {
                        if flags.len() < n_pts {
                            flags.push(fl);
                        }
                    }
                }
            }
            if flags.len() < n_pts {
                return;
            }

            let mut xs = Vec::with_capacity(n_pts);
            let mut cur_x = 0i32;
            for &fl in &flags {
                if (fl & 0x02) != 0 {
                    if p >= e {
                        return;
                    }
                    let d = self.data[p] as i32;
                    p += 1;
                    cur_x += if (fl & 0x10) != 0 { d } else { -d };
                } else if (fl & 0x10) == 0 {
                    if p + 2 > e {
                        return;
                    }
                    cur_x += rd_i16_be(&self.data, p) as i32;
                    p += 2;
                }
                xs.push(cur_x as f32);
            }

            let mut ys = Vec::with_capacity(n_pts);
            let mut cur_y = 0i32;
            for &fl in &flags {
                if (fl & 0x04) != 0 {
                    if p >= e {
                        return;
                    }
                    let d = self.data[p] as i32;
                    p += 1;
                    cur_y += if (fl & 0x20) != 0 { d } else { -d };
                } else if (fl & 0x20) == 0 {
                    if p + 2 > e {
                        return;
                    }
                    cur_y += rd_i16_be(&self.data, p) as i32;
                    p += 2;
                }
                ys.push(cur_y as f32);
            }

            let mut start_pt = 0usize;
            for &end_pt in &end_pts {
                if end_pt >= start_pt && end_pt < n_pts {
                    let mut contour = Vec::with_capacity(end_pt - start_pt + 1);
                    for i in start_pt..=end_pt {
                        let gx = xs[i];
                        let gy = ys[i];
                        let tx = xform[0] * gx + xform[2] * gy + xform[4];
                        let ty = xform[1] * gx + xform[3] * gy + xform[5];
                        contour.push(TtfPoint {
                            x: tx,
                            y: ty,
                            on_curve: (flags[i] & 0x01) != 0,
                        });
                    }
                    if contour.len() >= 2 {
                        out.push(contour);
                    }
                }
                start_pt = end_pt + 1;
            }
        } else {
            // Composite glyph (`numberOfContours < 0`)
            let mut p = s + 10;
            while p + 4 <= e {
                let comp_flags = rd_u16_be(&self.data, p);
                let sub_gid = rd_u16_be(&self.data, p + 2);
                p += 4;

                let (dx, dy) = if (comp_flags & 0x0001) != 0 {
                    let a1 = rd_i16_be(&self.data, p);
                    let a2 = rd_i16_be(&self.data, p + 2);
                    p += 4;
                    if (comp_flags & 0x0002) != 0 {
                        (a1 as f32, a2 as f32)
                    } else {
                        (0.0, 0.0)
                    }
                } else {
                    if p + 2 > e {
                        break;
                    }
                    let a1 = self.data[p] as i8;
                    let a2 = self.data[p + 1] as i8;
                    p += 2;
                    if (comp_flags & 0x0002) != 0 {
                        (a1 as f32, a2 as f32)
                    } else {
                        (0.0, 0.0)
                    }
                };

                let (mut m00, mut m01, mut m10, mut m11) = (1.0f32, 0.0f32, 0.0f32, 1.0f32);
                if (comp_flags & 0x0008) != 0 {
                    let sc = (rd_i16_be(&self.data, p) as f32) / 16384.0;
                    p += 2;
                    m00 = sc;
                    m11 = sc;
                } else if (comp_flags & 0x0040) != 0 {
                    m00 = (rd_i16_be(&self.data, p) as f32) / 16384.0;
                    m11 = (rd_i16_be(&self.data, p + 2) as f32) / 16384.0;
                    p += 4;
                } else if (comp_flags & 0x0080) != 0 {
                    m00 = (rd_i16_be(&self.data, p) as f32) / 16384.0;
                    m01 = (rd_i16_be(&self.data, p + 2) as f32) / 16384.0;
                    m10 = (rd_i16_be(&self.data, p + 4) as f32) / 16384.0;
                    m11 = (rd_i16_be(&self.data, p + 6) as f32) / 16384.0;
                    p += 8;
                }

                // Compose child transform with parent `xform`
                let child_xf = [
                    xform[0] * m00 + xform[2] * m01,
                    xform[1] * m00 + xform[3] * m01,
                    xform[0] * m10 + xform[2] * m11,
                    xform[1] * m10 + xform[3] * m11,
                    xform[0] * dx + xform[2] * dy + xform[4],
                    xform[1] * dx + xform[3] * dy + xform[5],
                ];
                self.collect_contours(sub_gid, child_xf, depth + 1, out);

                if (comp_flags & 0x0020) == 0 {
                    break;
                }
            }
        }
    }

    pub fn rasterize_glyph(&self, ch: char, px_size: u16) -> RasterizedGlyph {
        let scale = (px_size.max(8) as f32) / (self.units_per_em as f32);
        let gid = self.glyph_index(ch);
        let (adv_fu, _lsb) = self.advance_and_lsb(gid);
        let advance_px = ((adv_fu as f32) * scale).round().max(4.0) as i32;
        let baseline_y = ((self.ascent as f32) * scale).ceil();

        if ch.is_whitespace() || gid == 0 {
            return RasterizedGlyph {
                width: 0,
                height: 0,
                bearing_x: 0,
                bearing_y: 0,
                advance_px: if ch == ' ' {
                    ((px_size as i32) / 2).max(4)
                } else {
                    advance_px
                },
                alpha: Vec::new(),
            };
        }

        let mut contours = Vec::new();
        self.collect_contours(gid, [1.0, 0.0, 0.0, 1.0, 0.0, 0.0], 0, &mut contours);
        if contours.is_empty() {
            return RasterizedGlyph {
                width: 0,
                height: 0,
                bearing_x: 0,
                bearing_y: 0,
                advance_px,
                alpha: Vec::new(),
            };
        }

        // Flatten quadratic Bézier contours into screen-space segments (`y_down = baseline_y - y_font * scale`)
        let mut edges: Vec<(f32, f32, f32, f32)> = Vec::new();
        let mut min_x = f32::INFINITY;
        let mut max_x = f32::NEG_INFINITY;
        let mut min_y = f32::INFINITY;
        let mut max_y = f32::NEG_INFINITY;

        for raw in &contours {
            let n = raw.len();
            // Expand implied on-curve midpoints between consecutive off-curve points
            let mut pts: Vec<(f32, f32, bool)> = Vec::with_capacity(n * 2);
            for i in 0..n {
                let cur = raw[i];
                let nxt = raw[(i + 1) % n];
                let cx = cur.x * scale;
                let cy = baseline_y - cur.y * scale;
                pts.push((cx, cy, cur.on_curve));
                if !cur.on_curve && !nxt.on_curve {
                    let mx = (cur.x + nxt.x) * 0.5 * scale;
                    let my = baseline_y - (cur.y + nxt.y) * 0.5 * scale;
                    pts.push((mx, my, true));
                }
            }
            if pts.len() < 2 {
                continue;
            }
            // Find first on-curve point (or synthesize midpoint if all off-curve)
            let first_on = pts.iter().position(|p| p.2).unwrap_or(0);
            let m = pts.len();
            let mut poly: Vec<(f32, f32)> = Vec::with_capacity(m * 4);
            let mut idx = 0usize;
            while idx < m {
                let p0 = pts[(first_on + idx) % m];
                let p1 = pts[(first_on + idx + 1) % m];
                if p1.2 {
                    poly.push((p0.0, p0.1));
                    idx += 1;
                } else {
                    let p2 = pts[(first_on + idx + 2) % m];
                    poly.push((p0.0, p0.1));
                    let steps = 6usize;
                    for s in 1..steps {
                        let t = (s as f32) / (steps as f32);
                        let it = 1.0 - t;
                        let qx = it * it * p0.0 + 2.0 * it * t * p1.0 + t * t * p2.0;
                        let qy = it * it * p0.1 + 2.0 * it * t * p1.1 + t * t * p2.1;
                        poly.push((qx, qy));
                    }
                    idx += 2;
                }
            }
            let pn = poly.len();
            for i in 0..pn {
                let (x0, y0) = poly[i];
                let (x1, y1) = poly[(i + 1) % pn];
                min_x = min_x.min(x0);
                max_x = max_x.max(x0);
                min_y = min_y.min(y0);
                max_y = max_y.max(y0);
                if (y1 - y0).abs() > 1e-5 {
                    edges.push((x0, y0, x1, y1));
                }
            }
        }

        if !min_x.is_finite() || edges.is_empty() {
            return RasterizedGlyph {
                width: 0,
                height: 0,
                bearing_x: 0,
                bearing_y: 0,
                advance_px,
                alpha: Vec::new(),
            };
        }

        let ix0 = min_x.floor() as i32;
        let iy0 = min_y.floor() as i32;
        let ix1 = max_x.ceil() as i32;
        let iy1 = max_y.ceil() as i32;
        let w = (ix1 - ix0).clamp(1, 96) as u32;
        let h = (iy1 - iy0).clamp(1, 96) as u32;
        let mut cov = vec![0.0f32; (w * h) as usize];
        let mut xings = Vec::with_capacity(32);

        // 4x vertical x 4x horizontal subpixel non-zero winding scanline rasterizer
        const SUB_Y: [f32; 4] = [0.125, 0.375, 0.625, 0.875];
        for py in 0..h {
            let row = (py * w) as usize;
            for &sy_off in &SUB_Y {
                let scan_y = (iy0 + py as i32) as f32 + sy_off;
                xings.clear();
                for &(x0, y0, x1, y1) in &edges {
                    let (ymin, ymax, dir) = if y0 < y1 {
                        (y0, y1, 1i32)
                    } else {
                        (y1, y0, -1i32)
                    };
                    if scan_y >= ymin && scan_y < ymax {
                        let t = (scan_y - y0) / (y1 - y0);
                        let x_int = x0 + t * (x1 - x0) - (ix0 as f32);
                        xings.push((x_int, dir));
                    }
                }
                if xings.len() < 2 {
                    continue;
                }
                xings.sort_by(|a, b| a.0.partial_cmp(&b.0).unwrap_or(core::cmp::Ordering::Equal));

                let mut winding = 0i32;
                let mut span_start = 0.0f32;
                for &(x_pos, dir) in &xings {
                    let prev = winding;
                    winding += dir;
                    if prev == 0 && winding != 0 {
                        span_start = x_pos;
                    } else if prev != 0 && winding == 0 {
                        let a = span_start.max(0.0);
                        let b = x_pos.min(w as f32);
                        if b > a {
                            let px_a = (a.floor() as u32).min(w - 1);
                            let px_b = ((b.ceil() as u32).saturating_sub(1)).min(w - 1);
                            for px in px_a..=px_b {
                                let left = (px as f32).max(a);
                                let right = ((px + 1) as f32).min(b);
                                if right > left {
                                    cov[row + px as usize] += (right - left) * 0.25;
                                }
                            }
                        }
                    }
                }
            }
        }

        let alpha = cov
            .into_iter()
            .map(|c| {
                // Slight gamma boost (`powf(0.82)`) so thin 12px CJK strokes look crisp and readable on dark UI panels
                let boosted = c.clamp(0.0, 1.0).powf(0.82);
                (boosted * 255.0).round() as u8
            })
            .collect();

        RasterizedGlyph {
            width: w,
            height: h,
            bearing_x: ix0,
            bearing_y: iy0,
            advance_px,
            alpha,
        }
    }
}

pub struct RasterizedGlyph {
    pub width: u32,
    pub height: u32,
    pub bearing_x: i32,
    pub bearing_y: i32,
    pub advance_px: i32,
    pub alpha: Vec<u8>,
}

#[derive(Clone, Copy, Debug)]
pub struct CachedGlyph {
    pub u0: f32,
    pub v0: f32,
    pub u1: f32,
    pub v1: f32,
    pub width: i32,
    pub height: i32,
    pub bearing_x: i32,
    pub bearing_y: i32,
    pub advance_px: i32,
}

pub struct TtfFontAtlas {
    font: Option<TrueTypeFont>,
    pub atlas_tex_id: usize,
    atlas_size: u32,
    shelf_x: u32,
    shelf_y: u32,
    shelf_h: u32,
    cache: HashMap<(char, u16), CachedGlyph>,
    pub atlas_revision: u64,
}

impl TtfFontAtlas {
    pub fn new(ttf_bytes: Option<Vec<u8>>, textures: &mut Vec<SurfaceImage>) -> Self {
        let atlas_size = 1024u32;
        let atlas_tex_id = textures.len();
        textures.push(SurfaceImage::from_pixels(
            atlas_size,
            atlas_size,
            vec![0x00FF_FFFF; (atlas_size * atlas_size) as usize],
        ));
        let font = ttf_bytes.and_then(TrueTypeFont::parse);
        Self {
            font,
            atlas_tex_id,
            atlas_size,
            shelf_x: 2,
            shelf_y: 2,
            shelf_h: 0,
            cache: HashMap::new(),
            atlas_revision: 1,
        }
    }

    pub fn has_ttf(&self) -> bool {
        self.font.is_some()
    }

    fn ensure_glyph(
        &mut self,
        textures: &mut [SurfaceImage],
        ch: char,
        size_px: u16,
    ) -> CachedGlyph {
        let sz = size_px.clamp(9, 40);
        let mapped = match ch {
            '\u{2022}' | '\u{25B8}' | '\u{25AA}' | '\u{25CF}' => '\u{25C6}', // '◆' present in `fzl2jw.ttf`
            '\u{25CB}' => '\u{25C7}', // '◇' present in `fzl2jw.ttf`
            other => other,
        };
        if let Some(&cg) = self.cache.get(&(mapped, sz)) {
            return cg;
        }

        let rg = if let Some(f) = &self.font {
            if !mapped.is_whitespace() && f.glyph_index(mapped) == 0 {
                rasterize_fallback_glyph(mapped, sz)
            } else {
                let r = f.rasterize_glyph(mapped, sz);
                if r.width == 0 && !mapped.is_whitespace() {
                    rasterize_fallback_glyph(mapped, sz)
                } else {
                    r
                }
            }
        } else {
            rasterize_fallback_glyph(mapped, sz)
        };

        if rg.width == 0 || rg.height == 0 {
            let empty = CachedGlyph {
                u0: 0.0,
                v0: 0.0,
                u1: 0.0,
                v1: 0.0,
                width: 0,
                height: 0,
                bearing_x: 0,
                bearing_y: 0,
                advance_px: rg.advance_px,
            };
            self.cache.insert((mapped, sz), empty);
            return empty;
        }

        // Shelf pack with 1px gutter
        if self.shelf_x + rg.width + 2 >= self.atlas_size {
            self.shelf_x = 2;
            self.shelf_y += self.shelf_h + 2;
            self.shelf_h = 0;
        }
        if self.shelf_y + rg.height + 2 >= self.atlas_size {
            // Wrap atlas shelf cleanly if full after thousands of unique CJK glyphs
            self.shelf_x = 2;
            self.shelf_y = 2;
            self.shelf_h = 0;
            self.cache.clear();
        }

        let gx = self.shelf_x;
        let gy = self.shelf_y;
        self.shelf_x += rg.width + 2;
        self.shelf_h = self.shelf_h.max(rg.height);

        if let Some(atlas) = textures.get_mut(self.atlas_tex_id) {
            let stride = atlas.width as usize;
            for py in 0..rg.height {
                let dst_row = ((gy + py) as usize) * stride;
                let src_row = (py * rg.width) as usize;
                for px in 0..rg.width {
                    let a = rg.alpha[src_row + px as usize] as u32;
                    atlas.pixels[dst_row + (gx + px) as usize] = (a << 24) | 0x00FF_FFFF;
                }
            }
            self.atlas_revision = self.atlas_revision.wrapping_add(1);
        }

        let inv = 1.0 / (self.atlas_size as f32);
        let cg = CachedGlyph {
            u0: (gx as f32) * inv,
            v0: (gy as f32) * inv,
            u1: ((gx + rg.width) as f32) * inv,
            v1: ((gy + rg.height) as f32) * inv,
            width: rg.width as i32,
            height: rg.height as i32,
            bearing_x: rg.bearing_x,
            bearing_y: rg.bearing_y,
            advance_px: rg.advance_px,
        };
        self.cache.insert((mapped, sz), cg);
        cg
    }

    pub fn measure_text_px(
        &mut self,
        textures: &mut [SurfaceImage],
        text: &str,
        size_px: u32,
    ) -> i32 {
        let sz = size_px.clamp(9, 40) as u16;
        let mut x = 0i32;
        let chars: Vec<char> = text.chars().collect();
        let mut i = 0usize;
        while i < chars.len() {
            if chars[i] == '^' && i + 7 <= chars.len() && parse_hex6(&chars[i + 1..i + 7]).is_some()
            {
                i += 7;
                continue;
            }
            let cg = self.ensure_glyph(textures, chars[i], sz);
            x += cg.advance_px;
            i += 1;
        }
        x
    }

    #[allow(clippy::too_many_arguments)]
    pub fn emit_text_quads(
        &mut self,
        textures: &mut [SurfaceImage],
        quads: &mut Vec<UiQuad2D>,
        x: i32,
        y: i32,
        size_px: u32,
        color: u32,
        shadow: bool,
        text: &str,
    ) {
        self.emit_text_quads_clipped(textures, quads, x, y, size_px, color, shadow, text, None);
    }

    #[allow(clippy::too_many_arguments)]
    pub fn emit_text_quads_clipped(
        &mut self,
        textures: &mut [SurfaceImage],
        quads: &mut Vec<UiQuad2D>,
        x: i32,
        y: i32,
        size_px: u32,
        color: u32,
        shadow: bool,
        text: &str,
        clip_rect: Option<(i32, i32, i32, i32)>,
    ) {
        let sz = size_px.clamp(9, 40) as u16;
        let base_alpha = (color >> 24) & 0xFF;
        let alpha_bits = if base_alpha == 0 { 0xFF00_0000 } else { base_alpha << 24 };
        let mut cur_color = alpha_bits | (color & 0x00FF_FFFF);
        let shadow_col = ((alpha_bits >> 24).min(210) << 24) | 0x0008_080C;

        let chars: Vec<char> = text.chars().collect();
        let mut pen_x = x;
        let mut i = 0usize;
        while i < chars.len() {
            if chars[i] == '\n' {
                break;
            }
            // Perfect World `^RRGGBB` inline AUI color tag
            if chars[i] == '^' && i + 7 <= chars.len() {
                if let Some(rgb) = parse_hex6(&chars[i + 1..i + 7]) {
                    cur_color = alpha_bits | rgb;
                    i += 7;
                    continue;
                }
            }
            let cg = self.ensure_glyph(textures, chars[i], sz);
            if cg.width > 0 && cg.height > 0 {
                let gx = pen_x + cg.bearing_x;
                let gy = y + cg.bearing_y;
                if shadow {
                    quads.push(UiQuad2D {
                        x0: (gx + 1) as f32,
                        y0: (gy + 1) as f32,
                        x1: (gx + 1 + cg.width) as f32,
                        y1: (gy + 1 + cg.height) as f32,
                        u0: cg.u0,
                        v0: cg.v0,
                        u1: cg.u1,
                        v1: cg.v1,
                        color: shadow_col,
                        tex_id: Some(self.atlas_tex_id),
                        clip_rect,
                    });
                }
                quads.push(UiQuad2D {
                    x0: gx as f32,
                    y0: gy as f32,
                    x1: (gx + cg.width) as f32,
                    y1: (gy + cg.height) as f32,
                    u0: cg.u0,
                    v0: cg.v0,
                    u1: cg.u1,
                    v1: cg.v1,
                    color: cur_color,
                    tex_id: Some(self.atlas_tex_id),
                    clip_rect,
                });
            }
            pen_x += cg.advance_px;
            i += 1;
        }
    }

    /// Word- and CJK-wraps `text` to fit strictly inside `max_width_px` (`AUITextArea`, `0x007542a0`),
    /// carrying any active `^RRGGBB` inline color code onto continuation lines!
    pub fn wrap_text_lines(
        &mut self,
        textures: &mut [SurfaceImage],
        text: &str,
        size_px: u32,
        max_width_px: i32,
    ) -> Vec<String> {
        let sz = size_px.clamp(9, 40) as u16;
        let limit = max_width_px.max(24);
        let mut out_lines = Vec::new();
        let mut active_hex: Option<String> = None;

        for raw_para in text.replace("\\r", "\n").lines() {
            let chars: Vec<char> = raw_para.chars().collect();
            if chars.is_empty() {
                continue;
            }
            let mut cur_line = active_hex.clone().unwrap_or_default();
            let mut cur_w = 0i32;
            let mut last_space_byte_len: Option<(usize, i32, Option<String>)> = None;
            let mut i = 0usize;

            while i < chars.len() {
                if chars[i] == '^' && i + 7 <= chars.len() && parse_hex6(&chars[i + 1..i + 7]).is_some()
                {
                    let tag: String = chars[i..i + 7].iter().collect();
                    active_hex = Some(tag.clone());
                    cur_line.push_str(&tag);
                    i += 7;
                    continue;
                }
                let ch = chars[i];
                let adv = self.ensure_glyph(textures, ch, sz).advance_px;
                if cur_w > 0 && cur_w + adv > limit {
                    if let Some((sp_len, _, hex_at_sp)) = last_space_byte_len.take() {
                        let tail = cur_line[sp_len..].trim_start().to_string();
                        let head = cur_line[..sp_len].trim_end().to_string();
                        if !head.is_empty() {
                            out_lines.push(head);
                        }
                        cur_line = format!(
                            "{}{}",
                            hex_at_sp.unwrap_or_default(),
                            tail
                        );
                        cur_w = self.measure_text_px(textures, &cur_line, size_px);
                    } else {
                        out_lines.push(cur_line);
                        cur_line = active_hex.clone().unwrap_or_default();
                        cur_w = 0;
                    }
                }
                cur_line.push(ch);
                cur_w += adv;
                if ch == ' ' {
                    last_space_byte_len = Some((cur_line.len(), cur_w, active_hex.clone()));
                }
                i += 1;
            }
            if !cur_line.is_empty() && Some(cur_line.as_str()) != active_hex.as_deref() {
                out_lines.push(cur_line);
            }
        }
        out_lines
    }
}

fn parse_hex6(slice: &[char]) -> Option<u32> {
    if slice.len() != 6 {
        return None;
    }
    let mut v = 0u32;
    for &c in slice {
        let d = c.to_digit(16)?;
        v = (v << 4) | d;
    }
    Some(v)
}

fn rasterize_fallback_glyph(ch: char, sz: u16) -> RasterizedGlyph {
    let gw = ((sz as u32) * 3 / 5).max(6);
    let gh = (sz as u32).max(8);
    let mut alpha = vec![0u8; (gw * gh) as usize];
    // Simple clean box/arrow glyph for characters outside BMP `fzl2jw.ttf` (e.g. `↑` if missing)
    if ch == '↑' {
        let mid = gw / 2;
        for y in 1..gh - 1 {
            alpha[(y * gw + mid) as usize] = 240;
            if y < gh / 2 && mid >= y && mid + y < gw {
                alpha[(y * gw + (mid - y)) as usize] = 220;
                alpha[(y * gw + (mid + y)) as usize] = 220;
            }
        }
    } else if !ch.is_whitespace() {
        for x in 1..gw - 1 {
            alpha[(gw + x) as usize] = 190;
            alpha[((gh - 2) * gw + x) as usize] = 190;
        }
        for y in 1..gh - 1 {
            alpha[(y * gw + 1) as usize] = 190;
            alpha[(y * gw + gw - 2) as usize] = 190;
        }
    }
    RasterizedGlyph {
        width: if ch.is_whitespace() { 0 } else { gw },
        height: if ch.is_whitespace() { 0 } else { gh },
        bearing_x: 0,
        bearing_y: 1,
        advance_px: (gw as i32) + 1,
        alpha,
    }
}
