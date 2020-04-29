#include "Taunt.h"
#include "Vector.h"
#include <string>
#include <vector>
#include "Agent.h"

#include "Service.h"
#include "DeltaTime.h"
#include "BlackBoard.h"

Node::Result Taunt::Run()
{
   bb_->ChangeInt("red", 255);
   bb_->ChangeInt("green", 255);
   bb_->ChangeInt("blue", 0);

   if (timer_.IsDone())
   {
      // Somehow get every target in range of the taunt and increase their enmity toward the tank by 10.
      std::vector<Agent*> goblins;
      for (int i = 0; i < 10; i++) // gonna put a hard limit on the max amount of goblnis to 10
      {
         std::string index = std::to_string(i + 2); // might need to change this to +3
         Agent* target = Service<BlackBoard>::Get()->GetAgent(index);
         if (target == nullptr)
         {
            continue;
         }
         float distance = Distance(target->blackBoard_.GetVect("position"), bb_->GetVect("position"));
         if (distance <= bb_->GetInt("tauntRange"))
         {
            goblins.push_back(target);
         }
      }
      if (goblins.empty())
      {
         return FAILURE;
      }

      for (Agent* goblin : goblins)
      {
         int enmity = goblin->blackBoard_.GetInt("tank");
         goblin->blackBoard_.ChangeInt("tank", enmity + 10);
      }
      timer_.Reset();
      bb_->ChangeInt("target", -1);
      return SUCCESS;
   }
   return FAILURE;
}