#pragma once
#include "Action.hpp"

// Forward declarations
class Battle;

class BasicAttackAction : public Action {
private:
    // Dependency: BasicAttackAction targets a specific Character
    std::shared_ptr<Character> target;

public:
    BasicAttackAction(std::shared_ptr<Character> attacker,
                      std::shared_ptr<Character> defender);

    bool validate(Battle& battle) const override;
    void execute(Battle& battle) override;
    std::string getActionName() const override;

    const std::shared_ptr<Character>& getTarget() const;
};
