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

Mesh::Mesh()
{
	id = ComponentId::mesh;
}

Mesh::~Mesh() = default;

std::unique_ptr<Component> Mesh::clone() const
{
	return std::make_unique<Mesh>(*this);
}

Body::Body(const sf::Vector2i& indices, const sf::Vector2f& shapeSize, const OriginSpot originSpot)
{
    shape.setSize(shapeSize);
    const sf::FloatRect& shapeBounds{ shape.getLocalBounds() };

    switch (originSpot)
    {
    case OriginSpot::topLeft:
        shape.setOrigin(0.f, 0.f);
        break;
    case OriginSpot::topCenter:
        shape.setOrigin(shapeBounds.width / 2.f, 0.f);
        break;
    case OriginSpot::topRight:
        shape.setOrigin(shapeBounds.width, 0.f);
        break;
    case OriginSpot::middleLeft:
        shape.setOrigin(0.f, shapeBounds.height / 2.f);
        break;
    case OriginSpot::middleCenter:
        shape.setOrigin(shapeBounds.width / 2.f, shapeBounds.height / 2.f);
        break;
    case OriginSpot::middleRight:
        shape.setOrigin(shapeBounds.width, shapeBounds.height / 2.f);
        break;
    case OriginSpot::bottomLeft:
        shape.setOrigin(0.f, shapeBounds.height);
        break;
    case OriginSpot::bottomCenter:
        shape.setOrigin(shapeBounds.width / 2.f, shapeBounds.height);
        break;
    case OriginSpot::bottomRight:
        shape.setOrigin(shapeBounds.width, shapeBounds.height);
        break;
    }

    shape.setPosition(/*Tile::*/shapeSize.x * indices.x, /*Tile::*/shapeSize.y * indices.y);
	id = ComponentId::body;
}

Body::~Body() = default;

std::unique_ptr<Component> Body::clone() const
{
	return std::make_unique<Body>(*this);
}