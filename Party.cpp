#include "Party.hpp"
#include "Character.hpp"

Party::Party(string name, int id, int maxSize)
    : partyName(move(name)), partyId(id), maxMembers(maxSize) {}

Party::~Party() = default;

const string& Party::getPartyName() const {
    return partyName;
}

int Party::getPartyId() const {
    return partyId;
}

int Party::getMaxMembers() const {
    return maxMembers;
}

const vector<CharPtr>& Party::getMembers() const {
    return members;
}

vector<CharPtr> Party::getAliveMembers() const {
    vector<CharPtr> alive;

    for (const auto& m : members) {
        if (m->isAlive())
            alive.push_back(m);
    }

    return alive;
}

int Party::getAliveCount() const {
    return static_cast<int>(getAliveMembers().size());
}

bool Party::isDefeated() const {
    return getAliveCount() == 0;
}

bool Party::isFull() const {
    return static_cast<int>(members.size()) >= maxMembers;
}

void Party::setPartyName(const string& name) {
    partyName = name;
}

void Party::setMaxMembers(int max) {
    maxMembers = max(1, max);
}

bool Party::addMember(const CharPtr& character) {

    if (isFull()) {
        cout << "Party is full!\n";
        return false;
    }

    members.push_back(character);
    character->setOwnerParty(this);

    return true;
}
