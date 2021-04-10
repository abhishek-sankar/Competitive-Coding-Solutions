#include "grade_school.h"

namespace grade_school {
	std::map<int, std::vector<std::string>> school::roster() const{
		return this->school_roster;
	}
	void school::add(std::string name, int grade){
		if(this->school_roster.find(grade) != this->school_roster.end()){
			this->school_roster.at(grade).push_back(name);			
		}else{
			std::vector<std::string> grade_roster;
			grade_roster.push_back(name);
			this->school_roster.insert({grade, grade_roster});
		}
		std::sort(this->school_roster.at(grade).begin(), this->school_roster.at(grade).end());
	}
	std::vector<std::string> school::grade(int grade_id) const{
		try{
			return this->school_roster.at(grade_id);
		}
		catch(const std::out_of_range& e){
			return std::vector<std::string>();
		}
	}

}  // namespace grade_school
/* 
References:

https://stackoverflow.com/questions/688039/how-can-i-build-a-stdvectorstdstring-and-then-sort-them
https://www.cplusplus.com/reference/map/map/at/
*/