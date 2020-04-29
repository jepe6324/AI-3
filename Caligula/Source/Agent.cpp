// Agent.cpp

#include "Agent.h"
#include "Sprite.h"
#include "Service.h"
#include "Spritehandler.h"
#include "Config.h"
#include "BehaviourTree.h"

Agent::Agent(const char* filepath,
             int width,
             int height,
             Vector2 startPos)
{
   sprite_ = Service<SpriteHandler>::Get()->CreateSprite(filepath, 0, 0, width, height);

   drawHelper_.w = width;
   drawHelper_.h = height;

   blackBoard_.CreateVect("position", startPos);

}

Agent::~Agent()
{
   //delete sprite_;
   delete behaviourTree_;
}

void Agent::Render(SDL_Renderer* renderer_)
{
   SDL_RenderCopy(renderer_, sprite_->GetTexture(), &sprite_->GetArea(), &drawHelper_);
	
   SDL_SetRenderDrawColor(renderer_, blackBoard_.GetInt("red"), blackBoard_.GetInt("green"), blackBoard_.GetInt("blue"), 100);
	if(Config::DEBUGRENDER == TRUE)
   {
		SDL_RenderDrawRect(renderer_, &drawHelper_);
   }
}

void Agent::Update()
{
   blackBoard_.CreateInt("red", 255);
   blackBoard_.CreateInt("green", 255);
   blackBoard_.CreateInt("blue", 255);

   if (behaviourTree_ != nullptr)
   {
      behaviourTree_->Run();
   }

   drawHelper_.x = blackBoard_.GetVect("position").x_;
   drawHelper_.y = blackBoard_.GetVect("position").y_;
}