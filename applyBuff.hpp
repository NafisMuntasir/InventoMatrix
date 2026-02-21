#ifndef APPLYBUFF_HPP
#define APPLYBUFF_HPP
#include "Buff.hpp"
#include "Character.hpp"
#include "Battle.hpp"
class ApplyBuff{
    public:
    static void apply(Battle& battle, Character& character, std::shared_ptr<Buff> buff);
};
#endif
