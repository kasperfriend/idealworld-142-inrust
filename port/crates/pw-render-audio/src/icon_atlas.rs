//! Perfect World 1.4.2 Icon Set (`surfaces/iconset/iconlist_*.{dds,txt}`), Dynamic Minimap Radar
//! (`surfaces/minimaps/<map>/*.dds`), and Midlands World/Regional Map Loader (`surfaces/ingame/world.dds`, `surfaces/maps/*.dds`).
//!
//! Grounded directly in `AUICustomize` / `CECGameUIMan::GetIcon` (`07_cecgameuiman.c`):
//! - Each `iconlist_*.txt` begins with 4 integer lines: `icon_w`, `icon_h`, `rows`, `cols`,
//!   followed by one `.dds` icon filename per cell (`row * cols + col`).
//! - `surfaces/minimaps/<map>/<rrcc>.dds` stores `256x256` DXT1 radar tiles (`2x2` for `a01`, `22x16` for `world`).

use std::collections::HashMap;

use pw_core::decode_gbk;
use pw_pck::VirtualFileSystem;

use crate::image_dds::{decode_surface_auto, SurfaceImage};

#[derive(Debug, Clone)]
pub struct IconAtlas {
    pub tex_id: usize,
    pub tex_w: u32,
    pub tex_h: u32,
    pub icon_w: u32,
    pub icon_h: u32,
    pub rows: u32,
    pub cols: u32,
    pub total_icons: usize,
    name_to_idx: HashMap<String, usize>,
}

impl IconAtlas {
    pub fn load_from_vfs(
        vfs: &VirtualFileSystem,
        base_name: &str,
        textures: &mut Vec<SurfaceImage>,
    ) -> Option<Self> {
        let txt_bytes = vfs
            .read_ui_surface(&format!("iconset/{base_name}.txt"))
            .or_else(|| vfs.read_file(&format!("surfaces/iconset/{base_name}.txt")).ok())?;
        let dds_bytes = vfs
            .read_ui_surface(&format!("iconset/{base_name}.dds"))
            .or_else(|| vfs.read_file(&format!("surfaces/iconset/{base_name}.dds")).ok())?;

        let img = decode_surface_auto(&dds_bytes).ok()?;
        let txt = decode_gbk(&txt_bytes);
        let mut lines = txt.lines().map(str::trim).filter(|s| !s.is_empty());

        let icon_w: u32 = lines.next()?.parse().ok()?;
        let icon_h: u32 = lines.next()?.parse().ok()?;
        let rows: u32 = lines.next()?.parse().ok()?;
        let cols: u32 = lines.next()?.parse().ok()?;
        if rows == 0 || cols == 0 {
            return None;
        }

        let mut name_to_idx = HashMap::new();
        let mut count = 0usize;
        for (idx, line) in lines.enumerate() {
            let key = normalize_icon_key(line);
            if !key.is_empty() {
                name_to_idx.entry(key).or_insert(idx);
            }
            count = idx + 1;
        }

        let tex_w = img.width.max(1);
        let tex_h = img.height.max(1);
        let tex_id = textures.len();
        textures.push(img);

        Some(Self {
            tex_id,
            tex_w,
            tex_h,
            icon_w,
            icon_h,
            rows,
            cols,
            total_icons: count,
            name_to_idx,
        })
    }

    /// Returns exact pixel-aligned `(u0, v0, u1, v1)` inside `self.tex_id` (`tex_w x tex_h`) for icon index `idx`.
    pub fn uv_for_index(&self, idx: usize) -> (f32, f32, f32, f32) {
        let actual_cols = (self.tex_w / self.icon_w.max(1)).max(1);
        let actual_rows = (self.tex_h / self.icon_h.max(1)).max(1);
        let max_slots = (actual_rows * actual_cols).min(self.rows * self.cols).max(1) as usize;
        let i = idx % max_slots;
        let r = (i as u32) / self.cols;
        let c = (i as u32) % self.cols;
        let u0 = ((c * self.icon_w) as f32 + 0.5) / (self.tex_w as f32);
        let u1 = (((c + 1) * self.icon_w) as f32 - 0.5) / (self.tex_w as f32);
        let v0 = ((r * self.icon_h) as f32 + 0.5) / (self.tex_h as f32);
        let v1 = (((r + 1) * self.icon_h) as f32 - 0.5) / (self.tex_h as f32);
        (u0, v0, u1, v1)
    }

