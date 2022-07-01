#include "System.hpp"
#include "../../../Extensions/ScopedTimer/ScopedTimer.hpp"
#include "../Component/Component.hpp"

#include <algorithm>

std::vector<size_t> System::queryEntities(const int argc, ...)
{
	std::vector<size_t> filteredIndices;

	for (size_t i{ 0 }; i < Entity::entities.size(); i++)
	{
		va_list argv;
		va_start(argv, argc);

		bool flag{ true };

		for (int i{ 0 }; i < argc; i++)
		{
			if (Entity::entities[i].components[static_cast<int>(va_arg(argv, ComponentId))] == nullptr)
			{
				flag = false;
				break;
			}
		}

		if (flag)
		{
			filteredIndices.push_back(i);
		}

		va_end(argv);
	}

	std::cout << filteredIndices.size() << '\n';
	return filteredIndices;
}

void System::draw()
{
	//std::vector<size_t>filteredIndices {queryEntities(2, ComponentId::mesh, ComponentId::renderLayer)};

	////sort entities based on render layer level
	//std::sort(filteredIndices.begin(), filteredIndices.end(),
	//	[](const size_t& index1, const size_t& index2)
	//	{
	//		return
	//			Entity::entities[index1].components[static_cast<int>(ComponentId::renderLayer)] <
	//			Entity::entities[index2].components[static_cast<int>(ComponentId::renderLayer)]->layerLevel;
	//	});
}