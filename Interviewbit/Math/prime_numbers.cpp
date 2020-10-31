/*
https://www.interviewbit.com/problems/prime-numbers/
Prime Numbers
Given a number N, find all prime numbers upto N ( N included ).

Example:
if N = 7,
all primes till 7 = {2, 3, 5, 7}
Make sure the returned array is sorted.
*/

vector<int> Solution::sieve(int A) {
    vector<bool>s(A+1);
    vector<int>res;
    for(int i=2;i<=A;i++){
        s[i]=1;
    }
    for(int i=2;i<=A;i++){
        if(s[i]==1){
            for(int j=2;j*i<=A;j++){
                s[i*j] = 0;
            }
        }
    }
    for(int i=2;i<=A;i++){
        if(s[i]==1){
            res.push_back(i);
        }
    }
    return res;
}
