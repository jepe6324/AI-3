// Agent.h

#ifndef AGENT_H_INCLUDED
#define AGENT_H_INCLUDED

#include "Vector.h"
#include "BlackBoard.h"

#include <SDL_rect.h>
#include <SDL.h>

struct Sprite;
struct BehaviourTree;

struct Agent
{  // An agent will now basically have the things needed to render, it's behaviour tree and a blackboard
   Sprite* sprite_;
   SDL_Rect drawHelper_;

   //BehaviourTree behaviourTree_;
   BehaviourTree* behaviourTree_;
   BlackBoard blackBoard_;

   Agent(const char* filepath,
         int width,
         int height,
         Vector2 startPos);
   ~Agent();

	void Render(SDL_Renderer* renderer_);
   void Update();
};

#endif //!AGENT_H_INCLUDED