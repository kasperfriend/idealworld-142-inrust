# Movement Parity Audit — Rust client vs real PW 1.4.2 (evidence-based)

**28/28 checks passed**

| Check | Result | Detail |
|---|---|---|
| c2s PLAYER_MOVE exists with documented 33-byte layout | ✅ | cmd 0x0000, f32[3] cur + f32[3] next + u16 ms + u16 speed + u8 mode + u16 stamp |
| PLAYER_MOVE called from game loop with 0.25 s cadence | ✅ | server gets a move packet every 250 ms while moving |
| speed encoded as m/s * 256 (cm/s) in 1/256 m/s units | ✅ | sSpeed u16 = round(m/s * 256) |
| move modes: 0x01 ground / 0x21 fly | ✅ |  |
| s2c ObjectMove decoded (id, dest, time, speed, mode) | ✅ |  |
| s2c ObjectStopMove decoded (id, pos, speed, dir, mode) | ✅ |  |
| game_app applies ObjectMove/ObjectStopMove to live entities | ✅ |  |
| ExtProp decodes walk_speed | ✅ |  |
| ExtProp decodes run_speed | ✅ |  |
| ExtProp decodes swim_speed | ✅ |  |
| ExtProp decodes flight_speed | ✅ |  |
| run_speed from server drives local move_speed (x2.2) | ✅ |  |
| physics: default move speed 14.0 m/s | ✅ |  |
| physics: sprint multiplier 1.85 | ✅ |  |
| physics: fly multiplier 1.45 | ✅ |  |
| physics: jump initial velocity 9.5 | ✅ |  |
| physics: gravity 24.0 | ✅ |  |
| physics: fly ceiling ground+320 | ✅ |  |
| physics: fly vertical speed 0.75x | ✅ |  |
| ground collision samples .t2bk height + water + walkable | ✅ |  |
| position clamped to world bounds (half extents) | ✅ |  |
| landing snaps to ground and zeroes vertical velocity | ✅ |  |
| GNET::KeepAlive (op 90) in real opcode ledger and in port registry | ✅ | keepalive op 90 matches real client |
| PLAYER_MOVE is GamedataSend c2s cmd 0x00 (per decompiled cmd_player_move) | ✅ |  |
| real client class CECHostMove present in port RTTI registry (from real binary vtables) | ✅ | modeled in pw-client; physics in game_app tick |
| real client class CECHPWorkMove present in port RTTI registry (from real binary vtables) | ✅ | modeled in pw-client; physics in game_app tick |
| real client class CECHPWorkFall present in port RTTI registry (from real binary vtables) | ✅ | modeled in pw-client; physics in game_app tick |
| real client class CECHPWorkFly present in port RTTI registry (from real binary vtables) | ✅ | modeled in pw-client; physics in game_app tick |
