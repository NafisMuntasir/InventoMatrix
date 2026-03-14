#include "PlayerParty.hpp"
#include "Battle.hpp"
#include <iostream>

PlayerParty::PlayerParty(std::string name, int id, int weightLimit)
    : Party(name, id, 4), totalWeight(0), partyWeightLimit(weightLimit)
{
}

int PlayerParty::getTotalWeight() const {
    return totalWeight;
}

int PlayerParty::getPartyWeightLimit() const {
    return partyWeightLimit;
}

bool PlayerParty::isPartyOverencumbered() const {
    return totalWeight > partyWeightLimit;
}

void PlayerParty::setPartyWeightLimit(int limit) {
    partyWeightLimit = limit;
}

bool PlayerParty::addMember(std::shared_ptr<Character> character) {

    if (isFull())
        return false;

    int weight = character->getWeight();

    if (totalWeight + weight > partyWeightLimit)
        return false;

    bool added = Party::addMember(character);

    if (added) {
        totalWeight += weight;
        character->setOwnerParty(this);
    }

    return added;
}

void PlayerParty::updateTotalWeight() {

    totalWeight = 0;

    for (auto &member : getMembers()) {
        if (member)
            totalWeight += member->getWeight();
    }
}

void PlayerParty::executeTurn(Battle& battle) {

    for (auto &member : getMembers()) {

        if (member && member->isAlive() && member->canAct()) {
            member->onTurnStart(battle);

            // Player-controlled actions handled externally (UI/input)

            member->onTurnEnd(battle);
        }
    }
}

void PlayerParty::onTurnStart(Battle& battle) {
    std::cout << "Player party turn started.\n";
}

void PlayerParty::onTurnEnd(Battle& battle) {
    std::cout << "Player party turn ended.\n";
}

bool PlayerParty::isPlayerParty() const {
    return true;
}
