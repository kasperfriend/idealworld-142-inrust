//! Hardware Direct3D 9 (`d3d9.dll`) COM Backend + Win32 TrueType (`fonts.pck`) Text Cache.
//!
//! Zero external crates: binds directly to Windows `d3d9.dll` (`Direct3DCreate9(32)`), `IDirect3D9`,
//! `IDirect3DDevice9`, and `IDirect3DTexture9` raw COM vtables + `gdi32.dll` `AddFontMemResourceEx`
//! for crisp TrueType UI text from `fonts.pck` (`FZLBJW.TTF` / `FZXH1JW.TTF`).

#[cfg(target_os = "windows")]
mod imp {
    use std::collections::HashMap;
    use std::ffi::c_void;
    use std::ptr::{null, null_mut};

    use pw_core::{Mat4, Vec3};
    use pw_pck::VirtualFileSystem;

    use crate::a3d_models::A3dLitVertex;
    use crate::a3d_scene_renderer::{
        DynamicCharacterActor, LoadedScene3D, UiQuad2D, UiText2D,
    };
    use crate::image_dds::SurfaceImage;
    use crate::A3DCamera;

    const D3D_SDK_VERSION: u32 = 32;
    const D3DADAPTER_DEFAULT: u32 = 0;
    const D3DDEVTYPE_HAL: u32 = 1;
    const D3DCREATE_SOFTWARE_VERTEXPROCESSING: u32 = 0x0000_0020;
    const D3DCREATE_HARDWARE_VERTEXPROCESSING: u32 = 0x0000_0040;
    const D3DCREATE_FPU_PRESERVE: u32 = 0x0000_0002;

    const D3DSWAPEFFECT_DISCARD: u32 = 1;
    const D3DFMT_A8R8G8B8: u32 = 21;
    const D3DFMT_X8R8G8B8: u32 = 22;
    const D3DFMT_D24S8: u32 = 75;
    const D3DFMT_D16: u32 = 80;
    const D3DFMT_INDEX16: u32 = 101;
    const D3DPOOL_MANAGED: u32 = 1;
    const D3DPRESENT_INTERVAL_ONE: u32 = 1;

    const D3DCLEAR_TARGET: u32 = 0x0000_0001;
    const D3DCLEAR_ZBUFFER: u32 = 0x0000_0002;
    const D3DPT_TRIANGLELIST: u32 = 4;

    const FVF_WORLD_LIT: u32 = 0x002 | 0x040 | 0x100; // D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1
    const FVF_UI_2D: u32 = 0x004 | 0x040 | 0x100; // D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1

    const D3DTS_VIEW: u32 = 2;
    const D3DTS_PROJECTION: u32 = 3;
    const D3DTS_WORLD: u32 = 256;

    const D3DRS_ZENABLE: u32 = 7;
    const D3DRS_ZWRITEENABLE: u32 = 14;
    const D3DRS_ALPHATESTENABLE: u32 = 15;
    const D3DRS_SRCBLEND: u32 = 19;
    const D3DRS_DESTBLEND: u32 = 20;
    const D3DRS_CULLMODE: u32 = 22;
    const D3DRS_ALPHAREF: u32 = 24;
    const D3DRS_ALPHAFUNC: u32 = 25;
    const D3DRS_ALPHABLENDENABLE: u32 = 27;
    const D3DRS_FOGENABLE: u32 = 28;
    const D3DRS_FOGCOLOR: u32 = 34;
    const D3DRS_FOGTABLEMODE: u32 = 35;
    const D3DRS_FOGSTART: u32 = 36;
    const D3DRS_FOGEND: u32 = 37;
    const D3DRS_LIGHTING: u32 = 137;

    const D3DCULL_NONE: u32 = 1;
    const D3DCULL_CCW: u32 = 3;
    const D3DBLEND_ONE: u32 = 2;
    const D3DBLEND_SRCALPHA: u32 = 5;
    const D3DBLEND_INVSRCALPHA: u32 = 6;
    const D3DCMP_GREATEREQUAL: u32 = 7;
    const D3DFOG_LINEAR: u32 = 3;

    const D3DTSS_COLOROP: u32 = 1;
    const D3DTSS_COLORARG1: u32 = 2;
    const D3DTSS_COLORARG2: u32 = 3;
    const D3DTSS_ALPHAOP: u32 = 4;
    const D3DTSS_ALPHAARG1: u32 = 5;
    const D3DTSS_ALPHAARG2: u32 = 6;

    const D3DTOP_MODULATE: u32 = 4;
    const D3DTOP_MODULATE2X: u32 = 5;
    const D3DTA_DIFFUSE: u32 = 0;
    const D3DTA_TEXTURE: u32 = 2;

    const D3DSAMP_ADDRESSU: u32 = 1;
    const D3DSAMP_ADDRESSV: u32 = 2;
    const D3DSAMP_MAGFILTER: u32 = 5;
    const D3DSAMP_MINFILTER: u32 = 6;
    const D3DSAMP_MIPFILTER: u32 = 7;
    const D3DTADDRESS_WRAP: u32 = 1;
    const D3DTADDRESS_CLAMP: u32 = 3;
    const D3DTEXF_LINEAR: u32 = 2;

    #[repr(C)]
    #[derive(Clone, Copy)]
    struct D3DPresentParameters {
        back_buffer_width: u32,
        back_buffer_height: u32,
        back_buffer_format: u32,
        back_buffer_count: u32,
        multi_sample_type: u32,
        multi_sample_quality: u32,
        swap_effect: u32,
        h_device_window: isize,
        windowed: i32,
        enable_auto_depth_stencil: i32,
        auto_depth_stencil_format: u32,
        flags: u32,
        full_screen_refresh_rate_in_hz: u32,
        presentation_interval: u32,
    }

    #[repr(C)]
    #[derive(Default)]
    struct D3DLockedRect {
        pitch: i32,
        p_bits: *mut u8,
    }

    #[repr(C)]
    #[derive(Clone, Copy)]
    struct D3dRhwVertex {
        x: f32,
        y: f32,
        z: f32,
        rhw: f32,
        diffuse: u32,
        u: f32,
        v: f32,
    }

    #[repr(C)]
    struct RawComObj {
        vtbl: *const *const c_void,
    }

