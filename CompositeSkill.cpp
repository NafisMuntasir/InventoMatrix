#include "CompositeSkill.hpp"
#include "Effect.hpp"
#include "Battle.hpp"
#include "Character.hpp"
#include "BattleLog.hpp"

CompositeSkill::CompositeSkill(std::string name, int cost, int cooldown, 
                   std::shared_ptr<TargetingRule> rule)
    : Skill(std::move(name), cost, cooldown, std::move(rule)) {}

void CompositeSkill::addEffect(std::shared_ptr<Effect> eff) {
    effects.push_back(std::move(eff));
}

void CompositeSkill::use(Battle& battle, const std::shared_ptr<Character>& actor, 
             const std::vector<std::shared_ptr<Character>>& targets) {
    battle.getLog()->add("  " + actor->getName() + " uses " + getName() + "!");
    
    actor->consumeMana(getCost());
    putOnCooldown();
    
    for (const auto& target : targets) {
        if (!target || !target->isAlive()) continue;
        
        for (const auto& effect : effects) {
            effect->apply(battle, actor, target);
        }
    }
}

std::string CompositeSkill::getDescription() const {
    std::string desc = getName() + ": ";
    for (const auto& eff : effects) {
        if (eff) desc += eff->getDescription() + " ";
    }
    return desc;
}

size_t CompositeSkill::getEffectCount() const {
    return effects.size();
}
