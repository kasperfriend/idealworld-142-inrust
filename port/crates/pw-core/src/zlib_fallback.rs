//! Pure-Rust RFC 1950 (`zlib`) + RFC 1951 (`DEFLATE`) + CRC-32 / Adler-32 implementation.
//! Used automatically on Windows (`#[cfg(not(unix))]`) so `cargo build --release` works
//! out-of-the-box on MSVC/MinGW with zero C library setup, and unit-tested on all platforms.

use crate::{PwError, PwResult};

pub fn pure_adler32(data: &[u8]) -> u32 {
    const MOD_ADLER: u32 = 65521;
    let mut a: u32 = 1;
    let mut b: u32 = 0;
    for chunk in data.chunks(5552) {
        for &byte in chunk {
            a += byte as u32;
            b += a;
        }
        a %= MOD_ADLER;
        b %= MOD_ADLER;
    }
    (b << 16) | a
}

pub fn pure_crc32(data: &[u8]) -> u32 {
    let mut crc: u32 = 0xffff_ffff;
    for &byte in data {
        crc ^= byte as u32;
        for _ in 0..8 {
            let mask = (crc & 1).wrapping_neg();
            crc = (crc >> 1) ^ (0xedb8_8320 & mask);
        }
    }
    !crc
}

struct DeflateBitReader<'a> {
    src: &'a [u8],
    byte_pos: usize,
    bit_buf: u64,
    bit_cnt: u8,
}

impl<'a> DeflateBitReader<'a> {
    fn new(src: &'a [u8]) -> Self {
        Self { src, byte_pos: 0, bit_buf: 0, bit_cnt: 0 }
    }

    fn fill(&mut self, need: u8) -> PwResult<()> {
        while self.bit_cnt < need {
            if self.byte_pos >= self.src.len() {
                return Err(PwError::ZlibError(-5));
            }
            self.bit_buf |= (self.src[self.byte_pos] as u64) << self.bit_cnt;
            self.byte_pos += 1;
            self.bit_cnt += 8;
        }
        Ok(())
    }

    fn peek_bits(&mut self, n: u8) -> PwResult<u32> {
        if n == 0 {
            return Ok(0);
        }
        self.fill(n)?;
        Ok((self.bit_buf & ((1u64 << n) - 1)) as u32)
    }

    fn drop_bits(&mut self, n: u8) {
        self.bit_buf >>= n;
        self.bit_cnt -= n;
    }

    fn read_bits(&mut self, n: u8) -> PwResult<u32> {
        let v = self.peek_bits(n)?;
        self.drop_bits(n);
        Ok(v)
    }

    fn align_byte(&mut self) {
        let rem = self.bit_cnt & 7;
        self.drop_bits(rem);
    }

    fn read_u16_aligned(&mut self) -> PwResult<u16> {
        self.align_byte();
        let lo = self.read_bits(8)? as u16;
        let hi = self.read_bits(8)? as u16;
        Ok(lo | (hi << 8))
    }
}

struct HuffTable {
    counts: [u16; 16],
    symbols: Vec<u16>,
    max_bits: u8,
}

impl HuffTable {
    fn from_lengths(lengths: &[u8]) -> PwResult<Self> {
        let mut counts = [0u16; 16];
        let mut max_bits = 0u8;
        for &l in lengths {
            if l > 15 {
                return Err(PwError::ZlibError(-3));
            }
            if l > 0 {
                counts[l as usize] += 1;
                if l > max_bits {
                    max_bits = l;
                }
            }
        }
        let mut offsets = [0u16; 16];
        let mut total = 0u16;
        for bits in 1..=15 {
            offsets[bits] = total;
            total += counts[bits];
        }
        let mut symbols = vec![0u16; total as usize];
        for (sym, &l) in lengths.iter().enumerate() {
            if l > 0 {
                let idx = offsets[l as usize] as usize;
                symbols[idx] = sym as u16;
                offsets[l as usize] += 1;
            }
        }
        Ok(Self { counts, symbols, max_bits })
    }

    fn decode(&self, br: &mut DeflateBitReader<'_>) -> PwResult<u16> {
        let mut code = 0i32;
        let mut first = 0i32;
        let mut index = 0i32;
        for len in 1..=(self.max_bits.max(1) as usize) {
            code |= br.read_bits(1)? as i32;
            let count = self.counts[len] as i32;
            if code - count < first {
                return Ok(self.symbols[(index + (code - first)) as usize]);
            }
            index += count;
            first = (first + count) << 1;
            code <<= 1;
        }
        Err(PwError::ZlibError(-3))
    }
}

fn fixed_tables() -> PwResult<(HuffTable, HuffTable)> {
    let mut lit = [0u8; 288];
    lit[0..144].fill(8);
    lit[144..256].fill(9);
    lit[256..280].fill(7);
    lit[280..288].fill(8);
    let dist = [5u8; 32];
    Ok((HuffTable::from_lengths(&lit)?, HuffTable::from_lengths(&dist)?))
}

