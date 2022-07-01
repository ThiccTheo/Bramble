#include "Scene/Scene.hpp"
#include "ResourceManager/ResourceManager.hpp"
#include "StateManager/StateManager.hpp"
#include "StateManager/GameState/GameState.hpp"

#include <memory>
#include <iostream>

int main()
{
	if (ResourceManager::load())
	{
		Scene::init();
		StateManager::states.emplace(std::make_unique<GameState>()); //create game state
		StateManager::checkState();
		return EXIT_SUCCESS;
	}
	else
	{
		return EXIT_FAILURE;
	}
}