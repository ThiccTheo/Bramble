#include "GameState.hpp"
#include "../../Scene/Scene.hpp"
#include "../../ECS/Entity/Entity.hpp"
#include "../../ECS/Component/Component.hpp"
#include "../../ECS/System/System.hpp"
#include "../../../Extensions/ScopedTimer/ScopedTimer.hpp"

#include <memory>
#include <utility>

void GameState::run()
{
	while (Scene::window.isOpen())
	{
		const sf::Event& e{ eventHandler() };

		Scene::window.clear();
		Scene::window.display();
	}
}
