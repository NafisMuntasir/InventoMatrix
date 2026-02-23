#pragma once

// =========================
// TurnManager
// =========================
// Tracks round number and the ordered queue of parties for
// each combat round. Parties are sorted by average member
// speed (fastest acts first). Defeated parties are skipped.

#include "Types.hpp"
#include <vector>
#include <cstddef>

class TurnManager {
private:
    std::vector<PartyPtr> partyQueue;
    std::size_t           currentPartyIndex;
    int                   round;

public:
    // Constructor
    TurnManager();

    // Getters
    int                          getRound()             const;
    std::size_t                  getCurrentPartyIndex() const;
    const std::vector<PartyPtr>& getPartyQueue()        const;

    // Methods
    void     buildOrder(const std::vector<PartyPtr>& parties);
    PartyPtr nextParty();
    void     resetRound();
};
