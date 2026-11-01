//! Live Non-Blocking TCP `GLinkSession` (`glinkd:29000`) & Stateful 8KB `MPPC` Stream Decoder.
//!
//! Disassembly-verified 1:1 against `elementclient.exe` Build 2305:
//! - `Challenge` (`0x5fbbf0`, op 1)
//! - `SetupResponse` (`0x5c02c0..0x5c0780`) + 2-field `Response` (`0x5d9110`, op 3)
//! - `KeyExchange` (`0x5d97a0` / `0x5fc0d0`, op 2: `nonce: Octets`, `blkickuser: u8`)
//! - C2S `ARCFourSecurity` (type 2, raw RC4) vs S2C `DecompressARCFourSecurity` (`0x5c8730`, type 6,
//!   RC4 + stateful 8,192-byte sliding-window MPPC flushing on 10-bit `1111000000` EOB)
//! - `OnlineAnnounce` (`0x5fd110`, op 4), `ErrorInfo` (`0x5fb560`, op 5),
//!   `RoleList` (`0x5e0d90`, op 82), `RoleList_Re` (`0x60dc70` + `RoleInfo` `0x4333d0`, op 83),
//!   `SelectRole` (`0x5d4820`, op 70), `SelectRole_Re` (`0x60f330`, op 71),
//!   `EnterWorld` (`0x5d4bf0`, op 72), `PublicChat` (`0x5d2aa0`, op 79), `KeepAlive` (`0x5bc770`, op 90).

use std::io::{ErrorKind, Read, Write};
use std::net::{SocketAddr, TcpStream, ToSocketAddrs};
use std::time::{Duration, Instant};

use pw_core::{decode_utf16le_null_terminated, PwError, PwResult};

use crate::{
    decode_gs_s2c, gs_c2s, hmac_md5, md5_digest, ArcFourSecurity, GsS2cPacket, OctetsStream,
};

/// Stateful 8,192-byte sliding-window MPPC decompressor (`GNET::DecompressARCFourSecurity::Update`, `0x5c8730`).
#[derive(Debug, Clone)]
pub struct StatefulMppcDecoder {
    history: [u8; 8192],
    hist_pos: usize,
    in_buf: Vec<u8>,
    bit_offset: usize,
}

impl Default for StatefulMppcDecoder {
    fn default() -> Self {
        Self::new()
    }
}

impl StatefulMppcDecoder {
    pub fn new() -> Self {
        Self {
            history: [0u8; 8192],
            hist_pos: 0,
            in_buf: Vec::with_capacity(4096),
            bit_offset: 0,
        }
    }

    pub fn update(&mut self, chunk: &[u8]) -> Vec<u8> {
        self.in_buf.extend_from_slice(chunk);
        let mut out = Vec::new();
        let mut checkpoint_bit = self.bit_offset;
        let mut checkpoint_hist = self.hist_pos;

        let total_bits = self.in_buf.len() * 8;
        let peek_bits = |buf: &[u8], bit_pos: usize, n: usize| -> Option<u32> {
            if bit_pos + n > buf.len() * 8 {
                return None;
            }
            let mut val = 0u32;
            for i in 0..n {
                let bp = bit_pos + i;
                let bit = (buf[bp >> 3] >> (7 - (bp & 7))) & 1;
                val = (val << 1) | (bit as u32);
            }
            Some(val)
        };

        let mut bpos = self.bit_offset;
        while bpos < total_bits {
            let Some(lead4) = peek_bits(&self.in_buf, bpos, 4) else {
                break;
            };
            if (lead4 & 0b1000) == 0 {
                let Some(v) = peek_bits(&self.in_buf, bpos + 1, 7) else {
                    break;
                };
                bpos += 8;
                self.history[self.hist_pos & 0x1FFF] = v as u8;
                self.hist_pos += 1;
                continue;
            }
            if (lead4 & 0b1100) == 0b1000 {
                let Some(v) = peek_bits(&self.in_buf, bpos + 2, 7) else {
                    break;
                };
                bpos += 9;
                self.history[self.hist_pos & 0x1FFF] = (v as u8) | 0x80;
                self.hist_pos += 1;
                continue;
            }

            let offset: usize;
            if lead4 == 0b1111 {
                let Some(off6) = peek_bits(&self.in_buf, bpos + 4, 6) else {
                    break;
                };
                bpos += 10;
                if off6 == 0 {
                    // 10-bit EOB (`1111000000`): align to byte boundary & flush emitted window!
                    bpos = (bpos + 7) & !7;
                    for p in checkpoint_hist..self.hist_pos {
                        out.push(self.history[p & 0x1FFF]);
                    }
                    if (self.hist_pos & 0x1FFF) == 0 {
                        self.hist_pos = 0;
                    }
                    checkpoint_hist = self.hist_pos;
                    checkpoint_bit = bpos;
                    continue;
                }
                offset = off6 as usize;
            } else if lead4 == 0b1110 {
                let Some(off8) = peek_bits(&self.in_buf, bpos + 4, 8) else {
                    break;
                };
                bpos += 12;
                offset = (off8 as usize) + 64;
            } else {
                let Some(off13) = peek_bits(&self.in_buf, bpos + 3, 13) else {
                    break;
                };
                bpos += 16;
                offset = (off13 as usize) + 320;
            }

            let mut ones = 0usize;
            let mut incomplete = false;
            loop {
                let Some(bit) = peek_bits(&self.in_buf, bpos, 1) else {
                    incomplete = true;
                    break;
                };
                bpos += 1;
                if bit == 0 || ones >= 11 {
                    break;
                }
                ones += 1;
            }
            if incomplete {
                break;
            }
            let length = if ones == 0 {
                3usize
            } else {
                let extra_bits = ones + 1;
                let Some(low) = peek_bits(&self.in_buf, bpos, extra_bits) else {
                    break;
                };
                bpos += extra_bits;
                (1usize << extra_bits) + (low as usize)
            };

            if offset == 0 {
                break;
            }
            for _ in 0..length {
                let src = self.hist_pos.wrapping_sub(offset) & 0x1FFF;
                let b = self.history[src];
                self.history[self.hist_pos & 0x1FFF] = b;
                self.hist_pos += 1;
            }
        }

        let consumed_bytes = checkpoint_bit >> 3;
        if consumed_bytes > 0 {
            self.in_buf.drain(..consumed_bytes);
            self.bit_offset = checkpoint_bit & 7;
        } else {
            self.bit_offset = checkpoint_bit;
        }
        self.hist_pos = checkpoint_hist;
        out
    }
}

#[derive(Debug, Clone)]
pub struct CharacterSummary {
    pub role_id: u32,
    pub name: String,
    pub gender: u8,
    pub race: u8,
    pub occupation: u8,
    pub level: i32,
    pub level2: i32,
    pub pos: (f32, f32, f32),
    pub world_tag: i32,
}

impl CharacterSummary {
    pub fn occupation_name(&self) -> &'static str {
        match self.occupation {
            0 => "Blademaster",
            1 => "Wizard",
            2 => "Psychic",
            3 => "Venomancer",
            4 => "Barbarian",
            5 => "Assassin",
            6 => "Archer",
            7 => "Cleric",
            _ => "Cultivator",
        }
    }
}

#[derive(Debug, Clone, PartialEq, Eq)]
pub enum LiveConnPhase {
    Disconnected,
    Connecting,
    AwaitChallenge,
    AwaitKeyExchange,
    AwaitOnlineAnnounce,
    ListingRoles,
    ReadyAtRoleSelect,
    SelectingRole,
    InWorld,
    Error(String),
}

#[derive(Debug, Clone, PartialEq, Eq)]
pub struct GnetFriendEntry {
    pub role_id: u32,
    pub cls: u8,
    pub group_id: u8,
    pub name: String,
    pub online_status: i8,
}

#[derive(Debug, Clone, PartialEq, Eq)]
pub struct GnetMailHeader {
    pub mail_id: u8,
    pub sender_id: u32,
    pub send_type: u8,
    pub receiver_stamp: i32,
    pub attribute: u8,
    pub title: String,
    pub sender_name: String,
}

#[derive(Debug, Clone, PartialEq, Eq)]
pub struct GnetAuctionEntry {
    pub auction_id: u32,
    pub bid_price: u32,
    pub bin_price: u32,
    pub end_time: u32,
    pub item_id: u32,
    pub count: u16,
    pub seller_id: u32,
    pub bidder_id: u32,
}

#[derive(Debug, Clone, PartialEq, Eq)]
pub struct GnetTerritoryStatus {
    pub domain_id: u16,
    pub status: u8,
    pub owner_faction_id: u32,
    pub challenger_faction_id: u32,
    pub battle_end_timestamp: i32,
}

#[derive(Debug, Clone, PartialEq, Eq)]
pub struct GnetFactionSummary {
    pub faction_id: u32,
    pub name: String,
    pub level: u8,
    pub member_count: u16,
    pub announce: String,
}

