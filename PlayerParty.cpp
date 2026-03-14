#include "PlayerParty.hpp"
#include "Battle.hpp"

using namespace std;

PlayerParty::PlayerParty(string name, int id, int weightLimit)
    : Party(move(name), id, 4),
      totalWeight(0),
      partyWeightLimit(weightLimit)
{
}

int PlayerParty::getTotalWeight() const {
    return totalWeight;
}

int PlayerParty::getPartyWeightLimit() const {
    return partyWeightLimit;
}

void PlayerParty::setPartyWeightLimit(int limit) {
    partyWeightLimit = max(0, limit);
}

bool PlayerParty::isPartyOverencumbered() const {
    return totalWeight > partyWeightLimit;
}

bool PlayerParty::addMember(const CharPtr& character) {

    if (Party::addMember(character)) {

        totalWeight += character->getWeight();

        if (isPartyOverencumbered()) {
            cout << "Warning: Party is overencumbered!\n";
        }

        return true;
    }

    return false;
}

void PlayerParty::updateTotalWeight() {

    totalWeight = 0;

    for (const auto& member : getMembers()) {
        totalWeight += member->getWeight();
    }
}

void PlayerParty::executeTurn(Battle& battle) {

    for (const auto& member : getMembers()) {

        if (member && member->isAlive()) {
            member->onTurnStart(battle);

            // Player-controlled actions happen through UI/input

            member->onTurnEnd(battle);
        }
    }
}

void PlayerParty::onTurnStart(Battle& battle) {
    cout << "Player party turn started.\n";
}

void PlayerParty::onTurnEnd(Battle& battle) {
    cout << "Player party turn ended.\n";
}

bool PlayerParty::isPlayerParty() const {
    return true;
}
