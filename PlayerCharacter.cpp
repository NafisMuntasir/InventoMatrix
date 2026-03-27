#include "PlayerCharacter.hpp"
#include "Battle.hpp"
#include "BattleLog.hpp"
#include "OverencumberedStatus.hpp"
#include "TickTiming.hpp"

PlayerCharacter::PlayerCharacter(std::string name, int level, StatBlock stats,
                                 int startWeight, int weightLimit)
    : Character(std::move(name), level, stats, startWeight, weightLimit) {}

void PlayerCharacter::onTurnStart(Battle& battle) {
    tickStatuses(battle, TickTiming::TurnStart); // Append the battle log after status has expired/duration is over
    tickCooldowns(); // How many turns remain to use the Skill again

    if (isOverencumbered()) {
        battle.getLog()->add("  " + getName() + " is overencumbered! Movement hindered.");

        // Apply temporary speed reduction for this turn
        auto overencumberStatus = std::make_shared<OverencumberedStatus>(1, 5);  // Duration, speedPenalty
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
