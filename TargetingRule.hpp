#ifndef TARGETINGRULE_H
#define TARGETINGRULE_H

// =========================
// TargetingRule
// =========================
// Abstract interface for selecting valid targets for a Skill.
// Derived classes implement their own targeting logic (e.g. allies,
// enemies, self, etc.).

#include "Types.hpp"
#include <vector>

class Battle;

class Battle;
class Character;
class Party;

class TargetingRule {
public:
    TargetingRule() = default;
    virtual ~TargetingRule() = default;

    // Returns a list of valid target characters for the given actor.
    virtual std::vector<CharPtr> validTargets(const CharPtr& actor, Battle& battle) const = 0;

    // Optional helpers for UI or validation.
    virtual bool canTargetEnemies() const { return false; }
    virtual bool canTargetAllies() const { return false; }

    // Legacy helpers (optional) for simplified targeting.
    virtual void applyRule(Battle& battle, Character& actor, Party& target);
    virtual bool validateTarget(const Party& target) const;
};

#endif
