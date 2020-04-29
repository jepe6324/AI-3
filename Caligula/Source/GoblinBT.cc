#include "GoblinBT.h"
#include "GoblinSelector.h"
#include "BehaviourTree.h"
#include "BlackBoard.h"
#include "BTNode.h"

GoblinBehaviourTree::GoblinBehaviourTree(BlackBoard* bb, int id)
{
   startingNode_ = new GoblinSelector(bb);
   bb->CreateInt("health", 100);
   bb->CreateInt("damage", 10);
   bb->CreateInt("range", 32);
   bb->CreateInt("moveSpeed", 40);
   bb->CreateInt("id", id);
}