#pragma once

// =========================
// HealEffect
// =========================
// A concrete Effect that restores a fixed amount of HP
// to the target character when applied.

#include "Effect.hpp"

class HealEffect : public Effect {
private:
    int amount;

public:
    // Constructor
    explicit HealEffect(int healAmount);

    // Core Operation (polymorphism)
    void apply(Battle& battle, const CharPtr& actor, const CharPtr& target) override;

    // Virtual Methods
    std::string getDescription() const override;

    // Getter
    int getAmount() const;
};
