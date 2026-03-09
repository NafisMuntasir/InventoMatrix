#ifndef APPLYBUFFEFFECT_H
#define APPLYBUFFEFFECT_H

#include "Effect.h"
#include "Buff.h"
#include <memory>

using BuffPtr = std::shared_ptr<Buff>;

class ApplyBuffEffect : public Effect
{
private:
    BuffPtr buff;

public:
    ApplyBuffEffect(BuffPtr buffEffect);

    void apply(Battle& battle, CharPtr actor, CharPtr target) override;

    std::string getDescription() override;
};

#endif


