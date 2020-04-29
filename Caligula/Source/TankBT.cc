#include "TankBT.h"
#include "TankSelector.h"
#include "BehaviourTree.h"
#include "BlackBoard.h"
#include "BTNode.h"
TankBehaviourTree::TankBehaviourTree(BlackBoard* bb)
{
   startingNode_ = new TankSelector(bb);
   bb->CreateInt("health", 100);
   bb->CreateInt("tauntRange", 32 * 2);
   bb->CreateInt("damage", 30);
   bb->CreateInt("range", 32);
   bb->CreateInt("moveSpeed", 32);
   bb->CreateInt("id", 0);
}