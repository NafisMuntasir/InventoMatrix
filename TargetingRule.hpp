#ifndef TARGETINGRULE_H
#define TARGETINGRULE_H
#include "Battle.h"
#include "Character.h"
#include "Party.h"
class TargetingRule{
    public:
    TargetingRule()=default;
    virtual ~TargetingRule()=default;

    virtual void applyRule(Battle& battle, Character& actor, Party& target);
    virtual bool validateTarget(const Party& target)const;
};

#endif
