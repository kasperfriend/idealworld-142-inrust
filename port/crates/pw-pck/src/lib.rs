//! `pw-pck` — Angelica `.pck` / `.pkx` v2.0.2 Package Reader, Builder & Virtual File System.
//!
//! Clean-room 1:1 implementation of `AFilePackage::Open` (`0x76fff0.c`) and `AFilePackage::Close`
//! (`0x770990.c`) using the exact XOR keys recovered from `elementclient.exe` `.rdata` (`0x00987120`).
//! Supports both in-memory archives (`from_bytes`) and lazy seek-based streaming (`open_path`) so
//! mounting all 16 multi-hundred-MB `.pck`/`.pkx` archives on disk takes milliseconds and minimal RAM.

use std::collections::HashMap;
use std::fs::File;
use std::io::{Read, Seek, SeekFrom};
use std::path::{Path, PathBuf};
use std::sync::{Arc, Mutex};

use pw_core::{
    encode_gbk, find_path_case_insensitive, normalize_vfs_path, zlib_compress, zlib_uncompress,
    BinaryBuilder, BinaryCursor, PwError, PwResult,
};

pub const PCK_FSIG_1: u32 = 0x4dca_23ef;
pub const PCK_FSIG_2: u32 = 0x56a0_89b7;
pub const PCK_GUARD_0: u32 = 0xfdfd_feee;
pub const PCK_GUARD_1: u32 = 0xf00d_beef;
pub const PCK_VERSION_202: u32 = 0x0002_0002;
pub const PCK_MASK_KEY_1: u32 = 0xa893_7462;
pub const PCK_MASK_KEY_2: u32 = 0xf1a4_3653;
pub const PCK_ENTRY_RAW_SIZE: usize = 0x114; // 276 bytes
pub const PCK_TRAILER_SIZE: usize = 0x118; // 280 bytes
pub const PCK_SAFE_HEADER_FLAG: u32 = 0x8000_0000;
pub const PCK_DEFAULT_DESCRIPTION: &[u8] =
    b"lica File Package, Perfect World Co. Ltd. 2002~2008. All Rights Reserved. ";

#[derive(Debug, Clone, PartialEq, Eq)]
pub struct PckEntry {
    pub path: String,
    pub normalized_path: String,
    pub offset: u32,
    pub uncompressed_size: u32,
    pub compressed_size: u32,
    pub access_count: i32,
}

#[derive(Debug, Clone)]
pub struct PckHeaderInfo {
    pub total_pack_size: u32,
    pub version: u32,
    pub entry_table_offset: u32,
    pub flags: u32,
    pub description: String,
    pub entry_count: u32,
}

#[derive(Debug, Clone)]
enum PckBacking {
    Memory(Arc<Vec<u8>>),
    DiskSpan {
        pck_path: PathBuf,
        pck: Arc<Mutex<File>>,
        pck_len: u64,
        pkx: Option<Arc<Mutex<File>>>,
        pkx_len: u64,
    },
}

impl PckBacking {
    fn total_len(&self) -> u64 {
        match self {
            Self::Memory(b) => b.len() as u64,
            Self::DiskSpan { pck_len, pkx_len, .. } => *pck_len + *pkx_len,
        }
    }

    fn read_span(&self, start: u64, len: usize) -> PwResult<Vec<u8>> {
        if len == 0 {
            return Ok(Vec::new());
        }
        let total = self.total_len();
        let end = start.saturating_add(len as u64);
        if end > total {
            return Err(PwError::UnexpectedEof {
                offset: start as usize,
                needed: len,
                available: total.saturating_sub(start) as usize,
            });
        }
        match self {
            Self::Memory(b) => Ok(b[start as usize..end as usize].to_vec()),
            Self::DiskSpan {
                pck_path,
                pck,
                pck_len,
                pkx,
                ..
            } => {
                let mut out = vec![0u8; len];
                let mut filled = 0usize;
                if start < *pck_len {
                    let take = ((*pck_len - start) as usize).min(len);
                    let mut fh = pck
                        .lock()
                        .map_err(|_| PwError::Io(format!("'{}': poisoned lock", pck_path.display())))?;
                    fh.seek(SeekFrom::Start(start))
                        .map_err(|e| PwError::Io(format!("'{}': {e}", pck_path.display())))?;
                    fh.read_exact(&mut out[..take])
                        .map_err(|e| PwError::Io(format!("'{}': {e}", pck_path.display())))?;
                    filled += take;
                }
                if filled < len {
                    let pkx_fh = pkx.as_ref().ok_or_else(|| {
                        PwError::InvalidData(format!(
                            "'{}': span requires .pkx overflow file",
                            pck_path.display()
                        ))
                    })?;
                    let pkx_start = (start + filled as u64).saturating_sub(*pck_len);
                    let mut fh = pkx_fh
                        .lock()
                        .map_err(|_| PwError::Io(format!("'{}': poisoned pkx lock", pck_path.display())))?;
                    fh.seek(SeekFrom::Start(pkx_start))
                        .map_err(|e| PwError::Io(format!("'{}' (.pkx): {e}", pck_path.display())))?;
                    fh.read_exact(&mut out[filled..])
                        .map_err(|e| PwError::Io(format!("'{}' (.pkx): {e}", pck_path.display())))?;
                }
                Ok(out)
            }
        }
    }
}