fn dynamic_tables(br: &mut DeflateBitReader<'_>) -> PwResult<(HuffTable, HuffTable)> {
    const CL_ORDER: [usize; 19] = [16, 17, 18, 0, 8, 7, 9, 6, 10, 5, 11, 4, 12, 3, 13, 2, 14, 1, 15];
    let hlit = (br.read_bits(5)? as usize) + 257;
    let hdist = (br.read_bits(5)? as usize) + 1;
    let hclen = (br.read_bits(4)? as usize) + 4;
    let mut cl_lens = [0u8; 19];
    for i in 0..hclen {
        cl_lens[CL_ORDER[i]] = br.read_bits(3)? as u8;
    }
    let cl_tab = HuffTable::from_lengths(&cl_lens)?;
    let mut all_lens = Vec::with_capacity(hlit + hdist);
    while all_lens.len() < hlit + hdist {
        let sym = cl_tab.decode(br)?;
        match sym {
            0..=15 => all_lens.push(sym as u8),
            16 => {
                let prev = *all_lens.last().ok_or(PwError::ZlibError(-3))?;
                let rep = (br.read_bits(2)? as usize) + 3;
                all_lens.extend(std::iter::repeat_n(prev, rep));
            }
            17 => {
                let rep = (br.read_bits(3)? as usize) + 3;
                all_lens.extend(std::iter::repeat_n(0u8, rep));
            }
            18 => {
                let rep = (br.read_bits(7)? as usize) + 11;
                all_lens.extend(std::iter::repeat_n(0u8, rep));
            }
            _ => return Err(PwError::ZlibError(-3)),
        }
    }
    if all_lens.len() != hlit + hdist {
        return Err(PwError::ZlibError(-3));
    }
    Ok((
        HuffTable::from_lengths(&all_lens[..hlit])?,
        HuffTable::from_lengths(&all_lens[hlit..])?,
    ))
}

const LEN_BASE: [usize; 29] = [
    3, 4, 5, 6, 7, 8, 9, 10, 11, 13, 15, 17, 19, 23, 27, 31,
    35, 43, 51, 59, 67, 83, 99, 115, 131, 163, 195, 227, 258,
];
const LEN_EXTRA: [u8; 29] = [
    0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2,
    3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 0,
];
const DIST_BASE: [usize; 30] = [
    1, 2, 3, 4, 5, 7, 9, 13, 17, 25, 33, 49, 65, 97, 129, 193,
    257, 385, 513, 769, 1025, 1537, 2049, 3073, 4097, 6145, 8193, 12289, 16385, 24577,
];
const DIST_EXTRA: [u8; 30] = [
    0, 0, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6,
    7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12, 12, 13, 13,
];

pub fn pure_zlib_uncompress(compressed: &[u8], expected_len: usize) -> PwResult<Vec<u8>> {
    if expected_len == 0 {
        return Ok(Vec::new());
    }
    if compressed.len() < 6 {
        return Err(PwError::ZlibError(-3));
    }
    let cmf = compressed[0];
    let flg = compressed[1];
    if (cmf & 0x0f) != 8 || (((cmf as u16) << 8 | (flg as u16)) % 31) != 0 || (flg & 0x20) != 0 {
        return Err(PwError::ZlibError(-3));
    }

    let mut br = DeflateBitReader::new(&compressed[2..]);
    let mut out = Vec::with_capacity(expected_len);

    loop {
        let bfinal = br.read_bits(1)?;
        let btype = br.read_bits(2)?;
        match btype {
            0 => {
                let len = br.read_u16_aligned()? as usize;
                let nlen = br.read_u16_aligned()? as usize;
                if (len ^ 0xffff) != nlen {
                    return Err(PwError::ZlibError(-3));
                }
                for _ in 0..len {
                    out.push(br.read_bits(8)? as u8);
                }
            }
            1 | 2 => {
                let (lit_tab, dist_tab) = if btype == 1 {
                    fixed_tables()?
                } else {
                    dynamic_tables(&mut br)?
                };
                loop {
                    let sym = lit_tab.decode(&mut br)? as usize;
                    if sym < 256 {
                        out.push(sym as u8);
                    } else if sym == 256 {
                        break;
                    } else if sym <= 285 {
                        let lidx = sym - 257;
                        let length = LEN_BASE[lidx] + (br.read_bits(LEN_EXTRA[lidx])? as usize);
                        let dsym = dist_tab.decode(&mut br)? as usize;
                        if dsym >= 30 {
                            return Err(PwError::ZlibError(-3));
                        }
                        let dist = DIST_BASE[dsym] + (br.read_bits(DIST_EXTRA[dsym])? as usize);
                        if dist > out.len() {
                            return Err(PwError::ZlibError(-3));
                        }
                        let start = out.len() - dist;
                        for j in 0..length {
                            let b = out[start + j];
                            out.push(b);
                        }
                    } else {
                        return Err(PwError::ZlibError(-3));
                    }
                }
            }
            _ => return Err(PwError::ZlibError(-3)),
        }
        if bfinal != 0 {
            break;
        }
    }

    br.align_byte();
    let expected_adler = (br.read_bits(8)? << 24)
        | (br.read_bits(8)? << 16)
        | (br.read_bits(8)? << 8)
        | br.read_bits(8)?;
    if pure_adler32(&out) != expected_adler {
        return Err(PwError::ZlibError(-3));
    }
    Ok(out)
}

