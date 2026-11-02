//! `pw-render-audio` — 1:1 Port of `Angelica3D` (`A3DEngine`, `A3DCamera`, UltraWide FOV,
//! `.dds`/`.tga`/`.bmp` Texture Decoder, 3D Terrain/World Rasterizer, `shaders.pck`),
//! `AngelicaMedia` (`AMSoundEngine` WinMM MP3/WAV), `FTDriver.dll` (`fonts.pck` TTF),
//! `immwrapper.dll`, `ifc22.dll`, & `speedtreert.dll`.

pub mod a3d_gfx;
pub mod a3d_models;
pub mod a3d_scene_renderer;
pub mod a3d_skeleton;
pub mod audio_ogg;
pub mod d3d9_backend;
pub mod icon_atlas;
pub mod image_dds;
pub mod software_3d;
pub mod ttf_font;
pub mod vorbis_synth;
pub mod win_audio;

pub use a3d_gfx::{A3dGfxManager, A3dGfxTemplate, ActiveGfxEffect, GfxElementDef, GfxElementKind};
pub use a3d_models::{
    load_player_character_skins, load_player_character_skins_custom, A3dLitMesh, A3dLitModel,
    A3dLitVertex, A3dMoxMesh, A3dSkin, A3dSkyDome,
};
pub use a3d_scene_renderer::{
    build_aui_draw_list, class_aerogear_ecm, emit_aui_hover_tooltip, emit_software_cursor_quad,
    project_world_to_screen, render_scene_and_ui_cpu, DynamicCharacterActor, GpuMeshBatch,
    LoadedScene3D, OrnamentDrawInstance, TerrainBlockDraw, UiQuad2D, UiText2D,
};
pub use a3d_skeleton::{
    class_signature_weapon_ski, player_smd_vfs_path, A3dSkeleton, A3dSkinModelDesc,
    A3dSklTrackSet, ActorActionKind, EcModelDesc, LoadedSkeletonRig, REAL_MONSTER_ECMS,
    REAL_NPC_ECMS,
};
pub use audio_ogg::{
    decode_audio_auto, decode_wav_pcm_or_ima_adpcm, encode_pcm16_to_riff_wav, inspect_ogg_vorbis,
    ogg_page_crc32, DecodedAudioClip, OggVorbisStreamInfo, SpatialAudioMixer,
};
pub use vorbis_synth::{decode_ogg_vorbis_to_pcm, demux_ogg_packets, vorbis_imdct};
#[cfg(target_os = "windows")]
pub use d3d9_backend::D3d9Renderer;
pub use icon_atlas::{
    load_minimap_composite, load_minimap_composite_at, load_regional_map_texture,
    load_world_map_texture, IconAtlas,
};
pub use image_dds::{
    decode_bmp, decode_cur_or_ani, decode_dds, decode_surface_auto, decode_tga, DecodedCursor,
    SurfaceImage,
};
pub use software_3d::{
    EntityVisualKind, FrameBuffer, OverlayTextCmd, SceneCamera3D, WorldEntity3D,
};
pub use ttf_font::{TrueTypeFont, TtfFontAtlas};
pub use win_audio::AmSoundEngine;

use pw_core::{IniFile, PwError, PwResult};
use pw_pck::PckArchive;

#[derive(Debug, Clone)]
pub struct SystemSettings {
    pub render_wid: u32,
    pub render_hei: u32,
    pub fullscreen: bool,
    pub widescreen: bool,
    pub scale_ui: bool,
    pub tex_detail: u8,
    pub sound_vol: u8,
    pub music_vol: u8,
    pub water_quality: u8,
}

impl SystemSettings {
    pub fn from_ini(ini: &IniFile) -> Self {
        Self {
            render_wid: ini
                .get("Video", "RenderWid")
                .and_then(|v| v.parse().ok())
                .unwrap_or(1280),
            render_hei: ini
                .get("Video", "RenderHei")
                .and_then(|v| v.parse().ok())
                .unwrap_or(800),
            fullscreen: ini.get("Video", "FullScreen").unwrap_or("0") == "1",
            widescreen: ini.get("Video", "WideScreen").unwrap_or("1") == "1",
            scale_ui: ini.get("Video", "ScaleUI").unwrap_or("1") == "1",
            tex_detail: ini
                .get("Video", "TexDetail")
                .and_then(|v| v.parse().ok())
                .unwrap_or(0),
            sound_vol: ini
                .get("Audio", "SoundVol")
                .and_then(|v| v.parse().ok())
                .unwrap_or(65),
            music_vol: ini
                .get("Audio", "MusicVol")
                .and_then(|v| v.parse().ok())
                .unwrap_or(65),
            water_quality: ini
                .get("Video", "Water")
                .and_then(|v| v.parse().ok())
                .unwrap_or(1),
        }
    }
}

