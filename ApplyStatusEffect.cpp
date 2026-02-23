#include "ApplyStatusEffect.hpp"
#include "Battle.hpp"
#include "Character.hpp"

// =========================
// ApplyStatusEffect – Implementation
// =========================

// Constructor
ApplyStatusEffect::ApplyStatusEffect(StatusPtr statusEffect)
    : status(std::move(statusEffect)) {}

// Core Operation
void ApplyStatusEffect::apply(Battle& battle, const CharPtr& actor, const CharPtr& target) {
    (void)actor;

    if (!target || !target->isAlive()) return;

    target->applyStatus(battle, status);
}

// Virtual Methods
std::string ApplyStatusEffect::getDescription() const {
    return "Applies status effect";
}
