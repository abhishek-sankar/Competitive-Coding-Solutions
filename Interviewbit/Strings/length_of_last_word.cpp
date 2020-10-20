/*
https://www.interviewbit.com/problems/length-of-last-word/
Length of Last Word
Asked in:  Amazon
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
If the last word does not exist, return 0.
Note: A word is defined as a character sequence consists of non-space characters only.

Example:
Given s = "Hello World",
return 5 as length("World") = 5.

Please make sure you try to solve this problem without using library functions. Make sure you only traverse the string once.
*/

#include <string>
#include <regex>
std::string ltrim(const std::string& s) {
	return std::regex_replace(s, std::regex("^\\s+"), std::string(""));
}

std::string rtrim(const std::string& s) {
	return std::regex_replace(s, std::regex("\\s+$"), std::string(""));
}

std::string trim(const std::string& s) {
	return ltrim(rtrim(s));
}
int Solution::lengthOfLastWord(const string B) {
    // long len = A.size();
    string A = B;
    A = trim(A);
    long lastLen = -1;
    for(int i=0;i<A.size();i++){
        if(A[i]==' '){
            lastLen = A.size()-i-1;
        }
    }
    if(lastLen==-1)return A.size();
    return lastLen;
}
