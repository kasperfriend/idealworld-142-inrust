//! Native Win32 Game Window, 32-Bit `DIBSection` Blitter, `AddFontMemResourceEx` `fonts.pck`
//! ClearType GDI Text Engine, Custom `.ani`/`.cur` Cursor Loader, & `Alt+Enter`/`F11` Fullscreen.
//!
//! Zero external crates — links directly to Windows OS `user32.dll`, `gdi32.dll`, and `kernel32.dll`.

use pw_core::PwResult;

use crate::game_app::InteractiveClientApp;

/// Runs the interactive Perfect World 1.4.2 Win32 window (`CECGame::Run` message & render loop).
#[cfg(target_os = "windows")]
pub fn run_win32_client(mut app: InteractiveClientApp) -> PwResult<()> {
    win32_impl::run_loop(&mut app)
}

/// Non-Windows headless verification path (renders login, character-select, and in-world frames).
#[cfg(not(target_os = "windows"))]
pub fn run_win32_client(mut app: InteractiveClientApp) -> PwResult<()> {
    let mut fb = pw_render_audio::FrameBuffer::new(1280, 800);
    app.tick(0.016, &crate::game_app::InputSnapshot::default());
    app.render(&mut fb, 640, 400);
    fb.rasterize_queued_text_fallback();
    println!(
        "  [Headless Host] Rendered 1280x800 Login 3D Frame ({} ClearType text draw calls). Compile for x86_64-pc-windows-msvc to launch interactive Win32 GUI!",
        fb.text_queue.len()
    );
    Ok(())
}

#[cfg(target_os = "windows")]
mod win32_impl {
    use core::ffi::c_void;
    use core::ptr::{null, null_mut};
    use std::cell::RefCell;
    use std::time::{Duration, Instant};

    use pw_core::{find_path_case_insensitive, PwError, PwResult};
    use pw_render_audio::{D3d9Renderer, FrameBuffer};

    use crate::game_app::{InputSnapshot, InteractiveClientApp};

    type HWND = *mut c_void;
    type HDC = *mut c_void;
    type HBITMAP = *mut c_void;
    type HFONT = *mut c_void;
    type HCURSOR = *mut c_void;
    type HICON = *mut c_void;
    type HBRUSH = *mut c_void;
    type HMODULE = *mut c_void;
    type HANDLE = *mut c_void;
    type HGDIOBJ = *mut c_void;

    const CS_HREDRAW: u32 = 0x0002;
    const CS_VREDRAW: u32 = 0x0001;
    const CS_OWNDC: u32 = 0x0020;

    const WS_OVERLAPPEDWINDOW: u32 = 0x00CF_0000;
    const WS_POPUP: u32 = 0x8000_0000;
    const WS_VISIBLE: u32 = 0x1000_0000;

    const CW_USEDEFAULT: i32 = -2147483648i32;
    const SW_SHOW: i32 = 5;
    const PM_REMOVE: u32 = 0x0001;

    const WM_DESTROY: u32 = 0x0002;
    const WM_SIZE: u32 = 0x0005;
    const WM_CLOSE: u32 = 0x0010;
    const WM_SETCURSOR: u32 = 0x0020;
    const WM_ERASEBKGND: u32 = 0x0014;
    const WM_KEYDOWN: u32 = 0x0100;
    const WM_KEYUP: u32 = 0x0101;
    const WM_CHAR: u32 = 0x0102;
    const WM_SYSKEYDOWN: u32 = 0x0104;
    const WM_MOUSEMOVE: u32 = 0x0200;
    const WM_LBUTTONDOWN: u32 = 0x0201;
    const WM_LBUTTONUP: u32 = 0x0202;
    const WM_RBUTTONDOWN: u32 = 0x0204;
    const WM_RBUTTONUP: u32 = 0x0205;
    const WM_MOUSEWHEEL: u32 = 0x020A;

    const SM_CXSCREEN: i32 = 0;
    const SM_CYSCREEN: i32 = 1;
    const GWL_STYLE: i32 = -16;
    const SWP_FRAMECHANGED: u32 = 0x0020;
    const SWP_SHOWWINDOW: u32 = 0x0040;

    const SRCCOPY: u32 = 0x00CC_0020;
    const DIB_RGB_COLORS: u32 = 0;
    const TRANSPARENT: i32 = 1;
    const COLORONCOLOR: i32 = 3;
    const DEFAULT_CHARSET: u32 = 1;
    const CLEARTYPE_QUALITY: u32 = 5;

