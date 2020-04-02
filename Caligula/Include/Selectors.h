// Selectors.h

#ifndef SELECTORS_H_INCLUDED
#define SELECTORS_H_INCLUDED

#include "BTNode.h"
#include "BTComposites.h"
#include "Sequencers.h"

struct MageSelector : Selector
{
   MageSelector(BlackBoard* bb) :Selector(bb)
   {
      Add(new HealBehaviour(bb));
      Add(new MoveBehaviour(bb));
      Add(new HumanAttackBehaviour(bb));
      Add(new MoveBehaviour(bb));
   }
};

struct TankSelector : Selector
{
   TankSelector(BlackBoard* bb) :Selector(bb)
   {
      Add(new TauntBehaviour(bb));
      Add(new MoveBehaviour(bb));
      Add(new HumanAttackBehaviour(bb));
      Add(new MoveBehaviour(bb));
   }
};

struct GoblinSelector : Selector
{
   GoblinSelector(BlackBoard* bb) :Selector(bb)
   {
      Add(new GoblinAttackBehaviour(bb));
      Add(new MoveBehaviour(bb));
   }
};

#endif // !SELECTORS_H_INCLUDED
