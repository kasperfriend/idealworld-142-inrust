//! Pure-Rust Ogg/Vorbis (`OggS` RFC 3533) Bitstream Demuxer, PCM/IMA-ADPCM `.wav` Decoder,
//! 3D Spatial SFX Pan/Attenuation, & `precinct.clt` Zone BGM Playlist Controller (`AngelicaMedia`).

use pw_core::Vec3;

/// Decoded interleaved stereo/mono 16-bit PCM clip ready for WinMM `waveOutWrite` / DirectSound.
#[derive(Debug, Clone)]
pub struct DecodedAudioClip {
    pub sample_rate: u32,
    pub channels: u16,
    pub samples_i16: Vec<i16>,
}

/// Parsed Ogg (`OggS`) Vorbis bitstream metadata & packet count (`music/*.ogg`, `sfx/*.ogg`).
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct OggVorbisStreamInfo {
    pub serial_number: u32,
    pub vorbis_version: u32,
    pub channels: u8,
    pub sample_rate: u32,
    pub bitrate_nominal: i32,
    pub total_pages: usize,
    pub total_granule_samples: u64,
    pub vendor: String,
}

impl OggVorbisStreamInfo {
    pub fn duration_seconds(&self) -> f32 {
        if self.sample_rate == 0 {
            0.0
        } else {
            (self.total_granule_samples as f64 / self.sample_rate as f64) as f32
        }
    }
}

/// Computes the exact Ogg framing polynomial (`0x04C11DB7`, direct MSB-first) CRC-32 over a page.
pub fn ogg_page_crc32(page_with_zeroed_crc: &[u8]) -> u32 {
    let mut crc = 0u32;
    for &b in page_with_zeroed_crc {
        crc ^= (b as u32) << 24;
        for _ in 0..8 {
            if (crc & 0x8000_0000) != 0 {
                crc = (crc << 1) ^ 0x04C1_1DB7;
            } else {
                crc <<= 1;
            }
        }
    }
    crc
}

/// Demuxes and validates an Ogg Vorbis (`OggS`) stream (`music/*.ogg` in Perfect World 1.4.2).
pub fn inspect_ogg_vorbis(raw: &[u8]) -> Option<OggVorbisStreamInfo> {
    if raw.len() < 58 || &raw[0..4] != b"OggS" {
        return None;
    }
    let mut pos = 0usize;
    let mut total_pages = 0usize;
    let mut serial_number = 0u32;
    let mut max_granule = 0u64;
    let mut channels = 0u8;
    let mut sample_rate = 0u32;
    let mut vorbis_version = 0u32;
    let mut bitrate_nominal = 0i32;
    let mut vendor = String::new();

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
        if granule != u64::MAX && granule > max_granule {
            max_granule = granule;
        }
        serial_number = u32::from_le_bytes([raw[pos + 14], raw[pos + 15], raw[pos + 16], raw[pos + 17]]);
        let num_segs = raw[pos + 26] as usize;
        if pos + 27 + num_segs > raw.len() {
            break;
        }
        let seg_table = &raw[pos + 27..pos + 27 + num_segs];
        let body_len: usize = seg_table.iter().map(|&b| b as usize).sum();
        let body_start = pos + 27 + num_segs;
        if body_start + body_len > raw.len() {
            break;
        }
        let body = &raw[body_start..body_start + body_len];
        total_pages += 1;

        // Vorbis identification header (`\x01vorbis`)
        if sample_rate == 0 && body.len() >= 30 && &body[0..7] == b"\x01vorbis" {
            vorbis_version = u32::from_le_bytes([body[7], body[8], body[9], body[10]]);
            channels = body[11];
            sample_rate = u32::from_le_bytes([body[12], body[13], body[14], body[15]]);
            bitrate_nominal = i32::from_le_bytes([body[20], body[21], body[22], body[23]]);
        } else if vendor.is_empty() && body.len() >= 11 && &body[0..7] == b"\x03vorbis" {
            let vlen = u32::from_le_bytes([body[7], body[8], body[9], body[10]]) as usize;
            if 11 + vlen <= body.len() {
                vendor = String::from_utf8_lossy(&body[11..11 + vlen]).into_owned();
            }
        }
        pos = body_start + body_len;
    }

    if total_pages == 0 || sample_rate == 0 {
        return None;
    }
    Some(OggVorbisStreamInfo {
        serial_number,
        vorbis_version,
        channels,
        sample_rate,
        bitrate_nominal,
        total_pages,
        total_granule_samples: max_granule,
        vendor,
    })
}

