#ifndef TARGETINGRULE_H
#define TARGETINGRULE_H

#include <vector>
#include <memory>

class Character;
class Battle;

using CharPtr = std::shared_ptr<Character>;

class TargetingRule {
public:
    virtual ~TargetingRule() = default;

    virtual std::vector<CharPtr> validTargets(const CharPtr& actor, Battle& battle) const = 0;

    // Additional utility (can be overridden)
    virtual bool canTargetAllies() const;
    virtual bool canTargetEnemies() const;
};

#endif
