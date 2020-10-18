/*
https://www.interviewbit.com/problems/implement-power-function/
Implement Power Function
Asked in:  Google, LinkedIn
Implement pow(x, n) % d.
In other words, given x, n and d,
find (xn % d)

Note that remainders on division cannot be negative. 
In other words, make sure the answer you return is non negative.

Input : x = 2, n = 3, d = 3
Output : 2

2^3 % 3 = 8 % 3 = 2.
*/

long long int re(long long int num, long long int power, long long int mod){
    if(power==0 && mod!=1)return 1;
    long long int ans = re(num%mod, power/2, mod)%mod;
    if(power%2!=0){
        long long int answer = ((ans%mod)*(num%mod))%mod;
        answer = ((answer%mod)*(ans%mod))%mod;
        return answer;
    }else{
        long long int answer = ((ans%mod)*(ans%mod))%mod;
        return answer;
    }
}
int Solution::pow(int x, int n, int d) {
    if(x<0 && n%2!=0){
        return x+d;
    }
    if(x==0 && n==0 || d==1)return 0;
    return re(x,n,d);
}
