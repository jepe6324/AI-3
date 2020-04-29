#include "MageBT.h"
#include "MageSelector.h"
#include "BehaviourTree.h"
#include "BlackBoard.h"
#include "BTNode.h"

MageBehaviourTree::MageBehaviourTree(BlackBoard* bb)
{
   startingNode_ = new MageSelector(bb);
   bb->CreateInt("health", 100);
   bb->CreateInt("heal", 25);
   bb->CreateInt("healRange", 32 * 3);
   bb->CreateInt("damage", 20);
   bb->CreateInt("range", 32 * 3);
   bb->CreateInt("moveSpeed", 32);
   bb->CreateInt("id", 1);
}