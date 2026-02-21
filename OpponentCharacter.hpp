#pragma once
#include "Character.hpp"
#include "AIController.hpp"

// Forward declarations
class Battle;

class OpponentCharacter : public Character {
private:
    // Aggregation: OpponentCharacter HAS-A AIController (optional per-character AI)
    std::shared_ptr<AIController> individualAI;

public:
    OpponentCharacter(std::string name, int level, StatBlock stats);

    // AI management
    void setAI(std::shared_ptr<AIController> ai);
    std::shared_ptr<AIController> getAI() const;

    // Override pure virtual methods from Character
    void onTurnStart(Battle& battle) override;
    void onTurnEnd(Battle& battle) override;
    bool isPlayerControlled() const override;
};
