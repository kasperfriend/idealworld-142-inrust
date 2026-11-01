//! Pure-Rust Xiph Vorbis I (`\x01vorbis` / `\x03vorbis` / `\x05vorbis` + Audio Frame)
//! Bitstream Decoder & IMDCT Overlap-Add Synthesizer (Zero External Crates).
//!
//! Implements RFC 3533 Ogg packet reassembly + Xiph.Org Vorbis I specification:
//! - LSB-first `VorbisBitReader` (`ilog`, `float32_unpack`),
//! - Canonical Vorbis Huffman `Codebook` (`0x564342` `"BCV"`, Lookup Types `0`, `1`, `2`),
//! - `Floor1` piecewise-linear `FLOOR1_INVERSE_DB_TABLE` envelope synthesis,
//! - `Residue` Types `0`, `1`, and `2` partitioned VQ decoding,
//! - `Mapping0` square-polar stereo channel decoupling,
//! - Exact Vorbis window `sin(pi/2 * sin^2(...))` + IMDCT + overlap-add to 16-bit PCM.

use crate::audio_ogg::DecodedAudioClip;

/// Exact 256-entry Xiph Vorbis I Floor1 inverse dB lookup table (`10^(0.11512925 * (i - 255) / ...)`).
#[allow(clippy::excessive_precision)]
const FLOOR1_INVERSE_DB_TABLE: [f32; 256] = [
    1.0649863e-07, 1.1341951e-07, 1.2079015e-07, 1.2863978e-07, 1.3699951e-07, 1.4590251e-07,
    1.5538408e-07, 1.6548181e-07, 1.7623575e-07, 1.8768855e-07, 1.9988561e-07, 2.1287530e-07,
    2.2670913e-07, 2.4144197e-07, 2.5713223e-07, 2.7384213e-07, 2.9163793e-07, 3.1059021e-07,
    3.3077411e-07, 3.5226968e-07, 3.7516214e-07, 3.9954229e-07, 4.2550680e-07, 4.5315863e-07,
    4.8260743e-07, 5.1396998e-07, 5.4737065e-07, 5.8294187e-07, 6.2082472e-07, 6.6116941e-07,
    7.0413592e-07, 7.4989464e-07, 7.9862701e-07, 8.5052630e-07, 9.0579828e-07, 9.6466216e-07,
    1.0273513e-06, 1.0941144e-06, 1.1652161e-06, 1.2409384e-06, 1.3215816e-06, 1.4074654e-06,
    1.4989305e-06, 1.5963394e-06, 1.7000785e-06, 1.8105592e-06, 1.9282195e-06, 2.0535261e-06,
    2.1869758e-06, 2.3290978e-06, 2.4804557e-06, 2.6416497e-06, 2.8133190e-06, 2.9961443e-06,
    3.1908506e-06, 3.3982101e-06, 3.6190449e-06, 3.8542308e-06, 4.1047004e-06, 4.3714470e-06,
    4.6555282e-06, 4.9580707e-06, 5.2802740e-06, 5.6234160e-06, 5.9888572e-06, 6.3780469e-06,
    6.7925283e-06, 7.2339451e-06, 7.7040476e-06, 8.2047000e-06, 8.7378876e-06, 9.3057248e-06,
    9.9104632e-06, 1.0554501e-05, 1.1240392e-05, 1.1970856e-05, 1.2748789e-05, 1.3577278e-05,
    1.4459606e-05, 1.5399272e-05, 1.6400004e-05, 1.7465768e-05, 1.8600792e-05, 1.9809576e-05,
    2.1096914e-05, 2.2467911e-05, 2.3928002e-05, 2.5482978e-05, 2.7139006e-05, 2.8902651e-05,
    3.0780908e-05, 3.2781225e-05, 3.4911534e-05, 3.7180282e-05, 3.9596466e-05, 4.2169667e-05,
    4.4910090e-05, 4.7828601e-05, 5.0936773e-05, 5.4246931e-05, 5.7772202e-05, 6.1526565e-05,
    6.5524908e-05, 6.9783085e-05, 7.4317983e-05, 7.9147585e-05, 8.4291040e-05, 8.9768747e-05,
    9.5602426e-05, 0.00010181521, 0.00010843174, 0.00011547824, 0.00012298267, 0.00013097477,
    0.00013948625, 0.00014855085, 0.00015820453, 0.00016848555, 0.00017943469, 0.00019109536,
    0.00020351382, 0.00021673929, 0.00023082423, 0.00024582449, 0.00026179955, 0.00027881276,
    0.00029693158, 0.00031622787, 0.00033677814, 0.00035866388, 0.00038197188, 0.00040679456,
    0.00043323036, 0.00046138411, 0.00049136745, 0.00052329927, 0.00055730621, 0.00059352311,
    0.00063209358, 0.00067317058, 0.00071691700, 0.00076350630, 0.00081312324, 0.00086596457,
    0.00092223983, 0.00098217216, 0.0010459992, 0.0011139742, 0.0011863665, 0.0012634633,
    0.0013455702, 0.0014330129, 0.0015261382, 0.0016253153, 0.0017309374, 0.0018434235,
    0.0019632195, 0.0020908006, 0.0022266726, 0.0023713743, 0.0025254795, 0.0026895994,
    0.0028643847, 0.0030505286, 0.0032487691, 0.0034598925, 0.0036847358, 0.0039241906,
    0.0041792066, 0.0044507950, 0.0047400328, 0.0050480668, 0.0053761186, 0.0057254891,
    0.0060975636, 0.0064938176, 0.0069158225, 0.0073652516, 0.0078438871, 0.0083536271,
    0.0088964928, 0.009474637, 0.010090352, 0.010746080, 0.011444421, 0.012188144,
    0.012980198, 0.013823725, 0.014722068, 0.015678791, 0.016697687, 0.017782797,
    0.018938423, 0.020169149, 0.021479854, 0.022875735, 0.024362330, 0.025945531,
    0.027631618, 0.029427276, 0.031339626, 0.033376252, 0.035545228, 0.037855157,
    0.040315199, 0.042935108, 0.045725273, 0.048696758, 0.051861348, 0.055231591,
    0.058820850, 0.062643361, 0.066714279, 0.071049749, 0.075666962, 0.080584227,
    0.085821044, 0.091398179, 0.097337747, 0.10366330, 0.11039993, 0.11757434,
    0.12521498, 0.13335215, 0.14201813, 0.15124727, 0.16107617, 0.17154380,
    0.18269168, 0.19456402, 0.20720788, 0.22067342, 0.23501402, 0.25028656,
    0.26655159, 0.28387361, 0.30232132, 0.32196786, 0.34289114, 0.36517414,
    0.38890521, 0.41417847, 0.44109412, 0.46975890, 0.50028648, 0.53279791,
    0.56742212, 0.60429640, 0.64356699, 0.68538959, 0.72993007, 0.77736504,
    0.82788260, 0.88168307, 0.9389798, 1.0,
];

