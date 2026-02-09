#include "StatusEffect.hpp"
#include <algorithm>

StatusEffect::StatusEffect(std::string statusName, int statusDuration, TickTiming statusTiming)
    : name(std::move(statusName)), duration(statusDuration), timing(statusTiming) {}

void StatusEffect::onApply(Battle& battle, const std::shared_ptr<Character>& target) {
    (void)battle;
    (void)target;
}

void StatusEffect::onExpire(Battle& battle, const std::shared_ptr<Character>& target) {
    (void)battle;
    (void)target;
}

void StatusEffect::onTick(Battle& battle, const std::shared_ptr<Character>& target) {
    (void)battle;
    (void)target;
}

bool StatusEffect::blocksAction() const {
    return false;
}

std::vector<StatModifier> StatusEffect::modifiers() const {
    return {};
}

const std::string& StatusEffect::getName() const {
    return name;
}

TickTiming StatusEffect::getTiming() const {
    return timing;
}

int StatusEffect::getDuration() const {
    return duration;
}

void StatusEffect::setDuration(int dur) {
    duration = std::max(0, dur);
}

void StatusEffect::decrement() {
    duration = std::max(0, duration - 1);
}

bool StatusEffect::expired() const {
    return duration <= 0;
}

bool StatusEffect::isDebuff() const {
    return true;
}

bool StatusEffect::isBuff() const {
    return false;
}
