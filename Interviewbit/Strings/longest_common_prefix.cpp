/*
https://www.interviewbit.com/problems/longest-common-prefix/
ongest Common Prefix
Asked in:  Google
Given the array of strings A, 
you need to find the longest string S which is the prefix of ALL the strings in the array.
Longest common prefix for a pair of strings S1 and S2 is the longest string S which is the prefix of both S1 
and S2.
For Example, longest common prefix of "abcdefgh" and "abcefgh" is "abc".

Input Format
The only argument given is an array of strings A.

Output Format
Return longest common prefix of all strings in A.
For Example
Input 1:
    A = ["abcdefgh", "aefghijk", "abcefgh"]
Output 1:
    "a"
    Explanation 1:
        Longest common prefix of all the strings is "a".
Input 2:
    A = ["abab", "ab", "abcd"];
Output 2:
    "ab"
    Explanation 2:
        Longest common prefix of all the strings is "ab".
*/

string Solution::longestCommonPrefix(vector<string> &A) {
    string res;
    if(A.size()==1) return A[0];
    long min = INT_MAX;
    for(int i=0;i<A.size();i++){
        // cout<<"i: "<<i<<endl;
        // cout<<A[i]<<endl;
        // cout<<A[i].size()<<endl;
        if(A[i].length()<min) min = A[i].size();
    }
    // cout<<"Test #1"<<endl;
    int flag = -1;
    for(int i=0;i<min;i++){
        char ch = A[0][i];
        // cout<<"ch: "<<ch<<endl;
        for(int j=1;j<A.size();j++){
            if(A[j][i]!=ch){
                // cout<<i<<endl;
                flag = i;
                break;
            }
        }
        if(flag!=-1){
            // cout<<"Flag: "<<flag<<endl;
            return res;
        }else{
            res += ch;
            // cout<<res<<endl;
        }
    }
    if(flag==-1)return A[0].substr(0, (min));
}
