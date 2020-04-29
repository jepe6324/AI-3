// Sequence.h

#ifndef SEQUENCE_H_INCLUDED
#define SEQUENCE_H_INCLUDED

#include "BTComposites.h"

struct Sequence : CompositeNode
{
   Sequence(BlackBoard* bb) : CompositeNode(bb) { };

   Result Run();
};

#endif // !SEQUENCE_H_INCLUDED