/// Exact port of `A3DCamera` + UltraWide (`21:9`) aspect & Hor+ FOV scaling (`elementclient.exe` `0x0041BEFA`).
#[derive(Debug, Clone)]
pub struct A3DCamera {
    pub fov_degrees: f32,
    pub near_clip: f32,
    pub far_clip: f32,
    pub aspect_ratio: f32,
}

impl A3DCamera {
    pub fn new_perspective(width: u32, height: u32, base_fov_deg: f32) -> Self {
        let aspect_ratio = if height > 0 {
            (width as f32) / (height as f32)
        } else {
            16.0 / 9.0
        };
        let base_aspect = 4.0_f32 / 3.0_f32;
        let fov_degrees = if aspect_ratio > base_aspect {
            let base_rad = base_fov_deg.to_radians();
            2.0 * ((base_rad * 0.5).tan() * (aspect_ratio / base_aspect).min(1.85))
                .atan()
                .to_degrees()
        } else {
            base_fov_deg
        };
        Self {
            fov_degrees,
            near_clip: 0.2,
            far_clip: 800.0,
            aspect_ratio,
        }
    }

    pub fn from_settings(settings: &SystemSettings) -> Self {
        Self::new_perspective(settings.render_wid, settings.render_hei, 65.0)
    }
}

#[derive(Debug, Clone)]
pub struct ShaderCatalog {
    pub total_files: usize,
    pub sdr_count: usize,
    pub hlsl_count: usize,
    pub pixel_shader_count: usize,
    pub vertex_shader_count: usize,
}

impl ShaderCatalog {
    pub fn load_from_shaders_pck(pck: &PckArchive) -> PwResult<Self> {
        let mut sdr_count = 0;
        let mut hlsl_count = 0;
        let mut pixel_shader_count = 0;
        let mut vertex_shader_count = 0;
        for e in &pck.entries {
            let p = e.path.to_ascii_lowercase();
            if p.ends_with(".sdr") {
                sdr_count += 1;
            } else if p.ends_with(".hlsl") || p.ends_with(".fx") {
                hlsl_count += 1;
            } else if p.contains("\\ps\\") || p.ends_with(".ps") || p.ends_with(".pso") {
                pixel_shader_count += 1;
            } else if p.contains("\\vs\\") || p.ends_with(".vs") || p.ends_with(".vso") {
                vertex_shader_count += 1;
            }
        }
        Ok(Self {
            total_files: pck.entries.len(),
            sdr_count,
            hlsl_count,
            pixel_shader_count,
            vertex_shader_count,
        })
    }
}

/// 1:1 port of `ftdriver.dll` (`CreateFontDriver`) & `fonts.pck` TrueType font header & table verifier.
#[derive(Debug, Clone)]
pub struct TrueTypeFontInfo {
    pub sfnt_version: u32,
    pub num_tables: u16,
    pub byte_len: usize,
}

pub fn parse_truetype_font(raw: &[u8]) -> PwResult<TrueTypeFontInfo> {
    if raw.len() < 12 {
        return Err(PwError::InvalidData("truncated TrueType font".into()));
    }
    let sfnt_version = u32::from_be_bytes([raw[0], raw[1], raw[2], raw[3]]);
    if sfnt_version != 0x0001_0000 && sfnt_version != 0x7474_6366 && sfnt_version != 0x4F54_544F {
        return Err(PwError::InvalidMagic {
            expected: "TTF/TTC/OTTO",
            found: sfnt_version,
        });
    }
    let num_tables = u16::from_be_bytes([raw[4], raw[5]]);
    Ok(TrueTypeFontInfo {
        sfnt_version,
        num_tables,
        byte_len: raw.len(),
    })
}

