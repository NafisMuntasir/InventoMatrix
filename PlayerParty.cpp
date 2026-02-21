#include "PlayerParty.hpp"
#include "Battle.hpp"

PlayerParty::PlayerParty(std::string name, int weightLimit, int weight)
    : Party(name), totalWeight(weight), partyWeightLimit(weightLimit) {}

int PlayerParty::getTotalWeight() const {
    return totalWeight;
}

int PlayerParty::getPartyWeightLimit() const {
    return partyWeightLimit;
}

void PlayerParty::setTotalWeight(int weight) {
    totalWeight = weight;
}

void PlayerParty::setPartyWeightLimit(int weightLimit) {
    partyWeightLimit = weightLimit;
}

void PlayerParty::addMember(std::shared_ptr<Character> member, int weight) {
    if (!isFull() && totalWeight + weight <= partyWeightLimit) {
        Party::addMember(member);
        totalWeight += weight;
    } else {
        std::cout << "Cannot add member. Either party is full or weight limit exceeded." << std::endl;
    }
}

void PlayerParty::updateTotalWeight(int weightChange) {
    totalWeight += weightChange;
    if (totalWeight > partyWeightLimit) {
        std::cout << "Party weight has exceeded the limit! You may need to remove some members." << std::endl;
    }
}

void PlayerParty::removeMember(std::shared_ptr<Character> member, int weight) {
    Party::removeMember(member);
    totalWeight -= weight;
}

void PlayerParty::executeTurn(Battle& battle) {
    // Example implementation: iterate through members and let them act
    for (auto& member : getMembers()) {
        if (member && member->isAlive()) {
            member->executeTurn(battle);
        }
    }
}

void PlayerParty::onTurnStart(Battle& battle) {
    std::cout << "Player party turn start." << std::endl;
}

void PlayerParty::onTurnEnd(Battle& battle) {
    std::cout << "Player party turn end." << std::endl;
}

bool PlayerParty::isPlayerParty() const {
    return true;
}
