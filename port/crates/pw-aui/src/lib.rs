//! `pw-aui` — 1:1 Port of `AngelicaUI` (`0x72e6c0..0x761fff`) & All `199` `CDlg*`/`AUI*` Classes.
//!
//! Grounded directly in `10_auimanager_auidialog.c` & `09_auicontrols_frame_sprite.c`:
//! - `AUIManager::Init` (`0x0072e6c0`) & `AUIManager::LoadDialogLayout` (`0x0072f160`)
//! - `AUIDialog::TranslateAlignPos` (`0x00735630`: `align == -1` => `(scr - dlg) / 2`, `align < -1` => `(scr - dlg) + 2 + align`)
//! - `AUIDialog::ImportStringTable` & `.dtf` token parser (`DIALOG`, `POPUP`, `IMAGEPICTURE`, `STILLIMAGEBUTTON`,
//!   `EDIT`, `LABEL`, `TEXT`, `LIST`, `PROGRESS`, `CHECK`, `RADIO`, `COMBO`, `SCROLL`, `SLIDER`)
//! - Interactive `AuiRuntime` executing real `interfaces/loginui.dcf` and `interfaces/ingame.dcf` scenes.

pub mod generated_dialogs;
pub use generated_dialogs::{UiClassDescriptor, UI_CLASS_REGISTRY};

use std::collections::{BTreeMap, HashMap};

use pw_core::{decode_gbk, decode_utf16le_null_terminated, normalize_vfs_path, IniFile};
use pw_pck::PckArchive;

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum AuiControlKind {
    ImagePicture,
    StillImageButton,
    EditBox,
    Label,
    TextArea,
    ListBox,
    Progress,
    Scroll,
    Slider,
    CheckBox,
    RadioButton,
    ComboBox,
    SubDialog,
    TreeView,
    MenuItem,
    Custom,
}

impl AuiControlKind {
    pub fn from_keyword(kw: &str) -> Option<Self> {
        Some(match kw {
            "IMAGEPICTURE" | "PICTURE" => Self::ImagePicture,
            "STILLIMAGEBUTTON" | "BUTTON" => Self::StillImageButton,
            "EDIT" | "EDITBOX" | "CONSOLE" => Self::EditBox,
            "LABEL" => Self::Label,
            "TEXT" | "TEXTAREA" => Self::TextArea,
            "LIST" | "LISTBOX" => Self::ListBox,
            "PROGRESS" => Self::Progress,
            "SCROLL" => Self::Scroll,
            "SLIDER" => Self::Slider,
            "CHECK" | "CHECKBOX" => Self::CheckBox,
            "RADIO" | "RADIOBUTTON" => Self::RadioButton,
            "COMBO" | "COMBOBOX" => Self::ComboBox,
            "SUBDIALOG" => Self::SubDialog,
            "TREE" | "TREEVIEW" => Self::TreeView,
            "MENUITEM" => Self::MenuItem,
            "CUSTOM" | "MODELPICTURE" | "WINDOWPICTURE" => Self::Custom,
            _ => return None,
        })
    }
}

#[derive(Debug, Clone)]
pub struct AuiControl {
    pub kind: AuiControlKind,
    pub name: String,
    pub command: Option<String>,
    pub sound_sfx: Option<String>,
    pub x: i32,
    pub y: i32,
    pub width: i32,
    pub height: i32,
    /// Primary surface texture relative to `surfaces\` (e.g. `Button\按钮_文本1.dds`).
    pub tex_up: String,
    /// Pressed / checked / progress-fill surface texture relative to `surfaces\`.
    pub tex_down: String,
    /// Hover / highlight surface texture relative to `surfaces\`.
    pub tex_hilite: String,
    /// Vertical sprite frame count (`>= 1` for `IMAGEPICTURE` multi-frame icons).
    pub sprite_frames: u32,
    /// Animation interval in ms per sprite frame (`IMAGEPICTURE` token 9, e.g. `75`ms for `AP_B.tga` burning sparks).
    pub sprite_interval_ms: u32,
    /// `0` = stretch, `1` = 9-slice / frame mode.
    pub frame_mode: i32,
    /// Maximum integer level for `SLIDER` (`AUISlider`, default `100`).
    pub slider_max: i32,
    /// `(left, top, right, bottom)` inner fill margins for `PROGRESS` (`AUIProgress`).
    pub progress_margins: (i32, i32, i32, i32),
    pub font_stf_id: Option<u32>,
    pub font_size: u32,
    /// `0xAARRGGBB` control text color.
    pub text_color: u32,
    pub text_stf_id: Option<u32>,
    pub resolved_text: String,
    /// Localized hover tooltip resolved from the dialog's companion `.htf` hint table (`AUIManager::RenderHint`).
    pub resolved_hint: String,
    pub is_password: bool,
    pub read_only: bool,
    pub radio_group_id: i32,
    pub radio_button_id: i32,
}

#[derive(Debug, Clone)]
pub struct AuiDialogLayout {
    pub vfs_path: String,
    pub normalized_path: String,
    pub is_popup: bool,
    pub dialog_name: String,
    pub x: i32,
    pub y: i32,
    pub width: i32,
    pub height: i32,
    pub title_stf_id: Option<u32>,
    pub resolved_title: String,
    pub font_size: u32,
    pub frame_texture: String,
    pub bg_texture: String,
    pub title_texture: String,
    pub title_rect: (i32, i32, i32, i32),
    pub close_texture: String,
    /// `(close_rx_from_right, close_y_from_top)` (`0x00733770` + `0x00735f40`: screen `x = dx + width - close_pos.0`).
    pub close_pos: (i32, i32),
    pub bg_color: u32,
    pub can_move: bool,
    pub popup_hilite_tex: String,
    pub bound_rtti_class: Option<&'static UiClassDescriptor>,
    pub controls: Vec<AuiControl>,
}

#[derive(Debug, Clone)]
pub struct DcfEntry {
    pub dtf_file: String,
    pub x_align: i32,
    pub y_align: i32,
    pub show_on_load: bool,
}

fn decode_ui_text(bytes: &[u8]) -> String {
    if bytes.starts_with(&[0xFF, 0xFE]) {
        decode_utf16le_null_terminated(&bytes[2..])
    } else if bytes.starts_with(&[0xEF, 0xBB, 0xBF]) {
        String::from_utf8_lossy(&bytes[3..]).into_owned()
    } else if bytes.len() >= 4 && bytes[1] == 0 && bytes[3] == 0 {
        decode_utf16le_null_terminated(bytes)
    } else {
        decode_gbk(bytes)
    }
}

pub fn tokenize_dtf_line(line: &str) -> Vec<String> {
    let mut tokens = Vec::new();
    let mut chars = line.chars().peekable();
    while let Some(&ch) = chars.peek() {
        if ch.is_whitespace() {
            chars.next();
            continue;
        }
        if ch == '"' {
            chars.next();
            let mut s = String::new();
            for c in chars.by_ref() {
                if c == '"' {
                    break;
                }
                s.push(c);
            }
            tokens.push(s);
        } else {
            let mut s = String::new();
            while let Some(&c) = chars.peek() {
                if c.is_whitespace() {
                    break;
                }
                s.push(c);
                chars.next();
            }
            tokens.push(s);
        }
    }
    tokens
}

#[inline]
fn pack_rgba_toks(toks: &[String], r_idx: usize, has_alpha: bool) -> u32 {
    let r = toks.get(r_idx).and_then(|s| s.parse::<u32>().ok()).unwrap_or(255) & 0xFF;
    let g = toks.get(r_idx + 1).and_then(|s| s.parse::<u32>().ok()).unwrap_or(255) & 0xFF;
    let b = toks.get(r_idx + 2).and_then(|s| s.parse::<u32>().ok()).unwrap_or(255) & 0xFF;
    let a = if has_alpha {
        toks.get(r_idx + 3).and_then(|s| s.parse::<u32>().ok()).unwrap_or(255) & 0xFF
    } else {
        255
    };
    (a << 24) | (r << 16) | (g << 8) | b
}

fn looks_like_tex(s: &str) -> bool {
    let l = s.to_ascii_lowercase();
    l.ends_with(".tga") || l.ends_with(".dds") || l.ends_with(".bmp") || l.ends_with(".jpg")
}

/// Strips any untranslated CJK ideographs and normalizes fullwidth spaces (`\u{3000}`) in UI strings.
pub fn sanitize_english_ui_str(s: &str) -> String {
    s.replace('\u{3000}', " ")
        .chars()
        .filter(|&c| {
            !matches!(
                c as u32,
                0x3400..=0x4DBF | 0x4E00..=0x9FFF | 0xF900..=0xFAFF | 0xFF01..=0xFF60
            )
        })
        .collect::<String>()
        .trim()
        .to_string()
}

/// Exact port of `AUIDialog::TranslateAlignPos` (`0x00735630`).
#[inline]
pub fn translate_align_pos(align: i32, screen_dim: i32, dlg_dim: i32) -> i32 {
    if align == -1 {
        (screen_dim - dlg_dim) / 2
    } else if align < -1 {
        (screen_dim - dlg_dim) + 2 + align
    } else {
        align
    }
}

