#include "GameState.hpp"
#include "../../Scene/Scene.hpp"
#include "../../ECS/Entity/Entity.hpp"

#include <memory>
#include <utility>

GameState::GameState()
{
	run();
}

GameState::~GameState() {}

void GameState::run()
{
	sf::Color color = rand() % 2 == 0 ? sf::Color::Red : sf::Color::Black; //to see if a new state is being added, a random color will be displayed on screen

	while (Scene::window.isOpen())
	{
		const sf::Event& e{ eventHandler() };
		if (e.type == sf::Event::KeyPressed)
		{
			if (e.key.code == sf::Keyboard::W)
			{
				states.emplace(std::make_unique<GameState>()); //add new state when w is pressed
			}
			else if (e.key.code == sf::Keyboard::S)
			{
				if (!states.empty())
				{
					states.pop();//delete state if s is pressed *throws exception* despite how many times w is pressed
					return;
				}
			}
		}

		Scene::window.clear(color);
		Scene::window.display();
	}
}
