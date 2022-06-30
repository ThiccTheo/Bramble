#include "Entity.hpp"

#include <algorithm>

std::vector<Entity> Entity::entities;

Entity::Entity()
{
}

Entity::~Entity()
{
}

//emplace component into entity if not present
void Entity::addComponent(const Component& component)
{
	if (mask[static_cast<int>(component.id)] == 0) //check if component is not present
	{
		components.emplace_back(std::make_unique<Component>(component));
		mask[static_cast<int>(component.id)] = 1; //set the bit |
	}
}

//delete component from an entity if it is present
void Entity::removeComponent(const ComponentId id) 
{
	if (mask[static_cast<int>(id)] == 1) //check if component is present
	{
		components.erase(std::remove_if(components.begin(), components.end(),
			[id](std::unique_ptr<Component>& component)
			{
				return component->id == id;
			}));
		mask[static_cast<int>(id)] = 0; //clear the bit &
	}
}

//replaces existing component with new component
void Entity::modifyComponent(const Component& component)
{
	if (mask[static_cast<int>(component.id)] == 1) //check if component is present
	{
		//that code is cursed
		//we'll just erase the old component and insert at the end
		components.erase(std::remove_if(components.begin(), components.end(),
			[&, component](std::unique_ptr<Component>& currentComponent)
			{
				return currentComponent->id == component.id;
			}));
		components.emplace_back(std::make_unique<Component>(component));
	}
}