#[derive(Debug, Clone)]
pub enum GLinkEvent {
    Connected(String),
    ChallengeReceived { version: u32, algo: u8, edition: Vec<u8> },
    KeyExchangeComplete,
    OnlineAnnounce { user_id: u32, local_sid: u32, zone_id: u8 },
    RoleAdded(CharacterSummary),
    RoleListFinished(usize),
    RoleSelected { role_id: u32 },
    EnteredWorld { role_id: u32 },
    GsNotifyPos { pos: (f32, f32, f32), world_tag: i32 },
    GsCommand { s2c_cmd: u16, body: Vec<u8> },
    GsDecoded(GsS2cPacket),
    ChatMessage { channel: u8, sender_id: u32, text: String },
    PrivateChat { sender_name: String, sender_id: u32, text: String },
    FactionChat { sender_id: u32, text: String },
    FriendListUpdated(Vec<GnetFriendEntry>),
    FriendStatusChanged { role_id: u32, status: i8 },
    TradeEvent { opcode: u32, trade_id: u32, partner_id: u32, result: i32 },
    NewMailAnnounced { remain_time: i32 },
    MailListReceived(Vec<GnetMailHeader>),
    AuctionListReceived { category: u16, items: Vec<GnetAuctionEntry> },
    StockAccountUpdated { cash: i32, money: i32 },
    BattleMapReceived(Vec<GnetTerritoryStatus>),
    FactionInfoUpdated(GnetFactionSummary),
    CustomDataReceived { role_id: u32, custom_bytes: Vec<u8> },
    UiConfigReceived { role_id: u32, ui_bytes: Vec<u8> },
    HelpStatesReceived { role_id: u32, help_bytes: Vec<u8> },
    MatrixChallenge { algorithm: i32, nonce: u32 },
    AutolockUpdated { timeout_secs: i32, retcode: i32 },
    CashLockUpdated { locked: bool, retcode: i32 },
    BattleActionResult { opcode: u32, domain_id: u16, retcode: i32 },
    FactionOpResult { opcode: u32, op_type: i32, retcode: i32 },
    AntiCheatQuestion { question_type: i32, question_id: i32, image_bytes: Vec<u8> },
    ServerPacket { opcode: u32, payload_len: usize },
    ServerError { code: u8, message: String },
    Disconnected(String),
}

pub struct GLinkLiveClient {
    pub server_addr: String,
    pub account: String,
    password_resp: Vec<u8>,
    password_hash: [u8; 16],
    stream: Option<TcpStream>,
    pub phase: LiveConnPhase,
    c2s_rc4: Option<ArcFourSecurity>,
    s2c_rc4: Option<ArcFourSecurity>,
    s2c_mppc: Option<StatefulMppcDecoder>,
    recv_plain: Vec<u8>,
    pub user_id: u32,
    pub local_sid: u32,
    pub selected_role_id: u32,
    pub roles: Vec<CharacterSummary>,
    last_keepalive: Instant,
    connect_started: Instant,
}

impl GLinkLiveClient {
    pub fn new(server_addr: impl Into<String>) -> Self {
        Self {
            server_addr: server_addr.into(),
            account: String::new(),
            password_resp: Vec::new(),
            password_hash: [0u8; 16],
            stream: None,
            phase: LiveConnPhase::Disconnected,
            c2s_rc4: None,
            s2c_rc4: None,
            s2c_mppc: None,
            recv_plain: Vec::with_capacity(8192),
            user_id: 0,
            local_sid: 0,
            selected_role_id: 0,
            roles: Vec::new(),
            last_keepalive: Instant::now(),
            connect_started: Instant::now(),
        }
    }

    pub fn connect_and_login(&mut self, addr_str: &str, account: &str, password: &str) -> PwResult<()> {
        self.disconnect();
        self.server_addr = addr_str.trim().to_string();
        self.account = account.trim().to_ascii_lowercase();
        let mut cred = Vec::with_capacity(self.account.len() + password.len());
        cred.extend_from_slice(self.account.as_bytes());
        cred.extend_from_slice(password.as_bytes());
        self.password_hash = md5_digest(&cred);

        let sock_addr: SocketAddr = self
            .server_addr
            .to_socket_addrs()
            .map_err(|e| PwError::InvalidData(format!("resolve {}: {e}", self.server_addr)))?
            .next()
            .ok_or_else(|| PwError::InvalidData(format!("no address for {}", self.server_addr)))?;

        self.phase = LiveConnPhase::Connecting;
        self.connect_started = Instant::now();
        let stream = TcpStream::connect_timeout(&sock_addr, Duration::from_millis(1800))
            .map_err(|e| {
                let msg = format!("TCP connect {sock_addr} failed: {e}");
                self.phase = LiveConnPhase::Error(msg.clone());
                PwError::InvalidData(msg)
            })?;
        let _ = stream.set_nodelay(true);
        let _ = stream.set_nonblocking(true);
        self.stream = Some(stream);
        self.phase = LiveConnPhase::AwaitChallenge;
        self.last_keepalive = Instant::now();
        Ok(())
    }

    pub fn disconnect(&mut self) {
        self.stream = None;
        self.c2s_rc4 = None;
        self.s2c_rc4 = None;
        self.s2c_mppc = None;
        self.recv_plain.clear();
        self.roles.clear();
        self.phase = LiveConnPhase::Disconnected;
    }

    pub fn is_connected(&self) -> bool {
        self.stream.is_some()
    }

    fn send_protocol(&mut self, opcode: u32, payload: &[u8]) -> PwResult<()> {
        let mut frame = OctetsStream::with_capacity(payload.len() + 8);
        frame.write_compact_uint(opcode);
        frame.write_compact_uint(payload.len() as u32);
        frame.write_raw(payload);
        let mut wire = frame.into_vec();
        if let Some(rc4) = &mut self.c2s_rc4 {
            rc4.apply_in_place(&mut wire);
        }
        if let Some(sock) = &mut self.stream {
            sock.write_all(&wire)?;
            let _ = sock.flush();
        }
        Ok(())
    }

    pub fn select_and_enter_role(&mut self, role_id: u32) -> PwResult<()> {
        self.selected_role_id = role_id;
        let mut exact = OctetsStream::with_capacity(5);
        exact.write_u32_be(role_id);
        exact.write_u8(0);
        self.phase = LiveConnPhase::SelectingRole;
        self.send_protocol(70, exact.as_slice())
    }

    pub fn send_enter_world(&mut self, role_id: u32) -> PwResult<()> {
        let mut body = OctetsStream::with_capacity(20);
        body.write_u32_be(role_id);
        body.write_u32_be(self.local_sid);
        body.write_u32_be(0);
        body.write_u32_be(0);
        self.phase = LiveConnPhase::InWorld;
        self.send_protocol(72, body.as_slice())?;
        // Immediately request `GET_ALL_DATA` (`c2s=0x08`) inside `GamedataSend` (`op=34`) just like `CECGameRun::StartGame`!
        self.send_c2s_get_all_data(true, true, true)
    }

    /// Sends an inner `gs` `c2s::cmd_header` (`u16_le cmd` + little-endian struct payload)
    /// wrapped inside `GNET::GamedataSend` (`opcode = 34`, `data: Octets`).
    pub fn send_gamedata_c2s(&mut self, c2s_cmd: u16, inner_le: &[u8]) -> PwResult<()> {
        let mut inner = Vec::with_capacity(2 + inner_le.len());
        inner.extend_from_slice(&c2s_cmd.to_le_bytes());
        inner.extend_from_slice(inner_le);
        let mut body = OctetsStream::with_capacity(inner.len() + 5);
        body.write_octets(&inner);
        self.send_protocol(34, body.as_slice())
    }

    /// `c2s::GET_ALL_DATA` (`0x08`): `u8 detail_inv, u8 detail_equip, u8 detail_task`.
    pub fn send_c2s_get_all_data(
        &mut self,
        detail_inv: bool,
        detail_equip: bool,
        detail_task: bool,
    ) -> PwResult<()> {
        self.send_gamedata_c2s(
            0x0008,
            &[u8::from(detail_inv), u8::from(detail_equip), u8::from(detail_task)],
        )
    }

    /// `c2s::PLAYER_MOVE` (`0x00`, `cmd_player_move` `33` bytes):
    /// `f32[3] vCurPos, f32[3] vNextPos, u16 sTime, u16 sSpeed, u8 byMoveMode, u16 wStamp`.
    pub fn send_c2s_player_move(
        &mut self,
        cur_pos: (f32, f32, f32),
        next_pos: (f32, f32, f32),
        use_time_ms: u16,
        speed_cms: u16,
        move_mode: u8,
        stamp: u16,
    ) -> PwResult<()> {
        let mut p = Vec::with_capacity(33);
        for f in [cur_pos.0, cur_pos.1, cur_pos.2, next_pos.0, next_pos.1, next_pos.2] {
            p.extend_from_slice(&f.to_le_bytes());
        }
        p.extend_from_slice(&use_time_ms.to_le_bytes());
        p.extend_from_slice(&speed_cms.to_le_bytes());
        p.push(move_mode);
        p.extend_from_slice(&stamp.to_le_bytes());
        self.send_gamedata_c2s(0x0000, &p)
    }

    /// `c2s::SELECT_TARGET` (`0x02`): `u32_le id`.
    pub fn send_c2s_select_target(&mut self, target_id: u32) -> PwResult<()> {
        self.send_gamedata_c2s(0x0002, &target_id.to_le_bytes())
    }

    /// `c2s::CAST_SKILL` (`0x29`): `i32_le skill_id, u8 force_attack, u8 target_cnt, i32_le targets[]`.
    pub fn send_c2s_cast_skill(
        &mut self,
        skill_id: u32,
        force_attack: u8,
        targets: &[u32],
    ) -> PwResult<()> {
        let cnt = targets.len().min(64);
        let mut p = Vec::with_capacity(6 + cnt * 4);
        p.extend_from_slice(&skill_id.to_le_bytes());
        p.push(force_attack);
        p.push(cnt as u8);
        for &tid in &targets[..cnt] {
            p.extend_from_slice(&tid.to_le_bytes());
        }
        self.send_gamedata_c2s(gs_c2s::CAST_SKILL, &p)
    }

    pub fn send_c2s_normal_attack(&mut self, force_attack: u8) -> PwResult<()> {
        self.send_gamedata_c2s(gs_c2s::NORMAL_ATTACK, &[force_attack])
    }

