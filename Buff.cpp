#include "Buff.h"

Buff::Buff(std::string buffName, BuffType buffType, int buffValue, int buffDuration)
{
    name = buffName;
    type = buffType;
    value = buffValue;
    duration = buffDuration;
}

std::string Buff::getName()
{
    return name;
}

BuffType Buff::getType()
{
    return type;
}

int Buff::getValue()
{
    return value;
}

int Buff::getDuration()
{
    return duration;
}

void Buff::setDuration(int dur)
{
    duration = dur;
}

void Buff::setValue(int val)
{
    value = val;
}

void Buff::decrementDuration()
{
    duration--;
}

bool Buff::isExpired()
{
    return duration <= 0;
}

void Buff::reset(int newDuration)
{
    duration = newDuration;
}
