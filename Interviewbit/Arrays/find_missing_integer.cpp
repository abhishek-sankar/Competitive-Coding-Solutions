/*
https://www.interviewbit.com/problems/first-missing-integer/
First Missing Integer
Asked in:  Model N, InMobi, Amazon

Given an unsorted integer array, find the first missing positive integer.

Example:
Given [1,2,0] return 3,
[3,4,-1,1] return 2,
[-8, -7, -6] returns 1
Your algorithm should run in O(n) time and use constant space.
*/
int Solution::firstMissingPositive(vector<int> &A) {
    vector<int>v(A.size(),0);
    int flag = 0;
    for(int i=0;i<A.size();i++){
        if(A[i]>0) flag = 1;
        if(A[i]>=0 && A[i]<v.size())
        v[A[i]]++;
    }
    for(int i=1;i<v.size();i++){
        if(v[i]==0)return i;
    }
    if(!flag)return 1;
    return A.size()+1;
}
