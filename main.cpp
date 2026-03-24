#include <iostream>
#include <limits>
#include <memory>
#include <cstdlib>
#include <ctime>
#include <string>

#include "Battle.hpp"
#include "BattleRules.hpp"
#include "BattleLog.hpp"
#include "PlayerParty.hpp"
#include "OpponentParty.hpp"
#include "PlayerCharacter.hpp"
#include "OpponentCharacter.hpp"
#include "RandomAI.hpp"
#include "BasicAttackAction.hpp"
#include "FileIOPlayerCharacter.hpp"

// Minimal player-side party implementation that actually selects targets and attacks
class DemoPlayerParty : public PlayerParty {
public:
    DemoPlayerParty(const std::string& name, int id, int maxSize)
        : PlayerParty(name, id, maxSize) {}

    void executeTurn(Battle& battle) override {
        onTurnStart(battle);

        for (auto& member : getAliveMembers()) {
            if (!member->isAlive() || !member->canAct()) {
                continue;
            }

            member->onTurnStart(battle);
            member->setDefending(false);

            auto enemies = battle.enemiesOf(member);
            if (enemies.empty()) {
                member->onTurnEnd(battle);
                continue;
            }

            auto target = enemies.front();
            auto action = std::make_shared<BasicAttackAction>(member, target);

            if (action->validate(battle)) {
                action->execute(battle);
            }

            member->onTurnEnd(battle);

            if (battle.isOver()) {
                break;
            }
        }

        onTurnEnd(battle);
    }

    void onTurnStart(Battle& battle) override {
        (void)battle;
        std::cout << "-- Player party turn start --\n";
    }

    void onTurnEnd(Battle& battle) override {
        (void)battle;
        std::cout << "-- Player party turn end --\n";
    }

    bool isPlayerParty() const override {
        return true;
    }
};

// Friend function + operator overloading for ENTER pause
class RoundPause {
private:
    std::string prompt;

public:
    explicit RoundPause(const std::string& text = "Press ENTER to continue to next round...")
        : prompt(text) {}

    friend std::istream& operator>>(std::istream& in, RoundPause& pause);
};

std::istream& operator>>(std::istream& in, RoundPause& pause) {
    std::cout << pause.prompt;
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return in;
}

// Friend function + operator overloading for final battle result
class BattleOutcome {
private:
    std::shared_ptr<Party> winner;

public:
    explicit BattleOutcome(std::shared_ptr<Party> winningParty)
        : winner(std::move(winningParty)) {}

    friend std::ostream& operator<<(std::ostream& out, const BattleOutcome& outcome);
};

std::ostream& operator<<(std::ostream& out, const BattleOutcome& outcome) {
    if (outcome.winner) {
        out << "\n" << outcome.winner->getPartyName() << " won the battle!\n";
    } else {
        out << "\nBattle ended with no winner (all defeated).\n";
    }
    return out;
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    std::cout << "Party-based battle demo with FileIO support\n";

    // Create a sample hero and save/load from disk
    auto sampleStats = StatBlock(30, 12, 6, 8, 85, 12, 7);
    auto baseHero = std::make_shared<PlayerCharacter>("Hero", 1, sampleStats, 0, 80);

    const std::string saveFile = "hero_profile.txt";
    if (!FileIO::savePlayerCharacter(*baseHero, saveFile)) {
        std::cerr << "Failed to save player character to " << saveFile << "\n";
    }

    auto loadedHeroOpt = FileIO::loadPlayerCharacter(saveFile);
    std::shared_ptr<PlayerCharacter> hero;

    if (loadedHeroOpt) {
        hero = *loadedHeroOpt;
    } else {
        std::cerr << "Failed to load player character, using the in-memory character.\n";
        hero = baseHero;
    }

    // Build parties
    auto playerParty = std::make_shared<DemoPlayerParty>("Adventurers", 1, 4);
    playerParty->addMember(hero);

    auto mageStats = StatBlock(24, 10, 4, 9, 90, 14, 8);
    playerParty->addMember(std::make_shared<PlayerCharacter>("Mage", 1, mageStats, 0, 70));

    auto opponentParty = std::make_shared<OpponentParty>("Goblin Horde", 2, 4);
    auto goblin1 = std::make_shared<OpponentCharacter>("Goblin A", 1, StatBlock(20, 9, 4, 6, 70, 9, 3));
    auto goblin2 = std::make_shared<OpponentCharacter>("Goblin B", 1, StatBlock(20, 9, 4, 5, 70, 8, 2));
    goblin1->setAI(std::make_shared<RandomAI>());
    goblin2->setAI(std::make_shared<RandomAI>());

    opponentParty->addMember(goblin1);
    opponentParty->addMember(goblin2);
    opponentParty->setAI(std::make_shared<RandomAI>());

    auto rules = std::make_shared<BattleRules>();
    Battle battle(rules);
    battle.addParty(playerParty);
    battle.addParty(opponentParty);

    battle.start();
    battle.getLog()->dumpToStdout();
    battle.getLog()->clear();

    RoundPause pause;

    while (!battle.isOver()) {
        battle.executeRound();
        battle.getLog()->dumpToStdout();
        battle.getLog()->clear();

        if (battle.isOver()) {
            break;
        }

        std::cin >> pause;
    }

    std::cout << BattleOutcome(battle.getWinner());

    return 0;
}