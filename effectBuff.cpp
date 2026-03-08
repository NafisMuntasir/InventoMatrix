#include "effectBuff.hpp"
#include <iostream>

EffectBuff::EffectBuff(const std::string& name, int duration, StatusTiming timing)
    : statusName(name), statusDuration(duration), statusTiming(timing) {}

std::string EffectBuff::getName() const {
    return statusName;
}

int EffectBuff::getDuration() const {
    return statusDuration;
}

StatusTiming EffectBuff::getStatusTiming() const {
    return statusTiming;
}

void EffectBuff::tickDown() {
    if (statusDuration > 0) {
        statusDuration--;
    }
}

bool EffectBuff::isExpired() const {
    return statusDuration <= 0;
}

void EffectBuff::applyEffect(Battle& battle, Character& source, Character& target) {
    // Legacy effect buff logic. This method currently only logs the intent.
    std::cout << "EffectBuff applied: " << statusName << " to " << target.getName() << std::endl;
}
