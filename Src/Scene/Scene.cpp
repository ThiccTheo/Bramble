#include "Scene.hpp"
#include "../StateManager/StateManager.hpp"
#include "../StateManager/Game/Game.hpp"

#include <memory>

sf::RenderWindow Scene::window;
sf::View Scene::camera;

void Scene::init()
{
	const sf::Vector2u& resolution{ determineResolution() };
	window.create(sf::VideoMode(resolution.x, resolution.y), "Bramble", sf::Style::Default);
	window.setVerticalSyncEnabled(true);
	window.setKeyRepeatEnabled(false); 
	camera.setSize(sf::Vector2f(resolution));
	camera.setCenter(sf::Vector2f(window.getPosition().x + window.getSize().x / 2.f, window.getPosition().y + window.getSize().y / 2.f));
	camera.zoom(0.5);
	window.setView(camera);

	StateManager::states.emplace(std::make_unique<StateManager>(Game()));
}

const sf::Vector2u Scene::determineResolution()
{
	const sf::Vector2u desktopResolution{ sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height };

	if (desktopResolution.x % 16 == 0 && desktopResolution.y % 9 == 0) //16:9
	{
		return sf::Vector2u(1280, 720);
	}
	else if (desktopResolution.x % 16 == 0 && desktopResolution.y % 10 == 0) //16:10
	{
		return sf::Vector2u(1280, 800);
	}
	else if (desktopResolution.x % 4 == 0 && desktopResolution.y % 3 == 0) //4:3
	{
		return sf::Vector2u(1280, 960);
	}
	else if (desktopResolution.x % 5 == 0 && desktopResolution.y % 4 == 0) //5:4
	{
		return sf::Vector2u(1280, 1024);
	}
	else
	{
		return sf::Vector2u();
	}
}