struct DeflateBitWriter {
    out: Vec<u8>,
    bit_buf: u32,
    bit_cnt: u8,
}

impl DeflateBitWriter {
    fn new(cap: usize) -> Self {
        Self { out: Vec::with_capacity(cap), bit_buf: 0, bit_cnt: 0 }
    }

    fn write_bits(&mut self, val: u32, n: u8) {
        self.bit_buf |= (val & ((1u32 << n) - 1)) << self.bit_cnt;
        self.bit_cnt += n;
        while self.bit_cnt >= 8 {
            self.out.push((self.bit_buf & 0xff) as u8);
            self.bit_buf >>= 8;
            self.bit_cnt -= 8;
        }
    }

    fn write_huff(&mut self, mut code_msb: u16, bits: u8) {
        let mut rev = 0u32;
        for _ in 0..bits {
            rev = (rev << 1) | ((code_msb & 1) as u32);
            code_msb >>= 1;
        }
        self.write_bits(rev, bits);
    }

    fn flush_byte(&mut self) {
        if self.bit_cnt > 0 {
            self.out.push((self.bit_buf & 0xff) as u8);
            self.bit_buf = 0;
            self.bit_cnt = 0;
        }
    }
}

fn emit_fixed_lit(bw: &mut DeflateBitWriter, lit: usize) {
    if lit <= 143 {
        bw.write_huff(0x30 + (lit as u16), 8);
    } else if lit <= 255 {
        bw.write_huff(0x190 + ((lit - 144) as u16), 9);
    } else if lit <= 279 {
        bw.write_huff((lit - 256) as u16, 7);
    } else {
        bw.write_huff(0xc0 + ((lit - 280) as u16), 8);
    }
}

pub fn pure_zlib_compress(input: &[u8]) -> Vec<u8> {
    let mut bw = DeflateBitWriter::new(input.len() + 16);
    // RFC 1950 header: CMF=0x78 (Deflate, 32K window), FLG=0x9C (default level, 0x789c % 31 == 0)
    bw.out.push(0x78);
    bw.out.push(0x9c);

    // Single final Fixed-Huffman LZ77 block (BFINAL=1, BTYPE=01)
    bw.write_bits(1, 1);
    bw.write_bits(1, 2);

    let mut head = [-1i32; 4096];
    let mut prev = vec![-1i32; input.len()];
    let hash3 = |p: usize| -> usize {
        (((input[p] as usize) << 8) ^ ((input[p + 1] as usize) << 4) ^ (input[p + 2] as usize)) & 4095
    };

    let mut i = 0usize;
    while i < input.len() {
        let mut best_len = 0usize;
        let mut best_dist = 0usize;
        if i + 3 <= input.len() {
            let h = hash3(i);
            let mut cand = head[h];
            prev[i] = cand;
            head[h] = i as i32;
            let max_l = (input.len() - i).min(258);
            let mut steps = 0usize;
            while cand >= 0 && steps < 32 {
                let c = cand as usize;
                let dist = i - c;
                if dist > 32768 {
                    break;
                }
                if input[c..c + 3] == input[i..i + 3] {
                    let mut l = 3usize;
                    while l < max_l && input[c + l] == input[i + l] {
                        l += 1;
                    }
                    if l > best_len {
                        best_len = l;
                        best_dist = dist;
                        if best_len >= 128 {
                            break;
                        }
                    }
                }
                cand = prev[c];
                steps += 1;
            }
        }

        if best_len >= 3 {
            let mut lidx = 0usize;
            for k in (0..29).rev() {
                if best_len >= LEN_BASE[k] {
                    lidx = k;
                    break;
                }
            }
            emit_fixed_lit(&mut bw, 257 + lidx);
            if LEN_EXTRA[lidx] > 0 {
                bw.write_bits((best_len - LEN_BASE[lidx]) as u32, LEN_EXTRA[lidx]);
            }
            let mut didx = 0usize;
            for k in (0..30).rev() {
                if best_dist >= DIST_BASE[k] {
                    didx = k;
                    break;
                }
            }
            bw.write_huff(didx as u16, 5);
            if DIST_EXTRA[didx] > 0 {
                bw.write_bits((best_dist - DIST_BASE[didx]) as u32, DIST_EXTRA[didx]);
            }
            for step in 1..best_len {
                if i + step + 3 <= input.len() {
                    let h = hash3(i + step);
                    prev[i + step] = head[h];
                    head[h] = (i + step) as i32;
                }
            }
            i += best_len;
        } else {
            emit_fixed_lit(&mut bw, input[i] as usize);
            i += 1;
        }
    }

    emit_fixed_lit(&mut bw, 256); // EOB
    bw.flush_byte();
    let adler = pure_adler32(input);
    bw.out.extend_from_slice(&adler.to_be_bytes());
    bw.out
}
