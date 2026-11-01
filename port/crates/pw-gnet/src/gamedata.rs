//! Build 2305 Inner `gs` Game-Data Protocol Codec (`GNET::GamedataSend`, opcode `34`).
//!
//! Disassembly-verified 1:1 against `CECGameRun::OnGameDataMess` / `CECHostPlayer::SessionProcess`
//! (`elementclient.exe` Build 2305, `S2C` jump table `0x0000..0x00C8` and `C2S` encoders `0x0000..0x0058`).

use pw_core::{PwError, PwResult};

/// Canonical Build 2305 `s2c` inner opcodes (`u16` little-endian inside `GamedataSend`).
pub mod s2c {
    pub const PLAYER_INFO_1_LIST: u16 = 0x0004;
    pub const NPC_INFO_LIST: u16 = 0x0005;
    pub const MATTER_INFO_LIST: u16 = 0x0006;
    pub const SELF_INFO_1: u16 = 0x0008;
    pub const PLAYER_ENTER_SLICE: u16 = 0x000B;
    pub const NPC_ENTER_SLICE: u16 = 0x000C;
    pub const OBJECT_LEAVE_SLICE: u16 = 0x000D;
    pub const OBJECT_NOTIFY_POS: u16 = 0x000E;
    pub const OBJECT_MOVE: u16 = 0x000F;
    pub const NPC_ENTER_WORLD: u16 = 0x0010;
    pub const PLAYER_ENTER_WORLD: u16 = 0x0011;
    pub const MATTER_ENTER_WORLD: u16 = 0x0012;
    pub const OBJECT_STOP_MOVE: u16 = 0x0013;
    pub const NPC_DEAD: u16 = 0x0014;
    pub const TEAM_MEMBER_POS: u16 = 0x0017;
    pub const SELF_ITEM_DATA: u16 = 0x001B;
    pub const TEAM_INVITE_NOTIFY: u16 = 0x001D;
    pub const TEAM_DATA: u16 = 0x001E;
    pub const TEAM_MEMBER_LEAVE: u16 = 0x0020;
    pub const NOTIFY_POS: u16 = 0x0025;
    pub const EXT_PROP: u16 = 0x0026;
    pub const ADD_EXP: u16 = 0x0027;
    pub const LEVEL_UP: u16 = 0x0028;
    pub const DAMAGE_INFO: u16 = 0x0029;
    pub const EQUIPMENT_DATA: u16 = 0x002B;
    pub const OBJECT_CAST_SKILL: u16 = 0x002E;
    pub const PLAYER_REVIVAL: u16 = 0x002F;
    pub const SKILL_DATA: u16 = 0x0030;
    pub const HOST_START_ATTACK: u16 = 0x0031;
    pub const SELECT_TARGET_RE: u16 = 0x0034;
    pub const PLAYER_PICKUP_MONEY: u16 = 0x0035;
    pub const PLAYER_PICKUP_ITEM: u16 = 0x0036;
    pub const EQUIP_ITEM: u16 = 0x0038;
    pub const NPC_GREETING: u16 = 0x0046;
    pub const BE_KILLED: u16 = 0x0047;
    pub const OBJECT_DO_EMOTE: u16 = 0x004A;
    pub const SELF_GET_MONEY: u16 = 0x0052;
    pub const TRASHBOX_DATA: u16 = 0x005A;
    pub const OBJECT_ROOT: u16 = 0x005B;
    pub const TASK_DATA: u16 = 0x0069;
    pub const GATHER_START: u16 = 0x007E;
    pub const GATHER_STOP: u16 = 0x007F;
    pub const ICON_STATE_NOTIFY: u16 = 0x008A;
    pub const CON_EMOTE_REQUEST: u16 = 0x00AD;
    pub const PET_ROOM: u16 = 0x0108;
    pub const SUMMON_PET: u16 = 0x0109;
    pub const RECALL_PET: u16 = 0x010A;
    pub const PET_HP_NOTIFY: u16 = 0x010C;
    // Extended Build 2305 (`Rising Tide`) `s2c` opcodes (`0x004D..0x0130`):
    pub const PLAYER_ENABLE_PVP: u16 = 0x004D;
    pub const PLAYER_DISABLE_PVP: u16 = 0x004E;
    pub const INVADER_RISE: u16 = 0x0050;
    pub const PARIAH_RISE: u16 = 0x0051;
    pub const TRASHBOX_OPEN: u16 = 0x0058;
    pub const TRASHBOX_CLOSE: u16 = 0x0059;
    pub const TRASHBOX_WEALTH: u16 = 0x005D;
    pub const PLAYER_OPEN_BOOTH: u16 = 0x0060;
    pub const PLAYER_CLOSE_BOOTH: u16 = 0x0061;
    pub const BOOTH_GOODS_LIST: u16 = 0x0062;
    pub const PRODUCE_START: u16 = 0x0076;
    pub const PRODUCE_ONCE: u16 = 0x0077;
    pub const PRODUCE_END: u16 = 0x0078;
    pub const REFINE_RESULT: u16 = 0x0092;
    pub const ENCHASE_RESULT: u16 = 0x0093;
    pub const IDENTIFY_RESULT: u16 = 0x0094;
    pub const FASHION_MODE: u16 = 0x009A;
    pub const PLAYER_BIND_START: u16 = 0x00A2;
    pub const PLAYER_BIND_STOP: u16 = 0x00A3;
    pub const ELF_VIGOR: u16 = 0x011A;
    pub const ELF_ENHANCE: u16 = 0x011B;
    pub const ELF_STAMINA: u16 = 0x011C;
    pub const ELF_EXP: u16 = 0x011E;
    pub const ELF_CMD_RESULT: u16 = 0x0120;
    pub const PUBLIC_QUEST_INFO: u16 = 0x0128;
    pub const PUBLIC_QUEST_RANKS: u16 = 0x0129;
}

