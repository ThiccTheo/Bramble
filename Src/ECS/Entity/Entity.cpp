#include "Entity.hpp"

#include <algorithm>

std::vector<Entity> Entity::entities;

Entity::Entity()
{
	for (auto& component : components)
	{
		component = nullptr;
	}
}

void Entity::addComponent(const Component& component)
{
	int index{ static_cast<int>(component.id) };

	if (components[index] == nullptr)
	{
		components[index] = std::make_unique<Component>(component);
	}
}

void Entity::removeComponent(const ComponentId id) 
{
	int index{ static_cast<int>(id) };

	if (components[index] != nullptr)
	{
		components[index] = nullptr;
	}
}

void Entity::modifyComponent(const Component& component)
{
	int index{ static_cast<int>(component.id) };

	if (components[index] != nullptr)
	{
		components[index] = std::make_unique<Component>(component);
	}
}