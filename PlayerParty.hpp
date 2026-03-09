#ifndef PLAYERPARTY_H
#define PLAYERPARTY_H

#include "Party.h"

class PlayerParty : public Party
{
private:
    int totalWeight;
    int partyWeightLimit;

public:
    PlayerParty(std::string name, int id, int weightLimit);

    int getTotalWeight();
    int getPartyWeightLimit();

    bool isPartyOverencumbered();

    void setPartyWeightLimit(int limit);

    bool addMember(CharPtr character) override;

    void updateTotalWeight();

    void executeTurn(Battle& battle) override;

    void onTurnStart(Battle& battle) override;

    void onTurnEnd(Battle& battle) override;

    bool isPlayerParty() override;
};

#endif
