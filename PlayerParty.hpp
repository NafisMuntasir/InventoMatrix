#ifndef PLAYERPARTY_HPP
#define PLAYERPARTY_HPP

#include "Party.hpp"
#include <memory>
#include <string>

using namespace std;

class Battle;
class Character;

class PlayerParty : public Party
{
private:
    int totalWeight;
    int partyWeightLimit;

public:

    // Constructor
    PlayerParty(string name, int id, int weightLimit);

    // Getters
    int getTotalWeight() const;
    int getPartyWeightLimit() const;
    bool isPartyOverencumbered() const;

    // Setter
    void setPartyWeightLimit(int limit);

    // Member management
    bool addMember(shared_ptr<Character> character);

    // Weight management
    void updateTotalWeight();

    // Turn handling
    void executeTurn(Battle& battle) override;
    void onTurnStart(Battle& battle) override;
    void onTurnEnd(Battle& battle) override;

    // Identify party type
    bool isPlayerParty() const override;
};

#endif