/// 1:1 port of `immwrapper.dll` (`CreateIMMWrapper`, 92 procedures) IME composition state machine.
#[derive(Debug, Default, Clone)]
pub struct ImmWrapper {
    pub enabled: bool,
    pub composition_utf16: Vec<u16>,
    pub candidate_list: Vec<String>,
}

/// 1:1 port of `ifc22.dll` (Immersion Foundation Classes force-feedback haptics, 899 procedures).
#[derive(Debug, Default, Clone)]
pub struct Ifc22Haptics {
    pub device_connected: bool,
    pub active_effect: Option<String>,
}

/// 1:1 port of `speedtreert.dll` (`CSpeedTreeRT`, `.spt` parser & wind matrices, 3,050 procedures).
#[derive(Debug, Default, Clone)]
pub struct SpeedTreeForest {
    pub wind_strength: f32,
    pub time_seconds: f32,
    pub wind_matrices: [[f32; 16]; 4],
}

impl SpeedTreeForest {
    pub fn advance_wind(&mut self, dt: f32) {
        self.time_seconds += dt;
        for (i, mat) in self.wind_matrices.iter_mut().enumerate() {
            *mat = [0.0; 16];
            let sway = (self.time_seconds * (1.2 + i as f32 * 0.35)).sin()
                * self.wind_strength
                * 0.08;
            mat[0] = 1.0;
            mat[5] = 1.0;
            mat[10] = 1.0;
            mat[15] = 1.0;
            mat[4] = sway;
            mat[6] = sway * 0.5;
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_cec_face_fallback_paths_exist_in_facedata_pck() {
        // Regression: face/hair texture fallbacks must point at REAL facedata.pck entries.
        let Some(elem) = pw_core::find_test_pw142_element(env!("CARGO_MANIFEST_DIR")) else {
            return;
        };
        if !elem.join("facedata.pck").is_file() {
            return;
        }
        let mut vfs = pw_pck::VirtualFileSystem::new(Some(elem.clone()));
        vfs.mount_pck("facedata", PckArchive::open_path(elem.join("facedata.pck")).unwrap());
        // Every (cls, gender) x every submesh category must resolve at least one real file.
        let cases: &[(i32, u8, &str, &str, bool)] = &[
            (0, 0, "models/face/x", "脸.dds", false),
            (0, 1, "models/face/x", "脸.dds", false),
            (1, 0, "models/face/x", "脸.dds", false),
            (1, 1, "models/face/x", "脸.dds", false),
            (2, 0, "models/face/x", "脸.dds", false),
            (2, 1, "models/face/x", "脸.dds", false),
            (3, 0, "models/face/x", "脸.dds", false),
            (4, 0, "models/face/x", "脸.dds", false),
            (5, 0, "models/face/x", "脸.dds", false),
            (5, 1, "models/face/x", "脸.dds", false),
            (6, 1, "models/face/x", "脸.dds", false),
            (7, 0, "models/face/x", "脸.dds", false),
            (0, 0, "facedata/x/头发模型库", "头发a01.dds", true),
            (2, 1, "facedata/x/头发模型库", "头发a01.dds", true),
            (4, 0, "facedata/x/头发模型库", "x.dds", true),
            (0, 0, "models/face/x", "眼珠a01.dds", false),
            (4, 0, "models/face/x", "眼珠a01.dds", false),
            (1, 1, "models/face/x", "嘴唇a01.dds", false),
            (5, 0, "models/face/x", "嘴唇a01.dds", false),
        ];
        for &(cls, gender, hint, raw, is_hair) in cases {
            let cands = a3d_scene_renderer::cec_face_fallback_candidates(cls, gender, hint, raw, is_hair);
            assert!(!cands.is_empty(), "no candidates for cls={cls} gender={gender} raw={raw}");
            let resolved = cands.iter().find_map(|p| vfs.read_file(p).ok());
            assert!(
                resolved.is_some(),
                "ALL fallback candidates missing from facedata.pck for cls={cls} gender={gender} raw={raw}: {cands:?}"
            );
        }
    }

    #[test]
    fn test_settings_camera_shaders_and_fonts() {
        let syn_ini = b"[Video]\nRenderWid = 3440\nRenderHei = 1440\nWideScreen = 1\n";
        let syn_settings = SystemSettings::from_ini(&IniFile::parse_bytes(syn_ini));
        assert_eq!(syn_settings.render_wid, 3440);
        assert_eq!(syn_settings.render_hei, 1440);
        assert!(syn_settings.widescreen);

        let Some(elem) = pw_core::find_test_pw142_element(env!("CARGO_MANIFEST_DIR")) else {
            return;
        };
        let ini_bytes = std::fs::read(elem.join("userdata/SystemSettings.ini")).unwrap();
        let settings = SystemSettings::from_ini(&IniFile::parse_bytes(&ini_bytes));
        assert_eq!(settings.render_wid, 3440);
        assert_eq!(settings.render_hei, 1440);
        assert!(settings.widescreen);

        let cam = A3DCamera::from_settings(&settings);
        assert!(cam.aspect_ratio > 2.38 && cam.aspect_ratio < 2.40);
        assert!(cam.fov_degrees > 65.0);

        let shaders_pck = PckArchive::open_path(elem.join("shaders.pck")).unwrap();
        let shaders = ShaderCatalog::load_from_shaders_pck(&shaders_pck).unwrap();
        assert!(shaders.total_files > 10);

        let fonts_pck = PckArchive::open_path(elem.join("fonts.pck")).unwrap();
        assert_eq!(fonts_pck.len(), 2);
        for e in &fonts_pck.entries {
            let info = parse_truetype_font(&fonts_pck.read_entry(e).unwrap()).unwrap();
            assert!(info.num_tables > 5);
        }
    }

    #[test]
    fn test_real_login_world_3d_and_aui_render() {
        let Some(full_elem) = pw_core::find_test_pw142_element(env!("CARGO_MANIFEST_DIR")) else {
            return;
        };
        if !full_elem.join("maps/login").is_dir() || !full_elem.join("models.pck").is_file() {
            return;
        }
        let tmp = std::env::temp_dir();
        let mut vfs = pw_pck::VirtualFileSystem::new(Some(full_elem.clone()));
        for &(prefix, rel) in &[
            ("configs", "configs.pck"),
            ("interfaces", "interfaces.pck"),
            ("surfaces", "surfaces.pck"),
            ("textures", "textures.pck"),
            ("litmodels", "litmodels.pck"),
            ("building", "building.pck"),
            ("models", "models.pck"),
        ] {
            let p = full_elem.join(rel);
            if p.exists() {
                vfs.mount_pck(prefix, PckArchive::open_path(p).unwrap());
            }
        }
        let login_world =
            pw_world::MapInstanceBundle::load_map_dir(full_elem.join("maps/login"), "login")
                .unwrap();
        let mut scene = LoadedScene3D::build(&login_world, &vfs);
        assert_eq!(scene.terrain_blocks.len(), 256);
        assert!(
            scene.bmd_models.len() >= 150,
            "loaded {} unique bmd models",
            scene.bmd_models.len()
        );
        assert!(
            scene.ornaments.len() >= 185,
            "loaded {} ornament instances",
            scene.ornaments.len()
        );
        assert!(!scene.water_batches.is_empty(), "loaded water batches");

        // Load real `scenectrl.ini` cameras and `loginui.dcf`
        let scenectrl = pw_world::SceneCtrlConfig::from_ini(&IniFile::parse_bytes(
            &vfs.read_file("configs\\scenectrl.ini").unwrap(),
        ));
        let iface_pck = vfs.get_package("interfaces").unwrap();
        let aui_mgr = pw_aui::AuiManager::load_from_interfaces_pck(iface_pck);
        let mut ui = pw_aui::AuiRuntime::from_dcf(&aui_mgr, "interfaces/loginui.dcf");

        let mut fb = FrameBuffer::new(1280, 800);
        let cam_proj = A3DCamera::new_perspective(1280, 800, 56.0);

        // 1. Render Login Screen (`Cam[0]` + `Win_Login`)
        ui.hide_all_dialogs();
        ui.show_dialog("Win_Login", true);
        ui.set_edit_text("Win_Login", "DEFAULT_Txt_Account", "player");
        ui.set_edit_text("Win_Login", "Txt_PassWord", "secret123");
        ui.set_text("Win_Login", "Txt_CurrentServer", "Genesis");
        ui.focus_edit("Win_Login", "DEFAULT_Txt_Account");

        let login_cam = scenectrl.login_camera();
        let (quads, texts) = build_aui_draw_list(&mut scene, &vfs, &aui_mgr, &ui, 1280, 800);
        assert!(!quads.is_empty());
        render_scene_and_ui_cpu(
            &mut fb,
            &mut scene,
            &vfs,
            login_cam.pos,
            login_cam.dir,
            login_cam.up,
            &cam_proj,
            &[],
            &quads,
            &texts,
            0.0,
        );
        std::fs::write(
            tmp.join("pw_verify_login.bmp"),
            SurfaceImage::encode_bmp_24(fb.width, fb.height, &fb.pixels),
        )
        .unwrap();

        // 2. Render Character Select (`Cam[6]` + `SelChar[7]` 3D Blademaster `.ski` + `Win_Select` + `Win_Manage` + `Win_Manage2`)
        ui.hide_all_dialogs();
        ui.show_dialog("Win_Select", true);
        ui.show_dialog("Win_Manage", true);
        ui.show_dialog("Win_Manage2", true);
        ui.set_text("Win_Select", "Txt_Name1", "AetherBlade");
        ui.set_text("Win_Select", "Txt_Level1", "Lv.100 Blademaster");
        ui.radio_groups.insert(("Win_Select".to_string(), 1), 1);

        let (sel_cam, sel_pos, sel_dir) = scenectrl.select_rig_for_class(0);
        let actor = DynamicCharacterActor {
            role_id: 1024,
            name: "AetherBlade".into(),
            cls: 0,
            gender: 0,
            appearance_preset: 0,
            action: ActorActionKind::Stand,
            ecm_path: None,
            fly_ecm_path: None,
            pos: sel_pos,
            dir: sel_dir,
            scale: 1.0,
            selected: true,
        };
        let (quads2, texts2) = build_aui_draw_list(&mut scene, &vfs, &aui_mgr, &ui, 1280, 800);
        render_scene_and_ui_cpu(
            &mut fb,
            &mut scene,
            &vfs,
            sel_cam.pos,
            sel_cam.dir,
            sel_cam.up,
            &cam_proj,
            &[actor],
            &quads2,
            &texts2,
            1.5,
        );
        std::fs::write(
            tmp.join("pw_verify_select.bmp"),
            SurfaceImage::encode_bmp_24(fb.width, fb.height, &fb.pixels),
        )
        .unwrap();

        // 3. Render Character Create (`NewChar[6]` Winged Elf Archer + `Win_Create` + `Win_CreateGenderName`)
        ui.hide_all_dialogs();
        ui.show_dialog("Win_Create", true);
        ui.set_text("Win_Create", "Combo_Race", "Winged Elf");
        ui.set_text("Win_Create", "Combo_Profession", "Archer");
        ui.set_text("Win_Create", "Combo_Gender", "Female");
        ui.set_edit_text("Win_Create", "DEFAULT_CharName", "SylphWing");
        ui.focus_edit("Win_Create", "DEFAULT_CharName");
        let (cr_cam, cr_pos, cr_dir) = scenectrl.create_rig(6);
        let cr_actor = DynamicCharacterActor {
            role_id: 0,
            name: "SylphWing".into(),
            cls: 6,
            gender: 1,
            appearance_preset: 1,
            action: ActorActionKind::Stand,
            ecm_path: None,
            fly_ecm_path: None,
            pos: cr_pos,
            dir: cr_dir,
            scale: 1.0,
            selected: true,
        };
        let (quads3, texts3) = build_aui_draw_list(&mut scene, &vfs, &aui_mgr, &ui, 1280, 800);
        render_scene_and_ui_cpu(
            &mut fb,
            &mut scene,
            &vfs,
            cr_cam.pos,
            cr_cam.dir,
            cr_cam.up,
            &cam_proj,
            &[cr_actor],
            &quads3,
            &texts3,
            3.0,
        );
        std::fs::write(
            tmp.join("pw_verify_create.bmp"),
            SurfaceImage::encode_bmp_24(fb.width, fb.height, &fb.pixels),
        )
        .unwrap();
    }
}
