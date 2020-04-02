#include "..\Include\BehaviourTree.h"
#include "Selectors.h"
#include "BlackBoard.h"
//#include "../Source/ActionNodes.cc"

BehaviourTree::~BehaviourTree()
{
   if (startingNode_ != nullptr)
   {
      delete startingNode_;
      startingNode_ = nullptr;
   }
}

void BehaviourTree::Run()
{
   if (startingNode_ != nullptr)
      startingNode_->Run();
}

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

GoblinBehaviourTree::GoblinBehaviourTree(BlackBoard* bb, int id)
{
   startingNode_ = new GoblinSelector(bb);
   bb->CreateInt("health", 100);
   bb->CreateInt("damage", 10);
   bb->CreateInt("range", 32);
   bb->CreateInt("moveSpeed", 40);
   bb->CreateInt("id", id);
}
