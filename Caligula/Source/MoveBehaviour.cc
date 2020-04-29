#include "MoveBehaviour.h"
#include "BTComposites.h"
#include "SetGoal.h"
#include "Walk.h"

MoveBehaviour::MoveBehaviour(BlackBoard* bb)
   : Sequence(bb)
{
   Add(new SetGoal(bb));
   Add(new Walk(bb));
}