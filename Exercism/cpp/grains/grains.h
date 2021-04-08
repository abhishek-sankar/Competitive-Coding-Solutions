#if !defined(GRAINS_H)
#define GRAINS_H
#include <map>

namespace grains {
	unsigned long long square(int square_id);
	unsigned long long square_grain_count(unsigned square_id, std::map<int, unsigned long long> &chessboard);
	unsigned long long total();
}  // namespace grains

#endif // GRAINS_H