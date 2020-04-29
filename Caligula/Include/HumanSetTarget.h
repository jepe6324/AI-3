// HumanSetTarget.h

#ifndef HUMAN_SET_TARGET_H_INCLUDED
#define HUMAN_SET_TARGET_H_INCLUDED

#include "BTNode.h"

struct BlackBoard;

struct HumanSetTarget : Node
{
   HumanSetTarget(BlackBoard* bb) :Node(bb) {};
   Result Run();
};

#endif // !HUMAN_SET_TARGET_H_INCLUDED
