#pragma once
#include "../../../Include/CommonSFML.hpp"

#include <iostream>
#include <vector>
#include <unordered_map>

enum class ComponentId {active, renderLayer, mesh, count};

class Component
{
public:
	ComponentId id;
};

struct Active : public Component 
{
	bool isActive;

	Active(const bool isActive);
};

struct RenderLayer : public Component
{
	int layerLevel;

	RenderLayer(const int layerLevel);
};

struct Mesh : public Component
{
	std::vector<sf::Vector2f> vertices;

	Mesh(const std::vector<sf::Vector2f>& vertices);
}; 

