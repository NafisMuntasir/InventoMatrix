#pragma once
#include "StatType.hpp"

// StatModifier represents a modification applied to a single stat.
// It supports both flat changes and multiplicative scaling, enabling
// flexible buff and debuff systems.
class StatModifier {
private:
    StatType type; // Which stat this modifier affects
    int flat;      // Flat value added to the stat
    float mult;    // Multiplier applied to the stat

public:
    // Default constructor: creates a neutral modifier (no effect)
    StatModifier();

    // Parameterized constructor: defines target stat and modification values
    StatModifier(StatType t, int f, float m);

    // Accessors
    StatType getType() const;
    int getFlat() const;
    float getMult() const;

    // Mutators
    void setType(StatType t);
    void setFlat(int value);
    void setMult(float value);

    // Applies the modifier to a base stat value and returns the modified result
    int applyToValue(int baseValue) const;

    // Helper queries for gameplay logic and UI
    bool isBuffing() const;   // True if this modifier increases a stat
    bool isDebuffing() const; // True if this modifier decreases a stat
};
