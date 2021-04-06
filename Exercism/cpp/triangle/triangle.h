#if !defined(TRIANGLE_H)
#define TRIANGLE_H
#include "stdexcept"
#include "array"
#include "algorithm"
#include "cstdlib"

namespace triangle {
	enum class flavor{
		scalene,
		isosceles,
		equilateral
	};
	flavor kind(double side_1, double side_2, double side_3);

}  // namespace triangle

#endif // TRIANGLE_H