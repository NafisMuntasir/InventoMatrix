#include "BattleLog.hpp"
#include <iostream>

// BattleLog stores a list of BattleEvent objects that describe what happened in battle.
// It acts as a simple logging system for combat messages.

// Adds a new battle message to the log.
void BattleLog::add(const std::string& msg) {
    events.emplace_back(msg);
}

// Prints all stored battle messages to standard output.
// This is useful for debugging or console-based games.
void BattleLog::dumpToStdout() const {
    for (const auto& e : events) {
        std::cout << e.getText() << std::endl;
    }
}

// Returns a const reference to the internal list of events.
// This allows read-only access without copying the vector.
const std::vector<BattleEvent>& BattleLog::getEvents() const {
    return events;
}

// Clears all stored battle events.
void BattleLog::clear() {
    events.clear();
}

// Returns the number of logged battle events.
size_t BattleLog::getEventCount() const {
    return events.size();
}
