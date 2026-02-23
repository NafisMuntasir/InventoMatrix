#pragma once

// =========================
// Battle
// =========================
// Main controller for a single combat encounter.
// Manages the party roster, delegates turn order to
// TurnManager, enforces BattleRules, and maintains the
// shared BattleLog. No inheritance dependencies.

#include "Types.hpp"
#include "TurnManager.hpp"
#include "BattleLog.hpp"
#include <vector>
#include <memory>

class BattleRules;

class Battle {
private:
    std::vector<PartyPtr>        parties;
    TurnManager                  turnManager;
    std::shared_ptr<BattleRules> rules;
    std::shared_ptr<BattleLog>   log;

public:
    // Constructor
    explicit Battle(std::shared_ptr<BattleRules> battleRules);

    // Getters
    std::shared_ptr<BattleLog>   getLog()           const;
    BattleRules&                 getRules();
    const BattleRules&           getRules()          const;
    const std::vector<PartyPtr>& getParties()        const;
    TurnManager&                 getTurnManager();
    const TurnManager&           getTurnManager()    const;

    // Party Management
    void addParty(const PartyPtr& party);
    void removeParty(const PartyPtr& party);

    // Query Methods
    std::vector<CharPtr> allCharacters()                const;
    std::vector<CharPtr> enemiesOf(const CharPtr& actor) const;
    std::vector<CharPtr> alliesOf(const CharPtr& actor)  const;
    bool                 isOver()                        const;
    PartyPtr             getWinner()                     const;

    // Battle Control
    void start();
    void executeRound();
};
