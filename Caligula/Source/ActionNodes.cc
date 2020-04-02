#include "ActionNodes.h"

#include "Vector.h"
#include "Random.h"
#include <string>
#include <vector>
#include "Agent.h"

#include "Service.h"
#include "DeltaTime.h"
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
   if (distance < (moveSpeed * dt))
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
   if (mageHealth < (100 - bb_->GetInt("heal") ))
   {
      bb_->ChangeInt("target", 1);
      return SUCCESS;
   }
   bb_->ChangeInt("target", -1);
   return FAILURE;
}

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
