#include "TurnManager.hpp"
#include "Party.hpp"
#include "Character.hpp"
#include <algorithm>

// =========================
// TurnManager – Implementation
// =========================

// Constructor
TurnManager::TurnManager()
    : currentPartyIndex(0), round(0) {}

// Getters
int TurnManager::getRound() const {
    return round;
}

std::size_t TurnManager::getCurrentPartyIndex() const {
    return currentPartyIndex;
}

const std::vector<PartyPtr>& TurnManager::getPartyQueue() const {
    return partyQueue;
}

// Methods

void TurnManager::buildOrder(const std::vector<PartyPtr>& parties) {
    partyQueue.clear();

    for (const auto& party : parties) {
        if (!party->isDefeated()) {
            partyQueue.push_back(party);
        }
    }

    // Sort by average speed of alive members (fastest party acts first)
    std::sort(partyQueue.begin(), partyQueue.end(),
              [](const PartyPtr& a, const PartyPtr& b) {
        int avgSpeedA = 0, avgSpeedB = 0;
        auto aliveA   = a->getAliveMembers();
        auto aliveB   = b->getAliveMembers();

        for (const auto& m : aliveA) { avgSpeedA += m->getFinalStat(StatType::Speed); }
        for (const auto& m : aliveB) { avgSpeedB += m->getFinalStat(StatType::Speed); }

        if (!aliveA.empty()) avgSpeedA /= static_cast<int>(aliveA.size());
        if (!aliveB.empty()) avgSpeedB /= static_cast<int>(aliveB.size());

        return avgSpeedA > avgSpeedB;
    });

    currentPartyIndex = 0;
    round++;
}

PartyPtr TurnManager::nextParty() {
    if (partyQueue.empty()) return nullptr;

    for (std::size_t tries = 0; tries < partyQueue.size(); tries++) {
        auto& party         = partyQueue[currentPartyIndex];
        currentPartyIndex   = (currentPartyIndex + 1) % partyQueue.size();

        if (!party->isDefeated()) {
            return party;
        }
    }

    return nullptr;
}

void TurnManager::resetRound() {
    round = 0;
}
