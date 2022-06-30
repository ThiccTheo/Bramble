#pragma once
#include "../../../Include/CommonSFML.hpp"
#include "../StateManager.hpp"

#include <iostream>

class GameState : public StateManager
{
public:
	GameState();
	~GameState() override;
	void run() override;
};

