#include "BlackBoard.h"
#include <string>

void BlackBoard::CreateInt(std::string name, int value)
{
   intMap_.insert(std::pair<std::string, int>(name, value));
}

void BlackBoard::ChangeInt(std::string name, int value)
{
   intMap_[name] = value;
}

int BlackBoard::GetInt(std::string name)
{
   return intMap_[name];
}

void BlackBoard::CreateVect(std::string name, Vector2 value)
{
   vecMap_.insert(std::pair<std::string, Vector2>(name, value));
}

void BlackBoard::ChangeVect(std::string name, Vector2 value)
{
   vecMap_[name] = value;
}

Vector2 BlackBoard::GetVect(std::string name)
{
   return vecMap_[name];
}

void BlackBoard::CreateAgent(std::string name, Agent* value)
{
   agentMap_.insert(std::pair<std::string, Agent*>(name, value));
}

void BlackBoard::ChangeAgent(std::string name, Agent* value)
{
   agentMap_[name] = value;
}

Agent* BlackBoard::GetAgent(std::string name)
{
   return agentMap_[name];
}

BlackBoard::~BlackBoard()
{
   if (agentMap_.size() == 0)
   {
      return;
   }
   for (int i = 2; i < agentMap_.size() - 1; i++)
   {
      std::string index = std::to_string(i);
      agentMap_.at(index) = nullptr;
   }
}
