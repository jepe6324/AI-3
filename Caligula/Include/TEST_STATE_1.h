#pragma once

#include "State.h"
#include <array>
#include "Agent.h"
#include "Vector.h"
#include "BlackBoard.h"

struct SDL_Renderer;

class TEST_STATE_1 : public State
{

	SDL_Renderer* m_renderer;

   Vector2 boundaries;

	BlackBoard blackBoard_;
	Agent tank_;
	Agent mage_;
	std::vector<Agent*> goblins_;

	bool tankAlive_ = true;
	bool mageAlive_ = true;

public:

	TEST_STATE_1(SDL_Renderer& p_renderer); 
	void Enter();
	bool Update();
	void Exit();

	void GoblinSpawner();
	void KillDeadThings();
};
