#include "PlayerParty.hpp"
#include "Battle.hpp"
#include <iostream>

using namespace std;

PlayerParty::PlayerParty(string name, int id, int weightLimit)
    : Party(name, id, 4)
{
    totalWeight = 0;
    partyWeightLimit = weightLimit;
}

int PlayerParty::getTotalWeight() const
{
    return totalWeight;
}

int PlayerParty::getPartyWeightLimit() const
{
    return partyWeightLimit;
}

bool PlayerParty::isPartyOverencumbered() const
{
    return totalWeight > partyWeightLimit;
}

void PlayerParty::setPartyWeightLimit(int limit)
{
    partyWeightLimit = limit;
}

bool PlayerParty::addMember(shared_ptr<Character> character)
{
    if (isFull())
        return false;

    int weight = character->getWeight();

    if (totalWeight + weight > partyWeightLimit)
        return false;

    bool added = Party::addMember(character);

    if (added)
    {
        totalWeight += weight;
        character->setOwnerParty(this);
    }

    return added;
}

void PlayerParty::updateTotalWeight()
{
    totalWeight = 0;

    for (auto &member : getMembers())
    {
        if (member)
            totalWeight += member->getWeight();
    }
}

void PlayerParty::executeTurn(Battle& battle)
{
    for (auto &member : getMembers())
    {
        if (member && member->isAlive() && member->canAct())
        {
            member->onTurnStart(battle);

            // Player actions handled externally (UI/input)

            member->onTurnEnd(battle);
        }
    }
}

void PlayerParty::onTurnStart(Battle& battle)
{
    cout << "Player party turn started." << endl;
}

void PlayerParty::onTurnEnd(Battle& battle)
{
    cout << "Player party turn ended." << endl;
}

bool PlayerParty::isPlayerParty() const
{
    return true;
}