impl AuiDialogLayout {
    pub fn parse_dtf(vfs_path: &str, raw_bytes: &[u8]) -> Option<Self> {
        let text = decode_ui_text(raw_bytes);
        let mut is_popup = false;
        let mut dialog_name = String::new();
        let (mut dx, mut dy, mut dw, mut dh) = (0, 0, 0, 0);
        let mut title_stf_id: Option<u32> = None;
        let mut dlg_font_size = 10u32;
        let mut frame_texture = String::new();
        let mut bg_texture = String::new();
        let mut title_texture = String::new();
        let mut title_rect = (0, 0, -1, -1);
        let mut close_texture = String::new();
        let mut close_pos = (0, 0);
        let mut bg_color = 0xF0FF_FFFFu32;
        let mut can_move = false;
        let mut popup_hilite_tex = String::new();
        let mut found_header = false;
        let mut controls = Vec::new();

        for raw_line in text.lines() {
            let line = raw_line.trim();
            if line.is_empty()
                || line.starts_with('#')
                || line.starts_with("//")
                || line.starts_with(';')
            {
                continue;
            }
            let toks = tokenize_dtf_line(line);
            if toks.is_empty() {
                continue;
            }
            let kw = toks[0].to_ascii_uppercase();
            if kw == "DIALOG" || kw == "POPUP" {
                // Exact port of `AUIDialog::InitFrame` (`0x00733770`):
                // `DIALOG name x y w h title_stf font_stf font_sz frame_tex bg_tex title_tex [if !empty: tx ty tw th] close_tex [if !empty: close_rx close_y] r g b a can_move`
                found_header = true;
                is_popup = kw == "POPUP";
                dialog_name = toks.get(1).cloned().unwrap_or_default();
                dx = toks.get(2).and_then(|s| s.parse().ok()).unwrap_or(0);
                dy = toks.get(3).and_then(|s| s.parse().ok()).unwrap_or(0);
                dw = toks.get(4).and_then(|s| s.parse().ok()).unwrap_or(0);
                dh = toks.get(5).and_then(|s| s.parse().ok()).unwrap_or(0);
                title_stf_id = toks
                    .get(6)
                    .and_then(|s| s.parse::<u32>().ok())
                    .filter(|&v| v > 0);
                dlg_font_size = toks.get(8).and_then(|s| s.parse().ok()).unwrap_or(10);
                frame_texture = toks.get(9).cloned().unwrap_or_default();
                bg_texture = toks.get(10).cloned().unwrap_or_default();
                title_texture = toks.get(11).cloned().unwrap_or_default();
                let mut cur_idx = 12usize;
                if toks.len() >= 24 || !title_texture.is_empty() {
                    title_rect = (
                        toks.get(cur_idx).and_then(|s| s.parse().ok()).unwrap_or(0),
                        toks.get(cur_idx + 1).and_then(|s| s.parse().ok()).unwrap_or(0),
                        toks.get(cur_idx + 2).and_then(|s| s.parse().ok()).unwrap_or(-1),
                        toks.get(cur_idx + 3).and_then(|s| s.parse().ok()).unwrap_or(-1),
                    );
                    cur_idx += 4;
                }
                close_texture = toks.get(cur_idx).cloned().unwrap_or_default();
                cur_idx += 1;
                if toks.len() >= 24 || !close_texture.is_empty() {
                    close_pos = (
                        toks.get(cur_idx).and_then(|s| s.parse().ok()).unwrap_or(0),
                        toks.get(cur_idx + 1).and_then(|s| s.parse().ok()).unwrap_or(0),
                    );
                    cur_idx += 2;
                }
                bg_color = pack_rgba_toks(&toks, cur_idx, true);
                can_move = toks
                    .get(cur_idx + 4)
                    .and_then(|s| s.parse::<i32>().ok())
                    .unwrap_or(0)
                    != 0;
            } else if kw == "HILIGHT" {
                popup_hilite_tex = toks.get(1).cloned().unwrap_or_default();
            } else if kw == "MENUITEM" {
                controls.push(AuiControl {
                    kind: AuiControlKind::MenuItem,
                    name: toks.get(1).cloned().unwrap_or_default(),
                    command: toks.get(1).filter(|s| !s.is_empty()).cloned(),
                    sound_sfx: None,
                    x: 0,
                    y: 0,
                    width: 0,
                    height: 0,
                    tex_up: String::new(),
                    tex_down: String::new(),
                    tex_hilite: String::new(),
                    sprite_frames: 1,
                    sprite_interval_ms: 0,
                    frame_mode: 0,
                    slider_max: 0,
                    progress_margins: (0, 0, 0, 0),
                    font_stf_id: None,
                    font_size: 10,
                    text_color: 0xFFFF_CB4A,
                    text_stf_id: None,
                    resolved_text: sanitize_english_ui_str(toks.get(2).map(String::as_str).unwrap_or("")),
                    resolved_hint: String::new(),
                    is_password: false,
                    read_only: false,
                    radio_group_id: 0,
                    radio_button_id: 0,
                });
            } else if let Some(kind) = AuiControlKind::from_keyword(&kw) {
                let name = toks.get(1).cloned().unwrap_or_default();
                let command = toks.get(2).filter(|s| !s.is_empty()).cloned();
                let sound_sfx = toks.get(3).filter(|s| !s.is_empty()).cloned();
                let x = toks.get(4).and_then(|s| s.parse().ok()).unwrap_or(0);
                let y = toks.get(5).and_then(|s| s.parse().ok()).unwrap_or(0);
                let width = toks.get(6).and_then(|s| s.parse().ok()).unwrap_or(0);
                let height = toks.get(7).and_then(|s| s.parse().ok()).unwrap_or(0);

                let mut tex_up = String::new();
                let mut tex_down = String::new();
                let mut tex_hilite = String::new();
                let mut sprite_frames = 1u32;
                let mut sprite_interval_ms = 0u32;
                let mut frame_mode = 0i32;
                let mut slider_max = 100i32;
                let mut progress_margins = (0, 0, 0, 0);
                let mut font_stf_id: Option<u32> = None;
                let mut font_size = 10u32;
                let mut text_color = 0xFFFF_FFFFu32;
                let mut text_stf_id = None;
                let mut is_password = false;
                let mut read_only = false;
                let mut radio_group_id = 0i32;
                let mut radio_button_id = 0i32;

                match kind {
                    AuiControlKind::ImagePicture => {
                        let t8 = toks.get(8).map(String::as_str).unwrap_or("");
                        let t10 = toks.get(10).map(String::as_str).unwrap_or("");
                        if looks_like_tex(t8) {
                            tex_up = t8.to_string();
                            sprite_frames = toks
                                .get(9)
                                .and_then(|s| s.parse::<u32>().ok())
                                .unwrap_or(1)
                                .max(1);
                            frame_mode = toks.get(10).and_then(|s| s.parse().ok()).unwrap_or(0);
                        } else if looks_like_tex(t10) {
                            sprite_frames = toks
                                .get(8)
                                .and_then(|s| s.parse::<u32>().ok())
                                .unwrap_or(1)
                                .max(1);
                            sprite_interval_ms = toks
                                .get(9)
                                .and_then(|s| s.parse::<u32>().ok())
                                .unwrap_or(0);
                            tex_up = t10.to_string();
                        } else {
                            tex_up = t8.to_string();
                        }
                    }
                    AuiControlKind::StillImageButton => {
                        font_stf_id = toks.get(12).and_then(|s| s.parse().ok());
                        font_size = toks.get(13).and_then(|s| s.parse().ok()).unwrap_or(10);
                        text_color = pack_rgba_toks(&toks, 14, true);
                        tex_up = toks.get(18).cloned().unwrap_or_default();
                        tex_down = toks.get(19).cloned().unwrap_or_default();
                        if looks_like_tex(toks.get(20).map(String::as_str).unwrap_or("")) {
                            tex_hilite = toks.get(20).cloned().unwrap_or_default();
                            text_stf_id = toks.get(22).and_then(|s| s.parse().ok());
                            frame_mode = toks.get(23).and_then(|s| s.parse().ok()).unwrap_or(1);
                        } else {
                            text_stf_id = toks.get(20).and_then(|s| s.parse().ok());
                            frame_mode = toks.get(21).and_then(|s| s.parse().ok()).unwrap_or(1);
                        }
                    }
                    AuiControlKind::EditBox => {
                        if kw == "CONSOLE" {
                            font_stf_id = toks.get(8).and_then(|s| s.parse().ok());
                            font_size = toks.get(9).and_then(|s| s.parse().ok()).unwrap_or(10);
                            read_only = true;
                        } else {
                            tex_up = toks.get(8).cloned().unwrap_or_default();
                            font_stf_id = toks.get(9).and_then(|s| s.parse().ok());
                            font_size = toks.get(10).and_then(|s| s.parse().ok()).unwrap_or(10);
                            text_color = pack_rgba_toks(&toks, 11, false);
                            let mode_s = toks.get(14).map(String::as_str).unwrap_or("");
                            read_only =
                                toks.get(15).and_then(|s| s.parse::<i32>().ok()).unwrap_or(0) != 0;
                            is_password = mode_s.eq_ignore_ascii_case("PASSWORD")
                                || toks.get(16).and_then(|s| s.parse::<i32>().ok()).unwrap_or(0)
                                    != 0;
                            frame_mode = 1;
                        }
                    }
                    AuiControlKind::Label => {
                        font_stf_id = toks.get(8).and_then(|s| s.parse().ok());
                        font_size = toks.get(9).and_then(|s| s.parse().ok()).unwrap_or(10);
                        text_stf_id = toks.get(10).and_then(|s| s.parse().ok());
                        text_color = pack_rgba_toks(&toks, 11, true);
                    }
                    AuiControlKind::TextArea => {
                        font_stf_id = toks.get(8).and_then(|s| s.parse().ok());
                        font_size = toks.get(9).and_then(|s| s.parse().ok()).unwrap_or(10);
                        text_color = pack_rgba_toks(&toks, 10, true);
                        tex_up = toks.get(14).cloned().unwrap_or_default();
                        text_stf_id = toks.get(22).and_then(|s| s.parse().ok());
                    }
                    AuiControlKind::CheckBox => {
                        if looks_like_tex(toks.get(8).map(String::as_str).unwrap_or("")) {
                            tex_up = toks.get(8).cloned().unwrap_or_default();
                        } else {
                            font_stf_id = toks.get(8).and_then(|s| s.parse().ok());
                            font_size = toks.get(9).and_then(|s| s.parse().ok()).unwrap_or(10);
                            text_color = pack_rgba_toks(&toks, 10, true);
                            tex_up = toks.get(14).cloned().unwrap_or_default();
                            tex_down = toks.get(15).cloned().unwrap_or_default();
                            tex_hilite = toks.get(16).cloned().unwrap_or_default();
                            text_stf_id = toks.get(17).and_then(|s| s.parse().ok());
                        }
                    }
                    AuiControlKind::RadioButton => {
                        if looks_like_tex(toks.get(8).map(String::as_str).unwrap_or("")) {
                            tex_up = toks.get(8).cloned().unwrap_or_default();
                            radio_button_id = toks.get(9).and_then(|s| s.parse().ok()).unwrap_or(0);
                            radio_group_id = toks.get(10).and_then(|s| s.parse().ok()).unwrap_or(0);
                        } else {
                            font_stf_id = toks.get(8).and_then(|s| s.parse().ok());
                            font_size = toks.get(9).and_then(|s| s.parse().ok()).unwrap_or(10);
                            text_color = pack_rgba_toks(&toks, 10, true);
                            tex_up = toks.get(14).cloned().unwrap_or_default();
                            tex_down = toks.get(15).cloned().unwrap_or_default();
                            tex_hilite = toks.get(16).cloned().unwrap_or_default();
                            text_stf_id = toks.get(17).and_then(|s| s.parse().ok());
                            radio_group_id = toks.get(19).and_then(|s| s.parse().ok()).unwrap_or(0);
                            radio_button_id = toks.get(20).and_then(|s| s.parse().ok()).unwrap_or(0);
                        }
                    }
                    AuiControlKind::ComboBox | AuiControlKind::ListBox | AuiControlKind::TreeView => {
                        font_stf_id = toks.get(8).and_then(|s| s.parse().ok());
                        font_size = toks.get(9).and_then(|s| s.parse().ok()).unwrap_or(10);
                        text_color = pack_rgba_toks(&toks, 10, true);
                        tex_up = toks.get(14).cloned().unwrap_or_default();
                        tex_hilite = toks.get(15).cloned().unwrap_or_default();
                        frame_mode = 1;
                    }
                    AuiControlKind::Slider => {
                        tex_up = toks.get(8).cloned().unwrap_or_default();
                        tex_down = toks.get(9).cloned().unwrap_or_default();
                        slider_max = toks
                            .get(10)
                            .and_then(|s| s.parse::<i32>().ok())
                            .unwrap_or(100)
                            .max(1);
                    }
                    AuiControlKind::Scroll => {
                        tex_up = toks.get(8).cloned().unwrap_or_default();
                        tex_hilite = toks.get(9).cloned().unwrap_or_default();
                        tex_down = toks.get(11).cloned().unwrap_or_default();
                    }
                    AuiControlKind::Progress => {
                        tex_up = toks.get(8).cloned().unwrap_or_default();
                        tex_down = toks.get(9).cloned().unwrap_or_default();
                        progress_margins = (
                            toks.get(10).and_then(|s| s.parse().ok()).unwrap_or(0),
                            toks.get(11).and_then(|s| s.parse().ok()).unwrap_or(0),
                            toks.get(12).and_then(|s| s.parse().ok()).unwrap_or(0),
                            toks.get(13).and_then(|s| s.parse().ok()).unwrap_or(0),
                        );
                    }
                    _ => {}
                }

                controls.push(AuiControl {
                    kind,
                    name,
                    command,
                    sound_sfx,
                    x,
                    y,
                    width,
                    height,
                    tex_up,
                    tex_down,
                    tex_hilite,
                    sprite_frames,
                    sprite_interval_ms,
                    frame_mode,
                    slider_max,
                    progress_margins,
                    font_stf_id,
                    font_size,
                    text_color,
                    text_stf_id,
                    resolved_text: String::new(),
                    resolved_hint: String::new(),
                    is_password,
                    read_only,
                    radio_group_id,
                    radio_button_id,
                });
            }
        }

        if !found_header {
            return None;
        }
        let bound_rtti_class = match_dialog_rtti(&dialog_name);
        Some(Self {
            vfs_path: vfs_path.to_string(),
            normalized_path: normalize_vfs_path(vfs_path),
            is_popup,
            dialog_name,
            x: dx,
            y: dy,
            width: dw,
            height: dh,
            title_stf_id,
            resolved_title: String::new(),
            font_size: dlg_font_size,
            frame_texture,
            bg_texture,
            title_texture,
            title_rect,
            close_texture,
            close_pos,
            bg_color,
            can_move,
            popup_hilite_tex,
            bound_rtti_class,
            controls,
        })
    }
}

