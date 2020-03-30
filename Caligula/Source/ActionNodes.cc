#include "ActionNodes.h"

#include "Vector.h"

TestWalk::TestWalk(BlackBoard* bb)
   :timer_(.5f)
{
   bb_ = bb;
}

Result TestWalk::Run()
{
   if (timer_.IsDone())
   {
      timer_.Reset();
      Vector2 pos = bb_->GetVect("position");
      pos.x_++;
      bb_->ChangeVect("position", pos);
      return SUCCESS;
   }
   return RUNNING;
}
