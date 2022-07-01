#include "Component.hpp"
#include "../Extensions/ScopedTimer/ScopedTimer.hpp"

Active::Active(const bool isActive)
{
	this->isActive = isActive;
	id = ComponentId::active;
}

RenderLayer::RenderLayer(const int layerLevel)
{
	this->layerLevel = layerLevel;
	id = ComponentId::renderLayer;
}

Mesh::Mesh(const std::vector<sf::Vector2f>& vertices)
{
	this->vertices = vertices;
	id = ComponentId::mesh;
}