    pub fn send_c2s_pickup(&mut self, matter_id: u32, item_tid: u32) -> PwResult<()> {
        let mut p = [0u8; 8];
        p[0..4].copy_from_slice(&matter_id.to_le_bytes());
        p[4..8].copy_from_slice(&item_tid.to_le_bytes());
        self.send_gamedata_c2s(gs_c2s::PICKUP, &p)
    }

    pub fn send_c2s_hello_npc(&mut self, npc_id: u32) -> PwResult<()> {
        self.send_gamedata_c2s(gs_c2s::HELLO_NPC, &npc_id.to_le_bytes())
    }

    pub fn send_c2s_npc_service(&mut self, service_type: u32, payload: &[u8]) -> PwResult<()> {
        let mut p = Vec::with_capacity(8 + payload.len());
        p.extend_from_slice(&service_type.to_le_bytes());
        p.extend_from_slice(&(payload.len() as u32).to_le_bytes());
        p.extend_from_slice(payload);
        self.send_gamedata_c2s(gs_c2s::NPC_SEV_SERVE, &p)
    }

    pub fn send_c2s_do_emote(&mut self, emotion_idx: u16) -> PwResult<()> {
        self.send_gamedata_c2s(gs_c2s::DO_EMOTE, &emotion_idx.to_le_bytes())
    }

    pub fn send_c2s_cancel_action(&mut self) -> PwResult<()> {
        self.send_gamedata_c2s(gs_c2s::CANCEL_ACTION, &[])
    }

    pub fn send_c2s_toggle_fly(&mut self) -> PwResult<()> {
        self.send_gamedata_c2s(gs_c2s::TOGGLE_FLY, &[])
    }

    pub fn send_c2s_logout(&mut self, logout_type: i32) -> PwResult<()> {
        self.send_gamedata_c2s(gs_c2s::LOGOUT, &logout_type.to_le_bytes())
    }

    pub fn send_public_chat(&mut self, text: &str) -> PwResult<()> {
        let mut utf16 = Vec::with_capacity(text.len() * 2);
        for u in text.encode_utf16() {
            utf16.extend_from_slice(&u.to_le_bytes());
        }
        let mut body = OctetsStream::with_capacity(16 + utf16.len());
        body.write_u8(0);
        body.write_u8(0);
        body.write_u32_be(self.selected_role_id);
        body.write_u32_be(self.local_sid);
        body.write_octets(&utf16);
        body.write_octets(&[]);
        self.send_protocol(79, body.as_slice())
    }

    // -----------------------------------------------------------------------
    // Extended Inner `gs` (`GamedataSend` `34`) C2S Encoders (Inventory, Equip, Squad, Pet, Gather)
    // -----------------------------------------------------------------------

    pub fn send_c2s_move_inventory_item(&mut self, src_slot: u8, dst_slot: u8, amount: u16) -> PwResult<()> {
        let mut p = [0u8; 4];
        p[0] = src_slot;
        p[1] = dst_slot;
        p[2..4].copy_from_slice(&amount.to_le_bytes());
        self.send_gamedata_c2s(gs_c2s::MOVE_INVENTORY_ITEM, &p)
    }

    pub fn send_c2s_drop_inventory_item(&mut self, slot: u8, amount: u16) -> PwResult<()> {
        let mut p = [0u8; 3];
        p[0] = slot;
        p[1..3].copy_from_slice(&amount.to_le_bytes());
        self.send_gamedata_c2s(gs_c2s::DROP_INVENTORY_ITEM, &p)
    }

    pub fn send_c2s_exchange_inventory_item(&mut self, slot1: u8, slot2: u8) -> PwResult<()> {
        self.send_gamedata_c2s(gs_c2s::EXCHANGE_INVENTORY_ITEM, &[slot1, slot2])
    }

    pub fn send_c2s_equip_item(&mut self, inv_slot: u8, equip_slot: u8) -> PwResult<()> {
        self.send_gamedata_c2s(gs_c2s::EQUIP_ITEM, &[inv_slot, equip_slot])
    }

    pub fn send_c2s_drop_money(&mut self, amount: u32) -> PwResult<()> {
        self.send_gamedata_c2s(gs_c2s::DROP_MONEY, &amount.to_le_bytes())
    }

    pub fn send_c2s_add_status_point(&mut self, vit: i32, eng: i32, str_pt: i32, agi: i32) -> PwResult<()> {
        let mut p = Vec::with_capacity(16);
        for v in [vit, eng, str_pt, agi] {
            p.extend_from_slice(&v.to_le_bytes());
        }
        self.send_gamedata_c2s(gs_c2s::ADD_STATUS_POINT, &p)
    }

    pub fn send_c2s_team_invite(&mut self, target_player_id: u32) -> PwResult<()> {
        self.send_gamedata_c2s(gs_c2s::TEAM_INVITE, &target_player_id.to_le_bytes())
    }

    pub fn send_c2s_team_reply(&mut self, leader_id: u32, team_seq: u32, accept: bool) -> PwResult<()> {
        let mut p = Vec::with_capacity(8);
        p.extend_from_slice(&leader_id.to_le_bytes());
        p.extend_from_slice(&team_seq.to_le_bytes());
        let cmd = if accept {
            gs_c2s::TEAM_AGREE_INVITE
        } else {
            gs_c2s::TEAM_REJECT_INVITE
        };
        self.send_gamedata_c2s(cmd, &p)
    }

    pub fn send_c2s_team_leave(&mut self) -> PwResult<()> {
        self.send_gamedata_c2s(gs_c2s::TEAM_LEAVE_PARTY, &[])
    }

    pub fn send_c2s_gather_material(&mut self, matter_id: u32, tool_inv_slot: u8, tool_id: u32) -> PwResult<()> {
        let mut p = Vec::with_capacity(11);
        p.extend_from_slice(&matter_id.to_le_bytes());
        p.push(0); // where = inventory
        p.push(tool_inv_slot);
        p.extend_from_slice(&tool_id.to_le_bytes());
        p.push(0);
        self.send_gamedata_c2s(gs_c2s::GATHER_MATERIAL, &p)
    }

    pub fn send_c2s_summon_pet(&mut self, pet_index: u32) -> PwResult<()> {
        self.send_gamedata_c2s(gs_c2s::SUMMON_PET, &pet_index.to_le_bytes())
    }

    pub fn send_c2s_recall_pet(&mut self) -> PwResult<()> {
        self.send_gamedata_c2s(gs_c2s::RECALL_PET, &[])
    }

    pub fn send_c2s_pet_ctrl(&mut self, target_id: u32, pet_cmd: i32, param: i32) -> PwResult<()> {
        let mut p = Vec::with_capacity(12);
        p.extend_from_slice(&target_id.to_le_bytes());
        p.extend_from_slice(&pet_cmd.to_le_bytes());
        p.extend_from_slice(&param.to_le_bytes());
        self.send_gamedata_c2s(gs_c2s::PET_CTRL_CMD, &p)
    }

    // -----------------------------------------------------------------------
    // Outer Build 2305 `GNET` Social, Trade, Mail, Auction, Stock, Faction, & Territory War Codecs
    // -----------------------------------------------------------------------

    fn encode_utf16le_octets(s: &str) -> Vec<u8> {
        let mut out = Vec::with_capacity(s.len() * 2);
        for u in s.encode_utf16() {
            out.extend_from_slice(&u.to_le_bytes());
        }
        out
    }

    /// `GNET::PrivateChat` (`opcode = 96`).
    pub fn send_private_chat(&mut self, dst_name: &str, dst_role_id: u32, text: &str) -> PwResult<()> {
        let mut body = OctetsStream::with_capacity(64);
        body.write_u8(0); // channel = whisper
        body.write_u8(0); // emotion
        body.write_octets(&Self::encode_utf16le_octets(""));
        body.write_u32_be(self.selected_role_id);
        body.write_octets(&Self::encode_utf16le_octets(dst_name));
        body.write_u32_be(dst_role_id);
        body.write_octets(&Self::encode_utf16le_octets(text));
        body.write_octets(&[]);
        body.write_u32_be(0);
        self.send_protocol(96, body.as_slice())
    }

    /// `GNET::FactionChat` (`opcode = 4803`).
    pub fn send_faction_chat(&mut self, text: &str) -> PwResult<()> {
        let mut body = OctetsStream::with_capacity(32 + text.len() * 2);
        body.write_u8(0);
        body.write_u8(0);
        body.write_u32_be(self.selected_role_id);
        body.write_octets(&Self::encode_utf16le_octets(text));
        body.write_octets(&[]);
        body.write_u32_be(self.local_sid);
        self.send_protocol(4803, body.as_slice())
    }

    /// `GNET::GetFriends` (`opcode = 206`).
    pub fn send_get_friends(&mut self) -> PwResult<()> {
        let mut body = OctetsStream::with_capacity(8);
        body.write_u32_be(self.selected_role_id);
        body.write_u32_be(self.local_sid);
        self.send_protocol(206, body.as_slice())
    }

    /// `GNET::AddFriend` (`opcode = 202`).
    pub fn send_add_friend(&mut self, dst_role_id: u32, dst_name: &str) -> PwResult<()> {
        let mut body = OctetsStream::with_capacity(32);
        body.write_u32_be(self.selected_role_id);
        body.write_u32_be(dst_role_id);
        body.write_octets(&Self::encode_utf16le_octets(dst_name));
        body.write_u32_be(self.local_sid);
        self.send_protocol(202, body.as_slice())
    }

    /// `GNET::DelFriend` (`opcode = 212`).
    pub fn send_del_friend(&mut self, friend_role_id: u32) -> PwResult<()> {
        let mut body = OctetsStream::with_capacity(12);
        body.write_u32_be(self.selected_role_id);
        body.write_u32_be(friend_role_id);
        body.write_u32_be(self.local_sid);
        self.send_protocol(212, body.as_slice())
    }

