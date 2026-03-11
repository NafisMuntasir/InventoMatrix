#ifndef DAMAGEEFFECT_H
#define DAMAGEEFFECT_H

#include "Effect.hpp"
#include "DamageType.hpp"

class DamageEffect : public Effect
{
private:
    int baseDamage;
    DamageType dmgType;

public:
    DamageEffect(int base, DamageType type);

    void apply(Battle& battle, const CharPtr& actor, const CharPtr& target) override;

    std::string getDescription() const override;

    int getBaseDamage();
    DamageType getDamageType();
};

#endif
