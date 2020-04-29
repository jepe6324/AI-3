#include "..\Include\GoblinSelector.h"

GoblinSelector::GoblinSelector(BlackBoard* bb) :Selector(bb)
{
   Add(new GoblinAttackBehaviour(bb));
   Add(new MoveBehaviour(bb));
}
