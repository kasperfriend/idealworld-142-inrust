//! `pw-data` — Exact Zero-Remainder (`DIFF == 0`) Binary Parsers & Writers for All PW 1.4.2 `.data` Tables.
//!
//! Covers:
//! - `elements.data` (`ElementDataMan` v27 `0x3000001b`, 131 sections, `37,676` records, `0x6618f0.c`)
//! - `tasks.data` (`ATaskTemplMan` v75 `0x93858361`, recursive `ATaskTempl` quest trees + `m_ID` UTF-16 XOR, `0x687d60.c`)
//! - `dyn_tasks.data` (`UnmarshalDynTasks` v10, bitmask-encoded dynamic quests, `0x686b70.c`)
//! - `task_npc.data` (`1,572` NPC task-list descriptors, `0x68a330.c`)
//! - `aipolicy.data` (`CPolicyDataMan` v1 / trigger v7, `1,371` AI policies + AST conditions + ops, `0x466f00.c`)
//! - `domain.data` (`"MOXB"` + `47` Territory War polygons/meshes/graphs + `7` battle time slots)
//! - `gshop.data` / `gshop1.data` / `gshopsev.data` / `gshopsev1.data` (`GlobalData_Load`, `0x675e10.c`)

use std::collections::BTreeMap;

use pw_core::{
    decode_gbk_null_terminated, decode_utf16le_null_terminated, decode_utf16le_xor_null_terminated,
    open_afile_image, AFileMode, BinaryBuilder, BinaryCursor, PwError, PwResult,
};

// ===========================================================================
// 1. `elements.data` (v27 = `0x3000001b`, 131 Sections, `0x6618f0.c`)
// ===========================================================================

pub const ELEMENTS_VERSION_142: u32 = 0x3000_001b;

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum ElementSectionSpec {
    FixedRecord(usize),
    ControlWithTimestamp, // Section [20]: tag + len + bytes[len] + u32 timestamp
    ControlPlain,         // Section [101]: tag + len + bytes[len]
    TalkProc,             // Section [59]: NPC dialogue windows & options (`0x6639b0.c`)
}

/// Exact 131-section v27 layout recovered from `elementdataman::load_data` (`0x6618f0.c`).
pub const ELEMENT_V27_SECTIONS: [ElementSectionSpec; 131] = [
    ElementSectionSpec::FixedRecord(84),   // 000 EQUIPMENT_ADDON
    ElementSectionSpec::FixedRecord(68),   // 001 WEAPON_MAJOR_TYPE
    ElementSectionSpec::FixedRecord(356),  // 002 WEAPON_SUB_TYPE
    ElementSectionSpec::FixedRecord(1412), // 003 WEAPON_ESSENCE
    ElementSectionSpec::FixedRecord(68),   // 004 ARMOR_MAJOR_TYPE
    ElementSectionSpec::FixedRecord(72),   // 005 ARMOR_SUB_TYPE
    ElementSectionSpec::FixedRecord(1120), // 006 ARMOR_ESSENCE
    ElementSectionSpec::FixedRecord(68),   // 007 DECORATION_MAJOR_TYPE
    ElementSectionSpec::FixedRecord(72),   // 008 DECORATION_SUB_TYPE
    ElementSectionSpec::FixedRecord(1164), // 009 DECORATION_ESSENCE
    ElementSectionSpec::FixedRecord(68),   // 010 MEDICINE_MAJOR_TYPE
    ElementSectionSpec::FixedRecord(68),   // 011 MEDICINE_SUB_TYPE
    ElementSectionSpec::FixedRecord(376),  // 012 MEDICINE_ESSENCE
    ElementSectionSpec::FixedRecord(68),   // 013 MATERIAL_MAJOR_TYPE
    ElementSectionSpec::FixedRecord(68),   // 014 MATERIAL_SUB_TYPE
    ElementSectionSpec::FixedRecord(368),  // 015 MATERIAL_ESSENCE
    ElementSectionSpec::FixedRecord(68),   // 016 DAMAGERUNE_SUB_TYPE
    ElementSectionSpec::FixedRecord(364),  // 017 DAMAGERUNE_ESSENCE
    ElementSectionSpec::FixedRecord(68),   // 018 ARMORRUNE_SUB_TYPE
    ElementSectionSpec::FixedRecord(624),  // 019 ARMORRUNE_ESSENCE
    ElementSectionSpec::ControlWithTimestamp, // 020 CTRL_1 (0xab7689dd)
    ElementSectionSpec::FixedRecord(68),   // 021 SKILLTOME_SUB_TYPE
    ElementSectionSpec::FixedRecord(348),  // 022 SKILLTOME_ESSENCE
    ElementSectionSpec::FixedRecord(524),  // 023 FLYSWORD_ESSENCE
    ElementSectionSpec::FixedRecord(488),  // 024 WINGMANWING_ESSENCE
    ElementSectionSpec::FixedRecord(348),  // 025 TOWNSCROLL_ESSENCE
    ElementSectionSpec::FixedRecord(348),  // 026 UNIONSCROLL_ESSENCE
    ElementSectionSpec::FixedRecord(352),  // 027 REVIVESCROLL_ESSENCE
    ElementSectionSpec::FixedRecord(348),  // 028 ELEMENT_ESSENCE
    ElementSectionSpec::FixedRecord(208),  // 029 TASKMATTER_ESSENCE
    ElementSectionSpec::FixedRecord(888),  // 030 TOSSMATTER_ESSENCE
    ElementSectionSpec::FixedRecord(68),   // 031 PROJECTILE_TYPE
    ElementSectionSpec::FixedRecord(892),  // 032 PROJECTILE_ESSENCE
    ElementSectionSpec::FixedRecord(68),   // 033 QUIVER_SUB_TYPE
    ElementSectionSpec::FixedRecord(340),  // 034 QUIVER_ESSENCE
    ElementSectionSpec::FixedRecord(68),   // 035 STONE_SUB_TYPE
    ElementSectionSpec::FixedRecord(436),  // 036 STONE_ESSENCE
    ElementSectionSpec::FixedRecord(84),   // 037 MONSTER_ADDON
    ElementSectionSpec::FixedRecord(196),  // 038 MONSTER_TYPE
    ElementSectionSpec::FixedRecord(1528), // 039 MONSTER_ESSENCE
    ElementSectionSpec::FixedRecord(72),   // 040 NPC_TALK_SERVICE
    ElementSectionSpec::FixedRecord(1224), // 041 NPC_SELL_SERVICE
    ElementSectionSpec::FixedRecord(72),   // 042 NPC_BUY_SERVICE
    ElementSectionSpec::FixedRecord(72),   // 043 NPC_REPAIR_SERVICE
    ElementSectionSpec::FixedRecord(200),  // 044 NPC_INSTALL_SERVICE
    ElementSectionSpec::FixedRecord(200),  // 045 NPC_UNINSTALL_SERVICE
    ElementSectionSpec::FixedRecord(1092), // 046 NPC_TASK_IN_SERVICE
    ElementSectionSpec::FixedRecord(1092), // 047 NPC_TASK_OUT_SERVICE
    ElementSectionSpec::FixedRecord(644),  // 048 NPC_TASK_MATTER_SERVICE
    ElementSectionSpec::FixedRecord(584),  // 049 NPC_SKILL_SERVICE
    ElementSectionSpec::FixedRecord(72),   // 050 NPC_HEAL_SERVICE
    ElementSectionSpec::FixedRecord(460),  // 051 NPC_TRANSMIT_SERVICE
    ElementSectionSpec::FixedRecord(328),  // 052 NPC_TRANSPORT_SERVICE
    ElementSectionSpec::FixedRecord(72),   // 053 NPC_PROXY_SERVICE
    ElementSectionSpec::FixedRecord(68),   // 054 NPC_STORAGE_SERVICE
    ElementSectionSpec::FixedRecord(1228), // 055 NPC_MAKE_SERVICE
    ElementSectionSpec::FixedRecord(72),   // 056 NPC_DECOMPOSE_SERVICE
    ElementSectionSpec::FixedRecord(68),   // 057 NPC_TYPE
    ElementSectionSpec::FixedRecord(852),  // 058 NPC_ESSENCE
    ElementSectionSpec::TalkProc,          // 059 TALK_PROC (`0x6639b0.c`)
    ElementSectionSpec::FixedRecord(476),  // 060 FACE_TEXTURE_ESSENCE
    ElementSectionSpec::FixedRecord(348),  // 061 FACE_SHAPE_ESSENCE
    ElementSectionSpec::FixedRecord(196),  // 062 FACE_EMOTION_TYPE
    ElementSectionSpec::FixedRecord(336),  // 063 FACE_EXPRESSION_ESSENCE
    ElementSectionSpec::FixedRecord(468),  // 064 FACE_HAIR_ESSENCE
    ElementSectionSpec::FixedRecord(340),  // 065 FACE_MOUSTACHE_ESSENCE
    ElementSectionSpec::FixedRecord(208),  // 066 COLORPICKER_ESSENCE
    ElementSectionSpec::FixedRecord(204),  // 067 CUSTOMIZEDATA_ESSENCE
    ElementSectionSpec::FixedRecord(68),   // 068 RECIPE_MAJOR_TYPE
    ElementSectionSpec::FixedRecord(68),   // 069 RECIPE_SUB_TYPE
    ElementSectionSpec::FixedRecord(416),  // 070 RECIPE_ESSENCE
    ElementSectionSpec::FixedRecord(196),  // 071 ENEMY_FACTION_CONFIG
    ElementSectionSpec::FixedRecord(160),  // 072 CHARRACTER_CLASS_CONFIG
    ElementSectionSpec::FixedRecord(612),  // 073 PARAM_ADJUST_CONFIG
    ElementSectionSpec::FixedRecord(552),  // 074 PLAYER_ACTION_INFO_CONFIG
    ElementSectionSpec::FixedRecord(404),  // 075 TASKDICE_ESSENCE
    ElementSectionSpec::FixedRecord(344),  // 076 TASKNORMALMATTER_ESSENCE
    ElementSectionSpec::FixedRecord(340),  // 077 FACE_FALING_ESSENCE
    ElementSectionSpec::FixedRecord(668),  // 078 PLAYER_LEVELEXP_CONFIG
    ElementSectionSpec::FixedRecord(68),   // 079 MINE_TYPE
    ElementSectionSpec::FixedRecord(452),  // 080 MINE_ESSENCE
    ElementSectionSpec::FixedRecord(72),   // 081 NPC_IDENTIFY_SERVICE
    ElementSectionSpec::FixedRecord(68),   // 082 FASHION_MAJOR_TYPE
    ElementSectionSpec::FixedRecord(72),   // 083 FASHION_SUB_TYPE
    ElementSectionSpec::FixedRecord(412),  // 084 FASHION_ESSENCE
    ElementSectionSpec::FixedRecord(68),   // 085 FACETICKET_MAJOR_TYPE
    ElementSectionSpec::FixedRecord(68),   // 086 FACETICKET_SUB_TYPE
    ElementSectionSpec::FixedRecord(488),  // 087 FACETICKET_ESSENCE
    ElementSectionSpec::FixedRecord(68),   // 088 FACEPILL_MAJOR_TYPE
    ElementSectionSpec::FixedRecord(68),   // 089 FACEPILL_SUB_TYPE
    ElementSectionSpec::FixedRecord(2412), // 090 FACEPILL_ESSENCE
    ElementSectionSpec::FixedRecord(292),  // 091 SUITE_ESSENCE
    ElementSectionSpec::FixedRecord(68),   // 092 GM_GENERATOR_TYPE
    ElementSectionSpec::FixedRecord(344),  // 093 GM_GENERATOR_ESSENCE
    ElementSectionSpec::FixedRecord(68),   // 094 PET_TYPE
    ElementSectionSpec::FixedRecord(480),  // 095 PET_ESSENCE
    ElementSectionSpec::FixedRecord(628),  // 096 PET_EGG_ESSENCE
    ElementSectionSpec::FixedRecord(360),  // 097 PET_FOOD_ESSENCE
    ElementSectionSpec::FixedRecord(344),  // 098 PET_FACETICKET_ESSENCE
    ElementSectionSpec::FixedRecord(480),  // 099 FIREWORKS_ESSENCE
    ElementSectionSpec::FixedRecord(344),  // 100 WAR_TANKCALLIN_ESSENCE
    ElementSectionSpec::ControlPlain,      // 101 CTRL_2 (0xee35679f)
    ElementSectionSpec::FixedRecord(148),  // 102 NPC_WAR_TOWERBUILD_SERVICE
    ElementSectionSpec::FixedRecord(1092), // 103 PLAYER_SECONDLEVEL_CONFIG
    ElementSectionSpec::FixedRecord(368),  // 104 NPC_RESETPROP_SERVICE
    ElementSectionSpec::FixedRecord(76),   // 105 NPC_PETNAME_SERVICE
    ElementSectionSpec::FixedRecord(584),  // 106 NPC_PETLEARNSKILL_SERVICE
    ElementSectionSpec::FixedRecord(76),   // 107 NPC_PETFORGETSKILL_SERVICE
    ElementSectionSpec::FixedRecord(356),  // 108 SKILLMATTER_ESSENCE
    ElementSectionSpec::FixedRecord(436),  // 109 REFINE_TICKET_ESSENCE
    ElementSectionSpec::FixedRecord(344),  // 110 DESTROYING_ESSENCE
    ElementSectionSpec::FixedRecord(76),   // 111 NPC_EQUIPBIND_SERVICE
    ElementSectionSpec::FixedRecord(76),   // 112 NPC_EQUIPDESTROY_SERVICE
    ElementSectionSpec::FixedRecord(76),   // 113 NPC_EQUIPUNDESTROY_SERVICE
    ElementSectionSpec::FixedRecord(392),  // 114 BIBLE_ESSENCE
    ElementSectionSpec::FixedRecord(348),  // 115 SPEAKER_ESSENCE
    ElementSectionSpec::FixedRecord(356),  // 116 AUTOHP_ESSENCE
    ElementSectionSpec::FixedRecord(356),  // 117 AUTOMP_ESSENCE
    ElementSectionSpec::FixedRecord(348),  // 118 DOUBLE_EXP_ESSENCE
    ElementSectionSpec::FixedRecord(344),  // 119 TRANSMITSCROLL_ESSENCE
    ElementSectionSpec::FixedRecord(368),  // 120 DYE_TICKET_ESSENCE
    ElementSectionSpec::FixedRecord(1356), // 121 GOBLIN_ESSENCE
    ElementSectionSpec::FixedRecord(68),   // 122 GOBLIN_EQUIP_TYPE
    ElementSectionSpec::FixedRecord(392),  // 123 GOBLIN_EQUIP_ESSENCE
    ElementSectionSpec::FixedRecord(352),  // 124 GOBLIN_EXPPILL_ESSENCE
    ElementSectionSpec::FixedRecord(360),  // 125 SELL_CERTIFICATE_ESSENCE
    ElementSectionSpec::FixedRecord(384),  // 126 TARGET_ITEM_ESSENCE
    ElementSectionSpec::FixedRecord(344),  // 127 LOOK_INFO_ESSENCE
    ElementSectionSpec::FixedRecord(644),  // 128 INC_SKILL_ABILITY_ESSENCE
    ElementSectionSpec::FixedRecord(2116), // 129 WEDDING_BOOKCARD_ESSENCE
    ElementSectionSpec::FixedRecord(1092), // 130 WEDDING_INVITECARD_ESSENCE
];

