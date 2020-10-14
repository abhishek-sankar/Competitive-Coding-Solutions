#include<bits/stdc++.h>
using namespace std;
string reverse(string name){
	// 3 steps
	// one step simpler?
	// My function CAN
	// how will I use the function which can do 1 step simpler to solve present problem?
	// Base case:
	if(name.length()<=1)
		return name;
	return reverse(name.substr(1))+name[0];
}
int main(){
	cout<<reverse("kehsihbA")<<endl;
}