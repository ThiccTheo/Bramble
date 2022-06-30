#include "StateManager.hpp"
#include "../Scene/Scene.hpp"

std::stack<std::unique_ptr<StateManager>> StateManager::states;

StateManager::StateManager()
{
	checkState();
}

StateManager::~StateManager()
{
	checkState();
}

void StateManager::run() {};

void StateManager::checkState()
{
	states.top()->run();
}

const sf::Event StateManager::eventHandler()
{
	sf::Event e;
	while (Scene::window.pollEvent(e))
	{
		switch (e.type)
		{
		case sf::Event::Closed:
			Scene::window.close();
			break;
		}

		return e;
	}

	return sf::Event();
}