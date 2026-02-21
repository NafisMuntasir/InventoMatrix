#ifndef BUFF_HPP
#define BUFF_HPP
#include<string>
#include<iostream>
using namespace std;
enum class TickTiming{
    OnTurnStart,
    OnTurnEnd,
    Immediate
};
class Character;
class Battle;
class Buff{
    string statusName;
    int statusDuration;
    TickTiming timing;
    public:
    Buff(const string *name,int duration,TickTiming timing);
    string getName()const;
    int getStatusDuration()const;
    TickTiming getTiming()const;
    void decrementDuration();
    bool isExpired()const;
    void applyEffect(Battle& battle,Character& character);
};
#endif
