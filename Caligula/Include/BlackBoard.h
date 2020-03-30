// BlackBoard.h

#include <unordered_map>
#include "Vector.h"

#ifndef BLACKBOARD_H_INCLUDED
#define BLACKBOARD_H_INCLUDED

struct BlackBoard
{
   std::unordered_map<std::string, int> intMap_;
   std::unordered_map<std::string, Vector2> vecMap_;
   std::unordered_map<std::string, BlackBoard*> bbMap_;

   void CreateInt(std::string name, int value);
   void ChangeInt(std::string name, int value);
   int GetInt(std::string name);

   void CreateVect(std::string name, Vector2 value);
   void ChangeVect(std::string name, Vector2 value);
   Vector2 GetVect(std::string name);

   void CreateBB(std::string name, BlackBoard* value);
   void ChangeBB(std::string name, BlackBoard* value);
   BlackBoard* GetBB(std::string name);
};

#endif // !BLACKBOARD_H_INCLUDED