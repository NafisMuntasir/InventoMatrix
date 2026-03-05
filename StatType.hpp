#pragma once

// StatType: Identifies which stat is being referenced or modified.
// Used by: StatBlock (getStat/setStat), StatModifier (member type),
//          Character (getFinalStat, getModifiedAttack, getModifiedDefense),
//          OverencumberedStatus (modifiers returns StatModifier with StatType::Speed)
// Dependency on other classes: NONE - pure enum, no includes required.

enum class StatType {
    MaxHP,
    Attack,
    Defense,
    Speed,
    Accuracy,
    Evasion,
    Crit
};