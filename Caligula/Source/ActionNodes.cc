#include "ActionNodes.h"

#include "Vector.h"
#include "Random.h"

#include "Service.h"
#include "DeltaTime.h"

//#include <iostream> // DEBUG This shit did some bad stuff to things

TestWalk::TestWalk(BlackBoard* bb)
   :timer_(.5f)
{
   bb_ = bb;
}

Result TestWalk::Run()
{
   Vector2 pos = bb_->GetVect("position");
   pos += bb_->GetVect("direction") * Service<DeltaTime>::Get()->AsSeconds() * 10;
   //std::cout << pos.x_ << std::endl;
   bb_->ChangeVect("position", pos);
   return RUNNING;
}

TestWalkDir::TestWalkDir(BlackBoard* bb)
   :timer_(1)
{  //This node should basically verify that a random direction is to walk to is a valid position.
   bb_ = bb;

   bb->CreateVect("direction", Vector2(.0f,.0f));
}

Result TestWalkDir::Run()
{
   if (timer_.IsDone())
   {
      timer_.Reset();
      Vector2 dir = Vector2(Random::Randf(-1.f, 1.f), Random::Randf(-1.f, 1.f));
      dir.Normalize();
      bb_->ChangeVect("direction", dir);
   }
   else if (bb_->GetVect("direction") == Vector2(.0f, .0f))
      return SUCCESS;
   return SUCCESS;
}
