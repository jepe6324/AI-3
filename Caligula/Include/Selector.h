// Selector.h

#ifndef SELECTOR_H_INCLUDED
#define SELECTOR_H_INCLUDED

#include "BTComposites.h"

struct Selector : CompositeNode
{
   Selector(BlackBoard* bb) : CompositeNode(bb) { };

   Result Run();
};

#endif // !SELECTOR_H_INCLUDED
