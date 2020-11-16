/*
https://www.interviewbit.com/problems/convert-to-palindrome/
Convert to Palindrome
Asked in:  Amazon
Problem Description

Given a string A consisting only of lowercase characters, we need to check whether it is possible to make this string a palindrome after removing exactly one character from this.

If it is possible then return 1 else return 0.



Problem Constraints
3 <= |A| <= 105

A[i] is always a lowercase character.



Input Format
First and only argument is an string A.



Output Format
Return 1 if it is possible to convert A to palindrome by removing exactly one character else return 0.



Example Input
Input 1:

 A = "abcba"
Input 2:

 A = "abecbea"


Example Output
Output 1:

 1
Output 2:

 0


Example Explanation
Explanation 1:

 We can remove character ‘c’ to make string palindrome
Explanation 2:

 It is not possible to make this string palindrome just by removing one character 
*/

int Solution::solve(string A) {
    int flag = 0;
    int start = 0, end = A.size()-1;
    if(A.size()<=2)return 1;
    while(start<=end){
        // wofpkznm
        if(flag==0){
            if(A[start]!=A[end]){
                if(A[start+1]==A[end]){
                    flag=1;
                    start++;
                }else if(A[start]==A[end-1]){
                    flag = 1;
                    end--;
                }else if(A[start+1]!=A[end] || A[start]!=A[end-1]){
                    return 0;
                }
            }
        }else{
            if(A[start]!=A[end]){
                return 0;
            }
        }
        start++;
        end--;
    }
    if(flag==1)
    return 1;
    else if(A.size()%2==1){
        return 1;
    }else{
        return 0;
    }
}
