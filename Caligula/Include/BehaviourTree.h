// BehaviourTree.h

#ifndef BEHAVIOUR_TREE_H_INCLUDED
#define BEHAVIOUR_TREE_H_INCLUDED

#include "BTNode.h"

struct BehaviourTree
{
   Node* startingNode_;

   ~BehaviourTree();

   void Run();
};

struct MageBehaviourTree : BehaviourTree
{
   MageBehaviourTree(BlackBoard* bb);
};

struct TankBehaviourTree : BehaviourTree
{
   TankBehaviourTree(BlackBoard* bb);
};

struct GoblinBehaviourTree : BehaviourTree
{
   GoblinBehaviourTree(BlackBoard* bb, int id);
};

#endif // !BEHAVIOUR_TREE_H_INCLUDED
