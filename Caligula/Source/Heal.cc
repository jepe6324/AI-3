#include "Heal.h"
#include "Vector.h"
#include <string>
#include "Agent.h"

#include "Service.h"
#include "BlackBoard.h"

Node::Result Heal::Run()
{ // Note add range check for this one
   bb_->ChangeInt("red", 0);
   bb_->ChangeInt("green", 255);
   bb_->ChangeInt("blue", 0);

   if (timer_.IsDone())
   {
      std::string targetIndex = std::to_string(bb_->GetInt("target"));
      Agent* target = Service<BlackBoard>::Get()->GetAgent(targetIndex);
      if (target == nullptr)
      {
         return FAILURE;
      }
      float distance = Distance(bb_->GetVect("position"), target->blackBoard_.GetVect("position"));
      if (distance <= bb_->GetInt("healRange"))
      {
         int health = target->blackBoard_.GetInt("health");
         int healing = bb_->GetInt("heal");
         target->blackBoard_.ChangeInt("health", health + healing);

         timer_.Reset();
         bb_->ChangeInt("target", -1);
         return SUCCESS;
      }
   }
   return FAILURE;
}