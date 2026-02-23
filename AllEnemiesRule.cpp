#include "AllEnemiesRule.hpp"
#include "Battle.hpp"

// =========================
// AllEnemiesRule – Implementation
// =========================

std::vector<CharPtr> AllEnemiesRule::validTargets(const CharPtr& actor, Battle& battle) const {
    return battle.enemiesOf(actor);
}

bool AllEnemiesRule::canTargetEnemies() const {
    return true;
}
