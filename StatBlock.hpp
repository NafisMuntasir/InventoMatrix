#pragma once
#include "StatType.hpp"

// StatBlock is a data container for all base combat statistics of a character.
// Systems such as combat, AI, and status effects interact with stats through
// this class instead of directly modifying raw variables.
class StatBlock {
private:
    int maxHP;
    int attack;
    int defense;
    int speed;
    int accuracy;
    int evasion;
    int crit;

public:
    // Default constructor: initializes all stats to 0
    StatBlock();

    // Parameterized constructor: initializes all stats with given values
    StatBlock(int hp, int atk, int def, int spd, int acc, int eva, int crt);

    // Individual stat accessors
    int getMaxHP() const;
    int getAttack() const;
    int getDefense() const;
    int getSpeed() const;
    int getAccuracy() const;
    int getEvasion() const;
    int getCrit() const;

    // Individual stat mutators
    void setMaxHP(int value);
    void setAttack(int value);
    void setDefense(int value);
    void setSpeed(int value);
    void setAccuracy(int value);
    void setEvasion(int value);
    void setCrit(int value);

    // Generic stat access using StatType
    // This allows code to work with stats without knowing the exact member name
    int getStat(StatType type) const;
    void setStat(StatType type, int value);

    // Convenience methods for modifying stats incrementally
    void increaseStat(StatType type, int amount);
    void decreaseStat(StatType type, int amount);
};
