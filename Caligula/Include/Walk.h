// Walk.h

#ifndef WALK_H_INCLUDED
#define WALK_H_INCLUDED

#include "BTNode.h"

struct BlackBoard;

struct Walk : Node
{
   Walk(BlackBoard* bb) :Node(bb) {};
   Result Run();
};

#endif // !WALK_H_INCLUDED
