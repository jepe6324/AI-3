#include "BlackBoard.h"

void BlackBoard::CreateInt(std::string name, int value)
{
   map_.insert(std::pair<std::string, int>(name, value));
}

void BlackBoard::ChangeInt(std::string name, int value)
{
   map_[name] = value;
}

int BlackBoard::GetInt(std::string name)
{
   return map_[name];
}
