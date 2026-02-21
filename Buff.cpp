#include "Buff.hpp"
#include "Character.hpp"
#include "Battle.hpp"
Buff::Buff(const string *name,int duration,TickTiming timing):statusName(*name),statusDuration(duration),timing(timing){}
string Buff::getName()const{
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
    cout<<"Applying Buff:"<<statusName<<" to "<<target.getName()<<endl;
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