#[derive(Debug, Clone)]
pub struct PckArchive {
    backing: PckBacking,
    pub header: PckHeaderInfo,
    pub entries: Vec<PckEntry>,
    index_by_path: HashMap<String, usize>,
}

impl PckArchive {
    /// Opens an Angelica `.pck` archive lazily via `Seek` (reading only the 12-byte header,
    /// 280-byte trailer, and directory table; individual assets stream on demand).
    pub fn open_path(path: impl AsRef<Path>) -> PwResult<Self> {
        let p = path.as_ref();
        let file = File::open(p).map_err(|e| PwError::Io(format!("'{}': {e}", p.display())))?;
        let pck_len = file
            .metadata()
            .map_err(|e| PwError::Io(format!("'{}': {e}", p.display())))?
            .len();

        let pkx_candidate = p.with_extension("pkx");
        let (pkx, pkx_len) = if pkx_candidate.is_file() {
            let pf = File::open(&pkx_candidate)
                .map_err(|e| PwError::Io(format!("'{}': {e}", pkx_candidate.display())))?;
            let plen = pf
                .metadata()
                .map_err(|e| PwError::Io(format!("'{}': {e}", pkx_candidate.display())))?
                .len();
            (Some(Arc::new(Mutex::new(pf))), plen)
        } else {
            (None, 0)
        };

        let backing = PckBacking::DiskSpan {
            pck_path: p.to_path_buf(),
            pck: Arc::new(Mutex::new(file)),
            pck_len,
            pkx,
            pkx_len,
        };
        Self::from_backing(backing)
    }

    pub fn from_bytes(data: Vec<u8>) -> PwResult<Self> {
        Self::from_backing(PckBacking::Memory(Arc::new(data)))
    }

