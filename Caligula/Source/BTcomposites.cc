#include "BTComposites.h"
#include "BlackBoard.h"

void CompositeNode::Add(Node* node)
{
   children_.push_back(node);
}

Node::Result Sequence::Run()
{
   Result ret = SUCCESS;
   for (Node* node : children_)
   {
      ret = node->Run();
      if (ret != SUCCESS)
      {
         break;
      }
   }
   return ret;
}

Node::Result Selector::Run()
{
   Result ret = FAILURE;
   for (Node* node : children_)
   {
      ret = node->Run();
      if (ret != FAILURE)
      {
         break;
      }
   }
   return ret;
}

Node::Result Parallel::Run()
{
   for (Node* node : children_)
   {
      node->Run();
   }
   return SUCCESS;
}