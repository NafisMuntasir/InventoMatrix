#include "Buff.hpp"
#include "Character.hpp"
#include "Battle.hpp"

#include <iostream>
#include <string>

Buff::Buff(const std::string* name, int duration, TickTiming timing)
    : statusName(name ? *name : std::string()), statusDuration(duration), timing(timing) {}

std::string Buff::getName() const {
    return statusName;
}
int Buff::getStatusDuration()const{
    return statusDuration;
}
TickTiming Buff::getTiming()const{
    return timing;
}
void Buff::decrementDuration(){
    if(statusDuration>0){
        statusDuration--;
    }
}
bool Buff::isExpired()const{
    return statusDuration<=0;
}
void Buff::applyEffect(Battle &battle,Character &actor,Character &target){
    std::cout << "Applying Buff:" << statusName << " to " << target.getName() << std::endl;
    if(statusName=="Poison"){
        if(statusName=="Poison"){
            target.takeDamage(5);
        }
        else if(statusName=="StrengthUp"){
            target.increaseAttack(10);
        }
        decrementDuration();
    }
}
