// Sequencers.h

#ifndef SEQUENCERS_H_INCLUDED
#define SEQUENCERS_H_INCLUDED

#include "BTNode.h"
#include "BTComposites.h"
#include "ActionNodes.h"

struct HealBehaviour : Sequence
{
   HealBehaviour(BlackBoard* bb)
      :Sequence(bb)
   {
      Add(new HealSetTarget(bb));
      Add(new Heal(bb));
   }
};

struct TauntBehaviour : Sequence
{
   TauntBehaviour(BlackBoard* bb)
      : Sequence(bb)
   {
      Add(new TauntSetTarget(bb));
      Add(new Taunt(bb));
   }
};

struct HumanAttackBehaviour : Sequence
{
   HumanAttackBehaviour(BlackBoard* bb)
      : Sequence(bb)
   {
      Add(new HumanSetTarget(bb));
      Add(new Attack(bb));
   }
};

struct GoblinAttackBehaviour : Sequence
{
   GoblinAttackBehaviour(BlackBoard* bb)
      :Sequence(bb)
   {
      Add(new GoblinSetTarget(bb));
      Add(new Attack(bb));
   }
};

struct MoveBehaviour : Sequence
{
   MoveBehaviour(BlackBoard* bb)
      : Sequence(bb)
   {
      Add(new SetGoal(bb));
      Add(new Walk(bb));
   }
};

#endif // !SEQUENCERS_H_INCLUDED
