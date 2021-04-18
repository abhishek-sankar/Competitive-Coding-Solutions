#if !defined(WORD_COUNT_H)
#define WORD_COUNT_H
#include <map>
#include <vector>
#include <string>


namespace word_count {
	std::map<std::string, int> words(std::string input);
}  // namespace word_count

#endif // WORD_COUNT_H