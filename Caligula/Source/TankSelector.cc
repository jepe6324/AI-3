#include "..\Include\TankSelector.h"

TankSelector::TankSelector(BlackBoard* bb) :Selector(bb)
{
   Add(new TauntBehaviour(bb));
   Add(new MoveBehaviour(bb));
   Add(new HumanAttackBehaviour(bb));
   Add(new MoveBehaviour(bb));
}