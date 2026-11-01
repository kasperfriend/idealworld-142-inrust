//! `AngelicaMedia` (`AMSoundEngine` / `AMSoundStream`) — Native WinMM MP3/WAV BGM & SFX Engine.
//!
//! Mirrors `CECGameRun::CreateLoginWorld` (`0x434b80.c`: `music\theme_%c.mp3`, `SFX\Interface\ClickB.wav`).
//! On Windows, uses OS-native `winmm.dll` (`mciSendStringW` for streaming MP3/WAV background music
//! and `PlaySoundW(SND_MEMORY | SND_ASYNC)` for unpacked `sfx.pck` `.wav` UI/skill effects) with
//! zero external dependencies.

use std::path::Path;

#[cfg(target_os = "windows")]
#[link(name = "winmm")]
unsafe extern "system" {
    fn mciSendStringW(
        lpszCommand: *const u16,
        lpszReturnString: *mut u16,
        cchReturn: u32,
        hwndCallback: *mut core::ffi::c_void,
    ) -> u32;
    fn PlaySoundW(pszSound: *const u8, hmod: *mut core::ffi::c_void, fdwSound: u32) -> i32;
}

#[cfg(target_os = "windows")]
fn send_mci(cmd: &str) {
    let mut wide: Vec<u16> = cmd.encode_utf16().collect();
    wide.push(0);
    unsafe {
        let _ = mciSendStringW(
            wide.as_ptr(),
            core::ptr::null_mut(),
            0,
            core::ptr::null_mut(),
        );
    }
}

#[derive(Debug, Clone)]
pub struct AmSoundEngine {
    pub master_volume: u8,
    pub sfx_volume: u8,
    pub bgm_playlist: Vec<String>,
    pub active_bgm: Option<String>,
    /// Keeps the active async `SND_MEMORY` buffer alive while `winmm` plays it.
    last_sfx_buffer: Vec<u8>,
}

impl Default for AmSoundEngine {
    fn default() -> Self {
        Self {
            master_volume: 65,
            sfx_volume: 75,
            bgm_playlist: Vec::new(),
            active_bgm: None,
            last_sfx_buffer: Vec::new(),
        }
    }
}

impl AmSoundEngine {
    pub fn new(music_vol: u8, sfx_vol: u8) -> Self {
        Self {
            master_volume: music_vol.min(100),
            sfx_volume: sfx_vol.min(100),
            bgm_playlist: Vec::new(),
            active_bgm: None,
            last_sfx_buffer: Vec::new(),
        }
    }

    pub fn play_bgm_file(&mut self, path: &Path) {
        if !path.is_file() {
            return;
        }
        let path_str = path.to_string_lossy().into_owned();
        if self.active_bgm.as_deref() == Some(path_str.as_str()) {
            return;
        }
        self.stop_bgm();
        self.active_bgm = Some(path_str.clone());
        if !self.bgm_playlist.contains(&path_str) {
            self.bgm_playlist.push(path_str.clone());
        }

        #[cfg(target_os = "windows")]
        if self.master_volume > 0 {
            send_mci("close pw_bgm");
            let open_cmd = format!("open \"{}\" type mpegvideo alias pw_bgm", path.display());
            send_mci(&open_cmd);
            let vol = (self.master_volume as u32).min(100) * 10;
            send_mci(&format!("setaudio pw_bgm volume to {vol}"));
            send_mci("play pw_bgm repeat");
        }
    }

    pub fn stop_bgm(&mut self) {
        self.active_bgm = None;
        #[cfg(target_os = "windows")]
        {
            // Stop any active SND_MEMORY sound too if shutting down
            send_mci("stop pw_bgm");
            send_mci("close pw_bgm");
        }
    }

    pub fn play_sfx_wav_bytes(&mut self, wav_bytes: Vec<u8>) {
        let vol = (self.sfx_volume.min(100) as f32) / 100.0;
        self.play_spatial_audio_bytes(&wav_bytes, vol, vol);
    }

