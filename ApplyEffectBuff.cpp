#include "ApplyBuffEffect.h"
#include "Character.h"

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

std::string ApplyBuffEffect::getDescription()
{
    return "Applies Buff: " + buff->getName();
}
