#include "TEST_STATE_1.h"
#include "Service.h"
#include "SoundHandler.h"
#include "InputHandler.h"
#include "Sound.h"
#include <iostream>
#include "Config.h"
#include <time.h>
#include "Random.h"

#include "BehaviourTree.h"
#include "ActionNodes.h"

TEST_STATE_1::TEST_STATE_1(SDL_Renderer& p_renderer)
	: m_renderer(&p_renderer)
	, goblin_("../Assets/Goblin.png", 32, 32, {4,10})
	, tank_("../Assets/Tank.png", 32, 32, { 10,10 })
	, mage_("../Assets/Mage.png", 32, 32, { 11,10 })
{
	m_sound = Service<SoundHandler>::Get()->CreateSound("../Assets/plopp.wav");
	boundaries = { Config::INTERNAL_WIDTH, Config::INTERNAL_HEIGHT };
}

void TEST_STATE_1::Enter()
{
	srand(time(NULL));

	Sequence* sequence = new Sequence();
	sequence->Add(new TestWalkDir(&tank_.blackBoard_));
	sequence->Add(new TestWalk(&tank_.blackBoard_));

	tank_.behaviourTree_ = sequence;
	tank_.behaviourTree_->bb_ = &tank_.blackBoard_;
}

bool TEST_STATE_1::Update()
{
	goblin_.Update();
	tank_.Update();
	mage_.Update();

	goblin_.Render(m_renderer);
	tank_.Render(m_renderer);
	mage_.Render(m_renderer);

	return true;
}

void TEST_STATE_1::Exit()
{
	std::cout << "TEST_STATE_1::Exit" << std::endl;
}
