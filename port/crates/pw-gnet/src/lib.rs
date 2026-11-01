//! `pw-gnet` — Perfect World 1.4.2 `GNET` Wire Framing, Crypto (`MD5`, `HMAC-MD5`, `RC4`, `MPPC`),
//! `210+` Recovered Protocol Registry, and `CecGameSession` Handshake State Machine.
//!
//! Directly mirrors `CECGameSession` (`0x5d8c60.c`, `0x5d9700.c`, `0x5d97a0.c`) and `GNET::Protocol`.

pub mod gamedata;
pub mod generated_opcodes;
pub mod live_client;
pub use gamedata::{
    c2s as gs_c2s, decode_gs_s2c, encode_c2s_autolock_open, encode_c2s_cast_elf_skill,
    encode_c2s_elf_add_attribute, encode_c2s_enchase_equip, encode_c2s_identify_equip,
    encode_c2s_npc_buy_item, encode_c2s_npc_sell_item, encode_c2s_open_booth,
    encode_c2s_produce_item, encode_c2s_refine_equip, encode_c2s_repair_all,
    encode_c2s_switch_fashion_mode, encode_c2s_toggle_pk_mode, encode_c2s_trashbox_money,
    encode_gs_s2c_damage_info, encode_gs_s2c_npc_enter_slice, encode_gs_s2c_pet_room,
    encode_gs_s2c_skill_data, encode_gs_s2c_team_data, s2c as gs_s2c, GsExtProp,
    GsInventorySlot, GsMatterSliceInfo, GsNpcSliceInfo, GsPetSlotInfo, GsPlayerSliceInfo,
    GsS2cPacket, GsSelfInfo1, GsSkillEntry, GsTeamMemberInfo,
};
pub use generated_opcodes::{GnetProtocolDescriptor, GNET_PROTOCOL_REGISTRY};
pub use live_client::{
    CharacterSummary, GLinkEvent, GLinkLiveClient, GnetAuctionEntry, GnetFactionSummary,
    GnetFriendEntry, GnetMailHeader, GnetTerritoryStatus, LiveConnPhase, StatefulMppcDecoder,
};

use pw_core::{PwError, PwResult};

// ---------------------------------------------------------------------------
// 1. GNET `OctetsStream` & `CompactUINT` Framing
// ---------------------------------------------------------------------------

#[derive(Debug, Clone, Default, PartialEq, Eq)]
pub struct OctetsStream {
    buf: Vec<u8>,
    pos: usize,
}

impl OctetsStream {
    pub fn new() -> Self {
        Self { buf: Vec::new(), pos: 0 }
    }

    pub fn with_capacity(cap: usize) -> Self {
        Self {
            buf: Vec::with_capacity(cap),
            pos: 0,
        }
    }

    pub fn position(&self) -> usize {
        self.pos
    }

    pub fn write_raw(&mut self, bytes: &[u8]) {
        self.buf.extend_from_slice(bytes);
    }

    pub fn from_bytes(bytes: impl Into<Vec<u8>>) -> Self {
        Self { buf: bytes.into(), pos: 0 }
    }

    pub fn as_slice(&self) -> &[u8] {
        &self.buf
    }

    pub fn into_vec(self) -> Vec<u8> {
        self.buf
    }

    pub fn remaining(&self) -> usize {
        self.buf.len().saturating_sub(self.pos)
    }

    pub fn write_compact_uint(&mut self, v: u32) {
        if v < 0x80 {
            self.buf.push(v as u8);
        } else if v < 0x4000 {
            self.buf.extend_from_slice(&((v as u16) | 0x8000).to_be_bytes());
        } else if v < 0x2000_0000 {
            self.buf.extend_from_slice(&(v | 0xc000_0000).to_be_bytes());
        } else {
            self.buf.push(0xe0);
            self.buf.extend_from_slice(&v.to_be_bytes());
        }
    }