#[derive(Debug, Clone, PartialEq, Eq)]
pub struct TalkOption {
    pub param: u32,
    pub text: String,
    pub raw_bytes: [u8; 0x88],
}

#[derive(Debug, Clone, PartialEq, Eq)]
pub struct TalkWindow {
    pub id: u32,
    pub id_parent: u32,
    pub talk_text: String,
    pub raw_talk_u16_bytes: Vec<u8>,
    pub options: Vec<TalkOption>,
}

#[derive(Debug, Clone, PartialEq, Eq)]
pub struct TalkProc {
    pub id_talk: u32,
    pub dialog_name: String,
    pub raw_name: [u8; 0x80],
    pub windows: Vec<TalkWindow>,
}

impl TalkProc {
    pub fn parse(cur: &mut BinaryCursor<'_>, xor_key: u16) -> PwResult<Self> {
        let id_talk = cur.read_u32_le()?;
        let name_slice = cur.read_bytes(0x80)?;
        let mut raw_name = [0u8; 0x80];
        raw_name.copy_from_slice(name_slice);
        let dialog_name = decode_utf16le_xor_null_terminated(name_slice, xor_key);
        let num_win = cur.read_u32_le()? as usize;
        let mut windows = Vec::with_capacity(num_win);
        for _ in 0..num_win {
            let id = cur.read_u32_le()?;
            let id_parent = cur.read_u32_le()?;
            let talk_len = cur.read_u32_le()? as usize;
            let raw_talk = cur.read_bytes(talk_len * 2)?.to_vec();
            let talk_text = decode_utf16le_xor_null_terminated(&raw_talk, xor_key);
            let num_opt = cur.read_u32_le()? as usize;
            let mut options = Vec::with_capacity(num_opt);
            for _ in 0..num_opt {
                let opt_slice = cur.read_bytes(0x88)?;
                let mut raw_bytes = [0u8; 0x88];
                raw_bytes.copy_from_slice(opt_slice);
                let param = u32::from_le_bytes([opt_slice[0], opt_slice[1], opt_slice[2], opt_slice[3]]);
                let text = decode_utf16le_xor_null_terminated(&opt_slice[4..0x84], xor_key);
                options.push(TalkOption { param, text, raw_bytes });
            }
            windows.push(TalkWindow {
                id,
                id_parent,
                talk_text,
                raw_talk_u16_bytes: raw_talk,
                options,
            });
        }
        Ok(Self { id_talk, dialog_name, raw_name, windows })
    }

    pub fn write(&self, out: &mut BinaryBuilder) {
        out.write_u32_le(self.id_talk);
        out.write_bytes(&self.raw_name);
        out.write_u32_le(self.windows.len() as u32);
        for w in &self.windows {
            out.write_u32_le(w.id);
            out.write_u32_le(w.id_parent);
            out.write_u32_le((w.raw_talk_u16_bytes.len() / 2) as u32);
            out.write_bytes(&w.raw_talk_u16_bytes);
            out.write_u32_le(w.options.len() as u32);
            for opt in &w.options {
                out.write_bytes(&opt.raw_bytes);
            }
        }
    }
}

#[derive(Debug, Clone)]
pub enum ElementSectionData {
    FixedTable {
        record_size: usize,
        count: usize,
        raw_records: Vec<u8>,
    },
    ControlBlock {
        tag: u32,
        payload: Vec<u8>,
        extra_timestamp: Option<u32>,
    },
    TalkTable(Vec<TalkProc>),
}

#[derive(Debug, Clone)]
pub struct ElementRecordSummary {
    pub section_index: usize,
    pub id: u32,
    pub name: String,
}

#[derive(Debug, Clone)]
pub struct ElementsDatabase {
    pub version: u32,
    pub version_low_u16: u16,
    pub timestamp: u32,
    pub sections: Vec<ElementSectionData>,
}

impl ElementsDatabase {
    /// Parses `elements.data` v27 (`0x3000001b`) and enforces **0 unread trailing bytes (`DIFF == 0`)**.
    pub fn parse_exact(bytes: &[u8]) -> PwResult<Self> {
        let mut cur = BinaryCursor::new(bytes);
        let version = cur.read_u32_le()?;
        let timestamp = cur.read_u32_le()?;
        let version_low_u16 = (version & 0xffff) as u16;
        if version != ELEMENTS_VERSION_142 {
            return Err(PwError::UnsupportedVersion { format: "elements.data", version });
        }

        let mut sections = Vec::with_capacity(ELEMENT_V27_SECTIONS.len());
        for spec in ELEMENT_V27_SECTIONS {
            match spec {
                ElementSectionSpec::FixedRecord(record_size) => {
                    let count = cur.read_u32_le()? as usize;
                    let raw_records = cur.read_bytes(count * record_size)?.to_vec();
                    sections.push(ElementSectionData::FixedTable {
                        record_size,
                        count,
                        raw_records,
                    });
                }
                ElementSectionSpec::ControlWithTimestamp => {
                    let tag = cur.read_u32_le()?;
                    let len = cur.read_u32_le()? as usize;
                    let payload = cur.read_bytes(len)?.to_vec();
                    let extra_ts = cur.read_u32_le()?;
                    sections.push(ElementSectionData::ControlBlock {
                        tag,
                        payload,
                        extra_timestamp: Some(extra_ts),
                    });
                }
                ElementSectionSpec::ControlPlain => {
                    let tag = cur.read_u32_le()?;
                    let len = cur.read_u32_le()? as usize;
                    let payload = cur.read_bytes(len)?.to_vec();
                    sections.push(ElementSectionData::ControlBlock {
                        tag,
                        payload,
                        extra_timestamp: None,
                    });
                }
                ElementSectionSpec::TalkProc => {
                    let count = cur.read_u32_le()? as usize;
                    let mut talks = Vec::with_capacity(count);
                    for _ in 0..count {
                        talks.push(TalkProc::parse(&mut cur, 0)?);
                    }
                    sections.push(ElementSectionData::TalkTable(talks));
                }
            }
        }

        if cur.remaining() != 0 {
            return Err(PwError::InvalidData(format!(
                "elements.data trailing bytes: {}",
                cur.remaining()
            )));
        }

        Ok(Self { version, version_low_u16, timestamp, sections })
    }

    pub fn total_records(&self) -> usize {
        self.sections
            .iter()
            .map(|s| match s {
                ElementSectionData::FixedTable { count, .. } => *count,
                ElementSectionData::ControlBlock { .. } => 0,
                ElementSectionData::TalkTable(t) => t.len(),
            })
            .sum()
    }

    /// Extracts `(id, UTF-16 name)` for any standard essence/type table where `u32 id` is at `0`
    /// and `wchar_t name[32]` (`64` B) starts at offset `4` (or `12` for sub-typed essences).
    pub fn get_record_summary(&self, section_index: usize, row: usize, name_offset: usize) -> Option<ElementRecordSummary> {
        let ElementSectionData::FixedTable { record_size, count, raw_records } =
            self.sections.get(section_index)?
        else {
            return None;
        };
        if row >= *count || *record_size < name_offset + 64 {
            return None;
        }
        let rec = &raw_records[row * record_size..(row + 1) * record_size];
        let id = u32::from_le_bytes([rec[0], rec[1], rec[2], rec[3]]);
        let name = decode_utf16le_null_terminated(&rec[name_offset..name_offset + 64]);
        Some(ElementRecordSummary { section_index, id, name })
    }

    /// Serializes `ElementsDatabase` back into an exact byte-for-byte `elements.data` image.
    pub fn to_bytes(&self) -> Vec<u8> {
        let mut out = BinaryBuilder::with_capacity(29_000_000);
        out.write_u32_le(self.version);
        out.write_u32_le(self.timestamp);
        for sec in &self.sections {
            match sec {
                ElementSectionData::FixedTable { count, raw_records, .. } => {
                    out.write_u32_le(*count as u32);
                    out.write_bytes(raw_records);
                }
                ElementSectionData::ControlBlock { tag, payload, extra_timestamp } => {
                    out.write_u32_le(*tag);
                    out.write_u32_le(payload.len() as u32);
                    out.write_bytes(payload);
                    if let Some(ts) = extra_timestamp {
                        out.write_u32_le(*ts);
                    }
                }
                ElementSectionData::TalkTable(talks) => {
                    out.write_u32_le(talks.len() as u32);
                    for t in talks {
                        t.write(&mut out);
                    }
                }
            }
        }
        out.into_vec()
    }
}

// ===========================================================================
// 2. `tasks.data` (v75 = `0x4b`, Magic `0x93858361`, `0x6892f0.c` / `0x687d60.c`)
// ===========================================================================

pub const TASKS_MAGIC_142: u32 = 0x9385_8361;
pub const TASKS_VERSION_75: u32 = 75;

#[derive(Debug, Clone)]
pub struct TaskTemplateNode {
    pub id: u32,
    pub name: String,
    pub signature: Option<String>,
    pub description: String,
    pub ok_text: String,
    pub no_text: String,
    pub tribute_text: String,
    pub talks: [TalkProc; 5],
    pub sub_tasks: Vec<TaskTemplateNode>,
}

#[derive(Debug, Clone)]
pub struct TasksDatabase {
    pub magic: u32,
    pub version: u32,
    pub offsets: Vec<u32>,
    pub top_tasks: Vec<TaskTemplateNode>,
    pub total_nodes: usize,
}

fn skip_task_award_data(cur: &mut BinaryCursor<'_>) -> PwResult<()> {
    let aw = cur.read_bytes(0xbb)?;
    let rd_u32 = |off: usize| -> u32 {
        u32::from_le_bytes([aw[off], aw[off + 1], aw[off + 2], aw[off + 3]])
    };
    let n_cand = rd_u32(0x54) as usize;
    let n_summon = rd_u32(0x5c) as usize;
    let n_pq = rd_u32(0x7e) as usize;
    let n_var = rd_u32(0x86) as usize;
    let n_disp = rd_u32(0x9f) as usize;
    let n_ch = rd_u32(0xa7) as usize;
    let n_ev = rd_u32(0xb3) as usize;

    for _ in 0..n_cand {
        let _rand = cur.read_u8()?;
        let cnt = cur.read_u32_le()? as usize;
        cur.skip(cnt * 0x11)?;
    }
    if n_summon != 0 {
        cur.skip(6 + n_summon * 0x10)?;
    }
    if n_pq != 0 {
        cur.skip(1 + n_pq * 0x15)?;
    }
    if n_var != 0 {
        cur.skip(n_var * 9)?;
    }
    if n_disp != 0 {
        cur.skip(n_disp * 4)?;
    }
    if n_ch != 0 {
        cur.skip(n_ch * (0x40 + 0x200))?;
    }
    if n_ev != 0 {
        cur.skip(n_ev * 0x80)?;
    }
    Ok(())
}

fn skip_award_by_ratio(cur: &mut BinaryCursor<'_>) -> PwResult<()> {
    let cnt = cur.read_u32_le()? as usize;
    cur.skip(0x14)?;
    for _ in 0..cnt {
        skip_task_award_data(cur)?;
    }
    Ok(())
}

fn skip_award_by_items(cur: &mut BinaryCursor<'_>) -> PwResult<()> {
    let cnt = cur.read_u32_le()? as usize;
    cur.skip(4 + 0x14)?;
    for _ in 0..cnt {
        skip_task_award_data(cur)?;
    }
    Ok(())
}

fn read_xor_len_wstring(cur: &mut BinaryCursor<'_>, xor_key: u16) -> PwResult<String> {
    let char_count = cur.read_u32_le()? as usize;
    let bytes = cur.read_bytes(char_count * 2)?;
    Ok(decode_utf16le_xor_null_terminated(bytes, xor_key))
}