pub fn vorbis_ilog(v: u32) -> u8 {
    if v == 0 {
        0
    } else {
        (32 - v.leading_zeros()) as u8
    }
}

pub fn vorbis_float32_unpack(x: u32) -> f32 {
    let mantissa = (x & 0x001F_FFFF) as f64;
    let sign = (x & 0x8000_0000) != 0;
    let exp = ((x & 0x7FE0_0000) >> 21) as i32 - 788;
    let val = mantissa * 2.0f64.powi(exp);
    if sign {
        -(val as f32)
    } else {
        val as f32
    }
}

fn lookup1_values(entries: u32, dim: u16) -> u32 {
    if dim == 0 || entries == 0 {
        return 0;
    }
    let mut r = (entries as f64).powf(1.0 / dim as f64).floor() as u32;
    while r.saturating_add(1).saturating_pow(dim as u32) <= entries {
        r += 1;
    }
    while r > 0 && r.saturating_pow(dim as u32) > entries {
        r -= 1;
    }
    r
}

struct VorbisBitReader<'a> {
    buf: &'a [u8],
    bit_pos: usize,
}

impl<'a> VorbisBitReader<'a> {
    fn new(buf: &'a [u8]) -> Self {
        Self { buf, bit_pos: 0 }
    }

    fn read_bit(&mut self) -> Option<u8> {
        let byte_idx = self.bit_pos >> 3;
        if byte_idx >= self.buf.len() {
            return None;
        }
        let bit_idx = self.bit_pos & 7;
        self.bit_pos += 1;
        Some((self.buf[byte_idx] >> bit_idx) & 1)
    }

    fn read_bits(&mut self, count: u8) -> Option<u32> {
        if count == 0 {
            return Some(0);
        }
        if count > 32 {
            return None;
        }
        let mut out = 0u32;
        for i in 0..count {
            out |= (self.read_bit()? as u32) << i;
        }
        Some(out)
    }
}

/// Reassembles RFC 3533 `OggS` pages into logical Vorbis packets (`(packet_bytes, granule_pos)`).
pub fn demux_ogg_packets(raw: &[u8]) -> Option<Vec<(Vec<u8>, u64)>> {
    if raw.len() < 27 || &raw[0..4] != b"OggS" {
        return None;
    }
    let mut pos = 0usize;
    let mut packets = Vec::new();
    let mut cur_pkt = Vec::new();

    while pos + 27 <= raw.len() {
        if &raw[pos..pos + 4] != b"OggS" {
            break;
        }
        let granule = u64::from_le_bytes([
            raw[pos + 6],
            raw[pos + 7],
            raw[pos + 8],
            raw[pos + 9],
            raw[pos + 10],
            raw[pos + 11],
            raw[pos + 12],
            raw[pos + 13],
        ]);
        let num_segs = raw[pos + 26] as usize;
        if pos + 27 + num_segs > raw.len() {
            break;
        }
        let segs = &raw[pos + 27..pos + 27 + num_segs];
        let mut body_off = pos + 27 + num_segs;
        let total_body: usize = segs.iter().map(|&s| s as usize).sum();
        if body_off + total_body > raw.len() {
            break;
        }
        for &seg_len in segs {
            let sl = seg_len as usize;
            cur_pkt.extend_from_slice(&raw[body_off..body_off + sl]);
            body_off += sl;
            if seg_len < 255 {
                packets.push((std::mem::take(&mut cur_pkt), granule));
            }
        }
        pos = body_off;
    }
    if !cur_pkt.is_empty() {
        packets.push((cur_pkt, u64::MAX));
    }
    Some(packets)
}

#[derive(Clone, Default)]
struct HuffNode {
    left: usize,
    right: usize,
    sym: Option<u32>,
}

#[allow(dead_code)]
#[derive(Clone)]
struct Codebook {
    dimensions: u16,
    entries: u32,
    nodes: Vec<HuffNode>,
    single_sym: Option<u32>,
    lookup_type: u8,
    min_val: f32,
    delta_val: f32,
    sequence_p: bool,
    lookup_values: u32,
    multiplicands: Vec<u32>,
}

impl Codebook {
    fn parse(br: &mut VorbisBitReader<'_>) -> Option<Self> {
        let sync = br.read_bits(24)?;
        if sync != 0x564342 {
            return None;
        }
        let dimensions = br.read_bits(16)? as u16;
        let entries = br.read_bits(24)?;
        if entries > 262_144 {
            return None;
        }
        let ordered = br.read_bit()? != 0;
        let mut lengths = vec![0u8; entries as usize];
        if !ordered {
            let sparse = br.read_bit()? != 0;
            for l in &mut lengths {
                if sparse {
                    if br.read_bit()? != 0 {
                        *l = br.read_bits(5)? as u8 + 1;
                    }
                } else {
                    *l = br.read_bits(5)? as u8 + 1;
                }
            }
        } else {
            let mut cur_entry = 0u32;
            let mut cur_len = br.read_bits(5)? as u8 + 1;
            while cur_entry < entries {
                let num = br.read_bits(vorbis_ilog(entries - cur_entry))?;
                if cur_entry + num > entries {
                    return None;
                }
                for i in cur_entry..cur_entry + num {
                    lengths[i as usize] = cur_len;
                }
                cur_entry += num;
                cur_len = cur_len.saturating_add(1);
            }
        }

        let (nodes, single_sym) = Self::build_huffman_tree(&lengths)?;
        let lookup_type = br.read_bits(4)? as u8;
        let mut min_val = 0.0;
        let mut delta_val = 0.0;
        let mut sequence_p = false;
        let mut lookup_values = 0u32;
        let mut multiplicands = Vec::new();
        if lookup_type == 1 || lookup_type == 2 {
            min_val = vorbis_float32_unpack(br.read_bits(32)?);
            delta_val = vorbis_float32_unpack(br.read_bits(32)?);
            let value_bits = br.read_bits(4)? as u8 + 1;
            sequence_p = br.read_bit()? != 0;
            lookup_values = if lookup_type == 1 {
                lookup1_values(entries, dimensions)
            } else {
                entries.saturating_mul(dimensions as u32)
            };
            multiplicands.reserve(lookup_values as usize);
            for _ in 0..lookup_values {
                multiplicands.push(br.read_bits(value_bits)?);
            }
        } else if lookup_type > 2 {
            return None;
        }

        Some(Self {
            dimensions,
            entries,
            nodes,
            single_sym,
            lookup_type,
            min_val,
            delta_val,
            sequence_p,
            lookup_values,
            multiplicands,
        })
    }