    pub fn read_compact_uint(&mut self) -> PwResult<u32> {
        let b0 = self.read_u8()?;
        match b0 & 0xe0 {
            0xe0 => self.read_u32_be(),
            0xc0 => {
                let b1 = self.read_u8()?;
                let b2 = self.read_u8()?;
                let b3 = self.read_u8()?;
                Ok(u32::from_be_bytes([b0 & 0x1f, b1, b2, b3]))
            }
            0x80 | 0xa0 => {
                let b1 = self.read_u8()?;
                Ok(u16::from_be_bytes([b0 & 0x3f, b1]) as u32)
            }
            _ => Ok(b0 as u32),
        }
    }

    pub fn write_u8(&mut self, v: u8) {
        self.buf.push(v);
    }

    pub fn read_u8(&mut self) -> PwResult<u8> {
        if self.pos >= self.buf.len() {
            return Err(PwError::UnexpectedEof {
                offset: self.pos,
                needed: 1,
                available: 0,
            });
        }
        let b = self.buf[self.pos];
        self.pos += 1;
        Ok(b)
    }

    pub fn write_u32_be(&mut self, v: u32) {
        self.buf.extend_from_slice(&v.to_be_bytes());
    }

    pub fn read_u32_be(&mut self) -> PwResult<u32> {
        let b = self.read_raw(4)?;
        Ok(u32::from_be_bytes([b[0], b[1], b[2], b[3]]))
    }

    pub fn write_i32_be(&mut self, v: i32) {
        self.buf.extend_from_slice(&v.to_be_bytes());
    }

    pub fn read_i32_be(&mut self) -> PwResult<i32> {
        Ok(self.read_u32_be()? as i32)
    }

    pub fn write_u16_be(&mut self, v: u16) {
        self.buf.extend_from_slice(&v.to_be_bytes());
    }

    pub fn read_u16_be(&mut self) -> PwResult<u16> {
        let b = self.read_raw(2)?;
        Ok(u16::from_be_bytes([b[0], b[1]]))
    }

    pub fn write_u16_le(&mut self, v: u16) {
        self.buf.extend_from_slice(&v.to_le_bytes());
    }

    pub fn read_u16_le(&mut self) -> PwResult<u16> {
        let b = self.read_raw(2)?;
        Ok(u16::from_le_bytes([b[0], b[1]]))
    }

    pub fn write_octets(&mut self, data: &[u8]) {
        self.write_compact_uint(data.len() as u32);
        self.buf.extend_from_slice(data);
    }

    pub fn read_octets(&mut self) -> PwResult<Vec<u8>> {
        let len = self.read_compact_uint()? as usize;
        Ok(self.read_raw(len)?.to_vec())
    }

    pub fn read_raw(&mut self, len: usize) -> PwResult<&[u8]> {
        if self.remaining() < len {
            return Err(PwError::UnexpectedEof {
                offset: self.pos,
                needed: len,
                available: self.remaining(),
            });
        }
        let s = &self.buf[self.pos..self.pos + len];
        self.pos += len;
        Ok(s)
    }

    pub fn encode_packet(opcode: u32, payload: &[u8]) -> Vec<u8> {
        let mut frame = OctetsStream::new();
        frame.write_compact_uint(opcode);
        frame.write_octets(payload);
        frame.into_vec()
    }

    pub fn decode_packet(&mut self) -> PwResult<(u32, Vec<u8>)> {
        let opcode = self.read_compact_uint()?;
        let payload = self.read_octets()?;
        Ok((opcode, payload))
    }
}

// ---------------------------------------------------------------------------
// 2. Pure-Rust RFC 1321 MD5 & RFC 2104 HMAC-MD5 (`0x5d8c60.c` / `0x5d9700.c`)
// ---------------------------------------------------------------------------

const MD5_S: [u32; 64] = [
    7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
    5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
    4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
    6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21,
];

const MD5_K: [u32; 64] = [
    0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee, 0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
    0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be, 0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
    0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa, 0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
    0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed, 0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
    0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c, 0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
    0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05, 0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
    0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039, 0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
    0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1, 0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391,
];

