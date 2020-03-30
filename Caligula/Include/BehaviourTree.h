// BehaviourTree.h

#ifndef BEHAVIOUR_TREE_H_INCLUDED
#define BEHAVIOUR_TREE_H_INCLUDED

#include "BlackBoard.h"

enum Result
{
   SUCCESS,
   FAILURE,
   RUNNING,
};

#pragma region BaseNodes

struct Node
{
   BlackBoard* bb_;
   int priority = 0;
   virtual Result Run() = 0;
};

struct CompositeNode : Node
{
   std::vector<Node*> children_;

   void Add(Node* node)
   {
      children_.push_back(node);
   }
};

struct DecoratorNode : Node
{
   Node* child_;

   void SetChild(Node* node)
   {
      child_ = node;
   }
};

#pragma endregion BaseNodes

#pragma region Composite
struct Sequence : CompositeNode
{
   Result Run()
   {
      Result ret = SUCCESS;
      for (Node* node : children_)
      {
         ret = node->Run();
         if (ret != SUCCESS)
         {
            break;
         }
      }
      return ret;
   }
};

struct Selector : CompositeNode
{
   Result Run()
   {
      Result ret = FAILURE;
      for (Node* node : children_)
      {
         ret = node->Run();
         if (ret != FAILURE)
         {
            break;
         }
      }
      return ret;
   }
};

struct Parallel : CompositeNode
{
   Result Run()
   {
      for (Node* node : children_)
      {
         node->Run();
      }
      return SUCCESS;
   }
};

#pragma endregion Composite

#pragma region Decorators

struct AlwaysSucceed : DecoratorNode
{
   Result Run()
   {
      child_->Run();
      return SUCCESS;
   }
};

struct Inverter : DecoratorNode
{
   Result Run()
   {
      Result result = child_->Run();
      if (result == SUCCESS)
      {
         return FAILURE;
      }
      else if (result == FAILURE)
      {
         return SUCCESS;
      }
   }
};

#pragma endregion Decorators

#endif // !BEHAVIOUR_TREE_H_INCLUDED
