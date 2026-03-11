#include "DamageEffect.hpp"
#include "Battle.hpp"
#include "BattleRules.hpp"
#include "Character.hpp"

DamageEffect::DamageEffect(int base, DamageType type)
{
    baseDamage = base;
    dmgType = type;
}

void DamageEffect::apply(Battle& battle, const CharPtr& actor, const CharPtr& target)
{
    if(!target || !target->isAlive())
        return;

    int damage = battle.getRules().computeDamage(actor, target, baseDamage, dmgType);

    target->takeDamage(damage);
}

std::string DamageEffect::getDescription() const 
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
