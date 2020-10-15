/*
https://www.interviewbit.com/problems/kth-row-of-pascals-triangle/
Kth Row of Pascal's Triangle
Asked in:  Google

Given an index k, return the kth row of the Pascal’s triangle.
Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.

Example:
Input : k = 3
Return : [1,3,3,1]

NOTE : k is 0 based. k = 0, corresponds to the row [1]. 
*/
vector<int> Solution::getRow(int A) {
    vector<int>res;
    long val = 1;
    for(int i=1;i<=A+1;i++){
        res.push_back(val);
        val = val*(A+1-i)/i;
    }
    return res;
}
