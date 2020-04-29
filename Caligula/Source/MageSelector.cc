#include "..\Include\MageSelector.h"

MageSelector::MageSelector(BlackBoard* bb) :Selector(bb)
{
   Add(new HealBehaviour(bb));
   Add(new MoveBehaviour(bb));
   Add(new HumanAttackBehaviour(bb));
   Add(new MoveBehaviour(bb));
}
