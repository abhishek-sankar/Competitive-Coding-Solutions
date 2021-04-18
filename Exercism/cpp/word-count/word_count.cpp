#include "word_count.h"
#include <iostream>
namespace word_count {
	std::map<std::string, int> words(std::string input){ // "one,\ntwo,\nthree"
		std::vector<std::string> word_list_lowercase;
		std::map<std::string, int> word_counts_map;
		std::string new_word;
		for(std::string::size_type i = 0;i < input.size();i++){
			if(isalpha(input[i])){
				new_word+=tolower(input[i]);
			}else if(input[i]=='\'' && i!=0 && input[i-1]=='n'){
				new_word+=input[i];
			}else if(isnumber(input[i])){
				new_word+=input[i];
			}else{
				word_list_lowercase.push_back(new_word);
				new_word = "";
			}
			if(i==input.size()-1){
				word_list_lowercase.push_back(new_word);
				new_word = "";				
			}
		}
		for(unsigned long i=0;i<word_list_lowercase.size();i++){
			// std::cout<<word_list_lowercase[i]<<std::endl;
			if(word_counts_map.find(word_list_lowercase[i])==word_counts_map.end()){
				word_counts_map.insert({word_list_lowercase[i],1});
			}else{
				word_counts_map.at(word_list_lowercase[i])++;
			}
		}
		// for(auto word : word_counts_map){
		// 	std::cout<<word.first<<" : "<<word.second<<std::endl;
		// }
		word_counts_map.erase("");
		return word_counts_map;
	}
	
}  // namespace word_count
