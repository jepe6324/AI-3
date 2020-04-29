
#include "TankSelector.h"
#include "MageSelector.h"
#include "GoblinSelector.h"
#include "BehaviourTree.h"
#include "BlackBoard.h"
#include "BTNode.h"

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