pub fn parse_stf_string_table(raw_bytes: &[u8]) -> BTreeMap<u32, String> {
    let text = decode_ui_text(raw_bytes);
    let mut table = BTreeMap::new();
    for raw_line in text.lines() {
        let line = raw_line.trim();
        if line.is_empty() {
            continue;
        }
        let toks = tokenize_dtf_line(line);
        if toks.len() >= 2 {
            if let Ok(id) = toks[0].parse::<u32>() {
                table.insert(id, toks[1].clone());
            }
        }
    }
    table
}

pub fn parse_dcf_manifest(raw_bytes: &[u8]) -> Vec<DcfEntry> {
    let text = decode_ui_text(raw_bytes);
    let mut entries = Vec::new();
    for raw_line in text.lines() {
        let line = raw_line.trim();
        if line.is_empty() || line.starts_with('#') || line.starts_with("//") {
            continue;
        }
        let cols: Vec<&str> = line.split_whitespace().collect();
        if cols.len() >= 4 {
            entries.push(DcfEntry {
                dtf_file: cols[0].to_string(),
                x_align: cols[1].parse().unwrap_or(0),
                y_align: cols[2].parse().unwrap_or(0),
                show_on_load: cols[3] != "0",
            });
        }
    }
    entries
}

pub fn match_dialog_rtti(dialog_name: &str) -> Option<&'static UiClassDescriptor> {
    let stripped = dialog_name.strip_prefix("Win_").unwrap_or(dialog_name);
    let target = format!("CDlg{}", stripped.replace('_', ""));
    UI_CLASS_REGISTRY
        .iter()
        .find(|d| d.class_name.eq_ignore_ascii_case(&target))
        .or_else(|| UI_CLASS_REGISTRY.iter().find(|d| d.class_name == "AUIDialog"))
}

pub fn parse_htf_hint_table(raw_bytes: &[u8]) -> BTreeMap<String, String> {
    let text = decode_ui_text(raw_bytes);
    let mut table = BTreeMap::new();
    for raw_line in text.lines() {
        let line = raw_line.trim();
        if line.is_empty() || line.starts_with('#') || line.starts_with("//") {
            continue;
        }
        let toks = tokenize_dtf_line(line);
        if toks.len() >= 2 && !toks[0].is_empty() && !toks[1].is_empty() {
            table.insert(toks[0].clone(), toks[1].replace("\\r", "\n"));
        }
    }
    table
}

pub struct AuiManager {
    pub dcf_manifests: BTreeMap<String, Vec<DcfEntry>>,
    pub dialogs: BTreeMap<String, AuiDialogLayout>,
    pub dialogs_by_dtf_path: HashMap<String, String>,
    pub string_tables: BTreeMap<String, BTreeMap<u32, String>>,
    pub hint_tables: BTreeMap<String, BTreeMap<String, String>>,
    pub hint_table_count: usize,
}