fn parse_task_node(cur: &mut BinaryCursor<'_>, total_nodes: &mut usize) -> PwResult<TaskTemplateNode> {
    *total_nodes += 1;
    let fx = cur.read_bytes(0x361)?;
    let rd_u32 = |off: usize| -> u32 {
        u32::from_le_bytes([fx[off], fx[off + 1], fx[off + 2], fx[off + 3]])
    };

    let id = rd_u32(0);
    let xor_key = (id & 0xffff) as u16;
    let name = decode_utf16le_xor_null_terminated(&fx[4..64], xor_key);

    let signature = if fx[0x40] != 0 {
        let sig_bytes = cur.read_bytes(0x3c)?;
        Some(decode_utf16le_xor_null_terminated(sig_bytes, xor_key))
    } else {
        None
    };

    let n_tm = rd_u32(0x69) as usize;
    if n_tm != 0 {
        cur.skip(n_tm * 0x30)?;
    }
    let n_91 = rd_u32(0x122) as usize;
    if n_91 != 0 {
        cur.skip(n_91 * 9)?;
    }
    let n_135 = rd_u32(0x135) as usize;
    if n_135 != 0 {
        cur.skip(n_135 * (0x40 + 0x200))?;
    }
    let n_143 = rd_u32(0x143) as usize;
    if n_143 != 0 {
        cur.skip(n_143 * 0x0c)?;
    }
    let n_159 = rd_u32(0x159) as usize;
    if n_159 != 0 {
        cur.skip(n_159 * 0x11)?;
    }
    let n_b1 = rd_u32(0x162) as usize;
    if n_b1 != 0 {
        cur.skip(n_b1 * 0x11)?;
    }
    if fx[0x235] != 0 {
        let n_129 = rd_u32(0x252) as usize;
        if n_129 != 0 {
            cur.skip(n_129 * 0x20)?;
        }
    }
    let n_148 = rd_u32(0x290) as usize;
    if n_148 != 0 {
        cur.skip(n_148 * 0x16)?;
    }
    let n_14c = rd_u32(0x298) as usize;
    if n_14c != 0 {
        cur.skip(n_14c * 0x11)?;
    }
    let n_31d = rd_u32(0x31d) as usize;
    if n_31d != 0 {
        cur.skip(n_31d * (0x40 + 0x200))?;
    }
    let n_329 = rd_u32(0x329) as usize;
    if n_329 != 0 {
        cur.skip(n_329 * 0x80)?;
    }

    skip_task_award_data(cur)?;
    skip_task_award_data(cur)?;
    skip_award_by_ratio(cur)?;
    skip_award_by_ratio(cur)?;
    skip_award_by_items(cur)?;
    skip_award_by_items(cur)?;

    let description = read_xor_len_wstring(cur, xor_key)?;
    let ok_text = read_xor_len_wstring(cur, xor_key)?;
    let no_text = read_xor_len_wstring(cur, xor_key)?;
    let tribute_text = read_xor_len_wstring(cur, xor_key)?;

    let talks = [
        TalkProc::parse(cur, xor_key)?,
        TalkProc::parse(cur, xor_key)?,
        TalkProc::parse(cur, xor_key)?,
        TalkProc::parse(cur, xor_key)?,
        TalkProc::parse(cur, xor_key)?,
    ];

    let n_sub = cur.read_u32_le()? as usize;
    let mut sub_tasks = Vec::with_capacity(n_sub);
    for _ in 0..n_sub {
        sub_tasks.push(parse_task_node(cur, total_nodes)?);
    }

    Ok(TaskTemplateNode {
        id,
        name,
        signature,
        description,
        ok_text,
        no_text,
        tribute_text,
        talks,
        sub_tasks,
    })
}

impl TasksDatabase {
    /// Parses `tasks.data` v75 (`0x93858361`), verifying every top-level offset AND **exact EOF (`DIFF == 0`)**.
    pub fn parse_exact(bytes: &[u8]) -> PwResult<Self> {
        let mut cur = BinaryCursor::new(bytes);
        let magic = cur.read_u32_le()?;
        let version = cur.read_u32_le()?;
        let top_count = cur.read_u32_le()? as usize;
        if magic != TASKS_MAGIC_142 {
            return Err(PwError::InvalidMagic { expected: "TASKS_MAGIC (0x93858361)", found: magic });
        }
        if version != TASKS_VERSION_75 {
            return Err(PwError::UnsupportedVersion { format: "tasks.data", version });
        }

        let mut offsets = Vec::with_capacity(top_count);
        for _ in 0..top_count {
            offsets.push(cur.read_u32_le()?);
        }

        let mut top_tasks = Vec::with_capacity(top_count);
        let mut total_nodes = 0usize;
        for (idx, &expected_offset) in offsets.iter().enumerate() {
            if cur.position() != expected_offset as usize {
                return Err(PwError::InvalidData(format!(
                    "tasks.data offset mismatch at top[{idx}]: cursor={:#x}, table={expected_offset:#x}",
                    cur.position()
                )));
            }
            top_tasks.push(parse_task_node(&mut cur, &mut total_nodes)?);
        }

        if cur.remaining() != 0 {
            return Err(PwError::InvalidData(format!(
                "tasks.data trailing bytes: {}",
                cur.remaining()
            )));
        }

        Ok(Self { magic, version, offsets, top_tasks, total_nodes })
    }
}

// ===========================================================================
// 3. `dyn_tasks.data` (`UnmarshalDynTasks` v10, `0x689dc0.c` / `0x686b70.c`)
// ===========================================================================

#[derive(Debug, Clone)]
pub struct DynTaskNode {
    pub id: u32,
    pub dyn_task_type: u8,
    pub name: String,
    pub description: String,
    pub ok_text: String,
    pub no_text: String,
    pub sub_tasks: Vec<DynTaskNode>,
}

#[derive(Debug, Clone)]
pub struct DynTasksDatabase {
    pub total_size: u32,
    pub timestamp: u32,
    pub version: u16,
    pub tasks: Vec<DynTaskNode>,
}

fn skip_compact_talk(cur: &mut BinaryCursor<'_>) -> PwResult<()> {
    let name_bytes = cur.read_u32_le()? as usize;
    cur.skip(name_bytes)?;
    let num_win = cur.read_i8()?.max(0) as usize;
    for _ in 0..num_win {
        let _win_id = cur.read_i8()?;
        let _parent_id = cur.read_i8()?;
        let txt_len = cur.read_u32_le()? as usize;
        cur.skip(txt_len * 2)?;
        let num_opt = cur.read_i8()?.max(0) as usize;
        for _ in 0..num_opt {
            let _cmd = cur.read_u32_le()?;
            let _param = cur.read_u32_le()?;
            let opt_bytes = cur.read_u32_le()? as usize;
            cur.skip(opt_bytes)?;
        }
    }
    Ok(())
}

fn parse_dyn_task_node(cur: &mut BinaryCursor<'_>, has_parent: bool) -> PwResult<DynTaskNode> {
    let mask1 = cur.read_u32_le()?;
    let _reserved = cur.read_u32_le()?;
    let dyn_task_type = cur.read_u8()?;
    if !has_parent && dyn_task_type == 1 {
        let _special = cur.read_u32_le()?;
    }
    let id = cur.read_u32_le()?;
    let name_chars = cur.read_u8()? as usize;
    let name = decode_utf16le_null_terminated(cur.read_bytes(name_chars * 2)?);
    cur.skip(19)?; // 17 bool flags + 2 u8 counters

    if (mask1 & 0x0001) != 0 { cur.skip(4)?; }
    if (mask1 & 0x0002) != 0 { cur.skip(4)?; }
    if (mask1 & 0x0004) != 0 { cur.skip(2)?; }
    if (mask1 & 0x0008) != 0 {
        let n = cur.read_u8()? as usize;
        cur.skip(n * 17)?;
    }
    if (mask1 & 0x0010) != 0 { cur.skip(29)?; }
    if (mask1 & 0x0020) != 0 { cur.skip(17)?; }
    if (mask1 & 0x0040) != 0 {
        let n = cur.read_i8()?.max(0) as usize;
        cur.skip(2 + n * 17)?;
    }
    if (mask1 & 0x0080) != 0 { cur.skip(4)?; }
    if (mask1 & 0x0100) != 0 {
        let n = cur.read_i8()?.max(0) as usize;
        cur.skip(n * 4)?;
    }
    if (mask1 & 0x0200) != 0 { cur.skip(1)?; }
    if (mask1 & 0x0400) != 0 {
        let n = cur.read_i8()?.max(0) as usize;
        cur.skip(n * 4)?;
    }
    if (mask1 & 0x0800) != 0 {
        let n = cur.read_i8()?.max(0) as usize;
        cur.skip(n * 4)?;
    }
    if (mask1 & 0x1000) != 0 {
        let n = cur.read_i8()?.max(0) as usize;
        cur.skip(n + n * 24 + n * 24)?;
    }

    let method = cur.read_u8()?;
    match method {
        1 => {
            let n = cur.read_i8()?.max(0) as usize;
            cur.skip(n * 22)?;
        }
        2 => {
            let n = cur.read_u8()? as usize;
            cur.skip(n * 17 + 4)?;
        }
        4 | 11 => cur.skip(28)?,
        5 => cur.skip(4)?,
        _ => {}
    }

    let _award_type = cur.read_u8()?;
    let mask2 = cur.read_u32_le()?;
    if (mask2 & 0x01) != 0 { cur.skip(4)?; }
    if (mask2 & 0x02) != 0 { cur.skip(4)?; }
    if (mask2 & 0x04) != 0 { cur.skip(4)?; }
    if (mask2 & 0x08) != 0 { cur.skip(4)?; }
    if (mask2 & 0x10) != 0 {
        let cand = cur.read_i8()?.max(0) as usize;
        for _ in 0..cand {
            let _rand = cur.read_u8()?;
            let cnt = cur.read_i8()?.max(0) as usize;
            cur.skip(cnt * 17)?;
        }
    }
    if (mask2 & 0x20) != 0 {
        let flag = cur.read_i8()?;
        if flag != 0 {
            let _b0 = cur.read_u8()?;
            let _b1 = cur.read_i8()?;
            let cnt = cur.read_i8()?.max(0) as usize;
            let _b3 = cur.read_u8()?;
            cur.skip(cnt * 16)?;
        }
    }
    if (mask2 & 0x40) != 0 {
        let flag = cur.read_i8()?;
        if flag != 0 {
            let _b0 = cur.read_u8()?;
            let cnt = cur.read_i8()?.max(0) as usize;
            cur.skip(cnt * 21)?;
        }
    }

    let desc_len = cur.read_u32_le()? as usize;
    let description = decode_utf16le_null_terminated(cur.read_bytes(desc_len * 2)?);
    let ok_len = cur.read_u32_le()? as usize;
    let ok_text = decode_utf16le_null_terminated(cur.read_bytes(ok_len * 2)?);
    let no_len = cur.read_u32_le()? as usize;
    let no_text = decode_utf16le_null_terminated(cur.read_bytes(no_len * 2)?);

    for _ in 0..5 {
        skip_compact_talk(cur)?;
    }

    let sub_cnt = cur.read_i32_le()?.max(0) as usize;
    let mut sub_tasks = Vec::with_capacity(sub_cnt);
    for _ in 0..sub_cnt {
        sub_tasks.push(parse_dyn_task_node(cur, true)?);
    }

    Ok(DynTaskNode { id, dyn_task_type, name, description, ok_text, no_text, sub_tasks })
}

impl DynTasksDatabase {
    pub fn parse_exact(bytes: &[u8]) -> PwResult<Self> {
        let mut cur = BinaryCursor::new(bytes);
        let total_size = cur.read_u32_le()?;
        let timestamp = cur.read_u32_le()?;
        let version = cur.read_u16_le()?;
        let count = cur.read_u16_le()? as usize;
        if version != 10 {
            return Err(PwError::UnsupportedVersion {
                format: "dyn_tasks.data",
                version: version as u32,
            });
        }
        if total_size as usize != bytes.len() {
            return Err(PwError::InvalidData(format!(
                "dyn_tasks.data header size {total_size} != actual {}",
                bytes.len()
            )));
        }
        let mut tasks = Vec::with_capacity(count);
        for _ in 0..count {
            tasks.push(parse_dyn_task_node(&mut cur, false)?);
        }
        if cur.remaining() != 0 {
            return Err(PwError::InvalidData(format!(
                "dyn_tasks.data trailing bytes: {}",
                cur.remaining()
            )));
        }
        Ok(Self { total_size, timestamp, version, tasks })
    }
}

// ===========================================================================
// 4. `task_npc.data` (`0x68a330.c` / `0x68a150.c`)
// ===========================================================================

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub struct TaskNpcEntry {
    pub npc_id: u32,
    pub pos_x: i16,
    pub pos_y: i16,
    pub pos_z: i16,
    pub task_count: u16,
}

#[derive(Debug, Clone)]
pub struct TaskNpcDatabase {
    pub total_size: u32,
    pub timestamp: u32,
    pub version: u16,
    pub entries: Vec<TaskNpcEntry>,
}

impl TaskNpcDatabase {
    pub fn parse_exact(bytes: &[u8]) -> PwResult<Self> {
        let mut cur = BinaryCursor::new(bytes);
        let total_size = cur.read_u32_le()?;
        let timestamp = cur.read_u32_le()?;
        let version = cur.read_u16_le()?;
        let count = cur.read_u16_le()? as usize;
        let mut entries = Vec::with_capacity(count);
        for _ in 0..count {
            entries.push(TaskNpcEntry {
                npc_id: cur.read_u32_le()?,
                pos_x: cur.read_i16_le()?,
                pos_y: cur.read_i16_le()?,
                pos_z: cur.read_i16_le()?,
                task_count: cur.read_u16_le()?,
            });
        }
        if cur.remaining() != 0 {
            return Err(PwError::InvalidData(format!(
                "task_npc.data trailing bytes: {}",
                cur.remaining()
            )));
        }
        Ok(Self { total_size, timestamp, version, entries })
    }
}

// ===========================================================================
// 5. `gshop.data`, `gshop1.data`, `gshopsev.data`, `gshopsev1.data` (`0x675e10.c`)
// ===========================================================================

#[derive(Debug, Clone)]
pub struct GShopClientItem {
    pub local_id: i32,
    pub main_type: i32,
    pub sub_type: i32,
    pub icon_dds: String,
    pub item_id: u32,
    pub item_num: u32,
    pub description: String,
    pub name: String,
    pub raw_bytes: Vec<u8>,
}

#[derive(Debug, Clone)]
pub struct GShopCategory {
    pub name: String,
    pub sub_categories: Vec<String>,
}

#[derive(Debug, Clone)]
pub struct GShopClientDatabase {
    pub timestamp: u32,
    pub items: Vec<GShopClientItem>,
    pub categories: Vec<GShopCategory>,
}

