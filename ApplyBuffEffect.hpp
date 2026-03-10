#ifndef APPLYBUFFEFFECT_H
#define APPLYBUFFEFFECT_H

#include "Effect.hpp"
#include "Buff.hpp"
#include <memory>

using BuffPtr = std::shared_ptr<Buff>;

class ApplyBuffEffect : public Effect
{
private:
    BuffPtr buff;

public:
    ApplyBuffEffect(BuffPtr buffEffect);

    void apply(Battle& battle, CharPtr actor, CharPtr target) ;

    std::string getDescription() const ;
};

#endif


