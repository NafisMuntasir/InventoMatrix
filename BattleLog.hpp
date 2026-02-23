#pragma once

// =========================
// BattleLog
// =========================
// Stores a sequential log of BattleEvents produced during
// combat. Provides helpers to print, query, and clear the
// event history.

#include <iostream>
#include <string>
#include <vector>

// ----- BattleEvent -----
class BattleEvent {
private:
    std::string text;

public:
    BattleEvent() : text("") {}
    explicit BattleEvent(std::string msg) : text(std::move(msg)) {}

    // Getter
    const std::string& getText() const { return text; }

    // Setter
    void setText(const std::string& msg) { text = msg; }
};

// ----- BattleLog -----
class BattleLog {
private:
    std::vector<BattleEvent> events;

public:
    // Add an event message
    void add(const std::string& msg) {
        events.push_back(BattleEvent(msg));
    }

    // Display all events to stdout
    void dumpToStdout() const {
        for (const auto& e : events)
            std::cout << e.getText() << "\n";
    }

    // Getters
    const std::vector<BattleEvent>& getEvents() const { return events; }
    std::size_t                     getEventCount() const { return events.size(); }

    // Utility
    void clear() { events.clear(); }
};