    type FnDirect3DCreate9 = unsafe extern "system" fn(u32) -> *mut RawComObj;
    type FnRelease = unsafe extern "system" fn(*mut RawComObj) -> u32;
    type FnCreateDevice = unsafe extern "system" fn(
        *mut RawComObj,
        u32,
        u32,
        isize,
        u32,
        *mut D3DPresentParameters,
        *mut *mut RawComObj,
    ) -> i32;
    type FnReset = unsafe extern "system" fn(*mut RawComObj, *mut D3DPresentParameters) -> i32;
    type FnPresent = unsafe extern "system" fn(*mut RawComObj, *const c_void, *const c_void, isize, *const c_void) -> i32;
    type FnCreateTexture = unsafe extern "system" fn(
        *mut RawComObj,
        u32,
        u32,
        u32,
        u32,
        u32,
        u32,
        *mut *mut RawComObj,
        *mut isize,
    ) -> i32;
    type FnBeginEndScene = unsafe extern "system" fn(*mut RawComObj) -> i32;
    type FnClear = unsafe extern "system" fn(*mut RawComObj, u32, *const c_void, u32, u32, f32, u32) -> i32;
    type FnSetTransform = unsafe extern "system" fn(*mut RawComObj, u32, *const [[f32; 4]; 4]) -> i32;
    type FnSetRenderState = unsafe extern "system" fn(*mut RawComObj, u32, u32) -> i32;
    type FnSetTexture = unsafe extern "system" fn(*mut RawComObj, u32, *mut RawComObj) -> i32;
    type FnSetStageOrSampler = unsafe extern "system" fn(*mut RawComObj, u32, u32, u32) -> i32;
    type FnDrawPrimitiveUP = unsafe extern "system" fn(*mut RawComObj, u32, u32, *const c_void, u32) -> i32;
    type FnDrawIndexedPrimitiveUP = unsafe extern "system" fn(
        *mut RawComObj,
        u32,
        u32,
        u32,
        u32,
        *const c_void,
        u32,
        *const c_void,
        u32,
    ) -> i32;
    type FnSetFvf = unsafe extern "system" fn(*mut RawComObj, u32) -> i32;
    type FnCreateShader = unsafe extern "system" fn(*mut RawComObj, *const u32, *mut *mut RawComObj) -> i32;
    type FnSetShader = unsafe extern "system" fn(*mut RawComObj, *mut RawComObj) -> i32;
    type FnSetShaderConstantF = unsafe extern "system" fn(*mut RawComObj, u32, *const f32, u32) -> i32;
    type FnBlobBufferPtr = unsafe extern "system" fn(*mut RawComObj) -> *const u32;
    type FnD3DCompile = unsafe extern "system" fn(
        *const u8,
        usize,
        *const u8,
        *const c_void,
        *const c_void,
        *const u8,
        *const u8,
        u32,
        u32,
        *mut *mut RawComObj,
        *mut *mut RawComObj,
    ) -> i32;
    type FnLockRect = unsafe extern "system" fn(*mut RawComObj, u32, *mut D3DLockedRect, *const c_void, u32) -> i32;
    type FnUnlockRect = unsafe extern "system" fn(*mut RawComObj, u32) -> i32;

    #[link(name = "kernel32")]
    unsafe extern "system" {
        fn LoadLibraryW(lpLibFileName: *const u16) -> isize;
        fn GetProcAddress(hModule: isize, lpProcName: *const u8) -> *const c_void;
    }

    #[link(name = "gdi32")]
    unsafe extern "system" {
        fn AddFontMemResourceEx(pFileView: *const c_void, cjSize: u32, pvResrved: *const c_void, pNumFonts: *mut u32) -> isize;
        fn CreateCompatibleDC(hdc: isize) -> isize;
        fn DeleteDC(hdc: isize) -> i32;
        fn CreateDIBSection(
            hdc: isize,
            pbmi: *const BitmapInfoHeader40,
            usage: u32,
            ppvBits: *mut *mut u32,
            hSection: isize,
            offset: u32,
        ) -> isize;
        fn SelectObject(hdc: isize, h: isize) -> isize;
        fn DeleteObject(ho: isize) -> i32;
        fn CreateFontW(
            cHeight: i32,
            cWidth: i32,
            cEscapement: i32,
            cOrientation: i32,
            cWeight: i32,
            bItalic: u32,
            bUnderline: u32,
            bStrikeOut: u32,
            iCharSet: u32,
            iOutPrecision: u32,
            iClipPrecision: u32,
            iQuality: u32,
            iPitchAndFamily: u32,
            pszFaceName: *const u16,
        ) -> isize;
        fn SetBkMode(hdc: isize, mode: i32) -> i32;
        fn SetTextColor(hdc: isize, color: u32) -> u32;
        fn TextOutW(hdc: isize, x: i32, y: i32, lpString: *const u16, c: i32) -> i32;
        fn GetTextExtentPoint32W(hdc: isize, lpString: *const u16, c: i32, psizl: *mut WinSize) -> i32;
    }

    #[repr(C)]
    struct BitmapInfoHeader40 {
        bi_size: u32,
        bi_width: i32,
        bi_height: i32,
        bi_planes: u16,
        bi_bit_count: u16,
        bi_compression: u32,
        bi_size_image: u32,
        bi_x_pels: i32,
        bi_y_pels: i32,
        bi_clr_used: u32,
        bi_clr_important: u32,
    }

    #[repr(C)]
    #[derive(Default)]
    struct WinSize {
        cx: i32,
        cy: i32,
    }

    #[inline]
    unsafe fn vtbl_fn<F: Copy>(obj: *mut RawComObj, slot: usize) -> F {
        unsafe {
            let fn_ptr = *((*obj).vtbl.add(slot));
            std::mem::transmute_copy(&fn_ptr)
        }
    }

    struct CachedTextTex {
        tex: *mut RawComObj,
        w: u32,
        h: u32,
    }

    pub struct D3d9Renderer {
        d3d9: *mut RawComObj,
        dev: *mut RawComObj,
        pp: D3DPresentParameters,
        gpu_textures: Vec<*mut RawComObj>,
        text_cache: HashMap<(u32, String), CachedTextTex>,
        mem_dc: isize,
        font_handles: HashMap<u32, isize>,
        terrain_ps: *mut RawComObj,
        skin_ps: *mut RawComObj,
        water_ps: *mut RawComObj,
        gfx_ps: *mut RawComObj,
    }

