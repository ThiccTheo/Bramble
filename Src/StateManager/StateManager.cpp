#include "StateManager.hpp"
#include "../Scene/Scene.hpp"

std::stack<std::unique_ptr<StateManager>> StateManager::states;

void StateManager::checkState()
{
	if (!states.empty())
	{
		states.top()->run();
	}
}

void StateManager::run() {};

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