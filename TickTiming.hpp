#pragma once

// TickTiming: Determines at which point in a turn a StatusEffect triggers its onTick().
// Used by: StatusEffect (stores timing as a member, getTiming() returns it),
//          Character (tickStatuses receives TickTiming as a parameter to filter which statuses fire),
//          PlayerCharacter (onTurnStart/onTurnEnd pass TickTiming::TurnStart / TickTiming::TurnEnd),
//          OpponentCharacter (same as PlayerCharacter),
//          PoisonStatus (constructor passes TickTiming::TurnEnd to StatusEffect base),
//          StunStatus (constructor passes TickTiming::TurnStart to StatusEffect base),
//          OverencumberedStatus (constructor passes TickTiming::TurnStart to StatusEffect base)
// Dependency on other classes: NONE - pure enum, no includes required.
// NOTE: Previously declared inside StatusEffect.hpp; extracted here for consistency
//       with the project's one-class-per-file convention. StatusEffect.hpp should now
//       include this file instead of re-declaring TickTiming inline.

enum class TickTiming {
    TurnStart,
    TurnEnd,
    Immediate
};