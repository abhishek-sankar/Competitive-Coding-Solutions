/*
https://www.interviewbit.com/problems/minimum-characters-required-to-make-a-string-palindromic/
Minimum Characters required to make a String Palindromic
Asked in:  Amazon
Problem Setter: glowing_glare Problem Tester: RAMBO_tejasv
Given an string A. The only operation allowed is to insert characters in the beginning of the string.

Find how many minimum characters are needed to be inserted to make the string a palindrome string.

Input Format
The only argument given is string A.
Output Format
Return the minimum characters that are needed to be inserted to make the string a palindrome string.

For Example
Input 1:
    A = "ABC"
Output 1:
    2
    Explanation 1:
        Insert 'B' at beginning, string becomes: "BABC".
        Insert 'C' at beginning, string becomes: "CBABC".
Input 2:
    A = "AACECAAAA"
Output 2:
    2
    Explanation 2:
        Insert 'A' at beginning, string becomes: "AAACECAAAA".
        Insert 'A' at beginning, string becomes: "AAAACECAAAA".
*/

vector<int>findLPS(string A){
    int m = A.size();
    vector<int>lps(m);
    int i=1, len=0;
    lps[0] = 0;
    while(i<m){
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
    string res = A;
    reverse(A.begin(), A.end());
    string concat = res + '0' + A;
    vector<int>lps = findLPS(concat);
    return A.size() - lps.back();
}
