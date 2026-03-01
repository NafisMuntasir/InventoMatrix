#pragma once
#include <string>

// BattleEvent represents a single descriptive event in combat,
// such as an attack, a miss, or a status effect being applied.
// It is a lightweight data object used by BattleLog.
class BattleEvent {
private:
    std::string text; // Human-readable description of the event

public:
    // Default constructor: creates an empty event
    BattleEvent();

    // Parameterized constructor: creates an event with a message
    BattleEvent(std::string msg);

    // Accessors and mutators for the event text
    const std::string& getText() const;
    void setText(const std::string& msg);
};
