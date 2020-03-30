// ActionNodes.h

#ifndef ACTION_NODES_H_INCLUDED
#define ACTION_NODES_H_INCLUDED

#include "BehaviourTree.h"
#include "Timer.h"

struct TestWalk : Node
{
   Timer timer_;

   TestWalk(BlackBoard* bb);
   Result Run();
};

struct TestWalkDir : Node
{
   Timer timer_;

   TestWalkDir(BlackBoard* bb);
   Result Run();
};
#endif // !ACTION_NODES_H_INCLUDED
