#include "grains.h"
#include <iostream>
namespace grains {
	// std::map<int, unsigned long long> chessboard;
	unsigned long long square(int square_id){
		return 1ULL << (square_id-1);
	}

	uint64_t total(){
		return -1;
	}
}  // namespace grains

/*
Reference:
Other implementations of total()

return 18'446'744'073'709'551'615;
return 0xFFFF'FFFF'FFFF'FFFF;
return (1ULL << 63) * 2 - 1;
return (1ULL << 32 << 32) - 1;
return (2ULL << 63) - 1;
return UINT64_MAX;
return std::numeric_limits<std::uint64_t>::max();
return ~static_cast<std::uint64_t>(0);
return static_cast<std::uint64_t>(-1);
return std::bitset<64>().set().to_ullong();
return 2 * square(64) - 1;

https://stackoverflow.com/questions/4201301/warning-left-shift-count-width-of-type
https://stackoverflow.com/questions/47391546/how-to-set-bits-in-byte-without-loop
*/