    impl D3d9Renderer {
        pub fn try_create(hwnd: isize, width: u32, height: u32, font_blobs: &[Vec<u8>]) -> Option<Self> {
            unsafe {
                // Register `fonts.pck` TrueType fonts (`FZLBJW.TTF`, `FZXH1JW.TTF`) with GDI
                for blob in font_blobs {
                    let mut nfonts = 0u32;
                    let _ = AddFontMemResourceEx(
                        blob.as_ptr() as *const c_void,
                        blob.len() as u32,
                        null(),
                        &mut nfonts,
                    );
                }

                let dll_name: Vec<u16> = "d3d9.dll\0".encode_utf16().collect();
                let hmod = LoadLibraryW(dll_name.as_ptr());
                if hmod == 0 {
                    return None;
                }
                let proc_ptr = GetProcAddress(hmod, b"Direct3DCreate9\0".as_ptr());
                if proc_ptr.is_null() {
                    return None;
                }
                let create9: FnDirect3DCreate9 = std::mem::transmute(proc_ptr);
                let d3d9 = create9(D3D_SDK_VERSION);
                if d3d9.is_null() {
                    return None;
                }

                let mut pp = D3DPresentParameters {
                    back_buffer_width: width.max(64),
                    back_buffer_height: height.max(64),
                    back_buffer_format: D3DFMT_X8R8G8B8,
                    back_buffer_count: 1,
                    multi_sample_type: 0,
                    multi_sample_quality: 0,
                    swap_effect: D3DSWAPEFFECT_DISCARD,
                    h_device_window: hwnd,
                    windowed: 1,
                    enable_auto_depth_stencil: 1,
                    auto_depth_stencil_format: D3DFMT_D24S8,
                    flags: 0,
                    full_screen_refresh_rate_in_hz: 0,
                    presentation_interval: D3DPRESENT_INTERVAL_ONE,
                };

                let create_dev: FnCreateDevice = vtbl_fn(d3d9, 16);
                let mut dev: *mut RawComObj = null_mut();
                let mut hr = create_dev(
                    d3d9,
                    D3DADAPTER_DEFAULT,
                    D3DDEVTYPE_HAL,
                    hwnd,
                    D3DCREATE_HARDWARE_VERTEXPROCESSING | D3DCREATE_FPU_PRESERVE,
                    &mut pp,
                    &mut dev,
                );
                if hr < 0 || dev.is_null() {
                    pp.auto_depth_stencil_format = D3DFMT_D16;
                    hr = create_dev(
                        d3d9,
                        D3DADAPTER_DEFAULT,
                        D3DDEVTYPE_HAL,
                        hwnd,
                        D3DCREATE_SOFTWARE_VERTEXPROCESSING | D3DCREATE_FPU_PRESERVE,
                        &mut pp,
                        &mut dev,
                    );
                }
                if hr < 0 || dev.is_null() {
                    let rel: FnRelease = vtbl_fn(d3d9, 2);
                    rel(d3d9);
                    return None;
                }

                let mem_dc = CreateCompatibleDC(0);
                let (terrain_ps, skin_ps, water_ps, gfx_ps) = Self::compile_angelica_ps_suite(dev);
                Some(Self {
                    d3d9,
                    dev,
                    pp,
                    gpu_textures: Vec::new(),
                    text_cache: HashMap::new(),
                    mem_dc,
                    font_handles: HashMap::new(),
                    terrain_ps,
                    skin_ps,
                    water_ps,
                    gfx_ps,
                })
            }
        }

        /// Dynamically loads `d3dcompiler_47.dll` / `d3dcompiler_43.dll` (`D3DCompile`) to compile
        /// the 4 hardware `ps_2_0` Angelica 2.2 pixel shaders:
        /// 1. `t2_lm_f1lay_caustic.hlsl` (Terrain `MODULATE2X` lightmap + animated underwater caustics),
        /// 2. `skin_facerender.hlsl` (`facerender/*.txt` skin/armor specular & hemisphere rim),
        /// 3. `water_expensive.hlsl` (Schlick Fresnel + dual-wave ripple specular),
        /// 4. `gfx_particle.hlsl` (`A3DGFXEx` radial glow additive particles).
        unsafe fn compile_angelica_ps_suite(
            dev: *mut RawComObj,
        ) -> (*mut RawComObj, *mut RawComObj, *mut RawComObj, *mut RawComObj) {
            const TERRAIN_HLSL: &[u8] = b"sampler2D s0 : register(s0);\n\
                float4 cCaustic : register(c0);\n\
                struct PS_IN { float4 diff : COLOR0; float2 uv : TEXCOORD0; };\n\
                float4 main(PS_IN i) : COLOR0 {\n\
                    float4 tex = tex2D(s0, i.uv);\n\
                    float w1 = sin(i.uv.x * 42.0 + cCaustic.x * 2.3) * cos(i.uv.y * 39.0 - cCaustic.x * 1.9);\n\
                    float caustic = saturate(w1) * cCaustic.y;\n\
                    float3 col = saturate(tex.rgb * i.diff.rgb + caustic * float3(0.32, 0.52, 0.65));\n\
                    return float4(col, 1.0);\n\
                }\0";
            const SKIN_HLSL: &[u8] = b"sampler2D s0 : register(s0);\n\
                float4 cRim : register(c0);\n\
                struct PS_IN { float4 diff : COLOR0; float2 uv : TEXCOORD0; };\n\
                float4 main(PS_IN i) : COLOR0 {\n\
                    float4 tex = tex2D(s0, i.uv);\n\
                    float lum = dot(i.diff.rgb, float3(0.299, 0.587, 0.114));\n\
                    float spec = pow(saturate(lum), 4.0) * cRim.x;\n\
                    float3 col = saturate(tex.rgb * i.diff.rgb * 1.06 + spec);\n\
                    return float4(col, tex.a * i.diff.a);\n\
                }\0";
            const WATER_HLSL: &[u8] = b"sampler2D s0 : register(s0);\n\
                float4 cTimeSky : register(c0);\n\
                struct PS_IN { float4 diff : COLOR0; float2 uv : TEXCOORD0; };\n\
                float4 main(PS_IN i) : COLOR0 {\n\
                    float2 uv2 = i.uv * 1.37 + float2(-cTimeSky.x * 0.6, cTimeSky.x * 0.45);\n\
                    float4 t0 = tex2D(s0, i.uv);\n\
                    float4 t1 = tex2D(s0, uv2);\n\
                    float3 base = lerp(t0.rgb, t1.rgb, 0.42) * i.diff.rgb;\n\
                    float ripple = saturate((t0.b + t1.g) * 0.5);\n\
                    float spec = pow(ripple, 6.0) * 0.55;\n\
                    float3 col = saturate(lerp(base, cTimeSky.yzw, 0.26) + spec);\n\
                    return float4(col, saturate(i.diff.a * 0.82 + 0.14));\n\
                }\0";
            const GFX_HLSL: &[u8] = b"sampler2D s0 : register(s0);\n\
                struct PS_IN { float4 diff : COLOR0; float2 uv : TEXCOORD0; };\n\
                float4 main(PS_IN i) : COLOR0 {\n\
                    float4 t = tex2D(s0, i.uv);\n\
                    float2 d = (i.uv - 0.5) * 2.0;\n\
                    float radial = saturate(1.0 - dot(d, d));\n\
                    float glow = radial * radial;\n\
                    return float4(t.rgb * i.diff.rgb * (0.65 + 0.75 * glow), t.a * i.diff.a * radial);\n\
                }\0";

            unsafe {
                let mut d3dc_fn: Option<FnD3DCompile> = None;
                for dll in ["d3dcompiler_47.dll\0", "d3dcompiler_43.dll\0"] {
                    let wide: Vec<u16> = dll.encode_utf16().collect();
                    let hm = LoadLibraryW(wide.as_ptr());
                    if hm != 0 {
                        let p = GetProcAddress(hm, b"D3DCompile\0".as_ptr());
                        if !p.is_null() {
                            d3dc_fn = Some(std::mem::transmute(p));
                            break;
                        }
                    }
                }
                let Some(d3d_compile) = d3dc_fn else {
                    return (null_mut(), null_mut(), null_mut(), null_mut());
                };
                let compile_one = |src: &[u8], name: &[u8]| -> *mut RawComObj {
                    let mut code_blob: *mut RawComObj = null_mut();
                    let mut err_blob: *mut RawComObj = null_mut();
                    let hr = d3d_compile(
                        src.as_ptr(),
                        src.len() - 1,
                        name.as_ptr(),
                        null(),
                        null(),
                        b"main\0".as_ptr(),
                        b"ps_2_0\0".as_ptr(),
                        0,
                        0,
                        &mut code_blob,
                        &mut err_blob,
                    );
                    if !err_blob.is_null() {
                        let rel: FnRelease = vtbl_fn(err_blob, 2);
                        rel(err_blob);
                    }
                    if hr < 0 || code_blob.is_null() {
                        return null_mut();
                    }
                    let get_ptr: FnBlobBufferPtr = vtbl_fn(code_blob, 3);
                    let dword_ptr = get_ptr(code_blob);
                    let mut ps_obj: *mut RawComObj = null_mut();
                    if !dword_ptr.is_null() {
                        let create_ps: FnCreateShader = vtbl_fn(dev, 106);
                        let _ = create_ps(dev, dword_ptr, &mut ps_obj);
                    }
                    let rel: FnRelease = vtbl_fn(code_blob, 2);
                    rel(code_blob);
                    ps_obj
                };
                (
                    compile_one(TERRAIN_HLSL, b"t2_lm_f1lay_caustic.hlsl\0"),
                    compile_one(SKIN_HLSL, b"skin_facerender.hlsl\0"),
                    compile_one(WATER_HLSL, b"water_expensive.hlsl\0"),
                    compile_one(GFX_HLSL, b"gfx_particle.hlsl\0"),
                )
            }
        }