    fn from_backing(backing: PckBacking) -> PwResult<Self> {
        let total_len = backing.total_len();
        if total_len < (12 + PCK_TRAILER_SIZE) as u64 {
            return Err(PwError::UnexpectedEof {
                offset: 0,
                needed: 12 + PCK_TRAILER_SIZE,
                available: total_len as usize,
            });
        }

        let hdr_bytes = backing.read_span(0, 12)?;
        let mut hdr_cur = BinaryCursor::new(&hdr_bytes);
        let sig1 = hdr_cur.read_u32_le()?;
        let total_pack_size = hdr_cur.read_u32_le()?;
        let sig2 = hdr_cur.read_u32_le()?;
        if sig1 != PCK_FSIG_1 {
            return Err(PwError::InvalidMagic {
                expected: "PCK_FSIG_1 (0x4dca23ef)",
                found: sig1,
            });
        }
        if sig2 != PCK_FSIG_2 {
            return Err(PwError::InvalidMagic {
                expected: "PCK_FSIG_2 (0x56a089b7)",
                found: sig2,
            });
        }

        let trailer_pos = total_len - PCK_TRAILER_SIZE as u64;
        let tr_bytes = backing.read_span(trailer_pos, PCK_TRAILER_SIZE)?;
        let mut tr_cur = BinaryCursor::new(&tr_bytes);
        let guard0 = tr_cur.read_u32_le()?;
        let ver_hdr = tr_cur.read_u32_le()?;
        let enc_entry_offset = tr_cur.read_u32_le()?;
        let flags = tr_cur.read_u32_le()?;
        let desc = tr_cur.read_fixed_gbk(252)?;
        let guard1 = tr_cur.read_u32_le()?;
        let entry_count = tr_cur.read_u32_le()?;
        let ver_trailer = tr_cur.read_u32_le()?;

        if guard0 != PCK_GUARD_0 {
            return Err(PwError::InvalidMagic {
                expected: "PCK_GUARD_0 (0xfdfdfeee)",
                found: guard0,
            });
        }
        if guard1 != PCK_GUARD_1 {
            return Err(PwError::InvalidMagic {
                expected: "PCK_GUARD_1 (0xf00dbeef)",
                found: guard1,
            });
        }
        if ver_hdr != PCK_VERSION_202 || ver_trailer != PCK_VERSION_202 {
            return Err(PwError::UnsupportedVersion {
                format: "Angelica PCK",
                version: ver_trailer,
            });
        }

        // In >2GB spans, entry_table_offset may use flags high bits if needed; standard v2.0.2 XOR:
        let entry_table_offset = enc_entry_offset ^ PCK_MASK_KEY_1;
        if (entry_table_offset as u64) > trailer_pos {
            return Err(PwError::InvalidData(format!(
                "decrypted PCK entry offset {entry_table_offset:#x} exceeds trailer {trailer_pos:#x}"
            )));
        }

        let dir_len = (trailer_pos - entry_table_offset as u64) as usize;
        let dir_bytes = backing.read_span(entry_table_offset as u64, dir_len)?;
        let mut dir_cur = BinaryCursor::new(&dir_bytes);
        let mut entries = Vec::with_capacity(entry_count as usize);
        let mut index_by_path = HashMap::with_capacity(entry_count as usize);

        for idx in 0..(entry_count as usize) {
            let len1 = dir_cur.read_u32_le()? ^ PCK_MASK_KEY_1;
            let len2 = dir_cur.read_u32_le()? ^ PCK_MASK_KEY_2;
            if len1 != len2 {
                return Err(PwError::InvalidData(format!(
                    "PCK entry #{idx} length mismatch: {len1:#x} != {len2:#x}"
                )));
            }
            let block = dir_cur.read_bytes(len1 as usize)?;
            let raw_entry_vec;
            let raw_entry: &[u8] = if (len1 as usize) < PCK_ENTRY_RAW_SIZE {
                raw_entry_vec = zlib_uncompress(block, PCK_ENTRY_RAW_SIZE)?;
                &raw_entry_vec
            } else if (len1 as usize) == PCK_ENTRY_RAW_SIZE {
                block
            } else {
                return Err(PwError::InvalidData(format!(
                    "PCK entry #{idx} invalid block size {len1}"
                )));
            };

            let mut ecur = BinaryCursor::new(raw_entry);
            let path = ecur.read_fixed_gbk(260)?;
            let normalized_path = normalize_vfs_path(&path);
            let offset = ecur.read_u32_le()?;
            let uncompressed_size = ecur.read_u32_le()?;
            let compressed_size = ecur.read_u32_le()?;
            let access_count = ecur.read_i32_le()?;

            index_by_path.insert(normalized_path.clone(), idx);
            entries.push(PckEntry {
                path,
                normalized_path,
                offset,
                uncompressed_size,
                compressed_size,
                access_count,
            });
        }

        Ok(Self {
            backing,
            header: PckHeaderInfo {
                total_pack_size,
                version: ver_trailer,
                entry_table_offset,
                flags,
                description: desc,
                entry_count,
            },
            entries,
            index_by_path,
        })
    }

    pub fn len(&self) -> usize {
        self.entries.len()
    }

    pub fn is_empty(&self) -> bool {
        self.entries.is_empty()
    }

    pub fn get_entry(&self, vfs_path: &str) -> Option<&PckEntry> {
        let norm = normalize_vfs_path(vfs_path);
        self.index_by_path.get(&norm).map(|&i| &self.entries[i])
    }

    pub fn read_entry(&self, entry: &PckEntry) -> PwResult<Vec<u8>> {
        let raw = self
            .backing
            .read_span(entry.offset as u64, entry.compressed_size as usize)?;
        if entry.compressed_size < entry.uncompressed_size {
            zlib_uncompress(&raw, entry.uncompressed_size as usize)
        } else {
            Ok(raw)
        }
    }

