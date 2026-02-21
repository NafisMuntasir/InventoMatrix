#pragma once
#include "AIController.hpp"

// Forward declarations
class Battle;
class Character;

class RandomAI : public AIController {
public:
    // Picks a random living enemy and returns a BasicAttackAction against them
    std::shared_ptr<Action> chooseAction(Battle& battle,
                                          const std::shared_ptr<Character>& actor) override;

    std::string getAIType() const override;
};