        pub fn invalidate_scene_textures(&mut self) {
            unsafe {
                for &t in &self.gpu_textures {
                    if !t.is_null() {
                        let rel: FnRelease = vtbl_fn(t, 2);
                        rel(t);
                    }
                }
                self.gpu_textures.clear();
            }
        }

        pub fn resize(&mut self, width: u32, height: u32) {
            let nw = width.max(64);
            let nh = height.max(64);
            if nw == self.pp.back_buffer_width && nh == self.pp.back_buffer_height {
                return;
            }
            self.pp.back_buffer_width = nw;
            self.pp.back_buffer_height = nh;
            unsafe {
                let reset_fn: FnReset = vtbl_fn(self.dev, 16);
                let _ = reset_fn(self.dev, &mut self.pp);
            }
        }

        unsafe fn ensure_gpu_textures(&mut self, surfaces: &[SurfaceImage]) {
            while self.gpu_textures.len() < surfaces.len() {
                let idx = self.gpu_textures.len();
                let tex_ptr = unsafe { self.upload_surface(&surfaces[idx]) };
                self.gpu_textures.push(tex_ptr);
            }
        }

        unsafe fn upload_surface(&self, img: &SurfaceImage) -> *mut RawComObj {
            let w = img.width.max(1);
            let h = img.height.max(1);
            let mut tex: *mut RawComObj = null_mut();
            let create_tex: FnCreateTexture = unsafe { vtbl_fn(self.dev, 23) };
            // Upload full mipmap pyramid (`Level 0 ..= img.mips.len()`) into `D3DPOOL_MANAGED`!
            let total_levels = img.mip_count() as u32;
            let hr = unsafe {
                create_tex(
                    self.dev,
                    w,
                    h,
                    total_levels,
                    0,
                    D3DFMT_A8R8G8B8,
                    D3DPOOL_MANAGED,
                    &mut tex,
                    null_mut(),
                )
            };
            let (hr, uploaded_levels) = if hr < 0 || tex.is_null() {
                (
                    unsafe {
                        create_tex(
                            self.dev,
                            w,
                            h,
                            1,
                            0,
                            D3DFMT_A8R8G8B8,
                            D3DPOOL_MANAGED,
                            &mut tex,
                            null_mut(),
                        )
                    },
                    1u32,
                )
            } else {
                (hr, total_levels)
            };
            if hr < 0 || tex.is_null() {
                return null_mut();
            }

            let lock_fn: FnLockRect = unsafe { vtbl_fn(tex, 19) };
            let unlock_fn: FnUnlockRect = unsafe { vtbl_fn(tex, 20) };
            for lvl in 0..uploaded_levels {
                let (lw, lh, lbuf): (usize, usize, &[u32]) = if lvl == 0 {
                    (w as usize, h as usize, &img.pixels)
                } else {
                    let (mw, mh, ref mpx) = img.mips[(lvl - 1) as usize];
                    (mw as usize, mh as usize, mpx)
                };
                let mut lr = D3DLockedRect::default();
                if unsafe { lock_fn(tex, lvl, &mut lr, null(), 0) } >= 0 && !lr.p_bits.is_null() {
                    let row_bytes = lw * 4;
                    for y in 0..lh {
                        unsafe {
                            let dst = lr.p_bits.add(y * (lr.pitch as usize));
                            let src = lbuf.as_ptr().add(y * lw) as *const u8;
                            std::ptr::copy_nonoverlapping(src, dst, row_bytes);
                        }
                    }
                    unsafe { unlock_fn(tex, lvl) };
                }
            }
            tex
        }

        unsafe fn get_or_build_text_tex(&mut self, size_px: u32, text: &str) -> Option<(usize, u32, u32)> {
            if text.is_empty() || self.mem_dc == 0 {
                return None;
            }
            let sz = size_px.clamp(10, 36);
            let key = (sz, text.to_string());
            if !self.text_cache.contains_key(&key) {
                if self.text_cache.len() > 512 {
                    for (_, ct) in self.text_cache.drain() {
                        if !ct.tex.is_null() {
                            let rel: FnRelease = unsafe { vtbl_fn(ct.tex, 2) };
                            unsafe { rel(ct.tex) };
                        }
                    }
                }
                let hfont = *self.font_handles.entry(sz).or_insert_with(|| unsafe {
                    // Try PW's `方正细黑一简体` (registered via `AddFontMemResourceEx`), fallback ClearType Segoe UI / Tahoma
                    let face: Vec<u16> = "Tahoma\0".encode_utf16().collect();
                    CreateFontW(
                        -(sz as i32),
                        0,
                        0,
                        0,
                        600,
                        0,
                        0,
                        0,
                        1, // DEFAULT_CHARSET
                        0,
                        0,
                        4, // ANTIALIASED_QUALITY (clean grayscale coverage on black DIB!)
                        0,
                        face.as_ptr(),
                    )
                });
                unsafe { SelectObject(self.mem_dc, hfont) };
                let utf16: Vec<u16> = text.encode_utf16().collect();
                let mut ext = WinSize::default();
                unsafe {
                    GetTextExtentPoint32W(self.mem_dc, utf16.as_ptr(), utf16.len() as i32, &mut ext);
                }
                let tw = (ext.cx.max(4) as u32 + 4).min(1024);
                let th = (ext.cy.max(4) as u32 + 4).min(128);
                let bmi = BitmapInfoHeader40 {
                    bi_size: 40,
                    bi_width: tw as i32,
                    bi_height: -(th as i32),
                    bi_planes: 1,
                    bi_bit_count: 32,
                    bi_compression: 0,
                    bi_size_image: tw * th * 4,
                    bi_x_pels: 0,
                    bi_y_pels: 0,
                    bi_clr_used: 0,
                    bi_clr_important: 0,
                };
                let mut bits: *mut u32 = null_mut();
                let hbmp = unsafe { CreateDIBSection(self.mem_dc, &bmi, 0, &mut bits, 0, 0) };
                if hbmp != 0 && !bits.is_null() {
                    let old_bmp = unsafe { SelectObject(self.mem_dc, hbmp) };
                    unsafe {
                        std::ptr::write_bytes(bits, 0, (tw * th) as usize);
                        SetBkMode(self.mem_dc, 1); // TRANSPARENT
                        SetTextColor(self.mem_dc, 0x00FF_FFFF);
                        TextOutW(self.mem_dc, 1, 1, utf16.as_ptr(), utf16.len() as i32);
                    }
                    let mut pixels = vec![0u32; (tw * th) as usize];
                    for i in 0..pixels.len() {
                        let px = unsafe { *bits.add(i) };
                        let lum = ((px & 0xFF) + ((px >> 8) & 0xFF) + ((px >> 16) & 0xFF)) / 3;
                        pixels[i] = if lum > 4 {
                            (lum.min(255) << 24) | 0x00FF_FFFF
                        } else {
                            0
                        };
                    }
                    unsafe {
                        SelectObject(self.mem_dc, old_bmp);
                        DeleteObject(hbmp);
                    }
                    let tex = unsafe {
                        self.upload_surface(&SurfaceImage::from_pixels(tw, th, pixels))
                    };
                    self.text_cache.insert(key.clone(), CachedTextTex { tex, w: tw, h: th });
                }
            }
            let ct = self.text_cache.get(&key)?;
            if ct.tex.is_null() {
                None
            } else {
                Some((ct.tex as usize, ct.w, ct.h))
            }
        }

