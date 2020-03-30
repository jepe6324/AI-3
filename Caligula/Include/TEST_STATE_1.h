#pragma once

#include "State.h"
#include <array>
#include "DeltaTime.h"
#include "Agent.h"
#include "Vector.h"
#include "BlackBoard.h"

struct SDL_Renderer;
class Sound;

class TEST_STATE_1 : public State
{

	SDL_Renderer* m_renderer;
	Sound* m_sound;

   Vector2 boundaries;

	BlackBoard blackBoard_;

	Agent goblin_;
	Agent tank_;
	Agent mage_;

public:

	TEST_STATE_1(SDL_Renderer& p_renderer); 
	void Enter();
	bool Update();
	void Exit();
};
