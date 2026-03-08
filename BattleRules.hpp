#pragma once

// =========================
// BattleRules
// =========================
// Encapsulates the core combat formulas used during battle:
// hit-chance calculation, damage computation, and critical-hit
// rolls. Designed to be sub-classed for custom rule sets.

#include "Types.hpp"
#include "StatType.hpp"
#include "DamageType.hpp"
#include <algorithm>
#include <cstdlib>

class BattleRules {
private:
    int minHitChance;
    int maxHitChance;

public:
    // Constructor
    BattleRules();

    virtual ~BattleRules() = default;

    // Getters
    int getMinHitChance() const;
    int getMaxHitChance() const;

    // Setters
    void setMinHitChance(int chance);
    void setMaxHitChance(int chance);

    // Virtual Methods (override to customise combat rules)
    virtual bool rollHit(const CharPtr& actor, const CharPtr& target) const;
    virtual int  computeDamage(const CharPtr& actor, const CharPtr& target,
                               int base, DamageType type) const;
    virtual bool rollCrit(const CharPtr& actor) const;
};
