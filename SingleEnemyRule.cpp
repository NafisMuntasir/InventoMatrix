#include "SingleEnemyRule.hpp"
#include "Battle.hpp"

// =========================
// SingleEnemyRule – Implementation
// =========================

std::vector<CharPtr> SingleEnemyRule::validTargets(const CharPtr& actor, Battle& battle) const {
    auto enemies = battle.enemiesOf(actor);
    if (!enemies.empty()) {
        // Return a single candidate target (first alive enemy).
        return {enemies.front()};
    }
    return {};
}

bool SingleEnemyRule::canTargetEnemies() const {
    return true;
}
