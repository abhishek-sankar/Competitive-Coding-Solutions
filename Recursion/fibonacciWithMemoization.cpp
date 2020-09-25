#include<bits/stdc++.h>
#define count 50
using namespace std;
void initFibonacci(map<int,long>&fibonacci){
	fibonacci.insert({1,0});
	fibonacci.insert({2,1});
	fibonacci.insert({3,1});	
}
void printValues(map<int,long>fibonacci){
	for(auto i:fibonacci){
		cout<<"i:"<<i.first<<" Fib["<<i.first<<"] :"<<i.second<<endl;
	}
}
long findFibonacciRecursive(map<int, long>&fibonacci,int val){
	if(fibonacci.find(val)!=fibonacci.end()){
		return fibonacci[val];
	}else{
		long res1 = findFibonacciRecursive(fibonacci, val-1);
		long res2 = findFibonacciRecursive(fibonacci, val-2);
		fibonacci.insert({val-1, res1});
		fibonacci.insert({val-2, res2});
		fibonacci.insert({val,res1+res2});
		return fibonacci[val];
	}
}
int main(){
	map<int, long>fibonacci;
	initFibonacci(fibonacci);
	long res = findFibonacciRecursive(fibonacci, count);
	cout<<"value is "<<res<<endl;
}