# 04 — GNET Network Framing, Authentication, RC4 + MPPC Crypto, & Wire Opcodes

Recovered from `CECGameSession` (`0x5d8c60.c`, `0x5d9700.c`, `0x5d97a0.c`), `GNET::Marshal::OctetsStream`, and automated extraction of static protocol stub constructors across `elementclient.exe`.

## 1. Wire Framing (`GNET::Protocol` & `CompactUINT`)

Every GNET packet on the TCP stream is framed as:
`[CompactUINT opcode] [CompactUINT payload_byte_length] [payload_bytes]`

Where `CompactUINT` uses big-endian prefix length bits:
- `0x00..0x7f` (`0xxxxxxx`): 1-byte `u8` (`0..127`)
- `0x80..0xbf` (`10xxxxxx yyyyyyyy`): 2-byte `u16` (`((b0 & 0x3f) << 8) | b1`)
- `0xc0..0xdf` (`110xxxxx ...`): 4-byte `u32` (`((b0 & 0x1f) << 24) | ...`)
- `0xe0` (`11100000` + 4 bytes): Full 5-byte `u32` (`u32::from_be_bytes(b[1..5])`)

## 2. Handshake, HMAC-MD5, RC4 & MPPC Session Pipeline

1. **Server -> Client `Challenge` (Opcode `1`, `0x5d8c60.c`)**:
   - Delivers `Octets nonce`, `u32 version`, and login `algo`.
   - Client computes `pwd_hash = MD5(account_ascii + password_ascii)` and `response = HMAC_MD5(key = pwd_hash, msg = nonce)` and sends `Response` (Opcode `3`).
2. **Bidirectional `KeyExchange` (Opcode `2`, `0x5d9700.c` / `0x5d97a0.c`)**:
   - Client & server exchange `16`-byte random nonces (`blkickuser`).
   - Session keys are derived via `HMAC_MD5(pwd_hash, account_plus_nonce)` (`SetISecurity` / `SetOSecurity`) and immediately zeroed from stack memory (`0x5d97a0`).
   - **C2S Stream (`SetOSecurity`)**: `CompressARCFourSecurity` — **MPPC** (8,192-byte history ring buffer Lempel-Ziv + Huffman bitstream) followed by **RC4** (`ARCFourSecurity`).
   - **S2C Stream (`SetISecurity`)**: `DecompressARCFourSecurity` — **RC4** decryption followed by **MPPC** decompression (matching standard `glinkd` PW 1.4.2 behavior).
3. **World Sub-Protocol Tunneling (`GamedataSend` Opcode `34` / `0x22`)**:
   - Once `EnterWorld` (`72` / `0x48`) completes, real-time movement, combat, NPC interaction, inventory, chat, and quest updates ride inside `GamedataSend` (`u16_le cmd_id` + packed C2S/S2C struct).

## 3. Complete Recovered GNET Protocol & RPC Table (`214` Opcodes)

