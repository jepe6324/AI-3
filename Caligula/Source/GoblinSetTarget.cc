#include "GoblinSetTarget.h"
#include "Vector.h"
#include <string>
#include <vector>
#include "Agent.h"

#include "Service.h"
#include "BlackBoard.h"

Node::Result GoblinSetTarget::Run()
{
   Agent* tank = Service<BlackBoard>::Get()->GetAgent("0");
   Agent* mage = Service<BlackBoard>::Get()->GetAgent("1");

   if (tank == nullptr && mage == nullptr)
   {
      bb_->ChangeInt("target", -1);
      return FAILURE;
   }

   // here range and enmity should be considered
   int enmityTank = bb_->GetInt("tank");
   int enmityMage = bb_->GetInt("mage");
   Vector2 tankPos = Vector2(1234567, 1234567);
   if (tank != nullptr)
   {
      tankPos = tank->blackBoard_.GetVect("position");
   }
   Vector2 magePos = Vector2(1234567, 1234567);
   if (mage != nullptr)
   {
      magePos = mage->blackBoard_.GetVect("position");
   }

   int distanceTank = Distance(bb_->GetVect("position"), tankPos);
   int distanceMage = Distance(bb_->GetVect("position"), magePos);

   enmityTank -= distanceTank / 10;
   enmityMage -= distanceMage / 10;

   if (enmityMage > enmityTank) // NOTE: This doesn't check if they are alive or not
   {
      bb_->ChangeInt("target", 1);
   }
   else
   {
      bb_->ChangeInt("target", 0);
   }
   // Something along these lines
   return SUCCESS;
}