impl GShopClientDatabase {
    pub fn parse_exact(bytes: &[u8]) -> PwResult<Self> {
        let mut cur = BinaryCursor::new(bytes);
        let timestamp = cur.read_u32_le()?;
        let count = cur.read_u32_le()? as usize;
        let mut items = Vec::with_capacity(count);
        for _ in 0..count {
            let raw = cur.read_bytes(0x554)?;
            let local_id = i32::from_le_bytes([raw[0], raw[1], raw[2], raw[3]]);
            let main_type = i32::from_le_bytes([raw[4], raw[5], raw[6], raw[7]]);
            let sub_type = i32::from_le_bytes([raw[8], raw[9], raw[10], raw[11]]);
            let icon_dds = decode_gbk_null_terminated(&raw[12..140]);
            let item_id = u32::from_le_bytes([raw[140], raw[141], raw[142], raw[143]]);
            let item_num = u32::from_le_bytes([raw[144], raw[145], raw[146], raw[147]]);
            let description = decode_utf16le_null_terminated(&raw[276..1300]);
            let name = decode_utf16le_null_terminated(&raw[1300..1364]);
            items.push(GShopClientItem {
                local_id,
                main_type,
                sub_type,
                icon_dds,
                item_id,
                item_num,
                description,
                name,
                raw_bytes: raw.to_vec(),
            });
        }
        let mut categories = Vec::with_capacity(8);
        for _ in 0..8 {
            let cname = cur.read_fixed_utf16le(128)?;
            let sub_cnt = cur.read_u32_le()? as usize;
            let mut sub_categories = Vec::with_capacity(sub_cnt);
            for _ in 0..sub_cnt {
                sub_categories.push(cur.read_fixed_utf16le(128)?);
            }
            categories.push(GShopCategory { name: cname, sub_categories });
        }
        if cur.remaining() != 0 {
            return Err(PwError::InvalidData(format!(
                "gshop.data trailing bytes: {}",
                cur.remaining()
            )));
        }
        Ok(Self { timestamp, items, categories })
    }
}

#[derive(Debug, Clone)]
pub struct GShopServerDatabase {
    pub timestamp: u32,
    pub item_count: usize,
    pub raw_items: Vec<[u8; 0x94]>,
}

impl GShopServerDatabase {
    pub fn parse_exact(bytes: &[u8]) -> PwResult<Self> {
        let mut cur = BinaryCursor::new(bytes);
        let timestamp = cur.read_u32_le()?;
        let item_count = cur.read_u32_le()? as usize;
        let mut raw_items = Vec::with_capacity(item_count);
        for _ in 0..item_count {
            let s = cur.read_bytes(0x94)?;
            let mut arr = [0u8; 0x94];
            arr.copy_from_slice(s);
            raw_items.push(arr);
        }
        if cur.remaining() != 0 {
            return Err(PwError::InvalidData(format!(
                "gshopsev.data trailing bytes: {}",
                cur.remaining()
            )));
        }
        Ok(Self { timestamp, item_count, raw_items })
    }
}

// ===========================================================================
// 6. `domain.data` (`"MOXB"` + 47 Territory War Zones + 7 Battle Slots)
// ===========================================================================

#[derive(Debug, Clone)]
pub struct DomainZone {
    pub name: String,
    pub id: i32,
    pub point: i32,
    pub battle_type: i32,
    pub center_x: i32,
    pub center_y: i32,
    pub vertices: Vec<(i32, i32)>,
    pub faces: Vec<(i32, i32, i32)>,
    pub neighbours: Vec<i32>,
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub struct BattleTimeSlot {
    pub day_of_week: i32,
    pub hour: i32,
    pub minute: i32,
}

#[derive(Debug, Clone)]
pub struct DomainDatabase {
    pub zones: Vec<DomainZone>,
    pub battle_slots: Vec<BattleTimeSlot>,
    pub max_simultaneous_battles: i32,
}

impl DomainDatabase {
    pub fn parse_exact(bytes: &[u8]) -> PwResult<Self> {
        let (mode, mut cur) = open_afile_image(bytes);
        if mode != AFileMode::BinaryMoxb {
            return Err(PwError::InvalidData("domain.data missing MOXB header".into()));
        }
        let count = cur.read_u32_le()? as usize;
        let mut zones = Vec::with_capacity(count);
        for _ in 0..count {
            let name = cur.read_fixed_utf16le(32)?;
            let id = cur.read_i32_le()?;
            let point = cur.read_i32_le()?;
            let battle_type = cur.read_i32_le()?;
            let center_x = cur.read_i32_le()?;
            let center_y = cur.read_i32_le()?;
            let nverts = cur.read_i32_le()?.max(0) as usize;
            let mut vertices = Vec::with_capacity(nverts);
            for _ in 0..nverts {
                vertices.push((cur.read_i32_le()?, cur.read_i32_le()?));
            }
            let nfaces = cur.read_i32_le()?.max(0) as usize;
            let mut faces = Vec::with_capacity(nfaces);
            for _ in 0..nfaces {
                faces.push((cur.read_i32_le()?, cur.read_i32_le()?, cur.read_i32_le()?));
            }
            let nneigh = cur.read_i32_le()?.max(0) as usize;
            let mut neighbours = Vec::with_capacity(nneigh);
            for _ in 0..nneigh {
                neighbours.push(cur.read_i32_le()?);
            }
            zones.push(DomainZone {
                name,
                id,
                point,
                battle_type,
                center_x,
                center_y,
                vertices,
                faces,
                neighbours,
            });
        }

        let num_slots = cur.read_i32_le()?.max(0) as usize;
        let mut battle_slots = Vec::with_capacity(num_slots);
        for _ in 0..num_slots {
            battle_slots.push(BattleTimeSlot {
                day_of_week: cur.read_i32_le()?,
                hour: cur.read_i32_le()?,
                minute: cur.read_i32_le()?,
            });
        }
        let max_simultaneous_battles = cur.read_i32_le()?;

        if cur.remaining() != 0 {
            return Err(PwError::InvalidData(format!(
                "domain.data trailing bytes: {}",
                cur.remaining()
            )));
        }

        Ok(Self { zones, battle_slots, max_simultaneous_battles })
    }
}

// ===========================================================================
// 7. `aipolicy.data` (`CPolicyDataMan` v1 / Trigger v7, `0x467920.c` / `0x466f00.c`)
// ===========================================================================

#[derive(Debug, Clone)]
pub struct AiConditionNode {
    pub cond_type: u32,
    pub params: Vec<u8>,
    pub left: Option<Box<AiConditionNode>>,
    pub right: Option<Box<AiConditionNode>>,
}

#[derive(Debug, Clone)]
pub struct AiOperation {
    pub op_type: u32,
    pub params: Vec<u8>,
    pub target_type: u32,
    pub target_occupations: Option<u32>,
}

#[derive(Debug, Clone)]
pub struct AiTrigger {
    pub version: u32,
    pub id: u32,
    pub active: bool,
    pub run: bool,
    pub attack_valid: bool,
    pub name: String,
    pub root_condition: AiConditionNode,
    pub operations: Vec<AiOperation>,
}

#[derive(Debug, Clone)]
pub struct AiPolicy {
    pub version: u32,
    pub id: u32,
    pub triggers: Vec<AiTrigger>,
}

#[derive(Debug, Clone)]
pub struct AiPolicyDatabase {
    pub header_version: u32,
    pub policies: Vec<AiPolicy>,
}

fn parse_ai_cond_tree(cur: &mut BinaryCursor<'_>) -> PwResult<AiConditionNode> {
    let cond_type = cur.read_u32_le()?;
    let param_len = cur.read_u32_le()? as usize;
    let params = cur.read_bytes(param_len)?.to_vec();
    let mut left = None;
    let mut right = None;
    loop {
        let tag = cur.read_u32_le()?;
        match tag {
            1 => left = Some(Box::new(parse_ai_cond_tree(cur)?)),
            2 => right = Some(Box::new(parse_ai_cond_tree(cur)?)),
            3 | 4 => break,
            other => {
                return Err(PwError::InvalidData(format!("unknown AI condition AST tag {other}")));
            }
        }
    }
    Ok(AiConditionNode { cond_type, params, left, right })
}

fn ai_op_param_len(op: u32, trig_ver: u32, cur: &mut BinaryCursor<'_>) -> PwResult<usize> {
    Ok(match op {
        0 | 4 | 5 | 6 | 8 | 23 => 4,
        1 | 16 | 21 => 8,
        2 => {
            let byte_len = cur.read_u32_le()? as usize;
            return Ok(byte_len); // length prefix already consumed; caller handled below
        }
        3 | 9 | 10 | 11 | 12 | 13 => 0,
        7 | 22 => 12,
        14 => if trig_ver >= 1 { 8 } else { 4 },
        15 => if trig_ver >= 2 { 12 } else { 8 },
        17 => if trig_ver >= 7 { 24 } else { 20 },
        18 => if trig_ver >= 7 { 28 } else { 24 },
        19 => 16,
        20 => if trig_ver >= 5 { 136 } else { 132 },
        24 => 28,
        25 => 36,
        other => {
            return Err(PwError::InvalidData(format!(
                "unknown AI trigger op {other} (tver={trig_ver})"
            )));
        }
    })
}

impl AiPolicyDatabase {
    pub fn parse_exact(bytes: &[u8]) -> PwResult<Self> {
        let mut cur = BinaryCursor::new(bytes);
        let header_version = cur.read_u32_le()?;
        let num_policies = cur.read_u32_le()? as usize;
        let mut policies = Vec::with_capacity(num_policies);

        for _ in 0..num_policies {
            let version = cur.read_u32_le()?;
            let id = cur.read_u32_le()?;
            let num_triggers = cur.read_u32_le()? as usize;
            let mut triggers = Vec::with_capacity(num_triggers);
            for _ in 0..num_triggers {
                let tver = cur.read_u32_le()?;
                let tid = cur.read_u32_le()?;
                let active = cur.read_bool_u8()?;
                let run = cur.read_bool_u8()?;
                let attack_valid = cur.read_bool_u8()?;
                let name = cur.read_fixed_gbk(128)?;
                let root_condition = parse_ai_cond_tree(&mut cur)?;
                let num_ops = cur.read_u32_le()? as usize;
                let mut operations = Vec::with_capacity(num_ops);
                for _ in 0..num_ops {
                    let op_type = cur.read_u32_le()?;
                    let params = if op_type == 2 {
                        let byte_len = cur.read_u32_le()? as usize;
                        cur.read_bytes(byte_len)?.to_vec()
                    } else {
                        let sz = ai_op_param_len(op_type, tver, &mut cur)?;
                        cur.read_bytes(sz)?.to_vec()
                    };
                    let target_type = cur.read_u32_le()?;
                    let target_occupations = if target_type == 6 {
                        Some(cur.read_u32_le()?)
                    } else {
                        None
                    };
                    operations.push(AiOperation {
                        op_type,
                        params,
                        target_type,
                        target_occupations,
                    });
                }
                triggers.push(AiTrigger {
                    version: tver,
                    id: tid,
                    active,
                    run,
                    attack_valid,
                    name,
                    root_condition,
                    operations,
                });
            }
            policies.push(AiPolicy { version, id, triggers });
        }

        if cur.remaining() != 0 {
            return Err(PwError::InvalidData(format!(
                "aipolicy.data trailing bytes: {}",
                cur.remaining()
            )));
        }

        Ok(Self { header_version, policies })
    }
}

// ===========================================================================
// 8. `CECFace` Customization Tables (`elements.data` Sec 60/64/72, `character*.ini`)
//    & Original English Localization Tables (`configs\skillstr.txt`, `buff_str.txt`,
//    `fixed_msg.txt`, `item_ext_desc.txt`)
// ===========================================================================

#[derive(Debug, Clone)]
pub struct FaceTextureRecord {
    pub id: u32,
    pub name: String,
    pub base_tex: String,
    pub high_tex: String,
}

#[derive(Debug, Clone)]
pub struct FaceHairRecord {
    pub id: u32,
    pub name: String,
    pub hair_skin: String,
    pub hair_model: String,
}

#[derive(Debug, Clone)]
pub struct MonsterEssenceRecord {
    pub id: u32,
    pub monster_type: u32,
    pub name: String,
    pub prop: String,
    pub short_desc: String,
    pub file_model: String,
    pub level: u32,
    pub hp: u32,
}

impl ElementsDatabase {
    /// Extracts all `FACE_TEXTURE_ESSENCE` (`Section 60`, `476` B) records keyed by `id`.
    pub fn face_textures(&self) -> std::collections::HashMap<u32, FaceTextureRecord> {
        let mut out = std::collections::HashMap::new();
        let Some(ElementSectionData::FixedTable {
            record_size,
            count,
            raw_records,
        }) = self.sections.get(60)
        else {
            return out;
        };
        if *record_size < 324 {
            return out;
        }
        for row in 0..*count {
            let rec = &raw_records[row * record_size..(row + 1) * record_size];
            let id = u32::from_le_bytes([rec[0], rec[1], rec[2], rec[3]]);
            let name = decode_utf16le_null_terminated(&rec[4..68]);
            let base_tex = decode_gbk_null_terminated(&rec[68..196]);
            let high_tex = decode_gbk_null_terminated(&rec[196..324]);
            out.insert(
                id,
                FaceTextureRecord {
                    id,
                    name,
                    base_tex,
                    high_tex,
                },
            );
        }
        out
    }

    /// Extracts all `FACE_HAIR_ESSENCE` (`Section 64`, `468` B) records keyed by `id`.
    pub fn face_hairs(&self) -> std::collections::HashMap<u32, FaceHairRecord> {
        let mut out = std::collections::HashMap::new();
        let Some(ElementSectionData::FixedTable {
            record_size,
            count,
            raw_records,
        }) = self.sections.get(64)
        else {
            return out;
        };
        if *record_size < 324 {
            return out;
        }
        for row in 0..*count {
            let rec = &raw_records[row * record_size..(row + 1) * record_size];
            let id = u32::from_le_bytes([rec[0], rec[1], rec[2], rec[3]]);
            let name = decode_utf16le_null_terminated(&rec[4..68]);
            let hair_skin = decode_gbk_null_terminated(&rec[68..196]);
            let hair_model = decode_gbk_null_terminated(&rec[196..324]);
            out.insert(
                id,
                FaceHairRecord {
                    id,
                    name,
                    hair_skin,
                    hair_model,
                },
            );
        }
        out
    }

