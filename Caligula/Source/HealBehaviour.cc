#include "HealBehaviour.h"
#include "BTComposites.h"
#include "HealSetTarget.h"
#include "Heal.h"

HealBehaviour::HealBehaviour(BlackBoard* bb)
   :Sequence(bb)
{
   Add(new HealSetTarget(bb));
   Add(new Heal(bb));
}