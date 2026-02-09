#include "Skill.hpp"
#include <vector>
#include <memory>

// Forward declarations
class Effect;
class Battle;
class Character;
class TargetingRule;

class CompositeSkill : public Skill {
private:
    std::vector<std::shared_ptr<Effect>> effects;

public:
    CompositeSkill(std::string name, int cost, int cooldown, 
                   std::shared_ptr<TargetingRule> rule);

    void addEffect(std::shared_ptr<Effect> eff);

    void use(Battle& battle, const std::shared_ptr<Character>& actor, 
             const std::vector<std::shared_ptr<Character>>& targets) override;
    
    std::string getDescription() const override;
    
    size_t getEffectCount() const;
};
