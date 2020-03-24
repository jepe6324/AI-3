#pragma once

#include "State.h"
#include <array>
#include "DeltaTime.h"
#include "Agent.h"

struct SDL_Renderer;
class Sound;

class TEST_STATE_1 : public State
{

	SDL_Renderer* m_renderer;
	Sound* m_sound;

public:
   enum GameState {
      EDIT,
      SIMULATE
   };

   GameState currentState_;

	TEST_STATE_1(SDL_Renderer& p_renderer); 
	void Enter();
	bool Update();
	void Exit();

   void changeState(GameState newState);
};
