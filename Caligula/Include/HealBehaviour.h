// HealBehaviour.h

#ifndef HEAL_BEHAVIOUR_H_INCLUDED
#define HEAL_BEHAVIOUR_H_INCLUDED

#include "BTComposites.h"
#include "Sequence.h"

struct HealBehaviour : Sequence
{
   HealBehaviour(BlackBoard* bb);
};

#endif // !HEAL_BEHAVIOUR_H_INCLUDED
