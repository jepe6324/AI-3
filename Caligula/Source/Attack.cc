#include "Attack.h"
#include "Vector.h"
#include <string>
#include "Agent.h"

#include "Service.h"
#include "DeltaTime.h"
#include "BlackBoard.h"

Node::Result Attack::Run()
{
   bb_->ChangeInt("red", 255);
   bb_->ChangeInt("green", 0);
   bb_->ChangeInt("blue", 0);

   if (timer_.paused_ == true)
   {
      timer_.Reset();
      timer_.Start();
   }

   if (timer_.IsDone())
   { // Note add range check for this one
      std::string targetIndex = std::to_string(bb_->GetInt("target"));
      Agent* target = Service<BlackBoard>::Get()->GetAgent(targetIndex);
      if (target == nullptr)
      {
         return FAILURE;
      }
      float distance = Distance(target->blackBoard_.GetVect("position"), bb_->GetVect("position"));
      if (distance <= bb_->GetInt("range"))
      {
         int health = target->blackBoard_.GetInt("health");
         int damage = bb_->GetInt("damage");
         target->blackBoard_.ChangeInt("health", health - damage);

         if (bb_->GetInt("id") == 0) // 0 is for tank
         {
            int enmity = target->blackBoard_.GetInt("tank");
            target->blackBoard_.ChangeInt("tank", enmity + 5);
         }
         else if (bb_->GetInt("id") == 1) // 1 is for healer anything else is a gnoblin.
         {
            int enmity = target->blackBoard_.GetInt("mage");
            target->blackBoard_.ChangeInt("mage", enmity + 5);
         }

         timer_.Reset();
         timer_.Pause();
         bb_->ChangeInt("target", -1);
         return SUCCESS;
      }
      else
      {
         return FAILURE;
      }
   }
   return RUNNING;
}