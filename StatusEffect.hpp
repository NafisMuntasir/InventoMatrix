#include <string>
#include <vector>
#include <memory>

// Forward declarations
class Battle;
class Character;
class StatModifier;

enum class TickTiming { TurnStart, TurnEnd };

class StatusEffect {
private:
    std::string name;
    int duration;
    TickTiming timing;

public:
    StatusEffect(std::string statusName, int statusDuration, TickTiming statusTiming);
    virtual ~StatusEffect() = default;

    // Virtual methods (polymorphism)
    virtual void onApply(Battle& battle, const std::shared_ptr<Character>& target);
    virtual void onExpire(Battle& battle, const std::shared_ptr<Character>& target);
    virtual void onTick(Battle& battle, const std::shared_ptr<Character>& target);
    virtual bool blocksAction() const;
    virtual std::vector<StatModifier> modifiers() const;

    // Getters
    const std::string& getName() const;
    TickTiming getTiming() const;
    int getDuration() const;
    
    // Setters
    void setDuration(int dur);
    
    // Duration management
    void decrement();
    bool expired() const;

    // Utility
    virtual bool isDebuff() const;
    virtual bool isBuff() const;
};
