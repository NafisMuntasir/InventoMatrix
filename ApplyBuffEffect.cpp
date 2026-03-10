#include "ApplyBuffEffect.hpp"
#include "Character.hpp"
#include "Buff.hpp"

ApplyBuffEffect::ApplyBuffEffect(BuffPtr buffEffect)
{
    buff = buffEffect;
}

void ApplyBuffEffect::apply(Battle& battle, CharPtr actor, CharPtr target) 
{
    if(!target || !target->isAlive())
        return;

    target->applyBuff(battle, buff);
}

std::string ApplyBuffEffect::getDescription() const
{
    return "Applies Buff: " + buff->getName();
}