    pub fn read_by_path(&self, vfs_path: &str) -> PwResult<Vec<u8>> {
        let entry = self
            .get_entry(vfs_path)
            .ok_or_else(|| PwError::InvalidData(format!("PCK entry not found: {vfs_path}")))?;
        self.read_entry(entry)
    }
}

/// Lossless Angelica `.pck` v2.0.2 writer (`AFilePackage` Flush/Create parity).
#[derive(Default)]
pub struct PckBuilder {
    files: Vec<(String, Vec<u8>)>,
}

impl PckBuilder {
    pub fn new() -> Self {
        Self { files: Vec::new() }
    }

    pub fn add_file(&mut self, path: impl Into<String>, content: Vec<u8>) {
        self.files.push((path.into(), content));
    }

    pub fn build(&self) -> PwResult<Vec<u8>> {
        let mut out = BinaryBuilder::with_capacity(4096);
        out.write_u32_le(PCK_FSIG_1);
        out.write_u32_le(0);
        out.write_u32_le(PCK_FSIG_2);

        let mut dir_records: Vec<(String, u32, u32, u32)> = Vec::with_capacity(self.files.len());
        for (path, raw) in &self.files {
            let offset = out.len() as u32;
            let uncomp_len = raw.len() as u32;
            let compressed = zlib_compress(raw, 6)?;
            let comp_len = if compressed.len() < raw.len() {
                out.write_bytes(&compressed);
                compressed.len() as u32
            } else {
                out.write_bytes(raw);
                uncomp_len
            };
            dir_records.push((path.clone(), offset, uncomp_len, comp_len));
        }

        let entry_table_offset = out.len() as u32;
        for (path, offset, uncomp_len, comp_len) in &dir_records {
            let mut raw_entry = [0u8; PCK_ENTRY_RAW_SIZE];
            let gbk = encode_gbk(&path.replace('/', "\\"));
            let copy_len = gbk.len().min(259);
            raw_entry[..copy_len].copy_from_slice(&gbk[..copy_len]);
            raw_entry[260..264].copy_from_slice(&offset.to_le_bytes());
            raw_entry[264..268].copy_from_slice(&uncomp_len.to_le_bytes());
            raw_entry[268..272].copy_from_slice(&comp_len.to_le_bytes());
            raw_entry[272..276].copy_from_slice(&0i32.to_le_bytes());

            let comp_entry = zlib_compress(&raw_entry, 6)?;
            let block: &[u8] = if comp_entry.len() < PCK_ENTRY_RAW_SIZE {
                &comp_entry
            } else {
                &raw_entry
            };
            let blen = block.len() as u32;
            out.write_u32_le(blen ^ PCK_MASK_KEY_1);
            out.write_u32_le(blen ^ PCK_MASK_KEY_2);
            out.write_bytes(block);
        }

        out.write_u32_le(PCK_GUARD_0);
        out.write_u32_le(PCK_VERSION_202);
        out.write_u32_le(entry_table_offset ^ PCK_MASK_KEY_1);
        out.write_u32_le(0);
        let mut desc = [0u8; 252];
        desc[..PCK_DEFAULT_DESCRIPTION.len()].copy_from_slice(PCK_DEFAULT_DESCRIPTION);
        out.write_bytes(&desc);
        out.write_u32_le(PCK_GUARD_1);
        out.write_u32_le(dir_records.len() as u32);
        out.write_u32_le(PCK_VERSION_202);

        let total_size = out.len() as u32;
        out.patch_u32_le(4, total_size);
        Ok(out.into_vec())
    }
}

/// Multi-archive Angelica Virtual File System (`af_Initialize` + `AFilePackageMan`).
#[derive(Default)]
pub struct VirtualFileSystem {
    root_dir: Option<PathBuf>,
    packages: HashMap<String, PckArchive>,
}

impl VirtualFileSystem {
    pub fn new(root_dir: Option<PathBuf>) -> Self {
        Self {
            root_dir,
            packages: HashMap::new(),
        }
    }

    pub fn mount_pck(&mut self, mount_prefix: &str, archive: PckArchive) {
        self.packages
            .insert(normalize_vfs_path(mount_prefix), archive);
    }

    pub fn get_package(&self, mount_prefix: &str) -> Option<&PckArchive> {
        self.packages.get(&normalize_vfs_path(mount_prefix))
    }

    pub fn package_count(&self) -> usize {
        self.packages.len()
    }

