#include "raindrops.h"

namespace raindrops
{
	std::string convert(int number)
	{
		std::string result;
		std::array<std::pair<int, std::string>, 3> number_sounds = {{{3, "Pling"}, {5, "Plang"}, {7, "Plong"}}};
		for(auto number_sound_pair : number_sounds){
			if(number % number_sound_pair.first == 0){
				result.append(number_sound_pair.second);
			}
		}
		return result.empty()?std::to_string(number):result;
	}
} // namespace raindrops
