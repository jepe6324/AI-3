// HumanAttackBehaviour.h

#ifndef HUMAN_ATTACK_BEHAVIOUR_H_INCLUDED
#define HUMAN_ATTACK_BEHAVIOUR_H_INCLUDED

#include "BTComposites.h"
#include "Sequence.h"

struct HumanAttackBehaviour : Sequence
{
   HumanAttackBehaviour(BlackBoard* bb);
};

#endif // !HUMAN_ATTACK_BEHAVIOUR_H_INCLUDED
