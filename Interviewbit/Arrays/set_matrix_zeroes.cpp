/*
https://www.interviewbit.com/problems/set-matrix-zeros/
Set Matrix Zeros
Asked in:  Oracle, Amazon

Given a matrix, A of size M x N of 0s and 1s. If an element is 0, set its entire row and column to 0.
Note: This will be evaluated on the extra memory used. Try to minimize the space and time complexity.

Input Format:
The first and the only argument of input contains a 2-d integer matrix, A, of size M x N.

Output Format:
Return a 2-d matrix that satisfies the given conditions.

Constraints:
1 <= N, M <= 1000
0 <= A[i][j] <= 1
Examples:

Input 1:
    [   [1, 0, 1],
        [1, 1, 1], 
        [1, 1, 1]   ]
Output 1:
    [   [0, 0, 0],
        [1, 0, 1],
        [1, 0, 1]   ]

Input 2:
    [   [1, 0, 1],
        [1, 1, 1],
        [1, 0, 1]   ]
Output 2:
    [   [0, 0, 0],
        [1, 0, 1],
        [0, 0, 0]   ]


*/
void Solution::setZeroes(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    stack<pair<int,int>>s;
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[0].size();j++){
            if(A[i][j]==0){
                s.push(make_pair(i,j));
            }
        }
    }
    map<int,int>r;
    map<int, int>c;
    while(s.size()!=0){
        pair<int,int> p = s.top();
        r[p.first]++;
        c[p.second]++;
        s.pop();
    }
    for(auto j:r){
        for(int i=0;i<A[0].size();i++){
            A[j.first][i]=0;
        }        
    }
    for(auto j:c){
        for(int i=0;i<A.size();i++){
            A[i][j.first]=0;
        }        
    }
}