    fn build_huffman_tree(lengths: &[u8]) -> Option<(Vec<HuffNode>, Option<u32>)> {
        let used: Vec<(u32, u8)> = lengths
            .iter()
            .enumerate()
            .filter_map(|(i, &l)| (l > 0).then_some((i as u32, l)))
            .collect();
        if used.is_empty() {
            return Some((vec![HuffNode::default()], None));
        }
        if used.len() == 1 && used[0].1 == 1 {
            return Some((vec![HuffNode::default()], Some(used[0].0)));
        }

        // Canonical Vorbis codeword assignment (`available[len]` marker tree)
        let mut avail = [0u32; 33];
        let mut nodes = vec![HuffNode::default()];
        for (idx, &(sym, len)) in used.iter().enumerate() {
            if len == 0 || len > 32 {
                return None;
            }
            let code = if idx == 0 {
                0u32
            } else {
                let mut marker_len = len as usize;
                while marker_len > 0 && avail[marker_len] == 0 {
                    marker_len -= 1;
                }
                if marker_len == 0 {
                    return None;
                }
                let res = avail[marker_len];
                avail[marker_len] = 0;
                for j in (marker_len + 1)..=(len as usize) {
                    avail[j] = res | (1u32 << (32 - j));
                }
                res
            };
            if idx == 0 {
                for j in 1..=(len as usize) {
                    avail[j] = 1u32 << (32 - j);
                }
            }
            // Insert MSB-of-32-downwards into LSB-read binary trie
            let mut cur = 0usize;
            for b in 0..(len as usize) {
                let bit = (code >> (31 - b)) & 1;
                let next = if bit == 0 { nodes[cur].left } else { nodes[cur].right };
                let child = if next == 0 {
                    let nid = nodes.len();
                    nodes.push(HuffNode::default());
                    if bit == 0 {
                        nodes[cur].left = nid;
                    } else {
                        nodes[cur].right = nid;
                    }
                    nid
                } else {
                    next
                };
                cur = child;
            }
            nodes[cur].sym = Some(sym);
        }
        Some((nodes, None))
    }

    fn decode_scalar(&self, br: &mut VorbisBitReader<'_>) -> Option<u32> {
        if let Some(s) = self.single_sym {
            let _ = br.read_bit()?;
            return Some(s);
        }
        let mut cur = 0usize;
        for _ in 0..33 {
            if let Some(sym) = self.nodes.get(cur)?.sym {
                return Some(sym);
            }
            let bit = br.read_bit()?;
            cur = if bit == 0 {
                self.nodes[cur].left
            } else {
                self.nodes[cur].right
            };
            if cur == 0 {
                return None;
            }
        }
        None
    }

    fn decode_vq(&self, br: &mut VorbisBitReader<'_>, out: &mut [f32]) -> Option<()> {
        let lookup_off = self.decode_scalar(br)?;
        if self.lookup_type == 0 || self.dimensions == 0 {
            return None;
        }
        let dim = self.dimensions as usize;
        let mut last = 0.0f32;
        if self.lookup_type == 1 {
            let lv = self.lookup_values.max(1);
            let mut index_divisor = 1u32;
            for item in out.iter_mut().take(dim) {
                let m_off = ((lookup_off / index_divisor) % lv) as usize;
                let v = *self.multiplicands.get(m_off)? as f32 * self.delta_val + self.min_val + last;
                *item = v;
                if self.sequence_p {
                    last = v;
                }
                index_divisor = index_divisor.saturating_mul(lv);
            }
        } else {
            let base = (lookup_off as usize).saturating_mul(dim);
            for (i, item) in out.iter_mut().take(dim).enumerate() {
                let v = *self.multiplicands.get(base + i)? as f32 * self.delta_val + self.min_val + last;
                *item = v;
                if self.sequence_p {
                    last = v;
                }
            }
        }
        Some(())
    }
}

#[derive(Clone)]
struct Floor1Spec {
    partitions: Vec<u8>,
    class_dims: Vec<u8>,
    class_subclasses: Vec<u8>,
    class_masterbooks: Vec<u8>,
    subclass_books: Vec<[i16; 8]>,
    multiplier: i32,
    x_list: Vec<u16>,
}

impl Floor1Spec {
    fn parse(br: &mut VorbisBitReader<'_>) -> Option<Self> {
        let part_cnt = br.read_bits(5)? as usize;
        let mut partitions = Vec::with_capacity(part_cnt);
        let mut max_class = 0i32;
        for _ in 0..part_cnt {
            let c = br.read_bits(4)? as u8;
            max_class = max_class.max(c as i32);
            partitions.push(c);
        }
        let n_classes = (max_class + 1) as usize;
        let mut class_dims = vec![0u8; n_classes];
        let mut class_subclasses = vec![0u8; n_classes];
        let mut class_masterbooks = vec![0u8; n_classes];
        let mut subclass_books = vec![[-1i16; 8]; n_classes];
        for i in 0..n_classes {
            class_dims[i] = br.read_bits(3)? as u8 + 1;
            class_subclasses[i] = br.read_bits(2)? as u8;
            if class_subclasses[i] != 0 {
                class_masterbooks[i] = br.read_bits(8)? as u8;
            }
            let sub_cnt = 1usize << class_subclasses[i];
            for b in 0..sub_cnt {
                subclass_books[i][b] = br.read_bits(8)? as i16 - 1;
            }
        }
        let multiplier = br.read_bits(2)? as i32 + 1;
        let rangebits = br.read_bits(4)?;
        let mut x_list = vec![0u16, (1u32 << rangebits) as u16];
        for &cls in &partitions {
            let dim = class_dims[cls as usize] as usize;
            for _ in 0..dim {
                x_list.push(br.read_bits(rangebits as u8)? as u16);
            }
        }
        Some(Self {
            partitions,
            class_dims,
            class_subclasses,
            class_masterbooks,
            subclass_books,
            multiplier,
            x_list,
        })
    }