impl AuiManager {
    pub fn load_from_interfaces_pck(pck: &PckArchive) -> Self {
        let mut dcf_manifests = BTreeMap::new();
        let mut dialogs = BTreeMap::new();
        let mut dialogs_by_dtf_path = HashMap::new();
        let mut string_tables = BTreeMap::new();
        let mut hint_tables = BTreeMap::new();
        let mut hint_table_count = 0usize;

        // First pass: load all `.stf` string tables AND `.htf` hover hint tables so `.dtf` controls bind both 1:1!
        for entry in &pck.entries {
            if entry.normalized_path.ends_with(".stf") {
                if let Ok(bytes) = pck.read_entry(entry) {
                    string_tables.insert(entry.normalized_path.clone(), parse_stf_string_table(&bytes));
                }
            } else if entry.normalized_path.ends_with(".htf") {
                hint_table_count += 1;
                if let Ok(bytes) = pck.read_entry(entry) {
                    hint_tables.insert(entry.normalized_path.clone(), parse_htf_hint_table(&bytes));
                }
            }
        }

        for entry in &pck.entries {
            let lp = entry.normalized_path.as_str();
            let Ok(bytes) = pck.read_entry(entry) else { continue };
            if lp.ends_with(".dcf") {
                dcf_manifests.insert(entry.normalized_path.clone(), parse_dcf_manifest(&bytes));
            } else if lp.ends_with(".dtf") {
                if let Some(mut dlg) = AuiDialogLayout::parse_dtf(&entry.path, &bytes) {
                    let stf_key = format!("{}.stf", &lp[..lp.len() - 4]);
                    let htf_key = format!("{}.htf", &lp[..lp.len() - 4]);
                    if let Some(stf) = string_tables.get(&stf_key) {
                        if let Some(tid) = dlg.title_stf_id {
                            if let Some(tval) = stf.get(&tid) {
                                if !tval.contains("###") {
                                    dlg.resolved_title = sanitize_english_ui_str(tval);
                                }
                            }
                        }
                        let parent_font_sz = dlg.font_size.max(8);
                        for ctrl in &mut dlg.controls {
                            // `AUIOBJECT::ImportStringTable`: when font descriptor starts with `"0###"` (no custom font),
                            // inherit parent dialog's default font and size (`m_pParent->GetFont()`).
                            if let Some(fid) = ctrl.font_stf_id {
                                if let Some(fdesc) = stf.get(&fid) {
                                    if fdesc.starts_with("0###") {
                                        ctrl.font_size = parent_font_sz;
                                    }
                                }
                            }
                            if let Some(id) = ctrl.text_stf_id {
                                if let Some(val) = stf.get(&id) {
                                    if !val.contains("###") {
                                        ctrl.resolved_text = sanitize_english_ui_str(val);
                                    }
                                }
                            }
                        }
                    }
                    if let Some(htf) = hint_tables.get(&htf_key) {
                        for ctrl in &mut dlg.controls {
                            if let Some(hval) = htf.get(&ctrl.name) {
                                ctrl.resolved_hint = sanitize_english_ui_str(hval);
                            }
                        }
                    }
                    let key = if dlg.dialog_name.is_empty() {
                        entry.normalized_path.clone()
                    } else {
                        dlg.dialog_name.clone()
                    };
                    dialogs_by_dtf_path.insert(entry.normalized_path.clone(), key.clone());
                    dialogs.insert(key, dlg);
                }
            }
        }

        Self {
            dcf_manifests,
            dialogs,
            dialogs_by_dtf_path,
            string_tables,
            hint_tables,
            hint_table_count,
        }
    }

    pub fn total_controls(&self) -> usize {
        self.dialogs.values().map(|d| d.controls.len()).sum()
    }

    pub fn get_stf_string(&self, stf_vfs_path: &str, id: u32) -> Option<&str> {
        let norm = normalize_vfs_path(stf_vfs_path);
        self.string_tables
            .get(&norm)
            .and_then(|t| t.get(&id))
            .map(String::as_str)
    }
}

/// Interactive command event dispatched by `AuiRuntime` (`AUIDialog::OnCommand`).
#[derive(Debug, Clone)]
pub struct AuiCommandEvent {
    pub dialog_name: String,
    pub control_name: String,
    pub command: String,
}

#[derive(Debug, Clone)]
pub struct ActiveDialogState {
    pub dialog_name: String,
    pub x_align: i32,
    pub y_align: i32,
    pub visible: bool,
    pub pos_override: Option<(i32, i32)>,
}

/// Live `AUIManager` scene runtime executing a `.dcf` manifest (`loginui.dcf` or `ingame.dcf`).
#[derive(Debug, Clone)]
pub struct AuiRuntime {
    pub active_dcf: String,
    pub dialog_order: Vec<ActiveDialogState>,
    pub focused_edit: Option<(String, String)>,
    pub hovered_control: Option<(String, String)>,
    pub pressed_control: Option<(String, String)>,
    pub edit_texts: HashMap<(String, String), String>,
    pub text_overrides: HashMap<(String, String), String>,
    pub hidden_controls: HashMap<(String, String), bool>,
    pub check_states: HashMap<(String, String), bool>,
    pub radio_groups: HashMap<(String, i32), i32>,
    pub list_items: HashMap<(String, String), Vec<String>>,
    pub list_selected: HashMap<(String, String), usize>,
    pub progress_values: HashMap<(String, String), f32>,
    /// `(current_level, max_level)` for `AUISlider` controls (`SLIDER` in `.dtf`).
    pub slider_values: HashMap<(String, String), (i32, i32)>,
    /// Dynamic runtime hover tooltip overrides keyed by `(dialog_name, control_name)`.
    pub hint_overrides: HashMap<(String, String), String>,
    pub mouse_x: i32,
    pub mouse_y: i32,
}

impl AuiRuntime {
    pub fn from_dcf(mgr: &AuiManager, dcf_vfs_path: &str) -> Self {
        let norm_dcf = normalize_vfs_path(dcf_vfs_path);
        let entries = mgr.dcf_manifests.get(&norm_dcf).cloned().unwrap_or_default();
        let mut dialog_order = Vec::with_capacity(entries.len());

        for ent in entries {
            let cand1 = normalize_vfs_path(&format!("interfaces/{}", ent.dtf_file));
            let cand2 = normalize_vfs_path(&ent.dtf_file);
            if let Some(dlg_name) = mgr
                .dialogs_by_dtf_path
                .get(&cand1)
                .or_else(|| mgr.dialogs_by_dtf_path.get(&cand2))
            {
                dialog_order.push(ActiveDialogState {
                    dialog_name: dlg_name.clone(),
                    x_align: ent.x_align,
                    y_align: ent.y_align,
                    visible: ent.show_on_load,
                    pos_override: None,
                });
            }
        }

        Self {
            active_dcf: norm_dcf,
            dialog_order,
            focused_edit: None,
            hovered_control: None,
            pressed_control: None,
            edit_texts: HashMap::new(),
            text_overrides: HashMap::new(),
            hidden_controls: HashMap::new(),
            check_states: HashMap::new(),
            radio_groups: HashMap::new(),
            list_items: HashMap::new(),
            list_selected: HashMap::new(),
            progress_values: HashMap::new(),
            slider_values: HashMap::new(),
            hint_overrides: HashMap::new(),
            mouse_x: 0,
            mouse_y: 0,
        }
    }

    pub fn show_dialog(&mut self, dialog_name: &str, show: bool) {
        let mut found_idx = None;
        for (i, d) in self.dialog_order.iter_mut().enumerate() {
            if d.dialog_name.eq_ignore_ascii_case(dialog_name) {
                d.visible = show;
                found_idx = Some(i);
            }
        }
        // Bring newly shown dialog to top of Z-order (`AUIManager::BringWindowToTop`)
        if show {
            if let Some(idx) = found_idx {
                let d = self.dialog_order.remove(idx);
                self.dialog_order.push(d);
            }
        }
    }

    pub fn is_dialog_visible(&self, dialog_name: &str) -> bool {
        self.dialog_order
            .iter()
            .any(|d| d.visible && d.dialog_name.eq_ignore_ascii_case(dialog_name))
    }

    pub fn hide_all_dialogs(&mut self) {
        for d in &mut self.dialog_order {
            d.visible = false;
        }
    }

    pub fn set_control_visible(&mut self, dlg: &str, ctrl: &str, visible: bool) {
        self.hidden_controls
            .insert((dlg.to_string(), ctrl.to_string()), !visible);
    }

    pub fn is_control_visible(&self, dlg: &str, ctrl: &str) -> bool {
        !self
            .hidden_controls
            .get(&(dlg.to_string(), ctrl.to_string()))
            .copied()
            .unwrap_or(false)
    }

    pub fn set_text(&mut self, dlg: &str, ctrl: &str, text: impl Into<String>) {
        self.text_overrides
            .insert((dlg.to_string(), ctrl.to_string()), text.into());
    }

