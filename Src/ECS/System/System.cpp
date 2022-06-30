#include "System.hpp"
#include "../../../Utility/ScopedTimer/ScopedTimer.hpp"

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
			if (Entity::entities[i].mask[static_cast<int>(va_arg(argv, ComponentId))] == 0) //if entity is missing one of the variadic args, don't add
			{
				flag = false;
				std::cout << "missing\n";
				break;
			}
		}

		if (flag)
		{
			filteredIndices.push_back(i);
		}

		va_end(argv);
	}

	return filteredIndices;
}