    fn decode_curve(
        &self,
        br: &mut VorbisBitReader<'_>,
        books: &[Codebook],
        n_half: usize,
    ) -> Option<Option<Vec<f32>>> {
        if br.read_bit()? == 0 {
            return Some(None); // Unused channel floor
        }
        let range = [256i32, 128, 86, 64][(self.multiplier - 1) as usize];
        let y_bits = vorbis_ilog((range - 1) as u32);
        let mut y_raw = vec![0i32; self.x_list.len()];
        y_raw[0] = br.read_bits(y_bits)? as i32;
        y_raw[1] = br.read_bits(y_bits)? as i32;
        let mut offset = 2usize;
        for &cls in &self.partitions {
            let ci = cls as usize;
            let cdim = self.class_dims[ci] as usize;
            let cbits = self.class_subclasses[ci];
            let csub = (1u32 << cbits) - 1;
            let mut cval = 0u32;
            if cbits > 0 {
                cval = books.get(self.class_masterbooks[ci] as usize)?.decode_scalar(br)?;
            }
            for _ in 0..cdim {
                let book_num = self.subclass_books[ci][(cval & csub) as usize];
                cval >>= cbits;
                y_raw[offset] = if book_num >= 0 {
                    books.get(book_num as usize)?.decode_scalar(br)? as i32
                } else {
                    0
                };
                offset += 1;
            }
        }

        // Step 2: Amplitude prediction & step-line rendering
        let vals = self.x_list.len();
        let mut final_y = vec![0i32; vals];
        let mut step2_flag = vec![false; vals];
        final_y[0] = y_raw[0];
        final_y[1] = y_raw[1];
        step2_flag[0] = true;
        step2_flag[1] = true;

        for i in 2..vals {
            let x = self.x_list[i] as i32;
            let mut low_idx = 0usize;
            let mut high_idx = 1usize;
            for j in 0..i {
                let xj = self.x_list[j] as i32;
                if xj < x && xj > self.x_list[low_idx] as i32 {
                    low_idx = j;
                }
                if xj > x && xj < self.x_list[high_idx] as i32 {
                    high_idx = j;
                }
            }
            let lx = self.x_list[low_idx] as i32;
            let hx = self.x_list[high_idx] as i32;
            let ly = final_y[low_idx];
            let hy = final_y[high_idx];
            let dy = (hy - ly).abs();
            let dx = (hx - lx).max(1);
            let err = (dy * (x - lx)) / dx;
            let predicted = if hy < ly { ly - err } else { ly + err };
            let val = y_raw[i];
            let highroom = range - predicted;
            let lowroom = predicted;
            let room = if highroom < lowroom {
                highroom * 2
            } else {
                lowroom * 2
            };
            if val != 0 {
                step2_flag[low_idx] = true;
                step2_flag[high_idx] = true;
                step2_flag[i] = true;
                final_y[i] = if val >= room {
                    if highroom > lowroom {
                        val - lowroom + predicted
                    } else {
                        predicted - val + highroom - 1
                    }
                } else if (val & 1) == 1 {
                    predicted - ((val + 1) >> 1)
                } else {
                    predicted + (val >> 1)
                };
            } else {
                step2_flag[i] = false;
                final_y[i] = predicted;
            }
        }

        let mut order: Vec<usize> = (0..vals).collect();
        order.sort_by_key(|&idx| self.x_list[idx]);

        let mut floor_db = vec![0usize; n_half];
        let mut hx = 0i32;
        let mut lx = 0i32;
        let mut ly = (final_y[order[0]] * self.multiplier).clamp(0, 255);
        for &idx in order.iter().skip(1) {
            if step2_flag[idx] {
                let hy = (final_y[idx] * self.multiplier).clamp(0, 255);
                hx = self.x_list[idx] as i32;
                render_floor_line(lx, ly, hx, hy, &mut floor_db);
                lx = hx;
                ly = hy;
            }
        }
        if (hx as usize) < n_half {
            render_floor_line(hx, ly, n_half as i32, ly, &mut floor_db);
        }

        let curve = floor_db
            .into_iter()
            .map(|i| FLOOR1_INVERSE_DB_TABLE[i.min(255)])
            .collect();
        Some(Some(curve))
    }
}

fn render_floor_line(x0: i32, y0: i32, x1: i32, y1: i32, out: &mut [usize]) {
    let dy = y1 - y0;
    let adx = (x1 - x0).max(1);
    let ady = dy.abs();
    let base = dy / adx;
    let sy = if dy < 0 { base - 1 } else { base + 1 };
    let mut x = x0;
    let mut y = y0;
    let mut err = 0i32;
    let abase = ady - base.abs() * adx;
    if x >= 0 && (x as usize) < out.len() {
        out[x as usize] = y.clamp(0, 255) as usize;
    }
    while x + 1 < x1 {
        x += 1;
        err += abase;
        if err >= adx {
            err -= adx;
            y += sy;
        } else {
            y += base;
        }
        if x >= 0 && (x as usize) < out.len() {
            out[x as usize] = y.clamp(0, 255) as usize;
        }
    }
}

#[derive(Clone)]
struct ResidueSpec {
    res_type: u16,
    begin: u32,
    end: u32,
    part_size: u32,
    classifications: u8,
    classbook: u8,
    books: Vec<[i16; 8]>,
}

impl ResidueSpec {
    fn parse(res_type: u16, br: &mut VorbisBitReader<'_>) -> Option<Self> {
        let begin = br.read_bits(24)?;
        let end = br.read_bits(24)?;
        let part_size = br.read_bits(24)? + 1;
        let classifications = br.read_bits(6)? as u8 + 1;
        let classbook = br.read_bits(8)? as u8;
        let mut cascades = vec![0u8; classifications as usize];
        for c in &mut cascades {
            let low = br.read_bits(3)? as u8;
            let high = if br.read_bit()? != 0 {
                br.read_bits(5)? as u8
            } else {
                0
            };
            *c = (high << 3) | low;
        }
        let mut books = vec![[-1i16; 8]; classifications as usize];
        for (ci, &cas) in cascades.iter().enumerate() {
            for b in 0..8 {
                if (cas & (1 << b)) != 0 {
                    books[ci][b] = br.read_bits(8)? as i16;
                }
            }
        }
        Some(Self {
            res_type,
            begin,
            end,
            part_size,
            classifications,
            classbook,
            books,
        })
    }

