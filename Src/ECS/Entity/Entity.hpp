#pragma once
#include "../Component/Component.hpp"

#include <bitset>
#include <vector>
#include <iostream>
#include <memory>

class Entity
{
public:
	static std::vector<Entity> entities;
	std::bitset<static_cast<int>(ComponentId::count)> mask;
	std::vector<std::unique_ptr<Component>> components;

	Entity();
	~Entity();
	void addComponent(const Component& component);
	void removeComponent(const ComponentId id);
	void modifyComponent(const Component& component);
};

