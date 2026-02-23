#pragma once

// =========================
// AllEnemiesRule
// =========================
// TargetingRule that returns every living enemy of the
// acting character. Used for area-of-effect skills that
// hit the entire opposing party simultaneously.

#include "TargetingRule.hpp"

class AllEnemiesRule : public TargetingRule {
public:
    // Virtual Methods (polymorphism)
    std::vector<CharPtr> validTargets(const CharPtr& actor, Battle& battle) const override;
    bool canTargetEnemies() const override;
};