pub fn md5_digest(input: &[u8]) -> [u8; 16] {
    let mut a0: u32 = 0x6745_2301;
    let mut b0: u32 = 0xefcd_ab89;
    let mut c0: u32 = 0x98ba_dcfe;
    let mut d0: u32 = 0x1032_5476;

    let bit_len = (input.len() as u64).wrapping_mul(8);
    let mut msg = input.to_vec();
    msg.push(0x80);
    while (msg.len() % 64) != 56 {
        msg.push(0);
    }
    msg.extend_from_slice(&bit_len.to_le_bytes());

    for chunk in msg.chunks_exact(64) {
        let mut m = [0u32; 16];
        for (i, w) in chunk.chunks_exact(4).enumerate() {
            m[i] = u32::from_le_bytes([w[0], w[1], w[2], w[3]]);
        }
        let (mut a, mut b, mut c, mut d) = (a0, b0, c0, d0);
        for i in 0..64 {
            let (f, g) = if i < 16 {
                ((b & c) | ((!b) & d), i)
            } else if i < 32 {
                ((d & b) | ((!d) & c), (5 * i + 1) % 16)
            } else if i < 48 {
                (b ^ c ^ d, (3 * i + 5) % 16)
            } else {
                (c ^ (b | (!d)), (7 * i) % 16)
            };
            let temp = d;
            d = c;
            c = b;
            let sum = a.wrapping_add(f).wrapping_add(MD5_K[i]).wrapping_add(m[g]);
            b = b.wrapping_add(sum.rotate_left(MD5_S[i]));
            a = temp;
        }
        a0 = a0.wrapping_add(a);
        b0 = b0.wrapping_add(b);
        c0 = c0.wrapping_add(c);
        d0 = d0.wrapping_add(d);
    }

    let mut out = [0u8; 16];
    out[0..4].copy_from_slice(&a0.to_le_bytes());
    out[4..8].copy_from_slice(&b0.to_le_bytes());
    out[8..12].copy_from_slice(&c0.to_le_bytes());
    out[12..16].copy_from_slice(&d0.to_le_bytes());
    out
}

pub fn hmac_md5(key: &[u8], data: &[u8]) -> [u8; 16] {
    let mut k_block = [0u8; 64];
    if key.len() > 64 {
        let hashed = md5_digest(key);
        k_block[..16].copy_from_slice(&hashed);
    } else {
        k_block[..key.len()].copy_from_slice(key);
    }
    let mut ipad = [0x36u8; 64];
    let mut opad = [0x5cu8; 64];
    for i in 0..64 {
        ipad[i] ^= k_block[i];
        opad[i] ^= k_block[i];
    }
    let mut inner = Vec::with_capacity(64 + data.len());
    inner.extend_from_slice(&ipad);
    inner.extend_from_slice(data);
    let inner_hash = md5_digest(&inner);

    let mut outer = Vec::with_capacity(80);
    outer.extend_from_slice(&opad);
    outer.extend_from_slice(&inner_hash);
    md5_digest(&outer)
}

// ---------------------------------------------------------------------------
// 3. `ARCFourSecurity` (RC4) & `MPPC` 8KB History Compressor/Decompressor
// ---------------------------------------------------------------------------

#[derive(Clone)]
pub struct ArcFourSecurity {
    state: [u8; 256],
    x: u8,
    y: u8,
}

impl ArcFourSecurity {
    pub fn new(key: &[u8]) -> Self {
        let mut state = [0u8; 256];
        for (i, slot) in state.iter_mut().enumerate() {
            *slot = i as u8;
        }
        if !key.is_empty() {
            let mut j = 0u8;
            for i in 0..256 {
                j = j.wrapping_add(state[i]).wrapping_add(key[i % key.len()]);
                state.swap(i, j as usize);
            }
        }
        Self { state, x: 0, y: 0 }
    }

    pub fn apply_in_place(&mut self, buf: &mut [u8]) {
        for byte in buf.iter_mut() {
            self.x = self.x.wrapping_add(1);
            let sx = self.state[self.x as usize];
            self.y = self.y.wrapping_add(sx);
            let sy = self.state[self.y as usize];
            self.state[self.x as usize] = sy;
            self.state[self.y as usize] = sx;
            let k = self.state[sx.wrapping_add(sy) as usize];
            *byte ^= k;
        }
    }
}

