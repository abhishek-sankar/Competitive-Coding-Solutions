/*
https://www.interviewbit.com/problems/trailing-zeros-in-factorial/
Trailing Zeros in Factorial
Asked in:  Microsoft, Jabong, Zillow

Given an integer A, return the number of trailing zeroes in A!.
Note: Your solution should be in logarithmic time complexity.

**Problem Constraints**
1 <= A <= 10000
**Input Format**
First and only argumment is integer A.
**Output Format**
Return an integer, the answer to the problem.

**Example Input**
Input 1:
 A = 4
Input 2:
 A = 5
**Example Output**
Output 1:
 0
Output 2:
 1
**Example Explanation**
Explanation 1:
 4! = 24
Explanation 2:
 5! = 120
*/

int Solution::trailingZeroes(int A) {
    if(A<5)return 0;
    long count = 0;
    long mul = 1;
    for(int i=5;i<=A;i++){
        long j = i;
        while(j%5==0){
            count++;
            j/=5;
        }
    }
    return count;
}
