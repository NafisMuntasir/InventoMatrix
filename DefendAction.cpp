#include "DefendAction.hpp"
#include "Battle.hpp"
#include "BattleLog.hpp"
#include "Character.hpp"

DefendAction::DefendAction(std::shared_ptr<Character> defender)
    : Action(std::move(defender), 1) {}

bool DefendAction::validate(Battle& battle) const {
    (void)battle;
    return true;
}

void DefendAction::execute(Battle& battle) {
    actor->setDefending(true);
    battle.getLog()->add("  " + actor->getName() + " takes a defensive stance!");
}

std::string DefendAction::getActionName() const {
    return "Defend";
}
