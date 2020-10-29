/*
https://www.interviewbit.com/problems/prime-sum/
Prime Sum
Asked in:  Epic systems

Given an even number ( greater than 2 ), return two prime numbers whose sum will be equal to given number.
NOTE A solution will always exist. read Goldbach’s conjecture

Example:
Input : 4
Output: 2 + 2 = 4

If there are more than one solutions possible, return the lexicographically smaller solution.

If [a, b] is one solution with a <= b,
and [c,d] is another solution with c <= d, then

[a, b] < [c, d] 

If a < c OR a==c AND b < d. 
*/
vector<int> Solution::primesum(int A) {
    int max_size = A+1;
    vector<int>res;
    vector<bool>primes(max_size, 1);
    primes[0] = primes[1] = 0;
    for(int i=2;i<max_size;i++){
        if(primes[i]==1){
            for(int j=2;j*i<max_size;j++){
                primes[j*i] = 0;
            }
        }
    }
    for(int i=2;i<max_size;i++){
        if(primes[i]==1 && primes[A-i]==1){
            res.push_back(i);
            res.push_back(A-i);
            return res;
        }
    }
    return res;
}
