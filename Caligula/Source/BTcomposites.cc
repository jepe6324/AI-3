#include "BTComposites.h"

void CompositeNode::Add(Node* node)
{
   children_.push_back(node);
}