#include "GoblinAttackBehaviour.h"
#include "BTComposites.h"
#include "GoblinSetTarget.h"
#include "Attack.h"

GoblinAttackBehaviour::GoblinAttackBehaviour(BlackBoard* bb)
   :Sequence(bb)
{
   Add(new GoblinSetTarget(bb));
   Add(new Attack(bb));
}