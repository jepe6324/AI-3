// BlackBoard.h

#include <unordered_map>

#ifndef BLACKBOARD_H_INCLUDED
#define BLACKBOARD_H_INCLUDED

struct BlackBoard
{
   std::unordered_map<std::string, int> map_;

   void CreateInt(std::string name, int value);
   void ChangeInt(std::string name, int value);
   int GetInt(std::string name);
};

#endif // !BLACKBOARD_H_INCLUDED