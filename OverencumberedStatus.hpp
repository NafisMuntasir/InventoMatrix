#include "StatusEffect.hpp"
#include "StatModifier.hpp"
#include <vector>

class OverencumberedStatus : public StatusEffect {
private:
    int speedReduction;

public:
    OverencumberedStatus(int duration, int speedPenalty);

    std::vector<StatModifier> modifiers() const override;
    bool isDebuff() const override;
    
    int getSpeedReduction() const;
};