    /// Resolves an icon filename (e.g. `"一闪.dds"` or `"Surfaces\\图标\\武器\\单手剑\\*.dds"`) to `(u0, v0, u1, v1)`.
    pub fn uv_for_name(&self, raw_name: &str, fallback_seed: usize) -> (f32, f32, f32, f32) {
        let key = normalize_icon_key(raw_name);
        if let Some(&idx) = self.name_to_idx.get(&key) {
            return self.uv_for_index(idx);
        }
        // Fallback to a valid non-zero icon slot (`1 + seed`) so no slot ever renders `unknown.dds` (`idx=0`)
        let valid = self.total_icons.saturating_sub(1).max(1);
        self.uv_for_index(1 + (fallback_seed % valid))
    }
}

fn normalize_icon_key(raw: &str) -> String {
    let s = raw.trim().replace('\\', "/");
    let leaf = s.rsplit('/').next().unwrap_or(&s);
    leaf.to_ascii_lowercase()
}

/// Stitches `surfaces/minimaps/<map>/<rrcc>.dds` (`2x2`, active `4x4` `2048m` window for `world`, or single `map.dds`)
/// into a single `SurfaceImage` texture for `CDlgMiniMap` (`Win_Map`) and returns `(tex_id, (min_x, max_x, min_z, max_z))`.
pub fn load_minimap_composite_at(
    vfs: &VirtualFileSystem,
    map_name: &str,
    center_x: f32,
    center_z: f32,
    textures: &mut Vec<SurfaceImage>,
) -> Option<(usize, (f32, f32, f32, f32))> {
    let m = map_name.to_ascii_lowercase();

    // Multi-subterrain main world (`world`: `22` rows x `16` cols of `512m x 512m` tiles, `0000.dds..2115.dds`)
    if m == "world" {
        let cc0 = (((center_x + 4096.0) / 512.0).floor() as i32 - 1).clamp(0, 12) as usize;
        let rr0 = (((5632.0 - center_z) / 512.0).floor() as i32 - 1).clamp(0, 18) as usize;
        let mut grid_4x4: Vec<Option<SurfaceImage>> = Vec::with_capacity(16);
        let mut any_tile = false;
        for dr in 0..4usize {
            for dc in 0..4usize {
                let rr = rr0 + dr;
                let cc = cc0 + dc;
                let rel = format!("minimaps/world/{rr:02}{cc:02}.dds");
                let tile = vfs
                    .read_ui_surface(&rel)
                    .or_else(|| vfs.read_file(&format!("surfaces/{rel}")).ok())
                    .and_then(|b| decode_surface_auto(&b).ok());
                if tile.is_some() {
                    any_tile = true;
                }
                grid_4x4.push(tile);
            }
        }
        if any_tile {
            let tw = grid_4x4.iter().flatten().next().map(|t| t.width).unwrap_or(256);
            let th = grid_4x4.iter().flatten().next().map(|t| t.height).unwrap_or(256);
            let full_w = tw * 4;
            let full_h = th * 4;
            let mut pixels = vec![0xFF14_1C24u32; (full_w * full_h) as usize];
            for dr in 0..4usize {
                for dc in 0..4usize {
                    if let Some(tile) = &grid_4x4[dr * 4 + dc] {
                        let copy_w = tile.width.min(tw);
                        let copy_h = tile.height.min(th);
                        for py in 0..copy_h {
                            let dst_off =
                                (((dr as u32) * th + py) * full_w + (dc as u32) * tw) as usize;
                            let src_off = (py * tile.width) as usize;
                            pixels[dst_off..dst_off + copy_w as usize]
                                .copy_from_slice(&tile.pixels[src_off..src_off + copy_w as usize]);
                        }
                    }
                }
            }
            let tid = textures.len();
            textures.push(SurfaceImage::from_pixels_with_mips(full_w, full_h, pixels));
            let min_x = -4096.0 + (cc0 as f32) * 512.0;
            let max_x = min_x + 2048.0;
            let max_z = 5632.0 - (rr0 as f32) * 512.0;
            let min_z = max_z - 2048.0;
            return Some((tid, (min_x, max_x, min_z, max_z)));
        }
    }

    // Check `2x2` `0000..0101` tile layout (`a01`, `a02`, etc.)
    let mut grid_2x2: Vec<Option<SurfaceImage>> = Vec::with_capacity(4);
    let mut any_tile = false;
    for r in 0..2 {
        for c in 0..2 {
            let rel = format!("minimaps/{m}/{r:02}{c:02}.dds");
            let tile = vfs
                .read_ui_surface(&rel)
                .or_else(|| vfs.read_file(&format!("surfaces/{rel}")).ok())
                .and_then(|b| decode_surface_auto(&b).ok());
            if tile.is_some() {
                any_tile = true;
            }
            grid_2x2.push(tile);
        }
    }

    if any_tile {
        let tw = grid_2x2
            .iter()
            .flatten()
            .next()
            .map(|t| t.width)
            .unwrap_or(256);
        let th = grid_2x2
            .iter()
            .flatten()
            .next()
            .map(|t| t.height)
            .unwrap_or(256);
        let full_w = tw * 2;
        let full_h = th * 2;
        let mut pixels = vec![0xFF14_1C24u32; (full_w * full_h) as usize];
        for r in 0..2usize {
            for c in 0..2usize {
                if let Some(tile) = &grid_2x2[r * 2 + c] {
                    let copy_w = tile.width.min(tw);
                    let copy_h = tile.height.min(th);
                    for py in 0..copy_h {
                        let dst_off = (((r as u32) * th + py) * full_w + (c as u32) * tw) as usize;
                        let src_off = (py * tile.width) as usize;
                        pixels[dst_off..dst_off + copy_w as usize]
                            .copy_from_slice(&tile.pixels[src_off..src_off + copy_w as usize]);
                    }
                }
            }
        }
        let tid = textures.len();
        textures.push(SurfaceImage::from_pixels_with_mips(full_w, full_h, pixels));
        return Some((tid, (-512.0, 512.0, -512.0, 512.0)));
    }

    // Fallback: single minimap DDS (`minimaps/<map>.dds` or `ingame/<map>.dds`)
    for cand in [format!("minimaps/{m}.dds"), format!("ingame/<map>.dds")] {
        if let Some(bytes) = vfs.read_ui_surface(&cand) {
            if let Ok(img) = decode_surface_auto(&bytes) {
                let tid = textures.len();
                textures.push(img);
                return Some((tid, (-512.0, 512.0, -512.0, 512.0)));
            }
        }
    }
    None
}

