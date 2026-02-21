#include "BasicAttackAction.hpp"
#include "Battle.hpp"
#include "BattleLog.hpp"
#include "BattleRules.hpp"
#include "Character.hpp"

BasicAttackAction::BasicAttackAction(std::shared_ptr<Character> attacker,
                                     std::shared_ptr<Character> defender)
    : Action(std::move(attacker), 0), target(std::move(defender)) {}

bool BasicAttackAction::validate(Battle& battle) const {
    (void)battle;
    return actor && actor->isAlive() && target && target->isAlive();
}

void BasicAttackAction::execute(Battle& battle) {
    battle.getLog()->add("  " + actor->getName() + " attacks " + target->getName() + "!");

    if (!battle.getRules().rollHit(actor, target)) {
        battle.getLog()->add("    Miss!");
        return;
    }

    int dmg = battle.getRules().computeDamage(actor, target, 5, DamageType::Physical);
    target->takeDamage(dmg);
    battle.getLog()->add("    Deals " + std::to_string(dmg) + " damage. (" +
                         target->getName() + ": " + std::to_string(target->getHP()) +
                         "/" + std::to_string(target->getMaxHP()) + " HP)");

    if (!target->isAlive()) {
        battle.getLog()->add("    " + target->getName() + " is defeated!");
    }
}

std::string BasicAttackAction::getActionName() const {
    return "Basic Attack";
}

const std::shared_ptr<Character>& BasicAttackAction::getTarget() const {
    return target;
}
