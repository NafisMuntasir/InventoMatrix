#pragma once
#include <memory>
#include <string>

// Forward declarations
// AIController depends on Battle and Character only through the chooseAction signature.
// Action is the return type - we use shared_ptr so a forward declaration is sufficient.
class Battle;
class Character;
class Action;

class AIController {
public:
    virtual ~AIController() = default;

    // Pure virtual: subclasses decide which action the actor will take this turn
    virtual std::shared_ptr<Action> chooseAction(Battle& battle,
                                                  const std::shared_ptr<Character>& actor) = 0;

    // Pure virtual: identifies the AI strategy by name
    virtual std::string getAIType() const = 0;
};
