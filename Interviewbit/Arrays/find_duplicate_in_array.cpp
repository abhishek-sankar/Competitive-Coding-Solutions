/*
https://www.interviewbit.com/problems/find-duplicate-in-array/
Find Duplicate in Array
Asked in:  Amazon, VMWare, Riverbed

Given a read only array of n + 1 integers between 1 and n, find one number that 
repeats in linear time using less than O(n) space and traversing the stream sequentially O(1) times.

Sample Input:
[3 4 1 4 1]

Sample Output:
1

If there are multiple possible answers ( like in the sample case above ), output any one.
If there is no duplicate, output -1
*/
int Solution::repeatedNumber(const vector<int> &A) {
    // map<int, int>m;
    vector<int>v(A.size(),0);
    for(int i=0;i<A.size();i++){
        if(v[A[i]]==0)v[A[i]]=1;
        else return A[i];
    }
    return -1;
}
