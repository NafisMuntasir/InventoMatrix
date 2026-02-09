#include "PoisonStatus.hpp"
#include "Battle.hpp"
#include "Character.hpp"

PoisonStatus::PoisonStatus(int duration, int damage)
    : StatusEffect("Poison", duration, TickTiming::TurnEnd), perTick(damage) {}

void PoisonStatus::onTick(Battle& battle, const std::shared_ptr<Character>& target) {
    if (!target || !target->isAlive()) return;
    
    target->takeDamage(perTick);
    battle.getLog()->add("    " + target->getName() + " takes " + 
                        std::to_string(perTick) + " poison damage.");
}

bool PoisonStatus::isDebuff() const {
    return true;
}

int PoisonStatus::getDamagePerTick() const {
    return perTick;
}
