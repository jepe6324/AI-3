#include "HealSetTarget.h"
#include "Vector.h"
#include <string>
#include <vector>
#include "Agent.h"

#include "Service.h"
#include "DeltaTime.h"
#include "BlackBoard.h"

Node::Result HealSetTarget::Run()
{ // Lets say max health is 100
   Agent* tank = Service<BlackBoard>::Get()->GetAgent("0");
   if (tank != nullptr)
   {
      int tankHealth = Service<BlackBoard>::Get()->GetAgent("0")->blackBoard_.GetInt("health");
      if (tankHealth < ( 100 - bb_->GetInt("heal") )) // Healer will never overheal.
      {
         bb_->ChangeInt("target", 0);
         return SUCCESS;
      }
   }
   else
   {
      int breakpoint = 0;
      breakpoint++;
   }

   int mageHealth = bb_->GetInt("health");
   if (mageHealth < ( 100 - bb_->GetInt("heal") ))
   {
      bb_->ChangeInt("target", 1);
      return SUCCESS;
   }
   bb_->ChangeInt("target", -1);
   return FAILURE;
}