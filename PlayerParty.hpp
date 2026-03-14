

#ifndef PLAYERPARTY_HPP
#define PLAYERPARTY_HPP

#include "Party.hpp"
#include <algorithm>
#include <iostream>

using namespace std;

class Battle;

class PlayerParty : public Party {
private:
    int totalWeight;
    int partyWeightLimit;

public:
    PlayerParty(string name, int id, int weightLimit = 400);

    // Getters
    int getTotalWeight() const;
    int getPartyWeightLimit() const;

    // Setters
    void setPartyWeightLimit(int limit);

    bool isPartyOverencumbered() const;

    bool addMember(const CharPtr& character) override;

    void updateTotalWeight();

    // Overrides
    void executeTurn(Battle& battle) override;
    void onTurnStart(Battle& battle) override;
    void onTurnEnd(Battle& battle) override;
    bool isPlayerParty() const override;
};

#endif
