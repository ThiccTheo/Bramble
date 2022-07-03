#pragma once
#include "../../../Include/CommonSFML.hpp"

#include <iostream>
#include <memory>

enum class OriginSpot { topLeft, topCenter, topRight, middleLeft, middleCenter, middleRight, bottomLeft, bottomCenter, bottomRight };
enum class ComponentId {active, renderLayer, mesh, body, count};

class Component
{
public:
	ComponentId id;

	virtual ~Component();
	virtual std::unique_ptr<Component> clone() const;
};

struct Active : public Component 
{
	bool isActive;

	Active(const bool isActive);
	~Active() override;
	std::unique_ptr<Component> clone() const override;
};

struct RenderLayer : public Component
{
	int layerLevel;

	RenderLayer(const int layerLevel);
	~RenderLayer() override;
	std::unique_ptr<Component> clone() const override;
};

struct Mesh : public Component
{
	sf::Vector2f vertices[4];

	Mesh();
	~Mesh() override;
	std::unique_ptr<Component> clone() const override;
}; 

struct Body : public Component
{
	sf::RectangleShape shape;

	Body(const sf::Vector2i& indices, const sf::Vector2f& shapeSize, const OriginSpot originSpot);
	~Body() override;
	std::unique_ptr<Component> clone() const override;
};

