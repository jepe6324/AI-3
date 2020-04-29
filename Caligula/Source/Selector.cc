#include "Selector.h"

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