    /// `GNET::TradeStart` (`opcode = 4001`).
    pub fn send_trade_start(&mut self, partner_role_id: u32) -> PwResult<()> {
        let mut body = OctetsStream::with_capacity(12);
        body.write_u32_be(self.selected_role_id);
        body.write_u32_be(self.local_sid);
        body.write_u32_be(partner_role_id);
        self.send_protocol(4001, body.as_slice())
    }

    /// `GNET::TradeAddGoods` (`opcode = 4004`).
    pub fn send_trade_add_goods(
        &mut self,
        trade_id: u32,
        item_id: u32,
        inv_pos: u16,
        count: u16,
        money: u32,
    ) -> PwResult<()> {
        let mut body = OctetsStream::with_capacity(28);
        body.write_u32_be(trade_id);
        body.write_u32_be(self.selected_role_id);
        body.write_u32_be(self.local_sid);
        body.write_u32_be(item_id);
        body.write_u16_be(inv_pos);
        body.write_u16_be(count);
        body.write_u32_be(money);
        self.send_protocol(4004, body.as_slice())
    }

    /// `GNET::TradeSubmit` (`opcode = 4010`), `TradeConfirm` (`4012`), `TradeDiscard` (`4014`).
    pub fn send_trade_action(&mut self, opcode: u32, trade_id: u32) -> PwResult<()> {
        let mut body = OctetsStream::with_capacity(12);
        body.write_u32_be(trade_id);
        body.write_u32_be(self.selected_role_id);
        body.write_u32_be(self.local_sid);
        self.send_protocol(opcode, body.as_slice())
    }

    /// `GNET::CheckNewMail` (`opcode = 4200`) / `GetMailList` (`opcode = 4202`).
    pub fn send_get_mail_list(&mut self) -> PwResult<()> {
        let mut body = OctetsStream::with_capacity(8);
        body.write_u32_be(self.selected_role_id);
        body.write_u32_be(self.local_sid);
        self.send_protocol(4202, body.as_slice())
    }

    /// `GNET::PlayerSendMail` (`opcode = 4212`).
    pub fn send_player_mail(
        &mut self,
        receiver_name: &str,
        title: &str,
        context: &str,
        attach_inv_pos: u8,
        attach_count: u16,
        attach_money: u32,
    ) -> PwResult<()> {
        let mut body = OctetsStream::with_capacity(96);
        body.write_u32_be(self.selected_role_id);
        body.write_u32_be(self.local_sid);
        body.write_octets(&Self::encode_utf16le_octets(receiver_name));
        body.write_octets(&Self::encode_utf16le_octets(title));
        body.write_octets(&Self::encode_utf16le_octets(context));
        body.write_u8(attach_inv_pos);
        body.write_u16_be(attach_count);
        body.write_u32_be(attach_money);
        self.send_protocol(4212, body.as_slice())
    }

    /// `GNET::AuctionList` (`opcode = 804`).
    pub fn send_auction_list(&mut self, category: u16, item_id: u32, begin: u8) -> PwResult<()> {
        let mut body = OctetsStream::with_capacity(20);
        body.write_u32_be(self.selected_role_id);
        body.write_u32_be(self.local_sid);
        body.write_u16_be(category);
        body.write_u32_be(item_id);
        body.write_u8(begin);
        body.write_u8(0);
        self.send_protocol(804, body.as_slice())
    }

    /// `GNET::AuctionBid` (`opcode = 802`).
    pub fn send_auction_bid(&mut self, auction_id: u32, bid_price: u32, bin: u8) -> PwResult<()> {
        let mut body = OctetsStream::with_capacity(20);
        body.write_u32_be(self.selected_role_id);
        body.write_u32_be(auction_id);
        body.write_u32_be(bid_price);
        body.write_u8(bin);
        body.write_u32_be(self.local_sid);
        self.send_protocol(802, body.as_slice())
    }

    /// `GNET::StockAccount` (`opcode = 407`).
    pub fn send_stock_account(&mut self) -> PwResult<()> {
        let mut body = OctetsStream::with_capacity(8);
        body.write_u32_be(self.selected_role_id);
        body.write_u32_be(self.local_sid);
        self.send_protocol(407, body.as_slice())
    }

    /// `GNET::BattleGetMap` (`opcode = 850` — Territory War `domain.data` ownership map).
    pub fn send_battle_get_map(&mut self) -> PwResult<()> {
        let mut body = OctetsStream::with_capacity(8);
        body.write_u32_be(self.selected_role_id);
        body.write_u32_be(self.local_sid);
        self.send_protocol(850, body.as_slice())
    }

    /// `GNET::GetFactionBaseInfo` (`opcode = 4814`) & `GetPlayerFactionInfo` (`opcode = 4816`).
    pub fn send_get_faction_info(&mut self, faction_id: u32) -> PwResult<()> {
        let mut body = OctetsStream::with_capacity(16);
        body.write_u32_be(self.selected_role_id);
        body.write_u32_be(self.local_sid);
        body.write_compact_uint(1);
        body.write_u32_be(faction_id);
        self.send_protocol(4814, body.as_slice())
    }

    /// `GNET::SetCustomData` (`opcode = 100` — uploads `CharacterCustomizeIni` / `CECFace` blob).
    pub fn send_set_custom_data(&mut self, custom_data: &[u8]) -> PwResult<()> {
        let mut body = OctetsStream::with_capacity(12 + custom_data.len());
        body.write_u32_be(self.selected_role_id);
        body.write_octets(custom_data);
        self.send_protocol(100, body.as_slice())
    }

    /// `GNET::GetCustomData` (`opcode = 116`).
    pub fn send_get_custom_data(&mut self, target_role_id: u32) -> PwResult<()> {
        let mut body = OctetsStream::with_capacity(16);
        body.write_u32_be(self.selected_role_id);
        body.write_u32_be(self.local_sid);
        body.write_compact_uint(1);
        body.write_u32_be(target_role_id);
        self.send_protocol(116, body.as_slice())
    }

    /// `GNET::SetUIConfig` (`opcode = 102`) & `SetHelpStates` (`opcode = 128`).
    pub fn send_set_ui_config(&mut self, ui_blob: &[u8]) -> PwResult<()> {
        let mut body = OctetsStream::with_capacity(12 + ui_blob.len());
        body.write_u32_be(self.selected_role_id);
        body.write_octets(ui_blob);
        self.send_protocol(102, body.as_slice())
    }

    pub fn send_set_help_states(&mut self, help_blob: &[u8]) -> PwResult<()> {
        let mut body = OctetsStream::with_capacity(12 + help_blob.len());
        body.write_u32_be(self.selected_role_id);
        body.write_octets(help_blob);
        self.send_protocol(128, body.as_slice())
    }

    /// `GNET::MatrixResponse` (`opcode = 552`), `AutolockSet` (`opcode = 782`), & `CashLock` (`opcode = 4260`).
    pub fn send_matrix_response(&mut self, response_code: i32) -> PwResult<()> {
        let mut body = OctetsStream::with_capacity(4);
        body.write_i32_be(response_code);
        self.send_protocol(552, body.as_slice())
    }

    pub fn send_autolock_set(&mut self, timeout_secs: i32) -> PwResult<()> {
        let mut body = OctetsStream::with_capacity(12);
        body.write_u32_be(self.selected_role_id);
        body.write_i32_be(timeout_secs);
        body.write_u32_be(self.local_sid);
        self.send_protocol(782, body.as_slice())
    }

    pub fn send_cash_lock(&mut self, password_octets: &[u8], lock: bool) -> PwResult<()> {
        let mut body = OctetsStream::with_capacity(16 + password_octets.len());
        body.write_u32_be(self.user_id);
        body.write_octets(password_octets);
        body.write_u32_be(self.local_sid);
        body.write_u8(u8::from(lock));
        self.send_protocol(4260, body.as_slice())
    }

    /// `GNET::BattleChallenge` (`852`), `BattleEnter` (`860`), `FactionOPRequest` (`4804`), `Report2GM` (`368`), & `ACAnswer` (`5032`).
    pub fn send_battle_challenge(&mut self, domain_id: u16, faction_id: u32, deposit_coins: u32) -> PwResult<()> {
        let mut body = OctetsStream::with_capacity(18);
        body.write_u32_be(self.selected_role_id);
        body.write_u16_be(domain_id);
        body.write_u32_be(faction_id);
        body.write_u32_be(deposit_coins);
        body.write_u32_be(self.local_sid);
        self.send_protocol(852, body.as_slice())
    }

    pub fn send_battle_enter(&mut self, domain_id: u16) -> PwResult<()> {
        let mut body = OctetsStream::with_capacity(10);
        body.write_u32_be(self.selected_role_id);
        body.write_u16_be(domain_id);
        body.write_u32_be(self.local_sid);
        self.send_protocol(860, body.as_slice())
    }

    pub fn send_faction_op_request(&mut self, op_type: i32, params: &[u8]) -> PwResult<()> {
        let mut body = OctetsStream::with_capacity(16 + params.len());
        body.write_i32_be(op_type);
        body.write_u32_be(self.selected_role_id);
        body.write_octets(params);
        self.send_protocol(4804, body.as_slice())
    }

    pub fn send_report_to_gm(&mut self, message: &str, map_zone: &str) -> PwResult<()> {
        let mut body = OctetsStream::with_capacity(64);
        body.write_u32_be(self.selected_role_id);
        body.write_u32_be(self.local_sid);
        let map_u16: Vec<u8> = map_zone.encode_utf16().flat_map(|u| u.to_le_bytes()).collect();
        let msg_u16: Vec<u8> = message.encode_utf16().flat_map(|u| u.to_le_bytes()).collect();
        body.write_octets(&map_u16);
        body.write_octets(&msg_u16);
        self.send_protocol(368, body.as_slice())
    }

