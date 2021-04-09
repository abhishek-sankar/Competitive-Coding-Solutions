#include "grains.h"
#include <iostream>
namespace grains {
	// std::map<int, unsigned long long> chessboard;
	unsigned long long square(int square_id){
		unsigned long long res = 1;
		while(--square_id){
			res = res << 1;
		}
		return res;
	}
	std::vector<unsigned long long> find_all_grain_counts(){
		std::vector<unsigned long long> chessboard;
		unsigned long long current_square_grains = 1;
		int current_square = 1;
		while(current_square < 65){
			chessboard.push_back(current_square_grains);
			current_square++;
			current_square_grains = current_square_grains << 1;
		}
		return chessboard;
	}
	unsigned long long total(){
		std::vector<unsigned long long> chessboard = find_all_grain_counts();
		return std::accumulate(chessboard.begin(), chessboard.end(), 0);
	}
}  // namespace grains
