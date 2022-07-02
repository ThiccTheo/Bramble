#pragma once
#include "../../../Include/CommonSFML.hpp"

#include <iostream>
#include <memory>

enum class ComponentId {active, renderLayer, mesh, count};

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
	std::vector<sf::Vector2f> vertices;

	Mesh(const std::vector<sf::Vector2f>& vertices);
	~Mesh() override;
	std::unique_ptr<Component> clone() const override;
}; 

