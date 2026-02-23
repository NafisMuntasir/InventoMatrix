#include "SingleEnemyRule.hpp"
#include "Battle.hpp"

// =========================
// SingleEnemyRule – Implementation
// =========================

std::vector<CharPtr> SingleEnemyRule::validTargets(const CharPtr& actor, Battle& battle) const {
    return battle.enemiesOf(actor);
}

bool SingleEnemyRule::canTargetEnemies() const {
    return true;
}