    pub fn set_edit_text(&mut self, dlg: &str, ctrl: &str, text: impl Into<String>) {
        self.edit_texts
            .insert((dlg.to_string(), ctrl.to_string()), text.into());
    }

    pub fn get_edit_text(&self, dlg: &str, ctrl: &str) -> &str {
        self.edit_texts
            .get(&(dlg.to_string(), ctrl.to_string()))
            .map(String::as_str)
            .unwrap_or("")
    }

    pub fn set_slider(&mut self, dlg: &str, ctrl: &str, level: i32, max_level: i32) {
        let mx = max_level.max(1);
        self.slider_values
            .insert((dlg.to_string(), ctrl.to_string()), (level.clamp(0, mx), mx));
    }

    pub fn get_slider(&self, dlg: &str, ctrl: &str, default_max: i32) -> (i32, i32) {
        self.slider_values
            .get(&(dlg.to_string(), ctrl.to_string()))
            .copied()
            .unwrap_or((default_max.max(1) / 2, default_max.max(1)))
    }

    pub fn set_hint(&mut self, dlg: &str, ctrl: &str, hint: impl Into<String>) {
        self.hint_overrides
            .insert((dlg.to_string(), ctrl.to_string()), hint.into());
    }

    /// Resolves the active hover tooltip string (`^RRGGBB` rich text) for whatever control is under `(mouse_x, mouse_y)`.
    pub fn active_hover_hint(&self, mgr: &AuiManager) -> Option<String> {
        let (dlg_name, ctrl_name) = self.hovered_control.as_ref()?;
        if let Some(ov) = self.hint_overrides.get(&(dlg_name.clone(), ctrl_name.clone())) {
            if !ov.is_empty() {
                return Some(ov.clone());
            }
        }
        let layout = mgr.dialogs.get(dlg_name)?;
        if ctrl_name == "__DLG_CLOSE__" {
            return Some("^ffcb4aClose".to_string());
        }
        let ctrl = layout.controls.iter().find(|c| c.name == *ctrl_name)?;
        if !ctrl.resolved_hint.is_empty() {
            Some(ctrl.resolved_hint.clone())
        } else {
            None
        }
    }

    pub fn focus_edit(&mut self, dlg: &str, ctrl: &str) {
        self.focused_edit = Some((dlg.to_string(), ctrl.to_string()));
    }

    pub fn dialog_screen_rect(
        &self,
        state: &ActiveDialogState,
        layout: &AuiDialogLayout,
        screen_w: i32,
        screen_h: i32,
        ui_scale: f32,
    ) -> (i32, i32, i32, i32) {
        let dw = ((layout.width as f32) * ui_scale).round() as i32;
        let dh = ((layout.height as f32) * ui_scale).round() as i32;
        if let Some((ox, oy)) = state.pos_override {
            return (ox, oy, dw, dh);
        }
        let map_align = |al: i32, scr: i32, dim: i32| -> i32 {
            if al == -1 {
                (scr - dim) / 2
            } else if al < -1 {
                (scr - dim) + (((2 + al) as f32) * ui_scale).round() as i32
            } else {
                ((al as f32) * ui_scale).round() as i32
            }
        };
        let sx = map_align(state.x_align, screen_w, dw);
        let sy = map_align(state.y_align, screen_h, dh);
        (sx, sy, dw, dh)
    }

    pub fn find_dialog_screen_rect(
        &self,
        mgr: &AuiManager,
        dlg_name: &str,
        screen_w: u32,
        screen_h: u32,
    ) -> Option<(i32, i32, i32, i32)> {
        let scale = Self::compute_ui_scale(screen_w, screen_h);
        let dstate = self
            .dialog_order
            .iter()
            .find(|d| d.visible && d.dialog_name.eq_ignore_ascii_case(dlg_name))?;
        let layout = mgr.dialogs.get(&dstate.dialog_name)?;
        Some(self.dialog_screen_rect(dstate, layout, screen_w as i32, screen_h as i32, scale))
    }

    pub fn find_control_screen_rect(
        &self,
        mgr: &AuiManager,
        dlg_name: &str,
        ctrl_name: &str,
        screen_w: u32,
        screen_h: u32,
    ) -> Option<(i32, i32, i32, i32)> {
        let scale = Self::compute_ui_scale(screen_w, screen_h);
        let dstate = self
            .dialog_order
            .iter()
            .find(|d| d.visible && d.dialog_name.eq_ignore_ascii_case(dlg_name))?;
        let layout = mgr.dialogs.get(&dstate.dialog_name)?;
        let (dx, dy, _, _) =
            self.dialog_screen_rect(dstate, layout, screen_w as i32, screen_h as i32, scale);
        let ctrl = layout
            .controls
            .iter()
            .find(|c| c.name.eq_ignore_ascii_case(ctrl_name))?;
        Some((
            dx + ((ctrl.x as f32) * scale).round() as i32,
            dy + ((ctrl.y as f32) * scale).round() as i32,
            ((ctrl.width as f32) * scale).round() as i32,
            ((ctrl.height as f32) * scale).round() as i32,
        ))
    }

    pub fn compute_ui_scale(screen_w: u32, screen_h: u32) -> f32 {
        // Verified against `elementclient.exe` Build 2305 (`SystemSettings.ini` `Scale = 0` default,
        // `real_10_login.png`..`real_14_inworld_bigmap.png` at `1280x800`):
        // At desktop resolutions (`>= 1024x720`), `m_fWindowScale = 1.0` so every `.dtf` bitmap,
        // `32x32` icon, `1px` border, and `10pt`/`12px` glyph renders 1:1 without fractional blur!
        if screen_w >= 1024 && screen_h >= 720 {
            1.0
        } else {
            let sy = (screen_h as f32) / 768.0;
            let sx = (screen_w as f32) / 1024.0;
            sy.min(sx).clamp(0.65, 1.0)
        }
    }

    /// Exact port of `CECGameUIMan::LoadUIDefaultLayout` (`0x00597bf3`):
    /// Applies `userdata/Layout/1024.ini` (`[Windows]` `<DlgName>_x`, `<DlgName>_y` percentage coordinates):
    /// `x = int(screen_w * pct_x * 0.01).clamp(0, screen_w - dlg_w)`,
    /// `y = int(screen_h * pct_y * 0.01).clamp(0, screen_h - dlg_h)`.
    pub fn apply_layout_ini(
        &mut self,
        mgr: &AuiManager,
        ini: &IniFile,
        screen_w: u32,
        screen_h: u32,
    ) {
        let scale = Self::compute_ui_scale(screen_w, screen_h);
        let sw = screen_w as i32;
        let sh = screen_h as i32;
        for dstate in &mut self.dialog_order {
            let Some(layout) = mgr.dialogs.get(&dstate.dialog_name) else {
                continue;
            };
            // `0x00596755`: `Win_InventoryM` and `Win_InventoryF` share `Win_Inventory_x` / `Win_Inventory_y` in `1024.ini`!
            let base_key = if dstate.dialog_name.eq_ignore_ascii_case("Win_InventoryM")
                || dstate.dialog_name.eq_ignore_ascii_case("Win_InventoryF")
            {
                "Win_Inventory"
            } else {
                dstate.dialog_name.as_str()
            };
            let kx = format!("{base_key}_x");
            let ky = format!("{base_key}_y");
            let Some(px) = ini.get("Windows", &kx).and_then(|s| s.trim().parse::<f32>().ok()) else {
                continue;
            };
            let Some(py) = ini.get("Windows", &ky).and_then(|s| s.trim().parse::<f32>().ok()) else {
                continue;
            };
            if px < 0.0 || py < 0.0 {
                continue;
            }
            let dw = ((layout.width as f32) * scale).round() as i32;
            let dh = ((layout.height as f32) * scale).round() as i32;
            let sx = ((sw as f32 * px * 0.01) as i32).clamp(0, (sw - dw).max(0));
            let sy = ((sh as f32 * py * 0.01) as i32).clamp(0, (sh - dh).max(0));
            dstate.pos_override = Some((sx, sy));
        }
    }

    pub fn on_mouse_move(&mut self, mgr: &AuiManager, mx: i32, my: i32, screen_w: u32, screen_h: u32) {
        self.mouse_x = mx;
        self.mouse_y = my;
        self.hovered_control = self
            .hit_test(mgr, mx, my, screen_w, screen_h)
            .map(|(d, c, _)| (d, c));
    }

