#include "OpponentParty.hpp"
#include "Battle.hpp"
#include "Character.hpp"
#include "OpponentCharacter.hpp"
#include "AIController.hpp"
#include "BasicAttackAction.hpp"

// =========================
// OpponentParty – Implementation
// =========================

// Constructor
OpponentParty::OpponentParty(std::string name, int /*id*/, int /*maxSize*/)
    : Party(std::move(name)) {}

// Getters
std::shared_ptr<AIController> OpponentParty::getAI() const {
    return aiController;
}

// Setters
void OpponentParty::setAI(std::shared_ptr<AIController> ai) {
    aiController = std::move(ai);
}

// Methods

void OpponentParty::executeTurn(Battle& battle) {
    onTurnStart(battle);

    auto aliveMembers = getAliveMembers();

    // Opponents act as a coordinated unit; each member uses its own
    // individual AI when available, otherwise falls back to the
    // party-level AI controller.
    for (auto& member : aliveMembers) {
        if (!member->isAlive()) continue;

        member->onTurnStart(battle);

        if (!member->canAct()) {
            battle.getLog()->add("  " + member->getName() + " cannot act!");
            member->onTurnEnd(battle);
            continue;
        }

        member->setDefending(false);

        // Prefer individual AI, fall back to party AI
        auto opponentChar = std::dynamic_pointer_cast<OpponentCharacter>(member);
        auto ai = opponentChar ? opponentChar->getAI() : aiController;

        if (ai) {
            auto action = ai->chooseAction(battle, member);

            if (action && action->validate(battle)) {
                action->execute(battle);
            }
        }

        member->onTurnEnd(battle);
    }

    onTurnEnd(battle);
}

void OpponentParty::onTurnStart(Battle& battle) {
    (void)battle;
}

void OpponentParty::onTurnEnd(Battle& battle) {
    (void)battle;
}

bool OpponentParty::isPlayerParty() const {
    return false;
}
