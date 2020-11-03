/*
https://www.interviewbit.com/problems/diffk/
*/

int Solution::diffPossible(vector<int> &A, int B) {
    set<int>s;
    for(int i=0;i<A.size();i++){
        if(s.find(B+A[i])!=s.end())return 1;
        else{
            s.insert(A[i]);
        }
    }
    return 0;
}
