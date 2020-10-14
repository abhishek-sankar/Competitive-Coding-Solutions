/*
https://www.interviewbit.com/problems/max-sum-contiguous-subarray/
Find the contiguous subarray within an array, A of length N which has the largest sum.
*/
int Solution::maxSubArray(const vector<int> &A) {
    long maxSum = INT_MIN, sum = 0;
    for(int i=0;i<A.size();i++){
        sum+=A[i];
        if(sum>maxSum){
            maxSum = sum;
        }
        if(sum<=0){
            sum=0;
        }
    }
    return maxSum;
}