/// Canonical Build 2305 `c2s` inner opcodes (`u16` little-endian inside `GamedataSend`).
pub mod c2s {
    pub const PLAYER_MOVE: u16 = 0x0000;
    pub const LOGOUT: u16 = 0x0001;
    pub const SELECT_TARGET: u16 = 0x0002;
    pub const NORMAL_ATTACK: u16 = 0x0003;
    pub const REVIVE_VILLAGE: u16 = 0x0004;
    pub const REVIVE_ITEM: u16 = 0x0005;
    pub const PICKUP: u16 = 0x0006;
    pub const STOP_MOVE: u16 = 0x0007;
    pub const GET_ALL_DATA: u16 = 0x0008;
    pub const GET_ITEM_INFO: u16 = 0x0009;
    pub const GET_INVENTORY: u16 = 0x000A;
    pub const MOVE_INVENTORY_ITEM: u16 = 0x000B;
    pub const DROP_INVENTORY_ITEM: u16 = 0x000C;
    pub const EXCHANGE_INVENTORY_ITEM: u16 = 0x000D;
    pub const GET_EXT_PROP: u16 = 0x000E;
    pub const EXCHANGE_EQUIP_ITEM: u16 = 0x0010;
    pub const EQUIP_ITEM: u16 = 0x0011;
    pub const MOVE_ITEM_TO_EQUIP: u16 = 0x0012;
    pub const DROP_MONEY: u16 = 0x0014;
    pub const ADD_STATUS_POINT: u16 = 0x0015;
    pub const TEAM_INVITE: u16 = 0x001B;
    pub const TEAM_AGREE_INVITE: u16 = 0x001C;
    pub const TEAM_REJECT_INVITE: u16 = 0x001D;
    pub const DO_EMOTE: u16 = 0x001E;
    pub const TEAM_LEAVE_PARTY: u16 = 0x001F;
    pub const TEAM_KICK_MEMBER: u16 = 0x0020;
    pub const HELLO_NPC: u16 = 0x0023;
    pub const USE_ITEM: u16 = 0x0024;
    pub const NPC_SEV_SERVE: u16 = 0x0025;
    pub const SERVICE_GET_CONTENT: u16 = 0x0026;
    pub const CAST_SKILL: u16 = 0x0029;
    pub const CANCEL_ACTION: u16 = 0x002A;
    pub const TOGGLE_FLY: u16 = 0x002E;
    pub const GATHER_MATERIAL: u16 = 0x0036;
    pub const SUMMON_PET: u16 = 0x0064;
    pub const RECALL_PET: u16 = 0x0065;
    pub const BANISH_PET: u16 = 0x0066;
    pub const PET_CTRL_CMD: u16 = 0x0067;
    // Extended Build 2305 (`Rising Tide`) `c2s` opcodes:
    pub const SPLIT_INVENTORY_ITEM: u16 = 0x000F;
    pub const REPAIR_ALL: u16 = 0x0027;
    pub const NPC_BUY_ITEM: u16 = 0x0028;
    pub const NPC_SELL_ITEM: u16 = 0x002B;
    pub const TOGGLE_PK_MODE: u16 = 0x0030;
    pub const TRASHBOX_DEPOSIT_MONEY: u16 = 0x0039;
    pub const TRASHBOX_WITHDRAW_MONEY: u16 = 0x003A;
    pub const TRASHBOX_EXCHANGE_ITEM: u16 = 0x003B;
    pub const OPEN_BOOTH: u16 = 0x003E;
    pub const CLOSE_BOOTH: u16 = 0x003F;
    pub const BUY_BOOTH_ITEM: u16 = 0x0041;
    pub const PRODUCE_ITEM: u16 = 0x0048;
    pub const BREAK_PRODUCE: u16 = 0x0049;
    pub const ENCHASE_EQUIP: u16 = 0x004C;
    pub const IDENTIFY_EQUIP: u16 = 0x004E;
    pub const SWITCH_FASHION_MODE: u16 = 0x0055;
    pub const PLAYER_BIND_REQUEST: u16 = 0x005A;
    pub const REFINE_EQUIP: u16 = 0x0060;
    pub const DYE_FASHION: u16 = 0x0062;
    pub const ELF_ADD_ATTRIBUTE: u16 = 0x0078;
    pub const ELF_ADD_GENIUS: u16 = 0x0079;
    pub const ELF_PLAYER_INSERT_EXP: u16 = 0x007A;
    pub const ELF_EQUIP_ITEM: u16 = 0x007B;
    pub const ELF_CHANGE_SECURE_STATUS: u16 = 0x007C;
    pub const CAST_ELF_SKILL: u16 = 0x007D;
    pub const RECHARGE_EQUIPPED_ELF: u16 = 0x007E;
    pub const AUTOLOCK_OPEN: u16 = 0x0088;
}

#[derive(Debug, Clone, PartialEq)]
pub struct GsSelfInfo1 {
    pub exp: i32,
    pub sp: i32,
    pub role_id: u32,
    pub pos: (f32, f32, f32),
    pub dir: u8,
    pub level: u16,
    pub level2: u16,
    pub hp: i32,
    pub max_hp: i32,
    pub mp: i32,
    pub max_mp: i32,
}

#[derive(Debug, Clone, PartialEq)]
pub struct GsExtProp {
    pub vitality: i32,
    pub energy: i32,
    pub strength: i32,
    pub agility: i32,
    pub max_hp: i32,
    pub max_mp: i32,
    pub hp_gen: i32,
    pub mp_gen: i32,
    pub walk_speed: f32,
    pub run_speed: f32,
    pub swim_speed: f32,
    pub flight_speed: f32,
    pub attack: i32,
    pub damage_low: i32,
    pub damage_high: i32,
    pub attack_speed: i32,
    pub attack_range: f32,
    pub damage_magic_low: i32,
    pub damage_magic_high: i32,
    pub defense: i32,
    pub armor: i32,
}

#[derive(Debug, Clone, PartialEq)]
pub struct GsNpcSliceInfo {
    pub nid: u32,
    pub tid: u32,
    pub vis_tid: u32,
    pub pos: (f32, f32, f32),
    pub dir: u8,
    pub state: u32,
}

