// BlackBoard.h

#ifndef BLACKBOARD_H_INCLUDED
#define BLACKBOARD_H_INCLUDED

#include <unordered_map>
#include "Vector.h"

struct Agent;

struct BlackBoard
{
   std::unordered_map<std::string, int> intMap_;
   std::unordered_map<std::string, Vector2> vecMap_;
   std::unordered_map<std::string, Agent*> agentMap_;

   void CreateInt(std::string name, int value);
   void ChangeInt(std::string name, int value);
   int GetInt(std::string name);

   void CreateVect(std::string name, Vector2 value);
   void ChangeVect(std::string name, Vector2 value);
   Vector2 GetVect(std::string name);

   void CreateAgent(std::string name, Agent* value);
   void ChangeAgent(std::string name, Agent* value);
   Agent* GetAgent(std::string name);

   ~BlackBoard();
};

#endif // !BLACKBOARD_H_INCLUDED