    pub fn total_indexed_files(&self) -> usize {
        self.packages.values().map(PckArchive::len).sum()
    }

    pub fn read_file(&self, vfs_path: &str) -> PwResult<Vec<u8>> {
        let norm = normalize_vfs_path(vfs_path);
        if let Some(root) = &self.root_dir {
            if let Some(disk_path) = find_path_case_insensitive(root, &norm) {
                if disk_path.is_file() {
                    return pw_core::read_file_checked(disk_path);
                }
            }
        }
        if let Some((prefix, _)) = norm.split_once('\\') {
            if let Some(pkg) = self.packages.get(prefix) {
                if let Ok(bytes) = pkg.read_by_path(&norm) {
                    return Ok(bytes);
                }
            }
        }
        for pkg in self.packages.values() {
            if let Ok(bytes) = pkg.read_by_path(&norm) {
                return Ok(bytes);
            }
        }
        Err(PwError::InvalidData(format!("VFS file not found: {vfs_path}")))
    }

    /// Reads an AUI surface texture (checking `surfaces\<rel>`, `<rel>`, and `.dds`/`.tga`/`.bmp` swaps).
    pub fn read_ui_surface(&self, rel_path: &str) -> Option<Vec<u8>> {
        let clean = normalize_vfs_path(rel_path);
        if clean.is_empty() {
            return None;
        }
        let candidates = if clean.starts_with("surfaces\\") {
            vec![clean.clone()]
        } else {
            vec![format!("surfaces\\{clean}"), clean.clone()]
        };
        for cand in &candidates {
            if let Ok(bytes) = self.read_file(cand) {
                return Some(bytes);
            }
            // Angelica UI also falls back between .tga / .dds if converted in surfaces.pck
            if let Some((stem, _ext)) = cand.rsplit_once('.') {
                for alt in ["dds", "tga", "bmp"] {
                    let alt_path = format!("{stem}.{alt}");
                    if alt_path != *cand {
                        if let Ok(bytes) = self.read_file(&alt_path) {
                            return Some(bytes);
                        }
                    }
                }
            }
        }
        None
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_real_pw142_all_5_pcks_1430_files() {
        let Some(elem) = pw_core::find_test_pw142_element(env!("CARGO_MANIFEST_DIR")) else {
            return;
        };
        let cases = [
            (elem.join("configs.pck"), 72usize),
            (elem.join("interfaces.pck"), 1158usize),
            (elem.join("shaders.pck"), 166usize),
            (elem.join("fonts.pck"), 2usize),
            (elem.join("help/script.pck"), 32usize),
        ];
        let mut total_unpacked = 0usize;
        for (path, expected_count) in &cases {
            let pkg = PckArchive::open_path(path).expect(&path.display().to_string());
            assert_eq!(pkg.len(), *expected_count, "entry count mismatch for {path:?}");
            for entry in &pkg.entries {
                let payload = pkg.read_entry(entry).expect(&entry.path);
                assert_eq!(payload.len(), entry.uncompressed_size as usize);
                total_unpacked += 1;
            }
        }
        assert_eq!(total_unpacked, 1430);
    }

    #[test]
    fn test_pck_builder_lossless_roundtrip() {
        let mut syn_builder = PckBuilder::new();
        syn_builder.add_file("configs\\test.ini", b"[Video]\nLevel = 2\n".to_vec());
        let syn_arc = PckArchive::from_bytes(syn_builder.build().unwrap()).unwrap();
        assert_eq!(syn_arc.len(), 1);
        assert_eq!(
            syn_arc.read_by_path("configs\\test.ini").unwrap(),
            b"[Video]\nLevel = 2\n"
        );

        let Some(elem) = pw_core::find_test_pw142_element(env!("CARGO_MANIFEST_DIR")) else {
            return;
        };
        let orig = PckArchive::open_path(elem.join("configs.pck")).unwrap();
        let mut builder = PckBuilder::new();
        for e in &orig.entries {
            builder.add_file(&e.path, orig.read_entry(e).unwrap());
        }
        let rebuilt_bytes = builder.build().unwrap();
        let rebuilt = PckArchive::from_bytes(rebuilt_bytes).unwrap();
        assert_eq!(rebuilt.len(), orig.len());
        for e in &orig.entries {
            assert_eq!(
                rebuilt.read_by_path(&e.path).unwrap(),
                orig.read_entry(e).unwrap()
            );
        }
    }
}