    pub fn send_ac_answer(&mut self, question_id: i32, answer: i32) -> PwResult<()> {
        let mut body = OctetsStream::with_capacity(12);
        body.write_u32_be(self.selected_role_id);
        body.write_i32_be(question_id);
        body.write_i32_be(answer);
        self.send_protocol(5032, body.as_slice())
    }

    pub fn poll(&mut self) -> Vec<GLinkEvent> {
        let mut events = Vec::new();
        if self.stream.is_none() {
            return events;
        }

        if self.c2s_rc4.is_some() && self.last_keepalive.elapsed() >= Duration::from_secs(15) {
            self.last_keepalive = Instant::now();
            let _ = self.send_protocol(90, &[90u8]);
        }

        let mut raw_buf = [0u8; 8192];
        loop {
            let read_res = match &mut self.stream {
                Some(s) => s.read(&mut raw_buf),
                None => break,
            };
            match read_res {
                Ok(0) => {
                    let msg = "Server closed TCP connection".to_string();
                    self.disconnect();
                    self.phase = LiveConnPhase::Error(msg.clone());
                    events.push(GLinkEvent::Disconnected(msg));
                    return events;
                }
                Ok(n) => {
                    let mut chunk = raw_buf[..n].to_vec();
                    if let Some(rc4) = &mut self.s2c_rc4 {
                        rc4.apply_in_place(&mut chunk);
                    }
                    if let Some(mppc) = &mut self.s2c_mppc {
                        let decompressed = mppc.update(&chunk);
                        self.recv_plain.extend_from_slice(&decompressed);
                    } else {
                        self.recv_plain.extend_from_slice(&chunk);
                    }
                    self.drain_frames(&mut events);
                }
                Err(ref e)
                    if e.kind() == ErrorKind::WouldBlock || e.kind() == ErrorKind::Interrupted =>
                {
                    break;
                }
                Err(e) => {
                    let msg = format!("Socket error: {e}");
                    self.disconnect();
                    self.phase = LiveConnPhase::Error(msg.clone());
                    events.push(GLinkEvent::Disconnected(msg));
                    return events;
                }
            }
        }

        self.drain_frames(&mut events);
        events
    }

    fn drain_frames(&mut self, events: &mut Vec<GLinkEvent>) {
        loop {
            if self.recv_plain.is_empty() {
                break;
            }
            let mut probe = OctetsStream::from_bytes(self.recv_plain.clone());
            let Ok(opcode) = probe.read_compact_uint() else {
                break;
            };
            let Ok(len_u32) = probe.read_compact_uint() else {
                break;
            };
            let len = len_u32 as usize;
            let hdr_len = probe.position();
            if self.recv_plain.len() < hdr_len + len {
                break;
            }
            let payload = self.recv_plain[hdr_len..hdr_len + len].to_vec();
            self.recv_plain.drain(..hdr_len + len);

            if let Err(e) = self.handle_packet(opcode, &payload, events) {
                let msg = format!("Packet op={opcode} error: {e}");
                self.phase = LiveConnPhase::Error(msg.clone());
                events.push(GLinkEvent::Disconnected(msg));
                break;
            }
        }
    }

