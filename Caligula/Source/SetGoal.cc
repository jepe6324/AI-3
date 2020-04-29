#include "SetGoal.h"
#include "Vector.h"
#include <string>
#include <vector>
#include "Agent.h"

#include "Service.h"
#include "DeltaTime.h"
#include "BlackBoard.h"

Node::Result SetGoal::Run()
{

   std::string targetIndex = std::to_string(bb_->GetInt("target"));
   Agent* target = Service<BlackBoard>::Get()->GetAgent(targetIndex);
   if (target != nullptr)
   {
      Vector2 goal = target->blackBoard_.GetVect("position");
      bb_->ChangeVect("goal", goal);
      return SUCCESS;
   }
   return FAILURE;
}