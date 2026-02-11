#ifndef PLAYERPARTY_HPP
#define PLAYERPARTY_HPP

#include "Party.hpp"
#include "Character.hpp"
#include <string>
#include <vector>
#include <memory>
#include <iostream>

class PlayerParty : public Party, public Character {
private:
    int totalWeight;
    int partyWeightLimit;

public:
    PlayerParty(std::string name, int weightLimit = 100, int weight = 0);

    int getTotalWeight() const;
    int getPartyWeightLimit() const;

    void setTotalWeight(int weight);
    void setPartyWeightLimit(int weightLimit);

    void addMember(std::shared_ptr<Character> member, int weight);
    void updateTotalWeight(int weightChange);
    void removeMember(std::shared_ptr<Character> member, int weight);

    // Overrides from Party/Character
    void executeTurn(Battle& battle) override;
    void onTurnStart(Battle& battle) override;
    void onTurnEnd(Battle& battle) override;
    bool isPlayerParty() const override;
};

#endif
