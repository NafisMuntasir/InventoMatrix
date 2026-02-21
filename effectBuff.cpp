#include<effectBuff.hpp>
effectBuff::effectBuff(const string &name,int duration,StatusTiming Timing)
    :statusName(name),statusDuration(duration),statusTiming(Timing){}

string effectBuff::getName()const{
    return statusName;
}

int effectBuff::getDuration()const{
    return statusDuration;
}

StatusTiming effectBuff::getStatusTiming()const{
    return statusTiming;
}

void effectBuff::tickDown(){
    if(statusDuration>0){
        statusDuration--;
    }
}

bool effectBuff::isExpired()const{
    return statusDuration<=0;
}

void effectBuff::applyEffect(Battle &battle,Character source,Character &target){
    if(statusTiming==StatusTiming::Immediate){
        battle.applyStatusEffect(statusName,source,target);
    }
    else if(statusTiming==StatusTiming::Continuous){
        battle.applyStatusEffect(statusName,source,target);
    }
    else if(statusTiming==StatusTiming::onStart){
        if(battle.isTurnStart()){
            battle.applyStatusEffect(statusName,source,target);
        }
    }
    else if(statusTiming==StatusTiming::onEnd){
        if(battle.isTurnEnd()){
            battle.applyStatusEffect(statusName,source,target);
        }
    }
}
