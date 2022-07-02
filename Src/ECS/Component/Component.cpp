#include "Component.hpp"
#include "../Extensions/ScopedTimer/ScopedTimer.hpp"

Component::~Component() = default;

std::unique_ptr<Component> Component::clone() const
{
	return std::make_unique<Component>(*this);
}

Active::Active(const bool isActive)
{
	this->isActive = isActive;
	id = ComponentId::active;
}

Active::~Active() = default;
 
std::unique_ptr<Component> Active::clone() const
{
	return std::make_unique<Active>(*this);
}

RenderLayer::RenderLayer(const int layerLevel)
{
	this->layerLevel = layerLevel;
	id = ComponentId::renderLayer;
}

RenderLayer::~RenderLayer() = default;

std::unique_ptr<Component> RenderLayer::clone() const
{
	return std::make_unique<RenderLayer>(*this);
}

Mesh::Mesh(const std::vector<sf::Vector2f>& vertices)
{
	this->vertices = vertices;
	id = ComponentId::mesh;
}

Mesh::~Mesh() = default;

std::unique_ptr<Component> Mesh::clone() const
{
	return std::make_unique<Mesh>(*this);
}