    pub fn on_mouse_down(
        &mut self,
        mgr: &AuiManager,
        mx: i32,
        my: i32,
        screen_w: u32,
        screen_h: u32,
    ) -> Option<AuiCommandEvent> {
        self.mouse_x = mx;
        self.mouse_y = my;
        let scale = Self::compute_ui_scale(screen_w, screen_h);

        // Top-down Z-order hit test
        for dstate in self.dialog_order.iter().rev() {
            if !dstate.visible {
                continue;
            }
            let Some(layout) = mgr.dialogs.get(&dstate.dialog_name) else {
                continue;
            };
            let (dx, dy, dw, dh) =
                self.dialog_screen_rect(dstate, layout, screen_w as i32, screen_h as i32, scale);
            if mx < dx || my < dy || mx >= dx + dw || my >= dy + dh {
                continue;
            }

            // Dialog-level built-in `close_texture` (`m_pA2DSpriteClose` at `(dx + dw - close_rx, dy + close_y)`) -> `IDCANCEL`!
            if !layout.close_texture.is_empty() && layout.close_pos.0 > 0 {
                let cl_x = dx + dw - ((layout.close_pos.0 as f32) * scale).round() as i32;
                let cl_y = dy + ((layout.close_pos.1 as f32) * scale).round() as i32;
                let cl_s = (22.0 * scale).round() as i32;
                if mx >= cl_x - 2 && my >= cl_y - 2 && mx < cl_x + cl_s && my < cl_y + cl_s {
                    self.pressed_control =
                        Some((dstate.dialog_name.clone(), "__DLG_CLOSE__".to_string()));
                    return None;
                }
            }

            for ctrl in layout.controls.iter().rev() {
                if !self.is_control_visible(&dstate.dialog_name, &ctrl.name) {
                    continue;
                }
                let cx = dx + ((ctrl.x as f32) * scale).round() as i32;
                let cy = dy + ((ctrl.y as f32) * scale).round() as i32;
                let cw = ((ctrl.width.max(16) as f32) * scale).round() as i32;
                let ch = ((ctrl.height.max(16) as f32) * scale).round() as i32;
                if mx < cx || my < cy || mx >= cx + cw || my >= cy + ch {
                    continue;
                }

                match ctrl.kind {
                    AuiControlKind::EditBox if !ctrl.read_only => {
                        self.focused_edit = Some((dstate.dialog_name.clone(), ctrl.name.clone()));
                        return None;
                    }
                    AuiControlKind::StillImageButton => {
                        self.pressed_control = Some((dstate.dialog_name.clone(), ctrl.name.clone()));
                        return None;
                    }
                    AuiControlKind::CheckBox => {
                        let key = (dstate.dialog_name.clone(), ctrl.name.clone());
                        let cur = self.check_states.get(&key).copied().unwrap_or(false);
                        self.check_states.insert(key, !cur);
                        let cmd = ctrl.command.clone().unwrap_or_else(|| ctrl.name.clone());
                        return Some(AuiCommandEvent {
                            dialog_name: dstate.dialog_name.clone(),
                            control_name: ctrl.name.clone(),
                            command: cmd,
                        });
                    }
                    AuiControlKind::RadioButton => {
                        self.radio_groups.insert(
                            (dstate.dialog_name.clone(), ctrl.radio_group_id),
                            ctrl.radio_button_id,
                        );
                        let cmd = ctrl.command.clone().unwrap_or_else(|| ctrl.name.clone());
                        return Some(AuiCommandEvent {
                            dialog_name: dstate.dialog_name.clone(),
                            control_name: ctrl.name.clone(),
                            command: cmd,
                        });
                    }
                    AuiControlKind::ListBox | AuiControlKind::TreeView => {
                        let key = (dstate.dialog_name.clone(), ctrl.name.clone());
                        if let Some(items) = self.list_items.get(&key) {
                            if !items.is_empty() {
                                let row_h = (20.0 * scale).max(14.0) as i32;
                                let idx = (((my - cy - 4).max(0) / row_h) as usize)
                                    .min(items.len() - 1);
                                self.list_selected.insert(key, idx);
                                if let Some(cmd) = &ctrl.command {
                                    return Some(AuiCommandEvent {
                                        dialog_name: dstate.dialog_name.clone(),
                                        control_name: ctrl.name.clone(),
                                        command: cmd.clone(),
                                    });
                                }
                            }
                        }
                        return None;
                    }
                    AuiControlKind::Slider => {
                        let max_lv = self
                            .slider_values
                            .get(&(dstate.dialog_name.clone(), ctrl.name.clone()))
                            .map(|&(_, m)| m)
                            .unwrap_or(ctrl.slider_max)
                            .max(1);
                        let frac = ((mx - cx) as f32 / (cw.max(8) as f32)).clamp(0.0, 1.0);
                        let new_lv = ((frac * max_lv as f32).round() as i32).clamp(0, max_lv);
                        self.slider_values
                            .insert((dstate.dialog_name.clone(), ctrl.name.clone()), (new_lv, max_lv));
                        let cmd = ctrl.command.clone().unwrap_or_else(|| ctrl.name.clone());
                        return Some(AuiCommandEvent {
                            dialog_name: dstate.dialog_name.clone(),
                            control_name: ctrl.name.clone(),
                            command: cmd,
                        });
                    }
                    AuiControlKind::ImagePicture if ctrl.command.is_some() => {
                        self.pressed_control = Some((dstate.dialog_name.clone(), ctrl.name.clone()));
                        return None;
                    }
                    AuiControlKind::ComboBox => {
                        let key = (dstate.dialog_name.clone(), ctrl.name.clone());
                        if let Some(items) = self.list_items.get(&key) {
                            if !items.is_empty() {
                                let cur = self.list_selected.get(&key).copied().unwrap_or(0);
                                self.list_selected.insert(key, (cur + 1) % items.len());
                                if let Some(cmd) = &ctrl.command {
                                    return Some(AuiCommandEvent {
                                        dialog_name: dstate.dialog_name.clone(),
                                        control_name: ctrl.name.clone(),
                                        command: cmd.clone(),
                                    });
                                }
                            }
                        }
                        return None;
                    }
                    _ => {}
                }
            }
            break;
        }
        None
    }

    pub fn on_mouse_up(
        &mut self,
        mgr: &AuiManager,
        mx: i32,
        my: i32,
        screen_w: u32,
        screen_h: u32,
    ) -> Option<AuiCommandEvent> {
        let pressed = self.pressed_control.take()?;
        let hit = self.hit_test(mgr, mx, my, screen_w, screen_h)?;
        if hit.0 == pressed.0 && hit.1 == pressed.1 {
            return Some(AuiCommandEvent {
                dialog_name: hit.0,
                control_name: hit.1,
                command: hit.2,
            });
        }
        None
    }

    pub fn on_char_input(&mut self, ch: char) {
        if ch.is_control() {
            return;
        }
        if let Some(key) = self.focused_edit.clone() {
            let entry = self.edit_texts.entry(key).or_default();
            if entry.chars().count() < 48 {
                entry.push(ch);
            }
        }
    }

    pub fn on_backspace(&mut self) {
        if let Some(key) = self.focused_edit.clone() {
            if let Some(entry) = self.edit_texts.get_mut(&key) {
                entry.pop();
            }
        }
    }

    pub fn is_point_inside_visible_dialog(
        &self,
        mgr: &AuiManager,
        mx: i32,
        my: i32,
        screen_w: u32,
        screen_h: u32,
    ) -> bool {
        let scale = Self::compute_ui_scale(screen_w, screen_h);
        for dstate in self.dialog_order.iter().rev() {
            if !dstate.visible {
                continue;
            }
            let Some(layout) = mgr.dialogs.get(&dstate.dialog_name) else {
                continue;
            };
            let (dx, dy, dw, dh) =
                self.dialog_screen_rect(dstate, layout, screen_w as i32, screen_h as i32, scale);
            if mx >= dx && my >= dy && mx < dx + dw && my < dy + dh {
                return true;
            }
        }
        false
    }

    pub fn hit_test(
        &self,
        mgr: &AuiManager,
        mx: i32,
        my: i32,
        screen_w: u32,
        screen_h: u32,
    ) -> Option<(String, String, String)> {
        let scale = Self::compute_ui_scale(screen_w, screen_h);
        for dstate in self.dialog_order.iter().rev() {
            if !dstate.visible {
                continue;
            }
            let Some(layout) = mgr.dialogs.get(&dstate.dialog_name) else {
                continue;
            };
            let (dx, dy, dw, dh) =
                self.dialog_screen_rect(dstate, layout, screen_w as i32, screen_h as i32, scale);
            if mx < dx || my < dy || mx >= dx + dw || my >= dy + dh {
                continue;
            }
            if !layout.close_texture.is_empty() && layout.close_pos.0 > 0 {
                let cl_x = dx + dw - ((layout.close_pos.0 as f32) * scale).round() as i32;
                let cl_y = dy + ((layout.close_pos.1 as f32) * scale).round() as i32;
                let cl_s = (22.0 * scale).round() as i32;
                if mx >= cl_x - 2 && my >= cl_y - 2 && mx < cl_x + cl_s && my < cl_y + cl_s {
                    return Some((
                        dstate.dialog_name.clone(),
                        "__DLG_CLOSE__".to_string(),
                        "IDCANCEL".to_string(),
                    ));
                }
            }
            for ctrl in layout.controls.iter().rev() {
                if !self.is_control_visible(&dstate.dialog_name, &ctrl.name) {
                    continue;
                }
                if !matches!(
                    ctrl.kind,
                    AuiControlKind::StillImageButton
                        | AuiControlKind::EditBox
                        | AuiControlKind::CheckBox
                        | AuiControlKind::RadioButton
                        | AuiControlKind::ComboBox
                        | AuiControlKind::ListBox
                        | AuiControlKind::TreeView
                        | AuiControlKind::Slider
                        | AuiControlKind::Scroll
                        | AuiControlKind::ImagePicture
                ) {
                    continue;
                }
                if ctrl.kind == AuiControlKind::ImagePicture
                    && ctrl.command.is_none()
                    && ctrl.resolved_hint.is_empty()
                    && !self
                        .hint_overrides
                        .contains_key(&(dstate.dialog_name.clone(), ctrl.name.clone()))
                {
                    continue;
                }
                let cx = dx + ((ctrl.x as f32) * scale).round() as i32;
                let cy = dy + ((ctrl.y as f32) * scale).round() as i32;
                let cw = ((ctrl.width.max(12) as f32) * scale).round() as i32;
                let ch = ((ctrl.height.max(12) as f32) * scale).round() as i32;
                if mx >= cx && my >= cy && mx < cx + cw && my < cy + ch {
                    let cmd = ctrl.command.clone().unwrap_or_else(|| ctrl.name.clone());
                    return Some((dstate.dialog_name.clone(), ctrl.name.clone(), cmd));
                }
            }
            return None;
        }
        None
    }
}