/// Bitstream writer used by `GNET::Compress` (MPPC RFC 2118 / Perfect World 8KB ring buffer).
struct BitWriter {
    out: Vec<u8>,
    acc: u32,
    bits: u8,
}

impl BitWriter {
    fn new() -> Self {
        Self { out: Vec::new(), acc: 0, bits: 0 }
    }

    fn put_bits(&mut self, val: u32, nbits: u8) {
        self.acc = (self.acc << nbits) | (val & ((1u32 << nbits) - 1));
        self.bits += nbits;
        while self.bits >= 8 {
            self.bits -= 8;
            self.out.push(((self.acc >> self.bits) & 0xff) as u8);
        }
    }

    fn finish(mut self) -> Vec<u8> {
        if self.bits > 0 {
            self.out.push(((self.acc << (8 - self.bits)) & 0xff) as u8);
        }
        self.out
    }
}

struct BitReader<'a> {
    data: &'a [u8],
    byte_pos: usize,
    acc: u64,
    bits: u8,
}

impl<'a> BitReader<'a> {
    fn new(data: &'a [u8]) -> Self {
        Self { data, byte_pos: 0, acc: 0, bits: 0 }
    }

    fn ensure(&mut self, n: u8) -> bool {
        while self.bits < n {
            if self.byte_pos >= self.data.len() {
                return false;
            }
            self.acc = (self.acc << 8) | (self.data[self.byte_pos] as u64);
            self.byte_pos += 1;
            self.bits += 8;
        }
        true
    }

    fn peek(&mut self, n: u8) -> Option<u32> {
        if !self.ensure(n) {
            return None;
        }
        Some(((self.acc >> (self.bits - n)) & ((1u64 << n) - 1)) as u32)
    }

    fn skip(&mut self, n: u8) {
        self.bits -= n;
    }

    fn read(&mut self, n: u8) -> Option<u32> {
        let v = self.peek(n)?;
        self.skip(n);
        Some(v)
    }
}

/// Stateless/chunked MPPC compressor compatible with GNET's 8,192-byte sliding window:
/// - Literal `< 0x80`: `0` + 7 bits (`8` bits)
/// - Literal `>= 0x80`: `10` + low 7 bits (`9` bits)
/// - End-of-block marker: `1111` + `000000` (`offset == 0` in 6-bit offset mode)
/// - Copy tuples `(offset, length >= 3)`:
///   - `offset < 64`: `1111` + 6-bit `offset`
///   - `64 <= offset < 320`: `1110` + 8-bit `(offset - 64)`
///   - `320 <= offset < 8192`: `110` + 13-bit `(offset - 320)`
pub fn mppc_compress_block(input: &[u8]) -> Vec<u8> {
    let mut bw = BitWriter::new();
    let mut i = 0usize;
    while i < input.len() {
        let win_start = i.saturating_sub(8191);
        let mut best_len = 0usize;
        let mut best_off = 0usize;
        if i + 3 <= input.len() {
            let max_len = (input.len() - i).min(255);
            for cand in (win_start..i).rev() {
                if input[cand] == input[i] && input[cand + 1] == input[i + 1] && input[cand + 2] == input[i + 2] {
                    let mut l = 3usize;
                    while l < max_len && input[cand + l] == input[i + l] {
                        l += 1;
                    }
                    if l > best_len {
                        best_len = l;
                        best_off = i - cand;
                        if best_len >= 64 {
                            break;
                        }
                    }
                }
            }
        }

        if best_len >= 3 {
            if best_off < 64 {
                bw.put_bits(0b1111, 4);
                bw.put_bits(best_off as u32, 6);
            } else if best_off < 320 {
                bw.put_bits(0b1110, 4);
                bw.put_bits((best_off - 64) as u32, 8);
            } else {
                bw.put_bits(0b110, 3);
                bw.put_bits((best_off - 320) as u32, 13);
            }

            if best_len == 3 {
                bw.put_bits(0, 1);
            } else if best_len < 8 {
                bw.put_bits(0b10, 2);
                bw.put_bits((best_len & 0x03) as u32, 2);
            } else if best_len < 16 {
                bw.put_bits(0b110, 3);
                bw.put_bits((best_len & 0x07) as u32, 3);
            } else if best_len < 32 {
                bw.put_bits(0b1110, 4);
                bw.put_bits((best_len & 0x0f) as u32, 4);
            } else if best_len < 64 {
                bw.put_bits(0b11110, 5);
                bw.put_bits((best_len & 0x1f) as u32, 5);
            } else if best_len < 128 {
                bw.put_bits(0b111110, 6);
                bw.put_bits((best_len & 0x3f) as u32, 6);
            } else if best_len < 256 {
                bw.put_bits(0b1111110, 7);
                bw.put_bits((best_len & 0x7f) as u32, 7);
            }
            i += best_len;
        } else {
            let b = input[i];
            if b < 0x80 {
                bw.put_bits(b as u32, 8); // leading bit is 0
            } else {
                bw.put_bits(0b10, 2);
                bw.put_bits((b & 0x7f) as u32, 7);
            }
            i += 1;
        }
    }
    // End-of-record sentinel: `1111` + `000000`
    bw.put_bits(0b1111, 4);
    bw.put_bits(0, 6);
    bw.finish()
}