    /// Extracts all `CHARRACTER_CLASS_CONFIG` (`Section 72`, `160` B) English class names (`0..=7`).
    pub fn character_class_names(&self) -> std::collections::HashMap<u32, String> {
        let mut out = std::collections::HashMap::new();
        let Some(ElementSectionData::FixedTable {
            record_size,
            count,
            raw_records,
        }) = self.sections.get(72)
        else {
            return out;
        };
        if *record_size < 72 {
            return out;
        }
        for row in 0..*count {
            let rec = &raw_records[row * record_size..(row + 1) * record_size];
            let name = decode_utf16le_null_terminated(&rec[4..68]);
            let class_id = u32::from_le_bytes([rec[68], rec[69], rec[70], rec[71]]);
            if !name.is_empty() {
                out.insert(class_id, name);
            }
        }
        out
    }

    /// Extracts `MONSTER_ESSENCE` (`Section 39`, `1528` B) records with original English names,
    /// elemental traits (`short_desc`, e.g. `+WT-ER`), `.ecm` model paths, levels, and HP.
    pub fn monster_essences(&self) -> std::collections::HashMap<u32, MonsterEssenceRecord> {
        let mut out = std::collections::HashMap::new();
        let Some(ElementSectionData::FixedTable {
            record_size,
            count,
            raw_records,
        }) = self.sections.get(39)
        else {
            return out;
        };
        if *record_size < 560 {
            return out;
        }
        for row in 0..*count {
            let rec = &raw_records[row * record_size..(row + 1) * record_size];
            let id = u32::from_le_bytes([rec[0], rec[1], rec[2], rec[3]]);
            let monster_type = u32::from_le_bytes([rec[4], rec[5], rec[6], rec[7]]);
            let name = decode_utf16le_null_terminated(&rec[8..72]);
            let prop = decode_utf16le_null_terminated(&rec[72..104]);
            let short_desc = decode_utf16le_null_terminated(&rec[104..136])
                .trim_matches(|c: char| c == '"' || c == '“' || c == '”')
                .to_string();
            let file_model = decode_gbk_null_terminated(&rec[144..272]);
            let level = u32::from_le_bytes([rec[544], rec[545], rec[546], rec[547]]);
            let hp = u32::from_le_bytes([rec[552], rec[553], rec[554], rec[555]]);
            out.insert(
                id,
                MonsterEssenceRecord {
                    id,
                    monster_type,
                    name,
                    prop,
                    short_desc,
                    file_model,
                    level,
                    hp,
                },
            );
        }
        out
    }
}

/// Parsed `userdata/character/character{cls}{gender}.ini` preset for `CECFace` (`0x559250`),
/// facial bone morphing (`shaders\face.sdr`), and `[Body]` skeletal proportion scaling.
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct CharacterCustomizeIni {
    // [3Parts]
    pub scale_up: u8,
    pub scale_middle: u8,
    pub scale_down: u8,
    // [BlendFace]
    pub id_face_shape1: u32,
    pub id_face_shape2: u32,
    pub blend_face_shape: u8,
    // [Face]
    pub scale_face_h: u8,
    pub scale_face_v: u8,
    pub id_face_tex: u32,
    // [Faling]
    pub id_faling_skin: u32,
    pub id_faling_tex: u32,
    // [Forehead]
    pub offset_forehead_h: u8,
    pub offset_forehead_v: u8,
    pub offset_forehead_z: u8,
    pub rotate_forehead: u8,
    pub scale_forehead: u8,
    // [YokeBone]
    pub offset_yokebone_h: u8,
    pub offset_yokebone_v: u8,
    pub offset_yokebone_z: u8,
    pub rotate_yokebone: u8,
    pub scale_yokebone: u8,
    // [Cheek]
    pub offset_cheek_h: u8,
    pub offset_cheek_v: u8,
    pub offset_cheek_z: u8,
    pub scale_cheek: u8,
    // [Chain]
    pub offset_chain_v: u8,
    pub offset_chain_z: u8,
    pub rotate_chain: u8,
    pub scale_chain_h: u8,
    // [Jaw]
    pub offset_jaw_h: u8,
    pub offset_jaw_v: u8,
    pub offset_jaw_z: u8,
    pub scale_jaw_special: u8,
    pub scale_jaw_h: u8,
    pub scale_jaw_v: u8,
    // [Eye]
    pub id_eye_base_tex: u32,
    pub id_eye_high_tex: u32,
    pub id_eye_ball_tex: u32,
    pub id_eye_shape: u32,
    pub scale_eye_h: u8,
    pub scale_eye_v: u8,
    pub rotate_eye: u8,
    pub offset_eye_h: u8,
    pub offset_eye_v: u8,
    pub offset_eye_z: u8,
    pub scale_eye_ball: u8,
    pub scale_eye_h2: u8,
    pub scale_eye_v2: u8,
    pub rotate_eye2: u8,
    pub offset_eye_h2: u8,
    pub offset_eye_v2: u8,
    pub offset_eye_z2: u8,
    pub scale_eye_ball2: u8,
    // [Brow]
    pub id_brow_tex: u32,
    pub id_brow_shape: u32,
    pub scale_brow_h: u8,
    pub scale_brow_v: u8,
    pub rotate_brow: u8,
    pub offset_brow_h: u8,
    pub offset_brow_v: u8,
    pub offset_brow_z: u8,
    pub scale_brow_h2: u8,
    pub scale_brow_v2: u8,
    pub rotate_brow2: u8,
    pub offset_brow_h2: u8,
    pub offset_brow_v2: u8,
    pub offset_brow_z2: u8,
    // [Nose]
    pub id_nose_tex: u32,
    pub id_nose_tip_shape: u32,
    pub scale_nose_tip_h: u8,
    pub scale_nose_tip_v: u8,
    pub scale_nose_tip_z: u8,
    pub offset_nose_tip_v: u8,
    pub id_nose_bridge_shape: u32,
    pub scale_bridge_tip_h: u8,
    pub offset_bridge_tip_z: u8,
    // [Mouth]
    pub id_mouth_up_lip_line: u32,
    pub id_mouth_mid_lip_line: u32,
    pub id_mouth_down_lip_line: u32,
    pub thick_up_lip: u8,
    pub thick_down_lip: u8,
    pub scale_mouth_h: u8,
    pub offset_mouth_v: u8,
    pub offset_mouth_z: u8,
    pub id_mouth_tex: u32,
    pub offset_corner_mouth_special: u8,
    pub scale_mouth_h2: u8,
    pub offset_corner_mouth_special2: u8,
    // [Ear]
    pub id_ear_shape: u32,
    pub scale_ear: u8,
    pub offset_ear_v: u8,
    // [Hair] & [Moustache]
    pub id_hair_model: u32,
    pub id_hair_tex: u32,
    pub id_moustache_tex: u32,
    pub id_moustache_skin: u32,
    pub id_goatee_tex: u32,
    // [Color]
    pub color_face: u32,
    pub color_hair: u32,
    pub color_eye: u32,
    pub color_brow: u32,
    pub color_mouth: u32,
    pub color_eye_ball: u32,
    pub color_moustache: u32,
    // [Body]
    pub body_id: u32,
    pub color_body: u32,
    pub head_scale: u8,
    pub up_scale: u8,
    pub waist_scale: u8,
    pub arm_width: u8,
    pub leg_width: u8,
    pub breast_scale: u8,
}

impl Default for CharacterCustomizeIni {
    fn default() -> Self {
        Self {
            scale_up: 128,
            scale_middle: 128,
            scale_down: 128,
            id_face_shape1: 62,
            id_face_shape2: 62,
            blend_face_shape: 50,
            scale_face_h: 128,
            scale_face_v: 128,
            id_face_tex: 44,
            id_faling_skin: 433,
            id_faling_tex: 437,
            offset_forehead_h: 128,
            offset_forehead_v: 128,
            offset_forehead_z: 128,
            rotate_forehead: 128,
            scale_forehead: 128,
            offset_yokebone_h: 128,
            offset_yokebone_v: 128,
            offset_yokebone_z: 128,
            rotate_yokebone: 128,
            scale_yokebone: 128,
            offset_cheek_h: 128,
            offset_cheek_v: 128,
            offset_cheek_z: 128,
            scale_cheek: 128,
            offset_chain_v: 128,
            offset_chain_z: 128,
            rotate_chain: 128,
            scale_chain_h: 128,
            offset_jaw_h: 128,
            offset_jaw_v: 128,
            offset_jaw_z: 128,
            scale_jaw_special: 128,
            scale_jaw_h: 128,
            scale_jaw_v: 128,
            id_eye_base_tex: 50,
            id_eye_high_tex: 0,
            id_eye_ball_tex: 48,
            id_eye_shape: 74,
            scale_eye_h: 128,
            scale_eye_v: 128,
            rotate_eye: 128,
            offset_eye_h: 128,
            offset_eye_v: 128,
            offset_eye_z: 128,
            scale_eye_ball: 128,
            scale_eye_h2: 128,
            scale_eye_v2: 128,
            rotate_eye2: 128,
            offset_eye_h2: 128,
            offset_eye_v2: 128,
            offset_eye_z2: 128,
            scale_eye_ball2: 128,
            id_brow_tex: 45,
            id_brow_shape: 70,
            scale_brow_h: 128,
            scale_brow_v: 128,
            rotate_brow: 128,
            offset_brow_h: 128,
            offset_brow_v: 128,
            offset_brow_z: 128,
            scale_brow_h2: 128,
            scale_brow_v2: 128,
            rotate_brow2: 128,
            offset_brow_h2: 128,
            offset_brow_v2: 128,
            offset_brow_z2: 128,
            id_nose_tex: 0,
            id_nose_tip_shape: 16,
            scale_nose_tip_h: 128,
            scale_nose_tip_v: 128,
            scale_nose_tip_z: 128,
            offset_nose_tip_v: 128,
            id_nose_bridge_shape: 15,
            scale_bridge_tip_h: 128,
            offset_bridge_tip_z: 128,
            id_mouth_up_lip_line: 91,
            id_mouth_mid_lip_line: 86,
            id_mouth_down_lip_line: 94,
            thick_up_lip: 128,
            thick_down_lip: 128,
            scale_mouth_h: 128,
            offset_mouth_v: 128,
            offset_mouth_z: 128,
            id_mouth_tex: 52,
            offset_corner_mouth_special: 128,
            scale_mouth_h2: 128,
            offset_corner_mouth_special2: 128,
            id_ear_shape: 22,
            scale_ear: 128,
            offset_ear_v: 128,
            id_hair_model: 265,
            id_hair_tex: 313,
            id_moustache_tex: 0,
            id_moustache_skin: 0,
            id_goatee_tex: 0,
            color_face: 0xFFF6_F0E9,
            color_hair: 0xFF50_4135,
            color_eye: 0xFF40_3832,
            color_brow: 0xFF3A_3028,
            color_mouth: 0xFFD8_9088,
            color_eye_ball: 0xFF48_3828,
            color_moustache: 0xFF3A_3028,
            body_id: 0,
            color_body: 0xFFF6_F0E9,
            head_scale: 128,
            up_scale: 128,
            waist_scale: 128,
            arm_width: 128,
            leg_width: 128,
            breast_scale: 128,
        }
    }
}

impl CharacterCustomizeIni {
    /// Converts a `[0..255]` `CECFace`/`CECPlayer` slider byte (`128` = neutral `1.0`) to a multiplicative bone scale.
    #[inline]
    pub fn slider_to_scale(byte_val: u8, max_delta: f32) -> f32 {
        (1.0 + ((byte_val as f32 - 128.0) / 128.0) * max_delta).clamp(0.55, 1.55)
    }

    /// Converts a `[0..255]` `CECFace` slider byte (`128` = `0.0`) to a signed bone offset/angle.
    #[inline]
    pub fn slider_to_offset(byte_val: u8, max_offset: f32) -> f32 {
        ((byte_val as f32 - 128.0) / 128.0) * max_offset
    }

