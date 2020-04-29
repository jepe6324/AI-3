// Taunt.h

#ifndef TAUNT_H_INCLUDED
#define TAUNT_H_INCLUDED

#include "BTNode.h"
#include "Timer.h"

struct BlackBoard;

struct Taunt : Node
{
   Timer timer_;

   Taunt(BlackBoard* bb) :Node(bb), timer_(0) {};
   Result Run();
};

#endif // !TAUNT_H_INCLUDED
