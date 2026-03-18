#include "TargetingRule.h"

// Same logic moved from inline → cpp

bool TargetingRule::canTargetAllies() const {
    return false;
}

bool TargetingRule::canTargetEnemies() const {
    return true;
}
