#pragma once
#include "../Component/Component.hpp"

#include <array>
#include <iostream>
#include <memory>

class Entity
{
public:
	static std::vector<Entity> entities;
	std::array<std::unique_ptr<Component>, static_cast<int>(ComponentId::count)> components;

	Entity();
	void addComponent(const Component& component);
	void modifyComponent(const Component& component);
	void removeComponent(const ComponentId id);
private:
};