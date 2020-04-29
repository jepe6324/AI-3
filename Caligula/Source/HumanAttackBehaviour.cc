#include "HumanAttackBehaviour.h"
#include "BTComposites.h"
#include "HumanSetTarget.h"
#include "Attack.h"

HumanAttackBehaviour::HumanAttackBehaviour(BlackBoard* bb)
   : Sequence(bb)
{
   Add(new HumanSetTarget(bb));
   Add(new Attack(bb));
}