pub fn mppc_decompress_block(compressed: &[u8]) -> PwResult<Vec<u8>> {
    let mut br = BitReader::new(compressed);
    let mut out = Vec::with_capacity(compressed.len() * 2);

    loop {
        let Some(first) = br.read(1) else { break };
        if first == 0 {
            let low7 = br.read(7).ok_or_else(|| PwError::InvalidData("MPPC truncated <0x80 literal".into()))?;
            out.push(low7 as u8);
            continue;
        }
        let second = br.read(1).ok_or_else(|| PwError::InvalidData("MPPC truncated prefix".into()))?;
        if second == 0 {
            let low7 = br.read(7).ok_or_else(|| PwError::InvalidData("MPPC truncated >=0x80 literal".into()))?;
            out.push((low7 as u8) | 0x80);
            continue;
        }

        // Prefix started with `11...`
        let third = br.read(1).ok_or_else(|| PwError::InvalidData("MPPC truncated offset tag".into()))?;
        let offset: usize = if third == 0 {
            // `110` + 13 bits -> 320..8511
            (br.read(13).ok_or_else(|| PwError::InvalidData("MPPC 13-bit off EOF".into()))? as usize) + 320
        } else {
            let fourth = br.read(1).ok_or_else(|| PwError::InvalidData("MPPC 4th bit EOF".into()))?;
            if fourth == 0 {
                // `1110` + 8 bits -> 64..319
                (br.read(8).ok_or_else(|| PwError::InvalidData("MPPC 8-bit off EOF".into()))? as usize) + 64
            } else {
                // `1111` + 6 bits -> 0..63 (0 == EOB)
                let off6 = br.read(6).ok_or_else(|| PwError::InvalidData("MPPC 6-bit off EOF".into()))? as usize;
                if off6 == 0 {
                    break;
                }
                off6
            }
        };

        // Decode match length
        let mut ones = 0u8;
        while ones < 7 {
            let bit = br.read(1).ok_or_else(|| PwError::InvalidData("MPPC len prefix EOF".into()))?;
            if bit == 0 {
                break;
            }
            ones += 1;
        }
        let length: usize = if ones == 0 {
            3
        } else {
            let extra_bits = ones + 1;
            let extra = br.read(extra_bits).ok_or_else(|| PwError::InvalidData("MPPC len extra EOF".into()))? as usize;
            (1usize << extra_bits) + extra
        };

        if offset > out.len() {
            return Err(PwError::InvalidData(format!(
                "MPPC invalid back-reference offset {offset} > out.len() {}",
                out.len()
            )));
        }
        let start = out.len() - offset;
        for j in 0..length {
            let b = out[start + j];
            out.push(b);
        }
    }

    Ok(out)
}

// ---------------------------------------------------------------------------
// 4. Core Typed GNET Packets & `CecGameSession` Handshake (`0x5d8c60.c`)
// ---------------------------------------------------------------------------

