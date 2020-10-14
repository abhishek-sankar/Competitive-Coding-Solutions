#include<bits/stdc++.h>
using namespace std;
void printArray(vector<int> v);
void rearrangeArray(vector<int> v){
	int l = v.size();
	for(int i=0;i<l;i++){
		v[i]*=l;
	}
	for(int i=0;i<l;i++){
		v[i]+=v[v[i]/l]/l;
	}
	printArray(v);
	for(int i=0;i<l;i++){
		v[i]%=l;
	}
	printArray(v);
}
void printArray(vector<int> v){
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	// cout<<endl;
}
int main(){
int n, num;
vector<int>v;
cin>>n;
for(int i=0;i<n;i++){
	cin>>num;
	v.push_back(num);
}
rearrangeArray(v);
printArray(v);
}