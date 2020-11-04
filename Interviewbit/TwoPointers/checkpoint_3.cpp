/*
https://www.interviewbit.com/problems/numrange/

*/

int Solution::numRange(vector<int> &A, int B, int C) {
    // vector<int>res;
    long sum = 0, count = 0;
    for(int i=0;i<A.size();i++){
        long sum = 0;
        int k=i, j=i;
        while(sum+A[j]<B && j<A.size()){
            sum+=A[j];
            j++;
            k++;
        }// 1 2 3 4 5 6
        while(sum+A[k]<=C && k<A.size()){
            sum+=A[k];
            k++;
        }
        count+=k-j;
    }
    // for(int i=0;i<A.size();i++){
    //     int j=i, k=i;
    //     long sum = 0;
    //     int flag = 0;
    //     for(;sum<=C && k<A.size();k++){
    //         sum+=A[k];
    //         if(sum<B){
    //             j++;
    //         }
    //     }
    //     k--;
    //     count+=k-j;
    // }
    return count;
}
