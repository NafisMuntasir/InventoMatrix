#include"applyBuff.hpp"
#include<iostream>
using namespace std;
void ApplyBuff::apply(Battle& battle, Character& character, std::shared_ptr<Buff> buff){
    if(!buff){
        return;
    }
    cout<<character.getName()<<" applies buff: "<<buff->getName()<<endl;
   target.addBuff(buff);
   if(buff->getStatusTiming()==TickTiming::Immediate){
       buff->applyEffect(battle,character,target);
   }
}
