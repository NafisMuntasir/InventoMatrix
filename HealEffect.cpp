#include "HealEffect.hpp"
#include "Battle.hpp"
#include "Character.hpp"
#include <string>

// =========================
// HealEffect – Implementation
// =========================

// Constructor
HealEffect::HealEffect(int healAmount)
    : amount(healAmount) {}

// Core Operation
void HealEffect::apply(Battle& battle, const CharPtr& actor, const CharPtr& target) {
    (void)actor;

    if (!target || !target->isAlive()) return;

    target->heal(amount);
    battle.getLog()->add("    " + target->getName() + " heals " +
                         std::to_string(amount) + " HP.");
}

// Virtual Methods
std::string HealEffect::getDescription() const {
    return "Heals " + std::to_string(amount) + " HP";
}

// Getter
int HealEffect::getAmount() const {
    return amount;
}
