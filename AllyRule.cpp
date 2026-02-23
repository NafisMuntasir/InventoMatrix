#include "AllyRule.hpp"
#include "Battle.hpp"

// =========================
// AllyRule – Implementation
// =========================

std::vector<CharPtr> AllyRule::validTargets(const CharPtr& actor, Battle& battle) const {
    return battle.alliesOf(actor);
}

bool AllyRule::canTargetAllies() const {
    return true;
}
