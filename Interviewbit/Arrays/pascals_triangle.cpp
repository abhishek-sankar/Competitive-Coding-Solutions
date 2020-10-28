/*
https://www.interviewbit.com/problems/pascal-triangle/
Pascal Triangle
Asked in:  Google, Amazon

Given numRows, generate the first numRows of Pascal’s triangle.
Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.

Example:
Given numRows = 5,
Return
[
     [1],
     [1,1],
     [1,2,1],
     [1,3,3,1],
     [1,4,6,4,1]
]
*/

vector<int> getNextLineOfPascalsTriangle(int n){
    vector<int>res;
    long val = 1;
    for(int i=0;i<n;i++){
        res.push_back(val);
        val*=(n-i-1);
        val/=(i+1);
    }
    return res;
}

vector<vector<int> > Solution::solve(int A) {
    vector<vector<int>>res;
    for(int i=1;i<=A;i++){
        res.push_back(getNextLineOfPascalsTriangle(i));
    }
    return res;
}
