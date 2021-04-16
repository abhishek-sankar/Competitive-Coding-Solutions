#include "anagram.h"
#include <iostream>

namespace anagram {
	bool map_compare(std::map<char, long> main_word_map, std::map<char, long> test_word_map){
		return main_word_map.size() == test_word_map.size() && std::equal(main_word_map.begin(), main_word_map.end(), test_word_map.begin(), [](auto a, auto b){return (a.first == b.first) && (a.second == b.second);});
	}	
	anagram::anagram(std::string word){
		for(char ch : word){
			if(this->letter_counts.find(tolower(ch))!=this->letter_counts.end()){
				this->letter_counts.at(tolower(ch))+=1;
			}else{
				this->letter_counts.insert({tolower(ch), 1});
			}
		}
		this->anagram_word = word; 
	}
	std::vector<std::string> anagram::matches(std::vector<std::string> match_list){
		std::vector<std::string> return_list;
		std::map<char, long> word_letter_counts;
		for(std::string word : match_list){
			word_letter_counts.clear();
			for(char letter : word){
				if(word_letter_counts.find(tolower(letter))!=word_letter_counts.end()){
					word_letter_counts.at(tolower(letter))+=1;
				}else{
					word_letter_counts.insert({tolower(letter), 1});
				}
			}
			if(map_compare(this->letter_counts, word_letter_counts)){
				return_list.push_back(word);
			}
		}
		std::vector<std::string> clean_return_list; // removes repetitions of original word
		std::string anagram_word_lowercased = this->anagram_word;
		std::transform(anagram_word_lowercased.begin(), anagram_word_lowercased.end(), anagram_word_lowercased.begin(), []( unsigned char ch){ return tolower(ch);});
		for(std::string anagram_match_in_loop : return_list){
			std::string anagram_match = anagram_match_in_loop;
			std::transform(anagram_match.begin(), anagram_match.end(), anagram_match.begin(), []( unsigned char ch){ return tolower(ch);});
			if(anagram_word_lowercased.compare(anagram_match)!=0){
				clean_return_list.push_back(anagram_match_in_loop);
			}
		}
		return clean_return_list;
	}
}  // namespace anagram