// ---------------------------------------------------------------------------
// 6. `AUIClockIcon` Radial Cooldown Sweep, `AUITextArea` Rich Tags, `AUITreeView`, & `AUIComboBox`
// ---------------------------------------------------------------------------

/// 1:1 Port of `AUIClockIcon` (`11_auicontrols_frame.c`):
/// Computes whether normalized icon UV `(u, v)` in `[0.0..=1.0]` lies inside the remaining
/// clockwise cooldown dark overlay (`remaining_ratio` in `0.0..=1.0`, sweeping from 12 o'clock).
pub fn aui_clock_icon_contains_uv(u: f32, v: f32, remaining_ratio: f32) -> bool {
    let ratio = remaining_ratio.clamp(0.0, 1.0);
    if ratio <= 0.001 {
        return false;
    }
    if ratio >= 0.999 {
        return true;
    }
    let dx = u - 0.5;
    let dy = v - 0.5;
    if dx.abs() < 1e-6 && dy.abs() < 1e-6 {
        return true;
    }
    // Clockwise angle from 12 o'clock `(dx=0, dy=-0.5)`: `atan2(dx, -dy)` in `[-PI, PI]` -> `[0, TAU)`
    let mut cw_angle = dx.atan2(-dy);
    if cw_angle < 0.0 {
        cw_angle += std::f32::consts::TAU;
    }
    let elapsed_ratio = 1.0 - ratio;
    let frac = cw_angle / std::f32::consts::TAU;
    frac >= elapsed_ratio
}

/// Rich tag kinds corresponding to `AUITextArea::{TextTag, NameLinkTag, EditBoxItemTag, EmotionTag, LineTag}`.
#[derive(Debug, Clone, PartialEq, Eq)]
pub enum AuiRichSpanKind {
    Text(String),
    NameLink { player_name: String },
    ItemLink { item_id: u32, label: String },
    Emotion { set_idx: u8, icon_idx: u8 },
    LineBreak,
}

#[derive(Debug, Clone, PartialEq, Eq)]
pub struct AuiRichSpan {
    pub color_argb: u32,
    pub kind: AuiRichSpanKind,
}

/// Parses PW 1.4.2 `AUITextArea` rich markup (`^RRGGBB`, `&Player&`, `[Item#id:Name]`, `<set:idx>`, `\r`/`\n`).
pub fn parse_aui_rich_text(input: &str, default_color_argb: u32) -> Vec<AuiRichSpan> {
    let mut out = Vec::new();
    let mut cur_color = default_color_argb;
    let mut cur_text = String::new();
    let chars: Vec<char> = input.chars().collect();
    let mut i = 0usize;

    let flush_text = |buf: &mut String, color: u32, dst: &mut Vec<AuiRichSpan>| {
        if !buf.is_empty() {
            dst.push(AuiRichSpan {
                color_argb: color,
                kind: AuiRichSpanKind::Text(std::mem::take(buf)),
            });
        }
    };

    while i < chars.len() {
        let ch = chars[i];
        if ch == '\n' || ch == '\r' {
            flush_text(&mut cur_text, cur_color, &mut out);
            if ch == '\r' && i + 1 < chars.len() && chars[i + 1] == '\n' {
                i += 1;
            }
            out.push(AuiRichSpan {
                color_argb: cur_color,
                kind: AuiRichSpanKind::LineBreak,
            });
            i += 1;
            continue;
        }
        // `^RRGGBB` inline color tag (`AUITextArea::TextTag`)
        if ch == '^' && i + 6 < chars.len() {
            let hex: String = chars[i + 1..=i + 6].iter().collect();
            if hex.chars().all(|c| c.is_ascii_hexdigit()) {
                if let Ok(rgb) = u32::from_str_radix(&hex, 16) {
                    flush_text(&mut cur_text, cur_color, &mut out);
                    cur_color = (default_color_argb & 0xFF00_0000) | rgb;
                    i += 7;
                    continue;
                }
            }
        }
        // `&PlayerName&` clickable character link (`AUITextArea::NameLinkTag`)
        if ch == '&' {
            if let Some(rel_end) = chars[i + 1..].iter().position(|&c| c == '&') {
                if rel_end > 0 && rel_end <= 24 {
                    let name: String = chars[i + 1..i + 1 + rel_end].iter().collect();
                    flush_text(&mut cur_text, cur_color, &mut out);
                    out.push(AuiRichSpan {
                        color_argb: 0xFF88_E8FF,
                        kind: AuiRichSpanKind::NameLink { player_name: name },
                    });
                    i += rel_end + 2;
                    continue;
                }
            }
        }
        // `[Item#id:Label]` chat equipment link (`AUITextArea::EditBoxItemTag`)
        if ch == '[' {
            if let Some(rel_end) = chars[i + 1..].iter().position(|&c| c == ']') {
                let inner: String = chars[i + 1..i + 1 + rel_end].iter().collect();
                if let Some(rest) = inner.strip_prefix("Item#") {
                    if let Some((id_s, lbl)) = rest.split_once(':') {
                        if let Ok(item_id) = id_s.parse::<u32>() {
                            flush_text(&mut cur_text, cur_color, &mut out);
                            out.push(AuiRichSpan {
                                color_argb: cur_color,
                                kind: AuiRichSpanKind::ItemLink {
                                    item_id,
                                    label: lbl.to_string(),
                                },
                            });
                            i += rel_end + 2;
                            continue;
                        }
                    }
                }
            }
        }
        // `<set:idx>` inline emoticon (`AUITextArea::EmotionTag`)
        if ch == '<' {
            if let Some(rel_end) = chars[i + 1..].iter().position(|&c| c == '>') {
                if rel_end <= 7 {
                    let inner: String = chars[i + 1..i + 1 + rel_end].iter().collect();
                    if let Some((s_str, e_str)) = inner.split_once(':') {
                        if let (Ok(set_idx), Ok(icon_idx)) = (s_str.parse::<u8>(), e_str.parse::<u8>()) {
                            flush_text(&mut cur_text, cur_color, &mut out);
                            out.push(AuiRichSpan {
                                color_argb: cur_color,
                                kind: AuiRichSpanKind::Emotion { set_idx, icon_idx },
                            });
                            i += rel_end + 2;
                            continue;
                        }
                    }
                }
            }
        }
        cur_text.push(ch);
        i += 1;
    }
    flush_text(&mut cur_text, cur_color, &mut out);
    out
}

/// Hierarchical `AUITreeView` state (`PAV_AUITREEVIEW_ITEM::?$APtrStack`).
#[derive(Debug, Clone)]
pub struct AuiTreeNode {
    pub id: u32,
    pub label: String,
    pub expanded: bool,
    pub children: Vec<AuiTreeNode>,
}

#[derive(Debug, Clone, Default)]
pub struct AuiTreeViewState {
    pub roots: Vec<AuiTreeNode>,
    pub selected_id: Option<u32>,
}

impl AuiTreeViewState {
    pub fn toggle_expanded(&mut self, target_id: u32) -> bool {
        fn rec(nodes: &mut [AuiTreeNode], tid: u32) -> bool {
            for n in nodes {
                if n.id == tid {
                    n.expanded = !n.expanded;
                    return true;
                }
                if rec(&mut n.children, tid) {
                    return true;
                }
            }
            false
        }
        rec(&mut self.roots, target_id)
    }

    /// Flattens currently visible `(depth, id, expanded, has_children, label)` rows for rendering/hit-testing.
    pub fn visible_rows(&self) -> Vec<(usize, u32, bool, bool, String)> {
        fn walk(nodes: &[AuiTreeNode], depth: usize, out: &mut Vec<(usize, u32, bool, bool, String)>) {
            for n in nodes {
                out.push((depth, n.id, n.expanded, !n.children.is_empty(), n.label.clone()));
                if n.expanded {
                    walk(&n.children, depth + 1, out);
                }
            }
        }
        let mut out = Vec::new();
        walk(&self.roots, 0, &mut out);
        out
    }
}

