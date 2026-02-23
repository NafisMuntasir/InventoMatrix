#include "BattleRules.hpp"
#include "Character.hpp"
#include <algorithm>
#include <cstdlib>

// =========================
// BattleRules – Implementation
// =========================

// Constructor
BattleRules::BattleRules()
    : minHitChance(5), maxHitChance(95) {}

// Getters
int BattleRules::getMinHitChance() const { return minHitChance; }
int BattleRules::getMaxHitChance() const { return maxHitChance; }

// Setters
void BattleRules::setMinHitChance(int chance) {
    minHitChance = std::clamp(chance, 0, 100);
}

void BattleRules::setMaxHitChance(int chance) {
    maxHitChance = std::clamp(chance, 0, 100);
}

// Virtual Methods

bool BattleRules::rollHit(const CharPtr& actor, const CharPtr& target) const {
    int acc    = actor->getFinalStat(StatType::Accuracy);
    int eva    = target->getFinalStat(StatType::Evasion);
    int chance = std::clamp(acc - eva, minHitChance, maxHitChance);
    int r      = rand() % 100;
    return r < chance;
}

int BattleRules::computeDamage(const CharPtr& actor, const CharPtr& target,
                                int base, DamageType type) const {
    (void)type;

    int atk = actor->getModifiedAttack();
    int def = target->getModifiedDefense();
    int raw = base + atk - def;

    if (target->isDefending()) {
        raw = raw / 2;
    }

    return std::max(0, raw);
}

bool BattleRules::rollCrit(const CharPtr& actor) const {
    int critChance = actor->getFinalStat(StatType::Crit);
    int r          = rand() % 100;
    return r < critChance;
}
