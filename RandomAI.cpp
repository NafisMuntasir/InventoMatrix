#include "RandomAI.hpp"
#include "Battle.hpp"
#include "Character.hpp"
#include "BasicAttackAction.hpp"
#include <cstdlib>

std::shared_ptr<Action> RandomAI::chooseAction(Battle& battle,
                                                const std::shared_ptr<Character>& actor) {
    auto enemies = battle.enemiesOf(actor);

    if (enemies.empty()) return nullptr;

    // Pick a random enemy from the list of living enemies
    int idx = rand() % static_cast<int>(enemies.size());
    return std::make_shared<BasicAttackAction>(actor, enemies[idx]);
}

std::string RandomAI::getAIType() const {
    return "Random";
}