const IMA_INDEX_TABLE: [i32; 16] = [-1, -1, -1, -1, 2, 4, 6, 8, -1, -1, -1, -1, 2, 4, 6, 8];
const IMA_STEP_TABLE: [i32; 89] = [
    7, 8, 9, 10, 11, 12, 13, 14, 16, 17, 19, 21, 23, 25, 28, 31, 34, 37, 41, 45, 50, 55, 60, 66,
    73, 80, 88, 97, 107, 118, 130, 143, 157, 173, 190, 209, 230, 253, 279, 307, 337, 371, 408, 449,
    494, 544, 598, 658, 724, 796, 876, 963, 1060, 1166, 1282, 1411, 1552, 1707, 1878, 2066, 2272,
    2499, 2749, 3024, 3327, 3660, 4026, 4428, 4871, 5358, 5894, 6484, 7132, 7845, 8630, 9493,
    10442, 11487, 12635, 13899, 15289, 16818, 18500, 20350, 22385, 24623, 27086, 29794, 32767,
];

#[inline]
fn decode_ima_nibble(nibble: u8, pred: &mut i32, step_idx: &mut i32) -> i16 {
    let step = IMA_STEP_TABLE[(*step_idx).clamp(0, 88) as usize];
    let mut diff = step >> 3;
    if (nibble & 1) != 0 {
        diff += step >> 2;
    }
    if (nibble & 2) != 0 {
        diff += step >> 1;
    }
    if (nibble & 4) != 0 {
        diff += step;
    }
    if (nibble & 8) != 0 {
        *pred = (*pred - diff).clamp(-32768, 32767);
    } else {
        *pred = (*pred + diff).clamp(-32768, 32767);
    }
    *step_idx = (*step_idx + IMA_INDEX_TABLE[(nibble & 0x0F) as usize]).clamp(0, 88);
    *pred as i16
}

/// Decodes a Perfect World `sfx.pck` RIFF/WAVE file (`fmt=1` 8/16-bit PCM or `fmt=17` IMA-ADPCM).
pub fn decode_wav_pcm_or_ima_adpcm(raw: &[u8]) -> Option<DecodedAudioClip> {
    if raw.len() < 44 || &raw[0..4] != b"RIFF" || &raw[8..12] != b"WAVE" {
        return None;
    }
    let mut pos = 12usize;
    let mut fmt_tag = 0u16;
    let mut channels = 1u16;
    let mut sample_rate = 22050u32;
    let mut block_align = 0u16;
    let mut bits_per_sample = 16u16;
    let mut data_slice: Option<&[u8]> = None;

    while pos + 8 <= raw.len() {
        let cid = &raw[pos..pos + 4];
        let clen = u32::from_le_bytes([raw[pos + 4], raw[pos + 5], raw[pos + 6], raw[pos + 7]]) as usize;
        let body_start = pos + 8;
        if body_start + clen > raw.len() {
            break;
        }
        let body = &raw[body_start..body_start + clen];
        if cid == b"fmt " && body.len() >= 16 {
            fmt_tag = u16::from_le_bytes([body[0], body[1]]);
            channels = u16::from_le_bytes([body[2], body[3]]).max(1);
            sample_rate = u32::from_le_bytes([body[4], body[5], body[6], body[7]]);
            block_align = u16::from_le_bytes([body[12], body[13]]);
            bits_per_sample = u16::from_le_bytes([body[14], body[15]]);
        } else if cid == b"data" {
            data_slice = Some(body);
            break;
        }
        pos = body_start + clen + (clen & 1);
    }

    let data = data_slice?;
    let mut samples = Vec::new();
    match fmt_tag {
        1 => {
            if bits_per_sample == 16 {
                samples.reserve(data.len() / 2);
                for ch in data.chunks_exact(2) {
                    samples.push(i16::from_le_bytes([ch[0], ch[1]]));
                }
            } else if bits_per_sample == 8 {
                samples.reserve(data.len());
                for &b in data {
                    samples.push(((b as i16) - 128) * 256);
                }
            } else {
                return None;
            }
        }
        17 if block_align >= 4 * channels => {
            // IMA-ADPCM (`fmt=17`) used across `sfx.pck`
            let blk = block_align as usize;
            for block in data.chunks(blk) {
                if block.len() < 4 * (channels as usize) {
                    break;
                }
                if channels == 1 {
                    let mut pred = i16::from_le_bytes([block[0], block[1]]) as i32;
                    let mut step_idx = (block[2] as i32).clamp(0, 88);
                    samples.push(pred as i16);
                    for &byte in &block[4..] {
                        samples.push(decode_ima_nibble(byte & 0x0F, &mut pred, &mut step_idx));
                        samples.push(decode_ima_nibble(byte >> 4, &mut pred, &mut step_idx));
                    }
                } else {
                    let mut pred_l = i16::from_le_bytes([block[0], block[1]]) as i32;
                    let mut step_l = (block[2] as i32).clamp(0, 88);
                    let mut pred_r = i16::from_le_bytes([block[4], block[5]]) as i32;
                    let mut step_r = (block[6] as i32).clamp(0, 88);
                    samples.push(pred_l as i16);
                    samples.push(pred_r as i16);
                    for pair in block[8..].chunks_exact(8) {
                        let mut l_out = [0i16; 8];
                        let mut r_out = [0i16; 8];
                        for i in 0..4 {
                            l_out[i * 2] = decode_ima_nibble(pair[i] & 0x0F, &mut pred_l, &mut step_l);
                            l_out[i * 2 + 1] = decode_ima_nibble(pair[i] >> 4, &mut pred_l, &mut step_l);
                            r_out[i * 2] = decode_ima_nibble(pair[4 + i] & 0x0F, &mut pred_r, &mut step_r);
                            r_out[i * 2 + 1] = decode_ima_nibble(pair[4 + i] >> 4, &mut pred_r, &mut step_r);
                        }
                        for k in 0..8 {
                            samples.push(l_out[k]);
                            samples.push(r_out[k]);
                        }
                    }
                }
            }
        }
        _ => return None,
    }

    Some(DecodedAudioClip {
        sample_rate,
        channels,
        samples_i16: samples,
    })
}

