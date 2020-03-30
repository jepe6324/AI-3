#include "BlackBoard.h"

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

void BlackBoard::CreateBB(std::string name, BlackBoard* value)
{
   bbMap_.insert(std::pair<std::string, BlackBoard*>(name, value));
}

void BlackBoard::ChangeBB(std::string name, BlackBoard* value)
{
   bbMap_[name] = value;
}

BlackBoard* BlackBoard::GetBB(std::string name)
{
   return bbMap_[name];
}