| Opcode | Class Name | VTable VA | Stub Ctor VA |
| :--- | :--- | :--- | :--- |
| `4` (`0x4`) | `GNET::OnlineAnnounce` | `0x8e5680` | `0x5fcd60` |
| `5` (`0x5`) | `GNET::ErrorInfo` | `0x8e55b4` | `0x5fb200` |
| `6` (`0x6`) | `GNET::StatusAnnounce` | `0x8e59cc` | `0x601b60` |
| `7` (`0x7`) | `GNET::RoleStatusAnnounce` | `0x8e5a7c` | `0x602e00` |
| `34` (`0x22`) | `GNET::GamedataSend` | `0x8e41b0` | `0x5feca0` |
| `36` (`0x24`) | `GNET::UpdateRemainTime` | `0x8e65f4` | `0x613940` |
| `69` (`0x45`) | `GNET::PlayerLogout` | `0x8e59f8` | `0x601d00` |
| `70` (`0x46`) | `GNET::SelectRole` | `0x8e4260` | `0x5f62f0` |
| `71` (`0x47`) | `GNET::SelectRole_Re` | `0x8e5778` | `0x5fe3f0` |
| `72` (`0x48`) | `GNET::EnterWorld` | `0x8e42e4` | `0x5f6440` |
| `79` (`0x4f`) | `GNET::PublicChat` | `0x8e41dc` | `0x5f7920` |
| `80` (`0x50`) | `GNET::ChatMessage` | `0x8e5a24` | `0x601ea0` |
| `82` (`0x52`) | `GNET::RoleList` | `0x8e4310` | `0x5f6590` |
| `83` (`0x53`) | `GNET::RoleList_Re` | `0x8e56ac` | `0x5fd430` |
| `84` (`0x54`) | `GNET::CreateRole` | `0x8e4234` | `0x5f66e0` |
| `85` (`0x55`) | `GNET::CreateRole_Re` | `0x8e56f4` | `0x5fd8d0` |
| `86` (`0x56`) | `GNET::DeleteRole` | `0x8e428c` | `0x5f6950` |
| `87` (`0x57`) | `GNET::DeleteRole_Re` | `0x8e5720` | `0x5fe0b0` |
| `88` (`0x58`) | `GNET::UndoDeleteRole` | `0x8e42b8` | `0x5f6aa0` |
| `89` (`0x59`) | `GNET::UndoDeleteRole_Re` | `0x8e574c` | `0x5fe250` |
| `90` (`0x5a`) | `GNET::KeepAlive` | `0x8e3be8` | `0x5fd2e0` |
| `91` (`0x5b`) | `GNET::PlayerBaseInfo` | `0x8e433c` | `0x5f6bf0` |
| `92` (`0x5c`) | `GNET::PlayerBaseInfo_Re` | `0x8e5818` | `0x5fed90` |
| `96` (`0x60`) | `GNET::PrivateChat` | `0x8e4208` | `0x602cf0` |
| `98` (`0x62`) | `GNET::PlayerBaseInfoCRC` | `0x8e54cc` | `0x5f6ce0` |
| `99` (`0x63`) | `GNET::PlayerBaseInfoCRC_Re` | `0x8e587c` | `0x5ffdf0` |
| `100` (`0x64`) | `GNET::SetCustomData` | `0x8e43dc` | `0x5f71d0` |
| `101` (`0x65`) | `UnknownGNET_0x8eb660` | `0x8eb660` | `0x6db940` |
| `102` (`0x66`) | `GNET::SetUIConfig` | `0x8e4408` | `0x5f73b0` |
| `103` (`0x67`) | `GNET::SetUIConfig_Re` | `0x8e58d4` | `0x6009e0` |
| `104` (`0x68`) | `GNET::GetUIConfig` | `0x8e4434` | `0x5f74a0` |
| `105` (`0x69`) | `GNET::GetUIConfig_Re` | `0x8e5900` | `0x600b80` |
| `106` (`0x6a`) | `UnknownGNET_0x8ebf78` | `0x8ebf78` | `0x6f75c0` |
| `107` (`0x6b`) | `GNET::GetPlayerBriefInfo` | `0x8e44b8` | `0x5f7830` |
| `108` (`0x6c`) | `GNET::GetPlayerBriefInfo_Re` | `0x8e5984` | `0x6015e0` |
| `110` (`0x6e`) | `UnknownGNET_0x8ebe50` | `0x8ebe50` | `0x6f1950` |
| `116` (`0x74`) | `GNET::GetCustomData` | `0x8e4384` | `0x5f72c0` |
| `117` (`0x75`) | `GNET::GetCustomData_Re` | `0x8e57ec` | `0x5fe810` |
| `118` (`0x76`) | `GNET::GetPlayerIDByName` | `0x8e44e4` | `0x5f70e0` |
| `119` (`0x77`) | `GNET::GetPlayerIDByName_Re` | `0x8e58a8` | `0x600390` |
| `123` (`0x7b`) | `GNET::AnnounceForbidInfo` | `0x8e5638` | `0x5fc500` |
| `128` (`0x80`) | `GNET::SetHelpStates` | `0x8e4460` | `0x5f75f0` |
| `129` (`0x81`) | `GNET::SetHelpStates_Re` | `0x8e592c` | `0x600fe0` |
| `130` (`0x82`) | `GNET::GetHelpStates` | `0x8e448c` | `0x5f76e0` |
| `131` (`0x83`) | `GNET::GetHelpStates_Re` | `0x8e5958` | `0x601180` |
| `133` (`0x85`) | `GNET::WorldChat` | `0x8e5a50` | `0x6024e0` |
| `202` (`0xca`) | `GNET::AddFriend` | `0x8e4984` | `0x607560` |
| `203` (`0xcb`) | `GNET::AddFriend_Re` | `0x8e5d84` | `0x607650` |
| `206` (`0xce`) | `GNET::GetFriends` | `0x8e49b0` | `0x5f7a10` |
| `207` (`0xcf`) | `GNET::GetFriends_Re` | `0x8e5dcc` | `0x608050` |
| `208` (`0xd0`) | `GNET::SetGroupName` | `0x8e49dc` | `0x608800` |
| `209` (`0xd1`) | `GNET::SetGroupName_Re` | `0x8e5e4c` | `0x6088f0` |
| `210` (`0xd2`) | `GNET::SetFriendGroup` | `0x8e4a08` | `0x608f40` |
| `211` (`0xd3`) | `GNET::SetFriendGroup_Re` | `0x8e5e78` | `0x609090` |
| `212` (`0xd4`) | `GNET::DelFriend` | `0x8e4a34` | `0x609560` |
| `213` (`0xd5`) | `GNET::DelFriend_Re` | `0x8e5ea4` | `0x6096b0` |
| `214` (`0xd6`) | `GNET::FriendStatus` | `0x8e5ed0` | `0x609850` |
| `217` (`0xd9`) | `GNET::GetSavedMsg` | `0x8e4a60` | `0x609ca0` |
| `218` (`0xda`) | `GNET::GetSavedMsg_Re` | `0x8e5efc` | `0x609df0` |
| `220` (`0xdc`) | `GNET::ChatRoomCreate_Re` | `0x8e5f44` | `0x60a3c0` |
| `221` (`0xdd`) | `GNET::ChatRoomInvite` | `0x8e4b94` | `0x60aa80` |
| `222` (`0xde`) | `GNET::ChatRoomInvite_Re` | `0x8e4bc0` | `0x60ab90` |
| `224` (`0xe0`) | `GNET::ChatRoomJoin_Re` | `0x8e5f70` | `0x60ace0` |
| `225` (`0xe1`) | `GNET::ChatRoomLeave` | `0x8e4c18` | `0x60b550` |
| `226` (`0xe2`) | `GNET::ChatRoomExpel` | `0x8e4b68` | `0x60b6a0` |
| `227` (`0xe3`) | `GNET::ChatRoomSpeak` | `0x8e4c70` | `0x60b7f0` |
| `229` (`0xe5`) | `GNET::ChatRoomList_Re` | `0x8e5f9c` | `0x60b8e0` |
| `350` (`0x15e`) | `GNET::GMOnlineNum` | `0x8e4698` | `0x5f9c40` |
| `351` (`0x15f`) | `GNET::GMOnlineNum_Re` | `0x8e6144` | `0x60d8e0` |
| `352` (`0x160`) | `GNET::GMListOnlineUser` | `0x8e466c` | `0x5f9d90` |
| `353` (`0x161`) | `GNET::GMListOnlineUser_Re` | `0x8e6170` | `0x60da80` |
| `354` (`0x162`) | `GNET::GMKickoutUser` | `0x8e4640` | `0x5f9e80` |
| `355` (`0x163`) | `GNET::GMKickoutUser_Re` | `0x8e61b8` | `0x60ded0` |
| `356` (`0x164`) | `GNET::GMShutup` | `0x8e471c` | `0x5fa060` |
| `357` (`0x165`) | `GNET::GMShutup_Re` | `0x8e6210` | `0x60e210` |
| `358` (`0x166`) | `GNET::GMRestartServer` | `0x8e46c4` | `0x60d790` |
| `359` (`0x167`) | `GNET::GMRestartServer_Re` | `0x8e6294` | `0x60e900` |
| `360` (`0x168`) | `GNET::GMKickoutRole` | `0x8e4614` | `0x5f9f70` |
| `361` (`0x169`) | `GNET::GMKickoutRole_Re` | `0x8e61e4` | `0x60e070` |
| `362` (`0x16a`) | `GNET::GMShutupRole` | `0x8e46f0` | `0x5fa150` |
| `363` (`0x16b`) | `GNET::GMShutupRole_Re` | `0x8e623c` | `0x60e3b0` |
| `364` (`0x16c`) | `GNET::GMToggleChat` | `0x8e4774` | `0x5fa240` |
| `365` (`0x16d`) | `GNET::GMToggleChat_Re` | `0x8e6268` | `0x60e550` |
| `366` (`0x16e`) | `GNET::GMForbidRole` | `0x8e4748` | `0x5fa390` |
| `367` (`0x16f`) | `GNET::GMForbidRole_Re` | `0x8e62c0` | `0x60eaa0` |
| `368` (`0x170`) | `GNET::Report2GM` | `0x8e4510` | `0x5fa480` |
| `369` (`0x171`) | `GNET::Report2GM_Re` | `0x8e62ec` | `0x60ee40` |
| `370` (`0x172`) | `GNET::Complain2GM` | `0x8e453c` | `0x5fa590` |
| `371` (`0x173`) | `GNET::Complain2GM_Re` | `0x8e6318` | `0x60efe0` |
| `401` (`0x191`) | `GNET::StockCommission` | `0x8e492c` | `0x617cc0` |
| `405` (`0x195`) | `GNET::StockBill` | `0x8e4900` | `0x617e10` |
| `406` (`0x196`) | `GNET::StockBill_Re` | `0x8e68d0` | `0x618e90` |
| `407` (`0x197`) | `GNET::StockAccount` | `0x8e48d4` | `0x617f60` |
| `408` (`0x198`) | `GNET::StockAccount_Re` | `0x8e6878` | `0x6186e0` |
| `409` (`0x199`) | `GNET::StockCommission_Re` | `0x8e684c` | `0x6180b0` |
| `410` (`0x19a`) | `GNET::StockTransaction_Re` | `0x8e68a4` | `0x618cf0` |
| `411` (`0x19b`) | `GNET::StockCancel` | `0x8e4958` | `0x619590` |
| `412` (`0x19c`) | `GNET::StockCancel_Re` | `0x8e68fc` | `0x6193f0` |
| `507` (`0x1fb`) | `GNET::QueryUserPrivilege_Re` | `0x8e6344` | `0x60f180` |
| `551` (`0x227`) | `GNET::MatrixChallenge` | `0x8e6980` | `0x619be0` |
| `552` (`0x228`) | `GNET::MatrixResponse` | `0x8e5114` | `0x619d70` |
| `601` (`0x259`) | `GNET::SellPoint` | `0x8e5090` | `0x616270` |
| `602` (`0x25a`) | `GNET::SellPoint_Re` | `0x8e6728` | `0x616900` |
| `603` (`0x25b`) | `GNET::GetSellList` | `0x8e5038` | `0x616510` |
| `604` (`0x25c`) | `GNET::GetSellList_Re` | `0x8e6770` | `0x616f10` |
| `605` (`0x25d`) | `GNET::SellCancel` | `0x8e50bc` | `0x6167b0` |
| `606` (`0x25e`) | `GNET::SellCancel_Re` | `0x8e67f4` | `0x617980` |
| `607` (`0x25f`) | `GNET::BuyPoint` | `0x8e50e8` | `0x6163c0` |
| `608` (`0x260`) | `GNET::BuyPoint_Re` | `0x8e6820` | `0x617b20` |
| `610` (`0x262`) | `GNET::AnnounceSellResult` | `0x8e67c8` | `0x617590` |
| `619` (`0x26b`) | `GNET::FindSellPointInfo` | `0x8e5064` | `0x616660` |
| `620` (`0x26c`) | `GNET::FindSellPointInfo_Re` | `0x8e679c` | `0x617210` |
| `782` (`0x30e`) | `GNET::AutolockSet` | `0x8e5198` | `0x61a620` |
| `783` (`0x30f`) | `GNET::AutolockSet_Re` | `0x8e69d8` | `0x61a770` |
| `800` (`0x320`) | `GNET::AuctionOpen` | `0x8e4dd0` | `0x6111f0` |
| `801` (`0x321`) | `GNET::AuctionOpen_Re` | `0x8e64c0` | `0x611820` |
| `802` (`0x322`) | `GNET::AuctionBid` | `0x8e4dfc` | `0x6112e0` |
| `803` (`0x323`) | `GNET::AuctionBid_Re` | `0x8e64ec` | `0x611c70` |
| `804` (`0x324`) | `GNET::AuctionList` | `0x8e4e28` | `0x611430` |
| `805` (`0x325`) | `GNET::AuctionList_Re` | `0x8e6544` | `0x612290` |
| `806` (`0x326`) | `GNET::AuctionClose` | `0x8e4e54` | `0x611580` |
| `807` (`0x327`) | `GNET::AuctionClose_Re` | `0x8e6518` | `0x6120f0` |
| `808` (`0x328`) | `GNET::AuctionGet` | `0x8e4e80` | `0x6116d0` |
| `809` (`0x329`) | `GNET::AuctionGet_Re` | `0x8e6570` | `0x612850` |
| `816` (`0x330`) | `GNET::AuctionAttendList` | `0x8e4eac` | `0x613000` |
| `817` (`0x331`) | `GNET::AuctionAttendList_Re` | `0x8e659c` | `0x613150` |
| `818` (`0x332`) | `GNET::AuctionExitBid` | `0x8e4ed8` | `0x613650` |
| `819` (`0x333`) | `GNET::AuctionExitBid_Re` | `0x8e65c8` | `0x6137a0` |
| `820` (`0x334`) | `GNET::AuctionGetItem` | `0x8e4f04` | `0x615160` |
| `821` (`0x335`) | `GNET::AuctionGetItem_Re` | `0x8e66a4` | `0x615250` |
| `823` (`0x337`) | `GNET::AuctionListUpdate` | `0x8e4f30` | `0x61a910` |
| `824` (`0x338`) | `GNET::AuctionListUpdate_Re` | `0x8e6a04` | `0x61aa00` |
| `850` (`0x352`) | `GNET::BattleGetMap` | `0x8e4fb4` | `0x613ae0` |
| `851` (`0x353`) | `GNET::BattleGetMap_Re` | `0x8e6620` | `0x613ed0` |
| `852` (`0x354`) | `GNET::BattleChallenge` | `0x8e4f5c` | `0x613c30` |
| `853` (`0x355`) | `GNET::BattleChallenge_Re` | `0x8e664c` | `0x614520` |
| `854` (`0x356`) | `GNET::BattleChallengeMap` | `0x8e4f88` | `0x613d80` |
| `855` (`0x357`) | `GNET::BattleChallengeMap_Re` | `0x8e6678` | `0x614af0` |
| `860` (`0x35c`) | `GNET::BattleEnter` | `0x8e4fe0` | `0x615760` |
| `861` (`0x35d`) | `GNET::BattleEnter_Re` | `0x8e66d0` | `0x6158b0` |
| `866` (`0x362`) | `GNET::BattleStatus` | `0x8e500c` | `0x615c60` |
| `867` (`0x363`) | `GNET::BattleStatus_Re` | `0x8e66fc` | `0x615db0` |
| `4001` (`0xfa1`) | `GNET::TradeStart` | `0x8e47a0` | `0x60bea0` |
| `4002` (`0xfa2`) | `GNET::TradeStart_Re` | `0x8e5fe4` | `0x60bff0` |
| `4004` (`0xfa4`) | `GNET::TradeAddGoods` | `0x8e47cc` | `0x5f94f0` |
| `4005` (`0xfa5`) | `GNET::TradeAddGoods_Re` | `0x8e6010` | `0x60c190` |
| `4006` (`0xfa6`) | `GNET::TradeRemoveGoods` | `0x8e47f8` | `0x5f9610` |
| `4007` (`0xfa7`) | `GNET::TradeRemoveGoods_Re` | `0x8e603c` | `0x60c740` |
| `4008` (`0xfa8`) | `GNET::TradeMoveObj` | `0x8e4824` | `0x5f9880` |
| `4009` (`0xfa9`) | `GNET::TradeMoveObj_Re` | `0x8e6094` | `0x60cb30` |
| `4010` (`0xfaa`) | `GNET::TradeSubmit` | `0x8e4850` | `0x5f9730` |
| `4011` (`0xfab`) | `GNET::TradeSubmit_Re` | `0x8e6068` | `0x60c990` |
| `4012` (`0xfac`) | `GNET::TradeConfirm` | `0x8e487c` | `0x5f99a0` |
| `4013` (`0xfad`) | `GNET::TradeConfirm_Re` | `0x8e60c0` | `0x60d060` |
| `4014` (`0xfae`) | `GNET::TradeDiscard` | `0x8e48a8` | `0x5f9af0` |
| `4015` (`0xfaf`) | `GNET::TradeDiscard_Re` | `0x8e60ec` | `0x60d350` |
| `4016` (`0xfb0`) | `GNET::TradeEnd` | `0x8e6118` | `0x60d4f0` |
| `4200` (`0x1068`) | `GNET::CheckNewMail` | `0x8e4c9c` | `0x5fa7b0` |
| `4201` (`0x1069`) | `GNET::AnnounceNewMail` | `0x8e5588` | `0x5fa900` |
| `4202` (`0x106a`) | `GNET::GetMailList` | `0x8e4cc8` | `0x5faaa0` |
| `4203` (`0x106b`) | `GNET::GetMailList_Re` | `0x8e63b8` | `0x60f810` |
| `4204` (`0x106c`) | `GNET::GetMail` | `0x8e4cf4` | `0x5fabf0` |
| `4205` (`0x106d`) | `GNET::GetMail_Re` | `0x8e63e4` | `0x60fb30` |
| `4206` (`0x106e`) | `GNET::GetMailAttachObj` | `0x8e4d20` | `0x5fad40` |
| `4207` (`0x106f`) | `GNET::GetMailAttachObj_Re` | `0x8e6410` | `0x6103a0` |
| `4208` (`0x1070`) | `GNET::DeleteMail` | `0x8e4d4c` | `0x5fae30` |
| `4209` (`0x1071`) | `GNET::DeleteMail_Re` | `0x8e643c` | `0x610750` |
| `4210` (`0x1072`) | `GNET::PreserveMail` | `0x8e4d78` | `0x5faf80` |
| `4211` (`0x1073`) | `GNET::PreserveMail_Re` | `0x8e6468` | `0x6109f0` |
| `4212` (`0x1074`) | `GNET::PlayerSendMail` | `0x8e4da4` | `0x5fb0d0` |
| `4213` (`0x1075`) | `GNET::PlayerSendMail_Re` | `0x8e6494` | `0x610eb0` |
| `4260` (`0x10a4`) | `GNET::CashLock` | `0x8e5140` | `0x6196e0` |
| `4261` (`0x10a5`) | `GNET::CashLock_Re` | `0x8e6928` | `0x6198c0` |
| `4263` (`0x10a7`) | `GNET::CashPasswordSet` | `0x8e516c` | `0x6197d0` |
| `4264` (`0x10a8`) | `GNET::CashPasswordSet_Re` | `0x8e6954` | `0x619a50` |
| `4502` (`0x1196`) | `GNET::FactionCreate_Re` | `0x8e5ad4` | `0x6036f0` |
| `4503` (`0x1197`) | `GNET::FactionListMember_Re` | `0x8e5b2c` | `0x603f20` |
| `4504` (`0x1198`) | `GNET::FactionApplyJoin_Re` | `0x8e5b00` | `0x603d80` |
| `4505` (`0x1199`) | `GNET::FactionAcceptJoin_Re` | `0x8e5b74` | `0x604740` |
| `4506` (`0x119a`) | `GNET::FactionExpel_Re` | `0x8e5ba0` | `0x604f20` |
| `4507` (`0x119b`) | `GNET::FactionBroadcastNotice_Re` | `0x8e5bcc` | `0x6052e0` |
| `4508` (`0x119c`) | `GNET::FactionChangProclaim_Re` | `0x8e5c7c` | `0x6061e0` |
| `4509` (`0x119d`) | `GNET::FactionMasterResign_Re` | `0x8e5bf8` | `0x605740` |
| `4510` (`0x119e`) | `GNET::FactionAppoint_Re` | `0x8e5c24` | `0x6058e0` |
| `4511` (`0x119f`) | `GNET::FactionResign_Re` | `0x8e5c50` | `0x605e30` |
| `4512` (`0x11a0`) | `GNET::FactionLeave_Re` | `0x8e5ca8` | `0x606670` |
| `4513` (`0x11a1`) | `GNET::FactionUpgrade_Re` | `0x8e5d2c` | `0x607220` |
| `4514` (`0x11a2`) | `GNET::FactionDegrade_Re` | `0x8e5d58` | `0x6073c0` |
| `4515` (`0x11a3`) | `GNET::FactionDismiss_Re` | `0x8e5cd4` | `0x606970` |
| `4516` (`0x11a4`) | `GNET::FactionRename_Re` | `0x8e5d00` | `0x606b10` |
| `4803` (`0x12c3`) | `GNET::FactionChat` | `0x8e4a8c` | `0x603460` |
| `4804` (`0x12c4`) | `GNET::FactionOPRequest` | `0x8e4ab8` | `0x5e5bc0` |
| `4805` (`0x12c5`) | `GNET::FactionOPRequest_Re` | `0x8e5aa8` | `0x603550` |
| `4812` (`0x12cc`) | `GNET::FactionAcceptJoin` | `0x8e4ae4` | `0x5f7c50` |
| `4814` (`0x12ce`) | `GNET::GetFactionBaseInfo` | `0x8e43b0` | `0x5f7da0` |
| `4815` (`0x12cf`) | `GNET::GetFactionBaseInfo_Re` | `0x8e54f8` | `0x5f7e90` |
| `4816` (`0x12d0`) | `GNET::GetPlayerFactionInfo` | `0x8e4b10` | `0x5f86d0` |
| `4817` (`0x12d1`) | `GNET::GetPlayerFactionInfo_Re` | `0x8e5540` | `0x5f8820` |
| `4904` (`0x1328`) | `GNET::RefListReferrals` | `0x8e51f0` | `0x61b220` |
| `4905` (`0x1329`) | `GNET::RefListReferrals_Re` | `0x8e6a5c` | `0x61b370` |
| `4906` (`0x132a`) | `GNET::RefWithdrawBonus` | `0x8e521c` | `0x61af30` |
| `4907` (`0x132b`) | `GNET::RefWithdrawBonus_Re` | `0x8e6a30` | `0x61b080` |
| `4908` (`0x132c`) | `GNET::RefGetReferenceCode` | `0x8e51c4` | `0x61ba40` |
| `4909` (`0x132d`) | `GNET::RefGetReferenceCode_Re` | `0x8e6a88` | `0x61bb90` |
| `4952` (`0x1358`) | `GNET::GetRewardList` | `0x8e5248` | `0x61c060` |
| `4953` (`0x1359`) | `GNET::GetRewardList_Re` | `0x8e6ab4` | `0x61c1b0` |
| `4954` (`0x135a`) | `GNET::ExchangeConsumePoints` | `0x8e5274` | `0x61c800` |
| `4955` (`0x135b`) | `GNET::ExchangeConsumePoints_Re` | `0x8e6afc` | `0x61c950` |
| `4956` (`0x135c`) | `GNET::RewardMatureNotice` | `0x8e6b28` | `0x61cd20` |
| `5001` (`0x1389`) | `GNET::ACReport` | `0x8d6c80` | `0x5fa6c0` |
| `5003` (`0x138b`) | `GNET::ACRemoteCode` | `0x8e6370` | `0x60f460` |
| `5031` (`0x13a7`) | `GNET::ACQuestion` | `0x8e69ac` | `0x61a010` |
| `5032` (`0x13a8`) | `GNET::ACAnswer` | `0x8e4184` | `0x619ec0` |
| `4294967295` (`0xffffffff`) | `UnknownGNET_0x8edf24` | `0x8edf24` | `0x723250` |
