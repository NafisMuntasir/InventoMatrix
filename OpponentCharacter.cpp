#include "OpponentCharacter.hpp"
#include "Battle.hpp"
#include "BattleLog.hpp"

OpponentCharacter::OpponentCharacter(std::string name, int level, StatBlock stats)
    : Character(std::move(name), level, stats, 0, 200) {}

void OpponentCharacter::setAI(std::shared_ptr<AIController> ai) {
    individualAI = std::move(ai);
}

std::shared_ptr<AIController> OpponentCharacter::getAI() const {
    return individualAI;
}

void OpponentCharacter::onTurnStart(Battle& battle) {
    tickStatuses(battle, TickTiming::TurnStart);
    tickCooldowns();
}

void OpponentCharacter::onTurnEnd(Battle& battle) {
    tickStatuses(battle, TickTiming::TurnEnd);
    tickBuffs(battle);
}

bool OpponentCharacter::isPlayerControlled() const {
    return false;
}
