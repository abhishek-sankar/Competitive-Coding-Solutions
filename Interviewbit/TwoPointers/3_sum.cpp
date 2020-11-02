/*
https://www.interviewbit.com/problems/3-sum/
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
Return the sum of the three integers.

Assume that there will only be one solution

Example:
given array S = {-1 2 1 -4},
and target = 1.


*/

int Solution::threeSumClosest(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    long best_sum = A[0]+A[1]+A[2];
    int start = 0, end = A.size()-1, mid = start+1;
    for(int i=0;i<A.size()-2;i++){
        mid = i+1;
        end = A.size()-1;
        while(mid<end){
            long current_sum = A[i]+A[mid]+A[end];
            // cout<<current_sum<<endl;
            if(abs(B-current_sum)<abs(B-best_sum)){
                best_sum = current_sum;
            }
            if(current_sum<B)
            mid++;
            else
            end--;
        }
    }
    return best_sum;
}
