#include "PlayerCharacter.hpp"
#include "Battle.hpp"
#include "BattleLog.hpp"
#include "OverencumberedStatus.hpp"

PlayerCharacter::PlayerCharacter(std::string name, int level, StatBlock stats,
                                 int startWeight, int weightLimit)
    : Character(std::move(name), level, stats, startWeight, weightLimit) {}

void PlayerCharacter::onTurnStart(Battle& battle) {
    tickStatuses(battle, TickTiming::TurnStart);
    tickCooldowns();

    if (isOverencumbered()) {
        battle.getLog()->add("  " + getName() + " is overencumbered! Movement hindered.");

        // Apply temporary speed reduction for this turn
        auto overencumberStatus = std::make_shared<OverencumberedStatus>(1, 5);
        applyStatus(battle, overencumberStatus);
    }
}

void PlayerCharacter::onTurnEnd(Battle& battle) {
    tickStatuses(battle, TickTiming::TurnEnd);
    tickBuffs(battle);
}

bool PlayerCharacter::isPlayerControlled() const {
    return true;
}
