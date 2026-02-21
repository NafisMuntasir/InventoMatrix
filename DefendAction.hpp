#pragma once
#include "Action.hpp"

// Forward declarations
class Battle;

class DefendAction : public Action {
public:
    explicit DefendAction(std::shared_ptr<Character> defender);

    // validate always returns true - any alive character can choose to defend
    bool validate(Battle& battle) const override;
    void execute(Battle& battle) override;
    std::string getActionName() const override;
};
