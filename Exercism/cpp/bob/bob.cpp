#include "bob.h"

namespace bob {
	std::string hey(std::string prompt){
		std::string::size_type len = prompt.size();
		while(prompt[len-1]==' '){
			len--;
		}
		std::map<std::string, bool> checks = {{"Question", false}, {"Caps", false}, {"Letters present", false}, {"Alphanumeric", false}};
		if(prompt[len-1]=='?'){
			checks.at("Question") = true;
		}
		if(std::all_of(prompt.begin(), prompt.end(), [](char ch){ return isalpha(ch)?isupper(ch):1;})){
			checks.at("Caps") = true;
		}
		if(std::any_of(prompt.begin(), prompt.end(), [](char ch){return isalpha(ch);})){
			checks.at("Letters present") = true;
		}
		if(std::any_of(prompt.begin(), prompt.end(), [](char ch){return isalnum(ch);})){
			checks.at("Alphanumeric") = true;
		}
		if(checks.at("Question") && checks.at("Caps") && checks.at("Letters present")){
			// question all caps
			return "Calm down, I know what I'm doing!";
		}else if(checks.at("Question")){
			// question not all caps
			return "Sure.";
		}else if(checks.at("Caps") && checks.at("Letters present")){
			// caps and includes letters
			return "Whoa, chill out!";
		}else if(!checks.at("Alphanumeric")){
			// nothing present
			return "Fine. Be that way!";
		}else{
			// everything else
			return "Whatever.";
		}
	}
}  // namespace bob

/*
		if(std::all_of(prompt.begin(), prompt.end(), [](char ch){ return isalpha(ch)?isupper(ch):1;})){
			if(prompt[len-1]=='?'){
				return "Calm down, I know what I'm doing!";
			}else if(std::any_of(prompt.begin(), prompt.end(), [](char ch){return isalpha(ch);})){
				return "Whoa, chill out!";
			}else if(std::any_of(prompt.begin(), prompt.end(), [](char ch){return isalnum(ch);})){
				return "Whatever.";
			}
		}else if(prompt[len-1]=='?'){
			return "Sure.";
		}else if(std::any_of(prompt.begin(), prompt.end(), [](char ch){return isalnum(ch);})){
			return "Whatever.";		
		}
		return "Fine. Be that way!";
*/		