/*
https://www.interviewbit.com/problems/sum-of-pairwise-hamming-distance/

*/

int Solution::hammingDistance(const vector<int> &A) {
    long sum = 0;
    long count = 0;
    for(int i=0;i<32;i++){
        count = 0;
        for(int j=0;j<A.size();j++){
            if(A[j] & 1<<i){
                count+=1;
            }
        }
        sum+=count*(A.size()-count)*2;
    }
    return sum % 1000000007;
}
