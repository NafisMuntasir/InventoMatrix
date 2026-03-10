#include "ApplyBuffEffect.hpp"
#include "Character.hpp"
#include "Buff.hpp"

ApplyBuffEffect::ApplyBuffEffect(BuffPtr buffEffect)
{
    buff = buffEffect;
}

void ApplyBuffEffect::apply(Battle& battle, const CharPtr& actor, const CharPtr& target) 
{
    if(!target || !target->isAlive())
        return;

    target->applyBuff(battle, buff);
}

std::string ApplyBuffEffect::getDescription() const
{
    return "Applies Buff: " + buff->getName();
}