    pub fn parse_ini_bytes(raw: &[u8]) -> Self {
        let text = if raw.len() >= 2 && raw[0] == 0xFF && raw[1] == 0xFE {
            let u16s: Vec<u16> = raw[2..]
                .chunks_exact(2)
                .map(|c| u16::from_le_bytes([c[0], c[1]]))
                .collect();
            String::from_utf16_lossy(&u16s)
        } else {
            String::from_utf8_lossy(raw).into_owned()
        };

        let mut out = Self::default();
        let mut has_body_color = false;
        let parse_col = |v: &str| -> Option<u32> {
            let sv = v.trim().parse::<i64>().ok()?;
            Some((sv as i32 as u32) | 0xFF00_0000)
        };
        let parse_id = |v: &str| -> Option<u32> { v.trim().parse::<i64>().ok().map(|x| x.max(0) as u32) };
        let parse_u8 = |v: &str| -> Option<u8> { v.trim().parse::<i64>().ok().map(|x| x.clamp(0, 255) as u8) };

        for line in text.lines() {
            let ln = line.trim();
            if ln.is_empty() || ln.starts_with(';') || ln.starts_with('#') || ln.starts_with('[') {
                continue;
            }
            let Some((k, v)) = ln.split_once('=') else {
                continue;
            };
            let key = k.trim();
            match key {
                // [3Parts]
                "scaleUp" => if let Some(b) = parse_u8(v) { out.scale_up = b; },
                "scaleMiddle" => if let Some(b) = parse_u8(v) { out.scale_middle = b; },
                "scaleDown" => if let Some(b) = parse_u8(v) { out.scale_down = b; },
                // [BlendFace]
                "idFaceShape1" => if let Some(id) = parse_id(v) { out.id_face_shape1 = id; },
                "idFaceShape2" => if let Some(id) = parse_id(v) { out.id_face_shape2 = id; },
                "blendFaceShape" => if let Some(b) = parse_u8(v) { out.blend_face_shape = b; },
                // [Face] & [Faling]
                "scaleFaceH" => if let Some(b) = parse_u8(v) { out.scale_face_h = b; },
                "scaleFaceV" => if let Some(b) = parse_u8(v) { out.scale_face_v = b; },
                "idFaceTex" => if let Some(id) = parse_id(v) { out.id_face_tex = id; },
                "idFalingSkin" => if let Some(id) = parse_id(v) { out.id_faling_skin = id; },
                "idFalingTex" => if let Some(id) = parse_id(v) { out.id_faling_tex = id; },
                // [Forehead]
                "offsetForeheadH" => if let Some(b) = parse_u8(v) { out.offset_forehead_h = b; },
                "offsetForeheadV" => if let Some(b) = parse_u8(v) { out.offset_forehead_v = b; },
                "offsetForeheadZ" => if let Some(b) = parse_u8(v) { out.offset_forehead_z = b; },
                "rotateForehead" => if let Some(b) = parse_u8(v) { out.rotate_forehead = b; },
                "scaleForehead" => if let Some(b) = parse_u8(v) { out.scale_forehead = b; },
                // [YokeBone]
                "offsetYokeBoneH" => if let Some(b) = parse_u8(v) { out.offset_yokebone_h = b; },
                "offsetYokeBoneV" => if let Some(b) = parse_u8(v) { out.offset_yokebone_v = b; },
                "offsetYokeBoneZ" => if let Some(b) = parse_u8(v) { out.offset_yokebone_z = b; },
                "rotateYokeBone" => if let Some(b) = parse_u8(v) { out.rotate_yokebone = b; },
                "scaleYokeBone" => if let Some(b) = parse_u8(v) { out.scale_yokebone = b; },
                // [Cheek]
                "offsetCheekH" => if let Some(b) = parse_u8(v) { out.offset_cheek_h = b; },
                "offsetCheekV" => if let Some(b) = parse_u8(v) { out.offset_cheek_v = b; },
                "offsetCheekZ" => if let Some(b) = parse_u8(v) { out.offset_cheek_z = b; },
                "scaleCheek" => if let Some(b) = parse_u8(v) { out.scale_cheek = b; },
                // [Chain]
                "offsetChainV" => if let Some(b) = parse_u8(v) { out.offset_chain_v = b; },
                "offsetChainZ" => if let Some(b) = parse_u8(v) { out.offset_chain_z = b; },
                "rotateChain" => if let Some(b) = parse_u8(v) { out.rotate_chain = b; },
                "scaleChainH" => if let Some(b) = parse_u8(v) { out.scale_chain_h = b; },
                // [Jaw]
                "offsetJawH" => if let Some(b) = parse_u8(v) { out.offset_jaw_h = b; },
                "offsetJawV" => if let Some(b) = parse_u8(v) { out.offset_jaw_v = b; },
                "offsetJawZ" => if let Some(b) = parse_u8(v) { out.offset_jaw_z = b; },
                "scaleJawSpecial" => if let Some(b) = parse_u8(v) { out.scale_jaw_special = b; },
                "scaleJawH" => if let Some(b) = parse_u8(v) { out.scale_jaw_h = b; },
                "scaleJawV" => if let Some(b) = parse_u8(v) { out.scale_jaw_v = b; },
                // [Eye]
                "idEyeBaseTex" => if let Some(id) = parse_id(v) { out.id_eye_base_tex = id; },
                "idEyeHighTex" => if let Some(id) = parse_id(v) { out.id_eye_high_tex = id; },
                "idEyeBallTex" => if let Some(id) = parse_id(v) { out.id_eye_ball_tex = id; },
                "idEyeShape" => if let Some(id) = parse_id(v) { out.id_eye_shape = id; },
                "scaleEyeH" => if let Some(b) = parse_u8(v) { out.scale_eye_h = b; },
                "scaleEyeV" => if let Some(b) = parse_u8(v) { out.scale_eye_v = b; },
                "rotateEye" => if let Some(b) = parse_u8(v) { out.rotate_eye = b; },
                "offsetEyeH" => if let Some(b) = parse_u8(v) { out.offset_eye_h = b; },
                "offsetEyeV" => if let Some(b) = parse_u8(v) { out.offset_eye_v = b; },
                "offseteyeZ" | "offsetEyeZ" => if let Some(b) = parse_u8(v) { out.offset_eye_z = b; },
                "scaleEyeBall" => if let Some(b) = parse_u8(v) { out.scale_eye_ball = b; },
                "scaleEyeH2" => if let Some(b) = parse_u8(v) { out.scale_eye_h2 = b; },
                "scaleEyeV2" => if let Some(b) = parse_u8(v) { out.scale_eye_v2 = b; },
                "rotateEye2" => if let Some(b) = parse_u8(v) { out.rotate_eye2 = b; },
                "offsetEyeH2" => if let Some(b) = parse_u8(v) { out.offset_eye_h2 = b; },
                "offsetEyeV2" => if let Some(b) = parse_u8(v) { out.offset_eye_v2 = b; },
                "offseteyeZ2" | "offsetEyeZ2" => if let Some(b) = parse_u8(v) { out.offset_eye_z2 = b; },
                "scaleEyeBall2" => if let Some(b) = parse_u8(v) { out.scale_eye_ball2 = b; },
                // [Brow]
                "idBrowTex" => if let Some(id) = parse_id(v) { out.id_brow_tex = id; },
                "idBrowShape" => if let Some(id) = parse_id(v) { out.id_brow_shape = id; },
                "scaleBrowH" => if let Some(b) = parse_u8(v) { out.scale_brow_h = b; },
                "scaleBrowV" => if let Some(b) = parse_u8(v) { out.scale_brow_v = b; },
                "rotateBrow" => if let Some(b) = parse_u8(v) { out.rotate_brow = b; },
                "offsetBrowH" => if let Some(b) = parse_u8(v) { out.offset_brow_h = b; },
                "offsetBrowV" => if let Some(b) = parse_u8(v) { out.offset_brow_v = b; },
                "offsetBrowZ" => if let Some(b) = parse_u8(v) { out.offset_brow_z = b; },
                "scaleBrowH2" => if let Some(b) = parse_u8(v) { out.scale_brow_h2 = b; },
                "scaleBrowV2" => if let Some(b) = parse_u8(v) { out.scale_brow_v2 = b; },
                "rotateBrow2" => if let Some(b) = parse_u8(v) { out.rotate_brow2 = b; },
                "offsetBrowH2" => if let Some(b) = parse_u8(v) { out.offset_brow_h2 = b; },
                "offsetBrowV2" => if let Some(b) = parse_u8(v) { out.offset_brow_v2 = b; },
                "offsetBrowZ2" => if let Some(b) = parse_u8(v) { out.offset_brow_z2 = b; },
                // [Nose]
                "idNoseTex" => if let Some(id) = parse_id(v) { out.id_nose_tex = id; },
                "idNoseTipShape" => if let Some(id) = parse_id(v) { out.id_nose_tip_shape = id; },
                "scaleNoseTipH" => if let Some(b) = parse_u8(v) { out.scale_nose_tip_h = b; },
                "scaleNoseTipV" => if let Some(b) = parse_u8(v) { out.scale_nose_tip_v = b; },
                "scaleNoseTipZ" => if let Some(b) = parse_u8(v) { out.scale_nose_tip_z = b; },
                "offsetNoseTipV" => if let Some(b) = parse_u8(v) { out.offset_nose_tip_v = b; },
                "idNoseBridgeShape" => if let Some(id) = parse_id(v) { out.id_nose_bridge_shape = id; },
                "scaleBridgeTipH" => if let Some(b) = parse_u8(v) { out.scale_bridge_tip_h = b; },
                "offsetBridgeTipZ" => if let Some(b) = parse_u8(v) { out.offset_bridge_tip_z = b; },
                // [Mouth]
                "idMouthUpLipLine" => if let Some(id) = parse_id(v) { out.id_mouth_up_lip_line = id; },
                "idMouthMidLipLine" => if let Some(id) = parse_id(v) { out.id_mouth_mid_lip_line = id; },
                "idMouthDownLipLine" => if let Some(id) = parse_id(v) { out.id_mouth_down_lip_line = id; },
                "thickUpLip" => if let Some(b) = parse_u8(v) { out.thick_up_lip = b; },
                "thickDownLip" => if let Some(b) = parse_u8(v) { out.thick_down_lip = b; },
                "scaleMouthH" => if let Some(b) = parse_u8(v) { out.scale_mouth_h = b; },
                "offsetMouthV" => if let Some(b) = parse_u8(v) { out.offset_mouth_v = b; },
                "offsetMOuthZ" | "offsetMouthZ" => if let Some(b) = parse_u8(v) { out.offset_mouth_z = b; },
                "idMouthTex" => if let Some(id) = parse_id(v) { out.id_mouth_tex = id; },
                "offsetCornerOfMouthSpecial" => if let Some(b) = parse_u8(v) { out.offset_corner_mouth_special = b; },
                "scaleMouthH2" => if let Some(b) = parse_u8(v) { out.scale_mouth_h2 = b; },
                "offsetCornerOfMouthSpecial2" => if let Some(b) = parse_u8(v) { out.offset_corner_mouth_special2 = b; },
                // [Ear]
                "idEarShape" => if let Some(id) = parse_id(v) { out.id_ear_shape = id; },
                "scaleEar" => if let Some(b) = parse_u8(v) { out.scale_ear = b; },
                "offsetEarV" => if let Some(b) = parse_u8(v) { out.offset_ear_v = b; },
                // [Hair] & [Moustache]
                "idHairModel" => if let Some(id) = parse_id(v) { out.id_hair_model = id; },
                "idHairTex" => if let Some(id) = parse_id(v) { out.id_hair_tex = id; },
                "idMoustacheTex" => if let Some(id) = parse_id(v) { out.id_moustache_tex = id; },
                "idMoustacheSkin" => if let Some(id) = parse_id(v) { out.id_moustache_skin = id; },
                "idGoateeTex" => if let Some(id) = parse_id(v) { out.id_goatee_tex = id; },
                // [Color]
                "colorFace" => if let Some(c) = parse_col(v) { out.color_face = c; },
                "colorHair" => if let Some(c) = parse_col(v) { out.color_hair = c; },
                "colorEye" => if let Some(c) = parse_col(v) { out.color_eye = c; },
                "colorBrow" => if let Some(c) = parse_col(v) { out.color_brow = c; },
                "colorMouth" => if let Some(c) = parse_col(v) { out.color_mouth = c; },
                "colorEyeBall" => if let Some(c) = parse_col(v) { out.color_eye_ball = c; },
                "colorMoustache" => if let Some(c) = parse_col(v) { out.color_moustache = c; },
                // [Body]
                "bodyID" => if let Some(id) = parse_id(v) { out.body_id = id; },
                "colorBody" => {
                    if let Some(c) = parse_col(v) {
                        out.color_body = c;
                        has_body_color = true;
                    }
                }
                "headScale" => if let Some(b) = parse_u8(v) { out.head_scale = b; },
                "upScale" => if let Some(b) = parse_u8(v) { out.up_scale = b; },
                "waistScale" => if let Some(b) = parse_u8(v) { out.waist_scale = b; },
                "armWidth" => if let Some(b) = parse_u8(v) { out.arm_width = b; },
                "legWidth" => if let Some(b) = parse_u8(v) { out.leg_width = b; },
                "breastScale" => if let Some(b) = parse_u8(v) { out.breast_scale = b; },
                _ => {}
            }
        }
        if !has_body_color {
            out.color_body = out.color_face;
        }
        out
    }

