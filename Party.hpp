#ifndef PARTY_HPP
#define PARTY_HPP

#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <algorithm>

using namespace std;

class Character;
class Battle;

using CharPtr = shared_ptr<Character>;

class Party {
private:
    string partyName;
    int partyId;
    vector<CharPtr> members;
    int maxMembers;

public:
    Party(string name, int id, int maxSize);
    virtual ~Party();

    // Getters
    const string& getPartyName() const;
    int getPartyId() const;
    int getMaxMembers() const;
    const vector<CharPtr>& getMembers() const;

    vector<CharPtr> getAliveMembers() const;
    int getAliveCount() const;

    bool isDefeated() const;
    bool isFull() const;

    // Setters
    void setPartyName(const string& name);
    void setMaxMembers(int max);

    // Member management
    virtual bool addMember(const CharPtr& character);

    // Virtual functions from UML
    virtual void executeTurn(Battle& battle) = 0;
    virtual void onTurnStart(Battle& battle) = 0;
    virtual void onTurnEnd(Battle& battle) = 0;
    virtual bool isPlayerParty() const = 0;
};

#endif
