#if !defined(ANAGRAM_H)
#define ANAGRAM_H
#include <string>
#include <vector>
#include <map>

namespace anagram {
	class anagram{
		public:
		anagram(std::string word);
		std::vector<std::string> matches(std::vector<std::string> match_list);
		private:
		std::map<char, long> letter_counts;
		std::string anagram_word;
	};
}  // namespace anagram

#endif // ANAGRAM_H