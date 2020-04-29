// Attack.h

#ifndef ATTACK_H_INCLUDED
#define ATTACK_H_INCLUDED

#include "BTNode.h"
#include "Timer.h"

struct BlackBoard;

struct Attack : Node
{
   Timer timer_;

   Attack(BlackBoard* bb) :Node(bb), timer_(.5f, true) {};
   Result Run();
};

#endif // !ATTACK_H_INCLUDED
