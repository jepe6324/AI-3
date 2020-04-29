// SetGoal.h

#ifndef SET_GOAL_H_INCLUDED
#define SET_GOAL_H_INCLUDED

#include "BTNode.h"

struct BlackBoard;

struct SetGoal : Node
{
   SetGoal(BlackBoard* bb) :Node(bb) {};
   Result Run();
};

#endif // !SET_GOAL_H_INCLUDED
