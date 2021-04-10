#if !defined(GRAINS_H)
#define GRAINS_H
#include <vector>
#include <numeric>
#include <stdint.h>

namespace grains {
	unsigned long long square(int square_id);
	uint64_t total();
}  // namespace grains

#endif // GRAINS_H