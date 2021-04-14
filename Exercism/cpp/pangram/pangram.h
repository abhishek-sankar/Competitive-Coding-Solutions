#if !defined(PANGRAM_H)
#define PANGRAM_H
#include <string>
#include <array>
#include <utility>

namespace pangram {
	bool is_pangram(const std::string &sentence);
}  // namespace pangram

#endif // PANGRAM_H