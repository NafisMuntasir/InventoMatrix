#include "DamageEffect.h"
#include "Battle.h"
#include "Character.h"

DamageEffect::DamageEffect(int base, DamageType type)
{
    baseDamage = base;
    dmgType = type;
}

void DamageEffect::apply(Battle& battle, CharPtr actor, CharPtr target)
{
    if(!target || !target->isAlive())
        return;

    int damage = battle.getRules().computeDamage(actor, target, baseDamage, dmgType);

    target->takeDamage(damage);
}

std::string DamageEffect::getDescription()
{
    return "Deals damage to target";
}

int DamageEffect::getBaseDamage()
{
    return baseDamage;
}

DamageType DamageEffect::getDamageType()
{
    return dmgType;
}
