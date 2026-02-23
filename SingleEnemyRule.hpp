#pragma once

// =========================
// SingleEnemyRule
// =========================
// TargetingRule that selects all living enemies of the
// acting character. The skill user then picks one target
// from the returned list (or the engine auto-selects).

#include "TargetingRule.hpp"

class SingleEnemyRule : public TargetingRule {
public:
    // Virtual Methods (polymorphism)
    std::vector<CharPtr> validTargets(const CharPtr& actor, Battle& battle) const override;
    bool canTargetEnemies() const override;
};
