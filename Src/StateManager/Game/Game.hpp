#pragma once
#include "../../../Include/CommonSFML.hpp"
#include "../StateManager.hpp"

#include <iostream>

class Game : public StateManager
{
public:
	void run() override;
};

