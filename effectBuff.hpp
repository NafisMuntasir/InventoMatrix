#ifndef EFFECTBUFF_HPP
#define EFFECTBUFF_HPP
#include "Battle.hpp"
#include "Character.hpp"
#include <string>
enum class StatusTiming{
    onStart,
    onEnd,
    Continuous,
    Immediate
};
class EffectBuff {
    std::string statusName;
    int statusDuration;
    StatusTiming statusTiming;

public:
    EffectBuff(const std::string& name, int duration, StatusTiming timing);
    std::string getName() const;
    int getDuration()const;
    StatusTiming getStatusTiming() const;
    void tickDown();
    bool isExpired()const;
    void applyEffect(Battle& battle, Character& source, Character& target);
};

#endif
