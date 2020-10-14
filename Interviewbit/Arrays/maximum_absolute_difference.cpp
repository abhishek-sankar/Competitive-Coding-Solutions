/*
https://www.interviewbit.com/problems/maximum-absolute-difference/
Maximum Absolute Difference
Asked in:  
Amazon
You are given an array of N integers, A1, A2 ,…, AN. Return maximum value of f(i, j) for all 1 ≤ i, j ≤ N.
f(i, j) is defined as |A[i] - A[j]| + |i - j|, where |x| denotes absolute value of x.

For example,
A=[1, 3, -1]

f(1, 1) = f(2, 2) = f(3, 3) = 0
f(1, 2) = f(2, 1) = |1 - 3| + |1 - 2| = 3
f(1, 3) = f(3, 1) = |1 - (-1)| + |1 - 3| = 4
f(2, 3) = f(3, 2) = |3 - (-1)| + |2 - 3| = 5

So, we return 5.
*/

int Solution::maxArr(vector<int> &A) {
    vector<int>B;
    vector<int>C;
    int max_b, min_b, max_c, min_c;
    for(int i=0;i<A.size();i++){
        B.push_back(A[i]+i);
        C.push_back(A[i]-i);
    }
    min_b = INT_MAX;
    min_c = INT_MAX;
    max_b = INT_MIN;
    max_c = INT_MIN;
    for(int i=0;i<B.size();i++){
        if(B[i]>max_b)max_b = B[i];
        if(B[i]<min_b)min_b = B[i];
        if(C[i]>max_c)max_c = C[i];
        if(C[i]<min_c)min_c = C[i];
    }
    return max(abs(max_b-min_b),abs(max_c-min_c));
}
