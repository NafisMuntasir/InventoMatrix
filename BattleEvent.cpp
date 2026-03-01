#include "BattleEvent.hpp"

// BattleEvent represents a single message or event that occurred during battle.
// It is a small data object that stores text describing an action or result
// (e.g., "Player attacked Goblin for 10 damage").


BattleEvent::BattleEvent() {}


BattleEvent::BattleEvent(std::string msg) : text(msg) {}

// Returns the text describing this battle event.
const std::string& BattleEvent::getText() const {
    return text;
}

// Updates the text of this battle event.
void BattleEvent::setText(const std::string& msg) {
    text = msg;
}
