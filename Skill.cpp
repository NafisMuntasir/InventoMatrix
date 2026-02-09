#include "Skill.hpp"
#include "Character.hpp"
#include "Battle.hpp"
#include "TargetingRule.hpp"
#include <algorithm>

Skill::Skill(std::string skillName, int manaCost, int skillCooldown, 
              std::shared_ptr<TargetingRule> targetRule)
    : name(std::move(skillName)), cost(manaCost), cooldown(skillCooldown),
      currentCooldown(0), rule(std::move(targetRule)) {}

void Skill::resetCooldown() {
    currentCooldown = cooldown;
}

void Skill::tickCooldown() {
    if (currentCooldown > 0) currentCooldown--;
}

const std::string& Skill::getName() const {
    return name;
}

int Skill::getCost() const {
    return cost;
}

int Skill::getCooldown() const {
    return cooldown;
}

int Skill::getCurrentCooldown() const {
    return currentCooldown;
}

void Skill::setCost(int newCost) {
    cost = std::max(0, newCost);
}

void Skill::setCooldown(int newCooldown) {
    cooldown = std::max(0, newCooldown);
}

bool Skill::canUse(const std::shared_ptr<Character>& actor) const {
    return getCurrentCooldown() == 0 && actor->getMana() >= getCost();
}

std::vector<std::shared_ptr<Character>> Skill::validTargets(const std::shared_ptr<Character>& actor, Battle& battle) const {
    return rule ? rule->validTargets(actor, battle) : std::vector<std::shared_ptr<Character>>{};
}

void Skill::decrementCooldown() {
    tickCooldown();
}

void Skill::putOnCooldown() {
    resetCooldown();
}

void Skill::resetCurrentCooldown() {
    currentCooldown = 0;
}

bool Skill::isReady() const {
    return currentCooldown == 0;
}

std::string Skill::getDescription() const {
    return "Skill";
}
