#include "StatModifier.hpp"

// StatModifier represents a temporary or permanent modification applied to a stat.
// It supports both flat changes (e.g., +5 attack) and multiplicative changes
// (e.g., 1.2x attack for a 20% buff). This allows flexible buff/debuff systems.

// Default constructor: creates a neutral modifier that does not change anything.
StatModifier::StatModifier() : type(StatType::Attack), flat(0), mult(1.0f) {}

// Parameterized constructor: initializes the modifier with a target stat,
// a flat amount, and a multiplier.
StatModifier::StatModifier(StatType t, int f, float m) : type(t), flat(f), mult(m) {}

// Returns the stat type this modifier affects.
StatType StatModifier::getType() const {
    return type;
}

// Returns the flat amount added to the base stat.
int StatModifier::getFlat() const {
    return flat;
}

// Returns the multiplicative factor applied to the base stat.
float StatModifier::getMult() const {
    return mult;
}

// Sets which stat this modifier affects.
void StatModifier::setType(StatType t) {
    type = t;
}

// Sets the flat value of the modifier.
void StatModifier::setFlat(int value) {
    flat = value;
}

// Sets the multiplicative value of the modifier.
void StatModifier::setMult(float value) {
    mult = value;
}

// Applies the modifier to a base stat value.
// The formula is: (base + flat) * multiplier.
int StatModifier::applyToValue(int baseValue) const {
    return static_cast<int>((baseValue + flat) * mult);
}

// Returns true if this modifier increases a stat.
bool StatModifier::isBuffing() const {
    return flat > 0 || mult > 1.0f;
}

// Returns true if this modifier decreases a stat.
bool StatModifier::isDebuffing() const {
    return flat < 0 || mult < 1.0f;
}