/// Auto-decodes either an `OggS` Vorbis I bitstream (`music/*.ogg`, `sfx/*.ogg`) or a
/// `RIFF/WAVE` (`PCM` 8/16/24/32-bit or `IMA-ADPCM` `fmt=0x0011`) clip to 16-bit PCM.
pub fn decode_audio_auto(raw: &[u8]) -> Option<DecodedAudioClip> {
    if raw.len() >= 4 && &raw[0..4] == b"OggS" {
        crate::vorbis_synth::decode_ogg_vorbis_to_pcm(raw)
    } else if raw.len() >= 12 && &raw[0..4] == b"RIFF" {
        decode_wav_pcm_or_ima_adpcm(raw)
    } else {
        None
    }
}

/// Encodes a `DecodedAudioClip` into a stereo-panned 16-bit PCM `RIFF/WAVE` image in memory
/// (`left_gain`, `right_gain` in `0.0..=1.0`).
pub fn encode_pcm16_to_riff_wav(
    clip: &DecodedAudioClip,
    left_gain: f32,
    right_gain: f32,
) -> Vec<u8> {
    let gl = left_gain.clamp(0.0, 1.5);
    let gr = right_gain.clamp(0.0, 1.5);
    let frames = if clip.channels >= 2 {
        clip.samples_i16.len() / (clip.channels as usize)
    } else {
        clip.samples_i16.len()
    };
    let out_ch = 2u16;
    let data_bytes = (frames * 4) as u32;
    let byte_rate = clip.sample_rate * 4;
    let mut wav = Vec::with_capacity(44 + data_bytes as usize);
    wav.extend_from_slice(b"RIFF");
    wav.extend_from_slice(&(36 + data_bytes).to_le_bytes());
    wav.extend_from_slice(b"WAVEfmt ");
    wav.extend_from_slice(&16u32.to_le_bytes());
    wav.extend_from_slice(&1u16.to_le_bytes()); // PCM
    wav.extend_from_slice(&out_ch.to_le_bytes());
    wav.extend_from_slice(&clip.sample_rate.to_le_bytes());
    wav.extend_from_slice(&byte_rate.to_le_bytes());
    wav.extend_from_slice(&4u16.to_le_bytes());
    wav.extend_from_slice(&16u16.to_le_bytes());
    wav.extend_from_slice(b"data");
    wav.extend_from_slice(&data_bytes.to_le_bytes());

    if clip.channels >= 2 {
        let stride = clip.channels as usize;
        for f in 0..frames {
            let l = (clip.samples_i16[f * stride] as f32 * gl).clamp(-32768.0, 32767.0) as i16;
            let r = (clip.samples_i16[f * stride + 1] as f32 * gr).clamp(-32768.0, 32767.0) as i16;
            wav.extend_from_slice(&l.to_le_bytes());
            wav.extend_from_slice(&r.to_le_bytes());
        }
    } else {
        for &s in clip.samples_i16.iter().take(frames) {
            let l = (s as f32 * gl).clamp(-32768.0, 32767.0) as i16;
            let r = (s as f32 * gr).clamp(-32768.0, 32767.0) as i16;
            wav.extend_from_slice(&l.to_le_bytes());
            wav.extend_from_slice(&r.to_le_bytes());
        }
    }
    wav
}

