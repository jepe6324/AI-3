// BTComposites.h

#ifndef BT_COMPOSITES_H_INCLUDED
#define BT_COMPOSITES_H_INCLUDED

#include "BTNode.h"
#include <vector>

struct CompositeNode : Node
{
   std::vector<Node*> children_;

   CompositeNode(BlackBoard* bb) : Node(bb) { };
   ~CompositeNode()
   {
      for (Node* node : children_)
      {
         delete node;
         node = nullptr;
      }
      children_.clear();
   }

   void Add(Node* node);
};
#endif // !BT_COMPOSITES_H_INCLUDED
