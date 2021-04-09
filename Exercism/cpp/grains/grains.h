#if !defined(GRAINS_H)
#define GRAINS_H
#include <vector>
#include <numeric>

namespace grains {
	unsigned long long square(int square_id);
	std::vector<unsigned long long> find_all_grain_counts();
	unsigned long long total();
}  // namespace grains

#endif // GRAINS_H