#pragma once
#include "../Entity/Entity.hpp"

#include <cstdarg>
#include <iostream>

class System
{
public:
	static std::vector<size_t> queryEntities(const int argc, ...);
	static void removeEntities();
	static void drawEntities();
	static void updateEntities(const float deltaTime);
};