pub const OPCODE_CHALLENGE: u32 = 1;
pub const OPCODE_KEY_EXCHANGE: u32 = 2;
pub const OPCODE_RESPONSE: u32 = 3;
pub const OPCODE_ONLINE_ANNOUNCE: u32 = 4;
pub const OPCODE_ERROR_INFO: u32 = 5;
pub const OPCODE_GAMEDATA_SEND: u32 = 34;
pub const OPCODE_SELECT_ROLE: u32 = 70;
pub const OPCODE_SELECT_ROLE_RE: u32 = 71;
pub const OPCODE_ENTER_WORLD: u32 = 72;
pub const OPCODE_PUBLIC_CHAT: u32 = 79;
pub const OPCODE_ROLE_LIST: u32 = 82;
pub const OPCODE_ROLE_LIST_RE: u32 = 83;
pub const OPCODE_KEEP_ALIVE: u32 = 90;

#[derive(Debug, Clone, PartialEq, Eq)]
pub struct ChallengePacket {
    pub nonce: Vec<u8>,
    pub version: u32,
    pub algo: u8,
}

impl ChallengePacket {
    pub fn encode(&self) -> Vec<u8> {
        let mut s = OctetsStream::new();
        s.write_octets(&self.nonce);
        s.write_u32_be(self.version);
        s.write_u8(self.algo);
        OctetsStream::encode_packet(OPCODE_CHALLENGE, s.as_slice())
    }

    pub fn decode_payload(payload: &[u8]) -> PwResult<Self> {
        let mut s = OctetsStream::from_bytes(payload);
        Ok(Self {
            nonce: s.read_octets()?,
            version: s.read_u32_be()?,
            algo: if s.remaining() > 0 { s.read_u8()? } else { 0 },
        })
    }
}

#[derive(Debug, Clone, PartialEq, Eq)]
pub struct ResponsePacket {
    pub identity: Vec<u8>,
    pub response: [u8; 16],
    pub use_token: u8,
    pub cli_fingerprint: Vec<u8>,
}

impl ResponsePacket {
    pub fn encode(&self) -> Vec<u8> {
        let mut s = OctetsStream::new();
        s.write_octets(&self.identity);
        s.write_octets(&self.response);
        s.write_u8(self.use_token);
        s.write_octets(&self.cli_fingerprint);
        OctetsStream::encode_packet(OPCODE_RESPONSE, s.as_slice())
    }

    pub fn decode_payload(payload: &[u8]) -> PwResult<Self> {
        let mut s = OctetsStream::from_bytes(payload);
        let identity = s.read_octets()?;
        let resp_vec = s.read_octets()?;
        if resp_vec.len() != 16 {
            return Err(PwError::InvalidData("Response digest must be 16 bytes".into()));
        }
        let mut response = [0u8; 16];
        response.copy_from_slice(&resp_vec);
        let use_token = if s.remaining() > 0 { s.read_u8()? } else { 0 };
        let cli_fingerprint = if s.remaining() > 0 { s.read_octets()? } else { Vec::new() };
        Ok(Self { identity, response, use_token, cli_fingerprint })
    }
}

#[derive(Debug, Clone, PartialEq, Eq)]
pub struct KeyExchangePacket {
    pub nonce: [u8; 16],
    pub kick_user: u32,
}

impl KeyExchangePacket {
    pub fn encode(&self) -> Vec<u8> {
        let mut s = OctetsStream::new();
        s.write_octets(&self.nonce);
        s.write_u32_be(self.kick_user);
        OctetsStream::encode_packet(OPCODE_KEY_EXCHANGE, s.as_slice())
    }

    pub fn decode_payload(payload: &[u8]) -> PwResult<Self> {
        let mut s = OctetsStream::from_bytes(payload);
        let nv = s.read_octets()?;
        if nv.len() != 16 {
            return Err(PwError::InvalidData("KeyExchange nonce must be 16 bytes".into()));
        }
        let mut nonce = [0u8; 16];
        nonce.copy_from_slice(&nv);
        let kick_user = s.read_u32_be()?;
        Ok(Self { nonce, kick_user })
    }
}

#[derive(Debug, Clone, PartialEq, Eq)]
pub struct GamedataSendPacket {
    pub c2s_cmd: u16,
    pub data: Vec<u8>,
}

