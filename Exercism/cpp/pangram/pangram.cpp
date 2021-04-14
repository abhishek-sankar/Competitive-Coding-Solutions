#include "pangram.h"
#include <iostream>
namespace pangram {
	bool is_pangram(const std::string &sentence) {
		std::array<bool, 26>letters{}; // stores count of letters from a/A to z/Z case insensitive
		for(auto x : std::as_const(sentence)){
			if(isalpha(x)){
				letters[tolower(x)-'a'] = true;
			}
		}
		if(std::all_of(letters.begin(), letters.end(), [](bool val){return val;}))
			return true;
		return false;
	}
}  // namespace pangram

/*
range based loops
https://en.cppreference.com/w/cpp/language/range-for

set CXX to 20
https://www.reddit.com/r/cpp_questions/comments/ajz6bb/unexpected_behavior_by_cmake_c_standard/

clang flags for cpp verison
https://clang.llvm.org/cxx_status.html

std::all_of
https://www.cplusplus.com/reference/algorithm/all_of/
*/