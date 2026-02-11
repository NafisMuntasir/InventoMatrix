#ifndef PARTY_HPP
#define PARTY_HPP

#include <string>
#include <vector>
#include <memory>

class Character;
class Battle;

class Party {
private:
    std::string partyName;
    int partyID;
    std::vector<std::shared_ptr<Character>> members;
    
    static int count;

public:
    Party(std::string name);
    virtual ~Party();

    const std::string& getPartyName() const;
    int getPartyID() const;
    const std::vector<std::shared_ptr<Character>>& getMembers() const;

    bool isFull() const;
    bool isEmpty() const;
    bool isDefeated() const;
    int getAliveMembersCount() const;

    virtual void addMember(std::shared_ptr<Character> member);
    void removeMember(std::shared_ptr<Character> member);

    virtual void executeTurn(Battle& battle) = 0;
    virtual void onTurnStart(Battle& battle) = 0;
    virtual void onTurnEnd(Battle& battle) = 0;

    virtual bool isPlayerParty() const = 0;
};

#endif
