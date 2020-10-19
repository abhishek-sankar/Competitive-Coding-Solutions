/*
https://www.interviewbit.com/problems/implement-strstr/
Implement StrStr
Asked in:  Facebook, Amazon, Qualcomm, Wipro, Microsoft

Please Note:
Another question which belongs to the category of questions which are intentionally stated vaguely. 
Expectation is that you will ask for correct clarification or you will state your assumptions before you start coding.

Implement strStr().
 strstr - locate a substring ( needle ) in a string ( haystack ). 
Try not to use standard library string functions for this question.

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 NOTE: Good clarification questions:
What should be the return value if the needle is empty?
What if both haystack and needle are empty?
For the purpose of this problem, assume that the return value should be -1 in both cases. 
*/

int Solution::strStr(const string A, const string B) {
    if(A.size()==0)return -1;
    if(A.size()<B.size())return -1;
    if(A.size()==B.size()) {
        if(A.compare(B)==0)return 0;
        else return -1;
    }
    for(int i=0;i<A.size()-B.size();i++){
        if(A[i]==B[0]){
            if(B.size()==1) return i;
            int flag=0;
            for(int j = 1;j<B.size();j++){
                if(A[i+j]!=B[j]){
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                return i;
                }
        }
    }
    return -1;
}
