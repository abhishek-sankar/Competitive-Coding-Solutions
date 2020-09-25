#include<bits/stdc++.h>
#define count 100
using namespace std;
void initFibonacciVector(vector<double>&fibonacci){
	fibonacci.push_back(0);
	fibonacci.push_back(1);
	fibonacci.push_back(1);
}
void getFibonacci(vector<double>&fibonacci,long val){
	for(int i=3;i<val;i++){
		fibonacci.push_back (fibonacci[i-1]+fibonacci[i-2]);
	}
}
void printFibonacci(vector<double>fibonacci){
	for(int i=0;i<fibonacci.size();i++){
		cout<<fibonacci[i]<<" ";
	}
	cout<<endl;
}

int main(){
	vector<double>fibonacci;
	initFibonacciVector(fibonacci);
	getFibonacci(fibonacci, count);
	cout<<"Fibonacci["<<count<<"] :"<<fibonacci[count-1]<<endl;
}