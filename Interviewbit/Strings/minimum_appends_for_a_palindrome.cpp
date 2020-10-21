/*
https://www.interviewbit.com/problems/minimum-appends-for-palindrome/
Minimum Appends for Palindrome!
Asked in:  Facebook
Problem Description
Given a string A consisting of lowercase characters.
We need to tell minimum characters to be appended (insertion at end) to make the string A a palindrome.

Problem Constraints
1 <= |A| <= 105
A consists only of lower-case characters.

Input Format
First argument is an string A.
Output Format
Return a integer denoting the minimum characters to be appended (insertion at end) to make the string A a palindrome.

Example Input
Input 1:
 A = "abede"
Input 2:
 A = "aabb"
Example Output
Output 1:
 2
Output 2:
 2

Example Explanation
Explanation 1:
 We can make string palindrome as "abedeba" by adding ba at the end of the string.

Explanation 2:
 We can make string palindrome as "aabbaa" by adding aa at the end of the string.
*/

vector<int>findLPS(string A){
    int M = A.size();
    int i=1, len=0;
    vector<int>lps(M);
    lps[0] = 0;
    while(i<M){
        if(A[i]==A[len]){
            len++;
            lps[i] = len;
            i++;
        }else{
            if(len!=0){
                len = lps[len-1];
            }else{
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

int Solution::solve(string A) {
    string rev = A;
    reverse(A.begin(), A.end());
    string concat = A + '0' + rev;
    vector<int>lps = findLPS(concat);
    return A.size()-lps.back();
}
