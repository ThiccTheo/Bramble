#pragma once
#include "../../Include/CommonSFML.hpp"

#include <iostream>

class Scene
{
public:
	static sf::RenderWindow window;
	static sf::View camera;

	static void init();
	static const sf::Vector2u determineResolution();
};

