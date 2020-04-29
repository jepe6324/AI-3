#include "Walk.h"
#include "Vector.h"
#include <string>
#include "Agent.h"

#include "Service.h"
#include "DeltaTime.h"
#include "BlackBoard.h"

Node::Result Walk::Run()
{
   bb_->ChangeInt("red", 255);
   bb_->ChangeInt("green", 255);
   bb_->ChangeInt("blue", 255);

   float dt = Service<DeltaTime>::Get()->AsSeconds();

   int moveSpeed = bb_->GetInt("moveSpeed");
   Vector2 pos = bb_->GetVect("position");
   Vector2 goal = bb_->GetVect("goal");
   Vector2 direction = goal - pos;
   float distance = Magnitude(direction);
   direction.Normalize();
   if (distance < ( moveSpeed * dt ))
   {
      pos += direction * moveSpeed * dt;
      bb_->ChangeVect("position", pos);
      //bb_->ChangeVect("position", goal);
      bb_->ChangeInt("target", -1);
      return SUCCESS;
   }
   else
   {
      pos += direction * moveSpeed * dt;
      bb_->ChangeVect("position", pos);
      return RUNNING;
   }
}