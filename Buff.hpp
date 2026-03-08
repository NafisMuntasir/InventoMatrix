#ifndef BUFF_HPP
#define BUFF_HPP

#include <string>
#include <iostream>

#include "StatusEffect.hpp"

class Character;
class Battle;

class Buff {
    std::string statusName;
    int statusDuration;
    TickTiming timing;

public:
    Buff(const std::string* name, int duration, TickTiming timing);

    std::string getName() const;
    int getStatusDuration() const;
    TickTiming getTiming() const;

    void decrementDuration();
    bool isExpired() const;
    void applyEffect(Battle& battle, Character& character, Character& target);
};

#endif