#[derive(Debug, Clone, PartialEq)]
pub struct GsPlayerSliceInfo {
    pub cid: u32,
    pub pos: (f32, f32, f32),
    pub crc_custom: u16,
    pub dir: u8,
    pub cls: u8,
    pub state: u32,
}

#[derive(Debug, Clone, PartialEq)]
pub struct GsMatterSliceInfo {
    pub mid: u32,
    pub tid: u32,
    pub pos: (f32, f32, f32),
    pub dir0: u8,
    pub dir1: u8,
}

#[derive(Debug, Clone, PartialEq)]
pub struct GsInventorySlot {
    pub slot: u8,
    pub item_id: u32,
    pub expire_date: i32,
    pub count: u32,
    pub proc_type: u16,
}

#[derive(Debug, Clone, PartialEq, Eq)]
pub struct GsSkillEntry {
    pub skill_id: u16,
    pub level: u8,
    pub ability: u16,
}

#[derive(Debug, Clone, PartialEq)]
pub struct GsTeamMemberInfo {
    pub member_id: u32,
    pub level: u16,
    pub combat_state: u8,
    pub pk_level: u8,
    pub hp: i32,
    pub mp: i32,
    pub max_hp: i32,
    pub max_mp: i32,
}

#[derive(Debug, Clone, PartialEq)]
pub struct GsPetSlotInfo {
    pub pet_index: u8,
    pub pet_tid: u32,
    pub level: u16,
    pub hp: i32,
    pub max_hp: i32,
    pub loyalty: u16,
    pub hunger: u8,
}

#[derive(Debug, Clone, PartialEq)]
pub enum GsS2cPacket {
    SelfInfo1(GsSelfInfo1),
    NotifyPos { pos: (f32, f32, f32), world_tag: i32 },
    ExtProp(GsExtProp),
    NpcInfoList(Vec<GsNpcSliceInfo>),
    PlayerInfo1List(Vec<GsPlayerSliceInfo>),
    MatterInfoList(Vec<GsMatterSliceInfo>),
    NpcEnterSlice(GsNpcSliceInfo),
    PlayerEnterSlice(GsPlayerSliceInfo),
    ObjectLeaveSlice { id: u32 },
    ObjectMove {
        id: u32,
        dest: (f32, f32, f32),
        use_time_ms: u16,
        speed_cms: u16,
        move_mode: u8,
    },
    ObjectStopMove {
        id: u32,
        pos: (f32, f32, f32),
        speed_cms: u16,
        dir: u8,
        move_mode: u8,
    },
    SelfItemData {
        where_inv: u8,
        capacity: u8,
        items: Vec<GsInventorySlot>,
    },
    SkillData(Vec<GsSkillEntry>),
    SelectTargetRe {
        target_id: u32,
        level: u16,
        hp: i32,
        max_hp: i32,
        mp: i32,
        max_mp: i32,
    },
    ObjectCastSkill {
        caster_id: u32,
        target_id: u32,
        skill_id: u32,
        cast_time_ms: u16,
        skill_level: u8,
    },
    DamageInfo {
        attacker_id: u32,
        target_id: u32,
        damage: i32,
        flags: u8,
    },
    NpcDead { nid: u32, killer_id: u32 },
    NpcGreeting { nid: u32 },
    ObjectDoEmote { id: u32, emotion: u16 },
    IconStateNotify { id: u32, states: Vec<u16> },
    TaskData { active_bytes: usize, finished_bytes: usize },
    TeamData {
        leader_id: u32,
        team_seq: u32,
        members: Vec<GsTeamMemberInfo>,
    },
    TeamMemberPos {
        member_id: u32,
        pos: (f32, f32, f32),
        world_tag: i32,
    },
    TeamInviteNotify {
        leader_id: u32,
        team_seq: u32,
    },
    TeamMemberLeave {
        leader_id: u32,
        member_id: u32,
        reason: u16,
    },
    AddExp { exp: i32, sp: i32 },
    LevelUp { id: u32 },
    PlayerRevival { id: u32, revival_type: u16, pos: (f32, f32, f32) },
    SelfGetMoney { amount: u32, total_money: u32 },
    PlayerPickupMoney { amount: u32 },
    PlayerPickupItem {
        item_id: u32,
        expire_date: i32,
        amount: u32,
        slot_amount: u32,
        where_inv: u8,
        slot: u8,
    },
    EquipItem {
        inv_slot: u8,
        equip_slot: u8,
        count_inv: u32,
        count_eq: u32,
    },
    EquipmentData {
        id: u32,
        mask: u32,
        item_ids: Vec<u32>,
    },
    BeKilled { killer_id: u32, pos: (f32, f32, f32) },
    GatherStart {
        player_id: u32,
        mine_id: u32,
        use_time_s: u8,
    },
    GatherStop { player_id: u32 },
    PetRoom {
        capacity: u8,
        pets: Vec<GsPetSlotInfo>,
    },
    SummonPet {
        pet_index: u8,
        pet_nid: u32,
        pet_tid: u32,
    },
    RecallPet {
        pet_index: u8,
        pet_nid: u32,
    },
    PetHpNotify {
        pet_index: u8,
        cur_hp: i32,
        cur_vp: i32,
    },
    PvpStatusChanged {
        id: u32,
        enabled: bool,
    },
    TrashboxWealth {
        is_account_box: bool,
        money: u32,
    },
    BoothOpened {
        player_id: u32,
        booth_crc: u8,
        name_gbk: Vec<u8>,
    },
    ProduceProgress {
        recipe_id: u16,
        use_time_ms: u16,
        count: u16,
    },
    RefineResult {
        item_index: u16,
        item_id: u32,
        result_code: u8,
    },
    ElfVigor {
        vigor: i32,
        max_vigor: i32,
        vigor_gen_100x: i32,
    },
    ElfStamina {
        stamina: i32,
    },
    PublicQuestInfo {
        task_id: u32,
        score: i32,
        rank: u16,
    },
    Unknown { cmd: u16, len: usize },
}

struct LeReader<'a> {
    buf: &'a [u8],
    pos: usize,
}

