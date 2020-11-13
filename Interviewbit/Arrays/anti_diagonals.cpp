/*
https://www.interviewbit.com/problems/anti-diagonals/
Anti Diagonals
Asked in:  Microsoft, Adobe
Give a N*N square matrix, return an array of its anti-diagonals. Look at the example for more details.

Example:


Input: 	

1 2 3
4 5 6
7 8 9

Return the following :

[ 
  [1],
  [2, 4],
  [3, 5, 7],
  [6, 8],
  [9]
]


Input : 
1 2
3 4

Return the following  : 

[
  [1],
  [2, 3],
  [4]
]

*/

vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    int length = A.size();
    vector<vector<int>>res;
    for(int i=0;i<length;i++){
        int j=0;
        vector<int>small_res;
        for(int k=i;k>=0;k--){
            small_res.push_back(A[k][j]);
            j++;
        }
        reverse(small_res.begin(), small_res.end());
        if(small_res.size()!=0)
        res.push_back(small_res);
    }
    if(A.size()>1)
    for(int i=1;i<length;i++){
        int k=length-1;
        vector<int>small_res;
        for(int j=i;j<length;j++){
            small_res.push_back(A[k][j]);
            k--;
        }
        reverse(small_res.begin(), small_res.end());
        if(small_res.size()!=0)
        res.push_back(small_res);        
    }
    // for(int k=0;k<=length*length;k++){
    //     vector<int>small_res;
    //     for(int i=0;i<length;i++){
    //         for(int j=0;j<length;j++){
    //             if(i+j==k){
    //                 small_res.push_back(A[i][j]);
    //             }
    //         }
    //     }
    //     if(small_res.size()!=0)
    //     res.push_back(small_res);
    // }
    return res;
}
