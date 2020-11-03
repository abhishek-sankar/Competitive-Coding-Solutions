/*
https://www.interviewbit.com/problems/3-sum-zero/
// Big Sur beta 11 messsed up my select and click functions, update this once you get the non beta big sur on Nov 10th
*/

vector<vector<int> > Solution::threeSum(vector<int> &A) {
    if(A.size()<3){
        vector<vector<int>>zero;
        return zero;
    }
    set<vector<int>>res;
    sort(A.begin(), A.end());
    for(int i=0;i<A.size()-2;i++){
        int mid = i+1;
        int end = A.size()-1;
        while(mid<end){
            long long small_sum = 0;
            small_sum+=A[i]+A[mid]+A[end];
            if(A[i]==INT_MIN && A[mid]==INT_MIN || A[mid]==INT_MIN && A[end]==INT_MIN || A[i]==INT_MIN && A[end]==INT_MIN){
                mid++;
                continue;
            }
            // cout<<small_sum<<" "<<A[i]<<" "<<A[mid]<<" "<<A[end]<<endl;
            if(small_sum==0){
                // cout<<i<<" "<<mid<<" "<<end<<endl;
                vector<int>small_res;
                small_res.push_back(A[i]);
                small_res.push_back(A[mid]);
                small_res.push_back(A[end]);
                res.insert(small_res);
                mid++;
            }
            if(small_sum>0){
                end--;
            }else if(small_sum<0){
                mid++;
            }
        }
    }
    vector<vector<int>>res_new;
    for(auto i: res){
        res_new.push_back(i);
    }
    return res_new;
}
