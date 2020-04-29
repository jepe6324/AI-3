#include "HumanSetTarget.h"
#include "Vector.h"
#include <string>
#include <vector>
#include "Agent.h"

#include "Service.h"
#include "BlackBoard.h"

Node::Result HumanSetTarget::Run()
{  // Humans attack the closest goblin
   // I somehow need to get all living goblins to look at their blackboards
   std::vector<Agent*> goblins;
   for (int i = 0; i < 10; i++) // gonna put a hard limit on the max amount of goblnis to 10
   {
      std::string index = std::to_string(i + 2); // might need to change this to +3
      Agent* target = Service<BlackBoard>::Get()->GetAgent(index);
      if (target != nullptr)
      {
         goblins.push_back(target);
      }
   }
   int targetIndex = -1;
   float targetDistance = -1;
   for (Agent* goblin : goblins)
   {
      Vector2 tmpPos = goblin->blackBoard_.GetVect("position");
      float tmpDistance = Distance(tmpPos, bb_->GetVect("position"));
      if (tmpDistance < targetDistance || targetDistance == -1)
      {
         targetIndex = goblin->blackBoard_.GetInt("id");
         targetDistance = tmpDistance;
      }
   }
   if (targetIndex != -1)
   {
      bb_->ChangeInt("target", targetIndex);
      return SUCCESS;
   }

   // here range should be considered
   // Somehow decide a target and set it in bb_->ChangeInt("target"));
   bb_->ChangeInt("target", -1);
   return FAILURE;
}