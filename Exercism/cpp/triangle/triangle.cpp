#include "triangle.h"

namespace triangle {
	void triangle_rule_check(float side_1, float side_2, float side_3){
		if((side_1 + side_2 < side_3) || (side_2 + side_3 < side_1) || (side_1 + side_3 < side_2) || (side_1 <= 0 || side_2 <= 0 || side_3 <= 0)){
			throw std::domain_error("Triangle with side less than or equal to zero cant exist.");
		}
	}

	flavor kind(float side_1, float side_2, float side_3){
		triangle_rule_check(side_1, side_2, side_3);
		if(side_1==side_2 && side_2==side_3){
			return flavor::equilateral;
		}else if(side_1 == side_2 || side_2 == side_3 || side_1 == side_3){
			return flavor::isosceles;
		}else{
			return flavor::scalene;
		}
	}
}  // namespace triangle
