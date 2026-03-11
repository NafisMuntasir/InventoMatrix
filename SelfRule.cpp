#include "SelfRule.hpp"
#include "Character.hpp"

std::vector<CharPtr> SelfRule::validTargets(const CharPtr& actor, Battle& battle) const 
{
    std::vector<CharPtr> targets;

    if(actor && actor->isAlive())
        targets.push_back(actor);

    return targets;
}

bool SelfRule::canTargetAllies() const
{
    return true;
}

bool SelfRule::canTargetEnemies() const
{
    return false;
}
