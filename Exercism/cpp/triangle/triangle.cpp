#include "triangle.h"
#define threshold 0.00000001
namespace triangle {
	void triangle_rule_check(std::array<double,3> sides){
		if(sides[0] + sides[1] < sides[2]) {
			throw std::domain_error("Triangle fails the triangle rule A + B < C.");
		}else if(sides[0] <= 0){
			throw std::domain_error("Triangle with side less than or equal to zero cant exist.");
		}
	}
	/*
	Floating point comparisons are tricky. The following link explains why and what strategies can you use
	https://stackoverflow.com/questions/4915462/how-should-i-do-floating-point-comparison
	*/
	bool floating_point_equal_within_threshold_check(double num_1, double num_2){
		return (abs(num_1-num_2)<threshold);
	}
	flavor kind(double side_1, double side_2, double side_3){
		std::array<double, 3> sides = {side_1, side_2, side_3};
		std::sort(std::begin(sides), std::end(sides));
		triangle_rule_check(sides);
		if(floating_point_equal_within_threshold_check(sides[0], sides[2])){
			return flavor::equilateral;
		}else if(floating_point_equal_within_threshold_check(sides[0], sides[1]) || floating_point_equal_within_threshold_check(sides[1], sides[2])){
			return flavor::isosceles;
		}else{
			return flavor::scalene;
		}
	}
}  // namespace triangle
