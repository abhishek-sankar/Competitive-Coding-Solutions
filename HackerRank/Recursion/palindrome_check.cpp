#include<bits/stdc++.h>

using namespace std;

bool palindrome_check(string palindrome){
	if(palindrome.length()==1)
		return true;
	if(sizeof(palindrome)/sizeof(palindrome[0])==2)
		return palindrome[0]==palindrome[1];
	if(palindrome[0]==palindrome[palindrome.length()-1])
		return palindrome_check(palindrome.substr(1,palindrome.length()-2));
	else
		return false;
}
int main(){
	string palindrome = "malayalam";
	string pal2 = "Abhishek";
	cout<<palindrome_check(palindrome)<<endl;
	cout<<palindrome_check(pal2)<<endl;
	return 0;
}