#pragma once
#include "AIController.hpp"

// Forward declarations
class Battle;
class Character;

class AggressiveAI : public AIController {
public:
    // Targets the living enemy with the lowest current HP
    std::shared_ptr<Action> chooseAction(Battle& battle,
                                          const std::shared_ptr<Character>& actor) override;

    std::string getAIType() const override;
};
