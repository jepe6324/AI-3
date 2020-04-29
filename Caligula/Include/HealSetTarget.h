// HealSetTarget.h

#ifndef HEAL_SET_TARGET_H_INCLUDED
#define HEAL_SET_TARGET_H_INCLUDED

#include "BTNode.h"

struct BlackBoard;

struct HealSetTarget : Node
{ // The thing the healer uses to check if it can heal.
   HealSetTarget(BlackBoard* bb) :Node(bb) {};
   Result Run();
};

#endif // !HEAL_SET_TARGET_H_INCLUDED