/// 3D Spatial SFX Listener & Precinct BGM Playlist Controller (`AM3DSoundBuffer` / `CECWorld::UpdateBGM`).
#[derive(Debug, Clone)]
pub struct SpatialAudioMixer {
    pub listener_pos: Vec3,
    pub listener_right: Vec3,
    pub music_volume: f32,
    pub sfx_volume: f32,
    pub active_precinct_name: String,
    pub playlist: Vec<String>,
    pub current_track_idx: usize,
    pub track_elapsed_s: f32,
}

impl Default for SpatialAudioMixer {
    fn default() -> Self {
        Self {
            listener_pos: Vec3::new(0.0, 0.0, 0.0),
            listener_right: Vec3::new(1.0, 0.0, 0.0),
            music_volume: 0.65,
            sfx_volume: 0.65,
            active_precinct_name: String::new(),
            playlist: Vec::new(),
            current_track_idx: 0,
            track_elapsed_s: 0.0,
        }
    }
}

impl SpatialAudioMixer {
    /// Computes `(left_gain, right_gain)` in `[0.0..=1.0]` for a 3D world emitter (`min_dist..max_dist`).
    pub fn compute_stereo_gains(&self, source_pos: Vec3, min_dist: f32, max_dist: f32) -> (f32, f32) {
        let delta = source_pos.sub(self.listener_pos);
        let dist = (delta.x * delta.x + delta.y * delta.y + delta.z * delta.z).sqrt();
        if dist >= max_dist {
            return (0.0, 0.0);
        }
        let atten = if dist <= min_dist {
            1.0
        } else {
            1.0 - ((dist - min_dist) / (max_dist - min_dist).max(0.01)).clamp(0.0, 1.0)
        };
        let pan = if dist > 0.001 {
            let inv = 1.0 / dist;
            (delta.x * inv * self.listener_right.x
                + delta.y * inv * self.listener_right.y
                + delta.z * inv * self.listener_right.z)
                .clamp(-1.0, 1.0)
        } else {
            0.0
        };
        let base = atten * self.sfx_volume.clamp(0.0, 1.0);
        let left = base * ((1.0 - pan) * 0.5 + 0.5).clamp(0.0, 1.0);
        let right = base * ((1.0 + pan) * 0.5 + 0.5).clamp(0.0, 1.0);
        (left, right)
    }

