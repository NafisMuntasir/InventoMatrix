#include "StatusEffect.hpp"
#include <memory>

// Forward declarations
class Battle;
class Character;

class PoisonStatus : public StatusEffect {
private:
    int perTick;

public:
    PoisonStatus(int duration, int damage);

    void onTick(Battle& battle, const std::shared_ptr<Character>& target) override;
    bool isDebuff() const override;
    
    int getDamagePerTick() const;
};
