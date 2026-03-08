#include"applyBuff.hpp"
#include<iostream>
using namespace std;
void ApplyBuff::apply(Battle& battle, Character& character, std::shared_ptr<Buff> buff) {
    if (!buff) {
        return;
    }

    std::cout << character.getName() << " applies buff: " << buff->getName() << std::endl;
    character.applyBuff(battle, buff);

    if (buff->getTiming() == TickTiming::Immediate) {
        buff->applyEffect(battle, character, character);
    }
}
