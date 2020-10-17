/*
https://www.interviewbit.com/problems/greatest-common-divisor/
Greatest Common Divisor
Asked in:  NetApp, Google
Given 2 non negative integers m and n, find gcd(m, n)
GCD of 2 integers m and n is defined as the greatest integer g such that g is a divisor of both m and n.
Both m and n fit in a 32 bit signed integer.

Example
m : 6
n : 9
GCD(m, n) : 3 
NOTE : DO NOT USE LIBRARY FUNCTIONS 

*/
#define capacity 1000000
int Solution::gcd(int A, int B) {
    if(A<1 || B<1) return max(A,B);
    if(A<=1 || B<=1) return 1;
    int seive[capacity];
    long GCD = 1;
    for(int i=0;i<capacity;i++){
        seive[i] = 1;
    }
    seive[0] = seive[1] = 0;
    for(int i=2;i<capacity;i++){
        if(seive[i]==1){
            for(int j=2*i;j<capacity;j+=i){
                seive[j] = 0;
            }
        }
    }
    vector<int>primes;
    for(int i=2;i<capacity;i++){
        if(seive[i]==1){
            primes.push_back(i);
        }
    }
    map<int, int>map_1;
    map<int, int>map_2;
    for(auto& i:primes){
        while(A%i==0){
            map_1[i]++;
            A/=i;
        }
        while(B%i==0){
            map_2[i]++;
            B/=i;
        }
    }
    if(map_1.size()>map_2.size()){
        for(auto i:map_1){
            if(map_2.find(i.first)!=map_2.end()){
                GCD*=pow(i.first, min(i.second, map_2[i.first]));
            }
        }
    }else{
        for(auto i:map_2){
            if(map_1.find(i.first)!=map_1.end()){
                GCD*=pow(i.first, min(i.second, map_1[i.first]));
            }
        }        
    }
    return GCD;
}