        #[allow(clippy::too_many_arguments)]
        pub fn render_frame(
            &mut self,
            scene: &mut LoadedScene3D,
            vfs: &VirtualFileSystem,
            eye: Vec3,
            dir: Vec3,
            up: Vec3,
            cam_proj: &A3DCamera,
            actors: &[DynamicCharacterActor],
            ui_quads: &[UiQuad2D],
            ui_texts: &[UiText2D],
            anim_time: f32,
        ) -> bool {
            scene.sync_environment_for_camera(vfs, eye);
            let mut actor_draws_per_actor = Vec::with_capacity(actors.len());
            for actor in actors {
                actor_draws_per_actor.push(scene.build_actor_draw_calls(vfs, actor, anim_time));
            }

            unsafe {
                self.ensure_gpu_textures(&scene.textures);
                // Re-upload dynamic atlas / circular radar / 3D portrait surfaces!
                for dyn_id in [
                    Some(scene.font_atlas.atlas_tex_id),
                    scene.minimap_circle_tex_id,
                    scene.portrait_circle_tex_id,
                ]
                .into_iter()
                .flatten()
                {
                    if dyn_id < self.gpu_textures.len() && !self.gpu_textures[dyn_id].is_null() {
                        let rel: FnRelease = vtbl_fn(self.gpu_textures[dyn_id], 2);
                        rel(self.gpu_textures[dyn_id]);
                        self.gpu_textures[dyn_id] = self.upload_surface(&scene.textures[dyn_id]);
                    }
                }

                let clear_fn: FnClear = vtbl_fn(self.dev, 43);
                let begin_fn: FnBeginEndScene = vtbl_fn(self.dev, 41);
                let end_fn: FnBeginEndScene = vtbl_fn(self.dev, 42);
                let present_fn: FnPresent = vtbl_fn(self.dev, 17);
                let set_rs: FnSetRenderState = vtbl_fn(self.dev, 57);
                let set_tss: FnSetStageOrSampler = vtbl_fn(self.dev, 67);
                let set_samp: FnSetStageOrSampler = vtbl_fn(self.dev, 69);
                let set_xf: FnSetTransform = vtbl_fn(self.dev, 44);
                let set_tex: FnSetTexture = vtbl_fn(self.dev, 65);
                let set_fvf: FnSetFvf = vtbl_fn(self.dev, 89);
                let draw_idx_up: FnDrawIndexedPrimitiveUP = vtbl_fn(self.dev, 84);
                let draw_up: FnDrawPrimitiveUP = vtbl_fn(self.dev, 83);

                let _ = clear_fn(
                    self.dev,
                    0,
                    null(),
                    D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
                    scene.fog_color,
                    1.0,
                    0,
                );
                if begin_fn(self.dev) < 0 {
                    return false;
                }

                let aspect = (self.pp.back_buffer_width as f32) / (self.pp.back_buffer_height.max(1) as f32);
                let view = Mat4::look_to_lh(eye, dir, up);
                let proj = Mat4::perspective_fov_lh(
                    cam_proj.fov_degrees.to_radians(),
                    aspect,
                    cam_proj.near_clip.max(0.25),
                    cam_proj.far_clip.max(1100.0),
                );
                set_xf(self.dev, D3DTS_VIEW, &view.0);
                set_xf(self.dev, D3DTS_PROJECTION, &proj.0);

                // Fixed-function Angelica3D render states
                set_rs(self.dev, D3DRS_LIGHTING, 0);
                set_rs(self.dev, D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
                set_rs(self.dev, D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
                set_rs(self.dev, D3DRS_ALPHAFUNC, D3DCMP_GREATEREQUAL);
                set_rs(self.dev, D3DRS_ALPHAREF, 96);

                set_samp(self.dev, 0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
                // 8x Anisotropic + Trilinear Mipmap filtering (`D3DTEXF_ANISOTROPIC = 3`, `D3DSAMP_MAXANISOTROPY = 10`)
                set_samp(self.dev, 0, D3DSAMP_MINFILTER, 3);
                set_samp(self.dev, 0, 10, 8);
                set_samp(self.dev, 0, D3DSAMP_MIPFILTER, D3DTEXF_LINEAR);

                set_tss(self.dev, 0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
                set_tss(self.dev, 0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);
                set_tss(self.dev, 0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
                set_tss(self.dev, 0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
                set_tss(self.dev, 0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);

                set_fvf(self.dev, FVF_WORLD_LIT);

                // 1. Sky Dome (`A3DSkySphere`: Z-disable, no fog, clamp UVs)
                let sky_world = Mat4([
                    [1.0, 0.0, 0.0, 0.0],
                    [0.0, 1.0, 0.0, 0.0],
                    [0.0, 0.0, 1.0, 0.0],
                    [eye.x, eye.y - 35.0, eye.z, 1.0],
                ]);
                set_xf(self.dev, D3DTS_WORLD, &sky_world.0);
                set_rs(self.dev, D3DRS_ZENABLE, 0);
                set_rs(self.dev, D3DRS_ZWRITEENABLE, 0);
                set_rs(self.dev, D3DRS_FOGENABLE, 0);
                set_rs(self.dev, D3DRS_CULLMODE, D3DCULL_NONE);
                set_rs(self.dev, D3DRS_ALPHATESTENABLE, 0);
                set_tss(self.dev, 0, D3DTSS_COLOROP, D3DTOP_MODULATE);
                set_samp(self.dev, 0, D3DSAMP_ADDRESSU, D3DTADDRESS_CLAMP);
                set_samp(self.dev, 0, D3DSAMP_ADDRESSV, D3DTADDRESS_CLAMP);

                set_rs(self.dev, D3DRS_ALPHABLENDENABLE, 0);
                set_tex(self.dev, 0, self.gpu_textures[scene.sky_cap_tex]);
                draw_idx_up(
                    self.dev,
                    D3DPT_TRIANGLELIST,
                    0,
                    scene.sky_dome.cap_verts.len() as u32,
                    (scene.sky_dome.cap_indices.len() / 3) as u32,
                    scene.sky_dome.cap_indices.as_ptr() as *const c_void,
                    D3DFMT_INDEX16,
                    scene.sky_dome.cap_verts.as_ptr() as *const c_void,
                    std::mem::size_of::<A3dLitVertex>() as u32,
                );

                set_rs(self.dev, D3DRS_ALPHABLENDENABLE, 1);
                set_tex(self.dev, 0, self.gpu_textures[scene.sky_front_tex]);
                draw_idx_up(
                    self.dev,
                    D3DPT_TRIANGLELIST,
                    0,
                    scene.sky_dome.surround_front_verts.len() as u32,
                    (scene.sky_dome.surround_front_indices.len() / 3) as u32,
                    scene.sky_dome.surround_front_indices.as_ptr() as *const c_void,
                    D3DFMT_INDEX16,
                    scene.sky_dome.surround_front_verts.as_ptr() as *const c_void,
                    std::mem::size_of::<A3dLitVertex>() as u32,
                );
                set_tex(self.dev, 0, self.gpu_textures[scene.sky_back_tex]);
                draw_idx_up(
                    self.dev,
                    D3DPT_TRIANGLELIST,
                    0,
                    scene.sky_dome.surround_back_verts.len() as u32,
                    (scene.sky_dome.surround_back_indices.len() / 3) as u32,
                    scene.sky_dome.surround_back_indices.as_ptr() as *const c_void,
                    D3DFMT_INDEX16,
                    scene.sky_dome.surround_back_verts.as_ptr() as *const c_void,
                    std::mem::size_of::<A3dLitVertex>() as u32,
                );

                // 1b. Dynamic Sky Clouds (`CELCloudCreator` / `CloudSprite` horizon & mid-sky cumulus ring)
                if scene.clouds_enabled {
                    let (cverts, cindices) = scene.build_cloud_ring_mesh(eye, anim_time);
                    if !cverts.is_empty() {
                        set_xf(self.dev, D3DTS_WORLD, &Mat4::IDENTITY.0);
                        set_tex(self.dev, 0, self.gpu_textures[scene.cloud_sprite_tex_id]);
                        draw_idx_up(
                            self.dev,
                            D3DPT_TRIANGLELIST,
                            0,
                            cverts.len() as u32,
                            (cindices.len() / 3) as u32,
                            cindices.as_ptr() as *const c_void,
                            D3DFMT_INDEX16,
                            cverts.as_ptr() as *const c_void,
                            std::mem::size_of::<A3dLitVertex>() as u32,
                        );
                    }
                }

                // Enable Z-buffer & linear distance fog (`CECScnBoxArea`)
                set_rs(self.dev, D3DRS_ZENABLE, 1);
                set_rs(self.dev, D3DRS_ZWRITEENABLE, 1);
                set_rs(self.dev, D3DRS_ALPHABLENDENABLE, 0);
                set_rs(self.dev, D3DRS_FOGENABLE, 1);
                set_rs(self.dev, D3DRS_FOGCOLOR, scene.fog_color);
                set_rs(self.dev, D3DRS_FOGTABLEMODE, D3DFOG_LINEAR);
                set_rs(self.dev, D3DRS_FOGSTART, scene.fog_start.to_bits());
                set_rs(self.dev, D3DRS_FOGEND, scene.fog_end.to_bits());

                // 2. Terrain (`A3DTerrain2` 16x16 blocks + `t2_lm_f1lay_caustic.hlsl` `ps_2_0` shader!)
                let set_ps: FnSetShader = vtbl_fn(self.dev, 107);
                let set_ps_const: FnSetShaderConstantF = vtbl_fn(self.dev, 109);
                set_xf(self.dev, D3DTS_WORLD, &Mat4::IDENTITY.0);
                set_tss(self.dev, 0, D3DTSS_COLOROP, D3DTOP_MODULATE);
                set_samp(self.dev, 0, D3DSAMP_ADDRESSU, D3DTADDRESS_CLAMP);
                set_samp(self.dev, 0, D3DSAMP_ADDRESSV, D3DTADDRESS_CLAMP);
                let fwd = dir.normalized();
                for blk in &scene.terrain_blocks {
                    let delta = blk.world_aabb.center().sub(eye);
                    if delta.dot(fwd) < -(blk.world_aabb.radius() + 24.0) {
                        continue;
                    }
                    if !self.terrain_ps.is_null() {
                        let caustic_strength = if blk.world_aabb.mins.y < 205.0 && !scene.water_batches.is_empty() {
                            0.18f32
                        } else {
                            0.0f32
                        };
                        let c0 = [anim_time, caustic_strength, 0.0, 0.0];
                        let _ = set_ps(self.dev, self.terrain_ps);
                        let _ = set_ps_const(self.dev, 0, c0.as_ptr(), 1);
                    }
                    set_tex(self.dev, 0, self.gpu_textures[blk.tex_id]);
                    draw_idx_up(
                        self.dev,
                        D3DPT_TRIANGLELIST,
                        0,
                        blk.verts.len() as u32,
                        (blk.indices.len() / 3) as u32,
                        blk.indices.as_ptr() as *const c_void,
                        D3DFMT_INDEX16,
                        blk.verts.as_ptr() as *const c_void,
                        std::mem::size_of::<A3dLitVertex>() as u32,
                    );
                }
                if !self.terrain_ps.is_null() {
                    let _ = set_ps(self.dev, null_mut());
                }

                // 3. Ornaments (`CECOrnament` `.bmd` `A3DLitModel` with `D3DTOP_MODULATE2X` vertex day_colors!)
                set_tss(self.dev, 0, D3DTSS_COLOROP, D3DTOP_MODULATE2X);
                set_samp(self.dev, 0, D3DSAMP_ADDRESSU, D3DTADDRESS_WRAP);
                set_samp(self.dev, 0, D3DSAMP_ADDRESSV, D3DTADDRESS_WRAP);
                for inst in &scene.ornaments {
                    let delta = inst.world_aabb.center().sub(eye);
                    let r = inst.world_aabb.radius().max(4.0);
                    if delta.length_sq() > (950.0 + r) * (950.0 + r) || delta.dot(fwd) < -r * 1.15 {
                        continue;
                    }
                    set_xf(self.dev, D3DTS_WORLD, &inst.world_mat.0);
                    for batch in &scene.bmd_models[inst.model_idx] {
                        set_rs(
                            self.dev,
                            D3DRS_CULLMODE,
                            if batch.two_sided { D3DCULL_NONE } else { D3DCULL_CCW },
                        );
                        set_rs(self.dev, D3DRS_ALPHATESTENABLE, u32::from(batch.alpha_test));
                        set_tex(self.dev, 0, self.gpu_textures[batch.tex_id]);
                        draw_idx_up(
                            self.dev,
                            D3DPT_TRIANGLELIST,
                            0,
                            batch.verts.len() as u32,
                            (batch.indices.len() / 3) as u32,
                            batch.indices.as_ptr() as *const c_void,
                            D3DFMT_INDEX16,
                            batch.verts.as_ptr() as *const c_void,
                            std::mem::size_of::<A3dLitVertex>() as u32,
                        );
                    }
                }

                // 4. Dynamic 3D Characters, Real `.ecm` NPCs/Monsters, & `HH_*` Attached Weapons (`skin_facerender.hlsl` `ps_2_0`)
                set_tss(self.dev, 0, D3DTSS_COLOROP, D3DTOP_MODULATE);
                set_rs(self.dev, D3DRS_CULLMODE, D3DCULL_NONE);
                if !self.skin_ps.is_null() {
                    let c0 = [0.14f32, 0.0, 0.0, 0.0];
                    let _ = set_ps(self.dev, self.skin_ps);
                    let _ = set_ps_const(self.dev, 0, c0.as_ptr(), 1);
                }
                for draws in &actor_draws_per_actor {
                    for (world_m, batch) in draws {
                        set_xf(self.dev, D3DTS_WORLD, &world_m.0);
                        set_rs(self.dev, D3DRS_ALPHATESTENABLE, u32::from(batch.alpha_test));
                        set_rs(self.dev, D3DRS_ALPHABLENDENABLE, u32::from(batch.alpha_blend));
                        set_rs(self.dev, D3DRS_ZWRITEENABLE, u32::from(!batch.alpha_blend));
                        set_tex(self.dev, 0, self.gpu_textures[batch.tex_id]);
                        draw_idx_up(
                            self.dev,
                            D3DPT_TRIANGLELIST,
                            0,
                            batch.verts.len() as u32,
                            (batch.indices.len() / 3) as u32,
                            batch.indices.as_ptr() as *const c_void,
                            D3DFMT_INDEX16,
                            batch.verts.as_ptr() as *const c_void,
                            std::mem::size_of::<A3dLitVertex>() as u32,
                        );
                    }
                }
                if !self.skin_ps.is_null() {
                    let _ = set_ps(self.dev, null_mut());
                }
                set_rs(self.dev, D3DRS_ALPHABLENDENABLE, 0);
                set_rs(self.dev, D3DRS_ZWRITEENABLE, 1);

                // 5. Water (`A3DWaterArea` translucent animated ocean/lake planes + optional `ps_2_0` Fresnel shader)
                set_xf(self.dev, D3DTS_WORLD, &Mat4::IDENTITY.0);
                set_rs(self.dev, D3DRS_ZWRITEENABLE, 0);
                set_rs(self.dev, D3DRS_ALPHATESTENABLE, 0);
                set_rs(self.dev, D3DRS_ALPHABLENDENABLE, 1);
                let uv_scroll = anim_time * 0.035;
                if !self.water_ps.is_null() {
                    let c0 = [
                        uv_scroll,
                        ((scene.fog_color >> 16) & 0xFF) as f32 * (1.0 / 255.0),
                        ((scene.fog_color >> 8) & 0xFF) as f32 * (1.0 / 255.0),
                        (scene.fog_color & 0xFF) as f32 * (1.0 / 255.0),
                    ];
                    let _ = set_ps(self.dev, self.water_ps);
                    let _ = set_ps_const(self.dev, 0, c0.as_ptr(), 1);
                }
                for wb in &scene.water_batches {
                    let scrolled: Vec<A3dLitVertex> = wb
                        .verts
                        .iter()
                        .map(|v| A3dLitVertex {
                            u: v.u + uv_scroll,
                            v: v.v + uv_scroll * 0.7,
                            ..*v
                        })
                        .collect();
                    set_tex(self.dev, 0, self.gpu_textures[wb.tex_id]);
                    draw_idx_up(
                        self.dev,
                        D3DPT_TRIANGLELIST,
                        0,
                        scrolled.len() as u32,
                        (wb.indices.len() / 3) as u32,
                        wb.indices.as_ptr() as *const c_void,
                        D3DFMT_INDEX16,
                        scrolled.as_ptr() as *const c_void,
                        std::mem::size_of::<A3dLitVertex>() as u32,
                    );
                }
                if !self.water_ps.is_null() {
                    let _ = set_ps(self.dev, null_mut());
                }

                // 5b. `A3DGFXEx` (`.gfx` / `MOXT`) Additive Particle, Weapon Glow, & `VisibleState` Aura Billboards
                if scene.gfx_manager.particle_count() > 0 {
                    let cam_right = Vec3::new(-fwd.z, 0.0, fwd.x).normalized();
                    let cam_up = cam_right.cross(fwd).normalized();
                    let (pverts, pindices) = scene.gfx_manager.build_billboard_mesh(cam_right, cam_up);
                    if !pverts.is_empty() {
                        set_rs(self.dev, D3DRS_FOGENABLE, 0);
                        set_rs(self.dev, D3DRS_DESTBLEND, D3DBLEND_ONE);
                        if !self.gfx_ps.is_null() {
                            let _ = set_ps(self.dev, self.gfx_ps);
                        }
                        set_tex(self.dev, 0, self.gpu_textures[scene.particle_glow_tex_id]);
                        draw_idx_up(
                            self.dev,
                            D3DPT_TRIANGLELIST,
                            0,
                            pverts.len() as u32,
                            (pindices.len() / 3) as u32,
                            pindices.as_ptr() as *const c_void,
                            D3DFMT_INDEX16,
                            pverts.as_ptr() as *const c_void,
                            std::mem::size_of::<A3dLitVertex>() as u32,
                        );
                        if !self.gfx_ps.is_null() {
                            let _ = set_ps(self.dev, null_mut());
                        }
                        set_rs(self.dev, D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
                    }
                }

                // 6. `AUIManager` 2D Screen-Space Quads (`D3DFVF_XYZRHW` with half-texel `-0.5f` D3D9 offset!)
                set_rs(self.dev, D3DRS_FOGENABLE, 0);
                set_rs(self.dev, D3DRS_ZENABLE, 0);
                set_rs(self.dev, D3DRS_CULLMODE, D3DCULL_NONE);
                set_rs(self.dev, D3DRS_ALPHABLENDENABLE, 1);
                set_samp(self.dev, 0, D3DSAMP_ADDRESSU, D3DTADDRESS_CLAMP);
                set_samp(self.dev, 0, D3DSAMP_ADDRESSV, D3DTADDRESS_CLAMP);
                set_fvf(self.dev, FVF_UI_2D);

                for raw_q in ui_quads {
                    let Some(q) = raw_q.clipped() else {
                        continue;
                    };
                    let tptr = q
                        .tex_id
                        .and_then(|id| self.gpu_textures.get(id).copied())
                        .unwrap_or(self.gpu_textures[0]);
                    set_tex(self.dev, 0, tptr);
                    let x0 = q.x0 - 0.5;
                    let y0 = q.y0 - 0.5;
                    let x1 = q.x1 - 0.5;
                    let y1 = q.y1 - 0.5;
                    let verts = [
                        D3dRhwVertex { x: x0, y: y0, z: 0.0, rhw: 1.0, diffuse: q.color, u: q.u0, v: q.v0 },
                        D3dRhwVertex { x: x1, y: y0, z: 0.0, rhw: 1.0, diffuse: q.color, u: q.u1, v: q.v0 },
                        D3dRhwVertex { x: x0, y: y1, z: 0.0, rhw: 1.0, diffuse: q.color, u: q.u0, v: q.v1 },
                        D3dRhwVertex { x: x1, y: y0, z: 0.0, rhw: 1.0, diffuse: q.color, u: q.u1, v: q.v0 },
                        D3dRhwVertex { x: x1, y: y1, z: 0.0, rhw: 1.0, diffuse: q.color, u: q.u1, v: q.v1 },
                        D3dRhwVertex { x: x0, y: y1, z: 0.0, rhw: 1.0, diffuse: q.color, u: q.u0, v: q.v1 },
                    ];
                    draw_up(
                        self.dev,
                        D3DPT_TRIANGLELIST,
                        2,
                        verts.as_ptr() as *const c_void,
                        std::mem::size_of::<D3dRhwVertex>() as u32,
                    );
                }

                // 7. `AUIManager` TrueType Text Quads (clipped to `t.clip_rect`!)
                for t in ui_texts {
                    if let Some((raw_tex_usize, tw, th)) = self.get_or_build_text_tex(t.size_px, &t.text) {
                        let tptr = raw_tex_usize as *mut RawComObj;
                        set_tex(self.dev, 0, tptr);
                        for (ox, oy, col) in [
                            (1i32, 1i32, if t.shadow { 0xCC08_0808 } else { 0 }),
                            (0i32, 0i32, t.color),
                        ] {
                            if col == 0 {
                                continue;
                            }
                            let tq = UiQuad2D {
                                x0: (t.x + ox) as f32,
                                y0: (t.y + oy) as f32,
                                x1: (t.x + ox + tw as i32) as f32,
                                y1: (t.y + oy + th as i32) as f32,
                                u0: 0.0,
                                v0: 0.0,
                                u1: 1.0,
                                v1: 1.0,
                                color: col,
                                tex_id: None,
                                clip_rect: t.clip_rect,
                            };
                            if let Some(cq) = tq.clipped() {
                                let x0 = cq.x0 - 0.5;
                                let y0 = cq.y0 - 0.5;
                                let x1 = cq.x1 - 0.5;
                                let y1 = cq.y1 - 0.5;
                                let verts = [
                                    D3dRhwVertex { x: x0, y: y0, z: 0.0, rhw: 1.0, diffuse: cq.color, u: cq.u0, v: cq.v0 },
                                    D3dRhwVertex { x: x1, y: y0, z: 0.0, rhw: 1.0, diffuse: cq.color, u: cq.u1, v: cq.v0 },
                                    D3dRhwVertex { x: x0, y: y1, z: 0.0, rhw: 1.0, diffuse: cq.color, u: cq.u0, v: cq.v1 },
                                    D3dRhwVertex { x: x1, y: y0, z: 0.0, rhw: 1.0, diffuse: cq.color, u: cq.u1, v: cq.v0 },
                                    D3dRhwVertex { x: x1, y: y1, z: 0.0, rhw: 1.0, diffuse: cq.color, u: cq.u1, v: cq.v1 },
                                    D3dRhwVertex { x: x0, y: y1, z: 0.0, rhw: 1.0, diffuse: cq.color, u: cq.u0, v: cq.v1 },
                                ];
                                draw_up(
                                    self.dev,
                                    D3DPT_TRIANGLELIST,
                                    2,
                                    verts.as_ptr() as *const c_void,
                                    std::mem::size_of::<D3dRhwVertex>() as u32,
                                );
                            }
                        }
                    }
                }

                let _ = end_fn(self.dev);
                present_fn(self.dev, null(), null(), 0, null()) >= 0
            }
        }

        #[allow(dead_code)]
        unsafe fn emit_rhw_rect(
            dev: *mut RawComObj,
            draw_up: FnDrawPrimitiveUP,
            x: f32,
            y: f32,
            w: f32,
            h: f32,
            color: u32,
        ) {
            let x0 = x - 0.5;
            let y0 = y - 0.5;
            let x1 = x + w - 0.5;
            let y1 = y + h - 0.5;
            let verts = [
                D3dRhwVertex { x: x0, y: y0, z: 0.0, rhw: 1.0, diffuse: color, u: 0.0, v: 0.0 },
                D3dRhwVertex { x: x1, y: y0, z: 0.0, rhw: 1.0, diffuse: color, u: 1.0, v: 0.0 },
                D3dRhwVertex { x: x0, y: y1, z: 0.0, rhw: 1.0, diffuse: color, u: 0.0, v: 1.0 },
                D3dRhwVertex { x: x1, y: y0, z: 0.0, rhw: 1.0, diffuse: color, u: 1.0, v: 0.0 },
                D3dRhwVertex { x: x1, y: y1, z: 0.0, rhw: 1.0, diffuse: color, u: 1.0, v: 1.0 },
                D3dRhwVertex { x: x0, y: y1, z: 0.0, rhw: 1.0, diffuse: color, u: 0.0, v: 1.0 },
            ];
            unsafe {
                draw_up(
                    dev,
                    D3DPT_TRIANGLELIST,
                    2,
                    verts.as_ptr() as *const c_void,
                    std::mem::size_of::<D3dRhwVertex>() as u32,
                );
            }
        }
    }

    impl Drop for D3d9Renderer {
        fn drop(&mut self) {
            self.invalidate_scene_textures();
            unsafe {
                for (_, ct) in self.text_cache.drain() {
                    if !ct.tex.is_null() {
                        let rel: FnRelease = vtbl_fn(ct.tex, 2);
                        rel(ct.tex);
                    }
                }
                for (_, hf) in self.font_handles.drain() {
                    if hf != 0 {
                        DeleteObject(hf);
                    }
                }
                if self.mem_dc != 0 {
                    DeleteDC(self.mem_dc);
                }
                for ps in [self.terrain_ps, self.skin_ps, self.water_ps, self.gfx_ps] {
                    if !ps.is_null() {
                        let rel: FnRelease = vtbl_fn(ps, 2);
                        rel(ps);
                    }
                }
                if !self.dev.is_null() {
                    let rel: FnRelease = vtbl_fn(self.dev, 2);
                    rel(self.dev);
                }
                if !self.d3d9.is_null() {
                    let rel: FnRelease = vtbl_fn(self.d3d9, 2);
                    rel(self.d3d9);
                }
            }
        }
    }
}

#[cfg(target_os = "windows")]
pub use imp::D3d9Renderer;
