#pragma once

// DamageType: Classifies the nature of damage dealt in combat.
// Used by: DamageEffect (stores dmgType as a member),
//          BattleRules (computeDamage receives DamageType as a parameter),
//          BasicAttackAction (execute passes DamageType::Physical to computeDamage)
// Dependency on other classes: NONE - pure enum, no includes required.

enum class DamageType {
    Physical,
    Magical,
    True
};