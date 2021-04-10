#if !defined(GRADE_SCHOOL_H)
#define GRADE_SCHOOL_H
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

namespace grade_school {
	class school{
		public:
			std::map<int, std::vector<std::string>> roster() const;
			void add(std::string name, int grade);
			std::vector<std::string> grade(int grade_id) const;
		private:
			std::map<int, std::vector<std::string>> school_roster;
	};
}  // namespace grade_school

#endif // GRADE_SCHOOL_H