/// Interactive `AUIComboBox` dropdown state.
#[derive(Debug, Clone, Default)]
pub struct AuiComboBoxState {
    pub items: Vec<String>,
    pub selected_idx: usize,
    pub open: bool,
}

impl AuiComboBoxState {
    pub fn selected_text(&self) -> &str {
        self.items.get(self.selected_idx).map(String::as_str).unwrap_or("")
    }

    pub fn select(&mut self, idx: usize) {
        if idx < self.items.len() {
            self.selected_idx = idx;
        }
        self.open = false;
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_all_199_rtti_classes_and_real_interfaces_pck_dtf_stf_dcf() {
        assert_eq!(UI_CLASS_REGISTRY.len(), 199);
        assert!(UI_CLASS_REGISTRY.iter().any(|c| c.class_name == "CDlgLoginPage"));
        assert!(UI_CLASS_REGISTRY.iter().any(|c| c.class_name == "CDlgInventory"));

        let Some(elem) = pw_core::find_test_pw142_element(env!("CARGO_MANIFEST_DIR")) else {
            return;
        };
        let pck = PckArchive::open_path(elem.join("interfaces.pck")).unwrap();
        let mgr = AuiManager::load_from_interfaces_pck(&pck);
        assert_eq!(mgr.dcf_manifests.len(), 3, "loginui.dcf, ingame.dcf, loading.dcf");
        assert!(mgr.dialogs.len() >= 450, "expected >=450 .dtf dialogs, got {}", mgr.dialogs.len());
        assert_eq!(mgr.string_tables.len(), 483, "expected all 483 .stf string tables");
        assert_eq!(mgr.hint_table_count, 177, "expected all 177 .htf hint tables");
        assert!(mgr.total_controls() >= 3_000, "expected >=3000 controls, got {}", mgr.total_controls());

        let win_login = mgr.dialogs.get("Win_Login").expect("Win_Login");
        let back = win_login.controls.iter().find(|c| c.name == "Back").expect("Back");
        assert!(back.tex_up.contains("登录底板新.tga"));
        let btn_game = win_login.controls.iter().find(|c| c.name == "Btn_Game").expect("Btn_Game");
        assert_eq!(btn_game.resolved_text, "Start");
        let lab_acc = win_login.controls.iter().find(|c| c.name == "Control_21511284").expect("Account label");
        assert_eq!(lab_acc.resolved_text, "Account");

        // Verify all 177 `.htf` hover hint tables + SLIDER + TREE + TEXT token offsets
        assert_eq!(mgr.hint_tables.len(), 177);
        let win_main = mgr.dialogs.get("Win_Main").expect("Win_Main");
        let btn_skill = win_main.controls.iter().find(|c| c.name == "Btn_Skill").expect("Btn_Skill");
        assert!(btn_skill.resolved_hint.contains("Skills"), "hint={}", btn_skill.resolved_hint);

        let win_sys = mgr.dialogs.get("Win_SettingSystem").expect("Win_SettingSystem");
        let slider_count = win_sys
            .controls
            .iter()
            .filter(|c| c.kind == AuiControlKind::Slider && !c.tex_up.is_empty() && !c.tex_down.is_empty())
            .count();
        assert!(slider_count >= 10, "expected >=10 sliders in Win_SettingSystem, got {slider_count}");

        let win_quest = mgr.dialogs.get("Win_Quest").expect("Win_Quest");
        let tv_q = win_quest.controls.iter().find(|c| c.name == "Tv_Quest").expect("Tv_Quest");
        assert_eq!(tv_q.kind, AuiControlKind::TreeView);
        let txt_q = win_quest.controls.iter().find(|c| c.name == "Txt_Content").expect("Txt_Content");
        assert!(txt_q.tex_up.contains("文本框_4.dds"), "Txt_Content frame tex={}", txt_q.tex_up);
        let win_chat = mgr.dialogs.get("Win_Chat").expect("Win_Chat");
        let txt_chat = win_chat.controls.iter().find(|c| c.name == "Txt_Content").expect("Win_Chat Txt_Content");
        assert!(txt_chat.tex_up.contains("透明色"), "Win_Chat Txt_Content frame tex={}", txt_chat.tex_up);

        let runtime = AuiRuntime::from_dcf(&mgr, "interfaces/loginui.dcf");
        assert!(runtime.dialog_order.len() >= 30);

        // Verify ALL 459 `.dtf` dialogs never leak raw `"###"` font descriptors into `resolved_text`,
        // `"0###..."` (`stf[104]` on `Win_SettingSystem` `"Cloud"`) inherits dialog `font_size == 10`,
        // and `Win_Hpmpxp` / `Win_HpmpOther` / `Win_HpOther` portrait & monster frames match 1:1!
        for (dname, dlg) in &mgr.dialogs {
            for ctrl in &dlg.controls {
                assert!(
                    !ctrl.resolved_text.contains("###"),
                    "raw font descriptor leaked into {dname}::{}: {}",
                    ctrl.name,
                    ctrl.resolved_text
                );
            }
        }
        let cloud_lbl = win_sys
            .controls
            .iter()
            .find(|c| c.resolved_text.trim() == "Cloud")
            .expect("Win_SettingSystem Cloud label");
        assert_eq!(
            cloud_lbl.font_size,
            win_sys.font_size,
            "Cloud label with 0### font descriptor must inherit dialog font_size"
        );
        let hpmpxp = mgr.dialogs.get("Win_Hpmpxp").expect("Win_Hpmpxp");
        let p_size = hpmpxp.controls.iter().find(|c| c.name == "Size").expect("Win_Hpmpxp::Size");
        assert_eq!((p_size.width, p_size.height), (64, 64));

        let hpmp_other = mgr.dialogs.get("Win_HpmpOther").expect("Win_HpmpOther");
        let t_size = hpmp_other.controls.iter().find(|c| c.name == "Size").expect("Win_HpmpOther::Size");
        assert_eq!((t_size.width, t_size.height), (64, 64));

        let hp_other = mgr.dialogs.get("Win_HpOther").expect("Win_HpOther");
        assert!(hp_other.controls.iter().any(|c| c.name == "Txt_Name"));
        assert!(hp_other.controls.iter().any(|c| c.name == "Txt_Att"));
        assert!(hp_other.controls.iter().any(|c| c.name == "Prgs_HP"));
    }

    #[test]
    fn test_aui_clock_icon_rich_tags_treeview_and_combobox() {
        // 1. AUIClockIcon radial sweep: at 50% remaining (`elapsed = 0.5`), right half (`u=0.8, v=0.5`) is clear, left half (`u=0.2, v=0.5`) is dark
        assert!(!aui_clock_icon_contains_uv(0.8, 0.5, 0.5));
        assert!(aui_clock_icon_contains_uv(0.2, 0.5, 0.5));
        assert!(!aui_clock_icon_contains_uv(0.5, 0.2, 0.0));
        assert!(aui_clock_icon_contains_uv(0.5, 0.2, 1.0));

        // 2. AUITextArea rich markup tags (`TextTag`, `NameLinkTag`, `EditBoxItemTag`, `EmotionTag`, `LineTag`)
        let spans = parse_aui_rich_text(
            "&Archosaur& forged ^FFAA00[Item#14820:Dragon Slaying Blade]^FFFFFF <0:03>\nReady!",
            0xFFFF_FFFF,
        );
        assert!(spans.iter().any(|s| s.kind == AuiRichSpanKind::NameLink { player_name: "Archosaur".into() }));
        assert!(spans.iter().any(|s| s.kind == AuiRichSpanKind::ItemLink { item_id: 14820, label: "Dragon Slaying Blade".into() }));
        assert!(spans.iter().any(|s| s.kind == AuiRichSpanKind::Emotion { set_idx: 0, icon_idx: 3 }));
        assert!(spans.iter().any(|s| s.kind == AuiRichSpanKind::LineBreak));

        // 3. AUITreeView expand/collapse & AUIComboBox selection
        let mut tv = AuiTreeViewState {
            roots: vec![AuiTreeNode {
                id: 1,
                label: "Cultivation Quests".into(),
                expanded: true,
                children: vec![AuiTreeNode {
                    id: 11,
                    label: "Spiritual Adept".into(),
                    expanded: false,
                    children: Vec::new(),
                }],
            }],
            selected_id: Some(11),
        };
        assert_eq!(tv.visible_rows().len(), 2);
        assert!(tv.toggle_expanded(1));
        assert_eq!(tv.visible_rows().len(), 1);

        let mut cb = AuiComboBoxState {
            items: vec!["1280x800".into(), "1920x1080".into(), "3440x1440".into()],
            selected_idx: 0,
            open: true,
        };
        cb.select(2);
        assert_eq!(cb.selected_text(), "3440x1440");
        assert!(!cb.open);
    }
}

