#pragma once

// =========================
// BattleLog
// =========================
// Stores a sequential log of BattleEvents produced during
// combat. Provides helpers to print, query, and clear the
// event history.

#include <vector>
#include <string>
#include "BattleEvent.hpp"

class BattleLog {
private:
    std::vector<BattleEvent> events;

public:
    void add(const std::string& msg);
    void dumpToStdout() const;
    const std::vector<BattleEvent>& getEvents() const;
    void clear();
    size_t getEventCount() const;
};