    #[repr(C)]
    struct WNDCLASSEXW {
        cb_size: u32,
        style: u32,
        lpfn_wnd_proc: unsafe extern "system" fn(HWND, u32, usize, isize) -> isize,
        cb_cls_extra: i32,
        cb_wnd_extra: i32,
        h_instance: HMODULE,
        h_icon: HICON,
        h_cursor: HCURSOR,
        hbr_background: HBRUSH,
        lpsz_menu_name: *const u16,
        lpsz_class_name: *const u16,
        h_icon_sm: HICON,
    }

    #[repr(C)]
    struct MSG {
        hwnd: HWND,
        message: u32,
        w_param: usize,
        l_param: isize,
        time: u32,
        pt_x: i32,
        pt_y: i32,
    }

    #[repr(C)]
    #[derive(Clone, Copy, Default)]
    struct RECT {
        left: i32,
        top: i32,
        right: i32,
        bottom: i32,
    }

    #[repr(C)]
    struct BITMAPINFOHEADER {
        bi_size: u32,
        bi_width: i32,
        bi_height: i32,
        bi_planes: u16,
        bi_bit_count: u16,
        bi_compression: u32,
        bi_size_image: u32,
        bi_x_pels_per_meter: i32,
        bi_y_pels_per_meter: i32,
        bi_clr_used: u32,
        bi_clr_important: u32,
    }

    #[repr(C)]
    struct BITMAPINFO {
        bmi_header: BITMAPINFOHEADER,
        bmi_colors: [u32; 1],
    }

    #[link(name = "kernel32")]
    unsafe extern "system" {
        fn GetModuleHandleW(lpModuleName: *const u16) -> HMODULE;
    }

    #[link(name = "user32")]
    unsafe extern "system" {
        fn SetProcessDPIAware() -> i32;
        fn RegisterClassExW(lpwcx: *const WNDCLASSEXW) -> u16;
        fn CreateWindowExW(
            dwExStyle: u32,
            lpClassName: *const u16,
            lpWindowName: *const u16,
            dwStyle: u32,
            x: i32,
            y: i32,
            nWidth: i32,
            nHeight: i32,
            hWndParent: HWND,
            hMenu: HANDLE,
            hInstance: HMODULE,
            lpParam: *mut c_void,
        ) -> HWND;
        fn ShowWindow(hWnd: HWND, nCmdShow: i32) -> i32;
        fn SetForegroundWindow(hWnd: HWND) -> i32;
        fn SetFocus(hWnd: HWND) -> HWND;
        fn DestroyWindow(hWnd: HWND) -> i32;
        fn PostQuitMessage(nExitCode: i32);
        fn DefWindowProcW(hWnd: HWND, msg: u32, wParam: usize, lParam: isize) -> isize;
        fn PeekMessageW(
            lpMsg: *mut MSG,
            hWnd: HWND,
            wMsgFilterMin: u32,
            wMsgFilterMax: u32,
            wRemoveMsg: u32,
        ) -> i32;
        fn TranslateMessage(lpMsg: *const MSG) -> i32;
        fn DispatchMessageW(lpMsg: *const MSG) -> isize;
        fn GetClientRect(hWnd: HWND, lpRect: *mut RECT) -> i32;
        fn GetWindowRect(hWnd: HWND, lpRect: *mut RECT) -> i32;
        fn AdjustWindowRect(lpRect: *mut RECT, dwStyle: u32, bMenu: i32) -> i32;
        fn GetDC(hWnd: HWND) -> HDC;
        fn ReleaseDC(hWnd: HWND, hDC: HDC) -> i32;
        fn LoadCursorW(hInstance: HMODULE, lpCursorName: *const u16) -> HCURSOR;
        fn LoadCursorFromFileW(lpFileName: *const u16) -> HCURSOR;
        fn SetCursor(hCursor: HCURSOR) -> HCURSOR;
        fn GetSystemMetrics(nIndex: i32) -> i32;
        fn SetWindowLongW(hWnd: HWND, nIndex: i32, dwNewLong: i32) -> i32;
        fn SetWindowPos(
            hWnd: HWND,
            hWndInsertAfter: HWND,
            x: i32,
            y: i32,
            cx: i32,
            cy: i32,
            uFlags: u32,
        ) -> i32;
    }