impl<'a> LeReader<'a> {
    fn new(buf: &'a [u8]) -> Self {
        Self { buf, pos: 0 }
    }
    fn rem(&self) -> usize {
        self.buf.len().saturating_sub(self.pos)
    }
    fn u8(&mut self) -> PwResult<u8> {
        if self.rem() < 1 {
            return Err(PwError::UnexpectedEof {
                offset: self.pos,
                needed: 1,
                available: 0,
            });
        }
        let v = self.buf[self.pos];
        self.pos += 1;
        Ok(v)
    }
    fn u16(&mut self) -> PwResult<u16> {
        if self.rem() < 2 {
            return Err(PwError::UnexpectedEof {
                offset: self.pos,
                needed: 2,
                available: self.rem(),
            });
        }
        let v = u16::from_le_bytes([self.buf[self.pos], self.buf[self.pos + 1]]);
        self.pos += 2;
        Ok(v)
    }
    fn u32(&mut self) -> PwResult<u32> {
        if self.rem() < 4 {
            return Err(PwError::UnexpectedEof {
                offset: self.pos,
                needed: 4,
                available: self.rem(),
            });
        }
        let b = &self.buf[self.pos..self.pos + 4];
        self.pos += 4;
        Ok(u32::from_le_bytes([b[0], b[1], b[2], b[3]]))
    }
    fn i32(&mut self) -> PwResult<i32> {
        Ok(self.u32()? as i32)
    }
    fn f32(&mut self) -> PwResult<f32> {
        Ok(f32::from_bits(self.u32()?))
    }
    fn vec3(&mut self) -> PwResult<(f32, f32, f32)> {
        Ok((self.f32()?, self.f32()?, self.f32()?))
    }
    fn skip(&mut self, n: usize) -> PwResult<()> {
        if self.rem() < n {
            return Err(PwError::UnexpectedEof {
                offset: self.pos,
                needed: n,
                available: self.rem(),
            });
        }
        self.pos += n;
        Ok(())
    }
}

fn parse_npc_entry(r: &mut LeReader<'_>) -> PwResult<GsNpcSliceInfo> {
    let nid = r.u32()?;
    let tid = r.u32()?;
    let vis_tid = r.u32()?;
    let pos = r.vec3()?;
    let _seed = r.u16()?;
    let dir = r.u8()?;
    let state = r.u32()?;
    if (state & 0x01) != 0 && r.rem() >= 4 {
        let ext_cnt = r.u8()? as usize;
        let _ = r.skip((ext_cnt * 2).min(r.rem()));
    }
    Ok(GsNpcSliceInfo {
        nid,
        tid,
        vis_tid,
        pos,
        dir,
        state,
    })
}

fn parse_player_entry(r: &mut LeReader<'_>) -> PwResult<GsPlayerSliceInfo> {
    let cid = r.u32()?;
    let pos = r.vec3()?;
    let crc_custom = r.u16()?;
    let _crc_equip = r.u16()?;
    let dir = r.u8()?;
    let _sec_lv = r.u8()?;
    let state = r.u32()?;
    let _state2 = r.u32()?;
    let cls = (state & 0x07) as u8;
    Ok(GsPlayerSliceInfo {
        cid,
        pos,
        crc_custom,
        dir,
        cls,
        state,
    })
}

