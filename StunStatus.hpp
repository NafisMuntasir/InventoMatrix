#include "StatusEffect.hpp"

class StunStatus : public StatusEffect {
public:
    explicit StunStatus(int duration);

    bool blocksAction() const override;
    bool isDebuff() const override;
};