impl GamedataSendPacket {
    pub fn encode(&self) -> Vec<u8> {
        let mut inner = Vec::with_capacity(2 + self.data.len());
        inner.extend_from_slice(&self.c2s_cmd.to_le_bytes());
        inner.extend_from_slice(&self.data);
        let mut s = OctetsStream::new();
        s.write_octets(&inner);
        OctetsStream::encode_packet(OPCODE_GAMEDATA_SEND, s.as_slice())
    }

    pub fn decode_payload(payload: &[u8]) -> PwResult<Self> {
        let mut s = OctetsStream::from_bytes(payload);
        let raw = s.read_octets()?;
        if raw.len() < 2 {
            return Err(PwError::InvalidData("GamedataSend shorter than 2-byte cmd".into()));
        }
        let c2s_cmd = u16::from_le_bytes([raw[0], raw[1]]);
        Ok(Self { c2s_cmd, data: raw[2..].to_vec() })
    }
}

pub fn lookup_protocol(opcode: u32) -> Option<&'static GnetProtocolDescriptor> {
    GNET_PROTOCOL_REGISTRY.iter().find(|d| d.opcode == opcode)
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum SessionState {
    Connecting,
    SentResponse,
    EncryptedReady,
    InWorld,
}

/// Stateful 1:1 port of `CECGameSession` (`0x5d8c60.c`, `0x5d9700.c`).
pub struct CecGameSession {
    pub account: String,
    password_hash: [u8; 16],
    pub state: SessionState,
    pub server_version: u32,
    out_rc4: Option<ArcFourSecurity>,
    in_rc4: Option<ArcFourSecurity>,
}

impl CecGameSession {
    pub fn new(account: &str, password: &str) -> Self {
        let mut cred = Vec::with_capacity(account.len() + password.len());
        cred.extend_from_slice(account.as_bytes());
        cred.extend_from_slice(password.as_bytes());
        let password_hash = md5_digest(&cred);
        Self {
            account: account.to_string(),
            password_hash,
            state: SessionState::Connecting,
            server_version: 0,
            out_rc4: None,
            in_rc4: None,
        }
    }

    pub fn derive_key(&self, nonce: &[u8]) -> [u8; 16] {
        let mut msg = Vec::with_capacity(self.account.len() + nonce.len());
        msg.extend_from_slice(self.account.as_bytes());
        msg.extend_from_slice(nonce);
        hmac_md5(&self.password_hash, &msg)
    }

    /// Processes S2C `Challenge` (`0x5d8c60.c`) and returns wire-encoded `Response` (Opcode `3`).
    pub fn on_challenge(&mut self, challenge: &ChallengePacket) -> Vec<u8> {
        self.server_version = challenge.version;
        let response = hmac_md5(&self.password_hash, &challenge.nonce);
        self.state = SessionState::SentResponse;
        ResponsePacket {
            identity: self.account.as_bytes().to_vec(),
            response,
            use_token: 0,
            cli_fingerprint: vec![0x01, 0x04, 0x02, 0x00],
        }
        .encode()
    }

    /// Processes S2C `KeyExchange` (`0x5d9700.c`), initializes S2C & C2S RC4+MPPC streams,
    /// and returns C2S `KeyExchange` wire bytes (pre-encryption or encrypted per caller).
    pub fn on_server_key_exchange(&mut self, srv_ke: &KeyExchangePacket, client_nonce: [u8; 16], kick_user: bool) -> Vec<u8> {
        let dec_key = self.derive_key(&srv_ke.nonce);
        let enc_key = self.derive_key(&client_nonce);
        self.in_rc4 = Some(ArcFourSecurity::new(&dec_key));
        self.out_rc4 = Some(ArcFourSecurity::new(&enc_key));
        self.state = SessionState::EncryptedReady;
        KeyExchangePacket {
            nonce: client_nonce,
            kick_user: u32::from(kick_user),
        }
        .encode()
    }