    fn handle_packet(
        &mut self,
        opcode: u32,
        payload: &[u8],
        events: &mut Vec<GLinkEvent>,
    ) -> PwResult<()> {
        let mut os = OctetsStream::from_bytes(payload);
        match opcode {
            1 => {
                let server_nonce = os.read_octets()?;
                let version = if os.remaining() >= 4 { os.read_u32_be()? } else { 0 };
                let algo = if os.remaining() >= 1 { os.read_u8()? } else { 0 };
                let edition = if os.remaining() >= 1 {
                    os.read_octets().unwrap_or_default()
                } else {
                    Vec::new()
                };
                events.push(GLinkEvent::ChallengeReceived {
                    version,
                    algo,
                    edition,
                });

                let resp = hmac_md5(&self.password_hash, &server_nonce);
                self.password_resp = resp.to_vec();

                let mut reply = OctetsStream::with_capacity(64);
                reply.write_octets(self.account.as_bytes());
                reply.write_octets(&self.password_resp);
                self.phase = LiveConnPhase::AwaitKeyExchange;
                self.send_protocol(3, reply.as_slice())?;
            }
            2 => {
                let server_nonce = os.read_octets()?;
                let _blkick = if os.remaining() >= 1 { os.read_u8()? } else { 0 };

                let nanos = Instant::now()
                    .duration_since(self.connect_started)
                    .as_nanos() as u64;
                let mut seed = Vec::with_capacity(32);
                seed.extend_from_slice(&server_nonce);
                seed.extend_from_slice(&nanos.to_le_bytes());
                seed.extend_from_slice(b"PW142_RUST_PORT");
                let client_nonce = md5_digest(&seed);

                let mut out_msg = Vec::with_capacity(self.password_resp.len() + server_nonce.len());
                out_msg.extend_from_slice(&self.password_resp);
                out_msg.extend_from_slice(&server_nonce);
                let out_key = hmac_md5(self.account.as_bytes(), &out_msg);
                self.c2s_rc4 = Some(ArcFourSecurity::new(&out_key));

                let mut ke = OctetsStream::with_capacity(24);
                ke.write_octets(&client_nonce);
                ke.write_u8(1);
                self.send_protocol(2, ke.as_slice())?;

                let mut in_msg = Vec::with_capacity(self.password_resp.len() + client_nonce.len());
                in_msg.extend_from_slice(&self.password_resp);
                in_msg.extend_from_slice(&client_nonce);
                let in_key = hmac_md5(self.account.as_bytes(), &in_msg);

                let mut leftover = core::mem::take(&mut self.recv_plain);
                let mut in_rc4 = ArcFourSecurity::new(&in_key);
                let mut in_mppc = StatefulMppcDecoder::new();
                if !leftover.is_empty() {
                    in_rc4.apply_in_place(&mut leftover);
                    let dec = in_mppc.update(&leftover);
                    self.recv_plain.extend_from_slice(&dec);
                }
                self.s2c_rc4 = Some(in_rc4);
                self.s2c_mppc = Some(in_mppc);
                self.phase = LiveConnPhase::AwaitOnlineAnnounce;
                events.push(GLinkEvent::KeyExchangeComplete);
            }
            4 => {
                self.user_id = os.read_u32_be()?;
                self.local_sid = os.read_u32_be()?;
                let _remain = if os.remaining() >= 4 { os.read_u32_be()? } else { 0 };
                let zone_id = if os.remaining() >= 1 { os.read_u8()? } else { 0 };
                events.push(GLinkEvent::OnlineAnnounce {
                    user_id: self.user_id,
                    local_sid: self.local_sid,
                    zone_id,
                });

                self.roles.clear();
                self.phase = LiveConnPhase::ListingRoles;
                let mut rl = OctetsStream::with_capacity(12);
                rl.write_u32_be(self.user_id);
                rl.write_u32_be(self.local_sid);
                rl.write_i32_be(-1);
                self.send_protocol(82, rl.as_slice())?;
            }
            5 => {
                let code = os.read_u8().unwrap_or(255);
                let info = os.read_octets().unwrap_or_default();
                let msg = String::from_utf8_lossy(&info).into_owned();
                let full = format!("Server Error {code}: {msg}");
                self.phase = LiveConnPhase::Error(full.clone());
                events.push(GLinkEvent::ServerError { code, message: full });
            }
            83 => {
                let result = os.read_i32_be()?;
                let handle = os.read_i32_be()?;
                let _uid = os.read_u32_be()?;
                let _lsid = os.read_u32_be()?;
                if result == 0 && handle != -1 && os.remaining() >= 15 {
                    if let Ok(role) = parse_role_info(&mut os) {
                        self.roles.push(role.clone());
                        events.push(GLinkEvent::RoleAdded(role));
                    }
                    let mut next_rl = OctetsStream::with_capacity(12);
                    next_rl.write_u32_be(self.user_id);
                    next_rl.write_u32_be(self.local_sid);
                    next_rl.write_i32_be(handle);
                    self.send_protocol(82, next_rl.as_slice())?;
                } else {
                    self.phase = LiveConnPhase::ReadyAtRoleSelect;
                    events.push(GLinkEvent::RoleListFinished(self.roles.len()));
                }
            }
            71 => {
                let result = os.read_i32_be()?;
                if result == 0 {
                    let rid = self.selected_role_id;
                    events.push(GLinkEvent::RoleSelected { role_id: rid });
                    self.send_enter_world(rid)?;
                    events.push(GLinkEvent::EnteredWorld { role_id: rid });
                } else {
                    let msg = format!("SelectRole rejected (result={result})");
                    self.phase = LiveConnPhase::Error(msg.clone());
                    events.push(GLinkEvent::ServerError {
                        code: result as u8,
                        message: msg,
                    });
                }
            }
            34 | 74 => {
                // Build 2305 uses bidirectional `GNET::GamedataSend` (`opcode = 34`, `0x5cc740`);
                // also accept legacy `74` (`S2CGamedata`) for backward compatibility.
                let gd = os.read_octets().unwrap_or_default();
                if gd.len() >= 2 {
                    let s2c_cmd = u16::from_le_bytes([gd[0], gd[1]]);
                    let body = gd[2..].to_vec();
                    if s2c_cmd == 0x0008 && body.len() >= 20 {
                        // Verified Build 2305 `s2c::SELF_INFO_1` (`0x0008`, `34` bytes `<iifffHHHHBBBBi`):
                        // `i32 exp, i32 sp, f32 pos[3], u16 hp, u16 mp, ...`
                        let px = f32::from_le_bytes([body[8], body[9], body[10], body[11]]);
                        let py = f32::from_le_bytes([body[12], body[13], body[14], body[15]]);
                        let pz = f32::from_le_bytes([body[16], body[17], body[18], body[19]]);
                        events.push(GLinkEvent::GsNotifyPos {
                            pos: (px, py, pz),
                            world_tag: 1,
                        });
                    } else if s2c_cmd == 0x0004 && body.len() >= 24 {
                        // Legacy `s2c::SELF_INFO_1` (`0x0004`)
                        let px = f32::from_le_bytes([body[12], body[13], body[14], body[15]]);
                        let py = f32::from_le_bytes([body[16], body[17], body[18], body[19]]);
                        let pz = f32::from_le_bytes([body[20], body[21], body[22], body[23]]);
                        events.push(GLinkEvent::GsNotifyPos {
                            pos: (px, py, pz),
                            world_tag: 1,
                        });
                    } else if s2c_cmd == 0x0025 && body.len() >= 16 {
                        // `s2c::NOTIFY_POS` (`0x0025`): `f32 vPos[3], i32 tag`
                        let px = f32::from_le_bytes([body[0], body[1], body[2], body[3]]);
                        let py = f32::from_le_bytes([body[4], body[5], body[6], body[7]]);
                        let pz = f32::from_le_bytes([body[8], body[9], body[10], body[11]]);
                        let tag = i32::from_le_bytes([body[12], body[13], body[14], body[15]]);
                        events.push(GLinkEvent::GsNotifyPos {
                            pos: (px, py, pz),
                            world_tag: tag,
                        });
                    }
                    if let Ok(decoded) = decode_gs_s2c(s2c_cmd, &body) {
                        if !matches!(decoded, GsS2cPacket::Unknown { .. }) {
                            events.push(GLinkEvent::GsDecoded(decoded));
                        }
                    }
                    events.push(GLinkEvent::GsCommand { s2c_cmd, body });
                }
            }
            79 | 80 | 133 => {
                // `PublicChat` (79), `ChatMessage` (80, Build 2305 S2C broadcast), `WorldChat` (133)
                let channel = os.read_u8().unwrap_or(0);
                let _emotion = os.read_u8().unwrap_or(0);
                let sender_id = os.read_u32_be().unwrap_or(0);
                if opcode == 79 {
                    let _lsid = os.read_u32_be().unwrap_or(0);
                }
                let msg_bytes = os.read_octets().unwrap_or_default();
                let text = decode_utf16le_null_terminated(&msg_bytes);
                events.push(GLinkEvent::ChatMessage {
                    channel,
                    sender_id,
                    text,
                });
            }
            96 => {
                // `GNET::PrivateChat` (`opcode = 96`)
                let _channel = os.read_u8().unwrap_or(0);
                let _emotion = os.read_u8().unwrap_or(0);
                let src_name = decode_utf16le_null_terminated(&os.read_octets().unwrap_or_default());
                let sender_id = os.read_u32_be().unwrap_or(0);
                let _dst_name = os.read_octets().unwrap_or_default();
                let _dst_id = os.read_u32_be().unwrap_or(0);
                let text = decode_utf16le_null_terminated(&os.read_octets().unwrap_or_default());
                events.push(GLinkEvent::PrivateChat {
                    sender_name: src_name,
                    sender_id,
                    text,
                });
            }
            4803 => {
                // `GNET::FactionChat` (`opcode = 4803`)
                let _channel = os.read_u8().unwrap_or(0);
                let _emotion = os.read_u8().unwrap_or(0);
                let sender_id = os.read_u32_be().unwrap_or(0);
                let text = decode_utf16le_null_terminated(&os.read_octets().unwrap_or_default());
                events.push(GLinkEvent::FactionChat { sender_id, text });
            }
            207 => {
                // `GNET::GetFriends_Re` (`opcode = 207`)
                let _role_id = os.read_u32_be().unwrap_or(0);
                let grp_cnt = os.read_compact_uint().unwrap_or(0) as usize;
                for _ in 0..grp_cnt.min(16) {
                    let _gid = os.read_u8().unwrap_or(0);
                    let _gname = os.read_octets().unwrap_or_default();
                }
                let f_cnt = os.read_compact_uint().unwrap_or(0) as usize;
                let mut friends = Vec::with_capacity(f_cnt.min(200));
                for _ in 0..f_cnt.min(200) {
                    if os.remaining() < 6 {
                        break;
                    }
                    let rid = os.read_u32_be().unwrap_or(0);
                    let cls = os.read_u8().unwrap_or(0);
                    let group_id = os.read_u8().unwrap_or(0);
                    let name = decode_utf16le_null_terminated(&os.read_octets().unwrap_or_default());
                    friends.push(GnetFriendEntry {
                        role_id: rid,
                        cls,
                        group_id,
                        name,
                        online_status: 0,
                    });
                }
                events.push(GLinkEvent::FriendListUpdated(friends));
            }
            214 => {
                // `GNET::FriendStatus` (`opcode = 214`)
                let role_id = os.read_u32_be().unwrap_or(0);
                let status = os.read_u8().unwrap_or(0) as i8;
                events.push(GLinkEvent::FriendStatusChanged { role_id, status });
            }
            408 => {
                // `GNET::StockAccount_Re` (`opcode = 408`)
                let _ret = os.read_i32_be().unwrap_or(0);
                let cash = os.read_i32_be().unwrap_or(0);
                let money = os.read_i32_be().unwrap_or(0);
                events.push(GLinkEvent::StockAccountUpdated { cash, money });
            }
            805 => {
                // `GNET::AuctionList_Re` (`opcode = 805`)
                let category = os.read_u16_be().unwrap_or(0);
                let _end = os.read_u8().unwrap_or(0);
                let cnt = os.read_compact_uint().unwrap_or(0) as usize;
                let mut items = Vec::with_capacity(cnt.min(64));
                for _ in 0..cnt.min(64) {
                    if os.remaining() < 26 {
                        break;
                    }
                    items.push(GnetAuctionEntry {
                        auction_id: os.read_u32_be().unwrap_or(0),
                        bid_price: os.read_u32_be().unwrap_or(0),
                        bin_price: os.read_u32_be().unwrap_or(0),
                        end_time: os.read_u32_be().unwrap_or(0),
                        item_id: os.read_u32_be().unwrap_or(0),
                        count: os.read_u16_be().unwrap_or(1),
                        seller_id: os.read_u32_be().unwrap_or(0),
                        bidder_id: os.read_u32_be().unwrap_or(0),
                    });
                }
                events.push(GLinkEvent::AuctionListReceived { category, items });
            }
            851 => {
                // `GNET::BattleGetMap_Re` (`opcode = 851`)
                let _ret = os.read_u16_be().unwrap_or(0);
                let _status = os.read_u16_be().unwrap_or(0);
                let cnt = os.read_compact_uint().unwrap_or(0) as usize;
                let mut domains = Vec::with_capacity(cnt.min(64));
                for _ in 0..cnt.min(64) {
                    if os.remaining() < 15 {
                        break;
                    }
                    domains.push(GnetTerritoryStatus {
                        domain_id: os.read_u16_be().unwrap_or(0),
                        status: os.read_u8().unwrap_or(0),
                        owner_faction_id: os.read_u32_be().unwrap_or(0),
                        challenger_faction_id: os.read_u32_be().unwrap_or(0),
                        battle_end_timestamp: os.read_i32_be().unwrap_or(0),
                    });
                }
                events.push(GLinkEvent::BattleMapReceived(domains));
            }
            4002 | 4005 | 4011 | 4013 | 4016 => {
                // `TradeStart_Re` / `TradeAddGoods_Re` / `TradeSubmit_Re` / `TradeConfirm_Re` / `TradeEnd`
                let result = os.read_i32_be().unwrap_or(0);
                let trade_id = os.read_u32_be().unwrap_or(0);
                let partner_id = os.read_u32_be().unwrap_or(0);
                events.push(GLinkEvent::TradeEvent {
                    opcode,
                    trade_id,
                    partner_id,
                    result,
                });
            }
            4201 => {
                // `GNET::AnnounceNewMail` (`opcode = 4201`)
                let _rid = os.read_u32_be().unwrap_or(0);
                let _lsid = os.read_u32_be().unwrap_or(0);
                let remain_time = os.read_i32_be().unwrap_or(0);
                events.push(GLinkEvent::NewMailAnnounced { remain_time });
            }
            4203 => {
                // `GNET::GetMailList_Re` (`opcode = 4203`)
                let _ret = os.read_i32_be().unwrap_or(0);
                let _rid = os.read_u32_be().unwrap_or(0);
                let _lsid = os.read_u32_be().unwrap_or(0);
                let cnt = os.read_compact_uint().unwrap_or(0) as usize;
                let mut mails = Vec::with_capacity(cnt.min(64));
                for _ in 0..cnt.min(64) {
                    if os.remaining() < 11 {
                        break;
                    }
                    let mail_id = os.read_u8().unwrap_or(0);
                    let sender_id = os.read_u32_be().unwrap_or(0);
                    let send_type = os.read_u8().unwrap_or(0);
                    let receiver_stamp = os.read_i32_be().unwrap_or(0);
                    let title = decode_utf16le_null_terminated(&os.read_octets().unwrap_or_default());
                    let sender_name = decode_utf16le_null_terminated(&os.read_octets().unwrap_or_default());
                    let attribute = os.read_u8().unwrap_or(0);
                    mails.push(GnetMailHeader {
                        mail_id,
                        sender_id,
                        send_type,
                        receiver_stamp,
                        attribute,
                        title,
                        sender_name,
                    });
                }
                events.push(GLinkEvent::MailListReceived(mails));
            }
            4815 => {
                // `GNET::GetFactionBaseInfo_Re` (`opcode = 4815`)
                let _rid = os.read_u32_be().unwrap_or(0);
                let _ret = os.read_i32_be().unwrap_or(0);
                let cnt = os.read_compact_uint().unwrap_or(0) as usize;
                for _ in 0..cnt.min(16) {
                    if os.remaining() < 8 {
                        break;
                    }
                    let faction_id = os.read_u32_be().unwrap_or(0);
                    let name = decode_utf16le_null_terminated(&os.read_octets().unwrap_or_default());
                    let level = os.read_u8().unwrap_or(1);
                    let member_count = os.read_u16_be().unwrap_or(1);
                    let announce = decode_utf16le_null_terminated(&os.read_octets().unwrap_or_default());
                    events.push(GLinkEvent::FactionInfoUpdated(GnetFactionSummary {
                        faction_id,
                        name,
                        level,
                        member_count,
                        announce,
                    }));
                }
            }
            105 => {
                let _ret = os.read_i32_be().unwrap_or(0);
                let role_id = os.read_u32_be().unwrap_or(0);
                let _sid = os.read_u32_be().unwrap_or(0);
                let ui_bytes = os.read_octets().unwrap_or_default();
                events.push(GLinkEvent::UiConfigReceived { role_id, ui_bytes });
            }
            117 => {
                let _ret = os.read_i32_be().unwrap_or(0);
                let _rid = os.read_u32_be().unwrap_or(0);
                let _sid = os.read_u32_be().unwrap_or(0);
                let role_id = os.read_u32_be().unwrap_or(0);
                let custom_bytes = os.read_octets().unwrap_or_default();
                events.push(GLinkEvent::CustomDataReceived { role_id, custom_bytes });
            }
            131 => {
                let _ret = os.read_i32_be().unwrap_or(0);
                let role_id = os.read_u32_be().unwrap_or(0);
                let _sid = os.read_u32_be().unwrap_or(0);
                let help_bytes = os.read_octets().unwrap_or_default();
                events.push(GLinkEvent::HelpStatesReceived { role_id, help_bytes });
            }
            551 => {
                let algorithm = os.read_i32_be().unwrap_or(0);
                let nonce = os.read_u32_be().unwrap_or(0);
                events.push(GLinkEvent::MatrixChallenge { algorithm, nonce });
            }
            783 => {
                let retcode = os.read_i32_be().unwrap_or(0);
                let timeout_secs = os.read_i32_be().unwrap_or(0);
                events.push(GLinkEvent::AutolockUpdated { timeout_secs, retcode });
            }
            853 | 855 | 861 | 867 => {
                let retcode = os.read_i32_be().unwrap_or(0);
                let domain_id = os.read_u16_be().unwrap_or(0);
                events.push(GLinkEvent::BattleActionResult { opcode, domain_id, retcode });
            }
            4261 | 4264 => {
                let retcode = os.read_i32_be().unwrap_or(0);
                let locked = os.read_u8().unwrap_or(0) != 0;
                events.push(GLinkEvent::CashLockUpdated { locked, retcode });
            }
            4502..=4516 | 4805 => {
                let op_type = os.read_i32_be().unwrap_or(0);
                let retcode = os.read_i32_be().unwrap_or(0);
                events.push(GLinkEvent::FactionOpResult { opcode, op_type, retcode });
            }
            5031 => {
                let question_type = os.read_i32_be().unwrap_or(0);
                let question_id = os.read_i32_be().unwrap_or(0);
                let image_bytes = os.read_octets().unwrap_or_default();
                events.push(GLinkEvent::AntiCheatQuestion {
                    question_type,
                    question_id,
                    image_bytes,
                });
            }
            _ => {
                events.push(GLinkEvent::ServerPacket {
                    opcode,
                    payload_len: payload.len(),
                });
            }
        }
        Ok(())
    }
}

