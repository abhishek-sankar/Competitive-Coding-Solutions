#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<int> A;
	A.push_back(0);
	A.push_back(3);
	A.push_back(7);
	A.push_back(6);
	A.push_back(5);

    int flag=1;
    int i;

    for(i=0;i<A.size();i++){
        if(A[i]!=0)break;
	}
    if(i!=0)
	A.erase(A.begin(),A.begin()+i);
    for(i=A.size()-1;(i>=0&&flag==1);i--){
        if(A[i]==9){
            A[i]=0;
            continue;
        }
        flag=0;
	    A[i]+=1;
    }
	if(i==-1&&flag!=0){
		A.insert(A.begin(),1);
	}
	cout<<"Test 3";
    for(int i=0;i<A.size();i++){
		cout<<A[i]<<" ";
	}
}