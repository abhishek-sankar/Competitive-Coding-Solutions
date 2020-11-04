/*
https://www.interviewbit.com/problems/diffk/
*/

int Solution::diffPossible(vector<int> &A, int B) {
    for(int i=0;i<A.size();i++){
        int j = lower_bound(A.begin(), A.end(), A[i]+B) - A.begin();
        if(j==i)j++;
        if(A[j]-A[i]==B)return 1;
    }
    return 0;
}


// int Solution::diffPossible(vector<int> &A, int B) {
//     set<int>s;
//     for(int i=0;i<A.size();i++){
//         if(s.find(B+A[i])!=s.end())return 1;
//         else{
//             s.insert(A[i]);
//         }
//     }
//     return 0;
// }
