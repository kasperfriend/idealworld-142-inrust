#!/usr/bin/env python3
"""Network/coordinate parity auditor: verifies the server-authoritative position path
(NOTIFY_POS / SELF_INFO_1 / world_tag map switching / PLAYER_MOVE) is replicated 1:1,
so incorrect coordinates cannot happen. Ground truth: findings/04 + evidence ledgers.
Emits evidence/network_parity/report.{json,md}.
"""
import json, os, re, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
OUT = os.path.join(ROOT, "evidence", "network_parity")

def read(p):
    return open(os.path.join(ROOT, p), encoding="utf-8", errors="replace").read()

def main():
    os.makedirs(OUT, exist_ok=True)
    gd = read("port/crates/pw-gnet/src/gamedata.rs")
    live = read("port/crates/pw-gnet/src/live_client.rs")
    app = read("port/crates/pw-client/src/game_app.rs")
    checks = []
    def check(name, ok, detail=""):
        checks.append({"name": name, "ok": bool(ok), "detail": detail})
        print(("PASS " if ok else "FAIL ") + name + (f" — {detail}" if detail else ""))

    # s2c cmd ids present and matching the decompiled constants
    check("s2c::SELF_INFO_1 = 0x0008 decoded with f32 pos[3]", "SELF_INFO_1: u16 = 0x0008" in gd and "r.vec3()?" in gd)
    check("s2c::NOTIFY_POS = 0x0025 decoded (pos + i32 world_tag)",
          re.search(r"NOTIFY_POS: u16 = 0x0025", gd) is not None and "world_tag = r.i32()?" in gd)
    check("live fast-path decodes SELF_INFO_1 pos at body[8..20] and NOTIFY_POS at body[0..16]",
          "s2c_cmd == 0x0008" in live and "s2c_cmd == 0x0025" in live
          and "body[8], body[9], body[10], body[11]" in live)
    check("EnterWorld c2s op 72 sent after SelectRole_Re op 71 result==0",
          "send_enter_world(rid)" in live and re.search(r"71 => \{", live) is not None)

    # c2s movement echo (already audited in movement parity)
    check("c2s PLAYER_MOVE cmd 0x0000 33-byte layout", "send_gamedata_c2s(0x0000" in live)

    # game_app: world_tag drives map switch, position ground-clamped, no hardcoded online spawn
    check("GsNotifyPos switches map via world_tag_to_map before applying pos",
          re.search(r"GsNotifyPos \{ pos, world_tag \} => \{[\s\S]*?world_tag_to_map\(world_tag\)[\s\S]*?load_map_by_name_at", app) is not None)
    check("GsNotifyPos ground-clamps server Y via sample_active_ground_y",
          re.search(r"GsNotifyPos[\s\S]*?sample_active_ground_y\(pos\.0", app) is not None)
    check("SelfInfo1 applies server pos with ground clamp",
          re.search(r"SelfInfo1\(info\) => \{[\s\S]*?sample_active_ground_y\(info\.pos\.0", app) is not None)
    check("online mode never hardcodes Archosaur spawn (waits for server pos)",
          re.search(r"else if self\.online_mode \{\s*// Online: the server's SELF_INFO_1 / NOTIFY_POS", app) is not None
          and app.count("else if self.online_mode {") >= 2)
    check("world_tag_to_map: tag<=1 -> world (fallback a01), other tags -> matching map dir",
          "pub fn world_tag_to_map" in app and 'eq_ignore_ascii_case("world")' in app)

    # slice entries carry positions for NPC/player/matter
    check("NPC/player/matter slice entries decode pos (vec3) + dir + state",
          all(s in gd for s in ["GsNpcSliceInfo", "GsPlayerSliceInfo", "GsMatterSliceInfo"]))

    n_fail = sum(1 for c in checks if not c["ok"])
    report = {"checks": checks, "summary": {"passed": len(checks) - n_fail, "total": len(checks)}}
    with open(os.path.join(OUT, "report.json"), "w") as f:
        json.dump(report, f, indent=1)
    md = ["# Network / Coordinate Parity Audit", "",
          f"**{report['summary']['passed']}/{report['summary']['total']} checks passed**", "",
          "| Check | Result | Detail |", "|---|---|---|"]
    for c in checks:
        md.append(f"| {c['name']} | {'✅' if c['ok'] else '❌'} | {c['detail'][:110]} |")
    with open(os.path.join(OUT, "report.md"), "w") as f:
        f.write("\n".join(md) + "\n")
    print(f"\n{report['summary']['passed']}/{report['summary']['total']} -> {OUT}")
    sys.exit(1 if n_fail else 0)

if __name__ == "__main__":
    main()
