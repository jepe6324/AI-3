// Heal.h

#ifndef HEAL_H_INCLUDED
#define HEAL_H_INCLUDED

#include "BTNode.h"
#include "Timer.h"

struct BlackBoard;

struct Heal : Node
{
   Timer timer_;

   Heal(BlackBoard* bb) :Node(bb), timer_(1) {};
   Result Run();
};

#endif // !HEAL_H_INCLUDED
