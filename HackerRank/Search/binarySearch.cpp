#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>myVec, int num, int left, int right){
	if(left>right)return -1;
	int mid = left+(right-left)/2;
	// if(myVec[mid]==num) return mid;
	if(myVec[mid]<num && myVec[mid+1]>num)return mid;
	// else if(myVec[mid]<num) return binarySearch(myVec, num, mid+1, right);
	else if(myVec[mid]<num && myVec[mid+1]<num)return binarySearch(myVec, num, mid+1, right);
	// else return binarySearch(myVec, num, left, mid-1);
	else return binarySearch(myVec, num, left, mid-1);
}

int main(){
	vector<int>myVec;
	// cout<<myVec[0]<<endl;

	for(int i=0;i<100;i++){
		if(i%2!=0)continue;
		myVec.push_back(i);
	}
	// cout<<myVec[0]<<endl;
	int pos = binarySearch(myVec, 9, 0, myVec.size()-1);
	cout<<pos<<endl;
	myVec.insert(myVec.begin() + pos+1, 9);
	// cout<<myVec[0]<<endl;
	for(int i=0;i<myVec.size();i++)cout<<myVec[i]<<endl;
	return 0;
}