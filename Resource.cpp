#include "Resource.hpp"
#include <algorithm>

// Resource represents a generic pool like HP, Mana, or Stamina.
// It stores a current value and a maximum value, and provides
// helper functions to restore or consume the resource safely.

// Default constructor: initializes current and max to 0.
Resource::Resource() : current(0), max(0) {}

// Parameterized constructor: initializes current and max with given values.
// Clamps max to a non-negative number and clamps current to [0, max].
Resource::Resource(int cur, int mx) {
    max = std::max(0, mx);
    current = std::clamp(cur, 0, max);
}

// Returns the current amount of the resource.
int Resource::getCurrent() const {
    return current;
}

// Returns the maximum amount of the resource.
int Resource::getMax() const {
    return max;
}

// Sets the current value, clamping it between 0 and max
// so it never goes negative or above the maximum.
void Resource::setCurrent(int value) {
    // Clamp manually to support older C++ standards (C++11/C++14)
    if (value < 0)
        current = 0;
    else if (value > max)
        current = max;
    else
        current = value;
}

// Sets the maximum value of the resource.
// If the current value is higher than the new max, it is clamped down.
void Resource::setMax(int value) {
    // Ensure max is non-negative, then clamp current to the new range.
    max = std::max(0, value);
    if (current > max) current = max;
}

// Restores the resource by a certain amount.
// Negative amounts are ignored, and the result is clamped to [0, max].
void Resource::restore(int amount) {
    if (amount <= 0) return;
    setCurrent(current + amount);
}

// Consumes (reduces) the resource by a certain amount.
// Negative amounts are ignored, and the result is clamped to [0, max].
void Resource::consume(int amount) {
    if (amount <= 0) return;
    setCurrent(current - amount);
}

// Returns true if the resource is empty (0 or below).
bool Resource::isEmpty() const {
    return current <= 0;
}

// Returns true if the resource is full (equal to max).
bool Resource::isFull() const {
    return current >= max;
}

// Returns the current resource percentage (0.0 to 1.0).
// This is useful for UI bars (health bar, mana bar, etc.).
float Resource::getPercentage() const {
    if (max == 0) return 0.0f;
    return static_cast<float>(current) / max;
}
