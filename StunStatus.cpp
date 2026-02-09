#include "StunStatus.hpp"

StunStatus::StunStatus(int duration)
    : StatusEffect("Stun", duration, TickTiming::TurnStart) {}

bool StunStatus::blocksAction() const {
    return true;
}

bool StunStatus::isDebuff() const {
    return true;
}
