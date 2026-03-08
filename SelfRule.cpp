#include "SelfRule.h"

std::vector<CharPtr> SelfRule::validTargets(CharPtr actor, Battle& battle)
{
    std::vector<CharPtr> targets;

    if (actor && actor->isAlive())
    {
        targets.push_back(actor);
    }

    return targets;
}

bool SelfRule::canTargetAllies()
{
    return true;
}

bool SelfRule::canTargetEnemies()
{
    return false;
}
