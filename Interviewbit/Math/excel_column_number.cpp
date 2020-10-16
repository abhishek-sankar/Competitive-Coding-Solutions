/*
https://www.interviewbit.com/problems/excel-column-number/
Excel Column Number (example I/O needs an UNO reverse)
Asked in:  Amazon
Given a column title A as appears in an Excel sheet, return its corresponding column number.

Problem Constraints
1 <= |A| <= 100
Input Format
First and only argument is string A.
Output Format
Return an integer

Example Input
Input 1:
 1
Input 2:
 28

Example Output
Output 1:

 "A"
Output 2:

 "AB"


Example Explanation
Explanation 1:
 1 -> "A"
Explanation 2:
A  -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
*/
int Solution::titleToNumber(string A) {
    reverse(A.begin(), A.end());
    long result = 0;
    long multiplier = 1;
    for(int i=0;i<A.size();i++){
        result+=multiplier*int(A[i]-'A'+1);
        multiplier*=26;
    }
    return result;
}
