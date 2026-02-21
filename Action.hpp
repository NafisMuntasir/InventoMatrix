#pragma once
#include <memory>
#include <string>
#include "Character.hpp"

// Forward declarations
class Battle;

class Action {
protected:
    // Composition: Action HAS-A actor (the character performing the action)
    std::shared_ptr<Character> actor;
    int priority;

public:
    Action(std::shared_ptr<Character> actionActor, int actionPriority = 0);
    virtual ~Action() = default;

    // Getters
    int getPriority() const;
    const std::shared_ptr<Character>& getActor() const;

    // Setters
    void setPriority(int p);

    // Pure virtual methods - each action type defines its own validation and execution
    virtual bool validate(Battle& battle) const = 0;
    virtual void execute(Battle& battle) = 0;
    virtual std::string getActionName() const = 0;
};
