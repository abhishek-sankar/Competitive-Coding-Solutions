/*
https://www.interviewbit.com/problems/triplets-with-sum-between-given-range/
Triplets with Sum between given range
Bookmark Suggest Edit
Given an array of real numbers greater than zero in form of strings.
Find if there exists a triplet (a,b,c) such that 1 < a+b+c < 2 . 
Return 1 for true or 0 for false.

Example:
Given [0.6, 0.7, 0.8, 1.2, 0.4] ,
You should return 1 as 0.6+0.7+0.4=1.7
1<1.7<2
Hence, the output is 1.
*/

int Solution::solve(vector<string> &A) {
    if(A.size()<3)return 0;
    vector<float>v{stof(A[0]),stof(A[1])};
    for(int i=2;i<A.size();i++){
        v.push_back(stof(A[i]));
        sort(v.begin(), v.end());
        float sum = v[0]+v[1]+v[2];
        if(sum>1 && sum<2)return 1;
        if(sum<=1)v.erase(v.begin());
        else v.pop_back();
    }
    return 0;
}


/*
This solution gets a partial score
int Solution::solve(vector<string> &A) {
    vector<float>v;
    for(int i=0;i<A.size();i++){
        v.push_back(stof(A[i]));
    }
    // sort(v.begin(), v.end());
    // for(int i=0;i<v.size();i++)cout<<v[i]<<endl;
    for(int i=0;i<v.size()-2;i++){
        if(v[i]>2) continue;
        for(int j=i+1;j<v.size()-1;j++){
            if(v[i]+v[j]>2)continue;
            for(int k=j+1;k<v.size();k++){
                if(v[i]+v[j]+v[k]>1 && v[i]+v[j]+v[k]<2)return 1;
            }
        }
    }
    return 0;
}


*/