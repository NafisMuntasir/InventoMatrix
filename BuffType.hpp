#pragma once

// BuffType: Categorises what aspect of a character a Buff affects.
// Used by: Buff (stores type as a member, getType() returns it),
//          Character (getModifiedAttack checks BuffType::AttackBuff,
//                     getModifiedDefense checks BuffType::DefenseBuff)
// Dependency on other classes: NONE - pure enum, no includes required.

enum class BuffType {
    AttackBuff,
    DefenseBuff,
    Nerf
};