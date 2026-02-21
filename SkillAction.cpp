#include "SkillAction.hpp"
#include "Battle.hpp"
#include "Character.hpp"
#include "Skill.hpp"

SkillAction::SkillAction(std::shared_ptr<Character> user,
                         std::shared_ptr<Skill> ability,
                         std::vector<std::shared_ptr<Character>> skillTargets)
    : Action(std::move(user), 0),
      skill(std::move(ability)),
      targets(std::move(skillTargets)) {}

bool SkillAction::validate(Battle& battle) const {
    (void)battle;

    if (!actor || !actor->isAlive() || !skill) return false;
    if (!skill->canUse(actor)) return false;

    // At least one target must be alive
    for (const auto& target : targets) {
        if (target && target->isAlive()) return true;
    }

    return false;
}

void SkillAction::execute(Battle& battle) {
    skill->use(battle, actor, targets);
}

std::string SkillAction::getActionName() const {
    return "Skill: " + skill->getName();
}

const std::shared_ptr<Skill>& SkillAction::getSkill() const {
    return skill;
}

const std::vector<std::shared_ptr<Character>>& SkillAction::getTargets() const {
    return targets;
}
