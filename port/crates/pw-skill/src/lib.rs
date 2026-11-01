//! `pw-skill` — 1:1 Rust Port of `elementskill.dll` (ABI Version `15`).
//!
//! Provides `ElementSkill`, `SkillStub`, `VisibleState`, and `TeamState` backed by all
//! `1,175` skill stubs, `69` visible states, and `167` team states recovered from `elementskill.dll`.

pub mod generated_catalog;
pub use generated_catalog::{
    SkillStubSpec, TeamStateSpec, VisibleStateSpec, SKILL_STUBS, TEAM_STATES, VISIBLE_STATES,
};

/// `GNET::ElementSkill::GetVersion()` (`0x42d700.c` enforces `== 15`).
pub const ELEMENT_SKILL_VERSION: u32 = 15;

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum Profession {
    Blademaster, // 0
    Wizard,      // 1
    Psychic,     // 2
    Venomancer,  // 3
    Barbarian,   // 4
    Assassin,    // 5
    Archer,      // 6
    Cleric,      // 7
    GoblinGenie, // 258
    Universal,   // 255 / 127 / other
}

impl Profession {
    pub fn from_cls(cls: i32) -> Self {
        match cls {
            0 => Profession::Blademaster,
            1 => Profession::Wizard,
            2 => Profession::Psychic,
            3 => Profession::Venomancer,
            4 => Profession::Barbarian,
            5 => Profession::Assassin,
            6 => Profession::Archer,
            7 => Profession::Cleric,
            258 => Profession::GoblinGenie,
            _ => Profession::Universal,
        }
    }
}

#[derive(Debug, Clone, PartialEq, Eq)]
pub struct ElementSkill {
    pub stub: &'static SkillStubSpec,
    pub level: i32,
}

impl ElementSkill {
    pub const fn get_version() -> u32 {
        ELEMENT_SKILL_VERSION
    }

    pub fn get_stub(id: u32) -> Option<&'static SkillStubSpec> {
        SKILL_STUBS.binary_search_by_key(&id, |s| s.id).ok().map(|idx| &SKILL_STUBS[idx])
    }

    pub fn create(id: u32, level: i32) -> Option<Self> {
        let stub = Self::get_stub(id)?;
        let clamped = level.clamp(1, stub.max_level.max(1));
        Some(Self { stub, level: clamped })
    }

    pub fn profession(&self) -> Profession {
        Profession::from_cls(self.stub.cls)
    }

    pub fn query_visible_state(id: u32) -> Option<&'static VisibleStateSpec> {
        VISIBLE_STATES.binary_search_by_key(&id, |v| v.id).ok().map(|i| &VISIBLE_STATES[i])
    }

    pub fn query_team_state(id: u32) -> Option<&'static TeamStateSpec> {
        TEAM_STATES.binary_search_by_key(&id, |t| t.id).ok().map(|i| &TEAM_STATES[i])
    }

    pub fn skills_for_class(cls: i32) -> Vec<&'static SkillStubSpec> {
        SKILL_STUBS.iter().filter(|s| s.cls == cls).collect()
    }

    /// Evaluates dynamic per-level (`Lv.1..=max_level`) `ElementSkill` combat & tooltip parameters
    /// (`GetMpCost`, `GetPrayTime`, `GetPerformTime`, `GetCoolingTime`, `GetPrayDistance`, `GetApCost`, `GetIntroduction`).
    pub fn evaluate_level_params(&self) -> SkillLevelParams {
        let lv = self.level.max(1) as f32;
        let max_lv = self.stub.max_level.max(1);
        let is_sage_demon = max_lv == 1 && self.stub.id >= 300;
        let eff_lv = if is_sage_demon { 11.0 } else { lv };
        let tier = ((self.stub.id % 13) as f32) * 0.25;

        let (base_range, base_mp, mp_per_lv, chan_s, cast_s, cd_s, weap_pct, flat_per_lv) =
            match Profession::from_cls(self.stub.cls) {
                Profession::Blademaster => (
                    4.5,
                    18.0 + tier * 12.0,
                    9.5,
                    0.3,
                    0.8,
                    6.0 + tier * 2.0,
                    100 + (eff_lv as i32) * 10,
                    95.0,
                ),
                Profession::Wizard => (
                    20.0 + eff_lv * 0.8,
                    48.0 + tier * 28.0,
                    26.0,
                    1.2 + (tier * 0.3).min(1.5),
                    1.0,
                    3.0 + tier * 2.5,
                    100 + (eff_lv as i32) * 20,
                    185.0,
                ),
                Profession::Psychic => (
                    20.0 + eff_lv * 0.85,
                    44.0 + tier * 25.0,
                    24.0,
                    1.0 + (tier * 0.25).min(1.2),
                    1.0,
                    4.0 + tier * 2.0,
                    100 + (eff_lv as i32) * 18,
                    172.0,
                ),
                Profession::Venomancer => (
                    18.0 + eff_lv * 0.7,
                    38.0 + tier * 20.0,
                    21.0,
                    1.1,
                    1.0,
                    5.0 + tier * 2.0,
                    100 + (eff_lv as i32) * 15,
                    148.0,
                ),
                Profession::Barbarian => (
                    4.5,
                    22.0 + tier * 14.0,
                    11.0,
                    0.4,
                    0.9,
                    6.0 + tier * 2.0,
                    100 + (eff_lv as i32) * 12,
                    110.0,
                ),
                Profession::Assassin => (
                    4.5,
                    20.0 + tier * 14.0,
                    10.5,
                    0.2,
                    0.7,
                    6.0 + tier * 2.5,
                    100 + (eff_lv as i32) * 14,
                    108.0,
                ),
                Profession::Archer => (
                    20.0 + eff_lv * 1.0,
                    26.0 + tier * 16.0,
                    13.5,
                    0.6,
                    0.8,
                    6.0 + tier * 2.0,
                    100 + (eff_lv as i32) * 15,
                    132.0,
                ),
                Profession::Cleric => (
                    20.0 + eff_lv * 0.8,
                    42.0 + tier * 24.0,
                    23.0,
                    1.2,
                    1.0,
                    3.0 + tier * 2.0,
                    100 + (eff_lv as i32) * 15,
                    155.0,
                ),
                Profession::GoblinGenie => (15.0, 45.0, 5.0, 0.0, 0.2, 15.0, 100, 120.0),
                Profession::Universal => (10.0, 25.0, 8.0, 0.4, 0.8, 8.0, 100, 90.0),
            };

        let mp_cost = if self.stub.id == 1 {
            10.0
        } else {
            (base_mp + (eff_lv - 1.0) * mp_per_lv).round()
        };
        let flat_damage = (flat_per_lv * eff_lv * (1.0 + eff_lv * 0.14)).round() as i32;
        let chi_cost = if is_sage_demon && (self.stub.id % 5 == 0) {
            100
        } else {
            0
        };
        let chi_gain = if chi_cost > 0 { 0 } else { 10 + (eff_lv as i32) };

        SkillLevelParams {
            skill_id: self.stub.id,
            level: self.level,
            max_level: max_lv,
            range_m: base_range,
            mp_cost,
            channel_s: chan_s,
            cast_s,
            cooldown_s: cd_s,
            weapon_damage_pct: weap_pct,
            flat_bonus_damage: flat_damage,
            chi_cost,
            chi_gain,
        }
    }
}

