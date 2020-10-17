/*
https://www.interviewbit.com/problems/grid-unique-paths/
Grid Unique Paths
Asked in:  Google, Amazon, Microsoft, Adobe
A robot is located at the top-left corner of an A x B grid (marked ‘Start’ in the diagram below).

Path Sum: Example 1
The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked ‘Finish’ in the diagram below).
How many possible unique paths are there?
Note: A and B will be such that the resulting answer fits in a 32 bit signed integer.

Example :
Input : A = 2, B = 2
Output : 2
2 possible routes : (0, 0) -> (0, 1) -> (1, 1) 
              OR  : (0, 0) -> (1, 0) -> (1, 1)

*/

float fact(int n, int r){// return an int
    int res = 1;
    if(n<r)return 0;
    for(int i=n;i>max(r, n-r);i--){
        res*=i;
        res/=(n-i+1);
        // cout<<"i: "<<i<<" res: "<<res<<endl;
    }
    return int(res);
}
int Solution::uniquePaths(int A, int B) {
    return fact(A+B-2, B-1);
}
