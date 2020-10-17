/*
https://www.interviewbit.com/problems/square-root-of-integer/
Square Root of Integer
Asked in:  Facebook, Amazon, Microsoft

Given an integar A.
Compute and return the square root of A.
If A is not a perfect square, return floor(sqrt(A)).
DO NOT USE SQRT FUNCTION FROM STANDARD LIBRARY

Input Format
The first and only argument given is the integer A.
Output Format
Return floor(sqrt(A))

Constraints
1 <= A <= 10^9
For Example
Input 1:
    A = 11
Output 1:
    3
Input 2:
    A = 9
Output 2:
    3
*/
int Solution::sqrt(int A) {
    int low = 1, high = A;
    if(A==0)return 0;
    if(A==1)return 1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(mid<=A/mid && (mid+1)>A/(mid+1))return mid;
        else if(mid>A/mid)high = mid-1;
        else low = mid+1;
    }
}
