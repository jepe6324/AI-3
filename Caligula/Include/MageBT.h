// MageBT.h

#ifndef MAGE_B_T_H_INCLUDED
#define MAGE_B_T_H_INCLUDED

#include "BehaviourTree.h"

struct BlackBoard;

struct MageBehaviourTree : BehaviourTree
{
   MageBehaviourTree(BlackBoard* bb);
};

#endif // !MAGE_B_T_H_INCLUDED
