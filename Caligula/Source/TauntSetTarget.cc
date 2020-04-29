#include "TauntSetTarget.h"
#include "Vector.h"
#include <string>
#include "Agent.h"

#include "Service.h"
#include "BlackBoard.h"

Node::Result TauntSetTarget::Run()
{
   int targetIndex = -1;
   for (int i = 0; i < 10; i++) // gonna put a hard limit on the max amount of goblnis to 10
   {
      std::string index = std::to_string(i + 2); // might need to change this to +3
      Agent* target = Service<BlackBoard>::Get()->GetAgent(index);
      if (target == nullptr)
      {
         continue;
      }
      else if (target->blackBoard_.GetInt("target") == 1)
      {
         targetIndex = i + 2;
      }
   }
   if (targetIndex != -1)
   {
      bb_->ChangeInt("target", targetIndex);
      return SUCCESS;
   }
   bb_->ChangeInt("target", -1);
   return FAILURE;
}