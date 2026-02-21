#pragma once
#include "Action.hpp"
#include "Skill.hpp"
#include <vector>

// Forward declarations
class Battle;

class SkillAction : public Action {
private:
    // Association: SkillAction uses a Skill (shared ownership)
    std::shared_ptr<Skill> skill;

    // Dependency: targets is a list of Characters the skill will be applied to
    std::vector<std::shared_ptr<Character>> targets;

public:
    SkillAction(std::shared_ptr<Character> user,
                std::shared_ptr<Skill> ability,
                std::vector<std::shared_ptr<Character>> skillTargets);

    bool validate(Battle& battle) const override;
    void execute(Battle& battle) override;
    std::string getActionName() const override;

    const std::shared_ptr<Skill>& getSkill() const;
    const std::vector<std::shared_ptr<Character>>& getTargets() const;
};
