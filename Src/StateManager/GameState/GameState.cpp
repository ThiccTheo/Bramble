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
	for (int i{ 0 }; i < 400; i++)
	{
		for (int j{ 0 }; j < 400; j++)
		{
			Entity& entity{ Entity::entities.emplace_back() };
			entity.addComponent(Active(true));
			entity.addComponent(RenderLayer(0));
			entity.addComponent(Body(sf::Vector2i(j, i), sf::Vector2f(16.f, 16.f), OriginSpot::topLeft));
			entity.addComponent(Mesh());
		}
	}

	sf::Clock dtClock;

	while (Scene::window.isOpen())
	{
		const sf::Event& e{ eventHandler() };

		System::removeEntities();
		System::updateEntities(dtClock.restart().asSeconds());
		Scene::window.clear(sf::Color::Black);
		System::drawEntities();
		Scene::window.display();
	}
}
