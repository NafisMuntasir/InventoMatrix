#ifndef TARGETINGRULE_H
#define TARGETINGRULE_H
#include "Battle.hpp"
#include "Character.hpp"
#include "Party.hpp"
class TargetingRule{
    public:
    TargetingRule()=default;
    virtual ~TargetingRule()=default;

    virtual void applyRule(Battle& battle, Character& actor, Party& target);
    virtual bool validateTargets(const Party& target)const;
};

#endif
