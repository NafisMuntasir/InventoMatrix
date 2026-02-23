#pragma once

// =========================
// Effect
// =========================
// Abstract base class for all skill effects.
// Derived classes override apply() to define behaviour
// (damage, healing, status application, etc.).

#include "Types.hpp"
#include <string>

class Effect {
public:
    virtual ~Effect() = default;

    // Pure Virtual Methods
    virtual void apply(Battle& battle, const CharPtr& actor, const CharPtr& target) = 0;

    // Virtual Methods
    virtual std::string getDescription() const { return "Effect"; }
};
