#pragma once

// =========================
// ApplyStatusEffect
// =========================
// A concrete Effect that applies a StatusEffect to the
// target character when used (e.g., Poison, Stun).

#include "Effect.hpp"

class ApplyStatusEffect : public Effect {
private:
    StatusPtr status;

public:
    // Constructor
    explicit ApplyStatusEffect(StatusPtr statusEffect);

    // Core Operation (polymorphism)
    void apply(Battle& battle, const CharPtr& actor, const CharPtr& target) override;

    // Virtual Methods
    std::string getDescription() const override;
};
