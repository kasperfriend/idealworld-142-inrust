/*
 * Decompiled & Annotated Reconstruction: CECFace::Init & Player Avatar / Target Portrait Pipeline
 * Binary: elementclient.exe (Perfect World 1.4.2 Build 2305, Rising Tide / Tideborn)
 * Virtual Address Range: 0x00559250 .. 0x005593F5 (CECFace::Init), 0x0079A330 (A3DSkySphere)
 *
 * Key Reverse-Engineered Findings Ported 1:1 into `pw-render-audio` & `pw-data`:
 * 1. Base Face Rig (`models.pck`, attached to body rig via `CC_Neck <-> HH_Neck` rigid inverse):
 *    - Human / Winged Elf standard faces:
 *      `models\face\{武侠男,法师女,羽芒男,羽芒女,羽灵男,羽灵女}标准脸\*标准脸.{bon,ski}`
 *    - Tideborn (`cls = 2` Psychic, `cls = 5` Assassin) numbered face variants (`1..5`):
 *      `models\face\{巫师男,巫师女,刺客男,刺客女}标准脸\*标准脸{1..5}.{bon,ski}`
 *      (Note: `models\players\形象\刺客女\女刺客.ski` is an untextured rig test stub and is NEVER loaded
 *       by `CECPlayer` — real player rigs ALWAYS load `躯干\{folder}.{smd,ski}` + 4-piece default armor
 *       `装备\{男,女}\默认{上衣,护腕,裤子,靴子}\{equip_prefix}默认*一级.ski`, where `cls = 4` Untamed Barbarian
 *       uses `equip_prefix = "妖兽"`, NOT `"妖兽男"`!)
 *    - Untamed Venomancer (`cls = 3`, female-only) & Barbarian (`cls = 4`, male-only):
 *      `models\face\妖精标准脸{1..6}\*.{bon,ski}` and `models\face\妖兽男标准脸{1..4}\*.{bon,ski}`
 *
 * 2. 3D Hair Meshes (`facedata.pck`):
 *    - `facedata\{男,女,影族男,影族女}\头发模型库\*头发*.ski` skinned directly onto the `*标准脸*.bon` skeleton.
 *    - Lookup driven by `userdata\character\character{cls}{gender}.ini` (`00..71`):
 *      - `idFaceTex`, `idEyeBaseTex`, `idEyeHighTex`, `idEyeBallTex`, `idBrowTex`, `idNoseTex`,
 *        `idMouthTex`, `idMoustacheTex` -> `elements.data` Section 60 (`FACE_TEXTURE_ESSENCE`, 476 B)
 *      - `idHairModel`, `idHairTex`, `idMoustacheSkin` -> `elements.data` Section 64 (`FACE_HAIR_ESSENCE`, 468 B)
 *      - `colorFace`, `colorHair`, `colorEye`, `colorBrow`, `colorMouth`, `colorEyeBall`, `colorBody`
 *
 * 3. Angelica 2.2 Face Pixel Shaders (`shaders.pck\shaders\ps\facerender\*.txt`):
 *    - `facerender.txt` / `noserender.txt`:
 *        `out.rgb = tex0.rgb * colFace.rgb`
 *    - `browrender.txt` / `eyerender.txt` / `moustacherender.txt`:
 *        `out.rgb = lerp(tex0.rgb * colFace.rgb, tex1.rgb * colFeat.rgb, tex1.a)`
 *    - `mouthrender.txt` / `eyeballrender.txt`:
 *        `base = lerp(tex0.rgb * colFace.rgb, tex1.rgb * colFeat.rgb, tex1.a)`
 *        `out.rgb = lerp(base, tex2.rgb, tex2.a)` (specular lip/cornea highlight layer)
 *    - `furrender.txt` (Untamed Barbarian fur / tiger stripes, `character40.ini` `idFaceTex = 100` `虎.DDS`):
 *        `out.rgb = lerp(tex0.rgb * colFace.rgb, tex1.rgb, tex1.a)`
 *    - `hairrender.txt`:
 *        `out.rgb = tex0.rgb * colHair.rgb + pow(tex0.rgb * v1.rgb, 2) * tex1.a`
 *
 * 4. HUD Portrait & Target Frame Dispatch (`CECGameUIMan` + `interfaces.pck`):
 *    - Player Portrait: `Win_Hpmpxp::Size` (`12, 13, 64, 64`), circular-masked 3D headshot aimed at
 *      `Bip01 Head` world bone position (`tm_abs[head_bi] * actor_world`).
 *    - NPC / Player Target: `Win_HpmpOther::Size` (`14, 12, 64, 64`) + `Image_Prof` (`Profession.tga`).
 *    - Monster Target: `Win_HpOther` (`hpother.dtf`, `248x73`, `人鱼传说新界面\目标怪物2.dds`) with
 *      `Txt_Name`, `Txt_Att` (`MONSTER_ESSENCE` Section 39 `1528 B` `short_desc` elemental affinity),
 *      and `Prgs_HP` (`48, 5, 150, 10`).
 */

#include <stdint.h>

typedef struct CECFaceCustomizeData {
    uint32_t idFaceTex;
    uint32_t idEyeBaseTex;
    uint32_t idEyeHighTex;
    uint32_t idEyeBallTex;
    uint32_t idBrowTex;
    uint32_t idNoseTex;
    uint32_t idMouthTex;
    uint32_t idHairModel;
    uint32_t idHairTex;
    uint32_t idMoustacheTex;
    uint32_t idMoustacheSkin;
    uint32_t bodyID;
    uint32_t colorFace;
    uint32_t colorHair;
    uint32_t colorEye;
    uint32_t colorBrow;
    uint32_t colorMouth;
    uint32_t colorEyeBall;
    uint32_t colorMoustache;
    uint32_t colorBody;
} CECFaceCustomizeData;
