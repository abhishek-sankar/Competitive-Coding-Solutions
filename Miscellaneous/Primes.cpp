#include<bits/stdc++.h>
#define MAX 1048574
using namespace std;

int main(){
	int primes[MAX]={1};
	vector<int>result;
	primes[0]=0;
	primes[1]=0;
	for(int i=2;i<=MAX;i++){
		if(primes[i]==1){
			for(int j=i;j*i<=MAX;j++){
				primes[j*i]=0;	
			}
		}
	}
	for(int i=0;i*i<MAX;i++){
		if((primes[i]==1)&&(primes[MAX-i]==1)){
			result.push_back(i);
			result.push_back(MAX-i);
		}
	}
	cout<<"Result :"<<result[0]<<" "<<result[1]<<endl;	
	return 0;
}