#include "Battle.hpp"
#include "BattleRules.hpp"
#include "BattleLog.hpp"
#include "Party.hpp"
#include "Character.hpp"
#include <algorithm>
#include <string>

// =========================
// Battle – Implementation
// =========================

// Constructor
Battle::Battle(std::shared_ptr<BattleRules> battleRules)
    : rules(std::move(battleRules)) {
    log = std::make_shared<BattleLog>();
}

// Getters

std::shared_ptr<BattleLog> Battle::getLog() const {
    return log;
}

BattleRules& Battle::getRules() {
    return *rules;
}

const BattleRules& Battle::getRules() const {
    return *rules;
}

const std::vector<PartyPtr>& Battle::getParties() const {
    return parties;
}

TurnManager& Battle::getTurnManager() {
    return turnManager;
}

const TurnManager& Battle::getTurnManager() const {
    return turnManager;
}

// Party Management

void Battle::addParty(const PartyPtr& party) {
    parties.push_back(party);
}

void Battle::removeParty(const PartyPtr& party) {
    parties.erase(
        std::remove(parties.begin(), parties.end(), party),
        parties.end());
}

// Query Methods

std::vector<CharPtr> Battle::allCharacters() const {
    std::vector<CharPtr> all;
    for (const auto& party : parties) {
        for (const auto& member : party->getMembers()) {
            all.push_back(member);
        }
    }
    return all;
}

std::vector<CharPtr> Battle::enemiesOf(const CharPtr& actor) const {
    std::vector<CharPtr> enemies;
    Party* actorParty = actor->getOwnerParty();

    for (const auto& party : parties) {
        if (party.get() != actorParty) {
            for (const auto& member : party->getMembers()) {
                if (member->isAlive()) {
                    enemies.push_back(member);
                }
            }
        }
    }

    return enemies;
}

std::vector<CharPtr> Battle::alliesOf(const CharPtr& actor) const {
    std::vector<CharPtr> allies;
    Party* actorParty = actor->getOwnerParty();

    if (actorParty) {
        for (const auto& member : actorParty->getMembers()) {
            if (member->isAlive() && member != actor) {
                allies.push_back(member);
            }
        }
    }

    return allies;
}

bool Battle::isOver() const {
    int aliveParties = 0;
    for (const auto& party : parties) {
        if (!party->isDefeated()) {
            aliveParties++;
        }
    }
    return aliveParties <= 1;
}

PartyPtr Battle::getWinner() const {
    for (const auto& party : parties) {
        if (!party->isDefeated()) {
            return party;
        }
    }
    return nullptr;
}

// Battle Control

void Battle::start() {
    turnManager.buildOrder(parties);
    log->add("=== Battle Started! ===");

    for (const auto& party : parties) {
        log->add(party->getPartyName() + " enters the battle!");
    }
}

void Battle::executeRound() {
    if (isOver()) return;

    log->add("\n--- Round " + std::to_string(turnManager.getRound()) + " ---");

    // Rebuild party order at the start of each round
    turnManager.buildOrder(parties);

    // Execute turn for each party
    for (std::size_t i = 0; i < parties.size() && !isOver(); i++) {
        PartyPtr party = turnManager.nextParty();

        if (party && !party->isDefeated()) {
            log->add("\n" + party->getPartyName() + "'s turn:");
            party->executeTurn(*this);
        }
    }
}
