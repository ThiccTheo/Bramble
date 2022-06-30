#include "Scene/Scene.hpp"
#include "ResourceManager/ResourceManager.hpp"

#include <iostream>

int main()
{
	switch (ResourceManager::load())
	{
		case true:
			Scene::init();
			return EXIT_SUCCESS;
		case false:
			return EXIT_FAILURE;
	}
}