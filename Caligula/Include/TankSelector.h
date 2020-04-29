// TankSelector.h

#ifndef TANK_SELECTOR_H_INCLUDED
#define TANK_SELECTOR_H_INCLUDED

#include "Selector.h"
#include "TauntBehaviour.h"
#include "HumanAttackBehaviour.h"
#include "MoveBehaviour.h"

struct TankSelector : Selector
{
   TankSelector(BlackBoard* bb);
};

#endif // !TANK_SELECTOR_H_INCLUDED
