#include "triangle.h"

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
	We use an approach similar to the one given here: https://en.cppreference.com/w/cpp/types/numeric_limits/epsilon

	Discussed more in footnotes.
	*/
	bool almost_equal(double num_1, double num_2){
		return std::abs(num_1-num_2) <= std::numeric_limits<double>::epsilon() * std::max(num_1, num_2);
	}
	flavor kind(double side_1, double side_2, double side_3){
		std::array<double, 3> sides = {side_1, side_2, side_3};
		std::sort(std::begin(sides), std::end(sides));
		triangle_rule_check(sides);
		if(almost_equal(sides[0], sides[2])){
			return flavor::equilateral;
		}else if(almost_equal(sides[0], sides[1]) || almost_equal(sides[1], sides[2])){
			return flavor::isosceles;
		}else{
			return flavor::scalene;
		}
	}
}  // namespace triangle

/*
Footnotes on floating point comparison (taken from mentor feedback):
Function for reference (now removed):
	constexpr threshold 0.00000001
	bool floating_point_equal_within_threshold_check(double num_1, double num_2){
		return (abs(num_1-num_2)<threshold);
	}

floating_point_equal_within_threshold_check() uses an absolute epsilon of 0.00000001

But how do we know whether that epsilon is a good value for the triangles of the caller? Their triangles might be very small or very large.
Also, almost all platforms implement double as IEEE-754 binary64 and IEEE-754 floating point values are not equidistant. All values above 67'108'863 have a distance of more than 0.00000001 to each other.

Comparing floating point values is hard!

Instead of comparing the absolute difference to some epsilon you could use the relative distance, i.e. compare the absolute distance to an relative multiple of an epsilon:
std::abs(a - b) <= some_epsilon * std::max(
    std::abs(a), std::abs(b))
Or you could dive deeper and examine Units in the Last Place (ULP). It's quite similar to the relative distance with some minor differences. Or you could combine some of those methods.

But in the end it breaks down to this: There's no safe way to implement almost_equal(double a, double b) if the values can be very large or very small or close to zero. Whether you should use absolute distances, relative distances, ULPs or a mixture of them depends on the magnitude of the values, their origin and the algorithms that transformed them.
*/