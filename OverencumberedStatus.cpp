#include "OverencumberedStatus.hpp"

OverencumberedStatus::OverencumberedStatus(int duration, int speedPenalty)
    : StatusEffect("Overencumbered", duration, TickTiming::TurnStart), 
      speedReduction(speedPenalty) {}

std::vector<StatModifier> OverencumberedStatus::modifiers() const {
    return {StatModifier(StatType::Speed, -speedReduction, 1.0f)};
}

bool OverencumberedStatus::isDebuff() const {
    return true;
}

int OverencumberedStatus::getSpeedReduction() const {
    return speedReduction;
}
