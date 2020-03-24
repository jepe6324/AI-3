// Agent.cpp

#include "Agent.h"
#include "Sprite.h"
#include "Service.h"
#include "Spritehandler.h"
#include "Config.h"
#include "DeltaTime.h"
#include "Random.h"

Agent::Agent(const char* filepath,
             int width,
             int height,
             AgentState* startState,
             Vector2 startPos)
{
   sprite_ = Service<SpriteHandler>::Get()->CreateSprite(filepath, 0, 0, width, height);
   position_ = startPos;
   currentState_ = nullptr;

   drawHelper_.w = width;
   drawHelper_.h = height;
}

Agent::~Agent()
{
}

void Agent::Render(SDL_Renderer* renderer_)
{
   SDL_RenderCopy(renderer_, sprite_->GetTexture(), &sprite_->GetArea(), &drawHelper_);
	
	if(Config::DEBUGRENDER == TRUE)
   {
		//SDL_RenderDrawRect(renderer_, &drawHelper_);
   }
}

void Agent::Update(float dt) // As milliseconds
{
   Sense(); // Ad timers to make sure these happen at a proper time
   Decide();
   if (currentState_ != nullptr)
   {
      currentState_->Update(dt);
   }
   drawHelper_.x = position_.x_ * Config::TILE_SIZE;
   drawHelper_.y = position_.y_ * Config::TILE_SIZE;
}

void Agent::Move(Vector2 newPos) {
   // These lines should be used when moving the agents
}

void Agent::MoveInDirection(Vector2 direction)
{
	Vector2 newPos = position_ + direction;
	Move(newPos);
}

void Agent::SwitchState(AgentState* newState)
{
   if (currentState_ != nullptr)
   {
      currentState_->Exit();
      delete currentState_;
      currentState_ = nullptr;
   }

   if (newState != nullptr)
   {
      currentState_ = newState;
      currentState_->agent_ = this;
      currentState_->Enter();
   }
}

void Agent::Sense()
{
}

void Agent::Decide()
{
}