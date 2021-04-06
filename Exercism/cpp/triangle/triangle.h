#if !defined(TRIANGLE_H)
#define TRIANGLE_H
#include "stdexcept"

namespace triangle {
	enum class flavor{
		scalene,
		isosceles,
		equilateral
	};
	flavor kind(float side_1, float side_2, float side_3);

}  // namespace triangle

#endif // TRIANGLE_H