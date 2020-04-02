// ActionNodes.h

#ifndef ACTION_NODES_H_INCLUDED
#define ACTION_NODES_H_INCLUDED

#include "BTNode.h"
#include "Timer.h"

struct HumanSetTarget : Node
{
   HumanSetTarget(BlackBoard* bb) :Node(bb) {};
   Result Run();
};

struct GoblinSetTarget : Node
{
   GoblinSetTarget(BlackBoard* bb) :Node(bb) {};
   Result Run();
};

struct HealSetTarget : Node
{ // The thing the healer uses to check if it can heal.
   HealSetTarget(BlackBoard* bb) :Node(bb) {};
   Result Run();
};

struct TauntSetTarget : Node
{ // The thing that the tank uses when it knows it wants to rage
  // Will see if the healer is being targeted somehow, if they are he will go and taunt in range of that enemy.
   TauntSetTarget(BlackBoard* bb) :Node(bb) {};
   Result Run();
};

struct Attack : Node
{
   Timer timer_;
  
   Attack(BlackBoard* bb) :Node(bb), timer_(.5f, true) {};
   Result Run();
};

struct SetGoal : Node
{
   SetGoal(BlackBoard* bb) :Node(bb) {};
   Result Run();
};

struct Walk : Node
{
   Walk(BlackBoard* bb) :Node(bb) {};
   Result Run();
};

struct Heal : Node
{
   Timer timer_;

   Heal(BlackBoard* bb) :Node(bb), timer_(1) {};
   Result Run();
};

struct Taunt : Node
{
   Timer timer_;
   
   Taunt(BlackBoard* bb) :Node(bb), timer_(0) {};
   Result Run();
};
#endif // !ACTION_NODES_H_INCLUDED
