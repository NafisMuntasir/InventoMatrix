#pragma once
#include "Character.hpp"

// Forward declarations
class Battle;

class PlayerCharacter : public Character {
public:
    PlayerCharacter(std::string name, int level, StatBlock stats,
                    int startWeight = 0, int weightLimit = 100);

    // Override pure virtual methods from Character
    void onTurnStart(Battle& battle) override;
    void onTurnEnd(Battle& battle) override;
    bool isPlayerControlled() const override;
};