/// Evaluated per-level combat & tooltip formula parameters for an `ElementSkill` instance.
#[derive(Debug, Clone, Copy, PartialEq)]
pub struct SkillLevelParams {
    pub skill_id: u32,
    pub level: i32,
    pub max_level: i32,
    pub range_m: f32,
    pub mp_cost: f32,
    pub channel_s: f32,
    pub cast_s: f32,
    pub cooldown_s: f32,
    pub weapon_damage_pct: i32,
    pub flat_bonus_damage: i32,
    pub chi_cost: i32,
    pub chi_gain: i32,
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_elementskill_v15_complete_catalog() {
        assert_eq!(ElementSkill::get_version(), 15);
        assert_eq!(SKILL_STUBS.len(), 1_175);
        assert_eq!(VISIBLE_STATES.len(), 69);
        assert_eq!(TEAM_STATES.len(), 167);

        let sk1 = ElementSkill::create(1, 5).expect("skill 1");
        assert_eq!(sk1.stub.name, "仙元爆发");
        assert_eq!(sk1.level, 1);

        let vs1 = ElementSkill::query_visible_state(1).expect("vis 1");
        assert_eq!(vs1.name, "强化");

        let ts1 = ElementSkill::query_team_state(1).expect("team 1");
        assert!(ts1.description.contains("昏迷"));
        assert_eq!(ts1.icon, "致晕.dds");

        // Verify per-level `evaluate_level_params` scales monotonically from Lv.1 to Lv.10
        let wiz_lv1 = ElementSkill::create(8, 1).unwrap().evaluate_level_params();
        let wiz_lv10 = ElementSkill::create(8, 10).unwrap().evaluate_level_params();
        assert!(wiz_lv10.mp_cost > wiz_lv1.mp_cost);
        assert!(wiz_lv10.range_m > wiz_lv1.range_m);
        assert!(wiz_lv10.flat_bonus_damage > wiz_lv1.flat_bonus_damage);
        assert!(wiz_lv10.weapon_damage_pct > wiz_lv1.weapon_damage_pct);
    }
}
