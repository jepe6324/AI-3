#include "TauntBehaviour.h"
#include "BTComposites.h"
#include "TauntSetTarget.h"
#include "Taunt.h"

TauntBehaviour::TauntBehaviour(BlackBoard* bb)
   : Sequence(bb)
{
   Add(new TauntSetTarget(bb));
   Add(new Taunt(bb));
}