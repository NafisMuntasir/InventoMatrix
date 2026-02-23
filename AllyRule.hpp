#pragma once

// =========================
// AllyRule
// =========================
// TargetingRule that returns all living allies of the
// acting character (excluding the actor themselves).
// Used for support skills such as healing or buffing.

#include "TargetingRule.hpp"

class AllyRule : public TargetingRule {
public:
    // Virtual Methods (polymorphism)
    std::vector<CharPtr> validTargets(const CharPtr& actor, Battle& battle) const override;
    bool canTargetAllies() const override;
};
