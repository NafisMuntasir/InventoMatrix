#pragma once

// =========================
// OpponentParty
// =========================
// Concrete Party for AI-controlled enemies.
// Supports up to 6 members (default) and coordinates
// unit behaviour via a shared AIController.
// Individual members may also carry their own AI.

#include "Party.hpp"
#include <memory>

class AIController;

class OpponentParty : public Party {
private:
    std::shared_ptr<AIController> aiController;

public:
    // Constructor
    OpponentParty(std::string name, int id, int maxSize = 6);

    // Getters
    std::shared_ptr<AIController> getAI() const;

    // Setters
    void setAI(std::shared_ptr<AIController> ai);

    // Methods (polymorphism)
    void executeTurn(Battle& battle) override;
    void onTurnStart(Battle& battle) override;
    void onTurnEnd(Battle& battle)   override;
    bool isPlayerParty()       const override;
};
