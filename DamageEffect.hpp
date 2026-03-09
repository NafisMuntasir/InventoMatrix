#ifndef DAMAGEEFFECT_H
#define DAMAGEEFFECT_H

#include "Effect.h"
#include "DamageType.h"

class DamageEffect : public Effect
{
private:
    int baseDamage;
    DamageType dmgType;

public:
    DamageEffect(int base, DamageType type);

    void apply(Battle& battle, CharPtr actor, CharPtr target) override;

    std::string getDescription() override;

    int getBaseDamage();
    DamageType getDamageType();
};

#endif
