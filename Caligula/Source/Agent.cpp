// Agent.cpp

#include "Agent.h"
#include "Sprite.h"
#include "Service.h"
#include "Spritehandler.h"
#include "Config.h"

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
}

void Agent::Render(SDL_Renderer* renderer_)
{
   SDL_RenderCopy(renderer_, sprite_->GetTexture(), &sprite_->GetArea(), &drawHelper_);
	
	if(Config::DEBUGRENDER == TRUE)
   {
		SDL_RenderDrawRect(renderer_, &drawHelper_);
   }
}

void Agent::Update()
{
   if (behaviourTree_ != nullptr)
   {
      behaviourTree_->Run();
   }

   drawHelper_.x = blackBoard_.GetVect("position").x_ * Config::TILE_SIZE;
   drawHelper_.y = blackBoard_.GetVect("position").y_ * Config::TILE_SIZE;
}