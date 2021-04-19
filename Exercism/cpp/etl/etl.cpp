#include "etl.h"

namespace etl {
	std::map<char, int> transform(std::map<int, std::vector<char>> old_format){
		std::map<char, int> shiny_new_format;
		for(std::pair<int, std::vector<char>> point_letter_pair : old_format){
			for (char ch : point_letter_pair.second){
				shiny_new_format.insert({std::tolower(ch), point_letter_pair.first});
			}
		}
		return shiny_new_format;
	}
}  // namespace etl
