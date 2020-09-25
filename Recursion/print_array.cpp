#include<bits/stdc++.h>
using namespace std;

void printArr(int* arr, int size){
	if(size>0){
	cout<<arr[0]<<endl;
	printArr((arr+1), size-1);
	}
}
int main(){
	int arr[] = {1,2,3,4,5};
	int size = sizeof(arr)/sizeof(arr[0]);
	printArr(arr,size);
}