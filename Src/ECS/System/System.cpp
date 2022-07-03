#include "System.hpp"
#include "../../../Extensions/ScopedTimer/ScopedTimer.hpp"
#include "../Component/Component.hpp"
#include "../Entity/Entity.hpp"
#include "../../Scene/Scene.hpp"

#include <algorithm>

std::vector<size_t> System::queryEntities(const int argc, ...)
{
	std::vector<size_t> filteredIndices;

	for (size_t i{ 0 }; i < Entity::entities.size(); i++)
	{
		va_list argv;
		va_start(argv, argc);

		bool flag{ true };

		for (int j{ 0 }; j < argc; j++)
		{
			if (Entity::entities[i].components[static_cast<int>(va_arg(argv, ComponentId))] == nullptr)
			{
				flag = false;
				break;
			}
		}

		if (flag)
		{
			filteredIndices.push_back(i);
		}

		va_end(argv);
	}

	return filteredIndices;
}

void System::removeEntities()
{
	Entity::entities.erase(std::remove_if(Entity::entities.begin(), Entity::entities.end(),
		[](Entity& entity) -> bool
		{
			Active* active{ dynamic_cast<Active*>(entity.components[static_cast<int>(ComponentId::active)].get()) };
			return active && !active->isActive;

		}), Entity::entities.end());
}

void System::drawEntities()
{
	std::vector<size_t> filteredIndices{ queryEntities(4, ComponentId::active, ComponentId::mesh, ComponentId::renderLayer, ComponentId::body)};

	std::sort(filteredIndices.begin(), filteredIndices.end(),
		[](const size_t& index1, const size_t& index2)
		{
			return
				dynamic_cast<RenderLayer*>(Entity::entities[index1].components[static_cast<int>(ComponentId::renderLayer)].get())->layerLevel >
				dynamic_cast<RenderLayer*>(Entity::entities[index2].components[static_cast<int>(ComponentId::renderLayer)].get())->layerLevel;
		});

	sf::RenderStates renderStates;
	sf::VertexArray vertexArray;
	vertexArray.setPrimitiveType(sf::Quads);
	vertexArray.resize(filteredIndices.size() * 4);

	int vertexPointer{ 0 };

	for (auto& filteredIndex : filteredIndices)
	{
		Mesh* mesh{ dynamic_cast<Mesh*>(Entity::entities[filteredIndex].components[static_cast<int>(ComponentId::mesh)].get())};
		Body* body{ dynamic_cast<Body*>(Entity::entities[filteredIndex].components[static_cast<int>(ComponentId::body)].get()) };

		const sf::FloatRect& shapeBounds{ body->shape.getGlobalBounds() };

		mesh->vertices[0] = sf::Vector2f(shapeBounds.left, shapeBounds.top);
		mesh->vertices[1] = sf::Vector2f(shapeBounds.left + shapeBounds.width, shapeBounds.top);
		mesh->vertices[2] = sf::Vector2f(shapeBounds.left + shapeBounds.width, shapeBounds.top + shapeBounds.height);
		mesh->vertices[3] = sf::Vector2f(shapeBounds.left, shapeBounds.top + shapeBounds.height);

		sf::Vertex* currentVertices{ &vertexArray[vertexPointer] };

		for (int i{ 0 }; i < 4; i++)
		{
			currentVertices[i].position = mesh->vertices[i];
			currentVertices[i].color = sf::Color::Red;
		}

		vertexPointer += 4;
	}

	Scene::window.draw(vertexArray, renderStates);
}

void System::updateEntities(const float deltaTime)
{
	std::vector<size_t> filteredIndices{ queryEntities(2, ComponentId::active, ComponentId::body) };

	for (auto& filteredIndex : filteredIndices)
	{
		Body* body{ dynamic_cast<Body*>(Entity::entities[filteredIndex].components[static_cast<int>(ComponentId::body)].get()) };
		if (rand() % 30 == 0)
		{
			body->shape.move(100.f * deltaTime, 100.f * deltaTime);
		}
	}
}
