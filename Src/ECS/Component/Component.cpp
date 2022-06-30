#include "Component.hpp"

Component::Component() {}
Component::~Component() {}

Active::Active(const bool isActive)
{
	this->isActive = isActive;
	id = ComponentId::active;
}
