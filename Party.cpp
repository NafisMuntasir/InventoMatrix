
#include "Party.hpp"
#include "Character.hpp"
#include <iostream>

int Party::count = 0;

Party::Party(std::string name){
    partyName = name;
    partyID = ++count;
}

Party::~Party(){
    count--;
}

const std::string& Party::getPartyName() const {
    return partyName;
}

int Party::getPartyID() const {
    return partyID;
}

const std::vector<std::shared_ptr<Character>>& Party::getMembers() const {
    return members;
}

std::vector<std::shared_ptr<Character>> Party::getAliveMembers() const {
    std::vector<std::shared_ptr<Character>> alive;
    for (const auto& member : members) {
        if (member && member->isAlive()) {
            alive.push_back(member);
        }
    }
    return alive;
}

void Party::addMember(std::shared_ptr<Character> member){
    if(members.size() < MAX_MEMBERS){
        members.push_back(member);
        if(member){
            member->setOwnerParty(this);
        }
    }
    else{
        std::cout<<"Party is full. Cannot add any more members"<<std::endl;
    }
}

void Party::removeMember(std::shared_ptr<Character> member){
    for(int i = 0; i < members.size(); i++){
        if(members[i] == member){
            members[i]->setOwnerParty(nullptr);
            members.erase(members.begin() + i);
            return;
        }
    }
    std::cout<<"Member not found"<<std::endl;
}

bool Party::isFull() const{
    return members.size() >= MAX_MEMBERS;
}

bool Party::isEmpty() const{
    return members.empty();
}

bool Party::isDefeated() const{
    for(int i = 0; i < members.size(); i++){
        if(members[i] && members[i]->isAlive()){
            return false;
        }
    }
    return true;
}

int Party::getAliveMembersCount() const{
    int alive = 0;
    for(int i = 0; i < members.size(); i++){
        if(members[i] && members[i]->isAlive()){
            alive++;
        }
    }
    return alive;
}