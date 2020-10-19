/*
https://www.interviewbit.com/problems/palindrome-string/
Palindrome String
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Example:
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.
Return 0 / 1 ( 0 for false, 1 for true ) for this problem
*/

int Solution::isPalindrome(string A) {
    for(int i=0, j=A.size()-1;i<=j;){
        while(!isalnum(A[i]) && i<=A.size()-1)i++;
        while(!isalnum(A[j]) && j>=0)j--;
        if(tolower(A[i])!=tolower(A[j]))return 0;
        else{
            i++;
            j--;
        }
    }
    return 1;
}
