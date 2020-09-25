#include<bits/stdc++.h>
using namespace std;

void printArray(vector<int>arr, int start, int end);
void mergeHalves(vector<int> &arr, vector<int> &temp, int leftStart, int rightEnd);
void mergeSort(vector<int>&arr, vector<int>&temp, int leftStart, int rightEnd);
void mergeSort(vector<int> &arr);

void mergeHalves(vector<int> &arr, vector<int> &temp, int leftStart, int rightEnd){
	int leftEnd = leftStart + (rightEnd-leftStart)/2;
	int rightStart = leftEnd + 1;
	int size = rightEnd - leftStart + 1;
	int left = leftStart;
	int right = rightStart;
	int index = leftStart;
	// cout<<"LeftStart :"<<leftStart<<" LeftEnd: "<<leftEnd<<" RightStart: "<<rightStart<<" rightEnd: "<<rightEnd<<endl;
	while(left<=leftEnd && right<= rightEnd){
		if(arr[left]<=arr[right]){
			temp[index] = arr[left];
			left++;
		}else{
			temp[index] = arr[right];
			right++;
			// cout<<"Here"<<endl;
		}
		index++;
	}
	if(left>leftEnd){
		while(right<=rightEnd){
			temp[index] = arr[right];
			index++;
			right++;
		}
	}else if(right > rightEnd){
		while(left <= leftEnd){
			temp[index] = arr[left];
			index++;
			left++;
		}
	}
	for(int i=leftStart;i<=rightEnd;i++){
		arr[i] = temp[i];
		// cout<<"Here"<<endl;
	}
	// printArray(arr, leftStart, rightEnd);
}
void mergeSort(vector<int>&arr, vector<int>&temp, int leftStart, int rightEnd){
	if(leftStart>=rightEnd) return;
	int middle = leftStart + (rightEnd-leftStart)/2;
	mergeSort(arr, temp, leftStart, middle);
	mergeSort(arr, temp, middle+1, rightEnd);
	mergeHalves(arr, temp, leftStart, rightEnd);
}
void mergeSort(vector<int> &arr){
	vector<int>temp(arr.size(),0);
	mergeSort(arr, temp, 0, arr.size()-1);
}
void printArray(vector<int>arr, int start, int end){
	for(int i=start;i<=end;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int main(){
	vector<int>arr(10,0);
	for(int i=9;i>=0;i--){
		arr[9-i] = i;
	}
	printArray(arr, 0, arr.size()-1);
	mergeSort(arr);
	printArray(arr, 0, arr.size()-1);
}