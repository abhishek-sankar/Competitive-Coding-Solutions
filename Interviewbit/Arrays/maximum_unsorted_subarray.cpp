/*
https://www.interviewbit.com/problems/maximum-unsorted-subarray/
Maximum Unsorted Subarray
Asked in:  Amazon
You are given an array (zero indexed) of N non-negative integers, A0, A1 ,…, AN-1.
Find the minimum sub array Al, Al+1 ,…, Ar so if we sort(in ascending order) that sub array, then the whole array should get sorted.
If A is already sorted, output -1.

Example :
Input 1:
A = [1, 3, 2, 4, 5]
Return: [1, 2]

Input 2:
A = [1, 2, 3, 4, 5]
Return: [-1]
In the above example(Input 1), if we sort the subarray A1, A2, then whole array A should get sorted.
*/

vector<int> Solution::subUnsort(vector<int> &A) {
vector<int>res;
int f = INT_MIN;
int l = INT_MAX;

for(int i=0;i<A.size()-1;i++){
    if(A[i+1] < A[i]){
        l = i+1;
    }
}
for(int i=A.size()-1;i>0;i--){
    if(A[i-1] > A[i]){
        f = i-1;
    }
}

if(f == INT_MIN && l == INT_MAX){
    res.push_back(-1);
    return res;
}

int maximum = INT_MIN;
int minimum = INT_MAX;

for(int i=f;i<=l;i++){
    minimum = min(minimum,A[i]);
    maximum = max(maximum,A[i]);
}

int initial = upper_bound(A.begin(),A.begin()+f,minimum) - A.begin();
int final = lower_bound(A.begin()+l+1,A.end(),maximum) - A.begin() - 1;
res.push_back(initial);
res.push_back(final);
return res;    
}
