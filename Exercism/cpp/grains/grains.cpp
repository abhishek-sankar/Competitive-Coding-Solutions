#include "grains.h"
#include <iostream>
namespace grains {
	// std::map<int, unsigned long long> chessboard;
	unsigned long long square(int square_id){
		std::map<int, unsigned long long>chessboard = {};
		return square_grain_count(square_id, chessboard);
	}
	unsigned long long square_grain_count(int square_id, std::map<int, unsigned long long> &chessboard){
		if(square_id==1){
			return 1;
		}
		if(chessboard.find(square_id)==chessboard.end()){
			unsigned long long previous_square_grains = square_grain_count(square_id-1, chessboard);
			unsigned long long current_square_grains = previous_square_grains << 1;
			chessboard.insert(std::pair<int, unsigned long long>(square_id, current_square_grains));
			}
		return chessboard.at(square_id);
	}
	unsigned long long total(){
		unsigned long long total_grains = 0;
		int current_square = 1;
		std::map<int, unsigned long long> chessboard;
		while(current_square < 65){
			total_grains += square_grain_count(current_square, chessboard);
			current_square++;
		}
		return total_grains;
	}
}  // namespace grains
