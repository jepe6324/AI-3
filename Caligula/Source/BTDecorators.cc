#include "BTDecorators.h"

void DecoratorNode::SetChild(Node* node)
{
   child_ = node;
}

Node::Result AlwaysSucceed::Run()
{
   child_->Run();
   return Result::SUCCESS;
}

Node::Result Inverter::Run()
{
   Result result = child_->Run();
   if (result == Result::SUCCESS)
   {
      return Result::FAILURE;
   }
   else if (result == Result::FAILURE)
   {
      return Result::SUCCESS;
   }
}
