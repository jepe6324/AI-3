// BTNode.H

#ifndef BT_NODE_H_INCLUDED
#define BT_NODE_H_INCLUDED

struct BlackBoard;

struct Node
{
   enum Result
   {
      SUCCESS,
      FAILURE,
      RUNNING,
   };
   Node(BlackBoard* bb);
   virtual ~Node() {};

   BlackBoard* bb_;
   int priority = 0;
   virtual Result Run() = 0;
};

#endif // !BT_NODE_H_INCLUDED
