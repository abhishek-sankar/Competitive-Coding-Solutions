#include "leap.h"

namespace leap {
	bool is_leap_year(int year){
		return year%4==0 && (year%100!=0 || year%400==0);
	}
}  // namespace leap
/*
This helped me understand how to use namespaces: 
https://stackoverflow.com/questions/10492847/c-namespace-functions
*/


