// MageSelector.h

#ifndef MAGE_SELECTOR_H_INCLUDED
#define MAGE_SELECTOR_H_INCLUDED

#include "Selector.h"
#include "HealBehaviour.h"
#include "HumanAttackBehaviour.h"
#include "MoveBehaviour.h"

struct MageSelector : Selector
{
   MageSelector(BlackBoard* bb);
};

#endif // !MAGE_SELECTOR_H_INCLUDED
