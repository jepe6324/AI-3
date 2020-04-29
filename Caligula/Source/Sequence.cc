#include "Sequence.h"

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