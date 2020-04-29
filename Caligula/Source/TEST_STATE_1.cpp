#include "TEST_STATE_1.h"
#include <iostream>
#include "Config.h"
#include <time.h>
#include "Random.h"
#include "BehaviourTree.h"
#include "TankBT.h"
#include "MageBT.h"
#include "GoblinBT.h"

#include "Service.h"

TEST_STATE_1::TEST_STATE_1(SDL_Renderer& p_renderer)
	: m_renderer(&p_renderer)
	, tank_("../Assets/Tank.png", 32, 32, { (Config::INTERNAL_WIDTH / 2), (Config::INTERNAL_HEIGHT / 2) })
	, mage_("../Assets/Mage.png", 32, 32, { (Config::INTERNAL_WIDTH / 2) - 32, (Config::INTERNAL_HEIGHT / 2) })
{
	boundaries = { Config::INTERNAL_WIDTH, Config::INTERNAL_HEIGHT };

	blackBoard_.CreateAgent("0", &tank_);
	blackBoard_.CreateAgent("1", &mage_);
	Service<BlackBoard>::Set(&blackBoard_); // sets the blackboard as a service so that other things can easily access it.
}

void TEST_STATE_1::Enter()
{
	srand(time(NULL));
	goblins_.push_back(new Agent("../Assets/Goblin.png", 32, 32, { Random::Randf(.0f, Config::INTERNAL_WIDTH), Random::Randf(.0f, Config::INTERNAL_HEIGHT)}));
	blackBoard_.CreateAgent("2", goblins_.at(0));
	//sequence->Add(new TestWalkDir(&tank_.blackBoard_));
	//sequence->Add(new TestWalk(&tank_.blackBoard_));

	tank_.behaviourTree_ = new TankBehaviourTree(&tank_.blackBoard_);
	mage_.behaviourTree_ = new MageBehaviourTree(&mage_.blackBoard_);
	goblins_.at(0)->behaviourTree_ = new GoblinBehaviourTree(&goblins_.at(0)->blackBoard_, 2);
}

bool TEST_STATE_1::Update()
{
	if (tankAlive_) tank_.Update();
	if (tankAlive_) mage_.Update();
	for (Agent* goblin : goblins_)
	{
		if (goblin == nullptr)
		{
			continue;
		}
		goblin->Update();
	}

	KillDeadThings();

	if (tankAlive_) tank_.Render(m_renderer);
	if (tankAlive_) mage_.Render(m_renderer);
	for (Agent* goblin : goblins_)
	{
		if (goblin == nullptr)
		{
			continue;
		}
		goblin->Render(m_renderer);
	}

	return true;
}

void TEST_STATE_1::Exit()
{
	std::cout << "TEST_STATE_1::Exit" << std::endl;
	for (Agent* goblin : goblins_)
	{
		delete goblin;
		goblin = nullptr;
	}
	goblins_.clear();
}

void TEST_STATE_1::GoblinSpawner()
{
	if (goblins_.size() < 9)
	{
		// spawn two goblins
		Agent* goblin = new Agent("../Assets/Goblin.png", 32, 32, { Random::Randf(.0f, Config::INTERNAL_WIDTH), Random::Randf(.0f, Config::INTERNAL_HEIGHT) });
		for (int i = 0; i < goblins_.size(); i++)
		{
			if (goblins_.at(i) == nullptr)
			{
				goblins_.at(i) = goblin;
				std::string index = std::to_string(i + 2);
				blackBoard_.agentMap_[index] = goblin;
				goblin->behaviourTree_ = new GoblinBehaviourTree(&goblin->blackBoard_, i + 2);
			}
		}

		bool goblinSpawned = false;
		goblin = new Agent("../Assets/Goblin.png", 32, 32, { Random::Randf(.0f, Config::INTERNAL_WIDTH), Random::Randf(.0f, Config::INTERNAL_HEIGHT) });
		for (int i = 0; i < goblins_.size(); i++)
		{
			if (goblins_.at(i) == nullptr)
			{
				goblins_.at(i) = goblin;
				std::string index = std::to_string(i + 2);
				blackBoard_.agentMap_[index] = goblin;
				goblinSpawned = true;
				goblin->behaviourTree_ = new GoblinBehaviourTree(&goblin->blackBoard_, i + 2);
			}
		}
		if (!goblinSpawned)
		{
			int i = goblins_.size();
			std::string index = std::to_string(i + 2); // this is the same as the index for the new goblin
			goblins_.push_back(goblin);
			blackBoard_.agentMap_[index] = goblin;
			goblin->behaviourTree_ = new GoblinBehaviourTree(&goblin->blackBoard_, i + 2);
		}
	}
	else if (goblins_.size() < 10)
	{
		// spawn one goblinbool
		Agent* goblin = new Agent("../Assets/Goblin.png", 32, 32, { Random::Randf(.0f, Config::INTERNAL_WIDTH), Random::Randf(.0f, Config::INTERNAL_HEIGHT) });
		for (int i = 0; i < goblins_.size(); i++)
		{
			if (goblins_.at(i) == nullptr)
			{
				goblins_.at(i) = goblin;
				std::string index = std::to_string(i + 2);
				blackBoard_.agentMap_[index] = goblin;
				goblin->behaviourTree_ = new GoblinBehaviourTree(&goblin->blackBoard_, i + 2);
			}
		}
	}
}

void TEST_STATE_1::KillDeadThings()
{
	if (tank_.blackBoard_.GetInt("health") <= 0)
	{
		blackBoard_.agentMap_["0"] = nullptr;
		tankAlive_ = false;

	}
	if (mage_.blackBoard_.GetInt("health") <= 0)
	{
		blackBoard_.agentMap_["1"] = nullptr;
		mageAlive_ = false;
	}
	for (int i = 0; i < goblins_.size(); i++)
	{
		std::string index = std::to_string(i + 2);
		Agent* goblin = goblins_.at(i);
		if (goblin == nullptr)
		{
			continue;
		}
		if (goblin->blackBoard_.GetInt("health") <= 0)
		{
			delete goblin;
			goblins_.at(i) = nullptr;
			blackBoard_.agentMap_[index] = nullptr;
			GoblinSpawner();
		}
	}
}