/// Decodes a single Build 2305 inner `s2c` game-data payload (`cmd` + `body`).
pub fn decode_gs_s2c(cmd: u16, body: &[u8]) -> PwResult<GsS2cPacket> {
    let mut r = LeReader::new(body);
    match cmd {
        s2c::SELF_INFO_1 if body.len() >= 20 => {
            // Verified Build 2305 `s2c::SELF_INFO_1` (`0x0008`, `34` bytes `<iifffHHHHBBBBi`):
            // `i32 exp, i32 sp, f32 pos[3], u16 dir_w, u16 level, u16 level2, u16 pad, u8[4], u32 role_id`
            let exp = r.i32()?;
            let sp = r.i32()?;
            let pos = r.vec3()?;
            let dir = if r.rem() >= 2 {
                (r.u16()? & 0xFF) as u8
            } else {
                0
            };
            let level = if r.rem() >= 2 { r.u16()? } else { 1 };
            let level2 = if r.rem() >= 2 { r.u16()? } else { 0 };
            let _pad = if r.rem() >= 2 { r.u16()? } else { 0 };
            let _flags = if r.rem() >= 4 { r.u32()? } else { 0 };
            let role_id = if r.rem() >= 4 { r.u32()? } else { 0 };
            Ok(GsS2cPacket::SelfInfo1(GsSelfInfo1 {
                exp,
                sp,
                role_id,
                pos,
                dir,
                level,
                level2,
                hp: 0,
                max_hp: 0,
                mp: 0,
                max_mp: 0,
            }))
        }
        s2c::NOTIFY_POS if body.len() >= 16 => {
            let pos = r.vec3()?;
            let world_tag = r.i32()?;
            Ok(GsS2cPacket::NotifyPos { pos, world_tag })
        }
        s2c::EXT_PROP if body.len() >= 88 => {
            let _id = r.u32()?;
            let vitality = r.i32()?;
            let energy = r.i32()?;
            let strength = r.i32()?;
            let agility = r.i32()?;
            let max_hp = r.i32()?;
            let max_mp = r.i32()?;
            let hp_gen = r.i32()?;
            let mp_gen = r.i32()?;
            let walk_speed = r.f32()?;
            let run_speed = r.f32()?;
            let swim_speed = r.f32()?;
            let flight_speed = r.f32()?;
            let attack = r.i32()?;
            let damage_low = r.i32()?;
            let damage_high = r.i32()?;
            let attack_speed = r.i32()?;
            let attack_range = r.f32()?;
            let damage_magic_low = if r.rem() >= 4 { r.i32()? } else { 0 };
            let damage_magic_high = if r.rem() >= 4 { r.i32()? } else { 0 };
            let defense = if r.rem() >= 24 {
                let _ = r.skip(20);
                r.i32()?
            } else {
                0
            };
            let armor = if r.rem() >= 24 {
                let _ = r.skip(20);
                r.i32()?
            } else {
                0
            };
            Ok(GsS2cPacket::ExtProp(GsExtProp {
                vitality,
                energy,
                strength,
                agility,
                max_hp,
                max_mp,
                hp_gen,
                mp_gen,
                walk_speed,
                run_speed,
                swim_speed,
                flight_speed,
                attack,
                damage_low,
                damage_high,
                attack_speed,
                attack_range,
                damage_magic_low,
                damage_magic_high,
                defense,
                armor,
            }))
        }
        s2c::NPC_INFO_LIST if body.len() >= 2 => {
            let count = r.u16()? as usize;
            let mut npcs = Vec::with_capacity(count.min(256));
            for _ in 0..count {
                if r.rem() < 31 {
                    break;
                }
                npcs.push(parse_npc_entry(&mut r)?);
            }
            Ok(GsS2cPacket::NpcInfoList(npcs))
        }
        s2c::NPC_ENTER_SLICE | s2c::NPC_ENTER_WORLD if body.len() >= 31 => {
            Ok(GsS2cPacket::NpcEnterSlice(parse_npc_entry(&mut r)?))
        }
        s2c::PLAYER_INFO_1_LIST if body.len() >= 2 => {
            let count = r.u16()? as usize;
            let mut players = Vec::with_capacity(count.min(256));
            for _ in 0..count {
                if r.rem() < 30 {
                    break;
                }
                players.push(parse_player_entry(&mut r)?);
            }
            Ok(GsS2cPacket::PlayerInfo1List(players))
        }
        s2c::PLAYER_ENTER_SLICE | s2c::PLAYER_ENTER_WORLD if body.len() >= 30 => {
            Ok(GsS2cPacket::PlayerEnterSlice(parse_player_entry(&mut r)?))
        }
        s2c::MATTER_INFO_LIST if body.len() >= 2 => {
            let count = r.u16()? as usize;
            let mut items = Vec::with_capacity(count.min(256));
            for _ in 0..count {
                if r.rem() < 22 {
                    break;
                }
                items.push(GsMatterSliceInfo {
                    mid: r.u32()?,
                    tid: r.u32()?,
                    pos: r.vec3()?,
                    dir0: r.u8()?,
                    dir1: r.u8()?,
                });
            }
            Ok(GsS2cPacket::MatterInfoList(items))
        }
        s2c::OBJECT_LEAVE_SLICE if body.len() >= 4 => {
            Ok(GsS2cPacket::ObjectLeaveSlice { id: r.u32()? })
        }
        s2c::OBJECT_MOVE if body.len() >= 21 => {
            let id = r.u32()?;
            let dest = r.vec3()?;
            let use_time_ms = r.u16()?;
            let speed_cms = r.u16()?;
            let move_mode = r.u8()?;
            Ok(GsS2cPacket::ObjectMove {
                id,
                dest,
                use_time_ms,
                speed_cms,
                move_mode,
            })
        }
        s2c::OBJECT_STOP_MOVE if body.len() >= 20 => {
            let id = r.u32()?;
            let pos = r.vec3()?;
            let speed_cms = r.u16()?;
            let dir = r.u8()?;
            let move_mode = r.u8()?;
            Ok(GsS2cPacket::ObjectStopMove {
                id,
                pos,
                speed_cms,
                dir,
                move_mode,
            })
        }
        s2c::SELF_ITEM_DATA if body.len() >= 6 => {
            let where_inv = r.u8()?;
            let capacity = r.u8()?;
            let byte_len = r.u32()? as usize;
            let end_pos = (r.pos + byte_len).min(body.len());
            let mut items = Vec::new();
            while r.pos + 17 <= end_pos {
                let slot = r.u8()?;
                let item_id = r.u32()?;
                let expire_date = r.i32()?;
                let count = r.u32()?;
                let proc_type = r.u16()?;
                let content_len = r.u16()? as usize;
                let _ = r.skip(content_len.min(end_pos.saturating_sub(r.pos)));
                items.push(GsInventorySlot {
                    slot,
                    item_id,
                    expire_date,
                    count,
                    proc_type,
                });
            }
            Ok(GsS2cPacket::SelfItemData {
                where_inv,
                capacity,
                items,
            })
        }
        s2c::SKILL_DATA if body.len() >= 4 => {
            let count = r.u32()? as usize;
            let mut skills = Vec::with_capacity(count.min(256));
            for _ in 0..count {
                if r.rem() < 5 {
                    break;
                }
                skills.push(GsSkillEntry {
                    skill_id: r.u16()?,
                    level: r.u8()?,
                    ability: r.u16()?,
                });
            }
            Ok(GsS2cPacket::SkillData(skills))
        }
        s2c::SELECT_TARGET_RE if body.len() >= 22 => Ok(GsS2cPacket::SelectTargetRe {
            target_id: r.u32()?,
            level: r.u16()?,
            hp: r.i32()?,
            max_hp: r.i32()?,
            mp: r.i32()?,
            max_mp: r.i32()?,
        }),
        s2c::OBJECT_CAST_SKILL if body.len() >= 15 => Ok(GsS2cPacket::ObjectCastSkill {
            caster_id: r.u32()?,
            target_id: r.u32()?,
            skill_id: r.u32()?,
            cast_time_ms: r.u16()?,
            skill_level: r.u8()?,
        }),
        s2c::DAMAGE_INFO if body.len() >= 13 => Ok(GsS2cPacket::DamageInfo {
            attacker_id: r.u32()?,
            target_id: r.u32()?,
            damage: r.i32()?,
            flags: r.u8()?,
        }),
        s2c::NPC_DEAD if body.len() >= 8 => Ok(GsS2cPacket::NpcDead {
            nid: r.u32()?,
            killer_id: r.u32()?,
        }),
        s2c::NPC_GREETING if body.len() >= 4 => Ok(GsS2cPacket::NpcGreeting { nid: r.u32()? }),
        s2c::OBJECT_DO_EMOTE if body.len() >= 6 => Ok(GsS2cPacket::ObjectDoEmote {
            id: r.u32()?,
            emotion: r.u16()?,
        }),
        s2c::ICON_STATE_NOTIFY if body.len() >= 6 => {
            let id = r.u32()?;
            let cnt = r.u16()? as usize;
            let mut states = Vec::with_capacity(cnt.min(64));
            for _ in 0..cnt {
                if r.rem() < 2 {
                    break;
                }
                states.push(r.u16()?);
            }
            Ok(GsS2cPacket::IconStateNotify { id, states })
        }
        s2c::TASK_DATA if body.len() >= 8 => {
            let active_bytes = r.u32()? as usize;
            let _ = r.skip(active_bytes.min(r.rem()));
            let finished_bytes = if r.rem() >= 4 { r.u32()? as usize } else { 0 };
            Ok(GsS2cPacket::TaskData {
                active_bytes,
                finished_bytes,
            })
        }
        s2c::TEAM_DATA if body.len() >= 10 => {
            let leader_id = r.u32()?;
            let team_seq = r.u32()?;
            let count = r.u16()? as usize;
            let mut members = Vec::with_capacity(count.min(10));
            for _ in 0..count {
                if r.rem() < 24 {
                    break;
                }
                members.push(GsTeamMemberInfo {
                    member_id: r.u32()?,
                    level: r.u16()?,
                    combat_state: r.u8()?,
                    pk_level: r.u8()?,
                    hp: r.i32()?,
                    mp: r.i32()?,
                    max_hp: r.i32()?,
                    max_mp: r.i32()?,
                });
            }
            Ok(GsS2cPacket::TeamData {
                leader_id,
                team_seq,
                members,
            })
        }
        s2c::TEAM_MEMBER_POS if body.len() >= 20 => Ok(GsS2cPacket::TeamMemberPos {
            member_id: r.u32()?,
            pos: r.vec3()?,
            world_tag: r.i32()?,
        }),
        s2c::TEAM_INVITE_NOTIFY if body.len() >= 8 => Ok(GsS2cPacket::TeamInviteNotify {
            leader_id: r.u32()?,
            team_seq: r.u32()?,
        }),
        s2c::TEAM_MEMBER_LEAVE if body.len() >= 10 => Ok(GsS2cPacket::TeamMemberLeave {
            leader_id: r.u32()?,
            member_id: r.u32()?,
            reason: r.u16()?,
        }),
        s2c::ADD_EXP if body.len() >= 8 => Ok(GsS2cPacket::AddExp {
            exp: r.i32()?,
            sp: r.i32()?,
        }),
        s2c::LEVEL_UP if body.len() >= 4 => Ok(GsS2cPacket::LevelUp { id: r.u32()? }),
        s2c::PLAYER_REVIVAL if body.len() >= 18 => Ok(GsS2cPacket::PlayerRevival {
            id: r.u32()?,
            revival_type: r.u16()?,
            pos: r.vec3()?,
        }),
        s2c::SELF_GET_MONEY if body.len() >= 8 => Ok(GsS2cPacket::SelfGetMoney {
            amount: r.u32()?,
            total_money: r.u32()?,
        }),
        s2c::PLAYER_PICKUP_MONEY if body.len() >= 4 => Ok(GsS2cPacket::PlayerPickupMoney {
            amount: r.u32()?,
        }),
        s2c::PLAYER_PICKUP_ITEM if body.len() >= 18 => Ok(GsS2cPacket::PlayerPickupItem {
            item_id: r.u32()?,
            expire_date: r.i32()?,
            amount: r.u32()?,
            slot_amount: r.u32()?,
            where_inv: r.u8()?,
            slot: r.u8()?,
        }),
        s2c::EQUIP_ITEM if body.len() >= 10 => Ok(GsS2cPacket::EquipItem {
            inv_slot: r.u8()?,
            equip_slot: r.u8()?,
            count_inv: r.u32()?,
            count_eq: r.u32()?,
        }),
        s2c::EQUIPMENT_DATA if body.len() >= 8 => {
            let id = r.u32()?;
            let mask = r.u32()?;
            let bits = mask.count_ones() as usize;
            let mut item_ids = Vec::with_capacity(bits);
            for _ in 0..bits {
                if r.rem() < 4 {
                    break;
                }
                item_ids.push(r.u32()?);
            }
            Ok(GsS2cPacket::EquipmentData { id, mask, item_ids })
        }
        s2c::BE_KILLED if body.len() >= 16 => Ok(GsS2cPacket::BeKilled {
            killer_id: r.u32()?,
            pos: r.vec3()?,
        }),
        s2c::GATHER_START if body.len() >= 9 => Ok(GsS2cPacket::GatherStart {
            player_id: r.u32()?,
            mine_id: r.u32()?,
            use_time_s: r.u8()?,
        }),
        s2c::GATHER_STOP if body.len() >= 4 => Ok(GsS2cPacket::GatherStop {
            player_id: r.u32()?,
        }),
        s2c::PET_ROOM if body.len() >= 2 => {
            let capacity = r.u8()?;
            let count = r.u8()? as usize;
            let mut pets = Vec::with_capacity(count.min(20));
            for _ in 0..count {
                if r.rem() < 18 {
                    break;
                }
                pets.push(GsPetSlotInfo {
                    pet_index: r.u8()?,
                    pet_tid: r.u32()?,
                    level: r.u16()?,
                    hp: r.i32()?,
                    max_hp: r.i32()?,
                    loyalty: r.u16()?,
                    hunger: r.u8()?,
                });
            }
            Ok(GsS2cPacket::PetRoom { capacity, pets })
        }
        s2c::SUMMON_PET if body.len() >= 9 => Ok(GsS2cPacket::SummonPet {
            pet_index: r.u8()?,
            pet_nid: r.u32()?,
            pet_tid: r.u32()?,
        }),
        s2c::RECALL_PET if body.len() >= 5 => Ok(GsS2cPacket::RecallPet {
            pet_index: r.u8()?,
            pet_nid: r.u32()?,
        }),
        s2c::PET_HP_NOTIFY if body.len() >= 9 => Ok(GsS2cPacket::PetHpNotify {
            pet_index: r.u8()?,
            cur_hp: r.i32()?,
            cur_vp: r.i32()?,
        }),
        s2c::PLAYER_ENABLE_PVP if body.len() >= 4 => Ok(GsS2cPacket::PvpStatusChanged {
            id: r.u32()?,
            enabled: true,
        }),
        s2c::PLAYER_DISABLE_PVP if body.len() >= 4 => Ok(GsS2cPacket::PvpStatusChanged {
            id: r.u32()?,
            enabled: false,
        }),
        s2c::TRASHBOX_WEALTH if body.len() >= 5 => Ok(GsS2cPacket::TrashboxWealth {
            is_account_box: r.u8()? != 0,
            money: r.u32()?,
        }),
        s2c::PLAYER_OPEN_BOOTH if body.len() >= 6 => {
            let player_id = r.u32()?;
            let booth_crc = r.u8()?;
            let name_len = (r.u8()? as usize).min(r.rem());
            let name_gbk = body[r.pos..r.pos + name_len].to_vec();
            Ok(GsS2cPacket::BoothOpened {
                player_id,
                booth_crc,
                name_gbk,
            })
        }
        s2c::PRODUCE_START if body.len() >= 6 => Ok(GsS2cPacket::ProduceProgress {
            recipe_id: r.u16()?,
            use_time_ms: r.u16()?,
            count: r.u16()?,
        }),
        s2c::REFINE_RESULT if body.len() >= 7 => Ok(GsS2cPacket::RefineResult {
            item_index: r.u16()?,
            item_id: r.u32()?,
            result_code: r.u8()?,
        }),
        s2c::ELF_VIGOR if body.len() >= 12 => Ok(GsS2cPacket::ElfVigor {
            vigor: r.i32()?,
            max_vigor: r.i32()?,
            vigor_gen_100x: r.i32()?,
        }),
        s2c::ELF_STAMINA if body.len() >= 4 => Ok(GsS2cPacket::ElfStamina {
            stamina: r.i32()?,
        }),
        s2c::PUBLIC_QUEST_INFO if body.len() >= 10 => Ok(GsS2cPacket::PublicQuestInfo {
            task_id: r.u32()?,
            score: r.i32()?,
            rank: r.u16()?,
        }),
        _ => Ok(GsS2cPacket::Unknown {
            cmd,
            len: body.len(),
        }),
    }
}

