#include <string>
#include <vector>
#include <memory>

// Forward declarations
class Battle;
class Character;
class TargetingRule;

class Skill {
private:
    std::string name;
    int cost;
    int cooldown;
    int currentCooldown;
    std::shared_ptr<TargetingRule> rule;

protected:
    void resetCooldown();
    void tickCooldown();

public:
    Skill(std::string skillName, int manaCost, int skillCooldown, 
          std::shared_ptr<TargetingRule> targetRule);
    virtual ~Skill() = default;

    // Getters
    const std::string& getName() const;
    int getCost() const;
    int getCooldown() const;
    int getCurrentCooldown() const;
    
    // Setters
    void setCost(int newCost);
    void setCooldown(int newCooldown);
    
    // Virtual methods (polymorphism)
    virtual bool canUse(const std::shared_ptr<Character>& actor) const;
    virtual void use(Battle& battle, const std::shared_ptr<Character>& actor, 
                     const std::vector<std::shared_ptr<Character>>& targets) = 0;

    std::vector<std::shared_ptr<Character>> validTargets(const std::shared_ptr<Character>& actor, Battle& battle) const;
    
    // Cooldown management
    void decrementCooldown();
    void putOnCooldown();
    void resetCurrentCooldown();
    
    // Utility
    bool isReady() const;
    virtual std::string getDescription() const;
};
