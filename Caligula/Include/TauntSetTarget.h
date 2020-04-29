// TauntSetTarget.h

#ifndef TAUNT_SET_TARGET_H_INCLUDED
#define TAUNT_SET_TARGET_H_INCLUDED

#include "BTNode.h"

struct BlackBoard;

struct TauntSetTarget : Node
{ // The thing that the tank uses when it knows it wants to rage
  // Will see if the healer is being targeted somehow, if they are he will go and taunt in range of that enemy.
   TauntSetTarget(BlackBoard* bb) :Node(bb) {};
   Result Run();
};

#endif // !TAUNT_SET_TARGET_H_INCLUDED
