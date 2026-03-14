#ifndef PLAYERPARTY_HPP
#define PLAYERPARTY_HPP

#include "Party.hpp"
#include <memory>

class Battle;
class Character;

class PlayerParty : public Party
{
private:
    int totalWeight;
    int partyWeightLimit;

public:

    PlayerParty(std::string name, int id, int weightLimit);
    int getTotalWeight() const;
    int getPartyWeightLimit() const;
    bool isPartyOverencumbered() const;
    void setPartyWeightLimit(int limit);
    bool addMember(std::shared_ptr<Character> character);
    void updateTotalWeight();
    void executeTurn(Battle& battle) override;
    void onTurnStart(Battle& battle) override;
    void onTurnEnd(Battle& battle) override;
    bool isPlayerParty() const override;
};

#endif