pub fn load_minimap_composite(
    vfs: &VirtualFileSystem,
    map_name: &str,
    textures: &mut Vec<SurfaceImage>,
) -> Option<usize> {
    load_minimap_composite_at(vfs, map_name, 0.0, 0.0, textures).map(|(tid, _)| tid)
}

/// Loads `surfaces/ingame/world.dds` (`1024x1024`, active `4:3` viewport `y in 128..896` covering `8192m x 11264m`).
pub fn load_world_map_texture(
    vfs: &VirtualFileSystem,
    textures: &mut Vec<SurfaceImage>,
) -> Option<usize> {
    let bytes = vfs
        .read_ui_surface("ingame/world.dds")
        .or_else(|| vfs.read_file("surfaces/ingame/world.dds").ok())?;
    let img = decode_surface_auto(&bytes).ok()?;
    let tid = textures.len();
    textures.push(img);
    Some(tid)
}

/// Loads regional sub-terrain map `surfaces/maps/{sub_row:02}{sub_col:01}.dds` (`000.dds..107.dds`, `512x512` per `1024m` tile).
pub fn load_regional_map_texture(
    vfs: &VirtualFileSystem,
    sub_row: usize,
    sub_col: usize,
    textures: &mut Vec<SurfaceImage>,
) -> Option<usize> {
    let rel = format!("maps/{sub_row:02}{sub_col:01}.dds");
    let bytes = vfs
        .read_ui_surface(&rel)
        .or_else(|| vfs.read_file(&format!("surfaces/{rel}")).ok())?;
    let img = decode_surface_auto(&bytes).ok()?;
    let tid = textures.len();
    textures.push(img);
    Some(tid)
}
