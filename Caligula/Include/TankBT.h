// TankBT.h

#ifndef TANK_B_T_H_INCLUDED
#define TANK_B_T_H_INCLUDED

#include "BehaviourTree.h"

struct BlackBoard;

struct TankBehaviourTree : BehaviourTree
{
   TankBehaviourTree(BlackBoard* bb);
};

#endif // !TANK_B_T_H_INCLUDED
