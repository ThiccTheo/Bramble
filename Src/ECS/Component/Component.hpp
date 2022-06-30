#pragma once
#include "../../../Include/CommonSFML.hpp"

#include <iostream>
#include <unordered_map>

enum class ComponentId {active, renderLayer, count};

class Component
{
public:
	ComponentId id;

	Component();
	~Component();
};

struct Active : public Component 
{
	bool isActive;

	Active(const bool isActive);
};