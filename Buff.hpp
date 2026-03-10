#ifndef BUFF_H
#define BUFF_H

#include <string>
#include "BuffType.hpp"

class Buff
{
private:
    std::string name;
    BuffType type;
    int value;
    int duration;

public:
    Buff(std::string buffName, BuffType buffType, int buffValue, int buffDuration);

    std::string getName();
    BuffType getType();
    int getValue();
    int getDuration();

    void setDuration(int dur);
    void setValue(int val);

    void decrementDuration();
    bool isExpired();
    void reset(int newDuration);
};

#endif
