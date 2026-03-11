#ifndef SELFRULE_H
#define SELFRULE_H

#include "TargetingRule.hpp"

class SelfRule : public TargetingRule
{
public:
    std::vector<CharPtr> validTargets(const CharPtr& actor, Battle& battle) const override;

    bool canTargetAllies() const override;

    bool canTargetEnemies() const override;
};

#endif