pub fn encode_gs_s2c_team_data(leader_id: u32, team_seq: u32, members: &[GsTeamMemberInfo]) -> Vec<u8> {
    let mut out = Vec::with_capacity(12 + members.len() * 24);
    out.extend_from_slice(&s2c::TEAM_DATA.to_le_bytes());
    out.extend_from_slice(&leader_id.to_le_bytes());
    out.extend_from_slice(&team_seq.to_le_bytes());
    out.extend_from_slice(&(members.len() as u16).to_le_bytes());
    for m in members {
        out.extend_from_slice(&m.member_id.to_le_bytes());
        out.extend_from_slice(&m.level.to_le_bytes());
        out.push(m.combat_state);
        out.push(m.pk_level);
        out.extend_from_slice(&m.hp.to_le_bytes());
        out.extend_from_slice(&m.mp.to_le_bytes());
        out.extend_from_slice(&m.max_hp.to_le_bytes());
        out.extend_from_slice(&m.max_mp.to_le_bytes());
    }
    out
}

pub fn encode_gs_s2c_pet_room(capacity: u8, pets: &[GsPetSlotInfo]) -> Vec<u8> {
    let mut out = Vec::with_capacity(4 + pets.len() * 18);
    out.extend_from_slice(&s2c::PET_ROOM.to_le_bytes());
    out.push(capacity);
    out.push(pets.len() as u8);
    for p in pets {
        out.push(p.pet_index);
        out.extend_from_slice(&p.pet_tid.to_le_bytes());
        out.extend_from_slice(&p.level.to_le_bytes());
        out.extend_from_slice(&p.hp.to_le_bytes());
        out.extend_from_slice(&p.max_hp.to_le_bytes());
        out.extend_from_slice(&p.loyalty.to_le_bytes());
        out.push(p.hunger);
    }
    out
}

