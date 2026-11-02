# Network / Coordinate Parity Audit

**11/11 checks passed**

| Check | Result | Detail |
|---|---|---|
| s2c::SELF_INFO_1 = 0x0008 decoded with f32 pos[3] | ✅ |  |
| s2c::NOTIFY_POS = 0x0025 decoded (pos + i32 world_tag) | ✅ |  |
| live fast-path decodes SELF_INFO_1 pos at body[8..20] and NOTIFY_POS at body[0..16] | ✅ |  |
| EnterWorld c2s op 72 sent after SelectRole_Re op 71 result==0 | ✅ |  |
| c2s PLAYER_MOVE cmd 0x0000 33-byte layout | ✅ |  |
| GsNotifyPos switches map via world_tag_to_map before applying pos | ✅ |  |
| GsNotifyPos ground-clamps server Y via sample_active_ground_y | ✅ |  |
| SelfInfo1 applies server pos with ground clamp | ✅ |  |
| online mode never hardcodes Archosaur spawn (waits for server pos) | ✅ |  |
| world_tag_to_map: tag<=1 -> world (fallback a01), other tags -> matching map dir | ✅ |  |
| NPC/player/matter slice entries decode pos (vec3) + dir + state | ✅ |  |
