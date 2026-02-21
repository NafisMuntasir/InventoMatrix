#include "AggressiveAI.hpp"
#include "Battle.hpp"
#include "Character.hpp"
#include "BasicAttackAction.hpp"

std::shared_ptr<Action> AggressiveAI::chooseAction(Battle& battle,
                                                     const std::shared_ptr<Character>& actor) {
    auto enemies = battle.enemiesOf(actor);

    if (enemies.empty()) return nullptr;

    // Target the enemy with the lowest current HP (focus-fire the weakest)
    std::shared_ptr<Character> target = enemies[0];

    for (const auto& enemy : enemies) {
        if (enemy->getHP() < target->getHP()) {
            target = enemy;
        }
    }

    return std::make_shared<BasicAttackAction>(actor, target);
}

std::string AggressiveAI::getAIType() const {
    return "Aggressive";
}
