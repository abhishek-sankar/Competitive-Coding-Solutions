#include<bits/stdc++.h>
using namespace std;

int main(){
	vector<int>A;
	A.push_back(-89);
	A.push_back(-277);
	A.push_back(-475);
	A.push_back(-480);
	A.push_back(-420);
	// A.push_back(2);

    int sum=A[0],smallSum=A[0],i;
    for(i=0;A[i]<=0&&i<A.size();i++)if(A[i]>sum)sum=A[i];
    for(;i<A.size();i++){
        smallSum=0;
        for(int j=i;j<A.size();j++){
            smallSum+=A[j];
            if(smallSum>sum)
                sum=smallSum;
            if(smallSum<=0){
                i=j;
                break;
            }
        }
    }
	cout<<sum;
return 0;
}