/// Encodes an inner `s2c` frame (`u16_le cmd` + payload) for server/test/replay generation.
pub fn encode_gs_s2c_npc_enter_slice(npc: &GsNpcSliceInfo) -> Vec<u8> {
    let mut out = Vec::with_capacity(33);
    out.extend_from_slice(&s2c::NPC_ENTER_SLICE.to_le_bytes());
    out.extend_from_slice(&npc.nid.to_le_bytes());
    out.extend_from_slice(&npc.tid.to_le_bytes());
    out.extend_from_slice(&npc.vis_tid.to_le_bytes());
    for f in [npc.pos.0, npc.pos.1, npc.pos.2] {
        out.extend_from_slice(&f.to_le_bytes());
    }
    out.extend_from_slice(&0u16.to_le_bytes());
    out.push(npc.dir);
    out.extend_from_slice(&npc.state.to_le_bytes());
    out
}

pub fn encode_gs_s2c_damage_info(
    attacker_id: u32,
    target_id: u32,
    damage: i32,
    flags: u8,
) -> Vec<u8> {
    let mut out = Vec::with_capacity(15);
    out.extend_from_slice(&s2c::DAMAGE_INFO.to_le_bytes());
    out.extend_from_slice(&attacker_id.to_le_bytes());
    out.extend_from_slice(&target_id.to_le_bytes());
    out.extend_from_slice(&damage.to_le_bytes());
    out.push(flags);
    out
}

pub fn encode_gs_s2c_skill_data(skills: &[GsSkillEntry]) -> Vec<u8> {
    let mut out = Vec::with_capacity(6 + skills.len() * 5);
    out.extend_from_slice(&s2c::SKILL_DATA.to_le_bytes());
    out.extend_from_slice(&(skills.len() as u32).to_le_bytes());
    for s in skills {
        out.extend_from_slice(&s.skill_id.to_le_bytes());
        out.push(s.level);
        out.extend_from_slice(&s.ability.to_le_bytes());
    }
    out
}