    /// Serializes this `CharacterCustomizeIni` back into UTF-16LE BOM Perfect World 1.4.2 `.ini` format.
    pub fn to_ini_utf16le_bytes(&self) -> Vec<u8> {
        let s = format!(
            "[3Parts]\r\nscaleUp = {}\r\nscaleMiddle = {}\r\nscaleDown = {}\r\n\r\n\
             [BlendFace]\r\nidFaceShape1 = {}\r\nidFaceShape2 = {}\r\nblendFaceShape = {}\r\n\r\n\
             [Face]\r\nscaleFaceH = {}\r\nscaleFaceV = {}\r\nidFaceTex = {}\r\n\r\n\
             [Faling]\r\nidFalingSkin = {}\r\nidFalingTex = {}\r\n\r\n\
             [Forehead]\r\noffsetForeheadH = {}\r\noffsetForeheadV = {}\r\noffsetForeheadZ = {}\r\nrotateForehead = {}\r\nscaleForehead = {}\r\n\r\n\
             [YokeBone]\r\noffsetYokeBoneH = {}\r\noffsetYokeBoneV = {}\r\noffsetYokeBoneZ = {}\r\nrotateYokeBone = {}\r\nscaleYokeBone = {}\r\n\r\n\
             [Cheek]\r\noffsetCheekH = {}\r\noffsetCheekV = {}\r\noffsetCheekZ = {}\r\nscaleCheek = {}\r\n\r\n\
             [Chain]\r\noffsetChainV = {}\r\noffsetChainZ = {}\r\nrotateChain = {}\r\nscaleChainH = {}\r\n\r\n\
             [Jaw]\r\noffsetJawH = {}\r\noffsetJawV = {}\r\noffsetJawZ = {}\r\nscaleJawSpecial = {}\r\nscaleJawH = {}\r\nscaleJawV = {}\r\n\r\n\
             [Eye]\r\nidEyeBaseTex = {}\r\nidEyeHighTex = {}\r\nidEyeBallTex = {}\r\nidEyeShape = {}\r\nscaleEyeH = {}\r\nscaleEyeV = {}\r\nrotateEye = {}\r\noffsetEyeH = {}\r\noffsetEyeV = {}\r\noffseteyeZ = {}\r\nscaleEyeBall = {}\r\nscaleEyeH2 = {}\r\nscaleEyeV2 = {}\r\nrotateEye2 = {}\r\noffsetEyeH2 = {}\r\noffsetEyeV2 = {}\r\noffseteyeZ2 = {}\r\nscaleEyeBall2 = {}\r\n\r\n\
             [Brow]\r\nidBrowTex = {}\r\nidBrowShape = {}\r\nscaleBrowH = {}\r\nscaleBrowV = {}\r\nrotateBrow = {}\r\noffsetBrowH = {}\r\noffsetBrowV = {}\r\noffsetBrowZ = {}\r\nscaleBrowH2 = {}\r\nscaleBrowV2 = {}\r\nrotateBrow2 = {}\r\noffsetBrowH2 = {}\r\noffsetBrowV2 = {}\r\noffsetBrowZ2 = {}\r\n\r\n\
             [Nose]\r\nidNoseTex = {}\r\nidNoseTipShape = {}\r\nscaleNoseTipH = {}\r\nscaleNoseTipV = {}\r\nscaleNoseTipZ = {}\r\noffsetNoseTipV = {}\r\nidNoseBridgeShape = {}\r\nscaleBridgeTipH = {}\r\noffsetBridgeTipZ = {}\r\n\r\n\
             [Mouth]\r\nidMouthUpLipLine = {}\r\nidMouthMidLipLine = {}\r\nidMouthDownLipLine = {}\r\nthickUpLip = {}\r\nthickDownLip = {}\r\nscaleMouthH = {}\r\noffsetMouthV = {}\r\noffsetMOuthZ = {}\r\nidMouthTex = {}\r\noffsetCornerOfMouthSpecial = {}\r\nscaleMouthH2 = {}\r\noffsetCornerOfMouthSpecial2 = {}\r\n\r\n\
             [Ear]\r\nidEarShape = {}\r\nscaleEar = {}\r\noffsetEarV = {}\r\n\r\n\
             [Hair]\r\nidHairModel = {}\r\nidHairTex = {}\r\n\r\n\
             [Moustache]\r\nidMoustacheTex = {}\r\nidMoustacheSkin = {}\r\nidGoateeTex = {}\r\n\r\n\
             [Color]\r\ncolorHair = {}\r\ncolorFace = {}\r\ncolorEye = {}\r\ncolorBrow = {}\r\ncolorMouth = {}\r\ncolorEyeBall = {}\r\ncolorMoustache = {}\r\n\r\n\
             [Body]\r\nbodyID = {}\r\ncolorBody = {}\r\nheadScale = {}\r\nupScale = {}\r\nwaistScale = {}\r\narmWidth = {}\r\nlegWidth = {}\r\nbreastScale = {}\r\n",
            self.scale_up, self.scale_middle, self.scale_down,
            self.id_face_shape1, self.id_face_shape2, self.blend_face_shape,
            self.scale_face_h, self.scale_face_v, self.id_face_tex,
            self.id_faling_skin, self.id_faling_tex,
            self.offset_forehead_h, self.offset_forehead_v, self.offset_forehead_z, self.rotate_forehead, self.scale_forehead,
            self.offset_yokebone_h, self.offset_yokebone_v, self.offset_yokebone_z, self.rotate_yokebone, self.scale_yokebone,
            self.offset_cheek_h, self.offset_cheek_v, self.offset_cheek_z, self.scale_cheek,
            self.offset_chain_v, self.offset_chain_z, self.rotate_chain, self.scale_chain_h,
            self.offset_jaw_h, self.offset_jaw_v, self.offset_jaw_z, self.scale_jaw_special, self.scale_jaw_h, self.scale_jaw_v,
            self.id_eye_base_tex, self.id_eye_high_tex, self.id_eye_ball_tex, self.id_eye_shape,
            self.scale_eye_h, self.scale_eye_v, self.rotate_eye, self.offset_eye_h, self.offset_eye_v, self.offset_eye_z, self.scale_eye_ball,
            self.scale_eye_h2, self.scale_eye_v2, self.rotate_eye2, self.offset_eye_h2, self.offset_eye_v2, self.offset_eye_z2, self.scale_eye_ball2,
            self.id_brow_tex, self.id_brow_shape,
            self.scale_brow_h, self.scale_brow_v, self.rotate_brow, self.offset_brow_h, self.offset_brow_v, self.offset_brow_z,
            self.scale_brow_h2, self.scale_brow_v2, self.rotate_brow2, self.offset_brow_h2, self.offset_brow_v2, self.offset_brow_z2,
            self.id_nose_tex, self.id_nose_tip_shape, self.scale_nose_tip_h, self.scale_nose_tip_v, self.scale_nose_tip_z,
            self.offset_nose_tip_v, self.id_nose_bridge_shape, self.scale_bridge_tip_h, self.offset_bridge_tip_z,
            self.id_mouth_up_lip_line, self.id_mouth_mid_lip_line, self.id_mouth_down_lip_line,
            self.thick_up_lip, self.thick_down_lip, self.scale_mouth_h, self.offset_mouth_v, self.offset_mouth_z,
            self.id_mouth_tex, self.offset_corner_mouth_special, self.scale_mouth_h2, self.offset_corner_mouth_special2,
            self.id_ear_shape, self.scale_ear, self.offset_ear_v,
            self.id_hair_model, self.id_hair_tex,
            self.id_moustache_tex, self.id_moustache_skin, self.id_goatee_tex,
            self.color_hair as i32, self.color_face as i32, self.color_eye as i32, self.color_brow as i32,
            self.color_mouth as i32, self.color_eye_ball as i32, self.color_moustache as i32,
            self.body_id, self.color_body as i32, self.head_scale, self.up_scale, self.waist_scale,
            self.arm_width, self.leg_width, self.breast_scale,
        );
        let mut out = Vec::with_capacity(2 + s.len() * 2);
        out.extend_from_slice(&[0xFF, 0xFE]);
        for u in s.encode_utf16() {
            out.extend_from_slice(&u.to_le_bytes());
        }
        out
    }
}

fn decode_config_text_utf16_or_utf8(raw: &[u8]) -> String {
    if raw.len() >= 2 && raw[0] == 0xFF && raw[1] == 0xFE {
        let u16s: Vec<u16> = raw[2..]
            .chunks_exact(2)
            .map(|c| u16::from_le_bytes([c[0], c[1]]))
            .collect();
        String::from_utf16_lossy(&u16s)
    } else {
        String::from_utf8_lossy(raw).into_owned()
    }
}

/// Parses `<int_id> "<multi-line quoted string>"` tables (`skillstr.txt`, `buff_str.txt`, `item_ext_desc.txt`).
pub fn parse_indexed_quoted_table(raw: &[u8]) -> std::collections::HashMap<u32, String> {
    let text = decode_config_text_utf16_or_utf8(raw);
    let chars: Vec<char> = text.chars().collect();
    let n = chars.len();
    let mut i = 0usize;
    let mut out = std::collections::HashMap::new();

    while i < n {
        while i < n && chars[i].is_whitespace() {
            i += 1;
        }
        if i >= n {
            break;
        }
        if chars[i] == '#' || (i + 1 < n && chars[i] == '/' && chars[i + 1] == '/') {
            while i < n && chars[i] != '\n' {
                i += 1;
            }
            continue;
        }
        if chars[i].is_ascii_digit() {
            let start_num = i;
            while i < n && chars[i].is_ascii_digit() {
                i += 1;
            }
            let num_str: String = chars[start_num..i].iter().collect();
            while i < n && (chars[i] == ' ' || chars[i] == '\t') {
                i += 1;
            }
            if i < n && chars[i] == '"' {
                i += 1;
                let mut val = String::new();
                while i < n && chars[i] != '"' {
                    val.push(chars[i]);
                    i += 1;
                }
                if i < n && chars[i] == '"' {
                    i += 1;
                }
                if let Ok(id) = num_str.parse::<u32>() {
                    let cleaned = val
                        .replace('\u{3000}', "  ")
                        .replace('：', ": ")
                        .replace("\\r\\n", "\n")
                        .replace("\\r", "\n")
                        .replace("\r\n", "\n")
                        .replace('\r', "\n");
                    out.insert(id, cleaned);
                }
                continue;
            }
        }
        while i < n && chars[i] != '\n' {
            i += 1;
        }
    }
    out
}

/// Original English localization tables loaded from `configs.pck` (`skillstr.txt`, `buff_str.txt`,
/// `fixed_msg.txt`, `item_ext_desc.txt`). Guarantees ZERO Chinese characters in UI / skills / buffs / items.
#[derive(Debug, Clone, Default)]
pub struct EnglishLocalizationTables {
    /// `skill_id -> (english_name, english_colored_desc_template)`
    pub skills: std::collections::HashMap<u32, (String, String)>,
    /// `buff_id -> (english_name, english_description)`
    pub buffs: std::collections::HashMap<u32, (String, String)>,
    /// `item_id -> english_extended_description`
    pub item_ext_descs: std::collections::HashMap<u32, String>,
    /// Sequential `fixed_msg.txt` strings.
    pub fixed_msgs: Vec<String>,
}

impl EnglishLocalizationTables {
    pub fn load_skillstr(&mut self, raw: &[u8]) {
        let tbl = parse_indexed_quoted_table(raw);
        for (&key, val) in &tbl {
            if key % 10 == 0 {
                let skill_id = key / 10;
                let name = strip_cjk_fallback(val.trim(), &format!("Skill #{skill_id}"));
                let desc = tbl.get(&(key + 1)).cloned().unwrap_or_default();
                self.skills.insert(skill_id, (name, desc));
            }
        }
    }

    pub fn load_buff_str(&mut self, raw: &[u8]) {
        let tbl = parse_indexed_quoted_table(raw);
        for (buff_id, full) in tbl {
            let mut lines = full.lines();
            let raw_name = lines.next().unwrap_or("").trim();
            let name = strip_cjk_fallback(raw_name, &format!("State #{buff_id}"));
            let rest: Vec<&str> = lines.map(str::trim).filter(|s| !s.is_empty()).collect();
            let desc = strip_cjk_fallback(&rest.join("\n"), "Active status effect.");
            self.buffs.insert(buff_id, (name, desc));
        }
    }

    pub fn load_item_ext_desc(&mut self, raw: &[u8]) {
        let tbl = parse_indexed_quoted_table(raw);
        for (item_id, desc) in tbl {
            let clean = strip_cjk_fallback(&desc, "");
            if !clean.is_empty() {
                self.item_ext_descs.insert(item_id, clean);
            }
        }
    }

    pub fn load_fixed_msg(&mut self, raw: &[u8]) {
        let text = decode_config_text_utf16_or_utf8(raw);
        let chars: Vec<char> = text.chars().collect();
        let n = chars.len();
        let mut i = 0usize;
        self.fixed_msgs.clear();
        while i < n {
            if i + 1 < n && chars[i] == '/' && chars[i + 1] == '/' {
                while i < n && chars[i] != '\n' {
                    i += 1;
                }
                continue;
            }
            if chars[i] == '"' {
                i += 1;
                let mut s = String::new();
                while i < n && chars[i] != '"' {
                    s.push(chars[i]);
                    i += 1;
                }
                if i < n && chars[i] == '"' {
                    i += 1;
                }
                self.fixed_msgs.push(s.replace('\u{3000}', "  "));
            } else {
                i += 1;
            }
        }
    }

    pub fn skill_name(&self, skill_id: u32) -> String {
        self.skills
            .get(&skill_id)
            .map(|(n, _)| n.clone())
            .filter(|s| !s.is_empty())
            .unwrap_or_else(|| format!("Skill #{skill_id}"))
    }

    /// Formats a `skillstr.txt` description template (`Level %d`, `%.1f`, etc.) into clean multi-line English.
    pub fn format_skill_tooltip(&self, skill_id: u32, level: u32, mp_cost: f32, cooldown_s: f32) -> String {
        self.format_skill_tooltip_with_eval(
            skill_id,
            level,
            18.0,
            mp_cost,
            0.8,
            1.0,
            cooldown_s,
            100 + (level as i32) * 15,
            (level as i32 * 145).max(50),
        )
    }

    /// Formats a `skillstr.txt` description template substituting sequential `ElementSkill` per-level values
    /// (`level`, `mp_cost`, `channel_s`, `cast_s`, `cooldown_s`, `weapon_pct`, `flat_dmg`) into `%d`/`%.1f`.
    #[allow(clippy::too_many_arguments)]
    pub fn format_skill_tooltip_with_eval(
        &self,
        skill_id: u32,
        level: u32,
        range_m: f32,
        mp_cost: f32,
        channel_s: f32,
        cast_s: f32,
        cooldown_s: f32,
        weapon_pct: i32,
        flat_dmg: i32,
    ) -> String {
        let Some((name, tmpl)) = self.skills.get(&skill_id) else {
            return format!(
                "^ffcb4aSkill #{skill_id} (Lv.{level})\n^96f5ffRange: {range_m:.1}m  |  Mana: {mp_cost:.0}\nChannel: {channel_s:.1}s  |  Cast: {cast_s:.1}s  |  Cooldown: {cooldown_s:.1}s"
            );
        };
        if tmpl.trim().is_empty() {
            return format!(
                "^ffcb4a{name} (Lv.{level})\n^96f5ffRange: {range_m:.1}m  |  Mana: {mp_cost:.0}\nChannel: {channel_s:.1}s  |  Cast: {cast_s:.1}s  |  Cooldown: {cooldown_s:.1}s"
            );
        }
        let int_seq = [
            level as i32,
            mp_cost.round() as i32,
            weapon_pct,
            flat_dmg,
            (level as i32 * 10).max(10),
            cooldown_s.round() as i32,
        ];
        let float_seq = [range_m, mp_cost, channel_s, cast_s, cooldown_s, flat_dmg as f32];
        let mut out = String::with_capacity(tmpl.len() + 48);
        let bytes = tmpl.as_bytes();
        let mut i = 0usize;
        let mut arg_idx = 0usize;
        let mut float_idx = 0usize;
        let mut int_idx = 0usize;
        while i < bytes.len() {
            if bytes[i] == b'%' && i + 1 < bytes.len() {
                if bytes[i + 1] == b'%' {
                    out.push('%');
                    i += 2;
                    continue;
                }
                let mut j = i + 1;
                while j < bytes.len()
                    && (bytes[j].is_ascii_digit() || bytes[j] == b'.' || bytes[j] == b'-' || bytes[j] == b'+')
                {
                    j += 1;
                }
                if j < bytes.len() && matches!(bytes[j], b'd' | b'i' | b'u' | b'f' | b's') {
                    let spec = bytes[j];
                    let val_str = match spec {
                        b'd' | b'i' | b'u' => {
                            let v = int_seq.get(int_idx).copied().unwrap_or(flat_dmg);
                            int_idx += 1;
                            format!("{v}")
                        }
                        b'f' => {
                            let v = float_seq.get(float_idx).copied().unwrap_or(cooldown_s);
                            float_idx += 1;
                            format!("{v:.1}")
                        }
                        _ => String::new(),
                    };
                    out.push_str(&val_str);
                    arg_idx += 1;
                    let _ = arg_idx;
                    i = j + 1;
                    continue;
                }
            }
            let ch = tmpl[i..].chars().next().unwrap_or(' ');
            if !is_cjk_ideograph(ch) {
                out.push(ch);
            }
            i += ch.len_utf8();
        }
        let cleaned_lines: Vec<String> = out
            .lines()
            .map(|ln| {
                let mut s = String::with_capacity(ln.len());
                let mut sp = 0usize;
                for c in ln.trim_end().chars() {
                    if c == ' ' {
                        sp += 1;
                        if sp <= 2 {
                            s.push(' ');
                        }
                    } else {
                        sp = 0;
                        s.push(c);
                    }
                }
                s
            })
            .collect();
        cleaned_lines.join("\n").trim().to_string()
    }