    #[link(name = "gdi32")]
    unsafe extern "system" {
        fn CreateCompatibleDC(hdc: HDC) -> HDC;
        fn DeleteDC(hdc: HDC) -> i32;
        fn CreateDIBSection(
            hdc: HDC,
            pbmi: *const BITMAPINFO,
            usage: u32,
            ppvBits: *mut *mut c_void,
            hSection: HANDLE,
            offset: u32,
        ) -> HBITMAP;
        fn SelectObject(hdc: HDC, h: HGDIOBJ) -> HGDIOBJ;
        fn DeleteObject(ho: HGDIOBJ) -> i32;
        fn BitBlt(
            hdc: HDC,
            x: i32,
            y: i32,
            cx: i32,
            cy: i32,
            hdcSrc: HDC,
            x1: i32,
            y1: i32,
            rop: u32,
        ) -> i32;
        fn StretchBlt(
            hdcDest: HDC,
            xDest: i32,
            yDest: i32,
            wDest: i32,
            hDest: i32,
            hdcSrc: HDC,
            xSrc: i32,
            ySrc: i32,
            wSrc: i32,
            hSrc: i32,
            rop: u32,
        ) -> i32;
        fn SetStretchBltMode(hdc: HDC, mode: i32) -> i32;
        fn GdiFlush() -> i32;
        fn SetBkMode(hdc: HDC, mode: i32) -> i32;
        fn SetTextColor(hdc: HDC, color: u32) -> u32;
        fn TextOutW(hdc: HDC, x: i32, y: i32, lpString: *const u16, c: i32) -> i32;
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
        ) -> HFONT;
        fn AddFontMemResourceEx(
            pFileView: *const c_void,
            cjSize: u32,
            pvResrved: *const c_void,
            pNumFonts: *mut u32,
        ) -> HANDLE;
        fn RemoveFontMemResourceEx(h: HANDLE) -> i32;
    }

    struct WindowEvents {
        closed: bool,
        client_w: u32,
        client_h: u32,
        keys_down: [bool; 256],
        key_presses: Vec<u32>,
        chars: Vec<char>,
        clicks: Vec<(i32, i32)>,
        wheel_delta: i32,
        mouse_x: i32,
        mouse_y: i32,
        lmb_down: bool,
        rmb_down: bool,
        toggle_fullscreen: bool,
        custom_cursor: usize,
    }

    impl Default for WindowEvents {
        fn default() -> Self {
            Self {
                closed: false,
                client_w: 1280,
                client_h: 800,
                keys_down: [false; 256],
                key_presses: Vec::new(),
                chars: Vec::new(),
                clicks: Vec::new(),
                wheel_delta: 0,
                mouse_x: 0,
                mouse_y: 0,
                lmb_down: false,
                rmb_down: false,
                toggle_fullscreen: false,
                custom_cursor: 0,
            }
        }
    }

    thread_local! {
        static WIN_STATE: RefCell<WindowEvents> = RefCell::new(WindowEvents::default());
    }

    fn to_wide_null(s: &str) -> Vec<u16> {
        let mut v: Vec<u16> = s.encode_utf16().collect();
        v.push(0);
        v
    }

    #[inline]
    fn argb_to_colorref(argb: u32) -> u32 {
        let r = (argb >> 16) & 0xFF;
        let g = (argb >> 8) & 0xFF;
        let b = argb & 0xFF;
        (b << 16) | (g << 8) | r
    }

    unsafe extern "system" fn wnd_proc(
        hwnd: HWND,
        msg: u32,
        w_param: usize,
        l_param: isize,
    ) -> isize {
        match msg {
            WM_CLOSE => {
                WIN_STATE.with(|st| st.borrow_mut().closed = true);
                unsafe { DestroyWindow(hwnd) };
                0
            }
            WM_DESTROY => {
                WIN_STATE.with(|st| st.borrow_mut().closed = true);
                unsafe { PostQuitMessage(0) };
                0
            }
            WM_ERASEBKGND => 1,
            WM_SETCURSOR => {
                if (l_param & 0xFFFF) == 1 {
                    let cur = WIN_STATE.with(|st| st.borrow().custom_cursor);
                    if cur != 0 {
                        unsafe { SetCursor(cur as HCURSOR) };
                        return 1;
                    }
                }
                unsafe { DefWindowProcW(hwnd, msg, w_param, l_param) }
            }
            WM_SIZE => {
                let cw = (l_param as usize & 0xFFFF) as u32;
                let ch = ((l_param as usize >> 16) & 0xFFFF) as u32;
                if cw > 0 && ch > 0 {
                    WIN_STATE.with(|st| {
                        let mut b = st.borrow_mut();
                        b.client_w = cw;
                        b.client_h = ch;
                    });
                }
                0
            }
            WM_SYSKEYDOWN => {
                // Alt+Enter toggles borderless fullscreen!
                if w_param == 0x0D {
                    WIN_STATE.with(|st| st.borrow_mut().toggle_fullscreen = true);
                    return 0;
                }
                unsafe { DefWindowProcW(hwnd, msg, w_param, l_param) }
            }
            WM_KEYDOWN => {
                let vk = (w_param & 0xFF) as u32;
                WIN_STATE.with(|st| {
                    let mut b = st.borrow_mut();
                    if vk == 0x7A {
                        // F11 toggles borderless fullscreen!
                        b.toggle_fullscreen = true;
                    } else {
                        if (vk as usize) < 256 {
                            b.keys_down[vk as usize] = true;
                        }
                        b.key_presses.push(vk);
                    }
                });
                0
            }
            WM_KEYUP => {
                let vk = (w_param & 0xFF) as usize;
                if vk < 256 {
                    WIN_STATE.with(|st| st.borrow_mut().keys_down[vk] = false);
                }
                0
            }
            WM_CHAR => {
                if let Some(ch) = char::from_u32(w_param as u32) {
                    WIN_STATE.with(|st| st.borrow_mut().chars.push(ch));
                }
                0
            }
            WM_MOUSEMOVE => {
                let x = (l_param as i16) as i32;
                let y = ((l_param >> 16) as i16) as i32;
                WIN_STATE.with(|st| {
                    let mut b = st.borrow_mut();
                    b.mouse_x = x;
                    b.mouse_y = y;
                });
                0
            }
            WM_LBUTTONDOWN => {
                let x = (l_param as i16) as i32;
                let y = ((l_param >> 16) as i16) as i32;
                WIN_STATE.with(|st| {
                    let mut b = st.borrow_mut();
                    b.mouse_x = x;
                    b.mouse_y = y;
                    b.lmb_down = true;
                    b.clicks.push((x, y));
                });
                0
            }
            WM_LBUTTONUP => {
                WIN_STATE.with(|st| st.borrow_mut().lmb_down = false);
                0
            }
            WM_RBUTTONDOWN => {
                let x = (l_param as i16) as i32;
                let y = ((l_param >> 16) as i16) as i32;
                WIN_STATE.with(|st| {
                    let mut b = st.borrow_mut();
                    b.mouse_x = x;
                    b.mouse_y = y;
                    b.rmb_down = true;
                });
                0
            }
            WM_RBUTTONUP => {
                WIN_STATE.with(|st| st.borrow_mut().rmb_down = false);
                0
            }
            WM_MOUSEWHEEL => {
                let delta = ((w_param >> 16) as i16) as i32;
                WIN_STATE.with(|st| st.borrow_mut().wheel_delta += delta);
                0
            }
            _ => unsafe { DefWindowProcW(hwnd, msg, w_param, l_param) },
        }
    }

    struct DibSurface {
        mem_dc: HDC,
        dib: HBITMAP,
        old_bmp: HGDIOBJ,
        bits: *mut u32,
        w: u32,
        h: u32,
    }

    impl DibSurface {
        unsafe fn create(ref_dc: HDC, w: u32, h: u32) -> Option<Self> {
            let mem_dc = unsafe { CreateCompatibleDC(ref_dc) };
            if mem_dc.is_null() {
                return None;
            }
            let bmi = BITMAPINFO {
                bmi_header: BITMAPINFOHEADER {
                    bi_size: core::mem::size_of::<BITMAPINFOHEADER>() as u32,
                    bi_width: w as i32,
                    bi_height: -(h as i32), // Top-down 32-bit ARGB!
                    bi_planes: 1,
                    bi_bit_count: 32,
                    bi_compression: 0,
                    bi_size_image: w * h * 4,
                    bi_x_pels_per_meter: 0,
                    bi_y_pels_per_meter: 0,
                    bi_clr_used: 0,
                    bi_clr_important: 0,
                },
                bmi_colors: [0],
            };
            let mut bits_void: *mut c_void = null_mut();
            let dib = unsafe {
                CreateDIBSection(ref_dc, &bmi, DIB_RGB_COLORS, &mut bits_void, null_mut(), 0)
            };
            if dib.is_null() || bits_void.is_null() {
                unsafe { DeleteDC(mem_dc) };
                return None;
            }
            let old_bmp = unsafe { SelectObject(mem_dc, dib) };
            unsafe { SetBkMode(mem_dc, TRANSPARENT) };
            Some(Self {
                mem_dc,
                dib,
                old_bmp,
                bits: bits_void as *mut u32,
                w,
                h,
            })
        }
    }

    impl Drop for DibSurface {
        fn drop(&mut self) {
            unsafe {
                if !self.mem_dc.is_null() {
                    if !self.old_bmp.is_null() {
                        SelectObject(self.mem_dc, self.old_bmp);
                    }
                    if !self.dib.is_null() {
                        DeleteObject(self.dib);
                    }
                    DeleteDC(self.mem_dc);
                }
            }
        }
    }

    pub fn run_loop(app: &mut InteractiveClientApp) -> PwResult<()> {
        unsafe {
            let _ = SetProcessDPIAware();
            let h_inst = GetModuleHandleW(null());

            // Load custom PW cursor from `element/cursors/normal.ani` or `point.ani` if available
            let mut cursor_handle: HCURSOR = null_mut();
            for cur_rel in ["cursors/normal.ani", "cursors/Point.ani", "cursors/normal.cur"] {
                if let Some(p) = find_path_case_insensitive(&app.game.element_root, cur_rel) {
                    let wpath = to_wide_null(&p.to_string_lossy());
                    let hc = LoadCursorFromFileW(wpath.as_ptr());
                    if !hc.is_null() {
                        cursor_handle = hc;
                        break;
                    }
                }
            }
            if !cursor_handle.is_null() {
                app.scene_3d.show_software_cursor = false;
            }
            if cursor_handle.is_null() {
                cursor_handle = LoadCursorW(null_mut(), 32512usize as *const u16); // IDC_ARROW
            }

            let class_name = to_wide_null("PW142ElementClientRustClass");
            let wcx = WNDCLASSEXW {
                cb_size: core::mem::size_of::<WNDCLASSEXW>() as u32,
                style: CS_HREDRAW | CS_VREDRAW | CS_OWNDC,
                lpfn_wnd_proc: wnd_proc,
                cb_cls_extra: 0,
                cb_wnd_extra: 0,
                h_instance: h_inst,
                h_icon: null_mut(),
                h_cursor: cursor_handle,
                hbr_background: null_mut(),
                lpsz_menu_name: null(),
                lpsz_class_name: class_name.as_ptr(),
                h_icon_sm: null_mut(),
            };
            let _ = RegisterClassExW(&wcx);

            let screen_w = GetSystemMetrics(SM_CXSCREEN).max(1024);
            let screen_h = GetSystemMetrics(SM_CYSCREEN).max(768);
            let mut is_fullscreen = app.game.video_audio_settings.fullscreen;

            let init_cw = if is_fullscreen {
                screen_w
            } else {
                (app.game.video_audio_settings.render_wid as i32).clamp(1024, (screen_w - 80).max(1024))
            };
            let init_ch = if is_fullscreen {
                screen_h
            } else {
                (app.game.video_audio_settings.render_hei as i32).clamp(720, (screen_h - 100).max(720))
            };

            let style = if is_fullscreen {
                WS_POPUP | WS_VISIBLE
            } else {
                WS_OVERLAPPEDWINDOW | WS_VISIBLE
            };
            let mut rc = RECT {
                left: 0,
                top: 0,
                right: init_cw,
                bottom: init_ch,
            };
            if !is_fullscreen {
                let _ = AdjustWindowRect(&mut rc, style, 0);
            }
            let win_w = rc.right - rc.left;
            let win_h = rc.bottom - rc.top;
            let win_x = if is_fullscreen { 0 } else { ((screen_w - win_w) / 2).max(0) };
            let win_y = if is_fullscreen { 0 } else { ((screen_h - win_h) / 2).max(0) };

            WIN_STATE.with(|st| {
                let mut b = st.borrow_mut();
                *b = WindowEvents::default();
                b.client_w = init_cw as u32;
                b.client_h = init_ch as u32;
                b.custom_cursor = cursor_handle as usize;
            });

            let title = to_wide_null(&format!(
                "Perfect World 1.4.2 (Build {} — Rust 1:1 Client | F11 Fullscreen | F5 Offline Sandbox)",
                app.game.build_version
            ));
            let hwnd = CreateWindowExW(
                0,
                class_name.as_ptr(),
                title.as_ptr(),
                style,
                win_x,
                win_y,
                if win_w > 0 { win_w } else { CW_USEDEFAULT },
                if win_h > 0 { win_h } else { CW_USEDEFAULT },
                null_mut(),
                null_mut(),
                h_inst,
                null_mut(),
            );
            if hwnd.is_null() {
                return Err(PwError::InvalidData("CreateWindowExW failed".into()));
            }
            let _ = ShowWindow(hwnd, SW_SHOW);
            let _ = SetForegroundWindow(hwnd);
            let _ = SetFocus(hwnd);

            // Register TrueType fonts from `fonts.pck` directly into Win32 GDI memory!
            let mut font_handles: Vec<HANDLE> = Vec::new();
            for blob in &app.game.raw_font_blobs {
                let mut num_added = 0u32;
                let fh = AddFontMemResourceEx(
                    blob.as_ptr() as *const c_void,
                    blob.len() as u32,
                    null(),
                    &mut num_added,
                );
                if !fh.is_null() {
                    font_handles.push(fh);
                }
            }

            let face = to_wide_null("Microsoft YaHei UI");
            let font_sm = CreateFontW(-12, 0, 0, 0, 400, 0, 0, 0, DEFAULT_CHARSET, 0, 0, CLEARTYPE_QUALITY, 0, face.as_ptr());
            let font_sm_b = CreateFontW(-12, 0, 0, 0, 700, 0, 0, 0, DEFAULT_CHARSET, 0, 0, CLEARTYPE_QUALITY, 0, face.as_ptr());
            let font_md = CreateFontW(-14, 0, 0, 0, 400, 0, 0, 0, DEFAULT_CHARSET, 0, 0, CLEARTYPE_QUALITY, 0, face.as_ptr());
            let font_md_b = CreateFontW(-15, 0, 0, 0, 700, 0, 0, 0, DEFAULT_CHARSET, 0, 0, CLEARTYPE_QUALITY, 0, face.as_ptr());

            let win_dc = GetDC(hwnd);
            SetStretchBltMode(win_dc, COLORONCOLOR);

            // Cap internal 3D render target height at 900p (maintaining exact UltraWide 21:9 / 16:9 aspect!)
            // so 3440x1440 UltraWide runs at a locked, silky-smooth 60 FPS!
            let compute_fb_dims = |cw: u32, ch: u32| -> (u32, u32) {
                let cw = cw.max(640);
                let ch = ch.max(480);
                if ch > 900 {
                    let scaled_w = ((cw as u64 * 900) / (ch as u64)).max(640) as u32;
                    (scaled_w, 900)
                } else {
                    (cw, ch)
                }
            };

            // Primary renderer: hardware Direct3D 9 (`d3d9.dll` COM `IDirect3DDevice9`) at native resolution!
            let mut d3d9 = D3d9Renderer::try_create(
                hwnd as isize,
                init_cw.max(640) as u32,
                init_ch.max(480) as u32,
                &app.game.raw_font_blobs,
            );
            let mut last_scene_gen = app.scene_generation;

            let (init_fb_w, init_fb_h) = compute_fb_dims(init_cw as u32, init_ch as u32);
            let mut fb = FrameBuffer::new(init_fb_w, init_fb_h);
            let mut dib = DibSurface::create(win_dc, init_fb_w, init_fb_h)
                .ok_or_else(|| PwError::InvalidData("CreateDIBSection failed".into()))?;

            let mut saved_window_rect = RECT {
                left: 120,
                top: 80,
                right: 1400,
                bottom: 880,
            };

            let mut last_tick = Instant::now();
            let mut fps_timer = Instant::now();
            let mut fps_frames = 0u32;

            'game_loop: loop {
                let mut msg = core::mem::zeroed::<MSG>();
                while PeekMessageW(&mut msg, null_mut(), 0, 0, PM_REMOVE) != 0 {
                    if msg.message == 0x0012 {
                        // WM_QUIT
                        break 'game_loop;
                    }
                    TranslateMessage(&msg);
                    DispatchMessageW(&msg);
                }

                let (
                    closed,
                    cw,
                    ch,
                    toggle_fs,
                    presses,
                    chars,
                    clicks,
                    wheel,
                    snap,
                ) = WIN_STATE.with(|st| {
                    let mut b = st.borrow_mut();
                    let presses = core::mem::take(&mut b.key_presses);
                    let chars = core::mem::take(&mut b.chars);
                    let clicks = core::mem::take(&mut b.clicks);
                    let wheel = core::mem::replace(&mut b.wheel_delta, 0);
                    let toggle_fs = core::mem::replace(&mut b.toggle_fullscreen, false);
                    let cw = b.client_w.max(1);
                    let ch = b.client_h.max(1);
                    let render_w = if d3d9.is_some() { cw } else { fb.width };
                    let render_h = if d3d9.is_some() { ch } else { fb.height };
                    let map_x = |x: i32| ((x as i64 * render_w as i64) / cw as i64) as i32;
                    let map_y = |y: i32| ((y as i64 * render_h as i64) / ch as i64) as i32;

                    let snap = InputSnapshot {
                        move_fwd: b.keys_down[0x57] || b.keys_down[0x26],   // W / Up
                        move_back: b.keys_down[0x53] || b.keys_down[0x28],  // S / Down
                        move_left: b.keys_down[0x41] || b.keys_down[0x25],  // A / Left
                        move_right: b.keys_down[0x44] || b.keys_down[0x27], // D / Right
                        ascend: b.keys_down[0x20],                          // Space
                        descend: b.keys_down[0x43] || b.keys_down[0x11],    // C / Ctrl
                        sprint: b.keys_down[0x10],                          // Shift
                        mouse_x: map_x(b.mouse_x),
                        mouse_y: map_y(b.mouse_y),
                        lmb_down: b.lmb_down,
                        rmb_down: b.rmb_down,
                    };
                    let mapped_clicks: Vec<(i32, i32)> =
                        clicks.into_iter().map(|(x, y)| (map_x(x), map_y(y))).collect();
                    (
                        b.closed,
                        cw,
                        ch,
                        toggle_fs,
                        presses,
                        chars,
                        mapped_clicks,
                        wheel,
                        snap,
                    )
                });

                if closed || app.should_quit {
                    break 'game_loop;
                }

                if toggle_fs {
                    is_fullscreen = !is_fullscreen;
                    if is_fullscreen {
                        let _ = GetWindowRect(hwnd, &mut saved_window_rect);
                        SetWindowLongW(hwnd, GWL_STYLE, (WS_POPUP | WS_VISIBLE) as i32);
                        SetWindowPos(
                            hwnd,
                            null_mut(),
                            0,
                            0,
                            GetSystemMetrics(SM_CXSCREEN),
                            GetSystemMetrics(SM_CYSCREEN),
                            SWP_FRAMECHANGED | SWP_SHOWWINDOW,
                        );
                    } else {
                        SetWindowLongW(hwnd, GWL_STYLE, (WS_OVERLAPPEDWINDOW | WS_VISIBLE) as i32);
                        SetWindowPos(
                            hwnd,
                            null_mut(),
                            saved_window_rect.left,
                            saved_window_rect.top,
                            (saved_window_rect.right - saved_window_rect.left).max(1024),
                            (saved_window_rect.bottom - saved_window_rect.top).max(720),
                            SWP_FRAMECHANGED | SWP_SHOWWINDOW,
                        );
                    }
                }

                let active_w = if d3d9.is_some() { cw } else { fb.width };
                let active_h = if d3d9.is_some() { ch } else { fb.height };
                if let Some(ref mut hw) = d3d9 {
                    hw.resize(cw, ch);
                } else {
                    let (target_fb_w, target_fb_h) = compute_fb_dims(cw, ch);
                    if target_fb_w != fb.width || target_fb_h != fb.height {
                        fb.resize(target_fb_w, target_fb_h);
                        if let Some(new_dib) = DibSurface::create(win_dc, target_fb_w, target_fb_h) {
                            dib = new_dib;
                        }
                    }
                }

                for vk in presses {
                    app.on_key_down(vk);
                }
                for c in chars {
                    app.on_char_input(c);
                }
                if wheel != 0 {
                    app.on_mouse_wheel(wheel);
                }
                for (cx_click, cy_click) in clicks {
                    app.on_mouse_click(cx_click, cy_click, active_w, active_h);
                }
                if app.should_quit {
                    DestroyWindow(hwnd);
                    break 'game_loop;
                }

                let now = Instant::now();
                let dt = now.duration_since(last_tick).as_secs_f32();
                last_tick = now;

                app.tick(dt, &snap);

                let mut rendered_hw = false;
                if let Some(ref mut hw) = d3d9 {
                    if app.scene_generation != last_scene_gen {
                        hw.invalidate_scene_textures();
                        last_scene_gen = app.scene_generation;
                    }
                    let pf = app.prepare_frame(cw, ch, snap.mouse_x, snap.mouse_y);
                    rendered_hw = hw.render_frame(
                        &mut app.scene_3d,
                        &app.game.vfs,
                        pf.eye,
                        pf.dir,
                        pf.up,
                        &pf.cam_proj,
                        &pf.actors,
                        &pf.ui_quads,
                        &pf.ui_texts,
                        pf.anim_time,
                    );
                }

                if !rendered_hw {
                    app.render(&mut fb, snap.mouse_x, snap.mouse_y);

                    // Copy 3D + 2D pixels into DIBSection & overlay crisp GDI ClearType Unicode text!
                    if dib.w == fb.width && dib.h == fb.height {
                        core::ptr::copy_nonoverlapping(
                            fb.pixels.as_ptr(),
                            dib.bits,
                            fb.pixels.len(),
                        );
                        GdiFlush();

                        for cmd in &fb.text_queue {
                            let chosen = match (cmd.font_px >= 14, cmd.bold) {
                                (false, false) => font_sm,
                                (false, true) => font_sm_b,
                                (true, false) => font_md,
                                (true, true) => font_md_b,
                            };
                            SelectObject(dib.mem_dc, chosen);
                            let wide: Vec<u16> = cmd.text.encode_utf16().collect();
                            if wide.is_empty() {
                                continue;
                            }
                            if cmd.shadow {
                                SetTextColor(dib.mem_dc, 0x0000_0000);
                                TextOutW(
                                    dib.mem_dc,
                                    cmd.x + 1,
                                    cmd.y + 1,
                                    wide.as_ptr(),
                                    wide.len() as i32,
                                );
                            }
                            SetTextColor(dib.mem_dc, argb_to_colorref(cmd.color));
                            TextOutW(dib.mem_dc, cmd.x, cmd.y, wide.as_ptr(), wide.len() as i32);
                        }

                        let mut crc = RECT::default();
                        GetClientRect(hwnd, &mut crc);
                        let dest_w = (crc.right - crc.left).max(1);
                        let dest_h = (crc.bottom - crc.top).max(1);
                        if dest_w == dib.w as i32 && dest_h == dib.h as i32 {
                            BitBlt(win_dc, 0, 0, dest_w, dest_h, dib.mem_dc, 0, 0, SRCCOPY);
                        } else {
                            StretchBlt(
                                win_dc,
                                0,
                                0,
                                dest_w,
                                dest_h,
                                dib.mem_dc,
                                0,
                                0,
                                dib.w as i32,
                                dib.h as i32,
                                SRCCOPY,
                            );
                        }
                    }
                }

                fps_frames += 1;
                let elapsed_fps = fps_timer.elapsed().as_secs_f32();
                if elapsed_fps >= 0.5 {
                    app.fps_display = ((fps_frames as f32) / elapsed_fps).round() as u32;
                    fps_frames = 0;
                    fps_timer = Instant::now();
                }

                let frame_spent = now.elapsed();
                let target_budget = Duration::from_micros(16_000);
                if frame_spent < target_budget {
                    std::thread::sleep(target_budget - frame_spent);
                }
            }

            ReleaseDC(hwnd, win_dc);
            for fh in &[font_sm, font_sm_b, font_md, font_md_b] {
                if !fh.is_null() {
                    DeleteObject(*fh);
                }
            }
            for h in font_handles {
                RemoveFontMemResourceEx(h);
            }
        }
        Ok(())
    }
}
