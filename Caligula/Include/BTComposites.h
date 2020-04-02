// BTComposites.h

#ifndef BT_COMPOSITES_H_INCLUDED
#define BT_COMPOSITES_H_INCLUDED

#include "BTNode.h"
#include <vector>
// Base Node

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

// Composite Nodes

struct Sequence : CompositeNode
{
   Sequence(BlackBoard* bb) : CompositeNode(bb) { };

   Result Run();
};

struct Selector : CompositeNode
{
   Selector(BlackBoard* bb) : CompositeNode(bb) { };

   Result Run();
};

struct Parallel : CompositeNode
{
   Parallel(BlackBoard* bb) : CompositeNode(bb) { };

   Result Run();
};

#endif // !BT_COMPOSITES_H_INCLUDED
