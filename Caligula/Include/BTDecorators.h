// BTDecorators.h

#ifndef BT_DECORATORS_H_INCLUDED
#define BT_DECORATORS_H_INCLUDED

#include "BTNode.h"

// Base Node

struct DecoratorNode : Node
{
   Node* child_;

   void SetChild(Node* node);
};

// Decorators

struct AlwaysSucceed : DecoratorNode
{
   Result Run();
};

struct Inverter : DecoratorNode
{
   Result Run();
};

#endif // !BT_DECORATORS_H_INCLUDED
