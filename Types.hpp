#pragma once

// =========================
// Shared Type Aliases
// =========================
// This header is intended to provide common forward declarations and
// shared smart-pointer type aliases used across the project.

#include <memory>
#include <vector>

// Forward declarations
class Battle;
class Character;
class Party;
class Action;
class Skill;
class Effect;
class StatusEffect;
class Buff;
class TargetingRule;
class BattleRules;
class TurnManager;
class AIController;
class BattleLog;

// Convenience type aliases
using CharPtr   = std::shared_ptr<Character>;
using PartyPtr  = std::shared_ptr<Party>;
using ActPtr    = std::shared_ptr<Action>;
using SkillPtr  = std::shared_ptr<Skill>;
using EffPtr    = std::shared_ptr<Effect>;
using StatusPtr = std::shared_ptr<StatusEffect>;
using BuffPtr   = std::shared_ptr<Buff>;
