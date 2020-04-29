#include "Parallel.h"

Node::Result Parallel::Run()
{
   for (Node* node : children_)
   {
      node->Run();
   }
   return SUCCESS;
}