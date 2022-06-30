#include "Game.hpp"
#include "../../Scene/Scene.hpp"

void Game::run()
{
	while (Scene::window.isOpen())
	{
		const sf::Event& e{ StateManager::eventHandler() };

		Scene::window.clear();
		Scene::window.display();
	}
}
