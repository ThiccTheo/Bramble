#pragma once
#include "../../../Include/CommonSFML.hpp"
#include "../StateManager.hpp"

#include <iostream>

class GameState : public StateManager
{
public:
	void run() override;
};

