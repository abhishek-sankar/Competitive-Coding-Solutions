#include "string"
#include "reverse_string.h"
namespace reverse_string {
	std::string reverse_string(std::string str){
		char ch;
		for (int i=0, j=str.size()-1;i<j;i++,j--){
			ch = str[i];
			str[i] = str[j];
			str[j] = ch;
		}
		return str;
	}
}  // namespace reverse_string
