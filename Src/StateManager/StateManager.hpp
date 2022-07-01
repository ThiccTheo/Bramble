#pragma once
#include "../Include/CommonSFML.hpp"

#include <iostream>
#include <stack>
#include <memory>

class StateManager
{
public:
	static std::stack<std::unique_ptr<StateManager>> states;

	static void checkState();
	virtual void run();
	static const sf::Event eventHandler();
private:
};

