// Parallel.h

#ifndef PARALLEL_H_INCLUDED
#define PARALLEL_H_INCLUDED

#include "BTComposites.h"

struct Parallel : CompositeNode
{
   Parallel(BlackBoard* bb) : CompositeNode(bb) { };

   Result Run();
};

#endif // !PARALLEL_H_INCLUDED