    /// Plays any `.ogg` Vorbis I, IMA-ADPCM `.wav`, or PCM `.wav` clip with 3D stereo gains
    /// (`left_gain`, `right_gain` in `0.0..=1.0`) via WinMM `PlaySoundW` on Windows or dynamic
    /// `libasound.so.2` (ALSA) PCM output on Linux!
    pub fn play_spatial_audio_bytes(&mut self, raw_bytes: &[u8], left_gain: f32, right_gain: f32) {
        if self.sfx_volume == 0 || raw_bytes.len() < 28 || (left_gain <= 0.001 && right_gain <= 0.001) {
            return;
        }
        let Some(clip) = crate::audio_ogg::decode_audio_auto(raw_bytes) else {
            return;
        };
        let riff = crate::audio_ogg::encode_pcm16_to_riff_wav(&clip, left_gain, right_gain);
        self.last_sfx_buffer = riff;

        #[cfg(target_os = "windows")]
        unsafe {
            const SND_ASYNC: u32 = 0x0001;
            const SND_NODEFAULT: u32 = 0x0002;
            const SND_MEMORY: u32 = 0x0004;
            let _ = PlaySoundW(
                self.last_sfx_buffer.as_ptr(),
                core::ptr::null_mut(),
                SND_MEMORY | SND_ASYNC | SND_NODEFAULT,
            );
        }

        #[cfg(target_os = "linux")]
        {
            linux_alsa_try_play_async(clip, left_gain, right_gain);
        }
    }
}

#[cfg(target_os = "linux")]
fn linux_alsa_try_play_async(
    clip: crate::audio_ogg::DecodedAudioClip,
    left_gain: f32,
    right_gain: f32,
) {
    // Only spawn ALSA playback when `PW_ENABLE_ALSA=1` or `/dev/snd/pcmC0D0p` is present on desktop Linux
    if std::env::var_os("PW_ENABLE_ALSA").is_none()
        && !std::path::Path::new("/dev/snd/pcmC0D0p").exists()
    {
        return;
    }
    let _ = std::thread::spawn(move || unsafe {
        #[link(name = "dl")]
        unsafe extern "C" {
            fn dlopen(filename: *const u8, flags: i32) -> *mut core::ffi::c_void;
            fn dlsym(handle: *mut core::ffi::c_void, symbol: *const u8) -> *mut core::ffi::c_void;
        }
        let lib = dlopen(b"libasound.so.2\0".as_ptr(), 1);
        if lib.is_null() {
            return;
        }
        type SndPcmOpen = unsafe extern "C" fn(*mut *mut core::ffi::c_void, *const u8, i32, i32) -> i32;
        type SndPcmSetParams =
            unsafe extern "C" fn(*mut core::ffi::c_void, i32, i32, u32, u32, i32, u32) -> i32;
        type SndPcmWritei =
            unsafe extern "C" fn(*mut core::ffi::c_void, *const core::ffi::c_void, usize) -> isize;
        type SndPcmDrain = unsafe extern "C" fn(*mut core::ffi::c_void) -> i32;
        type SndPcmClose = unsafe extern "C" fn(*mut core::ffi::c_void) -> i32;

        let p_open = dlsym(lib, b"snd_pcm_open\0".as_ptr());
        let p_params = dlsym(lib, b"snd_pcm_set_params\0".as_ptr());
        let p_writei = dlsym(lib, b"snd_pcm_writei\0".as_ptr());
        let p_drain = dlsym(lib, b"snd_pcm_drain\0".as_ptr());
        let p_close = dlsym(lib, b"snd_pcm_close\0".as_ptr());
        if p_open.is_null() || p_params.is_null() || p_writei.is_null() || p_close.is_null() {
            return;
        }
        let f_open: SndPcmOpen = core::mem::transmute(p_open);
        let f_params: SndPcmSetParams = core::mem::transmute(p_params);
        let f_writei: SndPcmWritei = core::mem::transmute(p_writei);
        let f_close: SndPcmClose = core::mem::transmute(p_close);

        let mut pcm: *mut core::ffi::c_void = core::ptr::null_mut();
        if f_open(&mut pcm, b"default\0".as_ptr(), 0, 0) < 0 || pcm.is_null() {
            return;
        }
        // SND_PCM_FORMAT_S16_LE = 2, SND_PCM_ACCESS_RW_INTERLEAVED = 3
        if f_params(pcm, 2, 3, 2, clip.sample_rate, 1, 100_000) == 0 {
            let wav = crate::audio_ogg::encode_pcm16_to_riff_wav(&clip, left_gain, right_gain);
            if wav.len() > 44 {
                let frames = (wav.len() - 44) / 4;
                let _ = f_writei(pcm, wav[44..].as_ptr() as *const _, frames);
                if !p_drain.is_null() {
                    let f_drain: SndPcmDrain = core::mem::transmute(p_drain);
                    let _ = f_drain(pcm);
                }
            }
        }
        let _ = f_close(pcm);
    });
}

impl Drop for AmSoundEngine {
    fn drop(&mut self) {
        #[cfg(target_os = "windows")]
        unsafe {
            let _ = PlaySoundW(core::ptr::null(), core::ptr::null_mut(), 0);
            send_mci("close pw_bgm");
        }
    }
}
