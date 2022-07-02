#include "Entity.hpp"
#include "../System/System.hpp"

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
		components[index] = component.clone();
	}
}

void Entity::modifyComponent(const Component& component)
{
	int index{ static_cast<int>(component.id) };

	if (components[index] != nullptr)
	{
		components[index] = component.clone();
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