fn parse_role_info(os: &mut OctetsStream) -> PwResult<CharacterSummary> {
    let role_id = os.read_u32_be()?;
    let gender = os.read_u8()?;
    let race = os.read_u8()?;
    let occupation = os.read_u8()?;
    let level = os.read_i32_be()?;
    let level2 = os.read_i32_be()?;
    let name_bytes = os.read_octets()?;
    let name = decode_utf16le_null_terminated(&name_bytes);
    let _custom_data = os.read_octets()?;

    let eq_count = os.read_compact_uint()? as usize;
    for _ in 0..eq_count {
        let _id = os.read_u32_be()?;
        let _pos = os.read_i32_be()?;
        let _count = os.read_i32_be()?;
        let _max_count = os.read_i32_be()?;
        let _data = os.read_octets()?;
        let _proctype = os.read_u32_be()?;
        let _expire = os.read_i32_be()?;
        let _guid1 = os.read_u32_be()?;
        let _guid2 = os.read_u32_be()?;
        let _mask = os.read_u32_be()?;
    }

    let _status = os.read_u8()?;
    let _del_t = os.read_i32_be()?;
    let _create_t = os.read_i32_be()?;
    let _last_t = os.read_i32_be()?;
    let posx = f32::from_bits(os.read_u32_be()?);
    let posy = f32::from_bits(os.read_u32_be()?);
    let posz = f32::from_bits(os.read_u32_be()?);
    let world_tag = os.read_i32_be().unwrap_or(1);

    Ok(CharacterSummary {
        role_id,
        name,
        gender,
        race,
        occupation,
        level,
        level2,
        pos: (posx, posy, posz),
        world_tag,
    })
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::net::TcpListener;
    use std::thread;

    fn mppc_encode_literals_block(raw: &[u8]) -> Vec<u8> {
        let mut bits: Vec<u8> = Vec::with_capacity(raw.len() * 9 + 16);
        let push_bits = |bits: &mut Vec<u8>, val: u32, count: usize| {
            for i in (0..count).rev() {
                bits.push(((val >> i) & 1) as u8);
            }
        };
        for &b in raw {
            if b < 0x80 {
                push_bits(&mut bits, b as u32, 8);
            } else {
                push_bits(&mut bits, 0b10_0000000 | ((b & 0x7F) as u32), 9);
            }
        }
        push_bits(&mut bits, 0b1111000000, 10);
        while bits.len() % 8 != 0 {
            bits.push(0);
        }
        let mut out = Vec::with_capacity(bits.len() / 8);
        for chunk in bits.chunks_exact(8) {
            let mut byte = 0u8;
            for &bit in chunk {
                byte = (byte << 1) | bit;
            }
            out.push(byte);
        }
        out
    }

    #[test]
    fn test_live_glinkd_handshake_rc4_mppc_and_role_list_roundtrip() {
        let listener = TcpListener::bind("127.0.0.1:0").unwrap();
        let addr = listener.local_addr().unwrap();

        let server = thread::spawn(move || {
            let (mut sock, _) = listener.accept().unwrap();
            sock.set_read_timeout(Some(Duration::from_secs(3))).unwrap();

            let server_nonce = b"0123456789ABCDEF";
            let mut ch = OctetsStream::new();
            ch.write_octets(server_nonce);
            ch.write_u32_be(0x0001_0402);
            ch.write_u8(0);
            ch.write_octets(b"1.4.2");
            let mut f1 = OctetsStream::new();
            f1.write_compact_uint(1);
            f1.write_compact_uint(ch.as_slice().len() as u32);
            f1.write_raw(ch.as_slice());
            sock.write_all(f1.as_slice()).unwrap();

            let mut buf = [0u8; 256];
            let n = sock.read(&mut buf).unwrap();
            let mut rs = OctetsStream::from_bytes(&buf[..n]);
            assert_eq!(rs.read_compact_uint().unwrap(), 3);
            let rlen = rs.read_compact_uint().unwrap() as usize;
            let mut rbody = OctetsStream::from_bytes(rs.read_raw(rlen).unwrap());
            let ident = rbody.read_octets().unwrap();
            let resp = rbody.read_octets().unwrap();
            assert_eq!(rbody.remaining(), 0, "Response MUST have exactly 2 fields!");
            assert_eq!(ident, b"admin");
            let expected_pwd = md5_digest(b"admin123456");
            let expected_resp = hmac_md5(&expected_pwd, server_nonce);
            assert_eq!(resp.as_slice(), expected_resp.as_slice());

            let ke_nonce = b"FEDCBA9876543210";
            let mut ke = OctetsStream::new();
            ke.write_octets(ke_nonce);
            ke.write_u8(0);
            let mut f2 = OctetsStream::new();
            f2.write_compact_uint(2);
            f2.write_compact_uint(ke.as_slice().len() as u32);
            f2.write_raw(ke.as_slice());
            sock.write_all(f2.as_slice()).unwrap();

            let mut c2s_msg = Vec::new();
            c2s_msg.extend_from_slice(&resp);
            c2s_msg.extend_from_slice(ke_nonce);
            let mut c2s_dec = ArcFourSecurity::new(&hmac_md5(b"admin", &c2s_msg));

            let n2 = sock.read(&mut buf).unwrap();
            let mut ke_c2s = buf[..n2].to_vec();
            c2s_dec.apply_in_place(&mut ke_c2s);
            let mut ks = OctetsStream::from_bytes(ke_c2s);
            assert_eq!(ks.read_compact_uint().unwrap(), 2);
            let klen = ks.read_compact_uint().unwrap() as usize;
            let mut kbody = OctetsStream::from_bytes(ks.read_raw(klen).unwrap());
            let cli_nonce = kbody.read_octets().unwrap();
            let blkick = kbody.read_u8().unwrap();
            assert_eq!(blkick, 1);
            assert_eq!(kbody.remaining(), 0, "KeyExchange blkickuser MUST be 1 byte!");

            let mut s2c_msg = Vec::new();
            s2c_msg.extend_from_slice(&resp);
            s2c_msg.extend_from_slice(&cli_nonce);
            let mut s2c_enc = ArcFourSecurity::new(&hmac_md5(b"admin", &s2c_msg));

            let mut oa = OctetsStream::new();
            oa.write_u32_be(1024);
            oa.write_u32_be(77);
            oa.write_u32_be(0);
            oa.write_u8(1);
            oa.write_i32_be(0);
            oa.write_i32_be(0);
            oa.write_i32_be(0);
            oa.write_u8(0);
            let mut f4 = OctetsStream::new();
            f4.write_compact_uint(4);
            f4.write_compact_uint(oa.as_slice().len() as u32);
            f4.write_raw(oa.as_slice());
            let mut mppc_oa = mppc_encode_literals_block(f4.as_slice());
            s2c_enc.apply_in_place(&mut mppc_oa);
            sock.write_all(&mppc_oa).unwrap();

            let n3 = sock.read(&mut buf).unwrap();
            let mut rl_c2s = buf[..n3].to_vec();
            c2s_dec.apply_in_place(&mut rl_c2s);
            let mut rls = OctetsStream::from_bytes(rl_c2s);
            assert_eq!(rls.read_compact_uint().unwrap(), 82);

            let mut rre = OctetsStream::new();
            rre.write_i32_be(0);
            rre.write_i32_be(-1);
            rre.write_u32_be(1024);
            rre.write_u32_be(77);
            let mut f83 = OctetsStream::new();
            f83.write_compact_uint(83);
            f83.write_compact_uint(rre.as_slice().len() as u32);
            f83.write_raw(rre.as_slice());
            let mut mppc_83 = mppc_encode_literals_block(f83.as_slice());
            s2c_enc.apply_in_place(&mut mppc_83);
            sock.write_all(&mppc_83).unwrap();

            // 7. Read C2S SelectRole (op 70), send SelectRole_Re (op 71), and read C2S EnterWorld (op 72)!
            let n4 = sock.read(&mut buf).unwrap();
            let mut sr_c2s = buf[..n4].to_vec();
            c2s_dec.apply_in_place(&mut sr_c2s);
            let mut srs = OctetsStream::from_bytes(sr_c2s);
            assert_eq!(srs.read_compact_uint().unwrap(), 70);

            let mut sre = OctetsStream::new();
            sre.write_i32_be(0);
            sre.write_compact_uint(0);
            let mut f71 = OctetsStream::new();
            f71.write_compact_uint(71);
            f71.write_compact_uint(sre.as_slice().len() as u32);
            f71.write_raw(sre.as_slice());
            let mut mppc_71 = mppc_encode_literals_block(f71.as_slice());
            s2c_enc.apply_in_place(&mut mppc_71);
            sock.write_all(&mppc_71).unwrap();

            let n5 = sock.read(&mut buf).unwrap();
            let mut ew_c2s = buf[..n5].to_vec();
            c2s_dec.apply_in_place(&mut ew_c2s);
            let mut ews = OctetsStream::from_bytes(ew_c2s);
            assert_eq!(ews.read_compact_uint().unwrap(), 72);
        });

        let mut client = GLinkLiveClient::new(addr.to_string());
        client
            .connect_and_login(&addr.to_string(), "Admin", "123456")
            .unwrap();

        let deadline = Instant::now() + Duration::from_secs(3);
        while Instant::now() < deadline
            && client.phase != LiveConnPhase::ReadyAtRoleSelect
            && !matches!(client.phase, LiveConnPhase::Error(_))
        {
            let _ = client.poll();
            thread::sleep(Duration::from_millis(5));
        }

        assert_eq!(client.phase, LiveConnPhase::ReadyAtRoleSelect);
        assert_eq!(client.user_id, 1024);
        assert_eq!(client.local_sid, 77);

        client.select_and_enter_role(2048).unwrap();
        while Instant::now() < deadline
            && client.phase != LiveConnPhase::InWorld
            && !matches!(client.phase, LiveConnPhase::Error(_))
        {
            let _ = client.poll();
            thread::sleep(Duration::from_millis(5));
        }
        assert_eq!(client.phase, LiveConnPhase::InWorld);
        server.join().unwrap();
    }

    #[test]
    fn test_build2305_inner_gs_s2c_decoders_and_encoders() {
        use crate::{
            decode_gs_s2c, encode_gs_s2c_damage_info, encode_gs_s2c_npc_enter_slice,
            encode_gs_s2c_skill_data, GsNpcSliceInfo, GsS2cPacket, GsSkillEntry,
        };

        let npc_in = GsNpcSliceInfo {
            nid: 0x8000_0105,
            tid: 16215,
            vis_tid: 16215,
            pos: (1292.0, 219.61, 1132.0),
            dir: 64,
            state: 0,
        };
        let npc_wire = encode_gs_s2c_npc_enter_slice(&npc_in);
        let cmd = u16::from_le_bytes([npc_wire[0], npc_wire[1]]);
        assert_eq!(decode_gs_s2c(cmd, &npc_wire[2..]).unwrap(), GsS2cPacket::NpcEnterSlice(npc_in));

        let dmg_wire = encode_gs_s2c_damage_info(2048, 0x8000_0105, 1337, 0x01);
        let dcmd = u16::from_le_bytes([dmg_wire[0], dmg_wire[1]]);
        assert_eq!(
            decode_gs_s2c(dcmd, &dmg_wire[2..]).unwrap(),
            GsS2cPacket::DamageInfo {
                attacker_id: 2048,
                target_id: 0x8000_0105,
                damage: 1337,
                flags: 0x01,
            }
        );

        let skills = vec![
            GsSkillEntry { skill_id: 1, level: 10, ability: 0 },
            GsSkillEntry { skill_id: 312, level: 5, ability: 12 },
        ];
        let sk_wire = encode_gs_s2c_skill_data(&skills);
        let scmd = u16::from_le_bytes([sk_wire[0], sk_wire[1]]);
        assert_eq!(decode_gs_s2c(scmd, &sk_wire[2..]).unwrap(), GsS2cPacket::SkillData(skills));

        // Verify TeamData (`0x001E`) & PetRoom (`0x0108`) S2C round-trips
        let members = vec![crate::GsTeamMemberInfo {
            member_id: 2048,
            level: 85,
            combat_state: 1,
            pk_level: 0,
            hp: 9420,
            mp: 4100,
            max_hp: 10000,
            max_mp: 4500,
        }];
        let tm_wire = crate::encode_gs_s2c_team_data(2048, 777, &members);
        let tcmd = u16::from_le_bytes([tm_wire[0], tm_wire[1]]);
        assert_eq!(
            decode_gs_s2c(tcmd, &tm_wire[2..]).unwrap(),
            GsS2cPacket::TeamData {
                leader_id: 2048,
                team_seq: 777,
                members,
            }
        );

        let pets = vec![crate::GsPetSlotInfo {
            pet_index: 0,
            pet_tid: 20194,
            level: 73,
            hp: 4820,
            max_hp: 4820,
            loyalty: 999,
            hunger: 0,
        }];
        let pet_wire = crate::encode_gs_s2c_pet_room(5, &pets);
        let pcmd = u16::from_le_bytes([pet_wire[0], pet_wire[1]]);
        assert_eq!(
            decode_gs_s2c(pcmd, &pet_wire[2..]).unwrap(),
            GsS2cPacket::PetRoom { capacity: 5, pets }
        );

        // Verify outer GNET BattleGetMap_Re (`851`) & StockAccount_Re (`408`) decoding
        let mut client = GLinkLiveClient::new("127.0.0.1:29000");
        let mut bmap = OctetsStream::new();
        bmap.write_u16_be(0);
        bmap.write_u16_be(1);
        bmap.write_compact_uint(2);
        for (did, owner) in [(1u16, 101u32), (23u16, 202u32)] {
            bmap.write_u16_be(did);
            bmap.write_u8(1);
            bmap.write_u32_be(owner);
            bmap.write_u32_be(0);
            bmap.write_i32_be(1_700_000_000);
        }
        let mut evs = Vec::new();
        client.handle_packet(851, bmap.as_slice(), &mut evs).unwrap();
        assert!(matches!(evs.as_slice(), [GLinkEvent::BattleMapReceived(v)] if v.len() == 2 && v[1].domain_id == 23));

        // Verify all 210 genuine `GNET::*` classes are present in `GNET_PROTOCOL_REGISTRY`
        let gnet_count = crate::GNET_PROTOCOL_REGISTRY
            .iter()
            .filter(|d| d.class_name.starts_with("GNET::"))
            .count();
        assert_eq!(gnet_count, 210);

        // Verify extended `s2c` (`ELF_VIGOR`, `REFINE_RESULT`, `PUBLIC_QUEST_INFO`) & `c2s` encoders
        let mut elf_body = Vec::new();
        elf_body.extend_from_slice(&120i32.to_le_bytes());
        elf_body.extend_from_slice(&150i32.to_le_bytes());
        elf_body.extend_from_slice(&200i32.to_le_bytes());
        assert_eq!(
            decode_gs_s2c(crate::gs_s2c::ELF_VIGOR, &elf_body).unwrap(),
            GsS2cPacket::ElfVigor {
                vigor: 120,
                max_vigor: 150,
                vigor_gen_100x: 200,
            }
        );
        assert_eq!(crate::encode_c2s_refine_equip(3, 14820, 15049).len(), 12);
        assert_eq!(crate::encode_c2s_npc_buy_item(0, 8621, 0, 5).len(), 22);
        assert_eq!(crate::encode_c2s_cast_elf_skill(1801, 0, &[0x8000_0105]).len(), 10);
    }
}
