// BehaviourTree.h

#ifndef BEHAVIOUR_TREE_H_INCLUDED
#define BEHAVIOUR_TREE_H_INCLUDED

struct Node;
struct BlackBoard;

struct BehaviourTree
{
   Node* startingNode_;

   ~BehaviourTree();

   void Run();
};

#endif // !BEHAVIOUR_TREE_H_INCLUDED
