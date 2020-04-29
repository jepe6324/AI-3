// GoblinBT.h

#ifndef GOBLIN_B_T_H_INCLUDED
#define GOBLIN_B_T_H_INCLUDED

#include "BehaviourTree.h"

struct BlackBoard;

struct GoblinBehaviourTree : BehaviourTree
{
   GoblinBehaviourTree(BlackBoard* bb, int id);
};

#endif // !GOBLIN_B_T_H_INCLUDED
