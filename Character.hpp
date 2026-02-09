#include <string>
#include <vector>
#include <memory>
#include "StatBlock.hpp"
#include "Resource.hpp"

// Forward declarations
class Battle;
class Skill;
class StatusEffect;
class Buff;
class Party;

enum class StatType;
enum class TickTiming;

class Character : public std::enable_shared_from_this<Character> {
private:
    std::string name;
    int level;
    StatBlock baseStats;
    int hp;
    Resource mana;
    int weight;
    int maxWeight;
    bool defending;
    
    std::vector<std::shared_ptr<Skill>> skills;
    std::vector<std::shared_ptr<StatusEffect>> statuses;
    std::vector<std::shared_ptr<Buff>> buffs;
    
    Party* ownerParty;

public:
    Character(std::string charName, int charLevel, StatBlock stats, 
              int startWeight = 0, int weightLimit = 100);
    virtual ~Character() = default;

    // Getters (const for read-only access - encapsulation)
    const std::string& getName() const;
    int getHP() const;
    int getMaxHP() const;
    int getLevel() const;
    int getWeight() const;
    int getMaxWeight() const;
    int getMana() const;
    int getMaxMana() const;
    bool isDefending() const;
    Party* getOwnerParty() const;
    const std::vector<std::shared_ptr<Skill>>& getSkills() const;
    const StatBlock& getBaseStats() const;
    
    bool isAlive() const;
    bool isOverencumbered() const;

    // Setters (validation - encapsulation)
    void setOwnerParty(Party* party);
    void setDefending(bool def);
    void setLevel(int lvl);
    
    void addWeight(int amount);
    void removeWeight(int amount);

    // Core operations (abstraction)
    void takeDamage(int amount);
    void heal(int amount);
    void consumeMana(int amount);
    void restoreMana(int amount);

    void addSkill(std::shared_ptr<Skill> s);
    void removeSkill(const std::shared_ptr<Skill>& s);

    void applyStatus(Battle& battle, std::shared_ptr<StatusEffect> status);
    void applyBuff(Battle& battle, std::shared_ptr<Buff> buff);
    void tickStatuses(Battle& battle, TickTiming when);
    void tickBuffs(Battle& battle);
    void tickCooldowns();
    bool canAct() const;
    void checkOverencumbered();

    // Stat computation (base + buffs + status mods) - abstraction
    int getFinalStat(StatType type) const;
    
    // Calculate modified attack with buffs
    int getModifiedAttack() const;
    
    // Calculate modified defense with buffs
    int getModifiedDefense() const;
    
    // Apply nerf effect (percentage health reduction)
    void applyNerf(int percentage, Battle& battle);

    // Pure virtual - different behavior for player/opponent characters (polymorphism)
    virtual void onTurnStart(Battle& battle) = 0;
    virtual void onTurnEnd(Battle& battle) = 0;
    
    // Additional virtual methods
    virtual bool isPlayerControlled() const = 0;
};