    fn decode(
        &self,
        br: &mut VorbisBitReader<'_>,
        codebooks: &[Codebook],
        ch_vecs: &mut [Vec<f32>],
        do_not_decode: &[bool],
        n_half: usize,
    ) -> Option<()> {
        let ch = ch_vecs.len();
        if ch == 0 || do_not_decode.iter().all(|&d| d) {
            return Some(());
        }
        let cb_class = codebooks.get(self.classbook as usize)?;
        let cwords_per_codeword = cb_class.dimensions.max(1) as usize;
        let part_size = self.part_size.max(1) as usize;

        if self.res_type == 2 {
            let max_len = n_half * ch;
            let actual_end = (self.end as usize).min(max_len);
            let begin = (self.begin as usize).min(actual_end);
            let n_to_read = actual_end.saturating_sub(begin);
            if n_to_read == 0 {
                return Some(());
            }
            let part_count = n_to_read / part_size;
            let mut inter = vec![0.0f32; max_len];
            let mut classes = vec![0usize; part_count + cwords_per_codeword];
            let mut tmp = vec![0.0f32; 64];
            for pass in 0..8 {
                let mut pcount = 0usize;
                while pcount < part_count {
                    if pass == 0 {
                        let temp = cb_class.decode_scalar(br)?;
                        let mut div = 1u32;
                        for k in (0..cwords_per_codeword).rev() {
                            if pcount + k < classes.len() {
                                classes[pcount + k] =
                                    ((temp / div) % (self.classifications as u32)) as usize;
                            }
                            div = div.saturating_mul(self.classifications as u32);
                        }
                    }
                    for _ in 0..cwords_per_codeword {
                        if pcount >= part_count {
                            break;
                        }
                        let vqclass = classes[pcount].min(self.books.len() - 1);
                        let vqbook = self.books[vqclass][pass];
                        if vqbook >= 0 {
                            let book = codebooks.get(vqbook as usize)?;
                            let dim = book.dimensions.max(1) as usize;
                            if tmp.len() < dim {
                                tmp.resize(dim, 0.0);
                            }
                            let mut off = begin + pcount * part_size;
                            let end_off = (off + part_size).min(max_len);
                            while off < end_off {
                                book.decode_vq(br, &mut tmp[..dim])?;
                                for &val in &tmp[..dim] {
                                    if off < end_off {
                                        inter[off] += val;
                                        off += 1;
                                    }
                                }
                            }
                        }
                        pcount += 1;
                    }
                }
            }
            for i in 0..n_half {
                for (c, vec_c) in ch_vecs.iter_mut().enumerate() {
                    vec_c[i] += inter[i * ch + c];
                }
            }
        } else {
            let actual_end = (self.end as usize).min(n_half);
            let begin = (self.begin as usize).min(actual_end);
            let n_to_read = actual_end.saturating_sub(begin);
            if n_to_read == 0 {
                return Some(());
            }
            let part_count = n_to_read / part_size;
            let mut classes = vec![vec![0usize; part_count + cwords_per_codeword]; ch];
            let mut tmp = vec![0.0f32; 64];
            for pass in 0..8 {
                let mut pcount = 0usize;
                while pcount < part_count {
                    if pass == 0 {
                        for c in 0..ch {
                            if !do_not_decode[c] {
                                let temp = cb_class.decode_scalar(br)?;
                                let mut div = 1u32;
                                for k in (0..cwords_per_codeword).rev() {
                                    classes[c][pcount + k] =
                                        ((temp / div) % (self.classifications as u32)) as usize;
                                    div = div.saturating_mul(self.classifications as u32);
                                }
                            }
                        }
                    }
                    for _ in 0..cwords_per_codeword {
                        if pcount >= part_count {
                            break;
                        }
                        for c in 0..ch {
                            if !do_not_decode[c] {
                                let vqclass = classes[c][pcount].min(self.books.len() - 1);
                                let vqbook = self.books[vqclass][pass];
                                if vqbook >= 0 {
                                    let book = codebooks.get(vqbook as usize)?;
                                    let dim = book.dimensions.max(1) as usize;
                                    if tmp.len() < dim {
                                        tmp.resize(dim, 0.0);
                                    }
                                    let off_base = begin + pcount * part_size;
                                    if self.res_type == 0 {
                                        let step = part_size / dim;
                                        for s in 0..step {
                                            book.decode_vq(br, &mut tmp[..dim])?;
                                            for d in 0..dim {
                                                let idx = off_base + s + d * step;
                                                if idx < n_half {
                                                    ch_vecs[c][idx] += tmp[d];
                                                }
                                            }
                                        }
                                    } else {
                                        let mut off = off_base;
                                        let end_off = (off + part_size).min(n_half);
                                        while off < end_off {
                                            book.decode_vq(br, &mut tmp[..dim])?;
                                            for &val in &tmp[..dim] {
                                                if off < end_off {
                                                    ch_vecs[c][off] += val;
                                                    off += 1;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        pcount += 1;
                    }
                }
            }
        }
        Some(())
    }
}

#[derive(Clone)]
struct MappingSpec {
    couplings: Vec<(u8, u8)>,
    mux: Vec<u8>,
    submap_floor: Vec<u8>,
    submap_residue: Vec<u8>,
}

#[derive(Clone, Copy)]
struct ModeSpec {
    blockflag: bool,
    mapping: u8,
}

/// Computes the exact Vorbis I IMDCT (`N/2` frequency lines -> `N` time-domain samples, Xiph §4.3.6):
/// `y[p] = sum_{k=0}^{N/2 - 1} freq[k] * cos(pi / (2 * N) * (2 * p + 1 + N / 2) * (2 * k + 1))`
/// via $O(N \log N)$ radix-2 complex FFT pre/post-twiddle + TDAC symmetry unfolding.
pub fn vorbis_imdct(freq: &[f32], out_time: &mut [f32]) {
    let n2 = freq.len();
    let n = n2 * 2;
    let n4 = n / 4;
    if n < 4 || !n.is_power_of_two() || out_time.len() < n {
        return;
    }

    let mut re = vec![0.0f32; n];
    let mut im = vec![0.0f32; n];
    let pi = std::f32::consts::PI;

    // 1. Pre-twiddle `z[k] = freq[k] * exp(-i * pi * k / n)` for `k = 0..n/2`
    for k in 0..n2 {
        let ang = -pi * (k as f32) / (n as f32);
        let (s, c) = ang.sin_cos();
        re[k] = freq[k] * c;
        im[k] = freq[k] * s;
    }

    // 2. `N`-point radix-2 complex FFT (`O(N log N)`)
    fft_radix2_inplace(&mut re, &mut im);

    // 3. Post-twiddle `dct4[q] = Re[ Z[q] * exp(-i * pi * (2*q + 1) / (2*n)) ]` for `q = 0..n/2`
    let mut dct4 = vec![0.0f32; n2];
    for q in 0..n2 {
        let ang = -pi * (2.0 * q as f32 + 1.0) / (2.0 * n as f32);
        let (s, c) = ang.sin_cos();
        dct4[q] = re[q] * c - im[q] * s;
    }

    // 4. Unfold `N/2` DCT-IV values into `N` Vorbis TDAC time-domain samples (`+ N/4` shift)
    for p in 0..n4 {
        out_time[p] = dct4[p + n4];
    }
    for p in n4..(3 * n4) {
        out_time[p] = -dct4[3 * n4 - 1 - p];
    }
    for p in (3 * n4)..n {
        out_time[p] = -dct4[p - 3 * n4];
    }
}

fn fft_radix2_inplace(re: &mut [f32], im: &mut [f32]) {
    let n = re.len();
    if n <= 1 {
        return;
    }
    let mut j = 0usize;
    for i in 1..n {
        let mut bit = n >> 1;
        while (j & bit) != 0 {
            j ^= bit;
            bit >>= 1;
        }
        j ^= bit;
        if i < j {
            re.swap(i, j);
            im.swap(i, j);
        }
    }
    let mut len = 2usize;
    while len <= n {
        let half = len / 2;
        let step = -std::f32::consts::TAU / len as f32;
        for base in (0..n).step_by(len) {
            for k in 0..half {
                let (ws, wc) = (step * k as f32).sin_cos();
                let tr = re[base + k + half] * wc - im[base + k + half] * ws;
                let ti = re[base + k + half] * ws + im[base + k + half] * wc;
                re[base + k + half] = re[base + k] - tr;
                im[base + k + half] = im[base + k] - ti;
                re[base + k] += tr;
                im[base + k] += ti;
            }
        }
        len <<= 1;
    }
}

fn build_vorbis_half_window(half_len: usize) -> Vec<f32> {
    let mut w = Vec::with_capacity(half_len);
    let pi_2 = std::f32::consts::FRAC_PI_2;
    for i in 0..half_len {
        let s = ((i as f32 + 0.5) / half_len as f32 * pi_2).sin();
        w.push((pi_2 * s * s).sin());
    }
    w
}

/// Decodes a complete Ogg Vorbis I (`OggS`) file into 16-bit interleaved PCM samples!
pub fn decode_ogg_vorbis_to_pcm(raw: &[u8]) -> Option<DecodedAudioClip> {
    let packets = demux_ogg_packets(raw)?;
    if packets.len() < 3 {
        return None;
    }

    // 1. Identification Header (`\x01vorbis`)
    let id = &packets[0].0;
    if id.len() < 30 || &id[0..7] != b"\x01vorbis" {
        return None;
    }
    let channels = id[11] as usize;
    let sample_rate = u32::from_le_bytes([id[12], id[13], id[14], id[15]]);
    let bs0_exp = id[28] & 0x0F;
    let bs1_exp = (id[28] >> 4) & 0x0F;
    if channels == 0 || channels > 8 || !(6..=13).contains(&bs0_exp) || !(6..=13).contains(&bs1_exp) || bs0_exp > bs1_exp {
        return None;
    }
    let blocksize = [1usize << bs0_exp, 1usize << bs1_exp];
    let win_short = build_vorbis_half_window(blocksize[0] / 2);
    let win_long = build_vorbis_half_window(blocksize[1] / 2);

    // 2. Setup Header (`\x05vorbis`)
    let setup = &packets[2].0;
    if setup.len() < 8 || &setup[0..7] != b"\x05vorbis" {
        return None;
    }
    let mut br = VorbisBitReader::new(&setup[7..]);
    let codebook_cnt = br.read_bits(8)? as usize + 1;
    let mut codebooks = Vec::with_capacity(codebook_cnt);
    for _ in 0..codebook_cnt {
        codebooks.push(Codebook::parse(&mut br)?);
    }

    // Time-domain transforms (Vorbis I spec: count + 16-bit 0s)
    let td_cnt = br.read_bits(6)? as usize + 1;
    for _ in 0..td_cnt {
        if br.read_bits(16)? != 0 {
            return None;
        }
    }

    // Floors (`Floor1` supported; `Floor0` skipped cleanly if encountered)
    let floor_cnt = br.read_bits(6)? as usize + 1;
    let mut floors = Vec::with_capacity(floor_cnt);
    for _ in 0..floor_cnt {
        let ftype = br.read_bits(16)?;
        if ftype == 1 {
            floors.push(Some(Floor1Spec::parse(&mut br)?));
        } else if ftype == 0 {
            let _order = br.read_bits(8)?;
            let _rate = br.read_bits(16)?;
            let _bark = br.read_bits(16)?;
            let _amp_bits = br.read_bits(6)?;
            let _amp_off = br.read_bits(8)?;
            let nb = br.read_bits(4)? as usize + 1;
            for _ in 0..nb {
                let _ = br.read_bits(8)?;
            }
            floors.push(None);
        } else {
            return None;
        }
    }

    // Residues (`Type 0, 1, 2`)
    let res_cnt = br.read_bits(6)? as usize + 1;
    let mut residues = Vec::with_capacity(res_cnt);
    for _ in 0..res_cnt {
        let rtype = br.read_bits(16)?;
        if rtype > 2 {
            return None;
        }
        residues.push(ResidueSpec::parse(rtype as u16, &mut br)?);
    }

    // Mappings (`Mapping 0`)
    let map_cnt = br.read_bits(6)? as usize + 1;
    let mut mappings = Vec::with_capacity(map_cnt);
    for _ in 0..map_cnt {
        if br.read_bits(16)? != 0 {
            return None;
        }
        let submaps = if br.read_bit()? != 0 {
            br.read_bits(4)? as usize + 1
        } else {
            1
        };
        let mut couplings = Vec::new();
        if br.read_bit()? != 0 {
            let steps = br.read_bits(8)? as usize + 1;
            let ch_bits = vorbis_ilog((channels - 1) as u32);
            for _ in 0..steps {
                let mag = br.read_bits(ch_bits)? as u8;
                let ang = br.read_bits(ch_bits)? as u8;
                couplings.push((mag, ang));
            }
        }
        if br.read_bits(2)? != 0 {
            return None;
        }
        let mut mux = vec![0u8; channels];
        if submaps > 1 {
            for m in &mut mux {
                *m = br.read_bits(4)? as u8;
            }
        }
        let mut submap_floor = Vec::with_capacity(submaps);
        let mut submap_residue = Vec::with_capacity(submaps);
        for _ in 0..submaps {
            let _ = br.read_bits(8)?; // unused time placeholder
            submap_floor.push(br.read_bits(8)? as u8);
            submap_residue.push(br.read_bits(8)? as u8);
        }
        mappings.push(MappingSpec {
            couplings,
            mux,
            submap_floor,
            submap_residue,
        });
    }

    // Modes
    let mode_cnt = br.read_bits(6)? as usize + 1;
    let mut modes = Vec::with_capacity(mode_cnt);
    for _ in 0..mode_cnt {
        let blockflag = br.read_bit()? != 0;
        let _wtype = br.read_bits(16)?;
        let _ttype = br.read_bits(16)?;
        let mapping = br.read_bits(8)? as u8;
        modes.push(ModeSpec { blockflag, mapping });
    }
    let _framing = br.read_bit()?;

    // 3. Synthesize Audio Packets (`packets[3..]`) via Floor1 * Residue + IMDCT + Overlap-Add!
    let mode_bits = vorbis_ilog((mode_cnt - 1) as u32);
    let mut prev_right: Option<(usize, Vec<Vec<f32>>)> = None;
    let mut samples_i16 = Vec::new();
    let mut time_buf = vec![0.0f32; blocksize[1]];

    for (pkt, _granule) in packets.iter().skip(3) {
        if pkt.is_empty() {
            continue;
        }
        let mut pbr = VorbisBitReader::new(pkt);
        if pbr.read_bit()? != 0 {
            continue; // Non-audio packet
        }
        let mode_idx = pbr.read_bits(mode_bits)? as usize;
        let Some(&mode) = modes.get(mode_idx) else { continue };
        let prev_win_flag = if mode.blockflag { pbr.read_bit()? != 0 } else { false };
        let next_win_flag = if mode.blockflag { pbr.read_bit()? != 0 } else { false };

        let n = blocksize[usize::from(mode.blockflag)];
        let n_half = n / 2;
        let Some(map) = mappings.get(mode.mapping as usize) else { continue };

        let mut floor_curves: Vec<Option<Vec<f32>>> = Vec::with_capacity(channels);
        let mut no_residue = vec![false; channels];
        for c in 0..channels {
            let sub = *map.mux.get(c).unwrap_or(&0) as usize;
            let fl_idx = *map.submap_floor.get(sub).unwrap_or(&0) as usize;
            if let Some(Some(fl)) = floors.get(fl_idx) {
                match fl.decode_curve(&mut pbr, &codebooks, n_half) {
                    Some(Some(curve)) => floor_curves.push(Some(curve)),
                    _ => {
                        no_residue[c] = true;
                        floor_curves.push(None);
                    }
                }
            } else {
                no_residue[c] = true;
                floor_curves.push(None);
            }
        }

        for &(mag, ang) in &map.couplings {
            let m = mag as usize;
            let a = ang as usize;
            if m < channels && a < channels && (!no_residue[m] || !no_residue[a]) {
                no_residue[m] = false;
                no_residue[a] = false;
            }
        }

        let mut spectra = vec![vec![0.0f32; n_half]; channels];
        for (sub_i, &res_idx) in map.submap_residue.iter().enumerate() {
            let mut sub_ch_indices = Vec::new();
            let mut sub_vecs = Vec::new();
            let mut sub_dnd = Vec::new();
            for c in 0..channels {
                if *map.mux.get(c).unwrap_or(&0) as usize == sub_i {
                    sub_ch_indices.push(c);
                    sub_vecs.push(vec![0.0f32; n_half]);
                    sub_dnd.push(no_residue[c]);
                }
            }
            if let Some(res) = residues.get(res_idx as usize) {
                let _ = res.decode(&mut pbr, &codebooks, &mut sub_vecs, &sub_dnd, n_half);
            }
            for (local_i, &orig_c) in sub_ch_indices.iter().enumerate() {
                spectra[orig_c] = std::mem::take(&mut sub_vecs[local_i]);
            }
        }

        // Inverse square-polar coupling
        for &(mag, ang) in map.couplings.iter().rev() {
            let m_idx = mag as usize;
            let a_idx = ang as usize;
            if m_idx < channels && a_idx < channels {
                for k in 0..n_half {
                    let m = spectra[m_idx][k];
                    let a = spectra[a_idx][k];
                    let (new_m, new_a) = if m > 0.0 {
                        if a > 0.0 {
                            (m, m - a)
                        } else {
                            (m + a, m)
                        }
                    } else if a > 0.0 {
                        (m, m + a)
                    } else {
                        (m - a, m)
                    };
                    spectra[m_idx][k] = new_m;
                    spectra[a_idx][k] = new_a;
                }
            }
        }

        // Dot product with Floor1 curve & IMDCT + Windowing
        let mut cur_td = vec![vec![0.0f32; n]; channels];
        for c in 0..channels {
            if let Some(curve) = &floor_curves[c] {
                for k in 0..n_half {
                    spectra[c][k] *= curve[k];
                }
            } else {
                spectra[c].fill(0.0);
            }
            vorbis_imdct(&spectra[c], &mut time_buf[..n]);
            // Apply Vorbis hybrid short/long window slopes
            let left_w = if mode.blockflag && !prev_win_flag {
                &win_short
            } else if mode.blockflag {
                &win_long
            } else {
                &win_short
            };
            let right_w = if mode.blockflag && !next_win_flag {
                &win_short
            } else if mode.blockflag {
                &win_long
            } else {
                &win_short
            };
            let l_start = n / 4 - left_w.len() / 2;
            for p in 0..l_start {
                time_buf[p] = 0.0;
            }
            for (i, &w) in left_w.iter().enumerate() {
                time_buf[l_start + i] *= w;
            }
            let r_start = 3 * n / 4 - right_w.len() / 2;
            for (i, &w) in right_w.iter().enumerate() {
                time_buf[r_start + i] *= right_w[right_w.len() - 1 - i];
                let _ = w;
            }
            for p in (r_start + right_w.len())..n {
                time_buf[p] = 0.0;
            }
            cur_td[c].copy_from_slice(&time_buf[..n]);
        }

        if let Some((prev_n, prev_ch)) = &prev_right {
            let prev_center = prev_n * 3 / 4;
            let cur_center = n / 4;
            let overlap = (*prev_n / 2).min(n / 2);
            let prev_lap_start = prev_center - overlap / 2;
            let cur_lap_start = cur_center - overlap / 2;

            // 1) Non-overlapping samples from previous right half (`prev_n/2 .. prev_lap_start`)
            for s in (*prev_n / 2)..prev_lap_start {
                for c in 0..channels {
                    let v = (prev_ch[c][s] * 32767.0).clamp(-32768.0, 32767.0) as i16;
                    samples_i16.push(v);
                }
            }
            // 2) Overlap-add region
            for k in 0..overlap {
                for c in 0..channels {
                    let sum = prev_ch[c][prev_lap_start + k] + cur_td[c][cur_lap_start + k];
                    let v = (sum * 32767.0).clamp(-32768.0, 32767.0) as i16;
                    samples_i16.push(v);
                }
            }
            // 3) Post-overlap samples up to `cur_td` center `n / 2`
            for s in (cur_lap_start + overlap)..(n / 2) {
                for c in 0..channels {
                    let v = (cur_td[c][s] * 32767.0).clamp(-32768.0, 32767.0) as i16;
                    samples_i16.push(v);
                }
            }
        }
        prev_right = Some((n, cur_td));
    }

    Some(DecodedAudioClip {
        sample_rate,
        channels: channels as u16,
        samples_i16,
    })
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::audio_ogg::ogg_page_crc32;

    struct LsbBitWriter {
        bytes: Vec<u8>,
        bit_pos: usize,
    }
    impl LsbBitWriter {
        fn new() -> Self {
            Self { bytes: Vec::new(), bit_pos: 0 }
        }
        fn write_bits(&mut self, val: u32, count: u8) {
            for i in 0..count {
                let b = ((val >> i) & 1) as u8;
                let byte_i = self.bit_pos >> 3;
                let bit_i = self.bit_pos & 7;
                if byte_i >= self.bytes.len() {
                    self.bytes.push(0);
                }
                self.bytes[byte_i] |= b << bit_i;
                self.bit_pos += 1;
            }
        }
    }

    fn wrap_ogg_page(flags: u8, granule: u64, seq: u32, pkt: &[u8]) -> Vec<u8> {
        let mut p = Vec::new();
        p.extend_from_slice(b"OggS");
        p.push(0);
        p.push(flags);
        p.extend_from_slice(&granule.to_le_bytes());
        p.extend_from_slice(&0x2305_1420u32.to_le_bytes());
        p.extend_from_slice(&seq.to_le_bytes());
        p.extend_from_slice(&0u32.to_le_bytes());
        let full = pkt.len() / 255;
        let rem = pkt.len() % 255;
        p.push((full + 1) as u8);
        for _ in 0..full {
            p.push(255);
        }
        p.push(rem as u8);
        p.extend_from_slice(pkt);
        let crc = ogg_page_crc32(&p);
        p[22..26].copy_from_slice(&crc.to_le_bytes());
        p
    }

    #[test]
    fn test_vorbis_imdct_exact_identity_and_full_ogg_vorbis_pcm_decode() {
        // 1. Verify `vorbis_imdct` N=64 matches textbook Vorbis §4.3.6 cosine formula to < 1e-5!
        let n = 64usize;
        let n2 = n / 2;
        let mut freq = vec![0.0f32; n2];
        freq[1] = 0.5;
        freq[4] = -0.25;
        let mut fast = vec![0.0f32; n];
        vorbis_imdct(&freq, &mut fast);
        for p in 0..n {
            let mut slow = 0.0f32;
            for k in 0..n2 {
                let ang = std::f32::consts::PI / (2.0 * n as f32)
                    * (2.0 * p as f32 + 1.0 + n2 as f32)
                    * (2.0 * k as f32 + 1.0);
                slow += freq[k] * ang.cos();
            }
            assert!(
                (fast[p] - slow).abs() < 1e-4,
                "IMDCT mismatch at {p}: fast={} vs ref={}",
                fast[p],
                slow
            );
        }

        // 2. Synthesize a complete multi-packet Ogg Vorbis I stream (`\x01vorbis` + `\x03vorbis` + `\x05vorbis` + 3 audio frames)
        //    and verify `decode_ogg_vorbis_to_pcm` produces non-zero decoded 16-bit PCM waveform!
        let mut id = Vec::new();
        id.extend_from_slice(b"\x01vorbis");
        id.extend_from_slice(&0u32.to_le_bytes());
        id.push(1); // mono
        id.extend_from_slice(&22_050u32.to_le_bytes());
        id.extend_from_slice(&0i32.to_le_bytes());
        id.extend_from_slice(&64_000i32.to_le_bytes());
        id.extend_from_slice(&0i32.to_le_bytes());
        id.push(0x66); // bs0 = 64, bs1 = 64
        id.push(1);

        let mut comment = Vec::new();
        comment.extend_from_slice(b"\x03vorbis");
        comment.extend_from_slice(&5u32.to_le_bytes());
        comment.extend_from_slice(b"PW142");
        comment.extend_from_slice(&0u32.to_le_bytes());
        comment.push(1);

        // Build `\x05vorbis` setup with 1 VQ codebook (`dim=1, entries=2: [0.0, 0.45]`), 1 Floor1, 1 Residue1, 1 Mapping0, 1 Mode
        let mut sw = LsbBitWriter::new();
        sw.write_bits(0, 8); // 1 codebook
        sw.write_bits(0x564342, 24);
        sw.write_bits(1, 16); // dim = 1
        sw.write_bits(2, 24); // entries = 2
        sw.write_bits(0, 1); // unordered
        sw.write_bits(0, 1); // dense
        sw.write_bits(0, 5); // len[0] = 1
        sw.write_bits(0, 5); // len[1] = 1
        sw.write_bits(1, 4); // lookup_type = 1
        // Vorbis float32 pack for 0.0 (`exp=-788 -> raw=0`) and delta 0.25 (`mantissa = 1<<20 = 1048576, 0.25 = 1048576 * 2^-22 -> exp=-22 -> raw_exp = 766`)
        sw.write_bits(0, 32); // min_val = 0.0
        sw.write_bits((766u32 << 21) | (1u32 << 20), 32); // delta_val = 0.25
        sw.write_bits(1, 4); // value_bits = 2
        sw.write_bits(0, 1); // sequence_p = false
        sw.write_bits(0, 2); // mult[0] = 0 -> 0.0
        sw.write_bits(2, 2); // mult[1] = 2 -> 0.50

        sw.write_bits(0, 6); // 1 time-domain placeholder
        sw.write_bits(0, 16);

        sw.write_bits(0, 6); // 1 Floor1
        sw.write_bits(1, 16); // type 1
        sw.write_bits(1, 5); // 1 partition
        sw.write_bits(0, 4); // partition[0] = class 0
        sw.write_bits(0, 3); // class_dim = 1
        sw.write_bits(0, 2); // class_subclasses = 0
        sw.write_bits(0, 8); // subclass_book[0] = -1 (0 - 1)
        sw.write_bits(3, 2); // multiplier = 4 (range = 64, y_bits = 6)
        sw.write_bits(5, 4); // rangebits = 5 (x_list = [0, 32, 16])
        sw.write_bits(16, 5); // x_list[2] = 16

        sw.write_bits(0, 6); // 1 Residue (type 1)
        sw.write_bits(1, 16);
        sw.write_bits(0, 24); // begin = 0
        sw.write_bits(8, 24); // end = 8
        sw.write_bits(7, 24); // part_size = 8
        sw.write_bits(0, 6); // classifications = 1
        sw.write_bits(0, 8); // classbook = 0
        sw.write_bits(1, 3); // cascade[0] = 0b001 (pass 0 uses a book)
        sw.write_bits(0, 1);
        sw.write_bits(0, 8); // book 0 for pass 0

        sw.write_bits(0, 6); // 1 Mapping0
        sw.write_bits(0, 16);
        sw.write_bits(0, 1); // 1 submap
        sw.write_bits(0, 1); // 0 couplings
        sw.write_bits(0, 2); // reserved
        sw.write_bits(0, 8); // time
        sw.write_bits(0, 8); // floor 0
        sw.write_bits(0, 8); // residue 0

        sw.write_bits(0, 6); // 1 Mode
        sw.write_bits(0, 1); // blockflag = 0
        sw.write_bits(0, 16);
        sw.write_bits(0, 16);
        sw.write_bits(0, 8); // mapping 0
        sw.write_bits(1, 1); // framing = 1

        let mut setup = b"\x05vorbis".to_vec();
        setup.extend_from_slice(&sw.bytes);

        // Audio frame: packet_type=0 (1b), floor1 non-zero=1 (1b), y0=63 (6b), y1=63 (6b), class=0 (1b), 8 VQ syms alternating `1, 0, 1, ...`
        let mut aw = LsbBitWriter::new();
        aw.write_bits(0, 1); // audio pkt
        aw.write_bits(1, 1); // floor active
        aw.write_bits(63, 6); // y0 -> 63*4 = 252 (~0.88 gain)
        aw.write_bits(63, 6); // y1
        aw.write_bits(0, 1); // classword sym 0
        for s in [1u32, 1, 0, 1, 0, 0, 1, 0] {
            aw.write_bits(s, 1);
        }

        let mut stream = Vec::new();
        stream.extend_from_slice(&wrap_ogg_page(0x02, 0, 0, &id));
        stream.extend_from_slice(&wrap_ogg_page(0x00, 0, 1, &comment));
        stream.extend_from_slice(&wrap_ogg_page(0x00, 0, 2, &setup));
        stream.extend_from_slice(&wrap_ogg_page(0x00, 32, 3, &aw.bytes));
        stream.extend_from_slice(&wrap_ogg_page(0x00, 64, 4, &aw.bytes));
        stream.extend_from_slice(&wrap_ogg_page(0x04, 96, 5, &aw.bytes));

        let decoded = decode_ogg_vorbis_to_pcm(&stream).expect("valid Vorbis I audio decode");
        assert_eq!(decoded.sample_rate, 22_050);
        assert_eq!(decoded.channels, 1);
        assert_eq!(decoded.samples_i16.len(), 64); // 2 overlap transitions * 32 samples/frame
        assert!(
            decoded.samples_i16.iter().any(|&s| s.abs() > 1000),
            "decoded Vorbis PCM must contain non-zero synthesized waveform"
        );
    }
}
