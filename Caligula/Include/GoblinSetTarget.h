// GoblinSetTarget.h

#ifndef GOBLIN_SET_TARGET_H_INCLUDED
#define GOBLIN_SET_TARGET_H_INCLUDED

#include "BTNode.h"

struct BlackBoard;

struct GoblinSetTarget : Node
{
   GoblinSetTarget(BlackBoard* bb) :Node(bb) {};
   Result Run();
};

#endif // !GOBLIN_SET_TARGET_H_INCLUDED