    /// Encrypts an outbound C2S frame with `CompressARCFourSecurity` (MPPC -> RC4).
    pub fn send_encrypted(&mut self, plain_frame: &[u8]) -> Vec<u8> {
        let mut buf = mppc_compress_block(plain_frame);
        if let Some(rc4) = &mut self.out_rc4 {
            rc4.apply_in_place(&mut buf);
        }
        buf
    }

    /// Decrypts an inbound S2C frame with `DecompressARCFourSecurity` (RC4 -> MPPC).
    pub fn recv_encrypted(&mut self, cipher_frame: &[u8]) -> PwResult<Vec<u8>> {
        let mut buf = cipher_frame.to_vec();
        if let Some(rc4) = &mut self.in_rc4 {
            rc4.apply_in_place(&mut buf);
        }
        mppc_decompress_block(&buf)
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_md5_rfc1321_vectors() {
        let hex = |b: [u8; 16]| -> String { b.iter().map(|x| format!("{x:02x}")).collect() };
        assert_eq!(hex(md5_digest(b"")), "d41d8cd98f00b204e9800998ecf8427e");
        assert_eq!(hex(md5_digest(b"abc")), "900150983cd24fb0d6963f7d28e17f72");
        assert_eq!(hex(md5_digest(b"message digest")), "f96b697d7cb7938d525a2f31aaf161d0");
    }

    #[test]
    fn test_compact_uint_and_protocol_registry() {
        assert!(GNET_PROTOCOL_REGISTRY.len() >= 200);
        let gd = lookup_protocol(OPCODE_GAMEDATA_SEND).unwrap();
        assert_eq!(gd.class_name, "GNET::GamedataSend");

        for &val in &[0u32, 1, 34, 127, 128, 4804, 16383, 16384, 0x1fff_ffff, 0xdead_beef] {
            let mut os = OctetsStream::new();
            os.write_compact_uint(val);
            assert_eq!(os.read_compact_uint().unwrap(), val);
        }
    }

    #[test]
    fn test_full_glinkd_handshake_mppc_rc4_tunnel() {
        let mut client = CecGameSession::new("archosaur", "pw142secret");
        let srv_challenge = ChallengePacket {
            nonce: b"0123456789abcdef".to_vec(),
            version: 0x0001_0402,
            algo: 0,
        };
        let resp_wire = client.on_challenge(&srv_challenge);
        let mut resp_os = OctetsStream::from_bytes(resp_wire);
        let (op, payload) = resp_os.decode_packet().unwrap();
        assert_eq!(op, OPCODE_RESPONSE);
        let parsed_resp = ResponsePacket::decode_payload(&payload).unwrap();
        assert_eq!(parsed_resp.identity, b"archosaur");

        let srv_nonce = [0x11u8; 16];
        let cli_nonce = [0x22u8; 16];
        let _ke_wire = client.on_server_key_exchange(
            &KeyExchangePacket { nonce: srv_nonce, kick_user: 1 },
            cli_nonce,
            true,
        );
        assert_eq!(client.state, SessionState::EncryptedReady);

        // Simulate server matching keys (server's out_rc4 == client's in_rc4, server's in_rc4 == client's out_rc4)
        let mut server_in_rc4 = ArcFourSecurity::new(&client.derive_key(&cli_nonce));
        let mut server_out_rc4 = ArcFourSecurity::new(&client.derive_key(&srv_nonce));

        let move_pkt = GamedataSendPacket {
            c2s_cmd: 0x0001,
            data: vec![10, 20, 30, 40, 10, 20, 30, 40, 10, 20, 30, 40, 0x99, 0xfe],
        }
        .encode();
        let encrypted_c2s = client.send_encrypted(&move_pkt);
        let mut srv_buf = encrypted_c2s;
        server_in_rc4.apply_in_place(&mut srv_buf);
        let srv_plain = mppc_decompress_block(&srv_buf).unwrap();
        assert_eq!(srv_plain, move_pkt);

        // Test S2C direction
        let mut s2c_cipher = mppc_compress_block(&move_pkt);
        server_out_rc4.apply_in_place(&mut s2c_cipher);
        let cli_plain = client.recv_encrypted(&s2c_cipher).unwrap();
        assert_eq!(cli_plain, move_pkt);
    }
}
