#include "TargetingRule.h"
void TargetingRule::applyRule(Battle& battle, Character& actor, Party& target){
    if(validateTarget(target)){
        battle.executeAction(actor,target);
    }
}

bool TargetingRule::validateTarget(const Party& target)const{
    return !target.isEmpty();
}