    /// Updates the active zone `precinct.clt` BGM playlist (`music/*.ogg` / `music/*.mp3`) and returns
    /// `Some(next_track_path)` whenever a new precinct is entered or the current BGM track finishes.
    pub fn tick_bgm_playlist(
        &mut self,
        precinct_name: &str,
        tracks: &[String],
        dt: f32,
        track_period_s: f32,
    ) -> Option<String> {
        if precinct_name != self.active_precinct_name && !tracks.is_empty() {
            self.active_precinct_name = precinct_name.to_string();
            self.playlist = tracks.to_vec();
            self.current_track_idx = 0;
            self.track_elapsed_s = 0.0;
            return self.playlist.first().cloned();
        }
        if self.playlist.is_empty() {
            return None;
        }
        self.track_elapsed_s += dt.max(0.0);
        if self.track_elapsed_s >= track_period_s.max(30.0) {
            self.track_elapsed_s = 0.0;
            self.current_track_idx = (self.current_track_idx + 1) % self.playlist.len();
            return self.playlist.get(self.current_track_idx).cloned();
        }
        None
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_ogg_vorbis_header_and_ima_adpcm_and_spatial_3d_mixer() {
        // Synthesize a valid OggS Vorbis identification page (`\x01vorbis`, 44100 Hz, 2ch, 882000 samples = 20.0s)
        let mut ogg = Vec::new();
        ogg.extend_from_slice(b"OggS");
        ogg.push(0); // version
        ogg.push(0x02); // BOS
        ogg.extend_from_slice(&882_000u64.to_le_bytes()); // granule pos
        ogg.extend_from_slice(&0x1420_2305u32.to_le_bytes()); // serial
        ogg.extend_from_slice(&0u32.to_le_bytes()); // seq
        ogg.extend_from_slice(&0u32.to_le_bytes()); // crc placeholder
        ogg.push(1); // 1 segment
        ogg.push(30); // 30-byte Vorbis ID header
        ogg.extend_from_slice(b"\x01vorbis");
        ogg.extend_from_slice(&0u32.to_le_bytes()); // vorbis v0
        ogg.push(2); // stereo
        ogg.extend_from_slice(&44_100u32.to_le_bytes());
        ogg.extend_from_slice(&0i32.to_le_bytes());
        ogg.extend_from_slice(&128_000i32.to_le_bytes());
        ogg.extend_from_slice(&0i32.to_le_bytes());
        ogg.push(0xB8);
        ogg.push(1);
        let crc = ogg_page_crc32(&ogg);
        ogg[22..26].copy_from_slice(&crc.to_le_bytes());

        let info = inspect_ogg_vorbis(&ogg).expect("valid OggS Vorbis stream");
        assert_eq!(info.channels, 2);
        assert_eq!(info.sample_rate, 44_100);
        assert!((info.duration_seconds() - 20.0).abs() < 1e-3);

        // Synthesize a mono IMA-ADPCM (`fmt=17`) RIFF/WAVE clip and decode it
        let mut wav = Vec::new();
        wav.extend_from_slice(b"RIFF");
        wav.extend_from_slice(&44u32.to_le_bytes());
        wav.extend_from_slice(b"WAVEfmt ");
        wav.extend_from_slice(&16u32.to_le_bytes());
        wav.extend_from_slice(&17u16.to_le_bytes()); // IMA-ADPCM
        wav.extend_from_slice(&1u16.to_le_bytes()); // mono
        wav.extend_from_slice(&22_050u32.to_le_bytes());
        wav.extend_from_slice(&11_025u32.to_le_bytes());
        wav.extend_from_slice(&8u16.to_le_bytes()); // block_align = 8
        wav.extend_from_slice(&4u16.to_le_bytes()); // 4-bit ADPCM
        wav.extend_from_slice(b"data");
        wav.extend_from_slice(&8u32.to_le_bytes());
        wav.extend_from_slice(&1000i16.to_le_bytes()); // initial predictor
        wav.push(12); // step index
        wav.push(0);
        wav.extend_from_slice(&[0x31, 0x25, 0x94, 0x12]);

        let clip = decode_wav_pcm_or_ima_adpcm(&wav).expect("valid IMA-ADPCM wav");
        assert_eq!(clip.sample_rate, 22_050);
        assert_eq!(clip.samples_i16.len(), 9);
        assert_eq!(clip.samples_i16[0], 1000);

        // Verify 3D stereo panning & BGM playlist rotation
        let mut mixer = SpatialAudioMixer::default();
        let (gl, gr) = mixer.compute_stereo_gains(Vec3::new(10.0, 0.0, 0.0), 2.0, 40.0);
        assert!(gr > gl && gr > 0.0, "emitter on +X right must pan right ({gl} vs {gr})");
        let tracks = vec!["music\\archosaur_01.mp3".to_string(), "music\\archosaur_02.mp3".to_string()];
        assert_eq!(
            mixer.tick_bgm_playlist("Archosaur", &tracks, 0.1, 60.0).as_deref(),
            Some("music\\archosaur_01.mp3")
        );
        assert_eq!(
            mixer.tick_bgm_playlist("Archosaur", &tracks, 65.0, 60.0).as_deref(),
            Some("music\\archosaur_02.mp3")
        );

        // Also decode the real `patcher/skin/sounds/click.wav` in `source/pw142/`!
        let click_path = std::path::Path::new(env!("CARGO_MANIFEST_DIR"))
            .join("../../../source/pw142/patcher/skin/sounds/click.wav");
        if let Ok(click_raw) = std::fs::read(&click_path) {
            let real_clip = decode_audio_auto(&click_raw).expect("click.wav decode");
            assert!(real_clip.sample_rate >= 8_000 && !real_clip.samples_i16.is_empty());
            let panned_wav = encode_pcm16_to_riff_wav(&real_clip, 0.8, 0.4);
            assert!(panned_wav.starts_with(b"RIFF") && panned_wav.len() > 44);
        }
    }
}
