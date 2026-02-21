#include "Action.hpp"

Action::Action(std::shared_ptr<Character> actionActor, int actionPriority)
    : actor(std::move(actionActor)), priority(actionPriority) {}

int Action::getPriority() const {
    return priority;
}

const std::shared_ptr<Character>& Action::getActor() const {
    return actor;
}

void Action::setPriority(int p) {
    priority = p;
}