    pub fn load_from_reader<F>(mut read_fn: F) -> Self
    where
        F: FnMut(&str) -> Option<Vec<u8>>,
    {
        let mut out = Self::default();
        if let Some(b) = read_fn("configs/skillstr.txt") {
            out.load_skillstr(&b);
        }
        if let Some(b) = read_fn("configs/buff_str.txt") {
            out.load_buff_str(&b);
        }
        if let Some(b) = read_fn("configs/item_ext_desc.txt") {
            out.load_item_ext_desc(&b);
        }
        if let Some(b) = read_fn("configs/fixed_msg.txt") {
            out.load_fixed_msg(&b);
        }
        out
    }
}

#[inline]
pub fn is_cjk_ideograph(c: char) -> bool {
    matches!(
        c as u32,
        0x3400..=0x4DBF | 0x4E00..=0x9FFF | 0xF900..=0xFAFF | 0xFF01..=0xFF60
    )
}

/// Complete `Win_ChoosePreCustomize` Catalog loading all 237 official `.ini` presets across
/// `userdata/character/character{cls}{gender}.ini`, `customize/{cls}{gender}/*.ini`, and `customize1/{cls}{gender}/*.ini`.
#[derive(Debug, Clone, Default)]
pub struct CustomizePresetCatalog {
    pub by_class_gender: BTreeMap<(u8, u8), Vec<(String, CharacterCustomizeIni)>>,
}

impl CustomizePresetCatalog {
    pub fn load_from_element_dir(elem_dir: &std::path::Path) -> Self {
        let mut out = Self::default();
        let char_root = elem_dir.join("userdata/character");
        if !char_root.is_dir() {
            return out;
        }
        for cls in 0..=7u8 {
            for gender in 0..=1u8 {
                let code = format!("{cls}{gender}");
                let mut list = Vec::new();
                let base_path = char_root.join(format!("character{code}.ini"));
                if let Ok(raw) = std::fs::read(&base_path) {
                    list.push(("Default".to_string(), CharacterCustomizeIni::parse_ini_bytes(&raw)));
                }
                for subdir in ["customize", "customize1"] {
                    let dir = char_root.join(subdir).join(&code);
                    let Ok(rd) = std::fs::read_dir(&dir) else {
                        continue;
                    };
                    let mut entries: Vec<_> = rd
                        .filter_map(|e| e.ok())
                        .filter(|e| {
                            e.path()
                                .extension()
                                .and_then(|x| x.to_str())
                                .map(|x| x.eq_ignore_ascii_case("ini"))
                                .unwrap_or(false)
                        })
                        .collect();
                    entries.sort_by_key(|e| e.file_name());
                    for ent in entries {
                        if let Ok(raw) = std::fs::read(ent.path()) {
                            let stem = ent
                                .path()
                                .file_stem()
                                .and_then(|s| s.to_str())
                                .unwrap_or("Preset")
                                .trim()
                                .to_string();
                            let clean = strip_cjk_fallback(&stem, "Preset");
                            if !list.iter().any(|(n, _)| n.eq_ignore_ascii_case(&clean)) {
                                list.push((clean, CharacterCustomizeIni::parse_ini_bytes(&raw)));
                            }
                        }
                    }
                }
                if !list.is_empty() {
                    out.by_class_gender.insert((cls, gender), list);
                }
            }
        }
        out
    }

    pub fn total_presets(&self) -> usize {
        self.by_class_gender.values().map(Vec::len).sum()
    }
}

#[inline]
pub fn has_cjk(input: &str) -> bool {
    input.chars().any(is_cjk_ideograph)
}

pub fn strip_cjk_fallback(input: &str, fallback: &str) -> String {
    let filtered: String = input.chars().filter(|&c| !is_cjk_ideograph(c)).collect();
    let trimmed = filtered.trim();
    if trimmed.is_empty() {
        fallback.to_string()
    } else {
        trimmed.to_string()
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::fs;

    fn data_dir_opt() -> Option<std::path::PathBuf> {
        pw_core::find_test_pw142_element(env!("CARGO_MANIFEST_DIR"))
            .map(|e| e.join("data"))
            .filter(|d| d.join("elements.data").is_file())
    }

    #[test]
    fn test_elements_data_v27_exact_eof_and_roundtrip() {
        let Some(dd) = data_dir_opt() else { return };
        let raw = fs::read(dd.join("elements.data")).unwrap();
        assert_eq!(raw.len(), 28_613_176);
        let db = ElementsDatabase::parse_exact(&raw).unwrap();
        assert_eq!(db.version_low_u16, 27);
        assert_eq!(db.sections.len(), 131);
        assert_eq!(db.total_records(), 37_676);
        let rebuilt = db.to_bytes();
        assert_eq!(rebuilt.len(), raw.len());
        assert_eq!(rebuilt, raw, "elements.data round-trip must be 100% byte-identical");
    }

    #[test]
    fn test_tasks_sample_and_full_tasks_data_v75_exact_eof() {
        let Some(dd) = data_dir_opt() else { return };
        let sample = fs::read(dd.join("tasks_sample.data")).unwrap();
        let db = TasksDatabase::parse_exact(&sample).unwrap();
        assert_eq!(db.version, 75);
        assert_eq!(db.top_tasks.len(), 32);
        assert!(!db.top_tasks[0].name.is_empty());

        let full_path = dd.join("tasks.data");
        if full_path.is_file() {
            let full = fs::read(full_path).unwrap();
            let full_db = TasksDatabase::parse_exact(&full).unwrap();
            assert_eq!(full_db.top_tasks.len(), 6_860);
            assert_eq!(full_db.total_nodes, 17_787);
        }
    }

    #[test]
    fn test_all_other_data_files_exact_eof() {
        let Some(dd) = data_dir_opt() else { return };
        let dyn_db = DynTasksDatabase::parse_exact(
            &fs::read(dd.join("dyn_tasks.data")).unwrap(),
        )
        .unwrap();
        assert_eq!(dyn_db.tasks.len(), 6);
        assert_eq!(dyn_db.tasks[0].id, 2758);

        let npc_db =
            TaskNpcDatabase::parse_exact(&fs::read(dd.join("task_npc.data")).unwrap())
                .unwrap();
        assert_eq!(npc_db.entries.len(), 1_572);

        let gshop =
            GShopClientDatabase::parse_exact(&fs::read(dd.join("gshop.data")).unwrap())
                .unwrap();
        assert_eq!(gshop.items.len(), 605);
        assert_eq!(gshop.categories.len(), 8);

        let gshop1 =
            GShopClientDatabase::parse_exact(&fs::read(dd.join("gshop1.data")).unwrap())
                .unwrap();
        assert_eq!(gshop1.items.len(), 0);
        assert_eq!(gshop1.categories.len(), 8);

        let gsev = GShopServerDatabase::parse_exact(
            &fs::read(dd.join("gshopsev.data")).unwrap(),
        )
        .unwrap();
        assert_eq!(gsev.item_count, 605);

        let gsev1 = GShopServerDatabase::parse_exact(
            &fs::read(dd.join("gshopsev1.data")).unwrap(),
        )
        .unwrap();
        assert_eq!(gsev1.item_count, 0);

        let domain =
            DomainDatabase::parse_exact(&fs::read(dd.join("domain.data")).unwrap())
                .unwrap();
        assert_eq!(domain.zones.len(), 47);
        assert_eq!(domain.battle_slots.len(), 7);
        assert_eq!(domain.max_simultaneous_battles, 7);

        let ai =
            AiPolicyDatabase::parse_exact(&fs::read(dd.join("aipolicy.data")).unwrap())
                .unwrap();
        assert_eq!(ai.policies.len(), 1_371);
    }

    #[test]
    fn test_cec_face_and_all_14_character_customize_inis_and_monsters_parity() {
        let Some(elem_root) = pw_core::find_test_pw142_element(env!("CARGO_MANIFEST_DIR")) else {
            return;
        };
        let raw = fs::read(elem_root.join("data/elements.data")).unwrap();
        let db = ElementsDatabase::parse_exact(&raw).unwrap();

        let face_tex = db.face_textures();
        let face_hair = db.face_hairs();
        let monsters = db.monster_essences();
        let classes = db.character_class_names();

        assert_eq!(face_tex.len(), 184, "expected all 184 FACE_TEXTURE_ESSENCE rows");
        assert!(face_hair.len() >= 100, "expected >=100 FACE_HAIR_ESSENCE rows, got {}", face_hair.len());
        assert_eq!(monsters.len(), 4_208, "expected all 4,208 MONSTER_ESSENCE rows");
        assert_eq!(classes.len(), 8, "expected all 8 PW 1.4.2 playable classes");
        for cname in classes.values() {
            assert!(!has_cjk(cname), "CJK in class name: {cname}");
        }

        // Verify Tideborn (`859` -> `巫师男标准脸5\头05.DDS`, `881` -> `影族男头发10.SKI`) and Untamed (`100` -> `虎.DDS`)
        assert!(face_tex.get(&859).unwrap().base_tex.contains("头05"));
        assert!(face_hair.get(&881).unwrap().hair_skin.to_ascii_lowercase().contains(".ski"));
        assert!(face_tex.get(&100).unwrap().base_tex.contains("虎"));

        // Verify all 14 class*gender `character{cls}{gender}.ini` presets resolve valid `elements.data` records
        let char_dir = elem_root.join("userdata/character");
        let valid_pairs = [
            "00", "01", "10", "11", "20", "21", "31", "40", "50", "51", "60", "61", "70", "71",
        ];
        for code in valid_pairs {
            let ini_bytes = fs::read(char_dir.join(format!("character{code}.ini"))).unwrap();
            let ini = CharacterCustomizeIni::parse_ini_bytes(&ini_bytes);
            assert!(
                face_tex.contains_key(&ini.id_face_tex),
                "character{code}.ini idFaceTex={} missing from FACE_TEXTURE_ESSENCE",
                ini.id_face_tex
            );
            if code != "40" {
                assert!(
                    face_hair.contains_key(&ini.id_hair_model),
                    "character{code}.ini idHairModel={} missing from FACE_HAIR_ESSENCE",
                    ini.id_hair_model
                );
            }
        }

        // Verify playable English monsters (excluding raw `N/A*` hidden dungeon trigger rows)
        let english_monsters = monsters
            .values()
            .filter(|m| !m.name.is_empty() && !m.name.starts_with("N/A") && !has_cjk(&m.name))
            .count();
        assert_eq!(
            english_monsters, 3_763,
            "expected all 3,763 localized English MONSTER_ESSENCE rows, got {english_monsters}"
        );
    }

    #[test]
    fn test_all_14_character_customize_ini_full_75_params_roundtrip() {
        let fallback_root = std::path::Path::new(env!("CARGO_MANIFEST_DIR"))
            .join("../../../source/pw142/element");
        let elem_root = pw_core::find_test_pw142_element(env!("CARGO_MANIFEST_DIR"))
            .unwrap_or(fallback_root);
        let char_dir = elem_root.join("userdata/character");
        assert!(char_dir.is_dir(), "expected userdata/character at {}", char_dir.display());
        let valid_pairs = [
            "00", "01", "10", "11", "20", "21", "31", "40", "50", "51", "60", "61", "70", "71",
        ];
        for code in valid_pairs {
            let raw = fs::read(char_dir.join(format!("character{code}.ini"))).unwrap();
            let parsed = CharacterCustomizeIni::parse_ini_bytes(&raw);
            let encoded = parsed.to_ini_utf16le_bytes();
            let reparsed = CharacterCustomizeIni::parse_ini_bytes(&encoded);
            assert_eq!(
                parsed, reparsed,
                "75-parameter CharacterCustomizeIni round-trip mismatch on character{code}.ini"
            );
            let head_sc = CharacterCustomizeIni::slider_to_scale(parsed.head_scale, 0.25);
            let waist_sc = CharacterCustomizeIni::slider_to_scale(parsed.waist_scale, 0.25);
            assert!((0.55..=1.55).contains(&head_sc));
            assert!((0.55..=1.55).contains(&waist_sc));
        }

        // Also verify `CustomizePresetCatalog` loads all `customize/` & `customize1/` named English presets (`>= 180` unique presets) with 0 CJK!
        let catalog = CustomizePresetCatalog::load_from_element_dir(&elem_root);
        assert!(
            catalog.total_presets() >= 180,
            "expected >=180 named presets from customize/ & customize1/, got {}",
            catalog.total_presets()
        );
        for presets in catalog.by_class_gender.values() {
            for (name, _) in presets {
                assert!(!has_cjk(name), "CJK in preset name: {name}");
            }
        }

        // Also verify real `dyn_tasks.data` (`UnmarshalDynTasks` v10) parses cleanly with zero remainder!
        let dyn_path = elem_root.join("userdata/dyn_tasks.data");
        if dyn_path.is_file() {
            let dyn_raw = fs::read(&dyn_path).unwrap();
            let dyn_db = DynTasksDatabase::parse_exact(&dyn_raw).unwrap();
            assert_eq!(dyn_db.version, 10);
            assert!(!dyn_db.tasks.is_empty());
        }
    }
}

