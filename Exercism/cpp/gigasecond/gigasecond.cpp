#include "gigasecond.h"

namespace gigasecond {
	boost::posix_time::ptime advance(boost::posix_time::ptime start_time){
		boost::posix_time::time_duration one_gigasecond(0, 0, 1e9, 0);
		return start_time + one_gigasecond;
	}
}  // namespace gigasecond
