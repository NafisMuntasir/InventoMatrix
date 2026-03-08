#ifndef SELFRULE_H
#define SELFRULE_H

#include "TargetingRule.h"

class SelfRule : public TargetingRule
{
public:
    std::vector<CharPtr> validTargets(CharPtr actor, Battle& battle) override;

    bool canTargetAllies() override;

    bool canTargetEnemies() override;
};

#endif
