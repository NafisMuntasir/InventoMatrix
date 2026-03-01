#include "StatBlock.hpp"

// StatBlock stores all base stats for a character (HP, attack, defense, etc.).
// It centralizes stat access so gameplay systems can query and modify stats
// without touching individual member variables directly.

// Default constructor: initializes all stats to 0.
StatBlock::StatBlock()
    : maxHP(0), attack(0), defense(0), speed(0), accuracy(0), evasion(0), crit(0) {}

// Parameterized constructor: initializes all stats with given values.
StatBlock::StatBlock(int hp, int atk, int def, int spd, int acc, int eva, int crt)
    : maxHP(hp), attack(atk), defense(def), speed(spd), accuracy(acc), evasion(eva), crit(crt) {}

// Individual getters for each stat.
int StatBlock::getMaxHP() const { return maxHP; }
int StatBlock::getAttack() const { return attack; }
int StatBlock::getDefense() const { return defense; }
int StatBlock::getSpeed() const { return speed; }
int StatBlock::getAccuracy() const { return accuracy; }
int StatBlock::getEvasion() const { return evasion; }
int StatBlock::getCrit() const { return crit; }

// Individual setters for each stat.
void StatBlock::setMaxHP(int v) { maxHP = v; }
void StatBlock::setAttack(int v) { attack = v; }
void StatBlock::setDefense(int v) { defense = v; }
void StatBlock::setSpeed(int v) { speed = v; }
void StatBlock::setAccuracy(int v) { accuracy = v; }
void StatBlock::setEvasion(int v) { evasion = v; }
void StatBlock::setCrit(int v) { crit = v; }

// Returns a stat value based on the StatType enum.
// This allows generic code to work with any stat type.
int StatBlock::getStat(StatType type) const {
    switch (type) {
        case StatType::MaxHP: return maxHP;
        case StatType::Attack: return attack;
        case StatType::Defense: return defense;
        case StatType::Speed: return speed;
        case StatType::Accuracy: return accuracy;
        case StatType::Evasion: return evasion;
        case StatType::Crit: return crit;
    }
    return 0;
}

// Sets a stat value using the StatType enum.
void StatBlock::setStat(StatType type, int value) {
    switch (type) {
        case StatType::MaxHP: maxHP = value; break;
        case StatType::Attack: attack = value; break;
        case StatType::Defense: defense = value; break;
        case StatType::Speed: speed = value; break;
        case StatType::Accuracy: accuracy = value; break;
        case StatType::Evasion: evasion = value; break;
        case StatType::Crit: crit = value; break;
    }
}

// Increases a stat by a given amount.
void StatBlock::increaseStat(StatType type, int amount) {
    setStat(type, getStat(type) + amount);
}

// Decreases a stat by a given amount.
void StatBlock::decreaseStat(StatType type, int amount) {
    setStat(type, getStat(type) - amount);
}
