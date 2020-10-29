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
    int low = INT_MAX, high = INT_MIN;
    
    for(int i=0;i<A.size()-1;i++){
        if(A[i]>A[i+1]){
            low = i;
            break;
        }
    }
    for(int i=A.size()-1;i>0;i--){
        if(A[i]<A[i-1]){
            high = i;
            break;
        }
    }
    if(low==INT_MAX){
        res.push_back(-1);
        return res;
    }
    int minimum = INT_MAX;
    int maximum = INT_MIN;
    
    for(int i=low;i<=high;i++){
        minimum = min(minimum, A[i]);
        maximum = max(maximum, A[i]);
    }
    
    int start = upper_bound(A.begin(), A.begin()+low, minimum) - A.begin();
    int end = lower_bound(A.begin()+high, A.end(), maximum) - A.begin()-1;
    res.push_back(start);
    res.push_back(end);
    return res;
}
