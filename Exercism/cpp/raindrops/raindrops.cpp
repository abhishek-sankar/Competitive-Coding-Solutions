#include "raindrops.h"

namespace raindrops
{
	std::string convert(int number)
	{
		std::string result;
		if (number % 3 != 0 && number % 5 != 0 && number % 7 != 0)
		{
			result = std::to_string(number);
		}
		else
		{
			if (number % 3 == 0)
			{
				result.append("Pling");
			}
			if (number % 5 == 0)
			{
				result.append("Plang");
			}
			if (number % 7 == 0)
			{
				result.append("Plong");
			}
		}
		return result;
	}
} // namespace raindrops
