// GoblinSelector.h

#ifndef GOBLIN_SELECTOR_H_INCLUDED
#define GOBLIN_SELECTOR_H_INCLUDED

#include "Selector.h"
#include "GoblinAttackBehaviour.h"
#include "MoveBehaviour.h"

struct GoblinSelector : Selector
{
   GoblinSelector(BlackBoard* bb);
};

#endif // !GOBLIN_SELECTOR_H_INCLUDED
