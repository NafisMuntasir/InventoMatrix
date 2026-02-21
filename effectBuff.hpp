#ifndef EFFECTBUFF_HPP
#define EFFECTBUFF_HPP
#include<Battle.hpp>
#include<Character.hpp>
#include<string>
using namespace std;
enum class StatusTiming{
    onStart,
    onEnd,
    Continuous,
    Immediate
};
class EffectBuff{
    string statusName;
    int statusDuration;
    StatusTiming statusTiming;
public:
EffectBuff(const string &name,int duration,StatusTiming Timing);
    string getName()const;
    int getDuration()const;
    StatusTiming getStatusTiming() const;
    void tickDown();
    bool isExpired()const;
    void applyEffect(Battle &battle,Character source,Character &target);

};