// ---------------------------------------------------------------------------
// Extended Build 2305 `c2s` Encoders (Shop, Warehouse, Craft, Refine, Booth, Genie/ELF, PK, Autolock)
// ---------------------------------------------------------------------------

pub fn encode_c2s_npc_buy_item(shop_page: u32, item_id: u32, slot_idx: u32, count: u32) -> Vec<u8> {
    let mut out = Vec::with_capacity(22);
    out.extend_from_slice(&c2s::NPC_BUY_ITEM.to_le_bytes());
    out.extend_from_slice(&1u32.to_le_bytes()); // 1 entry
    out.extend_from_slice(&item_id.to_le_bytes());
    out.extend_from_slice(&slot_idx.to_le_bytes());
    out.extend_from_slice(&count.to_le_bytes());
    out.extend_from_slice(&shop_page.to_le_bytes());
    out
}

pub fn encode_c2s_npc_sell_item(item_id: u32, inv_slot: u32, count: u32) -> Vec<u8> {
    let mut out = Vec::with_capacity(18);
    out.extend_from_slice(&c2s::NPC_SELL_ITEM.to_le_bytes());
    out.extend_from_slice(&1u32.to_le_bytes());
    out.extend_from_slice(&item_id.to_le_bytes());
    out.extend_from_slice(&inv_slot.to_le_bytes());
    out.extend_from_slice(&count.to_le_bytes());
    out
}

pub fn encode_c2s_repair_all() -> Vec<u8> {
    c2s::REPAIR_ALL.to_le_bytes().to_vec()
}

pub fn encode_c2s_trashbox_money(deposit: bool, is_account_box: bool, amount: u32) -> Vec<u8> {
    let mut out = Vec::with_capacity(7);
    let op = if deposit {
        c2s::TRASHBOX_DEPOSIT_MONEY
    } else {
        c2s::TRASHBOX_WITHDRAW_MONEY
    };
    out.extend_from_slice(&op.to_le_bytes());
    out.push(u8::from(is_account_box));
    out.extend_from_slice(&amount.to_le_bytes());
    out
}

pub fn encode_c2s_produce_item(recipe_id: u16, count: u16) -> Vec<u8> {
    let mut out = Vec::with_capacity(6);
    out.extend_from_slice(&c2s::PRODUCE_ITEM.to_le_bytes());
    out.extend_from_slice(&recipe_id.to_le_bytes());
    out.extend_from_slice(&count.to_le_bytes());
    out
}

pub fn encode_c2s_refine_equip(inv_index: u16, item_id: u32, catalyst_id: u32) -> Vec<u8> {
    let mut out = Vec::with_capacity(12);
    out.extend_from_slice(&c2s::REFINE_EQUIP.to_le_bytes());
    out.extend_from_slice(&inv_index.to_le_bytes());
    out.extend_from_slice(&item_id.to_le_bytes());
    out.extend_from_slice(&catalyst_id.to_le_bytes());
    out
}

pub fn encode_c2s_enchase_equip(equip_slot: u16, stone_slot: u16) -> Vec<u8> {
    let mut out = Vec::with_capacity(6);
    out.extend_from_slice(&c2s::ENCHASE_EQUIP.to_le_bytes());
    out.extend_from_slice(&equip_slot.to_le_bytes());
    out.extend_from_slice(&stone_slot.to_le_bytes());
    out
}

pub fn encode_c2s_identify_equip(inv_slot: u16) -> Vec<u8> {
    let mut out = Vec::with_capacity(4);
    out.extend_from_slice(&c2s::IDENTIFY_EQUIP.to_le_bytes());
    out.extend_from_slice(&inv_slot.to_le_bytes());
    out
}

pub fn encode_c2s_open_booth(booth_name_utf16: &[u8]) -> Vec<u8> {
    let mut out = Vec::with_capacity(6 + booth_name_utf16.len());
    out.extend_from_slice(&c2s::OPEN_BOOTH.to_le_bytes());
    out.extend_from_slice(&0u16.to_le_bytes()); // 0 initial slots header
    let len = booth_name_utf16.len().min(62) as u16;
    out.extend_from_slice(&len.to_le_bytes());
    out.extend_from_slice(&booth_name_utf16[..len as usize]);
    out
}

pub fn encode_c2s_cast_elf_skill(skill_id: u16, force_attack: u8, targets: &[u32]) -> Vec<u8> {
    let mut out = Vec::with_capacity(6 + targets.len() * 4);
    out.extend_from_slice(&c2s::CAST_ELF_SKILL.to_le_bytes());
    out.extend_from_slice(&skill_id.to_le_bytes());
    out.push(force_attack);
    out.push(targets.len().min(255) as u8);
    for &t in targets.iter().take(255) {
        out.extend_from_slice(&t.to_le_bytes());
    }
    out
}

pub fn encode_c2s_elf_add_attribute(str_pt: i16, agi_pt: i16, vit_pt: i16, eng_pt: i16) -> Vec<u8> {
    let mut out = Vec::with_capacity(10);
    out.extend_from_slice(&c2s::ELF_ADD_ATTRIBUTE.to_le_bytes());
    for v in [str_pt, agi_pt, vit_pt, eng_pt] {
        out.extend_from_slice(&v.to_le_bytes());
    }
    out
}

pub fn encode_c2s_toggle_pk_mode(enable_pvp: bool) -> Vec<u8> {
    let mut out = Vec::with_capacity(3);
    out.extend_from_slice(&c2s::TOGGLE_PK_MODE.to_le_bytes());
    out.push(u8::from(enable_pvp));
    out
}

pub fn encode_c2s_switch_fashion_mode() -> Vec<u8> {
    c2s::SWITCH_FASHION_MODE.to_le_bytes().to_vec()
}

pub fn encode_c2s_autolock_open(timeout_minutes: i32) -> Vec<u8> {
    let mut out = Vec::with_capacity(6);
    out.extend_from_slice(&c2s::AUTOLOCK_OPEN.to_le_bytes());
    out.extend_from_slice(&timeout_minutes.to_le_bytes());
    out
}
